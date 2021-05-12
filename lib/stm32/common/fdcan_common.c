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


/* --- FD-CAN internal functions -------------------------------------------- */

/** Routine implementing FDCAN_CCCR's INIT bit manipulation.
 *
 * This routine will change INIT bit and wait for it to actually
 * change its value. If change won't happen before timeout,
 * error is signalized. If INIT bit already has value which
 * should be set, this function will return immediately.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] set new value of INIT, true means set
 * @param [in] timeout Amount of busyloop cycles, function will wait for FDCAN
 *		to switch it's state. If set to 0, then function returns immediately.
 * @returns FDCAN_E_OK on success, FDCAN_E_TIMEOUT if INIT bit value
 * didn't change before timeout has expired.
 */
int fdcan_cccr_init_cfg(uint32_t canport, bool set, uint32_t timeout)
{
	uint32_t expected;
	uint32_t wait_ack;

	if (set) {
		if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == FDCAN_CCCR_INIT) {
			/* Already there, sir */
			return FDCAN_E_OK;
		}

		FDCAN_CCCR(canport) |= FDCAN_CCCR_INIT;
		expected = FDCAN_CCCR_INIT;
	} else {
		if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == 0) {
			/* Already there, sir */
			return FDCAN_E_OK;
		}

		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_INIT;
		expected = 0;
	}

	/* Wait, until INIT bit is acknowledged */
	wait_ack = timeout;
	while ((wait_ack--) &&
			((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == expected));

	if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == expected) {
		return FDCAN_E_OK;
	} else {
		return FDCAN_E_TIMEOUT;
	}
}

/** Return ID of next free Tx buffer.
 *
 * Examines transmit buffer allocation in message RAM
 * and returns ID of buffer, which is free.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @returns Non-negative number ID of Tx buffer which is free,
 * or FDCAN_E_BUSY if no Tx buffer is available
 */
static int fdcan_get_free_txbuf(uint32_t canport)
{
	if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP0) == 0) {
		return 0;
	} else if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP1) == 0) {
		return 1;
	} else if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP2) == 0) {
		return 2;
	}

	return FDCAN_E_BUSY;
}

/** Returns fill state and next available get index from receive FIFO.
 *
 * Examines FDCAN receive FIFO and returns fill status of FIFO and ID of
 * next message available for reading. If fill status is 0 (FIFO is empty),
 * then get index is undefined.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] fifo_id ID of fifo queried (currently 0 or 1)
 * @param [out] get_index Address of buffer where next get index will be stored
 * @param [out] pending_frames Address of buffer where amount of pending frame will be stored.
 */
static void fdcan_get_fill_rxfifo(uint32_t canport, uint8_t fifo_id, unsigned *get_index,
		unsigned *pending_frames)
{
	*get_index = (FDCAN_RXFIS(canport, fifo_id) >> FDCAN_RXFIFO_GI_SHIFT)
		& FDCAN_RXFIFO_GI_MASK;

	*pending_frames = (FDCAN_RXFIS(canport, fifo_id) >> FDCAN_RXFIFO_FL_SHIFT)
		& FDCAN_RXFIFO_FL_MASK;
}

/** Returns standard filter start address in message RAM
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @returns Base address of standard filter configuration block.
 */
struct fdcan_standard_filter *fdcan_get_flssa_addr(uint32_t canport)
{
	struct fdcan_standard_filter *lfssa = (struct fdcan_standard_filter *)
		(CAN_MSG_BASE + FDCAN_LFSSA_OFFSET(canport));
	return lfssa;
}

/** Returns extended filter start address in message RAM
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @returns Base address of extended filter configuration block.
 */
struct fdcan_extended_filter *fdcan_get_flesa_addr(uint32_t canport)
{
	struct fdcan_extended_filter *lfesa = (struct fdcan_extended_filter *)
		(CAN_MSG_BASE + FDCAN_LFESA_OFFSET(canport));
	return lfesa;
}

/** Returns a pointer to an RX FIFO element in message RAM
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] fifo_id ID of FIFO whose address is requested
 * @param [in] element_id the element number in the fifo we're requesting
 * @returns a pointer to the individual element in the message ram
 */
struct fdcan_rx_fifo_element *fdcan_get_rxfifo_addr(uint32_t canport,
		unsigned fifo_id, unsigned element_id)
{
	struct fdcan_rx_fifo_element *rxfifo = (struct fdcan_rx_fifo_element *)
		(CAN_MSG_BASE + FDCAN_RXFIFO_OFFSET(canport, fifo_id)
		 + (element_id * fdcan_get_fifo_element_size(canport, fifo_id))
		 );
	return rxfifo;
}

/** Returns transmit event start address in message RAM
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @returns Base address of transmit event block.
 */
struct fdcan_tx_event_element *fdcan_get_txevt_addr(uint32_t canport)
{
	struct fdcan_tx_event_element *rxfifo = (struct fdcan_tx_event_element *)
		(CAN_MSG_BASE + FDCAN_TXEVT_OFFSET(canport));
	return rxfifo;
}

/** Returns a pointer to an TX FIFO element in message RAM
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] element_id the element number in the fifo we're requesting
 * @returns a pointer to the individual element in the message ram
 */
struct fdcan_tx_buffer_element *fdcan_get_txbuf_addr(uint32_t canport, unsigned element_id)
{
	struct fdcan_tx_buffer_element *rxfifo = (struct fdcan_tx_buffer_element *)
		(CAN_MSG_BASE + FDCAN_TXBUF_OFFSET(canport)
		 + (element_id * fdcan_get_txbuf_element_size(canport))
		 );

	return rxfifo;
}

/** Converts frame length to DLC value.
 *
 * Works for both CAN and FDCAN frame lengths. If length
 * is invalid value, then returns 0xFF.
 *
 * @param [in] length intended frame payload length in bytes
 * @returns DLC value representing lengths or 0xFF if length cannot
 * be encoded into DLC format (applies only to FDCAN frame lengths)
 */
uint32_t fdcan_length_to_dlc(uint8_t length)
{
	if (length <= 8) {
		return length;
	} else if (length <= 24) {
		if ((length % 4) != 0) {
			return 0xFF;
		}
		return 8 + ((length - 8) / 4);
	} else {
		if ((length % 16) != 0) {
			return 0xFF;
		}
		return 11 + (length / 16);
	}
}

/** Converts DLC value into frame payload length.
 *
 * Works for both CAN and FDCAN DLC values.
 *
 * @param [in] dlc DLC value
 * @returns data payload length in bytes
 */
uint8_t fdcan_dlc_to_length(uint32_t dlc)
{
	if (dlc <= 8) {
		return dlc;
	} else if (dlc <= 12) {
		return 8 + ((dlc - 8) * 4);
	} else {
		return 16 + ((dlc - 12) * 16);
	}
}

/* --- FD-CAN functions ----------------------------------------------------- */

/** @ingroup fdcan_file */
/**@{
 * */

/** Put FDCAN block into INIT mode for setup
 *
 * Initialize the selected CAN peripheral block. This function will switch CAN block
 * into initialization mode. CAN block is then left in initialization mode in order to
 * perform setup, which can't be adjusted once FDCAN block is started. It is mandatory
 * to call at least @ref fdcan_set_can function to configure basic timing values for
 * CAN 2.0 operation. Functions which only have effect, if FDCAN block is in INIT mode
 * are:
 * * @ref fdcan_set_can
 * * @ref fdcan_set_fdcan
 * * @ref fdcan_init_filter
 * * @ref fdcan_set_test
 *
 * You can check if FDCAN block is in INIT mode or it is started using
 * @ref fdcan_get_init_state.
 *
 * @param[in] canport CAN register base address. See @ref fdcan_block.
 * @param [in] timeout Amount of empty busy loops, which routine should wait for FDCAN
 *				confirming that it entered INIT mode. If set to 0, function will
 *				return immediately.
 * @returns Operation error status. See @ref fdcan_error.
 */
int fdcan_init(uint32_t canport, uint32_t timeout)
{
	if (fdcan_cccr_init_cfg(canport, true, timeout) != 0) {
		return FDCAN_E_TIMEOUT;
	}

	FDCAN_CCCR(canport) |= FDCAN_CCCR_CCE;

	return FDCAN_E_OK;
}

/** Set essential FDCAN block parameters for plain CAN operation
 *
 * Allows configuration of prescalers and essential transmit and FIFO behavior
 * used during transmission in plain CAN 2.0 mode. In this mode FDCAN frame format
 * is not available nor is possible to use fast bitrates.
 * This function does neither enable FD-CAN mode after reset nor disable it
 * after re-entering INIT mode of previously configured block. Timing values set
 * here are valid for both arbitration phase of all frames and for data phase of
 * both CAN and FDCAN frames, which don't use bitrate switching. This function can
 * only be called after FDCAN block has been switched into INIT mode.
 * It is possible to receive FDCAN frames even if FDCAN block is configured only using
 * this function as long as bitrate switching is not used.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] auto_retry_disable Disable automatic frame retransmission on error
 * @param [in] rx_fifo_locked Enable FIFO locked mode. Upon FIFO overflow all received
 *				messages are discarded.
 * @param [in] tx_queue_mode Enable transmission queue mode. Otherwise transmission
 *				works in FIFO mode.
 * @param [in] silent Enable silent mode. Transmitter stays recessive all the time.
 * @param [in] n_sjw Resynchronization time quanta jump width
 * @param [in] n_ts1 Time segment 1 time quanta
 * @param [in] n_ts2 Time segment 2 time quanta
 * @param [in] n_br_presc Arbitration phase / CAN mode bitrate prescaler
 */
void fdcan_set_can(uint32_t canport, bool auto_retry_disable, bool rx_fifo_locked,
		bool tx_queue_mode,	bool silent, uint32_t n_sjw, uint32_t n_ts1, uint32_t n_ts2,
		uint32_t n_br_presc)
{
	FDCAN_NBTP(canport) = (n_sjw << FDCAN_NBTP_NSJW_SHIFT)
		| (n_ts1 << FDCAN_NBTP_NTSEG1_SHIFT)
		| (n_ts2 << FDCAN_NBTP_NTSEG2_SHIFT)
		| (n_br_presc << FDCAN_NBTP_NBRP_SHIFT);

	if (tx_queue_mode) {
		FDCAN_TXBC(canport) |= FDCAN_TXBC_TFQM;
	} else {
		FDCAN_TXBC(canport) &= ~FDCAN_TXBC_TFQM;
	}

	if (auto_retry_disable) {
		FDCAN_CCCR(canport) |= FDCAN_CCCR_DAR;
	} else {
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_DAR;
	}

	if (silent) {
		FDCAN_CCCR(canport) |= FDCAN_CCCR_MON;
	} else {
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_MON;
	}

	fdcan_set_fifo_locked_mode(canport, rx_fifo_locked);
}

/** Set FDCAN block parameters for FDCAN transmission
 *
 * Enables and configures parameters related to FDCAN transmission. This function
 * allows configuration of bitrate switching, FDCAN frame format and fast mode
 * timing. This function can only be called if FDCAN block is in INIT mode.
 * It is safe to call this function on previously configured block in order
 * to enable/disable/change FDCAN mode parameters. Non-FDCAN parameters won't
 * be affected.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] brs_enable Enable FDCAN bitrate switching for fast mode operation
 * @param [in] fd_op_enable Enable transmission of FDCAN-formatted frames
 * @param [in] f_sjw Resynchronization time quanta jump width in fast mode
 * @param [in] f_ts1 Time segment 1 time quanta in fast mode
 * @param [in] f_ts2 Time segment 2 time quanta in fast mode
 * @param [in] f_br_presc Fast mode operation bitrate prescaler
 */
void fdcan_set_fdcan(uint32_t canport, bool brs_enable, bool fd_op_enable,
		uint32_t f_sjw, uint32_t f_ts1, uint32_t f_ts2, uint32_t f_br_presc)
{
	FDCAN_DBTP(canport) = (f_sjw << FDCAN_DBTP_DSJW_SHIFT)
		| (f_ts1 << FDCAN_DBTP_DTSEG1_SHIFT)
		| (f_ts2 << FDCAN_DBTP_DTSEG2_SHIFT)
		| (f_br_presc << FDCAN_DBTP_DBRP_SHIFT);

	if (fd_op_enable) {
		FDCAN_CCCR(canport) |= FDCAN_CCCR_FDOE;
	} else {
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_FDOE;
	}

	if (brs_enable) {
		FDCAN_CCCR(canport) |= FDCAN_CCCR_BRSE;
	} else {
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_BRSE;
	}
}

/** Set FDCAN block testing features.
 *
 * Configures self-test functions of FDCAN block. It is safe to call
 * this function on fully configured interface. This function can
 * only be called after FDCAN block is put into INIT mode.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] testing Enables testing mode of FDCAN block
 * @param [in] loopback Enables transmission loopback
 */
void fdcan_set_test(uint32_t canport, bool testing, bool loopback)
{
	if (testing) {
		FDCAN_CCCR(canport) |= FDCAN_CCCR_TEST;
		if (loopback) {
			FDCAN_TEST(canport) |= FDCAN_TEST_LBCK;
		} else {
			FDCAN_TEST(canport) &= ~FDCAN_TEST_LBCK;
		}
	} else {
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_TEST;
		/* FDCAN_TEST is automatically reset to default values by
		 * FDCAN at this point */
	}
}

/** Return current FDCAN block operation state.
 *
 * This function effectively returns value of FDCAN_CCCR's INIT bit.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @returns 1 if FDCAN block is in INIT mode, 0 if it is already started.
 */
int fdcan_get_init_state(uint32_t canport)
{
	return ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == FDCAN_CCCR_INIT);
}

/** Configure filter rule for standard ID frames.
 *
 * Sets up filter rule for frames having standard ID. Each FDCAN block can
 * have its own set of filtering rules. It is only possible to configure as
 * many filters as was configured previously using @ref fdcan_init_filter.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] nr number of filter to be configured
 * @param [in] id_list_mode Mode in which id1 and id2 are used to match the rule.
 *				See @ref fdcan_sft.
 * @param [in] id1 standard ID for matching. Used as exact value, lower bound or bit
 *				pattern depending on matching mode selected
 * @param [in] id2 standard ID or bitmask. Used as exact value, upper bound or bit mask
 *				depending on matching mode selected
 * @param [in] action Action performed if filtering rule matches frame ID.
 *				See @ref fdcan_sfec.
 */
void fdcan_set_std_filter(uint32_t canport, uint32_t nr,
			uint8_t id_list_mode, uint32_t id1, uint32_t id2,
			uint8_t action)
{
	struct fdcan_standard_filter *lfssa = fdcan_get_flssa_addr(canport);

	/* id_list_mode and action are passed unguarded. Simply use
	 * defines and it will be OK. id1 and id2 are masked for
	 * correct size, because it is way too simple to pass ID
	 * larger than 11 bits unintentionally. It then leads to all
	 * kind of extremely weird errors while excessive ID bits
	 * overflow into flags. This tends to be extremely time
	 * consuming to debug.
	 */
	lfssa[nr].type_id1_conf_id2 =
		(id_list_mode << FDCAN_SFT_SHIFT)
		| (action << FDCAN_SFEC_SHIFT)
		| ((id1 & FDCAN_SFID1_MASK) << FDCAN_SFID1_SHIFT)
		| ((id2 & FDCAN_SFID2_MASK) << FDCAN_SFID2_SHIFT);

	return;
}

/** Configure filter rule for extended ID frames.
 *
 * Sets up filter rule for frames having extended ID. Each FDCAN block can
 * have its own set of filtering rules. It is only possible to configure as
 * many filters as was configured previously using @ref fdcan_init_filter.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] nr number of filter to be configured
 * @param [in] id_list_mode mode in which id1 and id2 are used to match the rule.
 *				See @ref fdcan_eft.
 * @param [in] id1 extended ID for matching. Used as exact value, lower bound or bit
 *				pattern depending on matching mode selected
 * @param [in] id2 extended ID or bitmask. Used as exact value, upper bound or bit mask
 *				depending on matching mode selected
 * @param [in] action Action performed if filtering rule matches frame ID.
 *				See @ref fdcan_efec.
 */
void fdcan_set_ext_filter(uint32_t canport, uint32_t nr,
			uint8_t id_list_mode, uint32_t id1, uint32_t id2,
			uint8_t action)
{
	struct fdcan_extended_filter *lfesa = fdcan_get_flesa_addr(canport);

	lfesa[nr].conf_id1 =
		(action << FDCAN_EFEC_SHIFT)
		| ((id1 & FDCAN_EFID1_MASK) << FDCAN_EFID1_SHIFT);

	lfesa[nr].type_id2 =
		(id_list_mode << FDCAN_EFT_SHIFT)
		| ((id2 & FDCAN_EFID2_MASK) << FDCAN_EFID2_SHIFT);
}

/** Transmit Message using FDCAN
 *
 * @param [in] canport CAN block register base. See @ref fdcan_block.
 * @param [in] id Message ID
 * @param [in] ext Extended message ID
 * @param [in] rtr Request transmit
 * @param [in] fdcan_fmt Use FDCAN format
 * @param [in] btr_switch Switch bitrate for data portion of frame
 * @param [in] length Message payload length. Must be valid CAN or FDCAN frame length
 * @param [in] data Message payload data
 * @returns int 0, 1 or 2 on success and depending on which outgoing mailbox got
 * selected. Otherwise returns error code. For error codes, see @ref fdcan_error.
 */
int fdcan_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
			bool fdcan_fmt, bool btr_switch, uint8_t length, const uint8_t *data)
{
	int mailbox;
	uint32_t dlc, flags = 0;

	mailbox = fdcan_get_free_txbuf(canport);

	if (mailbox == FDCAN_E_BUSY) {
		return mailbox;
	}

	struct fdcan_tx_buffer_element *tx_buffer = fdcan_get_txbuf_addr(canport, mailbox);

	/* Early check: if FDCAN message lentgh is > 8, it must be
	 * a multiple of 4 *and* fdcan format must be enabled.
	 */
	dlc = fdcan_length_to_dlc(length);

	if (dlc == 0xFF) {
		return FDCAN_E_INVALID;
	}

	if (ext) {
		tx_buffer->identifier_flags = FDCAN_FIFO_XTD
			| ((id & FDCAN_FIFO_EID_MASK) << FDCAN_FIFO_EID_SHIFT);
	} else {
		tx_buffer->identifier_flags =
			(id & FDCAN_FIFO_SID_MASK) << FDCAN_FIFO_SID_SHIFT;
	}

	if (rtr) {
		tx_buffer->identifier_flags |= FDCAN_FIFO_RTR;
	}

	if (fdcan_fmt) {
		flags |= FDCAN_FIFO_FDF;
	}

	if (btr_switch) {
		flags |= FDCAN_FIFO_BRS;
	}

	tx_buffer->evt_fmt_dlc_res =
		(dlc << FDCAN_FIFO_DLC_SHIFT) | flags;

	for (int q = 0; q < length; q += 4) {
		tx_buffer->data[q / 4] = *((uint32_t *) &data[q]);
	}

	FDCAN_TXBAR(canport) |= 1 << mailbox;

	return mailbox;
}

/** Receive Message from FDCAN FIFO
 *
 * Reads one message from receive FIFO. Returns message ID, type of ID, message length
 * and message payload. It is mandatory to provide valid pointers to suitably sized buffers
 * for these outputs. Additionally, it is optinally possible to provide non-zero pointer to
 * obtain filter identification, request of transmission flag and message timestamp.
 * If pointers provided for optional outputs are NULL, then no information is returned
 * for given pointer.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block
 * @param [in] fifo_id FIFO id.
 * @param [in] release Release the FIFO automatically after copying data out
 * @param [out] id Returned message ID. Mandatory.
 * @param [out] ext Returned type of the message ID (true if extended). Mandatory.
 * @param [out] rtr Returnes flag if request of transmission was requested. Optional.
 * @param [out] fmi Returned ID of the filter which matched this frame. Optional.
 * @param [out] length Length of message payload in bytes. Mandatory.
 * @param [out] data Buffer for storage of message payload data. Mandatory.
 * @param [out] timestamp Returned timestamp of received frame. Optional.
 * @returns Operation error status. See @ref fdcan_error.
 */
int fdcan_receive(uint32_t canport, uint8_t fifo_id, bool release, uint32_t *id,
		 bool *ext, bool *rtr, uint8_t *fmi, uint8_t *length,
		 uint8_t *data, uint16_t *timestamp)
{
	unsigned pending_frames, get_index, dlc, len;

	fdcan_get_fill_rxfifo(canport, fifo_id, &get_index, &pending_frames);

	if (pending_frames == 0) {
		return FDCAN_E_NOTAVAIL;
	}

	const struct fdcan_rx_fifo_element *fifo = fdcan_get_rxfifo_addr(canport,
			fifo_id, get_index);

	dlc = (fifo->filt_fmt_dlc_ts >> FDCAN_FIFO_DLC_SHIFT)
		& FDCAN_FIFO_DLC_MASK;

	len = fdcan_dlc_to_length(dlc);

	*length = len;
	if ((fifo->identifier_flags & FDCAN_FIFO_XTD) == FDCAN_FIFO_XTD) {
		*ext = true;
		*id = (fifo->identifier_flags >> FDCAN_FIFO_EID_SHIFT)
			& FDCAN_FIFO_EID_MASK;
	} else {
		*ext = false;
		*id = (fifo->identifier_flags >> FDCAN_FIFO_SID_SHIFT)
			& FDCAN_FIFO_SID_MASK;
	}

	if (timestamp) {
		*timestamp = (uint16_t) (fifo->filt_fmt_dlc_ts >> FDCAN_FIFO_RXTS_SHIFT)
			& FDCAN_FIFO_RXTS_MASK;
	}

	if (fmi) {
		*fmi = (uint8_t) (fifo->filt_fmt_dlc_ts >> FDCAN_FIFO_MM_SHIFT)
			& FDCAN_FIFO_MM_MASK;
	}

	if (rtr) {
		*rtr = ((fifo->identifier_flags & FDCAN_FIFO_RTR) == FDCAN_FIFO_RTR);
	}

	for (unsigned int q = 0; q < len; q += 4) {
		*((uint32_t *) &data[q]) = fifo->data[q / 4];
	}

	if (release) {
		FDCAN_RXFIA(canport, fifo_id) = get_index << FDCAN_RXFIFO_AI_SHIFT;
	}

	return FDCAN_E_OK;
}

/** Release receive oldest FIFO entry.
 *
 * This function will mask oldest entry in FIFO as released making
 * space for another received frame. This function can be used if
 * fdcan_receive was called using release = false. If used in other
 * case, then messages can get lost.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] fifo_id ID of FIFO where release should be performed (0 or 1)
 */
void fdcan_release_fifo(uint32_t canport, uint8_t fifo_id)
{
	unsigned pending_frames, get_index;

	get_index = (FDCAN_RXFIS(canport, fifo_id) >> FDCAN_RXFIFO_GI_SHIFT)
		& FDCAN_RXFIFO_GI_SHIFT;

	pending_frames = (FDCAN_RXFIS(canport, fifo_id) >> FDCAN_RXFIFO_FL_SHIFT)
		& FDCAN_RXFIFO_FL_SHIFT;

	if (pending_frames) {
		FDCAN_RXFIA(canport, fifo_id) |= get_index << FDCAN_RXFIFO_AI_SHIFT;
	}
}

/** Enable IRQ from FDCAN block.
 *
 * This routine configures FDCAN to enable certain IRQ.
 * Each FDCAN block supports two IRQs.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] irq number of IRQ to be enabled (currently 0 or 1)
 */
void fdcan_enable_irq(uint32_t canport, uint32_t irq)
{
	FDCAN_ILE(canport) |= irq & (FDCAN_ILE_INT0 | FDCAN_ILE_INT1);
}

/** Disable IRQ from FDCAN block.
 *
 * This routine configures FDCAN to disable certain IRQ.
 * Each FDCAN block supports two IRQs.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] irq number of IRQ to be enabled (currently 0 or 1)
 */
void fdcan_disable_irq(uint32_t canport, uint32_t irq)
{
	FDCAN_ILE(canport) &= ~(irq & (FDCAN_ILE_INT0 | FDCAN_ILE_INT1));
}

/** Check if there is free transmit buffer.
 *
 * @param [in] canport FDCAN port. See @ref fdcan_block.
 * @returns true if there is at least one free transmit buffer for new message
 * to be sent, false otherwise.
 */
bool fdcan_available_tx(uint32_t canport)
{
	return (fdcan_get_free_txbuf(canport) != FDCAN_E_BUSY);
}

/** Tell if there is message waiting in receive FIFO.
 *
 * @param [in] canport FDCAN port. See @ref fdcan_block.
 * @param [in] fifo Rx FIFO number, 0 or 1
 * @returns true if there is at least one message waiting in given receive FIFO,
 * false otherwise.
 */
bool fdcan_available_rx(uint32_t canport, uint8_t fifo)
{
	unsigned pending_frames;

	pending_frames = (FDCAN_RXFIS(canport, fifo) >> FDCAN_RXFIFO_FL_SHIFT)
		& FDCAN_RXFIFO_FL_MASK;

	return (pending_frames != 0);
}

/**@}*/


