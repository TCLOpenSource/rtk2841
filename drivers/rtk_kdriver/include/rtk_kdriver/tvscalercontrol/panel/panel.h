#ifndef __PANEL_H__
#define __PANEL_H__
#include "rtd_types.h"
//#include "panel/panel_autoconf.h"
#include <panelConfigParameter.h>
//#define CONFIG_PANEL_BENQ_22 1
#define CONFIG_PANEL_DEFAULT_4K2K_600M_VBY1_1S8L 1


#ifdef CONFIG_PANEL_lg_42_420WUN_SAA1_3D_PR
	#define PANEL_NAME	"lg_42_420WUN_SAA1_3D_PR"
	#define PANEL_SIZE		"42"
	#include <panel/lg_42_420WUN_SAA1_3D_PR.h>
#endif

#ifdef CONFIG_PANEL_lg_47_470WUN_SAA1_3D_PR
	#define PANEL_NAME	"lg_47_470WUN_SAA1_3D_PR"
	#define PANEL_SIZE		"47"
	#include <panel/lg_47_470WUN_SAA1_3D_PR.h>
#endif

#ifdef CONFIG_PANEL_lg_55_550WUN_SAA1_3D_PR
	#define PANEL_NAME	"lg_55_550WUN_SAA1_3D_PR"
	#define PANEL_SIZE		"55"
	#include <panel/lg_55_550WUN_SAA1_3D_PR.h>
#endif

//----------------------------------------------
// AUO
//----------------------------------------------
#ifdef CONFIG_PANEL_AU_M170EG01
	#define PANEL_NAME	"au_m170eg01"
	#define PANEL_SIZE		"17"
	#include <panel/au_m170eg01.h>
#endif

#ifdef CONFIG_PANEL_AU170_480p
	#define PANEL_NAME	"au_m170eg01_480p"
	#define PANEL_SIZE		"17"
	#include <panel/au_m170eg01_480p.h>
#endif

#ifdef CONFIG_PANEL_AU_M190PW01
	#define PANEL_NAME	"au_m190pw01"
	#define PANEL_SIZE		"19"
	#include <panel/au_m190pw01.h>
#endif

#ifdef CONFIG_PANEL_AU_T200XW02
	#define PANEL_NAME	"au_t200xw02"
	#define PANEL_SIZE		"17"
	#include <panel/au_t200xw02.h>
#endif

#ifdef CONFIG_PANEL_AU_M220EW01//y
	#define PANEL_NAME	"au_m220ew01"
	#define PANEL_SIZE		"22"
	#include <panel/au_m220ew01.h>
#endif

#ifdef CONFIG_PANEL_AUM24HW01
	#define PANEL_NAME	"au_m240hw_01"
	#define PANEL_SIZE		"24"
	#include <panel/au_m240hw_01.h>
#endif

#ifdef CONFIG_PANEL_AUO_T240XVN01
	#define PANEL_NAME	"au_t240xvn01"
	#define PANEL_SIZE	"24"
	#include <panel/au_t240xvn01.h>
#endif

#ifdef CONFIG_PANEL_AUT315XW01
	#define PANEL_NAME	"au_t315xw01"
	#define PANEL_SIZE		"31"
	#include <panel/au_t315xw01.h>
#endif

#ifdef CONFIG_PANEL_AUT315XW02
	#define PANEL_NAME	"au_t315xw02"
	#define PANEL_SIZE		"31"
	#include <panel/au_t315xw02.h>
#endif

#ifdef CONFIG_PANEL_auo_32_T315HB01
	#define PANEL_NAME	"auo_32_T315HB01"
	#define PANEL_SIZE		"32"
	#include <panel/auo_32_T315HB01.h>
#endif

#ifdef CONFIG_PANEL_AUT32PV320TVM  //For Proview AU32" panel//2007-12-28 12:40
	#define PANEL_NAME	"au_pv320tvm"
	#define PANEL_SIZE		"32"
	#include <panel/au_pv320tvm.h>
#endif

#ifdef CONFIG_PANEL_AUT37PV370TVM  //For Proview AU37" panel//2008-1-24
	#define PANEL_NAME	"au_pv370tvm"
	#define PANEL_SIZE		"37"
	#include <panel/au_pv370tvm.h>
#endif

#ifdef CONFIG_PANEL_AUT37DXW02
	#define PANEL_NAME	"au_t37dxw02"
	#define PANEL_SIZE		"37"
	#include <panel/au_37_120Hz.h>
#endif

#ifdef CONFIG_PANEL_AUT370HW02
	#define PANEL_NAME	"au_t370hw02"
	#define PANEL_SIZE		"37"
	#include <panel/au_t370hw02.h>
#endif

#ifdef CONFIG_PANEL_AU_T420HW02V4
	#define PANEL_NAME	"au_t420hw02v4"
	#define PANEL_SIZE		"42"
	#include <panel/au_t420hw02v4.h>
#endif

#ifdef CONFIG_PANEL_AU_T420HW06
	#define PANEL_NAME	"au_t420hw06"
	#define PANEL_SIZE		"42"
	#include <panel/au_t420hw06.h>
#endif

#ifdef CONFIG_PANEL_auo_46_T460HVD01
	#define PANEL_NAME	"auo_46_T460HVD01"
	#define PANEL_SIZE		"46"
	#include <panel/auo_46_T460HVD01.h>
#endif

#ifdef CONFIG_PANEL_auo_55_T550HVD02
	#define PANEL_NAME	"auo_55_T550HVD02"
	#define PANEL_SIZE		"55"
	#include <panel/auo_55_T550HVD02.h>
#endif

#ifdef CONFIG_PANEL_auo_55_T550QVF01_PA168
	#define PANEL_NAME	"auo_55_T550QVF01_PA168"
	#define PANEL_SIZE		"55"
	#include <panel/au_t550QVF01_PA168.h>
#endif

#ifdef CONFIG_PANEL_AUO_42_T420HW09
    #define PANEL_NAME      "auo_42_T420HW09"
	#define PANEL_SIZE		"42"
    #include <panel/auo_42_t420hw09.h>
#endif


#ifdef CONFIG_PANEL_sansum_32_LTA320HN03
        #define PANEL_NAME      "sansum_32_LTA320HN03"
	#define PANEL_SIZE		"32"
        #include <panel/sansum_32_LTA320HN03.h>
#endif

#ifdef CONFIG_PANEL_sansum_48_LTA480HN01
	#define PANEL_NAME	"sansum_48_LTA480HN01"
	#define PANEL_SIZE		"48"
	#include <panel/sansum_48_LTA480HN01.h>
#endif

#ifdef CONFIG_PANEL_h_42_H420DFC
	#define PANEL_NAME	"h_42_H420DFC"
	#define PANEL_SIZE		"42"
	#include <panel/h_42_H420DFC.h>
#endif

#ifdef CONFIG_PANEL_auo_T320XW04V3
	#define PANEL_NAME	"auo_t320xw04v3"
	#define PANEL_SIZE		"32"
	#include <panel/tsb_auo_t320xw04_v3.h>
#endif
//----------------------------------------------
// BENQ
//----------------------------------------------
#ifdef CONFIG_PANEL_BENQ_22
	#define PANEL_NAME	"benq_e220hd"
	#define PANEL_SIZE		"22"
	#include <tvscalercontrol/panel/benq_e220hd.h>
#endif
#ifdef CONFIG_PANEL_DEFAULT_4K2K_600M_VBY1_1S8L
	#define PANEL_NAME	"inx8903_4k2k60_vby1"
	#define PANEL_SIZE		"42"
	#include <tvscalercontrol/panel/Default_4K2K_600M_VBY1_1Seg8Port.h>
#endif
#ifdef CONFIG_PANEL_BENQ_22_HFS3D
	#define PANEL_NAME	"benq_e220hd_HFS3D"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_HFS3D.h>
#endif
#ifdef CONFIG_PANEL_SEL320HY
	#define PANEL_NAME	"sel320hy"
	#define PANEL_SIZE		"32"
	#include <panel/sel320hy.h>
#endif
#ifdef CONFIG_PANEL_HAIER_COMMON
	#define PANEL_NAME	"haier_common_panel"
	#define PANEL_SIZE		"22"
	#include <panel/haier_common_panel.h>
#endif

#ifdef CONFIG_PANEL_SKY_SDL550FY_LDF
	#define PANEL_NAME	"sky_sdl550"
	#define PANEL_SIZE		"55"
	#include <panel/sky_SDL550FY_LDF.h>
#endif
#ifdef CONFIG_PANEL_SKY_SDL470FY_LDF
	#define PANEL_NAME	"sky_sdl470"
	#define PANEL_SIZE		"47"
	#include <panel/sky_SDL470FY_LDF.h>
#endif
#ifdef CONFIG_PANEL_SKY_RDL420FY_ADF
	#define PANEL_NAME	"sky_rdl420"
	#define PANEL_SIZE		"42"
	#include <panel/sky_RDL420FY_ADF.h>
#endif
#ifdef CONFIG_PANEL_SKY_V420DK1_LS1
	#define PANEL_NAME	"sky_v420dk1"
	#define PANEL_SIZE		"42"
	#include <panel/sky_V420DK1_LS1.h>
#endif
#ifdef CONFIG_PANEL_SKY_V500DK2_LS1
	#define PANEL_NAME	"sky_v500dk2"
	#define PANEL_SIZE		"50"
	#include <panel/sky_V500DK2_LS1.h>
#endif
#ifdef CONFIG_PANEL_SKYWORTH_REL320AH
	#define PANEL_NAME	"skyworth_rel320ah"
	#define PANEL_SIZE		"32"
	#include <panel/skyworth_rel320ah.h>
#endif
#ifdef CONFIG_PANEL_SKY_REL420FY
	#define PANEL_NAME	"skyworth_rel420fy"
	#define PANEL_SIZE		"42"
	#include <panel/sky_REL420FY.h>
#endif
#ifdef CONFIG_PANEL_HTR_236_1920_1080
	#define PANEL_NAME	"HTR_236hd"
	#define PANEL_SIZE		"23.6"
	#include <panel/HTR_236_1920_1080.h>
#endif
#ifdef CONFIG_PANEL_HTR_236_1366_768
	#define PANEL_NAME	"HTR_236sd"
	#define PANEL_SIZE		"23.6"
	#include <panel/HTR_236_1366_768.h>
#endif
#ifdef CONFIG_PANEL_HTR_141_1366_768
	#define PANEL_NAME	"HTR_141sd"
	#define PANEL_SIZE		"14.1"
	#include <panel/HTR_141_1366_768.h>
#endif
#ifdef CONFIG_PANEL_BENQ_22_3D_PR
    #define PANEL_NAME      "benq_e220hd_3D_PR"
	#define PANEL_SIZE		"22"
    #include <panel/benq_e220hd_PR3D.h>
#endif
#ifdef CONFIG_PANEL_CMO_V390HK1_HISENSE
    #define PANEL_NAME      "cmo_v390hk1_hisense"
	#define PANEL_SIZE		"39"
    #include <panel/cmo_v390hk1_hisense.h>
#endif

#ifdef CONFIG_PANEL_ST_315A05_1_HISENSE
    #define PANEL_NAME      "ST_315A05_1_Hisense"
	#define PANEL_SIZE		"32"
    #include <panel/ST_315A05_1_Hisense.h>
#endif


#ifdef CONFIG_PANEL_BENQ_22_3D_SG
	#define PANEL_NAME	"benq_3d_e220hd_3D_SG"
	#define PANEL_SIZE		"22"
	#include <panel/benq_3d_e220hd.h>
#endif

#ifdef CONFIG_PANEL_CMO_M185BGEL22
	#define PANEL_NAME	"cmi_m185bge_l22"
	#define PANEL_SIZE		"19"
	#include <panel/cmo_m185bge_l22.h>
#endif

#ifdef CONFIG_PANEL_CMI_24_3D
#define PANEL_NAME	"cmi_3d_panel"
	#define PANEL_SIZE		"24"
#include <panel/cmi_3d_panel.h>
#endif


//----------------------------------------------
// CMO
//----------------------------------------------
#ifdef CONFIG_PANEL_CMO_M190A1L02
	#define PANEL_NAME	"cmo_m190a1_l02"
	#define PANEL_SIZE		"19"
	#include <panel/cmo_m190a1_l02.h>
#endif

#ifdef	CONFIG_PANEL_CMO_V216
	#define PANEL_NAME	"cmo_v216"
	#define PANEL_SIZE		"21"
	#include <panel/cmo_v216.h>
#endif

#ifdef CONFIG_PANEL_CMO_V260B1L02
	#define PANEL_NAME	"cmo_v260b1l01"
	#define PANEL_SIZE		"26"
	#include <panel/cmo_v260b1l01.h>
#endif

#ifdef CONFIG_PANEL_CMO_V315B1
	#define PANEL_NAME	"cmo_v315b1"
	#define PANEL_SIZE		"31"
	#include <panel/cmo_v315b1.h>
#endif

#ifdef CONFIG_PANEL_CMO_V315B3
	#define PANEL_NAME	"cmo_v315b3"
	#define PANEL_SIZE		"31"
	#include <panel/cmo_v315b3.h>
#endif

#ifdef CONFIG_PANEL_CMO_V320B1L02
	#define PANEL_NAME	"cmo_v320b1l01"
	#define PANEL_SIZE		"32"
	#include <panel/cmo_v320b1l01.h>
#endif

#ifdef CONFIG_PANEL_CMO_V320B1L07
	#define PANEL_NAME	"cmo_v320b1l07"
	#define PANEL_SIZE		"32"
	#include <panel/cmo_v320b1l07.h>
#endif

#ifdef CONFIG_PANEL_CMO_V420B1_LH1
	#define PANEL_NAME	"cmo_v420b1_lh1"
	#define PANEL_SIZE		"42"
	#include <panel/cmo_v420b1_lh1.h>
#endif

#ifdef CONFIG_PANEL_CMO_V420H1
	#define PANEL_NAME	"cmo_v420h1"
	#define PANEL_SIZE		"42"
	#include <panel/cmo_v420h1.h>
#endif

#ifdef CONFIG_PANEL_CMO_V420H1_L15
	#define PANEL_NAME	"cmo_v420h1"
	#define PANEL_SIZE		"42"
	#include <panel/cmo_v420h1.h>
#endif

#ifdef CONFIG_PANEL_CMO_216H_1080P
	#define PANEL_NAME	"cmo_m216h1_1080p"
	#define PANEL_SIZE		"21"
	#include <panel/cmo_m216h1-L01_1080p.h>
#endif

#ifdef CONFIG_PANEL_CMO_270H_1080P
	#define PANEL_NAME	"cmo_m270h1_1080p"
	#define PANEL_SIZE		"27"
	#include <panel/cmo_m270h1-L01_1080p.h>
#endif

#ifdef CONFIG_PANEL_cmo_V400HJ2PE1
	#define PANEL_NAME	"cmo_v400hj2pe1"
	#define PANEL_SIZE		"40"
	#include <panel/tsb_cmo_v400hj2pe1.h>
#endif

#ifdef CONFIG_PANEL_cmo_V320BJ3P01
	#define PANEL_NAME	"cmo_v320bj3po1"
	#define PANEL_SIZE		"32"
	#include <panel/tsb_cmo_v320bj3p01.h>
#endif

#ifdef CONFIG_PANEL_cmo_V320BJ6PE1
        #define PANEL_NAME      "cmo_v320bj6pe1"
        #define PANEL_SIZE              "32"
        #include <panel/tsb_cmo_v320bj6pe1.h>
#endif

#ifdef CONFIG_PANEL_SKYWORTH_REL320AH
	#define PANEL_NAME	"skyworth_rel320ah"
	#define PANEL_SIZE		"32"
	#include <panel/skyworth_rel320ah.h>
#endif
#ifdef CONFIG_PANEL_CMI_236_V236BJ1_LE1
	#define PANEL_NAME	"cmi_v236bj1-le1"
	#define PANEL_SIZE		"23.6"
	#include <panel/cmi_v236bj1-le1.h>
#endif
#ifdef CONFIG_PANEL_CMI_39_V390HJ1_PE1
    #define PANEL_NAME      "cmi_v390hj1pe1"
	#define PANEL_SIZE		"39"
    #include <panel/cmi_v390hj1_pe1.h>
#endif

//===skyworth 8R55-39E500E====//

#ifdef CONFIG_PANEL_SKYWORTH_SEL390V7_S05A
    #define PANEL_NAME      "skyworth_sel390v7_s05a"
	#define PANEL_SIZE		"39"
    #include <panel/skyworth_sel390v7_s05a.h>
#endif

#ifdef CONFIG_PANEL_CMI_V500DK1
#define PANEL_NAME	"cmi_3d_v500dk1"
#include <panel/cmi_3d_v500dk1.h>
#endif

#ifdef CONFIG_PANEL_CMI_V650DK1
#define PANEL_NAME	"cmi_3d_v650dk1"
#include <panel/cmi_3d_v650dk1.h>
#endif

//----------------------------------------------
// CPT
//----------------------------------------------
#ifdef CONFIG_PANEL_CPT_32
	#define PANEL_NAME	"cpt_32"
	#define PANEL_SIZE		"32"
	#include <panel/cpt_32.h>
#endif



//----------------------------------------------
// HITACHI
//----------------------------------------------
#ifdef CONFIG_PANEL_HT_32
	#define PANEL_NAME	"ht_32"
	#define PANEL_SIZE		"32"
	#include <panel/ht_32.h>
#endif

#ifdef CONFIG_PANEL_HT_32_TX80D16
	#define PANEL_NAME	"ht_32_tx80d16"
	#define PANEL_SIZE		"32"
	#include <panel/ht_32_tx80d16.h>
#endif

//----------------------------------------------
// LG
//----------------------------------------------
#ifdef CONFIG_PANEL_LG_LB150X02
	#define PANEL_NAME	"lg_15"
	#define PANEL_SIZE		"15"
	#include <panel/lg_lb150x02.h>
#endif

#ifdef CONFIG_PANEL_LG_32
	#define PANEL_NAME	"lg_32"
	#define PANEL_SIZE		"32"
	#include <panel/lg_32.h>
#endif

#ifdef CONFIG_PANEL_LG_LC320W01
	#define PANEL_NAME	"lg_lc320w01"
	#define PANEL_SIZE		"32"
	#include <panel/lg_lc320w01.h>
#endif

#ifdef CONFIG_PANEL_LG_LC320WXE_SBB1
	#define PANEL_NAME	"lg_lc320wxe_sbb1"
	#define PANEL_SIZE		"32"
	#include <panel/lg_lc320wxe_sbb1.h>
#endif


#ifdef CONFIG_PANEL_LG_LC320WUN_SAA1
	#define PANEL_NAME	"lg_lc320wun_saa1"
	#define PANEL_SIZE		"32"
	#include <panel/lg_lc320wun_saa1.h>
#endif

#ifdef CONFIG_PANEL_LG_LC320EUD
	#define PANEL_NAME	"lg_lc320eud_120hz.h"
	#define PANEL_SIZE		"32"
	#include <panel/lg_lc320eud_120hz.h>
#endif


#ifdef CONFIG_PANEL_LG_37
	#define PANEL_NAME	"lg_37"
	#define PANEL_SIZE		"37"
	#include <panel/lg_37.h>
#endif

#ifdef CONFIG_PANEL_LG_V420V02
	#define PANEL_NAME	"lg_lc420v02"
	#define PANEL_SIZE		"42"
	#include <panel/lg_lc420v02.h>
#endif

#ifdef CONFIG_PANEL_LG_420WUNSAA1
	#define PANEL_NAME	"lg_42_420WUN_SAA1"
	#define PANEL_SIZE		"42"
	#include <panel/lg_42_420WUN_SAA1.h>
#endif

#ifdef CONFIG_PANEL_LG_LC420EUD_SCA1
	#define PANEL_NAME	"lg_lc420eud_sca1"
	#define PANEL_SIZE		"42"
	#include <panel/lg_lc420eud_sca1.h>
#endif


#ifdef CONFIG_PANEL_LG_47
	#define PANEL_NAME	"lg_47"
	#define PANEL_SIZE		"47"
	#include <panel/lg_47.h>
#endif

//USER: Vincent_Lee  DATE: 2011/11/9  TODO: Add new panel param for Project E650
#ifdef CONFIG_PANEL_lg_LC320EUN_SEF1
	#define PANEL_NAME	"lg_LC320EUN_SEF1"
	#define PANEL_SIZE		"32"
	#include <panel/lg_LC320EUN_SEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC420EUN_SEF1
	#define PANEL_NAME	"lg_LC420EUN_SEF1"
	#define PANEL_SIZE		"42"
	#include <panel/lg_LC420EUN_SEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC470EUN_SEF1
	#define PANEL_NAME	"lg_LC470EUN_SEF1"
	#define PANEL_SIZE		"47"
	#include <panel/lg_LC470EUN_SEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC550EUN_SEF1
	#define PANEL_NAME	"lg_LC550EUN_SEF1"
	#define PANEL_SIZE		"55"
	#include <panel/lg_LC550EUN_SEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC420EUN_FEF1
	#define PANEL_NAME	"lg_LC420EUN_FEF1"
	#define PANEL_SIZE		"42"
	#include <panel/lg_LC420EUN_FEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC470EUN_FEF1
	#define PANEL_NAME	"lg_LC470EUN_FEF1"
	#define PANEL_SIZE		"47"
	#include <panel/lg_LC470EUN_FEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC550EUN_FEF1
	#define PANEL_NAME	"lg_LC550EUN_FEF1"
	#define PANEL_SIZE		"55"
	#include <panel/lg_LC550EUN_FEF1.h>
#endif

#ifdef CONFIG_PANEL_lg_LC230EUE_SEA1
	#define PANEL_NAME	"lg_LC230EUE_SEA1"
	#define PANEL_SIZE		"23"
	#include <panel/tsb_lg_lc230eue_sea1.h>
#endif

#ifdef CONFIG_PANEL_HAIER_LC230EUE_SEA1
	#define PANEL_NAME	"lg_LC230EUE_SEA1"
	#define PANEL_SIZE		"23"
	#include <panel/haier_lg_lc230eue_sea1.h>
#endif

//----------------------------------------------
// MT
//----------------------------------------------
#ifdef CONFIG_PANEL_MT_19AW01
	#define PANEL_NAME	"mt19aw01"
	#define PANEL_SIZE		"19"
	#include	<panel/mt19aw01.h>
#endif



//----------------------------------------------
// SAMSUNG
//----------------------------------------------
#ifdef CONFIG_PANEL_SAMSUNG_32
	#define PANEL_NAME	"samsung_32"
	#define PANEL_SIZE		"32"
	#include <panel/samsung_32.h>
#endif

#ifdef CONFIG_PANEL_SAMSUNG_46
	#define PANEL_NAME	"samsung_46"
	#define PANEL_SIZE		"46"
	#include <panel/samsung_46.h>
#endif

#ifdef CONFIG_PANEL_SAMSUNG_LSC400HM03
	#define PANEL_NAME	"tsb_samsung_lsc400hm03"
	#define PANEL_SIZE		"40"
	#include <panel/tsb_samsung_lsc400hm03.h>
#endif

#ifdef CONFIG_PANEL_SAMSUNG_LSC320AN02
	#define PANEL_NAME	"tsb_samsung_lsc320an02"
	#define PANEL_SIZE		"32"
	#include <panel/tsb_samsung_lsc320an02.h>
#endif
//----------------------------------------------
// SHARP
//----------------------------------------------
#ifdef CONFIG_PANEL_SHARP_12WXGA
	#define PANEL_NAME	"sharp_12wxga"
	#define PANEL_SIZE		"12"
	#include <panel/sharp_12WXGA.h>
#endif

#ifdef CONFIG_PANEL_SHARP12_on_AU17
	#define PANEL_NAME	"sharp12_on_au17"
	#define PANEL_SIZE		"12"
	#include <panel/sharp_12_on_au_17.h>
#endif

#ifdef CONFIG_PANEL_SHARP_40_LK400D3LA14
	#define PANEL_NAME	"sharp_40_lk400d3la14"
	#define PANEL_SIZE		"40"
	#include	<panel/sharp_40_LK400D3LA14.h>
#endif //#ifdef CONFIG_PANEL_SHARP_40_LK400D3LA14

//------------------------------------------------
//    Skyworth
//------------------------------------------------
#ifdef CONFIG_PANEL_SKYWORTH_32_REL320QH
	#define PANEL_NAME	"skyworth_32_rel320qh"
	#define PANEL_SIZE		"32"
	#include <panel/skyworth_32_rel320qh.h>
#endif

#ifdef CONFIG_PANEL_SKYWORTH_37_REL370BH
	#define PANEL_NAME	"skyworth_37_rel370bh"
	#define PANEL_SIZE		"37"
	#include <panel/skyworth_37_rel370bh.h>
#endif
//-------------------------------------------------
// TPV
//-------------------------------------------------

#ifdef CONFIG_PANEL_TPT_216B1
	#define PANEL_NAME	"tpt_216B1"
	#define PANEL_SIZE		"21"
	#include <panel/tpt_216B1.h>
#endif
//xue add 31.5'' TPT_315lA77W_A800L panel 20101019
#ifdef CONFIG_PANEL_TPT_315lA77WA800LX1
	#define PANEL_NAME	"TPT315LA77WA800LX1"
	#define PANEL_SIZE		"31"
	#include <panel/tpt_315lA77WA800LX1.h>
#endif

#ifdef CONFIG_PANEL_LCB315B5_WX221
        #define PANEL_NAME      "LCB315B5-WX221adke10x"
        #define PANEL_SIZE              "31"
        #include <panel/Panel_LCB315_WX221ADKE10X.h>
#endif

#ifdef CONFIG_PANEL_MT275_A01_2
        #define PANEL_NAME      "MT275_A01_2"
        #define PANEL_SIZE              "27.5"
        #include <panel/Panel_MT275_A01_2.h>
#endif

//xue add 40'' TPT_400HA2KXA000LX0 panel 20101028
#ifdef CONFIG_PANEL_TPT_400HA2KXA000LX0
	#define PANEL_NAME	"TPT400HA2KXA000LX0"
	#define PANEL_SIZE		"40"
	#include <panel/tpt_400HA2KXA000LX0.h>
#endif
 //xue add 42'' AU_T420HW07V1 panel for SZ 20101113
#ifdef CONFIG_PANEL_AU_T420HW07V1
	#define PANEL_NAME	"AUO_T420HW07V1"
	#define PANEL_SIZE		"40"
	#include <panel/auo_T420HW07V1.h>
#endif

 //xue add 46'' AU_T460HW04V1 panel for SZ 20101113
#ifdef CONFIG_PANEL_AU_T460HW04V1
	#define PANEL_NAME	"AUO_T460HW04V1"
	#define PANEL_SIZE		"46"
	#include <panel/auo_T46HW04V1.h>
#endif

//TPV_Modify start Kyle at 2012/05/03
#ifdef CONFIG_PANEL_HT260WXC_200
	#define PANEL_NAME	"HT260WXC-200"
	#define PANEL_SIZE		"26"
	#include <panel/Panel_HT260WXC_200.h>
#endif

#ifdef CONFIG_PANEL_TPT315B5_TAT01
	#define PANEL_NAME	"TPT315B5_TAT01"
	#define PANEL_SIZE		"31.5"
	#include <panel/TPT315B5_TAT01.h>
#endif

#ifdef CONFIG_PANEL_TPT390J1_L01
	#define PANEL_NAME	"TPT390J1_L01"
	#define PANEL_SIZE		"39"
	#include <panel/Panel_TPT390J1_L01.h>
#endif

#ifdef CONFIG_PANEL_TPT390J1_L02_ADAE_10X
	#define PANEL_NAME	"TPT390J1_L02_ADAE_10X"
	#define PANEL_SIZE		"39"
	#include <panel/Panel_TPT390J1_L02adae10x.h>
#endif

#ifdef CONFIG_PANEL_LCA390HV_D03_A22A_10X  //Ferdie add 3D panel 20130301
        #define PANEL_NAME      "LCA390HV_D03_A22A_10X"
        #define PANEL_SIZE              "39"
        #include <panel/Panel_LCA390HV_D03A22A10X.h>
#endif

#ifdef CONFIG_PANEL_MT275_A01_2  //Ferdie add LE28D1440 panel 20130313
        #define PANEL_NAME      "MT275_A01_2"
        #define PANEL_SIZE              "28"
        #include <panel/Panel_MT275_A01_2.h>
#endif

#ifdef CONFIG_PANEL_TPT420H2_HVN01
	#define PANEL_NAME	"TPT420H2_HVN01"
	#define PANEL_SIZE		"42"
	#include <panel/Panel_TPT420H2_HVN01.h>
#endif

#ifdef CONFIG_PANEL_LG_LC420EUN_SEF1
	#define PANEL_NAME	"LG_LC420EUN_SEF1"
	#define PANEL_SIZE		"42"
	#include <panel/Panel_LG_LC420EUN_SEF1.h>
#endif

#ifdef CONFIG_PANEL_auo_TPT420H2HVD01C1B_3DPR
	#define PANEL_NAME	"AUO_TPT420H2"
	#define PANEL_SIZE		"42"
	#include <panel/auo_TPT420H2HVD01C1B_3DPR.h>
#endif

//TPV_Modify end Kyle at 2012/05/03

//-------------------------------------------------
// Ostar
//-------------------------------------------------
#ifdef CONFIG_PANEL_OSTAR_CMI_V390HJ1
	#define PANEL_NAME	"ostar_cmi_v390hj1"
	#define PANEL_SIZE		"39"
	#include <panel/ostar_cmi_v390hj1.h>
#endif


//----------------------------------------------
// TCL
//----------------------------------------------
#ifdef CONFIG_PANEL_CSOT_ST3151A04
	#define PANEL_NAME	"csot_st3151a04"
	#define PANEL_SIZE		"32"
	#include <panel/panel_csot_st3151a04.h>
#endif

//----------------------------------------------
// Toshib ISDB
//----------------------------------------------
#ifdef CONFIG_PANEL_cmo_V236BJ1P01
	#define PANEL_NAME	"cmo_V236BJ1P01"
	#define PANEL_SIZE		"23"
	#include <panel/tsbI_cmo_v236bj1p01.h>
#endif

#ifdef CONFIG_PANEL_cmo_V290BJ1PE1
	#define PANEL_NAME	"cmo_V290BJ1PE1"
	#define PANEL_SIZE		"29"
	#include <panel/tsbI_cmo_v290bj1pe1.h>
#endif

#ifdef CONFIG_PANEL_cmo_V390HJ1P02
	#define PANEL_NAME	"tsbI_cmo_v390hj1p02"
	#define PANEL_SIZE		"39"
	#include <panel/tsbI_cmo_v390hj1p02.h>
#endif

#ifdef CONFIG_PANEL_auo_T390HVN01
	#define PANEL_NAME	"tsbI_auo_t390hvn01"
	#define PANEL_SIZE		"39"
	#include <panel/tsbI_auo_t390hvn01.h>
#endif

#ifdef CONFIG_PANEL_lg_LC500DUE_SFR1
	#define PANEL_NAME	"tsb_lg_lc500due_sfr1"
	#define PANEL_SIZE		"50"
	#include <panel/tsb_lg_lc500due_sfr1.h>
#endif

#ifdef CONFIG_PANEL_sam_LSC320AN02
	#define PANEL_NAME	"sam_LSC320AN02"
	#define PANEL_SIZE		"32"
	#include <panel/tsbI_samsung_lsc320an02.h>
#endif

#ifdef CONFIG_PANEL_lg_LC320DXJSFE1
	#define PANEL_NAME	"lg_LC320DXJSFE1"
	#define PANEL_SIZE		"32"
	#include <panel/tsbI_lg_lc320dxjsfe1.h>
#endif

#ifdef CONFIG_PANEL_samsung_lta32ap05_t
	#define PANEL_NAME	"sam_lta32ap05_t"
	#define PANEL_SIZE		"32"
	#include <panel/sam_lta32ap05_t.h>
#endif

#ifdef CONFIG_PANEL_CMI_V400HJ2_PE1_REVC1
	#define PANEL_NAME	"cmi_v400hj2_pe1_revc1"
	#define PANEL_SIZE	"42"
	#include <panel/cmi_v400hj2_pe1_revc1.h>
#endif

#ifdef CONFIG_PANEL_CMI_V400HJ2_PE1_REVC1_FIX
	#define PANEL_NAME	"tsb_cmi_v400hj2_pe1_revc1"
	#define PANEL_SIZE	"42"
	#include <panel/tsb_cmi_v400hj2_pe1_revc1.h>
#endif

#ifdef CONFIG_PANEL_CMI_MILLET3_V500_4K2K
	#define PANEL_NAME	"CMI_M3_v500"
	#define PANEL_SIZE	"50"
	#include <panel/CMI_Millet3_v500_4k2k.h>
#endif

#ifdef CONFIG_PANEL_CMI_MILLET3_V500_4K2K_P1032
	#define PANEL_NAME	"CMI_M3_v500"
	#define PANEL_SIZE	"50"
	#include <panel/CMI_Millet3_v500_4k2k_p1032.h>
#endif

#ifdef CONFIG_PANEL_CMI_MILLET3_V500_4K2K_P0123TAIWAN
	#define PANEL_NAME	"CMI_M3_v500"
	#define PANEL_SIZE	"50"
	#include <panel/CMI_Millet3_v500_4k2k_p0123taiwan.h>
#endif


#ifdef CONFIG_PANEL_DEFAULT_MILLET4_4K2K_VBY1
	#define PANEL_NAME	"Default_Millet4_4k2k"
	#define PANEL_SIZE	"50"
	#include <panel/default_millet4_4k2k_vby1.h>
#endif

#ifdef CONFIG_PANEL_DEFAULT_MILLET4_2K1K_VBY1
	#define PANEL_NAME	"Default_Millet4_2k1k"
	#define PANEL_SIZE	"50"
	#include <panel/default_millet4_2k1k_vby1.h>
#endif

//---------------------------------------------------------
//  KNK TV035
//---------------------------------------------------------
#ifdef CONFIG_PANEL_lg_LC420EUJ_SFK1
	#define PANEL_NAME	"lg_LC420EUJ_SFK1"
	#define PANEL_SIZE		"42"
	#include <panel/lg_LC420EUJ_SFK1.h>
#endif

#ifdef CONFIG_PANEL_KNK_BOE_HV320WX2_206 //32 HD
	#define PANEL_NAME	"knk_boe_HV320WX2_206"
	#define PANEL_SIZE		"32"
	#include <panel/knk_boe_HV320WX2_206.h>
#endif

#ifdef CONFIG_PANEL_KNK_LG_LC320EXJ_SEK1 //32 HD
	#define PANEL_NAME	"knk_lg_LC320EXJ_SEK1"
	#define PANEL_SIZE		"32"
	#include <panel/knk_lg_LC320EXJ_SEK1.h>
#endif

#ifdef CONFIG_PANEL_KNK_LG_LC470EUN_FEF1
	#define PANEL_NAME	"knk_lg_LC470EUN_FEF1"
	#define PANEL_SIZE		"47"
	#include <panel/knk_lg_LC470EUN_FEF1.h>
#endif

#ifdef CONFIG_PANEL_LG_EPI_DEMO_32
       #define PANEL_NAME "lg_epi_demo_32"
       #define PANEL_SIZE	"32"
       #include <panel/lg_epi_demo_32.h>
#endif

#ifdef CONFIG_PANEL_LG_ART5_FHD_47_EPI
       #define PANEL_NAME "lg_art5_fhd_epi"
       #define PANEL_SIZE	"74"
       #include <panel/lg_art5_fhd_47_epi.h>
#endif

#ifdef CONFIG_PANEL_CMI_V390HK1_LS6
       #define PANEL_NAME "cmi_V390HK1_LS6"
       #define PANEL_SIZE	"39"
       #include <panel/cmi_V390HK1_LS6.h>
#endif

#ifdef CONFIG_PANEL_M195FGK_l30
       #define PANEL_NAME "m195fgk_l30"
       #define PANEL_SIZE	"19"
       #include <panel/m195fgk_l30.h>
#endif

#ifdef CONFIG_PANEL_LVDS_TO_HDMI_BOARD
       #define PANEL_NAME "panel_lvds_to_hdmi_board"
       #define PANEL_SIZE	"22"
       #include <panel/panel_lvds_to_hdmi_board.h>
#endif

#ifdef CONFIG_PANEL_LVDS2VGA
       #define PANEL_NAME "panel_forLVDS2VGA"
       #define PANEL_SIZE	"22"
       #include <panel/panel_forLVDS2VGA.h>
#endif

#ifdef CONFIG_PANEL_TVBOX
	#define PANEL_NAME	"disp_to_tvbox"
	#define PANEL_SIZE		"22"
	#include <panel/default_tvbox.h>
#endif


#ifdef CONFIG_PANEL_HAIER_SHARP_40
	#define PANEL_NAME	"Haier_sharp_40"
	#define PANEL_SIZE		"44"
	#include <panel/Haier_Sharp_40.h>
#endif


#ifdef CONFIG_PANEL_BENQ_22_MISM
	#define PANEL_NAME	"Benq_22_mism"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_MiSM.h>
#endif

#ifdef CONFIG_PANEL_BENQ_22_MISUM
	#define PANEL_NAME	"Benq_22_misum"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_MiSUM.h>
#endif
#ifdef CONFIG_PANEL_BENQ_22_MIUSM
	#define PANEL_NAME	"Benq_22_miusm"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_MiUSM.h>
#endif
#ifdef CONFIG_PANEL_BENQ_22_UMISM
	#define PANEL_NAME	"Benq_22_umism"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_UMiSM.h>
#endif
#ifdef CONFIG_PANEL_BENQ_22_UMISUM
	#define PANEL_NAME	"Benq_22_umisum"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_UMiSUM.h>
#endif

#ifdef CONFIG_PANEL_BENQ_22_UMIUSM
	#define PANEL_NAME	"Benq_22_umiusm"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_UMiUSM.h>
#endif
#ifdef CONFIG_PANEL_BENQ_22_UMIUSUM
	#define PANEL_NAME	"Benq_22_umiusum"
	#define PANEL_SIZE		"22"
	#include <panel/benq_e220hd_UMiUSUM.h>
#endif


//-------------------------------------------------
// Mode_id
//-------------------------------------------------
#ifdef ENABLE_UPDATE_AQPQ
typedef enum _MODE_ID{
    MODE_ID1 = 0x01,
    MODE_ID2 = 0x02,
    MODE_ID4 = 0x04,
    MODE_ID16 = 0x16,
    MODE_MAX_NUM
} MODE_ID;


#if defined(CONFIG_PANEL_auo_T390HVN01V0 )
	#define DEFAULT_MODE_ID	MODE_ID1
#elif defined( CONFIG_PANEL_cmo_V390HJ1P02)
	#define DEFAULT_MODE_ID	MODE_ID2
#elif defined(CONFIG_PANEL_lg_LC500DUE_SFR1)
	#define DEFAULT_MODE_ID	MODE_ID4
#elif defined(CONFIG_PANEL_BENQ_22)
	#define DEFAULT_MODE_ID	MODE_ID16
#else
	#define DEFAULT_MODE_ID	MODE_ID1
#endif
#endif


#endif // __PANEL_H__
