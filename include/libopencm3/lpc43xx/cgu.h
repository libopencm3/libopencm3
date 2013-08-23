/** @defgroup cgu_defines Clock Generation Unit Defines
 *
 * @brief <b>Defined Constants and Types for the LPC43xx Clock Generation
 * Unit</b>
 *
 * @ingroup LPC43xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann
 * <mike@ossmann.com>
 *
 * @date 10 March 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_CGU_H
#define CGU_LPC43XX_CGU_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- CGU registers ------------------------------------------------------- */

/* Frequency monitor register */
#define CGU_FREQ_MON                    MMIO32(CGU_BASE + 0x014)

/* Crystal oscillator control register */
#define CGU_XTAL_OSC_CTRL               MMIO32(CGU_BASE + 0x018)

/* PLL0USB status register */
#define CGU_PLL0USB_STAT                MMIO32(CGU_BASE + 0x01C)

/* PLL0USB control register */
#define CGU_PLL0USB_CTRL                MMIO32(CGU_BASE + 0x020)

/* PLL0USB M-divider register */
#define CGU_PLL0USB_MDIV                MMIO32(CGU_BASE + 0x024)

/* PLL0USB N/P-divider register */
#define CGU_PLL0USB_NP_DIV              MMIO32(CGU_BASE + 0x028)

/* PLL0AUDIO status register */
#define CGU_PLL0AUDIO_STAT              MMIO32(CGU_BASE + 0x02C)

/* PLL0AUDIO control register */
#define CGU_PLL0AUDIO_CTRL              MMIO32(CGU_BASE + 0x030)

/* PLL0AUDIO M-divider register */
#define CGU_PLL0AUDIO_MDIV              MMIO32(CGU_BASE + 0x034)

/* PLL0AUDIO N/P-divider register */
#define CGU_PLL0AUDIO_NP_DIV            MMIO32(CGU_BASE + 0x038)

/* PLL0AUDIO fractional divider register */
#define CGU_PLLAUDIO_FRAC               MMIO32(CGU_BASE + 0x03C)

/* PLL1 status register */
#define CGU_PLL1_STAT                   MMIO32(CGU_BASE + 0x040)

/* PLL1 control register */
#define CGU_PLL1_CTRL                   MMIO32(CGU_BASE + 0x044)

/* Integer divider A control register */
#define CGU_IDIVA_CTRL                  MMIO32(CGU_BASE + 0x048)

/* Integer divider B control register */
#define CGU_IDIVB_CTRL                  MMIO32(CGU_BASE + 0x04C)

/* Integer divider C control register */
#define CGU_IDIVC_CTRL                  MMIO32(CGU_BASE + 0x050)

/* Integer divider D control register */
#define CGU_IDIVD_CTRL                  MMIO32(CGU_BASE + 0x054)

/* Integer divider E control register */
#define CGU_IDIVE_CTRL                  MMIO32(CGU_BASE + 0x058)

/* Output stage 0 control register */
#define CGU_BASE_SAFE_CLK               MMIO32(CGU_BASE + 0x05C)

/* Output stage 1 control register for base clock */
#define CGU_BASE_USB0_CLK               MMIO32(CGU_BASE + 0x060)

/* Output stage 2 control register for base clock */
#define CGU_BASE_PERIPH_CLK             MMIO32(CGU_BASE + 0x064)

/* Output stage 3 control register for base clock */
#define CGU_BASE_USB1_CLK               MMIO32(CGU_BASE + 0x068)

/* Output stage 4 control register for base clock */
#define CGU_BASE_M4_CLK                 MMIO32(CGU_BASE + 0x06C)

/* Output stage 5 control register for base clock */
#define CGU_BASE_SPIFI_CLK              MMIO32(CGU_BASE + 0x070)

/* Output stage 6 control register for base clock */
#define CGU_BASE_SPI_CLK                MMIO32(CGU_BASE + 0x074)

/* Output stage 7 control register for base clock */
#define CGU_BASE_PHY_RX_CLK             MMIO32(CGU_BASE + 0x078)

/* Output stage 8 control register for base clock */
#define CGU_BASE_PHY_TX_CLK             MMIO32(CGU_BASE + 0x07C)

/* Output stage 9 control register for base clock */
#define CGU_BASE_APB1_CLK               MMIO32(CGU_BASE + 0x080)

/* Output stage 10 control register for base clock */
#define CGU_BASE_APB3_CLK               MMIO32(CGU_BASE + 0x084)

/* Output stage 11 control register for base clock */
#define CGU_BASE_LCD_CLK                MMIO32(CGU_BASE + 0x088)

/* Output stage 12 control register for base clock */
#define CGU_BASE_VADC_CLK               MMIO32(CGU_BASE + 0x08C)

/* Output stage 13 control register for base clock */
#define CGU_BASE_SDIO_CLK               MMIO32(CGU_BASE + 0x090)

/* Output stage 14 control register for base clock */
#define CGU_BASE_SSP0_CLK               MMIO32(CGU_BASE + 0x094)

/* Output stage 15 control register for base clock */
#define CGU_BASE_SSP1_CLK               MMIO32(CGU_BASE + 0x098)

/* Output stage 16 control register for base clock */
#define CGU_BASE_UART0_CLK              MMIO32(CGU_BASE + 0x09C)

/* Output stage 17 control register for base clock */
#define CGU_BASE_UART1_CLK              MMIO32(CGU_BASE + 0x0A0)

/* Output stage 18 control register for base clock */
#define CGU_BASE_UART2_CLK              MMIO32(CGU_BASE + 0x0A4)

/* Output stage 19 control register for base clock */
#define CGU_BASE_UART3_CLK              MMIO32(CGU_BASE + 0x0A8)

/* Output stage 20 control register for base clock */
#define CGU_BASE_OUT_CLK                MMIO32(CGU_BASE + 0x0AC)

/* Reserved output stage */
#define CGU_OUTCLK_21_CTRL              MMIO32(CGU_BASE + 0x0B0)

/* Reserved output stage */
#define CGU_OUTCLK_22_CTRL              MMIO32(CGU_BASE + 0x0B4)

/* Reserved output stage */
#define CGU_OUTCLK_23_CTRL              MMIO32(CGU_BASE + 0x0B8)

/* Reserved output stage */
#define CGU_OUTCLK_24_CTRL              MMIO32(CGU_BASE + 0x0BC)

/* Output stage 25 control register for base clock */
#define CGU_BASE_APLL_CLK               MMIO32(CGU_BASE + 0x0C0)

/* Output stage 26 control CLK register for base clock */
#define CGU_BASE_CGU_OUT0_CLK           MMIO32(CGU_BASE + 0x0C4)

/* Output stage 27 control CLK register for base clock */
#define CGU_BASE_CGU_OUT1_CLK           MMIO32(CGU_BASE + 0x0C8)

/* --- CGU_FREQ_MON values -------------------------------------- */

/* RCNT: 9-bit reference clock-counter value */
#define CGU_FREQ_MON_RCNT_SHIFT		(0)
#define CGU_FREQ_MON_RCNT_MASK		(0x1ff << CGU_FREQ_MON_RCNT_SHIFT)
#define CGU_FREQ_MON_RCNT(x)		((x) << CGU_FREQ_MON_RCNT_SHIFT)

/* FCNT: 14-bit selected clock-counter value */
#define CGU_FREQ_MON_FCNT_SHIFT		(9)
#define CGU_FREQ_MON_FCNT_MASK		(0x3fff << CGU_FREQ_MON_FCNT_SHIFT)
#define CGU_FREQ_MON_FCNT(x)		((x) << CGU_FREQ_MON_FCNT_SHIFT)

/* MEAS: Measure frequency */
#define CGU_FREQ_MON_MEAS_SHIFT		(23)
#define CGU_FREQ_MON_MEAS		(1 << CGU_FREQ_MON_MEAS_SHIFT)

/* CLK_SEL: Clock-source selection for the clock to be measured */
#define CGU_FREQ_MON_CLK_SEL_SHIFT	(24)
#define CGU_FREQ_MON_CLK_SEL_MASK	(0x1f << CGU_FREQ_MON_CLK_SEL_SHIFT)
#define CGU_FREQ_MON_CLK_SEL(x)		((x) << CGU_FREQ_MON_CLK_SEL_SHIFT)

/* --- CGU_XTAL_OSC_CTRL values --------------------------------- */

/* ENABLE: Oscillator-pad enable */
#define CGU_XTAL_OSC_CTRL_ENABLE_SHIFT	(0)
#define CGU_XTAL_OSC_CTRL_ENABLE	(1 << CGU_XTAL_OSC_CTRL_ENABLE_SHIFT)

/* BYPASS: Configure crystal operation or external-clock input pin XTAL1 */
#define CGU_XTAL_OSC_CTRL_BYPASS_SHIFT	(1)
#define CGU_XTAL_OSC_CTRL_BYPASS	(1 << CGU_XTAL_OSC_CTRL_BYPASS_SHIFT)

/* HF: Select frequency range */
#define CGU_XTAL_OSC_CTRL_HF_SHIFT	(2)
#define CGU_XTAL_OSC_CTRL_HF		(1 << CGU_XTAL_OSC_CTRL_HF_SHIFT)

/* --- CGU_PLL0USB_STAT values ---------------------------------- */

/* LOCK: PLL0 lock indicator */
#define CGU_PLL0USB_STAT_LOCK_SHIFT	(0)
#define CGU_PLL0USB_STAT_LOCK		(1 << CGU_PLL0USB_STAT_LOCK_SHIFT)

/* FR: PLL0 free running indicator */
#define CGU_PLL0USB_STAT_FR_SHIFT	(1)
#define CGU_PLL0USB_STAT_FR		(1 << CGU_PLL0USB_STAT_FR_SHIFT)

/* --- CGU_PLL0USB_CTRL values ---------------------------------- */

/* PD: PLL0 power down */
#define CGU_PLL0USB_CTRL_PD_SHIFT	(0)
#define CGU_PLL0USB_CTRL_PD		(1 << CGU_PLL0USB_CTRL_PD_SHIFT)

/* BYPASS: Input clock bypass control */
#define CGU_PLL0USB_CTRL_BYPASS_SHIFT	(1)
#define CGU_PLL0USB_CTRL_BYPASS		(1 << CGU_PLL0USB_CTRL_BYPASS_SHIFT)

/* DIRECTI: PLL0 direct input */
#define CGU_PLL0USB_CTRL_DIRECTI_SHIFT	(2)
#define CGU_PLL0USB_CTRL_DIRECTI	(1 << CGU_PLL0USB_CTRL_DIRECTI_SHIFT)

/* DIRECTO: PLL0 direct output */
#define CGU_PLL0USB_CTRL_DIRECTO_SHIFT	(3)
#define CGU_PLL0USB_CTRL_DIRECTO	(1 << CGU_PLL0USB_CTRL_DIRECTO_SHIFT)

/* CLKEN: PLL0 clock enable */
#define CGU_PLL0USB_CTRL_CLKEN_SHIFT	(4)
#define CGU_PLL0USB_CTRL_CLKEN		(1 << CGU_PLL0USB_CTRL_CLKEN_SHIFT)

/* FRM: Free running mode */
#define CGU_PLL0USB_CTRL_FRM_SHIFT	(6)
#define CGU_PLL0USB_CTRL_FRM		(1 << CGU_PLL0USB_CTRL_FRM_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_PLL0USB_CTRL_AUTOBLOCK_SHIFT (11)
#define CGU_PLL0USB_CTRL_AUTOBLOCK	(1 << CGU_PLL0USB_CTRL_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_PLL0USB_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_PLL0USB_CTRL_CLK_SEL_MASK	(0x1f << CGU_PLL0USB_CTRL_CLK_SEL_SHIFT)
#define CGU_PLL0USB_CTRL_CLK_SEL(x)	((x) << CGU_PLL0USB_CTRL_CLK_SEL_SHIFT)

/* --- CGU_PLL0USB_MDIV values ---------------------------------- */

/* MDEC: Decoded M-divider coefficient value */
#define CGU_PLL0USB_MDIV_MDEC_SHIFT	(0)
#define CGU_PLL0USB_MDIV_MDEC_MASK	(0x1ffff << CGU_PLL0USB_MDIV_MDEC_SHIFT)
#define CGU_PLL0USB_MDIV_MDEC(x)	((x) << CGU_PLL0USB_MDIV_MDEC_SHIFT)

/* SELP: Bandwidth select P value */
#define CGU_PLL0USB_MDIV_SELP_SHIFT	(17)
#define CGU_PLL0USB_MDIV_SELP_MASK	(0x1f << CGU_PLL0USB_MDIV_SELP_SHIFT)
#define CGU_PLL0USB_MDIV_SELP(x)	((x) << CGU_PLL0USB_MDIV_SELP_SHIFT)

/* SELI: Bandwidth select I value */
#define CGU_PLL0USB_MDIV_SELI_SHIFT	(22)
#define CGU_PLL0USB_MDIV_SELI_MASK	(0x3f << CGU_PLL0USB_MDIV_SELI_SHIFT)
#define CGU_PLL0USB_MDIV_SELI(x)	((x) << CGU_PLL0USB_MDIV_SELI_SHIFT)

/* SELR: Bandwidth select R value */
#define CGU_PLL0USB_MDIV_SELR_SHIFT	(28)
#define CGU_PLL0USB_MDIV_SELR_MASK	(0xf << CGU_PLL0USB_MDIV_SELR_SHIFT)
#define CGU_PLL0USB_MDIV_SELR(x)	((x) << CGU_PLL0USB_MDIV_SELR_SHIFT)

/* --- CGU_PLL0USB_NP_DIV values -------------------------------- */

/* PDEC: Decoded P-divider coefficient value */
#define CGU_PLL0USB_NP_DIV_PDEC_SHIFT	(0)
#define CGU_PLL0USB_NP_DIV_PDEC_MASK	(0x7f << CGU_PLL0USB_NP_DIV_PDEC_SHIFT)
#define CGU_PLL0USB_NP_DIV_PDEC(x)	((x) << CGU_PLL0USB_NP_DIV_PDEC_SHIFT)

/* NDEC: Decoded N-divider coefficient value */
#define CGU_PLL0USB_NP_DIV_NDEC_SHIFT	(12)
#define CGU_PLL0USB_NP_DIV_NDEC_MASK	(0x3ff << CGU_PLL0USB_NP_DIV_NDEC_SHIFT)
#define CGU_PLL0USB_NP_DIV_NDEC(x)	((x) << CGU_PLL0USB_NP_DIV_NDEC_SHIFT)

/* --- CGU_PLL0AUDIO_STAT values -------------------------------- */

/* LOCK: PLL0 lock indicator */
#define CGU_PLL0AUDIO_STAT_LOCK_SHIFT	(0)
#define CGU_PLL0AUDIO_STAT_LOCK		(1 << CGU_PLL0AUDIO_STAT_LOCK_SHIFT)

/* FR: PLL0 free running indicator */
#define CGU_PLL0AUDIO_STAT_FR_SHIFT	(1)
#define CGU_PLL0AUDIO_STAT_FR		(1 << CGU_PLL0AUDIO_STAT_FR_SHIFT)

/* --- CGU_PLL0AUDIO_CTRL values -------------------------------- */

/* PD: PLL0 power down */
#define CGU_PLL0AUDIO_CTRL_PD_SHIFT	(0)
#define CGU_PLL0AUDIO_CTRL_PD		(1 << CGU_PLL0AUDIO_CTRL_PD_SHIFT)

/* BYPASS: Input clock bypass control */
#define CGU_PLL0AUDIO_CTRL_BYPASS_SHIFT	(1)
#define CGU_PLL0AUDIO_CTRL_BYPASS	(1 << CGU_PLL0AUDIO_CTRL_BYPASS_SHIFT)

/* DIRECTI: PLL0 direct input */
#define CGU_PLL0AUDIO_CTRL_DIRECTI_SHIFT (2)
#define CGU_PLL0AUDIO_CTRL_DIRECTI	(1 << CGU_PLL0AUDIO_CTRL_DIRECTI_SHIFT)

/* DIRECTO: PLL0 direct output */
#define CGU_PLL0AUDIO_CTRL_DIRECTO_SHIFT (3)
#define CGU_PLL0AUDIO_CTRL_DIRECTO	(1 << CGU_PLL0AUDIO_CTRL_DIRECTO_SHIFT)

/* CLKEN: PLL0 clock enable */
#define CGU_PLL0AUDIO_CTRL_CLKEN_SHIFT	(4)
#define CGU_PLL0AUDIO_CTRL_CLKEN	(1 << CGU_PLL0AUDIO_CTRL_CLKEN_SHIFT)

/* FRM: Free running mode */
#define CGU_PLL0AUDIO_CTRL_FRM_SHIFT	(6)
#define CGU_PLL0AUDIO_CTRL_FRM		(1 << CGU_PLL0AUDIO_CTRL_FRM_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_PLL0AUDIO_CTRL_AUTOBLOCK_SHIFT (11)
#define CGU_PLL0AUDIO_CTRL_AUTOBLOCK	\
				(1 << CGU_PLL0AUDIO_CTRL_AUTOBLOCK_SHIFT)

/* PLLFRACT_REQ: Fractional PLL word write request */
#define CGU_PLL0AUDIO_CTRL_PLLFRACT_REQ_SHIFT (12)
#define CGU_PLL0AUDIO_CTRL_PLLFRACT_REQ \
				(1 << CGU_PLL0AUDIO_CTRL_PLLFRACT_REQ_SHIFT)

/* SEL_EXT: Select fractional divider */
#define CGU_PLL0AUDIO_CTRL_SEL_EXT_SHIFT (13)
#define CGU_PLL0AUDIO_CTRL_SEL_EXT	(1 << CGU_PLL0AUDIO_CTRL_SEL_EXT_SHIFT)

/* MOD_PD: Sigma-Delta modulator power-down */
#define CGU_PLL0AUDIO_CTRL_MOD_PD_SHIFT (14)
#define CGU_PLL0AUDIO_CTRL_MOD_PD	(1 << CGU_PLL0AUDIO_CTRL_MOD_PD_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_PLL0AUDIO_CTRL_CLK_SEL_SHIFT (24)
#define CGU_PLL0AUDIO_CTRL_CLK_SEL_MASK \
			(0x1f << CGU_PLL0AUDIO_CTRL_CLK_SEL_SHIFT)
#define CGU_PLL0AUDIO_CTRL_CLK_SEL(x) \
			((x) << CGU_PLL0AUDIO_CTRL_CLK_SEL_SHIFT)

/* --- CGU_PLL0AUDIO_MDIV values -------------------------------- */

/* MDEC: Decoded M-divider coefficient value */
#define CGU_PLL0AUDIO_MDIV_MDEC_SHIFT		(0)
#define CGU_PLL0AUDIO_MDIV_MDEC_MASK	\
			(0x1ffff << CGU_PLL0AUDIO_MDIV_MDEC_SHIFT)
#define CGU_PLL0AUDIO_MDIV_MDEC(x) \
			((x) << CGU_PLL0AUDIO_MDIV_MDEC_SHIFT)

/* --- CGU_PLL0AUDIO_NP_DIV values ------------------------------ */

/* PDEC: Decoded P-divider coefficient value */
#define CGU_PLL0AUDIO_NP_DIV_PDEC_SHIFT		(0)
#define CGU_PLL0AUDIO_NP_DIV_PDEC_MASK \
			(0x7f << CGU_PLL0AUDIO_NP_DIV_PDEC_SHIFT)
#define CGU_PLL0AUDIO_NP_DIV_PDEC(x) \
			((x) << CGU_PLL0AUDIO_NP_DIV_PDEC_SHIFT)

/* NDEC: Decoded N-divider coefficient value */
#define CGU_PLL0AUDIO_NP_DIV_NDEC_SHIFT		(12)
#define CGU_PLL0AUDIO_NP_DIV_NDEC_MASK \
			(0x3ff << CGU_PLL0AUDIO_NP_DIV_NDEC_SHIFT)
#define CGU_PLL0AUDIO_NP_DIV_NDEC(x) \
			((x) << CGU_PLL0AUDIO_NP_DIV_NDEC_SHIFT)

/* --- CGU_PLLAUDIO_FRAC values --------------------------------- */

/* PLLFRACT_CTRL: PLL fractional divider control word */
#define CGU_PLLAUDIO_FRAC_PLLFRACT_CTRL_SHIFT	(0)
#define CGU_PLLAUDIO_FRAC_PLLFRACT_CTRL_MASK \
			(0x3fffff << CGU_PLLAUDIO_FRAC_PLLFRACT_CTRL_SHIFT)
#define CGU_PLLAUDIO_FRAC_PLLFRACT_CTRL(x) \
			((x) << CGU_PLLAUDIO_FRAC_PLLFRACT_CTRL_SHIFT)

/* --- CGU_PLL1_STAT values ------------------------------------- */

/* LOCK: PLL1 lock indicator */
#define CGU_PLL1_STAT_LOCK_SHIFT	(0)
#define CGU_PLL1_STAT_LOCK		(1 << CGU_PLL1_STAT_LOCK_SHIFT)

/* --- CGU_PLL1_CTRL values ------------------------------------- */

/* PD: PLL1 power down */
#define CGU_PLL1_CTRL_PD_SHIFT		(0)
#define CGU_PLL1_CTRL_PD		(1 << CGU_PLL1_CTRL_PD_SHIFT)

/* BYPASS: Input clock bypass control */
#define CGU_PLL1_CTRL_BYPASS_SHIFT	(1)
#define CGU_PLL1_CTRL_BYPASS		(1 << CGU_PLL1_CTRL_BYPASS_SHIFT)

/* FBSEL: PLL feedback select */
#define CGU_PLL1_CTRL_FBSEL_SHIFT	(6)
#define CGU_PLL1_CTRL_FBSEL		(1 << CGU_PLL1_CTRL_FBSEL_SHIFT)

/* DIRECT: PLL direct CCO output */
#define CGU_PLL1_CTRL_DIRECT_SHIFT	(7)
#define CGU_PLL1_CTRL_DIRECT		(1 << CGU_PLL1_CTRL_DIRECT_SHIFT)

/* PSEL: Post-divider division ratio P */
#define CGU_PLL1_CTRL_PSEL_SHIFT	(8)
#define CGU_PLL1_CTRL_PSEL_MASK		(0x3 << CGU_PLL1_CTRL_PSEL_SHIFT)
#define CGU_PLL1_CTRL_PSEL(x)		((x) << CGU_PLL1_CTRL_PSEL_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_PLL1_CTRL_AUTOBLOCK_SHIFT	(11)
#define CGU_PLL1_CTRL_AUTOBLOCK		(1 << CGU_PLL1_CTRL_AUTOBLOCK_SHIFT)

/* NSEL: Pre-divider division ratio N */
#define CGU_PLL1_CTRL_NSEL_SHIFT	(12)
#define CGU_PLL1_CTRL_NSEL_MASK		(0x3 << CGU_PLL1_CTRL_NSEL_SHIFT)
#define CGU_PLL1_CTRL_NSEL(x)		((x) << CGU_PLL1_CTRL_NSEL_SHIFT)

/* MSEL: Feedback-divider division ratio (M) */
#define CGU_PLL1_CTRL_MSEL_SHIFT	(16)
#define CGU_PLL1_CTRL_MSEL_MASK		(0xff << CGU_PLL1_CTRL_MSEL_SHIFT)
#define CGU_PLL1_CTRL_MSEL(x)		((x) << CGU_PLL1_CTRL_MSEL_SHIFT)

/* CLK_SEL: Clock-source selection */
#define CGU_PLL1_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_PLL1_CTRL_CLK_SEL_MASK	(0x1f << CGU_PLL1_CTRL_CLK_SEL_SHIFT)
#define CGU_PLL1_CTRL_CLK_SEL(x)	((x) << CGU_PLL1_CTRL_CLK_SEL_SHIFT)

/* --- CGU_IDIVA_CTRL values ------------------------------------ */

/* PD: Integer divider power down */
#define CGU_IDIVA_CTRL_PD_SHIFT		(0)
#define CGU_IDIVA_CTRL_PD		(1 << CGU_IDIVA_CTRL_PD_SHIFT)

/* IDIV: Integer divider A divider value (1/(IDIV + 1)) */
#define CGU_IDIVA_CTRL_IDIV_SHIFT	(2)
#define CGU_IDIVA_CTRL_IDIV_MASK	(0x3 << CGU_IDIVA_CTRL_IDIV_SHIFT)
#define CGU_IDIVA_CTRL_IDIV(x)		((x) << CGU_IDIVA_CTRL_IDIV_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_IDIVA_CTRL_AUTOBLOCK_SHIFT	(11)
#define CGU_IDIVA_CTRL_AUTOBLOCK	(1 << CGU_IDIVA_CTRL_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_IDIVA_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_IDIVA_CTRL_CLK_SEL_MASK	(0x1f << CGU_IDIVA_CTRL_CLK_SEL_SHIFT)
#define CGU_IDIVA_CTRL_CLK_SEL(x)	((x) << CGU_IDIVA_CTRL_CLK_SEL_SHIFT)

/* --- CGU_IDIVB_CTRL values ------------------------------------ */

/* PD: Integer divider power down */
#define CGU_IDIVB_CTRL_PD_SHIFT		(0)
#define CGU_IDIVB_CTRL_PD		(1 << CGU_IDIVB_CTRL_PD_SHIFT)

/* IDIV: Integer divider B divider value (1/(IDIV + 1)) */
#define CGU_IDIVB_CTRL_IDIV_SHIFT	(2)
#define CGU_IDIVB_CTRL_IDIV_MASK	(0xf << CGU_IDIVB_CTRL_IDIV_SHIFT)
#define CGU_IDIVB_CTRL_IDIV(x)		((x) << CGU_IDIVB_CTRL_IDIV_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_IDIVB_CTRL_AUTOBLOCK_SHIFT	(11)
#define CGU_IDIVB_CTRL_AUTOBLOCK	(1 << CGU_IDIVB_CTRL_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_IDIVB_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_IDIVB_CTRL_CLK_SEL_MASK	(0x1f << CGU_IDIVB_CTRL_CLK_SEL_SHIFT)
#define CGU_IDIVB_CTRL_CLK_SEL(x)	((x) << CGU_IDIVB_CTRL_CLK_SEL_SHIFT)

/* --- CGU_IDIVC_CTRL values ------------------------------------ */

/* PD: Integer divider power down */
#define CGU_IDIVC_CTRL_PD_SHIFT		(0)
#define CGU_IDIVC_CTRL_PD		(1 << CGU_IDIVC_CTRL_PD_SHIFT)

/* IDIV: Integer divider C divider value (1/(IDIV + 1)) */
#define CGU_IDIVC_CTRL_IDIV_SHIFT	(2)
#define CGU_IDIVC_CTRL_IDIV_MASK	(0xf << CGU_IDIVC_CTRL_IDIV_SHIFT)
#define CGU_IDIVC_CTRL_IDIV(x)		((x) << CGU_IDIVC_CTRL_IDIV_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_IDIVC_CTRL_AUTOBLOCK_SHIFT	(11)
#define CGU_IDIVC_CTRL_AUTOBLOCK	(1 << CGU_IDIVC_CTRL_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_IDIVC_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_IDIVC_CTRL_CLK_SEL_MASK	(0x1f << CGU_IDIVC_CTRL_CLK_SEL_SHIFT)
#define CGU_IDIVC_CTRL_CLK_SEL(x)	((x) << CGU_IDIVC_CTRL_CLK_SEL_SHIFT)

/* --- CGU_IDIVD_CTRL values ------------------------------------ */

/* PD: Integer divider power down */
#define CGU_IDIVD_CTRL_PD_SHIFT		(0)
#define CGU_IDIVD_CTRL_PD		(1 << CGU_IDIVD_CTRL_PD_SHIFT)

/* IDIV: Integer divider D divider value (1/(IDIV + 1)) */
#define CGU_IDIVD_CTRL_IDIV_SHIFT	(2)
#define CGU_IDIVD_CTRL_IDIV_MASK	(0xf << CGU_IDIVD_CTRL_IDIV_SHIFT)
#define CGU_IDIVD_CTRL_IDIV(x)		((x) << CGU_IDIVD_CTRL_IDIV_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_IDIVD_CTRL_AUTOBLOCK_SHIFT	(11)
#define CGU_IDIVD_CTRL_AUTOBLOCK	(1 << CGU_IDIVD_CTRL_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_IDIVD_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_IDIVD_CTRL_CLK_SEL_MASK	(0x1f << CGU_IDIVD_CTRL_CLK_SEL_SHIFT)
#define CGU_IDIVD_CTRL_CLK_SEL(x)	((x) << CGU_IDIVD_CTRL_CLK_SEL_SHIFT)

/* --- CGU_IDIVE_CTRL values ------------------------------------ */

/* PD: Integer divider power down */
#define CGU_IDIVE_CTRL_PD_SHIFT		(0)
#define CGU_IDIVE_CTRL_PD		(1 << CGU_IDIVE_CTRL_PD_SHIFT)

/* IDIV: Integer divider E divider value (1/(IDIV + 1)) */
#define CGU_IDIVE_CTRL_IDIV_SHIFT	(2)
#define CGU_IDIVE_CTRL_IDIV_MASK	(0xff << CGU_IDIVE_CTRL_IDIV_SHIFT)
#define CGU_IDIVE_CTRL_IDIV(x)		((x) << CGU_IDIVE_CTRL_IDIV_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_IDIVE_CTRL_AUTOBLOCK_SHIFT	(11)
#define CGU_IDIVE_CTRL_AUTOBLOCK	(1 << CGU_IDIVE_CTRL_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_IDIVE_CTRL_CLK_SEL_SHIFT	(24)
#define CGU_IDIVE_CTRL_CLK_SEL_MASK	(0x1f << CGU_IDIVE_CTRL_CLK_SEL_SHIFT)
#define CGU_IDIVE_CTRL_CLK_SEL(x)	((x) << CGU_IDIVE_CTRL_CLK_SEL_SHIFT)

/* --- CGU_BASE_SAFE_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_SAFE_CLK_PD_SHIFT	(0)
#define CGU_BASE_SAFE_CLK_PD		(1 << CGU_BASE_SAFE_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_SAFE_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_SAFE_CLK_AUTOBLOCK	(1 << CGU_BASE_SAFE_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_SAFE_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_SAFE_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_SAFE_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_SAFE_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_SAFE_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_USB0_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_USB0_CLK_PD_SHIFT	(0)
#define CGU_BASE_USB0_CLK_PD		(1 << CGU_BASE_USB0_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_USB0_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_USB0_CLK_AUTOBLOCK	(1 << CGU_BASE_USB0_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_USB0_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_USB0_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_USB0_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_USB0_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_USB0_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_PERIPH_CLK values ------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_PERIPH_CLK_PD_SHIFT	(0)
#define CGU_BASE_PERIPH_CLK_PD		(1 << CGU_BASE_PERIPH_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_PERIPH_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_PERIPH_CLK_AUTOBLOCK \
			(1 << CGU_BASE_PERIPH_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_PERIPH_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_PERIPH_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_PERIPH_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_PERIPH_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_PERIPH_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_USB1_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_USB1_CLK_PD_SHIFT	(0)
#define CGU_BASE_USB1_CLK_PD		(1 << CGU_BASE_USB1_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_USB1_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_USB1_CLK_AUTOBLOCK	(1 << CGU_BASE_USB1_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_USB1_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_USB1_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_USB1_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_USB1_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_USB1_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_M4_CLK values ----------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_M4_CLK_PD_SHIFT	(0)
#define CGU_BASE_M4_CLK_PD		(1 << CGU_BASE_M4_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_M4_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_M4_CLK_AUTOBLOCK	(1 << CGU_BASE_M4_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_M4_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_M4_CLK_CLK_SEL_MASK	(0x1f << CGU_BASE_M4_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_M4_CLK_CLK_SEL(x)	((x) << CGU_BASE_M4_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_SPIFI_CLK values -------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_SPIFI_CLK_PD_SHIFT	(0)
#define CGU_BASE_SPIFI_CLK_PD		(1 << CGU_BASE_SPIFI_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_SPIFI_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_SPIFI_CLK_AUTOBLOCK \
			(1 << CGU_BASE_SPIFI_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_SPIFI_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_SPIFI_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_SPIFI_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_SPIFI_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_SPIFI_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_SPI_CLK values ---------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_SPI_CLK_PD_SHIFT	(0)
#define CGU_BASE_SPI_CLK_PD		(1 << CGU_BASE_SPI_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_SPI_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_SPI_CLK_AUTOBLOCK	(1 << CGU_BASE_SPI_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_SPI_CLK_CLK_SEL_SHIFT	(24)
#define CGU_BASE_SPI_CLK_CLK_SEL_MASK	(0x1f << CGU_BASE_SPI_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_SPI_CLK_CLK_SEL(x)	((x) << CGU_BASE_SPI_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_PHY_RX_CLK values ------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_PHY_RX_CLK_PD_SHIFT	(0)
#define CGU_BASE_PHY_RX_CLK_PD		(1 << CGU_BASE_PHY_RX_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_PHY_RX_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_PHY_RX_CLK_AUTOBLOCK \
			(1 << CGU_BASE_PHY_RX_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_PHY_RX_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_PHY_RX_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_PHY_RX_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_PHY_RX_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_PHY_RX_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_PHY_TX_CLK values ------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_PHY_TX_CLK_PD_SHIFT	(0)
#define CGU_BASE_PHY_TX_CLK_PD		(1 << CGU_BASE_PHY_TX_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_PHY_TX_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_PHY_TX_CLK_AUTOBLOCK \
			(1 << CGU_BASE_PHY_TX_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_PHY_TX_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_PHY_TX_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_PHY_TX_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_PHY_TX_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_PHY_TX_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_APB1_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_APB1_CLK_PD_SHIFT	(0)
#define CGU_BASE_APB1_CLK_PD		(1 << CGU_BASE_APB1_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_APB1_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_APB1_CLK_AUTOBLOCK	(1 << CGU_BASE_APB1_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_APB1_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_APB1_CLK_CLK_SEL_MASK  \
			(0x1f << CGU_BASE_APB1_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_APB1_CLK_CLK_SEL(x)	((x) << CGU_BASE_APB1_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_APB3_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_APB3_CLK_PD_SHIFT	(0)
#define CGU_BASE_APB3_CLK_PD		(1 << CGU_BASE_APB3_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_APB3_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_APB3_CLK_AUTOBLOCK	(1 << CGU_BASE_APB3_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_APB3_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_APB3_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_APB3_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_APB3_CLK_CLK_SEL(x)	((x) << CGU_BASE_APB3_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_LCD_CLK values ---------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_LCD_CLK_PD_SHIFT	(0)
#define CGU_BASE_LCD_CLK_PD		(1 << CGU_BASE_LCD_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_LCD_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_LCD_CLK_AUTOBLOCK	(1 << CGU_BASE_LCD_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_LCD_CLK_CLK_SEL_SHIFT	(24)
#define CGU_BASE_LCD_CLK_CLK_SEL_MASK	(0x1f << CGU_BASE_LCD_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_LCD_CLK_CLK_SEL(x)	((x) << CGU_BASE_LCD_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_VADC_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_VADC_CLK_PD_SHIFT	(0)
#define CGU_BASE_VADC_CLK_PD		(1 << CGU_BASE_VADC_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_VADC_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_VADC_CLK_AUTOBLOCK	(1 << CGU_BASE_VADC_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_VADC_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_VADC_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_VADC_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_VADC_CLK_CLK_SEL(x)	((x) << CGU_BASE_VADC_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_SDIO_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_SDIO_CLK_PD_SHIFT	(0)
#define CGU_BASE_SDIO_CLK_PD		(1 << CGU_BASE_SDIO_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_SDIO_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_SDIO_CLK_AUTOBLOCK	(1 << CGU_BASE_SDIO_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_SDIO_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_SDIO_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_SDIO_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_SDIO_CLK_CLK_SEL(x)	((x) << CGU_BASE_SDIO_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_SSP0_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_SSP0_CLK_PD_SHIFT	(0)
#define CGU_BASE_SSP0_CLK_PD		(1 << CGU_BASE_SSP0_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_SSP0_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_SSP0_CLK_AUTOBLOCK	(1 << CGU_BASE_SSP0_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_SSP0_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_SSP0_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_SSP0_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_SSP0_CLK_CLK_SEL(x)	((x) << CGU_BASE_SSP0_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_SSP1_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_SSP1_CLK_PD_SHIFT	(0)
#define CGU_BASE_SSP1_CLK_PD		(1 << CGU_BASE_SSP1_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_SSP1_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_SSP1_CLK_AUTOBLOCK	(1 << CGU_BASE_SSP1_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_SSP1_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_SSP1_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_SSP1_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_SSP1_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_SSP1_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_UART0_CLK values -------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_UART0_CLK_PD_SHIFT	(0)
#define CGU_BASE_UART0_CLK_PD		(1 << CGU_BASE_UART0_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_UART0_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_UART0_CLK_AUTOBLOCK \
			(1 << CGU_BASE_UART0_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_UART0_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_UART0_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_UART0_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_UART0_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_UART0_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_UART1_CLK values -------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_UART1_CLK_PD_SHIFT	(0)
#define CGU_BASE_UART1_CLK_PD		(1 << CGU_BASE_UART1_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_UART1_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_UART1_CLK_AUTOBLOCK \
			(1 << CGU_BASE_UART1_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_UART1_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_UART1_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_UART1_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_UART1_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_UART1_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_UART2_CLK values -------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_UART2_CLK_PD_SHIFT	(0)
#define CGU_BASE_UART2_CLK_PD		(1 << CGU_BASE_UART2_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_UART2_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_UART2_CLK_AUTOBLOCK \
			(1 << CGU_BASE_UART2_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_UART2_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_UART2_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_UART2_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_UART2_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_UART2_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_UART3_CLK values -------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_UART3_CLK_PD_SHIFT	(0)
#define CGU_BASE_UART3_CLK_PD		(1 << CGU_BASE_UART3_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_UART3_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_UART3_CLK_AUTOBLOCK \
			(1 << CGU_BASE_UART3_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_UART3_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_UART3_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_UART3_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_UART3_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_UART3_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_OUT_CLK values ---------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_OUT_CLK_PD_SHIFT	(0)
#define CGU_BASE_OUT_CLK_PD		(1 << CGU_BASE_OUT_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_OUT_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_OUT_CLK_AUTOBLOCK	(1 << CGU_BASE_OUT_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_OUT_CLK_CLK_SEL_SHIFT	(24)
#define CGU_BASE_OUT_CLK_CLK_SEL_MASK	(0x1f << CGU_BASE_OUT_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_OUT_CLK_CLK_SEL(x)	((x) << CGU_BASE_OUT_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_APLL_CLK values --------------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_APLL_CLK_PD_SHIFT	(0)
#define CGU_BASE_APLL_CLK_PD		(1 << CGU_BASE_APLL_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_APLL_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_APLL_CLK_AUTOBLOCK	(1 << CGU_BASE_APLL_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_APLL_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_APLL_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_APLL_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_APLL_CLK_CLK_SEL(x)	((x) << CGU_BASE_APLL_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_CGU_OUT0_CLK values ----------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_CGU_OUT0_CLK_PD_SHIFT	(0)
#define CGU_BASE_CGU_OUT0_CLK_PD	(1 << CGU_BASE_CGU_OUT0_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_CGU_OUT0_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_CGU_OUT0_CLK_AUTOBLOCK \
			(1 << CGU_BASE_CGU_OUT0_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_CGU_OUT0_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_CGU_OUT0_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_CGU_OUT0_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_CGU_OUT0_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_CGU_OUT0_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_CGU_OUT1_CLK values ----------------------------- */

/* PD: Output stage power down */
#define CGU_BASE_CGU_OUT1_CLK_PD_SHIFT	(0)
#define CGU_BASE_CGU_OUT1_CLK_PD	(1 << CGU_BASE_CGU_OUT1_CLK_PD_SHIFT)

/* AUTOBLOCK: Block clock automatically during frequency change */
#define CGU_BASE_CGU_OUT1_CLK_AUTOBLOCK_SHIFT (11)
#define CGU_BASE_CGU_OUT1_CLK_AUTOBLOCK \
			(1 << CGU_BASE_CGU_OUT1_CLK_AUTOBLOCK_SHIFT)

/* CLK_SEL: Clock source selection */
#define CGU_BASE_CGU_OUT1_CLK_CLK_SEL_SHIFT (24)
#define CGU_BASE_CGU_OUT1_CLK_CLK_SEL_MASK \
			(0x1f << CGU_BASE_CGU_OUT1_CLK_CLK_SEL_SHIFT)
#define CGU_BASE_CGU_OUT1_CLK_CLK_SEL(x) \
			((x) << CGU_BASE_CGU_OUT1_CLK_CLK_SEL_SHIFT)

/* --- CGU_BASE_x_CLK clock sources  --------------------------------------- */

#define CGU_SRC_32K       0x00
#define CGU_SRC_IRC       0x01
#define CGU_SRC_ENET_RX   0x02
#define CGU_SRC_ENET_TX   0x03
#define CGU_SRC_GP_CLKIN  0x04
#define CGU_SRC_XTAL      0x06
#define CGU_SRC_PLL0USB   0x07
#define CGU_SRC_PLL0AUDIO 0x08
#define CGU_SRC_PLL1      0x09
#define CGU_SRC_IDIVA     0x0C
#define CGU_SRC_IDIVB     0x0D
#define CGU_SRC_IDIVC     0x0E
#define CGU_SRC_IDIVD     0x0F
#define CGU_SRC_IDIVE     0x10

/**@}*/

#endif
