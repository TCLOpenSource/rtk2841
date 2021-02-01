##----------------------------------------------------------------------------
# Created with genmake.pl v1.1 on Thu Oct 28 13:37:18 2004
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------

include ../../../../../audio/src/Integrated/src/MakeConfig
LIBNAME= ../../../lib/libaudiorpc.a

#DEFS=

AUDIO_DIR = ../../../../../audio/src/Integrated/project/dvr_audio

ROS_LIB_INSTALL_DIR = $(AUDIO_DIR)/$(LIB_INSTALL_DIR)


INCLUDES =  -I. -I../../include/audio -I$(ROS_LIB_INSTALL_DIR)/include \
	-I$(ROS_LIB_INSTALL_DIR)/include/rt/misc -I../../../include
INCLUDES += -I../../../../../inc
DEFINES= $(INCLUDES) $(DEFS)
CFLAGS= $(DEFINES) $(COMPILE_OPT)

SRCS = AudioRPC_Agent_clnt.c AudioRPC_System_svc.c AudioRPCBaseDS_xdr.c AudioRPC_Agent_xdr.c AudioRPC_System_xdr.c RPCBaseDS_xdr.c
OBJS = AudioRPC_Agent_clnt.o AudioRPC_System_svc.o AudioRPCBaseDS_xdr.o AudioRPC_Agent_xdr.o AudioRPC_System_xdr.o RPCBaseDS_xdr.o

HEADERS= defs.h

%.o : %.c
	@echo "    CC $<"
	@$(rm) -f $@
	@$(CC) $(CFLAGS) $(WARNING) $(DEBUGFLAG) -c $*.c

all: $(LIBNAME)

$(LIBNAME) : $(OBJS)
	$(rm) $@
	$(AR) $@ $(OBJS)
	$(RANLIB) $@
clean:
	$(rm) $(OBJS) $(LIBNAME) core *~
