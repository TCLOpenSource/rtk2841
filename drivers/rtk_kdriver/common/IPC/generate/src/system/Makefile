##----------------------------------------------------------------------------
# Created with genmake.pl v1.1 on Thu Oct 28 13:37:18 2004
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------
rm=/bin/rm -f
cp=/bin/cp -f
mkdir=/bin/mkdir -p

include ../../../../CommonConfig

DEFS=
CC= $(MYCC)
ifdef PKG_CONFIG_SYSROOT_DIR
AR= $(MYAR) cq
else
AR= $(MYAR) cq
endif
RANLIB= $(MYRANLIB)
LIBNAME= ../../../lib/libsystemrpc.a
#INSTALLHEADER= ../../../../Include/AudioFilter
#include ../../../../../include/MakeConfig

INCLUDES=  -I. -I../../../include -I../../include/system
INCLUDES+= -I../../../../../inc
ifeq ($(ENABLE_BIONIC_BUILD), YES)
#ifeq ($(ENABLE_RUN_ON_MAGELLAN), YES)
ifneq (, $(filter YES, $(ENABLE_RUN_ON_MAGELLAN) $(ENABLE_RUN_ON_SIRIUS) $(ENABLE_RUN_ON_MACARTHUR3))) # either ENABLE_RUN_ON_MAGELLAN=YES or ENABLE_RUN_ON_SIRIUS=YES or ENABLE_RUN_ON_MACARTHUR3=YES
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/include 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/arch-arm/include 
ifeq ($(USE_LOLLIPOP_TOOLCHAIN), YES)
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/kernel/uapi 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/kernel/uapi/asm-arm
else
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/kernel/common 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/kernel/arch-arm 
endif
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libm/include
else
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/include 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/arch-mips/include 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/kernel/common 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libc/kernel/arch-mips 
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libm/include
endif
endif #ENABLE_BIONIC_BUILD

ifeq ($(ENABLE_BIONIC_BUILD), YES)
ifeq ($(USE_LOLLIPOP_TOOLCHAIN), YES)
DEFS += -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon
endif
endif

DEFINES = $(INCLUDES) $(DEFS) $(COMMON_IPC_GENERATE_SRC_SYSTEM_DEFINES)

ifeq ($(IS_SCPU), YES)
DEFINES += -DIS_SCPU -DUSE_TIMED_WAITREPLY
endif

ifeq ($(ENABLE_TEEMANAGER_IN_KCPU), YES)
DEFINES += -DENABLE_TEEMANAGER_IN_KCPU
endif

ifeq ($(ENABLE_BIONIC_BUILD), YES)
#ifeq ($(ENABLE_RUN_ON_MAGELLAN), YES)
ifneq (, $(filter YES, $(ENABLE_RUN_ON_MAGELLAN) $(ENABLE_RUN_ON_SIRIUS) $(ENABLE_RUN_ON_MACARTHUR3))) # either ENABLE_RUN_ON_MAGELLAN=YES or ENABLE_RUN_ON_SIRIUS=YES or ENABLE_RUN_ON_MACARTHUR3=YES
DEFINES += -fno-exceptions
else
DEFINES += -fno-exceptions -EL 
endif
endif #ENABLE_BIONIC_BUILD
CFLAGS= -g $(DEFINES) $(COMPILE_OPT)
ifeq ($(COMPILE_SHARED_LIB), YES)
CFLAGS  += -fPIC
endif

SRCS = AudioRPC_Agent_svc.c AudioRPC_System_clnt.c AudioRPCBaseDS_xdr.c AudioRPC_Agent_xdr.c AudioRPC_System_xdr.c RPCBaseDS_xdr.c
OBJS = AudioRPC_Agent_svc.o AudioRPC_System_clnt.o AudioRPCBaseDS_xdr.o AudioRPC_Agent_xdr.o AudioRPC_System_xdr.o RPCBaseDS_xdr.o

ifeq ($(ENABLE_KCPU_COMMON), YES)
#for Secure CPU
SRCS += SecureRPC_Agent_svc.c SecureRPC_System_clnt.c SecureRPCBaseDS_xdr.c SecureRPC_Agent_xdr.c SecureRPC_System_xdr.c
OBJS += SecureRPC_Agent_svc.o SecureRPC_System_clnt.o SecureRPCBaseDS_xdr.o SecureRPC_Agent_xdr.o SecureRPC_System_xdr.o
endif

HEADERS= defs.h

%.o : %.c
	$(rm) -f $@
	$(CC) $(CFLAGS) $(WARNING) $(DEBUGFLAG) -c $*.c

all: $(LIBNAME)
	$(MAKE) -f ./Makefile-video

$(LIBNAME) : $(OBJS)
	$(rm) $@
	$(AR) $@ $(OBJS)
	$(RANLIB) $@
clean:
	$(rm) $(OBJS) $(LIBNAME) core *~
	$(MAKE) -f ./Makefile-video clean
