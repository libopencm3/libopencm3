/** @defgroup fdcan_defines FD-CAN defines

@ingroup STM32G_defines

@brief <b>libopencm3 Defined Constants and Types for STM32 FD-CAN</b>

@author @htmlonly &copy @endhtmlonly 2021 Eduard Drusa <ventyl86@netkosice.sk>

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

/* TODO: javadoc */

#define CAN1		FDCAN1_BASE
#define CAN2		FDCAN2_BASE
#define CAN3		FDCAN3_BASE

#define FDCAN_CREL(can_base)		MMIO32(can_base + 0x0000)
#define FDCAN_ENDN(can_base)		MMIO32(can_base + 0x0004)
#define FDCAN_DBTP(can_base)		MMIO32(can_base + 0x000C)
#define FDCAN_TEST(can_base)		MMIO32(can_base + 0x0010)
#define FDCAN_RWD(can_base)			MMIO32(can_base + 0x0014)
#define FDCAN_CCCR(can_base)		MMIO32(can_base + 0x0018)
#define FDCAN_NBTP(can_base)		MMIO32(can_base + 0x001C)
#define FDCAN_TSCC(can_base)		MMIO32(can_base + 0x0020)
#define FDCAN_TSCV(can_base)		MMIO32(can_base + 0x0024)
#define FDCAN_TOCC(can_base)		MMIO32(can_base + 0x0028)
#define FDCAN_TOCV(can_base)		MMIO32(can_base + 0x002C)
#define FDCAN_ECR(can_base)			MMIO32(can_base + 0x0040)
#define FDCAN_PSR(can_base)			MMIO32(can_base + 0x0044)
#define FDCAN_TDCR(can_base)		MMIO32(can_base + 0x0048)
#define FDCAN_IR(can_base)			MMIO32(can_base + 0x0050)
#define FDCAN_IE(can_base)			MMIO32(can_base + 0x0054)
#define FDCAN_ILS(can_base)			MMIO32(can_base + 0x0058)
#define FDCAN_ILE(can_base)			MMIO32(can_base + 0x005C)
#define FDCAN_RXGFC(can_base)		MMIO32(can_base + 0x0080)
#define FDCAN_XIDAM(can_base)		MMIO32(can_base + 0x0084)
#define FDCAN_HPMS(can_base)		MMIO32(can_base + 0x0088)
#define FDCAN_RXF0S(can_base)		MMIO32(can_base + 0x0090)
#define FDCAN_RXF0A(can_base)		MMIO32(can_base + 0x0094)
#define FDCAN_RXF1S(can_base)		MMIO32(can_base + 0x0098)
#define FDCAN_RXF1A(can_base)		MMIO32(can_base + 0x009C)
#define FDCAN_TXBC(can_base)		MMIO32(can_base + 0x00C0)
#define FDCAN_TXFQS(can_base)		MMIO32(can_base + 0x00C4)
#define FDCAN_TXBRP(can_base)		MMIO32(can_base + 0x00C8)
#define FDCAN_TXBAR(can_base)		MMIO32(can_base + 0x00CC)
#define FDCAN_TXBCR(can_base)		MMIO32(can_base + 0x00D0)
#define FDCAN_TXBTO(can_base)		MMIO32(can_base + 0x00D4)
#define FDCAN_TXBCF(can_base)		MMIO32(can_base + 0x00D8)
#define FDCAN_TXBTIE(can_base)		MMIO32(can_base + 0x00DC)
#define FDCAN_TXBCIE(can_base)		MMIO32(can_base + 0x00E0)
#define FDCAN_TXEFS(can_base)		MMIO32(can_base + 0x00E4)
#define FDCAN_TXEFA(can_base)		MMIO32(can_base + 0x00E8)
#define FDCAN_CKDIV(can_base)		MMIO32(can_base + 0x0100)

/* TODO: javadoc */

/** @brief Helper macro for defining bitmasks
 * Will return number having n LSB set
 * @param n how many bits mask occupies
 */
#define __BITS(n)					((1 << n) - 1)

/* DAY[7:0]: TODO comment */
#define FDCAN_CREL_DAY_SHIFT		0
#define FDCAN_CREL_DAY_MASK		(__BITS(8) << FDCAN_CREL_DAY_SHIFT)

/* MON[7:0]: TODO comment */
#define FDCAN_CREL_MON_SHIFT		8
#define FDCAN_CREL_MON_MASK		(__BITS(8) << FDCAN_CREL_MON_SHIFT)

/* YEAR[3:0]: TODO comment */
#define FDCAN_CREL_YEAR_SHIFT		16
#define FDCAN_CREL_YEAR_MASK		(__BITS(4) << FDCAN_CREL_YEAR_SHIFT)

/* SUBSTEP[3:0]: TODO comment */
#define FDCAN_CREL_SUBSTEP_SHIFT		20
#define FDCAN_CREL_SUBSTEP_MASK		(__BITS(4) << FDCAN_CREL_SUBSTEP_SHIFT)

/* STEP[3:0]: TODO comment */
#define FDCAN_CREL_STEP_SHIFT		24
#define FDCAN_CREL_STEP_MASK		(__BITS(4) << FDCAN_CREL_STEP_SHIFT)

/* REL[3:0]: TODO comment */
#define FDCAN_CREL_REL_SHIFT		28
#define FDCAN_CREL_REL_MASK		(__BITS(4) << FDCAN_CREL_REL_SHIFT)


/* DSJW[3:0]: Synchronization jump width */
#define FDCAN_DBTP_DSJW_SHIFT			0
#define FDCAN_DBTP_DSJW_MASK		(__BITS(4) << FDCAN_DBTP_DSJW_SHIFT)

#define FDCAN_DBTP_DSJW_1TQ			(0x0 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_2TQ			(0x1 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_3TQ			(0x2 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_4TQ			(0x3 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_5TQ			(0x4 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_6TQ			(0x5 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_7TQ			(0x6 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_8TQ			(0x7 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_9TQ			(0x8 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_10TQ			(0x9 << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_11TQ			(0xa << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_12TQ			(0xb << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_13TQ			(0xc << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_14TQ			(0xd << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_15TQ			(0xe << FDCAN_DBTP_DSJW_SHIFT)
#define FDCAN_DBTP_DSJW_16TQ			(0xf << FDCAN_DBTP_DSJW_SHIFT)

/* DTSEG2[3:0]: Data time segment after sample point */
#define FDCAN_DBTP_DTSEG2_SHIFT		4
#define FDCAN_DBTP_DTSEG2_MASK		(__BITS(4) << FDCAN_DBTP_DTSEG2_SHIFT)

#define FDCAN_DBTP_DTSEG2_1TQ		(0x0 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_2TQ		(0x1 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_3TQ		(0x2 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_4TQ		(0x3 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_5TQ		(0x4 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_6TQ		(0x5 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_7TQ		(0x6 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_8TQ		(0x7 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_9TQ		(0x8 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_10TQ		(0x9 << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_11TQ		(0xa << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_12TQ		(0xb << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_13TQ		(0xc << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_14TQ		(0xd << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_15TQ		(0xe << FDCAN_DBTP_DTSEG2_SHIFT)
#define FDCAN_DBTP_DTSEG2_16TQ		(0xf << FDCAN_DBTP_DTSEG2_SHIFT)

/* DTSEG1[4:0]: Data time segment before sample point */
#define FDCAN_DBTP_DTSEG1_SHIFT		8
#define FDCAN_DBTP_DTSEG1_MASK		(__BITS(5) << FDCAN_DBTP_DTSEG1_SHIFT)

#define FDCAN_DBTP_DTSEG1_1TQ		(0x0 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_2TQ		(0x1 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_3TQ		(0x2 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_4TQ		(0x3 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_5TQ		(0x4 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_6TQ		(0x5 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_7TQ		(0x6 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_8TQ		(0x7 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_9TQ		(0x8 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_10TQ		(0x9 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_11TQ		(0xa << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_12TQ		(0xb << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_13TQ		(0xc << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_14TQ		(0xd << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_15TQ		(0xe << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_16TQ		(0xf << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_17TQ		(0x10 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_18TQ		(0x11 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_19TQ		(0x12 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_20TQ		(0x13 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_21TQ		(0x14 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_22TQ		(0x15 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_23TQ		(0x16 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_24TQ		(0x17 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_25TQ		(0x18 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_26TQ		(0x19 << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_27TQ		(0x1a << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_28TQ		(0x1b << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_29TQ		(0x1c << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_30TQ		(0x1d << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_31TQ		(0x1e << FDCAN_DBTP_DTSEG1_SHIFT)
#define FDCAN_DBTP_DTSEG1_32TQ		(0x1f << FDCAN_DBTP_DTSEG1_SHIFT)

/* DBRP[4:0]: Data bit rate prescaler */
#define FDCAN_DBTP_DBRP_SHIFT			16
#define FDCAN_DBTP_DBRP_MASK		(__BITS(5) << FDCAN_DBTP_DBRP_SHIFT)

#define FDCAN_DBTP_TDC				(1 << 23)

#define FDCAN_TEST_LBCK				(1 << 4)
/* TX[1:0]: Control of transmit pin */
#define FDCAN_TEST_TX_SHIFT			5
#define FDCAN_TEST_TX_MASK			(__BITS(2) << FDCAN_TEST_TX_SHIFT)

#define FDCAN_TEST_RX				(1 << 7)

/* WDC[7:0]: TODO comment */
#define FDCAN_RWD_WDC_SHIFT			0
#define FDCAN_RWD_WDC_MASK			(__BITS(8) << FDCAN_RWD_WDC_SHIFT)

/* WDV[7:0]: TODO comment */
#define FDCAN_RWD_WDV_SHIFT			7
#define FDCAN_RWD_WDV_MASK			(__BITS(8) << FDCAN_RWD_WDV_SHIFT)


#define FDCAN_CCCR_INIT				(1 << 0)
#define FDCAN_CCCR_CCE				(1 << 1)
#define FDCAN_CCCR_ASM				(1 << 2)
#define FDCAN_CCCR_CSA				(1 << 3)
#define FDCAN_CCCR_CSR				(1 << 4)
#define FDCAN_CCCR_MON				(1 << 5)
#define FDCAN_CCCR_DAR				(1 << 6)
#define FDCAN_CCCR_TEST				(1 << 7)
#define FDCAN_CCCR_FDOE				(1 << 8)
#define FDCAN_CCCR_BRSE				(1 << 9)
#define FDCAN_CCCR_PXHD				(1 << 12)
#define FDCAN_CCCR_EFBI				(1 << 13)
#define FDCAN_CCCR_TXP				(1 << 14)
#define FDCAN_CCCR_NISO				(1 << 15)

/* NTSEG2[6:0]: TODO comment */
#define FDCAN_NBTP_NTSEG2_SHIFT		0
#define FDCAN_NBTP_NTSEG2_MASK		(__BITS(7) << FDCAN_NBTP_NTSEG2_SHIFT)

/* NTSEG1[7:0]: TODO comment */
#define FDCAN_NBTP_NTSEG1_SHIFT		8
#define FDCAN_NBTP_NTSEG1_MASK		(__BITS(8) << FDCAN_NBTP_NTSEG1_SHIFT)

/* NBRP[8:0]: TODO comment */
#define FDCAN_NBTP_NBRP_SHIFT			16
#define FDCAN_NBTP_NBRP_MASK		(__BITS(9) << FDCAN_NBTP_NBRP_SHIFT)

/* NSJW[6:0]: TODO comment */
#define FDCAN_NBTP_NSJW_SHIFT			25
#define FDCAN_NBTP_NSJW_MASK		(__BITS(7) << FDCAN_NBTP_NSJW_SHIFT)


/* TSS[1:0]: TODO comment */
#define FDCAN_TSCC_TSS_SHIFT			0
#define FDCAN_TSCC_TSS_MASK			(__BITS(2) << FDCAN_TSCC_TSS_SHIFT)

/* TCP[3:0]: TODO comment */
#define FDCAN_TSCC_TCP_SHIFT			16
#define FDCAN_TSCC_TCP_MASK			(__BITS(4) << FDCAN_TSCC_TCP_SHIFT)


/* TSC[15:0]: TODO comment */
#define FDCAN_TSCV_TSC_SHIFT			0
#define FDCAN_TSCV_TSC_MASK			(__BITS(16) << FDCAN_TSCV_TSC_SHIFT)

#define FDCAN_TOCC_ETOC				(1 << 0)
/* TOS[1:0]: TODO comment */
#define FDCAN_TOCC_TOS_SHIFT			1
#define FDCAN_TOCC_TOS_MASK			(__BITS(2) << FDCAN_TOCC_TOS_SHIFT)

/* TOP[15:0]: TODO comment */
#define FDCAN_TOCC_TOP_SHIFT			16
#define FDCAN_TOCC_TOP_MASK			(__BITS(16) << FDCAN_TOCC_TOP_SHIFT)

/* TOC[15:0]: TODO comment */
#define FDCAN_TOCV_TOC_SHIFT			0
#define FDCAN_TOCV_TOC_MASK			(__BITS(16) << FDCAN_TOCV_TOC_SHIFT)

/* TEC[7:0]: TODO comment */
#define FDCAN_ECR_TEC_SHIFT			0
#define FDCAN_ECR_TEC_MASK			(__BITS(8) << FDCAN_ECR_TEC_SHIFT)

/* REC[6:0]: TODO comment */
#define FDCAN_ECR_REC_SHIFT			8
#define FDCAN_ECR_REC_MASK			(__BITS(7) << FDCAN_ECR_REC_SHIFT)

#define FDCAN_ECR_RP				(1 << 15)
/* CEL[7:0]: TODO comment */
#define FDCAN_ECR_CEL_SHIFT			16
#define FDCAN_ECR_CEL_MASK			(__BITS(8) << FDCAN_ECR_CEL_SHIFT)


/* LEC[2:0]: TODO comment */
#define FDCAN_PSR_LEC_SHIFT			0
#define FDCAN_PSR_LEC_MASK			(__BITS(3) << FDCAN_PSR_LEC_SHIFT)

/* ACT[1:0]: TODO comment */
#define FDCAN_PSR_ACT_SHIFT			3
#define FDCAN_PSR_ACT_MASK			(__BITS(2) << FDCAN_PSR_ACT_SHIFT)

#define FDCAN_PSR_EP				(1 << 5)
#define FDCAN_PSR_EW				(1 << 6)
#define FDCAN_PSR_BO				(1 << 7)
/* DLEC[2:0]: TODO comment */
#define FDCAN_PSR_DLEC_SHIFT			8
#define FDCAN_PSR_DLEC_MASK			(__BITS(3) << FDCAN_PSR_DLEC_SHIFT)

#define FDCAN_PSR_RESI				(1 << 11)

// the what?
#define FDCAN_PSR_RBRSRESI1			(1 << 12)
#define FDCAN_PSR_REDL				(1 << 13)
#define FDCAN_PSR_PXE				(1 << 14)
/* TDCV[6:0]: TODO comment */
#define FDCAN_PSR_TDCV_SHIFT			16
#define FDCAN_PSR_TDCV_MASK			(__BITS(7) << FDCAN_PSR_TDCV_SHIFT)


/* TDCF[6:0]: TODO comment */
#define FDCAN_TDCR_TDCF_SHIFT			0
#define FDCAN_TDCR_TDCF_MASK		(__BITS(7) << FDCAN_TDCR_TDCF_SHIFT)

/* TDCO[6:0]: TODO comment */
#define FDCAN_TDCR_TDCO_SHIFT			8
#define FDCAN_TDCR_TDCO_MASK		(__BITS(7) << FDCAN_TDCR_TDCO_SHIFT)


#define FDCAN_IR_RF0N				(1 << 0)
#define FDCAN_IR_RF0F				(1 << 1)
#define FDCAN_IR_RF0L				(1 << 2)
#define FDCAN_IR_RF1N				(1 << 3)
#define FDCAN_IR_RF1F				(1 << 4)
#define FDCAN_IR_RF1L				(1 << 5)
#define FDCAN_IR_HPM				(1 << 6)
#define FDCAN_IR_TC					(1 << 7)
#define FDCAN_IR_TCF				(1 << 8)
#define FDCAN_IR_TFE				(1 << 9)
#define FDCAN_IR_TEFN				(1 << 10)
#define FDCAN_IR_TEFF				(1 << 11)
#define FDCAN_IR_TEFL				(1 << 12)
#define FDCAN_IR_TSW				(1 << 13)
#define FDCAN_IR_MRAF				(1 << 14)
#define FDCAN_IR_TOO				(1 << 15)
#define FDCAN_IR_ELO				(1 << 16)
#define FDCAN_IR_EP					(1 << 17)
#define FDCAN_IR_EW					(1 << 18)
#define FDCAN_IR_BO					(1 << 19)
#define FDCAN_IR_WDI				(1 << 20)
#define FDCAN_IR_PEA				(1 << 21)
#define FDCAN_IR_PED				(1 << 22)
#define FDCAN_IR_ARA				(1 << 23)

#define FDCAN_IE_RF0NE				(1 << 0)
#define FDCAN_IE_RF0FE				(1 << 1)
#define FDCAN_IE_RF0LE				(1 << 2)
#define FDCAN_IE_RF1NE				(1 << 3)
#define FDCAN_IE_RF1FE				(1 << 4)
#define FDCAN_IE_RF1LE				(1 << 5)
#define FDCAN_IE_HPME				(1 << 6)
#define FDCAN_IE_TCE				(1 << 7)
#define FDCAN_IE_TCFE				(1 << 8)
#define FDCAN_IE_TFEE				(1 << 9)
#define FDCAN_IE_TEFNE				(1 << 10)
#define FDCAN_IE_TEFFE				(1 << 11)
#define FDCAN_IE_TEFLE				(1 << 12)
#define FDCAN_IE_TSWE				(1 << 13)
#define FDCAN_IE_MRAFE				(1 << 14)
#define FDCAN_IE_TOOE				(1 << 15)
#define FDCAN_IE_ELOE				(1 << 16)
#define FDCAN_IE_EPE				(1 << 17)
#define FDCAN_IE_EWE				(1 << 18)
#define FDCAN_IE_BOE				(1 << 19)
#define FDCAN_IE_WDIE				(1 << 20)
#define FDCAN_IE_PEAE				(1 << 21)
#define FDCAN_IE_PEDE				(1 << 22)
#define FDCAN_IE_ARAE				(1 << 23)

#define FDCAN_ILS_RxFIFO0			(1 << 0)
#define FDCAN_ILS_RxFIFO1			(1 << 1)
#define FDCAN_ILS_SMSG				(1 << 2)
#define FDCAN_ILS_TFERR				(1 << 3)
#define FDCAN_ILS_MISC				(1 << 4)
#define FDCAN_ILS_BERR				(1 << 5)
#define FDCAN_ILS_PERR				(1 << 6)

#define FDCAN_ILE_INT0				(1 << 0)
#define FDCAN_ILE_INT1				(1 << 1)

#define FDCAN_RXGFC_RRFE			(1 << 0)
#define FDCAN_RXGFC_RRFS			(1 << 1)
/* ANFE[1:0]: TODO comment */
#define FDCAN_RXGFC_ANFE_SHIFT		2
#define FDCAN_RXGFC_ANFE_MASK		(__BITS(2) << FDCAN_RXGFC_ANFE_SHIFT)

/* ANFS[1:0]: TODO comment */
#define FDCAN_RXGFC_ANFS_SHIFT		4
#define FDCAN_RXGFC_ANFS_MASK		(__BITS(2) << FDCAN_RXGFC_ANFS_SHIFT)

#define FDCAN_RXGFC_F1OM			(1 << 8)
#define FDCAN_RXGFC_F0OM			(1 << 9)
/* LSS[4:0]: TODO comment */
#define FDCAN_RXGFC_LSS_SHIFT			16
#define FDCAN_RXGFC_LSS_MASK		(__BITS(5) << FDCAN_RXGFC_LSS_SHIFT)

/* LSE[3:0]: TODO comment */
#define FDCAN_RXGFC_LSE_SHIFT			24
#define FDCAN_RXGFC_LSE_MASK		(__BITS(4) << FDCAN_RXGFC_LSE_SHIFT)


/* EIDM[28:0]: TODO comment */
#define FDCAN_XIDAM_EIDM_SHIFT		0
#define FDCAN_XIDAM_EIDM_MASK		(__BITS(29) << FDCAN_XIDAM_EIDM_SHIFT)


/* BIDX[2:0]: TODO comment */
#define FDCAN_HPMS_BIDX_SHIFT			0
#define FDCAN_HPMS_BIDX_MASK		(__BITS(3) << FDCAN_HPMS_BIDX_SHIFT)

/* MSI[1:0]: TODO comment */
#define FDCAN_HPMS_MSI_SHIFT			6
#define FDCAN_HPMS_MSI_MASK			(__BITS(2) << FDCAN_HPMS_MSI_SHIFT)

/* FIDX[4:0]: TODO comment */
#define FDCAN_HPMS_FIDX_SHIFT			8
#define FDCAN_HPMS_FIDX_MASK		(__BITS(5) << FDCAN_HPMS_FIDX_SHIFT)

#define FDCAN_HPMS_FLS				(1 << 15)

/* F0FL[3:0]: TODO comment */
#define FDCAN_RXF0S_F0FL_SHIFT		0
#define FDCAN_RXF0S_F0FL_MASK		(__BITS(4) << FDCAN_RXF0S_F0FL_SHIFT)

/* F0GI[1:0]: TODO comment */
#define FDCAN_RXF0S_F0GI_SHIFT		8
#define FDCAN_RXF0S_F0GI_MASK		(__BITS(2) << FDCAN_RXF0S_F0GI_SHIFT)

/* F0PI[1:0]: TODO comment */
#define FDCAN_RXF0S_F0PI_SHIFT		16
#define FDCAN_RXF0S_F0PI_MASK		(__BITS(2) << FDCAN_RXF0S_F0PI_SHIFT)

#define FDCAN_RXF0S_F0F				(1 << 24)
#define FDCAN_RXF0S_RF0L			(1 << 25)

/* R0AI[2:0]: TODO comment */
#define FDCAN_RXF0A_R0AI_SHIFT		0
#define FDCAN_RXF0A_R0AI_MASK		(__BITS(3) << FDCAN_RXF0A_R0AI_SHIFT)


/* F1FL[3:0]: TODO comment */
#define FDCAN_RXF1S_F1FL_SHIFT		0
#define FDCAN_RXF1S_F1FL_MASK		(__BITS(4) << FDCAN_RXF1S_F1FL_SHIFT)

/* F1GI[1:0]: TODO comment */
#define FDCAN_RXF1S_F1GI_SHIFT		8
#define FDCAN_RXF1S_F1GI_MASK		(__BITS(2) << FDCAN_RXF1S_F1GI_SHIFT)

/* F1PI[1:0]: TODO comment */
#define FDCAN_RXF1S_F1PI_SHIFT		16
#define FDCAN_RXF1S_F1PI_MASK		(__BITS(2) << FDCAN_RXF1S_F1PI_SHIFT)

#define FDCAN_RXF1S_F1F				(1 << 24)
#define FDCAN_RXF1S_RF1L			(1 << 25)

/* R1AI[2:0]: TODO comment */
#define FDCAN_RXF1A_R1AI_SHIFT		0
#define FDCAN_RXF1A_R1AI_MASK		(__BITS(3) << FDCAN_RXF1A_R1AI_SHIFT)


#define FDCAN_TXBC_TFQM				(1 << 24)

/* TFFL[2:0]: TODO comment */
#define FDCAN_TXFQS_TFFL_SHIFT		0
#define FDCAN_TXFQS_TFFL_MASK		(__BITS(3) << FDCAN_TXFQS_TFFL_SHIFT)

/* TFGI[1:0]: TODO comment */
#define FDCAN_TXFQS_TFGI_SHIFT		0
#define FDCAN_TXFQS_TFGI_MASK		(__BITS(2) << FDCAN_TXFQS_TFGI_SHIFT)

/* TFQPI[1:0]: TODO comment */
#define FDCAN_TXFQS_TFQPI_SHIFT		0
#define FDCAN_TXFQS_TFQPI_MASK		(__BITS(2) << FDCAN_TXFQS_TFQPI_SHIFT)

#define FDCAN_TXFQS_TFQF			(1 << 0)

#define FDCAN_TXBRP_TRP0			(1 << 0)
#define FDCAN_TXBRP_TRP1			(1 << 1)
#define FDCAN_TXBRP_TRP2			(1 << 2)

#define FDCAN_TXBAR_AR0				(1 << 0)
#define FDCAN_TXBAR_AR1				(1 << 1)
#define FDCAN_TXBAR_AR2				(1 << 2)

#define FDCAN_TXBCR_CR0				(1 << 0)
#define FDCAN_TXBCR_CR1				(1 << 1)
#define FDCAN_TXBCR_CR2				(1 << 2)

#define FDCAN_TXBTO_TO0				(1 << 0)
#define FDCAN_TXBTO_TO1				(1 << 1)
#define FDCAN_TXBTO_TO2				(1 << 2)

#define FDCAN_TXBCF_CF0				(1 << 0)
#define FDCAN_TXBCF_CF1				(1 << 1)
#define FDCAN_TXBCF_CF2				(1 << 2)

#define FDCAN_TXBTIE_TIE0			(1 << 0)
#define FDCAN_TXBTIE_TIE1			(1 << 1)
#define FDCAN_TXBTIE_TIE2			(1 << 2)

#define FDCAN_TXBCIE_CFIE0			(1 << 0)
#define FDCAN_TXBCIE_CFIE1			(1 << 1)
#define FDCAN_TXBCIE_CFIE2			(1 << 2)

/* EFFL[2:0]: TODO comment */
#define FDCAN_TXEFS_EFFL_SHIFT		0
#define FDCAN_TXEFS_EFFL_MASK		(__BITS(3) << FDCAN_TXEFS_EFFL_SHIFT)

/* EFG[1:0]: TODO comment */
#define FDCAN_TXEFS_EFG_SHIFT			8
#define FDCAN_TXEFS_EFG_MASK		(__BITS(2) << FDCAN_TXEFS_EFG_SHIFT)

/* EFPI[1:0]: TODO comment */
#define FDCAN_TXEFS_EFPI_SHIFT		16
#define FDCAN_TXEFS_EFPI_MASK		(__BITS(2) << FDCAN_TXEFS_EFPI_SHIFT)

#define FDCAN_TXEFS_EFF				(1 << 24)
#define FDCAN_TXEFS_TEF				(1 << 25)

/* EFAI[1:0]: TODO comment */
#define FDCAN_TXEFA_EFAI_SHIFT		0
#define FDCAN_TXEFA_EFAI_MASK		(__BITS(2) << FDCAN_TXEFA_EFAI_SHIFT)


/* PDIV[3:0]: TODO comment */
#define FDCAN_CKDIV_PDIV_SHIFT		0
#define FDCAN_CKDIV_PDIV_MASK		(__BITS(4) << FDCAN_CKDIV_PDIV_SHIFT)

/* --- FD-CAN memory block defines------------------------------------------ */

struct FDCAN_StandardFilter {
	uint32_t type_id1_conf_id2;
};

#define FDCAN_SFT_SHIFT				30
#define FDCAN_SFT_MASK				(__BITS(2) << FDCAN_SFT_SHIFT)

#define FDCAN_SFT_RANGE				(0x0 << FDCAN_SFT_SHIFT)	
#define FDCAN_SFT_DUAL				(0x1 << FDCAN_SFT_SHIFT)
#define FDCAN_SFT_ID_MASK			(0x2 << FDCAN_SFT_SHIFT)
#define FDCAN_SFT_DISABLE			(0x3 << FDCAN_SFT_SHIFT)

#define FDCAN_SFEC_SHIFT				27
#define FDCAN_SFEC_MASK 			(__BITS(3) << FDCAN_SFEC_SHIFT)

#define FDCAN_SFEC_DISABLE 			(0x0 << DCAN_SFEC_SHIFT)
#define FDCAN_SFEC_FIFO0			(0x1 << DCAN_SFEC_SHIFT)
#define FDCAN_SFEC_FIFO1			(0x2 << DCAN_SFEC_SHIFT)
#define FDCAN_SFEC_REJECT			(0x3 << DCAN_SFEC_SHIFT)
#define FDCAN_SFEC_PRIO				(0x4 << DCAN_SFEC_SHIFT)
#define FDCAN_SFEC_PRIO_FIFO0		(0x5 << DCAN_SFEC_SHIFT)
#define FDCAN_SFEC_PRIO_FIFO1		(0x6 << DCAN_SFEC_SHIFT)

/* SFEC = 0x7 is unused */

#define FDCAN_SFID1_SHIFT				16
#define FDCAN_SFID1_MASK			(__BITS(11) << SFID1_SHIFT)

#define FDCAN_SFID2_SHIFT				0
#define FDCAN_SFID2_MASK			(__BITS(11) << SFID2_SHIFT)

#define __CHANGE_BITS(tgt, value, mask) (tgt) = (tgt & ~(mask)) | (value & mask)

#define FDCAN_SET_SFT(filt, sft) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, sft, FDCAN_SFT_MASK)

#define FDCAN_SET_SFEC(filt, sfec) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, sfec, FDCAN_SFEC_MASK)

#define FDCAN_SET_SFID1(filt, sfid1) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, (sfid1 << FDCAN_SFID1_SHIFT), FDCAN_SFID1_MASK)

#define FDCAN_SET_SFID2(filt, sfid2) \
	__CHANGE_BITS((filt)->type_id1_conf_id2, (sfid2 << FDCAN_SFID2_SHIFT), FDCAN_SFID2_MASK)

struct FDCAN_ExtendedFilter {
	uint32_t conf_id1;
	uint32_t type_id2;
};

#define FDCAN_EFEC_SHIFT				29
#define FDCAN_EFEC_MASK				(__BITS(3) << EFEC_SHIFT)

#define FDCAN_EFEC_DISABLE 			(0x0 << DCAN_EFEC_SHIFT)
#define FDCAN_EFEC_FIFO0			(0x1 << DCAN_EFEC_SHIFT)
#define FDCAN_EFEC_FIFO1			(0x2 << DCAN_EFEC_SHIFT)
#define FDCAN_EFEC_REJECT			(0x3 << DCAN_EFEC_SHIFT)
#define FDCAN_EFEC_PRIO				(0x4 << DCAN_EFEC_SHIFT)
#define FDCAN_EFEC_PRIO_FIFO0		(0x5 << DCAN_EFEC_SHIFT)
#define FDCAN_EFEC_PRIO_FIFO1		(0x6 << DCAN_EFEC_SHIFT)

#define FDCAN_EFID1_SHIFT				0
#define FDCAN_EFID1_MASK			(__BITS(29) << EFID1_SHIFT)

#define FDCAN_EFT_SHIFT				30
#define FDCAN_EFT_MASK				(__BITS(2) << EFT_SHIFT)

#define FDCAN_EFT_RANGE				(0x0 << FDCAN_EFT_SHIFT)	
#define FDCAN_EFT_DUAL				(0x1 << FDCAN_EFT_SHIFT)
#define FDCAN_EFT_ID_MASK			(0x2 << FDCAN_EFT_SHIFT)
#define FDCAN_EFT_RANGE_NOXIDAM		(0x3 << FDCAN_EFT_SHIFT)

#define FDCAN_EFID2_SHIFT				0
#define FDCAN_EFID2_MASK			(__BITS(29) << EFID2_SHIFT)

#define FDCAN_SET_EFEC(filt, efec) \
	__CHANGE_BITS((filt)->conf_id1, efec, FDCAN_EFEC_MASK)

#define FDCAN_SET_EFT(filt, eft) \
	__CHANGE_BITS((filt)->type_id2, eft, FDCAN_EFT_MASK)

#define FDCAN_SET_EFID1(filt, efid1) \
	__CHANGE_BITS((filt)->conf_id1, (efid1 << FDCAN_EFID1_SHIFT), FDCAN_EFID1_MASK)

#define FDCAN_SET_EFID2(filt, efid2) \
	__CHANGE_BITS((filt)->type_id2, (efid2 << FDCAN_EFID2_SHIFT), FDCAN_EFID2_MASK)

struct FDCAN_RxFIFOElement {
	uint32_t identifier_flags;
	uint32_t filt_fmt_dlc_ts;
	uint8_t data[64];
};

struct FDCAN_TxEventElement {
	uint32_t identifier_flags;
	uint32_t evt_fmt_dlc_ts;
};

struct FDCAN_TxBufferElement {
	uint32_t identifier_flags;
	uint32_t evt_fmt_dlc;
	uint8_t data[64];
};

#define FDCAN_FIFO_ESI				(1 << 31)
#define FDCAN_FIFO_XTD				(1 << 20)
#define FDCAN_FIFO_RTR				(1 << 29)
#define FDCAN_FIFO_EFC				(1 << 23)
#define FDCAN_FIFO_FDF				(1 << 21)
#define FDCAN_FIFO_BRS				(1 << 20)
#define FDCAN_FIFO_DLC_SHIFT			16
#define FDCAN_FIFO_DLC_MASK			(__BITS(4) << FIFO_DLC_SHIFT)

#define FDCAN_FIFO_MM_SHIFT			24
#define FDCAN_FIFO_MM_MASK			(__BITS(8) << FIFO_MM_SHIFT)

#define FDCAN_FIFO_ANMF				(1 << 31)
#define FDCAN_FIFO_FIDX_SHIFT			24
#define FDCAN_FIFO_FIDX_MASK		(__BITS(7) << FIFO_FIDX_SHIFT)

#define FDCAN_FIFO_RXTS_SHIFT			0
#define FDCAN_FIFO_RXTS_MASK		(__BITS(16) << FIFO_RXTS_SHIFT)

/* --- FD-CAN functions ----------------------------------------------------- */

BEGIN_DECLS

void fdcan_reset(void);
int fdcan_init(uint32_t canport, bool brs, bool fdoe, bool nart,
	     bool rflm, bool txfp, uint32_t sjw, uint32_t ts1, uint32_t ts2,
	     uint32_t brp, bool loopback, bool silent);

void can_filter_init(uint32_t nr, bool scale_32bit,
		     bool id_list_mode, uint32_t fr1, uint32_t fr2,
		     uint32_t fifo, bool enable);
void can_filter_id_mask_16bit_init(uint32_t nr, uint16_t id1,
				   uint16_t mask1, uint16_t id2,
				   uint16_t mask2, uint32_t fifo, bool enable);
void can_filter_id_mask_32bit_init(uint32_t nr, uint32_t id,
				   uint32_t mask, uint32_t fifo, bool enable);
void can_filter_id_list_16bit_init(uint32_t nr, uint16_t id1,
				   uint16_t id2, uint16_t id3, uint16_t id4,
				   uint32_t fifo, bool enable);
void can_filter_id_list_32bit_init(uint32_t nr, uint32_t id1,
				   uint32_t id2, uint32_t fifo, bool enable);

void can_enable_irq(uint32_t canport, uint32_t irq);
void can_disable_irq(uint32_t canport, uint32_t irq);

int can_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
		 uint8_t length, uint8_t *data);
void can_receive(uint32_t canport, uint8_t fifo, bool release, uint32_t *id,
		 bool *ext, bool *rtr, uint8_t *fmi, uint8_t *length,
		 uint8_t *data, uint16_t *timestamp);

void can_fifo_release(uint32_t canport, uint8_t fifo);
bool can_available_mailbox(uint32_t canport);
END_DECLS


#endif
