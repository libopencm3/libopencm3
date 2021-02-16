#include <libopencm3/stm32/fdcan.h>
#include <libopencm3/stm32/rcc.h>

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
 * Initialize the selected CAN peripheral block.
 * 
 * @param[in] canport Unsigend int32. CAN register base address @ref can_reg_base.
 * @param[in] brs bool. Enable bitrate switching during Tx (only avaiable if FDCAN operation is also enabled)
 * @param[in] fdoe bool. Enable FDCAN operation
 * @param[in] nart bool. Disable automatic retransmission
 * @param[in] rflm bool. Turn on receive FIFO locked mode, otherwize FIFO is in overwrite mode
 * @param[in] txqm bool. Switch Tx into queue mode, if false then Tx works in FIFO mode 
 * @param[in] sjw Unsigned int32. Resynchronization time quanta jump width.
 * @param[in] ts1 Unsigned int32. Time segment 1 time quanta width.
 * @param[in] ts2 Unsigned int32. Time segment 2 time quanta width.
 * @param[in] brp Unsigned int32. Baud rate prescaler.
 * @param[in] loopback bool. Turn on loopback mode
 * @param[in] silent bool. Turn on silent (monitor) mode
 * @returns int 0 on success, 1 on initialization failure.
 */
int fdcan_init(uint32_t canport, bool brs, bool fdoe, bool nart,
	     bool rflm, bool txqm, uint32_t sjw, uint32_t ts1, uint32_t ts2,
	     uint32_t brp, bool loopback, bool silent)
{
	FDCAN_CCCR(canport) |= FDCAN_CCCR_INIT | FDCAN_CCCR_CCE;

	/* Wait, until INIT bit is acknowledged */
	/* TODO: timeout */
	while ((FDCAN_CCCR(canport) & FDCAN_CCCR_INIT) == 0);

	FDCAN_DBTP(canport) = (sjw & FDCAN_DBTP_DSJW_MASK)
		| (ts1 & FDCAN_DBTP_DTSEG1_MASK)
		| (ts2 & FDCAN_DBTP_DTSEG2_MASK)
		| ((brp << FDCAN_DBTP_DBRP_SHIFT) & FDCAN_DBTP_DBRP_MASK);

	if (fdoe)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_FDOE;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_FDOE;
	}

	if (brs)
	{
		FDCAN_CCCR(canport) |= FDCAN_CCCR_BRSE;
	}
	else
	{
		FDCAN_CCCR(canport) &= ~FDCAN_CCCR_BRSE;
	}

	if (txqm)
	{
		FDCAN_TXBC(canport) |= FDCAN_TXBC_TFQM;
	}
	else
	{
		FDCAN_TXBC(canport) &= ~FDCAN_TXBC_TFQM;
	}

	if (nart)
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
		FDCAN_CCCR(canport) &= FDCAN_CCCR_MON;
	}

	if (rflm)
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
		/* FDCAN_TEST is automatically reset to default values by FDCAN */
	}

	FDCAN_CCCR(canport) &= ~(FDCAN_CCCR_INIT | FDCAN_CCCR_CCE);

	return 0;
}

/** @brief CAN Transmit Message

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] id Unsigned int32. Message ID.
@param[in] ext bool. Extended message ID?
@param[in] rtr bool. Request transmit?
@param[in] length Unsigned int8. Message payload length.
@param[in] data Unsigned int8[]. Message payload data.
@returns int 0, 1 or 2 on success and depending on which outgoing mailbox got
selected. -1 if no mailbox was available and no transmission got queued.
 */
int fdcan_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
		 uint8_t length, uint8_t *data)
{
	unsigned int mailbox = 0xFF;
	int ret = 0;

	if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP0) == 0)
	{
		mailbox = 0;
	} else if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP1) == 0)
	{
		mailbox = 1;
	} else if ((FDCAN_TXBRP(canport) & FDCAN_TXBRP_TRP2) == 0)
	{
		mailbox = 2;
	} else {
		ret = -1;
	}

	if (ret == -1)
	{
		return ret;
	}



	return -1;
}
