/** @defgroup ccm_file CCM
 *
 * @ingroup VF6xx
 *
 * @section vf6xx_ccm_api_ex Clock Controller Module API.
 *
 * @brief <b>VF6xx Clock Controller Module</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Stefan Agner <stefan@agner.ch>
 *
 * @date 30 Jun 2014
 *
 * This library supports the Clock Controller Module in the VF6xx SoCs
 * by Freescale.
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

#include <libopencm3/vf6xx/memorymap.h>
#include <libopencm3/vf6xx/ccm.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Enable clock of given device

This enables (gates) the clock for the given device.
@param[in] gr enum ccm_clock_gate. Device
*/
void ccm_clock_gate_enable(enum ccm_clock_gate gr)
{
	uint32_t offset = (uint32_t)gr / 16;
	uint32_t gr_mask = 0x3 << ((gr % 16) * 2);
	CCM_CCGR(offset * 4) |= gr_mask;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable clock of given device

This disables (ungates) the clock for the given device.
@param[in] gr enum ccm_clock_gate. Device
*/

void ccm_clock_gate_disable(enum ccm_clock_gate gr)
{
	uint32_t offset = (uint32_t)gr / 16;
	uint32_t gr_mask = 0x3 << ((gr % 16) * 2);
	CCM_CCGR(offset * 4) &= ~gr_mask;
}
/**@}*/
