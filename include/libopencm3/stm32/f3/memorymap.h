/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Modified by 2013 Fernando Cortes <fernando.corcam@gmail.com> (stm32f3)
 * Modified by 2013 Guillermo Rivera <memogrg@gmail.com> (stm32f3)
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

/* --- STM32F3 specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE			(0x40000000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB1		(PERIPH_BASE + 0x20000)
#define PERIPH_BASE_AHB2		(0x48000000U)
#define PERIPH_BASE_AHB3		(0x50000000U)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE			(PERIPH_BASE_APB1 + 0x0800)
/* PERIPH_BASE_APB1 + 0x0C00 (0x4000 0C00 - 0x4000 0FFF): Reserved */
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
/* PERIPH_BASE_APB1 + 0x1800 (0x4000 1800 - 0x4000 27FF): Reserved */
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
#define I2S2_EXT_BASE			(PERIPH_BASE_APB1 + 0x3400)
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE			(PERIPH_BASE_APB1 + 0x3c00)
#define I2S3_EXT_BASE			(PERIPH_BASE_APB1 + 0x4000)
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE			(PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define USB_DEV_FS_BASE			(PERIPH_BASE_APB1 + 0x5C00)
#define USB_PMA_BASE			(PERIPH_BASE_APB1 + 0x6000)
#define BX_CAN1_BASE			(PERIPH_BASE_APB1 + 0x6400)
/* PERIPH_BASE_APB1 + 0x6800 (0x4000 6800 - 0x4000 6BFF): Reserved */
/* PERIPH_BASE_APB1 + 0x6C00 (0x4000 6C00 - 0x4000 6FFF): Reserved */
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
#define I2C3_BASE			(PERIPH_BASE_APB1 + 0x7800)
/* PERIPH_BASE_APB1 + 0x7800 (0x4000 7800 - 0x4000 7FFF): Reserved */


/* APB2 */
#define HRTIM_BASE			(PERIPH_BASE_APB2 + 0x7400)
#define TIM17_BASE			(PERIPH_BASE_APB2 + 0x4800)
#define TIM16_BASE			(PERIPH_BASE_APB2 + 0x4400)
#define TIM15_BASE			(PERIPH_BASE_APB2 + 0x4000)
/* PERIPH_BASE_APB2 + 0x3C00 (0x4001 3C00 - 0x4001 3FFF): Reserved */
#define SPI4_BASE			(PERIPH_BASE_APB2 + 0x3C00)
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)
#define TIM8_BASE			(PERIPH_BASE_APB2 + 0x3400)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x2C00)
/* PERIPH_BASE_APB2 + 0x0800 (0x4001 0800 - 0x4001 2BFF): Reserved */
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x0400)
#define SYSCFG_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define COMP_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define OPAMP_BASE			(PERIPH_BASE_APB2 + 0x0000)


/* AHB2 */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB2 + 0x0000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB2 + 0x0400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB2 + 0x0800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB2 + 0x0C00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB2 + 0x1000)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB2 + 0x1400)
#define GPIO_PORT_G_BASE		(PERIPH_BASE_AHB2 + 0x1800)
#define GPIO_PORT_H_BASE		(PERIPH_BASE_AHB2 + 0x1C00)


/* AHB1 */
#define TSC_BASE			(PERIPH_BASE_AHB1 + 0x4000)
/* PERIPH_BASE_AHB1 + 0x3400 (0x4002 3400 - 0x4002 37FF): Reserved */
#define CRC_BASE			(PERIPH_BASE_AHB1 + 0x3000)
/* PERIPH_BASE_AHB1 + 0x2400 (0x4002 2400 - 0x4002 2FFF): Reserved */
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB1 + 0x2000)
/* PERIPH_BASE_AHB1 + 0x1400 (0x4002 1400 - 0x4002 1FFF): Reserved */
#define RCC_BASE			(PERIPH_BASE_AHB1 + 0x1000)
/* PERIPH_BASE_AHB1 + 0x0800 (0x4002 0800 - 0x4002 0FFF): Reserved */
#define DMA1_BASE			(PERIPH_BASE_AHB1 + 0x0000)
#define DMA2_BASE			(PERIPH_BASE_AHB1 + 0x0400)


/* AHB3 */
#define ADC3_BASE			(PERIPH_BASE_AHB3 + 0x0400)
#define ADC4_BASE			(PERIPH_BASE_AHB3 + 0x0500)
#define ADC1_BASE			(PERIPH_BASE_AHB3 + 0x0000)
#define ADC2_BASE			(PERIPH_BASE_AHB3 + 0x0100)

/* PPIB */
#define DBGMCU_BASE			(PPBI_BASE + 0x00042000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(0x1FFFF7CCU)
#define DESIG_UNIQUE_ID_BASE		(0x1FFFF7ACU)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)

/* ST provided factory calibration values @ 3.3V */
#define ST_VREFINT_CAL		MMIO16(0x1FFFF7BA)
#define ST_TSENSE_CAL1_30C	MMIO16(0x1FFFF7B8)
#define ST_TSENSE_CAL2_110C	MMIO16(0x1FFFF7C2)

#endif
