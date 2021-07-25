/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32G4xx Reset and Clock Control</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * @author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * @author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran at seznam.cz>
 * @author @htmlonly &copy; @endhtmlonly 2020 Sam Kirkham <sam.kirkham@codethink.co.uk>
 * @author @htmlonly &copy; @endhtmlonly 2020 Ben Brewer <ben.brewer@codethink.co.uk>
 *
 * @date 30 July 2020
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2013 Frantisek Burian <BuFran at seznam.cz>
 * Copyright (C) 2020 Sam Kirkham <sam.kirkham@codethink.co.uk>
 * Copyright (C) 2020 Ben Brewer <ben.brewer@codethink.co.uk>
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


#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

/**@{*/

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 16000000;
uint32_t rcc_apb1_frequency = 16000000;
uint32_t rcc_apb2_frequency = 16000000;

const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_3V3_END] = {
	{ /* 24MHz */
		.pllm = 2,
		.plln = 12,
		.pllp = 0,
		.pllq = 2,
		.pllr = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE2,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 24e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 24e6,
	},
	{ /* 48MHz */
		.pllm = 2,
		.plln = 12,
		.pllp = 0,
		.pllq = 2,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 48e6,
		.apb1_frequency = 48e6,
		.apb2_frequency = 48e6,
	},
	{ /* 96MHz */
		.pllm = 2,
		.plln = 24,
		.pllp = 0,
		.pllq = 4,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 3,
		.ahb_frequency  = 96e6,
		.apb1_frequency = 96e6,
		.apb2_frequency = 96e6,
	},
	{ /* 170MHz */
		.pllm = 4,
		.plln = 85,
		.pllp = 0,
		.pllq = 0, /* USB requires CRS at this speed. */
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = true,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 4,
		.ahb_frequency  = 170e6,
		.apb1_frequency = 170e6,
		.apb2_frequency = 170e6,
	},
};

const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END] = {
	{ /* 24MHz */
		.pllm = 1,
		.plln = 12,
		.pllp = 0,
		.pllq = 2,
		.pllr = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE2,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 24e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 24e6,
	},
	{ /* 48MHz */
		.pllm = 1,
		.plln = 12,
		.pllp = 0,
		.pllq = 2,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 48e6,
		.apb1_frequency = 48e6,
		.apb2_frequency = 48e6,
	},
	{ /* 96MHz */
		.pllm = 1,
		.plln = 24,
		.pllp = 0,
		.pllq = 4,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 3,
		.ahb_frequency  = 96e6,
		.apb1_frequency = 96e6,
		.apb2_frequency = 96e6,
	},
	{ /* 170MHz */
		.pllm = 2,
		.plln = 85,
		.pllp = 0,
		.pllq = 0, /* USB requires CRS at this speed. */
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = true,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 4,
		.ahb_frequency  = 170e6,
		.apb1_frequency = 170e6,
		.apb2_frequency = 170e6,
	},
};


const struct rcc_clock_scale rcc_hse_12mhz_3v3[RCC_CLOCK_3V3_END] = {
	{ /* 24MHz */
		.pllm = 2,
		.plln = 16,
		.pllp = 0,
		.pllq = 2,
		.pllr = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE2,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 24e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 24e6,
	},
	{ /* 48MHz */
		.pllm = 2,
		.plln = 16,
		.pllp = 0,
		.pllq = 2,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 48e6,
		.apb1_frequency = 48e6,
		.apb2_frequency = 48e6,
	},
	{ /* 96MHz */
		.pllm = 2,
		.plln = 32,
		.pllp = 0,
		.pllq = 4,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 3,
		.ahb_frequency  = 96e6,
		.apb1_frequency = 96e6,
		.apb2_frequency = 96e6,
	},
	{ /* 170MHz */
		.pllm = 3,
		.plln = 85,
		.pllp = 0,
		.pllq = 0, /* USB requires CRS at this speed. */
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = true,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 4,
		.ahb_frequency  = 170e6,
		.apb1_frequency = 170e6,
		.apb2_frequency = 170e6,
	},
};

const struct rcc_clock_scale rcc_hse_16mhz_3v3[RCC_CLOCK_3V3_END] = {
	{ /* 24MHz */
		.pllm = 2,
		.plln = 12,
		.pllp = 0,
		.pllq = 2,
		.pllr = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE2,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 24e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 24e6,
	},
	{ /* 48MHz */
		.pllm = 2,
		.plln = 12,
		.pllp = 0,
		.pllq = 2,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 1,
		.ahb_frequency  = 48e6,
		.apb1_frequency = 48e6,
		.apb2_frequency = 48e6,
	},
	{ /* 96MHz */
		.pllm = 2,
		.plln = 24,
		.pllp = 0,
		.pllq = 4,
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = false,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 3,
		.ahb_frequency  = 96e6,
		.apb1_frequency = 96e6,
		.apb2_frequency = 96e6,
	},
	{ /* 170MHz */
		.pllm = 4,
		.plln = 85,
		.pllp = 0,
		.pllq = 0, /* USB requires CRS at this speed. */
		.pllr = 2,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPREx_NODIV,
		.ppre2 = RCC_CFGR_PPREx_NODIV,
		.vos_scale = PWR_SCALE1,
		.boost = true,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN,
		.flash_waitstates = 4,
		.ahb_frequency  = 170e6,
		.apb1_frequency = 170e6,
		.apb2_frequency = 170e6,
	},
};



void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CICR |= RCC_CICR_HSI48RDYC;
		break;
	case RCC_PLL:
		RCC_CICR |= RCC_CICR_PLLRDYC;
		break;
	case RCC_HSE:
		RCC_CICR |= RCC_CICR_HSERDYC;
		break;
	case RCC_HSI16:
		RCC_CICR |= RCC_CICR_HSIRDYC;
		break;
	case RCC_LSE:
		RCC_CICR |= RCC_CICR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CICR |= RCC_CICR_LSIRDYC;
		break;
	}
}

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CIER |= RCC_CIER_HSI48RDYIE;
		break;
	case RCC_PLL:
		RCC_CIER |= RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER |= RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER |= RCC_CIER_HSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIER |= RCC_CIER_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIER |= RCC_CIER_LSIRDYIE;
		break;
	}
}

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CIER &= ~RCC_CIER_HSI48RDYIE;
		break;
	case RCC_PLL:
		RCC_CIER &= ~RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER &= ~RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER &= ~RCC_CIER_HSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIER &= ~RCC_CIER_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIER &= ~RCC_CIER_LSIRDYIE;
		break;
	}
}

int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		return ((RCC_CIFR & RCC_CIFR_HSI48RDYF) != 0);
	case RCC_PLL:
		return ((RCC_CIFR & RCC_CIFR_PLLRDYF) != 0);
	case RCC_HSE:
		return ((RCC_CIFR & RCC_CIFR_HSERDYF) != 0);
	case RCC_HSI16:
		return ((RCC_CIFR & RCC_CIFR_HSIRDYF) != 0);
	case RCC_LSE:
		return ((RCC_CIFR & RCC_CIFR_LSERDYF) != 0);
	case RCC_LSI:
		return ((RCC_CIFR & RCC_CIFR_LSIRDYF) != 0);
	}
	return 0;
}

void rcc_css_int_clear(void)
{
	RCC_CICR |= RCC_CICR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIFR & RCC_CIFR_CSSF) != 0);
}

bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		return RCC_CRRCR & RCC_CRRCR_HSI48RDY;
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI16:
		return RCC_CR & RCC_CR_HSIRDY;
	case RCC_LSE:
		return RCC_BDCR & RCC_BDCR_LSERDY;
	case RCC_LSI:
		return RCC_CSR & RCC_CSR_LSIRDY;
	}
	return false;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc));
}

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWx_PLL);
		break;
	case RCC_HSE:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWx_HSE);
		break;
	case RCC_HSI16:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWx_HSI16);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CRRCR |= RCC_CRRCR_HSI48ON;
		break;
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI16:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CRRCR &= ~RCC_CRRCR_HSI48ON;
		break;
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI16:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	}
}

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	RCC_CFGR = (reg32 | (clk << RCC_CFGR_SW_SHIFT));
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(RCC_PLLCFGR_PLLSRC_MASK << RCC_PLLCFGR_PLLSRC_SHIFT);
	RCC_PLLCFGR = (reg32 | (pllsrc << RCC_PLLCFGR_PLLSRC_SHIFT));
}

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_SHIFT);
	RCC_CFGR = (reg32 | (ppre2 << RCC_CFGR_PPRE2_SHIFT));
}

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_SHIFT);
	RCC_CFGR = (reg32 | (ppre1 << RCC_CFGR_PPRE1_SHIFT));
}

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
}

/**
 * Reconfigures the main PLL for a HSE source.
 * Any reserved bits are kept at their reset values.
 * @param pllsrc Source for the main PLL input clock
 * @param pllm Divider for the main PLL input clock
 * @param plln Main PLL multiplication factor for VCO
 * @param pllp Main PLL divider for ADC
 * @param pllq Main PLL divider for QUADSPI, FDCAN, USB, SAI & I2S
 * @param pllr Main PLL divider for main system clock
 */
void rcc_set_main_pll(uint32_t pllsrc, uint32_t pllm, uint32_t plln,
		      uint32_t pllp, uint32_t pllq, uint32_t pllr)
{
	bool pllpen = (pllp != 0);
	bool pllqen = (pllq != 0);
	bool pllren = (pllr != 0);

	pllm -= 1;

	uint32_t pllpdiv = pllp;
	pllp = (pllpdiv == 17);
	if ((pllpdiv == 7) || (pllpdiv ==  17)) {
		pllpdiv = 0;
	}

	pllr = (pllr >> 1) - 1;
	pllq = (pllq >> 1) - 1;

	RCC_PLLCFGR = ((pllsrc & RCC_PLLCFGR_PLLSRC_MASK) << RCC_PLLCFGR_PLLSRC_SHIFT) |
		((pllm & RCC_PLLCFGR_PLLM_MASK) << RCC_PLLCFGR_PLLM_SHIFT) |
		((plln & RCC_PLLCFGR_PLLN_MASK) << RCC_PLLCFGR_PLLN_SHIFT) |
		(pllpen ? RCC_PLLCFGR_PLLPEN : 0 ) |
		(pllp ? RCC_PLLCFGR_PLLP_DIV17 : RCC_PLLCFGR_PLLP_DIV7) |
		(pllqen ? RCC_PLLCFGR_PLLQEN : 0 ) |
		((pllq & RCC_PLLCFGR_PLLQ_MASK) << RCC_PLLCFGR_PLLQ_SHIFT) |
		(pllren ? RCC_PLLCFGR_PLLREN : 0 ) |
		((pllr & RCC_PLLCFGR_PLLR_MASK) << RCC_PLLCFGR_PLLR_SHIFT) |
		((pllpdiv & RCC_PLLCFGR_PLLPDIV_MASK) << RCC_PLLCFGR_PLLPDIV_SHIFT);
}

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK;
}

/**
 * Setup clocks to run from PLL.
 *
 * The arguments provide the pll source, multipliers, dividers, all that's
 * needed to establish a system clock.
 *
 * @param clock clock information structure.
 */
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	/* Enable internal high-speed oscillator (HSI16). */
	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);

	/* Select HSI16 as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SWx_HSI16);

	/* Enable external high-speed oscillator (HSE). */
	if (clock->pll_source == RCC_PLLCFGR_PLLSRC_HSE) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	}

	/* Set the VOS scale mode */
	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->vos_scale);

	if (clock->boost) {
		pwr_enable_boost();
	} else {
		pwr_disable_boost();
	}

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	/* Disable PLL oscillator before changing its configuration. */
	rcc_osc_off(RCC_PLL);

	/* Configure the PLL oscillator. */
	rcc_set_main_pll(clock->pll_source,
			clock->pllm, clock->plln,
			clock->pllp, clock->pllq, clock->pllr);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash settings. */
	if (clock->flash_config & FLASH_ACR_DCEN) {
		flash_dcache_enable();
	} else {
		flash_dcache_disable();
	}
	if (clock->flash_config & FLASH_ACR_ICEN) {
		flash_icache_enable();
	} else {
		flash_icache_disable();
	}
	flash_set_ws(clock->flash_waitstates);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SWx_PLL);

	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;

	/* Disable internal high-speed oscillator. */
	if (clock->pll_source == RCC_PLLCFGR_PLLSRC_HSE) {
		rcc_osc_off(RCC_HSI16);
	}
}

/**
 * Setup clocks with the HSE.
 *
 * @deprecated replaced by rcc_clock_setup_pll as a drop in replacement.
 * @see rcc_clock_setup_pll which supports HSI16 as well as HSE, using the same
 * clock structures.
 */
void rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock)
{
	rcc_clock_setup_pll(clock);
}

/** Set clock source for 48MHz clock
 *
 * The 48 MHz clock is derived from one of the four following sources:
 *	- PLLQ VCO (RCC_CCIPR_CLK48_PLLQ)
 *	- HSI48 internal oscillator (RCC_CCIPR_CLK48_HSI48)
 *
 * @param clksel One of the definitions above
 */
void rcc_set_clock48_source(uint32_t clksel)
{
	RCC_CCIPR &= ~(RCC_CCIPR_SEL_MASK << RCC_CCIPR_CLK48_SHIFT);
	RCC_CCIPR |= (clksel << RCC_CCIPR_CLK48_SHIFT);
}

/**@}*/
