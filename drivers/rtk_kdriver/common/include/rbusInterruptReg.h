/**
* @file rbusInterruptReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_INTERRUPT_REG_H_
#define _RBUS_INTERRUPT_REG_H_

#include "rbusTypes.h"



//  INTERRUPT Register Address



#define  INTERRUPT_ALU_PASS_VADDR                           	(0xb8060068)
#define  INTERRUPT_ST_IP_VADDR                              	(0xb8060450)
#define  INTERRUPT_ST_IE_VADDR                              	(0xb8060454)
#define  INTERRUPT_MIS_ISR_VADDR                            	(0xb801b000)
#define  INTERRUPT_MIS_SCPU_INT_EN_VADDR                    	(0xb801b004)
#define  INTERRUPT_ISO_MISC_OFF_ISR_VADDR                   	(0xb8062100)
#define  INTERRUPT_ISO_MISC_OFF_INT_EN_VADDR                	(0xb8062104)
#define  INTERRUPT_ISO_ISR_VADDR                            	(0xb8061000)
#define  INTERRUPT_ISO_SCPU_INT_EN_VADDR                    	(0xb8061004)
#define  INTERRUPT_INT_CTRL_SCPU_VADDR                      	(0xb8000290)
#define  INTERRUPT_INT_CTRL_VCPU_VADDR                      	(0xb8000294)
#define  INTERRUPT_INT_CTRL_ACPU_VADDR                      	(0xb8000298)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======INTERRUPT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  stpass_self_wakeup:1;
        RBus_UInt32  stpass_rtc:1;
        RBus_UInt32  stpass_cec:1;
        RBus_UInt32  stpass_cbus:1;
        RBus_UInt32  stpass_iso_misc:1;
    };
}interrupt_alu_pass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  stip_wol:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_rbus:1;
        RBus_UInt32  stip_hdmi_clk_det:1;
        RBus_UInt32  stip_st_syncp:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_isomisc:1;
        RBus_UInt32  stip_isomisc_off:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_cbus_det:1;
    };
}interrupt_st_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  stie_wol:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_rbus:1;
        RBus_UInt32  stie_hdmi_clk_det:1;
        RBus_UInt32  stie_st_syncp:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_isomisc:1;
        RBus_UInt32  stie_isomisc_off:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_cbus_det:1;
    };
}interrupt_st_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2c1_int:1;
        RBus_UInt32  i2c2_int:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sc0_int:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pcmcia_int:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  tc7_int:1;
        RBus_UInt32  tc6_int:1;
        RBus_UInt32  tc5_int:1;
        RBus_UInt32  tc4_int:1;
        RBus_UInt32  tc3_int:1;
        RBus_UInt32  tc2_int:1;
        RBus_UInt32  tc1_int:1;
        RBus_UInt32  tc0_int:1;
        RBus_UInt32  ur1_int:1;
        RBus_UInt32  res8:6;
    };
}interrupt_mis_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  i2c1:1;
        RBus_UInt32  i2c2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sc0:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pcmcia:1;
        RBus_UInt32  gpio:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  ddc1:1;
        RBus_UInt32  tc7:1;
        RBus_UInt32  tc6:1;
        RBus_UInt32  tc5:1;
        RBus_UInt32  tc4:1;
        RBus_UInt32  tc3:1;
        RBus_UInt32  tc2:1;
        RBus_UInt32  tc1:1;
        RBus_UInt32  tc0:1;
        RBus_UInt32  ur1:1;
        RBus_UInt32  res6:6;
    };
}interrupt_mis_scpu_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:16;
        RBus_UInt32  timer_int:1;
        RBus_UInt32  wdog_ov_int:1;
        RBus_UInt32  irda1_int:1;
        RBus_UInt32  ur0_int:1;
        RBus_UInt32  i2c0_int:1;
        RBus_UInt32  res5:1;
    };
}interrupt_iso_misc_off_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:16;
        RBus_UInt32  timer_int:1;
        RBus_UInt32  wdog_ov_int:1;
        RBus_UInt32  irda1_int:1;
        RBus_UInt32  ur0_int:1;
        RBus_UInt32  i2c0_int:1;
        RBus_UInt32  res5:1;
    };
}interrupt_iso_misc_off_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  ddc0_int:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  ddc2_int:1;
        RBus_UInt32  ddc3_int:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  lsadc_int:1;
        RBus_UInt32  res10:4;
        RBus_UInt32  irda_int:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  artc_scpu_int:1;
        RBus_UInt32  artc_acpu_int:1;
        RBus_UInt32  iso_rtc_scpu_int:1;
        RBus_UInt32  iso_rtc_acpu_int:1;
    };
}interrupt_iso_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  ddc0_int:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  ddc2_int:1;
        RBus_UInt32  ddc3_int:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  lsadc_int:1;
        RBus_UInt32  res10:4;
        RBus_UInt32  irda_int:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
    };
}interrupt_iso_scpu_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  tve_int_scpu_routing_en:1;
        RBus_UInt32  dcphy_int_scpu_routing_en:1;
        RBus_UInt32  dc_int_scpu_routing_en:1;
        RBus_UInt32  osd_int_scpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_scpu_routing_en:1;
        RBus_UInt32  dctl_int_scpu_routing_en:1;
        RBus_UInt32  vbi_int_scpu_routing_en:1;
        RBus_UInt32  vdec_int_scpu_routing_en:1;
        RBus_UInt32  if_demod_int_scpu_routing_en:1;
        RBus_UInt32  dispm_int_scpu_routing_en:1;
        RBus_UInt32  dispi_int_scpu_routing_en:1;
        RBus_UInt32  apll_dds_int_scpu_routing_en:1;
        RBus_UInt32  ddc_int_scpu_routing_en:1;
        RBus_UInt32  vodma_int_scpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_scpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_scpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cec_int_scpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb3_dc1_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb2_dc1_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb1_dc1_int_scpu_routing_en:1;
        RBus_UInt32  osdcomp_int_scpu_routing_en:1;
    };
}interrupt_int_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tve_int_vcpu_routing_en:1;
        RBus_UInt32  dcphy_int_vcpu_routing_en:1;
        RBus_UInt32  dc_int_vcpu_routing_en:1;
        RBus_UInt32  osd_int_vcpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_vcpu_routing_en:1;
        RBus_UInt32  dctl_int_vcpu_routing_en:1;
        RBus_UInt32  vbi_int_vcpu_routing_en:1;
        RBus_UInt32  vdec_int_vcpu_routing_en:1;
        RBus_UInt32  if_demod_int_vcpu_routing_en:1;
        RBus_UInt32  dispm_int_vcpu_routing_en:1;
        RBus_UInt32  dispi_int_vcpu_routing_en:1;
        RBus_UInt32  apll_dds_int_vcpu_routing_en:1;
        RBus_UInt32  ddc_int_vcpu_routing_en:1;
        RBus_UInt32  vodma_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb3_dc1_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb2_dc1_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb1_dc1_int_vcpu_routing_en:1;
        RBus_UInt32  osdcomp_int_vcpu_routing_en:1;
    };
}interrupt_int_ctrl_vcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dcphy_int_acpu_routing_en:1;
        RBus_UInt32  dc_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb3_dc1_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb2_dc1_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb1_dc1_int_acpu_routing_en:1;
    };
}interrupt_int_ctrl_acpu_RBUS;

#else //apply LITTLE_ENDIAN

//======INTERRUPT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stpass_iso_misc:1;
        RBus_UInt32  stpass_cbus:1;
        RBus_UInt32  stpass_cec:1;
        RBus_UInt32  stpass_rtc:1;
        RBus_UInt32  stpass_self_wakeup:1;
        RBus_UInt32  res1:27;
    };
}interrupt_alu_pass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stip_cbus_det:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_isomisc_off:1;
        RBus_UInt32  stip_isomisc:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_st_syncp:1;
        RBus_UInt32  stip_hdmi_clk_det:1;
        RBus_UInt32  stip_rbus:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_wol:1;
        RBus_UInt32  res1:22;
    };
}interrupt_st_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stie_cbus_det:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_isomisc_off:1;
        RBus_UInt32  stie_isomisc:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_st_syncp:1;
        RBus_UInt32  stie_hdmi_clk_det:1;
        RBus_UInt32  stie_rbus:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_wol:1;
        RBus_UInt32  res1:22;
    };
}interrupt_st_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ur1_int:1;
        RBus_UInt32  tc0_int:1;
        RBus_UInt32  tc1_int:1;
        RBus_UInt32  tc2_int:1;
        RBus_UInt32  tc3_int:1;
        RBus_UInt32  tc4_int:1;
        RBus_UInt32  tc5_int:1;
        RBus_UInt32  tc6_int:1;
        RBus_UInt32  tc7_int:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  pcmcia_int:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  sc0_int:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  i2c2_int:1;
        RBus_UInt32  i2c1_int:1;
        RBus_UInt32  res8:4;
    };
}interrupt_mis_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ur1:1;
        RBus_UInt32  tc0:1;
        RBus_UInt32  tc1:1;
        RBus_UInt32  tc2:1;
        RBus_UInt32  tc3:1;
        RBus_UInt32  tc4:1;
        RBus_UInt32  tc5:1;
        RBus_UInt32  tc6:1;
        RBus_UInt32  tc7:1;
        RBus_UInt32  ddc1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  gpio:1;
        RBus_UInt32  pcmcia:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  sc0:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  i2c2:1;
        RBus_UInt32  i2c1:1;
        RBus_UInt32  res6:4;
    };
}interrupt_mis_scpu_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  i2c0_int:1;
        RBus_UInt32  ur0_int:1;
        RBus_UInt32  irda1_int:1;
        RBus_UInt32  wdog_ov_int:1;
        RBus_UInt32  timer_int:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:8;
    };
}interrupt_iso_misc_off_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  i2c0_int:1;
        RBus_UInt32  ur0_int:1;
        RBus_UInt32  irda1_int:1;
        RBus_UInt32  wdog_ov_int:1;
        RBus_UInt32  timer_int:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:8;
    };
}interrupt_iso_misc_off_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iso_rtc_acpu_int:1;
        RBus_UInt32  iso_rtc_scpu_int:1;
        RBus_UInt32  artc_acpu_int:1;
        RBus_UInt32  artc_scpu_int:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  irda_int:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  lsadc_int:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  ddc3_int:1;
        RBus_UInt32  ddc2_int:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  ddc0_int:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:8;
    };
}interrupt_iso_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  irda_int:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  lsadc_int:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  ddc3_int:1;
        RBus_UInt32  ddc2_int:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  ddc0_int:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:8;
    };
}interrupt_iso_scpu_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osdcomp_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb1_dc1_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb2_dc1_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb3_dc1_int_scpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cec_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_scpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_scpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_scpu_routing_en:1;
        RBus_UInt32  vodma_int_scpu_routing_en:1;
        RBus_UInt32  ddc_int_scpu_routing_en:1;
        RBus_UInt32  apll_dds_int_scpu_routing_en:1;
        RBus_UInt32  dispi_int_scpu_routing_en:1;
        RBus_UInt32  dispm_int_scpu_routing_en:1;
        RBus_UInt32  if_demod_int_scpu_routing_en:1;
        RBus_UInt32  vdec_int_scpu_routing_en:1;
        RBus_UInt32  vbi_int_scpu_routing_en:1;
        RBus_UInt32  dctl_int_scpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_scpu_routing_en:1;
        RBus_UInt32  osd_int_scpu_routing_en:1;
        RBus_UInt32  dc_int_scpu_routing_en:1;
        RBus_UInt32  dcphy_int_scpu_routing_en:1;
        RBus_UInt32  tve_int_scpu_routing_en:1;
        RBus_UInt32  res1:7;
    };
}interrupt_int_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osdcomp_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb1_dc1_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb2_dc1_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb3_dc1_int_vcpu_routing_en:1;
        RBus_UInt32  vodma_int_vcpu_routing_en:1;
        RBus_UInt32  ddc_int_vcpu_routing_en:1;
        RBus_UInt32  apll_dds_int_vcpu_routing_en:1;
        RBus_UInt32  dispi_int_vcpu_routing_en:1;
        RBus_UInt32  dispm_int_vcpu_routing_en:1;
        RBus_UInt32  if_demod_int_vcpu_routing_en:1;
        RBus_UInt32  vdec_int_vcpu_routing_en:1;
        RBus_UInt32  vbi_int_vcpu_routing_en:1;
        RBus_UInt32  dctl_int_vcpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_vcpu_routing_en:1;
        RBus_UInt32  osd_int_vcpu_routing_en:1;
        RBus_UInt32  dc_int_vcpu_routing_en:1;
        RBus_UInt32  dcphy_int_vcpu_routing_en:1;
        RBus_UInt32  tve_int_vcpu_routing_en:1;
        RBus_UInt32  res1:14;
    };
}interrupt_int_ctrl_vcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tv_sb1_dc1_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb2_dc1_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb3_dc1_int_acpu_routing_en:1;
        RBus_UInt32  dc_int_acpu_routing_en:1;
        RBus_UInt32  dcphy_int_acpu_routing_en:1;
        RBus_UInt32  res1:27;
    };
}interrupt_int_ctrl_acpu_RBUS;




#endif 


#endif 
