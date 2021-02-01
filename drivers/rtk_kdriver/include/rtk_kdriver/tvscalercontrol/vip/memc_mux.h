
#ifdef CONFIG_HW_SUPPORT_MEMC
void drvif_memc_mux_en(bool enable);
void drvif_memc_mux_Dither_ctrl(bool enable, bool temp_en);
void drvif_memc_mux_in_CSC_ctrl(bool enable);
void drvif_memc_mux_out_CSC_ctrl(bool enable);
void drvif_memc_mux_in_CSC_int(bool enable);
void drvif_memc_mux_out_CSC_int(bool enable);
void drvif_memc_mux_setdithering(unsigned char DI_Bit);   // parameter DI_Bit=2 , 12->10 bit dithering
#endif

