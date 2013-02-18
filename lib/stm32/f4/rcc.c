/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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
#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/f4/pwr.h>
#include <libopencm3/stm32/f4/flash.h>

/* Set the default ppre1 and ppre2 peripheral clock frequencies after reset. */
u32 rcc_ppre1_frequency = 16000000;
u32 rcc_ppre2_frequency = 16000000;

const clock_scale_t hse_8mhz_3v3[CLOCK_3V3_END] =
{
	{ /* 120MHz */
		.pllm = 8,
		.plln = 240,
		.pllp = 2,
		.pllq = 5,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.power_save = 1,
		.flash_config = FLASH_ACR_ICE | FLASH_ACR_DCE | FLASH_ACR_LATENCY_3WS,
		.apb1_frequency = 30000000,
		.apb2_frequency = 60000000,
	},
	{ /* 168MHz */
		.pllm = 8,
		.plln = 336,
		.pllp = 2,
		.pllq = 7,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.flash_config = FLASH_ACR_ICE | FLASH_ACR_DCE | FLASH_ACR_LATENCY_5WS,
		.apb1_frequency = 42000000,
		.apb2_frequency = 84000000,
	},
};

void rcc_osc_ready_int_clear(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
		break;
	case HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
		break;
	case LSE:
		RCC_CIR |= RCC_CIR_LSERDYC;
		break;
	case LSI:
		RCC_CIR |= RCC_CIR_LSIRDYC;
		break;
	}
}

void rcc_osc_ready_int_enable(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
		break;
	case HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
		break;
	case LSE:
		RCC_CIR |= RCC_CIR_LSERDYIE;
		break;
	case LSI:
		RCC_CIR |= RCC_CIR_LSIRDYIE;
		break;
	}
}

void rcc_osc_ready_int_disable(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYIE;
		break;
	case HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYIE;
		break;
	case HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYIE;
		break;
	case LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYIE;
		break;
	case LSI:
		RCC_CIR &= ~RCC_CIR_LSIRDYIE;
		break;
	}
}

int rcc_osc_ready_int_flag(osc_t osc)
{
	switch (osc) {
	case PLL:
		return ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
		break;
	case HSE:
		return ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case HSI:
		return ((RCC_CIR & RCC_CIR_HSIRDYF) != 0);
		break;
	case LSE:
		return ((RCC_CIR & RCC_CIR_LSERDYF) != 0);
		break;
	case LSI:
		return ((RCC_CIR & RCC_CIR_LSIRDYF) != 0);
		break;
	}

	cm3_assert_not_reached();
}

void rcc_css_int_clear(void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & RCC_CIR_CSSF) != 0);
}

void rcc_wait_for_osc_ready(osc_t osc)
{
	switch (osc) {
	case PLL:
		while ((RCC_CR & RCC_CR_PLLRDY) == 0);
		break;
	case HSE:
		while ((RCC_CR & RCC_CR_HSERDY) == 0);
		break;
	case HSI:
		while ((RCC_CR & RCC_CR_HSIRDY) == 0);
		break;
	case LSE:
		while ((RCC_BDCR & RCC_BDCR_LSERDY) == 0);
		break;
	case LSI:
		while ((RCC_CSR & RCC_CSR_LSIRDY) == 0);
		break;
	}
}

void rcc_wait_for_sysclk_status(osc_t osc)
{
	switch (osc) {
	case PLL:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_PLL);
		break;
	case HSE:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_HSE);
		break;
	case HSI:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_HSI);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

void rcc_osc_off(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case LSI:
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

void rcc_osc_bypass_enable(osc_t osc)
{
	switch (osc) {
	case HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEBYP;
		break;
	case PLL:
	case HSI:
	case LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_osc_bypass_disable(osc_t osc)
{
	switch (osc) {
	case HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEBYP;
		break;
	case PLL:
	case HSI:
	case LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_peripheral_enable_clock(volatile u32 *reg, u32 en)
{
	*reg |= en;
}

void rcc_peripheral_disable_clock(volatile u32 *reg, u32 en)
{
	*reg &= ~en;
}

void rcc_peripheral_reset(volatile u32 *reg, u32 reset)
{
	*reg |= reset;
}

void rcc_peripheral_clear_reset(volatile u32 *reg, u32 clear_reset)
{
	*reg &= ~clear_reset;
}

void rcc_set_sysclk_source(u32 clk)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC_CFGR = (reg32 | clk);
}

void rcc_set_pll_source(u32 pllsrc)
{
	u32 reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(1 << 22);
	RCC_PLLCFGR = (reg32 | (pllsrc << 22));
}

void rcc_set_ppre2(u32 ppre2)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 13) | (1 << 14) | (1 << 15));
	RCC_CFGR = (reg32 | (ppre2 << 13));
}

void rcc_set_ppre1(u32 ppre1)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 10) | (1 << 11) | (1 << 12));
	RCC_CFGR = (reg32 | (ppre1 << 10));
}

void rcc_set_hpre(u32 hpre)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
	RCC_CFGR = (reg32 | (hpre << 4));
}

void rcc_set_rtcpre(u32 rtcpre)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20));
	RCC_CFGR = (reg32 | (rtcpre << 16));
}

void rcc_set_main_pll_hsi(u32 pllm, u32 plln, u32 pllp, u32 pllq)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(((pllp >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT) |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT);
}

void rcc_set_main_pll_hse(u32 pllm, u32 plln, u32 pllp, u32 pllq)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(((pllp >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT) |
		RCC_PLLCFGR_PLLSRC |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT);
}

u32 rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return ((RCC_CFGR & 0x000c) >> 2);
}

void rcc_clock_setup_hse_3v3(const clock_scale_t *clock)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI);

	/* Enable external high-speed oscillator 8MHz. */
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);

	/* Enable/disable high performance mode */
	if (!clock->power_save)
		pwr_set_vos_scale(SCALE1);
	else
		pwr_set_vos_scale(SCALE2);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_main_pll_hse(clock->pllm, clock->plln,
			     clock->pllp, clock->pllq);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Configure flash settings. */
	flash_set_ws(clock->flash_config);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);

	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_ppre1_frequency = clock->apb1_frequency;
	rcc_ppre2_frequency = clock->apb2_frequency;
}

void rcc_backupdomain_reset(void)
{
	/* Set the backup domain software reset. */
	RCC_BDCR |= RCC_BDCR_BDRST;

	/* Clear the backup domain software reset. */
	RCC_BDCR &= ~RCC_BDCR_BDRST;
}
