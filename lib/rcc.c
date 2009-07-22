/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
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
		while ((RCC_CR & PLLRDY) != 0);
		break;
	case HSE:
		while ((RCC_CR & HSERDY) != 0);
		break;
	case HSI:
		while ((RCC_CR & HSIRDY) != 0);
		break;
	case LSE:
		while ((RCC_BDCR & LSERDY) != 0);
		break;
	case LSI:
		while ((RCC_CSR & LSIRDY) != 0);
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
