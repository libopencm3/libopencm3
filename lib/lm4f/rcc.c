/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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
 *
 */

/**
 * @defgroup rcc_file RCC
 *
 * @ingroup LM4Fxx
 *
@author @htmlonly &copy; @endhtmlonly 2012
Alexandru Gagniuc <mr.nuke.me@gmail.com>

 * \brief <b>libopencm3 LM4F Clock control API</b>
 *
 * The LM$F clock API provides functionaliity for manipulating the system clock,
 * oscillator, and PLL. Functions are provided for fine-grained control of clock
 * control registers, while also providing higher level functionality to easily
 * configure the main system clock source.
 *
 * The following code snippet uses fine-grained mechanisms to configures the
 * chip to run off an external 16MHz crystal, and use the PLL to derive a clock
 * frequency of 80MHz.
 * @code{.c}
 *	// A divisor of 5 gives us a clock of 400/5 = 80MHz
 *	#define PLLDIV_80MHZ 5
 *
 *	// Enable the main oscillator
 *	rcc_enable_main_osc();
 *
 *	// Make RCC2 override RCC
 *	rcc_enable_rcc2();
 *
 *	// Set XTAL value to 16MHz
 *	rcc_configure_xtal(XTAL_16M);
 *	// Set the oscillator source as the main oscillator
 *	rcc_set_osc_source(OSCSRC_MOSC);
 *	// Enable the PLL
 *	rcc_pll_on();
 *
 *	// Change the clock divisor
 *	rcc_set_pll_divisor(PLLDIV_80MHZ);
 *
 *	// We cannot use the PLL as a clock source until it locks
 *	rcc_wait_for_pll_ready();
 *	// Disable PLL bypass to derive the system clock from the PLL clock
 *	rcc_pll_bypass_disable();
 *
 *	// Keep track of frequency
 *	lm4f_rcc_sysclk_freq = 80E6;
 * @endcode
 *
 * The same can be achieved by a simple call to high-level routines:
 * @code
 *	// A divisor of 5 gives us a clock of 400/5 = 80MHz
 *	#define PLLDIV_80MHZ 5
 *
 *	rcc_sysclk_config(OSCSRC_MOSC, XTAL_16M, PLLDIV_80MHZ);
 * @endcode
 *
 * @{
 */

#include <libopencm3/lm4f/rcc.h>

/**
 * @defgroup rcc_low_level Low-level clock control API
@ingroup rcc_file
 * @{
 */
/**
 * \brief System clock frequency
 *
 * This variable is provided to keep track of the system clock frequency. It
 * should be updated every time the system clock is changed via the fine-grained
 * mechanisms. The initial value is 16MHz, which corresponds to the clock of the
 * internal 16MHz oscillator.
 *
 * High-level routines update the system clock automatically.
 * For read access, it is recommended to acces this variable via
 * @code
 *	rcc_get_system_clock_frequency();
 * @endcode
 *
 * If write access is desired (i.e. when changing the system clock via the
 * fine-grained mechanisms), then include the following  line in your code:
 * @code
 *	extern uint32_t lm4f_rcc_sysclk_freq;
 * @endcode
 */
uint32_t lm4f_rcc_sysclk_freq = 16000000;


/**
 * \brief Configure the crystal type connected to the device.
 *
 * Configure the crystal type connected between the OSCO and OSCI pins by
 * writing the appropriate value to the XTAL field in SYSCTL_RCC. The PLL
 * parameters are automatically adjusted in hardware to provide a PLL clock of
 * 400MHz.
 *
 * @param[in] xtal predefined crystal type @see xtal_t
 */
void rcc_configure_xtal(enum xtal_t xtal)
{
	uint32_t reg32;

	reg32 = SYSCTL_RCC;
	reg32 &= ~SYSCTL_RCC_XTAL_MASK;
	reg32 |= (xtal & SYSCTL_RCC_XTAL_MASK);
	SYSCTL_RCC = reg32;
}

/**
 * \brief Disable the main oscillator
 *
 * Sets the IOSCDIS bit in SYSCTL_RCC, disabling the main oscillator.
 */
void rcc_disable_main_osc(void)
{
	SYSCTL_RCC |= SYSCTL_RCC_MOSCDIS;
}

/**
 * \brief Disable the internal oscillator
 *
 * Sets the IOSCDIS bit in SYSCTL_RCC, disabling the internal oscillator.
 */
void rcc_disable_interal_osc(void)
{
	SYSCTL_RCC |= SYSCTL_RCC_IOSCDIS;
}

/**
 * \brief Enable the main oscillator
 *
 * Clears the MOSCDIS bit in SYSCTL_RCC, enabling the main oscillator.
 */
void rcc_enable_main_osc(void)
{
	SYSCTL_RCC &= ~SYSCTL_RCC_MOSCDIS;
}

/**
 * \brief Enable the internal oscillator
 *
 * Clears the IOSCDIS bit in SYSCTL_RCC, enabling the internal oscillator.
 */
void rcc_enable_interal_osc(void)
{
	SYSCTL_RCC &= ~SYSCTL_RCC_IOSCDIS;
}

/**
 * \brief Enable the use of SYSCTL_RCC2 register for clock control
 *
 * Enables the USERCC2 bit in SYSCTTL_RCC2. Settings in SYSCTL_RCC2 will
 * override settings in SYSCTL_RCC.
 * This function must be called before other calls to manipulate the clock, as
 * libopencm3 uses the SYSCTL_RCC2 register.
 */
void rcc_enable_rcc2(void)
{
	SYSCTL_RCC2 |= SYSCTL_RCC2_USERCC2;
}

/**
 * \brief Power down the main PLL
 *
 * Sets the SYSCTL_RCC2_PWRDN2 in SYSCTL_RCC2 to power down the PLL.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_pll_off(void)
{
	SYSCTL_RCC2 |= SYSCTL_RCC2_PWRDN2;
}

/**
 * \brief Power up the main PLL
 *
 * Clears the PWRDN2 in SYSCTL_RCC2 to power on the PLL.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_pll_on(void)
{
	SYSCTL_RCC2 &= ~SYSCTL_RCC2_PWRDN2;
}

/**
 * \brief Set the oscillator source to be used by the system clock
 *
 * Set the clock source for the system clock.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_set_osc_source(enum osc_src src)
{
	uint32_t reg32;

	reg32 = SYSCTL_RCC2;
	reg32 &= ~SYSCTL_RCC2_OSCSRC2_MASK;
	reg32 |= (src & SYSCTL_RCC2_OSCSRC2_MASK);
	SYSCTL_RCC2 = reg32;
}

/**
 * \brief Disable the PLL bypass and use the PLL clock
 *
 * Clear BYPASS2 in SYSCTL_RCC2. The system clock is derived from the PLL
 * clock divided by the divisor specified in SYSDIV2.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_pll_bypass_disable(void)
{
	SYSCTL_RCC2 &= ~SYSCTL_RCC2_BYPASS2;
}

/**
 * \brief Enable the PLL bypass and use the oscillator clock
 *
 * Set BYPASS2 in SYSCTL_RCC2. The system clock is derived from the oscillator
 * clock divided by the divisor specified in SYSDIV2.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_pll_bypass_enable(void)
{
	SYSCTL_RCC2 |= SYSCTL_RCC2_BYPASS2;
}

/**
 * \brief Set the PLL clock divisor (from 400MHz)
 *
 * Set the binary divisor used to predivide the system clock down for use as the
 * timing reference for the PWM module. The divisor is expected to be a divisor
 * from 400MHz, not 200MHz. The DIV400 is also set.
 *
 * Specifies the divisor that used to generate the system clock from either the
 * PLL output or the oscillator source (depending on the BYPASS2 bit in
 * SYSCTL_RCC2). SYSDIV2 is used for the divisor when both the USESYSDIV bit in
 * SYSCTL_RCC is set.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 *
 * @param[in] div clock divisor to apply to the 400MHz PLL clock. It is the
 *	      caller's responsibility to ensure that the divisor will not create
 *	      a system clock that is out of spec.
 */
void rcc_set_pll_divisor(uint8_t div400)
{
	uint32_t reg32;

	SYSCTL_RCC |= SYSCTL_RCC_USESYSDIV;

	reg32 = SYSCTL_RCC2;
	reg32 &= ~SYSCTL_RCC2_SYSDIV400_MASK;
	reg32 |= ((div400 - 1) << 22) & SYSCTL_RCC2_SYSDIV400_MASK;
	/* We are expecting a divider from 400MHz */
	reg32 |= SYSCTL_RCC2_DIV400;
	SYSCTL_RCC2 = reg32;
}
/**
 * \brief Set the PWM unit clock divisor
 *
 * Set the binary divisor used to predivide the system clock down for use as the
 * timing reference for the PWM module.
 *
 * @param[in] div clock divisor to use @see pwm_clkdiv_t
 */
void rcc_set_pwm_divisor(enum pwm_clkdiv div)
{
	uint32_t reg32;

	reg32 = SYSCTL_RCC;
	reg32 &= ~SYSCTL_RCC_PWMDIV_MASK;
	reg32 |= (div & SYSCTL_RCC_PWMDIV_MASK);
	SYSCTL_RCC = reg32;
}

/**
 * \brief Power down the USB PLL
 *
 * Sets the USBPWRDN in SYSCTL_RCC2 to power down the USB PLL.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_usb_pll_off(void)
{
	SYSCTL_RCC2 |= SYSCTL_RCC2_USBPWRDN;
}

/**
 * \brief Power up the USB PLL
 *
 * Clears the USBPWRDN in SYSCTL_RCC2 to power on the USB PLL.
 *
 * USERCC2 must have been set by a call to rcc_enable_rcc2() before calling this
 * function.
 */
void rcc_usb_pll_on(void)
{
	SYSCTL_RCC2 &= ~SYSCTL_RCC2_USBPWRDN;
}

/**
 * \brief Wait for main PLL to lock
 *
 * Waits until the LOCK bit in SYSCTL_PLLSTAT is set. This guarantees that the
 * PLL is locked, and ready to use.
 */
void rcc_wait_for_pll_ready(void)
{
	while (!(SYSCTL_PLLSTAT & SYSCTL_PLLSTAT_LOCK));
}

/**
 * @}
 */

/**
 * @defgroup rcc_high_level High-level clock control API
@ingroup rcc_file
 * @{
 */

/**
 * \brief Change the PLL divisor
 *
 * Changes the divisor applied to the 400MHz PLL clock. The PLL must have
 * previously been configured by selecting an appropriate XTAL value, and
 * turning on the PLL. This function does not reconfigure the XTAL value or
 * oscillator source. It only changes the PLL divisor.
 *
 * The PLL is bypassed before modifying the divisor, and the function blocks
 * until the PLL is locked, then the bypass is disabled, before returning.
 *
 * @param [in] pll_div400 The clock divisor to apply to the 400MHz PLL clock.
 */
void rcc_change_pll_divisor(uint8_t pll_div400)
{
	/* Bypass the PLL while its settings are modified */
	rcc_pll_bypass_enable();
	/* Change the clock divisor */
	rcc_set_pll_divisor(pll_div400);
	/* We cannot use the PLL as a clock source until it locks */
	rcc_wait_for_pll_ready();
	/* Disable PLL bypass to derive the system clock from the PLL clock */
	rcc_pll_bypass_disable();
	/* Update the system clock frequency for housekeeping */
	lm4f_rcc_sysclk_freq = (uint32_t)400E6 / pll_div400;
}

/**
 * \brief Get the system clock frequency
 *
 * @return System clock frequency in Hz
 */
uint32_t rcc_get_system_clock_frequency(void)
{
	return lm4f_rcc_sysclk_freq;
}

/* Get the clock frequency corresponding to a given XTAL value */
static uint32_t xtal_to_freq(enum xtal_t xtal)
{
	const uint32_t freqs[] = {
		 4000000,	/* XTAL_4M */
		 4096000,	/* XTAL_4M_096 */
		 4915200,	/* XTAL_4M_9152 */
		 5000000,	/* ,XTAL_5M */
		 5120000,	/* XTAL_5M_12 */
		 6000000,	/* XTAL_6M */
		 6144000,	/* XTAL_6M_144 */
		 7372800,	/* XTAL_7M_3728 */
		 8000000,	/* XTAL_8M */
		 8192000,	/* XTAL_8M_192 */
		10000000,	/* XTAL_10M */
		12000000,	/* XTAL_12M */
		12288000,	/* XTAL_12M_288 */
		13560000,	/* XTAL_13M_56 */
		14318180,	/* XTAL_14M_31818 */
		16000000,	/* XTAL_16M */
		16384000,	/* XTAL_16M_384 */
		18000000,	/* XTAL_18M */
		20000000,	/* XTAL_20M */
		24000000,	/* XTAL_24M */
		25000000,	/* XTAL_25M */
	};

	return freqs[xtal - XTAL_4M];
}

/**
 * \brief Configure the system clock source
 *
 * Sets up the system clock, including configuring the oscillator source, and
 * PLL to acheve the desired system clock frequency. Where applicable, The LM4F
 * clock API uses the new RCC2 register to configure clock parameters.
 *
 * Enables the main oscillator if the clock source is OSCSRC_MOSC. If the main
 * oscillator was previously enabled, it will not be disabled. If desired, it
 * can be separately disabled by a call to rcc_disable_main_osc().
 *
 * Configures the system clock to run from the 400MHz PLL with a divisor of
 * pll_div400 applied. If pll_div400 is 0, then the PLL is disabled, and the
 * system clock is configured to run off a "raw" clock. If the PLL was
 * previously powered on, it will not be disabled. If desired, it can de powered
 * off by a call to rcc_pll_off().
 *
 * @param [in] osc_src Oscillator from where to derive the system clock.
 * @param [in] xtal Type of crystal connected to the OSCO/OSCI pins
 * @param [in] pll_div400 The clock divisor to apply to the 400MHz PLL clock.
 *			  If 0, then the PLL is disabled, and the system runs
 *			  off a "raw" clock.
 *
 * @return System clock frequency in Hz
 */
void rcc_sysclk_config(enum osc_src src, enum xtal_t xtal, uint8_t pll_div400)
{
	/*
	 * We could be using the PLL at this point, or we could be running of a
	 * raw clock. Either way, it is safer to bypass the PLL now.
	 */
	rcc_pll_bypass_enable();

	/* Enable the main oscillator, if needed */
	if (src == OSCSRC_MOSC) {
		rcc_enable_main_osc();
	}

	/* Make RCC2 override RCC */
	rcc_enable_rcc2();

	/* Set XTAL value to 16MHz */
	rcc_configure_xtal(xtal);
	/* Set the oscillator source */
	rcc_set_osc_source(src);
	if (pll_div400) {
		/* Enable the PLL */
		rcc_pll_on();
		/* Configure the PLL to the divisor we want */
		rcc_change_pll_divisor(pll_div400);
	} else {
		/* We are running off a raw clock */
		switch (src) {
		case OSCSRC_PIOSC:
			lm4f_rcc_sysclk_freq = 16000000;
			break;
		case OSCSRC_PIOSC_D4:
			lm4f_rcc_sysclk_freq = 4000000;
			break;
		case OSCSRC_MOSC:
			lm4f_rcc_sysclk_freq = xtal_to_freq(xtal);
			break;
		case OSCSRC_32K_EXT:
			lm4f_rcc_sysclk_freq = 32768;
			break;
		case OSCSRC_30K_INT: /* Fall through. */
		default:
			/*
			 * We either are running off the internal 30KHz
			 * oscillator, which is +- 50% imprecise, or we got a
			 * bad osc_src parameter.
			 */
			lm4f_rcc_sysclk_freq = 0;
		}
	}

}

/**
 * @}
 * @}
 */
