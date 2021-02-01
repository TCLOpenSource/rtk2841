#!/bin/bash
# modified from gen_video_system.sh, ychen
echo Compile rpcgen
cd ../rpcgen
make clean ;
make all ;
cp rpcgen.ROS ../script/ ;
cp rpcgen.linux ../script/ ;
cd ../script ;

echo Convert RPCBaseDS.x ROS version
./rpcgen.ROS RPCBaseDS.x
mv -f RPCBaseDS*.h ../generate/include/audio
mv -f RPCBaseDS_xdr.c ../generate/src/audio

echo Convert AudioRPC_Agent.x ROS version
cd audio
../rpcgen.ROS AudioRPC_Agent.x
mv -f AudioRPC_Agent_xdr.c ../../generate/src/audio
mv -f AudioRPC_Agent*.h ../../generate/include/audio
mv -f AudioRPC_Agent_clnt.c ../../generate/src/audio
rm -f AudioRPC_Agent_svc.c

echo Convert AudioRPCBaseDS.x ROS version
../rpcgen.ROS AudioRPCBaseDS.x
mv -f AudioRPCBaseDS_xdr.c ../../generate/src/audio
mv -f AudioRPCBaseDS*.h ../../generate/include/audio

echo Convert AudioRPC_System.x ROS version
../rpcgen.ROS AudioRPC_System.x
mv -f AudioRPC_System_xdr.c ../../generate/src/audio
mv -f AudioRPC_System*.h ../../generate/include/audio
mv -f AudioRPC_System_svc.c ../../generate/src/audio
rm -f AudioRPC_System_clnt.c

