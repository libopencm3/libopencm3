/**
 * @brief Clock Control and System Defines for the Qorvo PAC55xx series of microcontrollers.
 *
 *  @defgroup system_defines Clock Config and System Defines
 *  @ingroup PAC55xx_defines
 *  @author Brian Viele <vielster@allocor.tech>
 *  @author Kevin Stefanik <kevin@allocor.tech>
 *  LGPL License Terms @ref lgpl_license
 *  @date 1 Dec 2019
 *
 *  Definitions in this file come from the PAC55XX Family User Guide Rev 1.21
 *  by Active-Semi dated August 26, 2019.
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
#ifndef LIBOPENCM3_PAC55XX_CCS_H_
#define LIBOPENCM3_PAC55XX_CCS_H_

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/pac55xx/memorymap.h>
#include <libopencm3/pac55xx/memctl.h>

/**@{*/

/** @defgroup ccs_frequencies CCS Frequencies
@{*/
/** Ring Oscillator Frequency */
#define CCS_ROSC_FREQ       (16000000U)
/** Internally generated and trimmed 4MHz clock */
#define CCS_CLKREF_FREQ     ( 4000000U)
/** Maximum external clock frequency */
#define CCS_EXTCLK_MAX_FREQ (20000000U)
/**@}*/

/** @defgroup ccs_ctl_reg Clock Control Register
@{*/
#define CCSCTL MMIO32(SCC_BASE)
#define CCS_CTL_FRCLKMUXSEL_MASK (0x03)
#define CCS_CTL_FRCLKMUXSEL(sel) ((sel) & CCS_CTL_FRCLKMUXSEL_MASK)
#define CCS_CTL_FRCLKMUXSEL_ROSC    (0)
#define CCS_CTL_FRCLKMUXSEL_CLKREF  (1)
#define CCS_CTL_FRCLKMUXSEL_EXTCLK  (3)
#define CCS_CTL_ROSCEN BIT2
#define CCS_CTL_SCLKMUXSEL BIT4
#define CCS_CTL_SCLKMUXSEL_FRCLK    (0)
#define CCS_CTL_SCLKMUXSEL_PLLCLK   (1)
#define CCS_CTL_CLKFAILEN BIT5
#define CCS_CTL_CLKFAILMUXSEL BIT6
#define CCS_CTL_CLKFAILIF BIT7
#define CCS_CTL_LDOEN BIT8
#define CCS_CTL_SWRESET BIT11
#define CCS_CTL_PCLKEN BIT12
#define CCS_CTL_ACLKEN BIT13
#define CCS_CTL_ADCCLKEN BIT14
#define CCS_CTL_STCLKSLPEN BIT15
#define CCS_CTL_PCLKDIV_MASK (0x07)
#define CCS_CTL_PCLKDIV_SHIFT (16)
/* Supported PCLK divisors: 1-8 */
#define CCS_CTL_PCLKDIV(div) (((div-1) & CCS_CTL_PCLKDIV_MASK) << CCS_CTL_PCLKDIV_SHIFT)
#define CCS_CTL_ACLKDIV_MASK (0x07)
#define CCS_CTL_ACLKDIV_SHIFT (20)
/* Supported ACLK divisors: 1-8 */
#define CCS_CTL_ACLKDIV(div) (((div-1) & CCS_CTL_ACLKDIV_MASK) << CCS_CTL_ACLKDIV_SHIFT)
#define CCS_CTL_HCLKDIV_MASK (0x07)
#define CCS_CTL_HCLKDIV_SHIFT (24)
/* Supported HCLK divisors: 1-8 */
#define CCS_CTL_HCLKDIV(div) (((div-1) & CCS_CTL_HCLKDIV_MASK) << CCS_CTL_HCLKDIV_SHIFT)
#define CCS_CTL_USAMODE BIT28
#define CCS_CTL_USBMODE BIT29
#define CCS_CTL_USCMODE BIT30
#define CCS_CTL_USDMODE BIT31
/**@}*/

/** @defgroup ccs_pllctl_reg CCS PLL Control Register
@{*/
#define CCSPLLCTL MMIO32(SCC_BASE + 0x04)
/** PLL Enable */
#define CCS_PLLCTL_PLLEN BIT0
/** PLL Bypass */
#define CCS_PLLCTL_PLLBP BIT1
#define CCS_PLLCTL_PLLOUTDIV_MASK (0x03)
#define CCS_PLLCTL_PLLOUTDIV_SHIFT (2)
/** PLL Output Divisor */
#define CCS_PLLCTL_PLLOUTDIV(div) (((div) & CCS_PLLCTL_PLLOUTDIV_MASK) << CCS_PLLCTL_PLLOUTDIV_SHIFT)
#define CCS_PLLCTL_PLLOUTDIV1     (0)
#define CCS_PLLCTL_PLLOUTDIV2     (1)
#define CCS_PLLCTL_PLLOUTDIV4     (2)
#define CCS_PLLCTL_PLLOUTDIV8     (3)
#define CCS_PLLCTL_PLLINDIV_MASK (0x0F)
#define CCS_PLLCTL_PLLINDIV_SHIFT (4)
/** PLL Input Divisor */
#define CCS_PLLCTL_PLLINDIV(div) (((div) & CCS_PLLCTL_PLLINDIV_MASK) << CCS_PLLCTL_PLLINDIV_SHIFT)
#define CCS_PLLCTL_PLLFBDIV_MASK (0x3FFF)
#define CCS_PLLCTL_PLLFBDIV_SHIFT (8)
/** PLL Feedback Divisor */
#define CCS_PLLCTL_PLLFBDIV(div) (((div) & CCS_PLLCTL_PLLFBDIV_MASK) << CCS_PLLCTL_PLLFBDIV_SHIFT)
/** PLL Lock */
#define CCS_PLLCTL_PLLLOCK BIT24
/**@}*/

/** @defgroup ccs_rosctrim Ring Oscillator Trim Control Register
@{*/
#define CCSROSCTRIM_MASK (0x7F)
#define CCSROSCTRIM MMIO32(SCC_BASE + 0x08)
/**@}*/

/** Port Pin Config Addresses
 * @defgroup port_pin_addresses Port Pinmux Register Base.
 * @{*/
#define CCS_PORTA (SCC_BASE + 0x0C)
#define CCS_PORTB (SCC_BASE + 0x10)
#define CCS_PORTC (SCC_BASE + 0x14)
#define CCS_PORTD (SCC_BASE + 0x18)
#define CCS_PORTE (SCC_BASE + 0x1C)
#define CCS_PORTF (SCC_BASE + 0x20)
#define CCS_PORTG (SCC_BASE + 0x24)
/**@}*/

/** Port Pin Mux Select Registers
 * @defgroup pmux_sel_regs PMUXSEL register mapping.
 * @{*/
#define CCS_MUXSELR(base) MMIO32(base)
#define CCS_PAMUXSELR CCS_MUXSELR(CCS_PORTA)
#define CCS_PBMUXSELR CCS_MUXSELR(CCS_PORTB)
#define CCS_PCMUXSELR CCS_MUXSELR(CCS_PORTC)
#define CCS_PDMUXSELR CCS_MUXSELR(CCS_PORTD)
#define CCS_PEMUXSELR CCS_MUXSELR(CCS_PORTE)
#define CCS_PFMUXSELR CCS_MUXSELR(CCS_PORTF)
#define CCS_PGMUXSELR CCS_MUXSELR(CCS_PORTG)
#define CCS_MUXSELR_MASK 0x7
#define CCS_MUXSELR_MASK_PIN(pin) (CCS_MUXSELR_MASK << ((pin) * 4))
#define CCS_MUXSELR_VAL(pin, muxsel) (((muxsel) & CCS_MUXSELR_MASK) << ((pin) * 4))

/* Enum type for port function setting for type specificity. */
typedef enum {
	CCS_MUXSEL_GPIO = 0,
	CCS_MUXSEL_AF1 = 1,
	CCS_MUXSEL_AF2 = 2,
	CCS_MUXSEL_AF3 = 3,
	CCS_MUXSEL_AF4 = 4,
	CCS_MUXSEL_AF5 = 5,
	CCS_MUXSEL_AF6 = 6,
	CCS_MUXSEL_AF7 = 7,
} ccs_muxsel_func_t;
/**@}*/

/** Port Pull-Up/Down Enable Registers.
 * @defgroup pden_regs PUEN PDEN register mapping.
 * @{*/
#define CCS_PUENR(base) MMIO32(base + 0x1C)
#define CCS_PAPUENR CCS_PUENR(CCS_PORTA)
#define CCS_PBPUENR CCS_PUENR(CCS_PORTB)
#define CCS_PCPUENR CCS_PUENR(CCS_PORTC)
#define CCS_PDPUENR CCS_PUENR(CCS_PORTD)
#define CCS_PEPUENR CCS_PUENR(CCS_PORTE)
#define CCS_PFPUENR CCS_PUENR(CCS_PORTF)
#define CCS_PGPUENR CCS_PUENR(CCS_PORTG)
#define CCS_PDENR(base) MMIO32(base + 0x38)
#define CCS_PAPDENR CCS_PDENR(CCS_PORTA)
#define CCS_PBPDENR CCS_PDENR(CCS_PORTB)
#define CCS_PCPDENR CCS_PDENR(CCS_PORTC)
#define CCS_PDPDENR CCS_PDENR(CCS_PORTD)
#define CCS_PEPDENR CCS_PDENR(CCS_PORTE)
#define CCS_PFPDENR CCS_PDENR(CCS_PORTF)
#define CCS_PGPDENR CCS_PDENR(CCS_PORTG)
/** Pull Up/Down enum for type specificity. */
typedef enum {
	CCS_IO_PULL_NONE = 0,
	CCS_IO_PULL_UP = 1,
	CCS_IO_PULL_DOWN = 2
} ccs_pull_updown_t;
/**@}*/

/** Port Drive Strength Enable Registers.
 * @defgroup dsr_regs DSR register mapping.
 * @{*/
#define CCS_DSR(base) MMIO32(base + 0x54)
#define CCS_PADSR CCS_DSR(CCS_PORTA)
#define CCS_PBDSR CCS_DSR(CCS_PORTB)
#define CCS_PCDSR CCS_DSR(CCS_PORTC)
#define CCS_PDDSR CCS_DSR(CCS_PORTD)
#define CCS_PEDSR CCS_DSR(CCS_PORTE)
#define CCS_PFDSR CCS_DSR(CCS_PORTF)
#define CCS_PGDSR CCS_DSR(CCS_PORTG)
#define CCS_DSR_MASK 0x7
#define CCS_DSR_MASK_PIN(pin) (CCS_DSR_MASK << ((pin) * 4))
#define CCS_DSR_DS_VAL(pin, ds) (((ds)&CCS_DSR_MASK) << ((pin)*4))
#define CCS_DSR_SCHMIDT_PIN(pin) (BIT0 << (((pin)*4) + 3))

/** Drive strength enumeration for type specificity. */
typedef enum {
	CCS_DSR_DS_6MA = 0x00,
	CCS_DSR_DS_8MA = 0x01,
	CCS_DSR_DS_11MA = 0x02,
	CCS_DSR_DS_14MA = 0x03,
	CCS_DSR_DS_17MA = 0x04,
	CCS_DSR_DS_20MA = 0x05,
	CCS_DSR_DS_22MA = 0x06,
	CCS_DSR_DS_25MA = 0x07,
} ccs_drive_strength_t;
/**@}*/

/**@}*/

BEGIN_DECLS

/**
 * @defgroup ccs_api Clock Control System API
 * @ingroup peripheral_apis
 * @brief <b>PAC5xx CCS Driver</b>
 * @author @htmlonly &copy; @endhtmlonly 2020 Kevin Stefanik <kevin@allocor.tech>
 * @date March 7, 2020
 *
 * This library supports the CCS module in the PAC55xx SoC from Qorvo.
 *
 * LGPL License Terms @ref lgpl_license
 */

/**@{*/

/**
 * Select the source for FRCLK.
 * @param[in] sel  one of:
 *   - /ref CCS_CTL_FRCLKMUXSEL_ROSC - 16MHz ring oscillator
 *   - /ref CCS_CTL_FRCLKMUXSEL_CLKREF - trimmed 4MHz clock
 *   - /ref CCS_CTL_FRCLKMUXSEL_EXTCLK
 */
void ccs_frclkmux_select(uint32_t sel);
/** Enable the 16MHz Ring oscillator */
void ccs_rosc_enable(void);
/** Disable the 16MHz Ring oscillator */
void ccs_rosc_disable(void);
/** Select FRCLK for SCLK */
void ccs_sclkmux_select_frclk(void);
/** Select PLLCLK for SCLK */
void ccs_sclkmux_select_pllclk(void);
/** Enable Clock Fail Detection */
void ccs_clkfail_enable(void);
/** Disable Clock Fail Detection */
void ccs_clkfail_disable(void);
/** Select FRCLK for Clock Fail Detection */
void ccs_clkfailmux_select_frclk(void);
/** Select PLLCLK for Clock Fail Detection */
void ccs_clkfailmux_select_pllclk(void);
/** Enable the LDO */
void ccs_ldo_enable(void);
/** Disable the LDO */
void ccs_ldo_disable(void);
/** Enable the Peripheral Clock */
void ccs_pclk_enable(void);
/** Disable the Peripheral Clock */
void ccs_pclk_disable(void);
/** Enable the Auxiliary Clock */
void ccs_aclk_enable(void);
/** Disable the Auxiliary Clock */
void ccs_aclk_disable(void);
/** Enable the ADC Clock */
void ccs_adcclk_enable(void);
/** Disable the ADC Clock */
void ccs_adcclk_disable(void);
/** Enable SysTick clock gating in deep sleep mode */
void ccs_stclk_sleep_enable(void);
/** Disable SysTick clock gating in deep sleep mode */
void ccs_stclk_sleep_disable(void);
/**
 * Set the divisor for the Peripheral Clock.
 * @param[in] div  PCLK Divisor: 1-8.
 */
void ccs_set_pclkdiv(uint32_t div);
/**
 * Set the divisor for the Auxiliary Clock.
 * @param[in] div  ACLK Divisor: 1-8.
 */
void ccs_set_aclkdiv(uint32_t div);
/**
 * Set the divisor for the AHB Clock.
 * @param[in] div  HCLK Divisor: 1-8.
 */
void ccs_set_hclkdiv(uint32_t div);
/** Enable the PLL */
void ccs_pll_enable(void);
/** Disable the PLL */
void ccs_pll_disable(void);
/** Check if the PLL is locked.
 * @return true if locked.
 */
bool ccs_pll_locked(void);
/** Enable the PLL bypass */
void ccs_pll_bypass_enable(void);
/** Disable the PLL bypass */
void ccs_pll_bypass_disable(void);
/**
 * Set the output divisor.
 * @param[in] div  Output divisor, one of:
 *   - /ref CCS_PLLCTL_PLLOUTDIV1
 *   - /ref CCS_PLLCTL_PLLOUTDIV2
 *   - /ref CCS_PLLCTL_PLLOUTDIV4
 *   - /ref CCS_PLLCTL_PLLOUTDIV8
 */
void ccs_pll_set_outdiv(uint32_t div);
/**
 * Set the PLL input divisor.
 * @param[in] div  Input divisor, 1-15.
 */
void ccs_pll_set_indiv(uint32_t div);
/**
 * Set the PLL feedback divisor.
 * @param[in] div  Feedback divisor, 4-16383.
 */
void ccs_pll_set_fbdiv(uint32_t div);
/**
 * Configure the CCS PLL, enable it, and wait for lock.
 * @param[in] indiv  Input divisor, 1-15.
 * @param[in] fbdiv  Feedback divisor, 4-16383.
 * @param[in] outdiv  Output divisor, one of:
 *   - /ref CCS_PLLCTL_PLLOUTDIV1
 *   - /ref CCS_PLLCTL_PLLOUTDIV2
 *   - /ref CCS_PLLCTL_PLLOUTDIV4
 *   - /ref CCS_PLLCTL_PLLOUTDIV8
 */
void css_pll_config_enable(uint32_t indiv, uint32_t fbdiv, uint32_t outdiv);
/**
 * Get the clock rate (in Hz) of the specified peripheral. This will pull the
 * proper sources out of the clock tree and calculate the clock for the
 * peripheral for return to the user, based on current settings.
 * @param[in] periph  Peripheral base address to get the clock rate for.
 * @param[in] select  Peripheral-controlled clock select value. Set to 0 when not applicable.
 * @return Clock rate in Hz for the specified peripheral. 0 if undefined or error.
 */
uint32_t ccs_get_peripheral_clk_freq(uint32_t periph, uint32_t select);
/** Restores CCSCTL and CCSPLLCTL registers to default/safe values */
void ccs_reset_clocks(void);

/** CCS Clock Configuration structure. */
struct ccs_clk_config {
	uint32_t frclk_source;              /**< FRCLK source input selection */
	uint32_t extclk_frequency;          /**< EXTCLK frequency, 0 if none. */
	uint32_t sclk_source;               /**< SCLK source selection */
	uint32_t pll_indiv;                 /**< PLL Input Divider 1-15 */
	uint32_t pll_fbdiv;                 /**< PLL Feedback Divider 4-16383 */
	uint32_t pll_outdiv;                /**< PLL Output Divider */
	uint32_t hclkdiv;                   /**< Divisor from SCLK to HCLK */
	uint32_t aclkdiv;                   /**< Divisor from SCLK to ACLK */
	uint32_t pclkdiv;                   /**< Divisor from HCLK to PCLK */
	uint32_t mem_wstate;                /**< Number of Flash Read wait states */
	uint32_t mem_mclkdiv;               /**< Divisor from HCLK to MCLK */
	bool mem_mclksel;                   /**< false: ROSCLK, true: HCLK/MCLK */
	bool mem_enable_cache;              /**< false: disable cache, true: enable cache */
};
/**
 * Setup the PAC55xx clocks with the given struct.
 * @param[in] config CCS Clock configuration struct /ref ccs_clk_config
 */
void ccs_configure_clocks(const struct ccs_clk_config *config);

/**@}*/

END_DECLS

#endif /* LIBOPENCM3_PAC55XX_CCS_H_ */
