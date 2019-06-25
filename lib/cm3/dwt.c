/** @defgroup CM3_dwt_file DWT
 *
 * @ingroup CM3_files
 *
 * @brief <b>libopencm3 Cortex-M Data Watchpoint and Trace unit</b>
 *
 * The DWT provides
 * * Comparators, that support
 *   * watch points
 *   * data tracing
 *   * signalling to ETM
 *   * PC value tracing
 *   * cycle count matching
 * * extra PC sampling
 *   * Sampling as a result of a clock count
 *   * external access for sampling
 * * exception trace
 * * performance profiling counters.
 *
 * Which of these features are available is unfortunately implementation defined.
 *
 * @see ARMv7m Architecture Reference Manual (Chapter ARMv7-M Debug)
 *
 * LGPL License Terms @ref lgpl_license
 * @{
 */
/*
 * This file is part of the libopencm3 project.
 *
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

#include <libopencm3/cm3/scs.h>
#include <libopencm3/cm3/dwt.h>

/*---------------------------------------------------------------------------*/
/** @brief DebugTrace Enable the CPU cycle counter
 *
 * This function will try to enable the CPU cycle counter that is intended for
 * benchmarking performance of the code. If function fails, the cycle counter
 * isn't available on this architecture.
 *
 * @return true, if success
 */
bool dwt_enable_cycle_counter(void)
{
#if defined(__ARM_ARCH_6M__)
	return false;			/* Not supported on ARMv6M */
#endif /* defined(__ARM_ARCH_6M__) */

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
	/* Note TRCENA is for 7M and above*/
	SCS_DEMCR |= SCS_DEMCR_TRCENA;
	if (DWT_CTRL & DWT_CTRL_NOCYCCNT) {
		return false;		/* Not supported in implementation */
	}

	DWT_CYCCNT = 0;
	DWT_CTRL |= DWT_CTRL_CYCCNTENA;
	return true;
#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

	/* not supported on other architectures */
	return false;
}
/*---------------------------------------------------------------------------*/
/** @brief DebugTrace Read the CPU cycle counter
 *
 * This function reads the core cycle counter if it is enabled. It is the
 * fastest clock running on the system.
 *
 * @note The CPU cycle counter must be enabled by @ref dwt_enable_cycle_counter
 *
 * @returns 0 if cycle counter is not supported or enabled, the cycle counter
 * value otherwise.
 */
uint32_t dwt_read_cycle_counter(void)
{
#if defined(__ARM_ARCH_6M__)
	return 0;		/* Not supported on ARMv6M */
#endif /* defined(__ARM_ARCH_6M__) */

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
	if (DWT_CTRL & DWT_CTRL_CYCCNTENA) {
		return DWT_CYCCNT;
	} else {
		return 0;		/* not supported or enabled */
	}
#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */
}

/**@}*/