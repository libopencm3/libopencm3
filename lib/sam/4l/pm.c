/** @addtogroup scif
 *
 * @brief <b>Access functions for the SAM4 Power Manager (PM)</b>
 * @ingroup SAM4
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
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

#include <libopencm3/sam/pm.h>

void pm_select_main_clock(enum mck_src source_clock)
{
	PM_UNLOCK = PM_MCCTRL_KEY;
	PM_MCCTRL = ((source_clock & PM_MCCTRL_MCSEL_MASK) << PM_MCCTRL_MCSEL_SHIFT);
	while (!(PM_SR & PM_SR_CKRDY));
}

void pm_enable_clock_div(enum pm_cksel sel_target, uint8_t div)
{
	while (!(PM_SR & PM_SR_CKRDY));
	uint32_t reg = (PM_CKSEL_DIV | (div & PM_CKSEL_MASK));

	PM_UNLOCK = PM_CKSEL_KEY(sel_target);
	PM_CKSEL(sel_target) = reg;
	while (!(PM_SR & PM_SR_CKRDY));
}

void pm_set_divmask_clock(uint8_t mask)
{
	PM_UNLOCK = PM_PBADIVMASK_KEY;
	PM_PBADIVMASK = mask;
}

static void set_peripheral_clock_status(enum pm_peripheral periph, bool on)
{
	uint8_t reg_id = periph/32;
	uint8_t bit_offset = periph % 32;
	uint32_t reg_mask = PM_MASK(reg_id);
	if (on) {
		reg_mask |= (1 << bit_offset);
	} else {
		reg_mask &= ~(1 << bit_offset);
	}
	PM_UNLOCK = PM_MASK_KEY(reg_id);
	PM_MASK(reg_id) = reg_mask;
}

void pm_enable_peripheral_clock(enum pm_peripheral periph)
{
	set_peripheral_clock_status(periph, true);
}

void pm_disable_peripheral_clock(enum pm_peripheral periph)
{
	set_peripheral_clock_status(periph, false);
}
