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
/**@{*/


#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>
#if !defined(AFIO_BASE)
#       include <libopencm3/stm32/syscfg.h>
#endif

void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig)
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

void exti_enable_request(uint32_t extis)
{
	/* Enable interrupts. */
	EXTI_IMR |= extis;

	/* Enable events. */
	EXTI_EMR |= extis;
}

void exti_disable_request(uint32_t extis)
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
void exti_reset_request(uint32_t extis)
{
	EXTI_PR = extis;
}

/*
 * Check the flag of a given EXTI interrupt.
 * */
uint32_t exti_get_flag_status(uint32_t exti)
{
	return EXTI_PR & exti;
}

/*
 * Remap an external interrupt line to the corresponding pin on the
 * specified GPIO port.
 *
 * TODO: This could be rewritten in fewer lines of code.
 */
void exti_select_source(uint32_t exti, uint32_t gpioport)
{
	uint32_t line;
	for (line = 0; line < 16; line++) {
		if (!(exti & (1 << line))) {
			continue;
		}

		uint32_t bits = 0, mask = 0x0F;

		switch (gpioport) {
		case GPIOA:
			bits = 0;
			break;
		case GPIOB:
			bits = 1;
			break;
		case GPIOC:
			bits = 2;
			break;
		case GPIOD:
			bits = 3;
			break;
#if defined(GPIOE) && defined(GPIO_PORT_E_BASE)
		case GPIOE:
			bits = 4;
			break;
#endif
#if defined(GPIOF) && defined(GPIO_PORT_F_BASE)
		case GPIOF:
			bits = 5;
			break;
#endif
#if defined(GPIOG) && defined(GPIO_PORT_G_BASE)
		case GPIOG:
			bits = 6;
			break;
#endif
#if defined(GPIOH) && defined(GPIO_PORT_H_BASE)
		case GPIOH:
			bits = 7;
			break;
#endif
#if defined(GPIOI) && defined(GPIO_PORT_I_BASE)
		case GPIOI:
			bits = 8;
			break;
#endif
#if defined(GPIOJ) && defined(GPIO_PORT_J_BASE)
		case GPIOJ:
			bits = 9;
			break;
#endif
#if defined(GPIOK) && defined(GPIO_PORT_K_BASE)
		case GPIOK:
			bits = 10;
			break;
#endif
		}

		uint8_t shift = (uint8_t)(4 * (line % 4));
		uint32_t reg = line / 4;
		bits <<= shift;
		mask <<= shift;

#if defined(AFIO_BASE)
		AFIO_EXTICR(reg) = (AFIO_EXTICR(reg) & ~mask) | bits;
#else
		SYSCFG_EXTICR(reg) = (SYSCFG_EXTICR(reg) & ~mask) | bits;
#endif
	};
}
/**@}*/

