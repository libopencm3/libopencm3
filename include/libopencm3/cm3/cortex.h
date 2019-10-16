/** @defgroup CM3_cortex_defines Cortex Core Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the Cortex Core </b>
 *
 * @ingroup CM3_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Ben Gamari <bgamari@gmail.com>
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

/**@{*/

#include <stdbool.h>
#include <stdint.h>

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Enable interrupts
 *
 * Disable the interrupt mask and enable interrupts globally
 */
static inline void cm_enable_interrupts(void)
{
	__asm__ volatile ("CPSIE I\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Disable interrupts
 *
 * Mask all interrupts globally
 */
static inline void cm_disable_interrupts(void)
{
	__asm__ volatile ("CPSID I\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Enable faults
 *
 * Disable the HardFault mask and enable fault interrupt globally
 */
static inline void cm_enable_faults(void)
{
	__asm__ volatile ("CPSIE F\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Disable faults
 *
 * Mask the HardFault interrupt globally
 */
static inline void cm_disable_faults(void)
{
	__asm__ volatile ("CPSID F\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Check if interrupts are masked
 *
 * Checks, if interrupts are masked (disabled).
 *
 * @returns true, if interrupts are disabled.
 */
__attribute__((always_inline))
static inline bool cm_is_masked_interrupts(void)
{
	register uint32_t result;
	__asm__ volatile ("MRS %0, PRIMASK"  : "=r" (result));
	return result;
}

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/*---------------------------------------------------------------------------*/
/** @brief Cortex M Check if Fault interrupt is masked
 *
 * Checks, if HardFault interrupt is masked (disabled).
 *
 * @returns bool true, if HardFault interrupt is disabled.
 */
__attribute__((always_inline))
static inline bool cm_is_masked_faults(void)
{
	register uint32_t result;
	__asm__ volatile ("MRS %0, FAULTMASK"  : "=r" (result));
	return result;
}
#endif

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Mask interrupts
 *
 * This function switches the mask of the interrupts. If mask is true, the
 * interrupts will be disabled. The result of this function can be used for
 * restoring previous state of the mask.
 *
 * @param[in] mask uint32_t New state of the interrupt mask
 * @returns uint32_t old state of the interrupt mask
 */
__attribute__((always_inline))
static inline uint32_t cm_mask_interrupts(uint32_t mask)
{
	register uint32_t old;
	__asm__ __volatile__("MRS %0, PRIMASK"  : "=r" (old));
	__asm__ __volatile__(""  : : : "memory");
	__asm__ __volatile__("MSR PRIMASK, %0" : : "r" (mask));
	return old;
}

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/*---------------------------------------------------------------------------*/
/** @brief Cortex M Mask HardFault interrupt
 *
 * This function switches the mask of the HardFault interrupt. If mask is true,
 * the HardFault interrupt will be disabled. The result of this function can be
 * used for restoring previous state of the mask.
 *
 * @param[in] mask uint32_t New state of the HardFault interrupt mask
 * @returns uint32_t old state of the HardFault interrupt mask
 */
__attribute__((always_inline))
static inline uint32_t cm_mask_faults(uint32_t mask)
{
	register uint32_t old;
	__asm__ __volatile__ ("MRS %0, FAULTMASK"  : "=r" (old));
	__asm__ __volatile__ (""  : : : "memory");
	__asm__ __volatile__ ("MSR FAULTMASK, %0" : : "r" (mask));
	return old;
}
#endif

/**@}*/

/*===========================================================================*/
/** @defgroup CM3_cortex_atomic_defines Cortex Core Atomic support Defines
 *
 * @brief Atomic operation support
 *
 * @ingroup CM3_cortex_defines
 */
/**@{*/

#if !defined(__DOXYGEN__)
/* Do not populate this definition outside */
static inline uint32_t __cm_atomic_set(uint32_t *val)
{
	return cm_mask_interrupts(*val);
}

#define __CM_SAVER(state)					\
	__val = (state),					\
	__save __attribute__((__cleanup__(__cm_atomic_set))) =	\
	__cm_atomic_set(&__val)

#endif /* !defined(__DOXYGEN) */


/*---------------------------------------------------------------------------*/
/** @brief Cortex M Atomic Declare block
 *
 * This macro disables interrupts for the next command or block of code. The
 * interrupt mask is automatically restored after exit of the boundary of the
 * code block. Therefore restore of interrupt is done automatically after call
 * of return or goto control sentence jumping outside of the block.
 *
 * @warning The usage of sentences break or continue is prohibited in the block
 * due to implementation of this macro!
 *
 * @note It is safe to use this block inside normal code and in interrupt
 * routine.
 *
 * Basic usage of atomic block
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * CM_ATOMIC_BLOCK() {			// interrupts are masked in this block
 *     value = value * 1024 + 651;	// access value as atomic
 * }					// interrupts is restored automatically
 * @endcode
 *
 * Use of return inside block
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * uint64_t allocval(void)
 * {
 *     CM_ATOMIC_BLOCK() {		// interrupts are masked in this block
 *         value = value * 1024 + 651;	// do long atomic operation
 *         return value;		// interrupts is restored automatically
 *     }
 * }
 * @endcode
 */
#if defined(__DOXYGEN__)
#define CM_ATOMIC_BLOCK()
#else /* defined(__DOXYGEN__) */
#define CM_ATOMIC_BLOCK()						\
	for (uint32_t __CM_SAVER(true), __my = true; __my; __my = false)
#endif /* defined(__DOXYGEN__) */

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Atomic Declare context
 *
 * This macro disables interrupts in the current block of code from the place
 * where it is defined to the end of the block. The interrupt mask is
 * automatically restored after exit of the boundary of the code block.
 * Therefore restore of interrupt is done automatically after call of return,
 * continue, break, or goto control sentence jumping outside of the block.
 *
 * @note This function is intended for use in for- cycles to enable the use of
 * break and contine sentences inside the block, and for securing the atomic
 * reader-like functions.
 *
 * @note It is safe to use this block inside normal code and in interrupt
 * routine.
 *
 * Basic usage of atomic context
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * for (int i=0;i < 100; i++) {
 *     CM_ATOMIC_CONTEXT();		// interrupts are masked in this block
 *     value += 100;			// access value as atomic
 *     if ((value % 16) == 0) {
 *         break;			// restore interrupts and break cycle
 *     }
 * }					// interrupts is restored automatically
 * @endcode
 *
 * Usage of atomic context inside atomic reader fcn.
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * uint64_t getnextval(void)
 * {
 *     CM_ATOMIC_CONTEXT();	// interrupts are masked in this block
 *     value = value + 3;	// do long atomic operation
 *     return value;		// interrupts is restored automatically
 * }
 * @endcode
 */
#if defined(__DOXYGEN__)
#define CM_ATOMIC_CONTEXT()
#else /* defined(__DOXYGEN__) */
#define CM_ATOMIC_CONTEXT()	uint32_t __CM_SAVER(true)
#endif /* defined(__DOXYGEN__) */

/**@}*/



#endif
