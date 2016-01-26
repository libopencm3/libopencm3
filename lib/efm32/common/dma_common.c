/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/dma.h>

#define CHANNEL_SUPPORT_LOOP(ch) (((ch) == DMA_CH0) || ((ch) == DMA_CH1))

/**
 * Enable DMA with privileged access
 * @see dma_enable_with_unprivileged_access()
 */
void dma_enable_with_privileged_access(void)
{
	DMA_CONFIG = DMA_CONFIG_EN | DMA_CONFIG_CHPROT;
}

/**
 * Enable DMA with un-privileged access
 * @see dma_enable_with_privileged_access()
 */
void dma_enable_with_unprivileged_access(void)
{
	DMA_CONFIG = DMA_CONFIG_EN;
}

/**
 * same as @a dma_enable_with_unprivileged_access()
 * @see dma_enable_with_unprivileged_access()
 */
void dma_enable(void)
{
	dma_enable_with_unprivileged_access();
}

/**
 * Disable DMA
 */
void dma_disable(void)
{
	DMA_CONFIG = 0;
}

/**
 * Set channel's descriptor address
 * @param[in] desc_base Address of channel's descriptor address
 * @note @a desc_base 8LSB's should be 0x00
 */
void dma_set_desc_address(uint32_t desc_base)
{
	if (desc_base & 0xFF) {
		return;
	}

	DMA_CTRLBASE = desc_base;
}

/**
 * Get channel wait on request status flag
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool dma_get_wait_on_request_flag(enum dma_ch ch)
{
	uint32_t mask = DMA_CHWAITSTATUS_CHxWAITSTATUS(ch);
	return (DMA_CHWAITSTATUS & mask) != 0;
}

/**
 * Generate a software request on channel
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_generate_software_request(enum dma_ch ch)
{
	DMA_CHSWREQ = DMA_CHSWREQ_CHxSWREQ(ch);
}

/**
 * Enable channel burst only
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_burst_only(enum dma_ch ch)
{
	DMA_CHUSEBURSTS = DMA_CHUSEBURSTS_CHxSUSEBURSTS(ch);
}

/**
 * Enable channel single and burst
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_single_and_burst(enum dma_ch ch)
{
	DMA_CHUSEBURSTC = DMA_CHUSEBURSTC_CHxSUSEBURSTC(ch);
}

/**
 * Enable channel peripherial request
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_periph_request(enum dma_ch ch)
{
	DMA_CHREQMASKC = DMA_CHREQMASKC_CHxSREQMASKC(ch);
}

/**
 * Disable channel peripherial request
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_disable_periph_request(enum dma_ch ch)
{
	DMA_CHREQMASKS = DMA_CHREQMASKS_CHxSREQMASKS(ch);
}

/**
 * Enable channel
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_channel(enum dma_ch ch)
{
	DMA_CHENS = DMA_CHENS_CHxSENS(ch);
}

/**
 * Disable channel
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_disable_channel(enum dma_ch ch)
{
	DMA_CHENC = DMA_CHENC_CHxSENC(ch);
}

/**
 * Disable channel alternate structure
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_disable_alternate_structure(enum dma_ch ch)
{
	DMA_CHALTC = DMA_CHALTC_CHxSALTC(ch);
}

/**
 * Enable channel alternate structure
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_alternate_structure(enum dma_ch ch)
{
	DMA_CHALTS = DMA_CHALTS_CHxSALTS(ch);
}

/**
 * Enable channel high priority
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_priority(enum dma_ch ch)
{
	DMA_CHPRIS = DMA_CHPRIS_CHxSPRIC(ch);
}

/**
 * Disable channel high priority
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_disable_priority(enum dma_ch ch)
{
	DMA_CHPRIC = DMA_CHPRIC_CHxSPRIC(ch);
}

/**
 * Get bus error flag
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool dma_get_bus_error_flag(void)
{
	return (DMA_ERRORC & DMA_ERRORC_ERRORC) != 0;
}

/**
 * Clear bus error flag
 */
void dma_clear_bus_error_flag(void)
{
	DMA_ERRORC = DMA_ERRORC_ERRORC;
}

/**
 * Get channel request flag
 * @param[in] ch Channel (use DMA_CHx)
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool dma_get_request_flag(enum dma_ch ch)
{
	uint32_t mask = DMA_CHREQSTATUS_CHxSREQSTATUS(ch);
	return (DMA_CHREQSTATUS & mask) != 0;
}

/**
 * Get bus error interrupt flag
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool dma_get_bus_error_interrupt_flag(void)
{
	return (DMA_IF & DMA_IF_ERR) != 0;
}

/**
 * Get channel done interrupt flag
 * @param[in] ch Channel (use DMA_CHx)
 * @retval true if flag is set
 * @retval false if flag is not set
 *
 */
bool dma_get_done_interrupt_flag(enum dma_ch ch)
{
	return (DMA_IF & DMA_IF_CHxDONE(ch)) != 0;
}

/**
 * Set bus error interrupt flag
 */
void dma_set_bus_error_interrupt_flag(void)
{
	DMA_IFS = DMA_IFS_ERR;
}

/**
 * Set channel done interrupt flag
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_set_done_interrupt_flag(enum dma_ch ch)
{
	DMA_IFS = DMA_IFS_CHxDONE(ch);
}

/**
 * Clear bus error interrupt flag
 */
void dma_clear_bus_error_interrupt_flag(void)
{
	DMA_IFC = DMA_IFC_ERR;
}

/**
 * Clear channel done interrupt flag
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_clear_done_interrupt_flag(enum dma_ch ch)
{
	DMA_IFC = DMA_IFC_CHxDONE(ch);
}

/**
 * Enable bus error interrupt
 */
void dma_enable_bus_error_interrupt(void)
{
	DMA_IEN |= DMA_IEN_ERR;
}

/**
 * Disable bus error interrupt
 */
void dma_disable_bus_error_interrupt(void)
{
	DMA_IEN &= ~DMA_IEN_ERR;
}

/**
 * Enable channel done interrupt
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_done_interrupt(enum dma_ch ch)
{
	DMA_IEN |= DMA_IEN_CHxDONE(ch);
}

/**
 * Disable channel done interrupt
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_disable_done_interrupt(enum dma_ch ch)
{
	DMA_IEN &= ~DMA_IEN_CHxDONE(ch);
}

/**
 * Set channel source
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] source Source (use DMA_CH_CTRL_SOURCESEL_*)
 */
void dma_set_source(enum dma_ch ch, uint32_t source)
{
	DMA_CHx_CTRL(ch) = (DMA_CHx_CTRL(ch) & ~DMA_CH_CTRL_SOURCESEL_MASK)
			    | source;
}

/**
 * Set channel source signal
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] signal Signal (use DMA_CH_CTRL_SIGSEL_*)
 */
void dma_set_signal(enum dma_ch ch, uint32_t signal)
{
	DMA_CHx_CTRL(ch) = (DMA_CHx_CTRL(ch) & ~DMA_CH_CTRL_SIGSEL_MASK)
			    | signal;
}

/**
 * Reset channel
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_channel_reset(enum dma_ch ch)
{
	/* Disable channel */
	DMA_CHENC = DMA_CHENC_CHxSENC(ch);
	/* reset channel alternate desc */
	DMA_CHALTC = DMA_CHALTC_CHxSALTC(ch);
	/* reset channel priority */
	DMA_CHPRIC = DMA_CHPRIC_CHxSPRIC(ch);
	/* clear channel interrupt */
	DMA_IFC = DMA_IFC_CHxDONE(ch);
	/* disable loop */
	if (CHANNEL_SUPPORT_LOOP(ch)) {
		DMA_LOOPx(ch) = 0;
	}
	/* reset signal {source, select} */
	DMA_CHx_CTRL(ch) = 0;
}

/**
 * Set channel loop width to ( @a count + 1)
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] count Count
 * @note @a count is expected to be equal to (n_minus_1 + 1)
 */
void dma_set_loop_count(enum dma_ch ch, uint16_t count)
{
	if (!CHANNEL_SUPPORT_LOOP(ch)) {
		return;
	}

	DMA_LOOPx(ch) = (DMA_LOOPx(ch) & ~DMA_LOOP_WIDTH_MASK)
			| DMA_LOOP_WIDTH(count - 1);
}

/**
 * Enable channel loop
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_enable_loop(enum dma_ch ch)
{
	if (!CHANNEL_SUPPORT_LOOP(ch)) {
		return;
	}

	DMA_LOOPx(ch) |= DMA_LOOP_EN;
}

/**
 * Disable channel loop
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_disable_loop(enum dma_ch ch)
{
	if (!CHANNEL_SUPPORT_LOOP(ch)) {
		return;
	}

	DMA_LOOPx(ch) &= ~DMA_LOOP_EN;
}

/**
 * Set desination size
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] size Size (use DMA_MEM_*)
 */
void dma_desc_set_dest_size(uint32_t desc_base, enum dma_ch ch,
			    enum dma_mem size)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_DEST_SIZE_MASK;
	cfg |= DMA_DESC_CH_CFG_DEST_SIZE(size);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}

/**
 * Set destination increment
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] inc Increment (use DMA_MEM_*)
 */
void dma_desc_set_dest_inc(uint32_t desc_base, enum dma_ch ch,
			   enum dma_mem inc)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_DEST_INC_MASK;
	cfg |= DMA_DESC_CH_CFG_DEST_INC(inc);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}

/**
 * Set source size
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] size Size (use DMA_MEM_*)
 */
void dma_desc_set_src_size(uint32_t desc_base, enum dma_ch ch,
			   enum dma_mem size)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_SRC_SIZE_MASK;
	cfg |= DMA_DESC_CH_CFG_SRC_SIZE(size);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}

/**
 * Set source increment
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] inc Increment (use DMA_MEM_*)
 */
void dma_desc_set_src_inc(uint32_t desc_base, enum dma_ch ch, enum dma_mem inc)
{

	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_SRC_INC_MASK;
	cfg |= DMA_DESC_CH_CFG_SRC_INC(inc);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}

/**
 * Set R Power
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] r_power R Power (Use DMA_R_POWER_*)
 */
void dma_desc_set_r_power(uint32_t desc_base, enum dma_ch ch,
			  enum dma_r_power r_power)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_R_POWER_MASK;
	cfg |= DMA_DESC_CH_CFG_R_POWER(r_power);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}

/**
 * Enable next useburst
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_desc_enable_next_useburst(uint32_t desc_base, enum dma_ch ch)
{
	DMA_DESC_CHx_CFG(desc_base, ch) &= ~DMA_DESC_CH_CFG_NEXT_USEBURST;
}

/**
 * Disable next useburst
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 */
void dma_desc_disable_next_useburst(uint32_t desc_base, enum dma_ch ch)
{
	DMA_DESC_CHx_CFG(desc_base, ch) |= DMA_DESC_CH_CFG_NEXT_USEBURST;
}

/**
 * Set number (count) of transfer to be performed
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] count Count
 */
void dma_desc_set_count(uint32_t desc_base, enum dma_ch ch, uint16_t count)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_N_MINUS_1_MASK;
	cfg |= DMA_DESC_CH_CFG_N_MINUS_1(count - 1);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}

/**
 * Store user data field in channel descriptor
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] user_data User data
 */
void dma_desc_set_user_data(uint32_t desc_base, enum dma_ch ch,
			    uint32_t user_data)
{
	DMA_DESC_CHx_USER_DATA(desc_base, ch) = user_data;
}

/**
 * Extract user data field from channel descriptor
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @return user data
 */
uint32_t dma_desc_get_user_data(uint32_t desc_base, enum dma_ch ch)
{
	return DMA_DESC_CHx_USER_DATA(desc_base, ch);
}

/**
 * Calculate end from start address.
 *
 * @details
 * See "8.4.3.4 Address calculation" p68, EFM32LG-RM "d0183_Rev1.10"
 *
 * @param[in] start address to start of memory
 * @param[in] inc Increment (use DMA_MEM_*)
 * @param[in] n_minus_1 the number of transfers minus 1  (ie count - 1)
 * @return the calculate end address
 * @note can be used to calculate {source, destination} end address
 */
static inline uint32_t dma_calc_end_from_start(uint32_t start, uint8_t inc,
					uint16_t n_minus_1)
{
	switch (inc) {
	case DMA_MEM_BYTE:
		return start + n_minus_1;
	case DMA_MEM_HALF_WORD:
		return start + (n_minus_1 << 1);
	case DMA_MEM_WORD:
		return start + (n_minus_1 << 2);
	case DMA_MEM_NONE:
		return start;
	}

	return 0;
}

/**
 * Assign Source address to DMA Channel
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] src_start Source data start address
 * @param[in] this function use dma_desc_set_count() and dma_desc_set_src_inc()
 *            set value to calculate the src data end address from @a src_start
 * @note dma_desc_set_count() should be called first.
 * @note dma_desc_set_src_inc() should be called first.
 */
void dma_desc_set_src_address(uint32_t desc_base, enum dma_ch ch,
			      uint32_t src_start)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	uint8_t inc = (cfg & DMA_DESC_CH_CFG_SRC_INC_MASK)
		      >> DMA_DESC_CH_CFG_SRC_INC_SHIFT;
	uint16_t n_minus_1 = (cfg & DMA_DESC_CH_CFG_N_MINUS_1_MASK)
			     >> DMA_DESC_CH_CFG_N_MINUS_1_SHIFT;
	uint32_t src_end = dma_calc_end_from_start(src_start, inc, n_minus_1);
	DMA_DESC_CHx_SRC_DATA_END_PTR(desc_base, ch) = src_end;
}

/**
 * Assign Destination address to DMA Channel
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] dest_start Destination data start address
 * @param[in] this function use dma_desc_set_count() and
 *            dma_desc_set_dest_inc() set value to calculate the dest data end
 *            address from @a dest_start
 * @note dma_desc_set_count() should be called first.
 * @note dma_desc_set_dest_inc() should be called first.
 */
void dma_desc_set_dest_address(uint32_t desc_base, enum dma_ch ch,
			       uint32_t dest_start)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	uint8_t inc = (cfg & DMA_DESC_CH_CFG_DEST_INC_MASK)
		      >> DMA_DESC_CH_CFG_DEST_INC_SHIFT;
	uint16_t n_minus_1 = (cfg & DMA_DESC_CH_CFG_N_MINUS_1_MASK)
			     >> DMA_DESC_CH_CFG_N_MINUS_1_SHIFT;
	uint32_t dest_end = dma_calc_end_from_start(dest_start, inc,
						    n_minus_1);
	DMA_DESC_CHx_DEST_DATA_END_PTR(desc_base, ch) = dest_end;
}

/**
 * Set the channel mode ("Cycle control")
 * @param[in] desc_base start of memory location that contain channel
 *            descriptor
 * @param[in] ch Channel (use DMA_CHx)
 * @param[in] mode Mode (use DMA_MODE_*)
 */
void dma_desc_set_mode(uint32_t desc_base, enum dma_ch ch, enum dma_mode mode)
{
	uint32_t cfg = DMA_DESC_CHx_CFG(desc_base, ch);
	cfg &= ~DMA_DESC_CH_CFG_CYCLE_CTRL_MASK;
	cfg |= DMA_DESC_CH_CFG_CYCLE_CTRL(mode);
	DMA_DESC_CHx_CFG(desc_base, ch) = cfg;
}
