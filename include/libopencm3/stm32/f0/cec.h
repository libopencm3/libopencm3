/** @defgroup CEC_defines CEC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx HDMI-CEC</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
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

#ifndef LIBOPENCM3_CEC_H
#define LIBOPENCM3_CEC_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define CEC				CEC_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define CEC_CR				MMIO32(CEC_BASE + 0x00)
#define CEC_CFGR			MMIO32(CEC_BASE + 0x04)
#define CEC_TXDR			MMIO32(CEC_BASE + 0x08)
#define CEC_RXDR			MMIO32(CEC_BASE + 0x0c)
#define CEC_ISR				MMIO32(CEC_BASE + 0x10)
#define CEC_IER				MMIO32(CEC_BASE + 0x14)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* CEC_CR Values ------------------------------------------------------------*/

#define CEC_CR_TXEOM			(1 << 2)
#define CEC_CR_TXSOM			(1 << 1)
#define CEC_CR_CECEN			(1 << 0)

/* CEC_CFGR Values ----------------------------------------------------------*/

#define CEC_CFGR_LSTN			(1 << 31)

#define CEC_CFGR_OAR_SHIFT		16
#define CEC_CFGR_OAR			(0x3FFF << CEC_CFGR_OAR_SHIFT)

#define CEC_CFGR_SFTOPT			(1 << 8)
#define CEC_CFGR_BRDNOGEN		(1 << 7)
#define CEC_CFGR_LBPEGEN		(1 << 6)
#define CEC_CFGR_BREGEN			(1 << 5)
#define CEC_CFGR_BRESTP			(1 << 4)
#define CEC_CFGR_RXTOL			(1 << 3)

#define CEC_CFGR_SFT_SHIFT		0
#define CEC_CFGR_SFT			(7 >> CEC_CFGR_SFT_SHIFT)

/* CEC_ISR Values -----------------------------------------------------------*/

#define CEC_ISR_TXACKE			(1 << 12)
#define CEC_ISR_TXERR			(1 << 11)
#define CEC_ISR_TXUDR			(1 << 10)
#define CEC_ISR_TXEND			(1 << 9)
#define CEC_ISR_TXBR			(1 << 8)
#define CEC_ISR_ARBLST			(1 << 7)
#define CEC_ISR_RXACKE			(1 << 6)
#define CEC_ISR_LBPE			(1 << 5)
#define CEC_ISR_SBPE			(1 << 4)
#define CEC_ISR_BRE			(1 << 3)
#define CEC_ISR_RXOVR			(1 << 2)
#define CEC_ISR_RXEND			(1 << 1)
#define CEC_ISR_RXBR			(1 << 0)

/* CEC_IER Values -----------------------------------------------------------*/

#define CEC_IER_TXACKIE			(1 << 12)
#define CEC_IER_TXERRIE			(1 << 11)
#define CEC_IER_TXUDRIE			(1 << 10)
#define CEC_IER_TXENDIE			(1 << 9)
#define CEC_IER_TXBRIE			(1 << 8)
#define CEC_IER_ARBLSTIE		(1 << 7)
#define CEC_IER_RXACKIE			(1 << 6)
#define CEC_IER_LBPEIE			(1 << 5)
#define CEC_IER_SBPEIE			(1 << 4)
#define CEC_IER_BREIE			(1 << 3)
#define CEC_IER_RXOVRIE			(1 << 2)
#define CEC_IER_RXENDIE			(1 << 1)
#define CEC_IER_RXBRIE			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS
/**@}*/

#endif
