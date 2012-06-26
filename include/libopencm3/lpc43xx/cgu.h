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

/* --- CGU_XTAL_OSC_CTRL values -------------------------------------------- */

#define CGU_XTAL_OSC_CTRL_ENABLE (1 << 0) /* enable or power down xtal osc */
#define CGU_XTAL_OSC_CTRL_BYPASS (1 << 1) /* external clock input (not xtal) */
#define CGU_XTAL_OSC_CTRL_HF     (1 << 2) /* high frequency mode (>15 MHz) */

/* --- CGU_PLL1_STAT values ------------------------------------------------ */

#define CGU_PLL1_STAT_LOCK (1 << 0)

/* --- CGU_PLL1_CTRL values ------------------------------------------------ */

#define CGU_PLL1_CTRL_PD            (1 << 0)  /* power down */
#define CGU_PLL1_CTRL_BYPASS        (1 << 1)  /* PLL input to post-dividers */
#define CGU_PLL1_CTRL_FBSEL         (1 << 6)  /* use clkout as feedback input */
#define CGU_PLL1_CTRL_DIRECT        (1 << 7)  /* enable direct CCO output */
#define CGU_PLL1_CTRL_PSEL_SHIFT    8         /* division ratio P (2 bits) */
#define CGU_PLL1_CTRL_AUTOBLOCK     (1 << 11) /* block clock automatically */
#define CGU_PLL1_CTRL_NSEL_SHIFT    12        /* division ratio N (2 bits) */
#define CGU_PLL1_CTRL_MSEL_SHIFT    16        /* division ratio M (8 bits) */
#define CGU_PLL1_CTRL_CLK_SEL_SHIFT 24        /* clock source (5 bits) */

/* --- CGU_PLL0USB_STAT values --------------------------------------------- */

#define CGU_PLL0USB_STAT_LOCK (1 << 0) /* PLL0 lock indicator */
#define CGU_PLL0USB_STAT_FR   (1 << 1) /* PLL0 free running indicator */

/* --- CGU_PLL0USB_CTRL values --------------------------------------------- */

#define CGU_PLL0USB_CTRL_PD            (1 << 0)  /* power down */
#define CGU_PLL0USB_CTRL_BYPASS        (1 << 1)  /* input to post-dividers */
#define CGU_PLL0USB_CTRL_DIRECTI       (1 << 2)  /* direct input */
#define CGU_PLL0USB_CTRL_DIRECTO       (1 << 3)  /* direct output */
#define CGU_PLL0USB_CTRL_CLKEN         (1 << 4)  /* clock enable */
#define CGU_PLL0USB_CTRL_FRM           (1 << 6)  /* free running mode */
#define CGU_PLL0USB_CTRL_AUTOBLOCK     (1 << 11) /* block clock automatically */
#define CGU_PLL0USB_CTRL_CLK_SEL_SHIFT 24        /* clock source (5 bits) */

/* --- CGU_PLL0USB_MDIV values --------------------------------------------- */

#define CGU_PLL0USB_MDIV_MDEC_SHIFT 0  /* Decoded M-divider value (17 bits) */
#define CGU_PLL0USB_SELP_MDEC_SHIFT 17 /* Bandwidth select P value (5 bits) */
#define CGU_PLL0USB_SELI_MDEC_SHIFT 22 /* Bandwidth select I value (6 bits) */
#define CGU_PLL0USB_SELR_MDEC_SHIFT 28 /* Bandwidth select R value (4 bits) */

/* --- CGU_PLL0USB_NP_DIV values ------------------------------------------- */

#define CGU_PLL0USB_NP_DIV_PDEC_SHIFT 0  /* Decoded P-divider value (7 bits) */
#define CGU_PLL0USB_NP_DIV_NDEC_SHIFT 12 /* Decoded N-divider value (8 bits) */

/* --- CGU_BASE_x_CLK values ----------------------------------------------- */

#define CGU_BASE_CLK_PD        (1 << 0)  /* output stage power-down */
#define CGU_BASE_CLK_AUTOBLOCK (1 << 11) /* block clock automatically */
#define CGU_BASE_CLK_SEL_SHIFT 24        /* clock source selection (5 bits) */

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

#endif
