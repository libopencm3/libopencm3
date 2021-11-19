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

#ifndef NRF_COMMON_OSTICK_H
#define NRF_COMMON_OSTICK_H

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

void ostick_init(uint16_t interval_ms, void (*ostick_handler)(void));
void ostick_start(void);
void ostick_isr(void);
void ostick_stop(void);

END_DECLS

#endif  /* NRF_OSTICK_H */
