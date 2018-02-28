/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 * Copyright (C) 2018 Seb Holzapfel <schnommus@gmail.com>
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
	case USHFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_USHFRCOEN;
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
	case USHFRCO:
		CMU_OSCENCMD = CMU_OSCENCMD_USHFRCODIS;
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
	case USHFRCO:
		return (CMU_STATUS & CMU_STATUS_USHFRCORDY) != 0;
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
 * Wait while oscillator is not ready
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
	case USHFRCO:
		while ((CMU_STATUS & CMU_STATUS_USHFRCORDY) == 0);
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

/**
 * Get HFCLK clock source
 * @retval enum cmu_osc Oscillator name
 */
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
 * Set USBCLK clock source
 * @retval enum cmu_osc Oscillator name
 */
void cmu_set_usbclk_source(enum cmu_osc osc)
{
	switch (osc) {
	case LFXO:
		CMU_CMD = CMU_CMD_USBCCLKSEL_LFXO;
		break;
	case LFRCO:
		CMU_CMD = CMU_CMD_USBCCLKSEL_LFRCO;
		break;
	case USHFRCO:
		CMU_CMD = CMU_CMD_USBCCLKSEL_USHFRCO;
		break;
	default:
		/* not applicable */
		return;
	}
}

/**
 * Wait while USBCLK is not selected
 * @param[in] osc enum cmu_osc Oscillator name
 */
void cmu_wait_for_usbclk_selected(enum cmu_osc osc)
{
	switch (osc) {
	case LFXO:
		while ((CMU_STATUS & CMU_STATUS_USBCLFXOSEL) == 0);
		break;
	case LFRCO:
		while ((CMU_STATUS & CMU_STATUS_USBCLFRCOSEL) == 0);
		break;
	case USHFRCO:
		while ((CMU_STATUS & CMU_STATUS_USBCUSHFRCOSEL) == 0);
		break;
	default:
		/* not applicable */
		return;
	}
}
