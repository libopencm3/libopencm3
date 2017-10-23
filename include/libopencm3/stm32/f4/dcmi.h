/** @defgroup dcmi_defines DCMI Defines
 *
 * @ingroup STM32F4xx_defines
 *
 * @brief Defined Constants and Macros for the STM32F4xx DCMI Peripheral
 *
 * @version 1.0.0
 *
 * @date 2017-10-16
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * STM32F4 DCMI Defines
 *
 * Copyright (C) 2017, Marek Koza <qyx@krtko.org>
 *
 * This file is part of the libopencm3 project.
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
 *
 */

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

#pragma once

/**@{*/

/**
 * DCMI control register 1
 */
#define DCMI_CR				MMIO32(DCMI_BASE + 0x0U)
/**
 * @defgroup dcmi_cr_values DCMI_CR Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_CR_EN			(1 << 14)
#define DCMI_CR_EDM1			(1 << 11)
#define DCMI_CR_EDM0			(1 << 10)
#define DCMI_CR_FCRC1			(1 << 9)
#define DCMI_CR_FCRC0			(1 << 8)
#define DCMI_CR_VSPOL			(1 << 7)
#define DCMI_CR_HSPOL			(1 << 6)
#define DCMI_CR_PCKPOL			(1 << 5)
#define DCMI_CR_ESS			(1 << 4)
#define DCMI_CR_JPEG			(1 << 3)
#define DCMI_CR_CROP			(1 << 2)
#define DCMI_CR_CM			(1 << 1)
#define DCMI_CR_CAPTURE			(1 << 0)
/**@}*/

/**
 * DCMI status register
 */
#define DCMI_SR				MMIO32(DCMI_BASE + 0x04U)

/**
 * DCMI raw interrupt status register
 *
 * DCMI_RIS gives the raw interrupt status and is accessible in read only. When read, this
 * register returns the status of the corresponding interrupt before masking with the DCMI_IER
 * register value.
 */
#define DCMI_RIS			MMIO32(DCMI_BASE + 0x08U)
/**
 * @defgroup dcmi_ris_values DCMI_RIS Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_RIS_LINE			(1 << 4)
#define DCMI_RIS_VSYNC			(1 << 3)
#define DCMI_RIS_ERR			(1 << 2)
#define DCMI_RIS_OVR			(1 << 1)
#define DCMI_RIS_FRAME			(1 << 0)
/**@}*/

/**
 * DCMI interrupt enable register
 *
 * The DCMI_IER register is used to enable interrupts. When one of the DCMI_IER bits is set,
 * the corresponding interrupt is enabled. This register is accessible in both read and write.
 */
#define DCMI_IER			MMIO32(DCMI_BASE + 0x0CU)
/**
 * @defgroup dcmi_ier_values DCMI_IER Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_IER_LINE			(1 << 4)
#define DCMI_IER_VSYNC			(1 << 3)
#define DCMI_IER_ERR			(1 << 2)
#define DCMI_IER_OVR			(1 << 1)
#define DCMI_IER_FRAME			(1 << 0)
/**@}*/

/**
 * DCMI masked interrupt status register
 *
 * This DCMI_MIS register is a read-only register. When read, it returns the current masked
 * status value (depending on the value in DCMI_IER) of the corresponding interrupt. A bit in
 * this register is set if the corresponding enable bit in DCMI_IER is set and the corresponding
 * bit in DCMI_RIS is set.
 */
#define DCMI_MIS			MMIO32(DCMI_BASE + 0x10U)
/**
 * @defgroup dcmi_mis_values DCMI_MIS Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_MIS_LINE			(1 << 4)
#define DCMI_MIS_VSYNC			(1 << 3)
#define DCMI_MIS_ERR			(1 << 2)
#define DCMI_MIS_OVR			(1 << 1)
#define DCMI_MIS_FRAME			(1 << 0)
/**@}*/

/**
 * DCMI interrupt clear register
 *
 * The DCMI_ICR register is write-only. Writing a ‘1’ into a bit of this register clears the
 * corresponding bit in the DCMI_RIS and DCMI_MIS registers. Writing a ‘0’ has no effect.
 */
#define DCMI_ICR			MMIO32(DCMI_BASE + 0x14U)
/**
 * @defgroup dcmi_icr_values DCMI_ICR Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_ICR_LINE			(1 << 4)
#define DCMI_ICR_VSYNC			(1 << 3)
#define DCMI_ICR_ERR			(1 << 2)
#define DCMI_ICR_OVR			(1 << 1)
#define DCMI_ICR_FRAME			(1 << 0)
/**@}*/

/**
 * DCMI embedded synchronization code register
 */
#define DCMI_ESCR			MMIO32(DCMI_BASE + 0x18U)
/**
 * @defgroup dcmi_escr_values DCMI_ESCR Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_ESCR_FEC_SHIFT		24
#define DCMI_ESCR_FEC_MASK		0xff
#define DCMI_ESCR_LEC_SHIFT		16
#define DCMI_ESCR_LEC_MASK		0xff
#define DCMI_ESCR_LSC_SHIFT		8
#define DCMI_ESCR_LSC_MASK		0xff
#define DCMI_ESCR_FSC_SHIFT		0
#define DCMI_ESCR_FSC_MASK		0xff
/**@}*/


/**
 * DCMI embedded synchronization unmask register
 */
#define DCMI_ESUR			MMIO32(DCMI_BASE + 0x1CU)
/**
 * @defgroup dcmi_esur_values DCMI_ESUR Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_ESUR_FEU_SHIFT		24
#define DCMI_ESUR_FEU_MASK		0xff
#define DCMI_ESUR_LEU_SHIFT		16
#define DCMI_ESUR_LEU_MASK		0xff
#define DCMI_ESUR_LSU_SHIFT		8
#define DCMI_ESUR_LSU_MASK		0xff
#define DCMI_ESUR_FSU_SHIFT		0
#define DCMI_ESUR_FSU_MASK		0xff
/**@}*/

/**
 * DCMI crop window start
 */
#define DCMI_CWSTRT			MMIO32(DCMI_BASE + 0x20U)
/**
 * @defgroup dcmi_cwstrt_values DCMI_CWSTRT Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_CWSTRT_VST_SHIFT		16
#define DCMI_CWSTRT_VST_MASK		0x1fff
#define DCMI_CWSTRT_HOFFCNT_SHIFT	0
#define DCMI_CWSTRT_HOFFCNT_MASK	0x3fff
/**@}*/

/**
 * DCMI crop window size
 */
#define DCMI_CWSIZE			MMIO32(DCMI_BASE + 0x24U)
/**
 * @defgroup dcmi_cwsize_values DCMI_CWSIZE Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_CWSIZE_VLINE_SHIFT		16
#define DCMI_CWSIZE_VLINE_MASK		0x3fff
#define DCMI_CWSIZE_CAPCNT_SHIFT	0
#define DCMI_CWSIZE_CAPCNT_MASK		0x3fff
/**@}*/

/**
 * DCMI data register
 *
 * The digital camera Interface packages all the received data in 32-bit format before
 * requesting a DMA transfer. A 4-word deep FIFO is available to leave enough time for DMA
 * transfers and avoid DMA overrun conditions.
 */
#define DCMI_DR				MMIO32(DCMI_BASE + 0x28U)

/**@}*/
