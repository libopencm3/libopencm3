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

#define HZ_PER_MHZ		 	1000000UL
#define HZ_PER_KHZ			1000UL

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
	struct {					/* Each PLL output set of data. */
		uint16_t p_mhz;
		uint16_t q_mhz;
		uint16_t r_mhz;
	} pll[4];					/* Note: PLL0 unimplemented. */
	uint16_t hse_khz;			/* This can't exceed 50MHz */
} rcc_clock_tree = {
	.sysclk_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ,
	.cpu_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ,
	.hclk_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ,
	.per.pclk1_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ,
	.per.pclk2_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ,
	.per.pclk3_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ,
	.per.pclk4_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ
};

static void rcc_set_and_enable_plls(const struct rcc_pll_config *config) {
	/* It is assumed that this function is entered with PLLs disabled and not
	 * running. Setup PLL1/2/3 with configurations specified in the config. */
	RCC_PLLCKSELR = RCC_PLLCKSELR_DIVM1(config->pll[1].divm) |
					RCC_PLLCKSELR_DIVM2(config->pll[2].divm) |
					RCC_PLLCKSELR_DIVM3(config->pll[3].divm) |
					config->pll_mux;

	RCC_PLLCFGR = 0;
	for (size_t i = 1; i <= 3; i++) {
		/* Only concern ourselves with the PLL if the input clock is enabled. */
		if (config->pll[i].divm == 0) {
			continue;
		}

		/* Let's write all of the dividers as specified. */
		RCC_PLLDIVR(i)  = 0;
		RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVN(config->pll[i].divn);

		/* Setup the PLL config values for this PLL. */
		uint8_t vco_addshift = 4 * i; 		/* Values spaced by 4 for PLL 1/2/3 */
		uint32_t clk = (config->pll_mux == RCC_PLL_HSI) ? RCC_HSI_BASE_FREQUENCY
			: config->hse_frequency;
		/* Set the PLL input frequency range. */
		uint32_t pll_clk_mhz = (clk / config->pll[i].divm) / HZ_PER_MHZ;
		if (pll_clk_mhz <= 2) {}	/* Do nothing, already masked to 0x00. */
		if (pll_clk_mhz > 2 && pll_clk_mhz <= 4) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_2_4MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
		} else if (pll_clk_mhz > 4 && pll_clk_mhz <= 8) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_4_8MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
		} else if (pll_clk_mhz > 8) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_8_16MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
		}

		/* Set the VCO output frequency range. */
		uint32_t pll_vco_clk_mhz = (pll_clk_mhz * config->pll[i].divn);
		if (pll_vco_clk_mhz <= 420) {
			RCC_PLLCFGR |= (RCC_PLLCFGR_PLL1VCO_MED << vco_addshift);
		}

		/* Setup the enable bits for the PLL outputs. */
		uint8_t diven_addshift = 3 * i;		/* Values spaced by 3 for PLL1/2/3 */
		if (config->pll[i].divp > 0) {
			RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVP(config->pll[i].divp);
			RCC_PLLCFGR |= (RCC_PLLCFGR_DIVP1EN << diven_addshift);
			rcc_clock_tree.pll[i].p_mhz = pll_vco_clk_mhz / config->pll[i].divp;
		}
		if (config->pll[i].divq > 0) {
			RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVQ(config->pll[i].divq);
			RCC_PLLCFGR |= (RCC_PLLCFGR_DIVQ1EN << diven_addshift);
			rcc_clock_tree.pll[i].q_mhz = pll_vco_clk_mhz / config->pll[i].divq;
		}
		if (config->pll[i].divr > 0) {
			RCC_PLLDIVR(i) |= RCC_PLLNDIVR_DIVR(config->pll[i].divr);
			RCC_PLLCFGR |= (RCC_PLLCFGR_DIVR1EN << diven_addshift);
			rcc_clock_tree.pll[i].r_mhz = pll_vco_clk_mhz / config->pll[i].divr;
		}

		/* Attempt to enable and lock PLL. */
		uint8_t cr_addshift = 2 * i;
		RCC_CR |= RCC_CR_PLL1ON << cr_addshift;
		while (!(RCC_CR & (RCC_CR_PLL1RDY << cr_addshift)));
	}
}

/* This is a helper to calculate dividers that go 2/4/8/16/64/128/256/512.
 * These dividers also use the top bit as an "enable". */
static uint16_t rcc_prediv_log_skip32_div(uint16_t clk_mhz, uint32_t div_val) {
	if (div_val < 0x8) {
		return clk_mhz;
	} else if (div_val <= RCC_D1CFGR_D1CPRE_DIV16) {
		return clk_mhz >> (div_val - 7);
	} else {
		return clk_mhz >> (div_val - 6);
	}
}

/* This is a helper to help calculate simple 3-bit log dividers with top bit
 * used as enable bit. */
static uint16_t rcc_prediv_3bit_log_div(uint16_t clk_mhz, uint32_t div_val) {
	if (div_val < 0x4) {
		return clk_mhz;
	} else {
		return clk_mhz >> (div_val - 3);
	}
}

static void rcc_clock_setup_domain1(const struct rcc_pll_config *config) {
	RCC_D1CFGR = 0;
	RCC_D1CFGR |= config->domain1.core_prescale | config->domain1.hclk3_prescale |
		config->domain1.pclk3_prescale;

	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.cpu_mhz =  rcc_prediv_log_skip32_div(rcc_clock_tree.sysclk_mhz,
		config->domain1.core_prescale >> RCC_D1CFGR_D1CPRE_SHIFT);

	rcc_clock_tree.hclk_mhz = rcc_prediv_log_skip32_div(rcc_clock_tree.cpu_mhz,
		config->domain1.hclk3_prescale);

	rcc_clock_tree.per.pclk3_mhz = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz,
		config->domain1.pclk3_prescale >> RCC_D1CFGR_D1PPRE_SHIFT);
}

static void rcc_clock_setup_domain2(const struct rcc_pll_config *config) {
	RCC_D2CFGR  = 0;
	RCC_D2CFGR |= config->domain2.pclk1_prescale | config->domain2.pclk2_prescale;

	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.per.pclk2_mhz = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz,
		config->domain2.pclk2_prescale >> RCC_D2CFGR_D2PPRE2_SHIFT);
	rcc_clock_tree.per.pclk1_mhz = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz,
		config->domain2.pclk1_prescale >> RCC_D2CFGR_D2PPRE1_SHIFT);
}

static void rcc_clock_setup_domain3(const struct rcc_pll_config *config) {
	RCC_D3CFGR &= 0;
	RCC_D3CFGR |= config->domain3.pclk4_prescale;

	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.per.pclk4_mhz = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz,
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
		rcc_clock_tree.hse_khz = config->hse_frequency / HZ_PER_KHZ;
	}

	/* Set, enable and lock all of the pll from the config. */
	rcc_set_and_enable_plls(config);

	/* Populate our base sysclk settings for use with domain clocks. */
	if (config->sysclk_mux == RCC_SYSCLK_PLL) {
		rcc_clock_tree.sysclk_mhz = rcc_clock_tree.pll[1].p_mhz;
	} else if (config->sysclk_mux == RCC_SYSCLK_HSE) {
		rcc_clock_tree.sysclk_mhz = config->hse_frequency / HZ_PER_MHZ;
	} else {
		rcc_clock_tree.sysclk_mhz = RCC_HSI_BASE_FREQUENCY / HZ_PER_MHZ;
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
	uint32_t clksel;
	switch (source) {
		case RCC_SYSCLK:
			return rcc_clock_tree.sysclk_mhz * HZ_PER_MHZ;
		case RCC_CPUCLK:
		case RCC_SYSTICKCLK:
			return rcc_clock_tree.cpu_mhz * HZ_PER_MHZ;
		case RCC_AHBCLK:
		case RCC_HCLK3:
			return rcc_clock_tree.hclk_mhz * HZ_PER_MHZ;
		case RCC_PCLK1:
		case RCC_APB1CLK:
			return rcc_clock_tree.per.pclk1_mhz * HZ_PER_MHZ;
		case RCC_PCLK2:
		case RCC_APB2CLK:
			return rcc_clock_tree.per.pclk2_mhz * HZ_PER_MHZ;
		case RCC_PCLK3:
		case RCC_APB3CLK:
			return rcc_clock_tree.per.pclk3_mhz * HZ_PER_MHZ;
		case RCC_PCLK4:
		case RCC_APB4CLK:
			return rcc_clock_tree.per.pclk4_mhz * HZ_PER_MHZ;
		case RCC_PERCLK:
			clksel = (RCC_D1CCIPR >> RCC_D1CCIPR_CKPERSEL_SHIFT) & RCC_D1CCIPR_CKPERSEL_MASK;
			if (clksel == RCC_D1CCIPR_CKPERSEL_HSI) {
				return RCC_HSI_BASE_FREQUENCY;
			} else if (clksel == RCC_D1CCIPR_CKPERSEL_HSE) {
				return rcc_clock_tree.hse_khz * HZ_PER_KHZ;
			} else {
				return 0U;
			}
		case RCC_FDCAN1CLK:
		case RCC_FDCAN2CLK:
			clksel = (RCC_D2CCIP1R >> RCC_D2CCIP1R_FDCANSEL_SHIFT) & RCC_D2CCIP1R_FDCANSEL_MASK;
			if (clksel == RCC_D2CCIP1R_FDCANSEL_HSE) {
				return rcc_clock_tree.hse_khz * HZ_PER_KHZ;
			} else if (clksel == RCC_D2CCIP1R_FDCANSEL_PLL1Q) {
				return rcc_clock_tree.pll[1].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP1R_FDCANSEL_PLL2Q) {
				return rcc_clock_tree.pll[2].q_mhz * HZ_PER_MHZ;
			} else {
				return 0U;
			}
		case RCC_SPI1CLK:
		case RCC_SPI2CLK:
		case RCC_SPI3CLK:
			clksel = (RCC_D2CCIP1R >> RCC_D2CCIP1R_SPI123SEL_SHIFT) & RCC_D2CCIP1R_SPI123SEL_MASK;
			if (clksel == RCC_D2CCIP1R_SPI123SEL_PLL1Q) {
				return rcc_clock_tree.pll[1].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP1R_SPI123SEL_PLL2P) {
				return rcc_clock_tree.pll[2].p_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP1R_SPI123SEL_PLL3P) {
				return rcc_clock_tree.pll[3].p_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP1R_SPI123SEL_PERCK) {
				return rcc_get_clock(RCC_PERCLK);
			} else {
				return 0U;
			}
		case RCC_SPI4CLK:
		case RCC_SPI5CLK:
			clksel = (RCC_D2CCIP1R >> RCC_D2CCIP1R_SPI45SEL_SHIFT) & RCC_D2CCIP1R_SPI45SEL_MASK;
			if (clksel == RCC_D2CCIP1R_SPI45SEL_APB4){
				return rcc_get_clock(RCC_PCLK1);
			} else if (clksel == RCC_D2CCIP1R_SPI45SEL_PLL2Q){
				return rcc_clock_tree.pll[2].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP1R_SPI45SEL_PLL3Q){
				return rcc_clock_tree.pll[3].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP1R_SPI45SEL_HSI){
				return RCC_HSI_BASE_FREQUENCY;
			} else if (clksel == RCC_D2CCIP1R_SPI45SEL_HSE) {
				return rcc_clock_tree.hse_khz * HZ_PER_KHZ;
			} else {
				return 0U;
			}
		case RCC_USART1CLK:
		case RCC_USART6CLK:
			clksel = (RCC_D2CCIP2R >> RCC_D2CCIP2R_USART16SEL_SHIFT) & RCC_D2CCIP2R_USARTSEL_MASK;
			if (clksel == RCC_D2CCIP2R_USART16SEL_PCLK2) {
				return rcc_get_clock(RCC_PCLK2);
			} else if (clksel == RCC_D2CCIP2R_USARTSEL_PLL2Q) {
				return rcc_clock_tree.pll[2].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP2R_USARTSEL_PLL3Q) {
				return rcc_clock_tree.pll[3].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP2R_USARTSEL_HSI) {
				return RCC_HSI_BASE_FREQUENCY;
			} else {
				return 0U;
			}
		case RCC_USART2CLK:
		case RCC_USART3CLK:
		case RCC_USART4CLK:
		case RCC_USART5CLK:
		case RCC_USART7CLK:
		case RCC_USART8CLK:
			clksel = (RCC_D2CCIP2R >> RCC_D2CCIP2R_USART234578SEL_SHIFT) & RCC_D2CCIP2R_USARTSEL_MASK;
			if (clksel == RCC_D2CCIP2R_USART234578SEL_PCLK1) {
				return rcc_get_clock(RCC_PCLK1);
			} else if (clksel == RCC_D2CCIP2R_USARTSEL_PLL2Q) {
				return rcc_clock_tree.pll[2].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP2R_USARTSEL_PLL3Q) {
				return rcc_clock_tree.pll[3].q_mhz * HZ_PER_MHZ;
			} else if (clksel == RCC_D2CCIP2R_USARTSEL_HSI) {
				return RCC_HSI_BASE_FREQUENCY;
			} else {
				return 0U;
			}
		default:
			return 0U;
	}
}

void rcc_set_fdcan_clksel(uint8_t clksel) {
	RCC_D2CCIP1R &= ~(RCC_D2CCIP1R_FDCANSEL_MASK << RCC_D2CCIP1R_FDCANSEL_SHIFT);
	RCC_D2CCIP1R |= clksel << RCC_D2CCIP1R_FDCANSEL_SHIFT;
}

void rcc_set_spi123_clksel(uint8_t clksel) {
	RCC_D2CCIP1R &= ~(RCC_D2CCIP1R_SPI123SEL_MASK << RCC_D2CCIP1R_SPI123SEL_SHIFT);
	RCC_D2CCIP1R |= clksel << RCC_D2CCIP1R_SPI123SEL_SHIFT;
}

void rcc_set_spi45_clksel(uint8_t clksel) {
	RCC_D2CCIP1R &= ~(RCC_D2CCIP1R_SPI45SEL_MASK << RCC_D2CCIP1R_SPI45SEL_SHIFT);
	RCC_D2CCIP1R |= clksel << RCC_D2CCIP1R_SPI45SEL_SHIFT;
}

