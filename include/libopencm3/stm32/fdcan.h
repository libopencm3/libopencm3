/** @defgroup fdcan_defines FDCAN defines
@ingroup STM32H7_defines
@brief <b>libopencm3 Defined Constants and Types for STM32 FDCAN </b>
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

#ifndef LIBOPENCM3_STM32_FDCAN_H
#define LIBOPENCM3_STM32_FDCAN_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/**@{
 * @defgroup can_reg_base CAN register base address
 * @ingroup can_defines
 * @{*/
#define FDCAN1			FDCAN1_BASE
#define FDCAN2			FDCAN2_BASE
/**@}*/

/** @defgroup can_registers CAN Register Macros
 * @ingroup can_defines
 * @{*/
/** FDCAN core release register (FDCAN_CREL) */
#define FDCAN_CRELR(fdcan_base)	MMIO32((fdcan_base) + 0x0000)
/** FDCAN Endian register (FDCAN_ENDN) */
#define FDCAN_ENDNR(fdcan_base)		MMIO32((fdcan_base) + 0x0004)
/** FDCAN data bit timing and prescaler register (FDCAN_DBTP) */
#define FDCAN_DBTPR(fdcan_base) 	MMIO32((fdcan_base) + 0x000C)
/** FDCAN test register (FDCAN_TEST)*/
#define FDCAN_TESTR(fdcan_base) 	MMIO32((fdcan_base) + 0x0010)
/** FDCAN RAM watchdog register (FDCAN_RWD) */
#define FDCAN_RWDR(fdcan_base) 		MMIO32((fdcan_base) + 0x0014)
/** FDCAN CC control register (FDCAN_CCCR) */
#define FDCAN_CCCRR(fdcan_base) 	MMIO32((fdcan_base) + 0x0018)
/** FDCAN nominal bit timing and prescaler register (FDCAN_NBTP) */
#define FDCAN_NBTPR(fdcan_base) 	MMIO32((fdcan_base) + 0x001C)
/** FDCAN timestamp counter configuration register (FDCAN_TSCC) */
#define FDCAN_TSCCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0020)
/** FDCAN timestamp counter value register (FDCAN_TSCV) */
#define FDCAN_TSCVR(fdcan_base) 	MMIO32((fdcan_base) + 0x0024)
/** FDCAN timeout counter configuration register (FDCAN_TOCC) */
#define FDCAN_TOCCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0028)
/** FDCAN timeout counter value register (FDCAN_TOCV) */
#define FDCAN_TOCVR(fdcan_base) 	MMIO32((fdcan_base) + 0x002C)
/** FDCAN error counter register (FDCAN_ECR) */
#define FDCAN_ECRR(fdcan_base) 		MMIO32((fdcan_base) + 0x0040)
/** FDCAN protocol status register (FDCAN_PSR) */
#define FDCAN_PSRR(fdcan_base) 		MMIO32((fdcan_base) + 0x0044)
/** FDCAN transmitter delay compensation register (FDCAN_TDCR) */
#define FDCAN_TDCRR(fdcan_base) 	MMIO32((fdcan_base) + 0x0048)
/** FDCAN interrupt register (FDCAN_IR) */
#define FDCAN_IRR(fdcan_base) 		MMIO32((fdcan_base) + 0x0050)
/** FDCAN interrupt enable register (FDCAN_IE) */
#define FDCAN_IER(fdcan_base) 		MMIO32((fdcan_base) + 0x0054)
/** FDCAN interrupt line select register (FDCAN_ILS) */
#define FDCAN_ILSR(fdcan_base) 		MMIO32((fdcan_base) + 0x0058)
/** FDCAN interrupt line enable register (FDCAN_ILE) */
#define FDCAN_ILER(fdcan_base) 		MMIO32((fdcan_base) + 0x005C)
/** FDCAN global filter configuration register (FDCAN_GFC) */
#define FDCAN_GFCR(fdcan_base) 		MMIO32((fdcan_base) + 0x0080)
/** FDCAN standard ID filter configuration register (FDCAN_SIDFC) */
#define FDCAN_SIDFCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0084)
/** FDCAN extended ID and mask register (FDCAN_XIDAM) */
#define FDCAN_XIDFCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0088)
/** FDCAN extended ID and mask register (FDCAN_XIDAM) */
#define FDCAN_XIDAMR(fdcan_base) 	MMIO32((fdcan_base) + 0x0090)
/** FDCAN high priority message status register (FDCAN_HPMS) */
#define FDCAN_HPMSR(fdcan_base) 	MMIO32((fdcan_base) + 0x0094)
/** FDCAN new data 1 register (FDCAN_NDAT1) */
#define FDCAN_NDAT1R(fdcan_base) 	MMIO32((fdcan_base) + 0x0098)
/** FDCAN new data 2 register (FDCAN_NDAT2) */
#define FDCAN_NDAT2R(fdcan_base) 	MMIO32((fdcan_base) + 0x009C)
/** FDCAN Rx FIFO 0 configuration register (FDCAN_RXF0C) */
#define FDCAN_RXF0CR(fdcan_base) 	MMIO32((fdcan_base) + 0x00A0)
/** FDCAN Rx FIFO 0 status register (FDCAN_RXF0S) */
#define FDCAN_RXF0SR(fdcan_base) 	MMIO32((fdcan_base) + 0x00A4)
/** FDCAN Rx FIFO 0 acknowledge register (FDCAN_RXF0A) */
#define FDCAN_RXF0AR(fdcan_base) 	MMIO32((fdcan_base) + 0x00A8)
/** FDCAN Rx buffer configuration register (FDCAN_RXBC) */
#define FDCAN_RXBCR(fdcan_base) 	MMIO32((fdcan_base) + 0x00AC)
/** FDCAN Rx FIFO 1 configuration register (FDCAN_RXF1C) */
#define FDCAN_RXF1CR(fdcan_base) 	MMIO32((fdcan_base) + 0x00B0)
/** FDCAN Rx FIFO 1 status register (FDCAN_RXF1S) */
#define FDCAN_RXF1SR(fdcan_base) 	MMIO32((fdcan_base) + 0x00B4)
/** FDCAN Rx FIFO 1 acknowledge register (FDCAN_RXF1A) */
#define FDCAN_RXF1AR(fdcan_base) 	MMIO32((fdcan_base) + 0x00B8)
/** FDCAN Rx buffer element size configuration register (FDCAN_RXESC) */
#define FDCAN_RXESCR(fdcan_base) 	MMIO32((fdcan_base) + 0x00BC)
/** FDCAN Tx buffer configuration register (FDCAN_TXBC) */
#define FDCAN_TXBCR(fdcan_base) 	MMIO32((fdcan_base) + 0x00C0)
/** FDCAN Tx FIFO/queue status register (FDCAN_TXFQS) */
#define FDCAN_TXFQSR(fdcan_base) 	MMIO32((fdcan_base) + 0x00C4)
/** FDCAN Tx buffer element size configuration register (FDCAN_TXESC) */
#define FDCAN_TXESCR(fdcan_base) 	MMIO32((fdcan_base) + 0x00C8)
/** FDCAN Tx buffer request pending register (FDCAN_TXBRP) */
#define FDCAN_TXBRPR(fdcan_base) 	MMIO32((fdcan_base) + 0x00CC)
/** FDCAN Tx buffer add request register (FDCAN_TXBAR) */
#define FDCAN_TXBARR(fdcan_base) 	MMIO32((fdcan_base) + 0x00D0)
/** FDCAN Tx buffer cancellation request register (FDCAN_TXBCR) */
#define FDCAN_TXBCRR(fdcan_base) 	MMIO32((fdcan_base) + 0x00D4)
/** FDCAN Tx buffer transmission occurred register (FDCAN_TXBTO) */
#define FDCAN_TXBTOR(fdcan_base) 	MMIO32((fdcan_base) + 0x00D8)
/** FDCAN Tx buffer cancellation finished register (FDCAN_TXBCF) */
#define FDCAN_TXBCFR(fdcan_base) 	MMIO32((fdcan_base) + 0x00DC)
/** FDCAN Tx buffer transmission interrupt enable register (FDCAN_TXBTIE) */
#define FDCAN_TXBTIER(fdcan_base) 	MMIO32((fdcan_base) + 0x00E0)
/** FDCAN Tx buffer cancellation finished interrupt enable register (FDCAN_ TXBCIE) */
#define FDCAN_TXBCIER(fdcan_base) 	MMIO32((fdcan_base) + 0x00E4)
/** FDCAN Tx event FIFO configuration register (FDCAN_TXEFC) */
#define FDCAN_TXEFCR(fdcan_base) 	MMIO32((fdcan_base) + 0x00F0)
/** FDCAN Tx event FIFO status register (FDCAN_TXEFS) */
#define FDCAN_TXEFSR(fdcan_base) 	MMIO32((fdcan_base) + 0x00F4)
/** FDCAN Tx event FIFO acknowledge register (FDCAN_TXEFA) */
#define FDCAN_TXEFAR(fdcan_base) 	MMIO32((fdcan_base) + 0x00F8)
/** FDCAN TT trigger memory configuration register (FDCAN_TTTMC) */
#define FDCAN_TTTMCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0100)
/** FDCAN TT reference message configuration register (FDCAN_TTRMC) */
#define FDCAN_TTRMCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0104)
/** FDCAN TT operation configuration register (FDCAN_TTOCF) */
#define FDCAN_TTOCFR(fdcan_base) 	MMIO32((fdcan_base) + 0x0108)
/** FDCAN TT matrix limits register (FDCAN_TTMLM) */
#define FDCAN_TTMLMR(fdcan_base) 	MMIO32((fdcan_base) + 0x010C)
/** FDCAN TUR configuration register (FDCAN_TURCF) */
#define FDCAN_TURCFR(fdcan_base) 	MMIO32((fdcan_base) + 0x0110)
/** FDCAN TT operation control register (FDCAN_TTOCN) */
#define FDCAN_TTOCNR(fdcan_base) 	MMIO32((fdcan_base) + 0x0114)
/** FDCAN TT global time preset register (FDCAN_TTGTP) */
#define FDCAN_TTGTPR(fdcan_base) 	MMIO32((fdcan_base) + 0x0118)
/** FDCAN TT time mark register (FDCAN_TTTMK) */
#define FDCAN_TTTMKR(fdcan_base) 	MMIO32((fdcan_base) + 0x011C)
/** FDCAN TT interrupt register (FDCAN_TTIR) */
#define FDCAN_TTIRR(fdcan_base) 	MMIO32((fdcan_base) + 0x0120)
/** FDCAN TT interrupt enable register (FDCAN_TTIE) */
#define FDCAN_TTIER(fdcan_base) 	MMIO32((fdcan_base) + 0x0124)
/** FDCAN TT interrupt line select register (FDCAN_TTILS) */
#define FDCAN_TTILSR(fdcan_base) 	MMIO32((fdcan_base) + 0x0128)
/** FDCAN TT operation status register (FDCAN_TTOST) */
#define FDCAN_TTOSTR(fdcan_base) 	MMIO32((fdcan_base) + 0x012C)
/** FDCAN TUR numerator actual register (FDCAN_TURNA) */
#define FDCAN_TURNAR(fdcan_base) 	MMIO32((fdcan_base) + 0x0130)
/** FDCAN TT local and global time register (FDCAN_TTLGT) */
#define FDCAN_TTLGTR(fdcan_base) 	MMIO32((fdcan_base) + 0x0134)
/** FDCAN TT cycle time and count register (FDCAN_TTCTC) */
#define FDCAN_TTCTCR(fdcan_base) 	MMIO32((fdcan_base) + 0x0138)
/** FDCAN TT capture time register (FDCAN_TTCPT) */
#define FDCAN_TTCPTR(fdcan_base) 	MMIO32((fdcan_base) + 0x013C)
/** FDCAN TT cycle sync mark register (FDCAN_TTCSM) */
#define FDCAN_TTCSMR(fdcan_base) 	MMIO32((fdcan_base) + 0x0140)
/** FDCAN TT trigger select register (FDCAN_TTTS) */
#define FDCAN_TTTSR(fdcan_base) 	MMIO32((fdcan_base) + 0x0300)

/** CCU Registers */
/** Clock calibration unit core release register (FDCAN_CCU_CREL) */
#define FDCAN_CCU_CRELR				MMIO32((CAN_CCU_BASE) + 0x0000)
/** Calibration configuration register (FDCAN_CCU_CCFG) */
#define FDCAN_CCU_CCFGR				MMIO32((CAN_CCU_BASE) + 0x0004)
/** Calibration status register (FDCAN_CCU_CSTAT) */
#define FDCAN_CCU_CSTATR			MMIO32((CAN_CCU_BASE) + 0x0008)
/** Calibration watchdog register (FDCAN_CCU_CWD) */
#define FDCAN_CCU_CWDR				MMIO32((CAN_CCU_BASE) + 0x000C)
/** Clock calibration unit interrupt register (FDCAN_CCU_IR) */
#define FDCAN_CCU_IRR				MMIO32((CAN_CCU_BASE) + 0x0010)
/** Clock calibration unit interrupt enable register (FDCAN_CCU_IE) */
#define FDCAN_CCU_IER				MMIO32((CAN_CCU_BASE) + 0x0014)
/**@}*/


/** @defgroup fdcan_peripherial_api FDCAN Peripheral API
 * @ingroup peripheral_apis
 * @{*/
BEGIN_DECLS
/**
 * Enable FDCAN interface specified.
 * @param[in] fdcan  FDCAN device to enable.
 */
void fdcan_enable(uint32_t fdcan);
/**
 * Disable FDCAN interface specified.
 * @param[in] fdcan  FDCAN device to disable.
 */
void fdcan_disable(uint32_t fdcan);


END_DECLS
/**@}*/
/**@}*/
#endif
