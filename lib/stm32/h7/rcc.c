/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
#include <stddef.h>
#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

#define ONEMILLION			1000000UL

uint32_t rcc_ahb_frequency = HSI_BASE_FREQUENCY;
uint32_t rcc_apb1_frequency = HSI_BASE_FREQUENCY;
uint32_t rcc_apb2_frequency = HSI_BASE_FREQUENCY;

/* Local private copy of the clock configuration for providing user with clock tree data. */
static struct {
	uint16_t sysclk_mhz;
	uint16_t cpu_mhz;
	uint16_t hclk_mhz;
	struct {
		uint16_t pclk1_mhz;		/* APB1 clock. */
		uint16_t pclk2_mhz;		/* APB2 clock. */
		uint16_t pclk3_mhz;		/* APB3 clock. */
		uint16_t pclk4_mhz;		/* APB4 clock. */
	} per;
	struct {				/* Each PLL output set of data. */
		uint16_t p_mhz;
		uint16_t q_mhz;
		uint16_t r_mhz;
	} pll[3];
} rcc_clock_tree;

static void rcc_set_and_enable_plls(const struct rcc_pll_config *config) {
	/* Now, let's setup PLL1/2/3 with configurations specified. */
	RCC_PLLCKSELR = RCC_PLLCKSELR_DIVM1(config->plls[0].divm) | 
					RCC_PLLCKSELR_DIVM2(config->plls[1].divm) | 
					RCC_PLLCKSELR_DIVM3(config->plls[2].divm) | 
					config->pll_mux;
	
	RCC_PLLCFGR &= RCC_PLLCFGR_RSVD_BITMASK;
	for (size_t i = 0; i < 3; i++) {
		/* Only concern ourselves with the PLL if the input clock is enabled. */
		if (config->plls[i].divm == 0) {
			continue;
		}

		/* Let's write all of the dividers as specified. */
		RCC_PLLDIVR(i) &= RCC_PLLNDIVR_RSVD_BITMASK;
		RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVN(config->plls[i].divn);

		/* Setup the PLL config values for this PLL. */
		uint8_t vco_addshift = 4 * i; 		/* Values spaced by 4 for PLL 1/2/3 */
		uint32_t clk = (config->pll_mux == RCC_PLL_HSI) ? HSI_BASE_FREQUENCY 
			: config->hse_frequency;
		/* Set the PLL input frequency range. */
		uint32_t pll_clk_mhz = (clk / config->plls[i].divm) / ONEMILLION;
		if (pll_clk_mhz <= 2) {}	/* Do nothing, already masked to 0x00. */
		if (pll_clk_mhz > 2 && pll_clk_mhz <= 4) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_2_4MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
		} else if (pll_clk_mhz > 4 && pll_clk_mhz <= 8) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_4_8MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
		} else if (pll_clk_mhz > 8) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_8_16MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
		}

		/* Set the VCO output frequency range. */
		uint32_t pll_vco_clk_mhz = (pll_clk_mhz * config->plls[i].divn);
		if (pll_vco_clk_mhz <= 420) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLL1VCO_MED << vco_addshift);
		}

		/* Setup the enable bits for the PLL outputs. */
		uint8_t diven_addshift = 3 * i;		/* Values spaced by 3 for PLL1/2/3 */
		if (config->plls[i].divp > 0) {
			RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVP(config->plls[i].divp);
			RCC_PLLCFGR |= (RCC_PLLCFGR_DIVP1EN << diven_addshift);
			rcc_clock_tree.pll[i].p_mhz = pll_vco_clk_mhz / config->plls[i].divp;
		} 
		if (config->plls[i].divq > 0) {
			RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVQ(config->plls[i].divq);
			RCC_PLLCFGR |= (RCC_PLLCFGR_DIVQ1EN << diven_addshift);
			rcc_clock_tree.pll[i].q_mhz = pll_vco_clk_mhz / config->plls[i].divq;
		}
		if (config->plls[i].divr > 0) {
			RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVR(config->plls[i].divr);
			RCC_PLLCFGR |= (RCC_PLLCFGR_DIVR1EN << diven_addshift);
			rcc_clock_tree.pll[i].r_mhz = pll_vco_clk_mhz / config->plls[i].divr;
		}

		/* Attempt to enable and lock PLL. */
		uint8_t cr_addshift = 2 * i; 
		RCC_CR |= RCC_CR_PLL1ON << cr_addshift;
		while (!(RCC_CR & (RCC_CR_PLL1RDY << cr_addshift)));
	}
}

static uint16_t rcc_prediv_log_skip32_div(uint16_t clk_mhz, uint32_t div_val) {
	if (div_val < 0x8) {
		return clk_mhz;
	} else if (div_val <= RCC_D1CFGR_D1CPRE_DIV16) {
		return clk_mhz >> (div_val - 7);
	} else {
		return clk_mhz >> (div_val - 6);
	}
}

static uint16_t rcc_prediv_log_to_16(uint16_t clk_mhz, uint32_t div_val) {
	if (div_val < 0x4) {
		return clk_mhz;
	} else {
		return clk_mhz >> (div_val - 3);
	}
}

static void rcc_clock_setup_domain1(const struct rcc_pll_config *config) {
	RCC_D1CFGR &= RCC_D1CFGR_RSVD_BITMASK;
	RCC_D1CFGR |= config->domain1.core_prescale | config->domain1.hclk3_prescale |
		config->domain1.pclk3_prescale;
	
	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.cpu_mhz =  rcc_prediv_log_skip32_div(rcc_clock_tree.sysclk_mhz, 
		config->domain1.core_prescale >> RCC_D1CFGR_D1CPRE_SHIFT);
	
	rcc_clock_tree.hclk_mhz = rcc_prediv_log_skip32_div(rcc_clock_tree.cpu_mhz, 
		config->domain1.hclk3_prescale);
	
	rcc_clock_tree.per.pclk3_mhz = rcc_prediv_log_to_16(rcc_clock_tree.hclk_mhz, 
		config->domain1.pclk3_prescale >> RCC_D1CFGR_D1PPRE_SHIFT);
}

static void rcc_clock_setup_domain2(const struct rcc_pll_config *config) {
	RCC_D2CFGR &= RCC_D2CFGR_RSVD_BITMASK;
	RCC_D2CFGR |= config->domain2.pclk1_prescale | config->domain2.pclk2_prescale;
	
	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.per.pclk2_mhz = rcc_prediv_log_to_16(rcc_clock_tree.hclk_mhz, 
		config->domain2.pclk2_prescale >> RCC_D2CFGR_D2PPRE2_SHIFT);
	rcc_clock_tree.per.pclk1_mhz = rcc_prediv_log_to_16(rcc_clock_tree.hclk_mhz, 
		config->domain2.pclk1_prescale >> RCC_D2CFGR_D2PPRE1_SHIFT);
}

static void rcc_clock_setup_domain3(const struct rcc_pll_config *config) {
	RCC_D3CFGR &= RCC_D3CFGR_RSVD_BITMASK;
	RCC_D3CFGR |= config->domain3.pclk4_prescale;
	
	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.per.pclk4_mhz = rcc_prediv_log_to_16(rcc_clock_tree.hclk_mhz, 
		config->domain3.pclk4_prescale >> RCC_D3CFGR_D3PPRE_SHIFT);
}

void rcc_clock_setup_pll(const struct rcc_pll_config *config) {
	/* First, set system clock to utilize HSI, then disable all but HSI. */
	RCC_CR |= RCC_CR_HSION;
	RCC_CFGR &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_HSI);
	RCC_CR = RCC_CR_HSION;

	/* User has specified an external oscillator, make sure we turn it on. */
	if (config->hse_frequency > 0) {
		RCC_CR |= RCC_CR_HSEON;
		while (!(RCC_CR & RCC_CR_HSERDY));
	}

	/* Set, enable and lock all of the PLLs from the config. */
	rcc_set_and_enable_plls(config);

	/* Populate our base sysclk settings for use with domain clocks. */
	if (config->sysclk_mux == RCC_SYSCLK_PLL) {
		rcc_clock_tree.sysclk_mhz = rcc_clock_tree.pll[0].p_mhz;		
	} else if (config->sysclk_mux == RCC_SYSCLK_HSE) {
		rcc_clock_tree.sysclk_mhz = config->hse_frequency / ONEMILLION;
	} else {
		rcc_clock_tree.sysclk_mhz = HSI_BASE_FREQUENCY / ONEMILLION;
	}

	/* PLL's are set, now we need to get everything switched over the correct domains. */
	rcc_clock_setup_domain1(config);
	rcc_clock_setup_domain2(config);
	rcc_clock_setup_domain3(config);

	/* TODO: Configure custom kernel mappings. */

	/* Domains dividers are all configured, now we can switchover to PLL. */
	RCC_CFGR |= RCC_CFGR_SW_PLL1;
	uint32_t cfgr_sws = ((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK);
	while(cfgr_sws != RCC_CFGR_SWS_PLL1) {
		cfgr_sws = ((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK);
	}
}

uint32_t rcc_get_clock(enum rcc_clock_source source) {
	switch (source) {
		case RCC_SYSCLK:
			return rcc_clock_tree.sysclk_mhz * ONEMILLION;
		case RCC_CPUCLK:
		case RCC_SYSTICKCLK:
			return rcc_clock_tree.cpu_mhz * ONEMILLION;
		case RCC_AHBCLK:
		case RCC_HCLK3:
			return rcc_clock_tree.hclk_mhz * ONEMILLION;
		case RCC_PCLK1:
		case RCC_APB1CLK:
			return rcc_clock_tree.per.pclk1_mhz * ONEMILLION;
		case RCC_PCLK2:
		case RCC_APB2CLK:
			return rcc_clock_tree.per.pclk2_mhz * ONEMILLION;
		case RCC_PCLK3:
		case RCC_APB3CLK:
			return rcc_clock_tree.per.pclk3_mhz * ONEMILLION;
		case RCC_PCLK4:
		case RCC_APB4CLK:
			return rcc_clock_tree.per.pclk4_mhz * ONEMILLION;
		default:
			return 0U;
	}
}
