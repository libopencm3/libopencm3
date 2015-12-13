/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include <libopencm3/efm32/cmu.h>
#include <libopencm3/efm32/msc.h>

/**
 * Enable CMU registers lock.
 */
void cmu_enable_lock(void)
{
	CMU_LOCK = CMU_LOCK_LOCKKEY_LOCK;
}

/**
 * Disable CMU registers lock
 */
void cmu_disable_lock(void)
{
	CMU_LOCK = CMU_LOCK_LOCKKEY_UNLOCK;
}

/**
 * Get CMU register lock flag
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool cmu_get_lock_flag(void)
{
	return (CMU_LOCK & CMU_LOCK_LOCKKEY_MASK) == CMU_LOCK_LOCKKEY_LOCKED;
}

#define _CMU_REG(i)		MMIO32(CMU_BASE + ((i) >> 5))
#define _CMU_BIT(i)		(1 << ((i) & 0x1f))

/**
 * @brief Enable Peripheral Clock in running mode.
 *
 * Enable the clock on particular peripheral.
 *
 * @param[in] periph enum cmu_periph_clken Peripheral Name
 *
 * For available constants, see @a enum::cmu_periph_clken (CMU_LEUART1 for
 * example)
 */

void cmu_periph_clock_enable(enum cmu_periph_clken clken)
{
	_CMU_REG(clken) |= _CMU_BIT(clken);
}

/**
 * @brief Disable Peripheral Clock in running mode.
 * Disable the clock on particular peripheral.
 *
 * @param[in] periph enum cmu_periph_clken Peripheral Name
 *
 * For available constants, see @a enum::cmu_periph_clken (CMU_LEUART1 for
 * example)
 */

void cmu_periph_clock_disable(enum cmu_periph_clken clken)
{
	_CMU_REG(clken) &= ~_CMU_BIT(clken);
}

/**
 * Turn on Oscillator
 * @param[in] osc enum cmu_osc Oscillator name
 */
void cmu_osc_on(enum cmu_osc osc)
{
	switch (osc) {
	case HFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_HFRCOEN;
	break;
	case LFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_LFRCOEN;
	break;
	case ULFRCO:
		/* TODO: but how? */
	break;
	case HFXO:
		CMU_OSCENCMD = CMU_OSCENCMD_HFXOEN;
	break;
	case LFXO:
		CMU_OSCENCMD = CMU_OSCENCMD_LFXOEN;
	break;
	case AUXHFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_AUXHFRCOEN;
	break;
	}
}

/**
 * Turn off Oscillator
 * @param[in] osc enum cmu_osc Oscillator name
 */
void cmu_osc_off(enum cmu_osc osc)
{
	switch (osc) {
	case HFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_HFRCODIS;
	break;
	case LFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_LFRCODIS;
	break;
	case ULFRCO:
		/* TODO: but how? */
	break;
	case HFXO:
		CMU_OSCENCMD = CMU_OSCENCMD_HFXODIS;
	break;
	case LFXO:
		CMU_OSCENCMD = CMU_OSCENCMD_LFXODIS;
	break;
	case AUXHFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_AUXHFRCODIS;
	break;
	}
}

/**
 * Get Oscillator read flag
 * @param[in] osc enum cmu_osc Oscillator name
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool cmu_osc_ready_flag(enum cmu_osc osc)
{
	switch (osc) {
	case HFRCO:
		return (CMU_STATUS & CMU_STATUS_HFRCORDY) != 0;
	break;
	case LFRCO:
		return (CMU_STATUS & CMU_STATUS_LFRCORDY) != 0;
	break;
	case ULFRCO:
		/* TODO: but how? */
	break;
	case HFXO:
		return (CMU_STATUS & CMU_STATUS_HFXORDY) != 0;
	break;
	case LFXO:
		return (CMU_STATUS & CMU_STATUS_LFXORDY) != 0;
	break;
	case AUXHFRCO:
		return (CMU_STATUS & CMU_STATUS_AUXHFRCORDY) != 0;
	break;
	}

	return false;
}

/**
 * Wait till oscillator is not ready
 * @param[in] osc enum cmu_osc Oscillator name
 */
void cmu_wait_for_osc_ready(enum cmu_osc osc)
{
	switch (osc) {
	case HFRCO:
		while ((CMU_STATUS & CMU_STATUS_HFRCORDY) == 0);
	break;
	case LFRCO:
		while ((CMU_STATUS & CMU_STATUS_LFRCORDY) == 0);
	break;
	case ULFRCO:
		/* TODO: but how? */
	break;
	case HFXO:
		while ((CMU_STATUS & CMU_STATUS_HFXORDY) == 0);
	break;
	case LFXO:
		while ((CMU_STATUS & CMU_STATUS_LFXORDY) == 0);
	break;
	case AUXHFRCO:
		while ((CMU_STATUS & CMU_STATUS_AUXHFRCORDY) == 0);
	break;
	}
}

/**
 * Set HFCLK clock source
 * @param[in] osc enum cmu_osc Oscillator name
 * @note calling cmu_set_hfclk_source() do not set source immediately, use
 *    @a cmu_get_hfclk_source() to verify that the source has been set.
 * @see cmu_get_hfclk_source()
 */
void cmu_set_hfclk_source(enum cmu_osc osc)
{
	switch (osc) {
	case HFXO:
		CMU_CMD = CMU_CMD_HFCLKSEL_HFXO;
		break;
	case HFRCO:
		CMU_CMD = CMU_CMD_HFCLKSEL_HFRCO;
		break;
	case LFXO:
		CMU_CMD = CMU_CMD_HFCLKSEL_LFXO;
		break;
	case LFRCO:
		CMU_CMD = CMU_CMD_HFCLKSEL_LFRCO;
		break;
	default:
		/* not applicable */
		return;
	}
}

enum cmu_osc cmu_get_hfclk_source(void)
{
	uint32_t status = CMU_STATUS;
	if (status & CMU_STATUS_LFXOSEL) {
		return LFXO;
	} else if (status & CMU_STATUS_LFRCOSEL) {
		return LFRCO;
	} else if (status & CMU_STATUS_HFXOSEL) {
		return HFXO;
	} else if (status & CMU_STATUS_HFRCOSEL) {
		return HFRCO;
	}

	/* never reached */
	return (enum cmu_osc) -1;
}

/**
 * HFXO output 48Mhz and core running at 48Mhz
 */
void cmu_clock_setup_in_hfxo_out_48mhz(void)
{
	/* configure HFXO and prescaler */
	CMU_HFCORECLKDIV = CMU_HFCORECLKDIV_HFCORECLKDIV_NODIV
			   | CMU_HFCORECLKDIV_HFCORECLKLEDIV;
	CMU_CTRL = (CMU_CTRL
		    & ~(CMU_CTRL_HFCLKDIV_MASK | CMU_CTRL_HFXOBUFCUR_MASK))
		    | (CMU_CTRL_HFCLKDIV_NODIV
		       | CMU_CTRL_HFXOBUFCUR_BOOSTABOVE32MHZ);

	/* enable HFXO */
	cmu_osc_on(HFXO);

	/* wait for HFXO */
	cmu_wait_for_osc_ready(HFXO);

	/* set flash wait state */
	MSC_READCTRL = (MSC_READCTRL & ~MSC_READCTRL_MODE_MASK)
			| MSC_READCTRL_MODE_WS2;

	/* switch to HFXO */
	cmu_set_hfclk_source(HFXO);

	/* wait till HFXO not selected */
	while (cmu_get_hfclk_source() != HFXO);
}
