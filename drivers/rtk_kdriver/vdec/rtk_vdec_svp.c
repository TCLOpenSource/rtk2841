#include "rtk_vdec_svp.h"

#ifdef CONFIG_OPTEE

#include <linux/kernel.h>
#include <linux/tee.h>
#include <linux/tee_drv.h>
#include <linux/err.h>

////////////////////////////////////////////////////////////////////////////////
#define TEE_NUM_PARAM 4

struct teec_uuid {
        uint32_t timeLow;
        uint16_t timeMid;
        uint16_t timeHiAndVersion;
        uint8_t clockSeqAndNode[8];
};
////////////////////////////////////////////////////////////////////////////////

//#define TA_RTK_SVP_UUID { 0xae9c26f2, 0x363f, 0x11e8, \
    { 0xb4, 0x67, 0x0e, 0xd5, 0xf8, 0x9f, 0x71, 0x8b} }
#define TA_RTK_SVP_UUID   { 0x15c66c21, 0x1275, 0x4040, \
                       { 0xaa, 0x61, 0xfb, 0x1e, 0xe4, 0x56, 0xda, 0xca } }


#define TA_RTK_SVP_CMD_OpenContentProtectedBuffer          1000
#define TA_RTK_SVP_CMD_CloseContentProtectedBuffer         1001

struct optee_ta {
    struct tee_context *ctx;
    __u32 session;
};

static struct optee_ta svp_ta;

static int optee_svp_match(struct tee_ioctl_version_data *data, const void *vers)
{
        return 1;
}

static int rtkvdec_svp_init (void)
{
  int ret = 0, rc = 0;
  struct teec_uuid uuid = TA_RTK_SVP_UUID;
  struct tee_ioctl_open_session_arg arg;
  struct tee_ioctl_version_data vers = {
      .impl_id = TEE_IMPL_ID_OPTEE,
      .impl_caps = TEE_OPTEE_CAP_TZ,
      .gen_caps = TEE_GEN_CAP_GP,
  };

  memset (&svp_ta, 0, sizeof(svp_ta));
  svp_ta.ctx = tee_client_open_context (NULL, optee_svp_match, NULL, &vers);
  if (svp_ta.ctx == NULL)
  {
    pr_err ("rtkvdec_svp: no ta context\n");
    ret = -EINVAL;
    goto err;
  }

  memset(&arg, 0, sizeof(arg));
  memcpy(&arg.uuid, &uuid, sizeof(struct teec_uuid));
  arg.clnt_login = TEE_IOCTL_LOGIN_PUBLIC;
  pr_debug("arg uuid %pUl \n", arg.uuid);

  rc = tee_client_open_session(svp_ta.ctx, &arg, NULL);
  if(rc) {
      pr_err("rtkvdec_svp: open_session failed ret %x arg %x", rc, arg.ret);
              ret = -EINVAL;
      goto err;
  }
  if (arg.ret) {
    ret = -EINVAL;
    goto err;
  }

  svp_ta.session = arg.session;

  pr_debug("open_session ok\n");
  return 0;

err:
  if (svp_ta.session) {
    tee_client_close_session(svp_ta.ctx, svp_ta.session);
    pr_err("rtkvdec_svp: open failed close session \n");
    svp_ta.session = 0;
  }
  if (svp_ta.ctx) {
    tee_client_close_context(svp_ta.ctx);
    pr_err("rtkvdec_svp: open failed close context\n");
    svp_ta.ctx = NULL;
  }
  pr_err("open_session fail\n");

  return ret;
}

static void rtkvdec_svp_deinit(void)
{
  if (svp_ta.session) {
    tee_client_close_session(svp_ta.ctx, svp_ta.session);
    svp_ta.session = 0;
  }

  if (svp_ta.ctx) {
    tee_client_close_context(svp_ta.ctx);
    svp_ta.ctx = NULL;
  }
}

int
rtkvdec_svp_enable_cpb_protection (unsigned int addr, unsigned int size)
{
  int ret = 0, rc = 0;
  struct tee_ioctl_invoke_arg arg;
  struct tee_param param[TEE_NUM_PARAM];

  ret = rtkvdec_svp_init();
  if(ret != 0) {
    pr_err("rtkvdec_svp: no ta context\n");
    goto out;
  }

  memset(&arg, 0, sizeof(arg));
  arg.func = TA_RTK_SVP_CMD_OpenContentProtectedBuffer;
  arg.session = svp_ta.session;
  arg.num_params = TEE_NUM_PARAM;

  memset(&param[0], 0, sizeof(struct tee_param) * TEE_NUM_PARAM);
  param[0].attr = TEE_IOCTL_PARAM_ATTR_TYPE_VALUE_INPUT;
  param[0].u.value.a = addr;
  param[0].u.value.b = size;
  param[1].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;
  param[2].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;
  param[3].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;

  rc = tee_client_invoke_func(svp_ta.ctx, &arg, &param[0]);
  if (rc || arg.ret) {
      pr_err("optee_meminfo: invoke failed ret %x arg.ret %x\n", rc, arg.ret);
      ret = -EINVAL;
      goto out;
  }

out:
  rtkvdec_svp_deinit();
  return ret;
}

int
rtkvdec_svp_disable_cpb_protection (unsigned int addr, unsigned int size)
{
  int ret = 0, rc = 0;
  struct tee_ioctl_invoke_arg arg;
  struct tee_param param[TEE_NUM_PARAM];

  ret = rtkvdec_svp_init();
  if(ret != 0) {
    pr_err("rtkvdec_svp: no ta context\n");
    goto out;
  }

  memset(&arg, 0, sizeof(arg));
  arg.func = TA_RTK_SVP_CMD_CloseContentProtectedBuffer;
  arg.session = svp_ta.session;
  arg.num_params = TEE_NUM_PARAM;

  memset(&param[0], 0, sizeof(struct tee_param) * TEE_NUM_PARAM);
  param[0].attr = TEE_IOCTL_PARAM_ATTR_TYPE_VALUE_INPUT;
  param[0].u.value.a = addr;
  param[0].u.value.b = size;
  param[1].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;
  param[2].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;
  param[3].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;

  rc = tee_client_invoke_func(svp_ta.ctx, &arg, &param);
  if (rc || arg.ret) {
      pr_err("optee_meminfo: invoke failed ret %x arg.ret %x\n", rc, arg.ret);
      ret = -EINVAL;
      goto out;
  }

out:
  rtkvdec_svp_deinit();
  return ret;
}

#else // CONFIG_OPTEE

int
rtkvdec_svp_enable_cpb_protection (unsigned int addr, unsigned int size)
{
  return -1;
}

int
rtkvdec_svp_disable_cpb_protection (unsigned int addr, unsigned int size)
{
  return -1;
}

#endif // CONFIG_OPTEE
