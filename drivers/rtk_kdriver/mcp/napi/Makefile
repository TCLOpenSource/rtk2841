#
# Makefile for the Realtek mcp drivers.
#

KBUILD_CPPFLAGS += -I ../

mcp_api-objs = mcp_cipher.o \
        mcp_dbg.o \
        mcp_aux.o \
        mcp_dgst.o mcp_dgst_dev.o aes_h.o sha1.o mcp_buff.o\
        mcp_cipher.o mcp_cipher_dev.o aes.o des.o tdes.o \

ifdef CONFIG_RTK_KDRV_MCP_SHA256
mcp_api-objs += sha256.o
endif  

ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA
mcp_api-objs += camellia.o
endif

ifdef CONFIG_RTK_KDRV_MCP_RSA
mcp_api-objs += rsa_api.o rsa_lib.o rsa_util.o
endif

obj-$(CONFIG_RTK_KDRV_MCP_NAPI) += mcp_api.o 
