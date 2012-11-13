/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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
 *
 * This provides the code for the "next gen" EXTI block provided in F2/F4/L1
 * devices.  (differences only in the source selection)
 */

#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/syscfg.h>
#if defined(STM32F2)
#include <libopencm3/stm32/f2/gpio.h>
#elif defined(STM32F4)
#include <libopencm3/stm32/f4/gpio.h>
#elif defined(STM32L1)
#include <libopencm3/stm32/l1/gpio.h>
#else
#error "invalid/unknown stm32 family for this code"
#endif

void exti_set_trigger(u32 extis, exti_trigger_type trig)
{
	switch (trig) {
	case EXTI_TRIGGER_RISING:
		EXTI_RTSR |= extis;
		EXTI_FTSR &= ~extis;
		break;
	case EXTI_TRIGGER_FALLING:
		EXTI_RTSR &= ~extis;
		EXTI_FTSR |= extis;
		break;
	case EXTI_TRIGGER_BOTH:
		EXTI_RTSR |= extis;
		EXTI_FTSR |= extis;
		break;
	}
}

void exti_enable_request(u32 extis)
{
	/* Enable interrupts. */
	EXTI_IMR |= extis;

	/* Enable events. */
	EXTI_EMR |= extis;
}

void exti_disable_request(u32 extis)
{
	/* Disable interrupts. */
	EXTI_IMR &= ~extis;

	/* Disable events. */
	EXTI_EMR &= ~extis;
}

/*
 * Reset the interrupt request by writing a 1 to the corresponding
 * pending bit register.
 */
void exti_reset_request(u32 extis)
{
	EXTI_PR = extis;
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
#if defined(STM32L1)
#else
	case GPIOF:
		bits = 0xa;
		break;
	case GPIOG:
		bits = 0x9;
		break;
#endif
	case GPIOH:
		bits = 0x8;
		break;
#if defined(STM32L1)
#else
	case GPIOI:
		bits = 0x7;
		break;
#endif
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
