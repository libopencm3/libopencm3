/** @defgroup VF6xx_iomuxc IOMUX-Control
 *
 * @ingroup VF6xx
 *
 * @section vf6xx_gpio_api_ex GPIO API.
 *
 * @brief <b>VF6xx IO Pad MUX Controller</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Stefan Agner <stefan@agner.ch>
 *
 * @date 07 July 2014
 *
 * This library supports the GPIO module in the VF6xx SoC of Freescale.
 * Access is provided by GPIO number according to the Pinmux list of the
 * Reference Manual, similar as GPIOs are available on Linux.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#include <libopencm3/vf6xx/iomuxc.h>
#include <libopencm3/vf6xx/ccm.h>

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO

Set GPIO by GPIO number according to MUX list

@param[in] gpio unsigned 32 bit. GPIO number
*/

void iomuxc_mux(enum vf6xx_pad pad, uint32_t muxc)
{
	IOMUXC(pad) = muxc;
}

/**@}*/

