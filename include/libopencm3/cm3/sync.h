/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_CM3_SYNC_H
#define LIBOPENCM3_CM3_SYNC_H

#include "common.h"

/* Implements synchronisation primatives as discussed in the ARM document
 * DHT0008A (ID081709) "ARM Synchronization Primitives" and the ARM v7-M
 * Architecture Reference Manual.
*/

/* --- Exclusive load and store instructions ------------------------------- */

u32 __ldrex(volatile u32* addr);
u32 __strex(u32 val, volatile u32* addr);
void __dmb(void);

/* --- Convenience functions ----------------------------------------------- */

/* Here we implement some simple synchronisation primatives. */

typedef u32 mutex_t;

#define MUTEX_UNLOCKED 0
#define MUTEX_LOCKED	 1

void mutex_lock(mutex_t* m);
void mutex_unlock(mutex_t* m);

#endif
