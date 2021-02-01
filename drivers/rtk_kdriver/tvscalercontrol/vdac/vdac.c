
#include <rbus/tv_sb1_ana_reg.h>
#include <tvscalercontrol/vdac/vdac.h>

void drvif_vdac_init(void)
{
    return;
#if 0
    //DAC
    rtd_outl(TV_SB1_ANA_VDAC_BSO_reg, (0x1<<12)|(0x4<<8)|(0x5<<4)|(0x2));
    rtd_outl(TV_SB1_ANA_VDAC_reg, (0x1<<20)|(0x2<<16)|(0x0));
    rtd_outl(TV_SB1_ANA_VDAC_TV_CTRL1_reg, (0x0<<16)|(0x1<<12)|(0xf<<4)|(0x0));//Modify REG_VDAC_RES75_EN_TV setting for current mode VDAC.
    rtd_outl(TV_SB1_ANA_VDAC_TV_CTRL2_reg, (0x4<<8)|(0x1<<4)|(0x1));
    rtd_outl(TV_SB1_ANA_VDAC_TV_SRC_SEL_reg, (0x0));
#endif

	//VDAC, MacArthur3-DesignSpec-TVSB1_Analog
	rtd_outl(TV_SB1_ANA_VDAC_VDBSO_reg, 0x11122002);           				//VDAC_CTRL1, [28]REG_VID_POWLDV, [24]REG_VID_POWMBIAS, [20]REG_VID_POWVDAC
	rtd_outl(TV_SB1_ANA_VDAC_reg, 0x00000000);           				//VDAC_CTRL2
	rtd_outl(TV_SB1_ANA_VADC_IDACO_CTRL1_reg, 0x20000313);           				//VDAC_CTRL3
	rtd_outl(TV_SB1_ANA_VDAC_SRC_SEL_reg, 0x00000013);							//[4]REG_VDAC_CLK_POLAR, [2:0]REG_VDAC_SRC_SEL, 0:from VD, 3:from ADC2X_DOUT


    return;
}

void drvif_vdac_tvdac_power_on(unsigned char enable)
{

    tv_sb1_ana_vdac_vdbso_RBUS VDAC_TV_CTRL1_reg;
    VDAC_TV_CTRL1_reg.regValue = IoReg_Read32(TV_SB1_ANA_VDAC_VDBSO_reg);
    if(enable)
        VDAC_TV_CTRL1_reg.reg_vid_powvdac = 1;
    else
        VDAC_TV_CTRL1_reg.reg_vid_powvdac = 0;
    IoReg_Write32(TV_SB1_ANA_VDAC_VDBSO_reg,VDAC_TV_CTRL1_reg.regValue);
}
void drvif_vdac_yppdac_power_on(unsigned char enable)
{
//remove on mac3
    /*
    	VDAC_YPP_CTRL3_RBUS VDAC_TV_CTRL3_reg;
    	VDAC_TV_CTRL3_reg.regValue = IoReg_Read32(TV_SB1_ANA_VDAC_YPP_CTRL3_reg);
    	if(enable)
    		VDAC_TV_CTRL3_reg.reg_vdac_vdac_en= 0x7;
    	else
    		VDAC_TV_CTRL3_reg.reg_vdac_vdac_en = 0;
    	IoReg_Write32(TV_SB1_ANA_VDAC_YPP_CTRL3_reg,VDAC_TV_CTRL3_reg.regValue);
    */
}
void drvif_vdac_source_sel(VDAC_TV_SRC_SEL sel)
{
    //fix me;
    tv_sb1_ana_vdac_src_sel_RBUS VDAC_SRC_SEL_reg;
    VDAC_SRC_SEL_reg.regValue=IoReg_Read32(TV_SB1_ANA_VDAC_SRC_SEL_reg);
    VDAC_SRC_SEL_reg.reg_vdac_src_sel=sel;
    IoReg_Write32(TV_SB1_ANA_VDAC_SRC_SEL_reg,VDAC_SRC_SEL_reg.regValue);
}

