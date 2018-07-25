/** @defgroup comp_defines COMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32F3xx
 * Comparator module</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 20 Jul 2018
 *
 *LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_COMP_H
#define LIBOPENCM3_COMP_H
/**@{*/

#define COMP1				(COMP_BASE + 0x1C)
#define COMP2				(COMP_BASE + 0x20)
#define COMP3				(COMP_BASE + 0x24)
#define COMP4				(COMP_BASE + 0x28)
#define COMP5				(COMP_BASE + 0x2C)
#define COMP6				(COMP_BASE + 0x30)
#define COMP7				(COMP_BASE + 0x34)

/* Comparator registers */

/* Control and status register (COMPx_CSR) */
#define COMP_CSR(comp_base)		MMIO32((comp_base) + 0x00)
#define COMP1_CSR			COMP_CSR(COMP1)
#define COMP2_CSR			COMP_CSR(COMP2)
#define COMP3_CSR			COMP_CSR(COMP3)
#define COMP4_CSR			COMP_CSR(COMP4)
#define COMP5_CSR			COMP_CSR(COMP5)
#define COMP6_CSR			COMP_CSR(COMP6)
#define COMP7_CSR			COMP_CSR(COMP7)

/* COMPx_CSR values */

#define COMP_CSR_LOCK			(0x1 << 31)
#define COMP_CSR_OUT			(0x1 << 30)

/* individual blanking sources depends on COMP used */
#define COMP_CSR_BLANKING_MASK		(0x7)
#define COMP_CSR_BLANKING_SHIFT		(18)
#define COMP_CSR_BLANKING_NONE		(0x0)
#define COMP_CSR_BLANKING(blanking)	(((blanking) & COMP_CSR_BLANKING_MASK) << COMP_CSR_BLANKING_SHIFT)

/* only on COMP1/3/5/7 */
#define COMP_CSR_HYST_NONE		(0x0)
#define COMP_CSR_HYST_LOW		(0x1)
#define COMP_CSR_HYST_MEDIUM		(0x2)
#define COMP_CSR_HYST_HIGH		(0x3)
#define COMP_CSR_HYST_MASK		(0x3)
#define COMP_CSR_HYST_SHIFT		(16)

#define COMP_CSR_POL			(0x1 << 15)

/* individual value depends on COMP used */
#define COMP_CSR_OUTSEL(outsel)		(((outsel) & COMP_CSR_OUTSEL_MASK) << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_MASK		(0xf)
#define COMP_CSR_OUTSEL_SHIFT		(10)

/* only on COMP2/4/6 */
#define COMP_CSR_WINMODE		(0x1 << 9)

/* not available on COMP1 */
#define COMP_CSR_INPSEL			(0x1 << 7)

/* individual value depends on COMP used,
   also respects bit 3 (INMSEL[3]) where available */
#define COMP_CSR_INMSEL(inmsel)		((((inmsel) & 0x7) << 4) | \
					 ((((inmsel) & 0x8) >> 3) << 22))
#define COMP_CSR_INMSEL_MASK		(0x7 << 4)

#define COMP_CSR_MODE_HIGHSPEED		(0x0)
#define COMP_CSR_MODE_MEDIUMSPEED	(0x1)
#define COMP_CSR_MODE_LOWSPEED		(0x2)
#define COMP_CSR_MODE_ULTRALOWPOWER	(0x3)
#define COMP_CSR_MODE_MASK		(0x3)
#define COMP_CSR_MODE_SHIFT		(2)

/* only on COMP1 and COMP2 */
#define COMP_CSR_INPDAC			(0x1 << 1)

#define COMP_CSR_EN			(0x1 << 0)

/**@}*/
#endif
