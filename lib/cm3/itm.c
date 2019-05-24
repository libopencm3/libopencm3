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

/**
@section  itm_example Example ITM setup for async SWO

Example: Async SWO output enabled, Manchester format, 8MHz:
@code
  // Enable trace subsystem
  scs_set_trace_enabled(true);

  // Use Manchester code for asynchronous transmission
  tpiu_set_trace_output_mode(TPIU_SPPR_ASYNC_MANCHESTER);

  // 8MHz operation
  tpiu_set_output_clock_speed(8000000);

  // Disable formatter
  tpiu_set_continuous_formatting_enabled(false);

  // Enable TRACESWO pin for async mode.
  DBGMCU_CR = DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE_ASYNC;

  // Unlock access to ITM registers.
  itm_set_write_access_enabled(true);

  // Enable ITM with ID = 1.
  itm_set_trace_bus_id(1);
  itm_set_enabled(true);

  // Enable stimulus port
  itm_enable_stimulus_ports(ITM_PORT0);

  // Send message to host
  itm_send_string(0, "SWO Enabled\n");
@endcode

*/

#include <libopencm3/cm3/itm.h>

/*---------------------------------------------------------------------------*/
/** @brief ITM Enable/disable write access to ITM control registers
 *
 * In order to access control registers 0xE00:0xFFC, the Lock Access Register
 * must be written with a magic value.
 * Writing any other value will disable write access to the registers.
 *
 * @return void
 */
void itm_set_write_access_enabled(bool enable) {
  if (enable) {
    ITM_LAR = ITM_LAR_WRITE_ENABLE;
  } else {
    ITM_LAR = 0;
  }
}

/*---------------------------------------------------------------------------*/
/** @brief ITM Set Advanced Trace Bus ID
 *
 * @return void
 */
void itm_set_trace_bus_id(uint8_t id) {
  ITM_TCR = (ITM_TCR & ~ITM_TCR_TRACE_BUS_ID_MASK) |
            ((id & ITM_TCR_TRACE_BUS_ID_MASK) << 16);
}

/*---------------------------------------------------------------------------*/
/** @brief ITM Enable/disable ITM.
 *
 * Set/clear the master enable bit on the ITM. This must be enabled before ITM
 * stimulus and trace enable registers can be written.
 *
 * @return void
 */
void itm_set_enabled(bool enable) {
  if (enable) {
    ITM_TCR |= ITM_TCR_ITMENA;
  } else {
    ITM_TCR &= ~ITM_TCR_ITMENA;
  }
}

/*---------------------------------------------------------------------------*/
/** @brief Enable a given set of stimulus ports (ITM_PORTN) */
void itm_enable_stimulus_ports(uint32_t ports) { ITM_TER[0] |= ports; }

/*---------------------------------------------------------------------------*/
/** @brief Disable a given set of stimulus ports (ITM_PORTN) */
void itm_disable_stimulus_ports(uint32_t ports) { ITM_TER[0] &= ~ports; }

/*---------------------------------------------------------------------------*/
/** @brief Directly configure the mask of enabled ITM ports (ITM_PORTN) */
void itm_set_stimulus_port_mask(uint32_t mask) { ITM_TER[0] = mask; }

/*---------------------------------------------------------------------------*/
/** @brief Write a byte to the given ITM stimulus port */
void itm_send_blocking_u8(uint8_t port, uint8_t datum) {
  // Wait for stimulus port to become available
  while (!(ITM_STIM8(port) & ITM_STIM_FIFOREADY)) {
  }
  // Write datum
  ITM_STIM8(port) = datum;
}

/*---------------------------------------------------------------------------*/
/** @brief Write a byte to the given ITM stimulus port */
void itm_send_blocking_u16(uint8_t port, uint16_t datum) {
  // Wait for stimulus port to become available
  while (!(ITM_STIM16(port) & ITM_STIM_FIFOREADY)) {
  }
  // Write datum
  ITM_STIM16(port) = datum;
}

/*---------------------------------------------------------------------------*/
/** @brief Write a byte to the given ITM stimulus port */
void itm_send_blocking_u32(uint8_t port, uint32_t datum) {
  // Wait for stimulus port to become available
  while (!(ITM_STIM32(port) & ITM_STIM_FIFOREADY)) {
  }
  // Write datum
  ITM_STIM32(port) = datum;
}

/*---------------------------------------------------------------------------*/
/** @brief Write a C string to the given stimulus port
 *
 * String must be terminated with a NULL byte.
 * This method will block until the data is fully sent.
 */
void itm_send_string(uint8_t port, const char *s) {
  // While we do not hit a '\0', send a byte on the given ITM port
  while (*s) {
    itm_send_blocking_u8(port, ((uint8_t)*s));
    s++;
  }
}

