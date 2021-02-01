/***************************************************************************
                          lara_config.h  -  Model configuration file
                             -------------------
    begin                : Tue Feb 10 2004
    copyright            : (C) 2004 by Lu, Yen-Ju
    email                : yen@realtek.com.tw
 ***************************************************************************/

// $Author: yj_lu $
// $Id: lara_config.h,v 1.5 2004/05/22 10:26:45 yj_lu Exp $

// Behavior Group
#define MCONFIG_BIG_ENDIAN    1         // Run in big-endian/little-endian mode
#define MCONFIG_CPU_NUM       0x1a5     // PrID[25:16]
#define MCONFIG_ISS_MODE      1         // Simulate in ISS mode
#define MCONFIG_AUTORUPT      1         // Enable external interrupt
#define MCONFIG_TIMEOUT       0         // Enable time-out for termination of simulation.
#define MCONFIG_TIMEOUT_CYCLE 500000    // How many thousand cycles to time-out
#define MCONFIG_IO_SYSCALL    0         // Use "syscall 5" to simulate Remote File IO
#define MCONFIG_EXPORT_CTX    1         // Export processor's context to sc_out ports
#define MCONFIG_LARA_TLM      0         // Config LARA as OCP-TLM TL1 model
#define MCONFIG_TLM_BLOCKING  0         // Blocking or non-blocking function call for OCP TL1.
#define MCONFIG_DP_DMEM       0         // Model DMEM as dual-port (DW_GNTRAM always asserted)


#define MCONFIG_SIM_STOP      1         // Enable sim. stop controlled by following addresses
#define MCONFIG_PASS_INST     0xffffffff// Sim. stop at this virtual/logic instruction address
#define MCONFIG_FAIL_INST     0xffffffff// Sim. stop at this virtual/logic instruction address
#define MCONFIG_PASS_DATA     0xbfa00028// Sim. stop at store with this virtual/logic address
#define MCONFIG_FAIL_DATA     0xbfa00024// Sim. stop at store with this virtual/logic address

// Display Group
#define MCONFIG_VERBOSE       0         // Set to 1 to display pipeline details
#define MCONFIG_NO_WARN       0         // Do not show warning message
#define MCONFIG_DUMP_CONTEXT  0         // Dump processor context at the end of execution
#define MCONFIG_USE_RGSN      1         // 0:sp, 1:$29, 2:r29. Reg. s/w name in disassembly

#define MCONFIG_NOP_ULS       0         // Unaligned LW/SW treated as no-op
#define MCONFIG_MNEM_I18      "NEWOPI1" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_I19      "NEWOPI2" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_I1a      "NEWOPI3" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_I1b      "NEWOPI4" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_R38      "NEWOPR1" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_R3a      "NEWOPR2" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_R3b      "NEWOPR3" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_R3c      "NEWOPR4" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_R3e      "NEWOPR5" // Specify CEI instruction's mnemonics
#define MCONFIG_MNEM_R3f      "NEWOPR6" // Specify CEI instruction's mnemonics

// Log/Dump Group
#define MCONFIG_LOG_GPR       0         // Dump gpr write log
#define MCONFIG_LOG_CE0       0         // Dump ce0 write log
#define MCONFIG_LOG_CP0       0         // Dump cop0 write log
#define MCONFIG_LOG_MEM_W     0         // Dump memory write log
#define MCONFIG_LOG_MEM_R     0         // Dump memory read log
#define MCONFIG_LOG_TLB_W     0         // Dump TLB write log
#define MCONFIG_LOG_TLM       0         // Dump TLM transaction info

// Profiling Group
#define MCONFIG_PROFILING     0         // Enable profiling function
#define MCONFIG_PROF_GRANU    1000      // Profiling Granularity (cycles)
#define MCONFIG_PROF_NOFUNC   0         // Do not generate function name in profile.fsdb

// Debug Group
#define MCONFIG_GDB           0         // Enable gdb debug connection, 1 for non-intrusive DSU, 2 for intrusive DSU
#define MCONFIG_TCP_PORT      10000     // Port for Remote protocol to connect
#define MCONFIG_SHOW_PACKET   0         // Display detailed packets of communication
#define MCONFIG_GDB_IO_BASE   0x80000090 // Base address of the memory region for Remote File IO
#define MCONFIG_CHECK_GRANU   10        // Check GDB command every n cycles
#define MCONFIG_RESET_PC      0xbfc00000// The program counter after reset (virtual)

// Lara testbench configuration Group (Applicable only when the Lara's Testbench
// is instantiated.
#define TCONFIG_SR_DELAY      0         // Single Read Trdy delay
#define TCONFIG_SW_DELAY      0         // Single Write Trdy delay
#define TCONFIG_LR_DELAY      0         // Line Read Trdy delay
#define TCONFIG_LW_DELAY      0         // Line Write Trdy delay (not valid for lx5280)
#define TCONFIG_REG_ENVIRON   1         // Special setting and response of lx's regression
#define TCONFIG_NO_CEI        0         // Disable the Testbench's custom engine
#define TCONFIG_EXT_DMEM_ARB  1         // Enable the Testbench to arbitrate for DMEM access
#define TCONFIG_EXT_IMEM_ARB  1         // Enable the Testbench to arbitrate for DMEM access
#define TCONFIG_RAND_SEED     0         // Random seed for Testbench's DMEM ARB. Seed time() if 0.
#define TCONFIG_OCP_ERR_RESP  0         // Enable error response for the memory whole for OCP interface

// Minor and less frequently used configurations
#define MCONFIG_CACHE_ALL     0         // Cache all segment (include Uncacheable seg.)
#define MCONFIG_INIT_DMEM     1         // Init. D-MEM with a same default pattern as RTL model
#define MCONFIG_INIT_IC       0         // Init. ICache Contents with file 'image'
#define MCONFIG_SIM_SPEEDUP   0         // Speedup sim., eg. reduced cycles for cache invalidation
#define MCONFIG_COLOR_MSG     1         // Set to 1 if you have a color terminal
#define MCONFIG_COLOR_HDR     0         // Set to 1 if you have a color terminal
#define MCONFIG_HDR_STRIDE    6         // Display pipeline stage header for every # cycles.
#define MCONFIG_MORE_INFO     0         // Display more model-related information
#define MCONFIG_DUMP_ALL_DMEM 0         // Dump all dmem contents after simulation.
