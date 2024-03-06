/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @ingroup AT32F42x_defines
 *
 * @brief Defined Constants and Types for the ATM32F42x Sysconfig
 *
 * @version 1.0.0
 *
 *  */

/*
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
 */

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

/* --- SYSCFG registers ---------------------------------------------------- */
#define SYSCFG_CFGR1		MMIO32(SYSCFG_COMP_BASE + 0x00)	/* SCFG_CFG1 */
#define SYSCFG_EXTICR(i)	MMIO32(SYSCFG_COMP_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1		SYSCFG_EXTICR(0)		/* EXINTC1 */
#define SYSCFG_EXTICR2		SYSCFG_EXTICR(1)		/* EXINTC2 */
#define SYSCFG_EXTICR3		SYSCFG_EXTICR(2)		/* EXINTC3 */
#define SYSCFG_EXTICR4		SYSCFG_EXTICR(3)		/* EXINTC4 */
#define SYSCFG_CFGR2		MMIO32(SYSCFG_COMP_BASE + 0x18) /* SCFG_CFGR2 */

/* --- SYSCFG_CFGR1 values -------------------------------------------------- */

#define SYSCFG_CFGR1_PB14UH		(1 << 19)	/* PB14_UH */
#define SYSCFG_CFGR1_PB13UH		(1 << 18)	/* PB13_UH */
#define SYSCFG_CFGR1_PB9UH		(1 << 17)	/* PB9_UH */
#define SYSCFG_CFGR1_PB8UH		(1 << 16)	/* PB8_UH */
/* DMA_MAP [12:8] */
/* IR_MOD [7:6] */					/* IR_SRC_SEL */
#define SYSCFG_CFGR1_IR_POL		(1 << 5)	/* IR_POL */
#define SYSCFG_CFGR1_PA11_PA12_REMAP	(1 << 4)	/* PA11_12_PMP */
/* MEM_MODE [1:0] */					/* MEM_MAP_SEL */

#define SYSCFG_CFGR1_DMA_MAP_SHIFT	8
#define SYSCFG_CFGR1_DMA_MAP_MASK	(0x1f << SYSCFG_CFGR1_DMA_MAP_SHIFT)

#define SYSCFG_CFGR1_IR_MOD_SHIFT	6
#define SYSCFG_CFGR1_IR_MOD		(3 << SYSCFG_CFGR1_IR_MOD_SHIFT)
#define SYSCFG_CFGR1_IR_MOD_TIM16	0
#define SYSCFG_CFGR1_IR_MOD_USART1	1
#define SYSCFG_CFGR1_IR_MOD_USART4	2

#define SYSCFG_CFGR1_MEM_MODE_SHIFT	0
#define SYSCFG_CFGR1_MEM_MODE		(3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_FLASH	(0 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SYSTEM	(1 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SRAM	(3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)

/* --- SYSCFG_EXTICR values ------------------------------------------------- */
#define SYSCFG_EXTICR_FIELDSIZE		4

/* --- SYSCFG_CFGR2 values -------------------------------------------------- */
/* I2S_FD [31:30] */
#define SYSCFG_CFGR2_PVD_LOCK		(1 << 2)

#endif
