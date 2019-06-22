/** @addtogroup gpio_defines
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#pragma once

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

#define GPIO_P(i)		(GPIO_BASE + (0x24 * (i)))
#define GPIO_PA			GPIO_P(0)
#define GPIO_PB			GPIO_P(1)
#define GPIO_PC			GPIO_P(2)
#define GPIO_PD			GPIO_P(3)
#define GPIO_PE			GPIO_P(4)
#define GPIO_PF			GPIO_P(5)

#define GPIO_P_CTRL(port)	MMIO32((port) + 0x00)
#define GPIO_PA_CTRL		GPIO_P_CTRL(GPIO_PA)
#define GPIO_PB_CTRL		GPIO_P_CTRL(GPIO_PB)
#define GPIO_PC_CTRL		GPIO_P_CTRL(GPIO_PC)
#define GPIO_PD_CTRL		GPIO_P_CTRL(GPIO_PD)
#define GPIO_PE_CTRL		GPIO_P_CTRL(GPIO_PE)
#define GPIO_PF_CTRL		GPIO_P_CTRL(GPIO_PF)

#define GPIO_P_CTRL_DRIVEMODE_SHIFT	(0)
#define GPIO_P_CTRL_DRIVEMODE_MASK	(0x03 << GPIO_P_CTRL_DRIVEMODE_SHIFT)
#define GPIO_P_CTRL_DRIVEMODE(v)	\
	(((v) << GPIO_P_CTRL_DRIVEMODE_SHIFT) & GPIO_P_CTRL_DRIVEMODE_MASK)
#define GPIO_P_CTRL_DRIVEMODE_STANDARD	GPIO_P_CTRL_DRIVEMODE(0)
#define GPIO_P_CTRL_DRIVEMODE_LOWEST	GPIO_P_CTRL_DRIVEMODE(1)
#define GPIO_P_CTRL_DRIVEMODE_HIGH	GPIO_P_CTRL_DRIVEMODE(2)
#define GPIO_P_CTRL_DRIVEMODE_LOW	GPIO_P_CTRL_DRIVEMODE(3)

/* NOTE: GPIO_MODE and GPIO_MODE_MASK is generic.
 * it is used with both GPIO_Px_MODEL and GPIO_Px_MODEH */
#define GPIO_P_MODE_MODEx_MASK(x)	(0x0F << (((x) & 0x7) * 4))
/* for mode: use GPIO_MODE_* */
#define GPIO_P_MODE_MODEx(x, mode)	\
	(((mode) << (((x) & 0x7) * 4)) & GPIO_P_MODE_MODEx_MASK(x))

#define GPIO_P_MODEL(port)	MMIO32((port) + 0x04)
#define GPIO_PA_MODEL		GPIO_P_MODEL(GPIO_PA)
#define GPIO_PB_MODEL		GPIO_P_MODEL(GPIO_PB)
#define GPIO_PC_MODEL		GPIO_P_MODEL(GPIO_PC)
#define GPIO_PD_MODEL		GPIO_P_MODEL(GPIO_PD)
#define GPIO_PE_MODEL		GPIO_P_MODEL(GPIO_PE)

#define GPIO_P_MODEL_MODEx_MASK(x)	GPIO_P_MODE_MODEx_MASK(x)
#define GPIO_P_MODEL_MODEx(x, mode)	GPIO_P_MODE_MODEx(x, mode)

#define GPIO_P_MODEL_MODE0_MASK		GPIO_P_MODEL_MODEx_MASK(0)
#define GPIO_P_MODEL_MODE0(mode)	GPIO_P_MODEL_MODEx(0, mode)

#define GPIO_P_MODEL_MODE1_MASK		GPIO_P_MODEL_MODEx_MASK(1)
#define GPIO_P_MODEL_MODE1(mode)	GPIO_P_MODEL_MODEx(1, mode)

#define GPIO_P_MODEL_MODE2_MASK		GPIO_P_MODEL_MODEx_MASK(2)
#define GPIO_P_MODEL_MODE2(mode)	GPIO_P_MODEL_MODEx(2, mode)

#define GPIO_P_MODEL_MODE3_MASK		GPIO_P_MODEL_MODEx_MASK(3)
#define GPIO_P_MODEL_MODE3(mode)	GPIO_P_MODEL_MODEx(3, mode)

#define GPIO_P_MODEL_MODE4_MASK		GPIO_P_MODEL_MODEx_MASK(4)
#define GPIO_P_MODEL_MODE4(mode)	GPIO_P_MODEL_MODEx(4, mode)

#define GPIO_P_MODEL_MODE5_MASK		GPIO_P_MODEL_MODEx_MASK(5)
#define GPIO_P_MODEL_MODE5(mode)	GPIO_P_MODEL_MODEx(5, mode)

#define GPIO_P_MODEL_MODE6_MASK		GPIO_P_MODEL_MODEx_MASK(6)
#define GPIO_P_MODEL_MODE6(mode)	GPIO_P_MODEL_MODEx(6, mode)

#define GPIO_P_MODEL_MODE7_MASK		GPIO_P_MODEL_MODEx_MASK(7)
#define GPIO_P_MODEL_MODE7(mode)	GPIO_P_MODEL_MODEx(7, mode)

#define GPIO_P_MODEH(port)		MMIO32((port) + 0x08)
#define GPIO_PA_MODEH			GPIO_P_MODEH(GPIO_PA)
#define GPIO_PB_MODEH			GPIO_P_MODEH(GPIO_PB)
#define GPIO_PC_MODEH			GPIO_P_MODEH(GPIO_PC)
#define GPIO_PD_MODEH			GPIO_P_MODEH(GPIO_PD)
#define GPIO_PE_MODEH			GPIO_P_MODEH(GPIO_PE)

/* note: (x - 8) is because for MODEH, MODE8 refers to offset 0 */
#define GPIO_P_MODEH_MODEx_MASK(x)	GPIO_P_MODE_MODEx_MASK((x) - 8)
#define GPIO_P_MODEH_MODEx(x, mode)	GPIO_P_MODE_MODEx((x) - 8, mode)

#define GPIO_P_MODEH_MODE8_MASK		GPIO_P_MODEH_MODEx_MASK(8)
#define GPIO_P_MODEH_MODE8(mode)	GPIO_P_MODEH_MODEx(8, mode)

#define GPIO_P_MODEH_MODE9_MASK		GPIO_P_MODEH_MODEx_MASK(9)
#define GPIO_P_MODEH_MODE9(mode)	GPIO_P_MODEH_MODEx(9, mode)

#define GPIO_P_MODEH_MODE10_MASK	GPIO_P_MODEH_MODEx_MASK(10)
#define GPIO_P_MODEH_MODE10(mode)	GPIO_P_MODEH_MODEx(10, mode)

#define GPIO_P_MODEH_MODE11_MASK	GPIO_P_MODEH_MODEx_MASK(11)
#define GPIO_P_MODEH_MODE11(mode)	GPIO_P_MODEH_MODEx(11, mode)

#define GPIO_P_MODEH_MODE12_MASK	GPIO_P_MODEH_MODEx_MASK(12)
#define GPIO_P_MODEH_MODE12(mode)	GPIO_P_MODEH_MODEx(12, mode)

#define GPIO_P_MODEH_MODE13_MASK	GPIO_P_MODEH_MODEx_MASK(13)
#define GPIO_P_MODEH_MODE13(mode)	GPIO_P_MODEH_MODEx(13, mode)

#define GPIO_P_MODEH_MODE14_MASK	GPIO_P_MODEH_MODEx_MASK(14)
#define GPIO_P_MODEH_MODE14(mode)	GPIO_P_MODEH_MODEx(14, mode)

#define GPIO_P_MODEH_MODE15_MASK	GPIO_P_MODEH_MODEx_MASK(15)
#define GPIO_P_MODEH_MODE15(mode)	GPIO_P_MODEH_MODEx(15, mode)

#define GPIO_P_DOUT(port)		MMIO32((port) + 0x0C)
#define GPIO_PA_DOUT			GPIO_P_DOUT(GPIO_PA)
#define GPIO_PB_DOUT			GPIO_P_DOUT(GPIO_PB)
#define GPIO_PC_DOUT			GPIO_P_DOUT(GPIO_PC)
#define GPIO_PD_DOUT			GPIO_P_DOUT(GPIO_PD)
#define GPIO_PE_DOUT			GPIO_P_DOUT(GPIO_PE)

#define GPIO_P_DOUTSET(port)		MMIO32((port) + 0x10)
#define GPIO_PA_DOUTSET			GPIO_P_DOUTSET(GPIO_PA)
#define GPIO_PB_DOUTSET			GPIO_P_DOUTSET(GPIO_PB)
#define GPIO_PC_DOUTSET			GPIO_P_DOUTSET(GPIO_PC)
#define GPIO_PD_DOUTSET			GPIO_P_DOUTSET(GPIO_PD)
#define GPIO_PE_DOUTSET			GPIO_P_DOUTSET(GPIO_PE)

#define GPIO_P_DOUTCLR(port)		MMIO32((port) + 0x14)
#define GPIO_PA_DOUTCLR			GPIO_P_DOUTCLR(GPIO_PA)
#define GPIO_PB_DOUTCLR			GPIO_P_DOUTCLR(GPIO_PB)
#define GPIO_PC_DOUTCLR			GPIO_P_DOUTCLR(GPIO_PC)
#define GPIO_PD_DOUTCLR			GPIO_P_DOUTCLR(GPIO_PD)
#define GPIO_PE_DOUTCLR			GPIO_P_DOUTCLR(GPIO_PE)

#define GPIO_P_DOUTTGL(port)		MMIO32((port) + 0x18)
#define GPIO_PA_DOUTTGL			GPIO_P_DOUTTGL(GPIO_PA)
#define GPIO_PB_DOUTTGL			GPIO_P_DOUTTGL(GPIO_PB)
#define GPIO_PC_DOUTTGL			GPIO_P_DOUTTGL(GPIO_PC)
#define GPIO_PD_DOUTTGL			GPIO_P_DOUTTGL(GPIO_PD)
#define GPIO_PE_DOUTTGL			GPIO_P_DOUTTGL(GPIO_PE)

#define GPIO_P_DIN(port)		MMIO32((port) + 0x1C)
#define GPIO_PA_DIN			GPIO_P_DIN(GPIO_PA)
#define GPIO_PB_DIN			GPIO_P_DIN(GPIO_PB)
#define GPIO_PC_DIN			GPIO_P_DIN(GPIO_PC)
#define GPIO_PD_DIN			GPIO_P_DIN(GPIO_PD)
#define GPIO_PE_DIN			GPIO_P_DIN(GPIO_PE)

#define GPIO_P_PINLOCKN(port)		MMIO32((port) + 0x20)
#define GPIO_PA_PINLOCKN		GPIO_P_PINLOCKN(GPIO_PA)
#define GPIO_PB_PINLOCKN		GPIO_P_PINLOCKN(GPIO_PB)
#define GPIO_PC_PINLOCKN		GPIO_P_PINLOCKN(GPIO_PC)
#define GPIO_PD_PINLOCKN		GPIO_P_PINLOCKN(GPIO_PD)
#define GPIO_PE_PINLOCKN		GPIO_P_PINLOCKN(GPIO_PE)

#define GPIO_EXTIPSELL			MMIO32(GPIO_BASE + 0x100)
#define GPIO_EXTIPSELH			MMIO32(GPIO_BASE + 0x104)
#define GPIO_EXTIRISE			MMIO32(GPIO_BASE + 0x108)
#define GPIO_EXTIFALL			MMIO32(GPIO_BASE + 0x10C)
#define GPIO_IEN			MMIO32(GPIO_BASE + 0x110)
#define GPIO_IF				MMIO32(GPIO_BASE + 0x114)
#define GPIO_IFS			MMIO32(GPIO_BASE + 0x118)
#define GPIO_IFC			MMIO32(GPIO_BASE + 0x11C)
#define GPIO_ROUTE			MMIO32(GPIO_BASE + 0x120)
#define GPIO_INSENSE			MMIO32(GPIO_BASE + 0x124)
#define GPIO_LOCK			MMIO32(GPIO_BASE + 0x128)
#define GPIO_CTRL			MMIO32(GPIO_BASE + 0x12C)
#define GPIO_CMD			MMIO32(GPIO_BASE + 0x130)
#define GPIO_EM4WUEN			MMIO32(GPIO_BASE + 0x134)
#define GPIO_EM4WUPOL			MMIO32(GPIO_BASE + 0x138)
#define GPIO_EM4WUCAUSE			MMIO32(GPIO_BASE + 0x13C)

/* mask is performed so that can be used with L and H */
#define GPIO_EXTIPSEL_MASK(n)		(0x7 << ((n) & 0xF))
#define GPIO_EXTIPSEL_PORTMASK(n, v)	((v) << ((n) & 0xF))
#define GPIO_EXTIPSEL_PORTA		0x0
#define GPIO_EXTIPSEL_PORTB		0x1
#define GPIO_EXTIPSEL_PORTC		0x2
#define GPIO_EXTIPSEL_PORTD		0x3
#define GPIO_EXTIPSEL_PORTE		0x4
#define GPIO_EXTIPSEL_PORTF		0x5

#define GPIO_ROUTE_SWCLKPEN		(1 << 0)
#define GPIO_ROUTE_SWDIOPEN		(1 << 1)
#define GPIO_ROUTE_SWOPEN		(1 << 3)

#define GPIO_ROUTE_SWLOCATION_SHIFT	(8)
#define GPIO_ROUTE_SWLOCATION_MASK	(0x3 << GPIO_ROUTE_SWLOCATION_SHIFT)
#define GPIO_ROUTE_SWLOCATION(v)	\
	(((v) << GPIO_ROUTE_SWLOCATION_SHIFT) & GPIO_ROUTE_SWLOCATION_MASK)

#define GPIO_ROUTE_TCLKPEN		(1 << 12)
#define GPIO_ROUTE_TD0PEN		(1 << 13)
#define GPIO_ROUTE_TD1PEN		(1 << 14)
#define GPIO_ROUTE_TD2PEN		(1 << 15)
#define GPIO_ROUTE_TD3PEN		(1 << 16)

#define GPIO_ROUTE_ETMLOCATION_SHIFT	(24)
#define GPIO_ROUTE_ETMLOCATION_MASK	(0x3 << GPIO_ROUTE_ETMLOCATION_SHIFT)
#define GPIO_ROUTE_ETMLOCATION(v)	\
	(((v) << GPIO_ROUTE_ETMLOCATION_SHIFT) & GPIO_ROUTE_ETMLOCATION_MASK)
#define GPIO_ROUTE_ETMLOCATION_LOCx(x)	GPIO_ROUTE_ETMLOCATION(x)
#define GPIO_ROUTE_ETMLOCATION_LOC0	GPIO_ROUTE_ETMLOCATION_LOCx(0)
#define GPIO_ROUTE_ETMLOCATION_LOC1	GPIO_ROUTE_ETMLOCATION_LOCx(1)
#define GPIO_ROUTE_ETMLOCATION_LOC2	GPIO_ROUTE_ETMLOCATION_LOCx(2)
#define GPIO_ROUTE_ETMLOCATION_LOC3	GPIO_ROUTE_ETMLOCATION_LOCx(3)

#define GPIO_INSENSE_INT		(1 << 0)
#define GPIO_INSENSE_PRS		(1 << 1)

#define GPIO_LOCK_LOCKKEY_SHIFT		(0)
#define GPIO_LOCK_LOCKKEY_MASK		(0xFFFF << GPIO_LOCK_LOCKKEY_SHIFT)
#define GPIO_LOCK_LOCKKEY_UNLOCKED	(0x0000 << GPIO_LOCK_LOCKKEY_SHIFT)
#define GPIO_LOCK_LOCKKEY_LOCKED	(0x0001 << GPIO_LOCK_LOCKKEY_SHIFT)
#define GPIO_LOCK_LOCKKEY_LOCK		(0x0000 << GPIO_LOCK_LOCKKEY_SHIFT)
#define GPIO_LOCK_LOCKKEY_UNLOCK	(0xA534 << GPIO_LOCK_LOCKKEY_SHIFT)

#define GPIO_CTRL_EM4RET		(1 << 0)

#define GPIO_CMD_EM4WUCLR		(1 << 0)

#define GPIO_EM4WUEN_EM4WUEN_A0		(1 << 0)
#define GPIO_EM4WUEN_EM4WUEN_A6		(1 << 1)
#define GPIO_EM4WUEN_EM4WUEN_C9		(1 << 2)
#define GPIO_EM4WUEN_EM4WUEN_F1		(1 << 3)
#define GPIO_EM4WUEN_EM4WUEN_F2		(1 << 4)
#define GPIO_EM4WUEN_EM4WUEN_E13	(1 << 5)

#define GPIO_EM4WUPOL_EM4WUPOL_A0	(1 << 0)
#define GPIO_EM4WUPOL_EM4WUPOL_A6	(1 << 1)
#define GPIO_EM4WUPOL_EM4WUPOL_C9	(1 << 2)
#define GPIO_EM4WUPOL_EM4WUPOL_F1	(1 << 3)
#define GPIO_EM4WUPOL_EM4WUPOL_F2	(1 << 4)
#define GPIO_EM4WUPOL_EM4WUPOL_E13	(1 << 5)

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
#define GPIO_ALL			(0xFFFF)

/* These are the acceptable mode values.
 *   (+ readable counterparts)
 *  do not confuse GPIO_MODE_* for GPIO_P_MODE_MODEx.
 */
enum gpio_mode {
	GPIO_MODE_DISABLE = 0,
	GPIO_MODE_INPUT,
	GPIO_MODE_INPUT_PULL,
	GPIO_MODE_INPUT_PULL_FILTER,
	GPIO_MODE_PUSH_PULL,
	GPIO_MODE_PUSH_PULL_DRIVE,
	GPIO_MODE_WIRED_OR,
	GPIO_MODE_WIRED_OR_PULL_DOWN,
	GPIO_MODE_WIRED_AND,
	GPIO_MODE_WIRED_AND_FILTER,
	GPIO_MODE_WIRED_AND_PULLUP,
	GPIO_MODE_WIRED_AND_PULLUP_FILTER,
	GPIO_MODE_WIRED_AND_DRIVE,
	GPIO_MODE_WIRED_AND_DRIVE_FILTER,
	GPIO_MODE_WIRED_AND_DRIVE_PULLUP,
	GPIO_MODE_WIRED_AND_DRIVE_PULLUP_FILTER
};

/* for readability. */
enum gpio_drive_strength {
	GPIO_STRENGTH_STANDARD = 0,
	GPIO_STRENGTH_LOWEST,
	GPIO_STRENGTH_HIGH,
	GPIO_STRENGTH_LOW
};

/* for readability */
#define GPIOA GPIO_PA
#define GPIOB GPIO_PB
#define GPIOC GPIO_PC
#define GPIOD GPIO_PD
#define GPIOE GPIO_PE
#define GPIOF GPIO_PF

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void gpio_enable_lock(void);
void gpio_disable_lock(void);
bool gpio_get_lock_flag(void);

void gpio_set_drive_strength(uint32_t gpio_port,
		enum gpio_drive_strength driver_stength);
void gpio_mode_setup(uint32_t gpio_port, enum gpio_mode mode, uint16_t gpios);

void gpio_set(uint32_t gpio_port, uint16_t gpios);
void gpio_clear(uint32_t gpio_port, uint16_t gpios);
uint16_t gpio_get(uint32_t gpio_port, uint16_t gpios);
void gpio_toggle(uint32_t gpio_port, uint16_t gpios);
uint16_t gpio_port_read(uint32_t gpio_port);
void gpio_port_write(uint32_t gpio_port, uint16_t data);

void gpio_port_config_lock(uint32_t gpio_port, uint16_t gpios);

END_DECLS

/**@}*/