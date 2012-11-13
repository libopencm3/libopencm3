/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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
 * Based on the F4 code...
 */

#include <libopencm3/stm32/l1/rcc.h>

/* Set the default ppre1 and ppre2 peripheral clock frequencies after reset. */
u32 rcc_ppre1_frequency = 2097000;
u32 rcc_ppre2_frequency = 2097000;

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
	case MSI:
		RCC_CIR |= RCC_CIR_MSIRDYC;
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
	case MSI:
		RCC_CIR |= RCC_CIR_MSIRDYIE;
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
	case MSI:
		RCC_CIR &= ~RCC_CIR_MSIRDYIE;
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
	case MSI:
		return ((RCC_CIR & RCC_CIR_MSIRDYF) != 0);
		break;
	}

	/* Shouldn't be reached. */
	return -1;
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
	case MSI:
		while ((RCC_CR & RCC_CR_MSIRDY) == 0);
		break;
	case LSE:
		while ((RCC_CSR & RCC_CSR_LSERDY) == 0);
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
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_SYSCLKSEL_PLLCLK);
		break;
	case HSE:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_SYSCLKSEL_HSECLK);
		break;
	case HSI:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_SYSCLKSEL_HSICLK);
		break;
	case MSI:
		while ((RCC_CFGR & ((1 << 1) | (1 << 0))) != RCC_CFGR_SWS_SYSCLKSEL_MSICLK);
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
	case MSI:
		RCC_CR |= RCC_CR_MSION;
		break;
	case HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case LSE:
		RCC_CSR |= RCC_CSR_LSEON;
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
	case MSI:
		RCC_CR &= ~RCC_CR_MSION;
		break;
	case HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case LSE:
		RCC_CSR &= ~RCC_CSR_LSEON;
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
		RCC_CSR |= RCC_CSR_LSEBYP;
		break;
	case PLL:
	case HSI:
	case LSI:
	case MSI:
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
		RCC_CSR &= ~RCC_CSR_LSEBYP;
		break;
	case PLL:
	case HSI:
	case LSI:
	case MSI:
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

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 16);
	RCC_CFGR = (reg32 | (pllsrc << 16));
}

void rcc_set_ppre2(u32 ppre2)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 13) | (1 << 12) | (1 << 11));
	RCC_CFGR = (reg32 | (ppre2 << 11));
}

void rcc_set_ppre1(u32 ppre1)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 10) | (1 << 9) | (1 << 8));
	RCC_CFGR = (reg32 | (ppre1 << 8));
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

	reg32 = RCC_CR;
	reg32 &= ~((1 << 30) | (1 << 29));
	RCC_CR = (reg32 | (rtcpre << 29));
}

u32 rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return ((RCC_CFGR & 0x000c) >> 2);
}

