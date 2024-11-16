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

/* --- AT32F43x specific peripheral definitions ---------------------------- */

/* Memory map for all buses */
#define FLASH_BASE			(0x08000000U)
#define PERIPH_BASE			(0x40000000U)
#define INFO_BASE			(0x1ffff000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB1		(PERIPH_BASE + 0x20000)

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
/* PERIPH_BASE_APB1 + 0x4000 (0x4000 4000 - 0x4000 43FF): Reserved */
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE			(PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define I2C3_BASE			(PERIPH_BASE_APB1 + 0x5c00)
/* PERIPH_BASE_APB1 + 0x6000 (0x4000 6000 - 0x4000 63FF): Reserved */
#define BX_CAN1_BASE			(PERIPH_BASE_APB1 + 0x6400)
#define BX_CAN2_BASE			(PERIPH_BASE_APB1 + 0x6800)
/* PERIPH_BASE_APB1 + 0x6C00 (0x4000 6C00 - 0x4000 6FFF): Reserved */
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
#define UART7_BASE			(PERIPH_BASE_APB1 + 0x7800)
#define UART8_BASE			(PERIPH_BASE_APB1 + 0x7c00)
/* PERIPH_BASE_APB1 + 0x8000 (0x4000 8000 - 0x4000 FFFF): Reserved */

/* APB2 */
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define TIM8_BASE			(PERIPH_BASE_APB2 + 0x0400)
/* PERIPH_BASE_APB2 + 0x0800 (0x4001 0800 - 0x4001 0FFF): Reserved */
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x1000)
#define USART6_BASE			(PERIPH_BASE_APB2 + 0x1400)
/* PERIPH_BASE_APB2 + 0x1800 (0x4001 1800 - 0x4001 1FFF): Reserved */
#define ADC_BASE			(PERIPH_BASE_APB2 + 0x2000)
/* PERIPH_BASE_APB2 + 0x2400 (0x4001 2400 - 0x4001 2FFF): Reserved */
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
#define SPI4_BASE			(PERIPH_BASE_APB2 + 0x3400)
#define SYSCFG_COMP_BASE		(PERIPH_BASE_APB2 + 0x3800)
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x3c00)
#define TIM9_BASE			(PERIPH_BASE_APB2 + 0x4000)
#define TIM10_BASE			(PERIPH_BASE_APB2 + 0x4400)
#define TIM11_BASE			(PERIPH_BASE_APB2 + 0x4800)
#define TIM20_BASE			(PERIPH_BASE_APB2 + 0x4c00)
#define CRS_BASE			(PERIPH_BASE_APB2 + 0x7400)
#define I2S2_EXT_BASE			(PERIPH_BASE_APB2 + 0x7800)
#define I2S3_EXT_BASE			(PERIPH_BASE_APB2 + 0x7c00)

/* AHB1 */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB1 + 0x0000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB1 + 0x0400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB1 + 0x0800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB1 + 0x0C00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB1 + 0x1000)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB1 + 0x1400)
#define GPIO_PORT_G_BASE		(PERIPH_BASE_AHB1 + 0x1800)
#define GPIO_PORT_H_BASE		(PERIPH_BASE_AHB1 + 0x1C00)
/* PERIPH_BASE_AHB1 + 0x2000 (0x4002 2000 - 0x4002 2FFF): Reserved */
#define CRC_BASE			(PERIPH_BASE_AHB1 + 0x3000)
/* PERIPH_BASE_AHB1 + 0x3400 (0x4002 3400 - 0x4002 37FF): Reserved */
#define RCC_BASE			(PERIPH_BASE_AHB1 + 0x3800)
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB1 + 0x3C00)
/* PERIPH_BASE_AHB1 + 0x4000 (0x4002 4000 - 0x4002 5FFF): Reserved */
#define DMA0_BASE			(PERIPH_BASE_AHB1 + 0x6000)
#define DMA12_BASE			(PERIPH_BASE_AHB1 + 0x6400)
/* PERIPH_BASE_AHB1 + 0x6800 (0x4002 6800 - 0x4002 7FFF): Reserved */
#define ETHERNET_BASE			(PERIPH_BASE_AHB1 + 0x8000)
#define SDIO1_BASE			(PERIPH_BASE_AHB1 + 0xc400)

#define USB_OTG_FS2_BASE		(0x40040000u + 0x0000)
#define USB_OTG_FS1_BASE		(0x50000000u + 0x0000)

#define DCMI_BASE			(0x50050000u + 0x0000)
#define SDIO2_BASE			(0x50061000u + 0x0000)

#define FSMC_BASE			(0x60000000u + 0x0000)
#define QUADSPI1_BANK			(0x90000000u + 0x0000)
#define QUADSPI2_BANK			(0xb0000000u + 0x0000)

/* PPIB */
#define DBGMCU_BASE			(PPBI_BASE + 0x00042000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x7e0)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x7e8)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)

#endif
