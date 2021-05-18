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
 * Device is equipped with two FDCAN peripherals residing in one FDCAN block. The peripherals
 * support both CAN 2.0 A and B standard and Bosch FDCAN standard. FDCAN frame format and
 * bitrate switching is supported. The peripheral has several filters for incoming messages that
 * can be distributed between two FIFOs and transmit buffer all of configurable amount of 
 * entries. For transmitted messages it is possible to opt for event notification once message 
 * is transmitted.
 *
 * The FDCAN peripheral present in STM32 H7 is a superset of FDCAN peripheral found in other MCUs
 * such as STM32 G4. It allows more fine-grade control over buffer and filter allocation and
 * supports TTCAN on CAN1, etc. This driver provides source-level backwards compatible
 * implementation of driver, which allows build of unmodified software originally written for
 * STM32 G4 on STM32 H7.
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

#define FDCAN_LSS_COUNT(can_base)		\
	((FDCAN_SIDFC(can_base) >> FDCAN_SIDFC_LSS_SHIFT) & FDCAN_SIDFC_LSS_MASK)

#define FDCAN_LSE_COUNT(can_base)		\
	((FDCAN_XIDFC(can_base) >> FDCAN_XIDFC_LSE_SHIFT) & FDCAN_XIDFC_LSE_MASK)

/* --- FD-CAN functions ----------------------------------------------------- */

/** @ingroup fdcan_file */
/**@{
 * */

/** Returns actual size of FIFO entry in FIFO for given CAN port and FIFO.
 *
 * Obtains value of FIFO entry length. This value covers both fixed-size frame
 * header block and payload buffer. User can configure payload buffer size individually
 * for each FIFO and designated RX buffer.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] fifo_id ID of FIFO whole length is queried.
 * @returns Length of FIFO entry length covering frame header and frame payload.
 */
unsigned fdcan_get_fifo_element_size(uint32_t canport, unsigned fifo_id)
{
	unsigned element_size;
	if (fifo_id == 0) {
		element_size = FDCAN_RXESC(canport) >> FDCAN_RXESC_F0DS_SHIFT;
	} else {
		element_size = FDCAN_RXESC(canport) >> FDCAN_RXESC_F1DS_SHIFT;
	}

	/* Mask is unshifted and at this point, element_size is unshifted too */
	return 8 + fdcan_dlc_to_length((element_size & FDCAN_RXESC_F0DS_MASK) | 0x8);
}

/** Returns actual size of transmit entry in transmit queue/FIFO for given CAN port.
 *
 * Obtains value of entry length in transmit queue/FIFO. This value covers both
 * fixed-sized frame header block and payload buffer. User can configure payload buffer
 * size.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @returns Length of FIFO entry length covering frame header and frame payload.
 */
unsigned fdcan_get_txbuf_element_size(uint32_t canport)
{
	unsigned element_size;
	element_size = (FDCAN_TXESC(canport) >> FDCAN_TXESC_TBDS_SHIFT) & FDCAN_TXESC_TBDS_MASK;
	return 8 + fdcan_dlc_to_length((element_size & FDCAN_TXESC_TBDS_MASK) | 0x8);
}

/** Initialize allocation of standard filter block in CAN message RAM.
 *
 * Allows specifying size of standard filtering block (in term of available filtering
 * rules and filter base address within CAN message RAM. Note, that there are no limitations
 * nor checking on address provided. It is possible to share whole filtering block or
 * portion of it between multiple CAN interfaces.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] flssa standard filtering block start address offset in message RAM
 * @param [in] lss amount of standard filters
 */
void fdcan_init_std_filter_ram(uint32_t canport, uint32_t flssa, uint8_t lss)
{
	FDCAN_SIDFC(canport) = flssa << FDCAN_SIDFC_FLSSA_SHIFT
		| lss << FDCAN_SIDFC_LSS_SHIFT;
}

/** Initialize allocation of extended filter block in CAN message RAM.
 *
 * Allows specifying size of extended filtering block (in term of available filtering
 * rules and filter base address within CAN message RAM. Note, that there are no limitations
 * nor checking on address provided. It is possible to share whole filtering block or
 * portion of it between multiple CAN interfaces.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] flesa extended filtering block start address offset in message RAM
 * @param [in] lse amount of extended filters
 */
void fdcan_init_ext_filter_ram(uint32_t canport, uint32_t flesa, uint8_t lse)
{
	FDCAN_XIDFC(canport) = flesa << FDCAN_XIDFC_FLESA_SHIFT
		| lse << FDCAN_XIDFC_LSE_SHIFT;
}

/** Initialize allocation of FIFO block in CAN message RAM.
 *
 * Allows specifying size of FIFO block (in term of available messages in FIFO
 * and FIFO base address within CAN message RAM. Note, that there are no limitations
 * nor checking on address provided.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] fifo_id ID of fifo being configured
 * @param [in] fxsa FIFO block start address offset in message RAM
 * @param [in] fxs number of elements to assign
 */
void fdcan_init_fifo_ram(uint32_t canport, unsigned fifo_id, uint32_t fxsa, uint8_t fxs)
{
	FDCAN_RXFIC(canport, fifo_id) = (FDCAN_RXFIC(canport, fifo_id)
		& ~(
			(FDCAN_RXFIC_FIS_MASK << FDCAN_RXFIC_FIS_SHIFT)
			| (FDCAN_RXFIC_FISA_MASK << FDCAN_RXFIC_FISA_SHIFT)
			))
		| (fxs << FDCAN_RXFIC_FIS_SHIFT)
		| (fxsa & (FDCAN_RXFIC_FISA_MASK << FDCAN_RXFIC_FISA_SHIFT));
}

/** Initialize allocation of transmit event block in CAN message RAM.
 *
 * Allows specifying size of transmit event block (in term of allocated events and block
 * base address within CAN message RAM. Note, that there are no limitations
 * nor checking on address provided.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] tesa block start address offset in message RAM
 * @param [in] tes number of elements to assign
 */
void fdcan_init_tx_event_ram(uint32_t canport, uint32_t tesa, uint8_t tes)
{
	FDCAN_TXEFC(canport) = (FDCAN_TXEFC(canport)
		& ~(
			(FDCAN_TXEFC_EFS_MASK << FDCAN_TXEFC_EFS_SHIFT)
			| (FDCAN_TXEFC_EFSA_MASK << FDCAN_TXEFC_EFSA_SHIFT)
			))
		| (tes << FDCAN_TXEFC_EFS_SHIFT)
		| (tesa & (FDCAN_TXEFC_EFSA_MASK << FDCAN_TXEFC_EFSA_SHIFT));
}

/** Initialize allocation of transmit queue block in CAN message RAM.
 *
 * Allows specifying size of transmit queue block (in term of allocated buffers and block
 * base address within CAN message RAM. Note, that there are no limitations
 * nor checking on address provided.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] tbsa block start address offset in message RAM
 * @param [in] tbs number of elements to assign
 */
void fdcan_init_tx_buffer_ram(uint32_t canport, uint32_t tbsa, uint8_t tbs)
{
	FDCAN_TXBC(canport) = (FDCAN_TXBC(canport)
		& ~(
			(FDCAN_TXBC_TFQS_MASK << FDCAN_TXBC_TFQS_SHIFT)
			| (FDCAN_TXBC_TBSA_MASK << FDCAN_TXBC_TBSA_SHIFT)
			))
		| (tbs << FDCAN_TXBC_TFQS_SHIFT)
		| (tbsa & (FDCAN_TXBC_TBSA_MASK << FDCAN_TXBC_TBSA_SHIFT));
}

/** Initialize size of data fields in reception buffers.
 *
 * Configures maximum size of message payload, which can be stored in different
 * reception buffers. Each buffer can have maximum payload size configured independently.
 * Buffers can only be configured to sizes which are valid sizes of FDCAN payload. Sizes smaller
 * than 8 are automatically padded to 8.
 * @note If you change these values, then content of reception buffers is invalidated. You may
 * also want to recalculate base addresses of objects in message RAM as their size might have
 * changed.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] rxbuf maximum storable payload size of dedicated RX buffer
 * @param [in] rxfifo0 maximum storable payload size of RX FIFO 0
 * @param [in] rxfifo1 maximum storable payload size of RX FIFO 1
 * @returns operation return status. See @ref fdcan_error.
 */
int fdcan_set_rx_element_size(uint32_t canport, uint8_t rxbuf, uint8_t rxfifo0, uint8_t rxfifo1)
{
	unsigned rxbufdlc = fdcan_length_to_dlc(rxbuf);
	unsigned rxfifo0dlc = fdcan_length_to_dlc(rxfifo0);
	unsigned rxfifo1dlc = fdcan_length_to_dlc(rxfifo1);

	if (rxbufdlc == 0xFF || rxfifo0dlc == 0xFF || rxfifo1dlc == 0xFF) {
		return FDCAN_E_INVALID;
	}

	/* RXESC fields use format of FDCAN DLC, albeit using only
	 * three LSBs. DLC < 8 is always allocated as 8 bytes and is always
	 * encoded as 0.
	 */
	if (rxbufdlc <= 8) {
		rxbufdlc = 0;
	} else {
		rxbufdlc &= ~(1 << 4);
	}

	if (rxfifo0dlc <= 8) {
		rxfifo0dlc = 0;
	} else {
		rxfifo0dlc &= ~(1 << 4);
	}

	if (rxfifo1dlc <= 8) {
		rxfifo1dlc = 0;
	} else {
		rxfifo1dlc &= ~(1 << 4);
	}

	FDCAN_RXESC(canport) = rxbufdlc << FDCAN_RXESC_RBDS_SHIFT
		| rxfifo1dlc << FDCAN_RXESC_F1DS_SHIFT
		| rxfifo0dlc << FDCAN_RXESC_F0DS_SHIFT;

	return FDCAN_E_OK;
}

/** Initialize size of data fields in transmit buffers.
 *
 * Configures maximum size of message payload, which can be stored either in dedicated
 * transmit buffer or into transmit queue/FIFO. One size is applied both to transmit buffer
 * and transmit queue / FIFO. Buffers can only be configured to sizes which are valid sizes
 * of FDCAN payload. Sizes smaller than 8 are automatically padded to 8 bytes.
 * @note If you change these values, then content of transmission buffers is invalidated. You may
 * also want to recalculate base addresses of objects in message RAM as their size might have
 * changed.
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] txbuf maximum storable payload size of TX buffer / FIFO / queue
 * @returns operation return status. See @ref fdcan_error.
 */
int fdcan_set_tx_element_size(uint32_t canport, uint8_t txbuf)
{
	unsigned txbufdlc = fdcan_length_to_dlc(txbuf);

	if (txbufdlc == 0xFF) {
		return FDCAN_E_INVALID;
	}

	if (txbufdlc <= 8) {
		txbufdlc = 0;
	} else {
		txbufdlc &= ~(1 << 4);
	}

	FDCAN_TXESC(canport) = txbufdlc << FDCAN_TXESC_TBDS_SHIFT;

	return FDCAN_E_OK;
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
 * This function is provided for source level compatibility with code written for
 * STM32G4. As an alternative, you can use @ref fdcan_init_std_filter_ram() and
 * @ref fdcan_init_ext_filter_ram() to have more control over filtering configuration.
 * Note that if you do so, your code won't be compatible with STM32G4 controllers.
 *
 * @param [in] canport FDCAN block base address. See @ref fdcan_block.
 * @param [in] std_filt requested amount of standard ID filter rules (0-28)
 * @param [in] ext_filt requested amount of extended ID filter rules (0-8)
 */
void fdcan_init_filter(uint32_t canport, uint8_t std_filt, uint8_t ext_filt)
{
	struct fdcan_standard_filter *lfssa;
	struct fdcan_extended_filter *lfesa;

	int can_id = FDCAN_BLOCK_ID(canport);

	int lfsofs = 0;
	int lfeofs = 0;
	int lfssize = std_filt * sizeof(struct fdcan_standard_filter);
	int lfesize = ext_filt * sizeof(struct fdcan_extended_filter);

	if (can_id == 0) {
		lfsofs = 0;
		lfeofs = lfssize;
	} else {
		lfsofs = CAN_MSG_BASE + CAN_MSG_SIZE - lfssize;
		lfeofs = lfsofs - lfesize;
	}

	fdcan_init_std_filter_ram(canport, lfsofs, 28);
	fdcan_init_ext_filter_ram(canport, lfeofs, 8);

	lfssa = fdcan_get_flssa_addr(canport);
	lfesa = fdcan_get_flesa_addr(canport);

	/* Only perform initialization of message RAM if there are
	 * any filters required
	 */
	if (std_filt > 0) {
		for (int q = 0; q < 28; ++q) {
			lfssa[q].type_id1_conf_id2 = 0;
		}
	}

	if (ext_filt > 0) {
		for (int q = 0; q < 8; ++q) {
			lfesa[q].conf_id1 = 0;
			lfesa[q].type_id2 = 0;
		}
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
	/* This block detects obviously invalid configuration of
	 * RX FIFOs and TX buffers. Such situation may happen
	 * if code originally targeted for STM32G4 is compiled for
	 * STM32H7. This code is not aware of H7 abilities and
	 * leaves this stuff unconfigured. We pick up here and
	 * assume, that the code wants the FDCAN to behave as if
	 * it was STM32G4. Therefore we will configure two three entry
	 * long RX FIFOs, three entry long TX event buffer and three
	 * entry long TX FIFO/queue here.
	 */
	if (FDCAN_RXFIFO_OFFSET(canport, 0) == 0
		&& FDCAN_RXFIFO_OFFSET(canport, 1) == 0
		&& FDCAN_TXBUF_OFFSET(canport) == 0
		&& FDCAN_TXEVT_OFFSET(canport) == 0
		&& FDCAN_RXESC(canport) == 0
		&& FDCAN_TXESC(canport) == 0
	   ) {
		/* These sizes are fixed based on what G4 contains. */
		int fifo0_size = 3 * sizeof(struct fdcan_rx_fifo_element);
		int fifo1_size = fifo0_size;
		int txevt_size = 3 * sizeof(struct fdcan_tx_event_element);
		int txbuf_size = 3 * sizeof(struct fdcan_tx_buffer_element);

		fdcan_set_rx_element_size(canport, 0, 64, 64);
		fdcan_set_tx_element_size(canport, 64);

		/* At this point we simply assume that FLSSA and FLESA were
		 * set up by calling fdcan_init_filter(). It they weren't,
		 * there just won't be allocated any space for them.
		 * That's not a problem as after fdcan_start returns, it is
		 * not possible to configure filter amount anymore.
		 *
		 * Default approach is to configure CAN1 to occupy bottom
		 * of message RAM and CAN1 to occupy top of message RAM keeping
		 * large unused space in between. This ensures that even if someone
		 * starts playing with CAN1, "implicit" configuration of CAN2 done
		 * here won't break things magically.
		 */
		if (FDCAN_BLOCK_ID(canport) == 0) {
			/* CAN1 will use bottom-up layout with
			 * FLSSA < FLESA < F0SA < F1SA < TXESA < TXBSA
			 * Rx buffer is not used.
			 */
			fdcan_init_fifo_ram(canport, 0,
					FDCAN_LFESA_OFFSET(canport)
					+ FDCAN_LSE_COUNT(canport) * sizeof(struct fdcan_extended_filter),
					3);
			fdcan_init_fifo_ram(canport, 1,
					FDCAN_RXFIFO_OFFSET(canport, 0) + fifo0_size, 3);
			fdcan_init_tx_event_ram(canport,
					FDCAN_RXFIFO_OFFSET(canport, 1) + fifo1_size, 3);
			fdcan_init_tx_buffer_ram(canport,
					FDCAN_TXEVT_OFFSET(canport) + txevt_size, 3);
		} else {
			/* LFESA might be uninitialized. In such case
			 * we forge it's address at the end of MSG RAM
			 */
			int lfesa_offs = FDCAN_LFESA_OFFSET(canport);
			if (lfesa_offs == 0) {
				lfesa_offs = CAN_MSG_SIZE;
			}
			/* CAN2 will use top-down layout with
			 * TXBSA < TXESA < F1SA < F0SA < FLESA < FLSSA
			 * Rx buffer is not used.
			 * This arrangement should ensure that even if
			 * CAN1 was configured manually, CAN2 default
			 * configuration should not break CAN1.
			 */
			fdcan_init_fifo_ram(canport, 0, lfesa_offs - fifo0_size, 3);
			fdcan_init_fifo_ram(canport, 1,
					FDCAN_RXFIFO_OFFSET(canport, 0) - fifo1_size, 3);
			fdcan_init_tx_event_ram(canport,
					FDCAN_RXFIFO_OFFSET(canport, 1) - txevt_size, 3);
			fdcan_init_tx_buffer_ram(canport,
					FDCAN_TXEVT_OFFSET(canport) - txbuf_size, 3);
		}

	}
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
		FDCAN_RXF0C(canport) &= ~(FDCAN_RXF0C_F0OM);
		FDCAN_RXF1C(canport) &= ~(FDCAN_RXF1C_F1OM);
	} else {
		FDCAN_RXF0C(canport) |= FDCAN_RXF0C_F0OM;
		FDCAN_RXF1C(canport) |= FDCAN_RXF1C_F1OM;
	}
}

/**@}*/
