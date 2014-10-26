/** @defgroup sgpio_defines Serial General Purpose I/O

@brief <b>Defined Constants and Types for the LPC43xx Serial General Purpose
I/O</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/** @defgroup sdio_defines SDIO

@brief <b>Defined Constants and Types for the LPC43xx SDIO</b>

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
 * Copyright (C) 2012 Jared Boone <jared@sharebrained.com>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#ifndef LPC43XX_SGPIO_H
#define LPC43XX_SGPIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- SGPIO registers ----------------------------------------------------- */

/* Pin multiplexer configuration registers (OUT_MUX_CFG0 to 15) */
#define SGPIO_OUT_MUX_CFG(pin)          MMIO32(SGPIO_PORT_BASE + (pin * 0x04))
#define SGPIO_OUT_MUX_CFG0              MMIO32(SGPIO_PORT_BASE + 0x00)
#define SGPIO_OUT_MUX_CFG1              MMIO32(SGPIO_PORT_BASE + 0x04)
#define SGPIO_OUT_MUX_CFG2              MMIO32(SGPIO_PORT_BASE + 0x08)
#define SGPIO_OUT_MUX_CFG3              MMIO32(SGPIO_PORT_BASE + 0x0C)
#define SGPIO_OUT_MUX_CFG4              MMIO32(SGPIO_PORT_BASE + 0x10)
#define SGPIO_OUT_MUX_CFG5              MMIO32(SGPIO_PORT_BASE + 0x14)
#define SGPIO_OUT_MUX_CFG6              MMIO32(SGPIO_PORT_BASE + 0x18)
#define SGPIO_OUT_MUX_CFG7              MMIO32(SGPIO_PORT_BASE + 0x1C)
#define SGPIO_OUT_MUX_CFG8              MMIO32(SGPIO_PORT_BASE + 0x20)
#define SGPIO_OUT_MUX_CFG9              MMIO32(SGPIO_PORT_BASE + 0x24)
#define SGPIO_OUT_MUX_CFG10             MMIO32(SGPIO_PORT_BASE + 0x28)
#define SGPIO_OUT_MUX_CFG11             MMIO32(SGPIO_PORT_BASE + 0x2C)
#define SGPIO_OUT_MUX_CFG12             MMIO32(SGPIO_PORT_BASE + 0x30)
#define SGPIO_OUT_MUX_CFG13             MMIO32(SGPIO_PORT_BASE + 0x34)
#define SGPIO_OUT_MUX_CFG14             MMIO32(SGPIO_PORT_BASE + 0x38)
#define SGPIO_OUT_MUX_CFG15             MMIO32(SGPIO_PORT_BASE + 0x3C)

/* SGPIO multiplexer configuration registers (SGPIO_MUX_CFG0 to 15) */
#define SGPIO_MUX_CFG(slice)            MMIO32(SGPIO_PORT_BASE + 0x40 + \
						(slice * 0x04))
#define SGPIO_MUX_CFG0                  MMIO32(SGPIO_PORT_BASE + 0x40)
#define SGPIO_MUX_CFG1                  MMIO32(SGPIO_PORT_BASE + 0x44)
#define SGPIO_MUX_CFG2                  MMIO32(SGPIO_PORT_BASE + 0x48)
#define SGPIO_MUX_CFG3                  MMIO32(SGPIO_PORT_BASE + 0x4C)
#define SGPIO_MUX_CFG4                  MMIO32(SGPIO_PORT_BASE + 0x50)
#define SGPIO_MUX_CFG5                  MMIO32(SGPIO_PORT_BASE + 0x54)
#define SGPIO_MUX_CFG6                  MMIO32(SGPIO_PORT_BASE + 0x58)
#define SGPIO_MUX_CFG7                  MMIO32(SGPIO_PORT_BASE + 0x5C)
#define SGPIO_MUX_CFG8                  MMIO32(SGPIO_PORT_BASE + 0x60)
#define SGPIO_MUX_CFG9                  MMIO32(SGPIO_PORT_BASE + 0x64)
#define SGPIO_MUX_CFG10                 MMIO32(SGPIO_PORT_BASE + 0x68)
#define SGPIO_MUX_CFG11                 MMIO32(SGPIO_PORT_BASE + 0x6C)
#define SGPIO_MUX_CFG12                 MMIO32(SGPIO_PORT_BASE + 0x70)
#define SGPIO_MUX_CFG13                 MMIO32(SGPIO_PORT_BASE + 0x74)
#define SGPIO_MUX_CFG14                 MMIO32(SGPIO_PORT_BASE + 0x78)
#define SGPIO_MUX_CFG15                 MMIO32(SGPIO_PORT_BASE + 0x7C)

/* Slice multiplexer configuration registers (SLICE_MUX_CFG0 to 15) */
#define SGPIO_SLICE_MUX_CFG(slice)      MMIO32(SGPIO_PORT_BASE + 0x80 + \
						(slice * 0x04))
#define SGPIO_SLICE_MUX_CFG0            MMIO32(SGPIO_PORT_BASE + 0x80)
#define SGPIO_SLICE_MUX_CFG1            MMIO32(SGPIO_PORT_BASE + 0x84)
#define SGPIO_SLICE_MUX_CFG2            MMIO32(SGPIO_PORT_BASE + 0x88)
#define SGPIO_SLICE_MUX_CFG3            MMIO32(SGPIO_PORT_BASE + 0x8C)
#define SGPIO_SLICE_MUX_CFG4            MMIO32(SGPIO_PORT_BASE + 0x90)
#define SGPIO_SLICE_MUX_CFG5            MMIO32(SGPIO_PORT_BASE + 0x94)
#define SGPIO_SLICE_MUX_CFG6            MMIO32(SGPIO_PORT_BASE + 0x98)
#define SGPIO_SLICE_MUX_CFG7            MMIO32(SGPIO_PORT_BASE + 0x9C)
#define SGPIO_SLICE_MUX_CFG8            MMIO32(SGPIO_PORT_BASE + 0xA0)
#define SGPIO_SLICE_MUX_CFG9            MMIO32(SGPIO_PORT_BASE + 0xA4)
#define SGPIO_SLICE_MUX_CFG10           MMIO32(SGPIO_PORT_BASE + 0xA8)
#define SGPIO_SLICE_MUX_CFG11           MMIO32(SGPIO_PORT_BASE + 0xAC)
#define SGPIO_SLICE_MUX_CFG12           MMIO32(SGPIO_PORT_BASE + 0xB0)
#define SGPIO_SLICE_MUX_CFG13           MMIO32(SGPIO_PORT_BASE + 0xB4)
#define SGPIO_SLICE_MUX_CFG14           MMIO32(SGPIO_PORT_BASE + 0xB8)
#define SGPIO_SLICE_MUX_CFG15           MMIO32(SGPIO_PORT_BASE + 0xBC)

/* Slice data registers (REG0 to 15) */
#define SGPIO_REG(slice)                MMIO32(SGPIO_PORT_BASE + 0xC0 + \
						(slice * 0x04))
#define SGPIO_REG0                      MMIO32(SGPIO_PORT_BASE + 0xC0)
#define SGPIO_REG1                      MMIO32(SGPIO_PORT_BASE + 0xC4)
#define SGPIO_REG2                      MMIO32(SGPIO_PORT_BASE + 0xC8)
#define SGPIO_REG3                      MMIO32(SGPIO_PORT_BASE + 0xCC)
#define SGPIO_REG4                      MMIO32(SGPIO_PORT_BASE + 0xD0)
#define SGPIO_REG5                      MMIO32(SGPIO_PORT_BASE + 0xD4)
#define SGPIO_REG6                      MMIO32(SGPIO_PORT_BASE + 0xD8)
#define SGPIO_REG7                      MMIO32(SGPIO_PORT_BASE + 0xDC)
#define SGPIO_REG8                      MMIO32(SGPIO_PORT_BASE + 0xE0)
#define SGPIO_REG9                      MMIO32(SGPIO_PORT_BASE + 0xE4)
#define SGPIO_REG10                     MMIO32(SGPIO_PORT_BASE + 0xE8)
#define SGPIO_REG11                     MMIO32(SGPIO_PORT_BASE + 0xEC)
#define SGPIO_REG12                     MMIO32(SGPIO_PORT_BASE + 0xF0)
#define SGPIO_REG13                     MMIO32(SGPIO_PORT_BASE + 0xF4)
#define SGPIO_REG14                     MMIO32(SGPIO_PORT_BASE + 0xF8)
#define SGPIO_REG15                     MMIO32(SGPIO_PORT_BASE + 0xFC)

/* Slice data shadow registers (REG_SS0 to 15) */
#define SGPIO_REG_SS(slice)             MMIO32(SGPIO_PORT_BASE + 0x100 + \
						(slice * 0x04))
#define SGPIO_REG_SS0                   MMIO32(SGPIO_PORT_BASE + 0x100)
#define SGPIO_REG_SS1                   MMIO32(SGPIO_PORT_BASE + 0x104)
#define SGPIO_REG_SS2                   MMIO32(SGPIO_PORT_BASE + 0x108)
#define SGPIO_REG_SS3                   MMIO32(SGPIO_PORT_BASE + 0x10C)
#define SGPIO_REG_SS4                   MMIO32(SGPIO_PORT_BASE + 0x110)
#define SGPIO_REG_SS5                   MMIO32(SGPIO_PORT_BASE + 0x114)
#define SGPIO_REG_SS6                   MMIO32(SGPIO_PORT_BASE + 0x118)
#define SGPIO_REG_SS7                   MMIO32(SGPIO_PORT_BASE + 0x11C)
#define SGPIO_REG_SS8                   MMIO32(SGPIO_PORT_BASE + 0x120)
#define SGPIO_REG_SS9                   MMIO32(SGPIO_PORT_BASE + 0x124)
#define SGPIO_REG_SS10                  MMIO32(SGPIO_PORT_BASE + 0x128)
#define SGPIO_REG_SS11                  MMIO32(SGPIO_PORT_BASE + 0x12C)
#define SGPIO_REG_SS12                  MMIO32(SGPIO_PORT_BASE + 0x130)
#define SGPIO_REG_SS13                  MMIO32(SGPIO_PORT_BASE + 0x134)
#define SGPIO_REG_SS14                  MMIO32(SGPIO_PORT_BASE + 0x138)
#define SGPIO_REG_SS15                  MMIO32(SGPIO_PORT_BASE + 0x13C)

/* Reload registers (PRESET0 to 15) */
#define SGPIO_PRESET(slice)             MMIO32(SGPIO_PORT_BASE + 0x140 + \
						(slice * 0x04))
#define SGPIO_PRESET0                   MMIO32(SGPIO_PORT_BASE + 0x140)
#define SGPIO_PRESET1                   MMIO32(SGPIO_PORT_BASE + 0x144)
#define SGPIO_PRESET2                   MMIO32(SGPIO_PORT_BASE + 0x148)
#define SGPIO_PRESET3                   MMIO32(SGPIO_PORT_BASE + 0x14C)
#define SGPIO_PRESET4                   MMIO32(SGPIO_PORT_BASE + 0x150)
#define SGPIO_PRESET5                   MMIO32(SGPIO_PORT_BASE + 0x154)
#define SGPIO_PRESET6                   MMIO32(SGPIO_PORT_BASE + 0x158)
#define SGPIO_PRESET7                   MMIO32(SGPIO_PORT_BASE + 0x15C)
#define SGPIO_PRESET8                   MMIO32(SGPIO_PORT_BASE + 0x160)
#define SGPIO_PRESET9                   MMIO32(SGPIO_PORT_BASE + 0x164)
#define SGPIO_PRESET10                  MMIO32(SGPIO_PORT_BASE + 0x168)
#define SGPIO_PRESET11                  MMIO32(SGPIO_PORT_BASE + 0x16C)
#define SGPIO_PRESET12                  MMIO32(SGPIO_PORT_BASE + 0x170)
#define SGPIO_PRESET13                  MMIO32(SGPIO_PORT_BASE + 0x174)
#define SGPIO_PRESET14                  MMIO32(SGPIO_PORT_BASE + 0x178)
#define SGPIO_PRESET15                  MMIO32(SGPIO_PORT_BASE + 0x17C)

/* Down counter registers (COUNT0 to 15) */
#define SGPIO_COUNT(slice)              MMIO32(SGPIO_PORT_BASE + 0x180 + \
						(slice * 0x04))
#define SGPIO_COUNT0                    MMIO32(SGPIO_PORT_BASE + 0x180)
#define SGPIO_COUNT1                    MMIO32(SGPIO_PORT_BASE + 0x184)
#define SGPIO_COUNT2                    MMIO32(SGPIO_PORT_BASE + 0x188)
#define SGPIO_COUNT3                    MMIO32(SGPIO_PORT_BASE + 0x18C)
#define SGPIO_COUNT4                    MMIO32(SGPIO_PORT_BASE + 0x190)
#define SGPIO_COUNT5                    MMIO32(SGPIO_PORT_BASE + 0x194)
#define SGPIO_COUNT6                    MMIO32(SGPIO_PORT_BASE + 0x198)
#define SGPIO_COUNT7                    MMIO32(SGPIO_PORT_BASE + 0x19C)
#define SGPIO_COUNT8                    MMIO32(SGPIO_PORT_BASE + 0x1A0)
#define SGPIO_COUNT9                    MMIO32(SGPIO_PORT_BASE + 0x1A4)
#define SGPIO_COUNT10                   MMIO32(SGPIO_PORT_BASE + 0x1A8)
#define SGPIO_COUNT11                   MMIO32(SGPIO_PORT_BASE + 0x1AC)
#define SGPIO_COUNT12                   MMIO32(SGPIO_PORT_BASE + 0x1B0)
#define SGPIO_COUNT13                   MMIO32(SGPIO_PORT_BASE + 0x1B4)
#define SGPIO_COUNT14                   MMIO32(SGPIO_PORT_BASE + 0x1B8)
#define SGPIO_COUNT15                   MMIO32(SGPIO_PORT_BASE + 0x1BC)

/* Position registers (POS0 to 15) */
#define SGPIO_POS(slice)                MMIO32(SGPIO_PORT_BASE + 0x1C0 + \
						(slice * 0x04))
#define SGPIO_POS0                      MMIO32(SGPIO_PORT_BASE + 0x1C0)
#define SGPIO_POS1                      MMIO32(SGPIO_PORT_BASE + 0x1C4)
#define SGPIO_POS2                      MMIO32(SGPIO_PORT_BASE + 0x1C8)
#define SGPIO_POS3                      MMIO32(SGPIO_PORT_BASE + 0x1CC)
#define SGPIO_POS4                      MMIO32(SGPIO_PORT_BASE + 0x1D0)
#define SGPIO_POS5                      MMIO32(SGPIO_PORT_BASE + 0x1D4)
#define SGPIO_POS6                      MMIO32(SGPIO_PORT_BASE + 0x1D8)
#define SGPIO_POS7                      MMIO32(SGPIO_PORT_BASE + 0x1DC)
#define SGPIO_POS8                      MMIO32(SGPIO_PORT_BASE + 0x1E0)
#define SGPIO_POS9                      MMIO32(SGPIO_PORT_BASE + 0x1E4)
#define SGPIO_POS10                     MMIO32(SGPIO_PORT_BASE + 0x1E8)
#define SGPIO_POS11                     MMIO32(SGPIO_PORT_BASE + 0x1EC)
#define SGPIO_POS12                     MMIO32(SGPIO_PORT_BASE + 0x1F0)
#define SGPIO_POS13                     MMIO32(SGPIO_PORT_BASE + 0x1F4)
#define SGPIO_POS14                     MMIO32(SGPIO_PORT_BASE + 0x1F8)
#define SGPIO_POS15                     MMIO32(SGPIO_PORT_BASE + 0x1FC)

/* Slice name to slice index mapping */
#define SGPIO_SLICE_A                   0
#define SGPIO_SLICE_B                   1
#define SGPIO_SLICE_C                   2
#define SGPIO_SLICE_D                   3
#define SGPIO_SLICE_E                   4
#define SGPIO_SLICE_F                   5
#define SGPIO_SLICE_G                   6
#define SGPIO_SLICE_H                   7
#define SGPIO_SLICE_I                   8
#define SGPIO_SLICE_J                   9
#define SGPIO_SLICE_K                   10
#define SGPIO_SLICE_L                   11
#define SGPIO_SLICE_M                   12
#define SGPIO_SLICE_N                   13
#define SGPIO_SLICE_O                   14
#define SGPIO_SLICE_P                   15

/* Mask for pattern match function of slice A */
#define SGPIO_MASK_A                    MMIO32(SGPIO_PORT_BASE + 0x200)

/* Mask for pattern match function of slice H */
#define SGPIO_MASK_H                    MMIO32(SGPIO_PORT_BASE + 0x204)

/* Mask for pattern match function of slice I */
#define SGPIO_MASK_I                    MMIO32(SGPIO_PORT_BASE + 0x208)

/* Mask for pattern match function of slice P */
#define SGPIO_MASK_P                    MMIO32(SGPIO_PORT_BASE + 0x20C)

/* GPIO input status register */
#define SGPIO_GPIO_INREG                MMIO32(SGPIO_PORT_BASE + 0x210)

/* GPIO output control register */
#define SGPIO_GPIO_OUTREG               MMIO32(SGPIO_PORT_BASE + 0x214)

/* GPIO OE control register */
#define SGPIO_GPIO_OENREG               MMIO32(SGPIO_PORT_BASE + 0x218)

/* Enables the slice COUNT counter */
#define SGPIO_CTRL_ENABLE               MMIO32(SGPIO_PORT_BASE + 0x21C)

/* Disables the slice COUNT counter */
#define SGPIO_CTRL_DISABLE              MMIO32(SGPIO_PORT_BASE + 0x220)

/* Shift clock interrupt clear mask */
#define SGPIO_CLR_EN_0                  MMIO32(SGPIO_PORT_BASE + 0xF00)

/* Shift clock interrupt set mask */
#define SGPIO_SET_EN_0                  MMIO32(SGPIO_PORT_BASE + 0xF04)

/* Shift clock interrupt enable */
#define SGPIO_ENABLE_0                  MMIO32(SGPIO_PORT_BASE + 0xF08)

/* Shift clock interrupt status */
#define SGPIO_STATUS_0                  MMIO32(SGPIO_PORT_BASE + 0xF0C)

/* Shift clock interrupt clear status */
#define SGPIO_CLR_STATUS_0              MMIO32(SGPIO_PORT_BASE + 0xF10)

/* Shift clock interrupt set status */
#define SGPIO_SET_STATUS_0              MMIO32(SGPIO_PORT_BASE + 0xF14)

/* Exchange clock interrupt clear mask */
#define SGPIO_CLR_EN_1                  MMIO32(SGPIO_PORT_BASE + 0xF20)

/* Exchange clock interrupt set mask */
#define SGPIO_SET_EN_1                  MMIO32(SGPIO_PORT_BASE + 0xF24)

/* Exchange clock interrupt enable */
#define SGPIO_ENABLE_1                  MMIO32(SGPIO_PORT_BASE + 0xF28)

/* Exchange clock interrupt status */
#define SGPIO_STATUS_1                  MMIO32(SGPIO_PORT_BASE + 0xF2C)

/* Exchange clock interrupt clear status */
#define SGPIO_CLR_STATUS_1              MMIO32(SGPIO_PORT_BASE + 0xF30)

/* Exchange clock interrupt set status */
#define SGPIO_SET_STATUS_1              MMIO32(SGPIO_PORT_BASE + 0xF34)

/* Pattern match interrupt clear mask */
#define SGPIO_CLR_EN_2                  MMIO32(SGPIO_PORT_BASE + 0xF40)

/* Pattern match interrupt set mask */
#define SGPIO_SET_EN_2                  MMIO32(SGPIO_PORT_BASE + 0xF44)

/* Pattern match interrupt enable */
#define SGPIO_ENABLE_2                  MMIO32(SGPIO_PORT_BASE + 0xF48)

/* Pattern match interrupt status */
#define SGPIO_STATUS_2                  MMIO32(SGPIO_PORT_BASE + 0xF4C)

/* Pattern match interrupt clear status */
#define SGPIO_CLR_STATUS_2              MMIO32(SGPIO_PORT_BASE + 0xF50)

/* Pattern match interrupt set status */
#define SGPIO_SET_STATUS_2              MMIO32(SGPIO_PORT_BASE + 0xF54)

/* Input interrupt clear mask */
#define SGPIO_CLR_EN_3                  MMIO32(SGPIO_PORT_BASE + 0xF60)

/* Input bit match interrupt set mask */
#define SGPIO_SET_EN_3                  MMIO32(SGPIO_PORT_BASE + 0xF64)

/* Input bit match interrupt enable */
#define SGPIO_ENABLE_3                  MMIO32(SGPIO_PORT_BASE + 0xF68)

/* Input bit match interrupt status */
#define SGPIO_STATUS_3                  MMIO32(SGPIO_PORT_BASE + 0xF6C)

/* Input bit match interrupt clear status */
#define SGPIO_CLR_STATUS_3              MMIO32(SGPIO_PORT_BASE + 0xF70)

/* Input bit match interrupt set status */
#define SGPIO_SET_STATUS_3              MMIO32(SGPIO_PORT_BASE + 0xF74)

/* --- Common register fields ----------------------------------- */
/* TODO: Generate this stuff with the gen.py script as well! */

#define SGPIO_OUT_MUX_CFG_P_OUT_CFG_SHIFT		(0)
#define SGPIO_OUT_MUX_CFG_P_OUT_CFG_MASK \
			(0xf << SGPIO_OUT_MUX_CFG_P_OUT_CFG_SHIFT)
#define SGPIO_OUT_MUX_CFG_P_OUT_CFG(x) \
			((x) << SGPIO_OUT_MUX_CFG_P_OUT_CFG_SHIFT)

#define SGPIO_OUT_MUX_CFG_P_OE_CFG_SHIFT		(4)
#define SGPIO_OUT_MUX_CFG_P_OE_CFG_MASK \
			(0x7 << SGPIO_OUT_MUX_CFG_P_OE_CFG_SHIFT)
#define SGPIO_OUT_MUX_CFG_P_OE_CFG(x) \
			((x) << SGPIO_OUT_MUX_CFG_P_OE_CFG_SHIFT)

#define SGPIO_MUX_CFG_EXT_CLK_ENABLE_SHIFT		(0)
#define SGPIO_MUX_CFG_EXT_CLK_ENABLE_MASK \
			(1 << SGPIO_MUX_CFG_EXT_CLK_ENABLE_SHIFT)
#define SGPIO_MUX_CFG_EXT_CLK_ENABLE(x) \
			((x) << SGPIO_MUX_CFG_EXT_CLK_ENABLE_SHIFT)

#define SGPIO_MUX_CFG_CLK_SOURCE_PIN_MODE_SHIFT		(1)
#define SGPIO_MUX_CFG_CLK_SOURCE_PIN_MODE_MASK \
			(0x3 << SGPIO_MUX_CFG_CLK_SOURCE_PIN_MODE_SHIFT)
#define SGPIO_MUX_CFG_CLK_SOURCE_PIN_MODE(x) \
			((x) << SGPIO_MUX_CFG_CLK_SOURCE_PIN_MODE_SHIFT)

#define SGPIO_MUX_CFG_CLK_SOURCE_SLICE_MODE_SHIFT	(3)
#define SGPIO_MUX_CFG_CLK_SOURCE_SLICE_MODE_MASK \
			(0x3 << SGPIO_MUX_CFG_CLK_SOURCE_SLICE_MODE_SHIFT)
#define SGPIO_MUX_CFG_CLK_SOURCE_SLICE_MODE(x) \
			((x) << SGPIO_MUX_CFG_CLK_SOURCE_SLICE_MODE_SHIFT)

#define SGPIO_MUX_CFG_QUALIFIER_MODE_SHIFT		(5)
#define SGPIO_MUX_CFG_QUALIFIER_MODE_MASK \
			(0x3 << SGPIO_MUX_CFG_QUALIFIER_MODE_SHIFT)
#define SGPIO_MUX_CFG_QUALIFIER_MODE(x) \
			((x) << SGPIO_MUX_CFG_QUALIFIER_MODE_SHIFT)

#define SGPIO_MUX_CFG_QUALIFIER_PIN_MODE_SHIFT		(7)
#define SGPIO_MUX_CFG_QUALIFIER_PIN_MODE_MASK \
			(0x3 << SGPIO_MUX_CFG_QUALIFIER_PIN_MODE_SHIFT)
#define SGPIO_MUX_CFG_QUALIFIER_PIN_MODE(x) \
			((x) << SGPIO_MUX_CFG_QUALIFIER_PIN_MODE_SHIFT)

#define SGPIO_MUX_CFG_QUALIFIER_SLICE_MODE_SHIFT	(9)
#define SGPIO_MUX_CFG_QUALIFIER_SLICE_MODE_MASK \
			(0x3 << SGPIO_MUX_CFG_QUALIFIER_SLICE_MODE_SHIFT)
#define SGPIO_MUX_CFG_QUALIFIER_SLICE_MODE(x) \
			((x) << SGPIO_MUX_CFG_QUALIFIER_SLICE_MODE_SHIFT)

#define SGPIO_MUX_CFG_CONCAT_ENABLE_SHIFT		(11)
#define SGPIO_MUX_CFG_CONCAT_ENABLE_MASK \
			(1 << SGPIO_MUX_CFG_CONCAT_ENABLE_SHIFT)
#define SGPIO_MUX_CFG_CONCAT_ENABLE(x) \
			((x) << SGPIO_MUX_CFG_CONCAT_ENABLE_SHIFT)

#define SGPIO_MUX_CFG_CONCAT_ORDER_SHIFT		(12)
#define SGPIO_MUX_CFG_CONCAT_ORDER_MASK \
			(0x3 << SGPIO_MUX_CFG_CONCAT_ORDER_SHIFT)
#define SGPIO_MUX_CFG_CONCAT_ORDER(x) \
			((x) << SGPIO_MUX_CFG_CONCAT_ORDER_SHIFT)

#define SGPIO_SLICE_MUX_CFG_MATCH_MODE_SHIFT		(0)
#define SGPIO_SLICE_MUX_CFG_MATCH_MODE_MASK \
			(1 << SGPIO_SLICE_MUX_CFG_MATCH_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFG_MATCH_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFG_MATCH_MODE_SHIFT)

#define SGPIO_SLICE_MUX_CFG_CLK_CAPTURE_MODE_SHIFT	(1)
#define SGPIO_SLICE_MUX_CFG_CLK_CAPTURE_MODE_MASK \
			(1 << SGPIO_SLICE_MUX_CFG_CLK_CAPTURE_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFG_CLK_CAPTURE_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFG_CLK_CAPTURE_MODE_SHIFT)

#define SGPIO_SLICE_MUX_CFG_CLKGEN_MODE_SHIFT		(2)
#define SGPIO_SLICE_MUX_CFG_CLKGEN_MODE_MASK \
			(1 << SGPIO_SLICE_MUX_CFG_CLKGEN_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFG_CLKGEN_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFG_CLKGEN_MODE_SHIFT)

#define SGPIO_SLICE_MUX_CFG_INV_OUT_CLK_SHIFT		(3)
#define SGPIO_SLICE_MUX_CFG_INV_OUT_CLK_MASK \
			(1 << SGPIO_SLICE_MUX_CFG_INV_OUT_CLK_SHIFT)
#define SGPIO_SLICE_MUX_CFG_INV_OUT_CLK(x) \
			((x) << SGPIO_SLICE_MUX_CFG_INV_OUT_CLK_SHIFT)

#define SGPIO_SLICE_MUX_CFG_DATA_CAPTURE_MODE_SHIFT	(4)
#define SGPIO_SLICE_MUX_CFG_DATA_CAPTURE_MODE_MASK \
			(0x3 << SGPIO_SLICE_MUX_CFG_DATA_CAPTURE_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFG_DATA_CAPTURE_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFG_DATA_CAPTURE_MODE_SHIFT)

#define SGPIO_SLICE_MUX_CFG_PARALLEL_MODE_SHIFT		(6)
#define SGPIO_SLICE_MUX_CFG_PARALLEL_MODE_MASK \
			(0x3 << SGPIO_SLICE_MUX_CFG_PARALLEL_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFG_PARALLEL_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFG_PARALLEL_MODE_SHIFT)

#define SGPIO_SLICE_MUX_CFG_INV_QUALIFIER_SHIFT		(8)
#define SGPIO_SLICE_MUX_CFG_INV_QUALIFIER_MASK \
			(1 << SGPIO_SLICE_MUX_CFG_INV_QUALIFIER_SHIFT)
#define SGPIO_SLICE_MUX_CFG_INV_QUALIFIER(x) \
			((x) << SGPIO_SLICE_MUX_CFG_INV_QUALIFIER_SHIFT)

#define SGPIO_POS_POS_SHIFT		(0)
#define SGPIO_POS_POS_MASK		(0xff << SGPIO_POS_POS_SHIFT)
#define SGPIO_POS_POS(x)		((x) << SGPIO_POS_POS_SHIFT)

#define SGPIO_POS_POS_RESET_SHIFT	(8)
#define SGPIO_POS_POS_RESET_MASK	(0xff << SGPIO_POS_POS_RESET_SHIFT)
#define SGPIO_POS_POS_RESET(x)		((x) << SGPIO_POS_POS_RESET_SHIFT)

/* --- AUTO-GENERATED STUFF FOLLOWS ----------------------------- */

/* --- SGPIO_OUT_MUX_CFG[0..15] values ------------------------------------ */

/* P_OUT_CFG: Output control of output SGPIOn */
#define SGPIO_OUT_MUX_CFGx_P_OUT_CFG_SHIFT		(0)
#define SGPIO_OUT_MUX_CFGx_P_OUT_CFG_MASK \
			(0xf << SGPIO_OUT_MUX_CFGx_P_OUT_CFG_SHIFT)
#define SGPIO_OUT_MUX_CFGx_P_OUT_CFG(x) \
			((x) << SGPIO_OUT_MUX_CFGx_P_OUT_CFG_SHIFT)

/* P_OE_CFG: Output enable source */
#define SGPIO_OUT_MUX_CFGx_P_OE_CFG_SHIFT		(4)
#define SGPIO_OUT_MUX_CFGx_P_OE_CFG_MASK \
			(0x7 << SGPIO_OUT_MUX_CFGx_P_OE_CFG_SHIFT)
#define SGPIO_OUT_MUX_CFGx_P_OE_CFG(x) \
			((x) << SGPIO_OUT_MUX_CFGx_P_OE_CFG_SHIFT)

/* --- SGPIO_MUX_CFG[0..15] values ---------------------------------------- */

/* EXT_CLK_ENABLE: Select clock signal */
#define SGPIO_MUX_CFGx_EXT_CLK_ENABLE_SHIFT		(0)
#define SGPIO_MUX_CFGx_EXT_CLK_ENABLE \
			(1 << SGPIO_MUX_CFGx_EXT_CLK_ENABLE_SHIFT)

/* CLK_SOURCE_PIN_MODE: Select source clock pin */
#define SGPIO_MUX_CFGx_CLK_SOURCE_PIN_MODE_SHIFT	(1)
#define SGPIO_MUX_CFGx_CLK_SOURCE_PIN_MODE_MASK \
			(0x3 << SGPIO_MUX_CFGx_CLK_SOURCE_PIN_MODE_SHIFT)
#define SGPIO_MUX_CFGx_CLK_SOURCE_PIN_MODE(x) \
			((x) << SGPIO_MUX_CFGx_CLK_SOURCE_PIN_MODE_SHIFT)

/* CLK_SOURCE_SLICE_MODE: Select clock source slice */
#define SGPIO_MUX_CFGx_CLK_SOURCE_SLICE_MODE_SHIFT	(3)
#define SGPIO_MUX_CFGx_CLK_SOURCE_SLICE_MODE_MASK \
			(0x3 << SGPIO_MUX_CFGx_CLK_SOURCE_SLICE_MODE_SHIFT)
#define SGPIO_MUX_CFGx_CLK_SOURCE_SLICE_MODE(x) \
			((x) << SGPIO_MUX_CFGx_CLK_SOURCE_SLICE_MODE_SHIFT)

/* QUALIFIER_MODE: Select qualifier mode */
#define SGPIO_MUX_CFGx_QUALIFIER_MODE_SHIFT		(5)
#define SGPIO_MUX_CFGx_QUALIFIER_MODE_MASK \
			(0x3 << SGPIO_MUX_CFGx_QUALIFIER_MODE_SHIFT)
#define SGPIO_MUX_CFGx_QUALIFIER_MODE(x) \
			((x) << SGPIO_MUX_CFGx_QUALIFIER_MODE_SHIFT)

/* QUALIFIER_PIN_MODE: Select qualifier pin */
#define SGPIO_MUX_CFGx_QUALIFIER_PIN_MODE_SHIFT		(7)
#define SGPIO_MUX_CFGx_QUALIFIER_PIN_MODE_MASK \
			(0x3 << SGPIO_MUX_CFGx_QUALIFIER_PIN_MODE_SHIFT)
#define SGPIO_MUX_CFGx_QUALIFIER_PIN_MODE(x) \
			((x) << SGPIO_MUX_CFGx_QUALIFIER_PIN_MODE_SHIFT)

/* QUALIFIER_SLICE_MODE: Select qualifier slice */
#define SGPIO_MUX_CFGx_QUALIFIER_SLICE_MODE_SHIFT	(9)
#define SGPIO_MUX_CFGx_QUALIFIER_SLICE_MODE_MASK \
			(0x3 << SGPIO_MUX_CFGx_QUALIFIER_SLICE_MODE_SHIFT)
#define SGPIO_MUX_CFGx_QUALIFIER_SLICE_MODE(x) \
			((x) << SGPIO_MUX_CFG0_QUALIFIER_SLICE_MODE_SHIFT)

/* CONCAT_ENABLE: Enable concatenation */
#define SGPIO_MUX_CFGx_CONCAT_ENABLE_SHIFT		(11)
#define SGPIO_MUX_CFGx_CONCAT_ENABLE \
			(1 << SGPIO_MUX_CFGx_CONCAT_ENABLE_SHIFT)

/* CONCAT_ORDER: Select concatenation order */
#define SGPIO_MUX_CFGx_CONCAT_ORDER_SHIFT		(12)
#define SGPIO_MUX_CFGx_CONCAT_ORDER_MASK \
			(0x3 << SGPIO_MUX_CFGx_CONCAT_ORDER_SHIFT)
#define SGPIO_MUX_CFGx_CONCAT_ORDER(x) \
			((x) << SGPIO_MUX_CFGx_CONCAT_ORDER_SHIFT)

/* --- SGPIO_SLICE_MUX_CFG[0..15] values ---------------------------------- */

/* MATCH_MODE: Match mode */
#define SGPIO_SLICE_MUX_CFGx_MATCH_MODE_SHIFT		(0)
#define SGPIO_SLICE_MUX_CFGx_MATCH_MODE \
			(1 << SGPIO_SLICE_MUX_CFG0_MATCH_MODE_SHIFT)

/* CLK_CAPTURE_MODE: Capture clock mode */
#define SGPIO_SLICE_MUX_CFGx_CLK_CAPTURE_MODE_SHIFT	(1)
#define SGPIO_SLICE_MUX_CFGx_CLK_CAPTURE_MODE \
			(1 << SGPIO_SLICE_MUX_CFGx_CLK_CAPTURE_MODE_SHIFT)

/* CLKGEN_MODE: Clock generation mode */
#define SGPIO_SLICE_MUX_CFGx_CLKGEN_MODE_SHIFT (2)
#define SGPIO_SLICE_MUX_CFGx_CLKGEN_MODE \
			(1 << SGPIO_SLICE_MUX_CFGx_CLKGEN_MODE_SHIFT)

/* INV_OUT_CLK: Invert output clock */
#define SGPIO_SLICE_MUX_CFGx_INV_OUT_CLK_SHIFT (3)
#define SGPIO_SLICE_MUX_CFGx_INV_OUT_CLK \
			(1 << SGPIO_SLICE_MUX_CFGx_INV_OUT_CLK_SHIFT)

/* DATA_CAPTURE_MODE: Condition for input bit match interrupt */
#define SGPIO_SLICE_MUX_CFGx_DATA_CAPTURE_MODE_SHIFT (4)
#define SGPIO_SLICE_MUX_CFGx_DATA_CAPTURE_MODE_MASK \
			(0x3 << SGPIO_SLICE_MUX_CFGx_DATA_CAPTURE_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFGx_DATA_CAPTURE_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFGx_DATA_CAPTURE_MODE_SHIFT)

/* PARALLEL_MODE: Parallel mode */
#define SGPIO_SLICE_MUX_CFGx_PARALLEL_MODE_SHIFT (6)
#define SGPIO_SLICE_MUX_CFGx_PARALLEL_MODE_MASK \
			(0x3 << SGPIO_SLICE_MUX_CFGx_PARALLEL_MODE_SHIFT)
#define SGPIO_SLICE_MUX_CFGx_PARALLEL_MODE(x) \
			((x) << SGPIO_SLICE_MUX_CFGx_PARALLEL_MODE_SHIFT)

/* INV_QUALIFIER: Inversion qualifier */
#define SGPIO_SLICE_MUX_CFGx_INV_QUALIFIER_SHIFT (8)
#define SGPIO_SLICE_MUX_CFGx_INV_QUALIFIER \
			(1 << SGPIO_SLICE_MUX_CFGx_INV_QUALIFIER_SHIFT)


/* --- SGPIO_POS[0..15] values -------------------------------------------- */

/* POS: Each time COUNT reaches 0x0 POS counts down */
#define SGPIO_POSx_POS_SHIFT		(0)
#define SGPIO_POSx_POS_MASK		(0xff << SGPIO_POSx_POS_SHIFT)
#define SGPIO_POSx_POS(x)		((x) << SGPIO_POSx_POS_SHIFT)

/* POS_RESET: Reload value for POS after POS reaches 0x0 */
#define SGPIO_POSx_POS_RESET_SHIFT	(8)
#define SGPIO_POSx_POS_RESET_MASK	(0xff << SGPIO_POSx_POS_RESET_SHIFT)
#define SGPIO_POSx_POS_RESET(x)		((x) << SGPIO_POSx_POS_RESET_SHIFT)


/* SGPIO structure for faster/better code generation (especially when optimized
 * with -O2/-O3)
 */
/* This structure is compliant with LPC43xx User Manual UM10503 Rev.1.4 - 3
 * September 2012
 */
typedef struct {
	/* Pin multiplexer configuration registers. RW */
	volatile uint32_t OUT_MUX_CFG[16];
	/* SGPIO multiplexer configuration registers. RW */
	volatile uint32_t SGPIO_MUX_CFG[16];
	/* Slice multiplexer configuration registers. RW */
	volatile uint32_t SLICE_MUX_CFG[16];
	/* Slice data registers. RW */
	volatile uint32_t REG[16];
	/* Slice data shadow registers. Each time POS reaches 0x0 the contents
	 * of REG_SS is exchanged with the content of REG. RW
	 */
	volatile uint32_t REG_SS[16];
	/* Reload registers. Counter reload value; loaded when COUNT reaches
	 * 0x0 RW
	 */
	volatile uint32_t PRESET[16];
	/* Down counter registers, counts down each shift clock cycle. RW */
	volatile uint32_t COUNT[16];
	/* Position registers. POS Each time COUNT reaches 0x0 POS counts down.
	 * POS_RESET Reload value for POS after POS reaches 0x0. RW
	 */
	volatile uint32_t POS[16];
	/* Slice A mask register. Mask for pattern match function of slice A.
	 * RW
	 */
	volatile uint32_t MASK_A;
	/* Slice H mask register. Mask for pattern match function of slice H.
	 * RW
	 */
	volatile uint32_t MASK_H;
	/* Slice I mask register. Mask for pattern match function of slice I.
	 * RW
	 */
	volatile uint32_t MASK_I;
	/* Slice P mask register. Mask for pattern match function of slice P.
	 * RW
	 */
	volatile uint32_t MASK_P;
	/* GPIO input status register. R */
	volatile uint32_t GPIO_INREG;
	/* GPIO output control register. RW */
	volatile uint32_t GPIO_OUTREG;
	/* GPIO output enable register. RW */
	volatile uint32_t GPIO_OENREG;
	/* Slice count enable register. RW */
	volatile uint32_t CTRL_ENABLE;
	/* Slice count disable register. RW */
	volatile uint32_t CTRL_DISABLE;
	volatile uint32_t RES0[823];
	/* Shift clock interrupt clear mask register. W */
	volatile uint32_t CLR_EN_0;
	/* Shift clock interrupt set mask register. W */
	volatile uint32_t SET_EN_0;
	/* Shift clock interrupt enable register. R */
	volatile uint32_t ENABLE_0;
	/* Shift clock interrupt status register. R */
	volatile uint32_t STATUS_0;
	/* Shift clock interrupt clear status register. W */
	volatile uint32_t CLR_STATUS_0;
	/* Shift clock interrupt set status register. W */
	volatile uint32_t SET_STATUS_0;
	volatile uint32_t RES1[2];
	/* Exchange clock interrupt clear mask register. W */
	volatile uint32_t CLR_EN_1;
	/* Exchange clock interrupt set mask register. W */
	volatile uint32_t SET_EN_1;
	/* Exchange clock interrupt enable. R */
	volatile uint32_t ENABLE_1;
	/* Exchange clock interrupt status register. R */
	volatile uint32_t STATUS_1;
	/* Exchange clock interrupt clear status register. W */
	volatile uint32_t CLR_STATUS_1;
	/* Exchange clock interrupt set status register. W */
	volatile uint32_t SET_STATUS_1;
	volatile uint32_t RES2[2];
	/* Pattern match interrupt clear mask register. W */
	volatile uint32_t CLR_EN_2;
	/* Pattern match interrupt set mask register. W */
	volatile uint32_t SET_EN_2;
	/* Pattern match interrupt enable register. R */
	volatile uint32_t ENABLE_2;
	/* Pattern match interrupt status register. R */
	volatile uint32_t STATUS_2;
	/* Pattern match interrupt clear status register. W */
	volatile uint32_t CLR_STATUS_2;
	/* Pattern match interrupt set status register. W */
	volatile uint32_t SET_STATUS_2;
	volatile uint32_t RES3[2];
	/* Input interrupt clear mask register. W */
	volatile uint32_t CLR_EN_3;
	/* Input bit match interrupt set mask register. W */
	volatile uint32_t SET_EN_3;
	/* Input bit match interrupt enable register. R */
	volatile uint32_t ENABLE_3;
	/* Input bit match interrupt status register. R */
	volatile uint32_t STATUS_3;
	/* Input bit match interrupt clear status register. W */
	volatile uint32_t CLR_STATUS_3;
	/* Input bit match interrupt set status register. W */
	volatile uint32_t SET_STATUS_3;
} sgpio_t;

/* Global access to SGPIO structure */
#define SGPIO   ((sgpio_t *)SGPIO_PORT_BASE)

/**@}*/

#endif
