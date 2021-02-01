#!/bin/bash
cd ../rpcgen
make clean ;
make ros ;
cp rpcgen.ROS ../script/ ;
cd ../script ;



./parse_script -r ./rpcgen.ROS -f RPCBaseDS.x
mv RPCBaseDS*.h ../generate/include/video
mv RPCBaseDS_xdr.c ../generate/src/video

cd video

../parse_script -r ../rpcgen.ROS -f VideoRPC_Agent.x
mv VideoRPC_Agent_xdr.c ../../generate/src/video
mv VideoRPC_Agent*.h ../../generate/include/video
mv VideoRPC_Agent_clnt.c ../../generate/src/video
mv VideoRPC_Agent_svc.c ../../generate/src/video

../parse_script -r ../rpcgen.ROS -f VideoRPCBaseDS.x
mv VideoRPCBaseDS_xdr.c ../../generate/src/video
mv VideoRPCBaseDS*.h ../../generate/include/video

../parse_script -r ../rpcgen.ROS -f VideoRPC_System.x
mv VideoRPC_System_xdr.c ../../generate/src/video
mv VideoRPC_System*.h ../../generate/include/video
mv VideoRPC_System_svc.c ../../generate/src/video
mv VideoRPC_System_clnt.c ../../generate/src/video

cp Video_InbandAPI.h ../../generate/include/video

../parse_script -r ../rpcgen.ROS -f VideoRPC_System.x -Ss VideoRPC_System_fakeSvc.c
../parse_script -r ../rpcgen.ROS -f VideoRPC_Agent.x -Ss VideoRPC_System_fakeClnt.c


cd ..



