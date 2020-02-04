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

/** @file
 * CAN Bit Timing Calculation
 *
 * Computing the bit times in CAN is not as simple as setting a baud rate,
 * instead each controller needs to know the location of several critical points
 * inside of each bit so that it can determine if arbitration has failed, or if
 * a remote device is reporting an error.
 *
 * To this end, CAN bits are divided into 4 non overlapping segments:
 *
 *		 +----------+----------------+------------+------------+
 *		 | SYNC_SEG |    PROP_SEG    | PHASE_SEG1 | PHASE_SEG2 |
 *		 +----------+----------------+------------+------------+
 *		 ^                                        ^            ^
 *		 |                                  Sample point       |
 *		 | <----------- Nominal Bit Time --------------------> |
 *
 * Each segment inside of the bit lasts for an integer multiple of a unit of
 * time called a Time Quantum. The duration of the time quantum is defined by
 * the system clock divided by the bit rate pre-scaler (brp).
 *
 * The synchronization segment, where the controller is looking for a bit
 * transition, is always 1 time quantum long. To account for variable phase
 * delay, likely due to clock drift, receivers are allowed to shift the start
 * of the synchronization segment by no more than their synchronization jump
 * width value (customizable, but this value has impacts on the maximum bus
 * length and bit rate.)
 *
 * The propagation delay segment, PROP_SEG, exists to delay the earliest
 * possible sample of the bit by a node until the transmitted bit values
 * from all the transmitting nodes have reached all of the nodes.
 *
 * If more than one sample per bit is taken, the sample point marks the
 * position of the final sample.
 */

#ifndef LIBOPENCM3_CAN_BIT_TIMING_H
#define LIBOPENCM3_CAN_BIT_TIMING_H

#include <libopencm3/cm3/common.h>

/** Constant data reflecting the capabilities of the CAN controller. */
struct can_bittiming_const {
	/** @{ Time segment 1 = prop_seg + phase_seg1 */
	uint32_t tseg1_min;
	uint32_t tseg1_max;
	/** @} */
	/** @{ Time segment 2 = phase_seg2 */
	uint32_t tseg2_min;
	uint32_t tseg2_max;
	/** @} */
	/** Synchronization jump width */
	uint32_t sjw_max;
	/** @{ Bitrate pre-scaler */
	uint32_t brp_min;
	uint32_t brp_max;
	uint32_t brp_inc;
	/** @} */
};

/** Resulting best fit CAN bit timing result. */
struct can_bittiming {
	/** Realized bitrate in bits per second. */
	uint32_t bitrate;
	/** Bitrate pre-scaler applied to system clock. */
	uint32_t brp;
	/** Realized sample point in tenths of a percent. */
	uint32_t sample_point;
	/** Propagation segment length in time quanta */
	uint32_t prop_seg;
	/** Phase buffer segment 1 length in time quanta */
	uint32_t phase_seg1;
	/** Phase buffer segment 2 length in time quanta */
	uint32_t phase_seg2;
	/** Synchronization jump width in time quanta. */
	uint32_t sjw;
};

BEGIN_DECLS
bool can_get_bittiming(uint32_t desired_bit_rate, uint32_t desired_spt,
		uint32_t desired_sjw, uint32_t base_freq,
		const struct can_bittiming_const* btc, struct can_bittiming* result);
END_DECLS

#endif /* LIBOPENCM3_CAN_BIT_TIMING_H */
