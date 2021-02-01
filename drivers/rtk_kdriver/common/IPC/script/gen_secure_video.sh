#!/bin/bash
cd ../rpcgen
make clean ;
make ros ;
cp rpcgen.ROS ../script/ ;
cd ../script ;


./parse_script -r ./rpcgen.ROS -f RPCBaseDS.x
mv RPCBaseDS*.h ../generate/include/video
mv RPCBaseDS_xdr.c ../generate/src/video

cd secure

../parse_script -r ../rpcgen.ROS -f SecureRPCBaseDS.x
mv SecureRPCBaseDS_xdr.c ../../generate/src/video
mv SecureRPCBaseDS*.h ../../generate/include/video

../parse_script -r ../rpcgen.ROS -f SecureRPC_System.x
mv SecureRPC_System_xdr.c ../../generate/src/video
mv SecureRPC_System*.h ../../generate/include/video
mv SecureRPC_System_svc.c ../../generate/src/video
mv SecureRPC_System_clnt.c ../../generate/src/video

#../parse_script -r ../rpcgen.ROS -f SecureRPC_System.x -Ss SecureRPC_System_fakeSvc.c
#../parse_script -r ../rpcgen.ROS -f SecureRPC_Agent.x -Ss SecureRPC_System_fakeClnt.c

cd ..



