/**
 * @brief <b>libopencm3 STM32U5xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @date 21 September, 2025
 *
 * This library supports the power control system for the
 * STM32U5 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 ALTracer <11005378+ALTracer@users.noreply.github.com>
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/pwr.h>

void pwr_set_mode_ldo(void)
{
	PWR_CR3 &= ~PWR_CR3_REGSEL_SMPS;
}

void pwr_set_mode_smps(void)
{
	PWR_CR3 |= PWR_CR3_REGSEL_SMPS;
}

void pwr_set_mode(const pwr_sys_mode_e mode)
{
	switch (mode) {
	case PWR_SYS_LDO:
		pwr_set_mode_ldo();
		break;
	case PWR_SYS_SMPS:
		pwr_set_mode_smps();
		break;
	}
}

void pwr_set_vos_scale(const pwr_vos_scale_e scale)
{
	static const uint8_t vosr_vos_values[] = {
		PWR_VOSR_VOS_SCALE_1,
		PWR_VOSR_VOS_SCALE_2,
		PWR_VOSR_VOS_SCALE_3,
		PWR_VOSR_VOS_SCALE_4,
	};
	cm3_assert(scale != PWR_VOS_SCALE_UNDEFINED); /* Make sure this has been set. */

	/* Set up the new scaling value */
	const uint32_t vosr_vos = (uint32_t)vosr_vos_values[scale - 1U] << PWR_VOSR_VOS_SHIFT;
	PWR_VOSR = (PWR_VOSR & ~PWR_VOSR_VOS_MASK) | vosr_vos;

	/* Wait for voltage offset scaling to become ready */
	while (!(PWR_VOSR & PWR_VOSR_VOSRDY))
		continue;

	/* If the scale picked is range 1 or 2, make sure BOOSTEN is set so >55MHz clocks can be legally picked */
	if (scale == PWR_VOS_SCALE_1 || scale == PWR_VOS_SCALE_2) {
		PWR_VOSR |= PWR_VOSR_BOOSTEN;

		/* Wait for boost become ready */
		while (!(PWR_VOSR & PWR_VOSR_BOOSTRDY))
			continue;
	}
}

void pwr_enable_vddusb(void)
{
	/* Enable voltage monitoring and wait for VDDUSB to be marked ready */
	PWR_SVMCR |= PWR_SVMCR_UVMEN;
	while (!(PWR_SVMSR & PWR_SVMSR_VDDUSBRDY))
		continue;
	/* Disable voltage monitoring again and disable isolation for the USB power domain */
	PWR_SVMCR &= ~PWR_SVMCR_UVMEN;
	PWR_SVMCR |= PWR_SVMCR_USV;
}

void pwr_enable_vdda(void)
{
	/* Enable voltage monitoring with the lower threshold and wait for VDDA to be marked ready */
	PWR_SVMCR |= PWR_SVMCR_AVMEN1;
	while (!(PWR_SVMSR & PWR_SVMSR_VDDA1RDY))
		continue;
	/* Disable monitoring again and disbale isolation for the analog power domain */
	PWR_SVMCR &= ~PWR_SVMCR_AVMEN1;
	PWR_SVMCR |= PWR_SVMCR_ASV;
}
