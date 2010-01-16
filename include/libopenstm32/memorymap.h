/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_MEMORYMAP_H
#define LIBOPENSTM32_MEMORYMAP_H

/* --- ARM Cortex-M3 specific definitions ---------------------------------- */

/* Private peripheral bus - Internal */
#define PPBI_BASE                       0xE0000000
#define ITM_BASE                        (PPBI_BASE + 0x0000)
#define DWT_BASE                        (PPBI_BASE + 0x1000)
#define FPB_BASE                        (PPBI_BASE + 0x2000)
/* PPBI_BASE + 0x3000 (0xE000 3000 - 0xE000 DFFF): Reserved */
#define SCS_BASE                        (PPBI_BASE + 0xE000)
/* PPBI_BASE + 0xF000 (0xE000 F000 - 0xE003 FFFF): Reserved */

/* --- ITM: Instrumentation Trace Macrocell --- */
/* TODO */

/* --- DWT: Data Watchpoint and Trace unit --- */
/* TODO */

/* --- FPB: Flash Patch and Breakpoint unit --- */
/* TODO */

/* --- SCS: System Control Space --- */

/* ITR: Interrupt Type Register */
#define ITR_BASE                        (SCS_BASE + 0x0000)
/* SYS_TICK: System Timer */
#define SYS_TICK_BASE                   (SCS_BASE + 0x0010)
/* NVIC: Nested Vector Interrupt Controller */
#define NVIC_BASE                       (SCS_BASE + 0x0100)
/* SCB: System Control Block */
#define SCB_BASE                        (SCS_BASE + 0x0D00)
/* STE: Software Trigger Interrupt Register */
#define STIR_BASE                       (SCS_BASE + 0x0F00)
/* ID: ID space */
#define ID_BASE                         (SCS_BASE + 0x0FD0)

/* --- STM32 specific peripheral definitions ------------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE			0x40000000
#define PERIPH_BASE_APB1		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2		(PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB			(PERIPH_BASE + 0x18000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE			(PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE			(PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE			(PERIPH_BASE_APB1 + 0x0800)
#define TIM5_BASE			(PERIPH_BASE_APB1 + 0x0c00)
#define TIM6_BASE			(PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE			(PERIPH_BASE_APB1 + 0x1400)
/* PERIPH_BASE_APB1 + 0x1800 (0x4000 1800 - 0x4000 27FF): Reserved */
#define RTC_BASE			(PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE			(PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE			(PERIPH_BASE_APB1 + 0x3000)
/* PERIPH_BASE_APB1 + 0x3400 (0x4000 3400 - 0x4000 37FF): Reserved */
#define SPI2_I2S_BASE			(PERIPH_BASE_APB1 + 0x3800)
#define SPI3_I2S_BASE			(PERIPH_BASE_APB1 + 0x3c00)
/* PERIPH_BASE_APB1 + 0x4000 (0x4000 4000 - 0x4000 3FFF): Reserved */
#define USART2_BASE			(PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE			(PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE			(PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE			(PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE			(PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE			(PERIPH_BASE_APB1 + 0x5800)
#define USB_DEV_FS_BASE			(PERIPH_BASE_APB1 + 0x5c00)
#define USB_CAN_SRAM_BASE		(PERIPH_BASE_APB1 + 0x6000)
#define BX_CAN1_BASE			(PERIPH_BASE_APB1 + 0x6400)
#define BX_CAN2_BASE			(PERIPH_BASE_APB1 + 0x6800)
/* PERIPH_BASE_APB1 + 0x6800 (0x4000 6800 - 0x4000 6BFF): Reserved? Typo? */
#define BACKUP_REGS_BASE		(PERIPH_BASE_APB1 + 0x6c00)
#define POWER_CONTROL_BASE		(PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE			(PERIPH_BASE_APB1 + 0x7400)
/* PERIPH_BASE_APB1 + 0x7800 (0x4000 7800 - 0x4000 FFFF): Reserved */

/* APB2 */
#define AFIO_BASE			(PERIPH_BASE_APB2 + 0x0000)
#define EXTI_BASE			(PERIPH_BASE_APB2 + 0x0400)
#define GPIO_PORT_A_BASE		(PERIPH_BASE_APB2 + 0x0800)
#define GPIO_PORT_B_BASE		(PERIPH_BASE_APB2 + 0x0c00)
#define GPIO_PORT_C_BASE		(PERIPH_BASE_APB2 + 0x1000)
#define GPIO_PORT_D_BASE		(PERIPH_BASE_APB2 + 0x1400)
#define GPIO_PORT_E_BASE		(PERIPH_BASE_APB2 + 0x1800)
#define GPIO_PORT_F_BASE		(PERIPH_BASE_APB2 + 0x1c00)
#define GPIO_PORT_G_BASE		(PERIPH_BASE_APB2 + 0x2000)
#define ADC1_BASE			(PERIPH_BASE_APB2 + 0x2400)
#define ADC2_BASE			(PERIPH_BASE_APB2 + 0x2800)
#define TIM1_BASE			(PERIPH_BASE_APB2 + 0x2c00)
#define SPI1_BASE			(PERIPH_BASE_APB2 + 0x3000)
#define TIM8_BASE			(PERIPH_BASE_APB2 + 0x3400)
#define USART1_BASE			(PERIPH_BASE_APB2 + 0x3800)
#define ADC3_BASE			(PERIPH_BASE_APB2 + 0x3c00)
/* PERIPH_BASE_APB2 + 0x4000 (0x4001 4000 - 0x4001 7FFF): Reserved */

/* AHB */
#define SDIO_BASE			(PERIPH_BASE_AHB + 0x00000)
/* PERIPH_BASE_AHB + 0x0400 (0x4001 8400 - 0x4001 7FFF): Reserved */
#define DMA1_BASE			(PERIPH_BASE_AHB + 0x08000)
#define DMA2_BASE			(PERIPH_BASE_AHB + 0x08400)
/* PERIPH_BASE_AHB + 0x8800 (0x4002 0800 - 0x4002 0FFF): Reserved */
#define RCC_BASE			(PERIPH_BASE_AHB + 0x09000)
/* PERIPH_BASE_AHB + 0x9400 (0x4002 1400 - 0x4002 1FFF): Reserved */
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB + 0x0a000)
#define CRC_BASE			(PERIPH_BASE_AHB + 0x0b000)
/* PERIPH_BASE_AHB + 0xb400 (0x4002 3400 - 0x4002 7FFF): Reserved */
#define ETHERNET_BASE			(PERIPH_BASE_AHB + 0x10000)
/* PERIPH_BASE_AHB + 0x18000 (0x4003 0000 - 0x4FFF FFFF): Reserved */
#define USB_OTG_FS_BASE			(PERIPH_BASE_AHB + 0x10000000)

#endif
