
#if PATCH_FOR_VDELAY
#include <linux/dma-mapping.h>

#ifdef CONFIG_RTK_KDRV_RPC
#include <rpc/VideoRPC_System.h>
#include <rtk_kdriver/RPCDriver.h>
#endif
#ifdef CONFIG_RTK_KDRV_RPC
#include <rtk_kdriver/rpc/VideoRPC_System.h>
#include <rtk_kdriver/RPCDriver.h>
#endif


static unsigned int* _gp_pwm_mem_virt;
static dma_addr_t _gp_pwm_mem_phy;

static int rtk_pwm_send_mem(void);

#endif

void videoPwmAction_No(void)
{
#if PATCH_FOR_VDELAY
	( *(_gp_pwm_mem_virt+3) = 0x0 );
#endif
}

void videoPwmAction_Yes(void)
{
#if PATCH_FOR_VDELAY
	( *(_gp_pwm_mem_virt+3) = 0xffffffff );
#endif
}


/*
 * visr needs this mem.
 * if fail to get mem, we use pwm register.
 * */

#if PATCH_FOR_VDELAY
static int rtk_pwm_init_mem(void) {

	pst_rtk_pwm_platform_dev->dev.coherent_dma_mask = 0xffffffff;
	_gp_pwm_mem_virt =
		    dma_alloc_coherent(&pst_rtk_pwm_platform_dev->dev, 64,
		    &_gp_pwm_mem_phy, GFP_KERNEL);

	if (_gp_pwm_mem_virt == NULL) {
		PWM_ERR("[PWM] get noncache mem fail.\n");
		return -1;
	}

	*(_gp_pwm_mem_virt+8) = rtd_inl(0xb801bc84);
	PWM_WARN("get shared mem = 0x%08x success.\n",
		(unsigned int)_gp_pwm_mem_phy);

	*(_gp_pwm_mem_virt+3) = 0x0;

	/*We need to init the memory value to avoid unexpected AC on/off flow*/

	//PWM0
	*(_gp_pwm_mem_virt) = htonl(rtd_inl(0xb801bc84));
	*(_gp_pwm_mem_virt+1) = htonl(rtd_inl(0xb801bc88));
	*(_gp_pwm_mem_virt+2) = htonl(rtd_inl(0xb801bc8c));

	//PWM1
	*(_gp_pwm_mem_virt+4) = htonl(rtd_inl(0xb801bc90));
	*(_gp_pwm_mem_virt+5) = htonl(rtd_inl(0xb801bc94));
	*(_gp_pwm_mem_virt+6) = htonl(rtd_inl(0xb801bc98));


	return 0;

}
static int rtk_pwm_send_mem(void) {
#ifdef CONFIG_RTK_KDRV_RPC
	static int ret_val = RPC_FAIL;
	unsigned long ret=0;

	if (_gp_pwm_mem_virt == NULL) {
		PWM_ERR(" send noncache mem fail.\n");
		return -1;
	}

	if(RPC_OK == ret_val)
		return 0;

	ret_val = send_rpc_command(RPC_VIDEO, VIDEO_RPC_PWM_SetSharedMemAddr,
		(unsigned long)_gp_pwm_mem_phy, 0, &ret);

	if (RPC_FAIL == ret_val){
		PWM_ERR(" send shared mem RPC fail.\n");
		return -1;
	}

	PWM_WARN( "send shared mem = 0x%08x success.\n",
		(unsigned int)_gp_pwm_mem_phy);
#endif
	return 0;

}

static void rtk_pwm_destroy_mem(void){
	if(_gp_pwm_mem_virt) {
		dma_free_coherent(&pst_rtk_pwm_platform_dev->dev, 64,
				_gp_pwm_mem_virt, _gp_pwm_mem_phy);
	}
}
#endif