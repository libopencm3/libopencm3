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
 * @see EFM32TG_GPIO
 */

/** Definitions for the GPIO subsystem (General Purpose Input Output).
 *
 * This corresponds to the description in d0034_efm32tg_reference_manual.pdf
 * section 28.
 *
 * @ingroup EFM32TG
 * @defgroup EFM32TG_GPIO GPIO (General Purpose Input Output)
 * @{
 */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_GPIO_H
#define LIBOPENCM3_EFM32_TINYGECKO_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>

/** Register definitions and register value definitions for the GPIO subsystem
 *
 * @defgroup EFM32TG_GPIO_regsandvals GPIO registers and values
 * @{
 */

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 28.4
 *
 * The bulk of the registers defined here (like GPIO_PA_CTRL) will not be used
 * inside the convenience functions, but are provided for direct access.
 *
 * @todo This section could profit from bit-banding.
 *
 * @defgroup EFM32TG_GPIO_registers GPIO registers
 * @{
 */
#define GPIO_Px_CTRL(port)	MMIO32(port + 0x000) /**< @see EFM32TG_GPIO_Px_CTRL_bits */
#define GPIO_Px_MODEL(port)	MMIO32(port + 0x004) /**< @see EFM32TG_GPIO_MODE_values */
#define GPIO_Px_MODEH(port)	MMIO32(port + 0x008) /**< @see EFM32TG_GPIO_MODE_values */
#define GPIO_Px_DOUT(port)	MMIO32(port + 0x00C) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_Px_DOUTSET(port)	MMIO32(port + 0x010) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_Px_DOUTCLR(port)	MMIO32(port + 0x014) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_Px_DOUTTGL(port)	MMIO32(port + 0x018) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_Px_DIN(port)	MMIO32(port + 0x01C) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_Px_PINLOCKN(port)	MMIO32(port + 0x020) /**< @see EFM32TG_GPIO_pinnumberbits */

#define GPIO_PA			(GPIO_BASE + 0x000)
#define GPIO_PA_CTRL		GPIO_Px_CTRL(GPIO_PA)
#define GPIO_PA_MODEL		GPIO_Px_MODEL(GPIO_PA)
#define GPIO_PA_MODEH		GPIO_Px_MODEH(GPIO_PA)
#define GPIO_PA_DOUT		GPIO_Px_DOUT(GPIO_PA)
#define GPIO_PA_DOUTSET		GPIO_Px_DOUTSET(GPIO_PA)
#define GPIO_PA_DOUTCLR		GPIO_Px_DOUTCLR(GPIO_PA)
#define GPIO_PA_DOUTTGL		GPIO_Px_DOUTTGL(GPIO_PA)
#define GPIO_PA_DIN		GPIO_Px_DIN(GPIO_PA)
#define GPIO_PA_PINLOCKN	GPIO_Px_PINLOCKN(GPIO_PA)

#define GPIO_PB			(GPIO_BASE + 0x024)
#define GPIO_PB_CTRL		GPIO_Px_CTRL(GPIO_PB)
#define GPIO_PB_MODEL		GPIO_Px_MODEL(GPIO_PB)
#define GPIO_PB_MODEH		GPIO_Px_MODEH(GPIO_PB)
#define GPIO_PB_DOUT		GPIO_Px_DOUT(GPIO_PB)
#define GPIO_PB_DOUTSET		GPIO_Px_DOUTSET(GPIO_PB)
#define GPIO_PB_DOUTCLR		GPIO_Px_DOUTCLR(GPIO_PB)
#define GPIO_PB_DOUTTGL		GPIO_Px_DOUTTGL(GPIO_PB)
#define GPIO_PB_DIN		GPIO_Px_DIN(GPIO_PB)
#define GPIO_PB_PINLOCKN	GPIO_Px_PINLOCKN(GPIO_PB)

#define GPIO_PC			(GPIO_BASE + 0x048)
#define GPIO_PC_CTRL		GPIO_Px_CTRL(GPIO_PC)
#define GPIO_PC_MODEL		GPIO_Px_MODEL(GPIO_PC)
#define GPIO_PC_MODEH		GPIO_Px_MODEH(GPIO_PC)
#define GPIO_PC_DOUT		GPIO_Px_DOUT(GPIO_PC)
#define GPIO_PC_DOUTSET		GPIO_Px_DOUTSET(GPIO_PC)
#define GPIO_PC_DOUTCLR		GPIO_Px_DOUTCLR(GPIO_PC)
#define GPIO_PC_DOUTTGL		GPIO_Px_DOUTTGL(GPIO_PC)
#define GPIO_PC_DIN		GPIO_Px_DIN(GPIO_PC)
#define GPIO_PC_PINLOCKN	GPIO_Px_PINLOCKN(GPIO_PC)

#define GPIO_PD			(GPIO_BASE + 0x06C)
#define GPIO_PD_CTRL		GPIO_Px_CTRL(GPIO_PD)
#define GPIO_PD_MODEL		GPIO_Px_MODEL(GPIO_PD)
#define GPIO_PD_MODEH		GPIO_Px_MODEH(GPIO_PD)
#define GPIO_PD_DOUT		GPIO_Px_DOUT(GPIO_PD)
#define GPIO_PD_DOUTSET		GPIO_Px_DOUTSET(GPIO_PD)
#define GPIO_PD_DOUTCLR		GPIO_Px_DOUTCLR(GPIO_PD)
#define GPIO_PD_DOUTTGL		GPIO_Px_DOUTTGL(GPIO_PD)
#define GPIO_PD_DIN		GPIO_Px_DIN(GPIO_PD)
#define GPIO_PD_PINLOCKN	GPIO_Px_PINLOCKN(GPIO_PD)

#define GPIO_PE			(GPIO_BASE + 0x090)
#define GPIO_PE_CTRL		GPIO_Px_CTRL(GPIO_PE)
#define GPIO_PE_MODEL		GPIO_Px_MODEL(GPIO_PE)
#define GPIO_PE_MODEH		GPIO_Px_MODEH(GPIO_PE)
#define GPIO_PE_DOUT		GPIO_Px_DOUT(GPIO_PE)
#define GPIO_PE_DOUTSET		GPIO_Px_DOUTSET(GPIO_PE)
#define GPIO_PE_DOUTCLR		GPIO_Px_DOUTCLR(GPIO_PE)
#define GPIO_PE_DOUTTGL		GPIO_Px_DOUTTGL(GPIO_PE)
#define GPIO_PE_DIN		GPIO_Px_DIN(GPIO_PE)
#define GPIO_PE_PINLOCKN	GPIO_Px_PINLOCKN(GPIO_PE)

#define GPIO_PF			(GPIO_BASE + 0x0B4)
#define GPIO_PF_CTRL		GPIO_Px_CTRL(GPIO_PF)
#define GPIO_PF_MODEL		GPIO_Px_MODEL(GPIO_PF)
#define GPIO_PF_MODEH		GPIO_Px_MODEH(GPIO_PF)
#define GPIO_PF_DOUT		GPIO_Px_DOUT(GPIO_PF)
#define GPIO_PF_DOUTSET		GPIO_Px_DOUTSET(GPIO_PF)
#define GPIO_PF_DOUTCLR		GPIO_Px_DOUTCLR(GPIO_PF)
#define GPIO_PF_DOUTTGL		GPIO_Px_DOUTTGL(GPIO_PF)
#define GPIO_PF_DIN		GPIO_Px_DIN(GPIO_PF)
#define GPIO_PF_PINLOCKN	GPIO_Px_PINLOCKN(GPIO_PF)

#define GPIO_EXTIPSELL		MMIO32(GPIO_BASE + 0x100) /**< @see EFM32TG_GPIO_EXTIP_values */
#define GPIO_EXTIPSELH		MMIO32(GPIO_BASE + 0x104) /**< @see EFM32TG_GPIO_EXTIP_values */
#define GPIO_EXTIRISE		MMIO32(GPIO_BASE + 0x108) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_EXTIFALL		MMIO32(GPIO_BASE + 0x10C) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_IEN		MMIO32(GPIO_BASE + 0x110) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_IF			MMIO32(GPIO_BASE + 0x114) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_IFS		MMIO32(GPIO_BASE + 0x118) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_IFC		MMIO32(GPIO_BASE + 0x11C) /**< @see EFM32TG_GPIO_pinnumberbits */
#define GPIO_ROUTE		MMIO32(GPIO_BASE + 0x120) /**< @see EFM32TG_GPIO_ROUTE_bits */
#define GPIO_INSENSE		MMIO32(GPIO_BASE + 0x124) /**< @see EFM32TG_GPIO_INSENSE_bits */
#define GPIO_LOCK		MMIO32(GPIO_BASE + 0x128) /**< @see EFM32TG_GPIO_LOCK_values */
#define GPIO_CTRL		MMIO32(GPIO_BASE + 0x12C) /**< @see EFM32TG_GPIO_CTRL_bits */
#define GPIO_CMD		MMIO32(GPIO_BASE + 0x130) /**< @see EFM32TG_GPIO_CMD_bits */
#define GPIO_EM4WUEN		MMIO32(GPIO_BASE + 0x134) /**< @see EFM32TG_GPIO_EM4WUEN_bits */
#define GPIO_EM4WUPOL		MMIO32(GPIO_BASE + 0x138) /**< @see EFM32TG_GPIO_EM4WUPOL_bits */
#define GPIO_EM4WUCAUSE		MMIO32(GPIO_BASE + 0x13C) /**< @see EFM32TG_GPIO_EM4WUCAUSE_bits */

/** @} */

/** Pin number bits
 *
 * Provided for convenience. They can be used on the GPIO_Px_DOUT,
 * GPIO_Px_DOUTSET, GPIO_Px_DOUTCLR, GPIO_Px_DOUTTGL, GPIO_Px_DIN,
 * GPIO_Px_PINLOCKN, GPIO_Px_EXTIRISE, GPIO_Px_EXTIFALL, GPIO_IEN, GPIO_IF,
 * GPIO_IFS, and GPIO_IFC registers.
 *
 * @defgroup EFM32TG_GPIO_pinnumberbits GPIO pin number bits
 * @{
 */

#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO8				(1 << 8)
#define GPIO9				(1 << 9)
#define GPIO10				(1 << 10)
#define GPIO11				(1 << 11)
#define GPIO12				(1 << 12)
#define GPIO13				(1 << 13)
#define GPIO14				(1 << 14)
#define GPIO15				(1 << 15)
#define GPIO_ALL			0xffff

/** @} */

/** Bit states for the GPIO_Px_CTRL register
 *
 * They are named as in d0034_efm32tg_reference_manual.pdf's section
 * 28.5.1.
 *
 * @defgroup EFM32TG_GPIO_Px_CTRL_bits GPIO Px CTRL bits
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
 * @defgroup EFM32TG_GPIO_MODE_values GPIO MODE values
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
#define GPIO_MODE_MASK				0x0f

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
 * @defgroup EFM32TG_GPIO_EXTIP_values GPIO EXTIPSEL values
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
 * @defgroup EFM32TG_GPIO_ROUTE_bits GPIO ROUTE bits
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
 * @defgroup EFM32TG_GPIO_INSENSE_bits GPIO INSENSE bits
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
 * @defgroup EFM32TG_GPIO_LOCK_values GPIO LOCK bits
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
 * @defgroup EFM32TG_GPIO_CTRL_bits GPIO CTRL bits
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
 * @defgroup EFM32TG_GPIO_CMD_bits GPIO CMD bits
 * @{
 */

#define GPIO_CMD_EM4WUCLR			(1<<0) /**< Write this flag to clear EM4 wakeup requests */

/** @} */

/** Bit states for the GPIO_EM4WUEN register
 *
 * See d0034_efm32tg_reference_manual.pdf section 28.5.23 for definitions, and
 * 28.3.2 for explanations.
 *
 * @defgroup EFM32TG_GPIO_EM4WUEN_bits GPIO EM4WUEN bits
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
 * @defgroup EFM32TG_GPIO_EM4WUPOL_bits GPIO EM4WUPOL bits
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
 * @defgroup EFM32TG_GPIO_EM4WUCAUSE_bits GPIO EM4WUCAUSE bits
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

/** GPIO convenience functions
 *
 * These functions try to be close to the STM32 F1 utility functions where
 * possible.
 *
 * The functions intentionally don't cover all the possible read- and write
 * operations to the GPIO registers. For example, reading the configured output
 * strength for a port is rarely required.
 *
 * Many convenience functions are static to allow inlining by the compiler.
 *
 * @todo Implement all the non-trivial but useful convenience functions.
 *
 * @defgroup EFM32TG_GPIO_convenience GPIO convenience functions
 * @{
 */

/** Set a whole GPIO port's out data to a particular value
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param gpios Bit pattern the output of the port will be configured to (eg GPIO6|GPIO3 to switch pins 6 and 3 to high and all the others to low)
 */
static void gpio_port_write(u32 gpioport, u16 data)
{
	GPIO_Px_DOUT(gpioport) = data;
}
/** Set some bits in a GPIO port's out data
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param gpios GPIO pin(s) to be set to 1 (eg GPIO6|GPIO3 to switch pins 6 and 3 to high and leave all the others in their previous state)
 */
static void gpio_set(u32 gpioport, u16 gpios)
{
	GPIO_Px_DOUTSET(gpioport) = gpios;
}
/** Clear some bits in a GPIO port's out data
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param gpios GPIO pin(s) to be set to 0 (eg GPIO6|GPIO3 to switch pins 6 and 3 to low and leave all the others in their previous state)
 */
static void gpio_clear(u32 gpioport, u16 gpios)
{
	GPIO_Px_DOUTCLR(gpioport) = gpios;
}
/** Toggle some bits in a GPIO port's out data
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param gpios GPIO pin(s) that will be toggled (eg GPIO6|GPIO3 to toggle the output directions of pins 6 and 3 and leave all the others in their previous state)
 */
static void gpio_toggle(u32 gpioport, u16 gpios)
{
	GPIO_Px_DOUTTGL(gpioport) = gpios;
}

/** Read input bits from a GPIO's port in data
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \returns Current value of the in register of the given port
 */
static u16 gpio_port_read(u32 gpioport)
{
	return GPIO_Px_DIN(gpioport);
}
/** Read input bits from a GPIO's port in data
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param gpios Bits that will be read (eg GPIO6|GPIO3 to read pins 6 and 3)
 * \returns Bit pattern that contains 1 in all pin positions that currently read as high (eg GPIO6 if port A's 6th pin is currently high and the 3rd pin is low)
 */
static u16 gpio_get(u32 gpioport, u16 gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

/** Configure a particular pin configuration on one or more pins
 *
 * This function is not atomic. It has to be made sure that it is not
 * interrupted by other code that modifies the port's configuration.
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param mode Pin configuration mode to set (eg GPIO_MODE_INPUT)
 * \param gpios Pins to configure (eg GPIO6|GPIO3 to set the mode on pins 6 and 3)
 */
void gpio_set_mode(u32 gpioport, u8 mode, u16 gpios);

/** Configure the alternate drive strength for a port
 *
 * \param gpioport Address of a GPIO port to use (eg GPIO_PA)
 * \param strength Alternate drive strength to configure for the port (eg GPIO_CTRL_DRIVEMODE_HIGH)
 */
static void gpio_set_strength(u32 gpioport, u8 strength)
{
	GPIO_Px_CTRL(gpioport) = strength;
}

/** @} */

/** @} */

#endif
