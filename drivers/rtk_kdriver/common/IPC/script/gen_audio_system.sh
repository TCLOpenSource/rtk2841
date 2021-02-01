#!/bin/bash
# modified from gen_video_system.sh, ychen
echo Compile rpcgen
cd ../rpcgen
make clean ;
make linux;
cp rpcgen.linux ../script/ ;
cd ../script ;

echo Convert RPCBaseDS.x
./rpcgen.linux RPCBaseDS.x
mv -f RPCBaseDS*.h ../generate/include/system
mv -f RPCBaseDS_xdr.c ../generate/src/system

echo Convert AudioRPC_Agent.x
cd audio
../rpcgen.linux AudioRPC_Agent.x
mv -f AudioRPC_Agent_xdr.c ../../generate/src/system
mv -f AudioRPC_Agent*.h ../../generate/include/system
mv -f AudioRPC_Agent_svc.c ../../generate/src/system
rm -f AudioRPC_Agent_clnt.c

echo Convert AudioRPCBaseDS.x
../rpcgen.linux AudioRPCBaseDS.x
mv -f AudioRPCBaseDS_xdr.c ../../generate/src/system
mv -f AudioRPCBaseDS*.h ../../generate/include/system

echo Convert AudioRPC_System.x
../rpcgen.linux AudioRPC_System.x
mv -f AudioRPC_System_xdr.c ../../generate/src/system
mv -f AudioRPC_System*.h ../../generate/include/system
mv -f AudioRPC_System_clnt.c ../../generate/src/system
rm -f AudioRPC_System_svc.c

cp -f ../../generate/src/system/AudioRPC* ../../generate/src/secure
cp -f ../../generate/include/system/AudioRPC* ../../generate/include/secure
