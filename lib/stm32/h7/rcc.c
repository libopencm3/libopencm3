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
	struct pll_clocks {			/* Each PLL output set of data. */
		uint16_t p_mhz;
		uint16_t q_mhz;
		uint16_t r_mhz;
	} pll1, pll2, pll3;
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

static void rcc_configure_pll(uint32_t clkin, const struct pll_config *config, int pll_num) {
	/* Only concern ourselves with the PLL if the input clock is enabled. */
	if (config->divm == 0 || pll_num < 1 || pll_num > 3) {
		return;
	}

	struct pll_clocks *pll_tree_ptr;
	if (pll_num == 1) {
		pll_tree_ptr = &rcc_clock_tree.pll1;
	} else if (pll_num == 2) {
		pll_tree_ptr = &rcc_clock_tree.pll2;
	} else {
		pll_tree_ptr = &rcc_clock_tree.pll3;
	}

	/* Let's write all of the dividers as specified. */
	RCC_PLLDIVR(pll_num)  = 0;
	RCC_PLLDIVR(pll_num) |= RCC_PLLNDIVR_DIVN(config->divn);

	/* Setup the PLL config values for this PLL. */
	uint8_t vco_addshift = 4 * (pll_num - 1); 		/* Values spaced by 4 for PLL 1/2/3 */

	/* Set the PLL input frequency range. */
	uint32_t pll_clk_mhz = (clkin / config->divm) / HZ_PER_MHZ;
	if (pll_clk_mhz > 2 && pll_clk_mhz <= 4) {
		RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_2_4MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
	} else if (pll_clk_mhz > 4 && pll_clk_mhz <= 8) {
		RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_4_8MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
	} else if (pll_clk_mhz > 8) {
		RCC_PLLCFGR |= (RCC_PLLCFGR_PLLRGE_8_16MHZ << RCC_PLLCFGR_PLL1RGE_SHIFT) << vco_addshift;
	}

	/* Set the VCO output frequency range. */
	uint32_t pll_vco_clk_mhz = (pll_clk_mhz * config->divn);
	if (pll_vco_clk_mhz <= 420) {
		RCC_PLLCFGR |= (RCC_PLLCFGR_PLL1VCO_MED << vco_addshift);
	}

	/* Setup the enable bits for the PLL outputs. */
	uint8_t diven_addshift = 3 * (pll_num - 1);		/* Values spaced by 3 for PLL1/2/3 */
	if (config->divp > 0) {
		RCC_PLLDIVR(pll_num) |= RCC_PLLNDIVR_DIVP(config->divp);
		RCC_PLLCFGR |= (RCC_PLLCFGR_DIVP1EN << diven_addshift);
		pll_tree_ptr->p_mhz = pll_vco_clk_mhz / config->divp;
	}
	if (config->divq > 0) {
		RCC_PLLDIVR(pll_num) |= RCC_PLLNDIVR_DIVQ(config->divq);
		RCC_PLLCFGR |= (RCC_PLLCFGR_DIVQ1EN << diven_addshift);
		pll_tree_ptr->q_mhz = pll_vco_clk_mhz / config->divq;
	}
	if (config->divr > 0) {
		RCC_PLLDIVR(pll_num) |= RCC_PLLNDIVR_DIVR(config->divr);
		RCC_PLLCFGR |= (RCC_PLLCFGR_DIVR1EN << diven_addshift);
		pll_tree_ptr->r_mhz = pll_vco_clk_mhz / config->divr;
	}

	/* Attempt to enable and lock PLL. */
	uint8_t cr_addshift = 2 * (pll_num - 1);
	RCC_CR |= RCC_CR_PLL1ON << cr_addshift;
	while (!(RCC_CR & (RCC_CR_PLL1RDY << cr_addshift)));
}

static void rcc_set_and_enable_plls(const struct rcc_pll_config *config) {
	/* It is assumed that this function is entered with PLLs disabled and not
	 * running. Setup PLL1/2/3 with configurations specified in the config. */
	RCC_PLLCKSELR = RCC_PLLCKSELR_DIVM1(config->pll1.divm) |
					RCC_PLLCKSELR_DIVM2(config->pll2.divm) |
					RCC_PLLCKSELR_DIVM3(config->pll3.divm) |
					config->pll_source;

	uint32_t clkin = (config->pll_source == RCC_PLLCKSELR_PLLSRC_HSI)
		? RCC_HSI_BASE_FREQUENCY : config->hse_frequency;

	RCC_PLLCFGR = 0;
	rcc_configure_pll(clkin, &config->pll1, 1);
	rcc_configure_pll(clkin, &config->pll2, 2);
	rcc_configure_pll(clkin, &config->pll3, 3);
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
	RCC_D1CFGR |= RCC_D1CFGR_D1CPRE(config->core_pre)  |
		RCC_D1CFGR_D1HPRE(config->hpre) | RCC_D1CFGR_D1PPRE(config->ppre3);

	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.cpu_mhz =
		rcc_prediv_log_skip32_div(rcc_clock_tree.sysclk_mhz, config->core_pre);
	rcc_clock_tree.hclk_mhz =
		rcc_prediv_log_skip32_div(rcc_clock_tree.cpu_mhz, config->hpre);
	rcc_clock_tree.per.pclk3_mhz =
		rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz, config->ppre3);
}

static void rcc_clock_setup_domain2(const struct rcc_pll_config *config) {
	RCC_D2CFGR  = 0;
	RCC_D2CFGR |= RCC_D2CFGR_D2PPRE1(config->ppre1) |
		RCC_D2CFGR_D2PPRE2(config->ppre2);

	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.per.pclk2_mhz =
		rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz, config->ppre2);
	rcc_clock_tree.per.pclk1_mhz =
		rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz, config->ppre1);
}

static void rcc_clock_setup_domain3(const struct rcc_pll_config *config) {
	RCC_D3CFGR &= 0;
	RCC_D3CFGR |= RCC_D3CFGR_D3PPRE(config->ppre4);

	/* Update our clock values in our tree based on the config values. */
	rcc_clock_tree.per.pclk4_mhz =
		rcc_prediv_3bit_log_div(rcc_clock_tree.hclk_mhz, config->ppre4);
}

void rcc_clock_setup_pll(const struct rcc_pll_config *config) {
	/* First, set system clock to utilize HSI, then disable all but HSI. */
	RCC_CR |= RCC_CR_HSION;
	RCC_CFGR &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_HSI);
	RCC_CR = RCC_CR_HSION;

	/* Now that we're safely running on HSI, let's setup the LDO. */
	pwr_set_mode_ldo();
	pwr_set_vos_scale(config->voltage_scale);

	/* Set flash waitstates. Enable flash prefetch if we have at least 1WS */
	flash_set_ws(config->flash_waitstates);
	if (config->flash_waitstates > FLASH_ACR_LATENCY_0WS) {
		flash_prefetch_enable();
	} else {
		flash_prefetch_disable();
	}

	/* User has specified an external oscillator, make sure we turn it on. */
	if (config->hse_frequency > 0) {
		RCC_CR |= RCC_CR_HSEON;
		while (!(RCC_CR & RCC_CR_HSERDY));
		rcc_clock_tree.hse_khz = config->hse_frequency / HZ_PER_KHZ;
	}

	/* Set, enable and lock all of the pll from the config. */
	rcc_set_and_enable_plls(config);

	/* Populate our base sysclk settings for use with domain clocks. */
	if (config->sysclock_source == RCC_PLL) {
		rcc_clock_tree.sysclk_mhz = rcc_clock_tree.pll1.p_mhz;
	} else if (config->sysclock_source == RCC_HSE) {
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

uint32_t rcc_get_bus_clk_freq(enum rcc_clock_source source) {
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
		case RCC_APB1CLK:
			return rcc_clock_tree.per.pclk1_mhz * HZ_PER_MHZ;
		case RCC_APB2CLK:
			return rcc_clock_tree.per.pclk2_mhz * HZ_PER_MHZ;
		case RCC_APB3CLK:
			return rcc_clock_tree.per.pclk3_mhz * HZ_PER_MHZ;
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
		default:
			cm3_assert_not_reached();
			return 0U;
	}
}

uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	uint32_t clksel, pclk;
	if (usart == USART1_BASE || usart == USART6_BASE) {
		pclk = rcc_clock_tree.per.pclk2_mhz * HZ_PER_MHZ;;
		clksel = (RCC_D2CCIP2R >> RCC_D2CCIP2R_USART16SEL_SHIFT) & RCC_D2CCIP2R_USARTSEL_MASK;
	} else {
		pclk = rcc_clock_tree.per.pclk1_mhz * HZ_PER_MHZ;
		clksel = (RCC_D2CCIP2R >> RCC_D2CCIP2R_USART234578SEL_SHIFT) & RCC_D2CCIP2R_USARTSEL_MASK;
	}

	/* Based on extracted clksel value, return the clock. */
	if (clksel == RCC_D2CCIP2R_USARTSEL_PCLK) {
		return pclk;
	} else if (clksel == RCC_D2CCIP2R_USARTSEL_PLL2Q) {
		return rcc_clock_tree.pll2.q_mhz * HZ_PER_MHZ;
	} else if (clksel == RCC_D2CCIP2R_USARTSEL_PLL3Q) {
		return rcc_clock_tree.pll3.q_mhz * HZ_PER_MHZ;
	} else if (clksel == RCC_D2CCIP2R_USARTSEL_HSI) {
		return RCC_HSI_BASE_FREQUENCY;
	} else {
		return 0U;
	}
}

uint32_t rcc_get_timer_clk_freq(uint32_t timer __attribute__((unused)))
{
	if (timer >= LPTIM2_BASE && timer <= LPTIM5_BASE) {
		/* TODO: Read LPTIMxSEL values from D3CCIPR to determine clock source. */
		return rcc_clock_tree.per.pclk4_mhz * HZ_PER_MHZ;
	} else if (timer >= TIM1_BASE && timer <= HRTIM_BASE) {
		return rcc_clock_tree.per.pclk2_mhz * HZ_PER_MHZ;
	} else {
		return rcc_clock_tree.per.pclk1_mhz * HZ_PER_MHZ;
	}
}

uint32_t rcc_get_i2c_clk_freq(uint32_t i2c)
{
	if (i2c == I2C4_BASE) {
		/* TODO: Read I2C4SEL from D3CCIPR to determine clock source. */
		return rcc_clock_tree.per.pclk3_mhz * HZ_PER_MHZ;
	} else {
		/* TODO: Read I2C123SEL from D2CCIP2R to determine clock source. */
		return rcc_clock_tree.per.pclk1_mhz * HZ_PER_MHZ;
	}
}

uint32_t rcc_get_spi_clk_freq(uint32_t spi)
{
	if (spi == SPI4_BASE || spi == SPI5_BASE) {
		uint32_t clksel =
			(RCC_D2CCIP1R >> RCC_D2CCIP1R_SPI45SEL_SHIFT) & RCC_D2CCIP1R_SPI45SEL_MASK;
		if (clksel == RCC_D2CCIP1R_SPI45SEL_APB4){
			return rcc_clock_tree.per.pclk2_mhz * HZ_PER_MHZ;
		} else if (clksel == RCC_D2CCIP1R_SPI45SEL_PLL2Q){
			return rcc_clock_tree.pll2.q_mhz * HZ_PER_MHZ;
		} else if (clksel == RCC_D2CCIP1R_SPI45SEL_PLL3Q){
			return rcc_clock_tree.pll3.q_mhz * HZ_PER_MHZ;
		} else if (clksel == RCC_D2CCIP1R_SPI45SEL_HSI){
			return RCC_HSI_BASE_FREQUENCY;
		} else if (clksel == RCC_D2CCIP1R_SPI45SEL_HSE) {
			return rcc_clock_tree.hse_khz * HZ_PER_KHZ;
		} else {
			return 0U;
		}
	} else {
		uint32_t clksel =
			(RCC_D2CCIP1R >> RCC_D2CCIP1R_SPI123SEL_SHIFT) & RCC_D2CCIP1R_SPI123SEL_MASK;
		if (clksel == RCC_D2CCIP1R_SPI123SEL_PLL1Q) {
			return rcc_clock_tree.pll1.q_mhz * HZ_PER_MHZ;
		} else if (clksel == RCC_D2CCIP1R_SPI123SEL_PLL2P) {
			return rcc_clock_tree.pll2.p_mhz * HZ_PER_MHZ;
		} else if (clksel == RCC_D2CCIP1R_SPI123SEL_PLL3P) {
			return rcc_clock_tree.pll3.p_mhz * HZ_PER_MHZ;
		} else if (clksel == RCC_D2CCIP1R_SPI123SEL_PERCK) {
			return rcc_get_bus_clk_freq(RCC_PERCLK);
		} else {
			return 0U;
		}
	}
}

uint32_t rcc_get_fdcan_clk_freq(uint32_t fdcan __attribute__((unused)))
{
	uint32_t clksel =
		(RCC_D2CCIP1R >> RCC_D2CCIP1R_FDCANSEL_SHIFT) & RCC_D2CCIP1R_FDCANSEL_MASK;
	if (clksel == RCC_D2CCIP1R_FDCANSEL_HSE) {
		return rcc_clock_tree.hse_khz * HZ_PER_KHZ;
	} else if (clksel == RCC_D2CCIP1R_FDCANSEL_PLL1Q) {
		return rcc_clock_tree.pll1.q_mhz * HZ_PER_MHZ;
	} else if (clksel == RCC_D2CCIP1R_FDCANSEL_PLL2Q) {
		return rcc_clock_tree.pll2.q_mhz * HZ_PER_MHZ;
	} else {
		return 0U;
	}
}

void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel) {
	volatile uint32_t *reg;
	uint32_t mask;
	uint32_t val;

	switch (periph) {
		case FDCAN1_BASE:
		case FDCAN2_BASE:
			reg = &RCC_D2CCIP1R;
			mask = RCC_D2CCIP1R_FDCANSEL_MASK << RCC_D2CCIP1R_FDCANSEL_SHIFT;
			val = sel << RCC_D2CCIP1R_FDCANSEL_SHIFT;
			break;
		case RNG_BASE:
		  reg = &RCC_D2CCIP2R;
		  mask = RCC_D2CCIP2R_RNGSEL_MASK << RCC_D2CCIP2R_RNGSEL_SHIFT;
		  val = sel << RCC_D2CCIP2R_RNGSEL_SHIFT;
		  break;
		case SPI1_BASE:
		case SPI2_BASE:
		case SPI3_BASE:
			reg = &RCC_D2CCIP2R;
			mask = RCC_D2CCIP1R_SPI123SEL_MASK << RCC_D2CCIP1R_SPI123SEL_SHIFT;
			val = sel << RCC_D2CCIP1R_SPI123SEL_SHIFT;
			break;
		case SPI4_BASE:
		case SPI5_BASE:
			reg = &RCC_D2CCIP1R;
			mask = RCC_D2CCIP1R_SPI45SEL_MASK << RCC_D2CCIP1R_SPI45SEL_SHIFT;
			val = sel << RCC_D2CCIP1R_SPI45SEL_SHIFT;
			break;
		case USART1_BASE:
		case USART6_BASE:
			reg = &RCC_D2CCIP2R;
			mask = RCC_D2CCIP2R_USARTSEL_MASK << RCC_D2CCIP2R_USART16SEL_SHIFT;
			val = sel << RCC_D2CCIP2R_USART16SEL_SHIFT;
			break;
		case USART2_BASE:
		case USART3_BASE:
		case UART4_BASE:
		case UART5_BASE:
		case UART7_BASE:
		case UART8_BASE:
			reg = &RCC_D2CCIP2R;
			mask = RCC_D2CCIP2R_USARTSEL_MASK << RCC_D2CCIP2R_USART234578SEL_SHIFT;
			val = sel << RCC_D2CCIP2R_USART234578SEL_SHIFT;
			break;

		default:
			cm3_assert_not_reached();
			return;
	}

	// Update the register value by masking and oring in new values.
	uint32_t regval = (*reg & mask) | val;
	*reg = regval;
}

void rcc_set_fdcan_clksel(uint8_t clksel) {
	RCC_D2CCIP1R &= ~(RCC_D2CCIP1R_FDCANSEL_MASK << RCC_D2CCIP1R_FDCANSEL_SHIFT);
	RCC_D2CCIP1R |= clksel << RCC_D2CCIP1R_FDCANSEL_SHIFT;
}

void rcc_set_rng_clksel(uint8_t clksel) {
	RCC_D2CCIP2R &= ~(RCC_D2CCIP2R_RNGSEL_MASK << RCC_D2CCIP2R_RNGSEL_SHIFT);
	RCC_D2CCIP2R |= clksel << RCC_D2CCIP2R_RNGSEL_SHIFT;
}

void rcc_set_spi123_clksel(uint8_t clksel) {
	RCC_D2CCIP1R &= ~(RCC_D2CCIP1R_SPI123SEL_MASK << RCC_D2CCIP1R_SPI123SEL_SHIFT);
	RCC_D2CCIP1R |= clksel << RCC_D2CCIP1R_SPI123SEL_SHIFT;
}

void rcc_set_spi45_clksel(uint8_t clksel) {
	RCC_D2CCIP1R &= ~(RCC_D2CCIP1R_SPI45SEL_MASK << RCC_D2CCIP1R_SPI45SEL_SHIFT);
	RCC_D2CCIP1R |= clksel << RCC_D2CCIP1R_SPI45SEL_SHIFT;
}
