//==============================================================================
// Copyright (c) 2015-2018 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief THIS CODE WAS AUTOGENERATED BY HSA CODE GENERATOR
//==============================================================================

#include "../HSATraceStringUtils.h"
#include "HSATraceStringOutput.h"

#include "HSAAMDAQLProfileExtensionAPITraceClasses.h"

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_version_major
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_version_major::HSA_APITrace_hsa_ven_amd_aqlprofile_version_major()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_version_major::~HSA_APITrace_hsa_ven_amd_aqlprofile_version_major()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_version_major::GetRetString()
{
    return StringUtils::ToString(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_version_major::ToString()
{
    return "";
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_version_major::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    uint32_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_version_major;
    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor::HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor::~HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor::GetRetString()
{
    return StringUtils::ToString(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor::ToString()
{
    return "";
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_version_minor::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    uint32_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_version_minor;
    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event::HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event::~HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event::ToString()
{
    std::ostringstream ss;
    ss << "agent=" << HSATraceStringUtils::Get_hsa_agent_t_String(m_agent) << s_strParamSeparator;
    ss << "event=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_event_t_Ptr_String(m_event, m_eventVal) << s_strParamSeparator;
    ss << "result=" << StringUtils::ToStringPtr(m_result, m_resultVal);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_validate_event::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    hsa_agent_t agent,
    const hsa_ven_amd_aqlprofile_event_t* event,
    bool* result,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_validate_event;
    m_agent = agent;
    m_event = event;

    if (nullptr != m_event)
    {
        m_eventVal = *m_event;
    }

    m_result = result;

    if (nullptr != m_result)
    {
        m_resultVal = *m_result;
    }

    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_start
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_start::HSA_APITrace_hsa_ven_amd_aqlprofile_start()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_start::~HSA_APITrace_hsa_ven_amd_aqlprofile_start()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_start::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_start::ToString()
{
    std::ostringstream ss;
    ss << "profile=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_profile_t_Ptr_String(m_profile, m_profileVal) << s_strParamSeparator;
    ss << "aql_start_packet=" << HSATraceStringUtils::Get_hsa_ext_amd_aql_pm4_packet_t_Ptr_String(m_aql_start_packet, m_aql_start_packetVal);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_start::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    hsa_ven_amd_aqlprofile_profile_t* profile,
    hsa_ext_amd_aql_pm4_packet_t* aql_start_packet,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_start;
    m_profile = profile;

    if (nullptr != m_profile)
    {
        m_profileVal = *m_profile;
    }

    m_aql_start_packet = aql_start_packet;

    if (nullptr != m_aql_start_packet)
    {
        m_aql_start_packetVal = *m_aql_start_packet;
    }

    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_stop
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_stop::HSA_APITrace_hsa_ven_amd_aqlprofile_stop()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_stop::~HSA_APITrace_hsa_ven_amd_aqlprofile_stop()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_stop::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_stop::ToString()
{
    std::ostringstream ss;
    ss << "profile=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_profile_t_Ptr_String(m_profile, m_profileVal) << s_strParamSeparator;
    ss << "aql_stop_packet=" << HSATraceStringUtils::Get_hsa_ext_amd_aql_pm4_packet_t_Ptr_String(m_aql_stop_packet, m_aql_stop_packetVal);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_stop::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    const hsa_ven_amd_aqlprofile_profile_t* profile,
    hsa_ext_amd_aql_pm4_packet_t* aql_stop_packet,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_stop;
    m_profile = profile;

    if (nullptr != m_profile)
    {
        m_profileVal = *m_profile;
    }

    m_aql_stop_packet = aql_stop_packet;

    if (nullptr != m_aql_stop_packet)
    {
        m_aql_stop_packetVal = *m_aql_stop_packet;
    }

    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_read
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_read::HSA_APITrace_hsa_ven_amd_aqlprofile_read()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_read::~HSA_APITrace_hsa_ven_amd_aqlprofile_read()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_read::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_read::ToString()
{
    std::ostringstream ss;
    ss << "profile=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_profile_t_Ptr_String(m_profile, m_profileVal) << s_strParamSeparator;
    ss << "aql_read_packet=" << HSATraceStringUtils::Get_hsa_ext_amd_aql_pm4_packet_t_Ptr_String(m_aql_read_packet, m_aql_read_packetVal);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_read::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    const hsa_ven_amd_aqlprofile_profile_t* profile,
    hsa_ext_amd_aql_pm4_packet_t* aql_read_packet,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_read;
    m_profile = profile;

    if (nullptr != m_profile)
    {
        m_profileVal = *m_profile;
    }

    m_aql_read_packet = aql_read_packet;

    if (nullptr != m_aql_read_packet)
    {
        m_aql_read_packetVal = *m_aql_read_packet;
    }

    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4::HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4::~HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4::ToString()
{
    std::ostringstream ss;
    ss << "aql_packet=" << HSATraceStringUtils::Get_hsa_ext_amd_aql_pm4_packet_t_Ptr_String(m_aql_packet, m_aql_packetVal) << s_strParamSeparator;
    ss << "data=" << StringUtils::ToHexString(m_data);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_legacy_get_pm4::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    const hsa_ext_amd_aql_pm4_packet_t* aql_packet,
    void* data,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_legacy_get_pm4;
    m_aql_packet = aql_packet;

    if (nullptr != m_aql_packet)
    {
        m_aql_packetVal = *m_aql_packet;
    }

    m_data = data;
    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_get_info
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_get_info::HSA_APITrace_hsa_ven_amd_aqlprofile_get_info() : m_value(nullptr)
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_get_info::~HSA_APITrace_hsa_ven_amd_aqlprofile_get_info()
{
    if (nullptr != m_value)
    {
        FreeBuffer(m_value);
    }
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_get_info::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_get_info::ToString()
{
    std::ostringstream ss;
    ss << "profile=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_profile_t_Ptr_String(m_profile, m_profileVal) << s_strParamSeparator;
    ss << "attribute=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_info_type_t_String(m_attribute) << s_strParamSeparator;
    ss << "value=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_get_info_AttributeString(m_value, m_attribute, m_retVal);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_get_info::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    const hsa_ven_amd_aqlprofile_profile_t* profile,
    hsa_ven_amd_aqlprofile_info_type_t attribute,
    void* value,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_get_info;
    m_profile = profile;

    if (nullptr != m_profile)
    {
        m_profileVal = *m_profile;
    }

    m_attribute = attribute;

    if (nullptr != value)
    {
        DeepCopyBuffer(&m_value, value, HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_get_info_AttributeSize(m_attribute));
    }

    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data::HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data::~HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data::ToString()
{
    std::ostringstream ss;
    ss << "profile=" << HSATraceStringUtils::Get_hsa_ven_amd_aqlprofile_profile_t_Ptr_String(m_profile, m_profileVal) << s_strParamSeparator;
    ss << "callback=" << StringUtils::ToString(reinterpret_cast<void*>(m_callback)) << s_strParamSeparator;
    ss << "data=" << StringUtils::ToHexString(m_data);
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_iterate_data::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    const hsa_ven_amd_aqlprofile_profile_t* profile,
    hsa_ven_amd_aqlprofile_data_callback_t callback,
    void* data,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_iterate_data;
    m_profile = profile;

    if (nullptr != m_profile)
    {
        m_profileVal = *m_profile;
    }

    m_callback = callback;
    m_data = data;
    m_retVal = retVal;
}

///////////////////////////////////////////////////
/// Class HSA_APITrace_hsa_ven_amd_aqlprofile_error_string
///////////////////////////////////////////////////

HSA_APITrace_hsa_ven_amd_aqlprofile_error_string::HSA_APITrace_hsa_ven_amd_aqlprofile_error_string()
{
}

HSA_APITrace_hsa_ven_amd_aqlprofile_error_string::~HSA_APITrace_hsa_ven_amd_aqlprofile_error_string()
{
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_error_string::GetRetString()
{
    return HSATraceStringUtils::Get_hsa_status_t_String(m_retVal);
}

std::string HSA_APITrace_hsa_ven_amd_aqlprofile_error_string::ToString()
{
    std::ostringstream ss;

    const char* multiple_indirection_str_helper = nullptr;

    if (nullptr != m_str)
    {
        multiple_indirection_str_helper = m_strVal.c_str();
    }
    ss << "str=" << HSATraceStringUtils::SurroundWithDeRef(HSATraceStringUtils::GetStringString(multiple_indirection_str_helper, m_strVal));
    return ss.str();
}

void HSA_APITrace_hsa_ven_amd_aqlprofile_error_string::Create(
    ULONGLONG ullStartTime,
    ULONGLONG ullEndTime,
    const char** str,
    hsa_status_t retVal)
{
    m_ullStart = ullStartTime;
    m_ullEnd = ullEndTime;
    m_type = HSA_API_Type_hsa_ven_amd_aqlprofile_error_string;
    m_str = str;

    if (nullptr != m_str && nullptr != *m_str)
    {
        m_strVal = std::string(*m_str);
    }
    else
    {
        m_strVal = "";
    }

    m_retVal = retVal;
}


