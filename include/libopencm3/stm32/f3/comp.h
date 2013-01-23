/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 ARCOS-Lab UCR <arcoslab.org> 
 * Copyright (C) 2012 Fernando Cortes <fernando.corcam@gmail.com>
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

#include <libopencm3/stm32/memorymap.h>

/* --- COMP registers ------------------------------------------------------ */

#define COMP_COMP1_CSR			MMIO32(COMP_BASE + 0x1C)

#define COMP_COMP2_CSR			MMIO32(COMP_BASE + 0x20)

#define COMP_COMP3_CSR			MMIO32(COMP_BASE + 0x24)

#define COMP_COMP4_CSR			MMIO32(COMP_BASE + 0x28)

#define COMP_COMP5_CSR			MMIO32(COMP_BASE + 0x2C)

#define COMP_COMP6_CSR			MMIO32(COMP_BASE + 0x30)

#define COMP_COMP7_CSR			MMIO32(COMP_BASE + 0x34)


/*------ COMP1_CSR values  ------*/

/* COMP1LOCK: Comparator 1 lock */
#define COMP_COMP1_CSR_LOCK		(1 << 31)

/* COMP1OUT: Comparator 1 output */
#define COMP_COMP1_CSR_OUT		(1 << 30)

/* COMP1_BLANKING: Comparator 1 blanking source */
#define COMP_COMP1_CSR_BLANKING_NO		(0x0 << 18)
#define COMP_COMP1_CSR_BLANKING_TIM1_OC5	(0x1 << 18)
#define COMP_COMP1_CSR_BLANKING_TIM2_OC3	(0x2 << 18)
#define COMP_COMP1_CSR_BLANKING_TIM3_OC3	(0x3 << 18)
/* bits 4,5,6 and 7 : Other configurations: reserved */

/* COMP1HYST[1:0] Comparator 1 hysteresis */
#define COMP_COMP1_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP1_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP1_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP1_CSR_HYST_HIGH	(0x3 << 16)

/* COMP1POL: Comparator 1 output polarity */
#define COMP_COMP1_CSR_POL		(1 << 15)

/* COMP1OUTSEL[3:0]: Comparator 1 output selection */
#define COMP_COMP1_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM1_OC_IN	(0x6 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM1_IN_CAP1	(0x7 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM2_IN_CAP4	(0x8 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM2_OC_IN	(0x9 << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM3_IN_CAP1	(0xA << 10)
#define COMP_COMP1_CSR_OUTSEL_TIM3_OC_IN	(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP1INMSEL[2:0]: Comparator 1 inverting input selection */
#define COMP_COMP1_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP1_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP1_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP1_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP1_CSR_INMSEL_COMP1_INM4	(0x4 << 4)
#define COMP_COMP1_CSR_INMSEL_COMP1_INM5	(0x5 << 4)
#define COMP_COMP1_CSR_INMSEL_COMP1_INM6	(0x6 << 4)
/* Bit 7 reserved */

/* COMP1MODE[1:0]: Comparator 1 mode */
#define COMP_COMP1_CSR_MODE_HIGH_SPEED		(0x0 << 2)
#define COMP_COMP1_CSR_MODE_MEDIUM_SPEED	(0x1 << 2)
#define COMP_COMP1_CSR_MODE_LOW_PWR		(0x2 << 2)
#define COMP_COMP1_CSR_MODE_ULTRA_LOW_PWR	(0x3 << 2)

/* COMP1SW1: Comparator 1 non inverting input connection to DAC output. */
#define COMP_COMP1_CSR_SW1		(1 << 1)

/* COMP1EN: Comparator 1 enable */
#define COMP_COMP1_CSR_EN		(1 << 0)


/*------ COMP2_CSR values  ------*/

/* COMP2LOCK: Comparator 2 lock */
#define COMP_COMP2_CSR_LOCK		(1 << 31)

/* COMP2OUT: Comparator 2 output */
#define COMP_COMP2_CSR_OUT		(1 << 30)

/* COMP2_BLANKING: Comparator 2 blanking source */
#define COMP_COMP2_CSR_BLANKING_NO		(0x0 << 18)
#define COMP_COMP2_CSR_BLANKING_TIM1_OC5	(0x1 << 18)
#define COMP_COMP2_CSR_BLANKING_TIM2_OC3	(0x2 << 18)
#define COMP_COMP2_CSR_BLANKING_TIM3_OC3	(0x3 << 18)
/* bits 4,5,6 and 7 : Other configurations: reserved */

/* COMP2HYST[1:0] Comparator 2 hysteresis */
#define COMP_COMP2_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP2_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP2_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP2_CSR_HYST_HIGH	(0x3 << 16)

/* COMP2POL: Comparator 2 output polarity */
#define COMP_COMP2_CSR_POL		(1 << 15)

/* COMP2OUTSEL[3:0]: Comparator 2 output selection */
#define COMP_COMP2_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM1_OC_IN	(0x6 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM1_IN_CAP1	(0x7 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM2_IN_CAP4	(0x8 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM2_OC_IN	(0x9 << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM3_IN_CAP1	(0xA << 10)
#define COMP_COMP2_CSR_OUTSEL_TIM3_OC_IN	(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP2WINMODE: Comparator 2 window mode */
#define COMP_COMP2_CSR_WINMODE		(1 << 9)

/* COMP2INPSEL: Comparator 2 non inverting input selection */
#define COMP_COMP2_CSR_INPSEL		(1 << 7)

/* COMP2INMSEL[2:0]: Comparator 2 inverting input selection */
#define COMP_COMP2_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP2_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP2_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP2_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP2_CSR_INMSEL_COMP2_INM4	(0x4 << 4)
#define COMP_COMP2_CSR_INMSEL_COMP2_INM5	(0x5 << 4)
#define COMP_COMP2_CSR_INMSEL_COMP2_INM6	(0x6 << 4)
/* Bit 7 reserved */

/* COMP2MODE[1:0]: Comparator 2 mode */
#define COMP_COMP2_CSR_MODE_HIGH_SPEED		(0x0 << 2)
#define COMP_COMP2_CSR_MODE_MEDIUM_SPEED	(0x1 << 2)
#define COMP_COMP2_CSR_MODE_LOW_PWR		(0x2 << 2)
#define COMP_COMP2_CSR_MODE_ULTRA_LOW_PWR	(0x3 << 2)

/* COMP2EN: Comparator 2 enable */
#define COMP_COMP2_CSR_EN		(1 << 0)


/*------ COMP3_CSR values  ------*/

/* COMP3LOCK: Comparator 3 lock */
#define COMP_COMP3_CSR_LOCK		(1 << 31)

/* COMP3OUT: Comparator 3 output */
#define COMP_COMP3_CSR_OUT		(1 << 30)

/* COMP3_BLANKING: Comparator 3 blanking source */
#define COMP_COMP3_CSR_BLANKING_NO		(0x0 << 18)
#define COMP_COMP3_CSR_BLANKING_TIM1_OC5	(0x1 << 18)
/* Blanking 010 reserved */
#define COMP_COMP3_CSR_BLANKING_TIM2_OC4	(0x3 << 18)
/* bits 4,5,6 and 7 : Other configurations: reserved */

/* COMP3HYST[1:0] Comparator 3 hysteresis */
#define COMP_COMP3_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP3_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP3_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP3_CSR_HYST_HIGH	(0x3 << 16)

/* COMP3POL: Comparator 3 output polarity */
#define COMP_COMP3_CSR_POL		(1 << 15)

/* COMP3OUTSEL[3:0]: Comparator 3 output selection */
#define COMP_COMP3_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM1_OC_IN	(0x6 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM4_IN_CAP1	(0x7 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM3_IN_CAP2	(0x8 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM2_OC_IN	(0x9 << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM15_IN_CAP1	(0xA << 10)
#define COMP_COMP3_CSR_OUTSEL_TIM15_IN		(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP3INPSEL: Comparator 3 non inverting input selection */
#define COMP_COMP3_CSR_INPSEL		(1 << 7)

/* COMP3INMSEL[2:0]: Comparator 3 inverting input selection */
#define COMP_COMP3_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP3_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP3_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP3_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP3_CSR_INMSEL_COMP3_INM4	(0x4 << 4)
#define COMP_COMP3_CSR_INMSEL_COMP3_INM5	(0x5 << 4)
#define COMP_COMP3_CSR_INMSEL_COMP3_INM6	(0x6 << 4)
#define COMP_COMP3_CSR_INMSEL_COMP3_INM7	(0x7 << 4)

/* COMP3MODE[1:0]: Comparator 3 mode */
#define COMP_COMP3_CSR_MODE_HIGH_SPEED		(0x3 << 2)
#define COMP_COMP3_CSR_MODE_MEDIUM_SPEED	(0x2 << 2)
#define COMP_COMP3_CSR_MODE_LOW_PWR		(0x1 << 2)
#define COMP_COMP3_CSR_MODE_ULTRA_LOW_PWR	(0x0 << 2)

/* COMP3EN: Comparator 3 enable */
#define COMP_COMP3_CSR_EN		(1 << 0)


/*------ COMP4_CSR values  ------*/

/* COMP4LOCK: Comparator 4 lock */
#define COMP_COMP4_CSR_LOCK		(1 << 31)

/* COMP4OUT: Comparator 4 output */
#define COMP_COMP4_CSR_OUT		(1 << 30)

/* COMP4_BLANKING: Comparator 4 blanking source */
#define COMP_COMP4_CSR_BLANKING_NO		(0x0 << 18)
#define COMP_COMP4_CSR_BLANKING_TIM3_OC4	(0x1 << 18)
#define COMP_COMP4_CSR_BLANKING_TIM8_OC5	(0x2 << 18)
#define COMP_COMP4_CSR_BLANKING_TIM15_OC1	(0x3 << 18)
/* bits 4,5,6 and 7 : Other configurations: reserved */

/* COMP4HYST[1:0] Comparator 4 hysteresis */
#define COMP_COMP4_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP4_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP4_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP4_CSR_HYST_HIGH	(0x3 << 16)

/* COMP4POL: Comparator 4 output polarity */
#define COMP_COMP4_CSR_POL		(1 << 15)

/* COMP4OUTSEL[3:0]: Comparator 4 output selection */
#define COMP_COMP4_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM3_IN_CAP3	(0x6 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM8_OC_IN	(0x7 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM15_IN_CAP2	(0x8 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM4_IN_CAP2	(0x9 << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM15_OC_IN	(0xA << 10)
#define COMP_COMP4_CSR_OUTSEL_TIM3_OC_IN	(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP4WINMODE: Comparator 4 window mode */
#define COMP_COMP4_CSR_WINMODE		(1 << 9)

/* COMP4INPSEL: Comparator 4 non inverting input selection */
#define COMP_COMP4_CSR_INPSEL		(1 << 7)

/* COMP4INMSEL[2:0]: Comparator 4 inverting input selection */
#define COMP_COMP4_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP4_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP4_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP4_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP4_CSR_INMSEL_COMP4_INM4	(0x4 << 4)
#define COMP_COMP4_CSR_INMSEL_COMP4_INM5	(0x5 << 4)
#define COMP_COMP4_CSR_INMSEL_COMP4_INM6	(0x6 << 4)
#define COMP_COMP4_CSR_INMSEL_COMP4_INM7	(0x7 << 4)

/* COMP4MODE[1:0]: Comparator 4 mode */
#define COMP_COMP4_CSR_MODE_HIGH_SPEED		(0x3 << 2)
#define COMP_COMP4_CSR_MODE_MEDIUM_SPEED	(0x2 << 2)
#define COMP_COMP4_CSR_MODE_LOW_PWR		(0x1 << 2)
#define COMP_COMP4_CSR_MODE_ULTRA_LOW_PWR	(0x0 << 2)

/* COMP4EN: Comparator 4 enable */
#define COMP_COMP4_CSR_EN		(1 << 0)


/*------ COMP5_CSR values  ------*/

/* COMP5LOCK: Comparator 5 lock */
#define COMP_COMP5_CSR_LOCK		(1 << 31)

/* COMP5OUT: Comparator 5 output */
#define COMP_COMP5_CSR_OUT		(1 << 30)

/* COMP5_BLANKING: Comparator 5 blanking source */
#define COMP_COMP5_CSR_BLANKING_NO		(0x0 << 18)
/* Blanking 001 reserved */
#define COMP_COMP5_CSR_BLANKING_TIM8_OC5	(0x2 << 18)
#define COMP_COMP5_CSR_BLANKING_TIM3_OC3	(0x3 << 18)
/* bits 4,5,6 and 7 : Other configurations: reserved */

/* COMP5HYST[1:0] Comparator 5 hysteresis */
#define COMP_COMP5_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP5_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP5_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP5_CSR_HYST_HIGH	(0x3 << 16)

/* COMP5POL: Comparator 5 output polarity */
#define COMP_COMP5_CSR_POL		(1 << 15)

/* COMP5OUTSEL[3:0]: Comparator 5 output selection */
#define COMP_COMP5_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM2_IN_CAP1	(0x6 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM8_OC_IN	(0x7 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM17_IN_CAP1	(0x8 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM4_IN_CAP3	(0x9 << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM16_IN		(0xA << 10)
#define COMP_COMP5_CSR_OUTSEL_TIM3_OC_IN	(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP5INPSEL: Comparator 5 non inverting input selection */
#define COMP_COMP5_CSR_INPSEL		(1 << 7)

/* COMP5INMSEL[2:0]: Comparator 5 inverting input selection */
#define COMP_COMP5_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP5_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP5_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP5_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP5_CSR_INMSEL_COMP4_INM4	(0x4 << 4)
#define COMP_COMP5_CSR_INMSEL_COMP4_INM5	(0x5 << 4)
#define COMP_COMP5_CSR_INMSEL_COMP4_INM6	(0x6 << 4)
#define COMP_COMP5_CSR_INMSEL_COMP4_INM7	(0x7 << 4)

/* COMP5MODE[1:0]: Comparator 5 mode */
#define COMP_COMP5_CSR_MODE_HIGH_SPEED		(0x3 << 2)
#define COMP_COMP5_CSR_MODE_MEDIUM_SPEED	(0x2 << 2)
#define COMP_COMP5_CSR_MODE_LOW_PWR		(0x1 << 2)
#define COMP_COMP5_CSR_MODE_ULTRA_LOW_PWR	(0x0 << 2)

/* COMP5EN: Comparator 5 enable */
#define COMP_COMP5_CSR_EN		(1 << 0)


/*------ COMP6_CSR values  ------*/

/* COMP6LOCK: Comparator 6 lock */
#define COMP_COMP6_CSR_LOCK		(1 << 31)

/* COMP6OUT: Comparator 6 output */
#define COMP_COMP6_CSR_OUT		(1 << 30)

/* COMP6_BLANKING: Comparator 6 blanking source */
#define COMP_COMP6_CSR_BLANKING_NO		(0x0 << 18)
/* Blanking 001 reserved */
#define COMP_COMP6_CSR_BLANKING_TIM8_OC5	(0x2 << 18)
#define COMP_COMP6_CSR_BLANKING_TIM2_OC4	(0x3 << 18)
#define COMP_COMP6_CSR_BLANKING_TIM15_OC2	(0x4 << 18)
/* Blanking bits 5,6 and 7 : Other configurations: reserved */

/* COMP6HYST[1:0] Comparator 6 hysteresis */
#define COMP_COMP6_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP6_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP6_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP6_CSR_HYST_HIGH	(0x3 << 16)

/* COMP6POL: Comparator 6 output polarity */
#define COMP_COMP6_CSR_POL		(1 << 15)

/* COMP6OUTSEL[3:0]: Comparator 6 output selection */
#define COMP_COMP6_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM2_IN_CAP2	(0x6 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM8_OC_IN	(0x7 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM2_OC_IN	(0x8 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM16_OC_IN	(0x9 << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM16_IN_CAP1	(0xA << 10)
#define COMP_COMP6_CSR_OUTSEL_TIM4_IN_CAP4	(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP6WINMODE: Comparator 6 window mode */
#define COMP_COMP6_CSR_WINMODE		(1 << 9)

/* COMP6INPSEL: Comparator 6 non inverting input selection */
#define COMP_COMP6_CSR_INPSEL		(1 << 7)

/* COMP6INMSEL[2:0]: Comparator 6 inverting input selection */
#define COMP_COMP6_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP6_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP6_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP6_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP6_CSR_INMSEL_COMP4_INM4	(0x4 << 4)
#define COMP_COMP6_CSR_INMSEL_COMP4_INM5	(0x5 << 4)
#define COMP_COMP6_CSR_INMSEL_COMP4_INM6	(0x6 << 4)
#define COMP_COMP6_CSR_INMSEL_COMP4_INM7	(0x7 << 4)

/* COMP6MODE[1:0]: Comparator 6 mode */
#define COMP_COMP6_CSR_MODE_HIGH_SPEED		(0x3 << 2)
#define COMP_COMP6_CSR_MODE_MEDIUM_SPEED	(0x2 << 2)
#define COMP_COMP6_CSR_MODE_LOW_PWR		(0x1 << 2)
#define COMP_COMP6_CSR_MODE_ULTRA_LOW_PWR	(0x0 << 2)

/* COMP6EN: Comparator 6 enable */
#define COMP_COMP6_CSR_EN		(1 << 0)


/*------ COMP7_CSR values  ------*/

/* COMP7LOCK: Comparator 7 lock */
#define COMP_COMP7_CSR_LOCK		(1 << 31)

/* COMP7OUT: Comparator 7 output */
#define COMP_COMP7_CSR_OUT		(1 << 30)

/* COMP7_BLANKING: Comparator 7 blanking source */
#define COMP_COMP7_CSR_BLANKING_NO		(0x0 << 18)
#define COMP_COMP7_CSR_BLANKING_TIM1_OC5	(0x1 << 18)
#define COMP_COMP7_CSR_BLANKING_TIM8_OC5	(0x2 << 18)
/* Blanking 011 reserved  */
#define COMP_COMP7_CSR_BLANKING_TIM15_OC2	(0x4 << 18)
/* Blanking bits 5,6 and 7 : Other configurations: reserved */

/* COMP7HYST[1:0] Comparator 7 hysteresis */
#define COMP_COMP7_CSR_HYST_NO		(0x0 << 16)
#define COMP_COMP7_CSR_HYST_LOW		(0x1 << 16)
#define COMP_COMP7_CSR_HYST_MEDIUM	(0x2 << 16)
#define COMP_COMP7_CSR_HYST_HIGH	(0x3 << 16)

/* COMP7POL: Comparator 7 output polarity */
#define COMP_COMP7_CSR_POL		(1 << 15)

/* COMP7OUTSEL[3:0]: Comparator 7 output selection */
#define COMP_COMP7_CSR_OUTSEL_NO		(0x0 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM1_IN		(0x1 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM1_IN2		(0x2 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM8_IN		(0x3 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM8_IN2		(0x4 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM1_IN2_TIM8_IN2	(0x5 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM1_OC_IN	(0x6 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM8_OC_IN	(0x7 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM2_IN_CAP3	(0x8 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM1_IN_CAP2	(0x9 << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM17_OC_IN	(0xA << 10)
#define COMP_COMP7_CSR_OUTSEL_TIM17_IN		(0xB << 10)
/* Others bits : Remaining combinations: reserved. */

/* COMP7INPSEL: Comparator 7 non inverting input selection */
#define COMP_COMP7_CSR_INPSEL		(1 << 7)

/* COMP7INMSEL[2:0]: Comparator 7 inverting input selection */
#define COMP_COMP7_CSR_INMSEL_QUARTER_VREFINT	(0x0 << 4)
#define COMP_COMP7_CSR_INMSEL_HALF_VREFINT	(0x1 << 4)
#define COMP_COMP7_CSR_INMSEL_THREE_QUARTERS_VREFINT	(0x2 << 4)
#define COMP_COMP7_CSR_INMSEL_VREFINT		(0x3 << 4)
#define COMP_COMP7_CSR_INMSEL_COMP4_INM4	(0x4 << 4)
#define COMP_COMP7_CSR_INMSEL_COMP4_INM5	(0x5 << 4)
#define COMP_COMP7_CSR_INMSEL_COMP4_INM6	(0x6 << 4)
/* INMSEL 111 reserved */

/* COMP7MODE[1:0]: Comparator 7 mode */
#define COMP_COMP7_CSR_MODE_HIGH_SPEED		(0x3 << 2)
#define COMP_COMP7_CSR_MODE_MEDIUM_SPEED	(0x2 << 2)
#define COMP_COMP7_CSR_MODE_LOW_PWR		(0x1 << 2)
#define COMP_COMP7_CSR_MODE_ULTRA_LOW_PWR	(0x0 << 2)

/* COMP7EN: Comparator 7 enable */
#define COMP_COMP7_CSR_EN		(1 << 0)




#endif

