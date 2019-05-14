/** @defgroup rcc_file RCC
 *
 * @ingroup STM32F7xx
 *
 * @section rcc_f7_api_ex Reset and Clock Control API.
 *
 * @brief <b>libopencm3 STM32F7xx Reset and Clock Control</b>
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

/**@{*/

// All PLL configurations without PLLM. PLLM should be set to the input clock
// frequency in MHz.
const struct rcc_clock_scale rcc_3v3[RCC_CLOCK_3V3_END] = {
	{ /* 216MHz */
		.plln = 432,
		.pllp = 2,
		.pllq = 9,
		.pllr = 0,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.vos_scale = PWR_SCALE1,
		.overdrive = 1,
		.flash_waitstates = 7,
		.ahb_frequency = 216000000,
		.apb1_frequency = 54000000,
		.apb2_frequency = 108000000,
	},
	{ /* 168MHz */
		.plln = 336,
		.pllp = 2,
		.pllq = 7,
		.pllr = 0,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.vos_scale = PWR_SCALE2,
		.overdrive = 1,
		.flash_waitstates = 5,
		.ahb_frequency = 168000000,
		.apb1_frequency = 42000000,
		.apb2_frequency = 84000000,
	},
	{ /* 120MHz */
		.plln = 240,
		.pllp = 2,
		.pllq = 5,
		.pllr = 0,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.vos_scale = PWR_SCALE3,
		.overdrive = 0,
		.flash_waitstates = 3,
		.ahb_frequency = 120000000,
		.apb1_frequency = 30000000,
		.apb2_frequency = 60000000,
	},
	{ /* 72MHz */
		.plln = 144,
		.pllp = 2,
		.pllq = 3,
		.pllr = 0,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.vos_scale = PWR_SCALE3,
		.overdrive = 0,
		.flash_waitstates = 2,
		.ahb_frequency = 72000000,
		.apb1_frequency = 18000000,
		.apb2_frequency = 36000000,
	},
	{ /* 48MHz */
		.plln = 192,
		.pllp = 4,
		.pllq = 4,
		.pllr = 0,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_2,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.vos_scale = PWR_SCALE3,
		.overdrive = 0,
		.flash_waitstates = 1,
		.ahb_frequency = 48000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 24000000,
	},
	{ /* 24MHz */
		.plln = 192,
		.pllp = 8,
		.pllq = 4,
		.pllr = 0,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_NONE,
		.ppre2 = RCC_CFGR_PPRE_DIV_NONE,
		.vos_scale = PWR_SCALE3,
		.overdrive = 0,
		.flash_waitstates = 0,
		.ahb_frequency = 24000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 24000000,
	}
};


void rcc_clock_setup_hse(const struct rcc_clock_scale *clock, uint32_t hse_mhz)
{
	uint8_t pllm = hse_mhz;

	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI);

	/* Enable external high-speed oscillator. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->vos_scale);

	if (clock->overdrive) {
		pwr_enable_overdrive();
	}

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	/* Disable PLL oscillator before changing its configuration. */
	rcc_osc_off(RCC_PLL);

	/* Configure the PLL oscillator. */
	rcc_set_main_pll_hse(pllm, clock->plln,
			clock->pllp, clock->pllq, clock->pllr);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash settings. */
	flash_set_ws(clock->flash_waitstates);
	flash_art_enable();
	flash_prefetch_enable();

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);

	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the clock frequencies used. */
	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;

	/* Disable internal high-speed oscillator. */
	rcc_osc_off(RCC_HSI);
}

void rcc_clock_setup_hsi(const struct rcc_clock_scale *clock)
{
	uint8_t pllm = 16;

	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI);

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->vos_scale);

	if (clock->overdrive) {
		pwr_enable_overdrive();
	}

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_main_pll_hsi(pllm, clock->plln,
			     clock->pllp, clock->pllq, clock->pllr);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash settings. */
	flash_set_ws(clock->flash_waitstates);
	flash_art_enable();
	flash_prefetch_enable();

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);

	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the clock frequencies used. */
	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/**@}*/
