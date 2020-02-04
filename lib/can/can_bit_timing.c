/*
 * This file is part of the libopencm3 project.
 *
 * Heavily based on code from LinCAN sources, the H8S2638 project, and the
 * linux-can projects.
 * Copyright 2004-2006 Pavel Pisa - DCE FELK CVUT cz
 * Copyright 2005      Stanislav <pisa@cmp.felk.cvut.cz>
 * Copyright 2019      Matt Walker <m@allocor.tech>
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

#include <libopencm3/can/can_bit_timing.h>
#include <math.h>

/** CiA recommended sample point for CANopen, in tenths of a percent. */
#define CIA_SAMPLE_PT 875

/** Standard defined synchronization segment length, in time quanta. */
#define SYNC_SEG_LEN 1

/** Maximum allowed bit rate error allowed in a valid solution, in tenths of a
 * percent. */
#define MAX_BIT_RATE_ERR 25

/* ========================================================================== */
static bool update_can_spt(const struct can_bittiming_const *btc,
			   uint32_t desired_spt, uint32_t nbt_tq,
			   uint32_t *best_tseg1, uint32_t *best_tseg2,
			   int32_t *best_spt_err, uint32_t *best_spt)
{
	bool updated = false;
	for (uint32_t i = 0; i < 2; ++i) {
		uint32_t tseg2 = nbt_tq - ((desired_spt * nbt_tq) / 1000) - i;
		if (tseg2 < btc->tseg2_min) {
			tseg2 = btc->tseg2_min;
		} else if (tseg2 > btc->tseg2_max) {
			tseg2 = btc->tseg2_max;
		}

		/* Obtain tseg1, but adjust tseg2 if tseg1 was out of bounds.
		 * Because we only iterate over valid (tseg1 + tseg2) we know
		 * that we don't have to go check tseg2 for validity again. */
		uint32_t tseg1 = nbt_tq - SYNC_SEG_LEN - tseg2;
		if (tseg1 > btc->tseg1_max) {
			tseg1 = btc->tseg1_max;
			tseg2 = nbt_tq - SYNC_SEG_LEN - tseg1;
		} else if (tseg1 < btc->tseg1_min) {
			tseg1 = btc->tseg1_min;
			tseg2 = nbt_tq - SYNC_SEG_LEN - tseg1;
		}

		uint32_t spt = (1000 * (nbt_tq - tseg2)) / nbt_tq;
		int32_t spt_err = (int32_t)desired_spt - (int32_t)spt;
		if (spt_err < 0) {
			spt_err *= -1;
		}

		if (spt_err < *best_spt_err) {
			updated = true;
			*best_spt_err = spt_err;
			*best_tseg1 = tseg1;
			*best_tseg2 = tseg2;
			*best_spt = spt;
		}
	}
	return updated;
}

/* ========================================================================== */
/** Compute CAN bus bit timing.
 * @param desired_bit_rate	Target bit rate of the CAN bus.
 * @param desired_spt		Target sample point, expressed as tenths of a
 * 							percent. If 0, CAN in Automation recommended
 * 							values are used.
 * @param desired_sjw		Target synchronization jump width. If 0, the
 * 							value 1 will be used.
 * @param base_freq			Base frequency of device from which the
 *							time quanta derived by dividing by the bit rate
 *							pre-scaler.
 * @param btc				Device bit timing constraints.
 * @param result			Calculated result.
 *
 * @returns True if the resultant bit rate and sample point are within 5% of the
 * desired values.
 */
bool can_get_bittiming(uint32_t desired_bit_rate, uint32_t desired_spt,
		       uint32_t desired_sjw, uint32_t base_freq,
		       const struct can_bittiming_const *btc,
		       struct can_bittiming *result)
{
	if (desired_bit_rate == 0 || desired_bit_rate > 8000000) {
		return false;
	}
	if (desired_spt > 1000) {
		return false;
	}
	if (btc == 0 || result == 0) {
		return false;
	}

	if (desired_spt == 0) {
		desired_spt = CIA_SAMPLE_PT;
	}

	int32_t best_br_err = INT32_MAX;
	int32_t best_spt_err = INT32_MAX;

	/* Compute all possible segment lengths to determine what is going to
	 * best fit our available prescalers. We multiply things by 2 so that we
	 * can round (even down, odd up) which allows us to explore our
	 * prescalers more easily.
	 */
	uint32_t nbt_tq_x2;
	for (nbt_tq_x2 =
		     (btc->tseg1_max + btc->tseg2_max) * 2 + SYNC_SEG_LEN + 1;
	     nbt_tq_x2 >= (btc->tseg1_min + btc->tseg2_min) * 2 + SYNC_SEG_LEN;
	     --nbt_tq_x2) {
		uint32_t nbt_tq = nbt_tq_x2 / 2;
		uint32_t brp = (base_freq / (nbt_tq * desired_bit_rate)) +
			       (nbt_tq_x2 % 2);

		/* Account for BRP step limitations */
		brp = (brp / btc->brp_inc) * btc->brp_inc;
		if ((brp < btc->brp_min) || (brp > btc->brp_max)) {
			continue;
		}

		/* Determine our bitrate and absolute error */
		uint32_t br = base_freq / (brp * nbt_tq);
		int32_t br_err = (int32_t)(desired_bit_rate) - (int32_t)(br);
		if (br_err < 0) {
			br_err *= -1;
		}
		if (br_err > best_br_err) {
			continue;
		}

		/* If we have a better bitrate; reset the sample point error. */
		if (br_err < best_br_err) {
			best_spt_err = INT32_MAX;
		}

		/* Find our best sample point, if we updated it then this is now
		 * our best
		 * bitrate (otherwise we would have bailed before now.) */
		uint32_t tseg1;
		if (!update_can_spt(btc, desired_spt, nbt_tq, &tseg1,
				    &result->phase_seg2, &best_spt_err,
				    &result->sample_point)) {
			continue;
		}

		result->prop_seg = tseg1 / 2;
		result->phase_seg1 = tseg1 - result->prop_seg;

		result->bitrate = br;
		result->brp = brp;
		best_br_err = br_err;

		/* If we're perfect, we don't need to search any more */
		if (best_br_err == 0 && best_spt_err == 0) {
			break;
		}
	}

	/* Check the SJW and ensure it is reasonable */
	if (desired_sjw == 0 || btc->sjw_max == 0) {
		result->sjw = 1;
	} else {
		result->sjw = btc->sjw_max;
		if (result->sjw > btc->sjw_max) {
			result->sjw = btc->sjw_max;
		}
		if (result->sjw > result->phase_seg2) {
			result->sjw = result->phase_seg2;
		}
	}

	/* Ensure we're not returning terrible results */
	if ((best_br_err * 1000 / desired_bit_rate) > MAX_BIT_RATE_ERR) {
		return false;
	}

	return true;
}
