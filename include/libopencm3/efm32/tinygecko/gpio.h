/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *
 * Definitions for the GPIO subsystem (General Purpose Input Output).
 *
 * This corresponds to the description in d0034_efm32tg_reference_manual.pdf
 * section 28.
 *
 * @see GPIO_registers
 * @see GPIO_MODE_values
 */
/* FIXME: i'd prefer not to @see CMU_registers but have some direct link placed
 * automatically from a file to its groups */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_GPIO_H
#define LIBOPENCM3_EFM32_TINYGECKO_GPIO_H

#include <libopencm3/cm3/common.h>

#define GPIO_BASE 0x40006000 /**< Register base address for the GPIO according to d0034_efm32tg_reference_manual.pdf figure 5.2. */

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 28.4
 *
 * The bulk of the registers defined here (like GPIO_PA_CTRL) will not be used
 * inside the convenience functions, but are provided for direct access.
 *
 * @todo This section could profit from bit-banding.
 *
 * @defgroup GPIO_registers GPIO registers
 * @{
 */
#define GPIO_Px_CTRL_OFFSET	0x000
#define GPIO_Px_MODEL_OFFSET	0x004
#define GPIO_Px_MODEH_OFFSET	0x008
#define GPIO_Px_DOUT_OFFSET	0x00C
#define GPIO_Px_DOUTSET_OFFSET	0x010
#define GPIO_Px_DOUTCLR_OFFSET	0x014
#define GPIO_Px_DOUTTGL_OFFSET	0x018
#define GPIO_Px_DIN_OFFSET	0x01C
#define GPIO_Px_PINLOCKN_OFFSET	0x020

#define GPIO_PA			(GPIO_BASE + 0x000)
#define GPIO_PA_CTRL		MMIO32(GPIO_PA + GPIO_Px_CTRL_OFFSET)
#define GPIO_PA_MODEL		MMIO32(GPIO_PA + GPIO_Px_MODEL_OFFSET)
#define GPIO_PA_MODEH		MMIO32(GPIO_PA + GPIO_Px_MODEH_OFFSET)
#define GPIO_PA_DOUT		MMIO32(GPIO_PA + GPIO_Px_DOUT_OFFSET)
#define GPIO_PA_DOUTSET		MMIO32(GPIO_PA + GPIO_Px_DOUTSET_OFFSET)
#define GPIO_PA_DOUTCLR		MMIO32(GPIO_PA + GPIO_Px_DOUTCLR_OFFSET)
#define GPIO_PA_DOUTTGL		MMIO32(GPIO_PA + GPIO_Px_DOUTTGL_OFFSET)
#define GPIO_PA_DIN		MMIO32(GPIO_PA + GPIO_Px_DIN_OFFSET)
#define GPIO_PA_PINLOCKN	MMIO32(GPIO_PA + GPIO_Px_PINLOCKN_OFFSET)

#define GPIO_PB			(GPIO_BASE + 0x024)
#define GPIO_PB_CTRL		MMIO32(GPIO_PB + GPIO_Px_CTRL_OFFSET)
#define GPIO_PB_MODEL		MMIO32(GPIO_PB + GPIO_Px_MODEL_OFFSET)
#define GPIO_PB_MODEH		MMIO32(GPIO_PB + GPIO_Px_MODEH_OFFSET)
#define GPIO_PB_DOUT		MMIO32(GPIO_PB + GPIO_Px_DOUT_OFFSET)
#define GPIO_PB_DOUTSET		MMIO32(GPIO_PB + GPIO_Px_DOUTSET_OFFSET)
#define GPIO_PB_DOUTCLR		MMIO32(GPIO_PB + GPIO_Px_DOUTCLR_OFFSET)
#define GPIO_PB_DOUTTGL		MMIO32(GPIO_PB + GPIO_Px_DOUTTGL_OFFSET)
#define GPIO_PB_DIN		MMIO32(GPIO_PB + GPIO_Px_DIN_OFFSET)
#define GPIO_PB_PINLOCKN	MMIO32(GPIO_PB + GPIO_Px_PINLOCKN_OFFSET)

#define GPIO_PC			(GPIO_BASE + 0x048)
#define GPIO_PC_CTRL		MMIO32(GPIO_PC + GPIO_Px_CTRL_OFFSET)
#define GPIO_PC_MODEL		MMIO32(GPIO_PC + GPIO_Px_MODEL_OFFSET)
#define GPIO_PC_MODEH		MMIO32(GPIO_PC + GPIO_Px_MODEH_OFFSET)
#define GPIO_PC_DOUT		MMIO32(GPIO_PC + GPIO_Px_DOUT_OFFSET)
#define GPIO_PC_DOUTSET		MMIO32(GPIO_PC + GPIO_Px_DOUTSET_OFFSET)
#define GPIO_PC_DOUTCLR		MMIO32(GPIO_PC + GPIO_Px_DOUTCLR_OFFSET)
#define GPIO_PC_DOUTTGL		MMIO32(GPIO_PC + GPIO_Px_DOUTTGL_OFFSET)
#define GPIO_PC_DIN		MMIO32(GPIO_PC + GPIO_Px_DIN_OFFSET)
#define GPIO_PC_PINLOCKN	MMIO32(GPIO_PC + GPIO_Px_PINLOCKN_OFFSET)

#define GPIO_PD			(GPIO_BASE + 0x06C)
#define GPIO_PD_CTRL		MMIO32(GPIO_PD + GPIO_Px_CTRL_OFFSET)
#define GPIO_PD_MODEL		MMIO32(GPIO_PD + GPIO_Px_MODEL_OFFSET)
#define GPIO_PD_MODEH		MMIO32(GPIO_PD + GPIO_Px_MODEH_OFFSET)
#define GPIO_PD_DOUT		MMIO32(GPIO_PD + GPIO_Px_DOUT_OFFSET)
#define GPIO_PD_DOUTSET		MMIO32(GPIO_PD + GPIO_Px_DOUTSET_OFFSET)
#define GPIO_PD_DOUTCLR		MMIO32(GPIO_PD + GPIO_Px_DOUTCLR_OFFSET)
#define GPIO_PD_DOUTTGL		MMIO32(GPIO_PD + GPIO_Px_DOUTTGL_OFFSET)
#define GPIO_PD_DIN		MMIO32(GPIO_PD + GPIO_Px_DIN_OFFSET)
#define GPIO_PD_PINLOCKN	MMIO32(GPIO_PD + GPIO_Px_PINLOCKN_OFFSET)

#define GPIO_PE			(GPIO_BASE + 0x090)
#define GPIO_PE_CTRL		MMIO32(GPIO_PE + GPIO_Px_CTRL_OFFSET)
#define GPIO_PE_MODEL		MMIO32(GPIO_PE + GPIO_Px_MODEL_OFFSET)
#define GPIO_PE_MODEH		MMIO32(GPIO_PE + GPIO_Px_MODEH_OFFSET)
#define GPIO_PE_DOUT		MMIO32(GPIO_PE + GPIO_Px_DOUT_OFFSET)
#define GPIO_PE_DOUTSET		MMIO32(GPIO_PE + GPIO_Px_DOUTSET_OFFSET)
#define GPIO_PE_DOUTCLR		MMIO32(GPIO_PE + GPIO_Px_DOUTCLR_OFFSET)
#define GPIO_PE_DOUTTGL		MMIO32(GPIO_PE + GPIO_Px_DOUTTGL_OFFSET)
#define GPIO_PE_DIN		MMIO32(GPIO_PE + GPIO_Px_DIN_OFFSET)
#define GPIO_PE_PINLOCKN	MMIO32(GPIO_PE + GPIO_Px_PINLOCKN_OFFSET)

#define GPIO_PF			(GPIO_BASE + 0x0B4)
#define GPIO_PF_CTRL		MMIO32(GPIO_PF + GPIO_Px_CTRL_OFFSET)
#define GPIO_PF_MODEL		MMIO32(GPIO_PF + GPIO_Px_MODEL_OFFSET)
#define GPIO_PF_MODEH		MMIO32(GPIO_PF + GPIO_Px_MODEH_OFFSET)
#define GPIO_PF_DOUT		MMIO32(GPIO_PF + GPIO_Px_DOUT_OFFSET)
#define GPIO_PF_DOUTSET		MMIO32(GPIO_PF + GPIO_Px_DOUTSET_OFFSET)
#define GPIO_PF_DOUTCLR		MMIO32(GPIO_PF + GPIO_Px_DOUTCLR_OFFSET)
#define GPIO_PF_DOUTTGL		MMIO32(GPIO_PF + GPIO_Px_DOUTTGL_OFFSET)
#define GPIO_PF_DIN		MMIO32(GPIO_PF + GPIO_Px_DIN_OFFSET)
#define GPIO_PF_PINLOCKN	MMIO32(GPIO_PF + GPIO_Px_PINLOCKN_OFFSET)

#define GPIO_EXTIPSELL		MMIO32(GPIO_BASE + 0x100)
#define GPIO_EXTIPSELH		MMIO32(GPIO_BASE + 0x104)
#define GPIO_EXTIRISE		MMIO32(GPIO_BASE + 0x108)
#define GPIO_EXTIFALL		MMIO32(GPIO_BASE + 0x10C)
#define GPIO_IEN		MMIO32(GPIO_BASE + 0x110)
#define GPIO_IF			MMIO32(GPIO_BASE + 0x114)
#define GPIO_IFS		MMIO32(GPIO_BASE + 0x118)
#define GPIO_IFC		MMIO32(GPIO_BASE + 0x11C)
#define GPIO_ROUTE		MMIO32(GPIO_BASE + 0x120)
#define GPIO_INSENSE		MMIO32(GPIO_BASE + 0x124)
#define GPIO_LOCK		MMIO32(GPIO_BASE + 0x128)
#define GPIO_CTRL		MMIO32(GPIO_BASE + 0x12C)
#define GPIO_CMD		MMIO32(GPIO_BASE + 0x130)
#define GPIO_EM4WUEN		MMIO32(GPIO_BASE + 0x134)
#define GPIO_EM4WUPOL		MMIO32(GPIO_BASE + 0x138)
#define GPIO_EM4WUCAUSE		MMIO32(GPIO_BASE + 0x13C)

/** @} */

/** These are the modes defined for the MODEx fields in the MODEL/MODEH
 * registers.
 *
 * For example, to set the mode for the 3rd pin of port A to pushpull, set
 * `GPIO_PA_MODEL = GPIO_MODE_PUSHPULL << (3*4);`.
 *
 * @todo Update the example as soon as there are convenience functions to do
 * this properly.
 *
 * They are named as in d0034_efm32tg_reference_manual.pdf's sections
 * 28.5.2/28.5.3. For explanations of what they really do, rather see section
 * 28.3.1.
 *
 * @defgroup GPIO_MODE_values GPIO MODE values
 * @{
 */

#define GPIO_MODE_DISABLED			0
#define GPIO_MODE_INPUT				1
#define GPIO_MODE_INPUTPULL			2
#define GPIO_MODE_INPUTPULLFILTER		3
#define GPIO_MODE_PUSHPULL			4
#define GPIO_MODE_PUSHPULLDRIVE			5
#define GPIO_MODE_WIREDOR			6
#define GPIO_MODE_WIREDORPULLDOWN		7
#define GPIO_MODE_WIREDAND			8
#define GPIO_MODE_WIREDANDFILTER		9
#define GPIO_MODE_WIREDANDPULLUP		10
#define GPIO_MODE_WIREDANDPULLUPFILTER		11
#define GPIO_MODE_WIREDANDDRIVE			12
#define GPIO_MODE_WIREDANDDRIVEFILTER		13
#define GPIO_MODE_WIREDANDDRIVEPULLUP		14
#define GPIO_MODE_WIREDANDDRIVEPULLUPFILTER	15

/** @} */

//void gpio_set(u32 gpioport, u16 gpios);
//void gpio_clear(u32 gpioport, u16 gpios);
//void gpio_toggle(u32 gpioport, u16 gpios);
//u16 gpio_get(u32 gpioport, u16 gpios);

#endif
