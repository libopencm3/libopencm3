/** @defgroup ethernet_phy_defines PHY Generic Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet PHY</b>
 *
 * @ingroup ETH
 *
 * @version 1.0.0
 *
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
#ifndef LIBOPENCM3_PHY_H
#define LIBOPENCM3_PHY_H

#include <stdbool.h>

/**@{*/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define PHY_REG_BCR			0x00
#define PHY_REG_BSR			0x01
#define PHY_REG_ID1			0x02
#define PHY_REG_ID2			0x03
#define PHY_REG_ANTX			0x04
#define PHY_REG_ANRX			0x05
#define PHY_REG_ANEXP			0x06
#define PHY_REG_ANNPTX			0x07
#define PHY_REG_ANNPRX			0x08

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

#define PHY_REG_BCR_COLTEST		(1 << 7)
#define PHY_REG_BCR_FD			(1 << 8)
#define PHY_REG_BCR_ANRST		(1 << 9)
#define PHY_REG_BCR_ISOLATE		(1 << 10)
#define PHY_REG_BCR_POWERDN		(1 << 11)
#define PHY_REG_BCR_AN			(1 << 12)
#define PHY_REG_BCR_100M		(1 << 13)
#define PHY_REG_BCR_LOOPBACK		(1 << 14)
#define PHY_REG_BCR_RESET		(1 << 15)

#define PHY_REG_BSR_JABBER		(1 << 1)
#define PHY_REG_BSR_UP			(1 << 2)
#define PHY_REG_BSR_FAULT		(1 << 4)
#define PHY_REG_BSR_ANDONE		(1 << 5)



/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

#define PHY0 0
#define PHY1 1

enum phy_status {
	LINK_DOWN,
	LINK_HD_10M,
	LINK_HD_100M,
	LINK_HD_1000M,
	LINK_HD_10000M,
	LINK_FD_10M,
	LINK_FD_100M,
	LINK_FD_1000M,
	LINK_FD_10000M,
};

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void phy_reset(uint8_t phy);
bool phy_link_isup(uint8_t phy);

enum phy_status phy_link_status(uint8_t phy);

void phy_autoneg_force(uint8_t phy, enum phy_status mode);
void phy_autoneg_enable(uint8_t phy);

END_DECLS

/**@}*/


#endif /* LIBOPENCM3_PHY_H__ */
