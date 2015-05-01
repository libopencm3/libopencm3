/** @defgroup crs_file CRS
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx Clock Recovery Subsystem</b>
 *
 * @version 1.0.0
 *
 * @date 5 Feb 2014
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/crs.h>
#include <libopencm3/stm32/rcc.h>

/**
 * This function enables autonatic trimming of internal RC oscillator by USB SOF
 * frames
 */
void crs_autotrim_usb_enable(void)
{
	rcc_periph_clock_enable(RCC_CRS);
	
	CRS_CFGR &= ~CRS_CFGR_SYNCSRC;
	CRS_CFGR |= CRS_CFGR_SYNCSRC_USB_SOF;
	
	CRS_CR |= CRS_CR_AUTOTRIMEN;
	CRS_CR |= CRS_CR_CEN;
}