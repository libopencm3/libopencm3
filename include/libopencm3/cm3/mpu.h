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

#ifndef LIBOPENCM3_CM0_MPU_H
#define LIBOPENCM3_CM0_MPU_H

#ifndef CM0_PLUS
#error "mpu is supported only on CM0+ architecture"
#else

#include <libopencm3/cm0/memorymap.h>
#include <libopencm3/cm0/common.h>

/* --- SCB: Registers ------------------------------------------------------ */

#define MPU_TYPE			MMIO32(MPU_BASE + 0x00)
#define MPU_CTRL			MMIO32(MPU_BASE + 0x04)
#define MPU_RNR				MMIO32(MPU_BASE + 0x08)
#define MPU_RBAR			MMIO32(MPU_BASE + 0x0C)
#define MPU_RASR			MMIO32(MPU_BASE + 0x10)

/* --- MPU values ---------------------------------------------------------- */

/* --- MPU_TYPE values ----------------------------------------------------- */

#define MPU_TYPE_IREGION_LSB		16
#define MPU_TYPE_IREGION		(0xFF << MPU_TYPE_IREGION_LSB)
#define MPU_TYPE_DREGION_LSB		8
#define MPU_TYPE_DREGION		(0xFF << MPU_TYPE_DREGION_LSB)
#define MPU_TYPE_SEPARATE		(1<<0)

/* --- MPU_CTRL values ----------------------------------------------------- */

#define MPU_CTRL_PRIVDEFENA		(1<<2)
#define MPU_CTRL_HFNMIENA		(1<<1)
#define MPU_CTRL_ENABLE			(1<<0)

/* --- MPU_RNR values ------------------------------------------------------ */

#define MPU_RNR_REGION_LSB		0
#define MPU_RNR_REGION			(0xFF << MPU_RNR_REGION_LSB)

/* --- MPU_RBAR values ----------------------------------------------------- */

#define MPU_RBAR_ADDR_LSB		8
#define MPU_RBAR_ADDR			(0x00FFFFFF << MPU_RBAR_REGION_LSB)
#define MPU_RBAR_VALID			(1<<4)
#define MPU_RBAR_REGION_LSB		0
#define MPU_RBAR_REGION			(0xF << MPU_RBAR_REGION_LSB)

/* --- MPU_RASR values ----------------------------------------------------- */

#define MPU_RASR_ATTRS_LSB		16
#define MPU_RASR_ATTRS			(0xFFFF << MPU_RASR_ATTRS_LSB)
#define MPU_RASR_SRD_LSB		8
#define MPU_RASR_SRD			(0xFF << MPU_RASR_SRD_LSB)
#define MPU_RASR_SIZE_LSB		1
#define MPU_RASR_SIZE			(0x1F << MPU_RASR_SIZE_LSB)
#define MPU_RASR_ENABLE			(1 << 0)


#define MPU_RASR_ATTR_XN		(1 << 28)
#define MPU_RASR_ATTR_AP		(7 << 24)
#define MPU_RASR_ATTR_AP_PNO_UNO	(0 << 24)
#define MPU_RASR_ATTR_AP_PRW_UNO	(1 << 24)
#define MPU_RASR_ATTR_AP_PRW_URO	(2 << 24)
#define MPU_RASR_ATTR_AP_PRW_URW	(3 << 24)
#define MPU_RASR_ATTR_AP_PRO_UNO	(5 << 24)
#define MPU_RASR_ATTR_AP_PRO_URO	(6 << 24)
#define MPU_RASR_ATTR_AP_PRO_URO	(7 << 24)
#define MPU_RASR_ATTR_TEX		(7 << 19)
#define MPU_RASR_ATTR_S			(1 << 18)
#define MPU_RASR_ATTR_C			(1 << 17)
#define MPU_RASR_ATTR_B			(1 << 16)
#define MPU_RASR_ATTR_SCB		(7 << 16)
#define MPU_RASR_ATTR_SCB_SH_STRONG	(0 << 16)
#define MPU_RASR_ATTR_SCB_SH_DEVICE	(1 << 16)
#define MPU_RASR_ATTR_SCB_NSH_WT	(2 << 16)
#define MPU_RASR_ATTR_SCB_NSH_WB	(3 << 16)
#define MPU_RASR_ATTR_SCB_SH_STRONG	(4 << 16)
#define MPU_RASR_ATTR_SCB_SH_DEVICE	(5 << 16)
#define MPU_RASR_ATTR_SCB_SH_WT		(6 << 16)
#define MPU_RASR_ATTR_SCB_SH_WB		(7 << 16)

/* --- MPU functions ------------------------------------------------------- */

BEGIN_DECLS


END_DECLS

#endif /* CM0_PLUS */

#endif
