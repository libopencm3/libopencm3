/** @defgroup dma_file DMA peripheral API
@ingroup peripheral_apis
@brief DMA library for the multi channel controller found in F0/1/3 & L/G parts.

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

This library supports the DMA Control System in the STM32 series of ARM Cortex
Microcontrollers by ST Microelectronics.

Up to two DMA controllers are supported. 12 DMA channels are allocated 7 to
the first DMA controller and 5 to the second. Each channel is connected to
between 3 and 6 hardware peripheral DMA signals in a logical OR arrangement.

DMA transfers can be configured to occur between peripheral and memory in
any combination including memory to memory. Circular mode transfers are
also supported in transfers involving a peripheral. An arbiter is provided
to resolve priority DMA requests. Transfers can be made with 8, 16 or 32 bit
words.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Reset

The channel is disabled and configuration registers are cleared.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_channel_reset(uint32_t dma, uint8_t channel)
{
	/* Disable channel and reset config bits. */
	DMA_CCR(dma, channel) = 0;
	/* Reset data transfer number. */
	DMA_CNDTR(dma, channel) = 0;
	/* Reset peripheral address. */
	DMA_CPAR(dma, channel) = 0;
	/* Reset memory address. */
	DMA_CMAR(dma, channel) = 0;
	/* Reset interrupt flags. */
	DMA_IFCR(dma) |= DMA_IFCR_CIF(channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Clear Interrupt Flag

The interrupt flag for the channel is cleared. More than one interrupt for the
same channel may be cleared by using the logical OR of the interrupt flags.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: @ref dma_ch
@param[in] interrupts unsigned int32. Logical OR of interrupt numbers: @ref
dma_if_offset
*/

void dma_clear_interrupt_flags(uint32_t dma, uint8_t channel,
			       uint32_t interrupts)
{
/* Get offset to interrupt flag location in channel field */
	uint32_t flags = (interrupts << DMA_FLAG_OFFSET(channel));
	DMA_IFCR(dma) = flags;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Read Interrupt Flag

The interrupt flag for the channel is returned.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: @ref dma_ch
@param[in] interrupt unsigned int32. Interrupt number: @ref dma_if_offset
@returns bool interrupt flag is set.
*/

bool dma_get_interrupt_flag(uint32_t dma, uint8_t channel, uint32_t interrupt)
{
/* get offset to interrupt flag location in channel field. */
	uint32_t flag = (interrupt << DMA_FLAG_OFFSET(channel));
	return ((DMA_ISR(dma) & flag) > 0);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Memory to Memory Transfers

Memory to memory transfers do not require a trigger to activate each transfer.
Transfers begin immediately the channel has been enabled, and proceed without
intervention.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_mem2mem_mode(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_MEM2MEM;
	DMA_CCR(dma, channel) &= ~DMA_CCR_CIRC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set Priority

Channel Priority has four levels: low to very high. This has precedence over the
hardware priority.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@param[in] prio unsigned int32. Priority level @ref dma_ch_pri.
*/

void dma_set_priority(uint32_t dma, uint8_t channel, uint32_t prio)
{
	DMA_CCR(dma, channel) &= ~(DMA_CCR_PL_MASK);
	DMA_CCR(dma, channel) |= prio;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set Memory Word Width

Set the memory word width 8 bits, 16 bits, or 32 bits. Refer to datasheet for
alignment information if the source and destination widths do not match.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@param[in] mem_size unsigned int32. Memory word width @ref dma_ch_memwidth.
*/

void dma_set_memory_size(uint32_t dma, uint8_t channel, uint32_t mem_size)
{

	DMA_CCR(dma, channel) &= ~(DMA_CCR_MSIZE_MASK);
	DMA_CCR(dma, channel) |= mem_size;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set Peripheral Word Width

Set the peripheral word width 8 bits, 16 bits, or 32 bits. Refer to datasheet
for alignment information if the source and destination widths do not match, or
if the peripheral does not support byte or half-word writes.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@param[in] peripheral_size unsigned int32. Peripheral word width @ref
dma_ch_perwidth.
*/

void dma_set_peripheral_size(uint32_t dma, uint8_t channel,
			     uint32_t peripheral_size)
{
	DMA_CCR(dma, channel) &= ~(DMA_CCR_PSIZE_MASK);
	DMA_CCR(dma, channel) |= peripheral_size;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Memory Increment after Transfer

Following each transfer the current memory address is incremented by
1, 2 or 4 depending on the data size set in @ref dma_set_memory_size. The
value held by the base memory address register is unchanged.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_memory_increment_mode(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_MINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Memory Increment after Transfer

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_disable_memory_increment_mode(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_MINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Peripheral Increment after Transfer

Following each transfer the current peripheral address is incremented by
1, 2 or 4 depending on the data size set in @ref dma_set_peripheral_size. The
value held by the base peripheral address register is unchanged.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_PINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Peripheral Increment after Transfer

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_PINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Memory Circular Mode

After the number of bytes/words to be transferred has been completed, the
original transfer block size, memory and peripheral base addresses are
reloaded and the process repeats.

@note This cannot be used with memory to memory mode, which is explicitly
disabled here.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_circular_mode(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_CIRC;
	DMA_CCR(dma, channel) &= ~DMA_CCR_MEM2MEM;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Transfers from a Peripheral

The data direction is set to read from a peripheral.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_set_read_from_peripheral(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_DIR;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Transfers from Memory

The data direction is set to read from memory.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_set_read_from_memory(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_DIR;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Interrupt on Transfer Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_TEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Interrupt on Transfer Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_TEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Interrupt on Transfer Half Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_HTIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Interrupt on Transfer Half Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_HTIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Interrupt on Transfer Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_TCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Interrupt on Transfer Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_TCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_enable_channel(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_EN;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable

@note The DMA channel registers retain their values when the channel is
disabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
*/

void dma_disable_channel(uint32_t dma, uint8_t channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_EN;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set the Peripheral Address

Set the address of the peripheral register to or from which data is to be
transferred.  Refer to the documentation for the specific peripheral.

@note The DMA channel must be disabled before setting this address. This
function has no effect if the channel is enabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@param[in] address unsigned int32. Peripheral Address.
*/

void dma_set_peripheral_address(uint32_t dma, uint8_t channel, uint32_t address)
{
	if (!(DMA_CCR(dma, channel) & DMA_CCR_EN)) {
		DMA_CPAR(dma, channel) = (uint32_t) address;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set the Base Memory Address

@note The DMA channel must be disabled before setting this address. This
function has no effect if the channel is enabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@param[in] address unsigned int32. Memory Initial Address.
*/

void dma_set_memory_address(uint32_t dma, uint8_t channel, uint32_t address)
{
	if (!(DMA_CCR(dma, channel) & DMA_CCR_EN)) {
		DMA_CMAR(dma, channel) = (uint32_t) address;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Get the Transfer Block Size

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@returns unsigned int16. Number of remaining data words to transfer (65535
maximum).
*/

uint16_t dma_get_number_of_data(uint32_t dma, uint8_t channel)
{
	return DMA_CNDTR(dma, channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set the Transfer Block Size

@note The DMA channel must be disabled before setting this count value. The
count is not changed if the channel is enabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] channel unsigned int8. Channel number: 1-7 for DMA1 or 1-5 for DMA2
@param[in] number unsigned int16. Number of data words to transfer (65535
maximum).
*/

void dma_set_number_of_data(uint32_t dma, uint8_t channel, uint16_t number)
{
	DMA_CNDTR(dma, channel) = number;
}
/**@}*/

