/** @addtogroup dsi_defines
 *
 * @version 1.0.0
 *
 * @date 7 July 2016
 *
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Chuck McManis <cmcmanis@mcmanis.com>
 * 
 * This library supports the Display Serial Interface Host and Wrapper in
 * the STM32F4xx and STM32F7xx series of ARM Cortex Microcontrollers by
 * ST Microelectronics.
 * 
 * LGPL License Terms @ref lgpl_license
 */

/*
 * STM32F4/7 DSI Host Defines
 *
 * Copyright (C) 2016, Chuck McManis <cmcmanis@mcmanis.com>
 *
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
 *
 */

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/** @cond */
#ifndef DSI_H
/** @endcond */
#define DSI_H

/**@{*/


/**
 * DSI Host Version Register
 */
#define DSI_VR				MMIO32(DSI_BASE + 0x0U)

/**
 * DSI Host Control Register
 */
#define DSI_CR				MMIO32(DSI_BASE + 0x4U)
#define DSI_CR_EN			(1 << 0)

/**
 * DSI Host Clock Control Register
 */
#define DSI_CCR				MMIO32(DSI_BASE + 0x8U)
#define DSI_CCR_TOCKDIV_SHIFT		8
#define DSI_CCR_TOCKDIV_MASK		0xff
#define DSI_CCR_TXECKDIV_SHIFT		0
#define DSI_CCR_TXECKDIV_MASK		0xff

/**
 * DSI Host LTDC VCID Register
 */
#define DSI_LVCIDR			MMIO32(DSI_BASE + 0xcU)
#define DSI_LVCIDR_VCID_SHIFT		0
#define DSI_LVCIDR_VCID_MASK		0x3

/**
 * DSI Host LTDC Color Coding Register
 */
#define DSI_LCOLCR			MMIO32(DSI_BASE + 0x10U)
#define DSI_LCOLCR_LPE			(1 << 8)
#define DSI_LCOLCR_COLC_SHIFT		0
#define DSI_LCOLCR_COLC_MASK		0xf

/**
 * DSI Host LTDC Polarity Configuration Register
 */
#define DSI_LPCR			MMIO32(DSI_BASE + 0x14U)
#define DSI_LPCR_HSP			(1 << 2)
#define DSI_LPCR_VSP			(1 << 1)
#define DSI_LPCR_DEP			(1 << 0)

/**
 * DSI Host Low-power Configuration Register
 */
#define DSI_LPMCR			MMIO32(DSI_BASE + 0x18U)
#define DSI_LPMCR_LPSIZE_SHIFT		16
#define DSI_LPMCR_LPSIZE_MASK		0xff
#define DSI_LPMCR_VLPSIZE_SHIFT		0
#define DSI_LPMCR_VLPSIZE_MASK		0xff

/**
 * DSI Host Protocol Configuration Register
 */
#define DSI_PCR				MMIO32(DSI_BASE + 0x2cU)
#define DSI_PCR_CRCRXE			(1 << 4)
#define DSI_PCR_ECCRXE			(1 << 3)
#define DSI_PCR_BTAE			(1 << 2)
#define DSI_PCR_ETRXE			(1 << 1)
#define DSI_PCR_ETTXE			(1 << 0)

/**
 * DSI Host Generic VCID Register
 */
#define DSI_GVCIDR			MMIO32(DSI_BASE + 0x30U)
#define DSI_GVCIDR_VCID_SHIFT		0
#define DSI_GVCIDR_VCID_MASK		0x3

/**
 * DSI Host mode Configuration Register
 */
#define DSI_MCR				MMIO32(DSI_BASE + 0x34U)
#define DSI_MCR_CMDM			(1 << 0)

/**
 * DSI Host Video mode Configuration Register
 */
#define DSI_VMCR			MMIO32(DSI_BASE + 0x38U)
#define DSI_VMCR_PGO			(1 << 24)
#define DSI_VMCR_PGM			(1 << 20)
#define DSI_VMCR_PGE			(1 << 16)
#define DSI_VMCR_LPCE			(1 << 15)
#define DSI_VMCR_FBTAAE			(1 << 14)
#define DSI_VMCR_LPHFPE			(1 << 13)
#define DSI_VMCR_LPHBPE			(1 << 12)
#define DSI_VMCR_LPVAE			(1 << 11)
#define DSI_VMCR_LPVFPE			(1 << 10)
#define DSI_VMCR_LPVBPE			(1 << 9)
#define DSI_VMCR_LPVSAE			(1 << 8)
#define DSI_VMCR_VMT_SHIFT		0
#define DSI_VMCR_VMT_MASK		0x3
#define DSI_VMCR_VMT_NON_BURST_PULSE	0x0
#define DSI_VMCR_VMT_NON_BURSE_EVENT	0x1
#define DSI_VMCR_VMT_BURST		0x2

/**
 * DSI Host Video Packet Configuration Register
 */
#define DSI_VPCR			MMIO32(DSI_BASE + 0x3CU)
#define DSI_VPCR_VPSIZE_SHIFT		0
#define DSI_VPCR_VPSIZE_MASK		0x3fff

/**
 * DSI Host Video Chunks Configuration Register
 */
#define DSI_VCCR			MMIO32(DSI_BASE + 0x40U)
#define DSI_VCCR_NUMC_SHIFT		0
#define DSI_VCCR_NUMC_MASK		0x1fff

/**
 * DSI Host Video Null Packet Configuration Register
 */
#define DSI_VNPCR			MMIO32(DSI_BASE + 0x44U)
#define DSI_VNPCR_NPSIZE_SHIFT		0
#define DSI_VNPCR_NPSIZE_MASK		0x1fff

/**
 * DSI Host Video HSA Configuration Register
 */
#define DSI_VHSACR			MMIO32(DSI_BASE + 0x48U)
#define DSI_VHSACR_HSA_SHIFT		0
#define DSI_VHSACR_HSA_MASK		0xfff

/**
 * DSI Host Video HBP Configuration Register
 */
#define DSI_VHBPCR			MMIO32(DSI_BASE + 0x4CU)
#define DSI_VHBPCR_HBP_SHIFT		0
#define DSI_VHBPCR_HBP_MASK		0xfff

/**
 * DSI Host Video Line Configuration Register
 */
#define DSI_VLCR			MMIO32(DSI_BASE + 0x50U)
#define DSI_VLCR_HLINE_SHIFT		0
#define DSI_VLCR_HLINE_MASK		0x7fff

/**
 * DSI Host Video VSA Configuration Register
 */
#define DSI_VVSACR			MMIO32(DSI_BASE + 0x54U)
#define DSI_VVSACR_VSA_SHIFT		0
#define DSI_VVSACR_VSA_MASK		0x3ff

/**
 * DSI Host Video VBP Configuration Register
 */
#define DSI_VVBPCR			MMIO32(DSI_BASE + 0x58U)
#define DSI_VVBPCR_VBP_SHIFT		0
#define DSI_VVBPCR_VBP_MASK		0x3ff

/**
 * DSI Host Video VFP Configuration Register
 */
#define DSI_VVFPCR			MMIO32(DSI_BASE + 0x5CU)
#define DSI_VVFPCR_VFP_SHIFT		0
#define DSI_VVFPCR_VFP_MASK		0x3ff

/**
 * DSI Host Video VA Configuration Register
 */
#define DSI_VVACR			MMIO32(DSI_BASE + 0x60U)
#define DSI_VVACR_VA_SHIFT		0
#define DSI_VVACR_VA_MASK		0x3fff

/**
 * DSI Host LTDC Command Configuration Register
 */
#define DSI_LCCR			MMIO32(DSI_BASE + 0x64U)
#define DSI_LCCR_CMDSIZE_SHIFT		0
#define DSI_LCCR_CMDSIZE_MASK		0xffff

/**
 * DSI Host Command mode Configuration Register
 */
#define DSI_CMCR			MMIO32(DSI_BASE + 0x68U)
#define DSI_CMCR_MRDPS			(1 << 24)
#define DSI_CMCR_DLWTX			(1 << 19)
#define DSI_CMCR_DSR0TX			(1 << 18)
#define DSI_CMCR_DSW1TX			(1 << 17)
#define DSI_CMCR_DSW0TX			(1 << 16)
/* Bit 15 reserved */
#define DSI_CMCR_GLWTX			(1 << 14)
#define DSI_CMCR_GSR2TX			(1 << 13)
#define DSI_CMCR_GSR1TX			(1 << 12)
#define DSI_CMCR_GSR0TX			(1 << 11)
#define DSI_CMCR_GSW2TX			(1 << 10)
#define DSI_CMCR_GSW1TX			(1 << 9)
#define DSI_CMCR_GSW0TX			(1 << 8)
/* Bits 7:2 Reserved */
#define DSI_CMCR_ARE			(1 << 1)
#define DSI_CMCR_TEARE			(1 << 0)

/**
 * DSI Host Generic Header Configuration Register
 */
#define DSI_GHCR			MMIO32(DSI_BASE + 0x6CU)
#define DSI_GHCR_WCMSB_SHIFT		16
#define DSI_GHCR_WCMSB_MASK		0xff
#define DSI_GHCR_WCLSB_SHIFT		8
#define DSI_GHCR_WCLSB_MASK		0xff
#define DSI_GHCR_DATA1_SHIFT		16	/* data 1 in 'short' mode */
#define DSI_GHCR_DATA1_MASK		0xff
#define DSI_GHCR_DATA0_SHIFT		8	/* data 0 in 'short' mode */
#define DSI_GHCR_DATA0_MASK		0xff
#define DSI_GHCR_VCID_SHIFT		6
#define DSI_GHCR_VCID_MASK		0x3
#define DSI_GHCR_DT_SHIFT		0
#define DSI_GHCR_DT_MASK		0x3f

/**
 * DSI Host Generic Payload Data Register
 */
#define DSI_GPDR			MMIO32(DSI_BASE + 0x70U)
#define DSI_GPDR_BYTE4_SHIFT		24
#define DSI_GPDR_BYTE4_MASK		0xff
#define DSI_GPDR_BYTE3_SHIFT		16
#define DSI_GPDR_BYTE3_MASK		0xff
#define DSI_GPDR_BYTE2_SHIFT		8
#define DSI_GPDR_BYTE2_MASK		0xff
#define DSI_GPDR_BYTE1_SHIFT		0
#define DSI_GPDR_BYTE1_MASK		0xff

/**
 * DSI Host Generate Packet Status Register
 */
#define DSI_GPSR			MMIO32(DSI_BASE + 0x74U)
/* Reserved 31:7 */
#define DSI_GPSR_RCB			(1 << 6)
#define DSI_GPSR_PRDFF			(1 << 5)
#define DSI_GPSR_PRDFE			(1 << 4)
#define DSI_GPSR_PWRFF			(1 << 3)
#define DSI_GPSR_PWRFE			(1 << 2)
#define DSI_GPSR_CMDFF			(1 << 1)
#define DSI_GPSR_CMDFE			(1 << 0)

/**
 * DSI Host Timeout Counter Configuration Register
 */
#define DSI_TCCR0			MMIO32(DSI_BASE + 0x78U)
#define DSI_TCCR0_HSTX_TOCNT_SHIFT	16
#define DSI_TCCR0_HSTX_TOCNT_MASK	0xffff
#define DSI_TCCR0_LPRX_TOCNT_SHIFT	0
#define DSI_TCCR0_LPRX_TOCNT_MASK	0xffff

/**
 * DSI Host Timeout Counter Configuration Register 1
 */
#define DSI_TCCR1			MMIO32(DSI_BASE + 0x7CU)
#define DSI_TCCR1_HSRD_TOCNT_SHIFT	0
#define DSI_TCCR1_HSRD_TOCNT_MASK	0xffff

/**
 * DSI Host Timeout Counter Configuration Register 2
 */
#define DSI_TCCR2			MMIO32(DSI_BASE + 0x80U)
#define DSI_TCCR2_LPRD_TOCNT_SHIFT	0
#define DSI_TCCR2_LPRD_TOCNT_MASK	0xffff

/**
 * DSI Host Timeout Counter Configuration Register 3
 */
#define DSI_TCCR3			MMIO32(DSI_BASE + 0x84U)
#define DSI_TCCR3_PM			(1 << 24)
#define DSI_TCCR3_HSWR_TOCNT_SHIFT	0
#define DSI_TCCR3_HSWR_TOCNT_MASK	0xffff

/**
 * DSI Host Timeout Counter Configuration Register 4
 */
#define DSI_TCCR4			MMIO32(DSI_BASE + 0x88U)
#define DSI_TCCR4_LPWR_TOCNT_SHIFT	0
#define DSI_TCCR4_LPWR_TOCNT_MASK	0xffff

/**
 * DSI Host Timeout Counter Configuration Register 5
 */
#define DSI_TCCR5			MMIO32(DSI_BASE + 0x8CU)
#define DSI_TCCR5_BTA_TOCNT_SHIFT	0
#define DSI_TCCR5_BTA_TOCNT_MASK	0xffff

/**
 * DSI Host Clock Lane Configuration Register
 */
#define DSI_CLCR			MMIO32(DSI_BASE + 0x94U)
#define DSI_CLCR_ACR			(1 << 1)
#define DSI_CLCR_DPCC			(1 << 0)

/**
 * DSI Host Clock Lane Timer Configuration Register
 */
#define DSI_CLTCR			MMIO32(DSI_BASE + 0x98U)
#define DSI_CLTCR_HS2LP_TIME_SHIFT	16
#define DSI_CLTCR_HS2LP_TIME_MASK	0x3ff
#define DSI_CLTCR_LP2HS_TIME_SHIFT	0
#define DSI_CLTCR_LP2HS_TIME_MASK	0x3ff

/**
 * DSI Host Data Lane Time Configuration Register
 */
#define DSI_DLTCR			MMIO32(DSI_BASE + 0x9CU)
#define DSI_DLTCR_HS2LP_TIME_SHIFT	24
#define DSI_DLTCR_HS2LP_TIME_MASK	0xff
#define DSI_DLTCR_LP2HS_TIME_SHIFT	16
#define DSI_DLTCR_LP2HS_TIME_MASK	0xff
#define DSI_DLTCR_MRD_TIME_SHIFT	0
#define DSI_DLTCR_MRD_TIME_MASK		0x7fff

/**
 * DSI Host PHY Control Register
 */
#define DSI_PCTLR			MMIO32(DSI_BASE + 0xA0U)
#define DSI_PCTLR_CKE			(1 << 2)
#define DSI_PCTLR_DEN			(1 << 1)

/**
 * DSI Host PHY Configuration Register
 */
#define DSI_PCONFR			MMIO32(DSI_BASE + 0xA4U)
#define DSI_PCONFR_SW_TIME_SHIFT	8
#define DSI_PCONFR_SW_TIME_MASK		0xff
#define DSI_PCONFR_NL_SHIFT		0
#define DSI_PCONFR_NL_MASK		0x3
#define DSI_PCONFR_NL_1LANE		0
#define DSI_PCONFR_NL_2LANE		1

/**
 * DSI Host PHY ULPS Control Register
 */
#define DSI_PUCR			MMIO32(DSI_BASE + 0xA8U)
#define DSI_PUCR_UEDL			(1 << 3)
#define DSI_PUCR_URDL			(1 << 2)
#define DSI_PUCR_UECL			(1 << 1)
#define DSI_PUCR_URCL			(1 << 0)

/**
 * DSI Host PHY TX Triggers Configuration Register
 */
#define DSI_PTTCR			MMIO32(DSI_BASE + 0xACU)
#define DSI_PTTCR_TX_TRIG_SHIFT		0
#define DSI_PTTCR_TX_TRIG_MASK		0xf
#define DSI_PTTCR_TX_TRIG_1		0x1
#define DSI_PTTCR_TX_TRIG_2		0x2
#define DSI_PTTCR_TX_TRIG_3		0x4
#define DSI_PTTCR_TX_TRIG_4		0x8

/**
 * DSI Host PHY Status Register
 */
#define DSI_PSR				MMIO32(DSI_BASE + 0xB0U)
#define DSI_PSR_UAN1			(1 << 8)
#define DSI_PSR_PSS1			(1 << 7)
#define DSI_PSR_RUE0			(1 << 6)
#define DSI_PSR_UAN0			(1 << 5)
#define DSI_PSR_PSS0			(1 << 4)
#define DSI_PSR_UANC			(1 << 3)
#define DSI_PSR_PSSC			(1 << 2)
#define DSI_PSR_PD			(1 << 1)

/**
 * DSI Host Interrupt & Status Register 0
 */
#define DSI_ISR0			MMIO32(DSI_BASE + 0xBCU)
#define DSI_ISR0_PE4			(1 << 20)
#define DSI_ISR0_PE3			(1 << 19)
#define DSI_ISR0_PE2			(1 << 18)
#define DSI_ISR0_PE1			(1 << 17)
#define DSI_ISR0_PE0			(1 << 16)
#define DSI_ISR0_AE15			(1 << 15)
#define DSI_ISR0_AE14			(1 << 14)
#define DSI_ISR0_AE13			(1 << 13)
#define DSI_ISR0_AE12			(1 << 12)
#define DSI_ISR0_AE11			(1 << 11)
#define DSI_ISR0_AE10			(1 << 10)
#define DSI_ISR0_AE9			(1 << 9)
#define DSI_ISR0_AE8			(1 << 8)
#define DSI_ISR0_AE7			(1 << 7)
#define DSI_ISR0_AE6			(1 << 6)
#define DSI_ISR0_AE5			(1 << 5)
#define DSI_ISR0_AE4			(1 << 4)
#define DSI_ISR0_AE3			(1 << 3)
#define DSI_ISR0_AE2			(1 << 2)
#define DSI_ISR0_AE1			(1 << 1)
#define DSI_ISR0_AE0			(1 << 0)

/**
 * DSI Host Interrupt & Status Register 1
 */
#define DSI_ISR1			MMIO32(DSI_BASE + 0xC0U)
#define DSI_ISR1_GPRXE			(1 << 12)
#define DSI_ISR1_GPRDE			(1 << 11)
#define DSI_ISR1_GPTXE			(1 << 10)
#define DSI_ISR1_GPWRE			(1 << 9)
#define DSI_ISR1_GCWRE			(1 << 8)
#define DSI_ISR1_LPWRE			(1 << 7)
#define DSI_ISR1_EOTPE			(1 << 6)
#define DSI_ISR1_PSE			(1 << 5)
#define DSI_ISR1_CRCE			(1 << 4)
#define DSI_ISR1_ECCME			(1 << 3)
#define DSI_ISR1_ECCSE			(1 << 2)
#define DSI_ISR1_TOLPRX			(1 << 1)
#define DSI_ISR1_TOHSTX			(1 << 0)

/**
 * DSI Host Interrupt Enable Register 0
 */
#define DSI_IER0			MMIO32(DSI_BASE + 0xC4U)
#define DSI_IER0_PE4IE			(1 << 20)
#define DSI_IER0_PE3IE			(1 << 19)
#define DSI_IER0_PE2IE			(1 << 18)
#define DSI_IER0_PE1IE			(1 << 17)
#define DSI_IER0_PE0IE			(1 << 16)
#define DSI_IER0_AE15IE			(1 << 15)
#define DSI_IER0_AE14IE			(1 << 14)
#define DSI_IER0_AE13IE			(1 << 13)
#define DSI_IER0_AE12IE			(1 << 12)
#define DSI_IER0_AE11IE			(1 << 11)
#define DSI_IER0_AE10IE			(1 << 10)
#define DSI_IER0_AE9IE			(1 << 9)
#define DSI_IER0_AE8IE			(1 << 8)
#define DSI_IER0_AE7IE			(1 << 7)
#define DSI_IER0_AE6IE			(1 << 6)
#define DSI_IER0_AE5IE			(1 << 5)
#define DSI_IER0_AE4IE			(1 << 4)
#define DSI_IER0_AE3IE			(1 << 3)
#define DSI_IER0_AE2IE			(1 << 2)
#define DSI_IER0_AE1IE			(1 << 1)
#define DSI_IER0_AE0IE			(1 << 0)

/**
 * DSI Host Interrupt Enable Register 1
 */
#define DSI_IER1			MMIO32(DSI_BASE + 0xC8U)
#define DSI_IER1_GPRXEIE		(1 << 12)
#define DSI_IER1_GPRDEIE		(1 << 11)
#define DSI_IER1_GPTXEIE		(1 << 10)
#define DSI_IER1_GPWREIE		(1 << 9)
#define DSI_IER1_GCWREIE		(1 << 8)
#define DSI_IER1_LPWREIE		(1 << 7)
#define DSI_IER1_EOTPEIE		(1 << 6)
#define DSI_IER1_PSEIE			(1 << 5)
#define DSI_IER1_CRCEIE			(1 << 4)
#define DSI_IER1_ECCMEIE		(1 << 3)
#define DSI_IER1_ECCSEIE		(1 << 2)
#define DSI_IER1_TOLPRXIE		(1 << 1)
#define DSI_IER1_TOHSTXIE		(1 << 0)

/**
 * DSI Host Force Interrupt Register 0
 */
#define DSI_FIR0			MMIO32(DSI_BASE + 0xD8U)
#define DSI_FIR0_FPE4			(1 << 20)
#define DSI_FIR0_FPE3			(1 << 19)
#define DSI_FIR0_FPE2			(1 << 18)
#define DSI_FIR0_FPE1			(1 << 17)
#define DSI_FIR0_FPE0			(1 << 16)
#define DSI_FIR0_FAE15			(1 << 15)
#define DSI_FIR0_FAE14			(1 << 14)
#define DSI_FIR0_FAE13			(1 << 13)
#define DSI_FIR0_FAE12			(1 << 12)
#define DSI_FIR0_FAE11			(1 << 11)
#define DSI_FIR0_FAE10			(1 << 10)
#define DSI_FIR0_FAE9			(1 << 9)
#define DSI_FIR0_FAE8			(1 << 8)
#define DSI_FIR0_FAE7			(1 << 7)
#define DSI_FIR0_FAE6			(1 << 6)
#define DSI_FIR0_FAE5			(1 << 5)
#define DSI_FIR0_FAE4			(1 << 4)
#define DSI_FIR0_FAE3			(1 << 3)
#define DSI_FIR0_FAE2			(1 << 2)
#define DSI_FIR0_FAE1			(1 << 1)
#define DSI_FIR0_FAE0			(1 << 0)

/**
 * DSI Host Force Interrupt Register 1
 */
#define DSI_FIR1			MMIO32(DSI_BASE + 0xDCU)
#define DSI_FIR1_FGPRXE			(1 << 12)
#define DSI_FIR1_FGPRDE			(1 << 11)
#define DSI_FIR1_FGPTXE			(1 << 10)
#define DSI_FIR1_FGPWRE			(1 << 9)
#define DSI_FIR1_FGCWRE			(1 << 8)
#define DSI_FIR1_FLPWRE			(1 << 7)
#define DSI_FIR1_FEOTPE			(1 << 6)
#define DSI_FIR1_FPSE			(1 << 5)
#define DSI_FIR1_FCRCE			(1 << 4)
#define DSI_FIR1_FECCME			(1 << 3)
#define DSI_FIR1_FECCSE			(1 << 2)
#define DSI_FIR1_FTOLPRX		(1 << 1)
#define DSI_FIR1_FTOHSTX		(1 << 0)

/**
 * DSI Host Video Shadow Control Register
 */
#define DSI_VSCR			MMIO32(DSI_BASE + 0x100U)
#define DSI_VSCR_UR			(1 << 8)
#define DSI_VSCR_EN			(1 << 0)

/**
 * DSI Host LTDC Current VCID Register
 */
#define DSI_LCVCIDR			MMIO32(DSI_BASE + 0x10CU)
#define DSI_LCVCIDR_VCID_SHIFT		0
#define DSI_LCVCIDR_VCID_MASK		0x3

/**
 * DSI Host LTCD Current Color Coding Register
 */
#define DSI_LCCCR			MMIO32(DSI_BASE + 0x110U)
#define DSI_LCCR_LPE			(1 << 8)
#define DSI_LCCR_COLC_SHIFT		0
#define DSI_LCCR_COLC_MASK		0xf

/**
 * DSI Host Low-power mode Current Configuration Register
 */
#define DSI_LPMCCR			MMIO32(DSI_BASE + 0x118U)
#define DSI_LPMCCR_LPSIZE_SHIFT		16
#define DSI_LPMCCR_LPSIZE_MASK		0xff
#define DSI_LPMCCR_VLPSIZE_SHIFT	0
#define DSI_LPMCCR_VLPSIZE_MASK		0xff

/**
 * DSI Host Video mode Current Configuration Register
 */
#define DSI_VMCCR			MMIO32(DSI_BASE + 0x138U)
#define DSI_VMCCR_LPCE			(1 << 9)
#define DSI_VMCCR_FBTAAE		(1 << 8)
#define DSI_VMCCR_LPHFE			(1 << 7)
#define DSI_VMCCR_LPHBPE		(1 << 6)
#define DSI_VMCCR_LPVAE			(1 << 5)
#define DSI_VMCCR_LPVFPE		(1 << 4)
#define DSI_VMCCR_LPVBPE		(1 << 3)
#define DSI_VMCCR_LPVSAE		(1 << 2)
#define DSI_VMCCR_VMT_SHIFT		0
#define DSI_VMCCR_VMT_MASK		0x3

/**
 * DSI Host Video Packet Current Configuration Register
 */
#define DSI_VPCCR			MMIO32(DSI_BASE + 0x13CU)
#define DSI_VPCCR_VPSIZE_SHIFT		0
#define DSI_VPCCR_VPSIZE_MASK		0x3fff

/**
 * DSI Host Video Chunks Current Configuration Register
 */
#define DSI_VCCCR			MMIO32(DSI_BASE + 0x140U)
#define DSI_VCCCR_NUMC_SHIFT		0
#define DSI_VCCCR_NUMC_MASK		0x1fff

/**
 * DSI Host Video Null Packet Current Configuration Register
 */
#define DSI_VNPCCR			MMIO32(DSI_BASE + 0x144U)
#define DSI_VNPCCR_NPSIZE_SHIFT		0
#define DSI_VNPCCR_NPSIZE_MASK		0x1fff

/**
 * DSI Host Video HSA Current Configuration Register
 */
#define DSI_VHSACCR			MMIO32(DSI_BASE + 0x148U)
#define DSI_VHSACCR_HSA_SHIFT		0
#define DSI_VHSACCR_HSA_MASK		0xfff

/**
 * DSI Host Video HBP Current Configuration Register
 */
#define DSI_VHBPCCR			MMIO32(DSI_BASE + 0x14CU)
#define DSI_VHBPCCR_HBP_SHIFT		0
#define DSI_VHBPCCR_HBP_MASK		0xfff

/**
 * DSI Host Video Line Current Configuration Register
 */
#define DSI_VLCCR			MMIO32(DSI_BASE + 0x150U)
#define DSI_VLCCR_HLINE_SHIFT		0
#define DSI_VLCCR_HLINE_MASK		0x7fff

/**
 * DSI Host Video VSA Current Configuration Register
 */
#define DSI_VVSACCR			MMIO32(DSI_BASE + 0x154U)
#define DSI_VVSACCR_VSA_SHIFT		0
#define DSI_VVSACCR_VSA_MASK		0x3ff

/**
 * DSI Host Video VBP Current Configuration Register
 */
#define DSI_VVBPCCR			MMIO32(DSI_BASE + 0x0158U)
#define DSI_VVBPCCR_VBP_SHIFT		0
#define DSI_VVBPCCR_VBP_MAST		0x3ff

/**
 * DSI Host Video VFP Current Configuration Register
 */
#define DSI_VVFPCCR			MMIO32(DSI_BASE + 0x15CU)
#define DSI_VVFPCCR_VFP_SHIFT		0
#define DSI_VVFPCCR_VFP_MASK		0x3ff

/**
 * DSI Host Video VA Current Configuration Register
 */
#define DSI_VVACCR			MMIO32(DSI_BASE + 0x160U)
#define DSI_VVACCR_VA_SHIFT		0
#define DSI_VVACCR_VA_MASK		0x3fff

/**
 * DSI Wrapper Configuration Register
 */
#define DSI_WCFGR			MMIO32(DSI_BASE + 0x400U)
#define DSI_WCFGR_VSPOL			(1 << 7)
#define DSI_WCFGR_AR			(1 << 6)
#define DSI_WCFGR_TEPOL			(1 << 5)
#define DSI_WCFGR_TESRC			(1 << 4)
#define DSI_WCFGR_COLMUX_SHIFT		1
#define DSI_WCFGR_COLMUX_MASK		7
#define DSI_WCFGR_DSIM			(1 << 0)

/**
 * DSI Wrapper Control Register
 */
#define DSI_WCR				MMIO32(DSI_BASE + 0x404U)
#define DSI_WCR_DSIEN			(1 << 3)
#define DSI_WCR_LTDCEN			(1 << 2)
#define DSI_WCR_SHTDN			(1 << 1)
#define DSI_WCR_COLM			(1 << 0)

/**
 * DSI Wrapper Interrupt Enable Register
 */
#define DSI_WIER			MMIO32(DSI_BASE + 0x408U)
#define DSI_WIER_RRIE			(1 << 13)
#define DSI_WIER_PLLUIE			(1 << 10)
#define DSI_WIER_PLLLIE			(1 << 9)
#define DSI_WIER_ERIE			(1 << 1)
#define DSI_WIER_TEIE			(1 << 0)

/**
 * DSI Wrapper Interrupt & Status Register
 */
#define DSI_WISR			MMIO32(DSI_BASE + 0x40CU)
/* reserved 31:14 */
#define DSI_WISR_RRIF			(1 << 13)
#define DSI_WISR_RRS			(1 << 12)
#define DSI_WISR_PLLUIF			(1 << 10)
#define DSI_WISR_PLLLIF			(1 << 9)
#define DSI_WISR_PLLLS			(1 << 8)
/* reserved 7:3 */
#define DSI_WISR_BUSY			(1 << 2)
#define DSI_WISR_ERIF			(1 << 1)
#define DSI_WISR_TEIF			(1 << 0)

/**
 * DSI Wrapper Interrupt Flag Clear Register
 */
#define DSI_WIFCR			MMIO32(DSI_BASE + 0x410U)
/* reserved 31:14 */
#define DSI_WIFCR_CRRIF			(1 << 13)
/* reserved 12:11 */
#define DSI_WIFCR_CPLLUIF		(1 << 10)
#define DSI_WIFCR_CPLLLIF		(1 << 9)
/* reserved 8:2 */
#define DSI_WIFCR_CERIF			(1 << 1)
#define DSI_WIFCR_CTEIF			(1 << 0)

/**
 * DSI Wrapper PHY Configuration Register 0
 */
#define DSI_WPCR0			MMIO32(DSI_BASE + 0x418U)
#define DSI_WPCR0_TCLKPOSTEN		(1 << 27)
#define DSI_WPCR0_TLPXCEN		(1 << 26)
#define DSI_WPCR0_THSEXITEN		(1 << 25)
#define DSI_WPCR0_TLPXDEN		(1 << 24)
#define DSI_WPCR0_THSZEROEN		(1 << 23)
#define DSI_WPCR0_THSTRAILEN		(1 << 22)
#define DSI_WPCR0_THSPREPEN		(1 << 21)
#define DSI_WPCR0_TCLKZEROEN		(1 << 20)
#define DSI_WPCR0_TCLKPREPEN		(1 << 19)
#define DSI_WPCR0_PDEN			(1 << 18)
#define DSI_WPCR0_TDDL			(1 << 16)
#define DSI_WPCR0_CDOFFDL		(1 << 14)
#define DSI_WPCR0_FTXSMDL		(1 << 13)
#define DSI_WPCR0_FTXSMCL		(1 << 12)
#define DSI_WPCR0_HSIDL1		(1 << 11)
#define DSI_WPCR0_HSIDL0		(1 << 10)
#define DSI_WPCR0_HSICL			(1 << 9)
#define DSI_WPCR0_SWDL1			(1 << 8)
#define DSI_WPCR0_SWDL0			(1 << 7)
#define DSI_WPCR0_SWCL			(1 << 6)
#define DSI_WPCR0_UIX4_SHIFT		0
#define DSI_WPCR0_UIX4_MASK		0x3f

/**
 * DSI Wrapper PHY Configration Register 1
 */
#define DSI_WPCR1			MMIO32(DSI_BASE + 0x41CU)
#define DSI_WPCR1_LPRXFT_SHIFT		25
#define DSI_WPCR1_LPRXFT_MASK		0x3
#define DSI_WPCR1_FLPRXLPM		(1 << 22)
#define DSI_WPCR1_HSTXSRCDL_SHIFT	18
#define DSI_WPCR1_HSTXSRCDL_MASK	0x3
#define DSI_WPCR1_HSTXSRCCL_SHIFT	16
#define DSI_WPCR1_HSTXSRCCL_MASK	0x3
#define DSI_WPCR1_SDDC			(1 << 12)
#define DSI_WPCR1_LPSRCDL_SHIFT		8
#define DSI_WPCR1_LPSRCDL_MASK		0x3
#define DSI_WPCR1_HSTXDDL_SHIFT		2
#define DSI_WPCR1_HSTXDDL_MASK		0x3
#define DSI_WPCR1_HSTXDCL_SHIFT		0
#define DSI_WPCR1_HSTXDCL_MASK		0x3

/**
 * DSI Wrapper PHY Configuration Register 2
 */
#define DSI_WPCR2			MMIO32(DSI_BASE + 0x420U)
#define DSI_WPCR2_THSTRAIL_SHIFT	24
#define DSI_WPCR2_THSTRAIL_MASK		0xff
#define DSI_WPCR2_THSPREP_SHIFT		16
#define DSI_WPCR2_THSPREP_MASK		0xff
#define DSI_WPCR2_TCLKZERO_SHIFT	8
#define DSI_WPCR2_TCLKZERO_MASK		0xff
#define DSI_WPCR2_TCLKPREP_SHIFT	0
#define DSI_WPCR2_TCLKPREP_MASK		0xff

/**
 * DSI Wrapper PHY Configuration Register 3
 */
#define DSI_WPCR3			MMIO32(DSI_BASE + 0x424U)
#define DSI_WPCR3_TLPXC_SHIFT		24
#define DSI_WPCR3_TLPXC_MASK		0xff
#define DSI_WPCR3_THSEXIT_SHIFT		16
#define DSI_WPCR3_THSEXIT_MASK		0xff
#define DSI_WPCR3_TLPXD_SHIFT		8
#define DSI_WPCR3_TLPXD_MASK		0xff
#define DSI_WPCR3_THSZERO_SHIFT		0
#define DSI_WPCR3_THSZERO_MASK		0xff

/**
 * DSI Wrapper PHY Configuration Register 4
 */
#define DSI_WPCR4			MMIO32(DSI_BASE + 0x428U)
#define DSI_WPCR4_TCLKPOST_SHIFT	0
#define DSI_WPCR4_TCLKPOST_MASK		0xff

/**
 * DSI Wrapper Regulator and PLL Control Register
 */
#define DSI_WRPCR			MMIO32(DSI_BASE + 0x430U)
#define DSI_WRPCR_REGEN			(1 << 24)
#define DSI_WRPCR_ODF_SHIFT		16
#define DSI_WRPCR_ODF_MASK		0x3
#define DSI_WRPCR_ODF_DIV_1		0
#define DSI_WRPCR_ODF_DIV_2		1
#define DSI_WRPCR_ODF_DIV_4		2
#define DSI_WRPCR_ODF_DIV_8		3
#define DSI_WRPCR_IDF_SHIFT		11
#define DSI_WRPCR_IDF_MASK		0xf
#define DSI_WRPCR_IDF_DIV_1		1
#define DSI_WRPCR_IDF_DIV_2		2
#define DSI_WRPCR_IDF_DIV_3		3
#define DSI_WRPCR_IDF_DIV_4		4
#define DSI_WRPCR_IDF_DIV_5		5
#define DSI_WRPCR_IDF_DIV_6		6
#define DSI_WRPCR_IDF_DIV_7		7
/* valid NDIV values 10 - 125 all other reserved */
#define DSI_WRPCR_NDIV_SHIFT		2
#define DSI_WRPCR_NDIV_MASK		0x7f
#define DSI_WRPCR_PLLEN			(1 << 0)

/** @cond */
#endif
/** @endcond */
/**@}*/
