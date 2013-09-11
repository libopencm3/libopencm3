/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Ben Gamari <bgamari@gmail.com>
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

#ifndef LIBOPENCM3_CORTEX_H
#define LIBOPENCM3_CORTEX_H

static inline void cm_enable_interrupts(void)
{
	__asm__("CPSIE I\n");
}

static inline void cm_disable_interrupts(void)
{
	__asm__("CPSID I\n");
}

static inline void cm_enable_faults(void)
{
	__asm__("CPSIE F\n");
}

static inline void cm_disable_faults(void)
{
	__asm__("CPSID F\n");
}

/* __attribute__(( always_inline )) */
static inline bool cm_is_masked_interrupts(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, PRIMASK"  : "=r" (result) );
	return (result);
}

/* __attribute__(( always_inline )) */
static inline bool cm_is_masked_faults(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, FAULTMASK"  : "=r" (result) );
	return (result);
}

/* __attribute__(( always_inline )) */
static inline bool cm_mask_interrupts(bool mask)
{
	register bool old;
	__asm__ __volatile__("MRS %0, PRIMASK"  : "=r" (old));
	__asm__ __volatile__(""  ::: "memory");
	__asm__ __volatile__("MSR PRIMASK, %0" : : "r" (mask));
	return old;
}

/* __attribute__(( always_inline )) */
static inline bool cm_mask_faults(bool mask)
{
	register bool old;
	__asm__ __volatile__ ("MRS %0, FAULTMASK"  : "=r" (old));
	__asm__ __volatile__(""  ::: "memory");
	__asm__ __volatile__ ("MSR FAULTMASK, %0" : : "r" (mask));
	return old;
}


#endif
