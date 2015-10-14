/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the LPC43xx A/D Converter</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_ADC_H
#define LPC43XX_ADC_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* ADC port base addresses (for convenience) */
#define ADC0                            ADC0_BASE
#define ADC1                            ADC1_BASE


/* --- ADC registers ------------------------------------------------------- */

/* A/D Control Register */
#define ADC_CR(port)                    MMIO32((port) + 0x000)
#define ADC0_CR                         ADC_CR(ADC0)
#define ADC1_CR                         ADC_CR(ADC1)

/* A/D Global Data Register */
#define ADC_GDR(port)                   MMIO32((port) + 0x004)
#define ADC0_GDR                        ADC_GDR(ADC0)
#define ADC1_GDR                        ADC_GDR(ADC1)

/* A/D Interrupt Enable Register */
#define ADC_INTEN(port)                 MMIO32((port) + 0x00C)
#define ADC0_INTEN                      ADC_INTEN(ADC0)
#define ADC1_INTEN                      ADC_INTEN(ADC1)

/* A/D Channel 0 Data Register */
#define ADC_DR0(port)                   MMIO32((port) + 0x010)
#define ADC0_DR0                        ADC_DR0(ADC0)
#define ADC1_DR0                        ADC_DR0(ADC1)

/* A/D Channel 1 Data Register */
#define ADC_DR1(port)                   MMIO32((port) + 0x014)
#define ADC0_DR1                        ADC_DR1(ADC0)
#define ADC1_DR1                        ADC_DR1(ADC1)

/* A/D Channel 2 Data Register */
#define ADC_DR2(port)                   MMIO32((port) + 0x018)
#define ADC0_DR2                        ADC_DR2(ADC0)
#define ADC1_DR2                        ADC_DR2(ADC1)

/* A/D Channel 3 Data Register */
#define ADC_DR3(port)                   MMIO32((port) + 0x01C)
#define ADC0_DR3                        ADC_DR3(ADC0)
#define ADC1_DR3                        ADC_DR3(ADC1)

/* A/D Channel 4 Data Register */
#define ADC_DR4(port)                   MMIO32((port) + 0x020)
#define ADC0_DR4                        ADC_DR4(ADC0)
#define ADC1_DR4                        ADC_DR4(ADC1)

/* A/D Channel 5 Data Register */
#define ADC_DR5(port)                   MMIO32((port) + 0x024)
#define ADC0_DR5                        ADC_DR5(ADC0)
#define ADC1_DR5                        ADC_DR5(ADC1)

/* A/D Channel 6 Data Register */
#define ADC_DR6(port)                   MMIO32((port) + 0x028)
#define ADC0_DR6                        ADC_DR6(ADC0)
#define ADC1_DR6                        ADC_DR6(ADC1)

/* A/D Channel 7 Data Register */
#define ADC_DR7(port)                   MMIO32((port) + 0x02C)
#define ADC0_DR7                        ADC_DR7(ADC0)
#define ADC1_DR7                        ADC_DR7(ADC1)

/* A/D Status Register */
#define ADC_STAT(port)                  MMIO32((port) + 0x030)
#define ADC0_STAT                       ADC_STAT(ADC0)
#define ADC1_STAT                       ADC_STAT(ADC1)

/**@}*/

#endif
