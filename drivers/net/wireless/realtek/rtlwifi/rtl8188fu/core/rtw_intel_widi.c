/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *                                        
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#define _RTW_INTEL_WIDI_C_

#include <drv_types.h>
#include <wifi.h>

#ifdef CONFIG_INTEL_WIDI
#include <rtw_intel_widi.h>

void intel_widi_listen_timer_hdl(void *FunctionContext);

int rtw_init_intel_widi( _adapter *padapter)
{
	int	res = _SUCCESS;
	struct mlme_priv		*pmlmepriv = &(padapter->mlmepriv);

	pmlmepriv->widi_state = INTEL_WIDI_STATE_NONE;
	ATOMIC_SET(&pmlmepriv->rx_probe_rsp, 1);

	_init_timer(&pmlmepriv->listen_timer, padapter->pnetdev, intel_widi_listen_timer_hdl, padapter);

	pmlmepriv->l2sdTaBuffer = rtw_zmalloc(sizeof(l2_msg_t) +8);
	if(pmlmepriv->l2sdTaBuffer == NULL)
	{
		DBG_871X("%s(): l2sdTaBuffer Allocation failed.\n",__FUNCTION__);
		res = _FAIL;
	}

	return res;
}

void rtw_free_intel_widi( _adapter *padapter)
{
	struct mlme_priv		*pmlmepriv = &(padapter->mlmepriv);

	if (rtw_is_drv_stopped(padapter))
		_cancel_timer_ex(&pmlmepriv->listen_timer);


	if(pmlmepriv->l2sdTaBuffer)
		rtw_mfree(pmlmepriv->l2sdTaBuffer, sizeof(l2_msg_t) +8);
}

void rtw_reset_widi_info( _adapter *padapter )
{
	struct mlme_priv		*pmlmepriv = &(padapter->mlmepriv);	

	pmlmepriv->widi_enable = _FALSE;
	_rtw_memset(pmlmepriv->sa_ext, 0x00, L2SDTA_SERVICE_VE_LEN);
	pmlmepriv->p2p_pdt_cid = 0;
	pmlmepriv->p2p_pdt_scid = 0;
	pmlmepriv->num_p2p_sdt = 0;
	_rtw_memset(pmlmepriv->p2p_sdt_cid, 0x00, MAX_NUM_P2P_SDT);
	_rtw_memset(pmlmepriv->p2p_sdt_scid, 0x00, MAX_NUM_P2P_SDT);
}

void rtw_set_wfd_rds_sink_info( _adapter *padapter, l2_msg_t *l2_msg )
{
	struct mlme_priv		*pmlmepriv = &(padapter->mlmepriv);

	_rtw_memcpy(pmlmepriv->sa_ext, l2_msg->u.l2sd_service_msg.sa_ext, L2SDTA_SERVICE_VE_LEN );
}

void issue_probereq_widi(_adapter *padapter, l2_msg_t *l2_msg)
{
	u8	wpsie[256] = { 0x00 };
	u16	wpsielen = 0;
	u8	count = 0;
	struct mlme_priv		*pmlmepriv = &(padapter->mlmepriv);
	struct mlme_ext_priv	*pmlmeext = &(padapter->mlmeextpriv);
	struct mlme_ext_info	*pmlmeinfo = &(pmlmeext->mlmext_info);

	_rtw_memcpy(get_my_bssid(&(pmlmeinfo->network)), l2_msg->u.l2sd_service_msg.dst_mac, ETH_ALEN);

	//add wps_ie for WiDi
	wpsielen = 0;
	//	WPS OUI
	*(u32*) ( wpsie ) = cpu_to_be32( WPSOUI );
	wpsielen += 4;

	//	WPS version
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_VER1 );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0001 );
	wpsielen += 2;

	//	Value:
	wpsie[wpsielen++] = WPS_VERSION_1;	//	Version 1.0

	//	Request Type
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_REQUEST_TYPE );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0001 );
	wpsielen += 2;

	//	Value:
	wpsie[wpsielen++] = WPS_REQ_TYPE_ENROLLEE_INFO_ONLY;

	//	Config Method
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_CONF_METHOD );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0002 );
	wpsielen += 2;

	//	Value:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_CONFIG_METHOD_PBC | WPS_CONFIG_METHOD_DISPLAY| WPS_CONFIG_METHOD_LABEL );
	wpsielen += 2;

	//	UUID-E
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_UUID_E );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0010 );
	wpsielen += 2;

	//	Value:
	_rtw_memcpy(wpsie + wpsielen, adapter_mac_addr(padapter), ETH_ALEN);
	wpsielen += 0x10;

	//	Primary Device Type
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_PRIMARY_DEV_TYPE );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( L2SDTA_PRIMARY_DEV_LEN );
	wpsielen += 2;

	//	Value:
	_rtw_memcpy( wpsie + wpsielen, l2_msg->u.l2sd_service_msg.sa_primary_dev, L2SDTA_PRIMARY_DEV_LEN );
	wpsielen += L2SDTA_PRIMARY_DEV_LEN;

	//	RF Bands
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_RF_BANDS );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0001 );
	wpsielen += 2;

	//	Value:
	wpsie[wpsielen++] = WPS_RF_BANDS_2_4_GHZ; // 2.4GHz

	//	Association State
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_ASSOCIATION_STATE );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0002 );
	wpsielen += 2;

	//	Value:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ASSOC_STATE_NOT_ASSOCIATED);
	wpsielen += 2;

	//	Configuration Error
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_CONFIG_ERROR);
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0002 );
	wpsielen += 2;

	//	Value:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0000);
	wpsielen += 2;

	//	Device Password ID
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_DEVICE_PWID);
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( 0x0002 );
	wpsielen += 2;

	//	Value:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_DPID_PIN);
	wpsielen += 2;

	//	Device Name
	//	Type:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( WPS_ATTR_DEVICE_NAME );
	wpsielen += 2;

	//	Length:
	*(u16*) ( wpsie + wpsielen ) = cpu_to_be16( L2SDTA_DEVICE_NAME_LEN );
	wpsielen += 2;

	//	Value:
	_rtw_memcpy( wpsie + wpsielen, l2_msg->u.l2sd_service_msg.sa_device_name, L2SDTA_DEVICE_NAME_LEN );
	wpsielen += L2SDTA_DEVICE_NAME_LEN;

	//	Vendor Extension
	_rtw_memcpy( wpsie + wpsielen, l2_msg->u.l2sd_service_msg.sa_ext, L2SDTA_SERVICE_VE_LEN );
	wpsielen += L2SDTA_SERVICE_VE_LEN;

	//	Commented by Kurt
	//	We have to save sa_ex that it would be used by issue_probersp_p2p()
	_rtw_memcpy(pmlmepriv->sa_ext, l2_msg->u.l2sd_service_msg.sa_ext, L2SDTA_SERVICE_VE_LEN );

	if(pmlmepriv->wps_probe_req_ie)
	{
		u32 free_len = pmlmepriv->wps_probe_req_ie_len;
		pmlmepriv->wps_probe_req_ie_len = 0;
		rtw_mfree(pmlmepriv->wps_probe_req_ie, free_len);
		pmlmepriv->wps_probe_req_ie = NULL;			
	}	

	pmlmepriv->wps_probe_req_ie = rtw_malloc(wpsielen+2);
	if ( pmlmepriv->wps_probe_req_ie == NULL) {
		printk("%s()-%d: rtw_malloc() ERROR!\n", __FUNCTION__, __LINE__);
		goto exit;
	}

	pmlmepriv->wps_probe_req_ie[0] = 0xdd;
	pmlmepriv->wps_probe_req_ie[1] = wpsielen;
	pmlmepriv->wps_probe_req_ie_len = wpsielen + 2;
	_rtw_memcpy(&pmlmepriv->wps_probe_req_ie[2], wpsie, wpsielen);

#if 1
	DBG_871X("%s():WiDi wps ie length = %d\n",__FUNCTION__,wpsielen);
	ATOMIC_SET(&pmlmepriv->rx_probe_rsp, 0);

	if( l2_msg->u.l2sd_service_msg.channel != pmlmeext->channel_set[pmlmepriv->channel_idx].ChannelNum)
	{
		SelectChannel(padapter, l2_msg->u.l2sd_service_msg.channel);

		issue_probereq(padapter, NULL, pmlmeinfo->network.MacAddress);

		while(1)
		{
			rtw_msleep_os(20);
			if(ATOMIC_READ(&pmlmepriv->rx_probe_rsp)==1)
			{
				break;
			}
			else
			{
				count ++;
				if(count == 5)
					break;
				//DBG_871X("do not receive probe rsp, count = %d\n",count);
				//issue_probereq(padapter, NULL, pmlmeinfo->network.MacAddress);
			}
		}

		SelectChannel(padapter, pmlmeext->channel_set[pmlmepriv->channel_idx].ChannelNum);
	}
	else
	{
		issue_probereq(padapter, NULL, pmlmeinfo->network.MacAddress);

		while(1)
		{
			rtw_msleep_os(20);
			if(ATOMIC_READ(&pmlmepriv->rx_probe_rsp)==1)
			{
				break;
			}
			else
			{
				count ++;
				if(count == 5)
					break;
				//DBG_871X("do not receive probe rsp, count = %d\n",count);
				//issue_probereq(padapter, NULL, pmlmeinfo->network.MacAddress);
			}
		}
	}
#else
	// driver should issue probe request in the right channel
	//if( l2_msg->u.l2sd_service_msg.channel == pmlmeext->channel_set[pmlmeext->sitesurvey_res.channel_idx].ChannelNum)
	if( l2_msg->u.l2sd_service_msg.channel == pmlmeext->channel_set[pmlmepriv->channel_idx].ChannelNum)
	{
		issue_probereq(padapter, NULL, pmlmeinfo->network.MacAddress);
	}
#endif
	//clear wps ie length after send probe request.
	if(pmlmepriv->wps_probe_req_ie)
	{
		u32 free_len = pmlmepriv->wps_probe_req_ie_len;
		pmlmepriv->wps_probe_req_ie_len = 0;
		rtw_mfree(pmlmepriv->wps_probe_req_ie, free_len);
		pmlmepriv->wps_probe_req_ie = NULL;			
	}
exit:
	return;
}

static void sendL2SDTANotificationToControlPlane(
	struct net_device *dev,
	u8 * l2sdtamsg,
	int lenOfl2sdtamsg)
{
	_pkt *skb = NULL;

	skb = dev_alloc_skb(lenOfl2sdtamsg + 2);

	if (!skb)
		printk(KERN_DEBUG "SKB Allocation failed.\n");
	else
	{
		skb_reserve(skb, 2);
		memcpy(skb_put(skb, lenOfl2sdtamsg), l2sdtamsg, lenOfl2sdtamsg);
		skb->len = lenOfl2sdtamsg;
		skb->dev = dev;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,22))
		skb_set_mac_header(skb, 0);
#else
		skb->mac.raw=skb->data;
#endif
		skb->ip_summed = CHECKSUM_UNNECESSARY;
		skb->pkt_type = PACKET_OTHERHOST;
		skb->protocol = htons(ETH_P_WIDI_NOTIF);
		memset(skb->cb, 0, sizeof(skb->cb));
		netif_rx(skb);
	}

}

static void detectedL2SDTAFromAssocStatus(
	struct net_device *dev,
	u8	* l2sdTaBuffer,
	u8	* peerMacAddress,
	u8	assoc_status)
{
	l2_msg_t *l2sdta_notification;

	l2sdta_notification = (l2_msg_t *)l2sdTaBuffer;

	l2sdta_notification->msg_type = L2SDTA_MSG_TYPE_ASSOC_STATUS;
	_rtw_memcpy(l2sdta_notification->u.l2sd_assoc_msg.peer_mac, peerMacAddress, 6);
	l2sdta_notification->u.l2sd_assoc_msg.assoc_stat = assoc_status;

	sendL2SDTANotificationToControlPlane(dev, l2sdTaBuffer,  sizeof(l2_msg_t) +8);
}


/* Call this function from Beacon parse Code */
static void detectedL2SDTAInVendorExtension(
	struct net_device *dev,
	u8	* l2sdTaBuffer,
	u8	* attrib_ie,
	u32	attrib_len,
	u8	* peerMacAddress,
	u8	channel,
	u8	* ssid,
	u32	ssid_len)
{
	l2_msg_t *l2sdta_notification;

	l2sdta_notification = (l2_msg_t *)l2sdTaBuffer;

	l2sdta_notification->msg_type = L2SDTA_MSG_TYPE_QUERY_OR_TRIGGER;
	_rtw_memcpy(l2sdta_notification->u.l2sd_query_or_trig_msg.src_mac, peerMacAddress, 6);
	l2sdta_notification->u.l2sd_query_or_trig_msg.channel = channel;
	l2sdta_notification->u.l2sd_query_or_trig_msg.ssid_len = ssid_len;
	_rtw_memcpy(l2sdta_notification->u.l2sd_query_or_trig_msg.ssid, ssid, ssid_len);

	_rtw_memcpy(l2sdta_notification->u.l2sd_query_or_trig_msg.qa_ta_ext, attrib_ie, attrib_len);

	sendL2SDTANotificationToControlPlane(dev, l2sdTaBuffer,  sizeof(l2_msg_t) +8);
}

/* Call this function from Beacon parse Code */
static void detectedL2SDWiDiWFDIE(
	struct net_device *dev,
	u8	* l2sdTaBuffer,
	u8	* peerMacAddress)
{
	l2_msg_t *l2sdta_notification;

	l2sdta_notification = (l2_msg_t *)l2sdTaBuffer;

	l2sdta_notification->msg_type = WIDI_MSG_TYPE_P2P_WFD_IE;
	_rtw_memcpy(l2sdta_notification->u.l2sd_p2p_wfd_ie_msg.src_mac, peerMacAddress, 6);
	sendL2SDTANotificationToControlPlane(dev, l2sdTaBuffer,  sizeof(l2_msg_t) +8);
}

void process_intel_widi_assoc_status(_adapter *padapter, u8 assoc_status)
{
	//_pkt *skb;
	//l2_msg_t *l2_notif;
	struct mlme_ext_priv	*pmlmeext = &(padapter->mlmeextpriv);
	struct mlme_ext_info	*pmlmeinfo = &(pmlmeext->mlmext_info);
	WLAN_BSSID_EX 		*cur_network = &(pmlmeinfo->network);

	detectedL2SDTAFromAssocStatus(
		padapter->pnetdev,
		padapter->mlmepriv.l2sdTaBuffer,
		get_my_bssid(cur_network),
		assoc_status);
}

void process_intel_widi_disconnect(_adapter *padapter, u8 bdisassoc)
{
	if(padapter->mlmepriv.widi_state == INTEL_WIDI_STATE_CONNECTED)
	{
		padapter->mlmepriv.widi_state = INTEL_WIDI_STATE_DEAUTHENTICATED;
		process_intel_widi_assoc_status(padapter, L2SDTA_DEAUTHENTICATED);
	}
}

void process_intel_widi_wps_status(_adapter *padapter, u8 wps_status)
{
	if ( wps_status == 2 ) // WPS Stop because of wps success
	{
		DBG_871X("Intel WiDi WPS Success with RDS Source\n");
		process_intel_widi_assoc_status(padapter, L2SDTA_WPS_STATUS_SUCCESS);
	}
	else if ( wps_status == 3 ) // WPS Stop because of wps fail
	{
		DBG_871X("Intel WiDi WPS Fail with RDS Source\n");
		process_intel_widi_assoc_status(padapter, L2SDTA_WPS_STATUS_FAIL);
	}
}

/**
 * rtw_get_widi_wps_attr - Search a specific WPS attribute from a given WPS IE
 * @wps_ie: Address of WPS IE to search, already remove  6byte = 1(Element ID) + 1(Length) + 4(WPS OUI)
 * @wps_ielen: Length limit from wps_ie
 * @target_attr_id: The attribute ID of WPS attribute to search
 * @buf_attr: If not NULL and the WPS attribute is found, WPS attribute will be copied to the buf starting from buf_attr
 * @len_attr: If not NULL and the WPS attribute is found, will set to the length of the entire WPS attribute
 *
 * Returns: the address of the specific WPS attribute found, or NULL
 */
static u8 *rtw_get_widi_wps_attr(u8 *wps_ie, uint wps_ielen, u16 target_attr_id ,u8 *buf_attr, u32 *len_attr)
{
	u8 *attr_ptr = NULL;
	u8 * target_attr_ptr = NULL;

	if(len_attr)
		*len_attr = 0;

	attr_ptr = wps_ie;
	
	while(attr_ptr - wps_ie < wps_ielen)
	{
		// 4 = 2(Attribute ID) + 2(Length)
		u16 attr_id = RTW_GET_BE16(attr_ptr);
		u16 attr_data_len = RTW_GET_BE16(attr_ptr + 2);
		u16 attr_len = attr_data_len + 4;
		
		//DBG_871X("%s attr_ptr:%p, id:%u, length:%u\n", __FUNCTION__, attr_ptr, attr_id, attr_data_len);
		if( attr_id == target_attr_id )
		{
			target_attr_ptr = attr_ptr;
		
			if(buf_attr)
				_rtw_memcpy(buf_attr, attr_ptr, attr_len);
			
			if(len_attr)
				*len_attr = attr_len;
			
			break;
		}
		else
		{
			attr_ptr += attr_len; //goto next
		}		
		
	}	

	return target_attr_ptr;
}

int	process_intel_widi_query_or_tigger(_adapter *padapter, WLAN_BSSID_EX *bssid)
{
	int	ret = 1;
	u8	*wps_ie, *wps_attr, *ie;
	u32	wps_len, wps_attr_len,ie_len;
	struct l2sd_wps_attrib_hdr_t	*l2sd_attr;

	if(padapter->mlmepriv.widi_state != INTEL_WIDI_STATE_LISTEN)
		return 0;

	if(bssid->Reserved[0] == 1) //Beacon
	{
		ie = bssid->IEs+_FIXED_IE_LENGTH_;
		ie_len = bssid->IELength-_FIXED_IE_LENGTH_;

#ifdef CONFIG_WFD
		if ( rtw_get_wfd_ie( ie , ie_len,  NULL, NULL ) )
		{
			detectedL2SDWiDiWFDIE( 
				padapter->pnetdev, 
				padapter->mlmepriv.l2sdTaBuffer, 
				bssid->MacAddress);
		}
#endif //CONFIG_WFD

		// Beacon IE may have more than one WPS IE.
		do
		{
			wps_ie = rtw_get_wps_ie(ie, ie_len, NULL, &wps_len);
			if(wps_ie && wps_len>0)
			{
				// Jump to next element
				ie += wps_len;
				ie_len -= wps_len;

				// Remove  6byte = 1(Element ID) + 1(Length) + 4(WPS OUI)
				wps_ie += 6;
				wps_len -= 6;

				// WPS IE may have more than one vendor extension.
				do
				{
					wps_attr = rtw_get_widi_wps_attr(wps_ie, wps_len, WPS_ATTR_VENDOR_EXT, NULL, &wps_attr_len);
					if(wps_attr && wps_attr_len>0)
					{
						l2sd_attr = (struct l2sd_wps_attrib_hdr_t *)wps_attr;
						if(IS_INTEL_SMI(l2sd_attr->smi_intel))	
						{
							detectedL2SDTAInVendorExtension(
								padapter->pnetdev,
								padapter->mlmepriv.l2sdTaBuffer,
								wps_attr,
								wps_attr_len,
								bssid->MacAddress,
								bssid->Configuration.DSConfig,
								bssid->Ssid.Ssid,
								bssid->Ssid.SsidLength);

							ret = 0;
							return ret;
						}
						else
						{
							wps_ie += wps_attr_len;
							wps_len -= wps_attr_len;
						}
					}
					else
					{
						break;
					}
				}while(1);
			}
			else
			{
				break;
			}
		}while(1);
	}
	else // ProbeResponse
	{
		if(ATOMIC_READ(&padapter->mlmepriv.rx_probe_rsp)==0)
		{
			ATOMIC_SET(&padapter->mlmepriv.rx_probe_rsp, 1);
			//DBG_871X("Get Query Response from %x:%x:%x:%x:%x:%x\n",
			//	bssid->MacAddress[0],bssid->MacAddress[1],bssid->MacAddress[2],bssid->MacAddress[3],bssid->MacAddress[4],bssid->MacAddress[5]);
			ret = 0;
		}
	}

	return ret;
}

void process_intel_widi_cmd(_adapter*padapter, u8 *cmd)
{
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);

	DBG_871X( "[%s] cmd = %s\n", __FUNCTION__, cmd );

	if( _rtw_memcmp( cmd, "enable", 6 ) )
	{
		DBG_871X("Intel WiDi Enable\n");
		pmlmepriv->widi_state = INTEL_WIDI_STATE_LISTEN;
		intel_widi_wk_cmd(padapter, INTEL_WIDI_ENABLE, NULL, 0);	
	}
	else if ( _rtw_memcmp( cmd, "disable", 7 ) )
	{
		DBG_871X("Intel WiDi Disable\n");
		//pmlmepriv->scan_mode = SCAN_ACTIVE;
		pmlmepriv->widi_state = INTEL_WIDI_STATE_NONE;
		intel_widi_wk_cmd(padapter, INTEL_WIDI_LISTEN_STOP_WK, NULL, 0);
		intel_widi_wk_cmd(padapter, INTEL_WIDI_DISABLE, NULL, 0);
	}
	else if ( _rtw_memcmp( cmd, "listen", 6 ) )
	{
		pmlmepriv->group_cnt = 8;
		if (_FAIL == rtw_pwr_wakeup(padapter)) {
			DBG_871X("rtw_pwr_wakeup fail , Do not Enter Intel WiDi listening phase !!!!!\n");
		} else {
			if(rtw_to_roam(padapter) == 0)
			{
				DBG_871X("Intel WiDi start listening for RDS Source\n");
				//pmlmepriv->scan_mode = SCAN_PASSIVE;
				pmlmepriv->widi_state = INTEL_WIDI_STATE_LISTEN;
				//rtw_sitesurvey_cmd(padapter, NULL, 0, NULL, 0);
				_rtw_memset(pmlmepriv->sa_ext, 0x00, L2SDTA_SERVICE_VE_LEN);
				intel_widi_wk_cmd(padapter, INTEL_WIDI_LISTEN_WK, NULL, 0);
			}
			else
			{
				//driver is doing roaming, after roaming redo listen
				pmlmepriv->widi_state = INTEL_WIDI_STATE_ROAMING;
				DBG_871X("%d Roaming! change to listen state later\n", rtw_to_roam(padapter));
			}
		}
	}
	else if ( _rtw_memcmp( cmd, "wps_start", 9 ) )
	{
		DBG_871X("Intel WiDi start WPS with RDS Source\n");
		//pmlmepriv->scan_mode = SCAN_ACTIVE;
		pmlmepriv->widi_state = INTEL_WIDI_STATE_WPS;
		intel_widi_wk_cmd(padapter, INTEL_WIDI_LISTEN_STOP_WK, NULL, 0);
	}
	else if ( _rtw_memcmp( cmd, "associate", 9 ) )
	{
		DBG_871X("Intel WiDi is ready to associate with RDS Source\n");
		//pmlmepriv->scan_mode = SCAN_ACTIVE;
		pmlmepriv->widi_state = INTEL_WIDI_STATE_ASSOICATE;
		intel_widi_wk_cmd(padapter, INTEL_WIDI_LISTEN_STOP_WK, NULL, 0);
	}
	else if ( _rtw_memcmp( cmd, "connected", 9 ) )
	{
		DBG_871X("Intel WiDi is connected with RDS Source\n");
		pmlmepriv->widi_state = INTEL_WIDI_STATE_CONNECTED;
		process_intel_widi_assoc_status(padapter, L2SDTA_ASSOCIATED);
	}
	else if ( _rtw_memcmp( cmd, "wfd_connected", 9 ) )
	{
		DBG_871X("Intel WiDi is connected with WFD Source\n");
		pmlmepriv->widi_state = INTEL_WIDI_STATE_CONNECTED;
		process_intel_widi_assoc_status(padapter, L2SDTA_ASSOCIATED);
	}
	// For WiDi 4.0
	else if ( _rtw_memcmp( cmd, "p2p_pdt_cid=", 12 ) )
	{
		pmlmepriv->p2p_pdt_cid = rtw_atoi( cmd + 12 );
	}
	else if ( _rtw_memcmp( cmd, "p2p_pdt_scid=", 13 ) )
	{
		pmlmepriv->p2p_pdt_scid = rtw_atoi( cmd + 13 );
	}
	else if ( _rtw_memcmp( cmd, "p2p_sdt_cid=", 12 ) )
	{
		pmlmepriv->p2p_sdt_cid[pmlmepriv->num_p2p_sdt] = rtw_atoi( cmd + 12 );
	}
	else if ( _rtw_memcmp( cmd, "p2p_sdt_scid=", 13 ) )
	{
		pmlmepriv->p2p_sdt_scid[pmlmepriv->num_p2p_sdt] = rtw_atoi( cmd + 13 );
		pmlmepriv->num_p2p_sdt++;
	}
	else if ( _rtw_memcmp( cmd, "reject_disable=", 15 ) )
	{
		pmlmepriv->p2p_reject_disable = rtw_atoi( cmd + 15 );
	}
}

void intel_widi_enable_handler(_adapter *padapter)
{
	u8	val;
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);

	pmlmepriv->widi_enable = _TRUE;
#if 0
	val = 0x2e;
	rtw_hal_set_odm_var(padapter, HAL_ODM_INITIAL_GAIN, &val, _FALSE);
#endif
}

void intel_widi_disable_handler(_adapter *padapter)
{
	u8	val;
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);

	pmlmepriv->widi_enable = _FALSE;
#if 0
	val = 0x2e;
	rtw_hal_set_odm_var(padapter, HAL_ODM_INITIAL_GAIN, &val, _FALSE);
#endif
}

void intel_widi_listen_timer_hdl(void *FunctionContext)
{
	_adapter *padapter = (_adapter *)FunctionContext;
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);

	if(pmlmepriv->listen_state == INTEL_WIDI_LISTEN_PROCESS)
	{
		if( pmlmepriv->group_cnt != 8 )
			pmlmepriv->channel_idx++;
	}

	intel_widi_wk_cmd(padapter, INTEL_WIDI_LISTEN_WK, NULL, 0);
}

void intel_widi_listen_stop_handler(_adapter *padapter)
{
	u8	val8;
	_irqL	irqL;
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
	struct mlme_ext_priv	*pmlmeext = &padapter->mlmeextpriv;
	struct mlme_ext_info	*pmlmeinfo = &(pmlmeext->mlmext_info);

	if(pmlmepriv->listen_state == INTEL_WIDI_LISTEN_STOP)
		return;

	DBG_871X("Leave WiDi Listen Mode\n");

	_cancel_timer_ex(&(pmlmepriv->listen_timer));

	mlmeext_set_scan_state(pmlmeext, SCAN_COMPLETE);
	if( pmlmepriv->widi_state == INTEL_WIDI_STATE_WFD_CONNECTION )
		set_channel_bwmode(padapter, padapter->wdinfo.listen_channel, HAL_PRIME_CHNL_OFFSET_DONT_CARE, CHANNEL_WIDTH_20);
	else
		set_channel_bwmode(padapter, pmlmeext->cur_channel, pmlmeext->cur_ch_offset, pmlmeext->cur_bwmode);


	val8 = 0;
	rtw_hal_set_hwreg(padapter, HW_VAR_MLME_SITESURVEY, (u8 *)(&val8));

	//config MSR
	Set_MSR(padapter, (pmlmeinfo->state & 0x3));

	//turn on dynamic functions
	rtw_phydm_ability_restore(padapter);

	report_surveydone_event(padapter);

	pmlmepriv->listen_state = INTEL_WIDI_LISTEN_STOP;
	mlmeext_set_scan_state(pmlmeext, SCAN_DISABLE);

	rtw_write8(padapter, 0xa07, rtw_read8(padapter, 0xa07)&0xf0);// Enable receive cck packet

	if(pmlmepriv->widi_state != INTEL_WIDI_STATE_NONE)
	{
		if( pmlmepriv->widi_state != INTEL_WIDI_STATE_WFD_CONNECTION )
		{
			_enter_critical_bh(&pmlmepriv->lock, &irqL);
			rtw_sitesurvey_cmd(padapter, NULL, 0, NULL, 0);
			_exit_critical_bh(&pmlmepriv->lock, &irqL);
		}
	} else {
		//restore to initial setting.
		update_tx_basic_rate(padapter, padapter->registrypriv.wireless_mode);
	}
}

void intel_widi_listen_handler(_adapter *padapter)
{
	u8	listen_channel, val8, i;
	u8 	initialgain;
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
	struct mlme_ext_priv	*pmlmeext = &padapter->mlmeextpriv;
	struct wifidirect_info *pwdinfo = &padapter->wdinfo;
	u8 p2p_listen_ch = 0;

	if(pmlmepriv->widi_state != INTEL_WIDI_STATE_LISTEN)
	{
		if(pmlmepriv->listen_state != INTEL_WIDI_LISTEN_STOP)
		{
			intel_widi_listen_stop_handler(padapter);
		}
		return;
	}

	if (check_fwstate(pmlmepriv, _FW_UNDER_SURVEY) == _TRUE)
	{
		_set_timer(&(pmlmepriv->listen_timer), 1000);
		return;
	}

	if(pmlmepriv->listen_state == INTEL_WIDI_LISTEN_STOP)
	{
		pmlmepriv->widi_state = INTEL_WIDI_STATE_NONE;
		update_tx_basic_rate(padapter, WIRELESS_11AGN);
		pmlmepriv->widi_state = INTEL_WIDI_STATE_LISTEN;
	
		pmlmepriv->channel_idx = 0;

		for(i=0;i<RTW_SSID_SCAN_AMOUNT;i++){
			_rtw_memset(pmlmeext->sitesurvey_res.ssid[i].Ssid, 0, (IW_ESSID_MAX_SIZE + 1));
			pmlmeext->sitesurvey_res.ssid[i].SsidLength= 0;
		}
	
		//config the initial gain under scaning, need to write the BB registers
		initialgain = 0x20;
		rtw_hal_set_odm_var(padapter, HAL_ODM_INITIAL_GAIN, &initialgain, _FALSE);

		//disable all phy-dynamic functions
		rtw_phydm_ability_backup(padapter);
		rtw_phydm_func_disable_all(padapter);
		
		//set MSR to no link state
		Set_MSR(padapter, _HW_STATE_NOLINK_);

		val8 = 1; //before site survey
		rtw_hal_set_hwreg(padapter, HW_VAR_MLME_SITESURVEY, (u8 *)(&val8));
	
		pmlmepriv->listen_state = INTEL_WIDI_LISTEN_PROCESS;
		mlmeext_set_scan_state(pmlmeext, SCAN_PROCESS);

		rtw_write8(padapter, 0xa07, rtw_read8(padapter, 0xa07)|0xf);// disable receive cck packet
	}

	listen_channel = pmlmeext->channel_set[pmlmepriv->channel_idx].ChannelNum;

	if( pmlmepriv->group_cnt == 8 )
	{
		pmlmepriv->group_cnt = 0;
		listen_channel = pwdinfo->listen_channel;
		p2p_listen_ch = 1;
	}
	else 
	{
		if( listen_channel == 0 )
		{
			// Get Back to first channel
			pmlmepriv->channel_idx = 0;
			listen_channel = pmlmeext->channel_set[pmlmepriv->channel_idx].ChannelNum;
		}
		pmlmepriv->group_cnt++;
	}

	if(pmlmepriv->channel_idx == 0)
	{
		mlmeext_set_scan_state(pmlmeext, SCAN_COMPLETE);
		set_channel_bwmode(padapter, listen_channel, HAL_PRIME_CHNL_OFFSET_DONT_CARE, CHANNEL_WIDTH_20);
		mlmeext_set_scan_state(pmlmeext, SCAN_PROCESS);
	}
	else
	{
		SelectChannel(padapter, listen_channel);
	}

	// Commented by Kurt
	// For WiDi 3.5 defined, we  have to stay on p2p listen channel for 500ms, other channels will be 120ms
	if( p2p_listen_ch == 1 )
		_set_timer(&(pmlmepriv->listen_timer), 500+10);
	else
		_set_timer(&(pmlmepriv->listen_timer), 120+10);

}

void intel_widi_wk_hdl(_adapter *padapter, u8 intel_widi_state, u8 *pbuf)
{	
_func_enter_;

	switch(intel_widi_state)
	{
		case INTEL_WIDI_LISTEN_WK:
			intel_widi_listen_handler(padapter);
			break;
		case INTEL_WIDI_LISTEN_STOP_WK:
			intel_widi_listen_stop_handler(padapter);
			break;
		case INTEL_WIDI_ISSUE_PROB_WK:
			issue_probereq_widi(padapter, (l2_msg_t *)pbuf);
			break;
		case INTEL_WIDI_ENABLE:
			intel_widi_enable_handler(padapter);
			break;
		case INTEL_WIDI_DISABLE:
			intel_widi_disable_handler(padapter);
			break;
		default:
			break;
	}

_func_exit_;
}

u8 intel_widi_wk_cmd(_adapter*padapter, u8 intel_widi_state, u8 *pbuf, s32 size)
{
	struct cmd_obj	*ph2c;
	struct drvextra_cmd_parm	*pdrvextra_cmd_parm;
	struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
	struct cmd_priv	*pcmdpriv = &padapter->cmdpriv;
	u8	res = _SUCCESS;
	
_func_enter_;

	ph2c = (struct cmd_obj*)rtw_zmalloc(sizeof(struct cmd_obj));	
	if(ph2c==NULL){
		res= _FAIL;
		goto exit;
	}
	
	pdrvextra_cmd_parm = (struct drvextra_cmd_parm*)rtw_zmalloc(sizeof(struct drvextra_cmd_parm)); 
	if(pdrvextra_cmd_parm==NULL){
		rtw_mfree((unsigned char *)ph2c, sizeof(struct cmd_obj));
		res= _FAIL;
		goto exit;
	}

	pdrvextra_cmd_parm->ec_id = INTEl_WIDI_WK_CID;
	pdrvextra_cmd_parm->type = intel_widi_state;
	pdrvextra_cmd_parm->size = size;
	pdrvextra_cmd_parm->pbuf = pbuf;

	init_h2fwcmd_w_parm_no_rsp(ph2c, pdrvextra_cmd_parm, GEN_CMD_CODE(_Set_Drv_Extra));

	res = rtw_enqueue_cmd(pcmdpriv, ph2c);
	
exit:
	
_func_exit_;

	return res;

}
#endif //CONFIG_INTEL_WIDI

