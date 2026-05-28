/** @defgroup dma_file DMA peripheral API
 * @ingroup peripheral_apis
 * @brief DMA library for the general purpose multi-stream controller found in the U5 series.
 *
 * @author @htmlonly &copy; @endhtmlonly 2025
 * Rachel Mant <git@dragonmux.network>
 *
 * This library supports the PDMA controller in the STM32U5
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * Up to two DMA controllers are supported each with 8 streams, and each stream
 * having up to 8 channels hardware dedicated to various peripheral DMA signals.
 *
 * DMA transfers can be configured to occur between peripheral and memory in
 * either direction, and memory to memory. Peripheral to peripheral transfer
 * is not supported. Circular mode transfers are also supported in transfers
 * involving a peripheral. An arbiter is provided to resolve priority DMA
 * requests. Transfers can be made with 8, 16 or 32 bit words.
 *
 * Each stream has access to a 4 word deep FIFO and can use double buffering
 * by means of two memory pointers. When using the FIFO it is possible to
 * configure transfers to occur in indivisible bursts.
 *
 * It is also possible to select a peripheral instead of the DMA controller to
 * control the flow of data. This limits the functionality but is useful when the
 * number of transfers is unknown.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

/**@{*/

#include <libopencm3/stm32/dma.h>

void dma_channel_reset(const uintptr_t dma, const uint8_t channel)
{
	/*
	 * Trigger a channel reset to get into a steady state and affect the following:
	 * Clear EN and SUSP bits in CxCR, FIFO state, and channel internal state.
	 * After this completes, CxBR1, CxSAR and CxDAR are invalidated and must be re-written
	 * to valid values before the channel can be re-enabled.
	 */
	DMA_CCR(dma, channel) = DMA_CxCR_RESET;
}

void dma_clear_interrupt_flags(const uintptr_t dma, const uint8_t channel, const uint32_t interrupts)
{
	DMA_CFCR(dma, channel) = interrupts;
}

bool dma_get_interrupt_flag(const uintptr_t dma, const uint8_t channel, const uint32_t interrupt)
{
	return (DMA_CSR(dma, channel) & interrupt) != 0U;
}

void dma_enable_interrupts(const uintptr_t dma, const uint8_t channel, const uint32_t interrupts)
{
	dma_clear_interrupt_flags(dma, channel, interrupts);
	DMA_CCR(dma, channel) |= interrupts;
}

void dma_disable_interrupts(const uintptr_t dma, const uint8_t channel, const uint32_t interrupts)
{
	DMA_CCR(dma, channel) &= ~interrupts;
}

void dma_set_priority(const uintptr_t dma, const uint8_t channel, const uint32_t prio)
{
	DMA_CCR(dma, channel) &= ~(DMA_CxCR_PRIO_MASK);
	DMA_CCR(dma, channel) |= prio;
}

void dma_set_source_width(const uintptr_t dma, const uint8_t channel, const uint8_t width)
{
	const uint32_t temp32 = DMA_CTR1(dma, channel) & ~DMA_CxTR1_SDW_MASK;
	DMA_CTR1(dma, channel) = temp32 | (width << DMA_CxTR1_SDW_SHIFT);
}

void dma_set_destination_width(const uintptr_t dma, const uint8_t channel, const uint8_t width)
{
	const uint32_t temp32 = DMA_CTR1(dma, channel) & ~DMA_CxTR1_DDW_MASK;
	DMA_CTR1(dma, channel) = temp32 | (width << DMA_CxTR1_DDW_SHIFT);
}

void dma_enable_source_increment_mode(const uintptr_t dma, const uint8_t channel)
{
	DMA_CTR1(dma, channel) |= DMA_CxTR1_SINC;
}

void dma_disable_source_increment_mode(const uintptr_t dma, const uint8_t channel)
{
	DMA_CTR1(dma, channel) &= ~DMA_CxTR1_SINC;
}

void dma_enable_destination_increment_mode(const uintptr_t dma, const uint8_t channel)
{
	DMA_CTR1(dma, channel) |= DMA_CxTR1_DINC;
}

void dma_disable_destination_increment_mode(const uintptr_t dma, const uint8_t channel)
{
	DMA_CTR1(dma, channel) &= ~DMA_CxTR1_DINC;
}

void dma_setup_linked_list(
	const uintptr_t dma, const uint8_t channel, const uintptr_t *const linked_list, const uint32_t flags)
{
	const uintptr_t ll_address = (uintptr_t)linked_list;
	/* Program CxLBAR with the upper 16 bits of the linked-list's address to get things ready */
	DMA_CLBAR(dma, channel) = ll_address & 0xffff0000U;
	/*
	 * Now program CxLLR with the lower 16 bits, ignoring the bottom most two as this must be
	 * a properly aligned pointer to the list (required is 4-byte alignment). Program the upper
	 * bits with the flags from the user to set up what the first entry in the list actually updates.
	 */
	DMA_CLLR(dma, channel) = (ll_address & 0x0000fffcU) | flags;
}

void dma_request_select(const uintptr_t dma, const uint8_t channel, const uint8_t request)
{
	const uint32_t temp32 = DMA_CTR2(dma, channel) & ~DMA_CxTR2_REQSEL_MASK;
	DMA_CTR2(dma, channel) = temp32 | (request << DMA_CxTR2_REQSEL_SHIFT);
}

void dma_trigger_select(const uintptr_t dma, const uint8_t channel, const uint8_t trigger)
{
	const uint32_t temp32 = DMA_CTR2(dma, channel) & ~DMA_CxTR2_TRIGSEL_MASK;
	DMA_CTR2(dma, channel) = temp32 | (trigger << DMA_CxTR2_TRIGSEL_SHIFT);
}

void dma_set_transfer_complete_mode(const uintptr_t dma, const uint8_t channel, const dma_transfer_complete_mode_e mode)
{
	const uint32_t temp32 = DMA_CTR2(dma, channel) & ~DMA_CxTR2_TCEM_MASK;
	DMA_CTR2(dma, channel) = temp32 | (mode << DMA_CxTR2_TCEM_SHIFT);
}

bool dma_set_source_burst(const uintptr_t dma, const uint8_t channel, const uint8_t burst)
{
	if (burst < 1U || burst > 64U) {
		return false;
	}
	const uint32_t temp32 = DMA_CTR1(dma, channel) & ~DMA_CxTR1_SBL_1_MASK;
	const uint8_t burst_length = burst - 1U;
	DMA_CTR1(dma, channel) = temp32 | (burst_length << DMA_CxTR1_SBL_1_SHIFT);
	return true;
}

bool dma_set_destination_burst(const uintptr_t dma, const uint8_t channel, const uint8_t burst)
{
	if (burst < 1U || burst > 64U) {
		return false;
	}
	const uint32_t temp32 = DMA_CTR1(dma, channel) & ~DMA_CxTR1_DBL_1_MASK;
	const uint8_t burst_length = burst - 1U;
	DMA_CTR1(dma, channel) = temp32 | (burst_length << DMA_CxTR1_DBL_1_SHIFT);
	return true;
}

void dma_set_source_stride(const uintptr_t dma, const uint8_t channel, const uint16_t stride)
{
	const uint32_t temp32 = DMA_CTR3(dma, channel) & ~DMA_CxTR3_SAO_MASK;
	DMA_CTR3(dma, channel) = temp32 | (stride << DMA_CxTR3_SAO_SHIFT);
}

void dma_set_destination_stride(const uintptr_t dma, const uint8_t channel, const uint16_t stride)
{
	const uint32_t temp32 = DMA_CTR3(dma, channel) & ~DMA_CxTR3_DAO_MASK;
	DMA_CTR3(dma, channel) = temp32 | (stride << DMA_CxTR3_DAO_SHIFT);
}

void dma_set_source_secure(uintptr_t dma, uint8_t channel, bool secure)
{
	if (secure) {
		DMA_CTR1(dma, channel) |= DMA_CxTR1_SSEC;
	} else {
		DMA_CTR1(dma, channel) &= ~DMA_CxTR1_SSEC;
	}
}

void dma_set_destination_secure(uintptr_t dma, uint8_t channel, bool secure)
{
	if (secure) {
		DMA_CTR1(dma, channel) |= DMA_CxTR1_DSEC;
	} else {
		DMA_CTR1(dma, channel) &= ~DMA_CxTR1_DSEC;
	}
}

void dma_set_source_byte_swap(uintptr_t dma, uint8_t channel, bool swap)
{
	if (swap) {
		DMA_CTR1(dma, channel) |= DMA_CxTR1_SBX;
	} else {
		DMA_CTR1(dma, channel) &= ~DMA_CxTR1_SBX;
	}
}

void dma_set_destination_swapping(uintptr_t dma, uint8_t channel, uint32_t swap_mode)
{
	const uint32_t temp32 = DMA_CTR1(dma, channel) & ~DMA_CxTR1_DEST_SWAP_MASK;
	DMA_CTR1(dma, channel) = temp32 | swap_mode;
}

bool dma_set_source_port(uintptr_t dma, uint8_t channel, uint8_t port)
{
	if (port > 1U) {
		return false;
	}

	if (port == 1U) {
		DMA_CTR1(dma, channel) |= DMA_CxTR1_SAP;
	} else {
		DMA_CTR1(dma, channel) &= ~DMA_CxTR1_SAP;
	}
	return true;
}

bool dma_set_destination_port(uintptr_t dma, uint8_t channel, uint8_t port)
{
	if (port > 1U) {
		return false;
	}

	if (port == 1U) {
		DMA_CTR1(dma, channel) |= DMA_CxTR1_DAP;
	} else {
		DMA_CTR1(dma, channel) &= ~DMA_CxTR1_DAP;
	}
	return true;
}

void dma_set_block_flow_control(uintptr_t dma, uint8_t channel)
{
	DMA_CTR2(dma, channel) |= DMA_CxTR2_BREQ;
}

void dma_set_burst_flow_control(uintptr_t dma, uint8_t channel)
{
	DMA_CTR2(dma, channel) &= ~DMA_CxTR2_BREQ;
}

void dma_set_source_flow_control(uintptr_t dma, uint8_t channel)
{
	DMA_CTR2(dma, channel) &= ~DMA_CxTR2_DREQ;
}

void dma_set_destination_flow_control(uintptr_t dma, uint8_t channel)
{
	DMA_CTR2(dma, channel) |= DMA_CxTR2_DREQ;
}

void dma_set_software_request(uintptr_t dma, uint8_t channel)
{
	DMA_CTR2(dma, channel) |= DMA_CxTR2_SWREQ;
}

void dma_set_hardware_request(uintptr_t dma, uint8_t channel)
{
	DMA_CTR2(dma, channel) &= ~DMA_CxTR2_SWREQ;
}

void dma_enable_channel(const uintptr_t dma, const uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CxCR_EN;
}

void dma_disable_channel(const uintptr_t dma, const uint8_t channel)
{
	/* First suspend the channel to break into its execution */
	DMA_CCR(dma, channel) |= DMA_CxCR_SUSP;
	while ((DMA_CSR(dma, channel) & DMA_CxSR_IDLEF) == 0)
		continue;
	/* Reset only resets channel internal state and clears the enable and suspend bits in this register. */
	DMA_CCR(dma, channel) |= DMA_CxCR_RESET;
}

void dma_set_source_address(const uintptr_t dma, const uint8_t channel, const uintptr_t address)
{
	DMA_CSAR(dma, channel) = address;
}

void dma_set_destination_address(const uintptr_t dma, const uint8_t channel, const uintptr_t address)
{
	DMA_CDAR(dma, channel) = address;
}

uint16_t dma_get_number_of_data(const uintptr_t dma, const uint8_t channel)
{
	return DMA_CBR1(dma, channel);
}

void dma_set_number_of_data(const uintptr_t dma, const uint8_t channel, const uint16_t number)
{
	DMA_CBR1(dma, channel) = number;
}
