#!/bin/bash
cd ../rpcgen
make clean ;
make linux;
cp rpcgen.linux ../script/ ;
cd ../script ;

./parse_script -r ./rpcgen.linux -f RPCBaseDS.x
mv RPCBaseDS*.h ../generate/include/system
mv RPCBaseDS_xdr.c ../generate/src/system

cd video
../parse_script -r ../rpcgen.linux -f VideoRPC_Agent.x
mv VideoRPC_Agent_xdr.c ../../generate/src/system
mv VideoRPC_Agent*.h ../../generate/include/system
mv VideoRPC_Agent_svc.c ../../generate/src/system
rm VideoRPC_Agent_clnt.c

../parse_script -r ../rpcgen.linux -f VideoRPCBaseDS.x
mv VideoRPCBaseDS_xdr.c ../../generate/src/system
mv VideoRPCBaseDS*.h ../../generate/include/system

../parse_script -r ../rpcgen.linux -f VideoRPC_System.x
mv VideoRPC_System_xdr.c ../../generate/src/system
mv VideoRPC_System*.h ../../generate/include/system
mv VideoRPC_System_clnt.c ../../generate/src/system
rm VideoRPC_System_svc.c

cp -f ../../generate/src/system/VideoRPC* ../../generate/src/secure
cp -f ../../generate/include/system/VideoRPC* ../../generate/include/secure
cd ../
rm rpcgen.linux

