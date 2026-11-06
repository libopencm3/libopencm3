/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2026 libopencm3 project
 *
 * PY32F0xx RCC (Reset and Clock Control) definitions.
 *
 * The PY32F0xx RCC layout differs from the STM32F0 RCC. Notably, the F0xx
 * uses a separate IOPENR register at offset 0x34 (like STM32G0/L0/L4) and
 * splits APB peripherals between APBENR1 and APBENR2.
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#ifndef LIBOPENCM3_PY32F0_RCC_H
#define LIBOPENCM3_PY32F0_RCC_H

#include <libopencm3/py32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- RCC registers ------------------------------------------------------ */
#define RCC_CR				MMIO32(RCC_BASE + 0x00)
#define RCC_ICSCR			MMIO32(RCC_BASE + 0x04)
#define RCC_CFGR			MMIO32(RCC_BASE + 0x08)
#define RCC_ECSCR			MMIO32(RCC_BASE + 0x10)
#define RCC_CIER			MMIO32(RCC_BASE + 0x18)
#define RCC_CIFR			MMIO32(RCC_BASE + 0x1C)
#define RCC_CICR			MMIO32(RCC_BASE + 0x20)
#define RCC_IOPRSTR			MMIO32(RCC_BASE + 0x24)
#define RCC_AHBRSTR			MMIO32(RCC_BASE + 0x28)
#define RCC_APBRSTR1			MMIO32(RCC_BASE + 0x2C)
#define RCC_APBRSTR2			MMIO32(RCC_BASE + 0x30)
#define RCC_IOPENR			MMIO32(RCC_BASE + 0x34)
#define RCC_AHBENR			MMIO32(RCC_BASE + 0x38)
#define RCC_APBENR1			MMIO32(RCC_BASE + 0x3C)
#define RCC_APBENR2			MMIO32(RCC_BASE + 0x40)
#define RCC_CCIPR			MMIO32(RCC_BASE + 0x54)
#define RCC_BDCR			MMIO32(RCC_BASE + 0x5C)
#define RCC_CSR				MMIO32(RCC_BASE + 0x60)

/* --- RCC_CR --------------------------------------------------------------*/
#define RCC_CR_HSION			(1 << 8)
#define RCC_CR_HSIRDY			(1 << 10)
#define RCC_CR_HSIDIV_SHIFT		11
#define RCC_CR_HSIDIV_MASK		0x7
#define RCC_CR_HSEON			(1 << 16)
#define RCC_CR_HSERDY			(1 << 17)
#define RCC_CR_HSEBYP			(1 << 18)
#define RCC_CR_CSSON			(1 << 19)

/* --- RCC_ICSCR (HSI factory frequency selection) ------------------------ */
#define RCC_ICSCR_HSI_FS_SHIFT		13
#define RCC_ICSCR_HSI_FS_MASK		0x7
#define RCC_ICSCR_HSI_FS_4MHZ		0
#define RCC_ICSCR_HSI_FS_8MHZ		1
#define RCC_ICSCR_HSI_FS_16MHZ		2
#define RCC_ICSCR_HSI_FS_22_12MHZ	3
#define RCC_ICSCR_HSI_FS_24MHZ		4

/* --- RCC_CFGR ----------------------------------------------------------- */
#define RCC_CFGR_SW_SHIFT		0
#define RCC_CFGR_SW_MASK		0x7
#define RCC_CFGR_SW_HSISYS		0
#define RCC_CFGR_SW_HSE			1
#define RCC_CFGR_SW_LSI			3
#define RCC_CFGR_SW_LSE			4
#define RCC_CFGR_SWS_SHIFT		3
#define RCC_CFGR_SWS_MASK		0x7
#define RCC_CFGR_HPRE_SHIFT		8
#define RCC_CFGR_HPRE_MASK		0xF
#define RCC_CFGR_PPRE_SHIFT		12
#define RCC_CFGR_PPRE_MASK		0x7
#define RCC_CFGR_MCOSEL_SHIFT		24
#define RCC_CFGR_MCOSEL_MASK		0xF
#define RCC_CFGR_MCOPRE_SHIFT		28
#define RCC_CFGR_MCOPRE_MASK		0x7

/* --- RCC_IOPENR (IO port clock enable) --------------------------------- */
#define RCC_IOPENR_IOPAEN		(1 << 0)
#define RCC_IOPENR_IOPBEN		(1 << 1)
#define RCC_IOPENR_IOPFEN		(1 << 5)

/* --- RCC_AHBENR --------------------------------------------------------- */
#define RCC_AHBENR_DMAEN		(1 << 0)
#define RCC_AHBENR_FLASHEN		(1 << 8)
#define RCC_AHBENR_SRAMEN		(1 << 9)
#define RCC_AHBENR_CRCEN		(1 << 12)

/* --- RCC_APBENR1 -------------------------------------------------------- */
#define RCC_APBENR1_TIM3EN		(1 << 1)
#define RCC_APBENR1_RTCAPBEN		(1 << 10)
#define RCC_APBENR1_WWDGEN		(1 << 11)
#define RCC_APBENR1_USART2EN		(1 << 17)
#define RCC_APBENR1_I2C1EN		(1 << 21)
#define RCC_APBENR1_DBGEN		(1 << 27)
#define RCC_APBENR1_PWREN		(1 << 28)
#define RCC_APBENR1_LPTIM1EN		(1 << 31)

/* --- RCC_APBENR2 -------------------------------------------------------- */
#define RCC_APBENR2_SYSCFGEN		(1 << 0)
#define RCC_APBENR2_TIM1EN		(1 << 11)
#define RCC_APBENR2_SPI1EN		(1 << 12)
#define RCC_APBENR2_USART1EN		(1 << 14)
#define RCC_APBENR2_TIM14EN		(1 << 15)
#define RCC_APBENR2_TIM16EN		(1 << 17)
#define RCC_APBENR2_TIM17EN		(1 << 18)
#define RCC_APBENR2_ADCEN		(1 << 20)
#define RCC_APBENR2_COMP1EN		(1 << 21)
#define RCC_APBENR2_COMP2EN		(1 << 22)

/* --- Peripheral clock enum (encoded as (reg_offset<<8) | bit_index) ---- */
enum rcc_periph_clken {
	/* IOPENR (offset 0x34) */
	RCC_GPIOA	= (0x34 << 8) | 0,
	RCC_GPIOB	= (0x34 << 8) | 1,
	RCC_GPIOF	= (0x34 << 8) | 5,
	/* AHBENR (offset 0x38) */
	RCC_DMA1	= (0x38 << 8) | 0,
	RCC_FLASH	= (0x38 << 8) | 8,
	RCC_SRAM	= (0x38 << 8) | 9,
	RCC_CRC		= (0x38 << 8) | 12,
	/* APBENR1 (offset 0x3C) */
	RCC_TIM3	= (0x3C << 8) | 1,
	RCC_RTCAPB	= (0x3C << 8) | 10,
	RCC_WWDG	= (0x3C << 8) | 11,
	RCC_USART2	= (0x3C << 8) | 17,
	RCC_I2C1	= (0x3C << 8) | 21,
	RCC_DBG		= (0x3C << 8) | 27,
	RCC_PWR		= (0x3C << 8) | 28,
	RCC_LPTIM1	= (0x3C << 8) | 31,
	/* APBENR2 (offset 0x40) */
	RCC_SYSCFG	= (0x40 << 8) | 0,
	RCC_TIM1	= (0x40 << 8) | 11,
	RCC_SPI1	= (0x40 << 8) | 12,
	RCC_USART1	= (0x40 << 8) | 14,
	RCC_TIM14	= (0x40 << 8) | 15,
	RCC_TIM16	= (0x40 << 8) | 17,
	RCC_TIM17	= (0x40 << 8) | 18,
	RCC_ADC1	= (0x40 << 8) | 20,
	RCC_COMP1	= (0x40 << 8) | 21,
	RCC_COMP2	= (0x40 << 8) | 22,
};

BEGIN_DECLS

extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb_frequency;

void rcc_periph_clock_enable(enum rcc_periph_clken periph);
void rcc_periph_clock_disable(enum rcc_periph_clken periph);

/* Switch HSISYS to the selected factory-calibrated HSI frequency
 * (one of RCC_ICSCR_HSI_FS_*). Updates rcc_ahb_frequency. */
void rcc_clock_setup_in_hsi_out(uint32_t hsi_fs);

END_DECLS

#endif
