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
#define BIT0  (1U << 0U)
#define BIT1  (1U << 1U)
#define BIT2  (1U << 2U)
#define BIT3  (1U << 3U)
#define BIT4  (1U << 4U)
#define BIT5  (1U << 5U)
#define BIT6  (1U << 6U)
#define BIT7  (1U << 7U)
#define BIT8  (1U << 8U)
#define BIT9  (1U << 9U)
#define BIT10 (1U << 10U)
#define BIT11 (1U << 11U)
#define BIT12 (1U << 12U)
#define BIT13 (1U << 13U)
#define BIT14 (1U << 14U)
#define BIT15 (1U << 15U)
#define BIT16 (1U << 16U)
#define BIT17 (1U << 17U)
#define BIT18 (1U << 18U)
#define BIT19 (1U << 19U)
#define BIT20 (1U << 20U)
#define BIT21 (1U << 21U)
#define BIT22 (1U << 22U)
#define BIT23 (1U << 23U)
#define BIT24 (1U << 24U)
#define BIT25 (1U << 25U)
#define BIT26 (1U << 26U)
#define BIT27 (1U << 27U)
#define BIT28 (1U << 28U)
#define BIT29 (1U << 29U)
#define BIT30 (1U << 30U)
#define BIT31 (1U << 31U)

#endif
