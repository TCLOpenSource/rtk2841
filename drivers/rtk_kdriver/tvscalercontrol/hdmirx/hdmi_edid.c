/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2018
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ========================== 
 * file: 	hdmi_edid.c 
 * author: 	Kevin_wang
 * date:    2018/3/13
 * version: 1.1
 * This file implements a set of functions of HDMI EDID check and 
 * modification to make sure the EDID can meets system requirement
 * (for Example, no resolutions above 2K ...)  
 *============================================================*/
#include <linux/kernel.h>
#include <linux/slab.h>
#include "hdmi_edid.h"
#include "hdmi_debug.h"
#include "cea_861.h"


#define HDMI_EDID_LIMIT_2K_TIMING      0x1


/*--------------------------------------------
 * Func : _check_video_data_block
 *
 * Desc : check if the given video data block can meet
 *        the specified constrains
 *
 * Para : p_vsdb : (I) Vendor Specific Data Block
 *        flags  : (I) constrain flags
 *
 *    HDMI_EDID_LIMIT_2K_TIMING : resoultion
 *            should be less than 2K
 *
 * Retn : 0 : the VSDB meets the requirements
 *       -1 : the VSDB doesn't meet the requirements
 *-------------------------------------------*/
static int _check_video_data_block(CEA_DATA_BLOCK *p_vdb, unsigned long flags)
{
    if ((flags & HDMI_EDID_LIMIT_2K_TIMING))
    {
        unsigned char svd_list[31];
        unsigned char svd_cnt = 0;
        int i;

        //TODO: remove SVDs that above 2K

        for (i=0; i<p_vdb->length; i++)
        {
            unsigned char svd = p_vdb->data[i];
            unsigned char vic = _svd_to_vic(svd);
            const VIC_TIMING_INFO* p_vic_timing = _get_vic_timing(vic);

            if (p_vic_timing)
            {
                HDMI_EDID_DBG("check_video_data_block, svd=%d (vic:%d, htotal=%d, vtotal=%d)\n",
                        svd, vic, p_vic_timing->htotal, p_vic_timing->vtotal);

                if (p_vic_timing->htotal <= 2048)
                {
                    HDMI_EDID_DBG("keep svd - %d\n", svd);
                    svd_list[svd_cnt++] = svd;
                }
                else {
                    HDMI_EDID_DBG("skip svd - %d\n", svd);
                }
            }
            else {
                HDMI_EDID_DBG("skip unknown svd - %d\n", svd);
            }
        }

        if (p_vdb->length == svd_cnt)
        {
            HDMI_EDID_DBG("check_video_data_block, no svd changed\n");
            return 0;
        }
        else
        {
            HDMI_EDID_INFO("_check_video_data_block, svd changed\n");
            p_vdb->length = svd_cnt;
            memcpy(p_vdb->data, svd_list, svd_cnt);
            return 1;
        }
    }

    return 0;
}



/*--------------------------------------------
 * Func : _check_vsdb
 *
 * Desc : check if the given VSDB can meet the specified
 *        constrains
 *
 * Para : p_vsdb : (I) Vendor Specific Data Block
 *        flags  : (I) constrain flags
 *
 *    HDMI_EDID_LIMIT_2K_TIMING : resoultion
 *            should be less than 2K
 *
 * Retn : 0 : the VSDB meets the requirements
 *       -1 : the VSDB doesn't meet the requirements
 *-------------------------------------------*/
static int _check_vsdb(CEA_DATA_BLOCK *p_vsdb, unsigned long flags)
{
    if ((flags & HDMI_EDID_LIMIT_2K_TIMING))
    {
        CEA_HDMI_VSDB_INFO info;

        //TODO: Remove HDMI_VIC List of the VSDB, beacause all of them are above 2K

        if (_parse_vsdb_info(p_vsdb, &info)<0)
        {
            HDMI_EDID_EMG("check VSDB failed, parse vsdb failed \n");
            return 0; // do not modify it
        }

        //_dump_vsdb_info(&info);

        if (info.p_hdmi_vic)
        {
            unsigned char hdmi_vic_len = info.p_video->hdmi_vic_len;

            HDMI_EDID_INFO("hdmi vic detected (len=%d), remove it for 2K limitation \n",
                hdmi_vic_len);

            if (info.p_hdmi_3d_data)
                memcpy(info.p_hdmi_vic, info.p_hdmi_3d_data, info.p_video->hdmi_3d_len); // copy 3D data

            info.p_hdmi_vic = NULL;
            info.p_video->hdmi_vic_len = 0;
            info.p_hdr->length -= hdmi_vic_len;

            //_dump_vsdb_info(&info);
            return 1;
        }
    }

    return 0;
}


/*--------------------------------------------
 * Func : _check_dtd
 *
 * Desc : check if the given DTD can meet the specified
 *        constrains
 *
 * Para : p_dtd : (I) DTD Block
 *        flags : (I) constrain flags
 *
 *    HDMI_EDID_LIMIT_2K_TIMING : resoultion
 *            should be less than 2K
 *
 * Retn : 0 : the DTD meets the requirements
 *       -1 : the DTD doesn't meet the requirements
 *-------------------------------------------*/
static int _check_dtd(CEA_DTD_BLK* p_dtd, unsigned long flags)
{
    if ((flags & HDMI_EDID_LIMIT_2K_TIMING))
    {
        CEA_DTD_INFO info;

        _parse_dtd_info(p_dtd, &info);

        if (info.h_active > 2048)
            return -1;
    }

    return 0;
}


/*--------------------------------------------
 * Func : newbase_hdmi_check_hdmi_edid
 *
 * Desc : check the correctness of hdmi edid.
 *        If there are some limitation are specified
 *        (for Example: limit EDID to 2K resolution)
 *        the FW will modify EDID to meet the constrain
 *        this limitation is specified by kernel config
 *
 *        for example, config CONFIG_REALTEK_2K_MODEL_ENABLED
 *        will eanble the check flag HDMI_EDID_LIMIT_2K_TIMING
 *        to modify EDID to meet 2K limitation
 *
 * Para : edid  : (I) HDMI EDID
 *
 * Retn : 0 : success, -1 : failed
 *-------------------------------------------*/
int newbase_hdmi_check_hdmi_edid(unsigned char edid[128])
{
    CEA_EXT_BLK_INFO info;
    int i;
    int edid_modified = 0;
    unsigned long check_flags = 0;

#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
    check_flags |= HDMI_EDID_LIMIT_2K_TIMING;
#endif

    HDMI_EDID_DBG("newbase_hdmi_check_hdmi_edid (%p)\n", edid);

    if (_compute_checksum(edid, 128)!=0)
    {
        HDMI_EDID_EMG("newbase_hdmi_check_hdmi_edid failed, checksum failed\n");
        return -1;
    }

    if (check_flags==0)
        return 0;

    if (_parse_cea_ext_blk_info(edid, &info)<0)
    {
        HDMI_EDID_EMG("newbase_hdmi_check_hdmi_edid failed, parse hdmi edid failed\n");
        return -1;
    }

    //_dump_cea_ext_blk_info(&info);

    // check CDB
    for (i=0; i< info.n_cdb; i++)
    {
        HDMI_EDID_DBG("check CDB[%d/%d], tag=%d\n", i, info.n_cdb, info.p_cdb[i]->tag);

        switch(info.p_cdb[i]->tag)
        {
        case CEA_861_TAG_2_VIDEO_DATA_BLOCK:
            if (_check_video_data_block(info.p_cdb[i], check_flags))
                edid_modified++;
            break;

        case CEA_861_TAG_3_VENDOR_SPECIFIC_BLOCK:
            if (_check_vsdb(info.p_cdb[i], check_flags))
                edid_modified++;
            break;

        default:
            break;
        }
    }

    // check DTD
    for (i=0; i< info.hdr.n_dtd; i++)
    {
        HDMI_EDID_DBG("check DTD[%d/%d]\n", i, info.hdr.n_dtd);

        if (_check_dtd(info.p_dtd[i], check_flags)<0)
        {
            info.p_dtd[i] = NULL;
            edid_modified++;
        }
    }

    if (edid_modified) {
        HDMI_EDID_INFO("newbase_hdmi_check_hdmi_edid, hdmi edid(%p) has been modified\n", edid);
        _gen_hdmi_edid(&info, edid);
    }

    return 0;
}



int newbase_hdmi_dump_hdmi_edid(unsigned char edid[128])
{
    HDMI_EDID_INFO("EDID, hdmi edid = %02x %02x %02x %02x %02x .... %02x\n", 
        edid[0], edid[1], edid[2],edid[3],edid[4], edid[127]);
        
    return 0;        
}
