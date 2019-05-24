/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019
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

#include <libopencm3/cm3/scs.h>

/*---------------------------------------------------------------------------*/
/** @brief SCS Enable/disable trace and debug blocks
 *
 * Enable/disable access to the following:
 *  - Data Watchpoint and Trace (DWT)
 *  - Instrumentation Trace Macrocell (ITM)
 *  - Embedded Trace Macrocess (ETM)
 *  - Trace Port Interface Unit (TPIU)
 *
 * @return void
 */
void scs_set_trace_enabled(bool enable) {
  if (enable) {
    SCS_DEMCR |= SCS_DEMCR_TRCENA;
  } else {
    SCS_DEMCR &= ~SCS_DEMCR_TRCENA;
  }
}

