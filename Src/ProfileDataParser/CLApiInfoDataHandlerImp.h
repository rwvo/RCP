//==============================================================================
// Copyright (c) 2017 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief CLApiInfoDataHandler Implementation Header
//==============================================================================

#ifndef _CL_API_INFO_DATA_HANDLER_IMP_H_
#define _CL_API_INFO_DATA_HANDLER_IMP_H_

#include "ICLApiInfoDataHandler.h"
#include "../CLTraceAgent/CLAPIInfo.h"

/// CL Api Info Data Handler class
class CLAPIInfoDataHandler : public IAPIInfoDataHandler,
    public ICLAPIInfoDataHandler,
    public ICLEnqueueApiInfoDataHandler,
    public ICLMemApiInfoDataHandler,
    public ICLOtherEnqueueApiInfoDataHandler,
    public ICLDataEnqueueApiInfoDataHandler,
    public ICLKernelApiInfoDataHandler
{
public:
    ///Constructor
    /// \param[in] pClApiInfo cl api info
    CLAPIInfoDataHandler(CLAPIInfo* pClApiInfo) : m_pCLApiInfo(pClApiInfo)
    {
    }

    /// Checks clapiinfo is CLMemApiInfo or not
    /// \param[in,opt] ppClMemApiInfoDataHandler interface pointer to the clMemApiInfo if exists otherwise nullptr
    /// \return flag indicating clMempApiInfo or not
    bool IsCLMemoryApiInfo(ICLMemApiInfoDataHandler** ppClMemApiInfoDataHandler = nullptr) override;

    /// Checks clapiinfo is clEnqueueOtheroperations or not
    /// \param[in,opt] ppClEnqueueOtherOperations interface pointer to the clEnqueueOtheroperations if exists otherwise nullptr
    /// \return flag indicating clMempApiInfo or not
    bool IsCLEnqueueOtherOperations(ICLOtherEnqueueApiInfoDataHandler** ppClEnqueueOtherOperations = nullptr) override;

    /// Checks clapiinfo is clEnqueue api or not
    /// \param[in,opt] ppClEnqueueApiInfoDataHandler interface pointer to the clEnqueue if exists otherwise nullptr
    /// \return flag indicating clMempApiInfo or not
    bool IsCLEnqueueAPI(ICLEnqueueApiInfoDataHandler** ppClEnqueueApiInfoDataHandler = nullptr) override;

    /// Checks clapiinfo is clDataEnqueue api or not
    /// \param[in,opt] ppClDataEnqueueApiInfoDataHandler interface pointer to the clDataEnqueue if exists otherwise nullptr
    /// \return flag indicating clMempApiInfo or not
    bool IsCLDataEnqueueApi(ICLDataEnqueueApiInfoDataHandler** ppClDataEnqueueApiInfoDataHandler = nullptr) override;

    /// Checks clapiinfo is clKernelApiInfo or not
    /// \param[in,opt] ppClKernelApiInfoDataHandler interface pointer to the clKernelApiInfo if exists otherwise nullptr
    /// \return flag indicating clMempApiInfo or not
    bool IsCLKernelApiInfo(ICLKernelApiInfoDataHandler** ppClKernelApiInfoDataHandler = nullptr) override;

    /// Returns the casted Common Api Information data handler access pointer
    /// \return api info data handler interface pointer
    IAPIInfoDataHandler* GetApiInfoDataHandler() override;

    /// Gets the api start time
    /// \return start time of the api
    ULONGLONG GetApiStartTime() const override;

    /// Gets the end time of the api
    /// \return end time of the api
    ULONGLONG GetApiEndTime() const override;

    /// Gets the sequence id of the api
    /// \return sequence id of the api
    unsigned int GetApiSequenceId() const override;

    /// Gets the displayable sequence id of the api
    /// \return sequence id for the display
    unsigned int GetApiDisplaySequenceId() const override;

    /// Checks api available for displaybale sequence or not
    /// \return flag indicating api is displayable sequence or not
    bool IsApiSequenceIdDisplayble() const override;

    /// Get the thread id of the api
    /// \return thread id of the api
    osThreadId GetApiThreadId() const override;

    /// Get the return type of the api as string
    /// \return return type of api
    std::string GetApiRetString() const override;

    /// Get the api name as string
    /// \return name of the api as string
    std::string GetApiNameString() const override;

    /// Get the argument list of the api as string
    /// \return argument list of the api as string
    std::string GetApiArgListString() const override;

    /// Gets the cl api type
    /// \return api Type
    CLAPIType GetCLApiType() const override;

    /// Get the OpenCl Api Id
    /// \return api id
    unsigned int GetCLApiId() const override;

    /// Get the comment string
    /// \return comment String
    std::string GetCLApiComment() const override;

    /// Checks the Enqueue information is missing or not
    /// \return flag indicating Enqueue information is present or not
    bool IsCLEnqueueInformationMissing() const override;

    /// Get the CLEnqueue command type string
    /// \return command type string
    std::string GetCLCommandTypeString() const override;

    /// Get the CL Device name string
    /// \return cl device name
    std::string GetCLDeviceNameString() const override;

    /// Get the CL context handle string
    /// \return cl context handle string
    std::string GetCLContextHandleString() const override;

    /// Get the CL Command Queue Handle string
    /// \return cl command queue handle string
    std::string GetCLCommandQueueHandleString() const override;

    /// Get the cl event handle string
    /// \return cl event hadnle string
    std::string GetCLEventHandleString() const override;

    /// Get the CL queue timestamp
    /// \return cl queue timestamp
    ULONGLONG GetCLQueueTimestamp() const override;

    /// Get the CL submit timestamp
    /// \return cl submit timestamp
    ULONGLONG GetCLSubmitTimestamp() const override;

    /// Get the CL running timestamp
    /// \return cl running timestamp
    ULONGLONG GetCLRunningTimestamp() const override;

    /// Get the CL complete timestamp
    /// \return cl complete timestamp
    ULONGLONG GetCLCompleteTimestamp() const override;

    /// Get the CL command type enum
    /// \return cl command type enum
    unsigned int GetCLCommandTypeEnum() const override;

    /// Get the CL queue id
    /// \return cl queue id
    unsigned int GetCLQueueId() const override;

    /// Get the CL context id
    /// \return cl context id
    unsigned int GetCLContextId() const override;

    /// Get the CL memory Transfer size
    /// \return cl memory size
    unsigned int GetCLMemoryTransferSize() const override;

    /// Get the CL Data transfer size
    /// \return data transfer size
    unsigned int GetCLDataTransferSize() const override;

    /// Get the CL kernel handle String
    /// \return kernel handle as string
    std::string GetCLKernelHandleString() const override;

    /// Get the CL Kernel name
    /// \return kernel name
    std::string GetCLKernelNameString() const override;

    /// Get the CL kernel work group size
    /// \return kernel work group size
    std::string GetCLKernelWorkGroupSize() const override;

    /// Get the CL global work group size
    /// \return kernel global work group size
    std::string GetCLKernelGlobalWorkGroupSize() const override;

    ///Destructor
    ~CLAPIInfoDataHandler() = default;

private:
    CLAPIInfo* m_pCLApiInfo;             ///< pointer to clApiInfo
};

#endif // _CL_API_INFO_DATA_HANDLER_IMP_H_
