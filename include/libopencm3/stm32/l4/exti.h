/** @defgroup exti_defines EXTI Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx External Interrupts
 * </b>
 *
 * @ingroup STM32L4xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Piotr Esden-Tempski <piotr@esden.net>
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Benjamin Levine <benjaminmileslevine@gmail.com>
 *
 * @version 1.0.0
 *
 * @date 19 February 2016
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
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

#ifndef LIBOPENCM3_EXTI_H
#define LIBOPENCM3_EXTI_H

/* --- EXTI registers ---------------------------------------------------- */

#define EXTI_IMR1			MMIO32(EXTI_BASE + 0x00)
#define EXTI_EMR1			MMIO32(EXTI_BASE + 0x04)
#define EXTI_RTSR1			MMIO32(EXTI_BASE + 0x08)
#define EXTI_FTSR1			MMIO32(EXTI_BASE + 0x0c)
#define EXTI_SWIER1			MMIO32(EXTI_BASE + 0x10)
#define EXTI_PR1			MMIO32(EXTI_BASE + 0x14)
#define EXTI_IMR2			MMIO32(EXTI_BASE + 0x20)
#define EXTI_EMR2			MMIO32(EXTI_BASE + 0x24)
#define EXTI_RTSR2			MMIO32(EXTI_BASE + 0x28)
#define EXTI_FTSR2			MMIO32(EXTI_BASE + 0x2c)
#define EXTI_SWIER2			MMIO32(EXTI_BASE + 0x30)
#define EXTI_PR2			MMIO32(EXTI_BASE + 0x34)

/* EXTI number definitions */
#define EXTI0				(1 << 0)
#define EXTI1				(1 << 1)
#define EXTI2				(1 << 2)
#define EXTI3				(1 << 3)
#define EXTI4				(1 << 4)
#define EXTI5				(1 << 5)
#define EXTI6				(1 << 6)
#define EXTI7				(1 << 7)
#define EXTI8				(1 << 8)
#define EXTI9				(1 << 9)
#define EXTI10				(1 << 10)
#define EXTI11				(1 << 11)
#define EXTI12				(1 << 12)
#define EXTI13				(1 << 13)
#define EXTI14				(1 << 14)
#define EXTI15				(1 << 15)
#define EXTI16				(1 << 16)
#define EXTI17				(1 << 17)
#define EXTI18				(1 << 18)
#define EXTI19				(1 << 19)
#define EXTI20				(1 << 20)
#define EXTI21				(1 << 21)
#define EXTI22				(1 << 22)
#define EXTI23				(1 << 23)
#define EXTI24				(1 << 24)
#define EXTI25				(1 << 25)
#define EXTI26				(1 << 26)
#define EXTI27				(1 << 27)
#define EXTI28				(1 << 28)
#define EXTI29				(1 << 29)
#define EXTI30				(1 << 30)
#define EXTI31				(1 << 31)

#define EXTI32				(1 << 0)
#define EXTI33				(1 << 1)
#define EXTI34				(1 << 2)
#define EXTI35				(1 << 3)
#define EXTI36				(1 << 4)
#define EXTI37				(1 << 5)
#define EXTI38				(1 << 6)
#define EXTI39				(1 << 7)

/* Trigger types */
enum exti_trigger_type {
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH,
};

BEGIN_DECLS

void exti_set_trigger(uint8_t exti, enum exti_trigger_type trig);
void exti_enable_request(uint8_t exti);
void exti_disable_request(uint8_t exti);
void exti_reset_request(uint8_t exti);
void exti_select_source(uint8_t exti, uint8_t gpioport);
uint32_t exti_get_flag_status(uint8_t exti);

END_DECLS

#endif
