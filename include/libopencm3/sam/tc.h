/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef SAM3X_TC_H
#define SAM3X_TC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- Timer Counter (TC) registers -------------------------------------- */

#define TC_CCR(x)			MMIO32(TC_BASE + 0x00 + 0x40*(x))
#define TC_CMR(x)			MMIO32(TC_BASE + 0x04 + 0x40*(x))
#define TC_SMMR(x)			MMIO32(TC_BASE + 0x08 + 0x40*(x))
/* 0x0C + 0x40*channel - Reserved */
#define TC_CV(x)			MMIO32(TC_BASE + 0x10 + 0x40*(x))
#define TC_RA(x)			MMIO32(TC_BASE + 0x14 + 0x40*(x))
#define TC_RB(x)			MMIO32(TC_BASE + 0x18 + 0x40*(x))
#define TC_RC(x)			MMIO32(TC_BASE + 0x1C + 0x40*(x))
#define TC_SR(x)			MMIO32(TC_BASE + 0x20 + 0x40*(x))
#define TC_IER(x)			MMIO32(TC_BASE + 0x24 + 0x40*(x))
#define TC_IDR(x)			MMIO32(TC_BASE + 0x28 + 0x40*(x))
#define TC_IMR(x)			MMIO32(TC_BASE + 0x2C + 0x40*(x))
#define TC_BCR				MMIO32(TC_BASE + 0xC0)
#define TC_BMR				MMIO32(TC_BASE + 0xC4)
#define TC_QIER				MMIO32(TC_BASE + 0xC8)
#define TC_QIDR				MMIO32(TC_BASE + 0xCC)
#define TC_QIMR				MMIO32(TC_BASE + 0xD0)
#define TC_QISR				MMIO32(TC_BASE + 0xD4)
#define TC_FMR				MMIO32(TC_BASE + 0xD8)
/* 0x00DC:0x00E0 - Undocumented */
#define TC_WPMR				MMIO32(TC_BASE + 0xE4)
/* 0x00E8:0x00F8 - Undocumented */
/* 0x00FC - Reserved */

/* TC Block Contol Register (TC_BCR) */
/* Bits [31:1]: Reserved. */
#define TC_BCR_SYNC				(1<<0)

/* TC Block Mode Register (TC_BMR) */
/* Bits [31:26]: Reserved. */
#define TC_BMR_MAXFILT_MASK		(0x3F<<20)
#define TC_BMR_FILTER			(1<<19)
/* Bit 18: Reserved. */
#define TC_BMR_IDXPHB			(1<<17)
#define TC_BMR_SWAP				(1<<16)
#define TC_BMR_INVIDX			(1<<15)
#define TC_BMR_INVB				(1<<14)
#define TC_BMR_INVA				(1<<13)
#define TC_BMR_EDGPHA			(1<<12)
#define TC_BMR_QDTRANS			(1<<11)
#define TC_BMR_SPEEDEN			(1<<10)
#define TC_BMR_POSEN			(1<<9)
#define TC_BMR_QDEN				(1<<8)
/* Bits [7:6]: Reserved. */
#define TC_BMR_TC2XC2S_MASK		(0x3<<4)
#define TC_BMR_TC2XC2S_TCKL2	(0x0<<4)
#define TC_BMR_TC2XC2S_TIOA1	(0x2<<4)
#define TC_BMR_TC2XC2S_TIOA2	(0x3<<4)
#define TC_BMR_TC1XC1S_MASK		(0x3<<2)
#define TC_BMR_TC1XC1S_TCKL1	(0x0<<2)
#define TC_BMR_TC1XC1S_TIOA0	(0x2<<2)
#define TC_BMR_TC1XC1S_TIOA2	(0x3<<2)
#define TC_BMR_TC0XC0S_MASK		(0x3<<0)
#define TC_BMR_TC0XC0S_TCKL0	(0x0<<0)
#define TC_BMR_TC0XC0S_TIOA1	(0x2<<0)
#define TC_BMR_TC0XC0S_TIOA2	(0x2<<0)

/* TC Channel Control Register (TC_CCR(x)) */
/* Bits [31:3]: Reserved. */
#define TC_CCR_SWTRG			(1<<2)
#define TC_CCR_CLKDIS			(1<<1)
#define TC_CCR_CLKEN			(1<<0)

/* TC QDEC Interrupt Registers (TC_QIER, TC_QIDR, TC_QIMR and TC_QISR) */
/* Bits [31:9]: Reserved. */
#define TC_QINT_DIR			(1<<8)	/* Valid for TC_QISR only */
/* Bits [7:3]: Reserved. */
#define TC_QINT_QERR		(1<<2)
#define TC_QINT_DIRCHG		(1<<1)
#define TC_QINT_IDX			(1<<0)

/* TC Fault Mode Register (TC_FMR) */
#define TC_FMR_ENCF1		(1<<1)
#define TC_FMR_ENCF0		(1<<0)

/* TC Write Protect Mode Register (TC_WPMR) */
#define TC_WPMR_FKEY		(0x54494D << 8)
/* Bits [7:1]: Reserved. */
#define TC_WPMR_WPEN		(1<<0)

/* TC Channel Mode Register: Common Fields (TC_CMR(x)) */
#define TC_CMR_WAVE				(1<<15)
#define TC_CMR_BURST_MASK		(0x3<<4)
#define TC_CMR_BURST_NONE		(0x0<<4)
#define TC_CMR_BURST_XC0		(0x1<<4)
#define TC_CMR_BURST_XC1		(0x2<<4)
#define TC_CMR_BURST_XC2		(0x3<<4)
#define TC_CMR_CLKI				(1<<3)
#define TC_CMR_TCCLKS_MASK		(0x7<<0)
#define TC_CMR_TCCLKS_TCLK1		(0x0<<0)
#define TC_CMR_TCCLKS_TCLK2		(0x1<<0)
#define TC_CMR_TCCLKS_TCLK3		(0x2<<0)
#define TC_CMR_TCCLKS_TCLK4		(0x3<<0)
#define TC_CMR_TCCLKS_TCLK5		(0x4<<0)
#define TC_CMR_TCCLKS_XC0		(0x5<<0)
#define TC_CMR_TCCLKS_XC1		(0x6<<0)
#define TC_CMR_TCCLKS_XC2		(0x7<<0)

/* TC Channel Mode Register: Capture Mode (TC_CMR(x): WAVE=0) */
/* Bits [31:20]: Reserved. */
#define TC_CMR_LDRB_MASK		(0x3<<18)
#define TC_CMR_LDRB_NONE			(0x0<<18)
#define TC_CMR_LDRB_RISING			(0x1<<18)
#define TC_CMR_LDRB_FALLING			(0x2<<18)
#define TC_CMR_LDRB_EDGE			(0x3<<18)
#define TC_CMR_LDRA_MASK		(0x3<<16)
#define TC_CMR_LDRA_NONE			(0x0<<16)
#define TC_CMR_LDRA_RISING			(0x1<<16)
#define TC_CMR_LDRA_FALLING			(0x2<<16)
#define TC_CMR_LDRA_EDGE			(0x3<<16)
/* Bit 15: Waveform/Capture Mode */
#define TC_CMR_CPCTRG			(1<<14)
/* Bits [13:11]: Reserved. */
#define TC_CMR_ABETRG			(1<<10)
#define TC_CMR_ETRGEDG_MASK		(0x3<<8)
#define TC_CMR_ETRGEDG_NONE			(0x0<<8)
#define TC_CMR_ETRGEDG_RISING		(0x1<<8)
#define TC_CMR_ETRGEDG_FALLING		(0x2<<8)
#define TC_CMR_ETRGEDG_EDGE			(0x3<<8)
#define TC_CMR_LDBDIS			(1<<7)
#define TC_CMR_LDBSTOP			(1<<6)
/* Bits [5:0]: Burst, Clock Inversion, and Clock Selection */

/* TC Channel Mode Register: Waveform Mode (TC_CMR(x): WAVE=1) */
#define TC_CMR_BSWTRG_MASK		(0x3<<30)
#define TC_CMR_BSWTRG_NONE			(0x0<<30)
#define TC_CMR_BSWTRG_SET			(0x1<<30)
#define TC_CMR_BSWTRG_CLEAR			(0x2<<30)
#define TC_CMR_BSWTRG_TOGGLE		(0x3<<30)
#define TC_CMR_BEEVT_MASK		(0x3<<28)
#define TC_CMR_BEEVT_NONE			(0x0<<28)
#define TC_CMR_BEEVT_SET			(0x1<<28)
#define TC_CMR_BEEVT_CLEAR			(0x2<<28)
#define TC_CMR_BEEVT_TOGGLE			(0x3<<28)
#define TC_CMR_BCPC_MASK		(0x3<<26)
#define TC_CMR_BCPC_NONE			(0x0<<26)
#define TC_CMR_BCPC_SET				(0x1<<26)
#define TC_CMR_BCPC_CLEAR			(0x2<<26)
#define TC_CMR_BCPC_TOGGLE			(0x3<<26)
#define TC_CMR_BCPB_MASK		(0x3<<24)
#define TC_CMR_BCPB_NONE			(0x0<<24)
#define TC_CMR_BCPB_SET				(0x1<<24)
#define TC_CMR_BCPB_CLEAR			(0x2<<24)
#define TC_CMR_BCPB_TOGGLE			(0x3<<24)
#define TC_CMR_ASWTRG_MASK		(0x3<<22)
#define TC_CMR_ASWTRG_NONE			(0x0<<22)
#define TC_CMR_ASWTRG_SET			(0x1<<22)
#define TC_CMR_ASWTRG_CLEAR			(0x2<<22)
#define TC_CMR_ASWTRG_TOGGLE		(0x3<<22)
#define TC_CMR_AEEVT_MASK		(0x3<<20)
#define TC_CMR_AEEVT_NONE			(0x0<<20)
#define TC_CMR_AEEVT_SET			(0x1<<20)
#define TC_CMR_AEEVT_CLEAR			(0x2<<20)
#define TC_CMR_AEEVT_TOGGLE			(0x3<<20)
#define TC_CMR_ACPC_MASK		(0x3<<18)
#define TC_CMR_ACPC_NONE			(0x0<<18)
#define TC_CMR_ACPC_SET				(0x1<<18)
#define TC_CMR_ACPC_CLEAR			(0x2<<18)
#define TC_CMR_ACPC_TOGGLE			(0x3<<18)
#define TC_CMR_ACPA_MASK		(0x3<<16)
#define TC_CMR_ACPA_NONE			(0x0<<16)
#define TC_CMR_ACPA_SET				(0x1<<16)
#define TC_CMR_ACPA_CLEAR			(0x2<<16)
#define TC_CMR_ACPA_TOGGLE			(0x3<<16)
/* Bit 15: Waveform/Capture Mode */
#define TC_CMR_WAVESEL_MASK		(0x3<<13)
#define TC_CMR_WAVESEL_UP			(0x0<<13)
#define TC_CMR_WAVESEL_UPDOWN		(0x1<<13)
#define TC_CMR_WAVESEL_UP_RC		(0x2<<13)
#define TC_CMR_WAVESEL_UPDOWN_RC	(0x3<<13)
#define TC_CMR_ENETRG			(1<<12)
#define TC_CMR_EEVT_MASK		(0x3<<10)
#define TC_CMR_EEVT_TIOB			(0x0<<10)
#define TC_CMR_EEVT_XC0				(0x1<<10)
#define TC_CMR_EEVT_XC1				(0x2<<10)
#define TC_CMR_EEVT_XC2				(0x3<<10)
#define TC_CMR_EEVTEDG_MASK		(0x3<<8)
#define TC_CMR_EEVTEDG_NONE			(0x0<<8)
#define TC_CMR_EEVTEDG_RISING		(0x1<<8)
#define TC_CMR_EEVTEDG_FALLING		(0x2<<8)
#define TC_CMR_EEVTEDG_EDGE			(0x3<<8)
#define TC_CMR_CPCDIS			(1<<7)
#define TC_CMR_CPCSTOP			(1<<6)
/* Bits [5:0]: Burst, Clock Inversion, and Clock Selection */

/* TC Stepper Motor Mode Register (TC_SMMR(x)) */
/* Bits [31:2]: Reserved. */
#define TC_SMMR_DOWN			(1<<1)
#define TC_SMMR_GCEN			(1<<0)

/* TC Status Register (TC_SR(x)) */
/* Bits [31:19]: Reserved. */
#define TC_SR_MTIOB			(1<<18)
#define TC_SR_MTIOA			(1<<17)
#define TC_SR_CLKSTA		(1<<16)
/* Bits [15:8]: Reserved. */
#define TC_SR_ETRGS			(1<<7)
#define TC_SR_LDRBS			(1<<6)
#define TC_SR_LDRAS			(1<<5)
#define TC_SR_CPCS			(1<<4)
#define TC_SR_CPBS			(1<<3)
#define TC_SR_CPAS			(1<<2)
#define TC_SR_LOVRS			(1<<1)
#define TC_SR_COVRS			(1<<0)

/* TC Interrupt and Registers (TC_IER(x), TC_IDR(x), and TC_IMR(x)) */
/* Bits [31:8]: Reserved. */
#define TC_INT_ETRGS		(1<<7)
#define TC_INT_LDRBS		(1<<6)
#define TC_INT_LDRAS		(1<<5)
#define TC_INT_CPCS			(1<<4)
#define TC_INT_CPBS			(1<<3)
#define TC_INT_CPAS			(1<<2)
#define TC_INT_LOVRS		(1<<1)
#define TC_INT_COVRS		(1<<0)

#endif
