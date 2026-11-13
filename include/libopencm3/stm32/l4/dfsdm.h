#ifndef DFSDM_H
#define DFSDM_H

#define DFSDM_CHANNEL_MAX 7
#define CHANNEL_SANITY_CHECK_RETURN(channel) do { if(channel > DFSDM_CHANNEL_MAX) return; } while(0);

/****** DFSDM_CHyCFGR1 ******/
#define DFSDM_CHyCFGR1_ADDR(y) (DFSDM_BASE+(0x20*y))
#define DFSDM_CHyCFGR1(y) MMIO32(DFSDM_CHyCFGR1_ADDR(y))

#define DFSDM_CHyCFGR1_DFSDM_EN_SHIFT 31
#define DFSDM_CHyCFGR1_DFSDM_EN_MASK 0x1

#define DFSDM_CHyCFGR1_CKOUTSRC_SHIFT 30
#define DFSDM_CHyCFGR1_CKOUTSRC_MASK 0x1

#define DFSDM_CHyCFGR1_CKOUTDIV_SHIFT 16
#define DFSDM_CHyCFGR1_CKOUTDIV_MASK 0xFF

#define DFSDM_CHyCFGR1_DATPACK_SHIFT 14
#define DFSDM_CHyCFGR1_DATPACK_MASK 0x3

#define DFSDM_CHyCFGR1_DATMPX_SHIFT 12
#define DFSDM_CHyCFGR1_DATMPX_MASK 0x3

#define DFSDM_CHyCFGR1_CHINSEL_SHIFT 8
#define DFSDM_CHyCFGR1_CHINSEL_MASK 0x1

#define DFSDM_CHyCFGR1_CHEN_SHIFT 7
#define DFSDM_CHyCFGR1_CHEN_MASK 0x1

#define DFSDM_CHyCFGR1_CKABEN_SHIFT 6
#define DFSDM_CHyCFGR1_CKABEN_MASK 0x1

#define DFSDM_CHyCFGR1_SCDEN_SHIFT 5
#define DFSDM_CHyCFGR1_SCDEN_MASK 0x1

#define DFSDM_CHyCFGR1_SPICKSEL_SHIFT 2
#define DFSDM_CHyCFGR1_SPICKSEL_MASK 0x3

#define DFSDM_CHyCFGR1_SITP_SHIFT 0
#define DFSDM_CHyCFGR1_SITP_MASK 0x3

/****** DFSDM_CHyCFGR1 config bits ******/
#define DFSDM_CHyCFGR1_DFSDM_EN_DISABLE 0
#define DFSDM_CHyCFGR1_DFSDM_EN_ENABLE 1

#define DFSDM_CHyCFGR1_CKOUTSRC_SYS 0
#define DFSDM_CHyCFGR1_CKOUTSRC_AUDIO 1

#define DFSDM_CHyCFGR1_DATPACK_STANDARD 0
#define DFSDM_CHyCFGR1_DATPACK_INTERLEAVED 1
#define DFSDM_CHyCFGR1_DATPACK_DUAL 2

#define DFSDM_CHyCFGR1_DATMPX_EXT 0
#define DFSDM_CHyCFGR1_DATMPX_ADC 1
#define DFSDM_CHyCFGR1_DATMPX_CPU_DMA 2

#define DFSDM_CHyCFGR1_CHINSEL_SAME 0
#define DFSDM_CHyCFGR1_CHINSEL_FOLLOWING 1

#define DFSDM_CHyCFGR1_CHEN_DISABLE 0
#define DFSDM_CHyCFGR1_CHEN_ENABLE 1

#define DFSDM_CHyCFGR1_CKABEN_DISABLE 0
#define DFSDM_CHyCFGR1_CKABEN_ENABLE 1

#define DFSDM_CHyCFGR1_SCDEN_DISABLE 0
#define DFSDM_CHyCFGR1_SCDEN_ENABLE 1

#define DFSDM_CHyCFGR1_SPICKSEL_CKINy_SITP 0
#define DFSDM_CHyCFGR1_SPICKSEL_CKOUT_SITP 1
#define DFSDM_CHyCFGR1_SPICKSEL_CKOUT_2FALL_EDGE 2
#define DFSDM_CHyCFGR1_SPICKSEL_CKOUT_2RISE_EDGE 3

#define DFSDM_CHyCFGR1_SITP_RISE_EDGE 0
#define DFSDM_CHyCFGR1_SITP_FALL_EDGE 1
#define DFSDM_CHyCFGR1_SITP_MANCHESTER_01 2
#define DFSDM_CHyCFGR1_SITP_MANCHESTER_10 3

/****** DFSDM_CHyCFGR2 ******/
#define DFSDM_CHyCFGR2_ADDR(y) ((DFSDM_BASE+0x4)+(0x20*y))
#define DFSDM_CHyCFGR2(y) MMIO32(DFSDM_CHyCFGR2_ADDR(y))

#define DFSDM_CHyCFGR2_OFFSET_SHIFT 8
#define DFSDM_CHyCFGR2_OFFSET_MASK 0xFFFFFF

#define DFSDM_CHyCFGR2_DTRBS_SHIFT 3
#define DFSDM_CHyCFGR2_DTRBS_MASK 0x1F

/****** DFSDM_CHyDATINR ******/
#define DFSDM_CHyDATINR_ADDR(y) ((DFSDM_BASE+0x10)+(0x20*y))
#define DFSDM_CHyDATINR(y) MMIO32(DFSDM_CHyDATINR_ADDR(y))

/****** DFSDM Filters ******/
#define DFSDM_FLT_MAX 3
#define FILTER_SANITY_CHECK_RETURN(filter_instance) do { if(filter_instance > DFSDM_FLT_MAX) return; } while(0);
#define FILTER_SANITY_CHECK_RETURN0(filter_instance) do { if(filter_instance > DFSDM_FLT_MAX) return 0; } while(0);

#define DFSDM_FLTxCR1_ADDR(x) ((DFSDM_BASE+0x100)+(0x80*x))
#define DFSDM_FLTxCR1(x) MMIO32(DFSDM_FLTxCR1_ADDR(x))

#define DFSDM_FLTxCR1_AWFSEL_SHIFT 30
#define DFSDM_FLTxCR1_AWFSEL_MASK 0x1

#define DFSDM_FLTxCR1_FAST_SHIFT 29
#define DFSDM_FLTxCR1_FAST_MASK 0x1

#define DFSDM_FLTxCR1_RCH_SHIFT 24
#define DFSDM_FLTxCR1_RCH_MASK 0x7

#define DFSDM_FLTxCR1_RDMAEN_SHIFT 21
#define DFSDM_FLTxCR1_RDMAEN_MASK 0x1

#define DFSDM_FLTxCR1_RSYNC_SHIFT 19
#define DFSDM_FLTxCR1_RSYNC_MASK 0x1

#define DFSDM_FLTxCR1_RCONT_SHIFT 18
#define DFSDM_FLTxCR1_RCONT_MASK 0x1

#define DFSDM_FLTxCR1_RSWSTART_SHIFT 17
#define DFSDM_FLTxCR1_RSWSTART_MASK 0x1

#define DFSDM_FLTxCR1_JEXTEN_SHIFT 13
#define DFSDM_FLTxCR1_JEXTEN_MASK 0x3

#define DFSDM_FLTxCR1_JEXTSEL_SHIFT 8
#define DFSDM_FLTxCR1_JEXTSEL_MASK 0x7

#define DFSDM_FLTxCR1_JDMAEN_SHIFT 5
#define DFSDM_FLTxCR1_JDMAEN_MASK 0x1

#define DFSDM_FLTxCR1_JSCAN_SHIFT 4
#define DFSDM_FLTxCR1_JSCAN_MASK 0x1

#define DFSDM_FLTxCR1_JSYNC_SHIFT 3
#define DFSDM_FLTxCR1_JSYNC_MASK 0x1

#define DFSDM_FLTxCR1_JSWSTART_SHIFT 1
#define DFSDM_FLTxCR1_JSWSTART_MASK 0x1

#define DFSDM_FLTxCR1_DFEN_SHIFT 0
#define DFSDM_FLTxCR1_DFEN_MASK 0x1

/****** DFSDM_FLTxCR1 config bits ******/
#define DFSDM_FLTxCR1_AWFSEL_ON_DATA_OUT 0
#define DFSDM_FLTxCR1_AWFSEL_ON_CH_TRANSCEIVER 1

#define DFSDM_FLTxCR1_FAST_DISABLE 0
#define DFSDM_FLTxCR1_FAST_ENABLE 1

#define DFSDM_FLTxCR1_RDMAEN_DISABLE 0
#define DFSDM_FLTxCR1_RDMAEN_ENABLE 1

#define DFSDM_FLTxCR1_RSYNC_FLT0_DISABLE 0
#define DFSDM_FLTxCR1_RSYNC_FLT0_ENABLE 1

#define DFSDM_FLTxCR1_RCONT_ONCE 0
#define DFSDM_FLTxCR1_RCONT_REPEAT 1

#define DFSDM_FLTxCR1_RSWSTART 1

#define DFSDM_FLTxCR1_JEXTEN_TRIG_DET_DISABLE 0
#define DFSDM_FLTxCR1_JEXTEN_TRIG_RISE 1
#define DFSDM_FLTxCR1_JEXTEN_TRIG_FALL 2
#define DFSDM_FLTxCR1_JEXTEN_TRIG_BOTH 3

#define DFSDM_FLTxCR1_JDMAEN_DISABLE 0
#define DFSDM_FLTxCR1_JDMAEN_ENABLE 1

#define DFSDM_FLTxCR1_JSCAN_ONE 0
#define DFSDM_FLTxCR1_JSCAN_SERIES 1

#define DFSDM_FLTxCR1_JSYNC_FLT0_DISABLE 0
#define DFSDM_FLTxCR1_JSYNC_FLT0_ENABLE 1

#define DFSDM_FLTxCR1_JSWSTART 1

#define DFSDM_FLTxCR1_DFEN_DISABLE 0
#define DFSDM_FLTxCR1_DFEN_ENABLE 1

/****** DFSDM_FLTxCR2 ******/
#define DFSDM_FLTxCR2_ADDR(x) ((DFSDM_BASE+0x104)+(0x80*x))
#define DFSDM_FLTxCR2(x) MMIO32(DFSDM_FLTxCR2_ADDR(x))

#define DFSDM_FLTxCR2_AWDCH_SHIFT 16
#define DFSDM_FLTxCR2_AWDCH_MASK 0xFF

#define DFSDM_FLTxCR2_EXCH_SHIFT 8
#define DFSDM_FLTxCR2_EXCH_MASK 0xFF

#define DFSDM_FLTxCR2_CKABIE_SHIFT 6
#define DFSDM_FLTxCR2_CKABIE_MASK 0x1

#define DFSDM_FLTxCR2_SCDIE_SHIFT 5
#define DFSDM_FLTxCR2_SCDIE_MASK 0x1

#define DFSDM_FLTxCR2_AWDIE_SHIFT 4
#define DFSDM_FLTxCR2_AWDIE_MASK 0x1

#define DFSDM_FLTxCR2_ROVRIE_SHIFT 3
#define DFSDM_FLTxCR2_ROVRIE_MASK 0x1

#define DFSDM_FLTxCR2_JOVRIE_SHIFT 2
#define DFSDM_FLTxCR2_JOVRIE_MASK 0x1

#define DFSDM_FLTxCR2_REOCIE_SHIFT 1
#define DFSDM_FLTxCR2_REOCIE_MASK 0x1

#define DFSDM_FLTxCR2_JEOCIE_SHIFT 0
#define DFSDM_FLTxCR2_JEOCIE_MASK 0x1

/****** DFSDM_FLTxCR2 config bits ******/
#define DFSDM_FLTxCR2_CKABIE_DISABLE 0
#define DFSDM_FLTxCR2_CKABIE_ENABLE 1

#define DFSDM_FLTxCR2_SCDIE_DISABLE 0
#define DFSDM_FLTxCR2_SCDIE_ENABLE 1

#define DFSDM_FLTxCR2_AWDIE_DISABLE 0
#define DFSDM_FLTxCR2_AWDIE_ENABLE 1

#define DFSDM_FLTxCR2_ROVRIE_DISABLE 0
#define DFSDM_FLTxCR2_ROVRIE_ENABLE 1

#define DFSDM_FLTxCR2_JOVRIE_DISABLE 0
#define DFSDM_FLTxCR2_JOVRIE_ENABLE 1

#define DFSDM_FLTxCR2_REOCIE_DISABLE 0
#define DFSDM_FLTxCR2_REOCIE_ENABLE 1

#define DFSDM_FLTxCR2_JEOCIE_DISABLE 0
#define DFSDM_FLTxCR2_JEOCIE_ENABLE 1

/****** DFSDM_FLTxISR ******/
#define DFSDM_FLTxISR_ADDR(x) ((DFSDM_BASE+0x108)+(0x80*x))
#define DFSDM_FLTxISR(x) MMIO32(DFSDM_FLTxISR_ADDR(x))

#define DFSDM_FLTxISR_SCDF_SHIFT 24
#define DFSDM_FLTxISR_SCDF_MASK 0xFF

#define DFSDM_FLTxISR_CKABF_SHIFT 16
#define DFSDM_FLTxISR_CKABF_MASK 0xFF

#define DFSDM_FLTxISR_RCIP_SHIFT 14
#define DFSDM_FLTxISR_RCIP_MASK 0x1

#define DFSDM_FLTxISR_JCIP_SHIFT 13
#define DFSDM_FLTxISR_JCIP_MASK 0x1

#define DFSDM_FLTxISR_AWDF_SHIFT 4
#define DFSDM_FLTxISR_AWDF_MASK 0x1

#define DFSDM_FLTxISR_ROVRF_SHIFT 3
#define DFSDM_FLTxISR_ROVRF_MASK 0x1

#define DFSDM_FLTxISR_JOVRF_SHIFT 2
#define DFSDM_FLTxISR_JOVRF_MASK 0x1

#define DFSDM_FLTxISR_REOCF_SHIFT 1
#define DFSDM_FLTxISR_REOCF_MASK 0x1

#define DFSDM_FLTxISR_JEOCF_SHIFT 0
#define DFSDM_FLTxISR_JEOCF_MASK 0x1

/****** DFSDM_FLTxICR ******/
#define DFSDM_FLTxICR_ADDR(x) ((DFSDM_BASE+0x10C)+(0x80*x))
#define DFSDM_FLTxICR(x) MMIO32(DFSDM_FLTxICR_ADDR(x))

#define DFSDM_FLTxICR_CLRSCDF_SHIFT 24
#define DFSDM_FLTxICR_CLRSCDF_MASK 0xFF

#define DFSDM_FLTxICR_CLRCKABF_SHIFT 16
#define DFSDM_FLTxICR_CLRCKABF_MASK 0xFF

#define DFSDM_FLTxICR_CLRROVRF_SHIFT 3
#define DFSDM_FLTxICR_CLRROVRF_MASK 0x1

#define DFSDM_FLTxICR_CLRJOVRF_SHIFT 2
#define DFSDM_FLTxICR_CLRJOVRF_MASK 0x1

/****** DFSDM_FLTxJCHGR ******/
#define DFSDM_FLTxJCHGR_ADDR(x) ((DFSDM_BASE+0x110)+(0x80*x))
#define DFSDM_FLTxJCHGR(x) MMIO32(DFSDM_FLTxJCHGR_ADDR(x))

#define DFSDM_FLTxJCHGR_JCHG_SHIFT 0
#define DFSDM_FLTxJCHGR_JCHG_MASK 0xFF

/****** DFSDM_FLTxFCR ******/
#define DFSDM_FLTxFCR_ADDR(x) ((DFSDM_BASE+0x114)+(0x80*x))
#define DFSDM_FLTxFCR(x) MMIO32(DFSDM_FLTxFCR_ADDR(x))

#define DFSDM_FLTxFCR_FORD_SHIFT 29
#define DFSDM_FLTxFCR_FORD_MASK 0x7

#define DFSDM_FLTxFCR_FOSR_SHIFT 16
#define DFSDM_FLTxFCR_FOSR_MASK 0x3FF

#define DFSDM_FLTxFCR_IOSR_SHIFT 0
#define DFSDM_FLTxFCR_IOSR_MASK 0xFF

/****** DFSDM_FLTxRDATAR ******/
#define DFSDM_FLTxRDATAR_ADDR(x) ((DFSDM_BASE+0x11C)+(0x80*x))
#define DFSDM_FLTxRDATAR(x) MMIO32(DFSDM_FLTxRDATAR_ADDR(x))

#define DFSDM_FLTxRDATAR_RDATA_SHIFT 8
#define DFSDM_FLTxRDATAR_RDATA_MASK 0xFFFFFF

#define DFSDM_FLTxRDATAR_RPEND_SHIFT 4
#define DFSDM_FLTxRDATAR_RPEND_MASK 0x1

#define DFSDM_FLTxRDATAR_RDATACH_SHIFT 0
#define DFSDM_FLTxRDATAR_RDATACH_MASK 0x7

/* --- function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dfsdm_enable(int channel);
void dfsdm_disable(int channel);
void dfsdm_set_ckout_src_sys(int channel);
void dfsdm_set_ckout_src_audio(int channel);
void dfsdm_set_ckout_divider(int channel, uint8_t div);
void dfsdm_set_datpack_standard(int channel);
void dfsdm_set_datpack_interleaved(int channel);
void dfsdm_set_datpack_dual(int channel);
void dfsdm_set_datmpx_external(int channel);
void dfsdm_set_datmpx_adc(int channel);
void dfsdm_set_datmpx_cpu_dma(int channel);
void dfsdm_set_chinsel_same_channel(int channel);
void dfsdm_set_chinsel_following_channel(int channel);
void dfsdm_set_chen_enable(int channel);
void dfsdm_set_chen_disable(int channel);
void dfsdm_set_ckaben_enable(int channel);
void dfsdm_set_ckaben_disable(int channel);
void dfsdm_set_scden_enable(int channel);
void dfsdm_set_scden_disable(int channel);
void dfsdm_set_spi_clock_ckin(int channel);
void dfsdm_set_spi_clock_ckout(int channel);
void dfsdm_set_spi_clock_ckout_2fall_edge(int channel);
void dfsdm_set_spi_clock_ckout_2rise_edge(int channel);
void dfsdm_set_sitp_spi_rise_edge(int channel);
void dfsdm_set_sitp_spi_fall_edge(int channel);
void dfsdm_set_sitp_manchester_01(int channel);
void dfsdm_set_sitp_manchester_10(int channel);
void dfsdm_set_offset(int channel, uint32_t offset);
void dfsdm_set_data_shift(int channel, uint8_t shift);

void dfsdm_flt_awfsel_on_data_out(int filter_instance);
void dfsdm_flt_awfsel_on_ch_transceiver(int filter_instance);
void dfsdm_flt_fast_disable(int filter_instance);
void dfsdm_flt_fast_enable(int filter_instance);
void dfsdm_flt_set_regular_ch(int filter_instance, uint8_t channel);
void dfsdm_flt_rdma_disable(int filter_instance);
void dfsdm_flt_rdma_enable(int filter_instance);
void dfsdm_flt_rsync_disable(int filter_instance);
void dfsdm_flt_rsync_enable(int filter_instance);
void dfsdm_flt_rcont_once(int filter_instance);
void dfsdm_flt_rcont_repeat(int filter_instance);
void dfsdm_flt_rswstart(int filter_instance);
void dfsdm_flt_jexten_trig_disable(int filter_instance);
void dfsdm_flt_jexten_trig_rise(int filter_instance);
void dfsdm_flt_jexten_trig_fall(int filter_instance);
void dfsdm_flt_jexten_trig_both(int filter_instance);
void dfsdm_flt_jextsel(int filter_instance, uint8_t selection);
void dfsdm_flt_jdma_disable(int filter_instance);
void dfsdm_flt_jdma_enable(int filter_instance);
void dfsdm_flt_jscan_one(int filter_instance);
void dfsdm_flt_jscan_series(int filter_instance);
void dfsdm_flt_jsync_disable(int filter_instance);
void dfsdm_flt_jsync_enable(int filter_instance);
void dfsdm_flt_jswstart(int filter_instance);
void dfsdm_flt_filter_disable(int filter_instance);
void dfsdm_flt_filter_enable(int filter_instance);
void dfsdm_flt_awdch_clear(int filter_instance);
void dfsdm_flt_awdch_disable(int filter_instance, uint8_t channel);
void dfsdm_flt_awdch_enable(int filter_instance, uint8_t channel);
void dfsdm_flt_exch_clear(int filter_instance);
void dfsdm_flt_exch_disable(int filter_instance, uint8_t channel);
void dfsdm_flt_exch_enable(int filter_instance, uint8_t channel);
void dfsdm_flt_clock_absence_irq_disable(int filter_instance);
void dfsdm_flt_clock_absence_irq_enable(int filter_instance);
void dfsdm_flt_short_circuit_irq_disable(int filter_instance);
void dfsdm_flt_short_circuit_irq_enable(int filter_instance);
void dfsdm_flt_awd_irq_disable(int filter_instance);
void dfsdm_flt_awd_irq_enable(int filter_instance);
void dfsdm_flt_reg_data_overrun_irq_disable(int filter_instance);
void dfsdm_flt_reg_data_overrun_irq_enable(int filter_instance);
void dfsdm_flt_injected_data_overrun_irq_disable(int filter_instance);
void dfsdm_flt_injected_data_overrun_irq_enable(int filter_instance);
void dfsdm_flt_reg_end_of_conv_irq_disable(int filter_instance);
void dfsdm_flt_reg_end_of_conv_irq_enable(int filter_instance);
void dfsdm_flt_injected_end_of_conv_irq_disable(int filter_instance);
void dfsdm_flt_injected_end_of_conv_irq_enable(int filter_instance);
uint8_t dfsdm_flt_get_clock_absence_flag(int filter_instance, uint8_t channel);
uint8_t dfsdm_flt_get_regular_conv_progress_status(int filter_instance);
uint8_t dfsdm_flt_get_injected_conv_progress_status(int filter_instance);
uint8_t dfsdm_flt_get_awdf_status(int filter_instance);
uint8_t dfsdm_flt_get_regular_conv_overrun_flag(int filter_instance);
uint8_t dfsdm_flt_get_injected_conv_overrun_flag(int filter_instance);
uint8_t dfsdm_flt_get_eof_regular_conv_flag(int filter_instance);
uint8_t dfsdm_flt_get_eof_injected_conv_flag(int filter_instance);
void dfsdm_flt_injected_channel_group_clear(int filter_instance);
void dfsdm_flt_injected_channel_group_disable(int filter_instance, uint8_t channel);
void dfsdm_flt_injected_channel_group_enable(int filter_instance, uint8_t channel);
void dfsdm_flt_set_sinc_filter_order(int filter_instance, uint8_t order);
void dfsdm_flt_set_sinc_oversample_ratio(int filter_instance, uint16_t ratio);
void dfsdm_flt_set_integrator_oversample_ratio(int filter_instance, uint8_t ratio);
int32_t dfsdm_flt_calc_regular_ch_data(uint32_t data);
int32_t dfsdm_flt_get_regular_ch_conv_data(int filter_instance);
uint8_t dfsdm_flt_get_regular_ch_conv_pend_flag(int filter_instance);
uint8_t dfsdm_flt_get_regular_ch_most_recent(int filter_instance);

END_DECLS

#endif /* DFSDM_H */
