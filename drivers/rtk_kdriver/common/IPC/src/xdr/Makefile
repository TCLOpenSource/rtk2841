##----------------------------------------------------------------------------
# Created with genmake.pl v1.1 on Tue Apr 13 17:13:41 2004
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------
rm=/bin/rm -f

include ../../../CommonConfig

DEFS=  #-DRPC_DEBUG
LIBNAME= ../../lib/librtxdr.a

INCLUDES+=  -I. -I../../include
INCLUDES+= -I../../../../inc
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
INCLUDES+= -I$(ANDROID_CODENAME_ROOT)/bionic/libm/include
endif
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
DEFS += -DIS_SCPU
endif

CC= $(MYCC)
ifdef PKG_CONFIG_SYSROOT_DIR
else
AR= $(MYAR) cq
endif
RANLIB= $(MYRANLIB)
DEFINES= $(INCLUDES) $(DEFS) -DSYS_UNIX=1
ifeq ($(ENABLE_BIONIC_BUILD), YES)
    #ifeq ($(ENABLE_RUN_ON_MAGELLAN), YES)
    ifneq (, $(filter YES, $(ENABLE_RUN_ON_MAGELLAN) $(ENABLE_RUN_ON_SIRIUS) $(ENABLE_RUN_ON_MACARTHUR3))) # either ENABLE_RUN_ON_MAGELLAN=YES or ENABLE_RUN_ON_SIRIUS=YES or ENABLE_RUN_ON_MACARTHUR3=YES
    DEFINES += -fno-exceptions
    else
    DEFINES += -fno-exceptions -EL 
    endif
endif #ENABLE_BIONIC_BUILD
CFLAGS= $(DEFINES)
ifeq ($(COMPILE_SHARED_LIB), YES)
CFLAGS  += -fPIC
endif

ifeq ($(TARGET_BOARD), YES)
DEFINES+= -DTARGET_BOARD
endif
ifeq ($(ENABLE_TEEMANAGER_IN_KCPU), YES)
DEFINES += -DENABLE_TEEMANAGER_IN_KCPU
endif

SRCS = xdr.c xdr_mem.c xdr_array.c xdr_float.c xdr_process.c xdr_ref.c xdr_sizeof.c

OBJS = xdr.o xdr_mem.o xdr_array.o xdr_float.o xdr_process.o xdr_ref.o xdr_sizeof.o

.o:
	$(rm) -f $@
	$(CC) $(CFLAGS) -c $*.c

all: $(LIBNAME)

#all: $(OBJS)
#	gcc -shared -o librtxdr.so $(OBJS)

$(LIBNAME) : $(OBJS)
	$(rm) $@
	$(AR) $@ $(OBJS)
	$(RANLIB) $@

clean:
	$(rm) $(OBJS) $(LIBNAME) librtxdr.so core *~

