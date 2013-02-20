/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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

#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/f3/syscfg.h>
#include <libopencm3/stm32/gpio.h>

void exti_set_trigger(u32 extis, exti_trigger_type trig)
{
	switch (trig) {
	case EXTI_TRIGGER_RISING:
		EXTI_RTSR1 |= extis;
		EXTI_FTSR1 &= ~extis;
		break;
	case EXTI_TRIGGER_FALLING:
		EXTI_RTSR1 &= ~extis;
		EXTI_FTSR1 |= extis;
		break;
	case EXTI_TRIGGER_BOTH:
		EXTI_RTSR1 |= extis;
		EXTI_FTSR1 |= extis;
		break;
	}
}

void exti_enable_request(u32 extis)
{
	/* Enable interrupts. */
	EXTI_IMR1 |= extis;

	/* Enable events. */
	EXTI_EMR1 |= extis;
}

void exti_disable_request(u32 extis)
{
	/* Disable interrupts. */
	EXTI_IMR1 &= ~extis;

	/* Disable events. */
	EXTI_EMR1 &= ~extis;
}

/*
 * Reset the interrupt request by writing a 1 to the corresponding
 * pending bit register.
 */
void exti_reset_request(u32 extis)
{
	EXTI_PR1 = extis;
}

/*
 * Remap an external interrupt line to the corresponding pin on the
 * specified GPIO port.
 *
 * TODO: This could be rewritten in fewer lines of code.
 */
void exti_select_source(u32 exti, u32 gpioport)
{
	u8 shift, bits;

	shift = bits = 0;

	switch (exti) {
	case EXTI0:
	case EXTI4:
	case EXTI8:
	case EXTI12:
		shift = 0;
		break;
	case EXTI1:
	case EXTI5:
	case EXTI9:
	case EXTI13:
		shift = 4;
		break;
	case EXTI2:
	case EXTI6:
	case EXTI10:
	case EXTI14:
		shift = 8;
		break;
	case EXTI3:
	case EXTI7:
	case EXTI11:
	case EXTI15:
		shift = 12;
		break;
	}

	switch (gpioport) {
	case GPIOA:
		bits = 0xf;
		break;
	case GPIOB:
		bits = 0xe;
		break;
	case GPIOC:
		bits = 0xd;
		break;
	case GPIOD:
		bits = 0xc;
		break;
	case GPIOE:
		bits = 0xb;
		break;
	case GPIOF:
		bits = 0xa;
		break;
	}

	/* Ensure that only valid EXTI lines are used. */
	if (exti < EXTI4) {
		SYSCFG_EXTICR1 &= ~(0x000F << shift);
		SYSCFG_EXTICR1 |= (~bits << shift);
	} else if (exti < EXTI8) {
		SYSCFG_EXTICR2 &= ~(0x000F << shift);
		SYSCFG_EXTICR2 |= (~bits << shift);
	} else if (exti < EXTI12) {
		SYSCFG_EXTICR3 &= ~(0x000F << shift);
		SYSCFG_EXTICR3 |= (~bits << shift);
	} else if (exti < EXTI16) {
		SYSCFG_EXTICR4 &= ~(0x000F << shift);
		SYSCFG_EXTICR4 |= (~bits << shift);
	}
}
