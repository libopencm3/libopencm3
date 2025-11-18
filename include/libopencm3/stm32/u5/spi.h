/** @defgroup spi_defines SPI Defines
 *
 * @ingroup STM32U5xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32U5xx SPI</b>
 *
 * @version 1.0.0
 *
 * @date 17 November 2025
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

#ifndef LIBOPENCM3_SPI_H
#define LIBOPENCM3_SPI_H

#include <stdbool.h>

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup spi_reg_base SPI Register base address
@ingroup spi_defines

@{*/
#define SPI1 SPI1_BASE
#define SPI2 SPI2_BASE
#define SPI3 SPI3_BASE
/**@}*/

/* --- SPI registers ------------------------------------------------------- */

/* Control register 1 (SPIx_CR1) */
#define SPI_CR1(spi_base) MMIO32((spi_base) + 0x00U)
#define SPI1_CR1          SPI_CR1(SPI1_BASE)
#define SPI2_CR1          SPI_CR1(SPI2_BASE)
#define SPI3_CR1          SPI_CR1(SPI3_BASE)

/* Control register 2 (SPIx_CR2) */
#define SPI_CR2(spi_base) MMIO32((spi_base) + 0x04U)
#define SPI1_CR2          SPI_CR2(SPI1_BASE)
#define SPI2_CR2          SPI_CR2(SPI2_BASE)
#define SPI3_CR2          SPI_CR2(SPI3_BASE)

/* Configuration register 1 (SPIx_CFG1) */
#define SPI_CFG1(spi_base) MMIO32((spi_base) + 0x08U)
#define SPI1_CFG1          SPI_CFG1(SPI1_BASE)
#define SPI2_CFG1          SPI_CFG1(SPI2_BASE)
#define SPI3_CFG1          SPI_CFG1(SPI3_BASE)

/* Configuration register 2 (SPIx_CFG2) */
#define SPI_CFG2(spi_base) MMIO32((spi_base) + 0x0cU)
#define SPI1_CFG2          SPI_CFG2(SPI1_BASE)
#define SPI2_CFG2          SPI_CFG2(SPI2_BASE)
#define SPI3_CFG2          SPI_CFG2(SPI3_BASE)

/* Interrupt enable register (SPIx_IER) */
#define SPI_IER(spi_base) MMIO32((spi_base) + 0x10U)
#define SPI1_IER          SPI_IER(SPI1_BASE)
#define SPI2_IER          SPI_IER(SPI2_BASE)
#define SPI3_IER          SPI_IER(SPI3_BASE)

/* Status register (SPIx_SR) */
#define SPI_SR(spi_base) MMIO32((spi_base) + 0x14U)
#define SPI1_SR          SPI_SR(SPI1_BASE)
#define SPI2_SR          SPI_SR(SPI2_BASE)
#define SPI3_SR          SPI_SR(SPI3_BASE)

/* Interrupt status/flag clear register (SPIx_IFCR) */
#define SPI_IFCR(spi_base) MMIO32((spi_base) + 0x18U)
#define SPI1_IFCR          SPI_IFCR(SPI1_BASE)
#define SPI2_IFCR          SPI_IFCR(SPI2_BASE)
#define SPI3_IFCR          SPI_IFCR(SPI3_BASE)

/* Autonomous control register (SPIx_AUTOCR) */
#define SPI_AUTOCR(spi_base) MMIO32((spi_base) + 0x1cU)
#define SPI1_AUTOCR          SPI_AUTOCR(SPI1_BASE)
#define SPI2_AUTOCR          SPI_AUTOCR(SPI2_BASE)
#define SPI3_AUTOCR          SPI_AUTOCR(SPI3_BASE)

/* Transmit data register (SPIx_TXDR) */
#define SPI_TXDR(spi_base) MMIO32((spi_base) + 0x20U)
#define SPI1_TXDR          SPI_TXDR(SPI1_BASE)
#define SPI2_TXDR          SPI_TXDR(SPI2_BASE)
#define SPI3_TXDR          SPI_TXDR(SPI3_BASE)

/* Receive data register (SPIx_RXDR) */
#define SPI_RXDR(spi_base) MMIO32((spi_base) + 0x30U)
#define SPI1_RXDR          SPI_RXDR(SPI1_BASE)
#define SPI2_RXDR          SPI_RXDR(SPI2_BASE)
#define SPI3_RXDR          SPI_RXDR(SPI3_BASE)

/* Polynomial register (SPIx_CRCPOLY) */
#define SPI_CRCPOLY(spi_base) MMIO32((spi_base) + 0x40U)
#define SPI1_CRCPOLY          SPI_CRCPOLY(SPI1_BASE)
#define SPI2_CRCPOLY          SPI_CRCPOLY(SPI2_BASE)
#define SPI3_CRCPOLY          SPI_CRCPOLY(SPI3_BASE)

/* Transmitter CRC register (SPIx_TXCRC) */
#define SPI_TXCRC(spi_base) MMIO32((spi_base) + 0x44U)
#define SPI1_TXCRC          SPI_TXCRC(SPI1_BASE)
#define SPI2_TXCRC          SPI_TXCRC(SPI2_BASE)
#define SPI3_TXCRC          SPI_TXCRC(SPI3_BASE)

/* Receiver CRC register (SPIx_RXCRC) */
#define SPI_RXCRC(spi_base) MMIO32((spi_base) + 0x48U)
#define SPI1_RXCRC          SPI_RXCRC(SPI1_BASE)
#define SPI2_RXCRC          SPI_RXCRC(SPI2_BASE)
#define SPI3_RXCRC          SPI_RXCRC(SPI3_BASE)

/* Underrun data register (SPIx_UDRDR) */
#define SPI_UDRDR(spi_base) MMIO32((spi_base) + 0x4cU)
#define SPI1_UDRDR          SPI_UDRDR(SPI1_BASE)
#define SPI2_UDRDR          SPI_UDRDR(SPI2_BASE)
#define SPI3_UDRDR          SPI_UDRDR(SPI3_BASE)

/* --- SPI_CR1 values ------------------------------------------------------ */

/* SSI: Internal slave select input level */
#define SPI_CR1_SSI (1U << 12U)

/* CSTART: Master transfer start */
#define SPI_CR1_CSTART (1U << 9U)

/* SPE: SPI enable */
#define SPI_CR1_SPE (1U << 0U)

/* --- SPI_CR2 values ------------------------------------------------------ */

#define SPI_CR1_TSIZE_MASK 0x0000ffffU

/* --- SPI_CFG1 values ----------------------------------------------------- */

/* BPASS: Master baud rate clock generator prescaler bypass */
#define SPI_CFG1_BPASS (1U << 31U)

/* MBR: Master baud rate prescaler */
/****************************************************************************/
/** @defgroup spi_mbr SPI master baud rate prescaler
 * @ingroup spi_defines
 *
 * @{*/
#define SPI_CFG1_MBR_DIV2   (0x0U << 28U)
#define SPI_CFG1_MBR_DIV4   (0x1U << 28U)
#define SPI_CFG1_MBR_DIV8   (0x2U << 28U)
#define SPI_CFG1_MBR_DIV16  (0x3U << 28U)
#define SPI_CFG1_MBR_DIV32  (0x4U << 28U)
#define SPI_CFG1_MBR_DIV64  (0x5U << 28U)
#define SPI_CFG1_MBR_DIV128 (0x6U << 28U)
#define SPI_CFG1_MBR_DIV256 (0x7U << 28U)
/**@}*/
#define SPI_CFG1_MBR_MASK (0x7U << 28U)

/* CRCEN: Hardware CRC calculation enable */
#define SPI_CFG1_CRCEN (1U << 22U)

/* TXDMAEN: Tx DMA stream enable */
#define SPI_CFG1_TXDMAEN (1U << 15U)

/* RXDMAEN: Rx DMA stream enable */
#define SPI_CFG1_RXDMAEN (1U << 14U)

/* DSIZE: Data size */
/****************************************************************************/
/** @defgroup spi_dsize SPI data size
 * @ingroup spi_defines
 *
 * @{*/
#define SPI_CFG1_DSIZE_4BIT  (0x03U << 0U)
#define SPI_CFG1_DSIZE_5BIT  (0x04U << 0U)
#define SPI_CFG1_DSIZE_6BIT  (0x05U << 0U)
#define SPI_CFG1_DSIZE_7BIT  (0x06U << 0U)
#define SPI_CFG1_DSIZE_8BIT  (0x07U << 0U)
#define SPI_CFG1_DSIZE_9BIT  (0x08U << 0U)
#define SPI_CFG1_DSIZE_10BIT (0x09U << 0U)
#define SPI_CFG1_DSIZE_11BIT (0x0aU << 0U)
#define SPI_CFG1_DSIZE_12BIT (0x0bU << 0U)
#define SPI_CFG1_DSIZE_13BIT (0x0cU << 0U)
#define SPI_CFG1_DSIZE_14BIT (0x0dU << 0U)
#define SPI_CFG1_DSIZE_15BIT (0x0eU << 0U)
#define SPI_CFG1_DSIZE_16BIT (0x0fU << 0U)
#define SPI_CFG1_DSIZE_17BIT (0x10U << 0U)
#define SPI_CFG1_DSIZE_18BIT (0x11U << 0U)
#define SPI_CFG1_DSIZE_19BIT (0x12U << 0U)
#define SPI_CFG1_DSIZE_20BIT (0x13U << 0U)
#define SPI_CFG1_DSIZE_21BIT (0x14U << 0U)
#define SPI_CFG1_DSIZE_22BIT (0x15U << 0U)
#define SPI_CFG1_DSIZE_23BIT (0x16U << 0U)
#define SPI_CFG1_DSIZE_24BIT (0x17U << 0U)
#define SPI_CFG1_DSIZE_25BIT (0x18U << 0U)
#define SPI_CFG1_DSIZE_26BIT (0x19U << 0U)
#define SPI_CFG1_DSIZE_27BIT (0x1aU << 0U)
#define SPI_CFG1_DSIZE_28BIT (0x1bU << 0U)
#define SPI_CFG1_DSIZE_29BIT (0x1cU << 0U)
#define SPI_CFG1_DSIZE_30BIT (0x1dU << 0U)
#define SPI_CFG1_DSIZE_31BIT (0x1eU << 0U)
#define SPI_CFG1_DSIZE_32BIT (0x1fU << 0U)
/**@}*/
#define SPI_CFG1_DSIZE_MASK (0x1fU << 0U)

/* --- SPI_CFG2 values ----------------------------------------------------- */

/* AFCNTR: Alternate function GPIOs control */
#define SPI_CFG2_AFCNTR (1U << 31U)

/* SSM: Software slave ouptut management in Master mode */
#define SPI_CFG2_SSOM (1U << 30U)

/* SSOE: SS output enable */
#define SPI_CFG2_SSOE (1U << 29U)

/* SSIOP: SS input/output polarity */
#define SPI_CFG2_SSIOP (1U << 28U)

/* SSM: Software slave management */
#define SPI_CFG2_SSM (1U << 26U)

/* CPOL: Clock polarity */
/****************************************************************************/
/** @defgroup spi_cpol SPI clock polarity
@ingroup spi_defines

@{*/
#define SPI_CFG2_CPOL_CLK_TO_0_WHEN_IDLE (0U << 25U)
#define SPI_CFG2_CPOL_CLK_TO_1_WHEN_IDLE (1U << 25U)
/**@}*/
#define SPI_CFG2_CPOL (1U << 25U)

/* CPHA: Clock phase */
/****************************************************************************/
/** @defgroup spi_cpha SPI clock phase
@ingroup spi_defines

@{*/
#define SPI_CFG2_CPHA_CLK_TRANSITION_1 (0U << 24U)
#define SPI_CFG2_CPHA_CLK_TRANSITION_2 (1U << 24U)
/**@}*/
#define SPI_CFG2_CPHA (1U << 24U)

#define SPI_CFG2_CPOL_CPHA_SHIFT 24U

/* LSBFIRST: Frame format */
/****************************************************************************/
/** @defgroup spi_lsbfirst SPI lsb/msb first
@ingroup spi_defines

@{*/
#define SPI_CFG2_MSBFIRST (0U << 23U)
#define SPI_CFG2_LSBFIRST (1U << 23U)

/* MASTER: SPI master */
#define SPI_CFG2_MASTER (1U << 22U)

/* SP: SPI protocol */
/****************************************************************************/
/** @defgroup spi_sp SPI protocols
@ingroup spi_defines

@{*/
#define SPI_CFG2_SP_MOTOROLA (0U << 19U)
#define SPI_CFG2_SP_TI       (1U << 19U)
/**@}*/
#define SPI_CFG2_SP_MASK (0x7U << 19U)

/* --- SPI_IER values ------------------------------------------------------ */

/* --- SPI_SR values ------------------------------------------------------- */

/* RXWNE: RxFIFO word not empty */
#define SPI_SR_RXWNE (1U << 15U)

/* TXC: TxFIFO tranmission complete */
#define SPI_SR_TXC (1U << 12U)

/* SUSP: Suspension status */
#define SPI_SR_SUSP (1U << 11U)

/* MODF: Mode fault */
#define SPI_SR_MODF (1U << 9U)

/* TIFRE: TI frame format error */
#define SPI_SR_TIFRE (1U << 8U)

/* CRCE: CRC error */
#define SPI_SR_CRCE (1U << 7U)

/* OVR: Overrun flag */
#define SPI_SR_OVR (1U << 6U)

/* UDR: Underrun flag */
#define SPI_SR_UDR (1U << 5U)

/* TXTF: Transmission transfer filled */
#define SPI_SR_TXTF (1U << 4U)

/* EOT: End of transfer */
#define SPI_SR_EOT (1U << 3U)

/* DXP: Duplex packet */
#define SPI_SR_DXP (1U << 2U)

/* TXP: TX packet space available */
#define SPI_SR_TXP (1U << 1U)

/* RXP: RX packet available */
#define SPI_SR_RXP (1U << 0U)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void spi_enable(uintptr_t spi);
void spi_disable(uintptr_t spi);

void spi_write(uintptr_t spi, uint32_t data);
void spi_send(uintptr_t spi, uint32_t data);
uint32_t spi_read(uintptr_t spi);
uint32_t spi_xfer(uintptr_t spi, uint32_t data);
void spi_write8(uintptr_t spi, uint8_t data);
uint8_t spi_read8(uintptr_t spi);
uint8_t spi_xfer8(uintptr_t spi, uint8_t data);
void spi_write16(uintptr_t spi, uint16_t data);
uint16_t spi_read16(uintptr_t spi);

void spi_enable_crc(uintptr_t spi);
void spi_disable_crc(uintptr_t spi);

void spi_disable_software_slave_management(uintptr_t spi);
void spi_enable_software_slave_management(uintptr_t spi);
void spi_set_nss_high(uintptr_t spi);
void spi_set_nss_low(uintptr_t spi);
void spi_set_nss_active_high(uintptr_t spi);
void spi_set_nss_active_low(uintptr_t spi);
void spi_send_lsb_first(uintptr_t spi);
void spi_send_msb_first(uintptr_t spi);

void spi_set_master_mode(uintptr_t spi);
void spi_set_slave_mode(uintptr_t spi);
void spi_set_clock_polarity_1(uintptr_t spi);
void spi_set_clock_polarity_0(uintptr_t spi);
void spi_set_clock_phase_1(uintptr_t spi);
void spi_set_clock_phase_0(uintptr_t spi);

void spi_enable_tx_dma(uintptr_t spi);
void spi_disable_tx_dma(uintptr_t spi);
void spi_enable_rx_dma(uintptr_t spi);
void spi_disable_rx_dma(uintptr_t spi);
void spi_set_standard_mode(uintptr_t spi, uint8_t mode);

bool spi_init_master(uintptr_t spi, uint32_t baud_rate, uint32_t cpol, uint32_t cpha, uint32_t data_size,
	uint32_t lsbfirst, uint32_t protocol);
void spi_set_data_size(uintptr_t spi, uint8_t data_size);
void spi_set_transfer_size(uintptr_t spi, uint16_t transfer_size);

END_DECLS

/**@}*/

#endif
