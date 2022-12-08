/** @addtogroup crs_file

@brief <b>(USB) AT32F40x Clock Recovery Subsystem</b>

@version 1.0.0

@date 7 Dec 2022

LGPL License Terms @ref lgpl_license
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
/**@{*/

#include <libopencm3/stm32/crs.h>

/* ------------------------------------------------------------------------- */

/** @brief Enable calibration ready interrupt

Enable interrupt generation when CRS_SR_CALRDY bit is set.
*/

void crs_enable_calrdy_interrupt()
{
	CRS_CR1 |= CRS_CR1_CALRDYIEN;
}

/** @brief Disable calibration ready interrupt

Do not generate interrupt when CRS_SR_CALRDY bit is set (default).
*/

void crs_disable_calrdy_interrupt()
{
	CRS_CR1 &= ~CRS_CR1_CALRDYIEN;
}

/* ------------------------------------------------------------------------- */

/** @brief Enable reference lost interrupt

Enable interrupt generation when CRS_SR_RSLOST bit is set.
*/

void crs_enable_reflost_interrupt()
{
	CRS_CR1 |= CRS_CR1_EIEN;
}

/** @brief Disable reference lost interrupt

Do not generate interrupt when CRS_SR_RSLOST bit is set (default).
*/

void crs_disable_reflost_interrupt()
{
	CRS_CR1 &= ~CRS_CR1_EIEN;
}

/* ------------------------------------------------------------------------- */

/** @brief Enable automatic trimming of HSI oscillator

When enabled, HSI oscillator is automatically trimmed by USB SOF frames.
*/

void crs_autotrim_usb_enable()
{
	CRS_CFGR1 = CRS_CFGR_LOW;
	CRS_CFGR2 = CRS_CFGR_CENTER;
	CRS_CFGR3 = CRS_CFGR_HIGH;

	CRS_CR1 |= CRS_CR1_ENTRIM | CRS_CR1_CALON;
}

/**@}*/
