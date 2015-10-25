/** @defgroup tsc_defines TSC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Touch Sensor</b>
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

#ifndef LIBOPENCM3_TSC_H
#define LIBOPENCM3_TSC_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define TSC				TSC_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define TSC_CR				MMIO32(TSC_BASE + 0x00)
#define TSC_IER				MMIO32(TSC_BASE + 0x04)
#define TSC_ICR				MMIO32(TSC_BASE + 0x08)
#define TSC_ISR				MMIO32(TSC_BASE + 0x0c)
#define TSC_IOHCR			MMIO32(TSC_BASE + 0x10)
#define TSC_IOASCR			MMIO32(TSC_BASE + 0x18)
#define TSC_IOSCR			MMIO32(TSC_BASE + 0x20)
#define TSC_IOCCR			MMIO32(TSC_BASE + 0x28)
#define TSC_IOGCSR			MMIO32(TSC_BASE + 0x30)
#define TSC_IOGxCR(x)			MMIO32(TSC_BASE + 0x34 + ((x)-1)*4)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* TSC_CR Values ------------------------------------------------------------*/

#define TSC_CR_CTPH_SHIFT		28
#define TSC_CR_CTPH			(0xF << TSC_CR_CTPH_SHIFT)

#define TSC_CR_CTPL_SHIFT		24
#define TSC_CR_CTPL			(0x0F << TSC_CR_CTPL_SHIFT)

#define TSC_CR_SSD_SHIFT		17
#define TSC_CR_SSD			(0x7F << TSC_CR_SSD_SHIFT)

#define TSC_CR_SSE			(1 << 16)
#define TSC_CR_SSPSC			(1 << 15)

#define TSC_CR_PGPSC_SHIFT		12
#define TSC_CR_PGPSC			(7 << TSC_CR_PGPSC_SHIFT)

#define TSC_CR_MCV_SHIFT		5
#define TSC_CR_MCV			(7 << TSC_CR_MCV_SHIFT)

#define TSC_CR_IODEF			(1 << 4)
#define TSC_CR_SYNCPOL			(1 << 3)
#define TSC_CR_AM			(1 << 2)
#define TSC_CR_START			(1 << 1)
#define TSC_CR_TSCE			(1 << 0)

/* TSC_IER Values -----------------------------------------------------------*/

#define TSC_IER_MCEIE			(1 << 1)
#define TSC_IER_EOAIE			(1 << 0)

/* TSC_ICR Values -----------------------------------------------------------*/

#define TSC_ICR_MCEIC			(1 << 1)
#define TSC_ICR_EOAIC			(1 << 0)

/* TSC_ISR Values -----------------------------------------------------------*/

#define TSC_ISR_MCEF			(1 << 1)
#define TSC_ISR_EOAF			(1 << 0)

/* TSC_IOHCR Values ---------------------------------------------------------*/

/* Bit helper g = [1..6] io = [1..4] */
#define TSC_IOBIT_VAL(g, io)		((1 << ((io)-1)) << (((g)-1)*4))

#define TSC_IOHCR_G1(io)		TSC_IOBIT_VAL(1, io)
#define TSC_IOHCR_G2(io)		TSC_IOBIT_VAL(2, io)
#define TSC_IOHCR_G3(io)		TSC_IOBIT_VAL(3, io)
#define TSC_IOHCR_G4(io)		TSC_IOBIT_VAL(4, io)
#define TSC_IOHCR_G5(io)		TSC_IOBIT_VAL(5, io)
#define TSC_IOHCR_G6(io)		TSC_IOBIT_VAL(6, io)

/* TSC_IOASCR Values --------------------------------------------------------*/

#define TSC_IOASCR_G1(io)		TSC_IOBIT_VAL(1, io)
#define TSC_IOASCR_G2(io)		TSC_IOBIT_VAL(2, io)
#define TSC_IOASCR_G3(io)		TSC_IOBIT_VAL(3, io)
#define TSC_IOASCR_G4(io)		TSC_IOBIT_VAL(4, io)
#define TSC_IOASCR_G5(io)		TSC_IOBIT_VAL(5, io)
#define TSC_IOASCR_G6(io)		TSC_IOBIT_VAL(6, io)

/* TSC_IOSCR Values ---------------------------------------------------------*/

#define TSC_IOSCR_G1(io)		TSC_IOBIT_VAL(1, io)
#define TSC_IOSCR_G2(io)		TSC_IOBIT_VAL(2, io)
#define TSC_IOSCR_G3(io)		TSC_IOBIT_VAL(3, io)
#define TSC_IOSCR_G4(io)		TSC_IOBIT_VAL(4, io)
#define TSC_IOSCR_G5(io)		TSC_IOBIT_VAL(5, io)
#define TSC_IOSCR_G6(io)		TSC_IOBIT_VAL(6, io)

/* TSC_IOCCR Values ---------------------------------------------------------*/

#define TSC_IOCCR_G1(io)		TSC_IOBIT_VAL(1, io)
#define TSC_IOCCR_G2(io)		TSC_IOBIT_VAL(2, io)
#define TSC_IOCCR_G3(io)		TSC_IOBIT_VAL(3, io)
#define TSC_IOCCR_G4(io)		TSC_IOBIT_VAL(4, io)
#define TSC_IOCCR_G5(io)		TSC_IOBIT_VAL(5, io)
#define TSC_IOCCR_G6(io)		TSC_IOBIT_VAL(6, io)

/* TSC_IOGCSR Values --------------------------------------------------------*/

#define TSC_IOGCSR_GxE(x)		(1 << ((x)-1))
#define TSC_IOGCSR_GxS(x)		(1 << ((x)+15))

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
