/** @defgroup ssi_defines Synchronous Serial Interface
 *
 * @brief <b>Defined Constants and Types for the LM4F Synchronous Serial Interface (SSI)</b>
 *
 * @ingroup LM4Fxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Tiago Costa <nippius+github@gmail.com>
 *
 * @date 11 June 2014
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Tiago Costa <nippius+github@gmail.com>
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

#ifndef LM4F_SSI_H
#define LM4F_SSI_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lm4f/memorymap.h>

/* =============================================================================
 * Convenience macros
 * ---------------------------------------------------------------------------*/
/** @defgroup ssi_base SSI register base addresses
 * @{*/
#define SSI0				SSI0_BASE
#define SSI1				SSI1_BASE
#define SSI2				SSI2_BASE
#define SSI3				SSI3_BASE
/** @} */

/* =============================================================================
 * SSI registers
 * ---------------------------------------------------------------------------*/

/* SSI Control 0 */
#define SSI_CR0(port)		MMIO32((port) + 0x000)

/* SSI Control 1 */
#define SSI_CR1(port)		MMIO32((port) + 0x004)

/* SSI Data */
#define SSI_DR(port)		MMIO32((port) + 0x008)

/* SSI Satus */
#define SSI_SR(port)		MMIO32((port) + 0x00C)

/* SSI Clock Prescale */
#define SSI_CPSR(port)		MMIO32((port) + 0x010)

/* SSI Interrupt Mask */
#define SSI_IM(port)		MMIO32((port) + 0x014)

/* SSI Raw Interrupt Status */
#define SSI_RIS(port)		MMIO32((port) + 0x018)

/* SSI Masked Interrupt Status */
#define SSI_MIS(port)		MMIO32((port) + 0x01C)

/* SSI Interrupt Clear */
#define SSI_ICR(port)		MMIO32((port) + 0x020)

/* SSI DMA Control */
#define SSI_DMACTL(port)	MMIO32((port) + 0x024)

/* SSI Clock Configuration */
#define SSI_CC(port)		MMIO32((port) + 0xFC8)

/* SSI Peripheral Identification */
#define SSI_PERIPH_ID4(port)	MMIO32((port) + 0xFD0)
#define SSI_PERIPH_ID5(port)	MMIO32((port) + 0xFD4)
#define SSI_PERIPH_ID6(port)	MMIO32((port) + 0xFD8)
#define SSI_PERIPH_ID7(port)	MMIO32((port) + 0xFDC)
#define SSI_PERIPH_ID0(port)	MMIO32((port) + 0xFE0)
#define SSI_PERIPH_ID1(port)	MMIO32((port) + 0xFE4)
#define SSI_PERIPH_ID2(port)	MMIO32((port) + 0xFE8)
#define SSI_PERIPH_ID3(port)	MMIO32((port) + 0xFEC)

/* SSI PrimeCell Identification */
#define SSI_PCELL_ID0(port)	MMIO32((port) + 0xFF0)
#define SSI_PCELL_ID1(port)	MMIO32((port) + 0xFF4)
#define SSI_PCELL_ID2(port)	MMIO32((port) + 0xFF8)
#define SSI_PCELL_ID3(port)	MMIO32((port) + 0xFFC)

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

END_DECLS

/**@}*/

#endif	/* LM4F_SSI_H */

