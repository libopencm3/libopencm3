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

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- AT32F42x specific peripheral definitions ----------------------------- */

/* Memory map for all buses */
#define FLASH_BASE			(0x08000000U)
#define PERIPH_BASE			(0x40000000U)
#define INFO_BASE			(0x1ffff000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB			(PERIPH_BASE + 0x18000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
/* (PERIPH_BASE_APB1 + 0x0800) reserved */
/* (PERIPH_BASE_APB1 + 0x0c00) reserved */
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
/* (PERIPH_BASE_APB1 + 0x1800) reserved */
#define TIM13_BASE			(PERIPH_BASE_APB1 + 0x1c00)
#define TIM14_BASE			(PERIPH_BASE_APB1 + 0x2000)
/* (PERIPH_BASE_APB1 + 0x2400) reserved */
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
/* (PERIPH_BASE_APB1 + 0x3400) reserved */
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE			(PERIPH_BASE_APB1 + 0x3c00)
/* (PERIPH_BASE_APB1 + 0x4000) reserved */
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define USART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
/* (PERIPH_BASE_APB1 + 0x5000) reserved */
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
/* (PERIPH_BASE_APB1 + 0x5c00) reserved */
/* (PERIPH_BASE_APB1 + 0x6000) reserved */
#define BX_CAN1_BASE			(PERIPH_BASE_APB1 + 0x6400)
/* (PERIPH_BASE_APB1 + 0x6800) reserved */
#define CRS_BASE			(PERIPH_BASE_APB1 + 0x6c00)
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
/* (PERIPH_BASE_APB1 + 0x7400) reserved */
/* (PERIPH_BASE_APB1 + 0x7800) reserved */
/* (PERIPH_BASE_APB1 + 0x7c00) reserved */
/* (PERIPH_BASE_APB1 + 0x8000) reserved */

/* APB2 */
#define SYSCFG_COMP_BASE		(PERIPH_BASE_APB2 + 0x0000)
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x0400)
/* (PERIPH_BASE_APB2 + 0x0800) reserved */
/* (PERIPH_BASE_APB2 + 0x0c00) reserved */
/* (PERIPH_BASE_APB2 + 0x1000) reserved */
/* (PERIPH_BASE_APB2 + 0x1400) reserved */
/* (PERIPH_BASE_APB2 + 0x1800) reserved */
/* (PERIPH_BASE_APB2 + 0x1c00) reserved */
/* (PERIPH_BASE_APB2 + 0x2000) reserved */
#define ADC1_BASE			(PERIPH_BASE_APB2 + 0x2400)
/* (PERIPH_BASE_APB2 + 0x2800) reserved */
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x2c00)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
/* (PERIPH_BASE_APB2 + 0x3400) reserved */
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)
/* (PERIPH_BASE_APB2 + 0x3c00) reserved */
#define TIM15_BASE			(PERIPH_BASE_APB2 + 0x4000)
#define TIM16_BASE			(PERIPH_BASE_APB2 + 0x4400)
#define TIM17_BASE			(PERIPH_BASE_APB2 + 0x4800)
/* (PERIPH_BASE_APB2 + 0x4c00) reserved */
/* (PERIPH_BASE_APB2 + 0x5000) reserved */
/* (PERIPH_BASE_APB2 + 0x5400) reserved */
/* (PERIPH_BASE_APB2 + 0x5800) reserved */
/* (PERIPH_BASE_APB2 + 0x5c00) reserved */
/* (PERIPH_BASE_APB2 + 0x6000) reserved */
/* (PERIPH_BASE_APB2 + 0x6400) reserved */
/* (PERIPH_BASE_APB2 + 0x6800) reserved */
/* (PERIPH_BASE_APB2 + 0x6c00) reserved */
/* (PERIPH_BASE_APB2 + 0x7000) reserved */
/* (PERIPH_BASE_APB2 + 0x7400) reserved */
/* (PERIPH_BASE_APB2 + 0x7800) reserved */
/* (PERIPH_BASE_APB2 + 0x7c00) reserved */

/* AHB */
/* (PERIPH_BASE_AHB + 0x0000) reserved */
/* (PERIPH_BASE_AHB + 0x0400) reserved */
#define DMA1_BASE			(PERIPH_BASE_AHB + 0x08000)
/* (PERIPH_BASE_AHB + 0x8400) reserved */
/* (PERIPH_BASE_AHB + 0x8800) reserved */
#define RCC_BASE			(PERIPH_BASE_AHB + 0x09000)
/* (PERIPH_BASE_AHB + 0x9400) reserved */
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB + 0x0a000)
#define CRC_BASE			(PERIPH_BASE_AHB + 0x0b000)
/* (PERIPH_BASE_AHB + 0xb400) reserved */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB + 0x7fe8000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB + 0x7fe8400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB + 0x7fe8800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB + 0x7fe8c00)
/* (PERIPH_BASE_AHB + 0x7fe9000) reserved */
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB + 0x7fe9400)
/* (PERIPH_BASE_AHB + 0x7fe9800) reserved */
#define USB_OTG_FS_BASE			(PERIPH_BASE_AHB + 0xffe8000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x7e0)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x7e8)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)

#endif
