/** @addtogroup spi_defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SPI.H
The order of header inclusion is important. spi.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_SPI_H
/** @endcond */
#pragma once

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup spi_reg_base SPI Register base address
@ingroup spi_defines

@{*/
#define SPI1				SPI1_BASE
#define SPI2				SPI2_BASE
#define SPI3				SPI3_BASE
#define SPI4				SPI4_BASE
#define SPI5				SPI5_BASE
#define SPI6				SPI6_BASE
/**@}*/

/* --- SPI registers ------------------------------------------------------- */
/** @defgroup spi_registers SPI and I2S Registers
@{*/
#define SPI2S_CR1(spi_base)       MMIO32((spi_base) + 0x000)
#define SPI_CR2(spi_base)         MMIO32((spi_base) + 0x004)
#define SPI_CFG1(spi_base)        MMIO32((spi_base) + 0x008)
#define SPI_CFG2(spi_base)        MMIO32((spi_base) + 0x00c)
#define SPI2S_IER(spi_base)       MMIO32((spi_base) + 0x010)
#define SPI2S_SR(spi_base)        MMIO32((spi_base) + 0x014)
#define SPI2S_IFCR(spi_base)      MMIO32((spi_base) + 0x018)
#define SPI2S_TXDR(spi_base)      MMIO32((spi_base) + 0x020)
#define SPI2S_TXDR8(spi_base)     MMIO8((spi_base) + 0x020)
#define SPI2S_RXDR(spi_base)      MMIO32((spi_base) + 0x030)
#define SPI2S_RXDR8(spi_base)     MMIO8((spi_base) + 0x030)
#define SPI_CRCPOLY(spi_base)     MMIO32((spi_base) + 0x040)
#define SPI_TXCRC(spi_base)       MMIO32((spi_base) + 0x044)
#define SPI_RXCRC(spi_base)       MMIO32((spi_base) + 0x048)
#define SPI_UDRDR(spi_base)       MMIO32((spi_base) + 0x04c)
#define SPI_I2SCFGR(spi_base)     MMIO32((spi_base) + 0x050)
#define SPIX_I2S_HWCFGR(spi_base) MMIO32((spi_base) + 0x3f0)
#define SPIX_VERR(spi_base)       MMIO32((spi_base) + 0x3f4)
#define SPIX_IPIDR(spi_base)      MMIO32((spi_base) + 0x3f8)
#define SPIX_SIDR(spi_base)       MMIO32((spi_base) + 0x3fc)
/**@}*/

/** @defgroup spi2s_cr_values SPI2S_CR1 Values
 * @ingroup spi_registers
@{*/
#define SPI2S_CR1_SPE         (1 << 0) /* SPI Enable */
#define SPI2S_CR1_MASRX       (1 << 8) /* Master automatic spi suspension */
#define SPI2S_CR1_CSTART      (1 << 9) /* SPI or I2S/PCM Communication start */
#define SPI2S_CR1_CSUSP       (1 << 10) /* SPI Communication suspended at end of current frame */
#define SPI2S_CR1_HDDIR       (1 << 11) /* SPI Half-Duplex Direction */
#define SPI2S_CR1_SSI         (1 << 12) /* Internal SS input level */
#define SPI2S_CR1_CRC33_17    (1 << 13) /* 32 bit CRC configuration */
#define SPI2S_CR1_RCRCINI     (1 << 14) /* CRC initialization pattern for receiver */
#define SPI2S_CR1_TCRCINI     (1 << 15) /* CRC initialization pattern for transmitter */
#define SPI2S_CR1_IOLOCK      (1 << 16) /* Lock Alternate functions of IOs */
/**@}*/

/** @defgroup spi_cr2_values SPI_CR2 Values
 * @ingroup spi_registers
@{*/
#define SPI_CR2_TSIZE_MASK  0xffff
#define SPI_CR2_TSIZE_SHIFT 0
#define SPI_CR2_TSER_MASK   0xffff
#define SPI_CR2_TSER_SHIFT  16
/**@}*/

/** @defgroup spi_cfg1_values SPI_CFG1 Values
 * @ingroup spi_registers
@{*/
#define SPI_CFG1_DSIZE_MASK    0x1f
#define SPI_CFG1_DSIZE_SHIFT   0
#define SPI_CFG1_FTHLV_MASK    0x0f
#define SPI_CFG1_FTHLV_SHIFT   5
#define SPI_CFG1_UDRCFG_MASK   0x03
#define SPI_CFG1_UDRCFG_SHIFT  9
#define SPI_CFG1_UDRDET_MASK   0x03
#define SPI_CFG1_UDRDET_SHIFT  11
#define SPI_CFG1_RXDMAEN       (1 << 14)
#define SPI_CFG1_TXDMAEN       (1 << 15)
#define SPI_CFG1_CRCSIZE_MASK  0x1f
#define SPI_CFG1_CRCSIZE_SHIFT 16
#define SPI_CFG1_CRCEN         (1 << 22)
#define SPI_CFG1_MBR_MASK      0x07
#define SPI_CFG1_MBR_SHIFT     28
/**@}*/

/** @defgroup spi_baudrate SPI peripheral baud rates
@ingroup spi_cfg1_values
@{*/
#define SPI_CFG1_MBR_MCK_DIV2   (0 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV4   (1 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV8   (2 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV16  (3 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV32  (4 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV64  (5 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV128 (6 << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MCK_DIV256 (7 << SPI_CFG1_MBR_SHIFT)
/**@}*/

/** @defgroup spi_cfg2_values SPI_CFG2 Values
 * @ingroup spi_registers
@{*/
#define SPI_CFG2_MSSI_MASK   0x0f
#define SPI_CFG2_MSSI_SHIFT  0
#define SPI_CFG2_MIDI_MASK   0x0f
#define SPI_CFG2_MIDI_SHIFT  4
#define SPI_CFG2_IOSWP       (1 << 15) /* MISO/MOSI Swap */
#define SPI_CFG2_COMM_MASK   (0x03)
#define SPI_CFG2_COMM_SHIFT  17
#define SPI_CFG2_COMM_FD     0 /* Full Duplex */
#define SPI_CFG2_COMM_TX     1 /* Simple Transmitter */
#define SPI_CFG2_COMM_RX     2 /* Simple Receiver */
#define SPI_CFG2_COMM_HD     3 /* Half Duplex */
#define SPI_CFG2_SP_MASK     0x07
#define SPI_CFG2_SP_SHIFT    19
#define SPI_CFG2_SP_MOTOROLA 0
#define SPI_CFG2_SP_TI       1
#define SPI_CFG2_MASTER      (1 << 22)
#define SPI_CFG2_LSBFRST     (1 << 23)
#define SPI_CFG2_CKPHA       (1 << 24) /* Clock Phase */
#define SPI_CFG2_CPOL        (1 << 25) /* Clock Polarity */
#define SPI_CFG2_SSM         (1 << 26) /* SS Software Management */
#define SPI_CFG2_SSIOP       (1 << 28) /* SS Polarity: 0=low level is active */
#define SPI_CFG2_SSOE        (1 << 29) /* SS Output Enable */
#define SPI_CFG2_SSOM        (1 << 30) /* Interleave SPI frames with SS non-active if MIDI > 1 */
#define SPI_CFG2_AFCNTR      (1 << 31) /* Alternate Function GPIO control */
/**@}*/

/** @defgroup spi_cpol SPI Clock Polarity
 * @ingroup spi_cfg2_values
@{*/
#define SPI_CFG2_CPOL_CLK_TO_0_WHEN_IDLE (0 << 25)
#define SPI_CFG2_CPOL_CLK_TO_1_WHEN_IDLE (1 << 25)
/**@}*/

/** @defgroup spi_cpha SPI Clock Phase
 * @ingroup spi_cfg2_values
@{*/
#define SPI_CFG2_CPHA_CLK_TRANSITION_1 (0 << 24)
#define SPI_CFG2_CPHA_CLK_TRANSITION_2 (1 << 24)
/**@}*/

/** @defgroup spi_lsbfirst SPI lsb/msb first
 * @ingroup spi_cfg2_values
@{*/
#define SPI_CFG2_LSBFIRST (1 << 23)
#define SPI_CFG2_MSBFIRST (0 << 23)
/**@}*/


/** @defgroup spi2s_ier_values SPI2S_IER Values
 * @ingroup spi_registers
@{*/
#define SPI2S_IER_RXPIE   (1 << 0) /* RXP Interrupt Enable */
#define SPI2S_IER_TXPIE   (1 << 1) /* TXP Interrupt Enable */
#define SPI2S_IER_DXPIE   (1 << 2) /* DXP Interrupt Enable */
#define SPI2S_IER_EOTIE   (1 << 3) /* EOT, SUSP, TXC Interrupt Enable */
#define SPI2S_IER_TXTFIE  (1 << 4) /* TXTF Interrupt Enable */
#define SPI2S_IER_UDRIE   (1 << 5) /* UDR Interrupt Enable */
#define SPI2S_IER_OVRIE   (1 << 6) /* OVR Interrupt Enable */
#define SPI2S_IER_CRCEIE  (1 << 7) /* CRC Error Interrupt Enable */
#define SPI2S_IER_TIFREIE (1 << 8) /* TIFRE Interrupt Enable */
#define SPI2S_IER_MODFIE  (1 << 9) /* Mode Fault Interrupt Enable */
#define SPI2S_IER_TSERFIE (1 << 10) /* Additional Number of Transaction Reload Interrupt Enable */
/**@}*/

/** @defgroup spi2s_sr_values SPI2S_SR Values
 * @ingroup spi_registers
@{*/
#define SPI2S_SR_RXP          (1 << 0) /* RX Packet Available */
#define SPI2S_SR_TXP          (1 << 1) /* TX Packet Space Available */
#define SPI2S_SR_DXP          (1 << 2) /* Duplex Packet */
#define SPI2S_SR_EOT          (1 << 3) /* End Of Transfer */
#define SPI2S_SR_TXTF         (1 << 4) /* Transmission Transfer Filled */
#define SPI2S_SR_UDR          (1 << 5) /* Underrun at slave transmission mode */
#define SPI2S_SR_OVR          (1 << 6) /* Overrun */
#define SPI2S_SR_CRCE         (1 << 7) /* CRC Error */
#define SPI2S_SR_TIFRE        (1 << 8) /* TI Frame Format Error */
#define SPI2S_SR_MODF         (1 << 9) /* Mode Fault */
#define SPI2S_SR_TSERF        (1 << 10) /* Additionnal Number of SPI Data to be Transacted was Reload */
#define SPI2S_SR_SUSP         (1 << 11) /* Suspend */
#define SPI2S_SR_TXC          (1 << 12) /* TxFifo Transmission Complete */
#define SPI2S_SR_RXPLVL_SHIFT 13
#define SPI2S_SR_RXPLVL_MASK  0x03
#define SPI2S_SR_RXWNE        (1 << 15) /* RxFifo Word Not Empty */
#define SPI2S_SR_CTSIZE_SHIFT 16
#define SPI2S_SR_CTSIZE_MASK  (0xffff)
/**@}*/

/** @defgroup spi2s_ifcr_values SPI2S_IFCR Values
 * @ingroup spi_registers
@{*/
#define SPI2S_IFCR_EOTC   (1 << 3) /* End of Transfer Flag Clear */
#define SPI2S_IFCR_TXTFC  (1 << 4) /* Transmission Transfer Filled Flag Clear */
#define SPI2S_IFCR_UDRC   (1 << 5) /* Underrun Flag Clear */
#define SPI2S_IFCR_OVRC   (1 << 6) /* Overrun Flag Clear */
#define SPI2S_IFCR_CRCEC  (1 << 7) /* CRC Error Flag Clear */
#define SPI2S_IFCR_TIFREC (1 << 8) /* TI Frame Format Error Flag Clear */
#define SPI2S_IFCR_MODEFC (1 << 9) /* Mode Fault Flag Clear */
#define SPI2S_IFCR_TSERFC (1 << 10) /* TSERF Flag Clear */
#define SPI2S_IFCR_SUSPC  (1 << 11) /* Suspend Flag Clear */
/**@}*/

/** @defgroup spi_i2scfgr_values SPI_I2SCFGR Values
 * @ingroup spi_registers
@{*/
#define SPI_I2SCFGR_I2SMOD           (1 << 0) /* I2S/PCM Mode Selected */
#define SPI_I2SCFGR_I2SCFG_SHIFT     1
#define SPI_I2SCFGR_I2SCFG_MASK      0x07
#define SPI_I2SCFGR_I2SCFG_SLAVE_TX  0 /* Slave Transmit */
#define SPI_I2SCFGR_I2SCFG_SLAVE_RX  1 /* Slave Receive */
#define SPI_I2SCFGR_I2SCFG_MASTER_TX 2 /* Master Transmit */
#define SPI_I2SCFGR_I2SCFG_MASTER_RX 3 /* Master Receive */
#define SPI_I2SCFGR_I2SCFG_SLAVE_FD  4 /* Slave Full Duplex */
#define SPI_I2SCFGR_I2SCFG_MASTER_FD 5 /* Master Full Duplex */
#define SPI_I2SCFGR_I2SSTD_SHIFT     4
#define SPI_I2SCFGR_I2SSTD_MASK      0x03
#define SPI_I2SCFGR_I2SSTD_PHILIPS   0 /* I2S Philips Standard */
#define SPI_I2SCFGR_I2SSTD_MSB_LEFT  1 /* MSB Left Justified */
#define SPI_I2SCFGR_I2SSTD_LSB_RIGHT 2 /* LSB Right Justified */
#define SPI_I2SCFGR_I2SSTD_PCM       3 /* PCM Standard */
#define SPI_I2SCFGR_PCMSYNC          (1 << 7) /* Long Frame Synchronisation */
#define SPI_I2SCFGR_DATLEN_SHIFT     8
#define SPI_I2SCFGR_DATLEN_MASK      0x03
#define SPI_I2SCFGR_DATLEN_16BIT     0
#define SPI_I2SCFGR_DATLEN_24BIT     1
#define SPI_I2SCFGR_DATLEN_32BIT     2
#define SPI_I2SCFGR_CHLEN_32BIT      (1 << 10) /* 32 bit wide channel. Relevant only if DATLEN is 0 */
#define SPI_I2SCFGR_CHLEN_16BIT      0 /* 16 bit wide channel. Relevant only if DATLEN is 0 */
#define SPI_I2SCFGR_CKPOL            (1 << 11) /* Serial Audio Clock Polarity */
#define SPI_I2SCFGR_CKPOL_RISING     (1 << 11) /* Data changes at rising edge, latched at falling edge */
#define SPI_I2SCFGR_CKPOL_FALLING    0 /* Data changes at falling edge, latched at rising edge */
#define SPI_I2SCFGR_FIXCH            (1 << 12) /* Fixed Channel Length in Slave */
#define SPI_I2SCFGR_WSINV            (1 << 13) /* Word Select Inversion */
#define SPI_I2SCFGR_DATFMT           (1 << 14) /* Data Format */
#define SPI_I2SCFGR_DATFMT_RIGHT     0 /* Data Format Right Aligned*/
#define SPI_I2SCFGR_DATFMT_LEFT      (1 << 14) /* Data Format Right Aligned*/
#define SPI_I2SCFGR_I2SDIV_SHIFT     16
#define SPI_I2SCFGR_I2SDIV_MASK      0xff
#define SPI_I2SCFGR_ODD              (1 << 24) /* Odd factor for the prescaler */
#define SPI_I2SCFGR_I2SDIV_ODD       (1 << 24)
#define SPI_I2SCFGR_I2SDIV_EVEN      0
#define SPI_I2SCFGR_MCKOE            (1 << 25) /* Master Clock Output Enable */
/**@}*/

/* --- Function prototypes ------------------------------------------------- */
BEGIN_DECLS

void spi_reset(uint32_t spi_peripheral);
void spi_enable(uint32_t spi);
void spi_disable(uint32_t spi);

int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
		uint32_t lsbfirst);
void spi_set_nss_high(uint32_t spi);
void spi_set_nss_low(uint32_t spi);
void spi_disable_software_slave_management(uint32_t spi);
void spi_enable_software_slave_management(uint32_t spi);
void spi_write(uint32_t spi, uint32_t data);
void spi_write8(uint32_t spi, uint8_t data);
void spi_send(uint32_t spi, uint32_t data);
void spi_send8(uint32_t spi, uint8_t data);
uint8_t spi_read8(uint32_t spi);
uint32_t spi_read(uint32_t spi);
uint32_t spi_xfer(uint32_t spi, uint32_t data);
void spi_set_data_size(uint32_t spi, uint16_t data_s);
int spi_set_transfer_size(uint32_t spi, uint16_t tsize, uint16_t tser);
void spi_set_fifo_thresh_lvl(uint32_t spi, uint8_t n);
void spi_set_interdata_idleness(uint32_t spi, uint8_t midi);
void spi_set_communication_mode(uint32_t spi, uint8_t comm);
void spi_clear_flags(uint32_t spi, uint32_t flags);
void spi_enable_interrupts(uint32_t spi, uint32_t flags);
void spi_disable_interrupts(uint32_t spi, uint32_t flags);
END_DECLS

/** @cond */
#else
#warning "spi_common_v3.h should not be included explicitly, only via spi.h"
#endif
/** @endcond */
/**@}*/

