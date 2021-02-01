#!/bin/bash
cp ../rpcgen/rpcgen.linux . ;

mkdir -p ../generate/include/secure
mkdir -p ../generate/src/secure

./parse_script -r ./rpcgen.linux -f RPCBaseDS.x
mv RPCBaseDS*.h ../generate/include/system
mv RPCBaseDS_xdr.c ../generate/src/system

cd secure
../parse_script -r ../rpcgen.linux -f SecureRPC_Agent.x
mv SecureRPC_Agent_xdr.c ../../generate/src/system
mv SecureRPC_Agent*.h ../../generate/include/system
mv SecureRPC_Agent_svc.c ../../generate/src/system
rm SecureRPC_Agent_clnt.c

../parse_script -r ../rpcgen.linux -f SecureRPCBaseDS.x
mv SecureRPCBaseDS_xdr.c ../../generate/src/system
mv SecureRPCBaseDS*.h ../../generate/include/system

../parse_script -r ../rpcgen.linux -f SecureRPC_System.x
mv SecureRPC_System_xdr.c ../../generate/src/system
mv SecureRPC_System*.h ../../generate/include/system
mv SecureRPC_System_clnt.c ../../generate/src/system
rm SecureRPC_System_svc.c

cd ../
rm rpcgen.linux

