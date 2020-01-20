/** @defgroup fdcan_defines FDCAN defines
 * @ingroup STM32_defines
 * @brief <b>libopencm3 Defined Constants and Types for STM32 FDCAN </b>
 * @version 1.0.0
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Matt Walker <m@allocor.tech>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA FDCAN.H
 * The order of header inclusion is important. fdcan.h includes the device
 * specific memorymap.h header before including this header file. */

/** @cond */
#ifdef LIBOPENCM3_STM32_FDCAN_H
/** @endcond */

#include <libopencm3/can/can_bit_timing.h>

#ifndef LIBOPENCM3_STM32_COMMON_FDCAN_COMMON_H
#define LIBOPENCM3_STM32_COMMON_FDCAN_COMMON_H

/** @defgroup fdcan_registers CAN Register Macros
 * @ingroup fdcan_defines
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

/* CCU Registers */
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

/* -------------------------------------------------------------------------- */
/** @ingroup fdcan_defines  @{ */

/* --- FDCAN_CREL: (FDCAN_CREL) --------------------------------------------- */
/** @{ Core release */
#define FDCAN_CREL_REL_MASK 0xF
#define FDCAN_CREL_REL_SHIFT 28
/** @} */
/** @{ Step of core release */
#define FDCAN_CREL_STEP_MASK 0xF
#define FDCAN_CREL_STEP_SHIFT 24
/** @} */
/** @{ Sub-step of core release */
#define FDCAN_CREL_SUBSTEP_MASK 0xF
#define FDCAN_CREL_SUBSTEP_SHIFT 20
/** @} */
/** @{ Timestamp Year */
#define FDCAN_CREL_YEAR_MASK 0xF
#define FDCAN_CREL_YEAR_SHIFT 16
/** @} */
/** @{ Timestamp Month */
#define FDCAN_CREL_MON_MASK 0xFF
#define FDCAN_CREL_MON_SHIFT 8
/** @} */
/** @{ Timestamp Day */
#define FDCAN_CREL_DAY_MASK 0xFF
#define FDCAN_CREL_DAY_SHIFT 0
/** @} */

/* --- FDCAN_ENDN: FDCAN Endian register ------------------------------------ */
/** Endianness Test value */
#define FDCAN_ENDN_ETV 0x87654321

/* --- FDCAN_DBTP: FDCAN data bit timing and prescaler register ------------- */
/** Transceiver Delay Compensation */
#define FDCAN_DBTP_TDC BIT23
/** @{ Data bitrate prescaler */
#define FDCAN_DBTP_DBRP_MASK 0x1F
#define FDCAN_DBTP_DBRP_SHIFT 16
/** @} */
/** @{ Data time segment before sample point */
#define FDCAN_DBTP_DTSEG1_MASK 0x1F
#define FDCAN_DBTP_DTSEG1_SHIFT 8
/** @} */
/** @{ Data time segment after sample point */
#define FDCAN_DBTP_DTSEG2_MASK 0xF
#define FDCAN_DBTP_DTSEG2_SHIFT 4
/** @} */
/** @{ Synchronization jump width */
#define FDCAN_DBTP_DSJW_MASK 0xF
#define FDCAN_DBTP_DSJW_SHIFT 0
/** @} */

/* --- FDCAN_TEST: (FDCAN_TEST) --------------------------------------------- */
/** Receive pin */
#define FDCAN_TEST_RX BIT7
/** @{ Control of transmit pin */
enum fdcan_test_tx {
	FDCAN_TEST_TX_RESET		= 0,
	FDCAN_TEST_TX_SAMPLE	= 1,
	FDCAN_TEST_TX_DOMINANT	= 2,
	FDCAN_TEST_TX_RECESSIVE	= 3,
	FDCAN_TEST_TX_MASK		= 3,
};
#define FDCAN_TEST_TX_SHIFT 5
/** @} */
/** Loop back mode */
#define FDCAN_TEST_LBCK BIT4

/* --- FDCAN_RWD: FDCAN RAM watchdog register ------------------------------- */
/** @{ Watchdog value */
#define FDCAN_RWD_WDV_MASK 0xFF
#define FDCAN_RWD_WDV_SHIFT 8
/** @} */
/** @{ Watchdog configuration */
#define FDCAN_RWD_WDC_MASK 0xFF
#define FDCAN_RWD_WDC_SHIFT 0
/** @} */

/* --- FDCAN_CCCR: FDCAN CC control register -------------------------------- */
/** Non ISO operation */
#define FDCAN_CCCR_NISO BIT15
/** Pause between transmissions */
#define FDCAN_CCCR_TXP BIT14
/** Edge Filtering during bus Integration */
#define FDCAN_CCCR_EFBI BIT13
/** Protocol exception handling disable */
#define FDCAN_CCCR_PXHD BIT12
/** FDCAN bitrate Switching */
#define FDCAN_CCCR_BRSE BIT9
/** FD operation enable */
#define FDCAN_CCCR_FDOE BIT8
/** Test mode enable */
#define FDCAN_CCCR_TEST BIT7
/** Disable automatic retransmission */
#define FDCAN_CCCR_DAR BIT6
/** Bus monitoring mode */
#define FDCAN_CCCR_MON BIT5
/** Clock stop request */
#define FDCAN_CCCR_CSR BIT4
/** Clock stop acknowledge */
#define FDCAN_CCCR_CSA BIT3
/** ASM restricted operation mode */
#define FDCAN_CCCR_ASM BIT2
/** Configuration change enable */
#define FDCAN_CCCR_CCE BIT1
/** Initialization */
#define FDCAN_CCCR_INIT BIT0

/* --- FDCAN_NBTP: FDCAN nominal bit timing and prescaler register ---------- */
/** @{ Nominal (re)synchronization jump width */
#define FDCAN_NBTP_NSJW_MASK 0x7F
#define FDCAN_NBTP_NSJW_SHIFT 25
/** @} */
/** @{ Bitrate prescaler */
#define FDCAN_NBTP_NBRP_MASK 0x1FF
#define FDCAN_NBTP_NBRP_SHIFT 16
/** @} */
/** @{ Nominal time segment before sample point */
#define FDCAN_NBTP_NTSEG1_MASK 0xFF
#define FDCAN_NBTP_NTSEG1_SHIFT 8
/** @} */
/** @{ Nominal time segment after sample point */
#define FDCAN_NBTP_NTSEG2_MASK 0x7F
#define FDCAN_NBTP_NTSEG2_SHIFT 0
/** @} */

/* --- FDCAN_TSCC: (FDCAN_TSCC) --------------------------------------------- */
/** @{ Timestamp counter prescaler */
#define FDCAN_TSCC_TCP_MASK 0xF
#define FDCAN_TSCC_TCP_SHIFT 16
/** @} */
/** @{ Timestamp select */
enum fdcan_tscc_tss {
	FDCAN_TSCC_TSS_ALWAYS_0	= 0,
	FDCAN_TSCC_TSS_INC_TSC	= 1,
	FDCAN_TSCC_TSS_USE_TIM3	= 2,
	FDCAN_TSCC_TSS_MASK		= 3,
};
#define FDCAN_TSCC_TSS_SHIFT 0
/** @} */

/* --- FDCAN_TSCV: FDCAN timestamp counter value register ------------------- */
/** @{ Timestamp counter */
#define FDCAN_TSCV_TSC_MASK 0xFFFF
#define FDCAN_TSCV_TSC_SHIFT 0
/** @} */

/* --- FDCAN_TOCC: (FDCAN_TOCC) --------------------------------------------- */
/** @{ Timeout period */
#define FDCAN_TOCC_TOP_MASK 0xFFFF
#define FDCAN_TOCC_TOP_SHIFT 16
/** @} */
/** @{ Timeout select */
enum fdcan_tocc_tos {
	FDCAN_TOCC_TOS_CONTINUOUS	= 0,
	FDCAN_TOCC_TOS_TX_EVENT		= 1,
	FDCAN_TOCC_TOS_RX_FIFO_0	= 2,
	FDCAN_TOCC_TOS_RX_FIFO_1	= 3,
	FDCAN_TOCC_TOS_RX_MASK		= 3,
};
#define FDCAN_TOCC_TOS_SHIFT 1
/** @} */
/** Enable timeout counter */
#define FDCAN_TOCC_ETOC BIT0

/* --- FDCAN_TOCV: FDCAN timeout counter value register --------------------- */
/** @{ Timeout counter */
#define FDCAN_TOCV_TOC_MASK 0xFFFF
#define FDCAN_TOCV_TOC_SHIFT 0
/** @} */

/* --- FDCAN_ECR: FDCAN error counter register ------------------------------ */
/** @{ CAN error logging */
#define FDCAN_ECR_CEL_MASK 0xFF
#define FDCAN_ECR_CEL_SHIFT 16
/** @} */
/** Receive error passive */
#define FDCAN_ECR_RP BIT15
/** @{ Receive error counter */
#define FDCAN_ECR_REC_MASK 0x7F
#define FDCAN_ECR_REC_SHIFT 8
/** @} */
/** @{ Transmit error counter */
#define FDCAN_ECR_TEC_MASK 0xFF
#define FDCAN_ECR_TEC_SHIFT 0
/** @} */

/* --- FDCAN_PSR: FDCAN protocol status register ---------------------------- */
/** @{ Transmitter Delay Compensation value */
#define FDCAN_PSR_TDCV_MASK 0x7F
#define FDCAN_PSR_TDCV_SHIFT 16
/** @} */
/** Protocol exception event */
#define FDCAN_PSR_PXE BIT14
/** Received FDCAN message */
#define FDCAN_PSR_REDL BIT13
/** BRS flag of last received FDCAN message */
#define FDCAN_PSR_RBRS BIT12
/** ESI flag of last received FDCAN message */
#define FDCAN_PSR_RESI BIT11
/** @{ Data Last error code */
#define FDCAN_PSR_DLEC_MASK 0x7
#define FDCAN_PSR_DLEC_SHIFT 8
/** @} */
/** Bus_Off status */
#define FDCAN_PSR_BO BIT7
/** Warning status */
#define FDCAN_PSR_EW BIT6
/** Error Passive */
#define FDCAN_PSR_EP BIT5
/** @{ Controller state */
enum fdcan_psr_act {
	FDCAN_PSR_ACT_SYNC	= 0,
	FDCAN_PSR_ACT_IDLE	= 1,
	FDCAN_PSR_ACT_RECV	= 2,
	FDCAN_PSR_ACT_TRANS	= 3,
	FDCAN_PSR_ACT_MASK	= 3,
};
#define FDCAN_PSR_ACT_SHIFT 3
/** @} */
/** @{ Last error code */
enum fdcan_psr_lec {
	FDCAN_PSR_LEC_NONE		= 0x0,
	FDCAN_PSR_LEC_STUFF		= 0x1,
	FDCAN_PSR_LEC_FORM		= 0x2,
	FDCAN_PSR_LEC_ACK		= 0x3,
	FDCAN_PSR_LEC_BIT_1		= 0x4,
	FDCAN_PSR_LEC_BIT_0		= 0x5,
	FDCAN_PSR_LEC_CRC		= 0x6,
	FDCAN_PSR_LEC_NO_CHANGE	= 0x7,
	FDCAN_PSR_LEC_MASK		= 0x7,
};
#define FDCAN_PSR_LEC_SHIFT 0
/** @} */

/* --- FDCAN_TDCR: (FDCAN_TDCR) --------------------------------------------- */
/** @{ Transmitter delay compensation offset */
#define FDCAN_TDCR_TDCO_MASK 0x7F
#define FDCAN_TDCR_TDCO_SHIFT 8
/** @} */
/** @{ Transmitter delay compensation filter window length */
#define FDCAN_TDCR_TDCF_MASK 0x7F
#define FDCAN_TDCR_TDCF_SHIFT 0
/** @} */

/* --- FDCAN_IR: FDCAN interrupt register ----------------------------------- */
/** Access to Reserved address */
#define FDCAN_IR_ARA BIT29
/** Protocol error in data phase (data Bit time is used) */
#define FDCAN_IR_PED BIT28
/** Protocol error in Arbitration phase (Nominal bit time is used) */
#define FDCAN_IR_PEA BIT27
/** Watchdog interrupt */
#define FDCAN_IR_WDI BIT26
/** Bus_Off status */
#define FDCAN_IR_BO BIT25
/** Warning status */
#define FDCAN_IR_EW BIT24
/** Error Passive */
#define FDCAN_IR_EP BIT23
/** Error logging Overflow */
#define FDCAN_IR_ELO BIT22
/** Message stored to dedicated Rx buffer */
#define FDCAN_IR_DRX BIT19
/** Timeout occurred */
#define FDCAN_IR_TOO BIT18
/** Message RAM Access Failure */
#define FDCAN_IR_MRAF BIT17
/** Timestamp wraparound */
#define FDCAN_IR_TSW BIT16
/** Tx event FIFO element Lost */
#define FDCAN_IR_TEFL BIT15
/** Tx event FIFO Full */
#define FDCAN_IR_TEFF BIT14
/** Tx event FIFO Watermark Reached */
#define FDCAN_IR_TEFW BIT13
/** Tx event FIFO New Entry */
#define FDCAN_IR_TEFN BIT12
/** Tx FIFO Empty */
#define FDCAN_IR_TFE BIT11
/** Transmission cancellation finished */
#define FDCAN_IR_TCF BIT10
/** Transmission Completed */
#define FDCAN_IR_TC BIT9
/** High priority message */
#define FDCAN_IR_HPM BIT8
/** Rx FIFO 1 message Lost */
#define FDCAN_IR_RF1L BIT7
/** Rx FIFO 1 Full */
#define FDCAN_IR_RF1F BIT6
/** Rx FIFO 1 Watermark Reached */
#define FDCAN_IR_RF1W BIT5
/** Rx FIFO 1 new message */
#define FDCAN_IR_RF1N BIT4
/** Rx FIFO 0 message Lost */
#define FDCAN_IR_RF0L BIT3
/** Rx FIFO 0 Full */
#define FDCAN_IR_RF0F BIT2
/** Rx FIFO 0 Watermark Reached */
#define FDCAN_IR_RF0W BIT1
/** Rx FIFO 0 New message */
#define FDCAN_IR_RF0N BIT0

/* --- FDCAN_IE: FDCAN interrupt enable register ---------------------------- */
/** Access to Reserved address enable */
#define FDCAN_IE_ARAE BIT29
/** Protocol error in data phase enable */
#define FDCAN_IE_PEDE BIT28
/** Protocol error in Arbitration phase enable */
#define FDCAN_IE_PEAE BIT27
/** Watchdog interrupt enable */
#define FDCAN_IE_WDIE BIT26
/** Bus_Off status */
#define FDCAN_IE_BOE BIT25
/** Warning status interrupt enable */
#define FDCAN_IE_EWE BIT24
/** Error passive interrupt enable */
#define FDCAN_IE_EPE BIT23
/** Error logging overflow interrupt enable */
#define FDCAN_IE_ELOE BIT22
/** Message stored to dedicated Rx buffer interrupt enable */
#define FDCAN_IE_DRXE BIT19
/** Timeout occurred interrupt enable */
#define FDCAN_IE_TOOE BIT18
/** Message RAM access failure interrupt enable */
#define FDCAN_IE_MRAFE BIT17
/** Timestamp wraparound interrupt enable */
#define FDCAN_IE_TSWE BIT16
/** Tx event FIFO element lost interrupt enable */
#define FDCAN_IE_TEFLE BIT15
/** Tx event FIFO full interrupt enable */
#define FDCAN_IE_TEFFE BIT14
/** Tx event FIFO watermark reached interrupt enable */
#define FDCAN_IE_TEFWE BIT13
/** Tx event FIFO new entry interrupt enable */
#define FDCAN_IE_TEFNE BIT12
/** Tx FIFO empty interrupt enable */
#define FDCAN_IE_TFEE BIT11
/** Transmission cancellation finished interrupt enable */
#define FDCAN_IE_TCFE BIT10
/** Transmission completed interrupt enable */
#define FDCAN_IE_TCE BIT9
/** High priority message interrupt enable */
#define FDCAN_IE_HPME BIT8
/** Rx FIFO 1 message lost interrupt enable */
#define FDCAN_IE_RF1LE BIT7
/** Rx FIFO 1 full interrupt enable */
#define FDCAN_IE_RF1FE BIT6
/** Rx FIFO 1 watermark reached interrupt enable */
#define FDCAN_IE_RF1WE BIT5
/** Rx FIFO 1 new message interrupt enable */
#define FDCAN_IE_RF1NE BIT4
/** Rx FIFO 0 message lost interrupt enable */
#define FDCAN_IE_RF0LE BIT3
/** Rx FIFO 0 full interrupt enable */
#define FDCAN_IE_RF0FE BIT2
/** Rx FIFO 0 watermark reached interrupt enable */
#define FDCAN_IE_RF0WE BIT1
/** Rx FIFO 0 new message interrupt enable */
#define FDCAN_IE_RF0NE BIT0

/* --- FDCAN_ILS: FDCAN interrupt line select register ---------------------- */
/** Access to reserved address line */
#define FDCAN_ILS_ARAL BIT29
/** Protocol error in data phase line */
#define FDCAN_ILS_PEDL BIT28
/** Protocol error in arbitration phase line */
#define FDCAN_ILS_PEAL BIT27
/** Watchdog interrupt Line */
#define FDCAN_ILS_WDIL BIT26
/** Bus_Off status */
#define FDCAN_ILS_BOL BIT25
/** Warning status interrupt Line */
#define FDCAN_ILS_EWL BIT24
/** Error passive interrupt line */
#define FDCAN_ILS_EPL BIT23
/** Error logging overflow interrupt line */
#define FDCAN_ILS_ELOL BIT22
/** Message stored to dedicated Rx buffer interrupt line */
#define FDCAN_ILS_DRXL BIT19
/** Timeout occurred interrupt Line */
#define FDCAN_ILS_TOOL BIT18
/** Message RAM access failure interrupt line */
#define FDCAN_ILS_MRAFL BIT17
/** Timestamp wraparound interrupt line */
#define FDCAN_ILS_TSWL BIT16
/** Tx event FIFO element Lost interrupt line */
#define FDCAN_ILS_TEFLL BIT15
/** Tx event FIFO full interrupt line */
#define FDCAN_ILS_TEFFL BIT14
/** Tx event FIFO watermark reached interrupt line */
#define FDCAN_ILS_TEFWL BIT13
/** Tx event FIFO new entry interrupt line */
#define FDCAN_ILS_TEFNL BIT12
/** Tx FIFO empty interrupt Line */
#define FDCAN_ILS_TFEL BIT11
/** Transmission cancellation finished interrupt line */
#define FDCAN_ILS_TCFL BIT10
/** Transmission completed interrupt line */
#define FDCAN_ILS_TCL BIT9
/** High priority message interrupt line */
#define FDCAN_ILS_HPML BIT8
/** Rx FIFO 1 message lost interrupt line */
#define FDCAN_ILS_RF1LL BIT7
/** Rx FIFO 1 full interrupt line */
#define FDCAN_ILS_RF1FL BIT6
/** Rx FIFO 1 watermark reached interrupt line */
#define FDCAN_ILS_RF1WL BIT5
/** Rx FIFO 1 new message interrupt line */
#define FDCAN_ILS_RF1NL BIT4
/** Rx FIFO 0 message lost interrupt line */
#define FDCAN_ILS_RF0LL BIT3
/** Rx FIFO 0 full interrupt line */
#define FDCAN_ILS_RF0FL BIT2
/** Rx FIFO 0 watermark reached interrupt line */
#define FDCAN_ILS_RF0WL BIT1
/** Rx FIFO 0 new message interrupt line */
#define FDCAN_ILS_RF0NL BIT0

/* --- FDCAN_ILE: FDCAN interrupt line enable register ---------------------- */
/** Enable interrupt Line 1 */
#define FDCAN_ILE_EINT1 BIT1
/** Enable interrupt Line 0 */
#define FDCAN_ILE_EINT0 BIT0

/* --- FDCAN_GFC: FDCAN global filter configuration register ---------------- */
/** Actions for messages that pass either the standard or extended global
 * filters. */
enum fdcan_gfc_anf {
	FDCAN_GFC_ANF_ACCEPT_FIFO0	= 0x0,
	FDCAN_GFC_ANF_ACCEPT_FIFO1	= 0x1,
	FDCAN_GFC_ANF_REJECT		= 0x2,
	FDCAN_GFC_ANF_MASK			= 0x3,
};
/** Accept non-matching frames standard, for possible values see
 * @ref fdcan_gfc_anf */
#define FDCAN_GFC_ANFS_SHIFT 4
/** Accept non-matching frames extended, for possible values see
 * @ref fdcan_gfc_anf */
#define FDCAN_GFC_ANFE_SHIFT 2
/** Reject remote frames standard */
#define FDCAN_GFC_RRFS BIT1
/** Reject remote frames extended */
#define FDCAN_GFC_RRFE BIT0

/* --- FDCAN_SIDFC: FDCAN standard ID filter configuration register --------- */
/** @{ List size standard */
#define FDCAN_SIDFC_LSS_MASK 0xFF
#define FDCAN_SIDFC_LSS_SHIFT 16
/** @} */
/** @{ Filter list standard start address */
#define FDCAN_SIDFC_FLSSA_MASK 0x3FFF
#define FDCAN_SIDFC_FLSSA_SHIFT 2
/** @} */

/* --- FDCAN_XIDFC: FDCAN extended ID filter configuration register --------- */
/** @{ List size extended */
#define FDCAN_XIDFC_LSE_MASK 0xFF
#define FDCAN_XIDFC_LSE_SHIFT 16
/** @} */
/** @{ Filter list standard start address */
#define FDCAN_XIDFC_FLESA_MASK 0x3FFF
#define FDCAN_XIDFC_FLESA_SHIFT 2
/** @} */

/* --- FDCAN_XIDAM: FDCAN extended ID and mask register --------------------- */
/** @{ Extended ID Mask */
#define FDCAN_XIDAM_EIDM_MASK 0x1FFFFFFF
#define FDCAN_XIDAM_EIDM_SHIFT 0
/** @} */

/* --- FDCAN_HPMS: FDCAN high priority message status register -------------- */
/** Filter list */
#define FDCAN_HPMS_FLST BIT15
/** @{ Filter index */
#define FDCAN_HPMS_FIDX_MASK 0x7F
#define FDCAN_HPMS_FIDX_SHIFT 8
/** @} */
/** @{ Message Storage Indicator */
enum fdcan_hpms_msi {
	FDCAN_HPMS_MSI_NO_FIFO	= 0x0,
	FDCAN_HPMS_MSI_OVERRUN	= 0x1,
	FDCAN_HPMS_MSI_FIFO0	= 0x2,
	FDCAN_HPMS_MSI_FIFO1	= 0x3,
	FDCAN_HPMS_MSI_MASK		= 0x3,
};
#define FDCAN_HPMS_MSI_SHIFT 6
/** @} */
/** @{ Buffer index */
#define FDCAN_HPMS_BIDX_MASK 0x3F
#define FDCAN_HPMS_BIDX_SHIFT 0
/** @} */

/* --- FDCAN_RXF0C: FDCAN Rx FIFO 0 configuration register ------------------ */
/** FIFO 0 operation mode */
#define FDCAN_RXF0C_F0OM BIT31
/** @{ FIFO 0 Watermark */
#define FDCAN_RXF0C_F0WM_MASK 0x7F
#define FDCAN_RXF0C_F0WM_SHIFT 24
/** @} */
/** @{  Rx FIFO 0 size */
#define FDCAN_RXF0C_F0S_MASK 0x7F
#define FDCAN_RXF0C_F0S_SHIFT 16
/** @} */
/** @{  Rx FIFO 0 start address */
#define FDCAN_RXF0C_F0SA_MASK 0x3FFF
#define FDCAN_RXF0C_F0SA_SHIFT 2
/** @} */

/* --- FDCAN_RXF0S: FDCAN Rx FIFO 0 status register ------------------------- */
/** Rx FIFO 0 message Lost */
#define FDCAN_RXF0S_RF0L BIT25
/** Rx FIFO 0 Full */
#define FDCAN_RXF0S_F0F BIT24
/** @{ Rx FIFO 0 put index */
#define FDCAN_RXF0S_F0PI_MASK 0x3F
#define FDCAN_RXF0S_F0PI_SHIFT 16
/** @} */
/** @{ Rx FIFO 0 get index */
#define FDCAN_RXF0S_F0GI_MASK 0x3F
#define FDCAN_RXF0S_F0GI_SHIFT 8
/** @} */
/** @{ Rx FIFO 0 fill level */
#define FDCAN_RXF0S_F0FL_MASK 0x7F
#define FDCAN_RXF0S_F0FL_SHIFT 0
/** @} */

/* --- FDCAN_RXF0A: FDCAN Rx FIFO 0 acknowledge register -------------------- */
/** @{ Rx FIFO 0 acknowledge index */
#define FDCAN_RXF0A_F0AI_MASK 0x3F
#define FDCAN_RXF0A_F0AI_SHIFT 0
/** @} */

/* --- FDCAN_RXBC: FDCAN Rx buffer configuration register ------------------- */
/** @{ Rx buffer start address */
#define FDCAN_RXBC_RBSA_MASK 0x3FFF
#define FDCAN_RXBC_RBSA_SHIFT 2
/** @} */

/* --- FDCAN_RXF1C: FDCAN Rx FIFO 1 configuration register ------------------ */
/** FIFO 1Operation mode */
#define FDCAN_RXF1C_F1OM BIT31
/** @{ Rx FIFO 1 Watermark */
#define FDCAN_RXF1C_F1WM_MASK 0x7F
#define FDCAN_RXF1C_F1WM_SHIFT 24
/** @} */
/** @{ Rx FIFO 1 size */
#define FDCAN_RXF1C_F1S_MASK 0x7F
#define FDCAN_RXF1C_F1S_SHIFT 16
/** @} */
/** @{ Rx FIFO 1 start address */
#define FDCAN_RXF1C_F1SA_MASK 0x3FFF
#define FDCAN_RXF1C_F1SA_SHIFT 2
/** @} */

/* --- FDCAN_RXF1S: FDCAN Rx FIFO 1 status register ------------------------- */
/** @{ Debug message status */
#define FDCAN_RXF1S_DMS_MASK 0x3
#define FDCAN_RXF1S_DMS_SHIFT 30
/** @} */
/** Rx FIFO 1 message Lost */
#define FDCAN_RXF1S_RF1L BIT25
/** Rx FIFO 1 Full */
#define FDCAN_RXF1S_F1F BIT24
/** @{ Rx FIFO 1 put index */
#define FDCAN_RXF1S_F1PI_MASK 0x3F
#define FDCAN_RXF1S_F1PI_SHIFT 16
/** @} */
/** @{ Rx FIFO 1 get index */
#define FDCAN_RXF1S_F1GI_MASK 0x3F
#define FDCAN_RXF1S_F1GI_SHIFT 8
/** @} */
/** @{ Rx FIFO 1 fill level */
#define FDCAN_RXF1S_F1FL_MASK 0x7F
#define FDCAN_RXF1S_F1FL_SHIFT 0
/** @} */

/* --- FDCAN_RXF1A: FDCAN Rx FIFO 1 acknowledge register -------------------- */
/** @{ Rx FIFO 1 acknowledge index */
#define FDCAN_RXF1A_F1AI_MASK 0x3F
#define FDCAN_RXF1A_F1AI_SHIFT 0
/** @} */

/* --- FDCAN_RXESC: FDCAN Rx buffer element size configuration register ----- */
/** Element lengths possible in the RXESC and TXESC registers */
enum fdcan_esc {
	FDCAN_ESC_8		= 0x0,
	FDCAN_ESC_12		= 0x1,
	FDCAN_ESC_16		= 0x2,
	FDCAN_ESC_20		= 0x3,
	FDCAN_ESC_24		= 0x4,
	FDCAN_ESC_32		= 0x5,
	FDCAN_ESC_48		= 0x6,
	FDCAN_ESC_64		= 0x7,
	FDCAN_ESC_MASK	= 0x7,
};

/** Rx buffer data field size, for possible values see @ref fdcan_esc */
#define FDCAN_RXESC_RBDS_SHIFT 8
/** Rx FIFO 0 data field size, for possible values see @ref fdcan_esc */
#define FDCAN_RXESC_F1DS_SHIFT 4
/** Rx FIFO 1 data field size, for possible values see @ref fdcan_esc */
#define FDCAN_RXESC_F0DS_SHIFT 0

/* --- FDCAN_TXBC: FDCAN Tx buffer configuration register ------------------- */
/** Tx FIFO/queue mode. */
#define FDCAN_TXBC_TFQM BIT30
/** @{ Transmit FIFO/queue size. */
#define FDCAN_TXBC_TFQS_MASK 0x3F
#define FDCAN_TXBC_TFQS_SHIFT 24
/** @} */
/** @{ Number of dedicated transmit buffers. */
#define FDCAN_TXBC_NDTB_MASK 0x3F
#define FDCAN_TXBC_NDTB_SHIFT 16
/** @} */
/** @{ Tx buffers start address. */
#define FDCAN_TXBC_TBSA_MASK 0x3FFF
#define FDCAN_TXBC_TBSA_SHIFT 2
/** @} */

/* --- FDCAN_TXFQS: (FDCAN_TXFQS) ------------------------------------------- */
/** Tx FIFO/queue Full */
#define FDCAN_TXFQS_TFQF BIT21
/** @{ Tx FIFO/queue put index */
#define FDCAN_TXFQS_TFQPI_MASK 0x1F
#define FDCAN_TXFQS_TFQPI_SHIFT 16
/** @} */
/** @{ Tx FIFO free level */
#define FDCAN_TXFQS_TFFL_MASK 0x3F
#define FDCAN_TXFQS_TFFL_SHIFT 0
/** @} */

/* --- FDCAN_TXESC: (FDCAN_TXESC) ------------------------------------------- */
/** Tx buffer data field size, for possible values see @ref fdcan_esc */
#define FDCAN_TXESC_TBDS_SHIFT 0

/* --- FDCAN_TXEFC: FDCAN Tx event FIFO configuration register -------------- */
/** @{ Event FIFO Watermark */
#define FDCAN_TXEFC_EFWM_MASK 0x3F
#define FDCAN_TXEFC_EFWM_SHIFT 24
/** @} */
/** @{ Event FIFO size. */
#define FDCAN_TXEFC_EFS_MASK 0x3F
#define FDCAN_TXEFC_EFS_SHIFT 16
/** @} */
/** @{ Event FIFO start address */
#define FDCAN_TXEFC_EFSA_MASK 0x3FFF
#define FDCAN_TXEFC_EFSA_SHIFT 2
/** @} */

/* --- FDCAN_TXEFS: FDCAN Tx event FIFO status register --------------------- */
/** Tx event FIFO element Lost. */
#define FDCAN_TXEFS_TEFL BIT25
/** Event FIFO Full. */
#define FDCAN_TXEFS_EFF BIT24
/** @{ Event FIFO put index. */
#define FDCAN_TXEFS_EFPI_MASK 0x1F
#define FDCAN_TXEFS_EFPI_SHIFT 16
/** @} */
/** @{ Event FIFO get index. */
#define FDCAN_TXEFS_EFGI_MASK 0x1F
#define FDCAN_TXEFS_EFGI_SHIFT 8
/** @} */
/** @{ Event FIFO fill level. */
#define FDCAN_TXEFS_EFFL_MASK 0x3F
#define FDCAN_TXEFS_EFFL_SHIFT 0
/** @} */

/* --- FDCAN_TXEFA: FDCAN Tx event FIFO acknowledge register ---------------- */
/** @{ Event FIFO acknowledge index. */
#define FDCAN_TXEFA_EFAI_MASK 0x1F
#define FDCAN_TXEFA_EFAI_SHIFT 0
/** @} */

/* --- FDCAN_TTTMC: FDCAN TT trigger memory configuration register ---------- */
/** @{ Trigger memory elements */
#define FDCAN_TTTMC_TME_MASK 0x7F
#define FDCAN_TTTMC_TME_SHIFT 16
/** @} */
/** @{ Trigger memory start address. */
#define FDCAN_TTTMC_TMSA_MASK 0x3FFF
#define FDCAN_TTTMC_TMSA_SHIFT 2
/** @} */

/* --- FDCAN_TTRMC: FDCAN TT reference message configuration register ------- */
/** Reference message Payload select */
#define FDCAN_TTRMC_RMPS BIT31
/** Extended identifier */
#define FDCAN_TTRMC_XTD BIT30
/** @{ Reference identifier. */
#define FDCAN_TTRMC_RID_MASK 0x1FFFFFFF
#define FDCAN_TTRMC_RID_SHIFT 0
/** @} */

/* --- FDCAN_TTOCF: FDCAN TT operation configuration register --------------- */
/** Event trigger polarity. */
#define FDCAN_TTOCF_EVTP BIT26
/** Enable clock calibration. */
#define FDCAN_TTOCF_ECC BIT25
/** Enable global time Filtering. */
#define FDCAN_TTOCF_EGTF BIT24
/** @{ Application watchdog limit. */
#define FDCAN_TTOCF_AWL_MASK 0xFF
#define FDCAN_TTOCF_AWL_SHIFT 16
/** @} */
/** Enable external clock synchronization */
#define FDCAN_TTOCF_EECS BIT15
/** @{ Initial reference trigger offset. */
#define FDCAN_TTOCF_IRTO_MASK 0x7F
#define FDCAN_TTOCF_IRTO_SHIFT 8
/** @} */
/** @{ LD of synchronization deviation limit. */
#define FDCAN_TTOCF_LDSDL_MASK 0x7
#define FDCAN_TTOCF_LDSDL_SHIFT 5
/** @} */
/** Time master. */
#define FDCAN_TTOCF_TM BIT4
/** Gap enable. */
#define FDCAN_TTOCF_GEN BIT3
/** @{ Operation mode. */
#define FDCAN_TTOCF_OM_MASK 0x3
#define FDCAN_TTOCF_OM_SHIFT 0
/** @} */

/* --- FDCAN_TTMLM: FDCAN TT matrix limits register ------------------------- */
/** @{ Expected Number of Tx triggers */
#define FDCAN_TTMLM_ENTT_MASK 0xFFF
#define FDCAN_TTMLM_ENTT_SHIFT 16
/** @} */
/** @{ Tx enable Window */
#define FDCAN_TTMLM_TXEW_MASK 0xF
#define FDCAN_TTMLM_TXEW_SHIFT 8
/** @} */
/** @{ Cycle start synchronization */
#define FDCAN_TTMLM_CSS_MASK 0x3
#define FDCAN_TTMLM_CSS_SHIFT 6
/** @} */
/** @{ Cycle count Max */
#define FDCAN_TTMLM_CCM_MASK 0x3F
#define FDCAN_TTMLM_CCM_SHIFT 0
/** @} */

/* --- FDCAN_TURCF: (FDCAN_TURCF) ------------------------------------------- */
/** Enable local time. */
#define FDCAN_TURCF_ELT BIT31
/** @{ Denominator configuration. */
#define FDCAN_TURCF_DC_MASK 0x3FFF
#define FDCAN_TURCF_DC_SHIFT 16
/** @} */
/** @{ Numerator configuration low. */
#define FDCAN_TURCF_NCL_MASK 0xFFFF
#define FDCAN_TURCF_NCL_SHIFT 0
/** @} */

/* --- FDCAN_TTOCN: (FDCAN_TTOCN) ------------------------------------------- */
/** TT operation control register Locked. */
#define FDCAN_TTOCN_LCKC BIT15
/** External synchronization control */
#define FDCAN_TTOCN_ESCN BIT13
/** Next is Gap. */
#define FDCAN_TTOCN_NIG BIT12
/** Time mark Gap. */
#define FDCAN_TTOCN_TMG BIT11
/** Finish Gap. */
#define FDCAN_TTOCN_FGP BIT10
/** Gap control select */
#define FDCAN_TTOCN_GCS BIT9
/** Trigger time mark interrupt pulse enable */
#define FDCAN_TTOCN_TTIE BIT8
/** @{ Register time mark Compare. */
#define FDCAN_TTOCN_TMC_MASK 0x3
#define FDCAN_TTOCN_TMC_SHIFT 6
/** @} */
/** Register time mark interrupt pulse enable. */
#define FDCAN_TTOCN_RTIE BIT5
/** @{ Stop watch source. */
#define FDCAN_TTOCN_SWS_MASK 0x3
#define FDCAN_TTOCN_SWS_SHIFT 3
/** @} */
/** Stop watch polarity. */
#define FDCAN_TTOCN_SWP BIT2
/** External clock synchronization. */
#define FDCAN_TTOCN_ECS BIT1
/** Set global time. */
#define FDCAN_TTOCN_SGT BIT0

/* --- FDCAN_TTGTP: FDCAN TT global time preset register -------------------- */
/** @{ Cycle time target phase */
#define FDCAN_TTGTP_CTP_MASK 0xFFFF
#define FDCAN_TTGTP_CTP_SHIFT 16
/** @} */
/** @{ Time Preset. */
#define FDCAN_TTGTP_TP_MASK 0xFFFF
#define FDCAN_TTGTP_TP_SHIFT 0
/** @} */

/* --- FDCAN_TTTMK: FDCAN TT time mark register ----------------------------- */
/** TT time mark register Locked. */
#define FDCAN_TTTMK_LCKM BIT31
/** @{ Time mark cycle code. */
#define FDCAN_TTTMK_TICC_MASK 0x7F
#define FDCAN_TTTMK_TICC_SHIFT 16
/** @} */
/** @{ Time mark. */
#define FDCAN_TTTMK_TM_MASK 0xFFFF
#define FDCAN_TTTMK_TM_SHIFT 0
/** @} */

/* --- FDCAN_TTIR: (FDCAN_TTIR) --------------------------------------------- */
/** Configuration error. */
#define FDCAN_TTIR_CER BIT18
/** Application watchdog. */
#define FDCAN_TTIR_AW BIT17
/** Watch trigger. */
#define FDCAN_TTIR_WT BIT16
/** Initialization watch trigger. */
#define FDCAN_TTIR_IWTG BIT15
/** Error level Changed. */
#define FDCAN_TTIR_ELC BIT14
/** Scheduling error 2. */
#define FDCAN_TTIR_SE2 BIT13
/** Scheduling error 1. */
#define FDCAN_TTIR_SE1 BIT12
/** Tx count overflow. */
#define FDCAN_TTIR_TXO BIT11
/** Tx count underflow. */
#define FDCAN_TTIR_TXU BIT10
/** Global time error. */
#define FDCAN_TTIR_GTE BIT9
/** Global time discontinuity. */
#define FDCAN_TTIR_GTD BIT8
/** Global time wrap */
#define FDCAN_TTIR_GTW BIT7
/** Stop watch event */
#define FDCAN_TTIR_SWE BIT6
/** Trigger time mark event internal */
#define FDCAN_TTIR_TTMI BIT5
/** Register time mark interrupt. */
#define FDCAN_TTIR_RTMI BIT4
/** Start of Gap */
#define FDCAN_TTIR_SOG BIT3
/** Change of synchronization mode. */
#define FDCAN_TTIR_CSM BIT2
/** Start of matrix cycle. */
#define FDCAN_TTIR_SMC BIT1
/** Start of basic cycle. */
#define FDCAN_TTIR_SBC BIT0

/* --- FDCAN_TTIE: FDCAN TT interrupt enable register ----------------------- */
/** Configuration error interrupt enable */
#define FDCAN_TTIE_CERE BIT18
/** Application watchdog interrupt enable */
#define FDCAN_TTIE_AWE BIT17
/** Watch trigger interrupt enable */
#define FDCAN_TTIE_WTE BIT16
/** Initialization watch trigger interrupt enable */
#define FDCAN_TTIE_IWTE BIT15
/** Change error level interrupt enable */
#define FDCAN_TTIE_ELCE BIT14
/** Scheduling error 2 interrupt enable */
#define FDCAN_TTIE_SE2E BIT13
/** Scheduling error 1 interrupt enable */
#define FDCAN_TTIE_SE1E BIT12
/** Tx count overflow interrupt enable */
#define FDCAN_TTIE_TXOE BIT11
/** Tx count underflow interrupt enable */
#define FDCAN_TTIE_TXUE BIT10
/** Global time error interrupt enable */
#define FDCAN_TTIE_GTEE BIT9
/** Global time discontinuity interrupt enable */
#define FDCAN_TTIE_GTDE BIT8
/** Global time wrap interrupt enable */
#define FDCAN_TTIE_GTWE BIT7
/** Stop watch event interrupt enable */
#define FDCAN_TTIE_SWEE BIT6
/** Trigger time mark event internal interrupt enable */
#define FDCAN_TTIE_TTMIE BIT5
/** Register time mark interrupt enable */
#define FDCAN_TTIE_RTMIE BIT4
/** Start of gap interrupt enable */
#define FDCAN_TTIE_SOGE BIT3
/** Change of synchronization mode interrupt enable */
#define FDCAN_TTIE_CSME BIT2
/** Start of matrix cycle interrupt enable */
#define FDCAN_TTIE_SMCE BIT1
/** Start of basic cycle interrupt enable */
#define FDCAN_TTIE_SBCE BIT0

/* --- FDCAN_TTILS: FDCAN TT interrupt line select register ----------------- */
/** Configuration error interrupt Line */
#define FDCAN_TTILS_CERL BIT18
/** Application watchdog interrupt Line */
#define FDCAN_TTILS_AWL BIT17
/** Watch trigger interrupt Line */
#define FDCAN_TTILS_WTL BIT16
/** Initialization watch trigger interrupt Line */
#define FDCAN_TTILS_IWTL BIT15
/** Change error level interrupt Line */
#define FDCAN_TTILS_ELCL BIT14
/** Scheduling error 2 interrupt Line */
#define FDCAN_TTILS_SE2L BIT13
/** Scheduling error 1 interrupt Line */
#define FDCAN_TTILS_SE1L BIT12
/** Tx count overflow interrupt Line */
#define FDCAN_TTILS_TXOL BIT11
/** Tx count underflow interrupt Line */
#define FDCAN_TTILS_TXUL BIT10
/** Global time error interrupt Line */
#define FDCAN_TTILS_GTEL BIT9
/** Global time discontinuity interrupt Line */
#define FDCAN_TTILS_GTDL BIT8
/** Global time wrap interrupt Line */
#define FDCAN_TTILS_GTWL BIT7
/** Stop watch event interrupt Line */
#define FDCAN_TTILS_SWEL BIT6
/** Trigger time mark event internal interrupt Line */
#define FDCAN_TTILS_TTMIL BIT5
/** Register time mark interrupt Line */
#define FDCAN_TTILS_RTMIL BIT4
/** Start of gap interrupt Line */
#define FDCAN_TTILS_SOGL BIT3
/** Change of synchronization mode interrupt Line */
#define FDCAN_TTILS_CSML BIT2
/** Start of matrix cycle interrupt Line */
#define FDCAN_TTILS_SMCL BIT1
/** Start of basic cycle interrupt Line */
#define FDCAN_TTILS_SBCL BIT0

/* --- FDCAN_TTOST: FDCAN TT operation status register ---------------------- */
/** Schedule phase lock. */
#define FDCAN_TTOST_SPL BIT31
/** Wait for external clock synchronization. */
#define FDCAN_TTOST_WECS BIT30
/** Application watchdog event. */
#define FDCAN_TTOST_AWE BIT29
/** Wait for event. */
#define FDCAN_TTOST_WFE BIT28
/** Gap started Indicator. */
#define FDCAN_TTOST_GSI BIT27
/** @{ Time master priority. */
#define FDCAN_TTOST_TMP_MASK 0x7
#define FDCAN_TTOST_TMP_SHIFT 24
/** @} */
/** Gap finished Indicator. */
#define FDCAN_TTOST_GFI BIT23
/** Wait for global time discontinuity. */
#define FDCAN_TTOST_WGTD BIT22
/** @{ Reference trigger offset. */
#define FDCAN_TTOST_RTO_MASK 0xFF
#define FDCAN_TTOST_RTO_SHIFT 8
/** @} */
/** Quality of clock Speed. */
#define FDCAN_TTOST_QCS BIT7
/** Quality of global time phase. */
#define FDCAN_TTOST_QGTP BIT6
/** @{ Synchronization state */
#define FDCAN_TTOST_SYS_MASK 0x3
#define FDCAN_TTOST_SYS_SHIFT 4
/** @} */
/** @{ Master state. */
#define FDCAN_TTOST_MS_MASK 0x3
#define FDCAN_TTOST_MS_SHIFT 2
/** @} */
/** @{ Error level. */
#define FDCAN_TTOST_EL_MASK 0x3
#define FDCAN_TTOST_EL_SHIFT 0
/** @} */

/* --- FDCAN_TURNA: FDCAN TUR numerator actual register --------------------- */
/** @{ Numerator actual value. */
#define FDCAN_TURNA_NAV_MASK 0x3FFFF
#define FDCAN_TURNA_NAV_SHIFT 0
/** @} */

/* --- FDCAN_TTLGT: FDCAN TT local and global time register ----------------- */
/** @{ Global time. */
#define FDCAN_TTLGT_GT_MASK 0xFFFF
#define FDCAN_TTLGT_GT_SHIFT 16
/** @} */
/** @{ Local time. */
#define FDCAN_TTLGT_LT_MASK 0xFFFF
#define FDCAN_TTLGT_LT_SHIFT 0
/** @} */

/* --- FDCAN_TTCTC: FDCAN TT cycle time and count register ------------------ */
/** @{ Cycle count. */
#define FDCAN_TTCTC_CC_MASK 0x3F
#define FDCAN_TTCTC_CC_SHIFT 16
/** @} */
/** @{ Cycle time */
#define FDCAN_TTCTC_CT_MASK 0xFFFF
#define FDCAN_TTCTC_CT_SHIFT 0
/** @} */

/* --- FDCAN_TTCPT: FDCAN TT capture time register -------------------------- */
/** @{ Stop watch value. */
#define FDCAN_TTCPT_SWV_MASK 0xFFFF
#define FDCAN_TTCPT_SWV_SHIFT 16
/** @} */
/** @{ Cycle count value */
#define FDCAN_TTCPT_CCV_MASK 0x3F
#define FDCAN_TTCPT_CCV_SHIFT 0
/** @} */

/* --- FDCAN_TTCSM: FDCAN TT cycle sync mark register ----------------------- */
/** @{ Cycle sync mark. */
#define FDCAN_TTCSM_CSM_MASK 0xFFFF
#define FDCAN_TTCSM_CSM_SHIFT 0
/** @} */

/* --- FDCAN_TTTS: FDCAN TT trigger select register ------------------------- */
/** @{ Event trigger input selection */
#define FDCAN_TTTS_EVTSEL_MASK 0x3
#define FDCAN_TTTS_EVTSEL_SHIFT 4
/** @} */
/** @{ Stop watch trigger input selection */
#define FDCAN_TTTS_SWTDEL_MASK 0x3
#define FDCAN_TTTS_SWTDEL_SHIFT 0
/** @} */

/* --- FDCAN_CCU_CREL: (FDCAN_CCU_CREL) ------------------------------------- */
/** @{ Core release */
#define FDCAN_CCU_CREL_REL_MASK 0xF
#define FDCAN_CCU_CREL_REL_SHIFT 28
/** @} */
/** @{ Step of core release */
#define FDCAN_CCU_CREL_STEP_MASK 0xF
#define FDCAN_CCU_CREL_STEP_SHIFT 24
/** @} */
/** @{ Sub-step of core release */
#define FDCAN_CCU_CREL_SUBSTEP_MASK 0xF
#define FDCAN_CCU_CREL_SUBSTEP_SHIFT 20
/** @} */
/** @{ Timestamp year */
#define FDCAN_CCU_CREL_YEAR_MASK 0xF
#define FDCAN_CCU_CREL_YEAR_SHIFT 16
/** @} */
/** @{ Timestamp month */
#define FDCAN_CCU_CREL_MON_MASK 0xFF
#define FDCAN_CCU_CREL_MON_SHIFT 8
/** @} */
/** @{ Timestamp day */
#define FDCAN_CCU_CREL_DAY_MASK 0xFF
#define FDCAN_CCU_CREL_DAY_SHIFT 0
/** @} */

/* --- FDCAN_CCU_CCFG: Calibration configuration register ------------------- */
/** Software Reset */
#define FDCAN_CCU_CCFG_SWR BIT31
/** @{ Clock Divider */
#define FDCAN_CCU_CCFG_CDIV_MASK 0xF
#define FDCAN_CCU_CCFG_CDIV_SHIFT 16
/** @} */
/** @{ Oscillator clock periods minimum */
#define FDCAN_CCU_CCFG_OCPM_MASK 0xFF
#define FDCAN_CCU_CCFG_OCPM_SHIFT 8
/** @} */
/** Calibration Field length */
#define FDCAN_CCU_CCFG_CFL BIT7
/** Bypass clock calibration */
#define FDCAN_CCU_CCFG_BCC BIT6
/** @{ Time quanta per bit time */
#define FDCAN_CCU_CCFG_TQBT_MASK 0x1F
#define FDCAN_CCU_CCFG_TQBT_SHIFT 0
/** @} */

/* --- FDCAN_CCU_CSTAT: Calibration status register ------------------------- */
/** @{ Calibration state */
enum fdcan_ccu_cstat_cals {
	FDCAN_CCU_CSTAT_CALS_NOT_CALCAL	= 0x0,
	FDCAN_CCU_CSTAT_CALS_BASIC_CAL	= 0x1,
	FDCAN_CCU_CSTAT_CALS_PREC_CAL	= 0x2,
	FDCAN_CCU_CSTAT_CALS_MASK		= 0x3,
};
#define FDCAN_CCU_CSTAT_CALS_SHIFT 30
/** @} */
/** @{ Time quanta counter */
#define FDCAN_CCU_CSTAT_TQC_MASK 0x7FF
#define FDCAN_CCU_CSTAT_TQC_SHIFT 18
/** @} */
/** @{ Oscillator clock period counter */
#define FDCAN_CCU_CSTAT_OCPC_MASK 0x3FFFF
#define FDCAN_CCU_CSTAT_OCPC_SHIFT 0
/** @} */

/* --- FDCAN_CCU_CWD: Calibration watchdog register ------------------------- */
/** @{ Watchdog value */
#define FDCAN_CCU_CWD_WDV_MASK 0xFFFF
#define FDCAN_CCU_CWD_WDV_SHIFT 16
/** @} */
/** @{ WDC */
#define FDCAN_CCU_CWD_WDC_MASK 0xFFFF
#define FDCAN_CCU_CWD_WDC_SHIFT 0
/** @} */

/* --- FDCAN_CCU_IR: Clock calibration unit interrupt register -------------- */
/** Calibration state changed */
#define FDCAN_CCU_IR_CSC BIT1
/** Calibration watchdog event */
#define FDCAN_CCU_IR_CWE BIT0

/* --- FDCAN_CCU_IE: Clock calibration unit interrupt enable register ------- */
/** Calibration state changed enable */
#define FDCAN_CCU_IE_CSCE BIT1
/** Calibration watchdog event enable */
#define FDCAN_CCU_IE_CWEE BIT0

/* --- RX Element Definition ------------------------------------------------ */
/** Received message element that is read from either the RX fifos or RX buffer.
 * The length of this is set by FDCAN_RXESC. Note: sizeof(msg) must be a
 * multiple of 4. */
struct fdcan_rxelement {
	uint32_t id_flag;
	uint32_t msg_flag;
	/** Contents of the CAN message, this can be read byte at a time, but for
	 * consistency with TX it's defined as a word. */
	uint32_t msg[];
};

/** Error status indicator; when set the transmitting node is error passive */
#define FDCAN_RXELEM_ID_FLAG_ESI BIT31
/** Extended ID indicator; when set the received frame used 29 bit addressing */
#define FDCAN_RXELEM_ID_FLAG_XTD BIT30
/** Remote transmission requested; when set the received frame is a remote
 * frame */
#define FDCAN_RXELEM_ID_FLAG_RTR BIT29
/** @{ Mask and shift for the received message id */
#define FDCAN_RXELEM_ID_29_MASK 0x1FFFFFFF
#define FDCAN_RXELEM_ID_29_SHIFT 0
#define FDCAN_RXELEM_ID_11_MASK 0x7FF
#define FDCAN_RXELEM_ID_11_SHIFT 18
/** @} */

/** @{ Received message filter status. If ANMF is clear, FIDX has the matched
 * index. Otherwise if ANMF is set, no filter matched the received message. */
#define FDCAN_RXELEM_MSG_ANMF BIT31
#define FDCAN_RXELEM_MSG_FIDX_MASK 0x7F
#define FDCAN_RXELEM_MSG_FIDX_SHIFT 24
/** @} */
/** FD Format, if set message may be longer than 8 bytes and may switch
 * baudrates */
#define FDCAN_RXELEM_MSG_FDF BIT21
/** Bitrate switch, if set message switch bitrates during reception */
#define FDCAN_RXELEM_MSG_BRS BIT20
/** @{ Received message data length code */
#define FDCAN_RXELEM_MSG_DLC_MASK 0xF
#define FDCAN_RXELEM_MSG_DLC_SHIFT 16
/** @} */
/** @{ RX timestamp counter value captured on start of frame reception.
 * Resolution set by timestamp counter prescaler FDCAN_TSCC.TCP */
#define FDCAN_RXELEM_MSG_TIMESTAMP_MASK 0xFFFF
#define FDCAN_RXELEM_MSG_TIMESTAMP_SHIFT 0
/** @} */

/* --- TX Element Definition ------------------------------------------------ */
/** Message element that is written into the TX fifo or TX buffer. The length of
 * this is set by FDCAN_TXESC. Note: sizeof(msg) must be a multiple of 4. */
struct fdcan_txelement {
	uint32_t id_flag;
	uint32_t msg_flag;
	/** Contents of the CAN message, this must be written as a word. */
	uint32_t msg[];
};

/** Error status indicator; when clear the ESI bit in the transmitted message
 * depends on the controllers error passive flag. If set, the ESI bit is
 * transmitted recessive. */
#define FDCAN_TXELEM_ID_FLAG_ESI BIT31
/** Extended ID indicator; when set the frame uses 29 bit addressing */
#define FDCAN_TXELEM_ID_FLAG_XTD BIT30
/** Remote transmission requested; when set the frame is a remote frame */
#define FDCAN_TXELEM_ID_FLAG_RTR BIT29
/** @{ Mask and shift for the frame message id */
#define FDCAN_TXELEM_ID_29_MASK 0x1FFFFFFF
#define FDCAN_TXELEM_ID_29_SHIFT 0
#define FDCAN_TXELEM_ID_11_MASK 0x7FF
#define FDCAN_TXELEM_ID_11_SHIFT 18
/** @} */

/** @{ Message marker (arbitrary user tag), written by CPU during Tx buffer
 * configuration. Copied into Tx event FIFO element for identification of TX
 * message. */
#define FDCAN_TXELEM_MSG_MM_MASK 0xFF
#define FDCAN_TXELEM_MSG_MM_SHIFT 24
/** @} */
/** Event FIFO control, if set, on transmission, event will be stored into the
 * event FIFO */
#define FDCAN_TXELEM_MSG_EFC BIT23
/** FD Format, if set message may be longer than 8 bytes and may switch baud
 * rates */
#define FDCAN_TXELEM_MSG_FDF BIT21
/** Baud Rate Switch, if set message will switch baud rates during data
 * transmission */
#define FDCAN_TXELEM_MSG_BRS BIT20
/** @{ Message data length code */
#define FDCAN_TXELEM_MSG_DLC_MASK 0xF
#define FDCAN_TXELEM_MSG_DLC_SHIFT 16
/** @} */

/* --- RX Event Definition -------------------------------------------------- */
/** Element written to the TX Event FIFO on transmission event */
struct fdcan_txevent {
	uint32_t id_flag;
	uint32_t msg_flag;
};

/** Error status indicator; when clear the ESI bit in the transmitted message
 * depends on the controllers error passive flag. If set, the ESI bit is
 * transmitted recessive. */
#define FDCAN_TXEVENT_ID_FLAG_ESI BIT31
/** Extended ID indicator; when set the frame uses 29 bit addressing */
#define FDCAN_TXEVENT_ID_FLAG_XTD BIT30
/** Remote transmission requested; when set the frame is a remote frame */
#define FDCAN_TXEVENT_ID_FLAG_RTR BIT29
/** @{ Mask and shift for the frame message id */
#define FDCAN_TXEVENT_ID_29_MASK  0x1FFFFFFF
#define FDCAN_TXEVENT_ID_29_SHIFT 0
#define FDCAN_TXEVENT_ID_11_MASK  0x7FF
#define FDCAN_TXEVENT_ID_11_SHIFT 18
/** @} */

/** @{ Message marker (arbitrary user tag), copied from the TX element. */
#define FDCAN_TXEVENT_MSG_MM_MASK 0xFF
#define FDCAN_TXEVENT_MSG_MM_SHIFT 24
/** @} */
/** FD Format, if set message may be longer than 8 bytes and may switch baud
 * rates */
#define FDCAN_TXEVENT_MSG_FDF BIT21
/** Baud Rate Switch, if set message will switch baud rates during data
 * transmission */
#define FDCAN_TXEVENT_MSG_BRS BIT20
/** @{ Message data length code */
#define FDCAN_TXEVENT_MSG_DLC_MASK  0xF
#define FDCAN_TXEVENT_MSG_DLC_SHIFT 16
/** @} */
/** @{ TX timestamp counter value captured on start of frame reception.
 * Resolution set by timestamp counter prescaler FDCAN_TSCC.TCP */
#define FDCAN_TXEVENT_MSG_TIMESTAMP_MASK  0xFFFF
#define FDCAN_TXEVENT_MSG_TIMESTAMP_SHIFT 0
/** @} */

/* --- Filter Definition ---------------------------------------------------- */
/** 11 bit address filter element. Note: depending on filter mode, the 2nd
 * address field has different meanings. */
struct fdcan_stdfilt {
	uint32_t flags;
};

/** @{ Standard filter type, valid values in @ref fdcan_filt_type */
#define FDCAN_STDFILT_SFT_SHIFT 30
/** @} */
/** @{ Standard filter configuration, valid values in @ref fdcan_filt_config */
#define FDCAN_STDFILT_SFEC_SHIFT 27
/** @} */
/** @{ Standard filter element ID 1. When filtering for RX buffers or for debug
 * messages this field defines the ID of a standard message to be stored. The
 * received identifiers must match exactly, no masking mechanism is used. */
#define FDCAN_STDFILT_SFID1_MASK  0x3FF
#define FDCAN_STDFILT_SFID1_SHIFT 16
/** @} */
/** @{ When SFEC != 0x7, second ID of standard ID filter element. */
#define FDCAN_STDFILT_SFID2_MASK  0x3FF
#define FDCAN_STDFILT_SFID2_SHIFT 0
/** @} */
/** @{ When SFEC == 0x7, type of message stored, in
 * @ref fdcan_filt_buffer_type */
#define FDCAN_STDFILT_SFID2_TYPE_SHIFT 9
/** @} */
/** @{ When SFEC == 0x7, filter event pin raised at the Extension Interface. A 1
 * at the respective bit position enables generation of a pulse at the related
 * filter event pin with th duration of one fdcan_pclk period in case the filter
 * matches. */
#define FDCAN_STDFILT_SFID2_EVENT_MASK  0x3
#define FDCAN_STDFILT_SFID2_EVENT_SHIFT 6
/** @} */
/** @{ When SFEC == 0x7, defines the offset to the Rx buffer start address
 * FDCAN_RXBC.RBSA for storage of a matching message. */
#define FDCAN_STDFILT_SFID2_OFFSET_MASK  0x1F
#define FDCAN_STDFILT_SFID2_OFFSET_SHIFT 0
/** @} */

/** 29 bit address filter element. Note: depending on mode id2_flags has two
 * different meanings. */
struct fdcan_extfilt {
	uint32_t id1_flags;
	uint32_t id2_flags;
};

/** @{ For both fields in the element, the ID is stored in the lower 29 bits. */
#define FDCAN_EXTFILT_ID_MASK  0x1FFFFFFF
#define FDCAN_EXTFILT_ID_SHIFT 0
/** @} */
/** @{ Extended filter element type, valid values in @ref fdcan_filt_config */
#define FDCAN_EXTFILT_ID1_EFEC_SHIFT 29
/** @} */
/** @{ Extended filter type, valid values in @ref fdcan_filt_type */
#define FDCAN_EXTFILT_ID2_EFT_SHIFT 30
/** @} */
/** @{ When EFT == 0x7, type of message stored */
#define FDCAN_EXTFILT_ID2_TYPE_SHIFT 9
/** @} */
/** @{ When EFT == 0x7, filter event pin raised at the Extension Interface. A 1
 * at the respective bit position enables generation of a pulse at the related
 * filter event pin with th duration of one fdcan_pclk period in case the filter
 * matches. */
#define FDCAN_EXTFILT_ID2_EVENT_MASK  0x3
#define FDCAN_EXTFILT_ID2_EVENT_SHIFT 6
/** @} */
/** @{ When ETF == 0x7, defines the offset to the Rx buffer start address
 * FDCAN_RXBC.RBSA for storage of a matching message. */
#define FDCAN_EXTFILT_ID2_OFFSET_MASK  0x1F
#define FDCAN_EXTFILT_ID2_OFFSET_SHIFT 0
/** @} */

/** Filter element type, shared between standard and extended filter elements
 * but placed in different locations. */
enum fdcan_filt_type {
	FDCAN_FILT_TYPE_RANGE		= 0x0,
	FDCAN_FILT_TYPE_DUAL		= 0x1,
	FDCAN_FILT_TYPE_MASKMATCH	= 0x2,
	FDCAN_FILT_TYPE_DISABLED	= 0x3,
	FDCAN_FILT_TYPE_MASK		= 0x3,
};
/** Filter element configuration, shared between standard and extended
 * filter elements but placed in different locations. */
enum fdcan_filt_config {
	FDCAN_FILT_CONFIG_DISABLE				= 0x0,
	FDCAN_FILT_CONFIG_STORE_FIFO0			= 0x1,
	FDCAN_FILT_CONFIG_STORE_FIFO1			= 0x2,
	FDCAN_FILT_CONFIG_REJECT				= 0x3,
	FDCAN_FILT_CONFIG_SET_PRI				= 0x4,
	FDCAN_FILT_CONFIG_SET_PRI_STORE_FIFO0	= 0x5,
	FDCAN_FILT_CONFIG_SET_PRI_STORE_FIFO1	= 0x6,
	FDCAN_FILT_CONFIG_STORE_BUFFER			= 0x7,
	FDCAN_FILT_CONFIG_STORE_MASK			= 0x7,
};
/** When the filter configuration (EFT or SFT) == 0x7, this determines what
 * gets stored in the RX buffer. */
enum fdcan_filt_buffer_type {
	FDCAN_FILT_BUFFER_TYPE_STORE	= 0x0,
	FDCAN_FILT_BUFFER_TYPE_DEBUG_A	= 0x1,
	FDCAN_FILT_BUFFER_TYPE_DEBUG_B	= 0x2,
	FDCAN_FILT_BUFFER_TYPE_DEBUG_C	= 0x3,
	FDCAN_FILT_BUFFER_TYPE_MASK		= 0x3,
};

/* --- RAM Configuration Helper --------------------------------------------- */
/** RAM configuration for a FDCAN device. RAM is of limited length and is shared
 * amongst all FDCAN devices. */
struct fdcan_ram_config {
	/** Length of RX buffer element. Each element is 2 words + payload long. */
	enum fdcan_esc rx_buffer_elem_len;
	/** Length of RX FIFO 0 element. Each element is 2 words + payload long. */
	enum fdcan_esc rx_fifo0_elem_len;
	/** Length of RX FIFO 1 element. Each element is 2 words + payload long. */
	enum fdcan_esc rx_fifo1_elem_len;
	/** Length of a TX buffer or FIFO element. Each element is 2 words + payload
	 * long. */
	enum fdcan_esc tx_elem_len;

	/** True if RX FIFO 0 is allowed to overwrite old messages on FIFO full. */
	bool rx_fifo0_overwrite;
	/** True if RX FIFO 1 is allowed to overwrite old messages on FIFO full. */
	bool rx_fifo1_overwrite;

	/** Number of standard 11-bit filters supported.
	 * 0-128 elements / 0-128 words. */
	uint32_t standard_filter_len;
	/** Number of extended 29-bit filters supported.
	 * 0-64 elements / 0-128 words. */
	uint32_t extended_filter_len;
	/** Number of receive buffer slots.
	 * 0-64 elements / 0-1152 words. */
	uint32_t rx_buffer_len;
	/** Number of slots in receive FIFO 0.
	 * 0-64 elements / 0-1152 words. */
	uint32_t rx_fifo0_len;
	/** Number of slots in receive FIFO 1.
	 * 0-64 elements / 0-1152 words. */
	uint32_t rx_fifo1_len;
	/** Number of slots in the transmit event FIFO.
	 * 0-32 elements / 0-64 words. */
	uint32_t tx_event_len;
	/** Number of slots in the transmit buffer.
	 * 0-32 elements / 0-576 words. */
	uint32_t tx_buf_len;
	/** Number of slots in the transmit FIFO.
	 * 0-32 elements / 0-576 words. */
	uint32_t tx_fifo_len;

	/** True if messages in the transmit FIFO should be sent in priority order. */
	bool tx_fifo_queue_mode;
};

/* @ingroup fdcan_defines */
/** @} */

BEGIN_DECLS

uint8_t fdcan_len_to_dlc(uint32_t len);
uint8_t fdcan_dlc_to_len(uint8_t dlc);

void fdcan_start_clock(uint32_t candev);
void fdcan_stop_clock(uint32_t candev);

void fdcan_set_nominal_bittiming(uint32_t candev,
		const struct can_bittiming* nbt);
void fdcan_set_fd_bittiming(uint32_t candev,
		const struct can_bittiming* fdt, uint32_t txcvr_loop_delay_ns);

uint32_t fdcan_esc_to_bytes(enum fdcan_esc e);

uint32_t fdcan_configure_ram(uint32_t candev, uint32_t ram_offset,
                             const struct fdcan_ram_config *cfg);

struct fdcan_txelement *fdcan_get_txelement_at_index(uint32_t candev,
		uint32_t idx);
uint32_t fdcan_get_next_fifo0(uint32_t candev, struct fdcan_rxelement **elem);

END_DECLS

#endif /* LIBOPENCM3_STM32_COMMON_FDCAN_COMMON_H */

/** @cond */
#else
#warning "fdcan_common.h should not be included explicitly, only via fdcan.h"
#endif
/** @endcond */
