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

void pwr_enable_vddusb(void)
{
	PWR_SVMCR |= PWR_SVMCR_UVMEN;
	while (!(PWR_SVMSR & PWR_SVMSR_VDDUSBRDY))
		continue;
	PWR_SVMCR &= ~PWR_SVMCR_UVMEN;
	PWR_SVMCR |= PWR_SVMCR_USV;
}
