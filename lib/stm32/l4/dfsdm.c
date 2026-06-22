#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/l4/memorymap.h>

#include <libopencm3/stm32/l4/dfsdm.h>

void dfsdm_enable(int channel)
{
    /* the global enable bit is only available in channel 0 */
    if(channel != 0) return;

    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_DFSDM_EN_ENABLE<<DFSDM_CHyCFGR1_DFSDM_EN_SHIFT);
}

void dfsdm_disable(int channel)
{
    /* the global enable bit is only available in channel 0 */
    if(channel != 0) return;

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DFSDM_EN_MASK<<DFSDM_CHyCFGR1_DFSDM_EN_SHIFT);
}

void dfsdm_set_ckout_src_sys(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_CKOUTSRC_MASK<<DFSDM_CHyCFGR1_CKOUTSRC_SHIFT);
}

void dfsdm_set_ckout_src_audio(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_CKOUTSRC_AUDIO<<DFSDM_CHyCFGR1_CKOUTSRC_SHIFT);
}

void dfsdm_set_ckout_divider(int channel, uint8_t div)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    /* first clear everything */
    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_CKOUTDIV_MASK<<DFSDM_CHyCFGR1_CKOUTDIV_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (div<<DFSDM_CHyCFGR1_CKOUTDIV_SHIFT);
}

void dfsdm_set_datpack_standard(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DATPACK_MASK<<DFSDM_CHyCFGR1_DATPACK_SHIFT);
}

void dfsdm_set_datpack_interleaved(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DATPACK_MASK<<DFSDM_CHyCFGR1_DATPACK_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_DATPACK_INTERLEAVED<<DFSDM_CHyCFGR1_DATPACK_SHIFT);
}

void dfsdm_set_datpack_dual(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DATPACK_MASK<<DFSDM_CHyCFGR1_DATPACK_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_DATPACK_DUAL<<DFSDM_CHyCFGR1_DATPACK_SHIFT);
}

void dfsdm_set_datmpx_external(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DATMPX_MASK<<DFSDM_CHyCFGR1_DATMPX_SHIFT);
}

void dfsdm_set_datmpx_adc(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DATMPX_MASK<<DFSDM_CHyCFGR1_DATMPX_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_DATMPX_ADC<<DFSDM_CHyCFGR1_DATMPX_SHIFT);
}

void dfsdm_set_datmpx_cpu_dma(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_DATMPX_MASK<<DFSDM_CHyCFGR1_DATMPX_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_DATMPX_CPU_DMA<<DFSDM_CHyCFGR1_DATMPX_SHIFT);
}

void dfsdm_set_chinsel_same_channel(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_CHINSEL_MASK<<DFSDM_CHyCFGR1_CHINSEL_SHIFT);
}

void dfsdm_set_chinsel_following_channel(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_CHINSEL_FOLLOWING<<DFSDM_CHyCFGR1_CHINSEL_SHIFT);
}

void dfsdm_set_chen_enable(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_CHEN_ENABLE<<DFSDM_CHyCFGR1_CHEN_SHIFT);
}

void dfsdm_set_chen_disable(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_CHEN_MASK<<DFSDM_CHyCFGR1_CHEN_SHIFT);
}

void dfsdm_set_ckaben_enable(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_CKABEN_ENABLE<<DFSDM_CHyCFGR1_CKABEN_SHIFT);
}

void dfsdm_set_ckaben_disable(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_CKABEN_MASK<<DFSDM_CHyCFGR1_CKABEN_SHIFT);
}

void dfsdm_set_scden_enable(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SCDEN_ENABLE<<DFSDM_CHyCFGR1_SCDEN_SHIFT);
}

void dfsdm_set_scden_disable(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SCDEN_MASK<<DFSDM_CHyCFGR1_SCDEN_SHIFT);
}

void dfsdm_set_spi_clock_ckin(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SPICKSEL_MASK<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
}

void dfsdm_set_spi_clock_ckout(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SPICKSEL_MASK<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SPICKSEL_CKOUT_SITP<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
}

void dfsdm_set_spi_clock_ckout_2fall_edge(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SPICKSEL_MASK<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SPICKSEL_CKOUT_2FALL_EDGE<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
}

void dfsdm_set_spi_clock_ckout_2rise_edge(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SPICKSEL_MASK<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SPICKSEL_CKOUT_2RISE_EDGE<<DFSDM_CHyCFGR1_SPICKSEL_SHIFT);
}

void dfsdm_set_sitp_spi_rise_edge(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SITP_MASK<<DFSDM_CHyCFGR1_SITP_SHIFT);
}

void dfsdm_set_sitp_spi_fall_edge(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SITP_MASK<<DFSDM_CHyCFGR1_SITP_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SITP_FALL_EDGE<<DFSDM_CHyCFGR1_SITP_SHIFT);
}

void dfsdm_set_sitp_manchester_01(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SITP_MASK<<DFSDM_CHyCFGR1_SITP_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SITP_MANCHESTER_01<<DFSDM_CHyCFGR1_SITP_SHIFT);
}

void dfsdm_set_sitp_manchester_10(int channel)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR1(channel) &= ~(DFSDM_CHyCFGR1_SITP_MASK<<DFSDM_CHyCFGR1_SITP_SHIFT);
    DFSDM_CHyCFGR1(channel) |= (DFSDM_CHyCFGR1_SITP_MANCHESTER_10<<DFSDM_CHyCFGR1_SITP_SHIFT);
}

void dfsdm_set_offset(int channel, uint32_t offset)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR2(channel) &= ~(DFSDM_CHyCFGR2_OFFSET_MASK<<DFSDM_CHyCFGR2_OFFSET_SHIFT);
    DFSDM_CHyCFGR2(channel) |= ((offset&DFSDM_CHyCFGR2_OFFSET_MASK)<<DFSDM_CHyCFGR2_OFFSET_SHIFT);
}

void dfsdm_set_data_shift(int channel, uint8_t shift)
{
    CHANNEL_SANITY_CHECK_RETURN(channel);

    DFSDM_CHyCFGR2(channel) &= ~(DFSDM_CHyCFGR2_DTRBS_MASK<<DFSDM_CHyCFGR2_DTRBS_SHIFT);
    DFSDM_CHyCFGR2(channel) |= ((shift&DFSDM_CHyCFGR2_DTRBS_MASK)<<DFSDM_CHyCFGR2_DTRBS_SHIFT);
}

void dfsdm_flt_awfsel_on_data_out(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_AWFSEL_MASK<<DFSDM_FLTxCR1_AWFSEL_SHIFT);
}

void dfsdm_flt_awfsel_on_ch_transceiver(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_AWFSEL_MASK<<DFSDM_FLTxCR1_AWFSEL_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_AWFSEL_ON_CH_TRANSCEIVER<<DFSDM_FLTxCR1_AWFSEL_SHIFT);
}

void dfsdm_flt_fast_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_FAST_MASK<<DFSDM_FLTxCR1_FAST_SHIFT);
}

void dfsdm_flt_fast_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_FAST_MASK<<DFSDM_FLTxCR1_FAST_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_FAST_ENABLE<<DFSDM_FLTxCR1_FAST_SHIFT);
}

void dfsdm_flt_set_regular_ch(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RCH_MASK<<DFSDM_FLTxCR1_RCH_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= ((channel&DFSDM_FLTxCR1_RCH_MASK)<<DFSDM_FLTxCR1_RCH_SHIFT);
}

void dfsdm_flt_rdma_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RDMAEN_MASK<<DFSDM_FLTxCR1_RDMAEN_SHIFT);
}

void dfsdm_flt_rdma_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RDMAEN_MASK<<DFSDM_FLTxCR1_RDMAEN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_RDMAEN_ENABLE<<DFSDM_FLTxCR1_RDMAEN_SHIFT);
}

void dfsdm_flt_rsync_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RSYNC_MASK<<DFSDM_FLTxCR1_RSYNC_SHIFT);
}

void dfsdm_flt_rsync_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RSYNC_MASK<<DFSDM_FLTxCR1_RSYNC_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_RSYNC_FLT0_ENABLE<<DFSDM_FLTxCR1_RSYNC_SHIFT);
}

void dfsdm_flt_rcont_once(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RCONT_MASK<<DFSDM_FLTxCR1_RCONT_SHIFT);
}

void dfsdm_flt_rcont_repeat(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_RCONT_MASK<<DFSDM_FLTxCR1_RCONT_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_RCONT_REPEAT<<DFSDM_FLTxCR1_RCONT_SHIFT);
}

void dfsdm_flt_rswstart(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_RSWSTART<<DFSDM_FLTxCR1_RSWSTART_SHIFT);
}

void dfsdm_flt_jexten_trig_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JEXTEN_MASK<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
}

void dfsdm_flt_jexten_trig_rise(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JEXTEN_MASK<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JEXTEN_TRIG_RISE<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
}

void dfsdm_flt_jexten_trig_fall(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JEXTEN_MASK<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JEXTEN_TRIG_FALL<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
}

void dfsdm_flt_jexten_trig_both(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JEXTEN_MASK<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JEXTEN_TRIG_BOTH<<DFSDM_FLTxCR1_JEXTEN_SHIFT);
}

void dfsdm_flt_jextsel(int filter_instance, uint8_t selection)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JEXTSEL_MASK<<DFSDM_FLTxCR1_JEXTSEL_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= ((selection&DFSDM_FLTxCR1_JEXTSEL_MASK)<<DFSDM_FLTxCR1_JEXTSEL_SHIFT);
}

void dfsdm_flt_jdma_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JDMAEN_MASK<<DFSDM_FLTxCR1_JDMAEN_SHIFT);
}

void dfsdm_flt_jdma_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JDMAEN_MASK<<DFSDM_FLTxCR1_JDMAEN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JDMAEN_ENABLE<<DFSDM_FLTxCR1_JDMAEN_SHIFT);
}

void dfsdm_flt_jscan_one(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JSCAN_MASK<<DFSDM_FLTxCR1_JSCAN_SHIFT);
}

void dfsdm_flt_jscan_series(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JSCAN_MASK<<DFSDM_FLTxCR1_JSCAN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JSCAN_SERIES<<DFSDM_FLTxCR1_JSCAN_SHIFT);
}

void dfsdm_flt_jsync_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JSYNC_MASK<<DFSDM_FLTxCR1_JSYNC_SHIFT);
}

void dfsdm_flt_jsync_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_JSYNC_MASK<<DFSDM_FLTxCR1_JSYNC_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JSYNC_FLT0_ENABLE<<DFSDM_FLTxCR1_JSYNC_SHIFT);
}

void dfsdm_flt_jswstart(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_JSWSTART<<DFSDM_FLTxCR1_JSWSTART_SHIFT);
}

void dfsdm_flt_filter_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_DFEN_MASK<<DFSDM_FLTxCR1_DFEN_SHIFT);
}

void dfsdm_flt_filter_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR1(filter_instance) &= ~(DFSDM_FLTxCR1_DFEN_MASK<<DFSDM_FLTxCR1_DFEN_SHIFT);
    DFSDM_FLTxCR1(filter_instance) |= (DFSDM_FLTxCR1_DFEN_ENABLE<<DFSDM_FLTxCR1_DFEN_SHIFT);
}

void dfsdm_flt_awdch_clear(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_AWDCH_MASK<<DFSDM_FLTxCR2_AWDCH_SHIFT);
}

void dfsdm_flt_awdch_disable(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    if(channel > 7)
        return;

    DFSDM_FLTxCR2(filter_instance) &= ~(1<<(DFSDM_FLTxCR2_AWDCH_SHIFT+channel));
}

void dfsdm_flt_awdch_enable(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    if(channel > 7)
        return;

    DFSDM_FLTxCR2(filter_instance) |= (1<<(DFSDM_FLTxCR2_AWDCH_SHIFT+channel));
}

void dfsdm_flt_exch_clear(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_EXCH_MASK<<DFSDM_FLTxCR2_EXCH_SHIFT);
}

void dfsdm_flt_exch_disable(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    if(channel > 7)
        return;

    DFSDM_FLTxCR2(filter_instance) &= ~(1<<(DFSDM_FLTxCR2_EXCH_SHIFT+channel));
}

void dfsdm_flt_exch_enable(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    if(channel > 7)
        return;

    DFSDM_FLTxCR2(filter_instance) |= (1<<(DFSDM_FLTxCR2_EXCH_SHIFT+channel));
}

void dfsdm_flt_clock_absence_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_CKABIE_MASK<<DFSDM_FLTxCR2_CKABIE_SHIFT);
}

void dfsdm_flt_clock_absence_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_CKABIE_MASK<<DFSDM_FLTxCR2_CKABIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_CKABIE_ENABLE<<DFSDM_FLTxCR2_CKABIE_SHIFT);
}

void dfsdm_flt_short_circuit_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_SCDIE_MASK<<DFSDM_FLTxCR2_SCDIE_SHIFT);
}

void dfsdm_flt_short_circuit_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_SCDIE_MASK<<DFSDM_FLTxCR2_SCDIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_SCDIE_ENABLE<<DFSDM_FLTxCR2_SCDIE_SHIFT);
}

void dfsdm_flt_awd_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_AWDIE_MASK<<DFSDM_FLTxCR2_AWDIE_SHIFT);
}

void dfsdm_flt_awd_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_AWDIE_MASK<<DFSDM_FLTxCR2_AWDIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_AWDIE_ENABLE<<DFSDM_FLTxCR2_AWDIE_SHIFT);
}

void dfsdm_flt_reg_data_overrun_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_ROVRIE_MASK<<DFSDM_FLTxCR2_ROVRIE_SHIFT);
}

void dfsdm_flt_reg_data_overrun_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_ROVRIE_MASK<<DFSDM_FLTxCR2_ROVRIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_ROVRIE_ENABLE<<DFSDM_FLTxCR2_ROVRIE_SHIFT);
}

void dfsdm_flt_injected_data_overrun_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_JOVRIE_MASK<<DFSDM_FLTxCR2_JOVRIE_SHIFT);
}

void dfsdm_flt_injected_data_overrun_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_JOVRIE_MASK<<DFSDM_FLTxCR2_JOVRIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_JOVRIE_ENABLE<<DFSDM_FLTxCR2_JOVRIE_SHIFT);
}

void dfsdm_flt_reg_end_of_conv_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_REOCIE_MASK<<DFSDM_FLTxCR2_REOCIE_SHIFT);
}

void dfsdm_flt_reg_end_of_conv_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_REOCIE_MASK<<DFSDM_FLTxCR2_REOCIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_REOCIE_ENABLE<<DFSDM_FLTxCR2_REOCIE_SHIFT);
}

void dfsdm_flt_injected_end_of_conv_irq_disable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_JEOCIE_MASK<<DFSDM_FLTxCR2_JEOCIE_SHIFT);
}

void dfsdm_flt_injected_end_of_conv_irq_enable(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxCR2(filter_instance) &= ~(DFSDM_FLTxCR2_JEOCIE_MASK<<DFSDM_FLTxCR2_JEOCIE_SHIFT);
    DFSDM_FLTxCR2(filter_instance) |= (DFSDM_FLTxCR2_JEOCIE_ENABLE<<DFSDM_FLTxCR2_JEOCIE_SHIFT);
}

uint8_t dfsdm_flt_get_clock_absence_flag(int filter_instance, uint8_t channel)
{
    /* this is only present in DFSDM_FLT0ISR */
    if(filter_instance != 0)
        return 0;

    if(channel > 7)
        return 0;

    return (DFSDM_FLTxISR(filter_instance) & (1<<(DFSDM_FLTxISR_CKABF_SHIFT+channel))) ? 1 : 0;
}

uint8_t dfsdm_flt_get_regular_conv_progress_status(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_RCIP_MASK << DFSDM_FLTxISR_RCIP_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_injected_conv_progress_status(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_JCIP_MASK << DFSDM_FLTxISR_JCIP_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_awdf_status(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_AWDF_MASK << DFSDM_FLTxISR_AWDF_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_regular_conv_overrun_flag(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_ROVRF_MASK << DFSDM_FLTxISR_ROVRF_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_injected_conv_overrun_flag(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_JOVRF_MASK << DFSDM_FLTxISR_JOVRF_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_eof_regular_conv_flag(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_REOCF_MASK << DFSDM_FLTxISR_REOCF_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_eof_injected_conv_flag(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxISR(filter_instance) & (DFSDM_FLTxISR_JEOCF_MASK << DFSDM_FLTxISR_JEOCF_SHIFT)) ? 1 : 0;
}

void dfsdm_flt_injected_channel_group_clear(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxJCHGR(filter_instance) &= ~(DFSDM_FLTxJCHGR_JCHG_MASK<<DFSDM_FLTxJCHGR_JCHG_SHIFT);
}

void dfsdm_flt_injected_channel_group_disable(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    if(channel > 7)
        return;

    DFSDM_FLTxJCHGR(filter_instance) &= ~(1<<(DFSDM_FLTxJCHGR_JCHG_SHIFT+channel));
}

void dfsdm_flt_injected_channel_group_enable(int filter_instance, uint8_t channel)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    if(channel > 7)
        return;

    DFSDM_FLTxJCHGR(filter_instance) |= (1<<(DFSDM_FLTxJCHGR_JCHG_SHIFT+channel));
}

void dfsdm_flt_set_sinc_filter_order(int filter_instance, uint8_t order)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxFCR(filter_instance) &= ~(DFSDM_FLTxFCR_FORD_MASK<<DFSDM_FLTxFCR_FORD_SHIFT);
    DFSDM_FLTxFCR(filter_instance) |= ((order&DFSDM_FLTxFCR_FORD_MASK)<<DFSDM_FLTxFCR_FORD_SHIFT);
}

void dfsdm_flt_set_sinc_oversample_ratio(int filter_instance, uint16_t ratio)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxFCR(filter_instance) &= ~(DFSDM_FLTxFCR_FOSR_MASK<<DFSDM_FLTxFCR_FOSR_SHIFT);
    DFSDM_FLTxFCR(filter_instance) |= ((ratio&DFSDM_FLTxFCR_FOSR_MASK)<<DFSDM_FLTxFCR_FOSR_SHIFT);
}

void dfsdm_flt_set_integrator_oversample_ratio(int filter_instance, uint8_t ratio)
{
    FILTER_SANITY_CHECK_RETURN(filter_instance);

    DFSDM_FLTxFCR(filter_instance) &= ~(DFSDM_FLTxFCR_IOSR_MASK<<DFSDM_FLTxFCR_IOSR_SHIFT);
    DFSDM_FLTxFCR(filter_instance) |= ((ratio&DFSDM_FLTxFCR_IOSR_MASK)<<DFSDM_FLTxFCR_IOSR_SHIFT);
}

int32_t dfsdm_flt_calc_regular_ch_data(uint32_t data)
{
    int32_t signed_tmp_data = (int32_t)data;
    return (signed_tmp_data>>DFSDM_FLTxRDATAR_RDATA_SHIFT);
}

int32_t dfsdm_flt_get_regular_ch_conv_data(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    uint32_t tmp_data = (DFSDM_FLTxRDATAR(filter_instance) & (DFSDM_FLTxRDATAR_RDATA_MASK << DFSDM_FLTxRDATAR_RDATA_SHIFT));
    return dfsdm_flt_calc_regular_ch_data(tmp_data);
}

uint8_t dfsdm_flt_get_regular_ch_conv_pend_flag(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxRDATAR(filter_instance) & (DFSDM_FLTxRDATAR_RPEND_MASK << DFSDM_FLTxRDATAR_RPEND_SHIFT)) ? 1 : 0;
}

uint8_t dfsdm_flt_get_regular_ch_most_recent(int filter_instance)
{
    FILTER_SANITY_CHECK_RETURN0(filter_instance);

    return (DFSDM_FLTxRDATAR(filter_instance) & (DFSDM_FLTxRDATAR_RDATACH_MASK << DFSDM_FLTxRDATAR_RDATACH_SHIFT)) ? 1 : 0;
}
