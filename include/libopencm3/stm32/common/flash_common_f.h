/** @addtogroup flash_defines
 *
 */
/*
 * This file is part of the libopencm3 project.
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

#pragma once

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

/**
 * Clear the End of OPeration flag.
 */
void flash_clear_eop_flag(void);

/**
 * Clear all status flags.
 * The number of bits can vary across families.
 */
void flash_clear_status_flags(void);

/** Wait until Last Operation has Ended.
 * This loops indefinitely until an operation (write or erase) has completed by
 * testing the busy flag
 */
void flash_wait_for_last_operation(void);

END_DECLS