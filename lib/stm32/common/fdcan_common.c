/**
 * @brief <b>libopencm3 STM32 FDCAN Controller</b>
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Matt Walker <m@allocor.tech>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.	If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/fdcan.h>
#include <string.h>

static const uint8_t FD_DLC_LEN[] = { 12, 16, 20, 24, 32, 48, 64 };

/** Return the data length of a frame in bytes given its DLC field.
 * @returns the DLC, or MAXDLC+1 if length is unsupported.
 */
uint8_t fdcan_len_to_dlc(uint32_t len)
{
	if (len <= 8) {
		return (uint8_t)len;
	} else {
		uint8_t dlc;
		for (dlc = 0; dlc < sizeof(FD_DLC_LEN); ++dlc) {
			if (len <= FD_DLC_LEN[dlc]) {
				break;
			}
		}
		// Note that this returns sizeof(kDlcLen) + 1 on length too long
		return (uint8_t)(dlc + 9);
	}
}

/** Return the DLC of a frame given its data length in bytes. */
uint8_t fdcan_dlc_to_len(uint8_t dlc)
{
	if (dlc <= 8) {
		return dlc;
	} else {
		return FD_DLC_LEN[dlc - 9];
	}
}

/** Stop the kernel clock of the FDCAN device. */
void fdcan_stop_clock(uint32_t candev)
{
	FDCAN_CCCRR(candev) |= FDCAN_CCCR_CSR;
	while ((FDCAN_CCCRR(candev) & FDCAN_CCCR_CSA) == 0) {
		continue;
	}
}

/** Restart the kernel clock of the FDCAN device. */
void fdcan_start_clock(uint32_t candev)
{
	FDCAN_CCCRR(candev) &= ~(FDCAN_CCCR_CSR | FDCAN_CCCR_CSA);
	FDCAN_CCCRR(candev) &= ~FDCAN_CCCR_INIT;
}

/** Set CAN2.0 / nominal bit timing */
void fdcan_set_nominal_bittiming(uint32_t candev,
				 const struct can_bittiming *nbt)
{
	uint32_t reg = FDCAN_NBTPR(candev);

	reg = CM3_SET_MASK(reg, FDCAN_NBTP_NSJW, nbt->sjw - 1);
	reg = CM3_SET_MASK(reg, FDCAN_NBTP_NBRP, nbt->brp - 1);
	reg = CM3_SET_MASK(reg, FDCAN_NBTP_NTSEG1,
			   nbt->prop_seg + nbt->phase_seg1 - 1);
	reg = CM3_SET_MASK(reg, FDCAN_NBTP_NTSEG2, nbt->phase_seg2 - 1);

	FDCAN_NBTPR(candev) = reg;
}

/** Set FD CAN bit timing and set transceiver compensation. */
void fdcan_set_fd_bittiming(uint32_t candev, const struct can_bittiming *fdt,
			    uint32_t txcvr_loop_delay_ns)
{
	/* Determine if we need a secondary sample point. We only need this if
	 * the transceiver loop delay is going to fall outside of the primary
	 * sample point. */
	uint32_t scaled_clock_mhz =
		(fdt->bitrate *
		 (1 + fdt->prop_seg + fdt->phase_seg1 + fdt->phase_seg2)) /
		1000000;
	uint32_t delay_clocks = (txcvr_loop_delay_ns * scaled_clock_mhz) / 1000;
	if (delay_clocks <= fdt->phase_seg1) {
		delay_clocks = 0;
	} else if (delay_clocks > 127) {
		delay_clocks = 127;
	}

	uint32_t reg = FDCAN_DBTPR(candev);
	if (delay_clocks) {
		reg |= FDCAN_DBTP_TDC;
	} else {
		reg &= ~FDCAN_DBTP_TDC;
	}
	reg = CM3_SET_MASK(reg, FDCAN_DBTP_DSJW, fdt->sjw - 1);
	reg = CM3_SET_MASK(reg, FDCAN_DBTP_DBRP, fdt->brp - 1);
	reg = CM3_SET_MASK(reg, FDCAN_DBTP_DTSEG1,
			   fdt->prop_seg + fdt->phase_seg1 - 1);
	reg = CM3_SET_MASK(reg, FDCAN_DBTP_DTSEG2, fdt->phase_seg2 - 1);
	FDCAN_DBTPR(candev) = reg;

	reg = FDCAN_TDCRR(candev);
	reg = CM3_SET_MASK(reg, FDCAN_TDCR_TDCO, delay_clocks);
	reg = CM3_SET_MASK(reg, FDCAN_TDCR_TDCF, 0);
	FDCAN_TDCRR(candev) = reg;
}

/** Obtain the length of a RAM element given its configuration enumeration. */
uint32_t fdcan_esc_to_bytes(enum fdcan_esc e)
{
	switch (e) {
	case FDCAN_ESC_8:
		return 8;
	case FDCAN_ESC_12:
		return 12;
	case FDCAN_ESC_16:
		return 16;
	case FDCAN_ESC_20:
		return 20;
	case FDCAN_ESC_24:
		return 24;
	case FDCAN_ESC_32:
		return 32;
	case FDCAN_ESC_48:
		return 48;
	case FDCAN_ESC_64:
		return 64;
	}
	return 0;
}

/** Obtain a pointer to the TX element at index \p idx. */
struct fdcan_txelement *fdcan_get_txelement_at_index(uint32_t candev,
						     uint32_t idx)
{
	uint32_t offset =
		CAN_MSG_BASE +
		(CM3_GET_MASK(FDCAN_TXBCR(candev), FDCAN_TXBC_TBSA) * 4);
	enum fdcan_esc esc = (enum fdcan_esc)(
		(FDCAN_TXESCR(candev) >> FDCAN_TXESC_TBDS_SHIFT) &
		FDCAN_ESC_MASK);
	uint32_t elem_len =
		sizeof(struct fdcan_txelement) + fdcan_esc_to_bytes(esc);
	return (struct fdcan_txelement *)(offset + (idx * elem_len));
}

/** Obtain a pointer to the current read element in FIFO 0. This does not check
 * if the current read index is valid, nor does it acknowledge that the element
 * has been read.
 * @param candev	Base RAM address of FDCAN device to configure.
 * @param elem		Pointer to fill with pointer to the current read
 * element.
 * @returns 		Index of current read element.
 */
uint32_t fdcan_get_next_fifo0(uint32_t candev, struct fdcan_rxelement **elem)
{
	uint32_t rxf0cr = FDCAN_RXF0CR(candev);
	uint32_t offset =
		CAN_MSG_BASE + (CM3_GET_MASK(rxf0cr, FDCAN_RXF0C_F0SA) * 4);

	uint32_t rxf0s = FDCAN_RXF0SR(candev);
	uint32_t idx = CM3_GET_MASK(rxf0s, FDCAN_RXF0S_F0GI);

	/* If we are full, and if we are using overwrite mode, then we have
	 * to return the idx+1 slot in case we receive a message while reading.
	 */
	if ((rxf0cr & FDCAN_RXF0C_F0OM) && (rxf0s & FDCAN_RXF0S_F0F)) {
		++idx;
		if (idx >=
		    CM3_GET_MASK(FDCAN_XIDFCR(candev), FDCAN_XIDFC_LSE)) {
			idx = 0;
		}
	}

	enum fdcan_esc esc = (enum fdcan_esc)(
		(FDCAN_RXESCR(candev) >> FDCAN_RXESC_F0DS_SHIFT) &
		FDCAN_ESC_MASK);
	uint32_t elem_len =
		sizeof(struct fdcan_rxelement) + fdcan_esc_to_bytes(esc);

	*elem = (struct fdcan_rxelement *)(offset + idx * elem_len);
	return idx;
}

/** Configure the RAM layout for a FDCAN device. This layout is not checked
 * against any other FDCAN device overlap.
 * @param candev		Base RAM address of FDCAN device to configure.
 * @param ram_offset	Offset into FDCAN shared RAM to start the map at. Must
 * not overlap with a mapping from any other FDCAN device.
 * @param cfg 			RAM configuration structure.
 * @returns				Ending offset of the map.
 */
uint32_t fdcan_configure_ram(uint32_t candev, uint32_t ram_offset,
			     const struct fdcan_ram_config *cfg)
{
	uint8_t* starting_addr = (uint8_t*)CAN_MSG_BASE + (ram_offset * 4);
	uint32_t starting_offset = ram_offset;

	uint32_t reg32;

	FDCAN_RXESCR(candev) =
		(cfg->rx_buffer_elem_len << FDCAN_RXESC_RBDS_SHIFT) |
		(cfg->rx_fifo1_elem_len << FDCAN_RXESC_F1DS_SHIFT) |
		(cfg->rx_fifo0_elem_len << FDCAN_RXESC_F0DS_SHIFT);

	FDCAN_TXESCR(candev) = (cfg->tx_elem_len << FDCAN_TXESC_TBDS_SHIFT);

	/* Standard filter */
	reg32 = FDCAN_SIDFCR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_SIDFC_LSS, cfg->standard_filter_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_SIDFC_FLSSA, ram_offset);
	FDCAN_SIDFCR(candev) = reg32;
	ram_offset +=
		cfg->standard_filter_len * (sizeof(struct fdcan_stdfilt) / 4);

	/* Extended filter */
	reg32 = FDCAN_XIDFCR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_XIDFC_LSE, cfg->extended_filter_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_XIDFC_FLESA, ram_offset);
	FDCAN_XIDFCR(candev) = reg32;
	ram_offset +=
		cfg->extended_filter_len * (sizeof(struct fdcan_extfilt) / 4);

	/* RX FIFO 0 */
	reg32 = FDCAN_RXF0CR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_RXF0C_F0S, cfg->rx_fifo0_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_RXF0C_F0SA, ram_offset);
	if (cfg->rx_fifo0_overwrite) {
		reg32 |= FDCAN_RXF0C_F0OM;
	} else {
		reg32 &= ~FDCAN_RXF0C_F0OM;
	}
	FDCAN_RXF0CR(candev) = reg32;
	ram_offset += cfg->rx_fifo0_len *
		      ((sizeof(struct fdcan_rxelement) +
			fdcan_esc_to_bytes(cfg->rx_fifo0_elem_len)) /
		       4);

	/* RX FIFO 1 */
	reg32 = FDCAN_RXF1CR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_RXF1C_F1S, cfg->rx_fifo1_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_RXF1C_F1SA, ram_offset);
	if (cfg->rx_fifo1_overwrite) {
		reg32 |= FDCAN_RXF1C_F1OM;
	} else {
		reg32 &= ~FDCAN_RXF1C_F1OM;
	}
	FDCAN_RXF1CR(candev) = reg32;
	ram_offset += cfg->rx_fifo1_len *
		      ((sizeof(struct fdcan_rxelement) +
			fdcan_esc_to_bytes(cfg->rx_fifo1_elem_len)) /
		       4);

	/* RX Buffer */
	reg32 = FDCAN_RXBCR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_RXBC_RBSA, cfg->rx_buffer_len);
	FDCAN_RXBCR(candev) = reg32;
	ram_offset += cfg->rx_buffer_len *
		      ((sizeof(struct fdcan_rxelement) +
			fdcan_esc_to_bytes(cfg->rx_buffer_elem_len)) /
		       4);

	/* TX Event FIFO */
	reg32 = FDCAN_TXEFCR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_TXEFC_EFS, cfg->tx_event_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_TXEFC_EFSA, ram_offset);
	FDCAN_TXEFCR(candev) = reg32;
	ram_offset += cfg->tx_event_len * (sizeof(struct fdcan_txevent) / 4);

	/* TX Buffer */
	reg32 = FDCAN_TXBCR(candev);
	reg32 = CM3_SET_MASK(reg32, FDCAN_TXBC_TFQS, cfg->tx_fifo_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_TXBC_NDTB, cfg->tx_buf_len);
	reg32 = CM3_SET_MASK(reg32, FDCAN_TXBC_TBSA, ram_offset);
	if (cfg->tx_fifo_queue_mode) {
		reg32 |= FDCAN_TXBC_TFQM;
	} else {
		reg32 &= ~FDCAN_TXBC_TFQM;
	}
	FDCAN_TXBCR(candev) = reg32;
	ram_offset += (cfg->tx_fifo_len + cfg->tx_buf_len) *
		      ((sizeof(struct fdcan_txelement) +
			fdcan_esc_to_bytes(cfg->tx_elem_len)) /
		       4);

	/* Ensure there is no old configuration laying around from a previous
	 * configuration. */
	memset(starting_addr, 0, (ram_offset - starting_offset) * 4);

	return ram_offset;
}
