/** @defgroup ethernet_phy_ksz8051mll_defines PHY KSZ8051mll Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet PHY KSZ8051mll
 * chips</b>
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

#ifndef LIBOPENCM3_PHY_KSZ8051MLL_H
#define LIBOPENCM3_PHY_KSZ8051MLL_H

#include <libopencm3/ethernet/phy.h>

/**@{*/

/* Registers */

#define PHY_REG_AFECTRL     0x11
#define PHY_REG_RXERCTR     0x15
#define PHY_REG_STRAPOVRD   0x16
#define PHY_REG_STRAPSTAT   0x17
#define PHY_REG_ECR         0x18

#define PHY_REG_ICSR        0x1B

#define PHY_REG_LINKMD      0x1D

#define PHY_REG_CR1         0x1E
#define PHY_REG_CR2         0x1E

/**@}*/


#endif /* LIBOPENCM3_PHY_KSZ8051MLL_H__ */
