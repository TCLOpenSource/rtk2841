#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/poll.h>
#include <asm/cacheflush.h>
#include <linux/proc_fs.h>

#include "comm.h"
#include "tuner.h"
#include "demod.h"
#include "demod_rtk_all.h"
#include "demod_rtk_common.h"

#include "DemodMgr.h"
#include "demod_debug.h"

extern PS_RTK_DEMOD_DATA pDemod_globe;


SRTK_DEMOD_DEBUG_CMD Demod_debug_cmd[DEMOD_PROC_COUNT]={{"log_onoff=",    DEMOD_PROC_SETLOGONOFF},
														{"check_lock=",   DEMOD_PROC_GETLOCK},
														{"check_offset=", DEMOD_PROC_GETCROFFSET},
														{"NULL",          DEMOD_PROC_COUNT}};


unsigned char demod_log_onoff = 0;
RTK_DEMOD_GET_SIGNAL_INFO get_signal_info_data;
TV_SIG_QUAL quality_temp;


int demod_proc_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	unsigned char str[128];
	unsigned long i;
	unsigned char *cmd = str;
	long input_data, input_data2, enable, temp_data;

	/* check parameter */
	if(buf == NULL)
	{
		DEMOD_MGR_WARNING("buf=%p\n", buf);
		return -EFAULT;
	}

	if (count > 128) /* procfs write and read has PAGE_SIZE limit */
	{
		DEMOD_MGR_WARNING("command too long, set length to 128 Byte\n");
		count = 128;
	}

	if (copy_from_user(str, buf, count))
	{
		DEMOD_MGR_WARNING("copy_from_user failed! (buf=%p, count=%u)\n", buf, count);
		return -EFAULT;
	}

	str[count-1] = '\0';
#if 1
	DEMOD_MGR_DBG("proc data: %s\n", str);
#endif

	/* get command string */
	for( i = 0; i < DEMOD_PROC_COUNT; i++)
	{
		//DEMOD_MGR_DBG("[%d]%s\n", i, Demod_debug_cmd[i].demod_cmd_str);
		if (strncmp(str, Demod_debug_cmd[i].demod_cmd_str, strlen(Demod_debug_cmd[i].demod_cmd_str)) == 0)
		{
			DEMOD_MGR_DBG("TP debug command: %s\n", Demod_debug_cmd[i].demod_cmd_str);
			break;
		}
	}

	/* command out of range check */
	if ( i >= DEMOD_PROC_COUNT )
	{
	    DEMOD_MGR_WARNING("Cannot find your command: \"%s\"\n", str);
	    return -EINVAL;

	}
	else
	{
	    /* get parameter */
	    cmd += strlen(Demod_debug_cmd[i].demod_cmd_str);
	    if (sscanf(cmd, "%d", &input_data) < 1)
	    {
	        DEMOD_MGR_DBG("sscanf get more data failed (%s) - there is no more parameter.\n", cmd);
			//return -EFAULT;
	    }
	    else
	    {
	        DEMOD_MGR_DBG("input data=%d\n", input_data);
	    }
	}

	switch(i)
	{
	    case DEMOD_PROC_SETLOGONOFF:
	    {
	        demod_log_onoff = (unsigned char)input_data;

	        if ( input_data == 1 )
	        {
	            DEMOD_MGR_WARNING("Enable Demod log\n");
	        }
	        else
	        {
	            DEMOD_MGR_WARNING("Disable Demod log\n");
	        }
	        break;
	    }
	    case DEMOD_PROC_GETLOCK:
	    {
			unsigned char lock_status;
			if(pDemod_globe->m_pDemod!=NULL)
				pDemod_globe->m_pDemod->GetLockStatus(pDemod_globe->m_pDemod, &lock_status);
			else
				lock_status=0;
	        DEMOD_MGR_WARNING("Lock=%d\n", lock_status);
			break;
	    }
	    case DEMOD_PROC_GETCROFFSET:
	    {
			long offset_value;
			if(pDemod_globe->m_pDemod!=NULL)
				pDemod_globe->m_pDemod->GetCarrierOffset(pDemod_globe->m_pDemod, &offset_value);
			else
				offset_value = 0;
	        DEMOD_MGR_WARNING("Offset=%d\n", offset_value);
	        break;
	    }
	    default:
	    {
	        DEMOD_MGR_WARNING("unsupport proc command=%s\n", str);
	        return -EINVAL;
	    }
    }

    return count;

}

int demod_proc_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	char *str;
	int len;
	/*
	unsigned *demod_mode_name[]=
		{
			"TV_MODULATION_UNKNOWN",
			"TV_MODULATION_NONE",
			"TV_MODULATION_VSB",
			"TV_MODULATION_OFDM",
			"TV_MODULATION_PSK",
			"TV_MODULATION_QAM",
			"TV_MODULATION_DVBC_QAM",
			"TV_MODULATION_DTMB_OFDM",
			"TV_MODULATION_DVBT2_OFDM", 	 // T2OFDM
			"TV_MODULATION_DVBS",
			"TV_MODULATION_DVBS2",
			"TV_MODULATION_ISDBT",			// ISDB-T
			"TV_MODULATION_ISDBS",				  // ISDB-S
			"TV_MODULATION_ABSS",			// ABS-S
			"TV_MODULATION_RTSP",
			"TV_MODULATION_ATV",
		};
	*/
	if (*ppos != 0)
	{
		DEMOD_MGR_WARNING("*ppos!=0 just exit\n");
		return 0;
	}

	DEMOD_MGR_WARNING("demod_proc_read Enter *ppos=0x%llx count=0x%x\n", *ppos, count);

	str = kmalloc(65536, GFP_KERNEL);
	memset(str, 0, 65536);

	if(pDemod_globe->m_pDemod!=NULL)
	{
		{
			unsigned char lock_status;
			pDemod_globe->m_pDemod->GetLockStatus(pDemod_globe->m_pDemod, &lock_status);
			len = sprintf(str, "%sLOCK     = %u\n", str, lock_status);
		}
		{
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_SNR, (TV_SIG_QUAL*)&quality_temp);
			len = sprintf(str, "%sSNR      = %u.%u\n", str, quality_temp.snr/10000, quality_temp.snr%10000);
		}
		{
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_AGC, (TV_SIG_QUAL*)&quality_temp);
			len = sprintf(str, "%sAGC      = %u\n", str, quality_temp.agc);
		}
		{
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_SIGNAL_STRENGTH, (TV_SIG_QUAL*)&quality_temp);
			len = sprintf(str, "%sSTRENGTH = %u\n", str, quality_temp.strength);
		}
		{
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_SIGNAL_QUALITY, (TV_SIG_QUAL*)&quality_temp);
			len = sprintf(str, "%sQUALITY  = %u\n", str, quality_temp.quality);
		}
		{
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_PEC, (TV_SIG_QUAL*)&quality_temp);
			len = sprintf(str, "%sPER_num  = %u  PER_den = %u", str, quality_temp.layer_per.per_num, quality_temp.layer_per.per_den);
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_PER, (TV_SIG_QUAL*)&quality_temp);
			len = sprintf(str, "%s PER = %u\n", str, quality_temp.per);
		}
		{
			REALTEK_ALL* pRealtekAll;
			pRealtekAll = (REALTEK_ALL*)(pDemod_globe->m_pDemod->private_data);
			if(pRealtekAll->m_output_mode == RTK_DEMOD_OUT_IF_PARALLEL)
				len = sprintf(str, "%sm_output_mode = PARALLEL\n", str);
			else
				len = sprintf(str, "%sm_output_mode = SERIAL\n", str);
		}
		{
			pDemod_globe->m_pDemod->GetSignalInfo(pDemod_globe->m_pDemod, (TV_SIG_INFO*)&get_signal_info_data);
			//len = sprintf(str, "%smod = %s if_freq=%u if_inversion=%u agc_pola=%u\n", str, demod_mode_name[get_signal_info_data.mod], get_signal_info_data.demod_param.if_freq, get_signal_info_data.demod_param.if_inversion, get_signal_info_data.demod_param.agc_pola);
			len = sprintf(str, "%sMOD = %u\n", str, get_signal_info_data.mod);
		}
	}
	else
	{
		len = sprintf(str, "%sInternal demod is not running!!\n", str);
	}

	len = strlen(str);

	if(count > len)
	{
		if(copy_to_user(buf, str, len))
		{
			DEMOD_MGR_WARNING("Copy proc data to user space failed\n");
			kfree(str);
			return 0;
		}

		if (*ppos == 0)
			*ppos += len;
		else
			len = 0;
	}
	else
	{
		len=0;
	}

	kfree(str);
	DEMOD_MGR_WARNING("demod_proc_read Exit *ppos=0x%llx count=0x%x len=0x%x\n", *ppos, count, len);
	return len;
}

void display_dtv_demod_information(void)
{
#if 0
	TV_SIG_QUAL quality_temp;
	RTK_DEMOD_GET_SIGNAL_INFO get_signal_info_data;
	/*unsigned *demod_mode_name[]=
		{
			"TV_MODULATION_UNKNOWN",
			"TV_MODULATION_NONE",
			"TV_MODULATION_VSB",
			"TV_MODULATION_OFDM",
			"TV_MODULATION_PSK",
			"TV_MODULATION_QAM",
			"TV_MODULATION_DVBC_QAM",
			"TV_MODULATION_DTMB_OFDM",
			"TV_MODULATION_DVBT2_OFDM", 	 // T2OFDM
			"TV_MODULATION_DVBS",
			"TV_MODULATION_DVBS2",
			"TV_MODULATION_ISDBT",			// ISDB-T
			"TV_MODULATION_ISDBS",				  // ISDB-S
			"TV_MODULATION_ABSS",			// ABS-S
			"TV_MODULATION_RTSP",
			"TV_MODULATION_ATV",
		};
	*/
	if(pDemod_globe->m_pDemod!=NULL)
	{
		unsigned char lock_status;
		pDemod_globe->m_pDemod->GetLockStatus(pDemod_globe->m_pDemod, &lock_status);
		DEMOD_MGR_EMERG_FORCE("LOCK     = %u\n", lock_status);
		pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_SNR, (TV_SIG_QUAL*)&quality_temp);
		DEMOD_MGR_EMERG_FORCE("SNR      = %u.%u\n", quality_temp.snr/10000, quality_temp.snr%10000);
		pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_AGC, (TV_SIG_QUAL*)&quality_temp);
		DEMOD_MGR_EMERG_FORCE("AGC      = %u\n", quality_temp.agc);
		pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_SIGNAL_STRENGTH, (TV_SIG_QUAL*)&quality_temp);
		DEMOD_MGR_EMERG_FORCE("STRENGTH = %u\n", quality_temp.strength);
		pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_SIGNAL_QUALITY, (TV_SIG_QUAL*)&quality_temp);
		DEMOD_MGR_EMERG_FORCE("QUALITY  = %u\n", quality_temp.quality);
		pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_PEC, (TV_SIG_QUAL*)&quality_temp);
		DEMOD_MGR_EMERG_FORCE("PER_num  = %u  PER_den = %u", quality_temp.layer_per.per_num, quality_temp.layer_per.per_den);
		pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, TV_QUAL_PER, (TV_SIG_QUAL*)&quality_temp);
		DEMOD_MGR_EMERG_FORCE("PER = %u\n", quality_temp.per);
		pDemod_globe->m_pDemod->GetSignalInfo(pDemod_globe->m_pDemod, (TV_SIG_INFO*)&get_signal_info_data);
		DEMOD_MGR_EMERG_FORCE("MOD = %u\n", get_signal_info_data.mod);
	}
	else
	{
		DEMOD_MGR_EMERG_FORCE("Internal demod is not running!!\n");
	}
#endif
}
