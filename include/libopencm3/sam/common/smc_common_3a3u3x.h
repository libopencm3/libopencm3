/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Felix Held <felix-libopencm3@felixheld.de>
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

#ifndef LIBOPENCM3_SMC_H
#define LIBOPENCM3_SMC_H

#include <libopencm3/sam/memorymap.h>


/* Chip Select Defines */
#define SMC_CS_0			0
#define SMC_CS_1			1
#define SMC_CS_2			2
#define SMC_CS_3			3


/* --- Static Memory Controller (SMC) registers ---------------------------- */

/* NFC Configuration Register */
#define SMC_CFG				MMIO32(SMC_BASE + 0x00)

/* NFC Control Register */
#define SMC_CTRL			MMIO32(SMC_BASE + 0x04)

/* NFC Status Register */
#define SMC_SR				MMIO32(SMC_BASE + 0x08)

/* NFC Interrupt Enable Register */
#define SMC_IER				MMIO32(SMC_BASE + 0x0C)

/* NFC Interrupt Disable Register */
#define SMC_IDR				MMIO32(SMC_BASE + 0x10)

/* Interrupt Mask Register */
#define SMC_IMR				MMIO32(SMC_BASE + 0x14)

/* NFC Address Cycle Zero Register */
#define SMC_ADDR			MMIO32(SMC_BASE + 0x18)

/* Bank Address Register */
#define SMC_BANK			MMIO32(SMC_BASE + 0x1C)

/* ECC Control Register */
#define SMC_ECC_CTRL			MMIO32(SMC_BASE + 0x20)

/* ECC Mode Register */
#define SMC_ECC_MD			MMIO32(SMC_BASE + 0x24)

/* ECC Status 1 Register */
#define SMC_ECC_SR1			MMIO32(SMC_BASE + 0x28)

/* ECC Parity 0 Register */
#define SMC_ECC_PR0			MMIO32(SMC_BASE + 0x2C)

/* ECC parity 1 Register */
#define SMC_ECC_PR1			MMIO32(SMC_BASE + 0x30)

/* ECC status 2 Register */
#define SMC_ECC_SR2			MMIO32(SMC_BASE + 0x34)

/* ECC parity 2 Register */
#define SMC_ECC_PR2			MMIO32(SMC_BASE + 0x38)

/* ECC parity 3 Register */
#define SMC_ECC_PR3			MMIO32(SMC_BASE + 0x3C)

/* ECC parity 4 Register */
#define SMC_ECC_PR4			MMIO32(SMC_BASE + 0x40)

/* ECC parity 5 Register */
#define SMC_ECC_PR5			MMIO32(SMC_BASE + 0x44)

/* ECC parity 6 Register */
#define SMC_ECC_PR6			MMIO32(SMC_BASE + 0x48)

/* ECC parity 7 Register */
#define SMC_ECC_PR7			MMIO32(SMC_BASE + 0x4C)

/* ECC parity 8 Register */
#define SMC_ECC_PR8			MMIO32(SMC_BASE + 0x50)

/* ECC parity 9 Register */
#define SMC_ECC_PR9			MMIO32(SMC_BASE + 0x54)

/* ECC parity 10 Register */
#define SMC_ECC_PR10			MMIO32(SMC_BASE + 0x58)

/* ECC parity 11 Register */
#define SMC_ECC_PR11			MMIO32(SMC_BASE + 0x5C)

/* ECC parity 12 Register */
#define SMC_ECC_PR12			MMIO32(SMC_BASE + 0x60)

/* ECC parity 13 Register */
#define SMC_ECC_PR13			MMIO32(SMC_BASE + 0x64)

/* ECC parity 14 Register */
#define SMC_ECC_PR14			MMIO32(SMC_BASE + 0x68)

/* ECC parity 15 Register */
#define SMC_ECC_PR15			MMIO32(SMC_BASE + 0x6C)

/* Setup Register */
#define SMC_SETUP(CS_number)		MMIO32(SMC_BASE + 0x14*(CS_number) + 0x70)

/* Pulse Register */
#define SMC_PULSE(CS_number)		MMIO32(SMC_BASE + 0x14*(CS_number) + 0x74)

/* Cycle Register */
#define SMC_CYCLE(CS_number)		MMIO32(SMC_BASE + 0x14*(CS_number) + 0x78)

/* Timings Register */
#define SMC_TIMINGS(CS_number)		MMIO32(SMC_BASE + 0x14*(CS_number) + 0x7C)

/* Mode Register */
#define SMC_MODE(CS_number)		MMIO32(SMC_BASE + 0x14*(CS_number) + 0x80)

/* Off Chip Memory Scrambling Mode Register */
#define SMC_OCMS			MMIO32(SMC_BASE + 0x110)

/* Off Chip Memory Scrambling KEY1 Register */
#define SMC_KEY1			MMIO32(SMC_BASE + 0x114)

/* Off Chip Memory Scrambling KEY2 Register */
#define SMC_KEY2			MMIO32(SMC_BASE + 0x118)

/* Write Protection Control Register */
#define SMC_WPCR			MMIO32(SMC_BASE + 0x1E4)

/* Write Protect Status Register */
#define SMC_WPSR			MMIO32(SMC_BASE + 0x1E8)


/* --- Register contents --------------------------------------------------- */


/* --- SMC NFC Configuration Register (SMC_CFG) ---------------------------- */

/* Data Timeout Multiplier */
#define SMC_CFG_DTOMUL_SHIFT		20
#define SMC_CFG_DTOMUL_MASK		(0x07 << SMC_DTOMUL_SHIFT)

/* Data Timeout Multiplier Values */
#define SMC_CFG_DTOMUL_X1		(0x00 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X16		(0x01 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X128		(0x02 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X256		(0x03 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X1024		(0x04 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X4096		(0x05 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X65536		(0x06 << SMC_DTOMUL_SHIFT)
#define SMC_CFG_DTOMUL_X1048576		(0x07 << SMC_DTOMUL_SHIFT)

/* Data Timeout Cycle Number */
#define SMC_CFG_DTOCYC_SHIFT		16
#define SMC_CFG_DTOCYC_MASK		(0x0F << SMC_DTOCYC_SHIFT)

/* Ready/Busy Signal Edge Detection */
#define SMC_CFG_RBEDGE			(1 << 13)

/* Rising/Falling Edge Detection Control */
#define SMC_CFG_EDGECTRL		(1 << 12)

/* Read Spare Area */
#define SMC_CFG_RSPARE			(1 << 9)

/* Write Spare Area */
#define SMC_CFG_WSPARE			(1 << 8)

/* NAND Flash Page Size */
#define SMC_CFG_PAGESIZE_SHIFT		0
#define SMC_CFG_PAGESIZE_MASK		(0x03 << SMC_CFG_PAGESIZE_SHIFT)

/* NAND Flash Page Size Values */
#define SMC_CFG_PAGESIZE_PS512_16	(0x00 << SMC_CFG_PAGESIZE_SHIFT)
#define SMC_CFG_PAGESIZE_PS1024_32	(0x01 << SMC_CFG_PAGESIZE_SHIFT)
#define SMC_CFG_PAGESIZE_PS2048_64	(0x02 << SMC_CFG_PAGESIZE_SHIFT)
#define SMC_CFG_PAGESIZE_PS4096_128	(0x03 << SMC_CFG_PAGESIZE_SHIFT)


/* --- SMC NFC Control Register (SMC_CTRL) --------------------------------- */

/* NAND Flash Controller Disable */
#define SMC_CTRL_NFCDIS			(1 << 1)

/* NAND Flash Controller Enable */
#define SMC_CTRL_NFCEN			(1 << 0)


/* --- SMC NFC Status Register (SMC_SR) ------------------------------------ */

/* Ready/Busy Line 0 Edge Detected */
#define SMC_SR_RB_EDGE0			(1 << 24)

/* NFC Access Size Error */
#define SMC_SR_NFCASE			(1 << 23)

/* Accessing While Busy */
#define SMC_SR_AWB			(1 << 22)

/* Undefined Area Error */
#define SMC_SR_UNDEF			(1 << 21)

/* Data Timeout Error */
#define SMC_SR_DTOE			(1 << 20)

/* Command Done */
#define SMC_SR_CMDDONE			(1 << 17)

/* NFC Data Transfer Terminated */
#define SMC_SR_XFRDONE			(1 << 16)

/* NFC Chip Select ID */
#define SMC_SR_NFCSID_SHIFT		12
#define SMC_SR_NFCSID_MASK		(0x07 << SMC_SR_NFCSID_SHIFT)

/* NFC Write/Read Operation */
#define SMC_SR_NFCWR			(1 << 11)

/* NFC Busy */
#define SMC_SR_NFCBUSY			(1 << 8)

/* Selected Ready Busy Falling Edge Detected */
#define SMC_SR_RB_FALL			(1 << 5)

/* Selected Ready Busy Rising Edge Detected */
#define SMC_SR_RB_RISE			(1 << 4)

/* NAND Flash Controller status */
#define SMC_SR_SMCSTS			(1 << 0)


/* --- SMC NFC Interrupt Enable Register (SMC_IER) ------------------------- */

/* Ready/Busy Line 0 Interrupt Enable */
#define SMC_IER_RB_EDGE0		(1 << 24)

/* NFC Access Size Error Interrupt Enable */
#define SMC_IER_NFCASE			(1 << 23)

/* Accessing While Busy Interrupt Enable */
#define SMC_IER_AWB			(1 << 22)

/* Undefined Area Access Interrupt Enable */
#define SMC_IER_UNDEF			(1 << 21)

/* Data Timeout Error Interrupt Enable */
#define SMC_IER_DTOE			(1 << 20)

/* Command Done Interrupt Enable */
#define SMC_IER_CMDDONE			(1 << 17)

/* Transfer Done Interrupt Enable */
#define SMC_IER_XFRDONE			(1 << 16)

/* Ready Busy Falling Edge Detection Interrupt Enable */
#define SMC_IER_RB_FALL			(1 << 5)

/* Ready Busy Rising Edge Detection Interrupt Enable */
#define SMC_IER_RB_RISE			(1 << 4)


/* --- SMC NFC Interrupt Disable Register (SMC_IDR) ------------------------ */

/* Ready/Busy Line 0 Interrupt Disable */
#define SMC_IDR_RB_EDGE0		(1 << 24)

/* NFC Access Size Error Interrupt Disable */
#define SMC_IDR_NFCASE			(1 << 23)

/* Accessing While Busy Interrupt Disable */
#define SMC_IDR_AWB			(1 << 22)

/* Undefined Area Access Interrupt Disable */
#define SMC_IDR_UNDEF			(1 << 21)

/* Data Timeout Error Interrupt Disable */
#define SMC_IDR_DTOE			(1 << 20)

/* Command Done Interrupt Disable */
#define SMC_IDR_CMDDONE			(1 << 17)

/* Transfer Done Interrupt Disable */
#define SMC_IDR_XFRDONE			(1 << 16)

/* Ready Busy Falling Edge Detection Interrupt Disable */
#define SMC_IDR_RB_FALL			(1 << 5)

/* Ready Busy Rising Edge Detection Interrupt Disable */
#define SMC_IDR_RB_RISE			(1 << 4)


/* --- SMC NFC Interrupt Mask Register (SMC_IMR) --------------------------- */

/* Ready/Busy Line 0 Interrupt Mask */
#define SMC_IMR_RB_EDGE0		(1 << 24)

/* NFC Access Size Error Interrupt Mask */
#define SMC_IMR_NFCASE			(1 << 23)

/* Accessing While Busy Interrupt Mask */
#define SMC_IMR_AWB			(1 << 22)

/* Undefined Area Access Interrupt Mask */
#define SMC_IMR_UNDEF			(1 << 21)

/* Data Timeout Error Interrupt Mask */
#define SMC_IMR_DTOE			(1 << 20)

/* Command Done Interrupt Mask */
#define SMC_IMR_CMDDONE			(1 << 17)

/* Transfer Done Interrupt Mask */
#define SMC_IMR_XFRDONE			(1 << 16)

/* Ready Busy Falling Edge Detection Interrupt Mask */
#define SMC_IMR_RB_FALL			(1 << 5)

/* Ready Busy Rising Edge Detection Interrupt Mask */
#define SMC_IMR_RB_RISE			(1 << 4)


/* --- SMC NFC Address Cycle Zero Register (SMC_ADDR) ---------------------- */

/* NAND Flash Array Address cycle 0 */
#define SMC_ADDR_ADDR_CYCLE0_SHIFT	0
#define SMC_ADDR_ADDR_CYCLE0_MASK	(0xFF << SMC_ADDR_ADDR_CYCLE0_SHIFT)


/* --- SMC NFC Bank Register (SMC_BANK) ------------------------------------ */

/* Bank Identifier */
#define SMC_BANK_BANK_SHIFT		0
#define SMC_BANK_BANK_MASK		(0x07 << SMC_BANK_BANK_SHIFT)


/* --- SMC ECC Control Register (SMC_ECC_CTRL) ----------------------------- */

/* Software Reset */
#define SMC_ECC_CTRL_SWRST		(1 << 1)

/* Reset ECC */
#define SMC_ECC_CTRL_RST		(1 << 0)


/* --- SMC ECC MODE Register (SMC_ECC_MD) ---------------------------------- */

/* Type of Correction */
#define SMC_ECC_MD_TYPCORREC_SHIFT	4
#define SMC_ECC_MD_TYPCORREC_MASK	(0x03 << SMC_ECC_MD_TYPCORREC_SHIFT)

/* Type of Correction Values */
#define SMC_ECC_MD_TYPCORREC_CPAGE	(0x00 << SMC_ECC_MD_TYPCORREC_SHIFT)
#define SMC_ECC_MD_TYPCORREC_C256B	(0x01 << SMC_ECC_MD_TYPCORREC_SHIFT)
#define SMC_ECC_MD_TYPCORREC_C512B	(0x02 << SMC_ECC_MD_TYPCORREC_SHIFT)

/* ECC Page Size */
#define SMC_ECC_MD_ECC_PAGESIZE_SHIFT	0
#define SMC_ECC_MD_ECC_PAGESIZE_MASK	(0x03 << SMC_ECC_MD_ECC_PAGESIZE_SHIFT)

/* ECC Page Size Values */
#define SMC_ECC_MD_ECC_PAGESIZE_PS512_16	(0x00 << SMC_ECC_MD_ECC_PAGESIZE_SHIFT)
#define SMC_ECC_MD_ECC_PAGESIZE_PS1024_32	(0x01 << SMC_ECC_MD_ECC_PAGESIZE_SHIFT)
#define SMC_ECC_MD_ECC_PAGESIZE_PS2048_64	(0x02 << SMC_ECC_MD_ECC_PAGESIZE_SHIFT)
#define SMC_ECC_MD_ECC_PAGESIZE_PS4096_128	(0x03 << SMC_ECC_MD_ECC_PAGESIZE_SHIFT)


/* --- SMC ECC Status Register 1 (SMC_ECC_SR1) ----------------------------- */
/* currently unimplemented */


/* --- SMC ECC Status Register 2 (SMC_ECC_SR2) ----------------------------- */
/* currently unimplemented */


/* --- SMC ECC Parity Register 0 (SMC_ECC_PR0) ----------------------------- */
/* currently unimplemented */


/* --- SMC ECC Parity Register 1 (SMC_ECC_PR1) ----------------------------- */
/* currently unimplemented */


/* --- SMC ECC Parity Registers (SMC_ECC_PRx) ------------------------------ */
/* currently unimplemented */


/* --- SMC Setup Register (SMC_SETUPx) ------------------------------------- */

/* NCS Setup length in Read access */
#define SMC_SETUP_NCS_RD_SETUP_SHIFT	24
#define SMC_SETUP_NCS_RD_SETUP_MASK	(0x3F << SMC_SETUP_NCS_RD_SETUP_SHIFT)

/* NRD Setup length */
#define SMC_SETUP_NRD_SETUP_SHIFT	16
#define SMC_SETUP_NRD_SETUP_MASK	(0x3F << SMC_SETUP_NRD_SETUP_SHIFT)

/* NCS Setup length in Write access */
#define SMC_SETUP_NCS_WR_SETUP_SHIFT	8
#define SMC_SETUP_NCS_WR_SETUP_MASK	(0x3F << SMC_SETUP_NCS_WR_SETUP_SHIFT)

/* NWE Setup Length */
#define SMC_SETUP_NWE_SETUP_SHIFT	0
#define SMC_SETUP_NWE_SETUP_MASK	(0x3F << SMC_SETUP_NWE_SETUP_SHIFT)


/* --- SMC Pulse Register (SMC_PULSEx) ------------------------------------- */

/* NCS Pulse Length in READ Access */
#define SMC_PULSE_NCS_RD_PULSE_SHIFT	24
#define SMC_PULSE_NCS_RD_PULSE_MASK	(0x3F << SMC_PULSE_NCS_RD_PULSE_SHIFT)

/* NRD Pulse Length */
#define SMC_PULSE_NRD_PULSE_SHIFT	16
#define SMC_PULSE_NRD_PULSE_MASK	(0x3F << SMC_PULSE_NRD_PULSE_SHIFT)

/* NCS Pulse Length in WRITE Access */
#define SMC_PULSE_NCS_WR_PULSE_SHIFT	8
#define SMC_PULSE_NCS_WR_PULSE_MASK	(0x3F << SMC_PULSE_NCS_WR_PULSE_SHIFT)

/* NWE Pulse Length */
#define SMC_PULSE_NWE_PULSE_SHIFT	0
#define SMC_PULSE_NWE_PULSE_MASK	(0x3F << SMC_PULSE_NWE_PULSE_SHIFT)


/* --- SMC Cycle Register (SMC_CYCLEx) ------------------------------------- */

/* Total Read Cycle Length */
#define SMC_CYCLE_NRD_CYCLE_SHIFT	16
#define SMC_CYCLE_NRD_CYCLE_MASK	(0x1FF << SMC_CYCLE_NRD_CYCLE_SHIFT)

/* Total Write Cycle Length */
#define SMC_CYCLE_NWE_CYCLE_SHIFT	0
#define SMC_CYCLE_NWE_CYCLE_MASK	(0x1FF << SMC_CYCLE_NWE_CYCLE_SHIFT)


/* --- SMC Timings Register (SMC_TIMINGSx) --------------------------------- */

/* NAND Flash Selection */
#define SMC_TIMINGS_NFSEL		(1 << 31)

/* Ready/Busy Line Selection */
#define SMC_TIMINGS_RBNSEL_SHIFT	28
#define SMC_TIMINGS_RBNSEL_MASK		(0x07 << SMC_TIMINGS_RBNSEL_SHIFT)

/* WEN High to REN to Busy */
#define SMC_TIMINGS_TWB_SHIFT		24
#define SMC_TIMINGS_TWB_MASK		(0x0F << SMC_TIMINGS_TWB_SHIFT)

/* Ready to REN Low Delay */
#define SMC_TIMINGS_TRR_SHIFT		16
#define SMC_TIMINGS_TRR_MASK		(0x0F << SMC_TIMINGS_TRR_SHIFT)

/* Off Chip Memory Scrambling Enable */
#define SMC_TIMINGS_OCMS		(1 << 12)

/* ALE to REN Low Delay */
#define SMC_TIMINGS_TAR_SHIFT		8
#define SMC_TIMINGS_TAR_MASK		(0x0F << SMC_TIMINGS_TAR_SHIFT)

/* ALE to Data Start */
#define SMC_TIMINGS_TADL_SHIFT		4
#define SMC_TIMINGS_TADL_MASK		(0x0F << SMC_TIMINGS_TADL_SHIFT)

/* CLE to REN Low Delay */
#define SMC_TIMINGS_TCLR_SHIFT		0
#define SMC_TIMINGS_TCLR_MASK		(0x0F << SMC_TIMINGS_TCLR_SHIFT)


/* --- SMC Mode Register (SMC_MODEx) --------------------------------------- */

/* TDF Optimization */
#define SMC_MODE_TDF_MODE		(1 << 20)

/* Data Float Time */
#define SMC_MODE_TDF_CYCLES_SHIFT	16
#define SMC_MODE_TDF_CYCLES_MASK	(0x0F << SMC_MODE_TDF_CYCLES_SHIFT)

/* Data Bus Width */
#define SMC_MODE_DBW			(1 << 12)

/* Data Bus Width Values */
#define SMC_MODE_DBW_BIT_8		(0 << 12)
#define SMC_MODE_DBW_BIT_16		(1 << 12)

/* Byte Access Type */
#define SMC_MODE_BAT			(1 << 8)

/* NWAIT Mode */
#define SMC_MODE_EXNW_MODE_SHIFT	4
#define SMC_MODE_EXNW_MODE_MASK		(0x03 << SMC_MODE_EXNW_MODE_SHIFT)

/* NWAIT Mode Values */
#define SMC_MODE_EXNW_MODE_DISABLED	(0x00 << SMC_MODE_EXNW_MODE_SHIFT)
#define SMC_MODE_EXNW_MODE_FROZEN	(0x02 << SMC_MODE_EXNW_MODE_SHIFT)
#define SMC_MODE_EXNW_MODE_READY	(0x03 << SMC_MODE_EXNW_MODE_SHIFT)

/* Write Mode */
#define SMC_MODE_WRITE_MODE		(1 << 1)

/* Read Mode */
#define SMC_MODE_READ_MODE		(1 << 0)


/* --- SMC OCMS Register (SMC_OCMS) ---------------------------------------- */

/* SRAM Scrambling Enable */
#define SMC_OCMS_SRSE			(1 << 1)

/* Static Memory Controller Scrambling Enable */
#define SMC_OCMS_SMSE			(1 << 0)


/* --- SMC Write Protection Control (SMC_WPCR) ----------------------------- */

/* Write Protect Key */
#define SMC_WPCR_WPKEY_SHIFT		8
#define SMC_WPCR_WPKEY_KEY		(0x534D43 << SMC_WPCR_WPKEY_SHIFT)

/* Write Protect Enable */
#define SMC_WPCR_WPEN			(1 << 0)


/* --- SMC Write Protection Status (SMC_WPSR) ------------------------------ */

/* Write Protection Violation Source */
#define SMC_WPSR_WP_VSRC_SHIFT		8
#define SMC_WPSR_WP_VSRC_MASK		(0xFFFF << SMC_WPSR_WP_VSRC_SHIFT)

/* Write Protection Violation Status */
#define SMC_WPSR_WP_VS_SHIFT		0
#define SMC_WPSR_WP_VS_MASK		(0x0F << SMC_WPSR_WP_VS_SHIFT)


#endif
