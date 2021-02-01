-include ../../CommonConfig

RM = /bin/rm
GCC = /usr/bin/gcc

#WITH_ROS = NO

ifeq ($(WITH_ROS), YES)
DEFINES+= -DROS
endif

all: ros linux
#	${GCC} $(DEFINES) -g -o rpcgen.linux rpc*.c 	

ros:
	make clean ;
	${GCC} -DROS -g -o rpcgen.ROS rpc*.c
linux:
	make clean ;
	${GCC} -g $(RPCGEN_DEFINES) -o rpcgen.linux rpc*.c
clean:
	${RM} -f sample_clnt.c
	${RM} -f sample.h
	${RM} -f sample_svc.c
	${RM} -f sample_xdr.c
	$(RM) -f rpcgen
	$(RM) -f core*
	$(RM) -f *~

cleanall: clean
	$(RM) -f rpcgen.linux
	$(RM) -f rpcgen.ROS
