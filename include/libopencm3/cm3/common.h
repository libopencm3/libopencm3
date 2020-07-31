/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_CM3_COMMON_H
#define LIBOPENCM3_CM3_COMMON_H

#ifdef __cplusplus
/* Declarations need wrapping for C++ */
# define BEGIN_DECLS extern "C" {
# define END_DECLS }
#elif defined(__ASSEMBLER__)
/* skipping for assembly */
#define BEGIN_DECLS .if 0
#define END_DECLS .endif
#else
/* And nothing for C */
# define BEGIN_DECLS
# define END_DECLS
#endif

/* Full-featured deprecation attribute with fallback for older compilers. */

#ifdef __GNUC__
#	if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 4)
#		define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))
#	else
#		define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated))
#	endif
#else
#	define LIBOPENCM3_DEPRECATED(x)
#endif


#if defined (__ASSEMBLER__)
#define MMIO8(addr)	(addr)
#define MMIO16(addr)	(addr)
#define MMIO32(addr)	(addr)
#define MMIO64(addr)	(addr)

#define BBIO_SRAM(addr, bit) \
	(((addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)

#define BBIO_PERIPH(addr, bit) \
	(((addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)
#else

#include <stdint.h>
#include <stdbool.h>

/* Generic memory-mapped I/O accessor functions */
#define MMIO8(addr)		(*(volatile uint8_t *)(addr))
#define MMIO16(addr)		(*(volatile uint16_t *)(addr))
#define MMIO32(addr)		(*(volatile uint32_t *)(addr))
#define MMIO64(addr)		(*(volatile uint64_t *)(addr))

/* Generic bit-band I/O accessor functions */
#define BBIO_SRAM(addr, bit) \
	MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)

#define BBIO_PERIPH(addr, bit) \
	MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)
#endif

/* Generic bit definition */
#define BIT0  (1<<0)
#define BIT1  (1<<1)
#define BIT2  (1<<2)
#define BIT3  (1<<3)
#define BIT4  (1<<4)
#define BIT5  (1<<5)
#define BIT6  (1<<6)
#define BIT7  (1<<7)
#define BIT8  (1<<8)
#define BIT9  (1<<9)
#define BIT10 (1<<10)
#define BIT11 (1<<11)
#define BIT12 (1<<12)
#define BIT13 (1<<13)
#define BIT14 (1<<14)
#define BIT15 (1<<15)
#define BIT16 (1<<16)
#define BIT17 (1<<17)
#define BIT18 (1<<18)
#define BIT19 (1<<19)
#define BIT20 (1<<20)
#define BIT21 (1<<21)
#define BIT22 (1<<22)
#define BIT23 (1<<23)
#define BIT24 (1<<24)
#define BIT25 (1<<25)
#define BIT26 (1<<26)
#define BIT27 (1<<27)
#define BIT28 (1<<28)
#define BIT29 (1<<29)
#define BIT30 (1<<30)
#define BIT31 (1<<31)

#endif
