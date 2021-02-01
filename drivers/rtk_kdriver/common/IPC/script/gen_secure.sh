#!/bin/bash
cp ../rpcgen/rpcgen.linux . ;

mkdir -p ../generate/include/secure
mkdir -p ../generate/src/secure

./parse_script -r ./rpcgen.linux -f RPCBaseDS.x
mv RPCBaseDS*.h ../generate/include/secure
mv RPCBaseDS_xdr.c ../generate/src/secure

cd secure
../parse_script -r ../rpcgen.linux -f SecureRPC_Agent.x
mv SecureRPC_Agent_xdr.c ../../generate/src/secure
mv SecureRPC_Agent*.h ../../generate/include/secure
mv SecureRPC_Agent_clnt.c ../../generate/src/secure
rm SecureRPC_Agent_svc.c

../parse_script -r ../rpcgen.linux -f SecureRPCBaseDS.x
mv SecureRPCBaseDS_xdr.c ../../generate/src/secure
mv SecureRPCBaseDS*.h ../../generate/include/secure

../parse_script -r ../rpcgen.linux -f SecureRPC_System.x
mv SecureRPC_System_xdr.c ../../generate/src/secure
mv SecureRPC_System*.h ../../generate/include/secure
mv SecureRPC_System_svc.c ../../generate/src/secure
rm SecureRPC_System_clnt.c

cd ../
rm rpcgen.linux

