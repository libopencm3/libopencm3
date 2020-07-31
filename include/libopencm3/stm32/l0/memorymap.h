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
#define PERIPH_BASE			(0x40000000U)
#define IOPORT_BASE			(0x50000000U)
#define INFO_BASE			(0x1ff80000U)
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB			(PERIPH_BASE + 0x20000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
#define LCD_BASE			(PERIPH_BASE_APB1 + 0x2400)
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
#define SPI2_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define LPUART1_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define USB_DEV_FS_BASE			(PERIPH_BASE_APB1 + 0x5c00)
#define USB_PMA_BASE			(PERIPH_BASE_APB1 + 0x6000)
#define CRS_BASE			(PERIPH_BASE_APB1 + 0x6C00)
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
#define I2C3_BASE			(PERIPH_BASE_APB1 + 0x7800)
#define LPTIM1_BASE			(PERIPH_BASE_APB1 + 0x7c00)


/* APB2 */
#define SYSCFG_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x0400)
#define TIM21_BASE			(PERIPH_BASE_APB2 + 0x0800)
#define TIM22_BASE			(PERIPH_BASE_APB2 + 0x1400)
#define FIREWALL_BASE			(PERIPH_BASE_APB2 + 0x1C00)
#define ADC1_BASE			(PERIPH_BASE_APB2 + 0x2400)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)
#define DBGMCU_BASE			(PERIPH_BASE_APB2 + 0x5800)

/* AHB */
#define DMA1_BASE			(PERIPH_BASE_AHB + 0x00000)
#define RCC_BASE			(PERIPH_BASE_AHB + 0x01000)
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB + 0x02000)
#define CRC_BASE			(PERIPH_BASE_AHB + 0x03000)
#define TSC_BASE			(PERIPH_BASE_AHB + 0x04000)
#define RNG_BASE			(PERIPH_BASE_AHB + 0x05000)
#define AES_BASE			(PERIPH_BASE_AHB + 0x06000)

#define GPIO_PORT_A_BASE		(IOPORT_BASE + 0x00000)
#define GPIO_PORT_B_BASE		(IOPORT_BASE + 0x00400)
#define GPIO_PORT_C_BASE		(IOPORT_BASE + 0x00800)
#define GPIO_PORT_D_BASE		(IOPORT_BASE + 0x00c00)
#define GPIO_PORT_H_BASE		(IOPORT_BASE + 0x01C00)

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x7C)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x50)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 0x14)

/* ST provided factory calibration values @ 3.0V */
#define ST_VREFINT_CAL			MMIO16((INFO_BASE + 0x78))
#define ST_TSENSE_CAL1_30C		MMIO16((INFO_BASE + 0x7A))
#define ST_TSENSE_CAL2_110C		MMIO16((INFO_BASE + 0x7E))

#endif
