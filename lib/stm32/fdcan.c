/** @defgroup fdcan_file FDCAN peripheral API
 * @ingroup peripheral_apis
 * 
 * @brief <b>libopencm3 STM32G4xx CAN</b>
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


/* Timeout for FDCAN_CCCR register INIT bit to accept set value.
 * This timeout is required because FDCAN uses two different clocks
 * feeding two different portions of block. There can be slight delay
 * based on how clocks are set up. While amount of FDCAN_clk /
 * FDCAN_pclk combinations is high and clock speeds may vary a lot,
 * following value has been choosen as sane default.
 */
#define FDCAN_CCCR_INIT_TIMEOUT		0x0000FFFF

static int fdcan_cccr_init_cfg(uint32_t canport, bool set);
static int fdcan_get_fill_rxfifo(uint32_t canport, uint8_t fifo_id, 
		unsigned * get_index, unsigned * pending_frames);
static struct FDCAN_MessageRAM * fdcan_get_msgram_addr(uint32_t canport);
static int fdcan_get_free_txbuf(uint32_t canport);
static uint32_t fdcan_length_to_dlc(uint8_t length);
static uint8_t fdcan_dlc_to_length(uint32_t dlc);

/** @ingroup fdcan_file */
/**@{
 * */

/** @brief FDCAN Reset
 *
 * This will reset the FDCAN peripheral. All registers will be placed in
 * the reset state. Note that it is not possible to reset FDCAN per-CAN
 */
void fdcan_reset(void)
{
	rcc_periph_reset_pulse(RST_FDCAN);
}


/* @brief FDCAN Init
 * Initialize the selected CAN peripheral block. This function will switch CAN block
 * into initialization mode and set crucial configuration flags and timing registers.
 * CAN block is then left in initialization mode in order to 
 * 
 * @param[in] canport Unsigend int32. CAN register base address @ref can_reg_base.
 * @param[in] brs bool. Enable bitrate switching during Tx (only avaiable if FDCAN operation is also enabled)
 * @param[in] fdoe Enable FDCAN operation
 * @param[in] nart Disable automatic retransmission
 * @param[in] rflm Turn on receive FIFO locked mode, otherwize FIFO is in overwrite mode
 * @param[in] txqm Switch Tx into queue mode, if false then Tx works in FIFO mode 
 * @param[in] sjw Resynchronization time quanta jump width.
 * @param[in] ts1 Time segment 1 time quanta width.
 * @param[in] ts2 Time segment 2 time quanta width.
 * @param[in] brp Baud rate prescaler.
 * @param[in] loopback Turn on loopback mode
 * @param[in] silent Turn on silent (monitor) mode
 * @returns int FDCAN_E_OK on success, FDCAN_E_TIMEOUT on timeout waiting for INIT bit to flip.
 */
int fdcan_init(uint32_t canport, bool brs_enable, bool fd_op_enable, 
		 bool auto_retr_disable, bool rx_fifo_locked, bool tx_queue_mode, 
		 uint32_t n_sjw, uint32_t n_ts1, uint32_t n_ts2, uint32_t n_br_presc, 
		 uint32_t f_sjw, uint32_t f_ts1, uint32_t f_ts2, uint32_t f_br_presc, 
		 bool loopback, bool silent)
{
	if (fdcan_cccr_init_cfg(canport, true) != 0)
	{
		return FDCAN_E_TIMEOUT;
	}

	FDCAN_CCCR(canport) |= FDCAN_CCCR_CCE;
	
	FDCAN_DBTP(canport) = (f_sjw & FDCAN_DBTP_DSJW_MASK)
		| (f_ts1 & FDCAN_DBTP_DTSEG1_MASK)
		| (f_ts2 & FDCAN_DBTP_DTSEG2_MASK)
		| ((f_br_presc << FDCAN_DBTP_DBRP_SHIFT) & FDCAN_DBTP_DBRP_MASK);

	FDCAN_NBTP(canport) = (n_sjw & FDCAN_NBTP_NSJW_MASK)
		| (n_ts1 & FDCAN_NBTP_NTSEG1_MASK)
		| (n_ts2 & FDCAN_NBTP_NTSEG2_MASK)
		| ((n_br_presc << FDCAN_NBTP_NBRP_SHIFT) & FDCAN_NBTP_NBRP_MASK);

	if (fd_op_enable)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_FDOE;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_FDOE;
	}

	if (brs_enable)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_BRSE;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_BRSE;
	}

	if (tx_queue_mode)
	{
		FDCAN_TXBC(canport) |= FDCAN_TXBC_TFQM;
	}
	else
	{
		FDCAN_TXBC(canport) &= ~FDCAN_TXBC_TFQM;
	}

	if (auto_retr_disable)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_DAR;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_DAR;
	}

	if (silent)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_MON;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_MON;
	}

	if (rx_fifo_locked)
	{
		FDCAN_RXGFC(canport) &= ~(FDCAN_RXGFC_F1OM | FDCAN_RXGFC_F0OM);
	}
	else
	{
		FDCAN_RXGFC(canport) |= FDCAN_RXGFC_F1OM | FDCAN_RXGFC_F0OM;
	}

	if (loopback)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_TEST;
		FDCAN_TEST(canport) |= FDCAN_TEST_LBCK;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_TEST;
		/* FDCAN_TEST is automatically reset to default values by FDCAN 
		 * at this point
		 **/
	}

	return FDCAN_E_OK;
}

/** Enable FDCAN operation after FDCAN block has been set up.
 * This function will disable FDCAN configuration effectively
 * allowing FDCAN to sync up with the bus. After calling this function
 * it is not possible to reconfigure amount of filter rules, yet
 * it is possible to configure rules themselves.
 * @param canport FDCAN block base address (use CANx defines)
 * @returns FDCAN_E_OK on success, FDCAN_E_TIMEOUT if operation timed out.
 * @Note If this function returns with timeout, it usually means that 
 * FDCAN_clk is not set up properly.
 */
int fdcan_start(uint32_t canport)
{
	/* Error here usually means, that FDCAN_clk is not set up
	 * correctly, or at all. This usually can't be seen above
	 * when INIT is set to 1, because default value for INIT is
	 * 1 as long as one has FDCAN_pclk configured properly. 
	 **/
	if (fdcan_cccr_init_cfg(canport, false) != 0)
	{
		return FDCAN_E_TIMEOUT;
	}

	return FDCAN_E_OK;
}

/** Configure amount of filters and initialize filtering block.
 * This function allows configure global amount of filters present.
 * FDCAN block will only ever check as many filters as this function configures.
 * Function will also clear all filter blocks to zero values. This function
 * can be only called after @see fdcan_init has already been called and
 * @see fdcan_start has not been called yet as registers holding filter
 * count are write-protected unless FDCAN block is in INIT mode.
 * @param canport FDCAN block base address
 * @param std_filt requested amount of standard ID filter rules (0-28)
 * @param ext_filt requested amount of extended ID filter rules (0-8)
 * @returns FDCAN_E_OK if filters were configured and initialized properly, otherwise
 * return FDCAN_E_INVALID if FDCAN block base address is not recognized,
 * FDCAN_E_OUTOFRANGE if requested amount of filters is too big,
 * FDCAN_E_BUSY if device is already out of INIT mode.
 */
int fdcan_filter_init(uint32_t canport, uint8_t std_filt, uint8_t ext_filt)
{
	struct FDCAN_MessageRAM * ram = fdcan_get_msgram_addr(canport);

	if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == 0)
	{
		return FDCAN_E_BUSY;
	}

	if (!ram)
	{
		return FDCAN_E_INVALID;
	}

	/* Only perform initialization of message RAM if there are
	 * any filters required
	 */
	if (std_filt > 0)
	{
		if (std_filt > FDCAN_SFT_MAX_NR)
		{
			return FDCAN_E_OUTOFRANGE;
		}

		FDCAN_RXGFC(canport) = (FDCAN_RXGFC(canport) & ~FDCAN_RXGFC_LSS_MASK)
			| (((std_filt + 1) << FDCAN_RXGFC_LSS_SHIFT) & FDCAN_RXGFC_LSS_MASK);


		for (int q = 0; q < FDCAN_SFT_MAX_NR; ++q)
		{
			ram->LFSSA[q].type_id1_conf_id2 = 0;
		}
	}
	else
	{
		/* Reset filter count to zero */
		FDCAN_RXGFC(canport) = (FDCAN_RXGFC(canport) & ~FDCAN_RXGFC_LSS_MASK);
	}

	if (ext_filt > 0)
	{
		if (ext_filt > FDCAN_EFT_MAX_NR)
		{
			return FDCAN_E_OUTOFRANGE;
		}

		FDCAN_RXGFC(canport) = (FDCAN_RXGFC(canport) & ~FDCAN_RXGFC_LSE_MASK)
			| (((ext_filt) << FDCAN_RXGFC_LSE_SHIFT) & FDCAN_RXGFC_LSE_MASK);

		for (int q = 0; q < FDCAN_EFT_MAX_NR; ++q)
		{
			ram->LFESA[q].conf_id1 = 0;
			ram->LFESA[q].type_id2 = 0;
		}
	}
	else
	{
		/* Reset filter count to zero */
		FDCAN_RXGFC(canport) = (FDCAN_RXGFC(canport) & ~FDCAN_RXGFC_LSE_MASK);
	}

	return FDCAN_E_OK;
}

/** Configure filter rule for standard ID frames.
 * Sets up filter rule for frames having standard ID. Each FDCAN block can
 * have its own set of filtering rules. It is only possible to configure as
 * many filters as was configured previously using @see fdcan_filter_init.
 * @param canport FDCAN block base address
 * @param nr number of filter to be configured
 * @param id_list_mode mode in which id1 and id2 are used to match the rule, see 
 * FDCAN_SFT_<mode> defines.
 * @param id1 standard ID for matching. Used as exact value, lower bound or bit 
 * pattern depending on matching mode selected
 * @param id2 standard ID or bitmask. Used as exact value, upper bound or bit mask 
 * depending on matching mode selected
 * @param action Action performed if filtering rule matches frame ID, see 
 * FDCAN_SFEC_<action> defines.
 * @returns FDCAN_E_OK if filter was set up properly, 
 * FDCAN_E_INVALID if FDCAN block base address is unknown and 
 * FDCAN_E_OUTOFRANGE is filter number is larger than previosly configured.
 */
int fdcan_std_filter_set(uint32_t canport, uint32_t nr, 
             uint8_t id_list_mode, uint32_t id1, uint32_t id2,
		     uint8_t action)
{
	if ((FDCAN_CCCR(canport) & (FDCAN_CCCR_INIT | FDCAN_CCCR_CCE)) != 
			(FDCAN_CCCR_INIT | FDCAN_CCCR_CCE))
	{

	}
	struct FDCAN_MessageRAM * ram = fdcan_get_msgram_addr(canport);

	if (!ram)
	{
		return FDCAN_E_INVALID;
	}

	uint32_t rxgfc_lss_current = ((FDCAN_RXGFC(canport) & FDCAN_RXGFC_LSS_MASK) 
			>> FDCAN_RXGFC_LSS_SHIFT);

	if (nr >= rxgfc_lss_current)
	{
		return FDCAN_E_OUTOFRANGE;
	}

	ram->LFSSA[nr].type_id1_conf_id2 = 
		((id_list_mode << FDCAN_SFT_SHIFT) & FDCAN_SFT_MASK)
		| (action & FDCAN_SFEC_MASK)
		| ((id1 << FDCAN_SFID1_SHIFT) & FDCAN_SFID1_SHIFT)
		| ((id2 << FDCAN_SFID2_SHIFT) & FDCAN_SFID2_SHIFT);

	return 0;
}

/** Configure filter rule for extended ID frames.
 * Sets up filter rule for frames having extended ID. Each FDCAN block can
 * have its own set of filtering rules. It is only possible to configure as
 * many filters as was configured previously using @see fdcan_filter_init.
 * @param canport FDCAN block base address
 * @param nr number of filter to be configured
 * @param id_list_mode mode in which id1 and id2 are used to match the rule, see 
 * FDCAN_EFT_<mode> defines.
 * @param id1 extended ID for matching. Used as exact value, lower bound or bit 
 * pattern depending on matching mode selected
 * @param id2 extended ID or bitmask. Used as exact value, upper bound or bit mask 
 * depending on matching mode selected
 * @param action Action performed if filtering rule matches frame ID, see 
 * FDCAN_EFEC_<action> defines.
 * @returns FDCAN_E_OK if filter was set up properly, 
 * FDCAN_E_INVALID if FDCAN block base address is unknown and 
 * FDCAN_E_OUTOFRANGE is filter number is larger than previosly configured.
 */
int fdcan_ext_filter_set(uint32_t canport, uint32_t nr, 
             uint8_t id_list_mode, uint32_t id1, uint32_t id2,
		     uint8_t action)
{
	struct FDCAN_MessageRAM * ram = fdcan_get_msgram_addr(canport);

	if (!ram)
	{
		return FDCAN_E_INVALID;
	}

	uint32_t rxgfc_lse_current = ((FDCAN_RXGFC(canport) & FDCAN_RXGFC_LSE_MASK) 
			>> FDCAN_RXGFC_LSE_SHIFT);

	if (nr >= rxgfc_lse_current)
	{
		return FDCAN_E_OUTOFRANGE;
	}

	ram->LFESA[nr].conf_id1 = 
		(action & FDCAN_EFEC_MASK)
		| ((id1 << FDCAN_EFID1_SHIFT) & FDCAN_EFID1_SHIFT);

	ram->LFESA[nr].type_id2 = 
		(id_list_mode & FDCAN_EFT_MASK)
		| ((id2 << FDCAN_EFID2_SHIFT) & FDCAN_EFID2_SHIFT);

	return 0;
}


/** @brief CAN Transmit Message
 *
 * @param canport Unsigned int32. CAN block register base @ref can_reg_base.
 * @param id Unsigned int32. Message ID.
 * @param ext bool. Extended message ID?
 * @param rtr bool. Request transmit?
 * @param fdcan_fmt Use FDCAN format?
 * @param btr_switch Switch bitrate for data portion of frame?
 * @param length Unsigned int8. Message payload length.
 * @param data Unsigned int8[]. Message payload data.
 * @returns int 0, 1 or 2 on success and depending on which outgoing mailbox got
 * selected. On error returns FDCAN_E_BUSY if no mailbox was available,
 * FDCAN_E_INVALID if CAN block base address and/or message length are invalid.
 */
int fdcan_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
        bool fdcan_fmt, bool btr_switch, uint8_t length, const uint8_t *data)
{
	int mailbox;
	uint32_t dlc, flags = 0;

	mailbox = fdcan_get_free_txbuf(canport);

	if (mailbox == FDCAN_E_BUSY)
	{
		return mailbox;
	}

	struct FDCAN_MessageRAM * ram = fdcan_get_msgram_addr(canport);

	/* Early check: if FDCAN message lentgh is > 8, it must be
	 * a multiple of 4 *and* fdcan format must be enabled.
	 */
	dlc = fdcan_length_to_dlc(length);

	if (dlc == 0xFF || (!fdcan_fmt && length > 8))
	{
		return FDCAN_E_INVALID;
	}

	if (!ram)
	{
		return FDCAN_E_INVALID;
	}

	if (ext)
	{
		ram->TxBuffer[mailbox].identifier_flags = FDCAN_FIFO_XTD 
			| ((id << FDCAN_FIFO_EID_SHIFT) & FDCAN_FIFO_EID_MASK);
	}
	else
	{
		ram->TxBuffer[mailbox].identifier_flags = 
			(id << FDCAN_FIFO_SID_SHIFT) & FDCAN_FIFO_SID_MASK;
	}

	if (rtr)
	{
		ram->TxBuffer[mailbox].identifier_flags |= FDCAN_FIFO_RTR;
	}

	if (fdcan_fmt)
	{
		flags |= FDCAN_FIFO_FDF;
	}

	if (btr_switch)
	{
		flags |= FDCAN_FIFO_BRS;
	}

	ram->TxBuffer[mailbox].evt_fmt_dlc_res = 
		((dlc << FDCAN_FIFO_DLC_SHIFT) & FDCAN_FIFO_DLC_MASK) | flags;

	for (int q = 0; q < length; q += 4)
	{
		ram->TxBuffer[mailbox].data[q / 4] = * ((uint32_t *) &data[q]);
	}

	FDCAN_TXBAR(canport) |= 1 << mailbox;

	return mailbox;
}

/** @brief CAN Receive Message
 *
 * @param canport FDCAN block base address @ref can_reg_base.
 * @param fifo FIFO id.
 * @param release Release the FIFO automatically after coping data out.
 * @param id Message ID.
 * @param ext The message ID is extended?
 * @param rtr Request of transmission?
 * @param fmi ID of the matched filter.
 * @param length Length of message payload.
 * @param data Message payload data.
 * @param timestamp Pointer to store the message timestamp.
 * 			Only valid on time triggered CAN. Use NULL to ignore.
 */
int fdcan_receive(uint32_t canport, uint8_t fifo_id, bool release, uint32_t *id,
		 bool *ext, bool *rtr, uint8_t *fmi, uint8_t *length,
		 uint8_t *data, uint16_t *timestamp)
{
	const struct FDCAN_MessageRAM * ram = fdcan_get_msgram_addr(canport);

	const struct FDCAN_RxFIFOElement * fifo;

	unsigned pending_frames, get_index, dlc, len;

	if (!ram)
	{
		return FDCAN_E_INVALID;
	}

	if (fdcan_get_fill_rxfifo(canport, fifo_id, &get_index, &pending_frames) != FDCAN_E_OK)
	{
		return FDCAN_E_INVALID;
	}

	if (fifo_id == 0)
	{
		fifo = ram->RxFIFO[0];
	}
	else /* No need to check if fifo_id == 1; If not then function already returned E_INVALID */
	{
		fifo = ram->RxFIFO[0];
	}
	
	if (pending_frames == 0)
	{
		return FDCAN_E_NOTAVAIL;
	}

	dlc = (fifo[get_index].filt_fmt_dlc_ts & FDCAN_FIFO_DLC_MASK) 
		>> FDCAN_FIFO_DLC_SHIFT;

	len = fdcan_dlc_to_length(dlc);

	*length = len;
	if ((fifo[get_index].identifier_flags & FDCAN_FIFO_XTD) == FDCAN_FIFO_XTD)
	{
		*ext = true;
		*id = (fifo[get_index].identifier_flags & FDCAN_FIFO_EID_MASK) 
			>> FDCAN_FIFO_EID_SHIFT;
	}
	else
	{
		*ext = false;
		*id = (fifo[get_index].identifier_flags & FDCAN_FIFO_SID_MASK) 
			>> FDCAN_FIFO_SID_SHIFT;
	}
	
	if (timestamp)
	{
		*timestamp = (uint16_t) (fifo[get_index].filt_fmt_dlc_ts & FDCAN_FIFO_RXTS_MASK) 
			>> FDCAN_FIFO_RXTS_SHIFT;
	}

	if (fmi)
	{
		*fmi = (uint8_t) (fifo[get_index].filt_fmt_dlc_ts & FDCAN_FIFO_MM_MASK)
			>> FDCAN_FIFO_MM_SHIFT;
	}

	if (rtr)
	{
		*rtr = ((fifo[get_index].identifier_flags & FDCAN_FIFO_RTR) == FDCAN_FIFO_RTR);
	}

	for (unsigned int q = 0; q < len; q += 4)
	{
		*((uint32_t *) &data[q]) = fifo[get_index].data[q / 4];
	}

	if (release)
	{
		if (fifo_id == 0)
		{
			FDCAN_RXF0A(canport) |= (get_index & FDCAN_RXF0A_R0AI_MASK) 
				<< FDCAN_RXF0A_R0AI_SHIFT;
		}
		else
		{
			FDCAN_RXF1A(canport) |= (get_index & FDCAN_RXF1A_R1AI_MASK) 
				<< FDCAN_RXF1A_R1AI_SHIFT;
		}
	}

	return FDCAN_E_OK;
}

/** Release receive oldest FIFO entry.
 * This function will mask oldest entry in FIFO as released making
 * space for another received frame. This function can be used if 
 * fdcan_receive was called using release = false. If used in other
 * case, then messages can get lost.
 * @param canport FDCAN block base address
 * @param fifo_id ID of FIFO where release should be performed (0 or 1)
 * @returns FDCAN_E_OK if frame was released, FDCAN_E_INVALID if fifo_id
 * is out of range and FDCAN_E_NOTAVAIL is FIFO is empty.
 */
int fdcan_fifo_release(uint32_t canport, uint8_t fifo_id)
{
	unsigned pending_frames, get_index;

	if (fifo_id == 0)
	{
		get_index = (FDCAN_RXF0S(canport) & FDCAN_RXF0S_F0GI_MASK) 
			>> FDCAN_RXF0S_F0GI_SHIFT;
		pending_frames = (FDCAN_RXF0S(canport) & FDCAN_RXF0S_F0FL_MASK) 
			>> FDCAN_RXF0S_F0FL_SHIFT;

		if (pending_frames)
		{
			FDCAN_RXF0A(canport) |= (get_index & FDCAN_RXF0A_R0AI_MASK) 
				<< FDCAN_RXF0A_R0AI_SHIFT;
		}
	}
	else if (fifo_id == 1)
	{
		get_index = (FDCAN_RXF1S(canport) & FDCAN_RXF1S_F1GI_MASK) 
					>> FDCAN_RXF1S_F1GI_SHIFT;
		pending_frames = (FDCAN_RXF1S(canport) & FDCAN_RXF1S_F1FL_MASK) 
			>> FDCAN_RXF1S_F1FL_SHIFT;

		if (pending_frames)
		{
			FDCAN_RXF1A(canport) |= (get_index & FDCAN_RXF1A_R1AI_MASK) 
				<< FDCAN_RXF1A_R1AI_SHIFT;
		}
	}
	else
	{
		return FDCAN_E_INVALID;
	}

	if (pending_frames == 0)
	{
		return FDCAN_E_NOTAVAIL;
	}

	return FDCAN_E_OK;
}

/** Enable IRQ from FDCAN block.
 * This routine configures FDCAN to enable certain IRQ.
 * Each FDCAN block supports two IRQs.
 * @param canport FDCAN block base address
 * @param irq number of IRQ to be enabled (currently 0 or 1)
 */
void fdcan_enable_irq(uint32_t canport, uint32_t irq)
{
	FDCAN_ILE(canport) |= irq & (FDCAN_ILE_INT0 | FDCAN_ILE_INT1);
}

/** Disable IRQ from FDCAN block.
 * This routine configures FDCAN to disable certain IRQ.
 * Each FDCAN block supports two IRQs.
 * @param canport FDCAN block base address
 * @param irq number of IRQ to be enabled (currently 0 or 1)
 */
void fdcan_disable_irq(uint32_t canport, uint32_t irq)
{
	FDCAN_ILE(canport) &= ~(irq & (FDCAN_ILE_INT0 | FDCAN_ILE_INT1));
}

/** Check if there is free transmit buffer.
 * @param canport FDCAN port
 * @returns true if there is at least one free transmit buffer for new message
 * to be sent, false otherwise.
 */
bool fdcan_available_tx(uint32_t canport)
{
	return (fdcan_get_free_txbuf(canport) != FDCAN_E_BUSY);
}

/** Tell if there is message waiting in receive FIFO.
 * @param canport FDCAN port
 * @param fifo Rx FIFO number, 0 or 1
 * @returns true if there is at least one message waiting in given receive FIFO,
 * false otherwise.
 */
bool fdcan_available_rx(uint32_t canport, uint8_t fifo)
{
	unsigned get_index, pending_frames;
	if (fdcan_get_fill_rxfifo(canport, fifo, &get_index, &pending_frames) != FDCAN_E_OK)
	{
		return false;
	}

	return (pending_frames != 0);
}

/**@}*/

/* --- FD-CAN internal functions -------------------------------------------- */

/** Routine implementing FDCAN_CCCR's INIT bit manipulation.
 * This routine will change INIT bit and wait for it to actually
 * change its value. If change won't happen before timeout,
 * error is signalized. If INIT bit already has value which
 * should be set, this function will return immediately.
 * @param canport FDCAN block base address
 * @param set new value of INIT, true means set
 * @returns FDCAN_E_OK on success, FDCAN_E_TIMEOUT if INIT bit value
 * didn't change before timeout has expired.
 */
static int fdcan_cccr_init_cfg(uint32_t canport, bool set)
{
	uint32_t expected;
	uint32_t wait_ack;

	if (set)
	{
		if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == FDCAN_CCCR_INIT)
		{
			/* Already there, sir */
			return FDCAN_E_OK;
		}

		FDCAN_CCCR(canport) |= FDCAN_CCCR_INIT;
		expected = FDCAN_CCCR_INIT;
	}
	else
	{
		if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == 0)
		{
			/* Already there, sir */
			return FDCAN_E_OK;
		}

		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_INIT;
		expected = 0;
	}

	/* Wait, until INIT bit is acknowledged */
	wait_ack = FDCAN_CCCR_INIT_TIMEOUT;
	while ((--wait_ack) && 
			((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == expected));

	if ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == expected)
	{
		return FDCAN_E_OK;
	}
	else
	{
		return FDCAN_E_TIMEOUT;
	}
}

/** Return ID of next free Tx buffer.
 * Examines transmit buffer allocation in message RAM
 * and returns ID of buffer, which is free.
 * @param canport FDCAN block base address
 * @returns Non-negative number ID of Tx buffer which is free,
 * or FDCAN_E_BUSY if no Tx buffer is available
 */
static int fdcan_get_free_txbuf(uint32_t canport)
{
	if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP0) == 0)
	{
		return 0;
	} 
	else if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP1) == 0)
	{
		return 1;
	} 
	else if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP2) == 0)
	{
		return 2;
	} 

	return FDCAN_E_BUSY;
}

/** Returns fill state and next available get index from receive FIFO.
 * Examines FDCAN receive FIFO and returns fill status of FIFO and ID of
 * next message available for reading. If fill status is 0 (FIFO is empty), 
 * then get index is undefined.
 * @param canport FDCAN block base address
 * @param fifo_id ID of fifo queried (currently 0 or 1)
 * @param get_index Address of buffer where next get index will be stored
 * @param pending_frames Address of buffer where amount of pending frame will be stored.
 * @returns FDCAN_E_OK if buffers were filled with data, FDCAN_E_INVALID if
 * FIFO ID is invalid.
 */
static int fdcan_get_fill_rxfifo(uint32_t canport, uint8_t fifo_id, unsigned * get_index, unsigned * pending_frames)
{
	if (fifo_id == 0)
	{
		*get_index = (FDCAN_RXF0S(canport) & FDCAN_RXF0S_F0GI_MASK) 
			>> FDCAN_RXF0S_F0GI_SHIFT;
		*pending_frames = (FDCAN_RXF0S(canport) & FDCAN_RXF0S_F0FL_MASK) 
			>> FDCAN_RXF0S_F0FL_SHIFT;
	}
	else if (fifo_id == 1)
	{
		*get_index = (FDCAN_RXF1S(canport) & FDCAN_RXF1S_F1GI_MASK) 
					>> FDCAN_RXF1S_F1GI_SHIFT;
		*pending_frames = (FDCAN_RXF1S(canport) & FDCAN_RXF1S_F1FL_MASK) 
			>> FDCAN_RXF1S_F1FL_SHIFT;
	}
	else
	{
		return FDCAN_E_INVALID;
	}

	return FDCAN_E_OK;
}

/** Obtain address of FDCAN Message RAM for certain FDCAN block.
 * @param canport identification of FDCAN block. Use CANx defines here.
 * @return Address of Message RAM for given FDCAN block or null pointer
 * if FDCAN block identification is invalid.
 */
static struct FDCAN_MessageRAM * fdcan_get_msgram_addr(uint32_t canport)
{
	/* This piece of code may look wrong, after one examines
	 * STM32G4 datasheet and/or g4/memorymap.h. There are three
	 * memory regions defined for FDCANx_RAM_BASE. They are 0x400
	 * bytes apart as per chapter 2.2.2 of [RM0440].
	 *
	 * It turns out, that these addresses are not in line with what 
	 * is specified later in chapter 44.3.3 of [RM0440]. There it is 
	 * stated, that message RAMs are packed and in case of multiple 
	 * FDCAN blocks, message RAM for n-th FDCAN starts at address 
	 * end of (n-1)-th block + 4 (explicitly, offset 0x354).
	 *
	 * It turns out, that this statement is also false! In fact FDCAN
	 * message RAMs are packed tightly and n-th block starts immediately
	 * after (n-1)-th block ends. Thus offset is going to be computed
	 * using formula:
	 *
	 * FDCAN1_RAM_BASE + (block_id * sizeof(struct FDCAN_MessageRAM))
	 */
	if (canport == CAN1)
	{
		return (struct FDCAN_MessageRAM *) (FDCAN1_RAM_BASE + 0);
	} 
	else if (canport == CAN2)
	{
		return (struct FDCAN_MessageRAM *) (FDCAN1_RAM_BASE + sizeof(struct FDCAN_MessageRAM));
	} 
	else if (canport == CAN3)
	{
		return (struct FDCAN_MessageRAM *) (FDCAN1_RAM_BASE + (2 * sizeof(struct FDCAN_MessageRAM)));
	}

	return (void *) 0;
}

/** Converts frame length to DLC value.
 * Works for both CAN and FDCAN frame lengths. If length
 * is invalid value, then returns 0xFF.
 * @param length intended frame payload length in bytes
 * @returns DLC value representing lengths or 0xFF if length cannot
 * be encoded into DLC format (applies only to FDCAN frame lengths)
 */
static uint32_t fdcan_length_to_dlc(uint8_t length)
{
	if (length <= 8)
	{
		return length;
	} 
	else if (length <= 24)
	{
		if ((length % 4) != 0)
		{
			return 0xFF;
		}
		return 8 + ((length - 8) / 4);
	} 
	else
	{
		if ((length % 16) != 0)
		{
			return 0xFF;
		}
		return 11 + (length / 16);
	}
}

/** Converts DLC value into frame payload length.
 * Works for both CAN and FDCAN DLC values.
 * @param dlc DLC value
 * @returns data payload length in bytes
 */
static uint8_t fdcan_dlc_to_length(uint32_t dlc)
{
	if (dlc <= 8)
	{
		return dlc;
	}
	else if (dlc <= 12)
	{
		return 8 + ((dlc - 8) * 4);
	}
	else 
	{
		return 16 + ((dlc - 12) * 16);
	}
}


