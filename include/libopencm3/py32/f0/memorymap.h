/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2026 libopencm3 project
 *
 * PY32F0xx (Puya Semiconductor, Cortex-M0+) memory map.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#ifndef LIBOPENCM3_PY32F0_MEMORYMAP_H
#define LIBOPENCM3_PY32F0_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- Bus base addresses -------------------------------------------------- */
#define FLASH_BASE			(0x08000000U)
#define SRAM_BASE			(0x20000000U)
#define PERIPH_BASE			(0x40000000U)
#define IOPORT_BASE			(0x50000000U)

#define PERIPH_BASE_APB			(PERIPH_BASE + 0x00000000U)
#define PERIPH_BASE_AHB			(PERIPH_BASE + 0x00020000U)

/* --- APB peripherals ----------------------------------------------------- */
#define TIM3_BASE			(PERIPH_BASE_APB + 0x0400U)
#define TIM14_BASE			(PERIPH_BASE_APB + 0x2000U)
#define RTC_BASE			(PERIPH_BASE_APB + 0x2800U)
#define WWDG_BASE			(PERIPH_BASE_APB + 0x2C00U)
#define IWDG_BASE			(PERIPH_BASE_APB + 0x3000U)
#define USART2_BASE			(PERIPH_BASE_APB + 0x4400U)
#define I2C1_BASE			(PERIPH_BASE_APB + 0x5400U)
#define PWR_BASE			(PERIPH_BASE_APB + 0x7000U)
#define LPTIM1_BASE			(PERIPH_BASE_APB + 0x7C00U)

#define SYSCFG_BASE			(PERIPH_BASE_APB + 0x10000U)
#define EXTI_BASE			(PERIPH_BASE_APB + 0x10400U)
#define ADC1_BASE			(PERIPH_BASE_APB + 0x12400U)
#define ADC1_COMMON_BASE		(PERIPH_BASE_APB + 0x12708U)
#define TIM1_BASE			(PERIPH_BASE_APB + 0x12C00U)
#define SPI1_BASE			(PERIPH_BASE_APB + 0x13000U)
#define USART1_BASE			(PERIPH_BASE_APB + 0x13800U)
#define TIM16_BASE			(PERIPH_BASE_APB + 0x14400U)
#define TIM17_BASE			(PERIPH_BASE_APB + 0x14800U)
#define DBGMCU_BASE			(PERIPH_BASE_APB + 0x15800U)

/* --- AHB peripherals ----------------------------------------------------- */
#define DMA1_BASE			(PERIPH_BASE_AHB + 0x0000U)
#define RCC_BASE			(PERIPH_BASE_AHB + 0x1000U)
#define FLASH_MEM_INTERFACE_BASE	(PERIPH_BASE_AHB + 0x2000U)
#define CRC_BASE			(PERIPH_BASE_AHB + 0x3000U)

/* --- IO port peripherals (private bus 0x50000000) ------------------------ */
#define GPIOA_BASE			(IOPORT_BASE + 0x00000000U)
#define GPIOB_BASE			(IOPORT_BASE + 0x00000400U)
#define GPIOF_BASE			(IOPORT_BASE + 0x00001400U)

#endif
