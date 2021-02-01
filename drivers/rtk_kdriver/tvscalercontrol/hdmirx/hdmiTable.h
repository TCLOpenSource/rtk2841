#ifndef __CUSTOM_HDMITABLE_H__
#define __CUSTOM_HDMITABLE_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <tvscalercontrol/hdmirx/board.h>


/*
K3L
#include "board/board.h"

TvServer
#include <Platform_Lib/Board/pcbMgr.h>
#include <Platform_Lib/Board/board.h>
#include <Platform_Lib/TVScalerControl/hdmiRx/hdmiFun.h>

QC
#include <qc_verify_common.h>
#include <hdmi_merlin2/hdmi_qc.h>
#include <hdmi_merlin2/hdmifun.h>
*/


extern void HdmiTable_Init(void);


#ifdef __cplusplus
}
#endif

#endif

