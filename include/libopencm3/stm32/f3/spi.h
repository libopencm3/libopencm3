/** @defgroup spi_defines SPI Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx SPI</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 5 December 2012
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/common/spi_common_all.h>

/* DFF: Data frame format */
/****************************************************************************/
/** @defgroup spi_dff SPI data frame format
 * @ingroup spi_defines
 *
 * @{*/

#define SPI_DR8(spi_base)	MMIO8(spi_base + 0x0c)
#define SPI1_DR8		SPI_DR8(SPI1_BASE)
#define SPI2_DR8		SPI_DR8(SPI2_I2S_BASE)
#define SPI3_DR8		SPI_DR8(SPI3_I2S_BASE)

#define SPI_CR1_CRCL_8BIT	(0 << 11)
#define SPI_CR1_CRCL_16BIT	(1 << 11)
/**@}*/
#define SPI_CR1_CRCL		(1 << 11)

/* --- SPI_CR2 values ------------------------------------------------------ */

/* LDMA_TX: Last DMA transfer for transmission */
#define SPI_CR2_LDMA_TX			(1 << 14)

/* LDMA_RX: Last DMA transfer for reception */
#define SPI_CR2_LDMA_RX			(1 << 13)

/* FRXTH: FIFO reception threshold */
#define SPI_CR2_FRXTH			(1 << 12)

/* DS [3:0]: Data size */
/* 0x0 - 0x2 NOT USED */
#define SPI_CR2_DS_4BIT			(0x3 << 8)
#define SPI_CR2_DS_5BIT			(0x4 << 8)
#define SPI_CR2_DS_6BIT			(0x5 << 8)
#define SPI_CR2_DS_7BIT			(0x6 << 8)
#define SPI_CR2_DS_8BIT			(0x7 << 8)
#define SPI_CR2_DS_9BIT			(0x8 << 8)
#define SPI_CR2_DS_10BIT		(0x9 << 8)
#define SPI_CR2_DS_11BIT		(0xA << 8)
#define SPI_CR2_DS_12BIT		(0xB << 8)
#define SPI_CR2_DS_13BIT		(0xC << 8)
#define SPI_CR2_DS_14BIT		(0xD << 8)
#define SPI_CR2_DS_15BIT		(0xE << 8)
#define SPI_CR2_DS_16BIT		(0xF << 8)
#define SPI_CR2_DS_MASK			(0xF << 8)

/* NSSP: NSS pulse management */
#define SPI_CR2_NSSP			(1 << 3)

/* --- SPI_SR values ------------------------------------------------------- */

/* FTLVL[1:0]: FIFO Transmission Level */
#define SPI_SR_FTLVL_FIFO_EMPTY		(0x0 << 11)
#define SPI_SR_FTLVL_QUARTER_FIFO	(0x1 << 11)
#define SPI_SR_FTLVL_HALF_FIFO		(0x2 << 11)
#define SPI_SR_FTLVL_FIFO_FULL		(0x3 << 11)

/* FRLVL[1:0]: FIFO Reception Level */
#define SPI_SR_FRLVL_FIFO_EMPTY		(0x0 << 9)
#define SPI_SR_FRLVL_QUARTER_FIFO	(0x1 << 9)
#define SPI_SR_FRLVL_HALF_FIFO		(0x2 << 9)
#define SPI_SR_FRLVL_FIFO_FULL		(0x3 << 9)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void spi_set_data_size(uint32_t spi, uint16_t data_s);
void spi_fifo_reception_threshold_8bit(uint32_t spi);
void spi_fifo_reception_threshold_16bit(uint32_t spi);
void spi_i2s_mode_spi_mode(uint32_t spi);
void spi_send8(uint32_t spi, uint8_t data);
uint8_t spi_read8(uint32_t spi);

END_DECLS

#endif
