/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 * @see EFM32TG_CMU
 */

/** Definitions for the CMU subsystem (Clock Management Unit).
 *
 * This corresponds to the description in d0034_efm32tg_reference_manual.pdf
 * section 11.
 *
 * @ingroup EFM32TG
 * @defgroup EFM32TG_CMU CMU (Clock Management Unit)
 * @{
 */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_CMU_H
#define LIBOPENCM3_EFM32_TINYGECKO_CMU_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>

/** Register definitions and register value definitions for the CMU subsystem
 *
 * @defgroup EFM32TG_CMU_regsandvals CMU registers and values
 * @{
 */

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 11.4
 *
 * @defgroup EFM32TG_CMU_registers CMU registers
 * @{
 */

#define CMU_CTRL                MMIO32(CMU_BASE + 0x000) /**< @see EFM32TG_CMU_CTRL_bits */
#define CMU_HFCORECLKDIV        MMIO32(CMU_BASE + 0x004) /**< @see EFM32TG_CMU_HFCORECLKDIV_values */
#define CMU_HFPERCLKDIV         MMIO32(CMU_BASE + 0x008) /**< @see EFM32TG_CMU_HFPERCLKDIV_bits */
#define CMU_HFRCOCTRL           MMIO32(CMU_BASE + 0x00c) /**< @see EFM32TG_CMU_HFRCOCTRL_bits */
#define CMU_LFRCOCTRL           MMIO32(CMU_BASE + 0x010)
#define CMU_AUXHFRCOCTRL        MMIO32(CMU_BASE + 0x014) /**< @see EFM32TG_CMU_AUXHFRCOCTRL_bits */
#define CMU_CALCTRL             MMIO32(CMU_BASE + 0x018) /**< @see EFM32TG_CMU_CALCTRL_bits */
#define CMU_CALCNT              MMIO32(CMU_BASE + 0x01c)
#define CMU_OSCENCMD            MMIO32(CMU_BASE + 0x020) /**< @see EFM32TG_CMU_OSCENCMD_bits */
#define CMU_CMD                 MMIO32(CMU_BASE + 0x024) /**< @see EFM32TG_CMU_CMD_bits */
#define CMU_LFCLKSEL            MMIO32(CMU_BASE + 0x028) /**< @see EFM32TG_CMU_LFCLKSEL_bits */
#define CMU_STATUS              MMIO32(CMU_BASE + 0x02c) /**< @see EFM32TG_CMU_STATUS_bits */
#define CMU_IF                  MMIO32(CMU_BASE + 0x030) /**< @see EFM32TG_CMU_I_bits */
#define CMU_IFS                 MMIO32(CMU_BASE + 0x034) /**< @see EFM32TG_CMU_I_bits */
#define CMU_IFC                 MMIO32(CMU_BASE + 0x038) /**< @see EFM32TG_CMU_I_bits */
#define CMU_IEN                 MMIO32(CMU_BASE + 0x03c) /**< @see EFM32TG_CMU_I_bits */
#define CMU_HFCORECLKEN0        MMIO32(CMU_BASE + 0x040) /**< @see EFM32TG_CMU_HFCORECLKEN0_bits */
#define CMU_HFPERCLKEN0         MMIO32(CMU_BASE + 0x044) /**< @see EFM32TG_CMU_HFPERCLKEN0_bits */
#define CMU_SYNCBUSY            MMIO32(CMU_BASE + 0x050) /**< @see EFM32TG_CMU_SYNCBUSY_bits */
#define CMU_FREEZE              MMIO32(CMU_BASE + 0x054) /**< @see EFM32TG_CMU_FREEZE_bits */
#define CMU_LFACLKEN0           MMIO32(CMU_BASE + 0x058) /**< @see EFM32TG_CMU_LFACLKEN0_bits */
#define CMU_LFBCLKEN0           MMIO32(CMU_BASE + 0x060) /**< @see EFM32TG_CMU_LFBCLKEN0_bits */
#define CMU_LFAPRESC0           MMIO32(CMU_BASE + 0x068) /**< @see EFM32TG_CMU_LFAPRESC0_bits */
#define CMU_LFBPRESC0           MMIO32(CMU_BASE + 0x070) /**< @see EFM32TG_CMU_LFBPRESC0_bits */
#define CMU_PCNTCTRL            MMIO32(CMU_BASE + 0x078) /**< @see EFM32TG_CMU_PCNTCTRL_bits */
#define CMU_LCDCTRL             MMIO32(CMU_BASE + 0x07c) /**< @see EFM32TG_CMU_LCDCTRL_bits */
#define CMU_ROUTE               MMIO32(CMU_BASE + 0x080) /**< @see EFM32TG_CMU_ROUTE_bits */
#define CMU_LOCK                MMIO32(CMU_BASE + 0x084) /**< @see EFM32TG_CMU_LOCK_values */

/** @} */

/** Bit states for the CMU_CTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.1 for definitions.
 *
 * @defgroup EFM32TG_CMU_CTRL_bits CMU CTRL bits
 * @{
 */

#define CMU_CTRL_DBGCLK_AUXHFRCO (0<<28)
#define CMU_CTRL_DBGCLK_HFCLK   (1<<28)
#define CMU_CTRL_DBGCLK_MASK    (0x1<<28)
#define CMU_CTRL_CLKOUTSEL1_LFRCO (0<<23)
#define CMU_CTRL_CLKOUTSEL1_LFXO (1<<23)
#define CMU_CTRL_CLKOUTSEL1_HFCLK (2<<23)
#define CMU_CTRL_CLKOUTSEL1_LFXOQ (3<<23)
#define CMU_CTRL_CLKOUTSEL1_HFXOQ (4<<23)
#define CMU_CTRL_CLKOUTSEL1_LFRCOQ (5<<23)
#define CMU_CTRL_CLKOUTSEL1_HFRCOQ (6<<23)
#define CMU_CTRL_CLKOUTSEL1_AUXHFRCOQ (7<<23)
#define CMU_CTRL_CLKOUTSEL1_MASK (0x7<<23)
#define CMU_CTRL_CLKOUTSEL0_HFRCO (0<<20)
#define CMU_CTRL_CLKOUTSEL0_HFXO (1<<20)
#define CMU_CTRL_CLKOUTSEL0_HFCLK2 (2<<20)
#define CMU_CTRL_CLKOUTSEL0_HFCLK4 (3<<20)
#define CMU_CTRL_CLKOUTSEL0_HFCLK8 (4<<20)
#define CMU_CTRL_CLKOUTSEL0_HFCLK16 (5<<20)
#define CMU_CTRL_CLKOUTSEL0_ULFRCO (6<<20)
#define CMU_CTRL_CLKOUTSEL0_AUXHFRCO (7<<20)
#define CMU_CTRL_CLKOUTSEL0_MASK (0x7<<20)
#define CMU_CTRL_LFXOTIMEOUT_8CYCLES (0<<18)
#define CMU_CTRL_LFXOTIMEOUT_1KCYCLES (1<<18)
#define CMU_CTRL_LFXOTIMEOUT_16KCYCLES (2<<18)
#define CMU_CTRL_LFXOTIMEOUT_32KCYCLES (3<<18)
#define CMU_CTRL_LFXOTIMEOUT_MASK (0x3<<18)
#define CMU_CTRL_LFXOBUFCUR     (1<<17)
#define CMU_CTRL_LXFOBOOST_70PCENT (0<<13)
#define CMU_CTRL_LXFOBOOST_100PCENT (1<<13)
#define CMU_CTRL_LXFOBOOST_MASK (0x1<<13)
#define CMU_CTRL_LFXOMODE_XTAL  (0<<11)
#define CMU_CTRL_LFXOMODE_BUFEXTCLK (1<<11)
#define CMU_CTRL_LFXOMODE_DIGEXTCLK (2<<11)
#define CMU_CTRL_LFXOMODE_MASK  (0x3<<11)
#define CMU_CTRL_HFXOTIMEOUT_8CYCLES (0<<9)
#define CMU_CTRL_HFXOTIMEOUT_256CYCLES (1<<9)
#define CMU_CTRL_HFXOTIMEOUT_1KCYCLES (2<<9)
#define CMU_CTRL_HFXOTIMEOUT_16KCYCLES (3<<9)
#define CMU_CTRL_HFXOTIMEOUT_MASK (0x3<<9)
#define CMU_CTRL_HFXOGLITCHDETEN (1<<7)
#define CMU_CTRL_HFXOBUFCUR_MASK (0x3<<5)
#define CMU_CTRL_HFXOBOOST_50PCENT (0<<2)
#define CMU_CTRL_HFXOBOOST_70PCENT (1<<2)
#define CMU_CTRL_HFXOBOOST_80PCENT (2<<2)
#define CMU_CTRL_HFXOBOOST_100PCENT (3<<2)
#define CMU_CTRL_HFXOBOOST_MASK (0x3<<2)
#define CMU_CTRL_HFXOMODE_XTAL  (0<<0)
#define CMU_CTRL_HFXOMODE_BUFEXTCLK (1<<0)
#define CMU_CTRL_HFXOMODE_DIGEXTCLK (2<<0)
#define CMU_CTRL_HFXOMODE_MASK  (0x3<<0)

/** @} */

/** Values for the CMU_HFCORECLKDIV register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.2 for definitions.
 *
 * @defgroup EFM32TG_CMU_HFCORECLKDIV_values CMU HFCORECLKDIV values
 * @{
 */

#define CMU_HFCORECLKDIV_HFCLK  0
#define CMU_HFCORECLKDIV_HFCLK2 1
#define CMU_HFCORECLKDIV_HFCLK4 2
#define CMU_HFCORECLKDIV_HFCLK8 3
#define CMU_HFCORECLKDIV_HFCLK16 4
#define CMU_HFCORECLKDIV_HFCLK32 5
#define CMU_HFCORECLKDIV_HFCLK64 6
#define CMU_HFCORECLKDIV_HFCLK128 7
#define CMU_HFCORECLKDIV_HFCLK256 8
#define CMU_HFCORECLKDIV_HFCLK512 9

/** @} */

/** Bit states for the CMU_HFPERCLKDIV register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.3 for definitions.
 *
 * @defgroup EFM32TG_CMU_HFPERCLKDIV_bits CMU HFPERCLKDIV bits
 * @{
 */

#define CMU_HFPERCLKDIV_HFPERCLKEN (1<<8)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK (0<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK2 (1<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK4 (2<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK8 (3<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK16 (4<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK32 (5<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK64 (6<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK128 (7<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK256 (8<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK512 (9<<0)
#define CMU_HFPERCLKDIV_HFPERCLKDIV_MASK (0x7<<0)

/** @} */

/** Bit states for the CMU_HFRCOCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.4 for definitions.
 *
 * @defgroup EFM32TG_CMU_HFRCOCTRL_bits CMU HFRCOCTRL bits
 * @{
 */

#define CMU_HFRCOCTRL_SUDELAY_MASK (0x1f<<12)
#define CMU_HFRCOCTRL_BAND_1MHZ (0<<8)
#define CMU_HFRCOCTRL_BAND_7MHZ (1<<8)
#define CMU_HFRCOCTRL_BAND_11MHZ (2<<8)
#define CMU_HFRCOCTRL_BAND_14MHZ (3<<8)
#define CMU_HFRCOCTRL_BAND_21MHZ (4<<8)
#define CMU_HFRCOCTRL_BAND_28MHZ (5<<8)
#define CMU_HFRCOCTRL_BAND_MASK (0x7<<8)
#define CMU_HFRCOCTRL_TUNING_MASK (0xff<<0)

/** @} */

/** Bit states for the CMU_AUXHFRCOCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.6 for definitions.
 *
 * @defgroup EFM32TG_CMU_AUXHFRCOCTRL_bits CMU AUXHFRCOCTRL bits
 * @{
 */

#define CMU_AUXHFRCOCTRL_BAND_14MHZ (0<<8)
#define CMU_AUXHFRCOCTRL_BAND_11MHZ (1<<8)
#define CMU_AUXHFRCOCTRL_BAND_7MHZ (2<<8)
#define CMU_AUXHFRCOCTRL_BAND_1MHZ (3<<8)
#define CMU_AUXHFRCOCTRL_BAND_28MHZ (6<<8)
#define CMU_AUXHFRCOCTRL_BAND_21MHZ (7<<8)
#define CMU_AUXHFRCOCTRL_BAND_MASK (0x7<<8)
#define CMU_AUXHFRCOCTRL_TUNING_MASK (0xff<<0)

/** @} */

/** Bit states for the CMU_CALCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.6.7 for definitions.
 *
 * @defgroup EFM32TG_CMU_CALCTRL_bits CMU CALCTRL bits
 * @{
 */

#define CMU_CALCTRL_CONT        (1<<6)
#define CMU_CALCTRL_DOWNSEL_HFCLK (0<<3)
#define CMU_CALCTRL_DOWNSEL_HFXO (1<<3)
#define CMU_CALCTRL_DOWNSEL_LFXO (2<<3)
#define CMU_CALCTRL_DOWNSEL_HFRCO (3<<3)
#define CMU_CALCTRL_DOWNSEL_LFRCO (4<<3)
#define CMU_CALCTRL_DOWNSEL_AUXHFRCO (5<<3)
#define CMU_CALCTRL_DOWNSEL_MASK (0x7<<3)
#define CMU_CALCTRL_UPSEL_HFXO  (0<<0)
#define CMU_CALCTRL_UPSEL_LFXO  (1<<0)
#define CMU_CALCTRL_UPSEL_HFRCO (2<<0)
#define CMU_CALCTRL_UPSEL_LFRCO (3<<0)
#define CMU_CALCTRL_UPSEL_AUXHFRCO (4<<0)
#define CMU_CALCTRL_UPSEL_MASK  (0x7<<0)

/** @} */

/** Bit states for the CMU_OSCENCMD register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.9 for definitions.
 *
 * @defgroup EFM32TG_CMU_OSCENCMD_bits CMU OSCENCMD bits
 * @{
 */

#define CMU_OSCENCMD_LFXODIS    (1<<9)
#define CMU_OSCENCMD_LFXOEN     (1<<8)
#define CMU_OSCENCMD_LFRCODIS   (1<<7)
#define CMU_OSCENCMD_LFRCOEN    (1<<6)
#define CMU_OSCENCMD_AUXHFRCODIS (1<<5)
#define CMU_OSCENCMD_AUXHFRCOEN (1<<4)
#define CMU_OSCENCMD_HFXODIS    (1<<3)
#define CMU_OSCENCMD_HFXOEN     (1<<2)
#define CMU_OSCENCMD_HFRCODIS   (1<<1)
#define CMU_OSCENCMD_HFRCOEN    (1<<0)

/** @} */

/** Bit states for the CMU_CMD register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.10 for definitions.
 *
 * @defgroup EFM32TG_CMU_CMD_bits CMU CMD bits
 * @{
 */

#define CMU_CMD_CALSTOP         (1<<4)
#define CMU_CMD_CALSTART        (1<<3)
#define CMU_CMD_HFCLKSEL_HFRCO  (1<<0)
#define CMU_CMD_HFCLKSEL_HFXO   (2<<0)
#define CMU_CMD_HFCLKSEL_LFRCO  (3<<0)
#define CMU_CMD_HFCLKSEL_LFXO   (4<<0)
#define CMU_CMD_HFCLKSEL_MASK   (0x7<<0)

/** @} */

/** Bit states for the CMU_LFCLKSEL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.11 for definitions.
 *
 * @defgroup EFM32TG_CMU_LFCLKSEL_bits CMU LFCLKSEL bits
 * @{
 */

#define CMU_LFCLKSEL_LFBE_DISABLED (0<<20)
#define CMU_LFCLKSEL_LFBE_ULFRCO (1<<20)
#define CMU_LFCLKSEL_LFBE_MASK  (0x1<<20)
#define CMU_LFCLKSEL_LFAE_DISABLED (0<<16)
#define CMU_LFCLKSEL_LFAE_ULFRCO (1<<16)
#define CMU_LFCLKSEL_LFAE_MASK  (0x1<<16)
#define CMU_LFCLKSEL_LFB_DISABLED (0<<2)
#define CMU_LFCLKSEL_LFB_LFRCO  (1<<2)
#define CMU_LFCLKSEL_LFB_LFXO   (2<<2)
#define CMU_LFCLKSEL_LFB_HFCORECLKLEDIV2 (3<<2)
#define CMU_LFCLKSEL_LFB_MASK   (0x3<<2)
#define CMU_LFCLKSEL_LFA_DISABLED (0<<0)
#define CMU_LFCLKSEL_LFA_LFRCO  (1<<0)
#define CMU_LFCLKSEL_LFA_LFXO   (2<<0)
#define CMU_LFCLKSEL_LFA_HFCORECLKLEDIV2 (3<<0)
#define CMU_LFCLKSEL_LFA_MASK   (0x3<<0)

/** @} */

/** Bit states for the CMU_STATUS register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.12 for definitions.
 *
 * @defgroup EFM32TG_CMU_STATUS_bits CMU STATUS bits
 * @{
 */

#define CMU_STATUS_CALBSY       (1<<14)
#define CMU_STATUS_LFXOSEL      (1<<13)
#define CMU_STATUS_LFRCOSEL     (1<<12)
#define CMU_STATUS_HFXOSEL      (1<<11)
#define CMU_STATUS_HFRCOSEL     (1<<10)
#define CMU_STATUS_LFXORDY      (1<<9)
#define CMU_STATUS_LFXOENS      (1<<8)
#define CMU_STATUS_LFRCORDY     (1<<7)
#define CMU_STATUS_LFRCOENS     (1<<6)
#define CMU_STATUS_AUXHFRCORDY  (1<<5)
#define CMU_STATUS_AUXHFRCOENS  (1<<4)
#define CMU_STATUS_HFXORDY      (1<<3)
#define CMU_STATUS_HFXOENS      (1<<2)
#define CMU_STATUS_HFRCORDY     (1<<1)
#define CMU_STATUS_HFRCOENS     (1<<0)

/** @} */

/** Bit states for the CMU_HFCORECLKEN0 register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.17 for definitions.
 *
 * @defgroup EFM32TG_CMU_HFCORECLKEN0_bits CMU HFCORECLKEN0 bits
 * @{
 */

#define CMU_HFCORECLKEN0_LE     (1<<2)
#define CMU_HFCORECLKEN0_DMA    (1<<1)
#define CMU_HFCORECLKEN0_AES    (1<<0)

/** @} */

/** Bit states for the CMU_HFPERCLKEN0 register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.18 for definitions.
 *
 * @defgroup EFM32TG_CMU_HFPERCLKEN0_bits CMU HFPERCLKEN0 bits
 * @{
 */

#define CMU_HFPERCLKEN0_I2C0    (1<<11)
#define CMU_HFPERCLKEN0_DAC0    (1<<10)
#define CMU_HFPERCLKEN0_ADC0    (1<<9)
#define CMU_HFPERCLKEN0_PRS     (1<<8)
#define CMU_HFPERCLKEN0_VCMP    (1<<7)
#define CMU_HFPERCLKEN0_GPIO    (1<<6)
#define CMU_HFPERCLKEN0_TIMER1  (1<<5)
#define CMU_HFPERCLKEN0_TIMER0  (1<<4)
#define CMU_HFPERCLKEN0_USART1  (1<<3)
#define CMU_HFPERCLKEN0_USART0  (1<<2)
#define CMU_HFPERCLKEN0_ACMP1   (1<<1)
#define CMU_HFPERCLKEN0_ACMP0   (1<<0)

/** @} */

/** Bit states for the CMU_SYNCBUSY register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.19 for definitions.
 *
 * @defgroup EFM32TG_CMU_SYNCBUSY_bits CMU SYNCBUSY bits
 * @{
 */

#define CMU_SYNCBUSY_LFBPRESC0  (1<<6)
#define CMU_SYNCBUSY_LFBCLKEN0  (1<<4)
#define CMU_SYNCBUSY_LFAPRESC0  (1<<2)
#define CMU_SYNCBUSY_LFACLKEN0  (1<<0)

/** @} */

/** Bit states for the CMU_FREEZE register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.20 for definitions.
 *
 * @defgroup EFM32TG_CMU_FREEZE_bits CMU FREEZE bits
 * @{
 */

#define CMU_FREEZE_REGFREEZE_UPDATE (0<<0)
#define CMU_FREEZE_REGFREEZE_FREEZE (1<<0)
#define CMU_FREEZE_REGFREEZE_MASK (0x1<<0)

/** @} */

/** Bit states for the CMU_LFACLKEN0 register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.21 for definitions.
 *
 * @defgroup EFM32TG_CMU_LFACLKEN0_bits CMU LFACLKEN0 bits
 * @{
 */

#define CMU_LFACLKEN0_LCD       (1<<3)
#define CMU_LFACLKEN0_LETIMER0  (1<<2)
#define CMU_LFACLKEN0_RTC       (1<<1)
#define CMU_LFACLKEN0_LESENSE   (1<<0)

/** @} */

/** Bit states for the CMU_LFBCLKEN0 register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.22 for definitions.
 *
 * @defgroup EFM32TG_CMU_LFBCLKEN0_bits CMU LFBCLKEN0 bits
 * @{
 */

#define CMU_LFBCLKEN0_LEUART0   (1<<0)

/** @} */

/** Bit states for the CMU_LFAPRESC0 register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.23 for definitions.
 *
 * @defgroup EFM32TG_CMU_LFAPRESC0_bits CMU LFAPRESC0 bits
 * @{
 */

#define CMU_LFAPRESC0_LCD_DIV16 (0<<12)
#define CMU_LFAPRESC0_LCD_DIV32 (1<<12)
#define CMU_LFAPRESC0_LCD_DIV64 (2<<12)
#define CMU_LFAPRESC0_LCD_DIV128 (3<<12)
#define CMU_LFAPRESC0_LCD_MASK  (0x3<<12)
#define CMU_LFAPRESC0_LETIMER0_DIV1 (0<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV2 (1<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV4 (2<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV8 (3<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV16 (4<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV32 (5<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV64 (6<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV128 (7<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV256 (8<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV512 (9<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV1024 (10<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV2048 (11<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV4096 (12<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV8192 (13<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV16384 (14<<8)
#define CMU_LFAPRESC0_LETIMER0_DIV32768 (15<<8)
#define CMU_LFAPRESC0_LETIMER0_MASK (0xf<<8)
#define CMU_LFAPRESC0_RTC_DIV1  (0<<4)
#define CMU_LFAPRESC0_RTC_DIV2  (1<<4)
#define CMU_LFAPRESC0_RTC_DIV4  (2<<4)
#define CMU_LFAPRESC0_RTC_DIV8  (3<<4)
#define CMU_LFAPRESC0_RTC_DIV16 (4<<4)
#define CMU_LFAPRESC0_RTC_DIV32 (5<<4)
#define CMU_LFAPRESC0_RTC_DIV64 (6<<4)
#define CMU_LFAPRESC0_RTC_DIV128 (7<<4)
#define CMU_LFAPRESC0_RTC_DIV256 (8<<4)
#define CMU_LFAPRESC0_RTC_DIV512 (9<<4)
#define CMU_LFAPRESC0_RTC_DIV1024 (10<<4)
#define CMU_LFAPRESC0_RTC_DIV2048 (11<<4)
#define CMU_LFAPRESC0_RTC_DIV4096 (12<<4)
#define CMU_LFAPRESC0_RTC_DIV8192 (13<<4)
#define CMU_LFAPRESC0_RTC_DIV16384 (14<<4)
#define CMU_LFAPRESC0_RTC_DIV32768 (15<<4)
#define CMU_LFAPRESC0_RTC_MASK  (0xf<<4)
#define CMU_LFAPRESC0_LESENSE_DIV1 (0<<0)
#define CMU_LFAPRESC0_LESENSE_DIV2 (1<<0)
#define CMU_LFAPRESC0_LESENSE_DIV4 (2<<0)
#define CMU_LFAPRESC0_LESENSE_DIV8 (3<<0)
#define CMU_LFAPRESC0_LESENSE_MASK (0x3<<0)

/** @} */

/** Bit states for the CMU_LFBPRESC0 register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.24 for definitions.
 *
 * @defgroup EFM32TG_CMU_LFBPRESC0_bits CMU LFBPRESC0 bits
 * @{
 */

#define CMU_LFBPRESC0_LEUART0_DIV1 (0<<0)
#define CMU_LFBPRESC0_LEUART0_DIV2 (1<<0)
#define CMU_LFBPRESC0_LEUART0_DIV4 (2<<0)
#define CMU_LFBPRESC0_LEUART0_DIV8 (3<<0)
#define CMU_LFBPRESC0_LEUART0_MASK (0x3<<0)

/** @} */

/** Bit states for the CMU_PCNTCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.25 for definitions.
 *
 * @defgroup EFM32TG_CMU_PCNTCTRL_bits CMU PCNTCTRL bits
 * @{
 */

#define CMU_PCNTCTRL_PCNT0CLKSEL_LFACLK (0<<1)
#define CMU_PCNTCTRL_PCNT0CLKSEL_PCNT0S0 (1<<1)
#define CMU_PCNTCTRL_PCNT0CLKSEL_MASK (0x1<<1)
#define CMU_PCNTCTRL_PCNT0CLKEN (1<<0)

/** @} */

/** Bit states for the CMU_LCDCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.26 for definitions.
 *
 * @defgroup EFM32TG_CMU_LCDCTRL_bits CMU LCDCTRL bits
 * @{
 */

#define CMU_LCDCTRL_VBFDIV_DIV1 (0<<4)
#define CMU_LCDCTRL_VBFDIV_DIV2 (1<<4)
#define CMU_LCDCTRL_VBFDIV_DIV4 (2<<4)
#define CMU_LCDCTRL_VBFDIV_DIV8 (3<<4)
#define CMU_LCDCTRL_VBFDIV_DIV16 (4<<4)
#define CMU_LCDCTRL_VBFDIV_DIV32 (5<<4)
#define CMU_LCDCTRL_VBFDIV_DIV64 (6<<4)
#define CMU_LCDCTRL_VBFDIV_DIV128 (7<<4)
#define CMU_LCDCTRL_VBFDIV_MASK (0x7<<4)
#define CMU_LCDCTRL_VBOOSTEN    (1<<3)
#define CMU_LCDCTRL_FDIV_MASK   (0x7<<0)

/** @} */

/** Bit states for the CMU_ROUTE register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.27 for definitions.
 *
 * @defgroup EFM32TG_CMU_ROUTE_bits CMU ROUTE bits
 * @{
 */

#define CMU_ROUTE_LOCATION_LOC0 (0<<4)
#define CMU_ROUTE_LOCATION_LOC1 (1<<4)
#define CMU_ROUTE_LOCATION_MASK (0x7<<4)
#define CMU_ROUTE_CLKOUT1PEN    (1<<1)
#define CMU_ROUTE_CLKOUT0PEN    (1<<0)

/** @} */

/** Values for the CMU_LOCK register
 *
 * See d0034_efm32tg_reference_manual.pdf section 11.5.28 for definitions.
 *
 * @defgroup EFM32TG_CMU_LOCK_values CMU LOCK values
 * @{
 */

#define CMU_LOCK_IS_UNLOCKED    0
#define CMU_LOCK_IS_LOCKED      1
#define CMU_LOCK_SET_LOCKED     0
#define CMU_LOCK_SET_UNLOCKED   0x580E

/** @} */

/** Bit states for the CMU "I" group of registers (IF, IFS, IFC, IEN)
 *
 * These registers use this:
 *
 * <ul>
 *
 * <li>The CMU_IF register; see d0034_efm32tg_reference_manual.pdf section
 * 11.5.13 for definitions.</li>
 *
 * <li>The CMU_IFS register; see d0034_efm32tg_reference_manual.pdf section
 * 11.5.14 for definitions.</li>
 *
 * <li>The CMU_IFC register; see d0034_efm32tg_reference_manual.pdf section
 * 11.5.15 for definitions.</li>
 *
 * <li>The CMU_IEN register; see d0034_efm32tg_reference_manual.pdf section
 * 11.5.16 for definitions.</li>
 *
 * </ul>
 *
 * @defgroup EFM32TG_CMU_I_bits CMU I bits group
 * @{
 */

#define CMU_I_CALOF             (1<<6)
#define CMU_I_CALRDY            (1<<5)
#define CMU_I_AUXHFRCORDY       (1<<4)
#define CMU_I_LFXORDY           (1<<3)
#define CMU_I_LFRCORDY          (1<<2)
#define CMU_I_HFXORDY           (1<<1)
#define CMU_I_HFRCORDY          (1<<0)

/** @} */

/** @} */

/** CMU convenience functions
 *
 * These functions assist in clock switching, and are intended to be safer to
 * use than direct fiddling with registers. They try to be suitable for typical
 * applications, and will invest some bytes of code in order to minimize power
 * consumption.
 *
 * @todo Work on this module is stalled until I can figure out if there is a
 * way to have a cmu_shutdown_unused function at all.
 *
 * @defgroup EFM32TG_CMU_convenience CMU convenience functions
 * @{
 */

/** Disable all oscillators not currently in use.
 *
 * The implementation follows d0034_efm32tg_reference_manual.pdf figure 11.1.
 * The clock out pin configurations are not depicted there, but described in
 * section 11.3.4.
 *
 * @todo This function is ignorant of ongoing calibrations.
 *
 * @todo This doesn't work at all: Fields like HFCLKSEL are write-only.
 * */
static void cmu_shutdown_unused(void)
{
	/* Is HFXO needed? */
	if (!(
	    (CMU_CMD & CMU_CMD_HFCLKSEL_MASK) == CMU_CMD_HFCLKSEL_HFXO ||
	    (
	        (CMU_CTRL & CMU_CTRL_CLKOUTSEL1_MASK) == CMU_CTRL_CLKOUTSEL1_HFXOQ &&
		(CMU_ROUTE & CMU_ROUTE_CLKOUT1PEN)
	    ) || (
	        (CMU_CTRL & CMU_CTRL_CLKOUTSEL0_MASK) == CMU_CTRL_CLKOUTSEL0_HFXO &&
		(CMU_ROUTE & CMU_ROUTE_CLKOUT0PEN)
	    )))
		CMU_OSCENCMD = CMU_OSCENCMD_HFXODIS;

	/* Is HFRCO neede? */
	if (!(
	    (CMU_CMD & CMU_CMD_HFCLKSEL_MASK) == CMU_CMD_HFCLKSEL_HFRCO ||
	    (
	        (CMU_CTRL & CMU_CTRL_CLKOUTSEL1_MASK) == CMU_CTRL_CLKOUTSEL1_HFRCOQ &&
		(CMU_ROUTE & CMU_ROUTE_CLKOUT1PEN)
	    ) || (
	        (CMU_CTRL & CMU_CTRL_CLKOUTSEL0_MASK) == CMU_CTRL_CLKOUTSEL0_HFRCO &&
		(CMU_ROUTE & CMU_ROUTE_CLKOUT0PEN)
	    )))
	{}
//		CMU_OSCENCMD = CMU_OSCENCMD_HFRCODIS;
}

/** Switch HFCLK to LFRC. This call is not only blocking, but even freezes
 * everything depending on HFCLK until LFRC is stable. The procedure is
 * sketched in d0034_efm32tg_reference_manual.pdf figure 11.2. */
static void cmu_hfclk_switch_blocking(void)
{
	CMU_OSCENCMD = CMU_OSCENCMD_LFRCOEN;
	CMU_CMD = CMU_CMD_HFCLKSEL_LFRCO;
	CMU_OSCENCMD = CMU_OSCENCMD_HFRCODIS;
}

/** @} */

/** @} */

#endif
