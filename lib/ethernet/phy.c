/** @defgroup ethernet_phy_file PHY Generic Drivers
 *
 * @ingroup ETH
 *
 * @brief <b>Ethernet PHY Generic Drivers</b>
 *
 * @version 1.0.0
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 1 September 2013
 *
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#include <libopencm3/ethernet/mac.h>
#include <libopencm3/ethernet/phy.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Is the link up ?
 *
 * @param[in] phy uint8_t phy ID of the PHY
 * @returns bool true, if link is up
 */
bool phy_link_isup(uint8_t phy)
{
	return eth_smi_read(phy, PHY_REG_BSR) & PHY_REG_BSR_UP;
}

/*---------------------------------------------------------------------------*/
/** @brief Reset the PHY
 *
 * Reset the PHY chip and wait for done
 * @param[in] phy uint8_t phy ID of the PHY
 */
void phy_reset(uint8_t phy)
{
	eth_smi_write(phy, PHY_REG_BCR, PHY_REG_BCR_RESET);
	while (eth_smi_read(phy, PHY_REG_BCR) & PHY_REG_BCR_RESET);
}

/*---------------------------------------------------------------------------*/

/**@}*/
