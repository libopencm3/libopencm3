/** @defgroup ssp_defines Synchronous Serial Port

@brief <b>Defined Constants and Types for the LPC43xx Synchronous Serial
Port</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
* This file is part of the libopencm3 project.
*
* Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_SSP_H
#define LPC43XX_SSP_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* SSP port base addresses (for convenience) */
#define SSP0                            SSP0_BASE
#define SSP1                            SSP1_BASE


/* --- SSP registers ------------------------------------------------------- */

/* Control Register 0 */
#define SSP_CR0(port)                   MMIO32(port + 0x000)
#define SSP0_CR0                        SSP_CR0(SSP0)
#define SSP1_CR0                        SSP_CR0(SSP1)

/* Control Register 1 */
#define SSP_CR1(port)                   MMIO32(port + 0x004)
#define SSP0_CR1                        SSP_CR1(SSP0)
#define SSP1_CR1                        SSP_CR1(SSP1)

/* Data Register */
#define SSP_DR(port)                    MMIO32(port + 0x008)
#define SSP0_DR                         SSP_DR(SSP0)
#define SSP1_DR                         SSP_DR(SSP1)

/* Status Register */
#define SSP_SR(port)                    MMIO32(port + 0x00C)
#define SSP0_SR                         SSP_SR(SSP0)
#define SSP1_SR                         SSP_SR(SSP1)

#define SSP_SR_TFE                      BIT0
#define SSP_SR_TNF                      BIT1
#define SSP_SR_RNE                      BIT2
#define SSP_SR_RFF                      BIT3
#define SSP_SR_BSY                      BIT4

/* Clock Prescale Register */
#define SSP_CPSR(port)                  MMIO32(port + 0x010)
#define SSP0_CPSR                       SSP_CPSR(SSP0)
#define SSP1_CPSR                       SSP_CPSR(SSP1)

/* Interrupt Mask Set and Clear Register */
#define SSP_IMSC(port)                  MMIO32(port + 0x014)
#define SSP0_IMSC                       SSP_IMSC(SSP0)
#define SSP1_IMSC                       SSP_IMSC(SSP1)

/* Raw Interrupt Status Register */
#define SSP_RIS(port)                   MMIO32(port + 0x018)
#define SSP0_RIS                        SSP_RIS(SSP0)
#define SSP1_RIS                        SSP_RIS(SSP1)

/* Masked Interrupt Status Register */
#define SSP_MIS(port)                   MMIO32(port + 0x01C)
#define SSP0_MIS                        SSP_MIS(SSP0)
#define SSP1_MIS                        SSP_MIS(SSP1)

/* SSPICR Interrupt Clear Register */
#define SSP_ICR(port)                   MMIO32(port + 0x020)
#define SSP0_ICR                        SSP_ICR(SSP0)
#define SSP1_ICR                        SSP_ICR(SSP1)

/* SSP1 DMA control register */
#define SSP_DMACR(port)                 MMIO32(port + 0x024)
#define SSP0_DMACR                      SSP_DMACR(SSP0)
#define SSP1_DMACR                      SSP_DMACR(SSP1)

/* RXDMAE: Receive DMA enable */
#define SSP_DMACR_RXDMAE                0x1

/* RXDMAE: Transmit DMA enable */
#define SSP_DMACR_TXDMAE                0x2

typedef enum {
	SSP0_NUM = 0x0,
	SSP1_NUM = 0x1
} ssp_num_t;

/*
 * SSP Control Register 0
 */
/* SSP Data Size Bits 0 to 3 */
typedef enum {
	SSP_DATA_4BITS  = 0x3,
	SSP_DATA_5BITS  = 0x4,
	SSP_DATA_6BITS  = 0x5,
	SSP_DATA_7BITS  = 0x6,
	SSP_DATA_8BITS  = 0x7,
	SSP_DATA_9BITS  = 0x8,
	SSP_DATA_10BITS = 0x9,
	SSP_DATA_11BITS = 0xA,
	SSP_DATA_12BITS = 0xB,
	SSP_DATA_13BITS = 0xC,
	SSP_DATA_14BITS = 0xD,
	SSP_DATA_15BITS = 0xE,
	SSP_DATA_16BITS = 0xF
} ssp_datasize_t;

/* SSP Frame Format/Type Bits 4 & 5 */
typedef enum {
	SSP_FRAME_SPI      = 0x00,
	SSP_FRAME_TI       = BIT4,
	SSP_FRAM_MICROWIRE = BIT5
} ssp_frame_format_t;

/* Clock Out Polarity / Clock Out Phase Bits Bits 6 & 7 */
typedef enum {
	SSP_CPOL_0_CPHA_0 = 0x0,
	SSP_CPOL_1_CPHA_0 = BIT6,
	SSP_CPOL_0_CPHA_1 = BIT7,
	SSP_CPOL_1_CPHA_1 = (BIT6|BIT7)
} ssp_cpol_cpha_t;

/*
 * SSP Control Register 1
 */
/* SSP Mode Bit0  */
typedef enum {
	SSP_MODE_NORMAL   = 0x0,
	SSP_MODE_LOOPBACK = BIT0
} ssp_mode_t;

/* SSP Enable Bit1  */
#define SSP_ENABLE  BIT1

/* SSP Master/Slave Mode Bit2 */
typedef enum {
	SSP_MASTER = 0x0,
	SSP_SLAVE  = BIT2
} ssp_master_slave_t;

/*
* SSP Slave Output Disable Bit3
* Slave Output Disable. This bit is relevant only in slave mode
* (MS = 1). If it is 1, this blocks this SSP controller from driving the
* transmit data line (MISO).
*/
typedef enum {
	SSP_SLAVE_OUT_ENABLE  = 0x0,
	SSP_SLAVE_OUT_DISABLE = BIT3
} ssp_slave_option_t; /* This option is relevant only in slave mode */

BEGIN_DECLS

void ssp_disable(ssp_num_t ssp_num);

/*
 * SSP Init
 * clk_prescale shall be in range 2 to 254 (even number only).
 * Clock computation: PCLK / (CPSDVSR * [SCR+1]) => CPSDVSR=clk_prescale,
 * SCR=serial_clock_rate
 */
void ssp_init(ssp_num_t ssp_num,
				ssp_datasize_t data_size,
				ssp_frame_format_t frame_format,
				ssp_cpol_cpha_t cpol_cpha_format,
				uint8_t serial_clock_rate,
				uint8_t clk_prescale,
				ssp_mode_t mode,
				ssp_master_slave_t master_slave,
				ssp_slave_option_t slave_option);

uint16_t ssp_transfer(ssp_num_t ssp_num, uint16_t data);

END_DECLS

/**@}*/

#endif
