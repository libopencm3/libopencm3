/** @defgroup ethernet_phy_ste100_defines PHY STE100 Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet PHY STE100 chip</b>
 *
 * @ingroup ETH
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 6 February 2014
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

#ifndef LIBOPENCM3_PHY_STE100_H
#define LIBOPENCM3_PHY_STE100_H

#include <libopencm3/ethernet/phy.h>

/**@{*/

/*
 * Architecture availability:
 *
 */

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define STE100_XCR				0x00
#define STE100_XSR				0x01
#define STE100_PID1				0x02
#define STE100_PID2				0x03
#define STE100_ANA				0x04
#define STE100_ANLPA				0x05
#define STE100_ANE				0x06

#define STE100_XCIIS				0x11
#define STE100_XIE				0x12
#define STE100_100CTR				0x13
#define STE100_XMC				0x14


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* STE100_XCR ---------------------------------------------------------------*/
/* STE100_XSR ---------------------------------------------------------------*/
/* STE100_PID1 --------------------------------------------------------------*/
/* STE100_PID2 --------------------------------------------------------------*/
/* STE100_ANA ---------------------------------------------------------------*/
/* STE100_ANLPA -------------------------------------------------------------*/
/* STE100_ANE ---------------------------------------------------------------*/

/* STE100_XCIIS -------------------------------------------------------------*/

#define STE100_XCIIS_SPEED			(1 << 9)
#define STE100_XCIIS_DUPLEX			(1 << 8)
#define STE100_XCIIS_PAUSE			(1 << 7)
#define STE100_XCIIS_ANC			(1 << 6)
#define STE100_XCIIS_RFD			(1 << 5)
#define STE100_XCIIS_LS				(1 << 4)
#define STE100_XCIIS_ANAR			(1 << 3)
#define STE100_XCIIS_PDF			(1 << 2)
#define STE100_XCIIS_ANPR			(1 << 1)
#define STE100_XCIIS_REF			(1 << 0)

/* STE100_XIE ---------------------------------------------------------------*/

#define STE100_XCIE_ANCE			(1 << 6)
#define STE100_XCIE_RFE				(1 << 5)
#define STE100_XCIE_LDE				(1 << 4)
#define STE100_XCIE_ANAE			(1 << 3)
#define STE100_XCIE_PDFE			(1 << 2)
#define STE100_XCIE_ANPE			(1 << 1)
#define STE100_XCIE_REFE			(1 << 0)

/* STE100_100CTR ------------------------------------------------------------*/

#define STE100_100CTR_DISRER			(1 << 13)
#define STE100_100CTR_ANC			(1 << 12)
#define STE100_100CTR_ENRLB			(1 << 9)
#define STE100_100CTR_ENDCR			(1 << 8)
#define STE100_100CTR_ENRZI			(1 << 7)
#define STE100_100CTR_EN4B5B			(1 << 6)
#define STE100_100CTR_ISOTX			(1 << 5)

#define STE100_100CTR_CMODE_SHIFT		2
#define STE100_100CTR_CMODE			(7 << STE100_100CTR_CMODE_SHIFT)
#define STE100_100CTR_CMODE_AN			(0 << STE100_100CTR_CMODE_SHIFT)
#define STE100_100CTR_CMODE_10HD		(1 << STE100_100CTR_CMODE_SHIFT)
#define STE100_100CTR_CMODE_100HD		(2 << STE100_100CTR_CMODE_SHIFT)
#define STE100_100CTR_CMODE_10FD		(5 << STE100_100CTR_CMODE_SHIFT)
#define STE100_100CTR_CMODE_100FD		(6 << STE100_100CTR_CMODE_SHIFT)
#define STE100_100CTR_CMODE_ISOLATE		(7 << STE100_100CTR_CMODE_SHIFT)

#define STE100_100CTR_DISMLT			(1 << 1)
#define STE100_100CTR_DISCRM			(1 << 0)

/* STE100_XMC ---------------------------------------------------------------*/

#define STE100_XMC_LD				(1 << 11)
#define STE100_XMC_PAD_SHIFT			3
#define STE100_XMC_PAD				(31 << STE100_XMC_PAD_SHIFT)

#define STE100_XMC_MFPSE			(1 << 1)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

/**@}*/


#endif /* LIBOPENCM3_PHY_STE100_H__ */
