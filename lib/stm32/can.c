/** @defgroup can_file CAN

@ingroup STM32F_files

@brief <b>libopencm3 STM32Fxxx CAN</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Piotr Esden-Tempski <piotr@esden.net>

@date 12 November 2012

Devices can have up to two CAN peripherals. The peripherals support up to 1MBit
transmission rate. The peripheral has several filters for incoming messages that
can be distributed between two FIFOs and three transmit mailboxes.

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

#include <libopencm3/stm32/can.h>
#include <libopencm3/stm32/rcc.h>

/* Timeout for CAN INIT acknowledge
 * this value is difficult to define.
 * INIT is set latest after finishing the current transfer.
 * Assuming the lowest CAN speed of 100kbps one CAN frame may take about 1.6ms
 * WAIT loop timeout varies on compiler switches, optimization, CPU architecture
 * and CPU speed
 *
 * The same timeout value is used for leaving INIT where the longest time is
 * 11 bits(110 us on 100 kbps).
 */
#define CAN_MSR_INAK_TIMEOUT 0x0000FFFF

/*---------------------------------------------------------------------------*/
/** @brief CAN Reset

The CAN peripheral and all its associated configuration registers are placed in
the reset condition. The reset is effective via the RCC peripheral reset
system.

@param[in] canport Unsigned int32. CAN block register address base @ref
can_reg_base.
 */
void can_reset(uint32_t canport)
{
	if (canport == CAN1) {
		rcc_periph_reset_pulse(RST_CAN1);
	} else {
#if defined(BX_CAN2_BASE)
		rcc_periph_reset_pulse(RST_CAN2);
#endif
	}
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Init

Initialize the selected CAN peripheral block.

@param[in] canport Unsigend int32. CAN register base address @ref can_reg_base.
@param[in] ttcm bool. Time triggered communication mode.
@param[in] abom bool. Automatic bus-off management.
@param[in] awum bool. Automatic wakeup mode.
@param[in] nart bool. No automatic retransmission.
@param[in] rflm bool. Receive FIFO locked mode.
@param[in] txfp bool. Transmit FIFO priority.
@param[in] sjw Unsigned int32. Resynchronization time quanta jump width.
@param[in] ts1 Unsigned int32. Time segment 1 time quanta width.
@param[in] ts2 Unsigned int32. Time segment 2 time quanta width.
@param[in] brp Unsigned int32. Baud rate prescaler.
@returns int 0 on success, 1 on initialization failure.
*/
int can_init(uint32_t canport, bool ttcm, bool abom, bool awum, bool nart,
	     bool rflm, bool txfp, uint32_t sjw, uint32_t ts1, uint32_t ts2,
	     uint32_t brp, bool loopback, bool silent)
{
	volatile uint32_t wait_ack;
	int ret = 0;

	/* Exit from sleep mode. */
	CAN_MCR(canport) &= ~CAN_MCR_SLEEP;

	/* Request initialization "enter". */
	CAN_MCR(canport) |= CAN_MCR_INRQ;

	/* Wait for acknowledge. */
	wait_ack = CAN_MSR_INAK_TIMEOUT;
	while ((--wait_ack) &&
		((CAN_MSR(canport) & CAN_MSR_INAK) != CAN_MSR_INAK));

	/* Check the acknowledge. */
	if ((CAN_MSR(canport) & CAN_MSR_INAK) != CAN_MSR_INAK) {
		return 1;
	}

	/* clear can timing bits */
	CAN_BTR(canport) = 0;

	/* Set the automatic bus-off management. */
	if (ttcm) {
		CAN_MCR(canport) |= CAN_MCR_TTCM;
	} else {
		CAN_MCR(canport) &= ~CAN_MCR_TTCM;
	}

	if (abom) {
		CAN_MCR(canport) |= CAN_MCR_ABOM;
	} else {
		CAN_MCR(canport) &= ~CAN_MCR_ABOM;
	}

	if (awum) {
		CAN_MCR(canport) |= CAN_MCR_AWUM;
	} else {
		CAN_MCR(canport) &= ~CAN_MCR_AWUM;
	}

	if (nart) {
		CAN_MCR(canport) |= CAN_MCR_NART;
	} else {
		CAN_MCR(canport) &= ~CAN_MCR_NART;
	}

	if (rflm) {
		CAN_MCR(canport) |= CAN_MCR_RFLM;
	} else {
		CAN_MCR(canport) &= ~CAN_MCR_RFLM;
	}

	if (txfp) {
		CAN_MCR(canport) |= CAN_MCR_TXFP;
	} else {
		CAN_MCR(canport) &= ~CAN_MCR_TXFP;
	}

	if (silent) {
		CAN_BTR(canport) |= CAN_BTR_SILM;
	} else {
		CAN_BTR(canport) &= ~CAN_BTR_SILM;
	}

	if (loopback) {
		CAN_BTR(canport) |= CAN_BTR_LBKM;
	} else {
		CAN_BTR(canport) &= ~CAN_BTR_LBKM;
	}

	/* Set bit timings. */
	CAN_BTR(canport) |= sjw | ts2 | ts1 |
		((brp - 1ul) & CAN_BTR_BRP_MASK);

	/* Request initialization "leave". */
	CAN_MCR(canport) &= ~CAN_MCR_INRQ;

	/* Wait for acknowledge. */
	wait_ack = CAN_MSR_INAK_TIMEOUT;
	while ((--wait_ack) &&
	       ((CAN_MSR(canport) & CAN_MSR_INAK) == CAN_MSR_INAK));

	if ((CAN_MSR(canport) & CAN_MSR_INAK) == CAN_MSR_INAK) {
		ret = 1;
	}

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Filter Init

Initialize incoming message filter and assign to FIFO.

@param[in] nr Unsigned int32. ID number of the filter.
@param[in] scale_32bit true for single 32bit, false for dual 16bit
@param[in] id_list_mode true for id lists, false for id/mask
@param[in] fr1 Unsigned int32. First filter register content.
@param[in] fr2 Unsigned int32. Second filter register content.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_init(uint32_t nr, bool scale_32bit,
		     bool id_list_mode, uint32_t fr1, uint32_t fr2,
		     uint32_t fifo, bool enable)
{
	uint32_t filter_select_bit = 0x00000001 << nr;

	/* Request initialization "enter". */
	CAN_FMR(CAN1) |= CAN_FMR_FINIT;

	/* Deactivate the filter. */
	CAN_FA1R(CAN1) &= ~filter_select_bit;

	if (scale_32bit) {
		/* Set 32-bit scale for the filter. */
		CAN_FS1R(CAN1) |= filter_select_bit;
	} else {
		/* Set 16-bit scale for the filter. */
		CAN_FS1R(CAN1) &= ~filter_select_bit;
	}

	if (id_list_mode) {
		/* Set filter mode to ID list mode. */
		CAN_FM1R(CAN1) |= filter_select_bit;
	} else {
		/* Set filter mode to id/mask mode. */
		CAN_FM1R(CAN1) &= ~filter_select_bit;
	}

	/* Set the first filter register. */
	CAN_FiR1(CAN1, nr) = fr1;

	/* Set the second filter register. */
	CAN_FiR2(CAN1, nr) = fr2;

	/* Select FIFO0 or FIFO1 as filter assignement. */
	if (fifo) {
		CAN_FFA1R(CAN1) |= filter_select_bit;  /* FIFO1 */
	} else {
		CAN_FFA1R(CAN1) &= ~filter_select_bit; /* FIFO0 */
	}

	if (enable) {
		CAN_FA1R(CAN1) |= filter_select_bit; /* Activate filter. */
	}

	/* Request initialization "leave". */
	CAN_FMR(CAN1) &= ~CAN_FMR_FINIT;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Initialize a 16bit Message ID Mask Filter

@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id1 Unsigned int16. First message ID to filter.
@param[in] mask1 Unsigned int16. First message ID bit mask.
@param[in] id2 Unsigned int16. Second message ID to filter.
@param[in] mask2 Unsigned int16. Second message ID bit mask.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_mask_16bit_init(uint32_t nr, uint16_t id1,
				   uint16_t mask1, uint16_t id2,
				   uint16_t mask2, uint32_t fifo, bool enable)
{
	can_filter_init(nr, false, false,
			((uint32_t)mask1 << 16) | (uint32_t)id1,
			((uint32_t)mask2 << 16) | (uint32_t)id2, fifo, enable);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Initialize a 32bit Message ID Mask Filter

@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id Unsigned int32. Message ID to filter.
@param[in] mask Unsigned int32. Message ID bit mask.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_mask_32bit_init(uint32_t nr, uint32_t id,
				   uint32_t mask, uint32_t fifo, bool enable)
{
	can_filter_init(nr, true, false, id, mask, fifo, enable);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Initialize a 16bit Message ID List Filter

@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id1 Unsigned int16. First message ID to match.
@param[in] id2 Unsigned int16. Second message ID to match.
@param[in] id3 Unsigned int16. Third message ID to match.
@param[in] id4 Unsigned int16. Fourth message ID to match.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_list_16bit_init(uint32_t nr,
				   uint16_t id1, uint16_t id2,
				   uint16_t id3, uint16_t id4,
				   uint32_t fifo, bool enable)
{
	can_filter_init(nr, false, true,
			((uint32_t)id1 << 16) | (uint32_t)id2,
			((uint32_t)id3 << 16) | (uint32_t)id4, fifo, enable);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Initialize a 32bit Message ID List Filter

@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id1 Unsigned int32. First message ID to match.
@param[in] id2 Unsigned int32. Second message ID to match.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_list_32bit_init(uint32_t nr,
				   uint32_t id1, uint32_t id2,
				   uint32_t fifo, bool enable)
{
	can_filter_init(nr, true, true, id1, id2, fifo, enable);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Enable IRQ

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] irq Unsigned int32. IRQ bit(s).
 */
void can_enable_irq(uint32_t canport, uint32_t irq)
{
	CAN_IER(canport) |= irq;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Disable IRQ

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] irq Unsigned int32. IRQ bit(s).
 */
void can_disable_irq(uint32_t canport, uint32_t irq)
{
	CAN_IER(canport) &= ~irq;
}

/*---------------------------------------------------------------------------*/
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
int can_transmit(uint32_t canport, uint32_t id, bool ext, bool rtr,
		 uint8_t length, uint8_t *data)
{
	int ret = 0;
	uint32_t mailbox = 0;
	union {
		uint8_t data8[4];
		uint32_t data32;
	} tdlxr, tdhxr;

	/* Check which transmit mailbox is empty if any. */
	if ((CAN_TSR(canport) & CAN_TSR_TME0) == CAN_TSR_TME0) {
		ret = 0;
		mailbox = CAN_MBOX0;
	} else if ((CAN_TSR(canport) & CAN_TSR_TME1) == CAN_TSR_TME1) {
		ret = 1;
		mailbox = CAN_MBOX1;
	} else if ((CAN_TSR(canport) & CAN_TSR_TME2) == CAN_TSR_TME2) {
		ret = 2;
		mailbox = CAN_MBOX2;
	} else {
		ret = -1;
	}

	/* If we have no empty mailbox return with an error. */
	if (ret == -1) {
		return ret;
	}

	if (ext) {
		/* Set extended ID. */
		CAN_TIxR(canport, mailbox) = (id << CAN_TIxR_EXID_SHIFT) |
			CAN_TIxR_IDE;
	} else {
		/* Set standard ID. */
		CAN_TIxR(canport, mailbox) = id << CAN_TIxR_STID_SHIFT;
	}

	/* Set/clear remote transmission request bit. */
	if (rtr) {
		CAN_TIxR(canport, mailbox) |= CAN_TIxR_RTR; /* Set */
	}

	/* Set the DLC. */
	CAN_TDTxR(canport, mailbox) &= ~CAN_TDTxR_DLC_MASK;
	CAN_TDTxR(canport, mailbox) |= (length & CAN_TDTxR_DLC_MASK);

	switch (length) {
	case 8:
		tdhxr.data8[3] = data[7];
		/* fall through */
	case 7:
		tdhxr.data8[2] = data[6];
		/* fall through */
	case 6:
		tdhxr.data8[1] = data[5];
		/* fall through */
	case 5:
		tdhxr.data8[0] = data[4];
		/* fall through */
	case 4:
		tdlxr.data8[3] = data[3];
		/* fall through */
	case 3:
		tdlxr.data8[2] = data[2];
		/* fall through */
	case 2:
		tdlxr.data8[1] = data[1];
		/* fall through */
	case 1:
		tdlxr.data8[0] = data[0];
		/* fall through */
	default:
		break;
	}
	/* Set the data. */

	CAN_TDLxR(canport, mailbox) = tdlxr.data32;
	CAN_TDHxR(canport, mailbox) = tdhxr.data32;

	/* Request transmission. */
	CAN_TIxR(canport, mailbox) |= CAN_TIxR_TXRQ;

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Release FIFO

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] fifo Unsigned int8. FIFO id.
 */
void can_fifo_release(uint32_t canport, uint8_t fifo)
{
	if (fifo == 0) {
		CAN_RF0R(canport) |= CAN_RF1R_RFOM1;
	} else {
		CAN_RF1R(canport) |= CAN_RF1R_RFOM1;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Receive Message

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] fifo Unsigned int8. FIFO id.
@param[in] release bool. Release the FIFO automatically after coping data out.
@param[out] id Unsigned int32 pointer. Message ID.
@param[out] ext bool pointer. The message ID is extended?
@param[out] rtr bool pointer. Request of transmission?
@param[out] fmi Unsigned int8 pointer. ID of the matched filter.
@param[out] length Unsigned int8 pointer. Length of message payload.
@param[out] data Unsigned int8[]. Message payload data.
@param[out] timestamp Pointer to store the message timestamp.
			Only valid on time triggered CAN. Use NULL to ignore.
 */
void can_receive(uint32_t canport, uint8_t fifo, bool release, uint32_t *id,
		 bool *ext, bool *rtr, uint8_t *fmi, uint8_t *length,
		 uint8_t *data, uint16_t *timestamp)
{
	uint32_t fifo_id = 0;
	union {
		uint8_t data8[4];
		uint32_t data32;
	} rdlxr, rdhxr;
	const uint32_t fifoid_array[2] = {CAN_FIFO0, CAN_FIFO1};

	fifo_id = fifoid_array[fifo];

	/* Get type of CAN ID and CAN ID. */
	if (CAN_RIxR(canport, fifo_id) & CAN_RIxR_IDE) {
		*ext = true;
		/* Get extended CAN ID. */
		*id = (CAN_RIxR(canport, fifo_id) >> CAN_RIxR_EXID_SHIFT) &
			CAN_RIxR_EXID_MASK;
	} else {
		*ext = false;
		/* Get standard CAN ID. */
		*id = (CAN_RIxR(canport, fifo_id) >> CAN_RIxR_STID_SHIFT) &
			CAN_RIxR_STID_MASK;
	}

	/* Get remote transmit flag. */
	if (CAN_RIxR(canport, fifo_id) & CAN_RIxR_RTR) {
		*rtr = true;
	} else {
		*rtr = false;
	}

	/* Get filter match ID. */
	*fmi = ((CAN_RDTxR(canport, fifo_id) & CAN_RDTxR_FMI_MASK) >>
		CAN_RDTxR_FMI_SHIFT);

	/* Get data length. */
	*length = CAN_RDTxR(canport, fifo_id) & CAN_RDTxR_DLC_MASK;
	/* accelerate reception by copying the CAN data from the controller
	 * memory to the fast internal RAM
	 */

	if (timestamp) {
		*timestamp = (CAN_RDTxR(canport, fifo_id) &
			CAN_RDTxR_TIME_MASK) >> CAN_RDTxR_TIME_SHIFT;
	}

	rdlxr.data32 = CAN_RDLxR(canport, fifo_id);
	rdhxr.data32 = CAN_RDHxR(canport, fifo_id);
	/* */
	/* Get data.
	 * Byte wise copy is needed because we do not know the alignment
	 * of the input buffer.
	 * Here copying 8 bytes unconditionally is faster than using loop
	 *
	 * It is OK to copy all 8 bytes because the upper layer must be
	 * prepared for data length bigger expected.
	 * In contrary the driver has no information about the intended size.
	 * This could be different if the max length would be handed over
	 * to the function, but it is not the case
	 */
	data[0] = rdlxr.data8[0];
	data[1] = rdlxr.data8[1];
	data[2] = rdlxr.data8[2];
	data[3] = rdlxr.data8[3];
	data[4] = rdhxr.data8[0];
	data[5] = rdhxr.data8[1];
	data[6] = rdhxr.data8[2];
	data[7] = rdhxr.data8[3];

	/* Release the FIFO. */
	if (release) {
		can_fifo_release(canport, fifo);
	}
}

bool can_available_mailbox(uint32_t canport)
{
	return CAN_TSR(canport) & (CAN_TSR_TME0 | CAN_TSR_TME1 | CAN_TSR_TME2);
}
