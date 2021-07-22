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

/* --- STM32 specific peripheral definitions ------------------------------- */

/* Memory map for all busses */
#define FLASH_BASE			(0x08000000U)
#define PERIPH_BASE			(0x40000000U)
#define FMC1_BANK_BASE			(0x60000000U)
#define FMC3_BANK_BASE			(0x80000000U)
#define OCTOSPI1_BANK_BASE		(0x90000000U)
#define INFO_BASE			(0x0BF99000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB1		(PERIPH_BASE + 0x20000)
#define PERIPH_BASE_AHB2		(PERIPH_BASE + 0x2020000)
#define PERIPH_BASE_AHB3		(PERIPH_BASE + 0x4020000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE			(PERIPH_BASE_APB1 + 0x0800)
#define TIM5_BASE			(PERIPH_BASE_APB1 + 0x0c00)
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
#define TAMP_BASE			(PERIPH_BASE_APB1 + 0x3400)
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE			(PERIPH_BASE_APB1 + 0x3c00)
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE			(PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define I2C3_BASE			(PERIPH_BASE_APB1 + 0x5c00)
#define CRS_BASE			(PERIPH_BASE_APB1 + 0x6000)
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
#define OPAMP_BASE			(PERIPH_BASE_APB1 + 0x7800)
#define LPTIM1_BASE			(PERIPH_BASE_APB1 + 0x7c00)
#define LPUART1_BASE			(PERIPH_BASE_APB1 + 0x8000)
#define I2C4_BASE			(PERIPH_BASE_APB1 + 0x8400)
#define LPTIM2_BASE			(PERIPH_BASE_APB1 + 0x9400)
#define LPTIM3_BASE			(PERIPH_BASE_APB1 + 0x9800)
#define FDCAN1_BASE			(PERIPH_BASE_APB1 + 0xA400)
#define FDCAN_RAM_BASE			(PERIPH_BASE_APB1 + 0xAC00)
#define USB_DEV_FS_BASE                 (PERIPH_BASE_APB1 + 0xD400)
#define USB_PMA_BASE                    (PERIPH_BASE_APB1 + 0xD800)
#define UCPD1_BASE			(PERIPH_BASE_APB1 + 0xDC00)

/* APB2 */
#define SYSCFG_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define VREFBUF_BASE			(PERIPH_BASE_APB2 + 0x0100)
#define COMP_BASE			(PERIPH_BASE_APB2 + 0x0200)
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x2C00)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
#define TIM8_BASE			(PERIPH_BASE_APB2 + 0x3400)
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)
#define TIM15_BASE			(PERIPH_BASE_APB2 + 0x4000)
#define TIM16_BASE			(PERIPH_BASE_APB2 + 0x4400)
#define TIM17_BASE			(PERIPH_BASE_APB2 + 0x4800)
#define SAI1_BASE			(PERIPH_BASE_APB2 + 0x5400)
#define SAI2_BASE			(PERIPH_BASE_APB2 + 0x5800)
#define DFSDM_BASE			(PERIPH_BASE_APB2 + 0x6000)

/* AHB1 */
#define DMA1_BASE			(PERIPH_BASE_AHB1 + 0x0000)
#define DMA2_BASE			(PERIPH_BASE_AHB1 + 0x0400)
#define DMAMUX_BASE			(PERIPH_BASE_AHB1 + 0x0800)
#define RCC_BASE			(PERIPH_BASE_AHB1 + 0x1000)
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB1 + 0x2000)
#define CRC_BASE			(PERIPH_BASE_AHB1 + 0x3000)
#define TSC_BASE			(PERIPH_BASE_AHB1 + 0x4000)
#define EXTI_BASE			(PERIPH_BASE_AHB1 + 0xF400)
#define ICACHE_BASE			(PERIPH_BASE_AHB1 + 0x10400)
#define GTZC_BASE			(PERIPH_BASE_AHB1 + 0x12400)

/* AHB2 */
#define GPIO_PORT_A_BASE		(PERIPH_BASE_AHB2 + 0x0000)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_AHB2 + 0x0400)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_AHB2 + 0x0800)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_AHB2 + 0x0c00)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_AHB2 + 0x1000)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_AHB2 + 0x1400)
#define GPIO_PORT_G_BASE		(PERIPH_BASE_AHB2 + 0x1800)
#define GPIO_PORT_H_BASE		(PERIPH_BASE_AHB2 + 0x1C00)
#define ADC1_BASE			(PERIPH_BASE_AHB2 + 0x8000)
#define AES_BASE			(PERIPH_BASE_AHB2 + 0xA0000)
#define HASH_BASE			(PERIPH_BASE_AHB2 + 0xA0400)
#define RNG_BASE			(PERIPH_BASE_AHB2 + 0xA0800)
#define PKA_BASE			(PERIPH_BASE_AHB2 + 0xA2000)
#define OFTDEC1_BASE			(PERIPH_BASE_AHB2 + 0xA5000)
#define SDMMC1_BASE			(PERIPH_BASE_AHB2 + 0xA8000)

/* AHB3 */
#define FMC_BASE			(PERIPH_BASE_AHB3 + 0x0000)
#define OCTOSPI_BASE			(PERIPH_BASE_AHB3 + 0x1000)

/* Private peripherals */
#define DBGMCU_BASE			(PPBI_BASE + 0x00044000)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x75e0)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x7590)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)
#define DESIG_PACKAGE			MMIO16((INFO_BASE + 0x7500))

/* ST provided factory calibration values @ 3.0V */
#define ST_VREFINT_CAL			MMIO16((INFO_BASE + 0x75aa))
#define ST_TSENSE_CAL1_30C		MMIO16((INFO_BASE + 0x75a8))
#define ST_TSENSE_CAL2_110C		MMIO16((INFO_BASE + 0x75ca))

#endif
