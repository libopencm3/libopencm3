/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32G0xx Reset and Clock Control</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @date 10 January 2019
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */

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

/**@{*/

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/cm3/assert.h>

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency =  16000000;
uint32_t rcc_apb1_frequency = 16000000;

const struct rcc_clock_scale rcc_clock_config[RCC_CLOCK_CONFIG_END] = {
	[RCC_CLOCK_CONFIG_LSI_32KHZ] = {
		/* 32khz from lsi, scale2, 0ws */
		.sysclock_source = RCC_LSI,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = FLASH_ACR_LATENCY_0WS,
		.voltage_scale = PWR_SCALE2,
		.ahb_frequency = 32000,
		.apb_frequency = 32000,
	},
	[RCC_CLOCK_CONFIG_HSI_4MHZ] = {
		/* 4mhz from hsi/4, scale2, 0ws */
		.sysclock_source = RCC_HSI,
		.hsisys_div = RCC_CR_HSIDIV_DIV4,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = FLASH_ACR_LATENCY_0WS,
		.voltage_scale = PWR_SCALE2,
		.ahb_frequency = 4000000,
		.apb_frequency = 4000000,
	},
	[RCC_CLOCK_CONFIG_HSI_16MHZ] = {
		/* 16mhz from hsi, scale2, 0ws */
		.sysclock_source = RCC_HSI,
		.hsisys_div = RCC_CR_HSIDIV_DIV1,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = FLASH_ACR_LATENCY_0WS,
		.voltage_scale = PWR_SCALE2,
		.ahb_frequency = 16000000,
		.apb_frequency = 16000000,
	},
	[RCC_CLOCK_CONFIG_HSI_PLL_32MHZ] = {
		/* 32mhz from hsi via pll @ 128mhz / 4, scale1, 1ws */
		.sysclock_source = RCC_PLL,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.pll_div = RCC_PLLCFGR_PLLM_DIV(1),
		.pll_mul = RCC_PLLCFGR_PLLN_MUL(8),
		.pllp_div = RCC_PLLCFGR_PLLP_DIV(4),
		.pllq_div = RCC_PLLCFGR_PLLQ_DIV(4),
		.pllr_div = RCC_PLLCFGR_PLLR_DIV(4),
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = FLASH_ACR_LATENCY_1WS,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency = 32000000,
		.apb_frequency = 32000000,
	},
	[RCC_CLOCK_CONFIG_HSI_PLL_64MHZ] = {
		/* 64mhz from hsi via pll @ 128mhz / 2, scale1, 2ws */
		.sysclock_source = RCC_PLL,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.pll_div = RCC_PLLCFGR_PLLM_DIV(1),
		.pll_mul = RCC_PLLCFGR_PLLN_MUL(8),
		.pllp_div = RCC_PLLCFGR_PLLP_DIV(2),
		.pllq_div = RCC_PLLCFGR_PLLQ_DIV(2),
		.pllr_div = RCC_PLLCFGR_PLLR_DIV(2),
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = FLASH_ACR_LATENCY_2WS,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency = 64000000,
		.apb_frequency = 64000000,
	},
	[RCC_CLOCK_CONFIG_HSE_12MHZ_PLL_64MHZ] = {
		/* 64mhz from hse@12mhz via pll @ 128mhz / 2, scale1, 2ws */
		.sysclock_source = RCC_PLL,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.pll_div = RCC_PLLCFGR_PLLM_DIV(3),
		.pll_mul = RCC_PLLCFGR_PLLN_MUL(32),
		.pllp_div = RCC_PLLCFGR_PLLP_DIV(2),
		.pllq_div = RCC_PLLCFGR_PLLQ_DIV(2),
		.pllr_div = RCC_PLLCFGR_PLLR_DIV(2),
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = FLASH_ACR_LATENCY_2WS,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency = 64000000,
		.apb_frequency = 64000000,
	},
};

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}
}

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}
}

bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI:
		return RCC_CR & RCC_CR_HSIRDY;
	case RCC_LSE:
		return RCC_BDCR & RCC_BDCR_LSERDY;
	case RCC_LSI:
		return RCC_CSR & RCC_CSR_LSIRDY;
	default:
		cm3_assert_not_reached();
		return 0;
	}
	return false;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc));
}

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_css_int_clear(void)
{
	RCC_CICR |= RCC_CICR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIFR & RCC_CIFR_CSSF) != 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Source for the System Clock.
 * @param osc Oscillator to use.
 */
void rcc_set_sysclk_source(enum rcc_osc osc)
{
	uint32_t reg32;
	uint32_t sw = 0;

	switch (osc) {
		case RCC_HSI:
			sw = RCC_CFGR_SW_HSISYS;
			break;
		case RCC_HSE:
			sw = RCC_CFGR_SW_HSE;
			break;
		case RCC_PLL:
			sw = RCC_CFGR_SW_PLLRCLK;
			break;
		case RCC_LSE:
			sw = RCC_CFGR_SW_LSE;
			break;
		case RCC_LSI:
			sw = RCC_CFGR_SW_LSI;
			break;
		default:
			cm3_assert_not_reached();
			return;
	}

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	RCC_CFGR = (reg32 | (sw << RCC_CFGR_SW_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Return the clock source which is used as system clock.
 * @return rcc_osc system clock source
 */
enum rcc_osc rcc_system_clock_source(void)
{
	switch ((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) {
		case RCC_CFGR_SW_HSISYS:
			return RCC_HSI;
		case RCC_CFGR_SW_HSE:
			return RCC_HSE;
		case RCC_CFGR_SWS_PLLRCLK:
			return RCC_PLL;
		case RCC_CFGR_SW_LSE:
			return RCC_LSE;
		case RCC_CFGR_SW_LSI:
			return RCC_LSI;
		default:
			cm3_assert_not_reached();
			return 0;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Wait until system clock switched to given oscillator.
 * @param osc Oscillator.
 */
void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	uint32_t sws = 0;

	switch (osc) {
		case RCC_PLL:
			sws = RCC_CFGR_SWS_PLLRCLK;
			break;
		case RCC_HSE:
			sws = RCC_CFGR_SWS_HSE;
			break;
		case RCC_HSI:
			sws = RCC_CFGR_SWS_HSISYS;
			break;
		case RCC_LSI:
			sws = RCC_CFGR_SWS_LSI;
			break;
		case RCC_LSE:
			sws = RCC_CFGR_SWS_LSE;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}

	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) != sws);
}

/**
 * @brief Configure pll source.
 * @param[in] pllsrc pll clock source @ref rcc_pllcfgr_pllsrc
 */
void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(RCC_PLLCFGR_PLLSRC_MASK << RCC_PLLCFGR_PLLSRC_SHIFT);
	RCC_PLLCFGR = (reg32 | (pllsrc << RCC_PLLCFGR_PLLSRC_SHIFT));
}

/**
 * @brief Configure pll source and output frequencies.
 * @param[in] source pll clock source @ref rcc_pllcfgr_pllsrc
 * @param[in] pllm pll vco division factor @ref rcc_pllcfgr_pllm
 * @param[in] plln pll vco multiplation factor @ref rcc_pllcfgr_plln
 * @param[in] pllp pll P clock output division factor @ref rcc_pllcfgr_pllp
 * @param[in] pllq pll Q clock output division factor @ref rcc_pllcfgr_pllq
 * @param[in] pllr pll R clock output (sysclock pll) division factor @ref rcc_pllcfgr_pllr
 */
void rcc_set_main_pll(uint32_t source, uint32_t pllm, uint32_t plln, uint32_t pllp,
	uint32_t pllq, uint32_t pllr)
{
	RCC_PLLCFGR = (source << RCC_PLLCFGR_PLLSRC_SHIFT) |
		(pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(pllp << RCC_PLLCFGR_PLLP_SHIFT) |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT) |
		(pllr << RCC_PLLCFGR_PLLR_SHIFT);
}

/**
 * @brief Enable PLL P clock output.
 * @param[in] enable or disable P clock output
 */
void rcc_enable_pllp(bool enable)
{
	if (enable) {
		RCC_PLLCFGR |= RCC_PLLCFGR_PLLPEN;
	} else {
		RCC_PLLCFGR &= ~RCC_PLLCFGR_PLLPEN;
	}
}

/**
 * @brief Enable PLL Q clock output.
 * @param[in] enable or disable Q clock output
 */
void rcc_enable_pllq(bool enable)
{
	if (enable) {
		RCC_PLLCFGR |= RCC_PLLCFGR_PLLQEN;
	} else {
		RCC_PLLCFGR &= ~RCC_PLLCFGR_PLLQEN;
	}
}

/**
 * @brief Enable PLL R clock output.
 * @param[in] enable or disable R clock output
 */
void rcc_enable_pllr(bool enable)
{
	if (enable) {
		RCC_PLLCFGR |= RCC_PLLCFGR_PLLREN;
	} else {
		RCC_PLLCFGR &= ~RCC_PLLCFGR_PLLREN;
	}
}

/**
 * @brief Configure APB peripheral clock prescaler
 * @param[in] ppre APB clock prescaler value @ref rcc_cfgr_ppre
 */
void rcc_set_ppre(uint32_t ppre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE_MASK << RCC_CFGR_PPRE_SHIFT);
	RCC_CFGR = (reg32 | (ppre << RCC_CFGR_PPRE_SHIFT));
}

/**
 * @brief Configure AHB peripheral clock prescaler
 * @param[in] hpre AHB clock prescaler value @ref rcc_cfgr_hpre
 */
void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
}

/**
 * @brief Configure HSI16 clock division factor to feed SYSCLK
 * @param[in] hsidiv HSYSSIS clock division factor @ref rcc_cr_hsidiv
 */
void rcc_set_hsisys_div(uint32_t hsidiv)
{
	uint32_t reg32;

	reg32 = RCC_CR;
	reg32 &= ~(RCC_CR_HSIDIV_MASK << RCC_CR_HSIDIV_SHIFT);
	RCC_CR = (reg32 | (hsidiv << RCC_CR_HSIDIV_SHIFT));
}

/**
 * @brief Configure mco prescaler.
 * @param[in] mcopre prescaler value @ref rcc_cfgr_mcopre
 */
void rcc_set_mcopre(uint32_t mcopre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_MCOPRE_MASK << RCC_CFGR_MCOPRE_SHIFT);
	RCC_CFGR = (reg32 | (mcopre << RCC_CFGR_MCOPRE_SHIFT));
}

/**
 * @brief Setup sysclock with desired source (HSE/HSI/PLL/LSE/LSI). taking care of flash/pwr and src configuration
 * @param clock rcc_clock_scale with desired parameters
 */
void rcc_clock_setup(const struct rcc_clock_scale *clock)
{
	if (clock->sysclock_source == RCC_PLL) {
		enum rcc_osc pll_source;

		if (clock->pll_source == RCC_PLLCFGR_PLLSRC_HSE)
			pll_source = RCC_HSE;
		else
			pll_source = RCC_HSI;

		/* start pll src osc. */
		rcc_osc_on(pll_source);
		rcc_wait_for_osc_ready(pll_source);

		/* stop pll to reconfigure it. */
		rcc_osc_off(RCC_PLL);
		while (rcc_is_osc_ready(RCC_PLL));

		rcc_set_main_pll(clock->pll_source, clock->pll_div, clock->pll_mul, clock->pllp_div, clock->pllq_div, clock->pllr_div);

		rcc_enable_pllr(true);
	} else if (clock->sysclock_source == RCC_HSI) {
		rcc_set_hsisys_div(clock->hsisys_div);
	}

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->voltage_scale);

	flash_set_ws(clock->flash_waitstates);

	/* enable flash prefetch if we have at least 1WS */
	if (clock->flash_waitstates > FLASH_ACR_LATENCY_0WS)
		flash_prefetch_enable();
	else
		flash_prefetch_disable();

	rcc_set_hpre(clock->hpre);
	rcc_set_ppre(clock->ppre);

	rcc_osc_on(clock->sysclock_source);
	rcc_wait_for_osc_ready(clock->sysclock_source);

	rcc_set_sysclk_source(clock->sysclock_source);
	rcc_wait_for_sysclk_status(clock->sysclock_source);

	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb_frequency;
}

/**
 * @brief Setup RNG Peripheral Clock Divider
 * @param rng_div clock divider @ref rcc_ccipr_rngdiv
 */
void rcc_set_rng_clk_div(uint32_t rng_div)
{
	uint32_t reg32 = RCC_CCIPR & ~(RCC_CCIPR_RNGDIV_MASK << RCC_CCIPR_RNGDIV_SHIFT);
	RCC_CCIPR = reg32 | (rng_div << RCC_CCIPR_RNGDIV_SHIFT);
}

/**
 * @brief Set the peripheral clock source
 * @param periph peripheral of choice, eg XXX_BASE
 * @param sel periphral clock source
 */
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel)
{
	uint8_t shift;
	uint32_t mask;

	switch (periph) {
		case ADC1_BASE:
			shift = RCC_CCIPR_ADCSEL_SHIFT;
			mask = RCC_CCIPR_ADCSEL_MASK;
			break;
		case RNG_BASE:
			shift = RCC_CCIPR_RNGSEL_SHIFT;
			mask = RCC_CCIPR_RNGSEL_MASK;
			break;
		case TIM1_BASE:
			shift = RCC_CCIPR_TIM1SEL_SHIFT;
			mask = RCC_CCIPR_TIM1SEL_MASK;
			break;
		case LPTIM1_BASE:
			shift = RCC_CCIPR_LPTIM1SEL_SHIFT;
			mask = RCC_CCIPR_LPTIM1SEL_MASK;
			break;
		case LPTIM2_BASE:
			shift = RCC_CCIPR_LPTIM2SEL_SHIFT;
			mask = RCC_CCIPR_LPTIM2SEL_MASK;
			break;
		case CEC_BASE:
			shift = RCC_CCIPR_CECSEL_SHIFT;
			mask = RCC_CCIPR_CECSEL_MASK;
			break;
		case USART2_BASE:
			shift = RCC_CCIPR_USART2SEL_SHIFT;
			mask = RCC_CCIPR_USART2SEL_MASK;
			break;
		case USART1_BASE:
			shift = RCC_CCIPR_USART1SEL_SHIFT;
			mask = RCC_CCIPR_USART1SEL_MASK;
			break;
		default:
			cm3_assert_not_reached();
			return;
	}

	uint32_t reg32 = RCC_CCIPR & ~(mask << shift);
	RCC_CCIPR = reg32 | (sel << shift);
}

static uint32_t rcc_get_clksel_freq(uint8_t shift) {
	uint8_t clksel = (RCC_CCIPR >> shift) & RCC_CCIPR_USART1SEL_MASK;
	uint8_t hpre = (RCC_CFGR >> RCC_CFGR_HPRE_SHIFT) & RCC_CFGR_HPRE_MASK;
	switch (clksel) {
		case RCC_CCIPR_USART1SEL_PCLK:
			return rcc_apb1_frequency;
		case RCC_CCIPR_USART1SEL_SYSCLK:
			return rcc_ahb_frequency * rcc_get_div_from_hpre(hpre);
		case RCC_CCIPR_USART1SEL_HSI16:
			return 16000000U;
	}
	cm3_assert_not_reached();
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	if (usart == USART1_BASE) {
		return rcc_get_clksel_freq(RCC_CCIPR_USART1SEL_SHIFT);
	} else if (usart == USART2_BASE) {
		return rcc_get_clksel_freq(RCC_CCIPR_USART2SEL_SHIFT);
	} else if (usart == LPUART1_BASE) {
		return rcc_get_clksel_freq(RCC_CCIPR_LPUART1SEL_SHIFT);
	} else {
		return rcc_apb1_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the Timer at base specified.
 * @param timer  Base address of TIM to get clock frequency for.
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer __attribute__((unused)))
{
	uint8_t ppre = (RCC_CFGR >> RCC_CFGR_PPRE_SHIFT) & RCC_CFGR_PPRE_MASK;
	return (ppre == RCC_CFGR_PPRE_NODIV) ? rcc_apb1_frequency
		: 2 * rcc_apb1_frequency;
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for.
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c __attribute__((unused)))
{
	if (i2c == I2C1_BASE) {
		return rcc_get_clksel_freq(RCC_CCIPR_I2C1SEL_SHIFT);
	} else {
		return rcc_apb1_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the SPI device at base specified.
 * @param spi  Base address of SPI device to get clock frequency for (e.g. SPI1_BASE).
 */
uint32_t rcc_get_spi_clk_freq(uint32_t spi __attribute__((unused))) {
	return rcc_apb1_frequency;
}

/**@}*/
