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

/** @defgroup CM3_mpu_defines Cortex-M MPU Defines
 *
 * @brief <b>libopencm3 Cortex Memory Protection Unit</b>
 *
 * @ingroup CM3_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 *
 * The MPU is available as an option in both ARMv6-M and ARMv7-M, but it has
 * more features in v7, particularly in the available attributes.
 *
 * For more information see the ARM Architecture reference manuals.
 */
/**@{*/

#ifndef LIBOPENCM3_MPU_H
#define LIBOPENCM3_MPU_H

#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- SCB: Registers ------------------------------------------------------ */
/** @defgroup CM3_mpu_registers MPU Registers
 * @ingroup CM3_mpu_defines
 *
 *@{*/
/** MPU_TYPE is always available, even if the MPU is not implemented */
#define MPU_TYPE			MMIO32(MPU_BASE + 0x00) /**< See also \ref CM3_mpu_type */
#define MPU_CTRL			MMIO32(MPU_BASE + 0x04) /**< See also \ref CM3_mpu_ctrl */
#define MPU_RNR				MMIO32(MPU_BASE + 0x08) /**< See also \ref CM3_mpu_rnr */
#define MPU_RBAR			MMIO32(MPU_BASE + 0x0C) /**< See also \ref CM3_mpu_rbar */
#define MPU_RASR			MMIO32(MPU_BASE + 0x10) /**< See also \ref CM3_mpu_rasr */
/**@}*/

/* --- MPU values ---------------------------------------------------------- */

/** @defgroup CM3_mpu_type MPU TYPE register fields
 * @ingroup CM3_mpu_defines
 * The MPU_TYPE register is always available, even if the MPU is not implemented.
 * In that case, the DREGION field will read as 0.
 *@{*/
#define MPU_TYPE_IREGION_LSB		16
#define MPU_TYPE_IREGION		(0xFF << MPU_TYPE_IREGION_LSB) /**< Number of protected instruction regions; always 0 on v6m/v7m */
#define MPU_TYPE_DREGION_LSB		8
#define MPU_TYPE_DREGION		(0xFF << MPU_TYPE_DREGION_LSB) /**< Number of protected data regions */
#define MPU_TYPE_SEPARATE		(1<<0) /**< Indicates if instruction regions are separate from data regions; always 0 on v6m/v7m */
/**@}*/

/** @defgroup CM3_mpu_ctrl MPU CTRL register fields
 * @ingroup CM3_mpu_defines
 * Defines for the Control Register.
 *@{*/
#define MPU_CTRL_PRIVDEFENA		(1<<2) /**< Enable default map in privileged mode */
#define MPU_CTRL_HFNMIENA		(1<<1) /**< Enable MPU during hard fault, NMI, and FAULTMASK handlers */
#define MPU_CTRL_ENABLE			(1<<0) /**< MPU enable */
/**@}*/

/** @defgroup CM3_mpu_rnr MPU RNR register fields
 * @ingroup CM3_mpu_defines
 * Defines for the Region Number Register.
 *@{*/
#define MPU_RNR_REGION_LSB		0
#define MPU_RNR_REGION			(0xFF << MPU_RNR_REGION_LSB) /**< Determines the region affected by RBAR and RASR */
/**@}*/

/** @defgroup CM3_mpu_rbar MPU RBAR register fields
 * @ingroup CM3_mpu_defines
 * Defines for the Region Base Address Register.
 *@{*/
/** minimum size supported is by writing all ones to ADDR, then reading back */
#define MPU_RBAR_ADDR			0xFFFFFFE0
#define MPU_RBAR_VALID			(1<<4) /**< Use REGION to determine region to be accessed instead of MPU_RNR */
#define MPU_RBAR_REGION_LSB		0
#define MPU_RBAR_REGION			(0xF << MPU_RBAR_REGION_LSB) /**< Region to change if MPU_RBAR_VALID is set */
/**@}*/

/** @defgroup CM3_mpu_rasr MPU RASR register fields
 * @ingroup CM3_mpu_defines
 * Defines for the Region Attribute and Size Register.
 *@{*/
#define MPU_RASR_ATTRS_LSB		16
#define MPU_RASR_ATTRS			(0xFFFF << MPU_RASR_ATTRS_LSB) /** Region attributes */
#define MPU_RASR_SRD_LSB		8
#define MPU_RASR_SRD			(0xFF << MPU_RASR_SRD_LSB) /**< Subregion disable bits */
#define MPU_RASR_SIZE_LSB		1
#define MPU_RASR_SIZE			(0x1F << MPU_RASR_SIZE_LSB) /**< Region size */
#define MPU_RASR_ENABLE			(1 << 0) /**< Region enable bit */

/** @defgroup mpu_rasr_attributes MPU RASR Attributes
 * @ingroup CM3_mpu_rasr
 * Not all attributes are available on v6m.
 *
 *@{*/
#define MPU_RASR_ATTR_XN		(1 << 28) /**< Execute never */
#define MPU_RASR_ATTR_AP		(7 << 24) /**< Access permissions mask */
#define MPU_RASR_ATTR_AP_PNO_UNO	(0 << 24) /**< Priv.: no, Unpriv.: no */
#define MPU_RASR_ATTR_AP_PRW_UNO	(1 << 24) /**< Priv.: RW, Unpriv.: no */
#define MPU_RASR_ATTR_AP_PRW_URO	(2 << 24) /**< Priv.: RW, Unpriv.: RO */
#define MPU_RASR_ATTR_AP_PRW_URW	(3 << 24) /**< Priv.: RW, Unpriv.: RW */
#define MPU_RASR_ATTR_AP_PRO_UNO	(5 << 24) /**< Priv.: RO, Unpriv.: no */
#define MPU_RASR_ATTR_AP_PRO_URO	(6 << 24) /**< Priv.: RO, Unpriv.: RO */
#define MPU_RASR_ATTR_TEX		(7 << 19) /**< Type extension (e.g., memory ordering) */
#define MPU_RASR_ATTR_S			(1 << 18) /**< Shareable */
#define MPU_RASR_ATTR_C			(1 << 17) /**< Cacheable */
#define MPU_RASR_ATTR_B			(1 << 16) /**< Bufferable */
#define MPU_RASR_ATTR_SCB		(7 << 16) /**< SCB mask */
/**@}*/
/**@}*/

/* --- MPU functions ------------------------------------------------------- */

BEGIN_DECLS


END_DECLS

/**@}*/

#endif
