/** @addtogroup fdcan_file FDCAN peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32 FDCAN</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
 *
 * Devices can have up to three FDCAN peripherals residing in one FDCAN block. The peripherals
 * support both CAN 2.0 A and B standard and Bosch FDCAN standard. FDCAN frame format and
 * bitrate switching is supported. The peripheral has several filters for incoming messages that
 * can be distributed between two FIFOs and three transmit mailboxes. For transmitted messages
 * it is possible to opt for event notification once message is transmitted.
 *
 * LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
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

#include <libopencm3/stm32/fdcan.h>
#include <libopencm3/stm32/rcc.h>
#include <stddef.h>

/* --- FD-CAN functions ----------------------------------------------------- */

/** @ingroup fdcan_file */
/**@{
 * */

/** Returns actual size of FIFO entry in FIFO for given CAN port and FIFO.
 *
 * Obtains value of FIFO entry length. For G4 it returns constant value as
 * G4 has FIFO element length hardcoded.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block. Unused.
 * @param [in] fifo_id ID of FIFO whole length is queried. Unused.
 * @returns Length of FIFO entry length covering frame header and frame payload.
 */
unsigned fdcan_get_fifo_element_size(uint32_t canport, unsigned fifo_id)
{
	/* Silences compiler. Variables are present for API compatibility
	 * with STM32H7
	 */
	(void) (canport);
	(void) (fifo_id);
	return sizeof(struct fdcan_rx_fifo_element);
}

/** Returns actual size of transmit entry in transmit queue/FIFO for given CAN port.
 *
 * Obtains value of entry length in transmit queue/FIFO. For G4 it returns constant value
 * as G4 has transmit buffer entries of fixed length.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block. Unused.
 * @returns Length of FIFO entry length covering frame header and frame payload.
 */
unsigned fdcan_get_txbuf_element_size(uint32_t canport)
{
	/* Silences compiler. Variables are present for API compatibility
	 * with STM32H7
	 */
	(void) (canport);
	return sizeof(struct fdcan_tx_buffer_element);
}

/** Configure amount of filters and initialize filtering block.
 *
 * This function allows to configure global amount of filters present.
 * FDCAN block will only ever check as many filters as this function configures.
 * Function will also clear all filter blocks to zero values. This function
 * can be only called after @ref fdcan_init has already been called and
 * @ref fdcan_start has not been called yet as registers holding filter
 * count are write-protected unless FDCAN block is in INIT mode. It is possible
 * to reconfigure filters (@ref fdcan_set_std_filter and @ref fdcan_set_ext_filter)
 * after FDCAN block has already been started.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] std_filt requested amount of standard ID filter rules (0-28)
 * @param [in] ext_filt requested amount of extended ID filter rules (0-8)
 */
void fdcan_init_filter(uint32_t canport, uint8_t std_filt, uint8_t ext_filt)
{
	struct fdcan_standard_filter *lfssa = fdcan_get_flssa_addr(canport);
	struct fdcan_extended_filter *lfesa = fdcan_get_flesa_addr(canport);

	/* Only perform initialization of message RAM if there are
	 * any filters required
	 */
	if (std_filt > 0) {
		FDCAN_RXGFC(canport) =
			(FDCAN_RXGFC(canport) & ~(FDCAN_RXGFC_LSS_MASK << FDCAN_RXGFC_LSS_SHIFT))
			| (std_filt << FDCAN_RXGFC_LSS_SHIFT);


		for (int q = 0; q < FDCAN_SFT_MAX_NR; ++q) {
			lfssa[q].type_id1_conf_id2 = 0;
		}
	} else {
		/* Reset filter count to zero */
		FDCAN_RXGFC(canport) =
			(FDCAN_RXGFC(canport) & ~(FDCAN_RXGFC_LSS_MASK << FDCAN_RXGFC_LSS_SHIFT));
	}

	if (ext_filt > 0) {
		FDCAN_RXGFC(canport) =
			(FDCAN_RXGFC(canport) & ~(FDCAN_RXGFC_LSE_MASK << FDCAN_RXGFC_LSE_SHIFT))
			| (ext_filt << FDCAN_RXGFC_LSE_SHIFT);

		for (int q = 0; q < FDCAN_EFT_MAX_NR; ++q) {
			lfesa[q].conf_id1 = 0;
			lfesa[q].type_id2 = 0;
		}
	} else {
		/* Reset filter count to zero */
		FDCAN_RXGFC(canport) =
			(FDCAN_RXGFC(canport) & ~(FDCAN_RXGFC_LSE_MASK << FDCAN_RXGFC_LSE_SHIFT));
	}
}

/** Enable FDCAN operation after FDCAN block has been set up.
 *
 * This function will disable FDCAN configuration effectively
 * allowing FDCAN to sync up with the bus. After calling this function
 * it is not possible to reconfigure amount of filter rules, yet
 * it is possible to configure rules themselves. FDCAN block operation
 * state can be checked using @ref fdcan_get_init_state.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] timeout Amount of empty busy loops, which routine should wait for FDCAN
 *				confirming that it left INIT mode. If set to 0, function will return
 *				immediately.
 * @returns Operation error status. See @ref fdcan_error.
 * @note If this function returns with timeout, it usually means that
 * FDCAN_clk is not set up properly.
 */
int fdcan_start(uint32_t canport, uint32_t timeout)
{
	/* Error here usually means, that FDCAN_clk is not set up
	 * correctly, or at all. This usually can't be seen above
	 * when INIT is set to 1, because default value for INIT is
	 * 1 as long as one has FDCAN_pclk configured properly.
	 **/
	if (fdcan_cccr_init_cfg(canport, false, timeout) != 0) {
		return FDCAN_E_TIMEOUT;
	}

	return FDCAN_E_OK;
}

/** Configure FDCAN FIFO lock mode
 *
 * This function allows to choose between locked and overewrite mode of FIFOs. In locked mode,
 * whenever FIFO is full and new frame arrives, which would normally been stored into given
 * FIFO, then frame is dropped. If overwrite mode is active, then most recent message in FIFO
 * is rewritten by frame just received.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] locked true activates locked mode, false activates overwrite mode
 */
void fdcan_set_fifo_locked_mode(uint32_t canport, bool locked)
{
	if (locked) {
		FDCAN_RXGFC(canport) &= ~(FDCAN_RXGFC_F1OM | FDCAN_RXGFC_F0OM);
	} else {
		FDCAN_RXGFC(canport) |= FDCAN_RXGFC_F1OM | FDCAN_RXGFC_F0OM;
	}
}

/** @} */
