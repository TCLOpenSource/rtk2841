###################################
# WC case map to DDR
###################################
RESET_ADDR 			= 0xBFC00000

##################################
# Single CPU USE
# map to ROM
##################################
SINGLE_RESET_ADDR 	= 0xBFC00000
BEV1_ADDR 			= 0xBFC00180
PLL_MAP_ADDR    	= 0xBFC01000
DCU1_MAP_ADDR   	= 0xBFC01080

###################################
# Others map to DDR
###################################
BEV0_ADDR 		    = 80000080
USER_PROG_ADDR_ACPU = 80204000 

STACK_ADDR     		= 80003000
STACK_ADDR_SCPU		= 80003000
STACK_ADDR_VCPU		= 80103000
STACK_ADDR_ACPU		= 80203000

INTVEC_ADDR     	= 80001000		#no INTVEC_ADDR_SCPU needed in Mars
INTVEC_ADDR_VCPU	= 80101000		#no INTVEC_ADDR_SCPU needed in Mars
INTVEC_ADDR_ACPU	= 80201000

INCLUDE = ${PROJECT_HOME}/verification/common/include
OBJECTS = $(reset_handler_obj) $(stack_obj) $(pll_obj) $(dcu1_obj) $(excp_obj)
#--- for vcpu/acpu compiler ----- 
GCC     = mips-rsdk-elf-gcc
OBJDUMP = mips-rsdk-elf-objdump
OBJCOPY = mips-rsdk-elf-objcopy
BOOT_ADDR_MAP = -DPLL_PARAM=${PLL_MAP_ADDR} -DDCU1_PARAM=${DCU1_MAP_ADDR} 
CFLAG_RESET = -DDDR3=1 ${BOOT_ADDR_MAP}
CFLAG_COMMON = $(BOOT_LOCAL) -x assembler-with-cpp -O0 -G0 -Wall -I${PROJECT_HOME}/verification/common/include -N -n -nostartfiles
CFLAGS  = $(CFLAG_COMMON) -march=5280 -EB

#####################################################################################
# Boot Code
#####################################################################################
reset_handler_obj = \
    reset_handler.o wc_reset_handler.o \
    remap_reset_handler.o wc_remap_reset_handler.o 
#####################################################################################
# Stack Setting
#####################################################################################
stack_obj = stack_acpu.o stack_vcpu.o stack.o
#####################################################################################
# Excp Setting
#####################################################################################
excp_obj = $(excp_normal_obj) $(excp_rand_obj)
excp_normal_obj = \
    excp_handler_intvec.o       \
    excp_handler_intvec_acpu.o  \
    excp_handler_intvec_vcpu.o  \
    excp_handler_bev0.o         \
    wc_excp_handler_bev0.o 
excp_rand_obj = \
    rnd_excp_handler_intvec.o       \
    rnd_excp_handler_intvec_acpu.o  \
    rnd_excp_handler_intvec_vcpu.o  \
    rnd_excp_handler_bev0.o         \
    rnd_wc_excp_handler_bev0.o
CFLAG_RND = -DRANDOM=1

#####################################################################################
# PLL Setting
#####################################################################################
CFLAG_PLL   = -e pll_param -Ttext ${PLL_MAP_ADDR}  -DMAP_START=${PLL_MAP_ADDR}
pll_obj     = pll_map.o pll_map_ddr2.o
#####################################################################################
# DCU Setting
#####################################################################################
CFLAG_DCU1     = -e dcu_param -Ttext ${DCU1_MAP_ADDR} -DMAP_START=${DCU1_MAP_ADDR}
CFLAG_DDR3_2k1 = -DDDR3=1 -DSDRAM_2K_1DDR=1
CFLAG_DDR3_4k2 = -DDDR3=1 -DSDRAM_4K_2DDR=1
CFLAG_DDR2_2k1 = -DDDR2=1 -DSDRAM_2K_1DDR=1
dcu1_obj = \
    dcu1_2k1_DDR3_512.o  \
    dcu1_2k1_DDR3.o      \
    dcu1_2k1_DDR3_2G.o   \
    dcu1_2k1_DDR3_4G.o   \
    dcu1_2k1_DDR3_8G.o   \
    dcu1_4k2_DDR3_512.o  \
    dcu1_4k2_DDR3.o      \
    dcu1_4k2_DDR3_2G.o   \
    dcu1_4k2_DDR3_4G.o   \
    dcu1_4k2_DDR3_8G.o   \
    dcu1_4k2_DDR3_4G2G.o \
    dcu1_4k2_DDR3_2G4G.o \
    $(dcu1_ddr2_obj)
dcu1_ddr2_obj = \
    dcu1_2k1_DDR2_512.o



#--------------------------------
all: $(OBJECTS)

reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${SINGLE_RESET_ADDR} -DSINGLE_CPU $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
remap_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${SINGLE_RESET_ADDR} -DDC_REMAP -DSINGLE_CPU $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
wc_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${RESET_ADDR} $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
wc_remap_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${RESET_ADDR} -DDC_REMAP $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
#---------------------------------------
#Stack
stack.o: stack.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${STACK_ADDR} -e _test_pass $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
stack_acpu.o: stack.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${STACK_ADDR_ACPU} -e _test_pass $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
stack_vcpu.o: stack.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${STACK_ADDR_VCPU} -e _test_pass $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
#---------------------------------------
#Excp
excp_handler_intvec.o: excp_handler_intvec.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${INTVEC_ADDR} -DSINGLE_CPU -e excp_handler_intvec $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
excp_handler_intvec_acpu.o: excp_handler_intvec_acpu.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${INTVEC_ADDR_ACPU} -e excp_handler_intvec $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
excp_handler_intvec_vcpu.o: excp_handler_intvec_vcpu.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${INTVEC_ADDR_VCPU} -e excp_handler_intvec $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
excp_handler_bev0.o: excp_handler_bev0.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${BEV0_ADDR} -DSINGLE_CPU -e excp_handler_bev0 $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
wc_excp_handler_bev0.o: excp_handler_bev0.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${BEV0_ADDR} -e excp_handler_bev0 $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text


rnd_excp_handler_intvec.o: excp_handler_intvec.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${INTVEC_ADDR} -DSINGLE_CPU -e excp_handler_intvec $(CFLAGS) $(CFLAG_RND) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
rnd_excp_handler_intvec_acpu.o: excp_handler_intvec_acpu.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${INTVEC_ADDR_ACPU} -e excp_handler_intvec $(CFLAGS) $(CFLAG_RND) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
rnd_excp_handler_intvec_vcpu.o: excp_handler_intvec_vcpu.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${INTVEC_ADDR_VCPU} -e excp_handler_intvec $(CFLAGS) $(CFLAG_RND) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
rnd_excp_handler_bev0.o: excp_handler_bev0.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${BEV0_ADDR} -DSINGLE_CPU -e excp_handler_bev0 $(CFLAGS) $(CFLAG_RND) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
rnd_wc_excp_handler_bev0.o: excp_handler_bev0.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${BEV0_ADDR} -e excp_handler_bev0 $(CFLAGS) $(CFLAG_RND) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
#---------------------------------------
#PLL
pll_map.o: pll_map.s ${INCLUDE}/*.h
	$(GCC) -o $@ ${CFLAG_PLL} -DDDR3=1 $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text

pll_map_ddr2.o: pll_map.s ${INCLUDE}/*.h
	$(GCC) -o $@ ${CFLAG_PLL} -DDDR2=1 $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text

#---------------------------------------
#DCU1
dcu1_2k1_DDR3_512.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX512=1 ${CFLAG_DDR3_2k1} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_2k1_DDR3.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1}          ${CFLAG_DDR3_2k1} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_2k1_DDR3_2G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX2G=1 ${CFLAG_DDR3_2k1} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_2k1_DDR3_4G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX4G=1 ${CFLAG_DDR3_2k1} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_2k1_DDR3_8G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX8G=1 ${CFLAG_DDR3_2k1} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3_512.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX512=1 ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1}          ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3_2G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX2G=1 ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3_4G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX4G=1 ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3_8G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX8G=1 ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3_4G2G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DEN_2DDR_SIZE_4G2G=1 ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
dcu1_4k2_DDR3_2G4G.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DEN_2DDR_SIZE_2G4G=1 ${CFLAG_DDR3_4k2} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text

#---------------------------------------
dcu1_2k1_DDR2_512.o: dcu_map.s
	$(GCC) -o $@ ${CFLAG_DCU1} -DX4G=1 ${CFLAG_DDR2_2k1} $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text



#####################################################################################
# BU_SIM Code
#####################################################################################
bu_reset_handler_obj = \
bu_reset_handler.o bu_remap_reset_handler.o bu_wc_reset_handler.o bu_wc_remap_reset_handler.o \
bu_stack.o bu_stack_acpu.o bu_stack_vcpu.o

BU_OBJECTS = $(bu_reset_handler_obj)
BU_CFLAGS = -DBU_SIM=1 $(CFLAGS)
BU_SIM: $(BU_OBJECTS)

bu_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${SINGLE_RESET_ADDR} -DSINGLE_CPU $(CFLAG_RESET) -e reset_handler $(BU_CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
bu_remap_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${SINGLE_RESET_ADDR} -DDC_REMAP -DSINGLE_CPU $(CFLAG_RESET) -e reset_handler $(BU_CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
bu_wc_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${RESET_ADDR} $(CFLAG_RESET) -e reset_handler $(BU_CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
bu_wc_remap_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${RESET_ADDR} -DDC_REMAP $(CFLAG_RESET) -e reset_handler $(BU_CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
bu_stack.o: stack.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${STACK_ADDR} -e _test_pass -DSINGLE_CPU=1 -DBU_ACPU_ON=1 -DBU_VCPU_ON=1 $(BU_CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
bu_stack_acpu.o: stack.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${STACK_ADDR_ACPU} -e _test_pass -DBU_ACPU_ON=1 $(BU_CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
bu_stack_vcpu.o: stack.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${STACK_ADDR_VCPU} -e _test_pass -DBU_VCPU_ON=1 $(BU_CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text
#####################################################################################
# END BU_SIM 
#####################################################################################

#####################################################################################
# GATESIM code
#####################################################################################
gs_objs = \
gs_reset_handler.o gs_wc_reset_handler.o \
gs_remap_reset_handler.o gs_wc_remap_reset_handler.o \
gs_pll_map.o gs_pll_map_ddr2.o
GATESIM: $(gs_objs)


gs_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${SINGLE_RESET_ADDR} -DSINGLE_CPU -DGATESIM $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
gs_remap_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${SINGLE_RESET_ADDR} -DDC_REMAP -DSINGLE_CPU -DGATESIM $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
gs_wc_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${RESET_ADDR} -DGATESIM $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text
gs_wc_remap_reset_handler.o: reset_handler.s ${INCLUDE}/*.h
	$(GCC) -o $@ -Ttext ${RESET_ADDR} -DDC_REMAP -DGATESIM $(CFLAG_RESET) -e reset_handler $(CFLAGS)  $<
	$(OBJDUMP) -S $@ > $(basename $@).text

gs_pll_map.o: pll_map.s ${INCLUDE}/*.h
	$(GCC) -o $@ ${CFLAG_PLL} -DDDR3=1 -DGATESIM $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text

gs_pll_map_ddr2.o: pll_map.s ${INCLUDE}/*.h
	$(GCC) -o $@ ${CFLAG_PLL} -DDDR2=1 -DGATESIM $(CFLAGS) $<
	$(OBJDUMP) -S $@ > $(basename $@).text



#####################################################################################
# END GATESIM
#####################################################################################



my_clean:
	/bin/rm -f  $(reset_handler_obj) $(dcu_obj) $(dcu2_obj)
#------------------------------------------------------------
.PHONY:	clean clobber
clean:
	/bin/rm -f *.o *.text *.hex

clobber:
	/bin/rm -rf *.o *.text *.hex INCA_libs *.dump *.log *.fsdb ignore.out debussyLog ncverilog.key runtime.f saturn cpu.trace >& /dev/null
#------------------------------------------------------------

