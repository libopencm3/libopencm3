/** @defgroup CRS_defines CRS Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Clock Recovery</b>
 *
 * @ingroup STM32F0xx_defines
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
 * Copyright (C) 2014 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_CRS_H
#define LIBOPENCM3_CRS_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define CRS				CRS_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define CRS_CR				MMIO32(CRS_BASE + 0x00)
#define CRS_CFGR			MMIO32(CRS_BASE + 0x04)
#define CRS_ISR				MMIO32(CRS_BASE + 0x08)
#define CRS_ICR				MMIO32(CRS_BASE + 0x0c)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* CEC_CR Values ------------------------------------------------------------*/

#define CRS_CR_TRIM_SHIFT		8
#define CRS_CR_TRIM			(0x3F << CRS_CR_TRIM_SHIFT)

#define CRS_CR_SWSYNC			(1 << 7)
#define CRS_CR_AUTOTRIMEN		(1 << 6)
#define CRS_CR_CEN			(1 << 5)
#define CRS_CR_ESYNCIE			(1 << 3)
#define CRS_CR_ERRIE			(1 << 2)
#define CRS_CR_SYNCWARNIE		(1 << 1)
#define CRS_CR_SYNCOKIE			(1 << 0)

/* CEC_CFGR Values ----------------------------------------------------------*/

#define CRS_CFGR_SYNCPOL		(1 << 31)

#define CRS_CFGR_SYNCSRC_SHIFT		28
#define CRS_CFGR_SYNCSRC		(3 << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC_GPIO		(0 << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC_LSE		(1 << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC_USB_SOF	(2 << CRS_CFGR_SYNCSRC_SHIFT)

#define CRS_CFGR_SYNCDIV_SHIFT		24
#define CRS_CFGR_SYNCDIV		(7 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_NODIV		(0 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV2		(1 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV4		(2 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV8		(3 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV16		(4 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV32		(5 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV64		(6 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV128		(7 << CRS_CFGR_SYNCDIV_SHIFT)

#define CRS_CFGR_FELIM_SHIFT		16
#define CRS_CFGR_FELIM			(0xFF << CRS_CFGR_FELIM_SHIFT)
#define CRS_CFGR_FELIM_VAL(x)		((x) << CRS_CFGR_FELIM_SHIFT)

#define CRS_CFGR_RELOAD_SHIFT		0
#define CRS_CFGR_RELOAD			(0xFFFF << CRS_CFGR_RELOAD_SHIFT)
#define CRS_CFGR_RELOAD_VAL(x)		((x) << CRS_CFGR_RELOAD_SHIFT)

/* CEC_ISR Values -----------------------------------------------------------*/

#define CRS_ISR_FECAP_SHIFT		16
#define CRS_ISR_FECAP			(0xFFFF << CRS_ISR_FECAP_SHIFT)

#define CRS_ISR_FEDIR			(1 << 15)
#define CRS_ISR_TRIMOVF			(1 << 10)
#define CRS_ISR_SYNCMISS		(1 << 9)
#define CRS_ISR_SYNCERR			(1 << 8)
#define CRS_ISR_ESYNCF			(1 << 3)
#define CRS_ISR_ERRF			(1 << 2)
#define CRS_ISR_SYNCWARNF		(1 << 1)
#define CRS_ISR_SYNCOOKF		(1 << 0)

/* CEC_ICR Values -----------------------------------------------------------*/

#define CRS_ICR_ESYNCC			(1 << 3)
#define CRS_ICR_ERRC			(1 << 2)
#define CRS_ICR_SYNCWARNC		(1 << 1)
#define CRS_ICR_SYNCOKC			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void crs_autotrim_usb_enable(void);

END_DECLS
/**@}*/

#endif
