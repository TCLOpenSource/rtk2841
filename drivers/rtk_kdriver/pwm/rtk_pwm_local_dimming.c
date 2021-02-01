#include <rtk_kdriver/rtk_pwm.h>
#include <rtk_kdriver/rtk_pwm_local_dimming.h>
#include <rbus/ldspi_reg.h>
#include <rbus/pinmux_lvdsphy_reg.h>
#include <rbus/ppoverlay_reg.h>


void rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
	unsigned int X,A,result;

	X=(1<<(endBit-startBit+1))-1;
	A=rtd_inl(reg_addr);

	result = (A & (~(X<<startBit))) | (value<<startBit);
	rtd_outl(reg_addr,result);
}

void rtk_local_dimming_enable(void)
{
	ppoverlay_dv_total_RBUS ppoverlay_dv_total_reg;

//	PWM_WARN("%s() disable this function \n", __FUNCTION__ );

	//lvds power enble
	//rtd_part_outl(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg,31,31,0x1);
	//rtd_part_outl(0xb8000d74,31,31,0x1);

#if 0
	//31X31
	rtd_part_outl(0xb8000888,7,4,0x5);//ld_spi1_p5_v_sync,<O>         ball¢GoAG37
	rtd_part_outl(0xb8000888,19,16,0x5);//ld_spi1_p2_sck_src1,<I/O>   ball¢GoAH36
	rtd_part_outl(0xb80008b4,18,16,0x1);//mux sck src1
	rtd_part_outl(0xb8000888,15,12,0x5);//ld_spi1_p3_sdo_SRC1,<I/O>   ball¢GoAH37
	rtd_part_outl(0xb80008b4,15,13,0x1); //mux sdo src1
#endif

	rtd_part_outl(LDSPI_LD_CTRL_reg,28,28,0x1); //Ld_spi enable

	rtd_part_outl(LDSPI_LD_CTRL_reg,31,30,0x1); //LGD mode(default)
	rtd_part_outl(LDSPI_LD_CTRL_reg,4,4,0x1); //LD_SPI1
	//rtd_part_outl(0xb802C900,4,4,0x0); //LD_SPI0
	rtd_part_outl(LDSPI_LD_CTRL_reg,3,3,0x0); //one SPI local dimming block
	//rtd_part_outl(0xb802C900,3,3,0x1); //two SPI local dimming block

	rtd_part_outl(LDSPI_Out_data_CTRL_reg,31,31,0x1); //First received bit or transmitted bit is in the MSB of SRAM or register
	rtd_part_outl(LDSPI_Out_data_CTRL_reg,13,4,0x7); //Output Unit:8 unit(= set+1)
	rtd_part_outl(LDSPI_Out_data_CTRL_reg,1,0,0x0); //Output_Data_format:8 bit

	//rtd_part_outl(0xb802C904,1,0,0x1	); //Output_Data_format:8 bit

	rtd_part_outl(LDSPI_Send_delay_reg,31,8,0x4a9); //Data_send_Delay  T1=(data_send_delay+CS_hold+SCKL+10)*4 = 10us
	rtd_part_outl(LDSPI_Cs_hold_time_reg,31,8,0x4a9); //CS_hold_time
	rtd_part_outl(LDSPI_Timing_CTRL_reg,23,16,0x68); //SCK_H            T2=(SCK_H+SCK_L+2)*4= 0.84us
	rtd_part_outl(LDSPI_Timing_CTRL_reg,7,0,0x68);   //SCK_L            T3=T2/2 = 0.42us
	rtd_part_outl(LDSPI_Data_unit_delay_reg,31,8,0x10b); //Each_unit_delay  T4=(Each_unit_delay+SCK_H+SCK_L)*4 = 1.9us
	rtd_part_outl(LDSPI_V_sync_duty_reg,31,24,0xaf); //Vsync_d          T5=(Vsync_d+1)*128*4 = = 90us K3L
	rtd_part_outl(LDSPI_Data_h_time_reg,24,16,0x68); //Data_hold_time, must to set equal SCK_H!!!



	rtd_part_outl(LDSPI_LD_CTRL_reg,0,0,0x0); //Ld_spi disable

	rtd_part_outl(LDSPI_Outindex_Addr_CTRL_reg,25,16,0x0); //SRAM index
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x0);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x1);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x2);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x3);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x4);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x5);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x6);
	rtd_part_outl(LDSPI_Outindex_Rwport_reg,9,0,0x7);


	//backlight control
	rtd_part_outl(LDSPI_Data_Addr_CTRL_reg,25,16,0x0); //Data index
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0xAA); //data : ID
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0xC3); //data : cmd
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0x99);
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0x99);
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0x99);
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0x99);
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0x99);
	rtd_part_outl(LDSPI_Data_Rwport_reg,15,0,0x99); //checksum = 1E

#if 1
	rtd_inl(LDSPI_Data_Addr_CTRL_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
	rtd_inl(LDSPI_Data_Rwport_reg);
#endif


	rtd_part_outl(LDSPI_LD_CTRL_reg,2,2,0x1); //Send_follow_Vsync
	//rtd_part_outl(0xb802C900,1,1,0x1); //Send_trigger

	rtd_part_outl(LDSPI_LD_CTRL_reg,0,0,0x1); //Ld_spi start enable

	rtd_part_outl(LDSPI_Send_delay_reg,31,8,0x4a9); //Data_send_Delay  T1=(data_send_delay+CS_hold+SCKL+10)*4 = 10us
	rtd_part_outl(LDSPI_Cs_hold_time_reg,31,8,0x4a9); //CS_hold_time
	rtd_part_outl(LDSPI_Timing_CTRL_reg,23,16,0x68); //SCK_H            T2=(SCK_H+SCK_L+2)*4= 0.84us
	rtd_part_outl(LDSPI_Timing_CTRL_reg,7,0,0x68);   //SCK_L            T3=T2/2 = 0.42us
	rtd_part_outl(LDSPI_Data_unit_delay_reg,31,8,0x10b); //Each_unit_delay  T4=(Each_unit_delay+SCK_H+SCK_L)*4 = 1.9us
	rtd_part_outl(LDSPI_V_sync_duty_reg,31,24,0xaf); //Vsync_d          T5=(Vsync_d+1)*128*4 = = 90us K3L
	rtd_part_outl(LDSPI_Data_h_time_reg,24,16,0x68); //Data_hold_time, must to set equal SCK_H!!!

#if 0
	if(Get_DISPLAY_REFRESH_RATE() == 60){
		ppoverlay_dv_total_reg.regValue = rtd_inl(PPOVERLAY_DV_total_reg);
		rtd_part_outl(LDSPI_ld_spi_h_total_reg,31,19,0x112f);  //ld_spi_dh_total ,reproduce hsync signal	 0x112f 4k
		if(ppoverlay_dv_total_reg.dv_total != 0){
			rtd_maskl(LDSPI_ld_spi_v_total_reg, 0x7ffff, ((ppoverlay_dv_total_reg.dv_total/2)-1)<<19); // repeat local dimming vsync
		}else{
			rtd_maskl(LDSPI_ld_spi_v_total_reg, 0x7ffff, ((Get_DISP_VERTICAL_TOTAL()/2)-1)<<19); // repeat local dimming vsync
		}
		PWM_INFO("vertical_total=%x, 0xb802c96c = %x\n", ppoverlay_dv_total_reg.dv_total, rtd_inl(LDSPI_ld_spi_v_total_reg));
		rtd_part_outl(LDSPI_ld_spi_reproduce_mode_reg,2,0,0x1);		 //reproduce mode
	}
#endif

//	ld_time_tick = rtd_inl(SCPU_CLK90K_LO_reg);
	PWM_INFO("##### rtk_local_dimming_enable ####\n");

}