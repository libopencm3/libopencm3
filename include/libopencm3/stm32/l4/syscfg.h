/** @defgroup syscfg_defines SYSCFG defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx System Configuration
 * </b>
 *
 * @ingroup STM32L4xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Fergus Noble <fergusnoble@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Benjamin Levine <benjaminmileslevine@gmail.com>
 *
 * @version 1.0.0
 *
 * @date 23 February 2016
 *
 * LGPL License Terms @ref lgpl_license
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
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

/**@{*/
#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

/* --- SYSCFG registers ---------------------------------------------------- */

#define SYSCFG_MEMRMP			MMIO32(SYSCFG_BASE + 0x00)
#define SYSCFG_CFGR1			MMIO32(SYSCFG_BASE + 0x04)

/* External interrupt configuration registers [0..3] (SYSCFG_EXTICR[1..4]) */
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4			SYSCFG_EXTICR(3)

#define SYSCFG_SCSR             MMIO32(SYSCFG_BASE + 0x18)
#define SYSCFG_CFGR2			MMIO32(SYSCFG_BASE + 0x1C)
#define SYSCFG_SWPR				MMIO32(SYSCFG_BASE + 0x20)
#define SYSCFG_SKR				MMIO32(SYSCFG_BASE + 0x24)

/* --- SYSCFG_MEMRMP values ----------------------------------------- */

#define SYSCFG_MEMRMP_FB_MODE   (1 << 8)

#define SYSCFG_MEMRMP_MEM_MODE_SHIFT    0
#define SYSCFG_MEMRMP_MEM_MODE_MASK    0x07

#define SYSCFG_MEMRMP_MEM_MODE_MAIN    0x00
#define SYSCFG_MEMRMP_MEM_MODE_SYSTEM  0x01
#define SYSCFG_MEMRMP_MEM_MODE_FMC     0x02
#define SYSCFG_MEMRMP_MEM_MODE_SRAM    0x03
#define SYSCFG_MEMRMP_MEM_MODE_QUADSPI 0x06

/* --- SYSCFG_CFGR1 values ----------------------------------------- */

#define SYSCFG_CFGR1_FPU_IE_SHIFT    26
#define SYSCFG_CFGR1_FPU_IE_MASK    0x3f

#define SYSCFG_CFGR1_I2C3_FMP			(1 << 22)
#define SYSCFG_CFGR1_I2C2_FMP			(1 << 21)
#define SYSCFG_CFGR1_I2C1_FMP			(1 << 20)
#define SYSCFG_CFGR1_I2C_PB9_FMP	    (1 << 19)
#define SYSCFG_CFGR1_I2C_PB8_FMP		(1 << 18)
#define SYSCFG_CFGR1_I2C_PB7_FMP		(1 << 17)
#define SYSCFG_CFGR1_I2C_PB6_FMP		(1 << 16)
#define SYSCFG_CFGR1_BOOSTEN			(1 << 8)
#define SYSCFG_CFGR1_FWDIS			    (1 << 0)


/* --- SYSCFG_EXTICR Values ----------------------------------------- */

#define SYSCFG_EXTICR_MASK      0x07

#define SYSCFG_EXTICR_GPIOA		0
#define SYSCFG_EXTICR_GPIOB		1
#define SYSCFG_EXTICR_GPIOC		2
#define SYSCFG_EXTICR_GPIOD		3
#define SYSCFG_EXTICR_GPIOE		4
#define SYSCFG_EXTICR_GPIOF		5
#define SYSCFG_EXTICR_GPIOG		6

/* --- SYSCFG_SCSR Values ----------------------------------------- */

#define SYSCFG_SCSR_SRAM2BSY		(1 << 1)
#define SYSCFG_SCSR_SRAM2ER			(1 << 0)

/* --- SYSCFG_CFGR2 Values ----------------------------------------- */

#define SYSCFG_CFGR2_SPF			(1 << 8)
#define SYSCFG_CFGR2_ECCL			(1 << 3)
#define SYSCFG_CFGR2_PVDL			(1 << 2)
#define SYSCFG_CFGR2_SPL			(1 << 1)
#define SYSCFG_CFGR2_CLL			(1 << 0)

/* --- SYSCFG_CFGR2 Values ----------------------------------------- */

/* Value of between 0 and 31 is permitted */
#define SYSCFG_SWPR_PxWP(x)		(1 << x)

/* --- SYSCFG_SKR Values ----------------------------------------- */

#define SYSCFG_SKR_KEY_SHIFT        0
#define SYSCFG_SKR_KEY_MASK      0xff

#define SYSCFG_SKR_KEY1    0xca
#define SYSCFG_SKR_KEY2    0x53

/* --- Function prototypes ----------------------------------------- */
BEGIN_DECLS


END_DECLS

#endif
/**@}*/
