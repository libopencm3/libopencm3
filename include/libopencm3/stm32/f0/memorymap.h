/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 *  .. based on file from F4.
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

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- STM32 specific peripheral definitions ------------------------------- */

/* Memory map for all buses */
#define FLASH_BASE			(0x08000000U)
#define PERIPH_BASE			(0x40000000U)
#define INFO_BASE			(0x1ffff000U)
#define PERIPH_BASE_APB			(PERIPH_BASE + 0x00000000)
#define PERIPH_BASE_AHB1		(PERIPH_BASE + 0x00020000)
#define PERIPH_BASE_AHB2		(PERIPH_BASE + 0x08000000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB + 0x0400)

#define TIM6_BASE			(PERIPH_BASE_APB + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB + 0x1400)

#define TIM14_BASE			(PERIPH_BASE_APB + 0x2000)
/* PERIPH_BASE_APB1 + 0x2400 (0x4000 2400 - 0x4000 27FF): Reserved */
#define RTC_BASE			(PERIPH_BASE_APB + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB + 0x3000)
/* PERIPH_BASE_APB + 0x3400 (0x4000 3400 - 0x4000 37FF): Reserved */
#define SPI2_BASE			(PERIPH_BASE_APB + 0x3800)
/* PERIPH_BASE_APB + 0x4000 (0x4000 4000 - 0x4000 3FFF): Reserved */
#define USART2_BASE			(PERIPH_BASE_APB + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB + 0x4800)
#define USART4_BASE			(PERIPH_BASE_APB + 0x4C00)

#define I2C1_BASE			(PERIPH_BASE_APB + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB + 0x5800)
#define USB_DEV_FS_BASE			(PERIPH_BASE_APB + 0x5C00)
#define USB_PMA_BASE			(PERIPH_BASE_APB + 0x6000)
#define BX_CAN1_BASE			(PERIPH_BASE_APB + 0x6400)

#define CRS_BASE			(PERIPH_BASE_APB + 0x6C00)
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB + 0x7400)
#define CEC_BASE			(PERIPH_BASE_APB + 0x7800)

#define SYSCFG_COMP_BASE		(PERIPH_BASE_APB + 0x10000)
#define EXTI_BASE			(PERIPH_BASE_APB + 0x10400)

#define ADC_BASE			(PERIPH_BASE_APB + 0x12400)
#define TIM1_BASE			(PERIPH_BASE_APB + 0x12C00)
#define SPI1_BASE			(PERIPH_BASE_APB + 0x13000)

#define USART1_BASE			(PERIPH_BASE_APB + 0x13800)
#define TIM15_BASE			(PERIPH_BASE_APB + 0x14000)
#define TIM16_BASE			(PERIPH_BASE_APB + 0x14400)
#define TIM17_BASE			(PERIPH_BASE_APB + 0x14800)

#define DBGMCU_BASE			(PERIPH_BASE_APB + 0x15800)

/* AHB1 */
#define DMA_BASE			(PERIPH_BASE_AHB1 + 0x0000)
/* DMA is the name in the F0 refman, but all other stm32's use DMA1 */
#define DMA1_BASE			DMA_BASE

#define RCC_BASE			(PERIPH_BASE_AHB1 + 0x1000)

#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB1 + 0x2000)

#define CRC_BASE			(PERIPH_BASE_AHB1 + 0x3000)

#define TSC_BASE			(PERIPH_BASE_AHB1 + 0x4000)

/* AHB2 */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB2 + 0x0000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB2 + 0x0400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB2 + 0x0800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB2 + 0x0C00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB2 + 0x1000)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB2 + 0x1400)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(0x1FFFF7CCU)
#define DESIG_UNIQUE_ID_BASE		(0x1FFFF7ACU)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)

/* ST provided factory calibration values @ 3.3V */
#define ST_VREFINT_CAL		MMIO16(0x1FFFF7BA)
#define ST_TSENSE_CAL1_30C	MMIO16(0x1FFFF7B8)
#define ST_TSENSE_CAL2_110	MMIO16(0x1FFFF7C2)

#endif
