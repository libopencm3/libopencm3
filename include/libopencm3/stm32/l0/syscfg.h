/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L0xx System Config</b>
 *
 * @ingroup STM32L0xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2015
 * Robin Kreis <r.kreis@uni-bremen.de>
 *
 * @date 1 May 2015
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Robin Kreis <r.kreis@uni-bremen.de>
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

#define SYSCFG_CFGR1			MMIO32(SYSCFG_BASE + 0x00)
#define SYSCFG_CFGR2			MMIO32(SYSCFG_BASE + 0x04)
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4			SYSCFG_EXTICR(3)
#define COMP1_CTRL			MMIO32(SYSCFG_BASE + 0x18)
#define COMP2_CTRL			MMIO32(SYSCFG_BASE + 0x1C)
#define SYSCFG_CFGR3			MMIO32(SYSCFG_BASE + 0x20)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* SYSCFG_CFGR1 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR1_MEM_MODE_SHIFT	0
#define SYSCFG_CFGR1_MEM_MODE		(3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_FLASH	(0 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SYSTEM	(1 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SRAM	(3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)

#define SYSCFG_CFGR1_UFB		(1<<3)

#define SYSCFG_CFGR1_BOOT_MODE_SHIFT	8
#define SYSCFG_CFGR1_BOOT_MODE		(3 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)
#define SYSCFG_CFGR1_BOOT_MODE_FLASH	(0 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)
#define SYSCFG_CFGR1_BOOT_MODE_SYSTEM	(1 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)
#define SYSCFG_CFGR1_BOOT_MODE_SRAM	(3 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)

/* SYSCFG_CFGR2 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR2_FWDIS		(1 << 0)

#define SYSCFG_CFGR2_I2C_PB6_FMP	(1 << 8)
#define SYSCFG_CFGR2_I2C_PB7_FMP	(1 << 9)
#define SYSCFG_CFGR2_I2C_PB8_FMP	(1 << 10)
#define SYSCFG_CFGR2_I2C_PB9_FMP	(1 << 11)

#define SYSCFG_CFGR2_I2C1_FMP		(1 << 12)
#define SYSCFG_CFGR2_I2C2_FMP		(1 << 13)
#define SYSCFG_CFGR2_I2C3_FMP		(1 << 14)

/* REF_CFGR3 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR3_EN_VREFINT		(1 << 0)

#define SYSCFG_CFGR3_SEL_VREF_OUT_SHIFT	4
#define SYSCFG_CFGR3_SEL_VREF_OUT	(3 << SYSCFG_CFGR3_EN_VREFINT_SHIFT)
#define SYSCFG_CFGR3_SEL_VREF_OUT_PB0	(1 << SYSCFG_CFGR3_EN_VREFINT_SHIFT)
#define SYSCFG_CFGR3_SEL_VREF_OUT_PB1	(2 << SYSCFG_CFGR3_EN_VREFINT_SHIFT)

#define SYSCFG_CFGR3_ENBUF_VREFINT_ADC	(1 << 8)
#define SYSCFG_CFGR3_ENBUF_SENSOR_ADC	(1 << 9)
#define SYSCFG_CFGR3_ENBUF_VREFINT_COMP	(1 << 12)
#define SYSCFG_CFGR3_ENREF_HSI48	(1 << 13)

#define SYSCFG_CFGR3_REF_HSI48_RDYF	(1 << 26)
#define SYSCFG_CFGR3_SENSOR_ADC_RDYF	(1 << 27)
#define SYSCFG_CFGR3_VREFINT_ADC_RDYF	(1 << 28)
#define SYSCFG_CFGR3_VREFINT_COMP_RDYF	(1 << 29)
#define SYSCFG_CFGR3_VREFINT_RDYF	(1 << 30)
#define SYSCFG_CFGR3_REF_LOCK		(1 << 31)

/* SYSCFG_EXTICR Values -- --------------------------------------------------*/

#define SYSCFG_EXTICR_GPIOA		0
#define SYSCFG_EXTICR_GPIOB		1
#define SYSCFG_EXTICR_GPIOC		2
#define SYSCFG_EXTICR_GPIOD		3
#define SYSCFG_EXTICR_GPIOE		4
#define SYSCFG_EXTICR_GPIOH		5

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
