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

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Enable interrupts
 *
 * Disable the interrupt mask and enable interrupts globally
 */
static inline void cm_enable_interrupts(void)
{
	__asm__("CPSIE I\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Disable interrupts
 *
 * Mask all interrupts globally
 */
static inline void cm_disable_interrupts(void)
{
	__asm__("CPSID I\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Enable faults
 *
 * Disable the HardFault mask and enable fault interrupt globally
 */
static inline void cm_enable_faults(void)
{
	__asm__("CPSIE F\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Disable faults
 *
 * Mask the HardFault interrupt globally
 */
static inline void cm_disable_faults(void)
{
	__asm__("CPSID F\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Check if interrupts are masked
 *
 * Checks, if interrupts are masked (disabled).
 *
 * @returns true, if interrupts are disabled.
 */
__attribute__(( always_inline ))
static inline bool cm_is_masked_interrupts(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, PRIMASK"  : "=r" (result) );
	return (result);
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Check if Fault interrupt is masked
 *
 * Checks, if HardFault interrupt is masked (disabled).
 *
 * @returns bool true, if HardFault interrupt is disabled.
 */
__attribute__(( always_inline ))
static inline bool cm_is_masked_faults(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, FAULTMASK"  : "=r" (result) );
	return (result);
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Mask interrupts
 *
 * This function switches the mask of the interrupts. If mask is true, the
 * interrupts will be disabled. The result of this function can be used for
 * restoring previous state of the mask.
 *
 * @param[in] mask bool New state of the interrupt mask
 * @returns bool old state of the interrupt mask
 */
__attribute__(( always_inline ))
static inline bool cm_mask_interrupts(bool mask)
{
	register bool old;
	__asm__ __volatile__("MRS %0, PRIMASK"  : "=r" (old));
	__asm__ __volatile__(""  ::: "memory");
	__asm__ __volatile__("MSR PRIMASK, %0" : : "r" (mask));
	return old;
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Mask HardFault interrupt
 *
 * This function switches the mask of the HardFault interrupt. If mask is true,
 * the HardFault interrupt will be disabled. The result of this function can be
 * used for restoring previous state of the mask.
 *
 * @param[in] mask bool New state of the HardFault interrupt mask
 * @returns bool old state of the HardFault interrupt mask
 */
__attribute__(( always_inline ))
static inline bool cm_mask_faults(bool mask)
{
	register bool old;
	__asm__ __volatile__ ("MRS %0, FAULTMASK"  : "=r" (old));
	__asm__ __volatile__(""  ::: "memory");
	__asm__ __volatile__ ("MSR FAULTMASK, %0" : : "r" (mask));
	return old;
}

/**@}*/

#endif
