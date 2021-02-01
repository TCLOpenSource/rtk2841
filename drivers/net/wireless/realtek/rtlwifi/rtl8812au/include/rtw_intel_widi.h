#ifndef __RTW_INTEL_WIDI_H__
#define __RTW_INTEL_WIDI_H__

//
// Copied from l2sd-ta-detail.h and l2sd-ta-msgs.h
//

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

#define ETH_P_WIDI_NOTIF	0x888F

#define L2SDTA_MAX_SSID_LEN			32
#define L2SDTA_DEVICE_NAME_LEN		32

// Currently 20 bytes are needed for Query and 24 bytes are needed for Trigger
#define L2SDTA_QUERY_TRIGGER_VE_LEN	24
#define L2SDTA_PRIMARY_DEV_LEN		8
#define L2SDTA_SERVICE_VE_LEN			23
#define MAX_NUM_P2P_SDT 				10

#define L2SDTA_MSG_TYPE_QUERY_OR_TRIGGER		1
#define L2SDTA_MSG_TYPE_SERVICE					2
#define L2SDTA_MSG_TYPE_ASSOC_STATUS			3
#define WIDI_MSG_TYPE_P2P_WFD_IE                		8

enum wdal_association_status
{ 
	L2SDTA_DISASSOCIATED			= 0,
	L2SDTA_ASSOCIATED				= 1,
	L2SDTA_WPS_STATUS_FAIL		= 2,
	L2SDTA_WPS_STATUS_SUCCESS	= 3,
	L2SDTA_DEAUTHENTICATED		= 4,
	P2P_PROVISION_REQ_RECV		= 5,
	P2P_GO_REQ_RECIVED			= 6,
	P2P_GO_CONFIRM_RECEIVED		= 7,
	P2P_ASSOCIATED				= 8,
	P2P_WPS_STATUS_FAIL			= 9,
	P2P_WPS_STATUS_SUCESS		= 10,
	P2P_DEAUTHENTICATED			= 11,
	// Note! value 12 is missing
	P2P_INVITE_REQ_RECEIVED		= 13,
	P2P_INVITE_RSP_SENT			= 14,
	P2P_WPS_SUCCESS				= 15,
	P2P_PBC_INVITE_REQ_RECEIVED	= 16
};


#define INTEL_SMI_CODE  "\x00\x01\x57"
#define INTEL_OUI_CODE  "\x00\x17\x35"
// Intel SMI (0x00:0x01:0x57)
#define IS_INTEL_SMI(x)         (x[0] == 0x00 && x[1] == 0x01 && x[2] == 0x57)
// Intel OUI (0x00:0x17:0x35)
#define IS_INTEL_OUI(x)         (x[0] == 0x00 && x[1] == 0x17 && x[2] == 0x35)

#define	INTEL_DEV_TYPE_OUI		0x00173520
#define	WPS_VENDOR_EXT_CODE		0x1049
#define	WPS_PDT_SCID_WIDI_CONSUMER_SINK	0x0102
#define	P2P_SCID_WIDI_CONSUMER_SINK			0x0002

struct l2sd_query_or_trig_msg_t
{
    uint8_t src_mac[ETH_ALEN];
    uint8_t channel;
    uint8_t ssid_len;
    uint8_t ssid[L2SDTA_MAX_SSID_LEN];
    uint8_t qa_ta_ext[L2SDTA_QUERY_TRIGGER_VE_LEN];
} __attribute__ ((packed));

struct l2sd_service_msg_t
{
    uint8_t dst_mac[ETH_ALEN];
    uint8_t channel;
    char sa_device_name[L2SDTA_DEVICE_NAME_LEN];
    uint8_t sa_primary_dev[L2SDTA_PRIMARY_DEV_LEN];
    uint8_t sa_ext[L2SDTA_SERVICE_VE_LEN];
} __attribute__ ((packed));

struct l2sd_assoc_msg_t
{
    uint8_t peer_mac[ETH_ALEN];
    uint8_t assoc_stat;
} __attribute__ ((packed));

struct l2sd_wps_status_msg_t
{
    uint8_t peer_mac[ETH_ALEN];
    uint8_t wps_status;
} __attribute__ ((packed));

struct l2sd_p2p_wfd_ie_msg_t {
    uint8_t type;
    uint8_t frame_type; // 1: probe req, 2: GO Nego Req, 3: GO Nego Confirm, 4: Provision Dicovery Req, 5: Invite Req
    uint8_t src_mac[ETH_ALEN];
    uint8_t dataLen;
    uint8_t data[0];
} __attribute__ ((packed));

struct _l2_msg_t {
    uint8_t msg_type;
    union {
        struct l2sd_query_or_trig_msg_t l2sd_query_or_trig_msg;
        struct l2sd_service_msg_t l2sd_service_msg;
        struct l2sd_assoc_msg_t l2sd_assoc_msg;
        struct l2sd_wps_status_msg_t l2sd_wps_status_msg;
        struct l2sd_p2p_wfd_ie_msg_t l2sd_p2p_wfd_ie_msg;
    } __attribute__ ((packed)) u;
} __attribute__ ((packed));

typedef struct _l2_msg_t l2_msg_t;

#ifdef WIN32
#define ATTRIB_PACK 
#else
#define ATTRIB_PACK __attribute__ ((packed))
#endif

#define L2SDTA_IPV4_ADDR_LEN	4

#define SMI_SUB_CATEGORY_WIDI	0x02 

#define SUB_ATTRIB_ID_QUERY		0x0001
#define SUB_ATTRIB_ID_TA		0x0002
#define SUB_ATTRIB_ID_EDID		0x0003

struct l2sd_wps_attrib_hdr_t 
{
	uint16_t vendor_ext_id;
	uint16_t total_len;
	uint8_t smi_intel[3];
	uint8_t smi_sub_cat;
	uint16_t sub_att_id;
} ATTRIB_PACK;

struct l2sd_wps_primary_t
{
	uint16_t qa_cat_id;
	uint8_t qa_oui[3]; 
	uint8_t qa_sub_rds_ver;
	uint16_t qa_sub_cat_id;
} ATTRIB_PACK;

struct l2sd_edid_data_t
{
	uint16_t mfg_code;
	uint16_t prod_code;
	uint32_t serial_num;
	uint8_t cap_flag;
	uint8_t hori_size;
	uint8_t vert_size;
} ATTRIB_PACK;

struct l2sd_trig_data_t
{
	uint8_t mac_addr[ETH_ALEN];
	uint8_t ip_addr[L2SDTA_IPV4_ADDR_LEN];
	uint16_t port;
} ATTRIB_PACK;

struct l2sd_wps_vea_service_t
{
	struct l2sd_wps_attrib_hdr_t att_hdr;
	uint16_t len;
	struct l2sd_edid_data_t edid_data;
} ATTRIB_PACK;

struct l2sd_wps_vea_query_t
{
	struct l2sd_wps_attrib_hdr_t att_hdr;
	uint16_t len;
	struct l2sd_wps_primary_t prim_dev;
} ATTRIB_PACK;

struct l2sd_wps_vea_trigger_t
{
	struct l2sd_wps_attrib_hdr_t att_hdr;
	uint16_t len;
	struct l2sd_trig_data_t trig_data;
} ATTRIB_PACK;

//
// Copied from l2sd-ta-detail.h and l2sd-ta-msgs.h - END
//


enum INTEL_WIDI_LISTEN_STATE
{
	INTEL_WIDI_LISTEN_STOP = 0,
	INTEL_WIDI_LISTEN_PROCESS = 1,
};

enum INTEL_WIDI_WK_ID
{
	INTEL_WIDI_LISTEN_WK = 0,
	INTEL_WIDI_LISTEN_STOP_WK = 1,
	INTEL_WIDI_ISSUE_PROB_WK = 2,
	INTEL_WIDI_ENABLE = 3,
	INTEL_WIDI_DISABLE = 4,
};

enum INTEL_WIDI_STATE {
	INTEL_WIDI_STATE_NONE = 0,				//	WiDi disable
	INTEL_WIDI_STATE_LISTEN = 1,				//	Listen beacon for query or trigger.
	INTEL_WIDI_STATE_WPS = 2,					//	In wps phase, handshake with RDS Source
	INTEL_WIDI_STATE_ASSOICATE = 3,			//	Already have profile, connecting with RDS Source
	INTEL_WIDI_STATE_CONNECTED = 4,			//	connected with RDS source
	INTEL_WIDI_STATE_DISASSOCIATED = 5,		//	disassociated by RDS source
	INTEL_WIDI_STATE_DEAUTHENTICATED = 6,	//	deauthenticated by RDS source
	INTEL_WIDI_STATE_WFD_CONNECTION = 7,	//	For WiDi 3.5, we receive p2p_invite_req frame to trigger WFD connection
	INTEL_WIDI_STATE_ROAMING = 8,			//	receive listen command, but driver is doing roaming, after roaming redo listen
};

int	rtw_init_intel_widi( _adapter *padapter);
void	rtw_free_intel_widi( _adapter *padapter);
void rtw_reset_widi_info( _adapter *padapter );
void rtw_set_wfd_rds_sink_info( _adapter *padapter, l2_msg_t *l2_msg );
void	issue_probereq_widi(_adapter *padapter, l2_msg_t *l2_msg);
void	process_intel_widi_disconnect(_adapter *padapter, u8 bdisassoc);
void	process_intel_widi_wps_status(_adapter *padapter, u8 wps_status);
int	process_intel_widi_query_or_tigger(_adapter *padapter, WLAN_BSSID_EX *bssid);
void	process_intel_widi_cmd(_adapter*padapter, u8 *cmd);
void	intel_widi_wk_hdl(_adapter *padapter, u8 p2p_ps_state, u8 *pbuf);
u8	intel_widi_wk_cmd(_adapter*padapter, u8 intel_widi_state, u8 *pbuf, s32 size);

#endif // __RTW_INTEL_WIDI_H__

