/** @defgroup ccm_file CCM
 *
 * @ingroup VF6xx
 *
 * @section vf6xx_ccm_api_ex Clock Controller Module API.
 *
 * @brief <b>VF6xx Clock Controller Module</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Stefan Agner <stefan@agner.ch>
 *
 * @date 30 Jun 2014
 *
 * This library supports the Clock Controller Module in the VF6xx SoCs
 * by Freescale.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#include <libopencm3/vf6xx/memorymap.h>
#include <libopencm3/vf6xx/ccm.h>
#include <libopencm3/vf6xx/anadig.h>

/**@{*/
static const uint32_t pll1_main_clk = 528000000;
static const uint32_t pll2_main_clk = 528000000;
static const uint32_t pll3_main_clk = 480000000;

/* ARM Cortex-A5 clock, core clock */
uint32_t ccm_core_clk = 0;

/* Platform bus clock and Cortex-M4 core clock */
uint32_t ccm_platform_bus_clk = 0;

/* IPS bus clock */
uint32_t ccm_ipg_bus_clk = 0;


uint32_t ccm_get_pll_pfd(uint32_t pfd_sel, uint32_t pll_pfd, uint32_t pll_clk);


/*---------------------------------------------------------------------------*/
/** @brief Enable clock of given device

This enables (gates) the clock for the given device.
@param[in] gr enum ccm_clock_gate. Device
*/
void ccm_clock_gate_enable(enum ccm_clock_gate gr)
{
	uint32_t offset = (uint32_t)gr / 16;
	uint32_t gr_mask = 0x3 << ((gr % 16) * 2);
	CCM_CCGR(offset * 4) |= gr_mask;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable clock of given device

This disables (ungates) the clock for the given device.
@param[in] gr enum ccm_clock_gate. Device
*/

void ccm_clock_gate_disable(enum ccm_clock_gate gr)
{
	uint32_t offset = (uint32_t)gr / 16;
	uint32_t gr_mask = 0x3 << ((gr % 16) * 2);
	CCM_CCGR(offset * 4) &= ~gr_mask;
}

/*---------------------------------------------------------------------------*/
/** @brief Calculate PFD clock

This function calculates the PFD clock for PLL1/2 or 3. All those PLLs
have the same PFD clock muxing/calculating logic, hence we can use one
function for all of them

@param[in] pfd_sel uint32_t. The PFD selection (muxing) value
@param[in] pll_pfd uint32_t. The ANADIG PFD register containing the fractions
for all possible PFDs
@param[in] pll_clk uint32_t. PLLs main clock (which the PFDs are derived from)
*/

uint32_t ccm_get_pll_pfd(uint32_t pfd_sel, uint32_t pll_pfd, uint32_t pll_clk)
{
	uint64_t pll_pfd_clk;
	uint32_t pll_pfd_frac = pll_pfd;

	switch (pfd_sel) {
	case CCM_CCSR_PLL_PFD_CLK_SEL_MAIN:
		return pll_clk;
	case CCM_CCSR_PLL_PFD_CLK_SEL_PFD1:
		pll_pfd_frac &= ANADIG_PLL_PFD1_FRAC_MASK;
		pll_pfd_frac >>= ANADIG_PLL_PFD1_FRAC_SHIFT;
		break;
	case CCM_CCSR_PLL_PFD_CLK_SEL_PFD2:
		pll_pfd_frac &= ANADIG_PLL_PFD2_FRAC_MASK;
		pll_pfd_frac >>= ANADIG_PLL_PFD2_FRAC_SHIFT;
		break;
	case CCM_CCSR_PLL_PFD_CLK_SEL_PFD3:
		pll_pfd_frac &= ANADIG_PLL_PFD3_FRAC_MASK;
		pll_pfd_frac >>= ANADIG_PLL_PFD3_FRAC_SHIFT;
		break;
	case CCM_CCSR_PLL_PFD_CLK_SEL_PFD4:
		pll_pfd_frac &= ANADIG_PLL_PFD4_FRAC_MASK;
		pll_pfd_frac >>= ANADIG_PLL_PFD4_FRAC_SHIFT;
		break;
	}

	/* Calculate using to PLL PFD fraction */
	pll_pfd_clk = pll_clk;
	pll_pfd_clk *= 18;
	pll_pfd_clk /= pll_pfd_frac;

	return (uint32_t)pll_pfd_clk;
}

/*---------------------------------------------------------------------------*/
/** @brief Calculate clocks

This function calculates the root clocks from the registers. On Vybrid, we
assume that the clocks/device is setup by the main operating system running
on the Cortex-A5 (for instance Linux). However, in order to calculate clocks
for peripherals its important to know the current value of those clocks.

This are mainly the @ref ccm_core_clk which the Cortex-A5 is running with
and lots of other clocks derive from.
The @ref ccm_platform_bus_clk is the clock which the Cortex-M4 is running
with.
And the @ref ccm_ipg_bus_clk is the clock most peripherals run with.

*/

void ccm_calculate_clocks()
{
	uint32_t ccsr = CCM_CCSR;
	uint32_t cacrr = CCM_CACRR;
	uint32_t arm_clk_div = (cacrr & CCM_CACRR_ARM_CLK_DIV_MASK) + 1;
	uint32_t bus_clk_div = cacrr & CCM_CACRR_BUS_CLK_DIV_MASK;
	uint32_t ipg_clk_div = cacrr & CCM_CACRR_IPG_CLK_DIV_MASK;
	uint32_t pll_pfd_sel;

	bus_clk_div >>= CCM_CACRR_BUS_CLK_DIV_SHIFT;
	bus_clk_div += 1;

	ipg_clk_div >>= CCM_CACRR_IPG_CLK_DIV_SHIFT;
	ipg_clk_div += 1;

	/* Get Cortex-A5 core clock from system clock selection */
	switch (ccsr & CCM_CCSR_SYS_CLK_SEL_MASK) {
	case CCM_CCSR_SYS_CLK_SEL_FAST:
		ccm_core_clk = 24000000;
		break;
	case CCM_CCSR_SYS_CLK_SEL_SLOW:
		ccm_core_clk = 32000;
		break;
	case CCM_CCSR_SYS_CLK_SEL_PLL2_PFD:
		pll_pfd_sel = ccsr & CCM_CCSR_PLL2_PFD_CLK_SEL_MASK;
		pll_pfd_sel >>= CCM_CCSR_PLL2_PFD_CLK_SEL_SHIFT;

		ccm_core_clk = ccm_get_pll_pfd(pll_pfd_sel, ANADIG_PLL2_PFD,
					       pll2_main_clk);
		break;
	case CCM_CCSR_SYS_CLK_SEL_PLL2:
		ccm_core_clk = pll2_main_clk;
		break;
	case CCM_CCSR_SYS_CLK_SEL_PLL1_PFD:
		pll_pfd_sel = ccsr & CCM_CCSR_PLL1_PFD_CLK_SEL_MASK;
		pll_pfd_sel >>= CCM_CCSR_PLL1_PFD_CLK_SEL_SHIFT;

		ccm_core_clk = ccm_get_pll_pfd(pll_pfd_sel, ANADIG_PLL1_PFD,
					       pll1_main_clk);
		break;
	case CCM_CCSR_SYS_CLK_SEL_PLL3:
		ccm_core_clk = pll3_main_clk;
		break;
	}

	ccm_core_clk /= arm_clk_div;
	ccm_platform_bus_clk = ccm_core_clk / bus_clk_div;
	ccm_ipg_bus_clk = ccm_platform_bus_clk / ipg_clk_div;

	return;
}

/**@}*/
