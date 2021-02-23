/** @defgroup fdcan_defines FDCAN Defines

@ingroup STM32G_defines

@brief <b>libopencm3 Defined Constants and Types for STM32 FD-CAN</b>

@author @htmlonly &copy @endhtmlonly 2021 Eduard Drusa <ventyl8 at netkosice dot sk>

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2021 Eduard Drusa <ventyl86@netkosice.sk>
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



#ifndef LIBOPENCM3_FDCAN_H
#define LIBOPENCM3_FDCAN_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/** @{ */

/* FDCAN block base addresses. Used in functions to identify FDCAN block being manipulated. */

/** @defgroup fdcan_block FDCAN block base addresses
 * @{
 */
#define CAN1							FDCAN1_BASE
#define CAN2							FDCAN2_BASE
#define CAN3							FDCAN3_BASE
/**@}*/


/** @defgroup fdcan_fifo Named constants for FIFOs
 * @{
 */
#define FDCAN_FIFO0						0
#define FDCAN_FIFO1						1
/**@}*/


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
#define FDCAN_RXGFC(can_base)			MMIO32(can_base + 0x0080)
#define FDCAN_XIDAM(can_base)			MMIO32(can_base + 0x0084)
#define FDCAN_HPMS(can_base)			MMIO32(can_base + 0x0088)
#define FDCAN_RXF0S(can_base)			MMIO32(can_base + 0x0090)
#define FDCAN_RXF0A(can_base)			MMIO32(can_base + 0x0094)
#define FDCAN_RXF1S(can_base)			MMIO32(can_base + 0x0098)
#define FDCAN_RXF1A(can_base)			MMIO32(can_base + 0x009C)
#define FDCAN_TXBC(can_base)			MMIO32(can_base + 0x00C0)
#define FDCAN_TXFQS(can_base)			MMIO32(can_base + 0x00C4)
#define FDCAN_TXBRP(can_base)			MMIO32(can_base + 0x00C8)
#define FDCAN_TXBAR(can_base)			MMIO32(can_base + 0x00CC)
#define FDCAN_TXBCR(can_base)			MMIO32(can_base + 0x00D0)
#define FDCAN_TXBTO(can_base)			MMIO32(can_base + 0x00D4)
#define FDCAN_TXBCF(can_base)			MMIO32(can_base + 0x00D8)
#define FDCAN_TXBTIE(can_base)			MMIO32(can_base + 0x00DC)
#define FDCAN_TXBCIE(can_base)			MMIO32(can_base + 0x00E0)
#define FDCAN_TXEFS(can_base)			MMIO32(can_base + 0x00E4)
#define FDCAN_TXEFA(can_base)			MMIO32(can_base + 0x00E8)
#define FDCAN_CKDIV(can_base)			MMIO32(can_base + 0x0100)

/** @brief Helper macro for defining bitmasks
 * Will return number having n LSB set
 * @param n how many bits mask occupies
 */
#define __BITS(n)						((1 << n) - 1)

/* DAY[7:0]: FDCAN core revision date */
#define FDCAN_CREL_DAY_SHIFT			0
#define FDCAN_CREL_DAY_MASK				(__BITS(8) << FDCAN_CREL_DAY_SHIFT)

/* MON[7:0]: FDCAN core revision month */
#define FDCAN_CREL_MON_SHIFT			8
#define FDCAN_CREL_MON_MASK				(__BITS(8) << FDCAN_CREL_MON_SHIFT)

/* YEAR[3:0]: FDCAN core revision year */
#define FDCAN_CREL_YEAR_SHIFT			16
#define FDCAN_CREL_YEAR_MASK			(__BITS(4) << FDCAN_CREL_YEAR_SHIFT)

/* SUBSTEP[3:0]: FDCAN core release sub stepping */
#define FDCAN_CREL_SUBSTEP_SHIFT		20
#define FDCAN_CREL_SUBSTEP_MASK			(__BITS(4) << FDCAN_CREL_SUBSTEP_SHIFT)

/* STEP[3:0]: FDCAN core release stepping */
#define FDCAN_CREL_STEP_SHIFT			24
#define FDCAN_CREL_STEP_MASK			(__BITS(4) << FDCAN_CREL_STEP_SHIFT)

/* REL[3:0]: FDCAN core release number */
#define FDCAN_CREL_REL_SHIFT			28
#define FDCAN_CREL_REL_MASK				(__BITS(4) << FDCAN_CREL_REL_SHIFT)


/* DSJW[3:0]: Synchronization jump width */
#define FDCAN_DBTP_DSJW_SHIFT			0
#define FDCAN_DBTP_DSJW_MASK			(__BITS(4) << FDCAN_DBTP_DSJW_SHIFT)

#define FDCAN_DBTP_DSJW_TQ(tq)			((tq) << FDCAN_DBTP_DSJW_SHIFT)

/* DTSEG2[3:0]: Data time segment after sample point */
#define FDCAN_DBTP_DTSEG2_SHIFT			4
#define FDCAN_DBTP_DTSEG2_MASK			(__BITS(4) << FDCAN_DBTP_DTSEG2_SHIFT)

#define FDCAN_DBTP_DTSEG2_TQ(tq)		((tq) << FDCAN_DBTP_DTSEG2_SHIFT)

/* DTSEG1[4:0]: Data time segment before sample point */
#define FDCAN_DBTP_DTSEG1_SHIFT			8
#define FDCAN_DBTP_DTSEG1_MASK			(__BITS(5) << FDCAN_DBTP_DTSEG1_SHIFT)

#define FDCAN_DBTP_DTSEG1_TQ(tq)		((tq) << FDCAN_DBTP_DTSEG1_SHIFT)

/* DBRP[4:0]: Data bit rate prescaler */
#define FDCAN_DBTP_DBRP_SHIFT			16
#define FDCAN_DBTP_DBRP_MASK			(__BITS(5) << FDCAN_DBTP_DBRP_SHIFT)

#define FDCAN_DBTP_TDC					(1 << 23)

#define FDCAN_TEST_LBCK					(1 << 4)
/* TX[1:0]: Control of transmit pin */
#define FDCAN_TEST_TX_SHIFT				5
#define FDCAN_TEST_TX_MASK				(__BITS(2) << FDCAN_TEST_TX_SHIFT)

#define FDCAN_TEST_RX					(1 << 7)

/* WDC[7:0]: RAM watchdog configuration */
#define FDCAN_RWD_WDC_SHIFT				0
#define FDCAN_RWD_WDC_MASK				(__BITS(8) << FDCAN_RWD_WDC_SHIFT)

/* WDV[7:0]: RAM watchdog actual value */
#define FDCAN_RWD_WDV_SHIFT				7
#define FDCAN_RWD_WDV_MASK				(__BITS(8) << FDCAN_RWD_WDV_SHIFT)

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

/* NTSEG2[6:0]: Nominal timing segment after sample point length */
#define FDCAN_NBTP_NTSEG2_SHIFT			0
#define FDCAN_NBTP_NTSEG2_MASK			(__BITS(7) << FDCAN_NBTP_NTSEG2_SHIFT)

/** Obtain value for use as TSEG2 for normal speed.
 * @param ts amount of tq
 * @returns value suitable for use with fdcan_init
 */
#define FDCAN_NBTP_NTSEG2_TQ(tq)		((tq) << FDCAN_NBTP_NTSEG2_SHIFT)

/* NTSEG1[7:0]: Nominal timing segment before sample point length */
#define FDCAN_NBTP_NTSEG1_SHIFT			8
#define FDCAN_NBTP_NTSEG1_MASK			(__BITS(8) << FDCAN_NBTP_NTSEG1_SHIFT)

/** Obtain value for use as TSEG1 for normal speed.
 * @param ts amount of tq
 * @returns value suitable for use with fdcan_init
 */
#define FDCAN_NBTP_NTSEG1_TQ(tq)		((tq) << FDCAN_NBTP_NTSEG1_SHIFT)

/* NBRP[8:0]: Norminal timing bit rate prescaler */
#define FDCAN_NBTP_NBRP_SHIFT			16
#define FDCAN_NBTP_NBRP_MASK			(__BITS(9) << FDCAN_NBTP_NBRP_SHIFT)

/* NSJW[6:0]: Norminal timing resynchronization jumb width*/
#define FDCAN_NBTP_NSJW_SHIFT			25
#define FDCAN_NBTP_NSJW_MASK			(__BITS(7) << FDCAN_NBTP_NSJW_SHIFT)

/** Obtain value for use as TSJW for normal speed.
 * @param ts amount of tq
 * @returns value suitable for use with fdcan_init
 */
#define FDCAN_NBTP_NSJW_TQ(tq)			((tq) << FDCAN_NBTP_NSJW_SHIFT)

/* TSS[1:0]: Timestamp select */
#define FDCAN_TSCC_TSS_SHIFT			0
#define FDCAN_TSCC_TSS_MASK				(__BITS(2) << FDCAN_TSCC_TSS_SHIFT)

/* TCP[3:0]: Timestamp counter prescaler */
#define FDCAN_TSCC_TCP_SHIFT			16
#define FDCAN_TSCC_TCP_MASK				(__BITS(4) << FDCAN_TSCC_TCP_SHIFT)


/* TSC[15:0]: Timestamp counter value */
#define FDCAN_TSCV_TSC_SHIFT			0
#define FDCAN_TSCV_TSC_MASK				(__BITS(16) << FDCAN_TSCV_TSC_SHIFT)

#define FDCAN_TOCC_ETOC					(1 << 0)
/* TOS[1:0]: Timeout select */
#define FDCAN_TOCC_TOS_SHIFT			1
#define FDCAN_TOCC_TOS_MASK				(__BITS(2) << FDCAN_TOCC_TOS_SHIFT)

/* TOP[15:0]: Timeout period */
#define FDCAN_TOCC_TOP_SHIFT			16
#define FDCAN_TOCC_TOP_MASK				(__BITS(16) << FDCAN_TOCC_TOP_SHIFT)

/* TOC[15:0]: Timeout counter */
#define FDCAN_TOCV_TOC_SHIFT			0
#define FDCAN_TOCV_TOC_MASK				(__BITS(16) << FDCAN_TOCV_TOC_SHIFT)

/* TEC[7:0]: Transmit error counter */
#define FDCAN_ECR_TEC_SHIFT				0
#define FDCAN_ECR_TEC_MASK				(__BITS(8) << FDCAN_ECR_TEC_SHIFT)

/* REC[6:0]: Receive error counter */
#define FDCAN_ECR_REC_SHIFT				8
#define FDCAN_ECR_REC_MASK				(__BITS(7) << FDCAN_ECR_REC_SHIFT)

#define FDCAN_ECR_RP					(1 << 15)
/* CEL[7:0]: CAN error logging */
#define FDCAN_ECR_CEL_SHIFT				16
#define FDCAN_ECR_CEL_MASK				(__BITS(8) << FDCAN_ECR_CEL_SHIFT)


/* LEC[2:0]: Last error code */
#define FDCAN_PSR_LEC_SHIFT				0
#define FDCAN_PSR_LEC_MASK				(__BITS(3) << FDCAN_PSR_LEC_SHIFT)

/* ACT[1:0]: CAN block activity */
#define FDCAN_PSR_ACT_SHIFT				3
#define FDCAN_PSR_ACT_MASK				(__BITS(2) << FDCAN_PSR_ACT_SHIFT)

#define FDCAN_PSR_EP					(1 << 5)
#define FDCAN_PSR_EW					(1 << 6)
#define FDCAN_PSR_BO					(1 << 7)
/* DLEC[2:0]: Last error code in data section */
#define FDCAN_PSR_DLEC_SHIFT			8
#define FDCAN_PSR_DLEC_MASK				(__BITS(3) << FDCAN_PSR_DLEC_SHIFT)

#define FDCAN_PSR_RESI					(1 << 11)

/* the what? */
#define FDCAN_PSR_RBRSRESI1				(1 << 12)
#define FDCAN_PSR_REDL					(1 << 13)
#define FDCAN_PSR_PXE					(1 << 14)

/* TDCV[6:0]: Transmitter delay compensation value */
#define FDCAN_PSR_TDCV_SHIFT			16
#define FDCAN_PSR_TDCV_MASK				(__BITS(7) << FDCAN_PSR_TDCV_SHIFT)

/* TDCF[6:0]: Transmitter delay compensation filter window length */
#define FDCAN_TDCR_TDCF_SHIFT			0
#define FDCAN_TDCR_TDCF_MASK			(__BITS(7) << FDCAN_TDCR_TDCF_SHIFT)

/* TDCO[6:0]: Transmitter delay compensation offset */
#define FDCAN_TDCR_TDCO_SHIFT			8
#define FDCAN_TDCR_TDCO_MASK			(__BITS(7) << FDCAN_TDCR_TDCO_SHIFT)

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

#define FDCAN_RXGFC_RRFE				(1 << 0)
#define FDCAN_RXGFC_RRFS				(1 << 1)
/* ANFE[1:0]: Accept non-matching frames w/ extended ID */
#define FDCAN_RXGFC_ANFE_SHIFT			2
#define FDCAN_RXGFC_ANFE_MASK			(__BITS(2) << FDCAN_RXGFC_ANFE_SHIFT)

/* ANFS[1:0]: Accept non-matching frames w/ standard ID */
#define FDCAN_RXGFC_ANFS_SHIFT			4
#define FDCAN_RXGFC_ANFS_MASK			(__BITS(2) << FDCAN_RXGFC_ANFS_SHIFT)

#define FDCAN_RXGFC_F1OM				(1 << 8)
#define FDCAN_RXGFC_F0OM				(1 << 9)
/* LSS[4:0]: List size of standard ID filters */
#define FDCAN_RXGFC_LSS_SHIFT			16
#define FDCAN_RXGFC_LSS_MASK			(__BITS(5) << FDCAN_RXGFC_LSS_SHIFT)

/* LSE[3:0]: List size of extended ID filters */
#define FDCAN_RXGFC_LSE_SHIFT			24
#define FDCAN_RXGFC_LSE_MASK			(__BITS(4) << FDCAN_RXGFC_LSE_SHIFT)


/* EIDM[28:0]: Extended ID mask for filtering */
#define FDCAN_XIDAM_EIDM_SHIFT			0
#define FDCAN_XIDAM_EIDM_MASK			(__BITS(29) << FDCAN_XIDAM_EIDM_SHIFT)


/* BIDX[2:0]: Buffer index */
#define FDCAN_HPMS_BIDX_SHIFT			0
#define FDCAN_HPMS_BIDX_MASK			(__BITS(3) << FDCAN_HPMS_BIDX_SHIFT)

/* MSI[1:0]: Message storage indicator */
#define FDCAN_HPMS_MSI_SHIFT			6
#define FDCAN_HPMS_MSI_MASK				(__BITS(2) << FDCAN_HPMS_MSI_SHIFT)

/* FIDX[4:0]: Filter index */
#define FDCAN_HPMS_FIDX_SHIFT			8
#define FDCAN_HPMS_FIDX_MASK			(__BITS(5) << FDCAN_HPMS_FIDX_SHIFT)

#define FDCAN_HPMS_FLS					(1 << 15)

/* F0FL[3:0]: Fill level of Rx FIFO 0 */
#define FDCAN_RXF0S_F0FL_SHIFT			0
#define FDCAN_RXF0S_F0FL_MASK			(__BITS(4) << FDCAN_RXF0S_F0FL_SHIFT)

/* F0GI[1:0]: Get index of Rx FIFO 0 */
#define FDCAN_RXF0S_F0GI_SHIFT			8
#define FDCAN_RXF0S_F0GI_MASK			(__BITS(2) << FDCAN_RXF0S_F0GI_SHIFT)

/* F0PI[1:0]: Put index of Rx FIFO 0 */
#define FDCAN_RXF0S_F0PI_SHIFT			16
#define FDCAN_RXF0S_F0PI_MASK			(__BITS(2) << FDCAN_RXF0S_F0PI_SHIFT)

#define FDCAN_RXF0S_F0F					(1 << 24)
#define FDCAN_RXF0S_RF0L				(1 << 25)

/* R0AI[2:0]: Rx FIFO 0 acknowledge index */
#define FDCAN_RXF0A_R0AI_SHIFT			0
#define FDCAN_RXF0A_R0AI_MASK			(__BITS(3) << FDCAN_RXF0A_R0AI_SHIFT)


/* F1FL[3:0]: Fill level of Rx FIFO 1 */
#define FDCAN_RXF1S_F1FL_SHIFT			0
#define FDCAN_RXF1S_F1FL_MASK			(__BITS(4) << FDCAN_RXF1S_F1FL_SHIFT)

/* F1GI[1:0]: Get index of Rx FIFO 1 */
#define FDCAN_RXF1S_F1GI_SHIFT			8
#define FDCAN_RXF1S_F1GI_MASK			(__BITS(2) << FDCAN_RXF1S_F1GI_SHIFT)

/* F1PI[1:0]: Put index of Rx FIFO 1 */
#define FDCAN_RXF1S_F1PI_SHIFT			16
#define FDCAN_RXF1S_F1PI_MASK			(__BITS(2) << FDCAN_RXF1S_F1PI_SHIFT)

#define FDCAN_RXF1S_F1F					(1 << 24)
#define FDCAN_RXF1S_RF1L				(1 << 25)

/* R1AI[2:0]: Rx FIFO 1 acknowledge index */
#define FDCAN_RXF1A_R1AI_SHIFT			0
#define FDCAN_RXF1A_R1AI_MASK			(__BITS(3) << FDCAN_RXF1A_R1AI_SHIFT)


#define FDCAN_TXBC_TFQM					(1 << 24)

/* TFFL[2:0]: Tx FIFO free level */
#define FDCAN_TXFQS_TFFL_SHIFT			0
#define FDCAN_TXFQS_TFFL_MASK			(__BITS(3) << FDCAN_TXFQS_TFFL_SHIFT)

/* TFGI[1:0]: Tx FIFO get index */
#define FDCAN_TXFQS_TFGI_SHIFT			0
#define FDCAN_TXFQS_TFGI_MASK			(__BITS(2) << FDCAN_TXFQS_TFGI_SHIFT)

/* TFQPI[1:0]: Tx FIFO put index */
#define FDCAN_TXFQS_TFQPI_SHIFT			0
#define FDCAN_TXFQS_TFQPI_MASK			(__BITS(2) << FDCAN_TXFQS_TFQPI_SHIFT)

#define FDCAN_TXFQS_TFQF				(1 << 0)

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
 * @{
 */
#define FDCAN_TXBTIE_TIE0				(1 << 0)
#define FDCAN_TXBTIE_TIE1				(1 << 1)
#define FDCAN_TXBTIE_TIE2				(1 << 2)
/**@}*/

/** @defgroup fdcan_txbcie FDCAN_TXBCIE Transmit cancelled interrupt enable bits
 * @{
 */
#define FDCAN_TXBCIE_CFIE0				(1 << 0)
#define FDCAN_TXBCIE_CFIE1				(1 << 1)
#define FDCAN_TXBCIE_CFIE2				(1 << 2)
/**@}*/

/* EFFL[2:0]: Event FIFO fill level*/
#define FDCAN_TXEFS_EFFL_SHIFT			0
#define FDCAN_TXEFS_EFFL_MASK			(__BITS(3) << FDCAN_TXEFS_EFFL_SHIFT)

/* EFG[1:0]: Event FIFO get index */
#define FDCAN_TXEFS_EFGI_SHIFT			8
#define FDCAN_TXEFS_EFGI_MASK			(__BITS(2) << FDCAN_TXEFS_EFGI_SHIFT)

/* EFPI[1:0]: Event FIFO put index */
#define FDCAN_TXEFS_EFPI_SHIFT			16
#define FDCAN_TXEFS_EFPI_MASK			(__BITS(2) << FDCAN_TXEFS_EFPI_SHIFT)

#define FDCAN_TXEFS_EFF					(1 << 24)
#define FDCAN_TXEFS_TEF					(1 << 25)

/* EFAI[1:0]: Event FIFO acknowledge index */
#define FDCAN_TXEFA_EFAI_SHIFT			0
#define FDCAN_TXEFA_EFAI_MASK			(__BITS(2) << FDCAN_TXEFA_EFAI_SHIFT)


/* PDIV[3:0]: Input clock divider */
#define FDCAN_CKDIV_PDIV_SHIFT			0
#define FDCAN_CKDIV_PDIV_MASK			(__BITS(4) << FDCAN_CKDIV_PDIV_SHIFT)

/* --- FD-CAN memory block defines------------------------------------------ */

/** Structure describing standard ID filter.
 * Standard ID filter is composed of one 32bit value.
 * This region of memory cannot be accessed in quantities less than 32bits.
 */
struct FDCAN_StandardFilter {
	uint32_t type_id1_conf_id2; 		//<< aggregate of filter type, filter action and two IDs
};

#define FDCAN_SFT_SHIFT					30
#define FDCAN_SFT_MASK					(__BITS(2) << FDCAN_SFT_SHIFT)

/** @defgroup fdcan_sft Standard ID filter match type
 * @{
 */
#define FDCAN_SFT_RANGE					(0x0 << FDCAN_SFT_SHIFT)	
#define FDCAN_SFT_DUAL					(0x1 << FDCAN_SFT_SHIFT)
#define FDCAN_SFT_ID_MASK				(0x2 << FDCAN_SFT_SHIFT)
#define FDCAN_SFT_DISABLE				(0x3 << FDCAN_SFT_SHIFT)
/**@}*/

#define FDCAN_SFEC_SHIFT				27
#define FDCAN_SFEC_MASK 				(__BITS(3) << FDCAN_SFEC_SHIFT)

/** @defgroup fdcan_sfec Standard ID filter action
 * @{
 */
#define FDCAN_SFEC_DISABLE 				(0x0 << FDCAN_SFEC_SHIFT)
#define FDCAN_SFEC_FIFO0				(0x1 << FDCAN_SFEC_SHIFT)
#define FDCAN_SFEC_FIFO1				(0x2 << FDCAN_SFEC_SHIFT)
#define FDCAN_SFEC_REJECT				(0x3 << FDCAN_SFEC_SHIFT)
#define FDCAN_SFEC_PRIO					(0x4 << FDCAN_SFEC_SHIFT)
#define FDCAN_SFEC_PRIO_FIFO0			(0x5 << FDCAN_SFEC_SHIFT)
#define FDCAN_SFEC_PRIO_FIFO1			(0x6 << FDCAN_SFEC_SHIFT)
/**@}*/

/** Amount of standard filters allocated in Message RAM
 * This number may vary between devices. 28 is value valid
 * for STM32G4 
 **/
#define FDCAN_SFT_MAX_NR				28

/* SFEC = 0x7 is unused */

#define FDCAN_SFID1_SHIFT				16
#define FDCAN_SFID1_MASK				(__BITS(11) << FDCAN_SFID1_SHIFT)

#define FDCAN_SFID2_SHIFT				0
#define FDCAN_SFID2_MASK				(__BITS(11) << FDCAN_SFID2_SHIFT)

#define __CHANGE_BITS(tgt, value, mask) (tgt) = (tgt & ~(mask)) | (value & mask)

/** Set filter type in standard ID filter.
 * @param filt address of filter
 * @param sft new value of filter type based on FDCAN_SFT_<type> macros
 */
#define FDCAN_SET_SFT(filt, sft) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, sft, FDCAN_SFT_MASK)

/** Set filter action in standard ID filter.
 * @param filt address of filter
 * @param sft new value of filter action based on FDCAN_SFEC_<type> macros
 */
#define FDCAN_SET_SFEC(filt, sfec) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, sfec, FDCAN_SFEC_MASK)

/** Set standard ID 1 in standard ID filter.
 * @param filt address of filter
 * @param sfid1 new value of filter ID 1
 */
#define FDCAN_SET_SFID1(filt, sfid1) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, (sfid1 << FDCAN_SFID1_SHIFT), FDCAN_SFID1_MASK)

/** Set standard ID 2 / mask in standard ID filter.
 * @param filt address of filter
 * @param sfid2 new value of filter ID 2 / filter mask
 */
#define FDCAN_SET_SFID2(filt, sfid2) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, (sfid2 << FDCAN_SFID2_SHIFT), FDCAN_SFID2_MASK)

/** Structure describing extended ID filters.
 * Extended ID filter is composed of two 32bit values.
 * This region of memory cannot be accessed in quantities less than 32bits.
 */
struct FDCAN_ExtendedFilter {
	uint32_t conf_id1;				/**< aggregate of filter action and extended ID */
	uint32_t type_id2;				/**< aggregate of filter type and extended ID or mask */
};

#define FDCAN_EFEC_SHIFT				29
#define FDCAN_EFEC_MASK					(__BITS(3) << FDCAN_EFEC_SHIFT)

/** @defgroup fdcan_eft Extended ID filter action
 * @{
 */
#define FDCAN_EFEC_DISABLE 				(0x0 << FDCAN_EFEC_SHIFT)
#define FDCAN_EFEC_FIFO0				(0x1 << FDCAN_EFEC_SHIFT)
#define FDCAN_EFEC_FIFO1				(0x2 << FDCAN_EFEC_SHIFT)
#define FDCAN_EFEC_REJECT				(0x3 << FDCAN_EFEC_SHIFT)
#define FDCAN_EFEC_PRIO					(0x4 << FDCAN_EFEC_SHIFT)
#define FDCAN_EFEC_PRIO_FIFO0			(0x5 << FDCAN_EFEC_SHIFT)
#define FDCAN_EFEC_PRIO_FIFO1			(0x6 << FDCAN_EFEC_SHIFT)
/**@}*/

#define FDCAN_EFID1_SHIFT				0
#define FDCAN_EFID1_MASK				(__BITS(29) << FDCAN_EFID1_SHIFT)

#define FDCAN_EFT_SHIFT					30
#define FDCAN_EFT_MASK					(__BITS(2) << FDCAN_EFT_SHIFT)

/** @defgroup fdcan_eft Extended ID filter match type
 * @{
 */
#define FDCAN_EFT_RANGE					(0x0 << FDCAN_EFT_SHIFT)	
#define FDCAN_EFT_DUAL					(0x1 << FDCAN_EFT_SHIFT)
#define FDCAN_EFT_ID_MASK				(0x2 << FDCAN_EFT_SHIFT)
#define FDCAN_EFT_RANGE_NOXIDAM			(0x3 << FDCAN_EFT_SHIFT)
/**@}*/

#define FDCAN_EFID2_SHIFT				0
#define FDCAN_EFID2_MASK				(__BITS(29) << FDCAN_EFID2_SHIFT)

/** Amount of extended filters allocated in Message RAM
 * This number may vary between devices. 8 is value valid
 * for STM32G4 
 **/
#define FDCAN_EFT_MAX_NR				8

/** Set filter type in extended ID filter.
 * @param filt address of filter
 * @param sft new value of filter type based on FDCAN_EFT_<type> macros
 */
#define FDCAN_SET_EFEC(filt, efec) \
	__CHANGE_BITS((filt)->conf_id1, efec, FDCAN_EFEC_MASK)

/** Set filter action in extended ID filter.
 * @param filt address of filter
 * @param sft new value of filter action based on FDCAN_EFEC_<type> macros
 */
#define FDCAN_SET_EFT(filt, eft) \
	__CHANGE_BITS((filt)->type_id2, eft, FDCAN_EFT_MASK)

/** Set extended ID 1 in extended ID filter.
 * @param filt address of filter
 * @param efid1 new value of filter ID 1
 */
#define FDCAN_SET_EFID1(filt, efid1) \
	__CHANGE_BITS((filt)->conf_id1, (efid1 << FDCAN_EFID1_SHIFT), FDCAN_EFID1_MASK)

/** Set extended ID 2 / mask in extended ID filter.
 * @param filt address of filter
 * @param efid2 new value of filter ID 2 / mask
 */
#define FDCAN_SET_EFID2(filt, efid2) \
	__CHANGE_BITS((filt)->type_id2, (efid2 << FDCAN_EFID2_SHIFT), FDCAN_EFID2_MASK)

/** Structure describing receive FIFO element.
 * Receive FIFO element consists of 2 32bit values for header
 * and 16 32bit values for message payload.
 * This area of memory can only be accessed in 32bit quantities
 */
struct FDCAN_RxFIFOElement {
	uint32_t identifier_flags;					/**< Aggregate of message identifier and flags. */
	uint32_t filt_fmt_dlc_ts;					/**< Aggregate of filter match ID, transfer format, DLC and timestamp */
	uint32_t data[64 / sizeof(uint32_t)];		/**< Message payload data */
};

/** Structure describing transmit event element.
 * Transmit event element consists of 2 32bit values.
 * This area of memory can only be accessed in 32bit quantities
 */
struct FDCAN_TxEventElement {
	uint32_t identifier_flags;					/**< Aggregate of message identifier and flags. */

	uint32_t evt_fmt_dlc_ts;					/**< Aggregate of event ID, transfer format, DLC and timestamp */
};

/** Structure describing transmit buffer element.
 * Transmit buffer consists of 2 32bit values for header
 * and 16 32bit values for message payload.
 * This area of memory can only be accessed in 32bit quantities
 */
struct FDCAN_TxBufferElement {
	uint32_t identifier_flags;					/**< Aggregate of message identifier and flags. */

	uint32_t evt_fmt_dlc_res;					/**< Aggregate of event ID, transfer format and DLC */
	uint32_t data[64 / sizeof(uint32_t)];		/**< Message payload data */
};

/** @defgroup fdcan_fifo FIFO / buffer flags
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
#define FDCAN_FIFO_EID_MASK				(__BITS(29) << FDCAN_FIFO_EID_SHIFT)

#define FDCAN_FIFO_SID_SHIFT			18
#define FDCAN_FIFO_SID_MASK				(__BITS(11) << FDCAN_FIFO_SID_SHIFT)

#define FDCAN_FIFO_DLC_SHIFT			16
#define FDCAN_FIFO_DLC_MASK				(__BITS(4) << FDCAN_FIFO_DLC_SHIFT)

#define FDCAN_FIFO_MM_SHIFT				24
#define FDCAN_FIFO_MM_MASK				(__BITS(8) << FDCAN_FIFO_MM_SHIFT)

#define FDCAN_FIFO_ANMF					(1 << 31)
#define FDCAN_FIFO_FIDX_SHIFT			24
#define FDCAN_FIFO_FIDX_MASK			(__BITS(7) << FDCAN_FIFO_FIDX_SHIFT)

#define FDCAN_FIFO_RXTS_SHIFT			0
#define FDCAN_FIFO_RXTS_MASK			(__BITS(16) << FDCAN_FIFO_RXTS_SHIFT)

/** Message RAM layout for one FDCAN block.
 * There are as many memory blocks as there are FDCAN blocks
 */
struct FDCAN_MessageRAM {
	/* List of standard ID filters */
	struct FDCAN_StandardFilter LFSSA[FDCAN_SFT_MAX_NR];

	/* List of extended ID filters */
	struct FDCAN_ExtendedFilter LFESA[FDCAN_EFT_MAX_NR];

	/* Buffer area for two receive FIFOs each having space for three messages */
	struct FDCAN_RxFIFOElement RxFIFO[2][3];

	/* Buffer area for transmit event buffers */
	struct FDCAN_TxEventElement TxEvent[3];

	/* Buffer area for transmitted messages. May act either as FIFO or as queue
	 * depending on configuration
	 */
	struct FDCAN_TxBufferElement TxBuffer[3];
};


/* --- FD-CAN error returns ------------------------------------------------- */

/** @defgroup fdcan_errors FDCAN error return values
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

/* --- FD-CAN functions ----------------------------------------------------- */

BEGIN_DECLS

void fdcan_reset(void);
int fdcan_init(uint32_t canport, bool brs_enable, bool fd_op_enable, 
		 bool auto_retr_disable, bool rx_fifo_locked, bool tx_queue_mode, 
		 uint32_t n_sjw, uint32_t n_ts1, uint32_t n_ts2, uint32_t n_br_presc, 
		 uint32_t f_sjw, uint32_t f_ts1, uint32_t f_ts2, uint32_t f_br_presc, 
		 bool loopback, bool silent);

int fdcan_start(uint32_t canport);

int fdcan_filter_init(uint32_t canport, uint8_t std_filt, uint8_t ext_filt);

int fdcan_std_filter_set(uint32_t canport, uint32_t nr, 
             uint8_t id_list_mode, uint32_t id1, uint32_t id2,
		     uint8_t action);
int fdcan_ext_filter_set(uint32_t canport, uint32_t nr, 
             uint8_t id_list_mode, uint32_t id1, uint32_t id2,
		     uint8_t action);

void fdcan_enable_irq(uint32_t canport, uint32_t irq);
void fdcan_disable_irq(uint32_t canport, uint32_t irq);

int fdcan_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
        bool fdcan_fmt, bool btr_switch, uint8_t length, const uint8_t *data);

int fdcan_receive(uint32_t canport, uint8_t fifo, bool release, uint32_t *id,
		 bool *ext, bool *rtr, uint8_t *fmi, uint8_t *length,
		 uint8_t *data, uint16_t *timestamp);

int fdcan_fifo_release(uint32_t canport, uint8_t fifo);

bool fdcan_available_tx(uint32_t canport);
bool fdcan_available_rx(uint32_t canport, uint8_t fifo);

END_DECLS


#endif
