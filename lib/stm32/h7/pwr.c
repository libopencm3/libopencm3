/**
 * @brief <b>libopencm3 STM32H7xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @date 16 December, 2019
 *
 * This library supports the power control system for the
 * STM32H7 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
 * Copyright (C) 2019 Brian Viele <vielster@allocor.tech>
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

#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/syscfg.h>


void pwr_set_mode_ldo(void) {
	const uint32_t ldo_mask = (PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	PWR_CR3 = (PWR_CR3 & ~ldo_mask) | (PWR_CR3_SCUEN | PWR_CR3_LDOEN);
	while (!(PWR_CSR1 & PWR_CSR1_ACTVOSRDY));
}

void pwr_set_svos_scale(enum pwr_svos_scale scale)
{
	uint32_t pwr_cr1_reg = PWR_CR1;
	pwr_cr1_reg = (pwr_cr1_reg & ~(PWR_CR1_SVOS_MASK  << PWR_CR1_SVOS_SHIFT));
	PWR_CR1 = pwr_cr1_reg | scale;
}

void pwr_set_vos_scale(enum pwr_vos_scale scale) {
	rcc_periph_clock_enable(RCC_SYSCFG);  /* Ensure we can access ODEN. */
	uint32_t d3cr_masked = PWR_D3CR & ~(PWR_D3CR_VOS_MASK << PWR_D3CR_VOS_SHIFT);

	/* Per the manual, VOS0 is implemented as VOS1 + ODEN. Handle this case. */
	if (scale == PWR_VOS_SCALE_0) {
		PWR_D3CR = d3cr_masked | PWR_VOS_SCALE_1;
		SYSCFG_PWRCR |= SYSCFG_PWRCR_ODEN;
	} else {
		SYSCFG_PWRCR &= ~SYSCFG_PWRCR_ODEN;
		PWR_D3CR = d3cr_masked | scale;
	}
	while (!(PWR_D3CR & PWR_D3CR_VOSRDY));
}
