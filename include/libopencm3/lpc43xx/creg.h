/** @defgroup creg_defines Configuration Registers Defines

@brief <b>Defined Constants and Types for the LPC43xx Configuration
Registers</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
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

#ifndef LPC43XX_CREG_H
#define LPC43XX_CREG_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- CREG registers ----------------------------------------------------- */

/*
 * Chip configuration register 32 kHz oscillator output and BOD control
 * register
 */
#define CREG_CREG0                      MMIO32(CREG_BASE + 0x004)

/* ARM Cortex-M4 memory mapping */
#define CREG_M4MEMMAP                   MMIO32(CREG_BASE + 0x100)

/* Chip configuration register 1 */
#define CREG_CREG1                      MMIO32(CREG_BASE + 0x108)

/* Chip configuration register 2 */
#define CREG_CREG2                      MMIO32(CREG_BASE + 0x10C)

/* Chip configuration register 3 */
#define CREG_CREG3                      MMIO32(CREG_BASE + 0x110)

/* Chip configuration register 4 */
#define CREG_CREG4                      MMIO32(CREG_BASE + 0x114)

/* Chip configuration register 5 */
#define CREG_CREG5                      MMIO32(CREG_BASE + 0x118)

/* DMA muxing control */
#define CREG_DMAMUX                     MMIO32(CREG_BASE + 0x11C)

/* Flash accelerator configuration register for flash bank A */
#define CREG_FLASHCFGA                  MMIO32(CREG_BASE + 0x120)

/* Flash accelerator configuration register for flash bank B */
#define CREG_FLASHCFGB                  MMIO32(CREG_BASE + 0x124)

/* ETB RAM configuration */
#define CREG_ETBCFG                     MMIO32(CREG_BASE + 0x128)

/*
 * Chip configuration register 6. Controls multiple functions: Ethernet
 * interface, SCT output, I2S0/1 inputs, EMC clock.
 */
#define CREG_CREG6                      MMIO32(CREG_BASE + 0x12C)

/* Cortex-M4 TXEV event clear */
#define CREG_M4TXEVENT                  MMIO32(CREG_BASE + 0x130)

/* Part ID (Boundary scan ID code, read-only) */
#define CREG_CHIPID                     MMIO32(CREG_BASE + 0x200)

/* Cortex-M0 TXEV event clear */
#define CREG_M0TXEVENT                  MMIO32(CREG_BASE + 0x400)

/* ARM Cortex-M0 memory mapping */
#define CREG_M0APPMEMMAP                MMIO32(CREG_BASE + 0x404)

/* USB0 frame length adjust register */
#define CREG_USB0FLADJ                  MMIO32(CREG_BASE + 0x500)

/* USB1 frame length adjust register */
#define CREG_USB1FLADJ                  MMIO32(CREG_BASE + 0x600)

/* --- CREG_CREG0 values ---------------------------------------- */

/* EN1KHZ: Enable 1 kHz output */
#define CREG_CREG0_EN1KHZ_SHIFT (0)
#define CREG_CREG0_EN1KHZ (1 << CREG_CREG0_EN1KHZ_SHIFT)

/* EN32KHZ: Enable 32 kHz output */
#define CREG_CREG0_EN32KHZ_SHIFT (1)
#define CREG_CREG0_EN32KHZ (1 << CREG_CREG0_EN32KHZ_SHIFT)

/* RESET32KHZ: 32 kHz oscillator reset */
#define CREG_CREG0_RESET32KHZ_SHIFT (2)
#define CREG_CREG0_RESET32KHZ (1 << CREG_CREG0_RESET32KHZ_SHIFT)

/* PD32KHZ: 32 kHz power control */
#define CREG_CREG0_PD32KHZ_SHIFT (3)
#define CREG_CREG0_PD32KHZ (1 << CREG_CREG0_PD32KHZ_SHIFT)

/* USB0PHY: USB0 PHY power control */
#define CREG_CREG0_USB0PHY_SHIFT (5)
#define CREG_CREG0_USB0PHY (1 << CREG_CREG0_USB0PHY_SHIFT)

/* ALARMCTRL: RTC_ALARM pin output control */
#define CREG_CREG0_ALARMCTRL_SHIFT (6)
#define CREG_CREG0_ALARMCTRL_MASK (0x3 << CREG_CREG0_ALARMCTRL_SHIFT)
#define CREG_CREG0_ALARMCTRL(x) ((x) << CREG_CREG0_ALARMCTRL_SHIFT)

/* BODLVL1: BOD trip level to generate an interrupt */
#define CREG_CREG0_BODLVL1_SHIFT (8)
#define CREG_CREG0_BODLVL1_MASK (0x3 << CREG_CREG0_BODLVL1_SHIFT)
#define CREG_CREG0_BODLVL1(x) ((x) << CREG_CREG0_BODLVL1_SHIFT)

/* BODLVL2: BOD trip level to generate a reset */
#define CREG_CREG0_BODLVL2_SHIFT (10)
#define CREG_CREG0_BODLVL2_MASK (0x3 << CREG_CREG0_BODLVL2_SHIFT)
#define CREG_CREG0_BODLVL2(x) ((x) << CREG_CREG0_BODLVL2_SHIFT)

/* SAMPLECTRL: SAMPLE pin input/output control */
#define CREG_CREG0_SAMPLECTRL_SHIFT (12)
#define CREG_CREG0_SAMPLECTRL_MASK (0x3 << CREG_CREG0_SAMPLECTRL_SHIFT)
#define CREG_CREG0_SAMPLECTRL(x) ((x) << CREG_CREG0_SAMPLECTRL_SHIFT)

/* WAKEUP0CTRL: WAKEUP0 pin input/output control */
#define CREG_CREG0_WAKEUP0CTRL_SHIFT (14)
#define CREG_CREG0_WAKEUP0CTRL_MASK (0x3 << CREG_CREG0_WAKEUP0CTRL_SHIFT)
#define CREG_CREG0_WAKEUP0CTRL(x) ((x) << CREG_CREG0_WAKEUP0CTRL_SHIFT)

/* WAKEUP1CTRL: WAKEUP1 pin input/output control */
#define CREG_CREG0_WAKEUP1CTRL_SHIFT (16)
#define CREG_CREG0_WAKEUP1CTRL_MASK (0x3 << CREG_CREG0_WAKEUP1CTRL_SHIFT)
#define CREG_CREG0_WAKEUP1CTRL(x) ((x) << CREG_CREG0_WAKEUP1CTRL_SHIFT)

/* --- CREG_M4MEMMAP values ------------------------------------- */

/* M4MAP: Shadow address when accessing memory at address 0x00000000 */
#define CREG_M4MEMMAP_M4MAP_SHIFT (12)
#define CREG_M4MEMMAP_M4MAP_MASK (0xfffff << CREG_M4MEMMAP_M4MAP_SHIFT)
#define CREG_M4MEMMAP_M4MAP(x) ((x) << CREG_M4MEMMAP_M4MAP_SHIFT)

/* --- CREG_CREG5 values ---------------------------------------- */

/* M4TAPSEL: JTAG debug select for M4 core */
#define CREG_CREG5_M4TAPSEL_SHIFT (6)
#define CREG_CREG5_M4TAPSEL (1 << CREG_CREG5_M4TAPSEL_SHIFT)

/* M0APPTAPSEL: JTAG debug select for M0 co-processor */
#define CREG_CREG5_M0APPTAPSEL_SHIFT (9)
#define CREG_CREG5_M0APPTAPSEL (1 << CREG_CREG5_M0APPTAPSEL_SHIFT)

/* --- CREG_DMAMUX values --------------------------------------- */

/* DMAMUXPER0: Select DMA to peripheral connection for DMA peripheral 0 */
#define CREG_DMAMUX_DMAMUXPER0_SHIFT (0)
#define CREG_DMAMUX_DMAMUXPER0_MASK (0x3 << CREG_DMAMUX_DMAMUXPER0_SHIFT)
#define CREG_DMAMUX_DMAMUXPER0(x) ((x) << CREG_DMAMUX_DMAMUXPER0_SHIFT)

/* DMAMUXPER1: Select DMA to peripheral connection for DMA peripheral 1 */
#define CREG_DMAMUX_DMAMUXPER1_SHIFT (2)
#define CREG_DMAMUX_DMAMUXPER1_MASK (0x3 << CREG_DMAMUX_DMAMUXPER1_SHIFT)
#define CREG_DMAMUX_DMAMUXPER1(x) ((x) << CREG_DMAMUX_DMAMUXPER1_SHIFT)

/* DMAMUXPER2: Select DMA to peripheral connection for DMA peripheral 2 */
#define CREG_DMAMUX_DMAMUXPER2_SHIFT (4)
#define CREG_DMAMUX_DMAMUXPER2_MASK (0x3 << CREG_DMAMUX_DMAMUXPER2_SHIFT)
#define CREG_DMAMUX_DMAMUXPER2(x) ((x) << CREG_DMAMUX_DMAMUXPER2_SHIFT)

/* DMAMUXPER3: Select DMA to peripheral connection for DMA peripheral 3 */
#define CREG_DMAMUX_DMAMUXPER3_SHIFT (6)
#define CREG_DMAMUX_DMAMUXPER3_MASK (0x3 << CREG_DMAMUX_DMAMUXPER3_SHIFT)
#define CREG_DMAMUX_DMAMUXPER3(x) ((x) << CREG_DMAMUX_DMAMUXPER3_SHIFT)

/* DMAMUXPER4: Select DMA to peripheral connection for DMA peripheral 4 */
#define CREG_DMAMUX_DMAMUXPER4_SHIFT (8)
#define CREG_DMAMUX_DMAMUXPER4_MASK (0x3 << CREG_DMAMUX_DMAMUXPER4_SHIFT)
#define CREG_DMAMUX_DMAMUXPER4(x) ((x) << CREG_DMAMUX_DMAMUXPER4_SHIFT)

/* DMAMUXPER5: Select DMA to peripheral connection for DMA peripheral 5 */
#define CREG_DMAMUX_DMAMUXPER5_SHIFT (10)
#define CREG_DMAMUX_DMAMUXPER5_MASK (0x3 << CREG_DMAMUX_DMAMUXPER5_SHIFT)
#define CREG_DMAMUX_DMAMUXPER5(x) ((x) << CREG_DMAMUX_DMAMUXPER5_SHIFT)

/* DMAMUXPER6: Select DMA to peripheral connection for DMA peripheral 6 */
#define CREG_DMAMUX_DMAMUXPER6_SHIFT (12)
#define CREG_DMAMUX_DMAMUXPER6_MASK (0x3 << CREG_DMAMUX_DMAMUXPER6_SHIFT)
#define CREG_DMAMUX_DMAMUXPER6(x) ((x) << CREG_DMAMUX_DMAMUXPER6_SHIFT)

/* DMAMUXPER7: Select DMA to peripheral connection for DMA peripheral 7 */
#define CREG_DMAMUX_DMAMUXPER7_SHIFT (14)
#define CREG_DMAMUX_DMAMUXPER7_MASK (0x3 << CREG_DMAMUX_DMAMUXPER7_SHIFT)
#define CREG_DMAMUX_DMAMUXPER7(x) ((x) << CREG_DMAMUX_DMAMUXPER7_SHIFT)

/* DMAMUXPER8: Select DMA to peripheral connection for DMA peripheral 8 */
#define CREG_DMAMUX_DMAMUXPER8_SHIFT (16)
#define CREG_DMAMUX_DMAMUXPER8_MASK (0x3 << CREG_DMAMUX_DMAMUXPER8_SHIFT)
#define CREG_DMAMUX_DMAMUXPER8(x) ((x) << CREG_DMAMUX_DMAMUXPER8_SHIFT)

/* DMAMUXPER9: Select DMA to peripheral connection for DMA peripheral 9 */
#define CREG_DMAMUX_DMAMUXPER9_SHIFT (18)
#define CREG_DMAMUX_DMAMUXPER9_MASK (0x3 << CREG_DMAMUX_DMAMUXPER9_SHIFT)
#define CREG_DMAMUX_DMAMUXPER9(x) ((x) << CREG_DMAMUX_DMAMUXPER9_SHIFT)

/* DMAMUXPER10: Select DMA to peripheral connection for DMA peripheral 10 */
#define CREG_DMAMUX_DMAMUXPER10_SHIFT (20)
#define CREG_DMAMUX_DMAMUXPER10_MASK (0x3 << CREG_DMAMUX_DMAMUXPER10_SHIFT)
#define CREG_DMAMUX_DMAMUXPER10(x) ((x) << CREG_DMAMUX_DMAMUXPER10_SHIFT)

/* DMAMUXPER11: Select DMA to peripheral connection for DMA peripheral 11 */
#define CREG_DMAMUX_DMAMUXPER11_SHIFT (22)
#define CREG_DMAMUX_DMAMUXPER11_MASK (0x3 << CREG_DMAMUX_DMAMUXPER11_SHIFT)
#define CREG_DMAMUX_DMAMUXPER11(x) ((x) << CREG_DMAMUX_DMAMUXPER11_SHIFT)

/* DMAMUXPER12: Select DMA to peripheral connection for DMA peripheral 12 */
#define CREG_DMAMUX_DMAMUXPER12_SHIFT (24)
#define CREG_DMAMUX_DMAMUXPER12_MASK (0x3 << CREG_DMAMUX_DMAMUXPER12_SHIFT)
#define CREG_DMAMUX_DMAMUXPER12(x) ((x) << CREG_DMAMUX_DMAMUXPER12_SHIFT)

/* DMAMUXPER13: Select DMA to peripheral connection for DMA peripheral 13 */
#define CREG_DMAMUX_DMAMUXPER13_SHIFT (26)
#define CREG_DMAMUX_DMAMUXPER13_MASK (0x3 << CREG_DMAMUX_DMAMUXPER13_SHIFT)
#define CREG_DMAMUX_DMAMUXPER13(x) ((x) << CREG_DMAMUX_DMAMUXPER13_SHIFT)

/* DMAMUXPER14: Select DMA to peripheral connection for DMA peripheral 14 */
#define CREG_DMAMUX_DMAMUXPER14_SHIFT (28)
#define CREG_DMAMUX_DMAMUXPER14_MASK (0x3 << CREG_DMAMUX_DMAMUXPER14_SHIFT)
#define CREG_DMAMUX_DMAMUXPER14(x) ((x) << CREG_DMAMUX_DMAMUXPER14_SHIFT)

/* DMAMUXPER15: Select DMA to peripheral connection for DMA peripheral 15 */
#define CREG_DMAMUX_DMAMUXPER15_SHIFT (30)
#define CREG_DMAMUX_DMAMUXPER15_MASK (0x3 << CREG_DMAMUX_DMAMUXPER15_SHIFT)
#define CREG_DMAMUX_DMAMUXPER15(x) ((x) << CREG_DMAMUX_DMAMUXPER15_SHIFT)

/* --- CREG_FLASHCFGA values ------------------------------------ */

/* FLASHTIM: Flash access time. The value of this field plus 1 gives the number
 * of BASE_M4_CLK clocks used for a flash access */
#define CREG_FLASHCFGA_FLASHTIM_SHIFT (12)
#define CREG_FLASHCFGA_FLASHTIM_MASK (0xf << CREG_FLASHCFGA_FLASHTIM_SHIFT)
#define CREG_FLASHCFGA_FLASHTIM(x) ((x) << CREG_FLASHCFGA_FLASHTIM_SHIFT)

/* POW: Flash bank A power control */
#define CREG_FLASHCFGA_POW_SHIFT (31)
#define CREG_FLASHCFGA_POW (1 << CREG_FLASHCFGA_POW_SHIFT)

/* --- CREG_FLASHCFGB values ------------------------------------ */

/* FLASHTIM: Flash access time. The value of this field plus 1 gives the number
 * of BASE_M4_CLK clocks used for a flash access */
#define CREG_FLASHCFGB_FLASHTIM_SHIFT (12)
#define CREG_FLASHCFGB_FLASHTIM_MASK (0xf << CREG_FLASHCFGB_FLASHTIM_SHIFT)
#define CREG_FLASHCFGB_FLASHTIM(x) ((x) << CREG_FLASHCFGB_FLASHTIM_SHIFT)

/* POW: Flash bank B power control */
#define CREG_FLASHCFGB_POW_SHIFT (31)
#define CREG_FLASHCFGB_POW (1 << CREG_FLASHCFGB_POW_SHIFT)

/* --- CREG_ETBCFG values --------------------------------------- */

/* ETB: Select SRAM interface */
#define CREG_ETBCFG_ETB_SHIFT (0)
#define CREG_ETBCFG_ETB (1 << CREG_ETBCFG_ETB_SHIFT)

/* --- CREG_CREG6 values ---------------------------------------- */

/* ETHMODE: Selects the Ethernet mode. Reset the ethernet after changing the
 * PHY interface */
#define CREG_CREG6_ETHMODE_SHIFT (0)
#define CREG_CREG6_ETHMODE_MASK (0x7 << CREG_CREG6_ETHMODE_SHIFT)
#define CREG_CREG6_ETHMODE(x) ((x) << CREG_CREG6_ETHMODE_SHIFT)

/* CTOUTCTRL: Selects the functionality of the SCT outputs */
#define CREG_CREG6_CTOUTCTRL_SHIFT (4)
#define CREG_CREG6_CTOUTCTRL (1 << CREG_CREG6_CTOUTCTRL_SHIFT)

/* I2S0_TX_SCK_IN_SEL: I2S0_TX_SCK input select */
#define CREG_CREG6_I2S0_TX_SCK_IN_SEL_SHIFT (12)
#define CREG_CREG6_I2S0_TX_SCK_IN_SEL (1 << CREG_CREG6_I2S0_TX_SCK_IN_SEL_SHIFT)

/* I2S0_RX_SCK_IN_SEL: I2S0_RX_SCK input select */
#define CREG_CREG6_I2S0_RX_SCK_IN_SEL_SHIFT (13)
#define CREG_CREG6_I2S0_RX_SCK_IN_SEL (1 << CREG_CREG6_I2S0_RX_SCK_IN_SEL_SHIFT)

/* I2S1_TX_SCK_IN_SEL: I2S1_TX_SCK input select */
#define CREG_CREG6_I2S1_TX_SCK_IN_SEL_SHIFT (14)
#define CREG_CREG6_I2S1_TX_SCK_IN_SEL (1 << CREG_CREG6_I2S1_TX_SCK_IN_SEL_SHIFT)

/* I2S1_RX_SCK_IN_SEL: I2S1_RX_SCK input select */
#define CREG_CREG6_I2S1_RX_SCK_IN_SEL_SHIFT (15)
#define CREG_CREG6_I2S1_RX_SCK_IN_SEL (1 << CREG_CREG6_I2S1_RX_SCK_IN_SEL_SHIFT)

/* EMC_CLK_SEL: EMC_CLK divided clock select */
#define CREG_CREG6_EMC_CLK_SEL_SHIFT (16)
#define CREG_CREG6_EMC_CLK_SEL (1 << CREG_CREG6_EMC_CLK_SEL_SHIFT)

/* --- CREG_M4TXEVENT values ------------------------------------ */

/* TXEVCLR: Cortex-M4 TXEV event */
#define CREG_M4TXEVENT_TXEVCLR_SHIFT (0)
#define CREG_M4TXEVENT_TXEVCLR (1 << CREG_M4TXEVENT_TXEVCLR_SHIFT)

/* --- CREG_M0TXEVENT values ------------------------------------ */

/* TXEVCLR: Cortex-M0 TXEV event */
#define CREG_M0TXEVENT_TXEVCLR_SHIFT (0)
#define CREG_M0TXEVENT_TXEVCLR (1 << CREG_M0TXEVENT_TXEVCLR_SHIFT)

/* --- CREG_M0APPMEMMAP values ---------------------------------- */

/* M0APPMAP: Shadow address when accessing memory at address 0x00000000 */
#define CREG_M0APPMEMMAP_M0APPMAP_SHIFT (12)
#define CREG_M0APPMEMMAP_M0APPMAP_MASK \
			(0xfffff << CREG_M0APPMEMMAP_M0APPMAP_SHIFT)
#define CREG_M0APPMEMMAP_M0APPMAP(x) ((x) << CREG_M0APPMEMMAP_M0APPMAP_SHIFT)

/* --- CREG_USB0FLADJ values ------------------------------------ */

/* FLTV: Frame length timing value */
#define CREG_USB0FLADJ_FLTV_SHIFT (0)
#define CREG_USB0FLADJ_FLTV_MASK (0x3f << CREG_USB0FLADJ_FLTV_SHIFT)
#define CREG_USB0FLADJ_FLTV(x) ((x) << CREG_USB0FLADJ_FLTV_SHIFT)

/* --- CREG_USB1FLADJ values ------------------------------------ */

/* FLTV: Frame length timing value */
#define CREG_USB1FLADJ_FLTV_SHIFT (0)
#define CREG_USB1FLADJ_FLTV_MASK (0x3f << CREG_USB1FLADJ_FLTV_SHIFT)
#define CREG_USB1FLADJ_FLTV(x) ((x) << CREG_USB1FLADJ_FLTV_SHIFT)

/**@}*/

#endif
