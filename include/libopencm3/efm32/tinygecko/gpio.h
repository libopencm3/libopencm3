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
 * @see EFM32TG_GPIO
 */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_GPIO_H
#define LIBOPENCM3_EFM32_TINYGECKO_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>

/** Register definitions and register value definitions for the GPIO subsystem
 *
 * @defgroup EFM32TG_GPIO EFM32 Tiny Gecko GPIO registers and values
 * @{
 */

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 28.4
 *
 * The bulk of the registers defined here (like GPIO_PA_CTRL) will not be used
 * inside the convenience functions, but are provided for direct access.
 *
 * @todo This section could profit from bit-banding.
 *
 * @defgroup EFM32TG_GPIO_registers EFM32 Tiny Gecko GPIO registers
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

/** Bit states for the GPIO_Px_CTRL register
 *
 * They are named as in d0034_efm32tg_reference_manual.pdf's section
 * 28.5.1.
 *
 * @defgroup EFM32TG_GPIO_Px_CTRL_bits EFM32 Tiny Gecko GPIO Px CTRL bits
 * @{
 */

#define GPIO_CTRL_DRIVEMODE_STANDARD		0 /**< 6mA drive current */
#define GPIO_CTRL_DRIVEMODE_LOWEST		1 /**< 0.5mA drive current */
#define GPIO_CTRL_DRIVEMODE_HIGH		2 /**< 20mA drive current */
#define GPIO_CTRL_DRIVEMODE_LOW			3 /**< 2mA drive current */

/** @} */

/** These are the modes defined for the MODEx fields in the GPIO_Px_MODEL and
 * GPIO_Px_MODEH registers.
 *
 * These bit state definitions are not localized, meaning that they have to be
 * bitshifted by multiples of 4 to configure other pins than 0; configurations
 * for pins 0 to 7 go to GPIO_Px_MODEL (shifted by 4*pin), configurations for
 * pins 8 to 15 go to GPIO_Px_MODEH (shifted by 4*(pin-8)).
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
 * @defgroup EFM32TG_GPIO_MODE_values EFM32 Tiny Gecko GPIO MODE values
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

/** These are the modes defined for the EXTIPSELx fields in the GPIO_EXTIPSELL
 * and GPIO_EXTIPSELH registers.
 *
 * These bit state definitions are not localized, meaning that they have to be
 * bitshifted by multiples of 4 to configure other pins than 0; configurations
 * for pins 0 to 7 go to GPIO_EXTIPSELL (shifted by 4*pin), configurations for
 * pins 8 to 15 go to GPIO_EXTIPSELH (shifted by 4*(pin-8)).
 *
 * They are named as in d0034_efm32tg_reference_manual.pdf's sections
 * 28.5.10/28.5.11. For explanations of what they do, rather see section
 * 28.3.5.
 *
 * @defgroup EFM32TG_GPIO_EXTIP_values EFM32 Tiny Gecko GPIO EXTIPSEL values
 * @{
 */

#define GPIO_EXTIPSEL_PORTA			0 /**< Port A pin x selected for external interrupt x */
#define GPIO_EXTIPSEL_PORTB			1 /**< Port B pin x selected for external interrupt x */
#define GPIO_EXTIPSEL_PORTC			2 /**< Port C pin x selected for external interrupt x */
#define GPIO_EXTIPSEL_PORTD			3 /**< Port D pin x selected for external interrupt x */
#define GPIO_EXTIPSEL_PORTE			4 /**< Port E pin x selected for external interrupt x */
#define GPIO_EXTIPSEL_PORTF			5 /**< Port F pin x selected for external interrupt x */

/** @} */

/** Bit states for the GPIO_ROUTE register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.18 for definitions, and
 * 28.3.4.1 for explanations.
 *
 * @defgroup EFM32TG_GPIO_ROUTE_bits EFM32 Tiny Gecko GPIO ROUTE bits
 * @{
 */

#define GPIO_ROUTE_SWLOCATION_MASK		(0x03<<8)
#define GPIO_ROUTE_SWLOCATION_LOC0		(0<<8) /**< Route SW pins to location 0 (see chip data sheet for exact pins */
#define GPIO_ROUTE_SWLOCATION_LOC1		(1<<8) /**< Route SW pins to location 1 (see chip data sheet for exact pins */
#define GPIO_ROUTE_SWLOCATION_LOC2		(2<<8) /**< Route SW pins to location 2 (see chip data sheet for exact pins */
#define GPIO_ROUTE_SWLOCATION_LOC3		(3<<8) /**< Route SW pins to location 3 (see chip data sheet for exact pins */

#define GPIO_ROUTE_SWOPEN			(1<<2) /**< Serial Wire Viewer Output pin enabled */
#define GPIO_ROUTE_SWDIOPEN			(1<<1) /**< Serial Wire Data pin enabled */
#define GPIO_ROUTE_SWCLKPEN			(1<<0) /**< Serial Wire Clock pin enabled */

/** @} */

/** Bit states for the GPIO_INSENSE register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.19 for definitions, and
 * 28.3.7 for details.
 *
 * @defgroup EFM32TG_GPIO_INSENSE_bits EFM32 Tiny Gecko GPIO INSENSE bits
 * @{
 */

#define GPIO_INSENSE_PRS			(1<<1) /**< Input sensing for PRS enabled */
#define GPIO_INSENSE_INT			(1<<0) /**< Input sensing for interrupts enabled */

/** @} */

/** Values for the GPIO_LOCK register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.20 for definitions, and
 * 28.3.1.1 for explanations.
 *
 * @defgroup EFM32TG_GPIO_LOCK_values EFM32 Tiny Gecko GPIO LOCK bits
 * @{
 */

#define GPIO_LOCK_IS_UNLOCKED			0 /**< When the LOCK register reads as this value, it is open */
#define GPIO_LOCK_IS_LOCKED			1 /**< When the LOCK register reads as this value, it is locked */
#define GPIO_LOCK_SET_LOCKED			0 /**< Write this to the LOCK register to lock down GPIO */
#define GPIO_LOCK_SET_UNLOCKED			0xa543 /**< Write this to the LOCK register to unlock the GPIO */

/** @} */

/** Bit states for the GPIO_CTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.21 for definitions, and
 * 28.3.4 for explanations.
 *
 * @defgroup EFM32TG_GPIO_CTRL_bits EFM32 Tiny Gecko GPIO CTRL bits
 * @{
 */

#define GPIO_CTRL_EM4RET			(1<<0) /**< Retention of states in EM4 */

/** @} */

/** Bit states for the GPIO_CMD register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.22 for definitions and
 * figure 28.5 in case you wonder if that register is mentioned anywhere else
 * at all.
 *
 * @defgroup EFM32TG_GPIO_CMD_bits EFM32 Tiny Gecko GPIO CMD bits
 * @{
 */

#define GPIO_CMD_EM4WUCLR			(1<<0) /**< Write this flag to clear EM4 wakeup requests */

/** @} */

/** Bit states for the GPIO_EM4WUEN register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.23 for definitions, and
 * 28.3.2 for explanations.
 *
 * @defgroup EFM32TG_GPIO_EM4WUEN_bits EFM32 Tiny Gecko GPIO EM4WUEN bits
 * @{
 */

#define GPIO_EM4WUEN_A0			0x01 /**< Wake up from EM4 on A0 activity */
#define GPIO_EM4WUEN_A6			0x02 /**< Wake up from EM4 on A6 activity */
#define GPIO_EM4WUEN_C9			0x04 /**< Wake up from EM4 on C9 activity */
#define GPIO_EM4WUEN_F1			0x08 /**< Wake up from EM4 on F1 activity */
#define GPIO_EM4WUEN_F3			0x10 /**< Wake up from EM4 on F3 activity */
#define GPIO_EM4WUEN_E13		0x20 /**< Wake up from EM4 on E13 activity */

/** @} */

/** Bit states for the GPIO_EM4WUPOL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.24 for definitions, and
 * 28.3.2 for explanations.
 *
 * @defgroup EFM32TG_GPIO_EM4WUPOL_bits EFM32 Tiny Gecko GPIO EM4WUPOL bits
 * @{
 */

#define GPIO_EM4WUPOL_A0		0x01 /**< High wake up from EM4 on A0 */
#define GPIO_EM4WUPOL_A6		0x02 /**< High wake up from EM4 on A6 */
#define GPIO_EM4WUPOL_C9		0x04 /**< High wake up from EM4 on C9 */
#define GPIO_EM4WUPOL_F1		0x08 /**< High wake up from EM4 on F1 */
#define GPIO_EM4WUPOL_F3		0x10 /**< High wake up from EM4 on F3 */
#define GPIO_EM4WUPOL_E13		0x20 /**< High wake up from EM4 on E13 */

/** @} */

/** Bit states for the GPIO_EM4WUCAUSE register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.25 for definitions, and
 * 28.3.2 for explanations.
 *
 * @defgroup EFM32TG_GPIO_EM4WUCAUSE_bits EFM32 Tiny Gecko GPIO EM4WUCAUSE bits
 * @{
 */

#define GPIO_EM4WUCAUSE_A0		0x01 /**< Woke up from EM4 on A0 */
#define GPIO_EM4WUCAUSE_A6		0x02 /**< Woke up from EM4 on A6 */
#define GPIO_EM4WUCAUSE_C9		0x04 /**< Woke up from EM4 on C9 */
#define GPIO_EM4WUCAUSE_F1		0x08 /**< Woke up from EM4 on F1 */
#define GPIO_EM4WUCAUSE_F3		0x10 /**< Woke up from EM4 on F3 */
#define GPIO_EM4WUCAUSE_E13		0x20 /**< Woke up from EM4 on E13 */

/** @} */

/** @} */

//void gpio_set(u32 gpioport, u16 gpios);
//void gpio_clear(u32 gpioport, u16 gpios);
//void gpio_toggle(u32 gpioport, u16 gpios);
//u16 gpio_get(u32 gpioport, u16 gpios);

#endif
