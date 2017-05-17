//==============================================================================
// Copyright (c) 2015-2017 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief THIS CODE WAS AUTOGENERATED BY PASSTHROUGHGENERATOR ON 04/13/17
//==============================================================================

#ifndef _HSARETCODEANALYZERHELPER_H_
#define _HSARETCODEANALYZERHELPER_H_

#include <set>
#include "../HSAFdnCommon/HSAFunctionDefs.h"

typedef std::set<HSA_API_Type> HSAAPITypeSet;

void GetNoReturnCodeAPIs(HSAAPITypeSet& noReturnCodeAPIs);

#endif // _HSARETCODEANALYZERHELPER_H_

