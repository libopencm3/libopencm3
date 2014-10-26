/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

/* --- STM32F20x specific peripheral definitions --------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE			(0x40000000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB1		(PERIPH_BASE + 0x20000)
#define PERIPH_BASE_AHB2		(0x50000000U)
#define PERIPH_BASE_AHB3		(0x60000000U)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE			(PERIPH_BASE_APB1 + 0x0800)
#define TIM5_BASE			(PERIPH_BASE_APB1 + 0x0c00)
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
#define TIM12_BASE			(PERIPH_BASE_APB1 + 0x1800)
#define TIM13_BASE			(PERIPH_BASE_APB1 + 0x1c00)
#define TIM14_BASE			(PERIPH_BASE_APB1 + 0x2000)
/* PERIPH_BASE_APB1 + 0x2400 (0x4000 2400 - 0x4000 27FF): Reserved */
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
/* PERIPH_BASE_APB1 + 0x3400 (0x4000 3400 - 0x4000 37FF): Reserved */
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE			(PERIPH_BASE_APB1 + 0x3c00)
/* PERIPH_BASE_APB1 + 0x4000 (0x4000 4000 - 0x4000 3FFF): Reserved */
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE			(PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define I2C3_BASE			(PERIPH_BASE_APB1 + 0x5C00)
/* PERIPH_BASE_APB1 + 0x6000 (0x4000 6000 - 0x4000 63FF): Reserved */
#define BX_CAN1_BASE			(PERIPH_BASE_APB1 + 0x6400)
#define BX_CAN2_BASE			(PERIPH_BASE_APB1 + 0x6800)
/* PERIPH_BASE_APB1 + 0x6C00 (0x4000 6C00 - 0x4000 6FFF): Reserved */
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
/* PERIPH_BASE_APB1 + 0x7800 (0x4000 7800 - 0x4000 FFFF): Reserved */

/* APB2 */
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define TIM8_BASE			(PERIPH_BASE_APB2 + 0x0400)
/* PERIPH_BASE_APB2 + 0x0800 (0x4001 0800 - 0x4001 0FFF): Reserved */
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x1000)
#define USART6_BASE			(PERIPH_BASE_APB2 + 0x1400)
/* PERIPH_BASE_APB2 + 0x1800 (0x4001 1800 - 0x4001 1FFF): Reserved */
#define ADC1_BASE			(PERIPH_BASE_APB2 + 0x2000)
#define ADC2_BASE			(PERIPH_BASE_APB2 + 0x2000)
#define ADC3_BASE			(PERIPH_BASE_APB2 + 0x2000)
/* PERIPH_BASE_APB2 + 0x2400 (0x4001 2400 - 0x4001 27FF): Reserved */
#define SDIO_BASE			(PERIPH_BASE_APB2 + 0x2C00)
/* PERIPH_BASE_APB2 + 0x2C00 (0x4001 2C00 - 0x4001 2FFF): Reserved */
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
/* PERIPH_BASE_APB2 + 0x3400 (0x4001 3400 - 0x4001 37FF): Reserved */
#define SYSCFG_BASE			(PERIPH_BASE_APB2 + 0x3800)
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x3C00)
#define TIM9_BASE			(PERIPH_BASE_APB2 + 0x4000)
#define TIM10_BASE			(PERIPH_BASE_APB2 + 0x4400)
#define TIM11_BASE			(PERIPH_BASE_APB2 + 0x4800)
/* PERIPH_BASE_APB2 + 0x4C00 (0x4001 4C00 - 0x4001 FFFF): Reserved */

/* AHB1 */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB1 + 0x0000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB1 + 0x0400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB1 + 0x0800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB1 + 0x0C00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB1 + 0x1000)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB1 + 0x1400)
#define GPIO_PORT_G_BASE		(PERIPH_BASE_AHB1 + 0x1800)
#define GPIO_PORT_H_BASE		(PERIPH_BASE_AHB1 + 0x1C00)
#define GPIO_PORT_I_BASE		(PERIPH_BASE_AHB1 + 0x2000)
/* PERIPH_BASE_AHB1 + 0x2400 (0x4002 2400 - 0x4002 2FFF): Reserved */
#define CRC_BASE			(PERIPH_BASE_AHB1 + 0x3000)
/* PERIPH_BASE_AHB1 + 0x3400 (0x4002 3400 - 0x4002 37FF): Reserved */
#define RCC_BASE			(PERIPH_BASE_AHB1 + 0x3800)
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB1 + 0x3C00)
#define BKPSRAM_BASE	(PERIPH_BASE_AHB1 + 0x4000)
/* PERIPH_BASE_AHB1 + 0x5000 (0x4002 5000 - 0x4002 5FFF): Reserved */
#define DMA1_BASE			(PERIPH_BASE_AHB1 + 0x6000)
#define DMA2_BASE			(PERIPH_BASE_AHB1 + 0x6400)
/* PERIPH_BASE_AHB1 + 0x6800 (0x4002 6800 - 0x4002 7FFF): Reserved */
#define ETHERNET_BASE			(PERIPH_BASE_AHB1 + 0x8000)
/* PERIPH_BASE_AHB1 + 0x9400 (0x4002 9400 - 0x4003 FFFF): Reserved */
#define USB_OTG_HS_BASE			(PERIPH_BASE_AHB1 + 0x20000)
/* PERIPH_BASE_AHB1 + 0x60000 (0x4008 0000 - 0x4FFF FFFF): Reserved */

/* AHB2 */
#define USB_OTG_FS_BASE			(PERIPH_BASE_AHB2 + 0x0000)
/* PERIPH_BASE_AHB2 + 0x40000 (0x5004 0000 - 0x5004 FFFF): Reserved */
#define DCMI_BASE			(PERIPH_BASE_AHB2 + 0x50000)
/* PERIPH_BASE_AHB2 + 0x50400 (0x5005 0400 - 0x5005 FFFF): Reserved */
#define CRYP_BASE			(PERIPH_BASE_AHB2 + 0x60000)
#define HASH_BASE			(PERIPH_BASE_AHB2 + 0x60400)
#define RNG_BASE			(PERIPH_BASE_AHB2 + 0x60800)
/* PERIPH_BASE_AHB2 + 0x61000 (0x5006 1000 - 0x5FFF FFFF): Reserved */

/* AHB3 */
#define FSMC_BASE			(PERIPH_BASE_AHB3 + 0x40000000)

/* PPIB */
#define DBGMCU_BASE			(PPBI_BASE + 0x00042000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(0x1FFF7A22U)
#define DESIG_UNIQUE_ID_BASE		(0x1FFF7A10U)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)


#endif
