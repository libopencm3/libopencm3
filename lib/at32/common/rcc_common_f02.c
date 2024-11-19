/** @addtogroup rcc_file RCC peripheral API
@ingroup peripheral_apis

This library contains common part of the Reset and Clock Control System
in the AT32F4xx series of ARM Cortex Microcontrollers by Arterytek.
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllsrc PLL clock source @ref rcc_cfgr_pcs
*/

void rcc_set_pll_source(uint32_t pllsrc)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLSRC) |
		(pllsrc ? RCC_CFGR_PLLSRC : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLMUL) |
		((mul & 0x70) << (RCC_CFGR_PLLMULHI_SHIFT - 4)) |
		((mul & 0x0f) << RCC_CFGR_PLLMUL_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC HSE Frequency Divider.

@param[in] xtpre Puts HSE clock thru divider before PLL @ref rcc_cfgr_pllxtpre
*/

void rcc_set_hse_xtpre(uint32_t xtpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLXTPRE) |
		(xtpre ? RCC_CFGR_PLLXTPRE : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Setup the A/D Clock

The ADC's have a common clock prescale setting.

@param[in] adcpre Prescale divider taken from @ref rcc_cfgr_adcpre
*/

void rcc_set_adcpre(uint32_t adcpre)
{
	RCC_CFGR = (RCC_CFGR & ~(RCC_CFGR_ADCPRE2 | RCC_CFGR_ADCPRE)) |
		((adcpre & 0x4) ? RCC_CFGR_ADCPRE2 : 0) |
		((adcpre & 0x3) << RCC_CFGR_ADCPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Set RCC HSI to SYSCLK selector.

@param[in] hsisclk HSI to SYSCLK selector @ref rcc_cfgr5_hsi_sclk
*/

void rcc_set_hsi_sclk(uint32_t hsisclk)
{
	RCC_CFGR5 = (RCC_CFGR5 & ~RCC_CFGR5_HSI_SCLK) |
		(hsisclk ? RCC_CFGR5_HSI_SCLK : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Clock Source.

@note This only has effect when the USB is disabled.

@param[in] ocs USB clock source, PLL or HSI. @ref rcc_cfgr5_usb_src
*/

void rcc_set_usb_clock_source(enum rcc_osc osc)
{
	RCC_CFGR5 = (RCC_CFGR5 & ~RCC_CFGR5_HSI_USB_SRC) |
		(osc == RCC_HSI ? RCC_CFGR5_HSI_USB_SRC : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Prescale Factor.

@note These bits cannot be reset while the USB clock is enabled.

@param[in] usbpre USB prescale factor @ref rcc_cfgr_usbpre
*/

void rcc_set_usbpre(uint32_t usbpre)
{
	RCC_CFGR = (RCC_CFGR & ~(RCC_CFGR_USBPRE2 | RCC_CFGR_USBPRE)) |
		((usbpre & 0x4) ? RCC_CFGR_USBPRE2 : 0) |
		((usbpre & 0x3) << RCC_CFGR_USBPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock Source.

@param[in] mcosrc MCO clock source. @ref rcc_cfgr_mco
*/

void rcc_set_mco_source(uint32_t mcosrc)
{
	/* MCO[3] lives here */
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_MCO3) |
		((mcosrc & 0x8) ? RCC_CFGR3_MCO3 : 0);
	/* feed MCO[2:0] to common code */
	rcc_set_mco(mcosrc & RCC_CFGR_MCO_MASK);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock Divider.

@param[in] mcodiv MCO clock divider. @ref rcc_cfgr_mco
*/

void rcc_set_mcodiv(uint32_t mcodiv)
{
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_MCO_DIV) |
		(mcodiv << RCC_CFGR3_MCO_DIV_SHIFT);
}

/**@}*/
