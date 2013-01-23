/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 ARCOS-Lab UCR <arcoslab.org> 
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


#ifndef LIBOPENCM3_OPAMP_H
#define LIBOPENCM3_OPAMP_H

#include <libopencm3/stm32/memorymap.h>

/* --- OPAMP registers ------------------------------------------------------ */

#define OPAMP_OPAMP1_CSR	MMIO32(OPAMP_BASE + 0x38)

#define OPAMP_OPAMP2_CSR	MMIO32(OPAMP_BASE + 0x3C)

#define OPAMP_OPAMP3_CSR	MMIO32(OPAMP_BASE + 0x40)

#define OPAMP_OPAMP4_CSR	MMIO32(OPAMP_BASE + 0x44)



/*------ OPAMP1_CSR values ------*/

/* LOCK: OPAMP 1 lock */
#define OPAMP_OPAMP1_CSR_LOCK		(1 << 31)

/* OUTCAL */
#define OPAMP_OPAMP1_CSR_OUTCAL		(1 << 30)

/* TSTREF */
#define OPAMP_OPAMP1_CSR_TSTREF		(1 << 29)

/* Bits 28:24 TRIMOFFSETN: Offset trimming value (NMOS) */

/* Bits 23:19 TRIMOFFSETP: Offset trimming value (PMOS) */

/* USER_TRIM: User trimming enable. */
#define OPAMP_OPAMP1_CSR_USER_TRIM	(1 << 18)


/* PGA_GAIN: Gain in PGA mode */
#define OPAMP_OPAMP1_CSR_PGA_GAIN_2		(0x0 << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_4		(0x1 << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_8		(0x2 << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_16		(0x3 << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_2_VM0		(0x8 << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_4_VM0		(0x9 << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_8_VM0		(0xA << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_16_VM0	(0xB << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_2_VM1		(0xC << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_4_VM1		(0xD << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_8_VM1		(0xE << 14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_16_VM1	(0xF << 14)

/* CALSEL: Calibration selection */
#define OPAMP_OPAMP1_CSR_CALSEL_3_3	(0x0 << 12)
#define OPAMP_OPAMP1_CSR_CALSEL_10	(0x1 << 12)
#define OPAMP_OPAMP1_CSR_CALSEL_50	(0x2 << 12)
#define OPAMP_OPAMP1_CSR_CALSEL_90	(0x3 << 12)

/* CALON: Calibration mode enable */
#define OPAMP_OPAMP1_CSR_CALON		(1 << 11)

/* VPS_SEL: OPAMP1 Non inverting input secondary selection */
#define OPAMP_OPAMP1_CSR_VPS_SEL_PA7	(0x0 << 9)
#define OPAMP_OPAMP1_CSR_VPS_SEL_PA5	(0x1 << 9)
#define OPAMP_OPAMP1_CSR_VPS_SEL_PA3	(0x2 << 9)
#define OPAMP_OPAMP1_CSR_VPS_SEL_PA1	(0x3 << 9)

/* VMS_SEL: OPAMP1 inverting input secondary selection */
#define OPAMP_OPAMP1_CSR_VMS_SEL	(1 << 8)

/* TCM_EN: Timer controlled Mux mode enable */
#define OPAMP_OPAMP1_CSR_TCM_EN		(1 << 7)

/* VM_SEL: OPAMP1 inverting input selection */
#define OPAMP_OPAMP1_CSR_VM_SEL_PC5		(0x0 << 5)
#define OPAMP_OPAMP1_CSR_VM_SEL_PA3		(0x1 << 5)
#define OPAMP_OPAMP1_CSR_VM_SEL_PGA_MODE	(0x2 << 5)
#define OPAMP_OPAMP1_CSR_VM_SEL_FOLLOWER_MODE	(0x3 << 5)

/* VP_SEL: OPAMP1 Non inverting input selection */
#define OPAMP_OPAMP1_CSR_VP_SEL_PA7		(0x0 << 2)
#define OPAMP_OPAMP1_CSR_VP_SEL_PA5		(0x1 << 2)
#define OPAMP_OPAMP1_CSR_VP_SEL_PA3		(0x2 << 2)
#define OPAMP_OPAMP1_CSR_VP_SEL_PA1		(0x3 << 2)

/* FORCE_VP */
#define OPAMP_OPAMP1_CSR_FORCE_VP	(1 << 1)

/* OPAMP1_EN: OPAMP1 enable */
#define OPAMP_OPAMP1_CSR_EN		(1 << 0)



/*------ OPAMP2_CSR values ------*/

/* LOCK: OPAMP 2 lock */
#define OPAMP_OPAMP2_CSR_LOCK		(1 << 31)

/* OUTCAL */
#define OPAMP_OPAMP2_CSR_OUTCAL		(1 << 30)

/* TSTREF */
#define OPAMP_OPAMP2_CSR_TSTREF		(1 << 29)

/* Bits 28:24 TRIMOFFSETN: Offset trimming value (NMOS) */

/* Bits 23:19 TRIMOFFSETP: Offset trimming value (PMOS) */

/* USER_TRIM: User trimming enable. */
#define OPAMP_OPAMP2_CSR_USER_TRIM	(1 << 18)

/* PGA_GAIN: Gain in PGA mode */
#define OPAMP_OPAMP2_CSR_PGA_GAIN_2		(0x0 << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_4		(0x1 << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_8		(0x2 << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_16		(0x3 << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_2_VM0		(0x8 << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_4_VM0		(0x9 << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_8_VM0		(0xA << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_16_VM0	(0xB << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_2_VM1		(0xC << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_4_VM1		(0xD << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_8_VM1		(0xE << 14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_16_VM1	(0xF << 14)

/* CALSEL: Calibration selection */
#define OPAMP_OPAMP2_CSR_CALSEL_3_3	(0x0 << 12)
#define OPAMP_OPAMP2_CSR_CALSEL_10	(0x1 << 12)
#define OPAMP_OPAMP2_CSR_CALSEL_50	(0x2 << 12)
#define OPAMP_OPAMP2_CSR_CALSEL_90	(0x3 << 12)

/* CALON: Calibration mode enable */
#define OPAMP_OPAMP2_CSR_CALON		(1 << 11)

/* VPS_SEL: OPAMP2 Non inverting input secondary selection */
#define OPAMP_OPAMP2_CSR_VPS_SEL_PD14	(0x0 << 9)
#define OPAMP_OPAMP2_CSR_VPS_SEL_PB14	(0x1 << 9)
#define OPAMP_OPAMP2_CSR_VPS_SEL_PB0	(0x2 << 9)
#define OPAMP_OPAMP2_CSR_VPS_SEL_PA7	(0x3 << 9)

/* VMS_SEL: OPAMP2 inverting input secondary selection */
#define OPAMP_OPAMP2_CSR_VMS_SEL	(1 << 8)

/* TCM_EN: Timer controlled Mux mode enable */
#define OPAMP_OPAMP2_CSR_TCM_EN		(1 << 7)

/* VM_SEL: OPAMP2 inverting input selection */
#define OPAMP_OPAMP2_CSR_VM_SEL_PC5		(0x0 << 5)
#define OPAMP_OPAMP2_CSR_VM_SEL_PA5		(0x1 << 5)
#define OPAMP_OPAMP2_CSR_VM_SEL_PGA_MODE	(0x2 << 5)
#define OPAMP_OPAMP2_CSR_VM_SEL_FOLLOWER_MODE	(0x3 << 5)

/* VP_SEL: OPAMP2 Non inverting input selection */
#define OPAMP_OPAMP2_CSR_VP_SEL_PD14		(0x0 << 2)
#define OPAMP_OPAMP2_CSR_VP_SEL_PB14		(0x1 << 2)
#define OPAMP_OPAMP2_CSR_VP_SEL_PB0		(0x2 << 2)
#define OPAMP_OPAMP2_CSR_VP_SEL_PA7		(0x3 << 2)

/* FORCE_VP */
#define OPAMP_OPAMP2_CSR_FORCE_VP	(1 << 1)

/* OPAMP2_EN: OPAMP2 enable */
#define OPAMP_OPAMP2_CSR_EN		(1 << 0)


/*------ OPAMP3_CSR values ------*/

/* LOCK: OPAMP 3 lock */
#define OPAMP_OPAMP3_CSR_LOCK		(1 << 31)

/* OUTCAL */
#define OPAMP_OPAMP3_CSR_OUTCAL		(1 << 30)

/* TSTREF */
#define OPAMP_OPAMP3_CSR_TSTREF		(1 << 29)

/* Bits 28:24 TRIMOFFSETN: Offset trimming value (NMOS) */

/* Bits 23:19 TRIMOFFSETP: Offset trimming value (PMOS) */

/* USER_TRIM: User trimming enable. */
#define OPAMP_OPAMP3_CSR_USER_TRIM	(1 << 18)

/* PGA_GAIN: Gain in PGA mode */
#define OPAMP_OPAMP3_CSR_PGA_GAIN_2		(0x0 << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_4		(0x1 << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_8		(0x2 << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_16		(0x3 << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_2_VM0		(0x8 << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_4_VM0		(0x9 << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_8_VM0		(0xA << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_16_VM0	(0xB << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_2_VM1		(0xC << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_4_VM1		(0xD << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_8_VM1		(0xE << 14)
#define OPAMP_OPAMP3_CSR_PGA_GAIN_16_VM1	(0xF << 14)

/* CALSEL: Calibration selection */
#define OPAMP_OPAMP3_CSR_CALSEL_3_3	(0x0 << 12)
#define OPAMP_OPAMP3_CSR_CALSEL_10	(0x1 << 12)
#define OPAMP_OPAMP3_CSR_CALSEL_50	(0x2 << 12)
#define OPAMP_OPAMP3_CSR_CALSEL_90	(0x3 << 12)

/* CALON: Calibration mode enable */
#define OPAMP_OPAMP3_CSR_CALON		(1 << 11)

/* VPS_SEL: OPAMP3 Non inverting input secondary selection */
#define OPAMP_OPAMP3_CSR_VPS_SEL_PB13	(0x0 << 9)
#define OPAMP_OPAMP3_CSR_VPS_SEL_PA5	(0x1 << 9)
#define OPAMP_OPAMP3_CSR_VPS_SEL_PA1	(0x2 << 9)
#define OPAMP_OPAMP3_CSR_VPS_SEL_PB0	(0x3 << 9)

/* VMS_SEL: OPAMP3 inverting input secondary selection */
#define OPAMP_OPAMP3_CSR_VMS_SEL	(1 << 8)

/* TCM_EN: Timer controlled Mux mode enable */
#define OPAMP_OPAMP3_CSR_TCM_EN		(1 << 7)

/* VM_SEL: OPAMP3 inverting input selection */
#define OPAMP_OPAMP3_CSR_VM_SEL_PB10		(0x0 << 5)
#define OPAMP_OPAMP3_CSR_VM_SEL_PB2		(0x1 << 5)
#define OPAMP_OPAMP3_CSR_VM_SEL_PGA_MODE	(0x2 << 5)
#define OPAMP_OPAMP3_CSR_VM_SEL_FOLLOWER_MODE	(0x3 << 5)

/* VP_SEL: OPAMP3 Non inverting input selection */
#define OPAMP_OPAMP3_CSR_VP_SEL_PB13		(0x0 << 2)
#define OPAMP_OPAMP3_CSR_VP_SEL_PA5		(0x1 << 2)
#define OPAMP_OPAMP3_CSR_VP_SEL_PA1		(0x2 << 2)
#define OPAMP_OPAMP3_CSR_VP_SEL_PB0		(0x3 << 2)

/* FORCE_VP */
#define OPAMP_OPAMP3_CSR_FORCE_VP	(1 << 1)

/* OPAMP3_EN: OPAMP3 enable */
#define OPAMP_OPAMP3_CSR_EN		(1 << 0)


/*------ OPAMP4_CSR values ------*/

/* LOCK: OPAMP 4 lock */
#define OPAMP_OPAMP4_CSR_LOCK		(1 << 31)

/* OUTCAL */
#define OPAMP_OPAMP4_CSR_OUTCAL		(1 << 30)

/* TSTREF */
#define OPAMP_OPAMP4_CSR_TSTREF		(1 << 29)

/* Bits 28:24 TRIMOFFSETN: Offset trimming value (NMOS) */

/* Bits 23:19 TRIMOFFSETP: Offset trimming value (PMOS) */

/* USER_TRIM: User trimming enable. */
#define OPAMP_OPAMP4_CSR_USER_TRIM	(1 << 18)

/* PGA_GAIN: Gain in PGA mode */
#define OPAMP_OPAMP4_CSR_PGA_GAIN_2		(0x0 << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_4		(0x1 << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_8		(0x2 << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_16		(0x3 << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_2_VM0		(0x8 << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_4_VM0		(0x9 << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_8_VM0		(0xA << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_16_VM0	(0xB << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_2_VM1		(0xC << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_4_VM1		(0xD << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_8_VM1		(0xE << 14)
#define OPAMP_OPAMP4_CSR_PGA_GAIN_16_VM1	(0xF << 14)

/* CALSEL: Calibration selection */
#define OPAMP_OPAMP4_CSR_CALSEL_3_3	(0x0 << 12)
#define OPAMP_OPAMP4_CSR_CALSEL_10	(0x1 << 12)
#define OPAMP_OPAMP4_CSR_CALSEL_50	(0x2 << 12)
#define OPAMP_OPAMP4_CSR_CALSEL_90	(0x3 << 12)

/* CALON: Calibration mode enable */
#define OPAMP_OPAMP4_CSR_CALON		(1 << 11)

/* VPS_SEL: OPAMP4 Non inverting input secondary selection */
#define OPAMP_OPAMP4_CSR_VPS_SEL_PD11	(0x0 << 9)
#define OPAMP_OPAMP4_CSR_VPS_SEL_PB11	(0x1 << 9)
#define OPAMP_OPAMP4_CSR_VPS_SEL_PA4	(0x2 << 9)
#define OPAMP_OPAMP4_CSR_VPS_SEL_PB13	(0x3 << 9)

/* VMS_SEL: OPAMP4 inverting input secondary selection */
#define OPAMP_OPAMP4_CSR_VMS_SEL	(1 << 8)

/* TCM_EN: Timer controlled Mux mode enable */
#define OPAMP_OPAMP4_CSR_TCM_EN		(1 << 7)

/* VM_SEL: OPAMP4 inverting input selection */
#define OPAMP_OPAMP4_CSR_VM_SEL_PB10		(0x0 << 5)
#define OPAMP_OPAMP4_CSR_VM_SEL_PD8		(0x1 << 5)
#define OPAMP_OPAMP4_CSR_VM_SEL_PGA_MODE	(0x2 << 5)
#define OPAMP_OPAMP4_CSR_VM_SEL_FOLLOWER_MODE	(0x3 << 5)

/* VP_SEL: OPAMP4 Non inverting input selection */
#define OPAMP_OPAMP4_CSR_VP_SEL_PD11		(0x0 << 2)
#define OPAMP_OPAMP4_CSR_VP_SEL_PB11		(0x1 << 2)
#define OPAMP_OPAMP4_CSR_VP_SEL_PA4		(0x2 << 2)
#define OPAMP_OPAMP4_CSR_VP_SEL_PB13		(0x3 << 2)

/* FORCE_VP */
#define OPAMP_OPAMP4_CSR_FORCE_VP	(1 << 1)

/* OPAMP4_EN: OPAMP4 enable */
#define OPAMP_OPAMP4_CSR_EN		(1 << 0)





#endif
