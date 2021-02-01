/* ----------------------------------------------------------------------------
 File Name: DTMBIP_User_Define.c

 Description:

 Version 2.0 : Created   2013.03.05  Sharp Wang	
				 2.2 : Modified  2013.05.20  Sharp Wang
 ---------------------------------------------------------------------------- */ 
#include "dtmb_demod_rtk_type.h"
#include "dtmb_demod_rtk.h"
#include "dtmb_demod_rtk_user.h"
#include "tv_osal.h"

/*****************************************************************************
According different platform settings, customer needs to modify as below functions.
*****************************************************************************/
#define NUMBER_LOST_BEFORE_UNLOCK 6
#define MONITOR_DELAY_MS		  500

static UINT8 DTMBIP_LockConut = NUMBER_LOST_BEFORE_UNLOCK;

/**********************************************************
** Task Monitor
**
**********************************************************/
void DTMBIP_MonitorTask(void)
{
	UINT8 LockResult,locked,status;
	while(1)
	{
		DTMBIP_IsDemodLocked(TRUE,&LockResult,&locked,&status);
		if(LockResult==1)
		{
			DTMBIP_LockConut = NUMBER_LOST_BEFORE_UNLOCK;
			/*Locked*/
		}
		else
		{
			DTMBIP_LockConut--;
		}
		if(DTMBIP_LockConut==0)
		{
			/* signal is unlock, it needs to report to AP.
			请Please implements it according to different playform.
			*/
		}
		DTMBIP_Wait(MONITOR_DELAY_MS);
	}
}

/********************************
 初始化高频头
********************************/
#if 0
UINT8 DTMBIP_TunerInit(void)
{
	UINT8 err = DTMB_NO_ERROR;	
	/****************************
	*
	* 此处应是tuner的初始化操作，具体
	* 需根据客户的实际情况。
	*
	****************************/	
	Tuner_Init();
	
	return (err);	
}
#endif

BOOL DTMBIP_TunerLock(UINT32 Frequency)
{

    return TRUE;
}


/********************************
Tuner Setting
********************************/
BOOL DTMBIP_SetTuner(UINT32 Frequency, UINT8 tunerMode)
{
#if (0)
	UINT8 Address = 0xC0;/*Tuner I2C Address, It needs to modify according by different tuner*/
	UINT8 TunerData[6],Temp;
	UINT16 tunerDivi;
	UINT8 ReadData = 0;
#endif
	/* Set Tuner I2C, input the tuner i2c device addr */
	/* It needs to be confirmed by different platform*/
	//HDIC2311_OpenTunerI2C(Address);

	/****************************
	*
	* Here is the operation about tuner frequency setting
	* It needs to be implement by customer.
	*
	****************************/
	//SetTuner(Frequency, tunerMode);

	//HDIC2311_CloseTunerI2C();
	/*Return Tuner Lock Status */
	return TRUE;
}

/********************************
 I2C Write Register
********************************/
UINT8 DTMBIP_WriteRegister(UINT16 Register, UINT8 Data)
{
	UINT8 err = DTMB_NO_ERROR;
    UINT32 Reg = 0;
	Reg = 0xB8140000 + ((UINT32)Register)*4; 
    
    rtd_outl(Reg, (UINT32)Data);


	return (err);
}
/*
//	UINT8 err = HDIC_NO_ERROR;
	UINT8 RegisterData[3];
	
	RegisterData[0] = (UINT8)((Register&0xFF00)>>8);
	RegisterData[1] = (UINT8)(Register&0xFF);
	RegisterData[2] = Data;

	return (Write_I2C(RegisterData, 3)==0) ? 0 : -1;
return 0;
}
*/
/********************************
 I2C Read Register
********************************/
UINT8 DTMBIP_ReadRegister(UINT16 Register, UINT8 *Data)
{
	UINT8 err = DTMB_NO_ERROR;
	
	UINT32 Reg = 0;
	Reg = 0xB8140000 + ((UINT32)Register)*4; 
    
    *Data = (UINT8)rtd_inl(Reg);



	return (err);
}
/*
//	UINT8 err = HDIC_NO_ERROR;
	UINT8 RegisterData[2];
	
	RegisterData[0] = (UINT8)((Register&0xFF00)>>8);
	RegisterData[1] = (UINT8)(Register&0xFF);

	return (Read_I2C(RegisterData, 2, Data, 1)==0) ? 0 : -1;
return 0;
}
*/

/********************************
Delay Function
********************************/
void DTMBIP_Wait(UINT16 millisecond)
{
	/* It implements at different	platforms */
	//Sleep(millisecond);
	tv_osal_msleep(millisecond);
}

/********************************
IC HW Reset
********************************/
void DTMBIP_HWReset(void)
{
	/*芯片硬复位，可根据硬件情况实现，低电平复位，保持10MS*/
	/* 需根据实际平台实现	*/
	//DTMB_HW_Reset();
    rtd_outl(0xB8000110,0x00100000); //Set dtmb clk bit20 => low 
    rtd_outl(0xB8000100,0x00700000); //Active Reset(low) bit20, bit21 and bit22  
    tv_osal_msleep(5);
    rtd_outl(0xB8000110,0x00100001); //Set dtmb clk bit20 => high
    rtd_outl(0xB8000110,0x00100000); //Set dtmb clk bit20 => low 
    tv_osal_msleep(5);
    rtd_outl(0xB8000100,0x00700001); //Release reset bit20, bit21 and bit22
    rtd_outl(0xB8000110,0x00100001); //Set dtmb clk bit20 => high
	tv_osal_msleep(10);
	
	REALTEK_H_DTMB_BASE_DBG("DTMB H/W Reset !!!");
	return;
}
