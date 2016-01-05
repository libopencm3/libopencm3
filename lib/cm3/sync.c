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

/* DMB is supported on CM0 */
void __dmb()
{
	__asm__ volatile ("dmb");
}

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

uint32_t __ldrex(volatile uint32_t *addr)
{
	uint32_t res;
	__asm__ volatile ("ldrex %0, [%1]" : "=r" (res) : "r" (addr));
	return res;
}

uint32_t __strex(uint32_t val, volatile uint32_t *addr)
{
	uint32_t res;
	__asm__ volatile ("strex %0, %2, [%1]"
			  : "=&r" (res) : "r" (addr), "r" (val));
	return res;
}

void mutex_lock(mutex_t *m)
{
	while (!mutex_trylock(m));
}

/* returns 1 if the lock was acquired */
uint32_t mutex_trylock(mutex_t *m)
{
	uint32_t status = 1;

	/* If the mutex is unlocked. */
	if (__ldrex(m) == MUTEX_UNLOCKED) {
		/* Try to lock it. */
		status = __strex(MUTEX_LOCKED, m);
	}

	/* Execute the mysterious Data Memory Barrier instruction! */
	__dmb();

	/* Did we get the lock? If not then try again
	 * by calling this function once more. */
	return status == 0;
}

void mutex_unlock(mutex_t *m)
{
	/* Ensure accesses to protected resource are finished */
	__dmb();

	/* Free the lock. */
	*m = MUTEX_UNLOCKED;
}

#endif
