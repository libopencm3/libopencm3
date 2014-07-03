/** @defgroup ccm_defines CCM Defines
 *
 * @brief <b>Defined Constants and Types for the VF6xx Common Clock Module</b>
 *
 * @ingroup VF6xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Stefan Agner <stefan@agner.ch>
 *
 * @date 30 June 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#ifndef LIBOPENCM3_CCM_H
#define LIBOPENCM3_CCM_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/vf6xx/memorymap.h>

/* --- CCM registers ------------------------------------------------------- */

#define CCM_CCR				MMIO32(CCM_BASE + 0x00)
#define CCM_CSR				MMIO32(CCM_BASE + 0x04)
#define CCM_CCSR			MMIO32(CCM_BASE + 0x08)
#define CCM_CACRR			MMIO32(CCM_BASE + 0x0C)
#define CCM_CSCMR1			MMIO32(CCM_BASE + 0x10)
#define CCM_CSCDR1			MMIO32(CCM_BASE + 0x14)
#define CCM_CSCDR2			MMIO32(CCM_BASE + 0x18)
#define CCM_CSCDR3			MMIO32(CCM_BASE + 0x1C)
#define CCM_CSCMR2			MMIO32(CCM_BASE + 0x20)

#define CCM_CTOR			MMIO32(CCM_BASE + 0x28)
#define CCM_CLPCR			MMIO32(CCM_BASE + 0x2C)
#define CCM_CISR			MMIO32(CCM_BASE + 0x30)
#define CCM_CIMR			MMIO32(CCM_BASE + 0x34)
#define CCM_CCOSR			MMIO32(CCM_BASE + 0x38)
#define CCM_CGPR			MMIO32(CCM_BASE + 0x3C)
#define CCM_CCGR(offset)		MMIO32(CCM_BASE + 0x40 + offset)
#define CCM_CMEOR(ovrr)			MMIO32(CCM_BASE + 0x70 + (4 * ovrr))
#define CCM_CPPDSR			MMIO32(CCM_BASE + 0x88)

#define CCM_CCOWR			MMIO32(CCM_BASE + 0x8C)
#define CCM_CCPGR(pcgr)			MMIO32(CCM_BASE + 0x90 + (4 * pcgr))

/* --- CCM values -....----------------------------------------------------- */

/* CCR: CCM Control Register */
#define CCM_CCR_FIRC_EN				(1 << 16)
#define CCM_CCR_FXOSC_EN			(1 << 12)
#define CCM_CCR_OSCNT_MASK			0xff

/* CSR: CCM Status Register */
#define CCM_CSR_FXOSC_RDY			(1 << 5)

/* CCSR: CCM Clock Switcher Register */
#define CCM_CCSR_PLL3_PFDN4_EN			(1 << 31)
#define CCM_CCSR_PLL3_PFDN3_EN			(1 << 30)
#define CCM_CCSR_PLL3_PFDN2_EN			(1 << 29)
#define CCM_CCSR_PLL3_PFDN1_EN			(1 << 28)

#define CCM_CCSR_DAP_EN				(1 << 24)

/* PLL1/PLL2 PFD SEL definition */
#define CCM_CCSR_PLL2_PFD_CLK_SEL_SHIFT		19
#define CCM_CCSR_PLL2_PFD_CLK_SEL_MASK		(0x7 << 19)
#define CCM_CCSR_PLL1_PFD_CLK_SEL_SHIFT		16
#define CCM_CCSR_PLL1_PFD_CLK_SEL_MASK		(0x7 << 16)

#define CCM_CCSR_PLL_PFD_CLK_SEL_MAIN		0x0
#define CCM_CCSR_PLL_PFD_CLK_SEL_PFD1		0x1
#define CCM_CCSR_PLL_PFD_CLK_SEL_PFD2		0x2
#define CCM_CCSR_PLL_PFD_CLK_SEL_PFD3		0x3
#define CCM_CCSR_PLL_PFD_CLK_SEL_PFD4		0x4

#define CCM_CCSR_PLL2_PFDN4_EN			(1 << 15)
#define CCM_CCSR_PLL2_PFDN3_EN			(1 << 14)
#define CCM_CCSR_PLL2_PFDN2_EN			(1 << 13)
#define CCM_CCSR_PLL2_PFDN1_EN			(1 << 12)

#define CCM_CCSR_PLL1_PFDN4_EN			(1 << 11)
#define CCM_CCSR_PLL1_PFDN3_EN			(1 << 10)
#define CCM_CCSR_PLL1_PFDN2_EN			(1 << 9)
#define CCM_CCSR_PLL1_PFDN1_EN			(1 << 8)

#define CCM_CCSR_DDRC_CLK_SEL			(1 << 7)
#define CCM_CCSR_FAST_CLK_SEL			(1 << 6)
#define CCM_CCSR_SLOW_CLK_SEL			(1 << 5)

#define CCM_CCSR_SYS_CLK_SEL_SHIFT		0
#define CCM_CCSR_SYS_CLK_SEL_MASK		0x7
#define CCM_CCSR_SYS_CLK_SEL_FAST		0x0
#define CCM_CCSR_SYS_CLK_SEL_SLOW		0x1
#define CCM_CCSR_SYS_CLK_SEL_PLL2_PFD		0x2
#define CCM_CCSR_SYS_CLK_SEL_PLL2		0x3
#define CCM_CCSR_SYS_CLK_SEL_PLL1_PFD		0x4
#define CCM_CCSR_SYS_CLK_SEL_PLL3		0x5

/* CACRR: ARM Clock Root Register */
#define CCM_CACRR_FLEX_CLK_DIV_SHIFT		22
#define CCM_CACRR_FLEX_CLK_DIV_MASK		(0x7 << 22)
#define CCM_CACRR_PLL6_CLK_DIV			(1 << 21)
#define CCM_CACRR_PLL3_CLK_DIV			(1 << 20)
#define CCM_CACRR_PLL1_PFD_CLK_DIV_SHIFT	16
#define CCM_CACRR_PLL1_PFD_CLK_DIV_MASK		(0x3 << 16)
#define CCM_CACRR_IPG_CLK_DIV_SHIFT		11
#define CCM_CACRR_IPG_CLK_DIV_MASK		(0x3 << 11)
#define CCM_CACRR_PLL4_CLK_DIV_SHIFT		6
#define CCM_CACRR_PLL4_CLK_DIV_MASK		(0x7 << 6)
#define CCM_CACRR_BUS_CLK_DIV_SHIFT		3
#define CCM_CACRR_BUS_CLK_DIV_MASK		(0x7 << 3)
#define CCM_CACRR_ARM_CLK_DIV_SHIFT		0
#define CCM_CACRR_ARM_CLK_DIV_MASK		(0x7 << 0)

/* --- Variable definitions ------------------------------------------------ */

extern uint32_t ccm_core_clk;
extern uint32_t ccm_platform_bus_clk;
extern uint32_t ccm_ipg_bus_clk;

enum ccm_clock_gate {
	/* AIPS0 */
	CG0_FLEXCAN0 = 0,
	CG1_RESERVED,
	CG2_RESERVED,
	CG3_RESERVED,
	CG4_DMA_MUX0,
	CG5_DMA_MUX1,
	CG6_RESERVED,
	CG7_UART0,
	CG8_UART1,
	CG9_UART2,
	CG10_UART3,
	CG11_RESERVED,
	CG12_SPI0,
	CG13_SPI1,
	CG14_RESERVED,
	CG15_SAI0,
	CG16_SAI1,
	CG17_SAI2,
	CG18_SAI3,
	CG19_CRC,
	CG20_USBC0,
	CG21_RESERVED,
	CG22_PDB,
	CG23_PIT,
	CG24_FTM0,
	CG25_FTM1,
	CG26_RESERVED,
	CG27_ADC0,
	CG28_RESERVED,
	CG29_TCON0,
	CG30_WDOG_A5,
	CG31_WDOG_M4,
	CG32_LPTMR,
	CG33_RESERVED,
	CG34_RLE,
	CG35_RESERVED,
	CG36_QSPI0,
	CG37_RESERVED,
	CG38_RESERVED,
	CG39_RESERVED,
	CG40_IOMUX,
	CG41_PORTA,
	CG42_PORTB,
	CG43_PORTC,
	CG44_PORTD,
	CG45_PORTE,
	CG46_RESERVED,
	CG47_RESERVED,
	CG48_ANADIG,
	CG49_RESERVED,
	CG50_SCSCM,
	CG51_RESERVED,
	CG52_RESERVED,
	CG53_RESERVED,
	CG54_RESERVED,
	CG55_RESERVED,
	CG56_DCU0,
	CG57_RESERVED,
	CG58_RESERVED,
	CG59_RESERVED,
	CG60_RESERVED,
	CG61_RESERVED,
	CG62_RESERVED,
	CG63_RESERVED,
	CG64_ASRC,
	CG65_SPDIF,
	CG66_ESAI,
	CG67_RESERVED,
	CG68_RESERVED,
	CG69_EWM,
	CG70_I2C0,
	CG71_I2C1,
	CG72_RESERVED,
	CG73_RESERVED,
	CG74_WKUP,
	CG75_CCM,
	CG76_GPC,
	CG77_VREG_DIG,
	CG78_RESERVED,
	CG79_CMU,
	CG80_NOTUSED,
	CG81_NOTUSED,
	CG82_NOTUSED,
	CG83_NOTUSED,
	CG84_NOTUSED,
	CG85_NOTUSED,
	CG86_NOTUSED,
	CG87_NOTUSED,
	CG88_NOTUSED,
	CG89_NOTUSED,
	CG90_NOTUSED,
	CG91_NOTUSED,
	CG92_NOTUSED,
	CG93_NOTUSED,
	CG94_NOTUSED,
	CG95_NOTUSED,

	/* AIPS1 */
	CG96_RESERVED,
	CG97_DMA_MUX2,
	CG98_DMA_MUX3,
	CG99_RESERVED,
	CG100_RESERVED,
	CG101_OTP_CTRL,
	CG102_RESERVED,
	CG103_RESERVED,
	CG104_RESERVED,
	CG105_UART4,
	CG106_UART5,
	CG107_RESERVED,
	CG108_SPI2,
	CG109_SPI3,
	CG110_DDRMC,
	CG111_RESERVED,
	CG112_RESERVED,
	CG113_SDHC0,
	CG114_SDHC1,
	CG115_RESERVED,
	CG116_USBC1,
	CG117_RESERVED,
	CG118_RESERVED,
	CG119_RESERVED,
	CG120_FTM2,
	CG121_FTM3,
	CG122_RESERVED,
	CG123_ADC1,
	CG124_RESERVED,
	CG125_TCON1,
	CG126_SEG_LCD,
	CG127_RESERVED,
	CG128_RESERVED,
	CG129_RESERVED,
	CG130_RESERVED,
	CG131_RESERVED,
	CG132_QSPI1,
	CG133_RESERVED,
	CG134_RESERVED,
	CG135_VADC,
	CG136_VDEC,
	CG137_VIU3,
	CG138_RESERVED,
	CG139_RESERVED,
	CG140_DAC0,
	CG141_DAC1,
	CG142_RESERVED,
	CG143_NOTUSED,
	CG144_ETH0_1588,
	CG145_ETH1_1588,
	CG146_RESERVED,
	CG147_RESERVED,
	CG148_FLEXCAN1,
	CG149_RESERVED,
	CG150_RESERVED,
	CG151_RESERVED,
	CG152_DCU1,
	CG153_RESERVED,
	CG154_RESERVED,
	CG155_RESERVED,
	CG156_RESERVED,
	CG157_RESERVED,
	CG158_RESERVED,
	CG159_RESERVED,
	CG160_NFC,
	CG161_RESERVED,
	CG162_RESERVED,
	CG163_RESERVED,
	CG164_RESERVED,
	CG165_RESERVED,
	CG166_I2C2,
	CG167_I2C3,
	CG168_ETH_L2,
	CG169_RESERVED,
	CG170_RESERVED,
	CG171_RESERVED,
	CG172_RESERVED,
	CG173_RESERVED,
	CG174_RESERVED,
	CG175_RESERVED,
	CG176_RESERVED,
	CG177_RESERVED,
	CG178_RESERVED,
	CG179_RESERVED,
	CG180_RESERVED,
	CG181_RESERVED,
	CG182_RESERVED,
	CG183_RESERVED,
	CG184_RESERVED,
	CG185_RESERVED,
	CG186_RESERVED,
	CG187_RESERVED,
	CG188_RESERVED,
	CG189_RESERVED,
	CG190_RESERVED,
	CG191_RESERVED
};

/* --- Function prototypes ------------------------------------------------- */

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

void ccm_clock_gate_enable(enum ccm_clock_gate gr);
void ccm_clock_gate_disable(enum ccm_clock_gate gr);
void ccm_calculate_clocks(void);

END_DECLS

#endif
