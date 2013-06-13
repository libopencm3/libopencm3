/** @addtogroup dma_file

@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

This library supports the DMA Control System in the STM32F2 and STM32F4
series of ARM Cortex Microcontrollers by ST Microelectronics.

Up to two DMA controllers are supported each with 8 streams, and each stream
having up to 8 channels hardware dedicated to various peripheral DMA signals.

DMA transfers can be configured to occur between peripheral and memory in
either direction, and memory to memory. Peripheral to peripheral transfer
is not supported. Circular mode transfers are also supported in transfers
involving a peripheral. An arbiter is provided to resolve priority DMA
requests. Transfers can be made with 8, 16 or 32 bit words.

Each stream has access to a 4 word deep FIFO and can use double buffering
by means of two memory pointers. When using the FIFO it is possible to
configure transfers to occur in indivisible bursts.

It is also possible to select a peripheral instead of the DMA controller to
control the flow of data. This limits the functionality but is useful when the
number of transfers is unknown.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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
/** @brief DMA Stream Reset

The specified stream is disabled and configuration registers are cleared.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_stream_reset(uint32_t dma, uint8_t stream)
{
/* Disable stream (must be done before register is otherwise changed). */
	DMA_SCR(dma, stream) &= ~DMA_SxCR_EN;
/* Reset all config bits. */
	DMA_SCR(dma, stream) = 0;
/* Reset data transfer number. */
	DMA_SNDTR(dma, stream) = 0;
/* Reset peripheral and memory addresses. */
	DMA_SPAR(dma, stream) = 0;
	DMA_SM0AR(dma, stream) = 0;
	DMA_SM1AR(dma, stream) = 0;
/* This is the default setting */
	DMA_SFCR(dma, stream) = 0x21;
/* Reset all stream interrupt flags using the interrupt flag clear register. */
	uint32_t mask = DMA_ISR_MASK(stream);
	if (stream < 4) {
		DMA_LIFCR(dma) |= mask;
	} else {
		DMA_HIFCR(dma) |= mask;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Clear Interrupt Flag

The interrupt flag for the stream is cleared. More than one interrupt for the
same stream may be cleared by using the bitwise OR of the interrupt flags.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] interrupts unsigned int32. Bitwise OR of interrupt numbers: @ref
dma_if_offset
*/

void dma_clear_interrupt_flags(uint32_t dma, uint8_t stream,
			       uint32_t interrupts)
{
	/* Get offset to interrupt flag location in stream field */
	uint32_t flags = (interrupts << DMA_ISR_OFFSET(stream));
	/* First four streams are in low register. Flag clear must be set then
	 * reset.
	 */
	if (stream < 4) {
		DMA_LIFCR(dma) = flags;
	} else {
		DMA_HIFCR(dma) = flags;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Read Interrupt Flag

The interrupt flag for the stream is returned.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] interrupt unsigned int32. Interrupt number: @ref dma_if_offset
@returns bool interrupt flag is set.
*/

bool dma_get_interrupt_flag(uint32_t dma, uint8_t stream, uint32_t interrupt)
{
	/* get offset to interrupt flag location in stream field. Assumes
	 * stream and interrupt parameters are integers.
	 */
	uint32_t flag = (interrupt << DMA_ISR_OFFSET(stream));
	/* First four streams are in low register */
	if (stream < 4) {
		return ((DMA_LISR(dma) & flag) > 0);
	} else {
		return ((DMA_HISR(dma) & flag) > 0);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Transfer Direction

Set peripheral to memory, memory to peripheral or memory to memory. If memory
to memory mode is selected, circular mode and double buffer modes are disabled.
Ensure that these modes are not enabled at a later time.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] direction unsigned int32. Data transfer direction @ref dma_st_dir
*/

void dma_set_transfer_mode(uint32_t dma, uint8_t stream, uint32_t direction)
{
	uint32_t reg32 = (DMA_SCR(dma, stream) & ~DMA_SxCR_DIR_MASK);
	/* Disable circular and double buffer modes if memory to memory
	 * transfers are in effect. (Direct Mode is automatically disabled by
	 * hardware)
	 */
	if (direction == DMA_SxCR_DIR_MEM_TO_MEM) {
		reg32 &= ~(DMA_SxCR_CIRC | DMA_SxCR_DBM);
	}

	DMA_SCR(dma, stream) = (reg32 | direction);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Priority

Stream Priority has four levels: low to very high. This has precedence over the
hardware priority. In the event of equal software priority the lower numbered
stream has priority.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] prio unsigned int32. Priority level @ref dma_st_pri.
*/

void dma_set_priority(uint32_t dma, uint8_t stream, uint32_t prio)
{
	DMA_SCR(dma, stream) &= ~(DMA_SxCR_PL_MASK);
	DMA_SCR(dma, stream) |= prio;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Memory Word Width

Set the memory word width 8 bits, 16 bits, or 32 bits. Refer to datasheet for
alignment information if the source and destination widths do not match.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] mem_size unsigned int32. Memory word width @ref dma_st_memwidth.
*/

void dma_set_memory_size(uint32_t dma, uint8_t stream, uint32_t mem_size)
{
	DMA_SCR(dma, stream) &= ~(DMA_SxCR_MSIZE_MASK);
	DMA_SCR(dma, stream) |= mem_size;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Peripheral Word Width

Set the peripheral word width 8 bits, 16 bits, or 32 bits. Refer to datasheet
for alignment information if the source and destination widths do not match, or
if the peripheral does not support byte or half-word writes.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] peripheral_size unsigned int32. Peripheral word width @ref
dma_st_perwidth.
*/

void dma_set_peripheral_size(uint32_t dma, uint8_t stream,
			     uint32_t peripheral_size)
{
	DMA_SCR(dma, stream) &= ~(DMA_SxCR_PSIZE_MASK);
	DMA_SCR(dma, stream) |= peripheral_size;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Memory Increment after Transfer

Following each transfer the current memory address is incremented by
1, 2 or 4 depending on the data size set in @ref dma_set_memory_size. The
value held by the base memory address register is unchanged.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_memory_increment_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) |= DMA_SxCR_MINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Memory Increment after Transfer

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_memory_increment_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_MINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Variable Sized Peripheral Increment after Transfer

Following each transfer the current peripheral address is incremented by
1, 2 or 4 depending on the data size set in @ref dma_set_peripheral_size. The
value held by the base peripheral address register is unchanged.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t stream)
{
	uint32_t reg32 = (DMA_SCR(dma, stream) | DMA_SxCR_PINC);
	DMA_SCR(dma, stream) = (reg32 & ~DMA_SxCR_PINCOS);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Disable Peripheral Increment after Transfer

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_PINC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Enable Fixed Sized Peripheral Increment after Transfer

Following each transfer the current peripheral address is incremented by
4 regardless of the data size. The value held by the base peripheral address
register is unchanged.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_fixed_peripheral_increment_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) |= (DMA_SxCR_PINC | DMA_SxCR_PINCOS);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Memory Circular Mode

After the number of bytes/words to be transferred has been completed, the
original transfer block size, memory and peripheral base addresses are
reloaded and the process repeats.

Ensure that the stream is disabled otherwise the setting will not be changed.

@note This cannot be used with memory to memory mode. It is disabled
automatically if the peripheral is selected as the flow controller.
It is enabled automatically if double buffered mode is selected.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_circular_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) |= DMA_SxCR_CIRC;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Channel Select

Associate an input channel to the stream. Not every channel is allocated to a
hardware DMA request signal. The allocations for each stream are given in the
STM32F4 Reference Manual.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] channel unsigned int8. Channel selection @ref dma_ch_sel
*/

void dma_channel_select(uint32_t dma, uint8_t stream, uint32_t channel)
{
	DMA_SCR(dma, stream) |= channel;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Memory Burst Configuration

Set the memory burst type to none, 4 8 or 16 word length. This is forced to none
if direct mode is used.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] burst unsigned int8. Memory Burst selection @ref dma_mburst
*/

void dma_set_memory_burst(uint32_t dma, uint8_t stream, uint32_t burst)
{
	uint32_t reg32 = (DMA_SCR(dma, stream) & ~DMA_SxCR_MBURST_MASK);
	DMA_SCR(dma, stream) = (reg32 | burst);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Peripheral Burst Configuration

Set the memory burst type to none, 4 8 or 16 word length. This is forced to none
if direct mode is used.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] burst unsigned int8. Peripheral Burst selection @ref dma_pburst
*/

void dma_set_peripheral_burst(uint32_t dma, uint8_t stream, uint32_t burst)
{
	uint32_t reg32 = (DMA_SCR(dma, stream) & ~DMA_SxCR_PBURST_MASK);
	DMA_SCR(dma, stream) = (reg32 | burst);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Initial Target Memory

In double buffered mode, set the target memory (M0 or M1) to be used for the
first transfer.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] memory unsigned int8. Initial memory pointer to use: 0 or 1
*/

void dma_set_initial_target(uint32_t dma, uint8_t stream, uint8_t memory)
{
	uint32_t reg32 = (DMA_SCR(dma, stream) & ~DMA_SxCR_CT);
	if (memory == 1) {
		reg32 |= DMA_SxCR_CT;
	}

	DMA_SCR(dma, stream) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Read Current Memory Target

In double buffer mode, return the current memory target (M0 or M1). It is
possible to update the memory pointer in the register that is <b> not </b>
currently in use. An attempt to change the register currently in use will cause
the stream to be disabled and the transfer error flag to be set.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@returns unsigned int8. Memory buffer in use: 0 or 1
*/

uint8_t dma_get_target(uint32_t dma, uint8_t stream)
{
	if (DMA_SCR(dma, stream) & DMA_SxCR_CT) {
		return 1;
	}

	return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Double Buffer Mode

Double buffer mode is used for memory to/from peripheral transfers only, and in
circular mode which is automatically enabled. Two memory buffers must be
established with pointers stored in the memory pointer registers.

Ensure that the stream is disabled otherwise the setting will not be changed.

@note This cannot be used with memory to memory mode.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_double_buffer_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) |= DMA_SxCR_DBM;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Disable Double Buffer Mode

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_double_buffer_mode(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_DBM;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set Peripheral Flow Control

Set the peripheral to control DMA flow. Useful when the number of transfers is
unknown. This is forced off when memory to memory mode is selected.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_set_peripheral_flow_control(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) |= DMA_SxCR_PFCTRL;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set DMA Flow Control

Set the DMA controller to control DMA flow. This is the default.

Ensure that the stream is disabled otherwise the setting will not be changed.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_set_dma_flow_control(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_PFCTRL;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Interrupt on Transfer Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t stream)
{
	dma_clear_interrupt_flags(dma, stream, DMA_TEIF);
	DMA_SCR(dma, stream) |= DMA_SxCR_TEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Disable Interrupt on Transfer Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_TEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Interrupt on Transfer Half Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t stream)
{
	dma_clear_interrupt_flags(dma, stream, DMA_HTIF);
	DMA_SCR(dma, stream) |= DMA_SxCR_HTIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Disable Interrupt on Transfer Half Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_HTIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Interrupt on Transfer Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t stream)
{
	dma_clear_interrupt_flags(dma, stream, DMA_TCIF);
	DMA_SCR(dma, stream) |= DMA_SxCR_TCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Disable Interrupt on Transfer Complete

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_TCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable Interrupt on Direct Mode Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream)
{
	dma_clear_interrupt_flags(dma, stream, DMA_DMEIF);
	DMA_SCR(dma, stream) |= DMA_SxCR_DMEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Disable Interrupt on Direct Mode Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_DMEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Enable Interrupt on FIFO Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_fifo_error_interrupt(uint32_t dma, uint8_t stream)
{
	dma_clear_interrupt_flags(dma, stream, DMA_FEIF);
	DMA_SFCR(dma, stream) |= DMA_SxFCR_FEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Disable Interrupt on FIFO Error

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_fifo_error_interrupt(uint32_t dma, uint8_t stream)
{
	DMA_SFCR(dma, stream) &= ~DMA_SxFCR_FEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Get FIFO Status

Status of FIFO (empty. full or partial filled states) is returned. This has no
meaning if direct mode is enabled (as the FIFO is not used).

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@returns uint32_t FIFO Status @ref dma_fifo_status
*/

uint32_t dma_fifo_status(uint32_t dma, uint8_t stream)
{
	return DMA_SFCR(dma, stream) & DMA_SxFCR_FS_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Enable Direct Mode

Direct mode is the default. Data is transferred as soon as a DMA request is
received. The FIFO is not used. This must not be set when memory to memory
mode is selected.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_direct_mode(uint32_t dma, uint8_t stream)
{
	DMA_SFCR(dma, stream) &= ~DMA_SxFCR_DMDIS;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Enable FIFO Mode

Data is transferred via a FIFO.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_fifo_mode(uint32_t dma, uint8_t stream)
{
	DMA_SFCR(dma, stream) |= DMA_SxFCR_DMDIS;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Set FIFO Threshold

This is the filled level at which data is transferred out of the FIFO to the
destination.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] threshold unsigned int8. Threshold setting @ref dma_fifo_thresh
*/

void dma_set_fifo_threshold(uint32_t dma, uint8_t stream, uint32_t threshold)
{
	uint32_t reg32 = (DMA_SFCR(dma, stream) & ~DMA_SxFCR_FTH_MASK);
	DMA_SFCR(dma, stream) = (reg32 | threshold);
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Enable

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_enable_stream(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) |= DMA_SxCR_EN;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Disable

@note The DMA stream registers retain their values when the stream is disabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
*/

void dma_disable_stream(uint32_t dma, uint8_t stream)
{
	DMA_SCR(dma, stream) &= ~DMA_SxCR_EN;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set the Peripheral Address

Set the address of the peripheral register to or from which data is to be
transferred.  Refer to the documentation for the specific peripheral.

@note The DMA stream must be disabled before setting this address. This function
has no effect if the stream is enabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] address unsigned int32. Peripheral Address.
*/

void dma_set_peripheral_address(uint32_t dma, uint8_t stream, uint32_t address)
{
	if (!(DMA_SCR(dma, stream) & DMA_SxCR_EN)) {
		DMA_SPAR(dma, stream) = (uint32_t *) address;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set the Base Memory Address 0

Set the address pointer to the memory location for DMA transfers. The DMA stream
must normally be disabled before setting this address, however it is possible
to change this in double buffer mode when the current target is memory area 1
(see @ref dma_get_target).

This is the default base memory address used in direct mode.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] address unsigned int32. Memory Initial Address.
*/

void dma_set_memory_address(uint32_t dma, uint8_t stream, uint32_t address)
{
	uint32_t reg32 = DMA_SCR(dma, stream);
	if (!(reg32 & DMA_SxCR_EN) ||
	     ((reg32 & DMA_SxCR_CT) && (reg32 & DMA_SxCR_DBM))) {
		DMA_SM0AR(dma, stream) = (uint32_t *) address;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set the Base Memory Address 1

Set the address pointer to the memory location for DMA transfers. The DMA stream
must normally be disabled before setting this address, however it is possible
to change this in double buffer mode when the current target is memory area 0
(see @ref dma_get_target).

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] address unsigned int32. Memory Initial Address.
*/

void dma_set_memory_address_1(uint32_t dma, uint8_t stream, uint32_t address)
{
	uint32_t reg32 = DMA_SCR(dma, stream);
	if (!(reg32 & DMA_SxCR_EN) ||
	     (!(reg32 & DMA_SxCR_CT) && (reg32 & DMA_SxCR_DBM))) {
		DMA_SM1AR(dma, stream) = (uint32_t *) address;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Stream Set the Transfer Block Size

@note The DMA stream must be disabled before setting this count value. The count
is not changed if the stream is enabled.

@param[in] dma unsigned int32. DMA controller base address: DMA1 or DMA2
@param[in] stream unsigned int8. Stream number: @ref dma_st_number
@param[in] number unsigned int16. Number of data words to transfer (65535
maximum).
*/

void dma_set_number_of_data(uint32_t dma, uint8_t stream, uint16_t number)
{
	DMA_SNDTR(dma, stream) = number;
}
/**@}*/

