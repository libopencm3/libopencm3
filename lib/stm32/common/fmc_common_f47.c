/** @addtogroup fmc_file FMC peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies ksarkies@internode.on.net

This library supports the Flexible Memory Controller in the STM32F4xx and
STM32F7xx series of ARM Cortex Microcontrollers by ST Microelectronics.
*/
/*
 *
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

/* Utility functions for the SDRAM component of the FMC */

#include <stdint.h>
#include <libopencm3/stm32/fsmc.h>

/**@{*/

/*
 * Install various timing values into the correct place in the
 * SDRAM Timing Control Register format.
 *
 * Note that the register is 'zero' based to save bits so 1 cycle
 * is stored as '0'. This command takes actual cycles and adjusts
 * by subtracting 1.
 */
uint32_t
sdram_timing(struct sdram_timing *t) {
	uint32_t result;

	result = 0;
	result |= ((t->trcd - 1) & 0xf) << FMC_SDTR_TRCD_SHIFT;
	result |= ((t->trp - 1) & 0xf) << FMC_SDTR_TRP_SHIFT;
	result |= ((t->twr - 1) & 0xf) << FMC_SDTR_TWR_SHIFT;
	result |= ((t->trc - 1) & 0xf) << FMC_SDTR_TRC_SHIFT;
	result |= ((t->tras - 1) & 0xf) << FMC_SDTR_TRAS_SHIFT;
	result |= ((t->txsr - 1) & 0xf) << FMC_SDTR_TXSR_SHIFT;
	result |= ((t->tmrd - 1) & 0xf) << FMC_SDTR_TMRD_SHIFT;
	return result;
}

/*
 * Send a command to the SDRAM controller, wait until it is not
 * busy before sending. This allows you to chain sending commands
 * and the code will pause as needed between them.
 */
void
sdram_command(enum fmc_sdram_bank bank,
	      enum fmc_sdram_command cmd, int autorefresh, int modereg) {
	uint32_t tmp_reg = 0;

	switch (bank) {
	case SDRAM_BANK1:
		tmp_reg = FMC_SDCMR_CTB1;
		break;
	case SDRAM_BANK2:
		tmp_reg = FMC_SDCMR_CTB2;
		break;
	case SDRAM_BOTH_BANKS:
		tmp_reg = FMC_SDCMR_CTB1 | FMC_SDCMR_CTB2;
		break;
	}
	tmp_reg |= autorefresh << FMC_SDCMR_NRFS_SHIFT;
	tmp_reg |= modereg << FMC_SDCMR_MRD_SHIFT;
	switch (cmd) {
	case SDRAM_CLK_CONF:
		tmp_reg |= FMC_SDCMR_MODE_CLOCK_CONFIG_ENA;
		break;
	case SDRAM_AUTO_REFRESH:
		tmp_reg |= FMC_SDCMR_MODE_AUTO_REFRESH;
		break;
	case SDRAM_LOAD_MODE:
		tmp_reg |= FMC_SDCMR_MODE_LOAD_MODE_REGISTER;
		break;
	case SDRAM_PALL:
		tmp_reg |= FMC_SDCMR_MODE_PALL;
		break;
	case SDRAM_SELF_REFRESH:
		tmp_reg |= FMC_SDCMR_MODE_SELF_REFRESH;
		break;
	case SDRAM_POWER_DOWN:
		tmp_reg |= FMC_SDCMR_MODE_POWER_DOWN;
		break;
	case SDRAM_NORMAL:
	default:
		break;
	}

	/* Wait for the next chance to talk to the controller */
	while (FMC_SDSR & FMC_SDSR_BUSY);

	/* Send the next command */
	FMC_SDCMR = tmp_reg;
}

/**@}*/
