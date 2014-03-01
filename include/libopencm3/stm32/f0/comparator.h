/** @defgroup comp_defines COMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32F0xx
 * Comparator module</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 29 Jun 2013
 *
 *LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_COMP_H
#define LIBOPENCM3_COMP_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define COMP1	0
#define COMP2	1

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define COMP_CSR(i)			MMIO16(SYSCFG_COMP_BASE + 0x1c + (i)*2)
#define COMP_CSR1			COMP_CSR(COMP1)
#define COMP_CSR2			COMP_CSR(COMP2)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* COMP_CSR Values ----------------------------------------------------------*/

#define COMP_CSR_LOCK			(1 << 15)
#define COMP_CSR_OUT			(1 << 14)

#define COMP_CSR_HYST_SHIFT		12
#define COMP_CSR_HYST			(3 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_NO		(0 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_LOW		(1 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_MED		(2 << COMP_CSR_HYST_SHIFT)
#define COMP_CSR_HYST_HIGH		(3 << COMP_CSR_HYST_SHIFT)

#define COMP_CSR_POL			(1 << 11)

#define COMP_CSR_OUTSEL_SHIFT		8
#define COMP_CSR_OUTSEL			(7 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_NONE		(0 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM1_BRK	(1 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM1_IC1	(2 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM1_OCRCLR	(3 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM2_IC4	(4 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM2_OCRCLR	(5 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM3_IC1	(6 << COMP_CSR_OUTSEL_SHIFT)
#define COMP_CSR_OUTSEL_TIM3_OCRCLR	(7 << COMP_CSR_OUTSEL_SHIFT)

#define COMP_CSR_WINDWEN		(1 << 23)

#define COMP_CSR_INSEL_SHIFT		4
#define COMP_CSR_INSEL			(7 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_1_4_VREFINT	(0 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_2_4_VREFINT	(1 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_3_4_VREFINT	(2 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_4_4_VREFINT	(3 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_VREFINT		(3 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_INM4		(4 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_INM5		(5 << COMP_CSR_INSEL_SHIFT)
#define COMP_CSR_INSEL_INM6		(6 << COMP_CSR_INSEL_SHIFT)

#define COMP_CSR_SPEED_SHIFT		2
#define COMP_CSR_SPEED			(3 << COMP_CSR_SPEED_SHIFT)
#define COMP_CSR_SPEED_HIGH		(0 << COMP_CSR_SPEED_SHIFT)
#define COMP_CSR_SPEED_MED		(1 << COMP_CSR_SPEED_SHIFT)
#define COMP_CSR_SPEED_LOW		(2 << COMP_CSR_SPEED_SHIFT)
#define COMP_CSR_SPEED_VERYLOW		(3 << COMP_CSR_SPEED_SHIFT)

#define COMP_CSR_SW1			(1 << 1)
#define COMP_CSR_EN			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void comp_enable(uint8_t id);
void comp_disable(uint8_t id);
void comp_select_input(uint8_t id, uint32_t input);
void comp_select_output(uint8_t id, uint32_t output);
void comp_select_hyst(uint8_t id, uint32_t hyst);
void comp_select_speed(uint8_t id, uint32_t speed);

END_DECLS
/**@}*/

#endif
