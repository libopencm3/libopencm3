/**
 * @brief <b>PAC55xxxx CCS Driver</b>
 * @author @htmlonly &copy; @endhtmlonly 2020 Kevin Stefanik <kevin@allocor.tech>
 * @date March 7, 2020
 *
 * This library supports the CCS module in the PAC55xx SoC from Qorvo.
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
#include <libopencm3/pac55xx/ccs.h>
#include <libopencm3/pac55xx/memorymap.h>
#include <libopencm3/pac55xx/memctl.h>
#include <libopencm3/cm3/assert.h>

static volatile uint32_t ccs_extclk_frequency = 0;
static volatile uint32_t ccs_frclk_frequency = CCS_ROSC_FREQ;
static volatile uint32_t ccs_sclk_frequency = CCS_ROSC_FREQ;
static volatile uint32_t ccs_pll_clk_frequency = 0;
static volatile uint32_t ccs_hclk_frequency = CCS_ROSC_FREQ;
static volatile uint32_t ccs_aclk_frequency = CCS_ROSC_FREQ;
static volatile uint32_t ccs_pclk_frequency = CCS_ROSC_FREQ;

void ccs_frclkmux_select(uint32_t sel) {
	CCSCTL = (CCSCTL & ~CCS_CTL_FRCLKMUXSEL(CCS_CTL_FRCLKMUXSEL_MASK)) | CCS_CTL_FRCLKMUXSEL(sel);
}
void ccs_rosc_enable(void) {
	CCSCTL |= CCS_CTL_ROSCEN;
}
void ccs_rosc_disable(void) {
	CCSCTL &= ~CCS_CTL_ROSCEN;
}
void ccs_sclkmux_select_frclk(void) {
	CCSCTL &= ~CCS_CTL_SCLKMUXSEL;
}
void ccs_sclkmux_select_pllclk(void) {
	CCSCTL |= CCS_CTL_SCLKMUXSEL;
}
void ccs_clkfail_enable(void) {
	CCSCTL |= CCS_CTL_CLKFAILEN;
}
void ccs_clkfail_disable(void) {
	CCSCTL &= ~CCS_CTL_CLKFAILEN;
}
void ccs_clkfailmux_select_frclk(void) {
	CCSCTL &= ~CCS_CTL_CLKFAILMUXSEL;
}
void ccs_clkfailmux_select_pllclk(void) {
	CCSCTL |= CCS_CTL_CLKFAILMUXSEL;
}
void ccs_ldo_enable(void) {
	CCSCTL |= CCS_CTL_LDOEN;
}
void ccs_ldo_disable(void) {
	CCSCTL &= ~CCS_CTL_LDOEN;
}
void ccs_pclk_enable(void) {
	CCSCTL |= CCS_CTL_PCLKEN;
}
void ccs_pclk_disable(void) {
	CCSCTL &= ~CCS_CTL_PCLKEN;
}
void ccs_aclk_enable(void) {
	CCSCTL |= CCS_CTL_ACLKEN;
}
void ccs_aclk_disable(void) {
	CCSCTL &= ~CCS_CTL_ACLKEN;
}
void ccs_adcclk_enable(void) {
	CCSCTL |= CCS_CTL_ADCCLKEN;
}
void ccs_adcclk_disable(void) {
	CCSCTL &= ~CCS_CTL_ADCCLKEN;
}
void ccs_stclk_sleep_enable(void) {
	CCSCTL |= CCS_CTL_STCLKSLPEN;
}
void ccs_stclk_sleep_disable(void) {
	CCSCTL &= ~CCS_CTL_STCLKSLPEN;
}
void ccs_set_pclkdiv(uint32_t div) {
	CCSCTL = (CCSCTL & ~CCS_CTL_PCLKDIV(8)) | CCS_CTL_PCLKDIV(div);
}
void ccs_set_aclkdiv(uint32_t div) {
	CCSCTL = (CCSCTL & ~CCS_CTL_ACLKDIV(8)) | CCS_CTL_ACLKDIV(div);
}
void ccs_set_hclkdiv(uint32_t div) {
	CCSCTL = (CCSCTL & ~CCS_CTL_HCLKDIV(8)) | CCS_CTL_HCLKDIV(div);
}
void ccs_pll_enable(void) {
	CCSPLLCTL |= CCS_PLLCTL_PLLEN;
}
void ccs_pll_disable(void) {
	CCSPLLCTL &= ~CCS_PLLCTL_PLLEN;
}
bool ccs_pll_locked(void) {
	return (CCSPLLCTL & CCS_PLLCTL_PLLLOCK) == CCS_PLLCTL_PLLLOCK;
}
void ccs_pll_bypass_enable(void) {
	CCSPLLCTL |= CCS_PLLCTL_PLLBP;
}
void ccs_pll_bypass_disable(void) {
	CCSPLLCTL &= ~CCS_PLLCTL_PLLBP;
}
void ccs_pll_set_outdiv(uint32_t div) {
	CCSPLLCTL = (CCSPLLCTL & ~CCS_PLLCTL_PLLOUTDIV(CCS_PLLCTL_PLLOUTDIV_MASK)) | CCS_PLLCTL_PLLOUTDIV(div);
}
void ccs_pll_set_indiv(uint32_t div) {
	if (div <= 15 && div >= 1) {
		CCSPLLCTL = (CCSPLLCTL & ~CCS_PLLCTL_PLLINDIV(CCS_PLLCTL_PLLINDIV_MASK)) | CCS_PLLCTL_PLLINDIV(div);
	} else {
		cm3_assert_not_reached();
	}
}
void ccs_pll_set_fbdiv(uint32_t div) {
	if (div <= 16383 && div >= 4) {
		CCSPLLCTL = (CCSPLLCTL & ~CCS_PLLCTL_PLLFBDIV(CCS_PLLCTL_PLLFBDIV_MASK)) | CCS_PLLCTL_PLLFBDIV(div);
	} else {
		cm3_assert_not_reached();
	}
}
void css_pll_config_enable(uint32_t indiv, uint32_t fbdiv, uint32_t outdiv) {
	ccs_pll_disable();
	ccs_pll_set_fbdiv(fbdiv);
	ccs_pll_set_outdiv(outdiv);
	ccs_pll_set_indiv(indiv);
	ccs_pll_enable();
	while (!ccs_pll_locked()) ; /* Wait for PLL lock ~500us */
}

void ccs_reset_clocks(void) {
	CCSCTL = CCS_CTL_LDOEN | CCS_CTL_ROSCEN |
			CCS_CTL_PCLKEN | CCS_CTL_ACLKEN |
			CCS_CTL_ADCCLKEN | CCS_CTL_STCLKSLPEN;
	CCSPLLCTL = 0;
}

void ccs_configure_clocks(const struct ccs_clk_config *config) {
	MEMCTL_FLASHLOCK = MEMCTL_FLASHLOCK_ALLOW_MEMCTL_WRITE;

	ccs_reset_clocks();  /* set safe defaults */
	ccs_frclkmux_select(CCS_CTL_FRCLKMUXSEL_ROSC);
	ccs_sclkmux_select_frclk();
	memctl_flash_select_roscclk();

	if (config->mem_enable_cache) {
		memctl_flash_cache_enable();
	} else {
		memctl_flash_cache_disable();
	}

	ccs_frclkmux_select(CCS_CTL_FRCLKMUXSEL_CLKREF); /* switch frclk to 4MHz CLKREF */

	switch (config->frclk_source) {
		case CCS_CTL_FRCLKMUXSEL_ROSC:
			ccs_frclkmux_select(CCS_CTL_FRCLKMUXSEL_ROSC);
			ccs_frclk_frequency = CCS_ROSC_FREQ;
			break;
		case CCS_CTL_FRCLKMUXSEL_CLKREF:
			ccs_frclkmux_select(CCS_CTL_FRCLKMUXSEL_CLKREF);
			ccs_frclk_frequency = CCS_CLKREF_FREQ;
			break;
		case CCS_CTL_FRCLKMUXSEL_EXTCLK:
			if (config->extclk_frequency > CCS_EXTCLK_MAX_FREQ
					|| config->extclk_frequency == 0) {
				cm3_assert_not_reached();
			}
			ccs_frclkmux_select(CCS_CTL_FRCLKMUXSEL_EXTCLK);
			ccs_frclk_frequency = ccs_extclk_frequency = config->extclk_frequency;
			break;
		default:
			cm3_assert_not_reached();
	}

	if (config->sclk_source == CCS_CTL_SCLKMUXSEL_FRCLK) {
		ccs_set_hclkdiv(config->hclkdiv);
		ccs_set_aclkdiv(config->aclkdiv);
		memctl_flash_set_wstate(config->mem_wstate);
		ccs_sclkmux_select_frclk();
		memctl_flash_set_mclkdiv(config->mem_mclkdiv);
		if (config->mem_mclksel == false) {
			memctl_flash_select_roscclk();
		} else {
			memctl_flash_select_mclk();
		}
		ccs_sclk_frequency = ccs_frclk_frequency;
	} else if (config->sclk_source == CCS_CTL_SCLKMUXSEL_PLLCLK) {
		css_pll_config_enable(config->pll_indiv, config->pll_fbdiv, config->pll_outdiv);
		ccs_set_hclkdiv(config->hclkdiv);
		ccs_set_aclkdiv(config->aclkdiv);
		memctl_flash_set_wstate(config->mem_wstate);
		ccs_sclkmux_select_pllclk();
		memctl_flash_set_mclkdiv(config->mem_mclkdiv);
		if (config->mem_mclksel == false) {
			memctl_flash_select_roscclk();
		} else {
			memctl_flash_select_mclk();
		}
		ccs_pll_clk_frequency = ((ccs_frclk_frequency * config->pll_fbdiv) / config->pll_indiv) >> config->pll_outdiv;
		ccs_sclk_frequency = ccs_pll_clk_frequency;
	} else {
		cm3_assert_not_reached();
	}
	ccs_set_pclkdiv(config->pclkdiv);
	ccs_pclk_enable();
	ccs_aclk_enable();
	ccs_adcclk_enable();
	ccs_stclk_sleep_disable();

	ccs_hclk_frequency = ccs_sclk_frequency / (config->hclkdiv + 1);
	ccs_aclk_frequency = ccs_sclk_frequency / (config->aclkdiv + 1);
	ccs_pclk_frequency = ccs_hclk_frequency / (config->pclkdiv + 1);

	MEMCTL_FLASHLOCK = MEMCTL_FLASHLOCK_CLEAR;
}

uint32_t ccs_get_extclk_frequency(void) { return ccs_extclk_frequency; }
uint32_t ccs_get_frclk_frequency(void) { return ccs_frclk_frequency; }
uint32_t ccs_get_sclk_frequency(void) { return ccs_sclk_frequency; }
uint32_t ccs_get_pllclk_frequency(void) { return ccs_pll_clk_frequency; }
uint32_t ccs_get_hclk_frequency(void) { return ccs_hclk_frequency; }
uint32_t ccs_get_aclk_frequency(void) { return ccs_aclk_frequency; }
uint32_t ccs_get_pclk_frequency(void) { return ccs_pclk_frequency; }

uint32_t ccs_get_adc_clk_freq(uint32_t adc __attribute__((unused))) { return ccs_sclk_frequency; }
uint32_t ccs_get_i2c_clk_freq(uint32_t i2c __attribute__((unused))) { return ccs_pclk_frequency; }
uint32_t ccs_get_usart_clk_freq(uint32_t usart __attribute__((unused))) { return ccs_pclk_frequency; }
uint32_t ccs_get_can_clk_freq(uint32_t can __attribute__((unused))) { return ccs_pclk_frequency; }
uint32_t ccs_get_gptimer_clk_freq(uint32_t gptimer __attribute__((unused))) { return ccs_pclk_frequency; }
uint32_t ccs_get_timer_clk_freq(uint32_t timer) {
	if ((MMIO32(timer) & BIT9) == 0) {
		return ccs_pclk_frequency;
	}
	return ccs_aclk_frequency;
}
uint32_t ccs_get_memctl_clk_freq(uint32_t memctl) {
	if ((MMIO32(memctl) & BIT22) == 0) {
		return CCS_ROSC_FREQ;
	}
	return ccs_hclk_frequency;
}
uint32_t ccs_get_wwdt_clk_freq(uint32_t wwdt) {
	if ((MMIO32(wwdt) & BIT3) == 0) {
		return ccs_frclk_frequency;
	}
	return CCS_ROSC_FREQ;
}
uint32_t ccs_get_rtc_clk_freq(uint32_t rtc __attribute__((unused))) { return ccs_frclk_frequency; }
uint32_t ccs_get_crc_clk_freq(uint32_t crc __attribute__((unused))) { return ccs_hclk_frequency; }
uint32_t ccs_get_systick_clk_freq(uint32_t systick __attribute__((unused))) { return ccs_hclk_frequency; }
