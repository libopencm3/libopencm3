/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
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

#include <libopenstm32.h>

void rcc_osc_ready_int_clear(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= PLLRDYC;
		break;
	case HSE:
		RCC_CR |= HSERDYC;
		break;
	case HSI:
		RCC_CR |= HSIRDYC;
		break;
	case LSE:
		RCC_CIR |= LSERDYC;
		break;
	case LSI:
		RCC_CIR |= LSIRDYC;
		break;
	}
}

void rcc_osc_ready_int_enable(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= PLLRDYIE;
		break;
	case HSE:
		RCC_CR |= HSERDYIE;
		break;
	case HSI:
		RCC_CR |= HSIRDYIE;
		break;
	case LSE:
		RCC_CIR |= LSERDYIE;
		break;
	case LSI:
		RCC_CIR |= LSIRDYIE;
		break;
	}
}

void rcc_osc_ready_int_disable(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR &= ~PLLRDYIE;
		break;
	case HSE:
		RCC_CR &= ~HSERDYIE;
		break;
	case HSI:
		RCC_CR &= ~HSIRDYIE;
		break;
	case LSE:
		RCC_CIR &= ~LSERDYIE;
		break;
	case LSI:
		RCC_CIR &= ~LSIRDYIE;
		break;
	}
}

int rcc_osc_ready_int_flag(osc_t osc)
{
	switch (osc) {
	case PLL:
		return ((RCC_CR & PLLRDYF) != 0);
		break;
	case HSE:
		return ((RCC_CR & HSERDYF) != 0);
		break;
	case HSI:
		return ((RCC_CR & HSIRDYF) != 0);
		break;
	case LSE:
		return ((RCC_CIR & LSERDYF) != 0);
		break;
	case LSI:
		return ((RCC_CIR & LSIRDYF) != 0);
		break;
	}

	/* Shouldn't be reached. */
	return -1;
}

void rcc_css_int_clear(void)
{
	RCC_CIR |= CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & CSSF) != 0);
}

void rcc_wait_for_osc_ready(osc_t osc)
{
	switch (osc) {
	case PLL:
		while ((RCC_CR & PLLRDY) == 0);
		break;
	case HSE:
		while ((RCC_CR & HSERDY) == 0);
		break;
	case HSI:
		while ((RCC_CR & HSIRDY) == 0);
		break;
	case LSE:
		while ((RCC_BDCR & LSERDY) == 0);
		break;
	case LSI:
		while ((RCC_CSR & LSIRDY) == 0);
		break;
	}
}

void rcc_osc_on(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= PLLON;
		break;
	case HSE:
		RCC_CR |= HSEON;
		break;
	case HSI:
		RCC_CR |= HSION;
		break;
	case LSE:
		RCC_BDCR |= LSEON;
		break;
	case LSI:
		RCC_CSR |= LSION;
		break;
	}
}

void rcc_osc_off(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR &= ~PLLON;
		break;
	case HSE:
		RCC_CR &= ~HSEON;
		break;
	case HSI:
		RCC_CR &= ~HSION;
		break;
	case LSE:
		RCC_BDCR &= ~LSEON;
		break;
	case LSI:
		RCC_CSR &= ~LSION;
		break;
	}
}

void rcc_css_enable(void)
{
	RCC_CR |= CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~CSSON;
}

void rcc_osc_bypass_enable(osc_t osc)
{
	switch (osc) {
	case HSE:
		RCC_CR |= HSEBYP;
		break;
	case LSE:
		RCC_BDCR |= LSEBYP;
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
		RCC_CR &= ~HSEBYP;
		break;
	case LSE:
		RCC_BDCR &= ~LSEBYP;
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
	*reg |= clear_reset;
}

void rcc_set_sysclk_source(u32 clk)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC_CFGR = (reg32 | clk);
}

void rcc_set_pll_multiplication_factor(u32 mul)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 21) | (1 << 20) | (1 << 19) | (1 << 18));
	RCC_CFGR = (reg32 | (mul << 18));
}

void rcc_set_pll_source(u32 pllsrc)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 16);
	RCC_CFGR = (reg32 | (pllsrc << 16));
}

void rcc_set_pllxtpre(u32 pllxtpre)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 17);
	RCC_CFGR = (reg32 | (pllxtpre << 17));
}

void rcc_set_adcpre(u32 adcpre)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ((1 << 14) | (1 << 15));
	RCC_CFGR = (reg32 | (adcpre << 14));
}

void rcc_set_ppre2(u32 ppre2)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ((1 << 11) | (1 << 12) | (1 << 13));
	RCC_CFGR = (reg32 | (ppre2 << 11));
}

void rcc_set_ppre1(u32 ppre1)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ((1 << 8) | (1 << 9) | (1 << 10));
	RCC_CFGR = (reg32 | (ppre1 << 8));
}

void rcc_set_hpre(u32 hpre)
{
	u32 reg32;

	reg32 = RCC_CFGR;
	reg32 &= ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
	RCC_CFGR = (reg32 | (hpre << 4));
}

u32 rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return ((RCC_CFGR & 0x000c) >> 2);
}


/*
 * These functions are setting up the whole clock system for the most common
 * input clock and output clock configurations.
 */
void rcc_clock_setup_in_hsi_out_64mhz(void){

        /* enable Internal High Speed Oscillator */
        rcc_osc_on(HSI);
        rcc_wait_for_osc_ready(HSI);

        /* Select HSI as SYSCLK source. */
        rcc_set_sysclk_source(SW_SYSCLKSEL_HSICLK);

        /*
	 * set prescalers for AHB, ADC, ABP1, ABP2
	 * make this before touching the PLL (why?)
	 */
        rcc_set_hpre(HPRE_SYSCLK_NODIV);   /* Max 72MHz */
        rcc_set_adcpre(ADCPRE_PLCK2_DIV8); /* Max 14MHz */
        rcc_set_ppre1(PPRE1_HCLK_DIV2);    /* Max 36MHz */
        rcc_set_ppre2(PPRE2_HCLK_NODIV);   /* Max 72MHz */

        /* sysclk is running with 64MHz -> 2 Waitstates
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
        flash_set_ws(FLASH_LATENCY_2WS);

        /* Set the PLL multiplication factor to 16.
	 * -> 8MHz (internal) * 16 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 64MHz
	 */
        rcc_set_pll_multiplication_factor(PLLMUL_PLL_CLK_MUL16);

        /* Select HSI/2 as PLL source. */
        rcc_set_pll_source(PLLSRC_HSI_CLK_DIV2);


        /* Enable PLL oscillator and wait for it to stabilize. */
        rcc_osc_on(PLL);
        rcc_wait_for_osc_ready(PLL);

        /* Select PLL as SYSCLK source. */
        rcc_set_sysclk_source(SW_SYSCLKSEL_PLLCLK);
}

void rcc_clock_setup_in_hse_8mhz_out_72mhz(void){

        /* enable Internal High Speed Oscillator */
        rcc_osc_on(HSI);
        rcc_wait_for_osc_ready(HSI);

        /* Select HSI as SYSCLK source. */
        rcc_set_sysclk_source(SW_SYSCLKSEL_HSICLK);

        /* enable External High Speed Oscillator 8MHz */
        rcc_osc_on(HSE);
        rcc_wait_for_osc_ready(HSE);
        rcc_set_sysclk_source(SW_SYSCLKSEL_HSECLK);

        /* set prescalers for AHB, ADC, ABP1, ABP2
	 * do this before touching the PLL (why?)
	 */
        rcc_set_hpre(HPRE_SYSCLK_NODIV);   // Max 72MHz
        rcc_set_adcpre(ADCPRE_PLCK2_DIV8); // Max 14MHz
        rcc_set_ppre1(PPRE1_HCLK_DIV2);    // Max 36MHz
        rcc_set_ppre2(PPRE2_HCLK_NODIV);   // Max 72MHz

        /* sysclk runs with 72MHz -> 2 Waitstates
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
        flash_set_ws(FLASH_LATENCY_2WS);

        /* Set the PLL multiplication factor to 9.
	 * -> 8MHz (external) * 9 (multiplier) = 72MHz
	 */
        rcc_set_pll_multiplication_factor(PLLMUL_PLL_CLK_MUL10);

        /* Select HSE as PLL source. */
        rcc_set_pll_source(PLLSRC_HSE_CLK);

        /* external frequency undivided before entering pll
	 * (only valid/needed for HSE)
	 */
        rcc_set_pllxtpre(PLLXTPRE_HSE_CLK);

        /* Enable PLL oscillator and wait for it to stabilize. */
        rcc_osc_on(PLL);
        rcc_wait_for_osc_ready(PLL);

        /* Select PLL as SYSCLK source. */
        rcc_set_sysclk_source(SW_SYSCLKSEL_PLLCLK);

}
