/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
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

#pragma once

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#if defined(STM32G4)
#	include <libopencm3/stm32/g4/fdcan.h>
#elif defined(STM32H7)
#	include <libopencm3/stm32/h7/fdcan.h>
#endif

/** @addtogroup fdcan_defines
 * @{
 */

/** @defgroup fdcan_fifo Named constants for FIFOs
 * @{
 */
#define FDCAN_FIFO0						0
#define FDCAN_FIFO1						1
/**@}*/

#define FDCAN_BLOCK_ID(can_base)		(((can_base) - CAN1)/(CAN2 - CAN1))

/** @defgroup FDCAN registers file in each FDCAN block. */

#define FDCAN_CREL(can_base)			MMIO32(can_base + 0x0000)
#define FDCAN_ENDN(can_base)			MMIO32(can_base + 0x0004)
#define FDCAN_DBTP(can_base)			MMIO32(can_base + 0x000C)
#define FDCAN_TEST(can_base)			MMIO32(can_base + 0x0010)
#define FDCAN_RWD(can_base)				MMIO32(can_base + 0x0014)
#define FDCAN_CCCR(can_base)			MMIO32(can_base + 0x0018)
#define FDCAN_NBTP(can_base)			MMIO32(can_base + 0x001C)
#define FDCAN_TSCC(can_base)			MMIO32(can_base + 0x0020)
#define FDCAN_TSCV(can_base)			MMIO32(can_base + 0x0024)
#define FDCAN_TOCC(can_base)			MMIO32(can_base + 0x0028)
#define FDCAN_TOCV(can_base)			MMIO32(can_base + 0x002C)
#define FDCAN_ECR(can_base)				MMIO32(can_base + 0x0040)
#define FDCAN_PSR(can_base)				MMIO32(can_base + 0x0044)
#define FDCAN_TDCR(can_base)			MMIO32(can_base + 0x0048)
#define FDCAN_IR(can_base)				MMIO32(can_base + 0x0050)
#define FDCAN_IE(can_base)				MMIO32(can_base + 0x0054)
#define FDCAN_ILS(can_base)				MMIO32(can_base + 0x0058)
#define FDCAN_ILE(can_base)				MMIO32(can_base + 0x005C)


/** Generic access to Rx FIFO status registers.
 * @param can_base FDCAN block base address @ref fdcan_block
 * @param fifo_id ID of FIFO, 0 or 1
 */
#define FDCAN_RXFIS(can_base, fifo_id)	\
	MMIO32(can_base + FDCAN_RXFIS_BASE + (FDCAN_RXFI_OFFSET * fifo_id))

#define FDCAN_RXF0S(can_base)			FDCAN_RXFIS(can_base, 0)
#define FDCAN_RXF1S(can_base)			FDCAN_RXFIS(can_base, 1)


/** Generic access to Rx FIFO acknowledge registers.
 * @param can_base FDCAN block base address @ref fdcan_block
 * @param fifo_id ID of FIFO, 0 or 1
 */
#define FDCAN_RXFIA(can_base, fifo_id)	\
	MMIO32(can_base + FDCAN_RXFIA_BASE + (FDCAN_RXFI_OFFSET * fifo_id))

#define FDCAN_RXF0A(can_base)			FDCAN_RXFIA(can_base, 0)
#define FDCAN_RXF1A(can_base)			FDCAN_RXFIA(can_base, 1)

#define FDCAN_TXBC(can_base)			MMIO32(can_base + 0x00C0)
#define FDCAN_TXFQS(can_base)			MMIO32(can_base + 0x00C4)

/** DAY[7:0]: FDCAN core revision date */
#define FDCAN_CREL_DAY_SHIFT			0
#define FDCAN_CREL_DAY_MASK				0xFF

/** MON[7:0]: FDCAN core revision month */
#define FDCAN_CREL_MON_SHIFT			8
#define FDCAN_CREL_MON_MASK				0xFF

/** YEAR[3:0]: FDCAN core revision year */
#define FDCAN_CREL_YEAR_SHIFT			16
#define FDCAN_CREL_YEAR_MASK			0xF

/** SUBSTEP[3:0]: FDCAN core release sub stepping */
#define FDCAN_CREL_SUBSTEP_SHIFT		20
#define FDCAN_CREL_SUBSTEP_MASK			0xF

/** STEP[3:0]: FDCAN core release stepping */
#define FDCAN_CREL_STEP_SHIFT			24
#define FDCAN_CREL_STEP_MASK			0xF

/** REL[3:0]: FDCAN core release number */
#define FDCAN_CREL_REL_SHIFT			28
#define FDCAN_CREL_REL_MASK				0xF


/** DSJW[3:0]: Synchronization jump width */
#define FDCAN_DBTP_DSJW_SHIFT			0
#define FDCAN_DBTP_DSJW_MASK			0xF

/** DTSEG2[3:0]: Data time segment after sample point */
#define FDCAN_DBTP_DTSEG2_SHIFT			4
#define FDCAN_DBTP_DTSEG2_MASK			0xF

/** DTSEG1[4:0]: Data time segment before sample point */
#define FDCAN_DBTP_DTSEG1_SHIFT			8
#define FDCAN_DBTP_DTSEG1_MASK			0x1F

/** DBRP[4:0]: Data bit rate prescaler */
#define FDCAN_DBTP_DBRP_SHIFT			16
#define FDCAN_DBTP_DBRP_MASK			0x1F

#define FDCAN_DBTP_TDC					(1 << 23)

#define FDCAN_TEST_LBCK					(1 << 4)
/** TX[1:0]: Control of transmit pin */
#define FDCAN_TEST_TX_SHIFT				5
#define FDCAN_TEST_TX_MASK				0x3

#define FDCAN_TEST_RX					(1 << 7)

/** WDC[7:0]: RAM watchdog configuration */
#define FDCAN_RWD_WDC_SHIFT				0
#define FDCAN_RWD_WDC_MASK				0xFF

/** WDV[7:0]: RAM watchdog actual value */
#define FDCAN_RWD_WDV_SHIFT				7
#define FDCAN_RWD_WDV_MASK				0xFF

/** @defgroup fdcan_cccr FDCAN CC control register bits
 * @{
 */
#define FDCAN_CCCR_INIT					(1 << 0)
#define FDCAN_CCCR_CCE					(1 << 1)
#define FDCAN_CCCR_ASM					(1 << 2)
#define FDCAN_CCCR_CSA					(1 << 3)
#define FDCAN_CCCR_CSR					(1 << 4)
#define FDCAN_CCCR_MON					(1 << 5)
#define FDCAN_CCCR_DAR					(1 << 6)
#define FDCAN_CCCR_TEST					(1 << 7)
#define FDCAN_CCCR_FDOE					(1 << 8)
#define FDCAN_CCCR_BRSE					(1 << 9)
#define FDCAN_CCCR_PXHD					(1 << 12)
#define FDCAN_CCCR_EFBI					(1 << 13)
#define FDCAN_CCCR_TXP					(1 << 14)
#define FDCAN_CCCR_NISO					(1 << 15)
/**@}*/

/** Timeout for FDCAN_CCCR register INIT bit to accept set value.
 *
 * This timeout is required because FDCAN uses two different clocks
 * feeding two different portions of block. There can be slight delay
 * based on how clocks are set up. While amount of FDCAN_clk /
 * FDCAN_pclk combinations is high and clock speeds may vary a lot,
 * following value has been choosen as sane default. You are free to
 * use any timeout value you want.
 */
#define FDCAN_CCCR_INIT_TIMEOUT		0x0000FFFF

/** NTSEG2[6:0]: Nominal timing segment after sample point length */
#define FDCAN_NBTP_NTSEG2_SHIFT			0
#define FDCAN_NBTP_NTSEG2_MASK			0x7F

/** NTSEG1[7:0]: Nominal timing segment before sample point length */
#define FDCAN_NBTP_NTSEG1_SHIFT			8
#define FDCAN_NBTP_NTSEG1_MASK			0xFF

/** NBRP[8:0]: Norminal timing bit rate prescaler */
#define FDCAN_NBTP_NBRP_SHIFT			16
#define FDCAN_NBTP_NBRP_MASK			0x1FF

/** NSJW[6:0]: Norminal timing resynchronization jumb width*/
#define FDCAN_NBTP_NSJW_SHIFT			25
#define FDCAN_NBTP_NSJW_MASK			0x7F

/** TSS[1:0]: Timestamp select */
#define FDCAN_TSCC_TSS_SHIFT			0
#define FDCAN_TSCC_TSS_MASK				0x3

/** TCP[3:0]: Timestamp counter prescaler */
#define FDCAN_TSCC_TCP_SHIFT			16
#define FDCAN_TSCC_TCP_MASK				0xF


/** TSC[15:0]: Timestamp counter value */
#define FDCAN_TSCV_TSC_SHIFT			0
#define FDCAN_TSCV_TSC_MASK				0xFFFF

#define FDCAN_TOCC_ETOC					(1 << 0)
/** TOS[1:0]: Timeout select */
#define FDCAN_TOCC_TOS_SHIFT			1
#define FDCAN_TOCC_TOS_MASK				0x3

/** TOP[15:0]: Timeout period */
#define FDCAN_TOCC_TOP_SHIFT			16
#define FDCAN_TOCC_TOP_MASK				0xFFFF

/** TOC[15:0]: Timeout counter */
#define FDCAN_TOCV_TOC_SHIFT			0
#define FDCAN_TOCV_TOC_MASK				0xFFFF

/** TEC[7:0]: Transmit error counter */
#define FDCAN_ECR_TEC_SHIFT				0
#define FDCAN_ECR_TEC_MASK				0xFF

/** REC[6:0]: Receive error counter */
#define FDCAN_ECR_REC_SHIFT				8
#define FDCAN_ECR_REC_MASK				0x7F

#define FDCAN_ECR_RP					(1 << 15)
/** CEL[7:0]: CAN error logging */
#define FDCAN_ECR_CEL_SHIFT				16
#define FDCAN_ECR_CEL_MASK				0xFF


/** LEC[2:0]: Last error code */
#define FDCAN_PSR_LEC_SHIFT				0
#define FDCAN_PSR_LEC_MASK				0x7

/** ACT[1:0]: CAN block activity */
#define FDCAN_PSR_ACT_SHIFT				3
#define FDCAN_PSR_ACT_MASK				0x3

#define FDCAN_PSR_EP					(1 << 5)
#define FDCAN_PSR_EW					(1 << 6)
#define FDCAN_PSR_BO					(1 << 7)
/** DLEC[2:0]: Last error code in data section */
#define FDCAN_PSR_DLEC_SHIFT			8
#define FDCAN_PSR_DLEC_MASK				0x7

#define FDCAN_PSR_RESI					(1 << 11)

/* the what? */
#define FDCAN_PSR_RBRSRESI1				(1 << 12)
#define FDCAN_PSR_REDL					(1 << 13)
#define FDCAN_PSR_PXE					(1 << 14)

/** TDCV[6:0]: Transmitter delay compensation value */
#define FDCAN_PSR_TDCV_SHIFT			16
#define FDCAN_PSR_TDCV_MASK				0x7F

/** TDCF[6:0]: Transmitter delay compensation filter window length */
#define FDCAN_TDCR_TDCF_SHIFT			0
#define FDCAN_TDCR_TDCF_MASK			0x7F

/** TDCO[6:0]: Transmitter delay compensation offset */
#define FDCAN_TDCR_TDCO_SHIFT			8
#define FDCAN_TDCR_TDCO_MASK			0x7F

/** @defgroup fdcan_ir FDCAN interrupt register flags
 * @{
 */
#define FDCAN_IR_RF0N					(1 << 0)
#define FDCAN_IR_RF0F					(1 << 1)
#define FDCAN_IR_RF0L					(1 << 2)
#define FDCAN_IR_RF1N					(1 << 3)
#define FDCAN_IR_RF1F					(1 << 4)
#define FDCAN_IR_RF1L					(1 << 5)
#define FDCAN_IR_HPM					(1 << 6)
#define FDCAN_IR_TC						(1 << 7)
#define FDCAN_IR_TCF					(1 << 8)
#define FDCAN_IR_TFE					(1 << 9)
#define FDCAN_IR_TEFN					(1 << 10)
#define FDCAN_IR_TEFF					(1 << 11)
#define FDCAN_IR_TEFL					(1 << 12)
#define FDCAN_IR_TSW					(1 << 13)
#define FDCAN_IR_MRAF					(1 << 14)
#define FDCAN_IR_TOO					(1 << 15)
#define FDCAN_IR_ELO					(1 << 16)
#define FDCAN_IR_EP						(1 << 17)
#define FDCAN_IR_EW						(1 << 18)
#define FDCAN_IR_BO						(1 << 19)
#define FDCAN_IR_WDI					(1 << 20)
#define FDCAN_IR_PEA					(1 << 21)
#define FDCAN_IR_PED					(1 << 22)
#define FDCAN_IR_ARA					(1 << 23)
/**@}*/

/** @defgroup fdcan_ie FDCAN interrupt enable flags
 * @{
 */
#define FDCAN_IE_RF0NE					(1 << 0)
#define FDCAN_IE_RF0FE					(1 << 1)
#define FDCAN_IE_RF0LE					(1 << 2)
#define FDCAN_IE_RF1NE					(1 << 3)
#define FDCAN_IE_RF1FE					(1 << 4)
#define FDCAN_IE_RF1LE					(1 << 5)
#define FDCAN_IE_HPME					(1 << 6)
#define FDCAN_IE_TCE					(1 << 7)
#define FDCAN_IE_TCFE					(1 << 8)
#define FDCAN_IE_TFEE					(1 << 9)
#define FDCAN_IE_TEFNE					(1 << 10)
#define FDCAN_IE_TEFFE					(1 << 11)
#define FDCAN_IE_TEFLE					(1 << 12)
#define FDCAN_IE_TSWE					(1 << 13)
#define FDCAN_IE_MRAFE					(1 << 14)
#define FDCAN_IE_TOOE					(1 << 15)
#define FDCAN_IE_ELOE					(1 << 16)
#define FDCAN_IE_EPE					(1 << 17)
#define FDCAN_IE_EWE					(1 << 18)
#define FDCAN_IE_BOE					(1 << 19)
#define FDCAN_IE_WDIE					(1 << 20)
#define FDCAN_IE_PEAE					(1 << 21)
#define FDCAN_IE_PEDE					(1 << 22)
#define FDCAN_IE_ARAE					(1 << 23)
/**@}*/

/** @defgroup fdcan_ils FDCAN_ILS interrupt line select flags
 * @{
 */
#define FDCAN_ILS_RxFIFO0				(1 << 0)
#define FDCAN_ILS_RxFIFO1				(1 << 1)
#define FDCAN_ILS_SMSG					(1 << 2)
#define FDCAN_ILS_TFERR					(1 << 3)
#define FDCAN_ILS_MISC					(1 << 4)
#define FDCAN_ILS_BERR					(1 << 5)
#define FDCAN_ILS_PERR					(1 << 6)
/**@}*/

#define FDCAN_ILE_INT0					(1 << 0)
#define FDCAN_ILE_INT1					(1 << 1)


/** EIDM[28:0]: Extended ID mask for filtering */
#define FDCAN_XIDAM_EIDM_SHIFT			0
#define FDCAN_XIDAM_EIDM_MASK			0x1FFFFFFF


/** BIDX[2:0]: Buffer index */
#define FDCAN_HPMS_BIDX_SHIFT			0
#define FDCAN_HPMS_BIDX_MASK			0x7

/** MSI[1:0]: Message storage indicator */
#define FDCAN_HPMS_MSI_SHIFT			6
#define FDCAN_HPMS_MSI_MASK				0x3

/** FIDX[4:0]: Filter index */
#define FDCAN_HPMS_FIDX_SHIFT			8
#define FDCAN_HPMS_FIDX_MASK			0x1F

#define FDCAN_HPMS_FLS					(1 << 15)

/** Fill level of Rx FIFOs */
#define FDCAN_RXFIFO_FL_SHIFT			0

/** Get index of Rx FIFOs */
#define FDCAN_RXFIFO_GI_SHIFT			8

/** Put index of Rx FIFOs */
#define FDCAN_RXFIFO_PI_SHIFT			16

#define FDCAN_RXFIFO_FF					(1 << 24)
#define FDCAN_RXFIFO_RFL				(1 << 25)

/** F0FL[3:0]: Fill level of Rx FIFO 0 */
#define FDCAN_RXF0S_F0FL_SHIFT			FDCAN_RXFIFO_FL_SHIFT
#define FDCAN_RXF0S_F0FL_MASK			FDCAN_RXFIFO_FL_MASK

/** F0GI[1:0]: Get index of Rx FIFO 0 */
#define FDCAN_RXF0S_F0GI_SHIFT			FDCAN_RXFIFO_GI_SHIFT
#define FDCAN_RXF0S_F0GI_MASK			FDCAN_RXFIFO_GI_MASK

/** F0PI[1:0]: Put index of Rx FIFO 0 */
#define FDCAN_RXF0S_F0PI_SHIFT			FDCAN_RXFIFO_PI_SHIFT
#define FDCAN_RXF0S_F0PI_MASK			FDCAN_RXFIFO_PI_MASK

#define FDCAN_RXF0S_F0F					FDCAN_RXFIFO_FF
#define FDCAN_RXF0S_RF0L				FDCAN_RXFIFO_RFL

/** Rx FIFOs acknowledge index */
#define FDCAN_RXFIFO_AI_SHIFT			0

/** R0AI[2:0]: Rx FIFO 0 acknowledge index */
#define FDCAN_RXF0A_R0AI_SHIFT			FDCAN_RXFIFO_AI_SHIFT
#define FDCAN_RXF0A_R0AI_MASK			FDCAN_RXFIFO_AI_MASK

/** F1FL[3:1]: Fill level of Rx FIFO 1 */
#define FDCAN_RXF1S_F1FL_SHIFT			FDCAN_RXFIFO_FL_SHIFT
#define FDCAN_RXF1S_F1FL_MASK			FDCAN_RXFIFO_FL_MASK

/** F1GI[1:1]: Get index of Rx FIFO 1 */
#define FDCAN_RXF1S_F1GI_SHIFT			FDCAN_RXFIFO_GI_SHIFT
#define FDCAN_RXF1S_F1GI_MASK			FDCAN_RXFIFO_GI_MASK

/** F1PI[1:1]: Put index of Rx FIFO 1 */
#define FDCAN_RXF1S_F1PI_SHIFT			FDCAN_RXFIFO_PI_SHIFT
#define FDCAN_RXF1S_F1PI_MASK			FDCAN_RXFIFO_PI_MASK

#define FDCAN_RXF1S_F1F					FDCAN_RXFIFO_FF
#define FDCAN_RXF1S_RF1L				FDCAN_RXFIFO_RFL

/** R1AI[2:0]: Rx FIFO 1 acknowledge index */
#define FDCAN_RXF1A_R1AI_SHIFT			FDCAN_RXFIFO_AI_SHIFT
#define FDCAN_RXF1A_R1AI_MASK			FDCAN_RXFIFO_AI_MASK

#define FDCAN_TXBC_TFQM					(1 << 24)

/** TFFL[2:0]: Tx FIFO free level */
#define FDCAN_TXFQS_TFFL_SHIFT			0

/** TFGI[1:0]: Tx FIFO get index */
#define FDCAN_TXFQS_TFGI_SHIFT			8

/** TFQPI[1:0]: Tx FIFO put index */
#define FDCAN_TXFQS_TFQPI_SHIFT			16

#define FDCAN_TXFQS_TFQF				(1 << 21)

/** @defgroup fdcan_txbrp FDCAN_TXBRP Transmit request pending bits
 * @{
 */
#define FDCAN_TXBRP_TRP0				(1 << 0)
#define FDCAN_TXBRP_TRP1				(1 << 1)
#define FDCAN_TXBRP_TRP2				(1 << 2)
/**@}*/

/** @defgroup fdcan_txbar FDCAN_TXBAR Transmit buffer add request bits
 * @{
 */
#define FDCAN_TXBAR_AR0					(1 << 0)
#define FDCAN_TXBAR_AR1					(1 << 1)
#define FDCAN_TXBAR_AR2					(1 << 2)
/**@}*/

/** @defgroup fdcan_txbcr FDCAN_TXBCR Transmit buffer cancel request bits
 * @{
 */
#define FDCAN_TXBCR_CR0					(1 << 0)
#define FDCAN_TXBCR_CR1					(1 << 1)
#define FDCAN_TXBCR_CR2					(1 << 2)
/**@}*/

/** @defgroup fdcan_txbto FDCAN_TXBTO Transmit buffer transfer occured bits
 * @{
 */
#define FDCAN_TXBTO_TO0					(1 << 0)
#define FDCAN_TXBTO_TO1					(1 << 1)
#define FDCAN_TXBTO_TO2					(1 << 2)
/**@}*/

/** @defgroup fdcan_txbcf FDCAN_TXBCF Transmit buffer cancellation finished bits
 * @{
 */
#define FDCAN_TXBCF_CF0					(1 << 0)
#define FDCAN_TXBCF_CF1					(1 << 1)
#define FDCAN_TXBCF_CF2					(1 << 2)
/**@}*/

/** @defgroup fdcan_txbtie FDCAN_TXBTIE Transmit interrupt enable bits
 *
 * Each bit enables or disables transmit interrupt for transmit buffer
 * slot.
 * @{
 */
#define FDCAN_TXBTIE_TIE0				(1 << 0)
#define FDCAN_TXBTIE_TIE1				(1 << 1)
#define FDCAN_TXBTIE_TIE2				(1 << 2)
/**@}*/

/** @defgroup fdcan_txbcie FDCAN_TXBCIE Transmit cancelled interrupt enable bits
 *
 * Each bit enables or disables transmit cancelled interrupt for transmit buffer
 * slot.
 * @{
 */
#define FDCAN_TXBCIE_CFIE0				(1 << 0)
#define FDCAN_TXBCIE_CFIE1				(1 << 1)
#define FDCAN_TXBCIE_CFIE2				(1 << 2)
/**@}*/

/** EFFL[2:0]: Event FIFO fill level*/
#define FDCAN_TXEFS_EFFL_SHIFT			0

/** EFG[1:0]: Event FIFO get index */
#define FDCAN_TXEFS_EFGI_SHIFT			8

/** EFPI[1:0]: Event FIFO put index */
#define FDCAN_TXEFS_EFPI_SHIFT			16

#define FDCAN_TXEFS_EFF					(1 << 24)
#define FDCAN_TXEFS_TEF					(1 << 25)

/** EFAI[1:0]: Event FIFO acknowledge index */
#define FDCAN_TXEFA_EFAI_SHIFT			0
#define FDCAN_TXEFA_EFAI_MASK			0x3


/* --- FD-CAN memory block defines------------------------------------------ */

/** Structure describing standard ID filter.
 * Standard ID filter is composed of one 32bit value.
 * This region of memory cannot be accessed in quantities less than 32bits.
 */
struct fdcan_standard_filter {
	/** Aggregate of filter type, filter action and two IDs	*/
	uint32_t type_id1_conf_id2;
};

#define FDCAN_SFT_SHIFT					30
#define FDCAN_SFT_MASK					0x3

/** @defgroup fdcan_sft Standard ID filter match type
 *
 * Matching strategy for standard ID filters.
 * @{
 */
/** Filter matches all messages in range from id1 to id2. */
#define FDCAN_SFT_RANGE					0x0

/** Filter matches messages with id1 or id2 */
#define FDCAN_SFT_DUAL					0x1

/** Filter matches messages which match id1 after being unmasked
 * using id2. */
#define FDCAN_SFT_ID_MASK				0x2

/** Disable this filter. */
#define FDCAN_SFT_DISABLE				0x3
/**@}*/

#define FDCAN_SFEC_SHIFT				27
#define FDCAN_SFEC_MASK					0x7

/** @defgroup fdcan_sfec Standard ID filter action
 *
 * Defines possible actions for standard ID filters. All actions except
 * of @ref FDCAN_SFEC_PRIO cause filter matching to terminate immediately
 * with desired outcome. FDCAN_SFEC_PRIO sets priority flag for message
 * and continues processing remaining filters.
 * @{
 */

/** Filter is disabled. No matchin occurrs. */
#define FDCAN_SFEC_DISABLE				0x0

/** Put message into FIFO0 */
#define FDCAN_SFEC_FIFO0				0x1

/** Put message into FIFO1 */
#define FDCAN_SFEC_FIFO1				0x2

/** Reject message */
#define FDCAN_SFEC_REJECT				0x3

/** Treat message as priority message (and continue processing further rules) */
#define FDCAN_SFEC_PRIO					0x4

/** Treat message as priority and put it into FIFO0 */
#define FDCAN_SFEC_PRIO_FIFO0			0x5

/** Treat message as priority and put it into FIFO1 */
#define FDCAN_SFEC_PRIO_FIFO1			0x6
/**@}*/

/* SFEC = 0x7 is unused */

#define FDCAN_SFID1_SHIFT				16
#define FDCAN_SFID1_MASK				0x7FF

#define FDCAN_SFID2_SHIFT				0
#define FDCAN_SFID2_MASK				0x7FF

/** Structure describing extended ID filters.
 * Extended ID filter is composed of two 32bit values.
 * This region of memory cannot be accessed in quantities less than 32bits.
 */
struct fdcan_extended_filter {
	/** Aggregate of filter action and extended ID */
	uint32_t conf_id1;
	/** Aggregate of filter type and extended ID or mask */
	uint32_t type_id2;
};

#define FDCAN_EFEC_SHIFT				29
#define FDCAN_EFEC_MASK					0x7

/** @defgroup fdcan_efec Extended ID filter action
 *
 * These are possible actions, extended filter can have. If filter is
 * disabled, then no matching is performed. All other actions except of
 * @ref FDCAN_EFEC_PRIO cause matching to terminate with required outcome.
 * FDCAN_EFEC_PRIO marks message as priority and continues matching.
 * @{
 */

/** Disable this filter. */
#define FDCAN_EFEC_DISABLE				0x0

/** Put message into FIFO0 */
#define FDCAN_EFEC_FIFO0				0x1

/** Put message into FIFO1 */
#define FDCAN_EFEC_FIFO1				0x2

/** Reject message */
#define FDCAN_EFEC_REJECT				0x3

/** Treat message as priority message (and continue processing further rules) */
#define FDCAN_EFEC_PRIO					0x4

/** Treat message as priority and put it into FIFO0 */
#define FDCAN_EFEC_PRIO_FIFO0			0x5

/** Treat message as priority and put it into FIFO1 */
#define FDCAN_EFEC_PRIO_FIFO1			0x6
/**@}*/

#define FDCAN_EFID1_SHIFT				0
#define FDCAN_EFID1_MASK				0x1FFFFFFF

#define FDCAN_EFT_SHIFT					30
#define FDCAN_EFT_MASK					0x3

/** @defgroup fdcan_eft Extended ID filter match type
 *
 * Matching strategy for extended ID filters.
 * @{
 */
/** Filter matches all messages in range from id1 to id2. */
#define FDCAN_EFT_RANGE					0x0

/** Filter matches messages with id1 or id2 */
#define FDCAN_EFT_DUAL					0x1

/** Filter matches messages which match id1 after being unmasked
 * using id2. */
#define FDCAN_EFT_ID_MASK				0x2

/** Similar to @ref FDCAN_EFT_RANGE except of ignoring global mask
 * set using @ref FDCAN_XIDAM register.
 */
#define FDCAN_EFT_RANGE_NOXIDAM			0x3
/**@}*/

#define FDCAN_EFID2_SHIFT				0
#define FDCAN_EFID2_MASK				0x1FFFFFFF

/** Structure describing receive FIFO element.
 * Receive FIFO element consists of 2 32bit values for header
 * and 16 32bit values for message payload.
 * This area of memory can only be accessed in 32bit quantities
 */
struct fdcan_rx_fifo_element {
	/** Aggregate of message identifier and flags. */
	uint32_t identifier_flags;
	/** Aggregate of filter match ID, transfer format, DLC and timestamp */
	uint32_t filt_fmt_dlc_ts;
	/** Message payload data */
	uint32_t data[64 / sizeof(uint32_t)];
};

/** Structure describing transmit event element.
 * Transmit event element consists of 2 32bit values.
 * This area of memory can only be accessed in 32bit quantities
 */
struct fdcan_tx_event_element {
	/** Aggregate of message identifier and flags. */
	uint32_t identifier_flags;

	/** Aggregate of event ID, transfer format, DLC and timestamp */
	uint32_t evt_fmt_dlc_ts;
};

/** Structure describing transmit buffer element.
 * Transmit buffer consists of 2 32bit values for header
 * and 16 32bit values for message payload.
 * This area of memory can only be accessed in 32bit quantities
 */
struct fdcan_tx_buffer_element {
	/** Aggregate of message identifier and flags. */
	uint32_t identifier_flags;

	/** Aggregate of event ID, transfer format and DLC */
	uint32_t evt_fmt_dlc_res;
	/** Message payload data */
	uint32_t data[64 / sizeof(uint32_t)];
};

/** @defgroup fdcan_fifo_flags FIFO / buffer flags
 * @{
 */
#define FDCAN_FIFO_ESI					(1 << 31)
#define FDCAN_FIFO_XTD					(1 << 20)
#define FDCAN_FIFO_RTR					(1 << 29)
#define FDCAN_FIFO_EFC					(1 << 23)
#define FDCAN_FIFO_FDF					(1 << 21)
#define FDCAN_FIFO_BRS					(1 << 20)
/**@}*/

#define FDCAN_FIFO_EID_SHIFT			0
#define FDCAN_FIFO_EID_MASK				0x1FFFFFFF

#define FDCAN_FIFO_SID_SHIFT			18
#define FDCAN_FIFO_SID_MASK				0x7FF

#define FDCAN_FIFO_DLC_SHIFT			16
#define FDCAN_FIFO_DLC_MASK				0xF

#define FDCAN_FIFO_MM_SHIFT				24
#define FDCAN_FIFO_MM_MASK				0xFF

#define FDCAN_FIFO_ANMF					(1 << 31)
#define FDCAN_FIFO_FIDX_SHIFT			24
#define FDCAN_FIFO_FIDX_MASK			0x7F

#define FDCAN_FIFO_RXTS_SHIFT			0
#define FDCAN_FIFO_RXTS_MASK			0xFFFF


/** @defgroup fdcan_error FDCAN error return values
 * @{
 */

/** No error. Operation finished successfully */
#define FDCAN_E_OK						0

/** Value provided was out of range */
#define FDCAN_E_OUTOFRANGE				-1

/** Timeout waiting for FDCAN block to accept INIT bit change */
#define FDCAN_E_TIMEOUT					-2

/** Value provided was invalid (FIFO index, FDCAN block base address, length, etc.) */
#define FDCAN_E_INVALID					-3

/** Device is busy: Transmit buffer is full, unable to queue additional message or device
 * is outside of INIT mode and cannot perform desired operation. */
#define FDCAN_E_BUSY					-4

/** Receive buffer is empty, unable to read any new message */
#define FDCAN_E_NOTAVAIL				-5

/**@}*/

/**@}*/


BEGIN_DECLS

int fdcan_init(uint32_t canport, uint32_t timeout);

void fdcan_set_can(uint32_t canport, bool auto_retry_disable, bool rx_fifo_locked,
		bool tx_queue_mode, bool silent, uint32_t n_sjw, uint32_t n_ts1, uint32_t n_ts2,
		uint32_t n_br_presc);

void fdcan_set_fdcan(uint32_t canport, bool brs_enable, bool fd_op_enable,
		uint32_t f_sjw, uint32_t f_ts1, uint32_t f_ts2, uint32_t f_br_presc);

void fdcan_set_test(uint32_t canport, bool testing, bool loopback);

void fdcan_init_filter(uint32_t canport, uint8_t std_filt, uint8_t ext_filt);

int fdcan_start(uint32_t canport, uint32_t timeout);

int fdcan_get_init_state(uint32_t canport);

void fdcan_set_std_filter(uint32_t canport, uint32_t nr,
		uint8_t id_list_mode, uint32_t id1, uint32_t id2,
		uint8_t action);

void fdcan_set_ext_filter(uint32_t canport, uint32_t nr,
		uint8_t id_list_mode, uint32_t id1, uint32_t id2,
		uint8_t action);

void fdcan_enable_irq(uint32_t canport, uint32_t irq);
void fdcan_disable_irq(uint32_t canport, uint32_t irq);

int fdcan_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
		bool fdcan_fmt, bool btr_switch, uint8_t length, const uint8_t *data);

int fdcan_receive(uint32_t canport, uint8_t fifo, bool release, uint32_t *id,
		bool *ext, bool *rtr, uint8_t *fmi, uint8_t *length,
		uint8_t *data, uint16_t *timestamp);

void fdcan_release_fifo(uint32_t canport, uint8_t fifo);

bool fdcan_available_tx(uint32_t canport);
bool fdcan_available_rx(uint32_t canport, uint8_t fifo);

int fdcan_cccr_init_cfg(uint32_t canport, bool set, uint32_t timeout);
struct fdcan_standard_filter *fdcan_get_flssa_addr(uint32_t canport);
struct fdcan_extended_filter *fdcan_get_flesa_addr(uint32_t canport);

struct fdcan_rx_fifo_element *fdcan_get_rxfifo_addr(uint32_t canport,
		unsigned fifo_id, unsigned element_id);
unsigned fdcan_get_fifo_element_size(uint32_t canport, unsigned fifo_id);

struct fdcan_tx_event_element *fdcan_get_txevt_addr(uint32_t canport);
struct fdcan_tx_buffer_element *fdcan_get_txbuf_addr(uint32_t canport, unsigned element_id);
unsigned fdcan_get_txbuf_element_size(uint32_t canport);
void fdcan_set_fifo_locked_mode(uint32_t canport, bool locked);
uint32_t fdcan_length_to_dlc(uint8_t length);
uint8_t fdcan_dlc_to_length(uint32_t dlc);

END_DECLS

