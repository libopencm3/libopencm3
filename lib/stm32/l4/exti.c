/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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
 *
 * This provides the code for the EXTI block provided in L4
 * devices.
 */
/**@{*/


#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/syscfg.h>

void exti_set_trigger(uint8_t exti, enum exti_trigger_type trig)
{
	uint32_t reg32_rtsr;
	uint32_t reg32_ftsr;
	uint8_t exti_shift = exti;

	if (exti < 32) {
		reg32_rtsr = EXTI_RTSR1;
		reg32_ftsr = EXTI_FTSR1;
	} else {
		reg32_rtsr = EXTI_RTSR2;
		reg32_ftsr = EXTI_FTSR2;
		exti_shift -= 32;
	}

	switch (trig) {
	case EXTI_TRIGGER_RISING:
		reg32_rtsr |= (1 << exti_shift);
		reg32_ftsr &= ~(1 << exti_shift);
		break;
	case EXTI_TRIGGER_FALLING:
		reg32_rtsr &= ~(1 << exti_shift);
		reg32_ftsr |= (1 << exti_shift);
		break;
	case EXTI_TRIGGER_BOTH:
		reg32_rtsr |= (1 << exti_shift);
		reg32_ftsr |= (1 << exti_shift);
		break;
	}
}

void exti_enable_request(uint8_t exti)
{
	uint32_t reg32_imr;
	uint32_t reg32_emr;
	uint8_t exti_shift = exti;

	if (exti < 32) {
		reg32_imr = EXTI_IMR1;
		reg32_emr = EXTI_EMR1;
	} else {
		reg32_imr = EXTI_IMR2;
		reg32_emr = EXTI_EMR2;
		exti_shift -= 32;
	}

	/* Enable interrupts. */
	reg32_imr |= (1 << exti_shift);

	/* Enable events. */
	reg32_emr |= (1 << exti_shift);
}

void exti_disable_request(uint8_t exti)
{
	uint32_t reg32_imr;
	uint32_t reg32_emr;
	uint8_t exti_shift = exti;

	if (exti < 32) {
		reg32_imr = EXTI_IMR1;
		reg32_emr = EXTI_EMR1;
	} else {
		reg32_imr = EXTI_IMR2;
		reg32_emr = EXTI_EMR2;
		exti_shift -= 32;
	}

	/* Disable interrupts. */
	reg32_imr &= ~(1 << exti_shift);

	/* Disable events. */
	reg32_emr &= ~(1 << exti_shift);
}

/*
 * Reset the interrupt request by writing a 1 to the corresponding
 * pending bit register.
 */
void exti_reset_request(uint8_t exti)
{
	uint32_t reg32_pr;
	uint8_t exti_shift = exti;

	if (exti < 32) {
		reg32_pr = EXTI_PR1;
	} else {
		reg32_pr = EXTI_PR2;
		exti_shift -= 32;
	}

	reg32_pr = (1 << exti_shift);

	/* Overcome the compile error */
	reg32_pr = reg32_pr;
}

/*
 * Check the flag of a given EXTI interrupt.
 * */
uint32_t exti_get_flag_status(uint8_t exti)
{
	uint32_t reg32_pr;
	uint8_t exti_shift = exti;

	if (exti < 32) {
		reg32_pr = EXTI_PR1;
	} else {
		reg32_pr = EXTI_PR2;
		exti_shift -= 32;
	}

	return reg32_pr & (1 << exti_shift);
}

/*
 * Remap an external interrupt line to the corresponding pin on the
 * specified GPIO port.
 *
 * exti should be a number 0 to 15 - corresponds with EXTI0 - EXTI15
 * gpioport should be SYSCFG_EXTICR_GPIOX (A - G)
 */
void exti_select_source(uint8_t exti, uint8_t gpioport)
{
	uint8_t shift = (uint8_t)(4 * (exti % 4));
	uint8_t reg = exti / 4;

	SYSCFG_EXTICR(reg) = (SYSCFG_EXTICR(reg) & ~(SYSCFG_EXTICR_MASK << shift)) | (gpioport << shift);
}
/**@}*/
