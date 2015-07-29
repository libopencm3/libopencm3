/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx System Config</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 13 January 2014
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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define SYSCFG_CFGR1			MMIO32(SYSCFG_COMP_BASE + 0x00)
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_COMP_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4			SYSCFG_EXTICR(3)
#define SYSCFG_CFGR2			MMIO32(SYSCFG_COMP_BASE + 0x18)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* SYSCFG_CFGR1 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR1_MEM_MODE_SHIFT		0
#define SYSCFG_CFGR1_MEM_MODE		(3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_FLASH	(0 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SYSTEM	(1 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SRAM	(3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)

#define SYSCFG_CFGR1_PA11_PA12_RMP	(1 << 4)
#define SYSCFG_CFGR1_ADC_DMA_RMP	(1 << 8)
#define SYSCFG_CFGR1_USART1_TX_DMA_RMP	(1 << 9)
#define SYSCFG_CFGR1_USART1_RX_DMA_RMP	(1 << 10)
#define SYSCFG_CFGR1_TIM16_DMA_RMP	(1 << 11)
#define SYSCFG_CFGR1_TIM17_DMA_RMP	(1 << 12)
#define SYSCFG_CFGR1_TIM16_DMA_RMP2	(1 << 13)
#define SYSCFG_CFGR1_TIM17_DMA_RMP2	(1 << 14)

#define SYSCFG_CFGR1_I2C_PB6_FMP	(1 << 16)
#define SYSCFG_CFGR1_I2C_PB7_FMP	(1 << 17)
#define SYSCFG_CFGR1_I2C_PB8_FMP	(1 << 18)
#define SYSCFG_CFGR1_I2C_PB9_FMP	(1 << 19)
#define SYSCFG_CFGR1_I2C1_FMP		(1 << 20)
#define SYSCFG_CFGR1_I2C2_FMP		(1 << 21)
#define SYSCFG_CFGR1_I2C_PA9_FMP	(1 << 22)
#define SYSCFG_CFGR1_I2C_PA10_FMP	(1 << 23)
#define SYSCFG_CFGR1_SPI2_DMA_RMP	(1 << 24)
#define SYSCFG_CFGR1_USART2_DMA_RMP	(1 << 25)
#define SYSCFG_CFGR1_USART3_DMA_RMP	(1 << 26)
#define SYSCFG_CFGR1_I2C1_DMA_RMP	(1 << 27)
#define SYSCFG_CFGR1_TIM1_DMA_RMP	(1 << 28)
#define SYSCFG_CFGR1_TIM2_DMA_RMP	(1 << 29)
#define SYSCFG_CFGR1_TIM3_DMA_RMP	(1 << 30)

/* SYSCFG_EXTICR Values -- --------------------------------------------------*/

#define SYSCFG_EXTICR_SKIP		4
#define SYSCFG_EXTICR_GPIOA		0
#define SYSCFG_EXTICR_GPIOB		1
#define SYSCFG_EXTICR_GPIOC		2
#define SYSCFG_EXTICR_GPIOD		3
#define SYSCFG_EXTICR_GPIOF		5

/* SYSCFG_CFGR2 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR2_LOCKUP_LOCK	(1 << 0)
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK	(1 << 1)
#define SYSCFG_CFGR2_PVD_LOCK		(1 << 2)
#define SYSCFG_CFGR2_SRAM_PEF		(1 << 8)

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
