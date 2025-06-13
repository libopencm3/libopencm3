/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 AT32F43x Reset and Clock Control</b>

@version 1.0.0

This library supports the Reset and Clock Control System in the AT32F43x
series of ARM Cortex Microcontrollers by Arterytek.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>

/** Set the default clock frequencies */
uint32_t rcc_apb1_frequency = 8000000;
uint32_t rcc_apb2_frequency = 8000000;
uint32_t rcc_ahb_frequency = 8000000;

const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END] = {
	{	/* 8->84 MHz */
		.pllm = 2,
		.plln = 168,
		.pllp = 8,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency = 84000000,
		.apb1_frequency = 84000000,
		.apb2_frequency = 84000000,
	},
	{	/* 8->96 MHz */
		.pllm = 2,
		.plln = 192,
		.pllp = 8,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency	= 96000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 8->168 MHz */
		.pllm = 2,
		.plln = 168,
		.pllp = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency	= 168000000,
		.apb1_frequency = 84000000,
		.apb2_frequency = 84000000,
	},
	{	/* 8->192 MHz */
		.pllm = 2,
		.plln = 192,
		.pllp = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.voltage_scale = PWR_SCALE2,
		.ahb_frequency	= 192000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 8->240 MHz */
		.pllm = 1,
		.plln = 120,
		.pllp = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.voltage_scale = PWR_SCALE2,
		.ahb_frequency	= 240000000,
		.apb1_frequency = 120000000,
		.apb2_frequency = 120000000,
	},
	{	/* 8->288 MHz */
		.pllm = 1,
		.plln = 144,
		.pllp = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.voltage_scale = PWR_SCALE3,
		.ahb_frequency	= 288000000,
		.apb1_frequency = 144000000,
		.apb2_frequency = 144000000,
	}
};

const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END] = {
	{	/* 8->84 MHz */
		.pllm = 2,
		.plln = 168,
		.pllp = 8,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency = 84000000,
		.apb1_frequency = 84000000,
		.apb2_frequency = 84000000,
	},
	{	/* 8->96 MHz */
		.pllm = 2,
		.plln = 192,
		.pllp = 8,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency	= 96000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 8->168 MHz */
		.pllm = 2,
		.plln = 168,
		.pllp = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.voltage_scale = PWR_SCALE1,
		.ahb_frequency	= 168000000,
		.apb1_frequency = 84000000,
		.apb2_frequency = 84000000,
	},
	{	/* 8->192 MHz */
		.pllm = 2,
		.plln = 192,
		.pllp = 4,
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.voltage_scale = PWR_SCALE2,
		.ahb_frequency	= 192000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	}
};

/*---------------------------------------------------------------------------*/
void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while (((RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_SHIFT) !=
		       RCC_CFGR_SWS_SYSCLKSEL_PLLCLK);
		break;
	case RCC_HSE:
		while (((RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_SHIFT) !=
		       RCC_CFGR_SWS_SYSCLKSEL_HSECLK);
		break;
	case RCC_HSI:
		while (((RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_SHIFT) !=
		       RCC_CFGR_SWS_SYSCLKSEL_HSICLK);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllsrc PLL clock source @ref rcc_cfgr_pcs
*/

void rcc_set_pll_source(uint32_t pllsrc)
{
	RCC_PLLCFGR = (RCC_PLLCFGR & ~RCC_PLLCFGR_PLLSRC) |
		(pllsrc ? RCC_PLLCFGR_PLLSRC : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Setup the PLL in fractional mode.

@note This only has effect when the PLL is disabled.

@param pllm Divider for the PLL input clock
@param plln PLL multiplication factor for VCO
@param pllp PLL post divider for main system clock
*/

void rcc_set_pll_fract(uint32_t pllm, uint32_t plln, uint32_t pllp)
{
	pllp = 0x7 & (31 - __builtin_clz(pllp));
	RCC_PLLCFGR = (RCC_PLLCFGR & ~(RCC_PLLCFGR_PLLM |
				       RCC_PLLCFGR_PLLN |
				       RCC_PLLCFGR_PLLP)) |
                (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
                (plln << RCC_PLLCFGR_PLLN_SHIFT) |
                (pllp << RCC_PLLCFGR_PLLP_SHIFT);
}

/*---------------------------------------------------------------------------*/
/**
 * Setup clocks to run from PLL.
 * The arguments provide the pll source, multipliers, dividers, all that's
 * needed to establish a system clock.
 * @param clock clock information structure
 */

void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{/* TODO generalize PLLCFGR & PLLSRC constants */
	if (clock->pll_source == RCC_PLLCFGR_PLLSRC_HSE) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else {
		rcc_osc_on(RCC_HSI);
		rcc_wait_for_osc_ready(RCC_HSI);
	}

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->voltage_scale);

	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_pll_fract(clock->pllm, clock->plln, clock->pllp);
	rcc_set_pll_source(clock->pll_source);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/*---------------------------------------------------------------------------*/
/** @brief Set RCC HSI to SYSCLK selector.

@param[in] hsisclk HSI to SYSCLK selector @ref rcc_cfgr5_hsi_sclk
*/

void rcc_set_hsi_sclk(uint32_t hsisclk)
{
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_HSI_SCLK) |
		(hsisclk ? RCC_CFGR3_HSI_SCLK : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock Source.

@param[in] mco MCO clock output. @ref rcc_cfgr_mco
@param[in] mcosrc MCO clock source. @ref rcc_cfgr_mco
*/

void rcc_set_mco_source(enum rcc_mco mco, uint32_t mcosrc)
{
	switch (mco) {
	case MCO1:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_MCO1) |
			(mcosrc << RCC_CFGR_MCO1_SHIFT);
		break;
	case MCO2:
		/* TODO mco2 extra mux */
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_MCO2) |
			(mcosrc << RCC_CFGR_MCO2_SHIFT);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock prescaler.

@param[in] mco MCO clock output. @ref rcc_cfgr_mco
@param[in] mcopre MCO clock prescaler. @ref rcc_cfgr_mco
*/

void rcc_set_mcopre(enum rcc_mco mco, uint32_t mcopre)
{
	switch (mco) {
	case MCO1:
		RCC_CFGR = (RCC_CFGR & ~ RCC_CFGR_MCO1PRE) |
			(mcopre << RCC_CFGR_MCO1PRE_SHIFT);
		break;
	case MCO2:
		RCC_CFGR = (RCC_CFGR & ~ RCC_CFGR_MCO2PRE) |
			(mcopre << RCC_CFGR_MCO2PRE_SHIFT);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock Divider.

@param[in] mco MCO clock output. @ref rcc_cfgr_mco
@param[in] mcopre MCO clock divider. @ref rcc_cfgr_mco
*/

void rcc_set_mcodiv(enum rcc_mco mco, uint32_t mcodiv)
{
	switch (mco) {
	case MCO1:
		RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_MCO1_DIV) |
			(mcodiv << RCC_CFGR3_MCO1_DIV_SHIFT);
		break;
	case MCO2:
		RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_MCO2_DIV) |
			(mcodiv << RCC_CFGR3_MCO2_DIV_SHIFT);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the RTC Clock Divider.

@param[in] rtcdiv RTC clock divider. @ref rcc_cfgr_rtc
*/

void rcc_set_rtcpre(uint32_t rtcpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_RTCPRE) |
		(rtcpre << RCC_CFGR_RTCPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Clock Source.

@note This only has effect when the USB is disabled.

@param[in] ocs USB clock source, PLL or HSI. @ref rcc_cfgr3_usb_src
*/

void rcc_set_usb_clock_source(enum rcc_osc osc)
{
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_HSI_USB_SRC) |
		(osc == RCC_HSI ? RCC_CFGR3_HSI_USB_SRC : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Prescale Factor.

@note These bits cannot be reset while the USB clock is enabled.

@param[in] usbpre USB prescale factor @ref rcc_cfgr_usbpre
*/

void rcc_set_usbpre(uint32_t usbpre)
{
	RCC_CFGR4 = (RCC_CFGR4 & ~RCC_CFGR4_USBPRE) |
		(usbpre << RCC_CFGR4_USBPRE_SHIFT);
}

/**@}*/
