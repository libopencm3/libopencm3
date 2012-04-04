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
 * @see EFM32TG_LCD
 */

/** Definitions for the LCD subsystem (Liquid Crystal Display driver).
 *
 * This corresponds to the description in d0034_efm32tg_reference_manual.pdf
 * section 29.
 *
 * @ingroup EFM32TG
 * @defgroup EFM32TG_LCD LCD (Liquid Crystal Display driver)
 * @{
 */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_LCD_H
#define LIBOPENCM3_EFM32_TINYGECKO_LCD_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>

/** Register definitions and register value definitions for the LCD subsystem
 *
 * @defgroup EFM32TG_LCD_regsandvals LCD registers and values
 * @{
 */

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 29.4
 *
 * @defgroup EFM32TG_LCD_registers LCD registers
 * @{
 */

#define LCD_CTRL                MMIO32(LCD_BASE + 0x000) /**< @see EFM32TG_LCD_CTRL_bits */
#define LCD_DISPCTRL            MMIO32(LCD_BASE + 0x004) /**< @see EFM32TG_LCD_DISPCTRL_bits */
#define LCD_SEGEN               MMIO32(LCD_BASE + 0x008)
#define LCD_BACTRL              MMIO32(LCD_BASE + 0x00c) /**< @see EFM32TG_LCD_BACTRL_bits */
#define LCD_STATUS              MMIO32(LCD_BASE + 0x010) /**< @see EFM32TG_LCD_STATUS_bits */
#define LCD_AREGA               MMIO32(LCD_BASE + 0x014)
#define LCD_AREGB               MMIO32(LCD_BASE + 0x018)
#define LCD_IF                  MMIO32(LCD_BASE + 0x01c) /**< @see EFM32TG_LCD_I_bits */
#define LCD_IFS                 MMIO32(LCD_BASE + 0x020) /**< @see EFM32TG_LCD_I_bits */
#define LCD_IFC                 MMIO32(LCD_BASE + 0x024) /**< @see EFM32TG_LCD_I_bits */
#define LCD_IEN                 MMIO32(LCD_BASE + 0x028) /**< @see EFM32TG_LCD_I_bits */
#define LCD_SEGD0L              MMIO32(LCD_BASE + 0x040) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_SEGD1L              MMIO32(LCD_BASE + 0x044) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_SEGD2L              MMIO32(LCD_BASE + 0x048) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_SEGD3L              MMIO32(LCD_BASE + 0x04c) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_FREEZE              MMIO32(LCD_BASE + 0x060) /**< @see EFM32TG_LCD_FREEZE_bits */
#define LCD_SYNCBUSY            MMIO32(LCD_BASE + 0x064) /**< @see EFM32TG_LCD_SYNCBUSY_bits */
#define LCD_SEGD4L              MMIO32(LCD_BASE + 0x0cc) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_SEGD5L              MMIO32(LCD_BASE + 0x0d0) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_SEGD6L              MMIO32(LCD_BASE + 0x0d4) /**< @see EFM32TG_LCD_SEG_bits */
#define LCD_SEGD7L              MMIO32(LCD_BASE + 0x0d8) /**< @see EFM32TG_LCD_SEG_bits */

/** @} */

/** Bit states for the LCD_CTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 29.5.1 for definitions.
 *
 * @defgroup EFM32TG_LCD_CTRL_bits LCD CTRL bits
 * @{
 */

#define LCD_CTRL_DSC            (1<<23)
#define LCD_CTRL_UDCTRL_REGULAR (0<<1)
#define LCD_CTRL_UDCTRL_FCEVENT (1<<1)
#define LCD_CTRL_UDCTRL_FRAMESTART (2<<1)
#define LCD_CTRL_UDCTRL_MASK    (0x3<<1)
#define LCD_CTRL_EN             (1<<0)

/** @} */

/** Bit states for the LCD_DISPCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 29.5.2 for definitions.
 *
 * @defgroup EFM32TG_LCD_DISPCTRL_bits LCD DISPCTRL bits
 * @{
 */

#define LCD_DISPCTRL_VBLEV_LEVEL0 (0<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL1 (1<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL2 (2<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL3 (3<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL4 (4<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL5 (5<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL6 (6<<18)
#define LCD_DISPCTRL_VBLEV_LEVEL7 (7<<18)
#define LCD_DISPCTRL_VBLEV_MASK (0x7<<18)
#define LCD_DISPCTRL_VLCDSEL_VDD (0<<16)
#define LCD_DISPCTRL_VLCDSEL_VEXTBOOST (1<<16)
#define LCD_DISPCTRL_VLCDSEL_MASK (0x1<<16)
#define LCD_DISPCTRL_CONCONF_VLCD (0<<15)
#define LCD_DISPCTRL_CONCONF_GND (1<<15)
#define LCD_DISPCTRL_CONCONF_MASK (0x1<<15)
/** By this parameter, the voltage V_LCD_OUT is interpolated linearly from
 * 0.5V_LCD to V_LCD.
 */
#define LCD_DISPCTRL_CONLEV_MIN (0<<8)
#define LCD_DISPCTRL_CONLEV_MAX (31<<8)
#define LCD_DISPCTRL_CONLEV_MASK (0x1f<<8)
#define LCD_DISPCTRL_WAVE_LOWPOWER (0<<4)
#define LCD_DISPCTRL_WAVE_NORMAL (1<<4)
#define LCD_DISPCTRL_WAVE_MASK  (0x1<<4)
#define LCD_DISPCTRL_BIAS_STATIC (0<<2)
#define LCD_DISPCTRL_BIAS_ONEHALF (1<<2)
#define LCD_DISPCTRL_BIAS_ONETHIRD (2<<2)
#define LCD_DISPCTRL_BIAS_ONEFOURTH (3<<2)
#define LCD_DISPCTRL_BIAS_MASK  (0x3<<2)
/** These definitions munge the MUX and the MUXE fields, as they are described
 * in the documentation only together too.
 */
#define LCD_DISPCTRL_MUX_STATIC 0x00000000
#define LCD_DISPCTRL_MUX_DUPLEX 0x00000001
#define LCD_DISPCTRL_MUX_TRIPLEX 0x00000002
#define LCD_DISPCTRL_MUX_QUADRUPLEX 0x00000003
#define LCD_DISPCTRL_MUX_SEXTAPLEX 0x00400001
#define LCD_DISPCTRL_MUX_OCTAPLEX 0x00400003
#define LCD_DISPCTRL_MUX_MASK   0x00400003

/** @} */

/** Bit states for the LCD_BACTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 29.5.4 for definitions.
 *
 * @defgroup EFM32TG_LCD_BACTRL_bits LCD BACTRL bits
 * @{
 */

#define LCD_BACTRL_FCTOP_MASK   (0x3f<<18)
#define LCD_BACTRL_FCPRESC_DIV1 (0<<16)
#define LCD_BACTRL_FCPRESC_DIV2 (1<<16)
#define LCD_BACTRL_FCPRESC_DIV4 (2<<16)
#define LCD_BACTRL_FCPRESC_DIV8 (3<<16)
#define LCD_BACTRL_FCPRESC_MASK (0x3<<16)
#define LCD_BACTRL_FCEN         (1<<8)
#define LCD_BACTRL_ALGOSEL_AND  (0<<7)
#define LCD_BACTRL_ALGOSEL_OR   (1<<7)
#define LCD_BACTRL_ALGOSEL_MASK (0x1<<7)
#define LCD_BACTRL_AREGBSC_NOSHIFT (0<<5)
#define LCD_BACTRL_AREGBSC_SHIFTLEFT (1<<5)
#define LCD_BACTRL_AREGBSC_SHIFTRIGHT (2<<5)
#define LCD_BACTRL_AREGBSC_MASK (0x3<<5)
#define LCD_BACTRL_AREGASC_NOSHIFT (0<<3)
#define LCD_BACTRL_AREGASC_SHIFTLEFT (1<<3)
#define LCD_BACTRL_AREGASC_SHIFTRIGHT (2<<3)
#define LCD_BACTRL_AREGASC_MASK (0x3<<3)
#define LCD_BACTRL_AEN          (1<<2)
#define LCD_BACTRL_BLANK        (1<<1)
#define LCD_BACTRL_BLINKEN      (1<<0)

/** @} */

/** Bit states for the LCD_STATUS register
 *
 * See d0034_efm32tg_reference_manual.pdf section 29.5.5 for definitions.
 *
 * @defgroup EFM32TG_LCD_STATUS_bits LCD STATUS bits
 * @{
 */

#define LCD_STATUS_BLINK        (1<<8)
#define LCD_STATUS_ASTATE_MASK  (0xf<<0)

/** @} */

/** Bit states for the LCD_FREEZE register
 *
 * See d0034_efm32tg_reference_manual.pdf section 29.5.16 for definitions.
 *
 * @defgroup EFM32TG_LCD_FREEZE_bits LCD FREEZE bits
 * @{
 */

#define LCD_FREEZE_REGFREEZE_UPDATE (0<<0)
#define LCD_FREEZE_REGFREEZE_FREEZE (1<<0)
#define LCD_FREEZE_REGFREEZE_MASK (0x1<<0)

/** @} */

/** Bit states for the LCD_SYNCBUSY register
 *
 * See d0034_efm32tg_reference_manual.pdf section 29.5.17 for definitions.
 *
 * @defgroup EFM32TG_LCD_SYNCBUSY_bits LCD SYNCBUSY bits
 * @{
 */

#define LCD_SYNCBUSY_SEGD7L     (1<<19)
#define LCD_SYNCBUSY_SEGD6L     (1<<18)
#define LCD_SYNCBUSY_SEGD5L     (1<<17)
#define LCD_SYNCBUSY_SEGD4L     (1<<16)
#define LCD_SYNCBUSY_SEGD3L     (1<<7)
#define LCD_SYNCBUSY_SEGD2L     (1<<6)
#define LCD_SYNCBUSY_SEGD1L     (1<<5)
#define LCD_SYNCBUSY_SEGD0L     (1<<4)
#define LCD_SYNCBUSY_AREGB      (1<<3)
#define LCD_SYNCBUSY_AREGA      (1<<2)
#define LCD_SYNCBUSY_BACTRL     (1<<1)
#define LCD_SYNCBUSY_CTRL       (1<<0)

/** @} */

/** Bit states for the LCD "I" group of registers (IF, IFS, IFC, IEN)
 *
 * These registers use this:
 *
 * <ul>
 *
 * <li>The LCD_IF register; see d0034_efm32tg_reference_manual.pdf section
 * 29.5.8 for definitions.</li>
 *
 * <li>The LCD_IFS register; see d0034_efm32tg_reference_manual.pdf section
 * 29.5.9 for definitions.</li>
 *
 * <li>The LCD_IFC register; see d0034_efm32tg_reference_manual.pdf section
 * 29.5.10 for definitions.</li>
 *
 * <li>The LCD_IEN register; see d0034_efm32tg_reference_manual.pdf section
 * 29.5.11 for definitions.</li>
 *
 * </ul>
 *
 * @defgroup EFM32TG_LCD_I_bits LCD I bits group
 * @{
 */

#define LCD_I_FC                (1<<0)

/** @} */

/** Bit states for the LCD "SEG" group of registers (SEGD0L, SEGD1L, SEGD2L,
 * SEGD3L, SEGD4L, SEGD5L, SEGD6L, SEGD7L)
 *
 * These values are used by the SEGDxL registers, as defined in
 * d0034_efm32tg_reference_manual.pdf sections 29.5.12 to .15 and .18 to .21.
 *
 * @defgroup EFM32TG_LCD_SEG_bits LCD SEG bits group
 * @{
 */

#define LCD_SEG_23              (1<<23)
#define LCD_SEG_22              (1<<22)
#define LCD_SEG_21              (1<<21)
#define LCD_SEG_20              (1<<20)
#define LCD_SEG_19              (1<<19)
#define LCD_SEG_18              (1<<18)
#define LCD_SEG_17              (1<<17)
#define LCD_SEG_16              (1<<16)
#define LCD_SEG_15              (1<<15)
#define LCD_SEG_14              (1<<14)
#define LCD_SEG_13              (1<<13)
#define LCD_SEG_12              (1<<12)
#define LCD_SEG_11              (1<<11)
#define LCD_SEG_10              (1<<10)
#define LCD_SEG_9               (1<<9)
#define LCD_SEG_8               (1<<8)
#define LCD_SEG_7               (1<<7)
#define LCD_SEG_6               (1<<6)
#define LCD_SEG_5               (1<<5)
#define LCD_SEG_4               (1<<4)
#define LCD_SEG_3               (1<<3)
#define LCD_SEG_2               (1<<2)
#define LCD_SEG_1               (1<<1)
#define LCD_SEG_0               (1<<0)

/** @} */

/** @} */


/** @} */

#endif
