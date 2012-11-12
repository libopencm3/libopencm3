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

#if defined(STM32F1)
#	include <libopencm3/stm32/f1/rcc.h>
#elif defined(STM32F2)
#	include <libopencm3/stm32/f2/rcc.h>
#elif defined(STM32F4)
#	include <libopencm3/stm32/f4/rcc.h>
#else
#	error "stm32 family not defined."
#endif

/*-----------------------------------------------------------------------------*/
/** @brief CAN Reset

The CAN peripheral and all its associated configuration registers are placed in the
reset condition. The reset is effective via the RCC peripheral reset system.

@param[in] canport Unsigned int32. CAN block register address base @ref can_reg_base.
 */
void can_reset(u32 canport)
{
	if (canport == CAN1) {
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_CAN1RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_CAN1RST);
	} else {
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_CAN2RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_CAN2RST);
	}
}

/*-----------------------------------------------------------------------------*/
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
int can_init(u32 canport, bool ttcm, bool abom, bool awum, bool nart,
	     bool rflm, bool txfp, u32 sjw, u32 ts1, u32 ts2, u32 brp)
{
	u32 wait_ack = 0x00000000;
	u32 can_msr_inak_timeout = 0x0000FFFF;
	int ret = 0;

	/* Exit from sleep mode. */
	CAN_MCR(canport) &= ~CAN_MCR_SLEEP;

	/* Request initialization "enter". */
	CAN_MCR(canport) |= CAN_MCR_INRQ;

	/* Wait for acknowledge. */
	while ((wait_ack != can_msr_inak_timeout) &&
	       ((CAN_MSR(canport) & CAN_MSR_INAK) != CAN_MSR_INAK)) {
		wait_ack++;
	}

	/* Check the acknowledge. */
	if ((CAN_MSR(canport) & CAN_MSR_INAK) != CAN_MSR_INAK)
		return 1;

	/* Set the automatic bus-off management. */
	if (ttcm)
		CAN_MCR(canport) |= CAN_MCR_TTCM;
	else
		CAN_MCR(canport) &= ~CAN_MCR_TTCM;

	if (abom)
		CAN_MCR(canport) |= CAN_MCR_ABOM;
	else
		CAN_MCR(canport) &= ~CAN_MCR_ABOM;

	if (awum)
		CAN_MCR(canport) |= CAN_MCR_AWUM;
	else
		CAN_MCR(canport) &= ~CAN_MCR_AWUM;

	if (nart)
		CAN_MCR(canport) |= CAN_MCR_NART;
	else
		CAN_MCR(canport) &= ~CAN_MCR_NART;

	if (rflm)
		CAN_MCR(canport) |= CAN_MCR_RFLM;
	else
		CAN_MCR(canport) &= ~CAN_MCR_RFLM;

	if (txfp)
		CAN_MCR(canport) |= CAN_MCR_TXFP;
	else
		CAN_MCR(canport) &= ~CAN_MCR_TXFP;

	/* Set bit timings. */
	CAN_BTR(canport) = sjw | ts2 | ts1 |
		           (u32)(CAN_BTR_BRP_MASK & (brp - 1));

	/* Request initialization "leave". */
	CAN_MCR(canport) &= ~CAN_MCR_INRQ;

	/* Wait for acknowledge. */
	wait_ack = 0x00000000;
	while ((wait_ack != can_msr_inak_timeout) &&
	       ((CAN_MSR(canport) & CAN_MSR_INAK) == CAN_MSR_INAK)) {
		wait_ack++;
	}

	if ((CAN_MSR(canport) & CAN_MSR_INAK) == CAN_MSR_INAK)
		ret = 1;

	return ret;
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Filter Init

Initialize incoming message filter and assign to FIFO.

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] nr Unsigned int32. ID number of the filter.
@param[in] scale_32bit bool. 32-bit scale for the filter?
@param[in] id_list_mode bool. ID list filter mode?
@param[in] fr1 Unsigned int32. First filter register content.
@param[in] fr2 Unsigned int32. Second filter register content.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_init(u32 canport, u32 nr, bool scale_32bit, bool id_list_mode,
		     u32 fr1, u32 fr2, u32 fifo, bool enable)
{
	u32 filter_select_bit = 0x00000001 << nr;

	/* Request initialization "enter". */
	CAN_FMR(canport) |= CAN_FMR_FINIT;

	/* Deactivate the filter. */
	CAN_FA1R(canport) &= ~filter_select_bit;

	if (scale_32bit) {
		/* Set 32-bit scale for the filter. */
		CAN_FS1R(canport) |= filter_select_bit;
	} else {
		/* Set 16-bit scale for the filter. */
		CAN_FS1R(canport) &= ~filter_select_bit;
	}

	if (id_list_mode) {
		/* Set filter mode to ID list mode. */
		CAN_FM1R(canport) |= filter_select_bit;
	} else {
		/* Set filter mode to id/mask mode. */
		CAN_FM1R(canport) &= ~filter_select_bit;
	}

	/* Set the first filter register. */
	CAN_FiR1(canport, nr) = fr1;

	/* Set the second filter register. */
	CAN_FiR2(canport, nr) = fr2;

	/* Select FIFO0 or FIFO1 as filter assignement. */
	if (fifo)
		CAN_FFA1R(canport) |= filter_select_bit;  /* FIFO1 */
	else
		CAN_FFA1R(canport) &= ~filter_select_bit; /* FIFO0 */

	if (enable)
		CAN_FA1R(canport) |= filter_select_bit; /* Activate filter. */

	/* Request initialization "leave". */
	CAN_FMR(canport) &= ~CAN_FMR_FINIT;
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Initialize a 16bit Message ID Mask Filter

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id1 Unsigned int16. First message ID to filter.
@param[in] mask1 Unsigned int16. First message ID bit mask.
@param[in] id2 Unsigned int16. Second message ID to filter.
@param[in] mask2 Unsigned int16. Second message ID bit mask.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_mask_16bit_init(u32 canport, u32 nr, u16 id1, u16 mask1,
				   u16 id2, u16 mask2, u32 fifo, bool enable)
{
	can_filter_init(canport, nr, false, false,
			((u32)id1 << 16) | (u32)mask1,
			((u32)id2 << 16) | (u32)mask2, fifo, enable);
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Initialize a 32bit Message ID Mask Filter

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id Unsigned int32. Message ID to filter.
@param[in] mask Unsigned int32. Message ID bit mask.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_mask_32bit_init(u32 canport, u32 nr, u32 id, u32 mask,
				   u32 fifo, bool enable)
{
	can_filter_init(canport, nr, true, false, id, mask, fifo, enable);
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Initialize a 16bit Message ID List Filter

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id1 Unsigned int16. First message ID to match.
@param[in] id2 Unsigned int16. Second message ID to match.
@param[in] id3 Unsigned int16. Third message ID to match.
@param[in] id4 Unsigned int16. Fourth message ID to match.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_list_16bit_init(u32 canport, u32 nr, u16 id1, u16 id2,
				   u16 id3, u16 id4, u32 fifo, bool enable)
{
	can_filter_init(canport, nr, false, true,
			((u32)id1 << 16) | (u32)id2,
			((u32)id3 << 16) | (u32)id4, fifo, enable);
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Initialize a 32bit Message ID List Filter

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] nr Unsigned int32. ID number of the filter.
@param[in] id1 Unsigned int32. First message ID to match.
@param[in] id2 Unsigned int32. Second message ID to match.
@param[in] fifo Unsigned int32. FIFO id.
@param[in] enable bool. Enable filter?
 */
void can_filter_id_list_32bit_init(u32 canport, u32 nr, u32 id1, u32 id2,
				   u32 fifo, bool enable)
{
	can_filter_init(canport, nr, true, true, id1, id2, fifo, enable);
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Enable IRQ

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] irq Unsigned int32. IRQ bit(s).
 */
void can_enable_irq(u32 canport, u32 irq)
{
	CAN_IER(canport) |= irq;
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Disable IRQ

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] irq Unsigned int32. IRQ bit(s).
 */
void can_disable_irq(u32 canport, u32 irq)
{
	CAN_IER(canport) &= ~irq;
}

/*-----------------------------------------------------------------------------*/
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
int can_transmit(u32 canport, u32 id, bool ext, bool rtr, u8 length, u8 *data)
{
	int ret = 0, i;
	u32 mailbox = 0;

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
	if (ret == -1)
		return ret;

	/* Clear stale register bits */
	CAN_TIxR(canport, mailbox) = 0;
	if (ext) {
		/* Set extended ID. */
		CAN_TIxR(canport, mailbox) |= id << CAN_TIxR_EXID_SHIFT;
		/* Set extended ID indicator bit. */
		CAN_TIxR(canport, mailbox) |= CAN_TIxR_IDE;
	} else {
		/* Set standard ID. */
		CAN_TIxR(canport, mailbox) |= id << CAN_TIxR_STID_SHIFT;
	}

	/* Set/clear remote transmission request bit. */
	if (rtr)
		CAN_TIxR(canport, mailbox) |= CAN_TIxR_RTR; /* Set */

	/* Set the DLC. */
	CAN_TDTxR(canport, mailbox) &= 0xFFFFFFF0;
	CAN_TDTxR(canport, mailbox) |= length & CAN_TDTxR_DLC_MASK;

	/* Set the data. */
	CAN_TDLxR(canport, mailbox) = 0;
	CAN_TDHxR(canport, mailbox) = 0;
	for (i = 0; (i < 4) && (i < length); i++)
		CAN_TDLxR(canport, mailbox) |= (u32)data[i] << (8 * i);
	for (i = 4; (i < 8) && (i < length); i++)
		CAN_TDHxR(canport, mailbox) |= (u32)data[i] << (8 * (i - 4));

	/* Request transmission. */
	CAN_TIxR(canport, mailbox) |= CAN_TIxR_TXRQ;

	return ret;
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Release FIFO

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] fifo Unsigned int8. FIFO id.
 */
void can_fifo_release(u32 canport, u8 fifo)
{
	if (fifo == 0)
		CAN_RF0R(canport) |= CAN_RF1R_RFOM1;
	else
		CAN_RF1R(canport) |= CAN_RF1R_RFOM1;
}

/*-----------------------------------------------------------------------------*/
/** @brief CAN Receive Message

@param[in] canport Unsigned int32. CAN block register base @ref can_reg_base.
@param[in] fifo Unsigned int8. FIFO id.
@param[in] release bool. Release the FIFO automatically after coping data out.
@param[out] id Unsigned int32 pointer. Message ID.
@param[out] ext bool pointer. The message ID is extended?
@param[out] rtr bool pointer. Request of transmission?
@param[out] fmi Unsigned int32 pointer. ID of the matched filter.
@param[out] length Unsigned int8 pointer. Length of message payload.
@param[out] data Unsigned int8[]. Message payload data.
 */
void can_receive(u32 canport, u8 fifo, bool release, u32 *id, bool *ext,
		 bool *rtr, u32 *fmi, u8 *length, u8 *data)
{
	u32 fifo_id = 0;
	int i;

	if (fifo == 0)
		fifo_id = CAN_FIFO0;
	else
		fifo_id = CAN_FIFO1;

	/* Get type of CAN ID and CAN ID. */
	if (CAN_RIxR(canport, fifo_id) & CAN_RIxR_IDE) {
		*ext = true;
		/* Get extended CAN ID. */
		*id = ((CAN_RIxR(canport, fifo_id) & CAN_RIxR_EXID_MASK) >>
			CAN_RIxR_EXID_SHIFT);
	} else {
		*ext = false;
		/* Get standard CAN ID. */
		*id = ((CAN_RIxR(canport, fifo_id) & CAN_RIxR_STID_MASK) >>
			CAN_RIxR_STID_SHIFT);
	}

	/* Get request transmit flag. */
	if (CAN_RIxR(canport, fifo_id) & CAN_RIxR_RTR)
		*rtr = true;
	else
		*rtr = false;

	/* Get filter match ID. */
	*fmi = ((CAN_RDTxR(canport, fifo_id) & CAN_RDTxR_FMI_MASK) >
		CAN_RDTxR_FMI_SHIFT);

	/* Get data length. */
	*length = CAN_RDTxR(canport, fifo_id) & CAN_RDTxR_DLC_MASK;

	/* Get data. */
	for (i = 0; (i < 4) && (i < *length); i++)
		data[i] = (CAN_RDLxR(canport, fifo_id) >> (8 * i)) & 0xFF;

	for (i = 4; (i < 8) && (i < *length); i++)
		data[i] = (CAN_RDHxR(canport, fifo_id) >> (8 * (i - 4))) & 0xFF;

	/* Release the FIFO. */
	if (release)
		can_fifo_release(canport, fifo);
}
