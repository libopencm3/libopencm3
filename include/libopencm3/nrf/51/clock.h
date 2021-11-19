/*
 * This file is part of the unicore-mx project.
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

#ifndef NRF51_CLOCK_H
#define NRF51_CLOCK_H

#include <stdbool.h>

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/common/clock.h>

/* Clock registers */
#define CLOCK_XTALFREQ          MMIO32(CLOCK_BASE + 0x550)

#define CLOCK_PCLK              16000000

enum clock_xtal_freq {
    CLOCK_XTAL_FREQ_32MHZ,
    CLOCK_XTAL_FREQ_16MHZ = 0xff,
};

BEGIN_DECLS

void clock_set_xtal_freq(enum clock_xtal_freq freq);

END_DECLS

#endif  /* NRF51_CLOCK_H */
