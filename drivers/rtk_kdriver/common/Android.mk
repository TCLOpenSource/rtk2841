LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
	$(RTK_FRAMEWORKS_LIBS_INCLUDE) \
	$(RTK_FRAMEWORKS_UTILS_INCLUDE) \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/IPC/include \
	$(LOCAL_PATH)/IPC/include/xdr \
	$(LOCAL_PATH)/IPC/generate/include/system
	
LOCAL_SRC_FILES := \
    IPC/src/RPCstruct.c \
    IPC/src/SVCFunc.c \
    IPC/src/ClientStub.c

ifneq ($(ENABLE_SECURE_CPU), YES)
LOCAL_SRC_FILES += \
	IPC/src/rpcapi.c \
	IPC/src/RPCProxy.c \
	IPC/src/rpcstubapi.c
else
LOCAL_SRC_FILES += \
	IPC/src/rpcapi_secure.c \
	IPC/src/RPCProxy_secure.c \
	IPC/src/rpcstubapi_secure.c
endif

LOCAL_SRC_FILES += \
    IPC/src/xdr/xdr.c \
    IPC/src/xdr/xdr_mem.c \
    IPC/src/xdr/xdr_array.c \
    IPC/src/xdr/xdr_float.c \
    IPC/src/xdr/xdr_process.c \
    IPC/src/xdr/xdr_ref.c \
    IPC/src/xdr/xdr_sizeof.c

LOCAL_SRC_FILES += \
    IPC/generate/src/system/AudioRPC_Agent_svc.c \
    IPC/generate/src/system/AudioRPC_System_clnt.c \
    IPC/generate/src/system/AudioRPCBaseDS_xdr.c \
    IPC/generate/src/system/AudioRPC_Agent_xdr.c \
    IPC/generate/src/system/AudioRPC_System_xdr.c \
    IPC/generate/src/system/RPCBaseDS_xdr.c

ifeq ($(ENABLE_KCPU_COMMON), YES)
#for Secure CPU
LOCAL_SRC_FILES += \
	IPC/generate/src/system/SecureRPC_Agent_svc.c \
	IPC/generate/src/system/SecureRPC_System_clnt.c \
	IPC/generate/src/system/SecureRPCBaseDS_xdr.c \
	IPC/generate/src/system/SecureRPC_Agent_xdr.c \
	IPC/generate/src/system/SecureRPC_System_xdr.c
endif

LOCAL_SRC_FILES += \
    IPC/generate/src/system/VideoRPC_Agent_svc.c \
    IPC/generate/src/system/VideoRPC_System_clnt.c \
    IPC/generate/src/system/VideoRPC_Agent_xdr.c \
    IPC/generate/src/system/VideoRPC_System_xdr.c \
    IPC/generate/src/system/VideoRPCBaseDS_xdr.c

LOCAL_CFLAGS := $(RTK_CFLAGS)
	
LOCAL_SHARED_LIBRARIES := liblog librtk_pli

LOCAL_MODULE := librtk_common
LOCAL_PROPRIETARY_MODULE := $(ENABLE_VENDOR_MODULE)

include $(BUILD_SHARED_LIBRARY)

