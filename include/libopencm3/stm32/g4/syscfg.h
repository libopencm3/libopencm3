/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @ingroup STM32G4xx_defines 
 *
 * @brief Defined Constants and Types for the STM32F4xx Sysconfig
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 13 January 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */

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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/** @defgroup syscfg_registers SYSCFG Registers
@ingroup syscfg_defines
@{*/

/** SYSCFG: memory remap register */
#define SYSCFG_MEMRMP		MMIO32(SYSCFG_BASE + 0x00)

/** SYSCFG: configuration register 1 */
#define SYSCFG_CFGR1		MMIO32(SYSCFG_BASE + 0x04)

/** EXTICR: SYSCFG external interrupt configuration register*/
#define SYSCFG_EXTICR(i)	MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1		SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2		SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3		SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4		SYSCFG_EXTICR(3)

/** SCSR: SYSCFG CCM SRAM control and status register */
#define SYSCFG_SCSR			MMIO32(SYSCFG_BASE + 0x18)

/** CFGR2: SYSCFG configuration register 2 */
#define SYSCFG_CFGR2		MMIO32(SYSCFG_BASE + 0x1C)

/** SWPR: SYSCFG CCM SRAM write protection register */
#define SYSCFG_SWPR			MMIO32(SYSCFG_BASE + 0x20)

/** SKR: SYSCFG CCM SRAM key register */
#define SYSCFG_SKR			MMIO32(SYSCFG_BASE + 0x24)

/**@}*/

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* SYSCFG_MEMRMP Values -- ---------------------------------------------------*/

/** @defgroup syscfg_memrmp_values SYSCFG_MEMRMP Values
@ingroup syscfg_registers
@{*/

/** FB_MODE: Flash Bank mode selection */
#define SYSCFG_MEMRMP_FB_MODE   (1 << 8)

#define SYSCFG_MEMRMP_MEM_MODE_MASK  7
#define SYSCFG_MEMRMP_MEM_MODE_SHIFT 0
/** MEM_MODE[2:0]: Memory mapping selection
 * @defgroup syscfg_memrmp_mem_mode Memory mapping selection
 * @ingroup syscfg_memrmp_values
 * @{
 */
#define SYSCFG_MEMRMP_MEM_MODE_MAIN_FLASH_0X0 	(0x0 << SYSCFG_MEMRMP_MEM_MODE_SHIFT)
#define SYSCFG_MEMRMP_MEM_MODE_SYSTEM_FLASH_0X0	(0x1 << SYSCFG_MEMRMP_MEM_MODE_SHIFT)
#define SYSCFG_MEMRMP_MEM_MODE_FSMC_MEMORY		(0x2 << SYSCFG_MEMRMP_MEM_MODE_SHIFT)
#define SYSCFG_MEMRMP_MEM_MODE_SRAM1_0X0		(0x3 << SYSCFG_MEMRMP_MEM_MODE_SHIFT)
#define SYSCFG_MEMRMP_MEM_MODE_QUADSPI_0X0		(0x4 << SYSCFG_MEMRMP_MEM_MODE_SHIFT)
/**@}*/


/**@}*/


/* SYSCFG_CFGR1 Values -- ---------------------------------------------------*/

/** @defgroup syscfg_cfgr1_values SYSCFG_MEMRMP Values
@ingroup syscfg_registers
@{*/

/**  */

/** FPU_IE[5..0]: Floating Point Unit interrupts enable bits
 * @defgroup syscfg_cfgr1_fpu_ie Floating Point Unit interrupts enable bits
 * @ingroup syscfg_cfgr1_values
 * @{
 */

/** FPU_IE[0]: Invalid operation interrupt enable */ 
#define SYSCFG_CFGR1_FPU_IE0			(1 << 26)

/** FPU_IE[1]: Divide-by-zero interrupt enable */ 
#define SYSCFG_CFGR1_FPU_IE1			(1 << 27)

/** FPU_IE[2]: underflow interrupt enable */ 
#define SYSCFG_CFGR1_FPU_IE2			(1 << 28)

/** FPU_IE[3]: Overflow interrupt enable */ 
#define SYSCFG_CFGR1_FPU_IE3			(1 << 29)

/** FPU_IE[4]: Input denormal interrupt enable */ 
#define SYSCFG_CFGR1_FPU_IE4			(1 << 30)

/** FPU_IE[5]: Inexact interrupt enable */ 
#define SYSCFG_CFGR1_FPU_IE5			(1 << 31)

/**@}*/


/** I2C4_FMP: Fast-mode Plus driving capability activation */ 
#define SYSCFG_CFGR1_I2C4_FMP			(1 << 23)

/** I2C3_FMP: I2C3 Fast-mode Plus driving capability activation */ 
#define SYSCFG_CFGR1_I2C3_FMP			(1 << 22)

/** I2C2_FMP: I2C2 Fast-mode Plus driving capability activation */ 
#define SYSCFG_CFGR1_I2C2_FMP			(1 << 21)

/** I2C1_FMP: I2C1 Fast-mode Plus driving capability activation */ 
#define SYSCFG_CFGR1_I2C1_FMP			(1 << 20)

/** I2C_PB9_FMP: Fast-mode Plus (Fm+) driving capability activation on PB9 */ 
#define SYSCFG_CFGR1_I2C_PB9_FMP		(1 << 19)

/** I2C_PB8_FMP: Fast-mode Plus (Fm+) driving capability activation on PB8 */ 
#define SYSCFG_CFGR1_I2C_PB8_FMP		(1 << 18)

/** I2C_PB7_FMP: Fast-mode Plus (Fm+) driving capability activation on PB7 */ 
#define SYSCFG_CFGR1_I2C_PB7_FMP		(1 << 17)

/** I2C_PB6_FMP: Fast-mode Plus (Fm+) driving capability activation on PB6 */ 
#define SYSCFG_CFGR1_I2C_PB6_FMP		(1 << 16)

/** ANASWVDD: GPIO analog switch control voltage selection */ 
#define SYSCFG_CFGR1_ANASWVDD			(1 << 9)

/** BOOSTEN: I/O analog switch voltage booster enable */ 
#define SYSCFG_CFGR1_BOOSTEN			(1 << 8)

/**@}*/

/* SYSCFG_EXTICR Values -- --------------------------------------------------*/

/** @defgroup syscfg_exticr_values SYSCFG_EXTICR Values
@ingroup syscfg_registers
@{*/


/** EXTI[3:0]: EXTI configuration bits
 * @defgroup syscfg_exticr_exti select the source input for the EXTI external interrupt
 * @ingroup syscfg_exticr_values
 * @{
 */
#define SYSCFG_EXTICR_FIELDSIZE		4
#define SYSCFG_EXTICR_EXTI_GPIOA	0
#define SYSCFG_EXTICR_EXTI_GPIOB	1
#define SYSCFG_EXTICR_EXTI_GPIOC	2
#define SYSCFG_EXTICR_EXTI_GPIOD	3
#define SYSCFG_EXTICR_EXTI_GPIOE	4
#define SYSCFG_EXTICR_EXTI_GPIOF	5
#define SYSCFG_EXTICR_EXTI_GPIOG	6
/**@}*/

#define SYSCFG_EXTICR_EXTI_MASK		0xf

/** EXTI0[3:0]: EXTI 0 configuration bits shift */ 
#define SYSCFG_EXTICR1_EXTI0_SHIFT	0

/** EXTI1[3:0]: EXTI 1 configuration bits shift */ 
#define SYSCFG_EXTICR1_EXTI1_SHIFT	4

/** EXTI2[3:0]: EXTI 2 configuration bits shift */ 
#define SYSCFG_EXTICR1_EXTI2_SHIFT	8

/** EXTI3[3:0]: EXTI 3 configuration bits shift */ 
#define SYSCFG_EXTICR1_EXTI3_SHIFT	12

/** EXTI4[3:0]: EXTI 4 configuration bits shift */ 
#define SYSCFG_EXTICR2_EXTI4_SHIFT	0

/** EXTI5[3:0]: EXTI 5 configuration bits shift */ 
#define SYSCFG_EXTICR2_EXTI5_SHIFT	4

/** EXTI6[3:0]: EXTI 6 configuration bits shift */ 
#define SYSCFG_EXTICR2_EXTI6_SHIFT	8

/** EXTI7[3:0]: EXTI 7 configuration bits shift */ 
#define SYSCFG_EXTICR2_EXTI7_SHIFT	12

/** EXTI8[3:0]: EXTI 8 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI8_SHIFT	0

/** EXTI9[3:0]: EXTI 9 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI9_SHIFT	4

/** EXTI10[3:0]: EXTI 10 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI10_SHIFT	8

/** EXTI11[3:0]: EXTI 11 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI11_SHIFT	12

/** EXTI12[3:0]: EXTI 12 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI12_SHIFT	0

/** EXTI13[3:0]: EXTI 13 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI13_SHIFT	4

/** EXTI14[3:0]: EXTI 14 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI14_SHIFT	8

/** EXTI15[3:0]: EXTI 15 configuration bits shift */ 
#define SYSCFG_EXTICR3_EXTI15_SHIFT	12

/**@}*/

/* SYSCFG_SCSR Values -- --------------------------------------------------*/

/** @defgroup syscfg_scsr_values SCSR Values
@ingroup syscfg_registers
@{*/

/** CCMBSY: CCM SRAM busy by erase operation */ 
#define SYSCFG_SCSR_CCMBSY			(1 << 1)

/** CCMER: CCM SRAM Erase */ 
#define SYSCFG_SCSR_CCMER			(1 << 0)

/**@}*/

/* SYSCFG_CFGR2 Values -- --------------------------------------------------*/

/** @defgroup syscfg_cfgr2_values CFGR2 Values
@ingroup syscfg_registers
@{*/

/** SPF: SRAM1 and CCM SRAM parity error flag */ 
#define SYSCFG_CFGR2_SPF			(1 << 8)

/** ECCL: ECC Lock */ 
#define SYSCFG_CFGR2_ECCL			(1 << 3)

/** PVDL: PVD lock enable bit */ 
#define SYSCFG_CFGR2_PVDL			(1 << 2)

/** SPL: SRAM1 and CCM SRAM parity lock bit */ 
#define SYSCFG_CFGR2_SPL			(1 << 1)

/** CLL: Cortex ® -M4 LOCKUP (Hardfault) output enable bit */ 
#define SYSCFG_CFGR2_CLL			(1 << 0)

/**@}*/

/* SYSCFG_SKR Values -- ---------------------------------------------------*/

/** @defgroup syscfg_skr_values CFGR2 Values
@ingroup syscfg_registers
@{*/


/** KEY[7:0]: CCM SRAM write protection key for software erase
 * @defgroup syscfg_skr_key CCM SRAM write protection key for software erase
 * @ingroup syscfg_skr_values
 * @{
 */
 
/** 1 Write protection disable key 0xCA */  
#define SYSCFG_SKR_KEY_0XCA		0xCA

/** 1 Write protection disable key 0x53 */  
#define SYSCFG_SKR_KEY_0X53		0x53

/**@}*/


/**@}*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

/**@}*/



#endif
