##----------------------------------------------------------------------------
# Created with genmake.pl v1.1 on Tue Apr 13 17:13:41 2004
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------
rm=/bin/rm -f

include ../../CommonConfig

DEFS=  -DSUPPORT_PRC_VIDEO_CPU2 #-DRPC_DEBUG

CC= $(MYCC)
AR= $(MYAR) cq
RANLIB= $(MYRANLIB)
LIBNAME= ../lib/libRPC.a

INCLUDES+=  -I. -I../include/
INCLUDES+= -I../../../inc
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

ifeq ($(IS_SCPU), YES)
DEFS += -DIS_SCPU -DUSE_TIMED_WAITREPLY
endif

ifeq ($(ENABLE_TEEMANAGER_IN_KCPU), YES)
DEFINES += -DENABLE_TEEMANAGER_IN_KCPU
endif

#DEFINES= $(INCLUDES) $(DEFS) -DSYS_UNIX=1 -D_GNU_SOURCE
CFLAGS= $(INCLUDES) $(DEFINES) $(DEFS) -DSYS_UNIX=1 -D_GNU_SOURCE -Wall -g

SUBDIRS = xdr

ifeq ($(TARGET_BOARD), YES)
CFLAGS+= -DTARGET_BOARD
endif
ifeq ($(COMPILE_SHARED_LIB), YES)
CFLAGS  += -fPIC
endif

#SRCS = RPCstruct.c rpcapi.c RPCProxy.c SVCFunc.c rpcstubapi.c ClientStub.c
#OBJS = RPCstruct.o rpcapi.o RPCProxy.o SVCFunc.o rpcstubapi.o ClientStub.o

SRCS = RPCstruct.c SVCFunc.c ClientStub.c
OBJS = RPCstruct.o SVCFunc.o ClientStub.o

ifneq ($(ENABLE_SECURE_CPU), YES)
SRCS += rpcapi.c RPCProxy.c rpcstubapi.c
OBJS += rpcapi.o RPCProxy.o rpcstubapi.o
else
SRCS += rpcapi_secure.c RPCProxy_secure.c rpcstubapi_secure.c
OBJS += rpcapi_secure.o RPCProxy_secure.o rpcstubapi_secure.o
endif

.o:
	$(rm) -f $@
	$(CC) $(CFLAGS) -c $*.c

all: $(LIBNAME) 
	set -e; for i in $(SUBDIRS); do $(MAKE) -C $$i; done
#	$(CC) UserTask.c -L./ -lcln -L./xdr/ -lrtxdr

#all: $(OBJS)
#	gcc -shared -o libcli.so $(OBJS)

$(LIBNAME) : $(OBJS)
	$(rm) $@
	$(AR) $@ $(OBJS) 
	$(RANLIB) $@



clean:
	set -e; for i in $(SUBDIRS); do $(MAKE) clean -C $$i; done; rm -rf ../lib/*
	$(rm) $(OBJS) $(LIBNAME) libcln.so a.out core.* *~


