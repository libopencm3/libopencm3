/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <libopencm3/sam/pmc.h>
#include <libopencm3/sam/eefc.h>

/** Default peripheral clock frequency after reset. */
uint32_t pmc_mck_frequency = 4000000;

void pmc_xtal_enable(bool en, uint8_t startup_time)
{
	if (en) {
		CKGR_MOR = (CKGR_MOR & ~CKGR_MOR_MOSCXTST_MASK) |
				CKGR_MOR_KEY | CKGR_MOR_MOSCXTEN |
				(startup_time << 8);
		while (!(PMC_SR & PMC_SR_MOSCXTS));
	} else {
		CKGR_MOR = CKGR_MOR_KEY | (CKGR_MOR & ~CKGR_MOR_MOSCXTEN);
	}
}

void pmc_plla_config(uint8_t mul, uint8_t div)
{
	CKGR_PLLAR = CKGR_PLLAR_ONE | ((mul - 1) << 16) |
			CKGR_PLLAR_PLLACOUNT_MASK | div;
	while (!(PMC_SR & PMC_SR_LOCKA));
}

void pmc_peripheral_clock_enable(uint8_t pid)
{
#if defined(PMC_PCER1)
	if (pid < 32) {
		PMC_PCER0 = 1 << pid;
	} else {
		PMC_PCER1 = 1 << (pid & 31);
	}
#else
	/* SAM3N and SAM3U only have one Peripheral Clock Enable Register */
	PMC_PCER = 1 << pid;
#endif
}

void pmc_peripheral_clock_disable(uint8_t pid)
{
#if defined(PMC_PCER1)
	if (pid < 32) {
		PMC_PCDR0 = 1 << pid;
	} else {
		PMC_PCDR1 = 1 << (pid & 31);
	}
#else
	PMC_PCDR = 1 << pid;
#endif
}

void pmc_mck_set_source(enum mck_src src)
{
	PMC_MCKR = (PMC_MCKR & ~PMC_MCKR_CSS_MASK) | src;
	while (!(PMC_SR & PMC_SR_MCKRDY));
}

void pmc_clock_setup_in_xtal_12mhz_out_84mhz(void)
{
	eefc_set_latency(4);

	/* 12MHz external xtal, maximum possible startup time */
	pmc_xtal_enable(true, 0xff);
	/* Select as main oscillator */
	CKGR_MOR |= CKGR_MOR_KEY | CKGR_MOR_MOSCSEL;
	/* Multiply by 7 for 84MHz */
	pmc_plla_config(7, 1);
	pmc_mck_set_source(MCK_SRC_PLLA);

	pmc_mck_frequency = 84000000;
}

void pmc_clock_setup_in_rc_4mhz_out_84mhz(void)
{
	eefc_set_latency(4);

	/* Select as main oscillator */
	CKGR_MOR = CKGR_MOR_KEY |
		(CKGR_MOR & ~(CKGR_MOR_MOSCSEL | CKGR_MOR_MOSCRCF_MASK));
	/* Multiply by 21 for 84MHz */
	pmc_plla_config(21, 1);
	pmc_mck_set_source(MCK_SRC_PLLA);

	pmc_mck_frequency = 84000000;
}

