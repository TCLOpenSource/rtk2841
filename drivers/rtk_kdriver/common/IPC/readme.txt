HOW TO install RPC procedure:

 (NOTE***) Demo Machine 上已有裝好的新版 RPC module, 不需再另外安裝
           一般使用者可跳過此段
(一) Install Linux's RPC Module

 (1) 解開 linux-test-module.tar.gz
     在 rpcjacky/TestDriver/ 底下, 打 make clean; make
     如果失敗, 編輯 Makefile , 
     有個 KERNELDIR 的變數, 要指去 linux kernel source code 的路徑... (沒有? 去抓 kernel src...)

 (2) make 成功後執行 insmod ./RPC.o (insert module)...
     應該會有一些 warning, 不用理他
     看到 Module RPC loaded, with warnings 應該就是 insert 好了

 (3) more /proc/devices | grep RPC
     如果有號碼, 就把它記起來 (假設是 254)
 
 (4) 建目錄 /dev/rpc
     cd /dev/rpc;  
     用剛剛的號碼建 2 個 device
     mknod 0 c 254 1;
     mknod 1 c 254 2;         
     

====================================================================================

HOW TO use RPC procedure :

 (1) Run RPC module
     (Description) 如果 OS 的 RPC module 還沒 run 起來, 就要手動 run RPC module
 
 (2) <編輯 Script 檔>
     (Description) 編輯一個 script 檔, 注意 program id 和 version id 要和別人不同!
                   範例參考  "VideoEncoder_System.x",      
                   這是 Video Encoder 的 system CPU 要送給 Video CPU 所需的 funciton 和 data structure
                   在 script 前幾行, 可加入一些 .insert <...>
                   在 generate 出來的 .h 檔中, 就會有這幾行 #include...
     (example) 
            .insert <RPCBaseDS.h>
            struct AA {
              long sum;
              char t_char;
            }
            
            program ITest {
              version VERSION {
                 int VE_RPC_RequestWriteSpace(long)=1;
                 struct AA TestFunction(char)=2;
              }=0;
            }=0;
            
     (NOTE****) program ID 編號規則：  0~100 給 RPC library 使用
                                     100~200 給 Video Team 使用
                                     200~300 給 Audio Team 使用
                                     300~400 給 System Team 使用
  
 (3) <Run rpcgen 來產生 code>
     (Description) 目錄在 common/IPC/rpcgen, 平台為 Linux
                   cd rpcgen/;  修改 Makefile, 來看要產生 Linux 或是 ROS 版本
                   執行 ./rpcgen VideoEncoder_System.x
                   會產生 .h  _data.h  _svc.c _clnt.c _xdr.c 這五個檔案
  
 (4) <產生 Function implement template>
     (Description) 這個步驟不是必需, 但如果需要產生一個 被呼叫端實作的 template 檔
                   可以使用指令: ./rpcgen -Ss VideoEncoder_System.x 
                   會把 template 印在螢幕上
                   使用指令 ./rpcgen -Ss VideoEncoder_System.x > template.c
                   就會導入 template.c 這個檔案
     
 (5) <產生檔案說明>
     (Description) _svc.c 放在被呼叫的那一端 (範例是 src/Filters/VideoEncoder/agent/)
                   _clnt.c 放在呼叫的那一端  (範例是 src/Filters/VideoEncoder/system/)     
                   .h _data.h _xdr.c 這三個檔案, 呼叫端和被呼叫端都需要放
     
 (5) <被呼叫端: 程式實作>
     (Desctiption) 編輯被呼叫的 function 檔案 (範例是 src/Filter/VideoEncoder/agent/SystemRPCFunction.cpp)
                   如果當初在 .x 內所定義的 function name 是 VE_RPC_RequestWriteSpace();
                   那被呼叫端相對應的 function name 就是 VE_RPC_RequestWriteSpace_VERSION數字_svc();
     (NOTE***) 可使用 (4) 步驟來產生 template 檔
     (example) 
           int *
           VE_RPC_RequestWriteSpace_0_svc(long *argp, RPC_STRUCT *rpc) {
               static int result;    // NOTE*** 必須宣告成 static !!!!!!!
               result = 321;
               return &result;
           }
 
 (6) <呼叫端：使用方法>
     (Desctiption) 呼叫前, 記得先使用 function: 
                   struct CLNT_STRUCT clnt = prepareCLNT(mode, PROGRAM NAME, VERSION NAME); 
                   其中 mode 有 BLOCK_MODE, NONBLOCK_MODE, USE_INTR_BUF, USE_POLL_BUF   
     
                   然後再呼叫 function:  
                        return參數 = VE_RPC_RequestWriteSpace_0(&自訂參數, &clnt);
                   其中 clnt 是剛剛用 prepareCLNT(); 得到的結果
     (example)
           int *result;
           long arg = 123;
        
           CLNT_STRUCT clnt = prepareCLNT(BLOCK_MODE | USE_POLL_BUF, ITest, Version);
           result = VE_RPC_RequestWriteSpace_0(&arg, &clnt);
        
           if (result) == (int *)-1)
               printf("function send error\n");
           else
               printf("function send success, return value: %d \n", *result);
                 
           free(result);     // NOTE*** 必須手動 free result !!!!!!!
 
 (7) <測試方法>
     (Desctiption) 以後 RPC alwayse listen 的 dispatch thread 會由 OS boot 起來的時候 run
                   但是現在必須我們手動加入
     
                   Unit_test (範例在 src/Unit_test/DVDAuthoringTest/main.cpp)
                   需要呼叫 register function, 
                   把這個 program 註冊進去 (範例是 VIDEO_ENCODER_0_register();)
                   還要記得註冊 reply handler (範例是 ReplyHandler_register();)
                   然後 create RPCProxy 的 Thread 來 listen... 

     (example)
           struct REG_STRUCT * rnode = NULL;

           // 以下是 register function 們
           rnode = (struct REG_STRUCT *)VIDEO_ENCODER_SYSTEM_0_register(rnode);  // Client program 0
           rnode = (struct REG_STRUCT *)VIDEO_ENCODER_AGENT_0_register(rnode);  // Client program 1
           rnode = (struct REG_STRUCT *)ReplyHandler_register(rnode);  // Reply Handler    
           
           initRPCProxy(rnode); // 將 RPC listen 的 dispatch thread run 起來 
     
     
 (8) <link library>
     (Description) link 的時候, 記得去找 library:  libRPC.a librtxdr.a
                   都在 common/IPC/src/ 底下可以 generate 出來
      