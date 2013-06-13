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

#include <libopencm3/cm3/sync.h>

u32 __ldrex(volatile u32 *addr)
{
	u32 res;
	__asm__ volatile ("ldrex %0, [%1]" : "=r" (res) : "r" (addr));
	return res;
}

u32 __strex(u32 val, volatile u32 *addr)
{
	u32 res;
	__asm__ volatile ("strex %0, %2, [%1]"
			  : "=&r" (res) : "r" (addr), "r" (val));
	return res;
}

void __dmb()
{
	__asm__ volatile ("dmb");
}

void mutex_lock(mutex_t *m)
{
	u32 status = 0;

	do {
		/* Wait until the mutex is unlocked. */
		while (__ldrex(m) != MUTEX_UNLOCKED);

		/* Try to acquire it. */
		status = __strex(MUTEX_LOCKED, m);

	/* Did we get it? If not then try again. */
	} while (status != 0);

	/* Execute the mysterious Data Memory Barrier instruction! */
	__dmb();
}

void mutex_unlock(mutex_t *m)
{
	__dmb();

	/* Free the lock. */
	*m = MUTEX_UNLOCKED;
}

