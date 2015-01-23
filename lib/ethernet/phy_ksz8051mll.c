/** @defgroup ethernet_phy_ksz8051mll_file PHY KSZ8051MLL
 *
 * @ingroup ETH
 *
 * @brief <b>Ethernet PHY STM32Fxx7 Drivers</b>
 *
 * @version 1.0.0
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 1 September 2013
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
#include <libopencm3/ethernet/phy_ksz8051mll.h>


/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Get the current link status
 *
 * Retrieve the link speed and duplex status of the link.
 *
 * @param[in] phy uint8_t phy ID of the PHY
 * @returns ::phy_status Link status
 */
enum phy_status phy_link_status(uint8_t phy)
{
	return eth_smi_read(phy, PHY_REG_CR1) & 0x07;
}

/*---------------------------------------------------------------------------*/
/** @brief Force autonegotiation
 *
 * Force the autonegotiation and set link speed and duplex mode of the link
 *
 * @param[in] phy uint8_t phy ID of the PHY
 * @param[in] mode enum phy_status Desired link status
 */
void phy_autoneg_force(uint8_t phy, enum phy_status mode)
{
	uint16_t bst = 0;

	if ((mode == LINK_FD_10M) || (mode == LINK_FD_100M) ||
	    (mode == LINK_FD_1000M) || (mode == LINK_FD_10000M)) {
		bst |= PHY_REG_BCR_FD;
	}

	if ((mode == LINK_FD_100M) || (mode == LINK_HD_100M)) {
		bst |= PHY_REG_BCR_100M;
	}

	eth_smi_bit_op(phy, PHY_REG_BCR, bst,
		    ~(PHY_REG_BCR_AN | PHY_REG_BCR_100M | PHY_REG_BCR_FD));
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the autonegotiation
 *
 * Enable the autonegotiation of the link speed and duplex mode
 *
 * @param[in] phy uint8_t phy ID of the PHY
 */
void phy_autoneg_enable(uint8_t phy)
{
	eth_smi_bit_set(phy, PHY_REG_BCR, PHY_REG_BCR_AN | PHY_REG_BCR_ANRST);
}

/*---------------------------------------------------------------------------*/

/**@}*/
