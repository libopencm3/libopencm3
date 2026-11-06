/*
 * This file is part of the libopencm3 project.
 *
 * PY32F0xx RCC implementation.
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#include <libopencm3/py32/rcc.h>
#include <libopencm3/cm3/common.h>

/* HSISYS default frequency after reset is 8 MHz (HSI / 1). */
uint32_t rcc_ahb_frequency = 8000000;
uint32_t rcc_apb_frequency = 8000000;

void rcc_periph_clock_enable(enum rcc_periph_clken periph)
{
	uint32_t offset = (((uint32_t)periph) >> 8) & 0xFF;
	uint32_t bit    = ((uint32_t)periph) & 0xFF;
	MMIO32(RCC_BASE + offset) |= (1U << bit);
	/* Read-back to ensure the write is committed before the next access. */
	(void)MMIO32(RCC_BASE + offset);
}

void rcc_periph_clock_disable(enum rcc_periph_clken periph)
{
	uint32_t offset = (((uint32_t)periph) >> 8) & 0xFF;
	uint32_t bit    = ((uint32_t)periph) & 0xFF;
	MMIO32(RCC_BASE + offset) &= ~(1U << bit);
}

/*
 * Switch HSISYS to a factory-calibrated HSI frequency.
 *  hsi_fs  : one of RCC_ICSCR_HSI_FS_4MHZ .. RCC_ICSCR_HSI_FS_24MHZ
 *
 * The PY32F0xx HSI requires loading both the HSI_FS field (bits 13..15)
 * AND the corresponding 13-bit factory TRIM (bits 0..12) from the
 * calibration area in system memory. The ROM does NOT load them on reset;
 * the vendor SystemInit() writes the 8MHz trim from 0x1FFF0F04. If we
 * only change HSI_FS without loading the matching trim, the HSI may not
 * oscillate at the expected frequency (or at all).
 */
void rcc_clock_setup_in_hsi_out(uint32_t hsi_fs)
{
	static const uint32_t hsi_trim_addr[8] = {
		0x1FFF0F00U, /* 4 MHz    */
		0x1FFF0F04U, /* 8 MHz    */
		0x1FFF0F08U, /* 16 MHz   */
		0x1FFF0F0CU, /* 22.12 MHz*/
		0x1FFF0F10U, /* 24 MHz   */
		0x1FFF0F04U, /* fallback */
		0x1FFF0F04U,
		0x1FFF0F04U,
	};
	static const uint32_t hsi_freq_table[8] = {
		4000000U, 8000000U, 16000000U, 22120000U,
		24000000U, 4000000U, 4000000U, 4000000U
	};

	uint32_t fs   = hsi_fs & 0x7;
	uint32_t trim = MMIO32(hsi_trim_addr[fs]) & 0x1FFF;

	/* Make sure HSI is on. */
	RCC_CR |= RCC_CR_HSION;
	while (!(RCC_CR & RCC_CR_HSIRDY)) {
		/* spin */
	}

	/* Update ICSCR low 16 bits with (HSI_FS << 13) | TRIM, preserving
	 * the upper 16 bits (LSI trim and reserved fields). */
	RCC_ICSCR = (RCC_ICSCR & 0xFFFF0000U) | (fs << 13) | trim;

	/* HSIDIV = 0 (no division) -> HSISYS = HSI. */
	RCC_CR &= ~(RCC_CR_HSIDIV_MASK << RCC_CR_HSIDIV_SHIFT);

	/* Select HSISYS as system clock. */
	uint32_t cfgr = RCC_CFGR;
	cfgr &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	cfgr |= (RCC_CFGR_SW_HSISYS << RCC_CFGR_SW_SHIFT);
	/* AHB and APB prescaler = 1. */
	cfgr &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	cfgr &= ~(RCC_CFGR_PPRE_MASK << RCC_CFGR_PPRE_SHIFT);
	RCC_CFGR = cfgr;

	/* Wait for the switch to complete. */
	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
	       != RCC_CFGR_SW_HSISYS) {
		/* spin */
	}

	rcc_ahb_frequency = hsi_freq_table[fs];
	rcc_apb_frequency = rcc_ahb_frequency;
}
