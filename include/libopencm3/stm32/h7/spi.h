/** @defgroup spi_defines SPI Defines
@brief <b>Defined Constants and Types for the STM32H7xx SPI</b>
@ingroup STM32H7xx_defines
@version 1.0.0
LGPL License Terms @ref lgpl_license
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

#ifndef INCLUDE_LIBOPENCM3_STM32_H7_SPI_H_
#define INCLUDE_LIBOPENCM3_STM32_H7_SPI_H_

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/* SPI Base Addresses */
/** @defgroup spi_base_addresses SPI Base Addresses
@ingroup spi_defines
@{*/
#define SPI1        SPI1_BASE
#define SPI2        SPI2_BASE
#define SPI3        SPI3_BASE
#define SPI4        SPI4_BASE
#define SPI5        SPI5_BASE
#define SPI6        SPI6_BASE
/**@}*/


/* SPI Register Offsets */
/** @defgroup spi_reg_offsets SPI Registers
@ingroup spi_defines
@{*/
#define SPI2S_CR1(spi_base)   MMIO32((spi_base) + 0x00)
#define SPI_CR2(spi_base)   MMIO32((spi_base) + 0x04)
#define SPI_CFG1(spi_base)   MMIO32((spi_base) + 0x08)
#define SPI_CFG2(spi_base)   MMIO32((spi_base) + 0x0C)
#define SPI2S_IER(spi_base)   MMIO32((spi_base) + 0x10)
#define SPI2S_SR(spi_base)   MMIO32((spi_base) + 0x14)
#define SPI2S_IFCR(spi_base)   MMIO32((spi_base) + 0x18)
#define SPI2S_TXDR(spi_base)   MMIO32((spi_base) + 0x20)
#define SPI2S_TXDR8(spi_base)   MMIO8((spi_base) + 0x20)
#define SPI2S_RXDR(spi_base)   MMIO32((spi_base) + 0x30)
#define SPI2S_CRCPOLY(spi_base)   MMIO32((spi_base) + 0x40)
#define SPI2S_TXCRC(spi_base)   MMIO32((spi_base) + 0x44)
#define SPI2S_RXCRC(spi_base)   MMIO32((spi_base) + 0x48)
#define SPI2S_UDRDR(spi_base)   MMIO32((spi_base) + 0x4C)
#define SPI_I2SCFGR(spi_base)   MMIO32((spi_base) + 0x50)
/**@}*/

/** @defgroup spi_control_reg1_bits SPI2S_CR1 Definitions
@ingroup spi_defines
@{*/
#define SPI2S_CR1_IOLOCK    BIT16
#define SPI2S_CR1_TCRCINI   BIT15
#define SPI2S_CR1_RCRCINI   BIT14
#define SPI2S_CR1_CRC33_17  BIT13
#define SPI2S_CR1_SSI       BIT12
#define SPI2S_CR1_HDDIR     BIT11
#define SPI2S_CR1_CSUSP     BIT10
#define SPI2S_CR1_CSTART    BIT9
#define SPI2S_CR1_MASRX     BIT8
#define SPI2S_CR1_SPE       BIT0
/**@}*/

/** @defgroup spi_config_reg1_bits SPI2S_CFG1 Definitions
@ingroup spi_defines
@{*/
#define SPI_CFG1_MBR_MCLK_DIV_2       0x0
#define SPI_CFG1_MBR_MCLK_DIV_4       0x1
#define SPI_CFG1_MBR_MCLK_DIV_8       0x2
#define SPI_CFG1_MBR_MCLK_DIV_16      0x3
#define SPI_CFG1_MBR_MCLK_DIV_32      0x4
#define SPI_CFG1_MBR_MCLK_DIV_64      0x5
#define SPI_CFG1_MBR_MCLK_DIV_128     0x6
#define SPI_CFG1_MBR_MCLK_DIV_256     0x7
#define SPI_CFG1_CRCSIZE_BITS(n)      ((n) - 1)
#define SPI_CFG1_UDRDET_BEGIN_DATA    0
#define SPI_CFG1_UDRDET_END_DATA      1
#define SPI_CFG1_UDRDET_BEGIN_SS      2
#define SPI_CFG1_UDRCFG_CONST_PT      0
#define SPI_CFG1_UDRCFG_LAST_RX       1
#define SPI_CFG1_UDRCFG_LAST_TX       2
#define SPI_CFG1_FTHLV(n)             ((n) - 1)
#define SPI_CFG1_DSIZE(n)             ((n) - 1)

#define SPI_CFG1_MBR_SHIFT            28
#define SPI_CFG1_CRCEN                BIT22
#define SPI_CFG1_CRCSIZE_SHIFT        16
#define SPI_CFG1_TXDMAEN              BIT15
#define SPI_CFG1_RXDMAEN              BIT14
#define SPI_CFG1_UDRDET_SHIFT         11
#define SPI_CFG1_UDRCFG_SHIFT         9
#define SPI_CFG1_FTHLV_SHIFT          5
/**@}*/

/** @defgroup spi_config_reg2_bits SPI2S_CFG2 Definitions
@ingroup spi_defines
@{*/
#define SPI_CFG2_SP_MOTOROLA          0
#define SPI_CFG2_SP_TI                1
#define SPI_CFG2_COMM_FULLDUPLEX      0
#define SPI_CFG2_COMM_SIMPLEX_TX      1
#define SPI_CFG2_COMM_SIMPLEX_RX      2
#define SPI_CFG2_COMM_HALFDUPLEX      3
#define SPI_CFG2_COMM_MASK            3
#define SPI_CFG2_MIDI_CLK(n)          (n)
#define SPI_CFG2_MSSI_CLK(n)          (n)

#define SPI_CFG2_AFCNTR               BIT31
#define SPI_CFG2_SSOM                 BIT30
#define SPI_CFG2_SSOE                 BIT29
#define SPI_CFG2_SSIOP                BIT28
#define SPI_CFG2_SSM                  BIT26
#define SPI_CFG2_CPOL                 BIT25
#define SPI_CFG2_CPHA                 BIT24
#define SPI_CFG2_LSBFRST              BIT23
#define SPI_CFG2_MASTER               BIT22
#define SPI_CFG2_SP_SHIFT             19
#define SPI_CFG2_COMM_SHIFT           17
#define SPI_CFG2_IOSWP                BIT15
#define SPI_CFG2_MIDI_SHIFT           4
/**@}*/

/** @defgroup spi_interuptenable_reg_bits SPI2S_IER Definitions
@ingroup spi_defines
@{*/
#define SPI2S_IER_TSERFIE       BIT10
#define SPI2S_IER_MODFIE        BIT9
#define SPI2S_IER_TIFREIE       BIT8
#define SPI2S_IER_CRCEIE        BIT7
#define SPI2S_IER_OVRIE         BIT6
#define SPI2S_IER_UDRIE         BIT5
#define SPI2S_IER_TXTFIE        BIT4
#define SPI2S_IER_EOTIE         BIT3
#define SPI2S_IER_DXPIE         BIT2
#define SPI2S_IER_TXPIE         BIT1
#define SPI2S_IER_RXPIE         BIT0
/**@}*/

/** @defgroup spi_status_reg_bits SPI2S_SR Definitions
@ingroup spi_defines
@{*/
#define SPI2S_SR_RXPLVL_MASK    0x3

#define SPI2S_SR_CTSIZE_SHIFT   16
#define SPI2S_SR_RWNE           BIT15
#define SPI2S_SR_RXPLVL_SHIFT   13
#define SPI2S_SR_TXC            BIT12
#define SPI2S_SR_SUSP           BIT11
#define SPI2S_SR_TSERF          BIT10
#define SPI2S_SR_MODF           BIT9
#define SPI2S_SR_TIFRE          BIT8
#define SPI2S_SR_CRCE           BIT7
#define SPI2S_SR_OVR            BIT6
#define SPI2S_SR_UDR            BIT5
#define SPI2S_SR_TXTF           BIT4
#define SPI2S_SR_EOT            BIT3
#define SPI2S_SR_DXP            BIT2
#define SPI2S_SR_TXP            BIT1
#define SPI2S_SR_RXP            BIT0
/**@}*/

/** @defgroup spi_interuptclear_reg_bits SPI2S_IFCR Definitions
@ingroup spi_defines
@{*/
#define SPI2S_IFCR_SUSPC          BIT11
#define SPI2S_IFCR_TSERFC         BIT10
#define SPI2S_IFCR_MODFC          BIT9
#define SPI2S_IFCR_TIFREC         BIT8
#define SPI2S_IFCR_CRCEC          BIT7
#define SPI2S_IFCR_OVRC           BIT6
#define SPI2S_IFCR_UDRC           BIT5
#define SPI2S_IFCR_TXTFC          BIT4
#define SPI2S_IFCR_EOTC           BIT3
/**@}*/

/** @defgroup spi_i2s_cfg_register SPI_I2S_CFGR
@ingroup spi_defines
@{*/
#define SPI_I2SCFGR_DATALEN_16BIT   0
#define SPI_I2SCFGR_DATALEN_24BIT   1
#define SPI_I2SCFGR_DATALEN_32BIT   2

#define SPI_I2SCFGR_MCKOE           BIT25
#define SPI_I2SCFGR_ODD             BIT24
#define SPI_I2SCFGR_I2SDIV_SHIFT    16
#define SPI_I2SCFGR_DATFMT          BIT14
#define SPI_I2SCFGR_WSINV           BIT13
#define SPI_I2SCFGR_FIXCH           BIT12
#define SPI_I2SCFGR_CKPOL           BIT11
#define SPI_I2SCFGR_CHLEN           BIT10
#define SPI_I2SCFGR_DATALEN_SHIFT   8
#define SPI_I2SCFGR_PCMSYNC         BIT7
#define SPI_I2SCFGR_I2SSTD_SHFT     4
#define SPI_I2SCFGR_I2SCFG_SHIFT    1
#define SPI_I2SCFGR_I2SMOD          BIT0
/**@}*/

/* GPIO Application Programming Interface. */
/** @defgroup spi_api SPI API
 * @ingroup spi_defines
@{*/
BEGIN_DECLS
/**
 * Reset the SPI peripheral.
 * @param[in] spi  SPI device base address to reset.
 */
void spi_reset(uint32_t spi);
/**
 * Enable the SPI peripheral.
 * @param[in] spi  SPI device base address to enable.
 */
void spi_enable(uint32_t spi);
/**
 * Disable the SPI peripheral.
 * @param[in] spi  SPI device base address to disable.
 */
void spi_disable(uint32_t spi);
/**
 * Write data to the SPI device blindly.
 * @param[in] spi  SPI device base address to write data to.
 * @param[in] data  16-bit data word to send (note: bits sent depend on mode).
 */
void spi_write(uint32_t spi, uint32_t data);
/**
 * Read data from SPI peripheral data register.
 * @param[in] spi  SPI device base address to write data to.
 * @return 16-bit data word in the RX data register.
 */
uint32_t spi_read(uint32_t spi);
/**
 * Configure SPI peripheral to transfer LSB first.
 * @param[in] spi  SPI peripheral to configure
 */
void spi_send_lsb_first(uint32_t spi);
/**
 * Configure SPI peripheral to transfer LSB first.
 * @param[in] spi  SPI peripheral to configure
 */
void spi_send_msb_first(uint32_t spi);
/**
 * Configure SPI peripheral to polarity 1 (rising edge)
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_clock_polarity_1(uint32_t spi);
/**
 * Configure SPI peripheral to polarity 0 (falling edge)
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_clock_polarity_0(uint32_t spi);
/**
 * Configure SPI peripheral to phase 1 (sample on trailing edge).
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_clock_phase_1(uint32_t spi);
/**
 * Configure SPI peripheral to phase 0 (sample on leading).
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_clock_phase_0(uint32_t spi);
/**
 * Configure SPI peripheral for full duplex communication.
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_bidirectional_mode(uint32_t spi);
/**
 * Configure SPI peripheral for half duplex communication.
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_halfduplex_mode(uint32_t spi);
/**
 * Configure SPI peripheral for receive only communication.
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_bidirectional_receive_only_mode(uint32_t spi);
/**
 * Configure SPI peripheral for transmit only communication.
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_bidirectional_transmit_only_mode(uint32_t spi);
/**
 * Configure SPI peripheral for Master mode (i.e. generate clock and drive MOSI).
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_master_mode(uint32_t spi);
/**
 * Configure SPI peripheral for Slave mode (i.e. receive clock, drive MISO).
 * @param[in] spi  SPI peripheral to configure
 */
void spi_set_slave_mode(uint32_t spi);


END_DECLS

/**@}*/
#endif  /* INCLUDE_LIBOPENCM3_STM32_H7_SPI_H_ */
