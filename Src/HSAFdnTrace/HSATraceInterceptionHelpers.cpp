//==============================================================================
// Copyright (c) 2015 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  This file contains functions called by various intercepted APIs
//==============================================================================

#include <Defs.h>
#include <Logger.h>
#include <GlobalSettings.h>

#include "HSAToolsRTModule.h"
#include "HSARTModuleLoader.h"

#include "AutoGenerated/HSATraceInterception.h"

#include "AutoGenerated/HSATraceStringOutput.h"

#include "HSAFdnAPIInfoManager.h"
#include "FinalizerInfoManager.h"
#include "HSATraceInterceptionHelpers.h"
#include "HSASignalPool.h"
#include "HSAAqlPacketTimeCollector.h"

hsa_status_t AqlPacketTraceCallback(const hsa_aql_trace_t* pAqlPacketTrace, void* pUserArg)
{
    SpAssertRet(nullptr != pAqlPacketTrace) HSA_STATUS_ERROR_INVALID_ARGUMENT;

    SP_UNREFERENCED_PARAMETER(pUserArg);

    HSAAqlPacketBase* pAqlPacket = nullptr;

    switch (pAqlPacketTrace->type)
    {
        case HSA_PACKET_TYPE_KERNEL_DISPATCH:
        {
            HSAAqlKernelDispatchPacket* pAqlKernelDispatchPacket = new(std::nothrow) HSAAqlKernelDispatchPacket(*static_cast<hsa_kernel_dispatch_packet_t*>(pAqlPacketTrace->packet));
            pAqlPacket = pAqlKernelDispatchPacket;

            hsa_kernel_dispatch_packet_t* pKernelDispatchPacket = static_cast<hsa_kernel_dispatch_packet_t*>(pAqlPacketTrace->packet);

            hsa_signal_t replacementSignal;

            if (HSASignalPool::Instance()->AcquireSignal(1, replacementSignal))
            {
                // create a replacement signal
                HSAPacketSignalReplacer signalReplacer(pAqlKernelDispatchPacket, pKernelDispatchPacket->completion_signal,
                                                       replacementSignal, pAqlPacketTrace->agent,
                                                       pAqlPacketTrace->queue);

                pKernelDispatchPacket->completion_signal = replacementSignal;

                // add the replacer to the list of signals that are available to listen for
                HSASignalQueue::Instance()->AddSignalToBack(signalReplacer);

#if defined (_LINUX) || defined (LINUX)

                // notify the signal collector that there are now dispatches available to listen for
                if (!HSATimeCollectorGlobals::Instance()->m_dispatchesInFlight.unlockCondition())
                {
                    GPULogger::Log(GPULogger::logERROR, "unable to unlock condition\n");
                }

                if (!HSATimeCollectorGlobals::Instance()->m_dispatchesInFlight.signalSingleThread())
                {
                    GPULogger::Log(GPULogger::logERROR, "unable to signal condition\n");
                }

#endif
            }

            break;
        }

        case HSA_PACKET_TYPE_AGENT_DISPATCH:
            pAqlPacket = new(std::nothrow) HSAAqlAgentDispatchPacket(*static_cast<hsa_agent_dispatch_packet_t*>(pAqlPacketTrace->packet));
            break;

        case HSA_PACKET_TYPE_BARRIER_AND:
            pAqlPacket = new(std::nothrow) HSAAqlBarrierAndPacket(*static_cast<hsa_barrier_and_packet_t*>(pAqlPacketTrace->packet));
            break;

        case HSA_PACKET_TYPE_BARRIER_OR:
            pAqlPacket = new(std::nothrow) HSAAqlBarrierOrPacket(*static_cast<hsa_barrier_or_packet_t*>(pAqlPacketTrace->packet));
            break;

        default:
            break;
    }

    if (nullptr != pAqlPacket)
    {
        pAqlPacket->m_packetId = pAqlPacketTrace->packet_id;
        pAqlPacket->m_agent = pAqlPacketTrace->agent;
        pAqlPacket->m_pQueue = pAqlPacketTrace->queue;
        HSAAPIInfoManager::Instance()->AddAqlPacketEntry(pAqlPacket);
    }

    return HSA_STATUS_SUCCESS;
}

void HSA_APITrace_hsa_queue_create_PostCallHelper(hsa_status_t retVal, hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type, void(*callback)(hsa_status_t status, hsa_queue_t* source,
                                                  void* data), void* data, uint32_t private_segment_size, uint32_t group_segment_size, hsa_queue_t** queue)
{
    SP_UNREFERENCED_PARAMETER(agent);
    SP_UNREFERENCED_PARAMETER(size);
    SP_UNREFERENCED_PARAMETER(type);
    SP_UNREFERENCED_PARAMETER(callback);
    SP_UNREFERENCED_PARAMETER(data);
    SP_UNREFERENCED_PARAMETER(private_segment_size);
    SP_UNREFERENCED_PARAMETER(group_segment_size);

    if (HSA_STATUS_SUCCESS == retVal && nullptr != queue)
    {
        g_pRealAmdExtFunctions->hsa_amd_profiling_async_copy_enable_fn(true);
        HSAAPIInfoManager::Instance()->AddQueue(*queue);

        if (GlobalSettings::GetInstance()->m_params.m_bAqlPacketTracing)
        {
            HSAToolsRTModule* pToolsRTModule = HSARTModuleLoader<HSAToolsRTModule>::Instance()->GetHSARTModule();

            if (pToolsRTModule->IsModuleLoaded())
            {
                hsa_status_t localStatus = pToolsRTModule->ext_tools_register_aql_trace_callback(*queue, nullptr, AqlPacketTraceCallback);

                if (HSA_STATUS_SUCCESS != localStatus)
                {
                    GPULogger::Log(GPULogger::logERROR, "Error registering an Aql Trace Callback\n");
                    GlobalSettings::GetInstance()->m_params.m_bAqlPacketTracing = false;
                }
            }
        }
    }
}

void HSA_APITrace_hsa_executable_get_symbol_PostCallHelper(hsa_status_t retVal, hsa_executable_t executable, const char* module_name, const char* symbol_name, hsa_agent_t agent, int32_t call_convention, hsa_executable_symbol_t* symbol)
{
    SP_UNREFERENCED_PARAMETER(executable);
    SP_UNREFERENCED_PARAMETER(module_name);
    SP_UNREFERENCED_PARAMETER(agent);
    SP_UNREFERENCED_PARAMETER(call_convention);

    if (HSA_STATUS_SUCCESS == retVal && nullptr != symbol)
    {
        if (nullptr != symbol_name)
        {
            Log(logMESSAGE, "HSA_API_Trace_hsa_executable_get_symbol: Adding symbol handle/symbol name pair to FinalizerInfoManager\n");
            Log(logMESSAGE, "  SymHandle: %llu, SymName: %s \n", symbol->handle, symbol_name);
            FinalizerInfoManager::Instance()->m_symbolHandleToNameMap[symbol->handle] = std::string(symbol_name);

            uint64_t kernelObject;

            if (g_pRealCoreFunctions->hsa_executable_symbol_get_info_fn(*symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernelObject) == HSA_STATUS_SUCCESS)
            {
                Log(logMESSAGE, "HSA_API_Trace_hsa_executable_get_symbol: Adding code handle/symbol handle pair to FinalizerInfoManager\n");
                Log(logMESSAGE, "  CodeHandle: %llu, SymHandle: %llu\n", kernelObject, symbol->handle);
                FinalizerInfoManager::Instance()->m_codeHandleToSymbolHandleMap[kernelObject] = symbol->handle;
            }
        }
    }
}


void HSA_APITrace_hsa_executable_get_symbol_by_name_PostCallHelper(hsa_status_t retVal, hsa_executable_t executable, const char* symbol_name, const hsa_agent_t* agent, hsa_executable_symbol_t* symbol)
{
    SP_UNREFERENCED_PARAMETER(executable);
    SP_UNREFERENCED_PARAMETER(agent);

    if (HSA_STATUS_SUCCESS == retVal && nullptr != symbol)
    {
        if (nullptr != symbol_name)
        {
            Log(logMESSAGE, "HSA_API_Trace_hsa_executable_get_symbol_by_name: Adding symbol handle/symbol name pair to FinalizerInfoManager\n");
            Log(logMESSAGE, "  SymHandle: %llu, SymName: %s \n", symbol->handle, symbol_name);
            FinalizerInfoManager::Instance()->m_symbolHandleToNameMap[symbol->handle] = std::string(symbol_name);

            uint64_t kernelObject;

            if (g_pRealCoreFunctions->hsa_executable_symbol_get_info_fn(*symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernelObject) == HSA_STATUS_SUCCESS)
            {
                Log(logMESSAGE, "HSA_API_Trace_hsa_executable_get_symbol_by_name: Adding code handle/symbol handle pair to FinalizerInfoManager\n");
                Log(logMESSAGE, "  CodeHandle: %llu, SymHandle: %llu\n", kernelObject, symbol->handle);
                FinalizerInfoManager::Instance()->m_codeHandleToSymbolHandleMap[kernelObject] = symbol->handle;
            }
        }
    }
}


void HSA_APITrace_hsa_executable_symbol_get_info_PostCallHelper(hsa_status_t retVal, hsa_executable_symbol_t executable_symbol, hsa_executable_symbol_info_t attribute, void* value)
{
    SP_UNREFERENCED_PARAMETER(attribute);

    if (HSA_STATUS_SUCCESS == retVal && nullptr != value)
    {
        uint32_t symbolNameLength = 0;

        if (g_pRealCoreFunctions->hsa_executable_symbol_get_info_fn(executable_symbol, HSA_EXECUTABLE_SYMBOL_INFO_NAME_LENGTH, &symbolNameLength) == HSA_STATUS_SUCCESS)
        {
            if (symbolNameLength > 0)
            {
                char* tempSymbolName = new(std::nothrow) char[symbolNameLength + 1];

                if (nullptr != tempSymbolName)
                {
                    memcpy(tempSymbolName, value, symbolNameLength);
                    tempSymbolName[symbolNameLength] = '\0';
                    Log(logMESSAGE, "HSA_API_Trace_hsa_executable_get_symbol: Adding symbol handle/symbol name pair to FinalizerInfoManager\n");
                    Log(logMESSAGE, "  SymHandle: %llu, SymName: %s \n", executable_symbol.handle, tempSymbolName);
                    FinalizerInfoManager::Instance()->m_symbolHandleToNameMap[executable_symbol.handle] = std::string(tempSymbolName);
                    delete[] tempSymbolName;

                    uint64_t kernelObject;

                    if (g_pRealCoreFunctions->hsa_executable_symbol_get_info_fn(executable_symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernelObject) == HSA_STATUS_SUCCESS)
                    {
                        Log(logMESSAGE, "HSA_API_Trace_hsa_executable_get_symbol: Adding code handle/symbol handle pair to FinalizerInfoManager\n");
                        Log(logMESSAGE, "  CodeHandle: %llu, SymHandle: %llu\n", kernelObject, executable_symbol.handle);
                        FinalizerInfoManager::Instance()->m_codeHandleToSymbolHandleMap[kernelObject] = executable_symbol.handle;
                    }
                }
            }
        }
    }
}

void HSA_APITrace_hsa_amd_memory_async_copy_PreCallHelper(void* dst, hsa_agent_t dst_agent, const void* src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t* dep_signals, hsa_signal_t& completion_signal)
{
    SP_UNREFERENCED_PARAMETER(dst);
    SP_UNREFERENCED_PARAMETER(dst_agent);
    SP_UNREFERENCED_PARAMETER(src);
    SP_UNREFERENCED_PARAMETER(src_agent);
    SP_UNREFERENCED_PARAMETER(size);
    SP_UNREFERENCED_PARAMETER(num_dep_signals);
    SP_UNREFERENCED_PARAMETER(dep_signals);

    if (0 != completion_signal.handle)
    {
        hsa_signal_value_t origValue = g_pRealCoreFunctions->hsa_signal_load_scacquire_fn(completion_signal);

        hsa_signal_t replacementSignal;

        if (HSAAPIInfoManager::Instance()->IsCapReached() || !HSASignalPool::Instance()->AcquireSignal(origValue, replacementSignal))
        {
            replacementSignal = completion_signal;
        }
        else
        {
            HSAAPIInfoManager::Instance()->AddReplacementAsyncCopySignal(completion_signal, replacementSignal);
            HSAAPIInfoManager::Instance()->AddAsyncCopyCompletionSignal(replacementSignal);
            completion_signal = replacementSignal;
        }
    }
}
