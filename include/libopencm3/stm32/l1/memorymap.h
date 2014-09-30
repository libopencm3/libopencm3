/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

/* Memory map for all busses */
#define PERIPH_BASE			(0x40000000U)
#define INFO_BASE			(0x1ff00000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB			(PERIPH_BASE + 0x20000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE			(PERIPH_BASE_APB1 + 0x0800)
#define TIM5_BASE			(PERIPH_BASE_APB1 + 0x0c00)
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
#define LCD_BASE			(PERIPH_BASE_APB1 + 0x2400)
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
/* PERIPH_BASE_APB1 + 0x3400 (0x4000 3400 - 0x4000 37FF): Reserved */
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE			(PERIPH_BASE_APB1 + 0x3c00)
/* PERIPH_BASE_APB1 + 0x4000 (0x4000 4000 - 0x4000 3FFF): Reserved */
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define USART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
#define USART5_BASE			(PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define USB_DEV_FS_BASE			(PERIPH_BASE_APB1 + 0x5c00)
#define USB_SRAM_BASE			(PERIPH_BASE_APB1 + 0x6000)
/* gap */
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
#define OPAMP_BASE			(PERIPH_BASE_APB1 + 0x7c5c)
#define COMP_BASE			(PERIPH_BASE_APB1 + 0x7c00)
#define ROUTING_BASE	                (PERIPH_BASE_APB1 + 0x7c04)

/* APB2 */
#define SYSCFG_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x0400)
#define TIM9_BASE			(PERIPH_BASE_APB2 + 0x0800)
#define TIM10_BASE			(PERIPH_BASE_APB2 + 0x0c00)
#define TIM11_BASE			(PERIPH_BASE_APB2 + 0x1000)
/* gap */
#define ADC_BASE			(PERIPH_BASE_APB2 + 0x2400)
/* ADC is the name in the L1 refman, but all other stm32's use ADC1 */
#define ADC1_BASE			ADC_BASE
/* gap */
#define SDIO_BASE			(PERIPH_BASE_APB2 + 0x2c00)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
/* gap */
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)

/* AHB */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB + 0x00000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB + 0x00400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB + 0x00800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB + 0x00c00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB + 0x01000)
#define GPIO_PORT_H_BASE		(PERIPH_BASE_AHB + 0x01400)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB + 0x01800)
#define GPIO_PORT_G_BASE		(PERIPH_BASE_AHB + 0x01c00)
/* gap */
#define CRC_BASE			(PERIPH_BASE_AHB + 0x03000)
/* gap */
#define RCC_BASE			(PERIPH_BASE_AHB + 0x03800)
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB + 0x03c00)
/* gap */
#define DMA1_BASE			(PERIPH_BASE_AHB + 0x06000)
#define DMA2_BASE			(PERIPH_BASE_AHB + 0x04000)

/* PPIB */
#define DBGMCU_BASE			(PPBI_BASE + 0x00042000)

/* FSMC */
#define FSMC_BASE			(PERIPH_BASE +  0x60000000)
/* AES */
#define AES_BASE			(PERIPH_BASE +  0x10000000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x8004C)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x80050)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 0x14)

/* ST provided factory calibration values @ 3.0V */
#define ST_VREFINT_CAL			MMIO16(0x1FF80078)
#define ST_TSENSE_CAL1_30C		MMIO16(0x1FF8007A)
#define ST_TSENSE_CAL2_110C		MMIO16(0x1FF8007E)

#endif
