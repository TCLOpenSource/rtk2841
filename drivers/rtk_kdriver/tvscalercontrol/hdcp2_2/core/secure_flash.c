/**
 * SPU secure flash API
 *
 * INTEL CONFIDENTIAL
 * Copyright 2010-2011 Intel Corporation All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its
 * suppliers or licensors.  Title to the Material remains with Intel
 * Corporation or its suppliers and licensors.  The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * suppliers and licensors.  The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials,  either expressly, by implication, inducement,
 * estoppel or otherwise.  Any license under such intellectual property
 * rights must be express and approved by Intel in writing.
 */

/**
 * This file contains the method for loading serialization data
 * from secure flash.
 */

/**
 * Includes
 */
#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_session.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_messages.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_interface.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_rcp_api.h>
/*
 * This is for including the fake serialization data defined in the
 * HDCP-2.0 Errata. This should not be include for production builds.
 */

#ifdef DEBUG_MAIN
#define LOCALDBG ENABLE
#else
#define LOCALDBG DISABLE
#endif

#define INFO LOCALDBG

