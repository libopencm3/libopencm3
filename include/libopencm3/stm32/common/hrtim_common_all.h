/** @addtogroup hrtim_defines

@author @htmlonly &copy; @endhtmlonly 2017
Florian Larysch <fl@n621.de>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Florian Larysch <fl@n621.de>
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

/**@{*/

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA HRTIM.H
The order of header inclusion is important. hrtim.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_HRTIM_H
/** @endcond */
#ifndef LIBOPENCM3_HRTIM_COMMON_ALL_H
#define LIBOPENCM3_HRTIM_COMMON_ALL_H

/** @defgroup hrtim_registers_common HRTIM Common Registers
 * @ingroup hrtim_defines
 * @{
 */
/** Control Register 1 (CR1) */
#define HRTIM_CR1               MMIO32(HRTIM_BASE + 0x380 + 0x00)

/** Control Register 2 (CR2) */
#define HRTIM_CR2               MMIO32(HRTIM_BASE + 0x380 + 0x04)

/** Interrupt Status Register (ISR) */
#define HRTIM_ISR               MMIO32(HRTIM_BASE + 0x380 + 0x08)

/** Interrupt Clear Register (ICR) */
#define HRTIM_ICR               MMIO32(HRTIM_BASE + 0x380 + 0x0c)

/** Interrupt Enable Register (IER) */
#define HRTIM_IER               MMIO32(HRTIM_BASE + 0x380 + 0x10)

/** Output Enable Register (OENR) */
#define HRTIM_OENR              MMIO32(HRTIM_BASE + 0x380 + 0x14)

/** Output Disable Register (ODISR) */
#define HRTIM_ODISR             MMIO32(HRTIM_BASE + 0x380 + 0x18)

/** Output Disable Status Register (ODSR) */
#define HRTIM_ODSR              MMIO32(HRTIM_BASE + 0x380 + 0x1c)

/** Burst Mode Control Register (BMCR) */
#define HRTIM_BMCR              MMIO32(HRTIM_BASE + 0x380 + 0x20)

/** Burst Mode Trigger Register (BMTRGR) */
#define HRTIM_BMTRGR            MMIO32(HRTIM_BASE + 0x380 + 0x24)

/** Burst Mode Compare Register (BMCMPR) */
#define HRTIM_BMCMPR6           MMIO32(HRTIM_BASE + 0x380 + 0x28)

/** Burst Mode Period Register (BMPER) */
#define HRTIM_BMPER             MMIO32(HRTIM_BASE + 0x380 + 0x2c)

/** Timer External Event Control Register 1 (EECR1) */
#define HRTIM_EECR1             MMIO32(HRTIM_BASE + 0x380 + 0x30)

/** Timer External Event Control Register 2 (EECR2) */
#define HRTIM_EECR2             MMIO32(HRTIM_BASE + 0x380 + 0x34)

/** Timer External Event Control Register 3 (EECR3) */
#define HRTIM_EECR3             MMIO32(HRTIM_BASE + 0x380 + 0x38)

/** ADC Trigger 1 Register (ADC1R) */
#define HRTIM_ADC1R             MMIO32(HRTIM_BASE + 0x380 + 0x3c)

/** ADC Trigger 2 Register (ADC2R) */
#define HRTIM_ADC2R             MMIO32(HRTIM_BASE + 0x380 + 0x40)

/** ADC Trigger 3 Register (ADC3R) */
#define HRTIM_ADC3R             MMIO32(HRTIM_BASE + 0x380 + 0x44)

/** ADC Trigger 4 Register (ADC4R) */
#define HRTIM_ADC4R             MMIO32(HRTIM_BASE + 0x380 + 0x48)

/** DLL Control Register (DLLCR) */
#define HRTIM_DLLCR             MMIO32(HRTIM_BASE + 0x380 + 0x4c)

/** HRTIM Fault Input Register 1 (FLTINR1) */
#define HRTIM_FLTINR1           MMIO32(HRTIM_BASE + 0x380 + 0x50)

/** HRTIM Fault Input Register 2 (FLTINR2) */
#define HRTIM_FLTINR2           MMIO32(HRTIM_BASE + 0x380 + 0x54)

/** Burst DMA Master timer update Register (BDMUPDR) */
#define HRTIM_BDMUPDR           MMIO32(HRTIM_BASE + 0x380 + 0x58)

/** Burst DMA Timerx update Register (BDTxUPR) */
#define HRTIM_BDTxUPR(x)           MMIO32(HRTIM_BASE + 0x380 + 0x5c + (x)*4)

/** Burst DMA Data Register (BDMADR) */
#define HRTIM_BDMADR            MMIO32(HRTIM_BASE + 0x380 + 0x70)
/**@}*/


/** @defgroup hrtim_registers_master HRTIM Master Registers
 * @ingroup hrtim_defines
 * @{
 */
/** Master Timer Control Register (MCR) */
#define HRTIM_MCR               MMIO32(HRTIM_BASE + 0x00)

/** Master Timer Interrupt Status Register (MISR) */
#define HRTIM_MISR              MMIO32(HRTIM_BASE + 0x04)

/** Master Timer Interrupt Clear Register (MICR) */
#define HRTIM_MICR              MMIO32(HRTIM_BASE + 0x08)

/** Master Timer DMA / Interrupt Enable Register (MDIER) */
#define HRTIM_MDIER             MMIO32(HRTIM_BASE + 0x0c)

/** Master Timer Counter Register (MCNTR) */
#define HRTIM_MCNTR             MMIO32(HRTIM_BASE + 0x10)

/** Master Timer Period Register (MPER) */
#define HRTIM_MPER              MMIO32(HRTIM_BASE + 0x14)

/** Master Timer Repetition Register (MREP) */
#define HRTIM_MREP              MMIO32(HRTIM_BASE + 0x18)

/** Master Timer Compare 1 Register (MCMP1R) */
#define HRTIM_MCMP1R            MMIO32(HRTIM_BASE + 0x1c)

/** Master Timer Compare 2 Register (MCMP2R) */
#define HRTIM_MCMP2R            MMIO32(HRTIM_BASE + 0x24)

/** Master Timer Compare 3 Register (MCMP3R) */
#define HRTIM_MCMP3R            MMIO32(HRTIM_BASE + 0x28)

/** Master Timer Compare 4 Register (MCMP4R) */
#define HRTIM_MCMP4R            MMIO32(HRTIM_BASE + 0x2c)
/**@}*/


/** @defgroup hrtim_registers_timer HRTIM TIMx Registers
 * @ingroup hrtim_defines
 * @{
 */
#define HRTIM_TIMx_BASE(x)             (HRTIM_BASE + 0x80 + (x) * 0x80)

#define HRTIM_TIMA                     0
#define HRTIM_TIMB                     1
#define HRTIM_TIMC                     2
#define HRTIM_TIMD                     3
#define HRTIM_TIME                     4

/** Timerx Control Register (TIMCR) */
#define HRTIM_TIMx_TIMCR(x)            MMIO32(HRTIM_TIMx_BASE(x) + 0x00)

/** Timerx Interrupt Status Register (ISR) */
#define HRTIM_TIMx_ISR(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x04)

/** Timerx Interrupt Clear Register (ICR) */
#define HRTIM_TIMx_ICR(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x08)

/** Timerx DMA / Interrupt Enable Register (DIER) */
#define HRTIM_TIMx_DIER(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x0c)

/** Timerx Counter Register (CNT) */
#define HRTIM_TIMx_CNT(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x10)

/** Timerx Period Register (PER) */
#define HRTIM_TIMx_PER(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x14)

/** Timerx Repetition Register (REP) */
#define HRTIM_TIMx_REP(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x18)

/** Timerx Compare 1 Register (CMP1) */
#define HRTIM_TIMx_CMP1(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x1c)

/** Timerx Compare 1 Compound Register (CMP1C) */
#define HRTIM_TIMx_CMP1C(x)            MMIO32(HRTIM_TIMx_BASE(x) + 0x20)

/** Timerx Compare 2 Register (CMP2) */
#define HRTIM_TIMx_CMP2(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x24)

/** Timerx Compare 3 Register (CMP3) */
#define HRTIM_TIMx_CMP3(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x28)

/** Timerx Compare 4 Register (CMP4) */
#define HRTIM_TIMx_CMP4(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x2c)

/** Timerx Capture 1 Register (CPT1) */
#define HRTIM_TIMx_CPT1(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x30)

/** Timerx Capture 2 Register (CPT2) */
#define HRTIM_TIMx_CPT2(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x34)

/** Timerx Deadtime Register (DT) */
#define HRTIM_TIMx_DT(x)               MMIO32(HRTIM_TIMx_BASE(x) + 0x38)

/** Timerx Output1 Set Register (SET1) */
#define HRTIM_TIMx_SET1(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x3c)

/** Timerx Output1 Reset Register (RST1) */
#define HRTIM_TIMx_RST1(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x40)

/** Timerx Output2 Set Register (SET2) */
#define HRTIM_TIMx_SET2(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x44)

/** Timerx Output2 Reset Register (RST2) */
#define HRTIM_TIMx_RST2(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x48)

/** Timerx External Event Filtering Register 1 (EEF1) */
#define HRTIM_TIMx_EEF1(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x4c)

/** Timerx External Event Filtering Register 2 (EEF2) */
#define HRTIM_TIMx_EEF2(x)             MMIO32(HRTIM_TIMx_BASE(x) + 0x50)

/** TimerA Reset Register (RST) */
#define HRTIM_TIMx_RST(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x54)

/** Timerx Chopper Register (CHP) */
#define HRTIM_TIMx_CHP(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x58)

/** Timerx Capture 1 Control Register (CPT1CR) */
#define HRTIM_TIMx_CPT1CR(x)            MMIO32(HRTIM_TIMx_BASE(x) + 0x5c)

/** Timerx Capture 2 Control Register (CPT2CR) */
#define HRTIM_TIMx_CPT2CR(x)            MMIO32(HRTIM_TIMx_BASE(x) + 0x60)

/** Timerx Output Register (OUT) */
#define HRTIM_TIMx_OUT(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x64)

/** Timerx Fault Register (FLT) */
#define HRTIM_TIMx_FLT(x)              MMIO32(HRTIM_TIMx_BASE(x) + 0x68)

/**@}*/

/** @defgroup hrtim_cr1_values HRTIM_CR1 Values
 * @ingroup hrtim_defines
 * @{
 */
/** AD4USRC[27:25]: ADC Trigger 4 Update Source */
#define HRTIM_CR1_AD4USRC_SHIFT 25
#define HRTIM_CR1_AD4USRC_MASK  (0x7 << HRTIM_CR1_AD4USRC_SHIFT)

/** AD3USRC[24:22]: ADC Trigger 3 Update Source */
#define HRTIM_CR1_AD3USRC_SHIFT 22
#define HRTIM_CR1_AD3USRC_MASK  (0x7 << HRTIM_CR1_AD3USRC_SHIFT)

/** AD2USRC[21:19]: ADC Trigger 2 Update Source */
#define HRTIM_CR1_AD2USRC_SHIFT 19
#define HRTIM_CR1_AD2USRC_MASK  (0x7 << HRTIM_CR1_AD2USRC_SHIFT)

/** AD1USRC[18:16]: ADC Trigger 1 Update Source */
#define HRTIM_CR1_AD1USRC_SHIFT 16
#define HRTIM_CR1_AD1USRC_MASK  (0x7 << HRTIM_CR1_AD1USRC_SHIFT)

#define HRTIM_CR1_ADxUSRC_MASTER      0x0
#define HRTIM_CR1_ADxUSRC_TIMA        0x1
#define HRTIM_CR1_ADxUSRC_TIMB        0x2
#define HRTIM_CR1_ADxUSRC_TIMC        0x3
#define HRTIM_CR1_ADxUSRC_TIMD        0x4
#define HRTIM_CR1_ADxUSRC_TIME        0x5

/** TEUDIS: Timer E Update Disable */
#define HRTIM_CR1_TEUDIS        (1 << 5)

/** TDUDIS: Timer D Update Disable */
#define HRTIM_CR1_TDUDIS        (1 << 4)

/** TCUDIS: Timer C Update Disable */
#define HRTIM_CR1_TCUDIS        (1 << 3)

/** TBUDIS: Timer B Update Disable */
#define HRTIM_CR1_TBUDIS        (1 << 2)

/** TAUDIS: Timer A Update Disable */
#define HRTIM_CR1_TAUDIS        (1 << 1)

/** MUDIS: Master Update Disable */
#define HRTIM_CR1_MUDIS         (1 << 0)
/**@}*/


/** @defgroup hrtim_cr2_values HRTIM_CR2 Values
 * @ingroup hrtim_defines
 * @{
 */

/** TERST: Timer E counter software reset */
#define HRTIM_CR2_TERST         (1 << 13)

/** TDRST: Timer D counter software reset */
#define HRTIM_CR2_TDRST         (1 << 12)

/** TCRST: Timer C counter software reset */
#define HRTIM_CR2_TCRST         (1 << 11)

/** TBRST: Timer B counter software reset */
#define HRTIM_CR2_TBRST         (1 << 10)

/** TARST: Timer A counter software reset */
#define HRTIM_CR2_TARST         (1 << 9)

/** MRST: Master Counter software reset */
#define HRTIM_CR2_MRST          (1 << 8)

/** TESWU: Timer E Software Update */
#define HRTIM_CR2_TESWU         (1 << 5)

/** TDSWU: Timer D Software Update */
#define HRTIM_CR2_TDSWU         (1 << 4)

/** TCSWU: Timer C Software Update */
#define HRTIM_CR2_TCSWU         (1 << 3)

/** TBSWU: Timer B Software Update */
#define HRTIM_CR2_TBSWU         (1 << 2)

/** TASWU: Timer A Software update */
#define HRTIM_CR2_TASWU         (1 << 1)

/** MSWU: Master Timer Software update */
#define HRTIM_CR2_MSWU          (1 << 0)
/**@}*/


/** @defgroup hrtim_isr_values HRTIM_ISR Values
 * @ingroup hrtim_defines
 * @{
 */

/** BMPER: Burst mode Period Interrupt Flag */
#define HRTIM_ISR_BMPER         (1 << 17)

/** DLLRDY: DLL Ready Interrupt Flag */
#define HRTIM_ISR_DLLRDY        (1 << 16)

/** SYSFLT: System Fault Interrupt Flag */
#define HRTIM_ISR_SYSFLT        (1 << 5)

/** FLT5: Fault 5 Interrupt Flag */
#define HRTIM_ISR_FLT5          (1 << 4)

/** FLT4: Fault 4 Interrupt Flag */
#define HRTIM_ISR_FLT4          (1 << 3)

/** FLT3: Fault 3 Interrupt Flag */
#define HRTIM_ISR_FLT3          (1 << 2)

/** FLT2: Fault 2 Interrupt Flag */
#define HRTIM_ISR_FLT2          (1 << 1)

/** FLT1: Fault 1 Interrupt Flag */
#define HRTIM_ISR_FLT1          (1 << 0)
/**@}*/

/** @defgroup hrtim_icr_values HRTIM_ICR Values
 * @ingroup hrtim_defines
 * @{
 */

/** BMPERC: Burst mode period flag Clear */
#define HRTIM_ICR_BMPERC        (1 << 17)

/** DLLRDYC: DLL Ready Interrupt flag Clear */
#define HRTIM_ICR_DLLRDYC       (1 << 16)

/** SYSFLTC: System Fault Interrupt Flag Clear */
#define HRTIM_ICR_SYSFLTC       (1 << 5)

/** FLT5C: Fault 5 Interrupt Flag Clear */
#define HRTIM_ICR_FLT5C         (1 << 4)

/** FLT4C: Fault 4 Interrupt Flag Clear */
#define HRTIM_ICR_FLT4C         (1 << 3)

/** FLT3C: Fault 3 Interrupt Flag Clear */
#define HRTIM_ICR_FLT3C         (1 << 2)

/** FLT2C: Fault 2 Interrupt Flag Clear */
#define HRTIM_ICR_FLT2C         (1 << 1)

/** FLT1C: Fault 1 Interrupt Flag Clear */
#define HRTIM_ICR_FLT1C         (1 << 0)

/**@}*/

/** @defgroup hrtim_ier_values HRTIM_IER Values
 * @ingroup hrtim_defines
 * @{
 */

/** BMPERIE: Burst mode period Interrupt Enable */
#define HRTIM_IER_BMPERIE       (1 << 17)

/** DLLRDYIE: DLL Ready Interrupt Enable */
#define HRTIM_IER_DLLRDYIE      (1 << 16)

/** SYSFLTE: System Fault Interrupt Enable */
#define HRTIM_IER_SYSFLTE       (1 << 5)

/** FLT5IE: Fault 5 Interrupt Enable */
#define HRTIM_IER_FLT5IE        (1 << 4)

/** FLT4IE: Fault 4 Interrupt Enable */
#define HRTIM_IER_FLT4IE        (1 << 3)

/** FLT3IE: Fault 3 Interrupt Enable */
#define HRTIM_IER_FLT3IE        (1 << 2)

/** FLT2IE: Fault 2 Interrupt Enable */
#define HRTIM_IER_FLT2IE        (1 << 1)

/** FLT1IE: Fault 1 Interrupt Enable */
#define HRTIM_IER_FLT1IE        (1 << 0)

/**@}*/

/** @defgroup hrtim_oenr_values HRTIM_OENR Values
 * @ingroup hrtim_defines
 * @{
 */

/** TE2OEN: Timer E Output 2 Enable */
#define HRTIM_OENR_TE2OEN       (1 << 9)

/** TE1OEN: Timer E Output 1 Enable */
#define HRTIM_OENR_TE1OEN       (1 << 8)

/** TD2OEN: Timer D Output 2 Enable */
#define HRTIM_OENR_TD2OEN       (1 << 7)

/** TD1OEN: Timer D Output 1 Enable */
#define HRTIM_OENR_TD1OEN       (1 << 6)

/** TC2OEN: Timer C Output 2 Enable */
#define HRTIM_OENR_TC2OEN       (1 << 5)

/** TC1OEN: Timer C Output 1 Enable */
#define HRTIM_OENR_TC1OEN       (1 << 4)

/** TB2OEN: Timer B Output 2 Enable */
#define HRTIM_OENR_TB2OEN       (1 << 3)

/** TB1OEN: Timer B Output 1 Enable */
#define HRTIM_OENR_TB1OEN       (1 << 2)

/** TA2OEN: Timer A Output 2 Enable */
#define HRTIM_OENR_TA2OEN       (1 << 1)

/** TA1OEN: Timer A Output 1 Enable */
#define HRTIM_OENR_TA1OEN       (1 << 0)

/**@}*/

/** @defgroup hrtim_odisr_values HRTIM_ODISR Values
 * @ingroup hrtim_defines
 * @{
 */

/** TE2ODIS: Timer E Output 2 disable */
#define HRTIM_DISR_TE2ODIS      (1 << 9)

/** TE1ODIS: Timer E Output 1 disable */
#define HRTIM_DISR_TE1ODIS      (1 << 8)

/** TD2ODIS: Timer D Output 2 disable */
#define HRTIM_DISR_TD2ODIS      (1 << 7)

/** TD1ODIS: Timer D Output 1 disable */
#define HRTIM_DISR_TD1ODIS      (1 << 6)

/** TC2ODIS: Timer C Output 2 disable */
#define HRTIM_DISR_TC2ODIS      (1 << 5)

/** TC1ODIS: Timer C Output 1 disable */
#define HRTIM_DISR_TC1ODIS      (1 << 4)

/** TB2ODIS: Timer B Output 2 disable */
#define HRTIM_DISR_TB2ODIS      (1 << 3)

/** TB1ODIS: Timer B Output 1 disable */
#define HRTIM_DISR_TB1ODIS      (1 << 2)

/** TA2ODIS: Timer A Output 2 disable */
#define HRTIM_DISR_TA2ODIS      (1 << 1)

/** TA1ODIS: Timer A Output 1 disable */
#define HRTIM_DISR_TA1ODIS      (1 << 0)

/**@}*/

/** @defgroup hrtim_odsr_values HRTIM_ODSR Values
 * @ingroup hrtim_defines
 * @{
 */

/** TE2ODS: Timer E Output 2 disable status */
#define HRTIM_ODSR_TE2ODS       (1 << 9)

/** TE1ODS: Timer E Output 1 disable status */
#define HRTIM_ODSR_TE1ODS       (1 << 8)

/** TD2ODS: Timer D Output 2 disable status */
#define HRTIM_ODSR_TD2ODS       (1 << 7)

/** TD1ODS: Timer D Output 1 disable status */
#define HRTIM_ODSR_TD1ODS       (1 << 6)

/** TC2ODS: Timer C Output 2 disable status */
#define HRTIM_ODSR_TC2ODS       (1 << 5)

/** TC1ODS: Timer C Output 1 disable status */
#define HRTIM_ODSR_TC1ODS       (1 << 4)

/** TB2ODS: Timer B Output 2 disable status */
#define HRTIM_ODSR_TB2ODS       (1 << 3)

/** TB1ODS: Timer B Output 1 disable status */
#define HRTIM_ODSR_TB1ODS       (1 << 2)

/** TA2ODS: Timer A Output 2 disable status */
#define HRTIM_ODSR_TA2ODS       (1 << 1)

/** TA1ODS: Timer A Output 1 disable status */
#define HRTIM_ODSR_TA1ODS       (1 << 0)

/**@}*/

/** @defgroup hrtim_bmcr_values HRTIM_BMCR Values
 * @ingroup hrtim_defines
 * @{
 */

/** BMSTAT: Burst Mode Status */
#define HRTIM_BMCR_BMSTAT       (1 << 31)

/** TEBM: Timer E Burst Mode */
#define HRTIM_BMCR_TEBM         (1 << 21)

/** TDBM: Timer D Burst Mode */
#define HRTIM_BMCR_TDBM         (1 << 20)

/** TCBM: Timer C Burst Mode */
#define HRTIM_BMCR_TCBM         (1 << 19)

/** TBBM: Timer B Burst Mode */
#define HRTIM_BMCR_TBBM         (1 << 18)

/** TABM: Timer A Burst Mode */
#define HRTIM_BMCR_TABM         (1 << 17)

/** MTBM: Master Timer Burst Mode */
#define HRTIM_BMCR_MTBM         (1 << 16)

/** BMPREN: Burst Mode Preload Enable */
#define HRTIM_BMCR_BMPREN       (1 << 10)

/** BMPRSC[9:6]: Burst Mode Prescaler */
#define HRTIM_BMCR_BMPRSC_SHIFT 6
#define HRTIM_BMCR_BMPRSC_MASK  (0xf << HRTIM_BMCR_BMPRSC_SHIFT)

#define HRTIM_BMCR_BMPRSC_1          ( 0 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_2          ( 1 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_4          ( 2 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_8          ( 3 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_16         ( 4 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_32         ( 5 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_64         ( 6 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_128        ( 7 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_256        ( 8 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_512        ( 9 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_1024       (10 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_2048       (11 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_4096       (12 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_8192       (13 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_16384      (14 << HRTIM_BMCR_BMPRSC_SHIFT)
#define HRTIM_BMCR_BMPRSC_32768      (15 << HRTIM_BMCR_BMPRSC_SHIFT)

/** BMCLK[5:2]: Burst Mode Clock source */
#define HRTIM_BMCR_BMCLK_SHIFT  2
#define HRTIM_BMCR_BMCLK_MASK   (0xf << HRTIM_BMCR_BMCLK_SHIFT)

#define HRTIM_BMCR_BMCLK_MASTER    ( 0 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_TIMA      ( 1 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_TIMB      ( 2 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_TIMC      ( 3 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_TIMD      ( 4 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_TIME      ( 5 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_BMC1      ( 6 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_BMC2      ( 7 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_BMC3      ( 8 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_BMC4      ( 9 << HRTIM_BMCR_BMCLK_SHIFT)
#define HRTIM_BMCR_BMCLK_HRTIM     (10 << HRTIM_BMCR_BMCLK_SHIFT)

/** BMOM: Burst Mode operating mode */
#define HRTIM_BMCR_BMOM         (1 << 1)

/** BME: Burst Mode enable */
#define HRTIM_BMCR_BME          (1 << 0)

/**@}*/

/** @defgroup hrtim_bmtrgr_values HRTIM_BMTRGR Values
 * @ingroup hrtim_defines
 * @{
 */

/** OCHPEV: On-chip Event */
#define HRTIM_BMTRGR_OCHPEV      (1 << 31)

/** EEV8: External Event 8 */
#define HRTIM_BMTRGR_EEV8        (1 << 30)

/** EEV7: External Event 7 */
#define HRTIM_BMTRGR_EEV7        (1 << 29)

/** TDEEV8: Timer D period following External Event 8 */
#define HRTIM_BMTRGR_TDEEV8      (1 << 28)

/** TAEEV7: Timer A period following External Event 7 */
#define HRTIM_BMTRGR_TAEEV7      (1 << 27)

/** TECMP2: Timer E Compare 2 event */
#define HRTIM_BMTRGR_TECMP2      (1 << 26)

/** TECMP1: Timer E Compare 1 event */
#define HRTIM_BMTRGR_TECMP1      (1 << 25)

/** TEREP: Timer E repetition */
#define HRTIM_BMTRGR_TEREP       (1 << 24)

/** TERST: Timer E reset or roll-over */
#define HRTIM_BMTRGR_TERST       (1 << 23)

/** TDCMP2: Timer D Compare 2 event */
#define HRTIM_BMTRGR_TDCMP2      (1 << 22)

/** TDCMP1: Timer D Compare 1 event */
#define HRTIM_BMTRGR_TDCMP1      (1 << 21)

/** TDREP: Timer D repetition */
#define HRTIM_BMTRGR_TDREP       (1 << 20)

/** TDRST: Timer D reset or roll-over */
#define HRTIM_BMTRGR_TDRST       (1 << 19)

/** TCCMP2: Timer C Compare 2 event */
#define HRTIM_BMTRGR_TCCMP2      (1 << 18)

/** TCCMP1: Timer C Compare 1 event */
#define HRTIM_BMTRGR_TCCMP1      (1 << 17)

/** TCREP: Timer C repetition */
#define HRTIM_BMTRGR_TCREP       (1 << 16)

/** TCRST: Timer C reset or roll-over */
#define HRTIM_BMTRGR_TCRST       (1 << 15)

/** TBCMP2: Timer B Compare 2 event */
#define HRTIM_BMTRGR_TBCMP2      (1 << 14)

/** TBCMP1: Timer B Compare 1 event */
#define HRTIM_BMTRGR_TBCMP1      (1 << 13)

/** TBREP: Timer B repetition */
#define HRTIM_BMTRGR_TBREP       (1 << 12)

/** TBRST: Timer B reset or roll-over */
#define HRTIM_BMTRGR_TBRST       (1 << 11)

/** TACMP2: Timer A Compare 2 event */
#define HRTIM_BMTRGR_TACMP2      (1 << 10)

/** TACMP1: Timer A Compare 1 event */
#define HRTIM_BMTRGR_TACMP1      (1 << 9)

/** TAREP: Timer A repetition */
#define HRTIM_BMTRGR_TAREP       (1 << 8)

/** TARST: Timer A reset or roll-over */
#define HRTIM_BMTRGR_TARST       (1 << 7)

/** MSTCMP4: Master Compare 4 */
#define HRTIM_BMTRGR_MSTCMP4     (1 << 6)

/** MSTCMP3: Master Compare 3 */
#define HRTIM_BMTRGR_MSTCMP3     (1 << 5)

/** MSTCMP2: Master Compare 2 */
#define HRTIM_BMTRGR_MSTCMP2     (1 << 4)

/** MSTCMP1: Master Compare 1 */
#define HRTIM_BMTRGR_MSTCMP1     (1 << 3)

/** MSTREP: Master repetition */
#define HRTIM_BMTRGR_MSTREP      (1 << 2)

/** MSTRST: Master reset or roll-over */
#define HRTIM_BMTRGR_MSTRST      (1 << 1)

/** SW: Software start */
#define HRTIM_BMTRGR_SW          (1 << 0)

/**@}*/

/** @defgroup hrtim_eecrx_values HRTIM_EECRx Values
 * @ingroup hrtim_defines
 * @{
 */

/** EExFAST: External Event x Fast mode */
#define HRTIM_EECR_EExFAST(x)     (1 << ((x) * 6 - 1))

/** EExSNS: External Event x Sensitivity */
#define HRTIM_EECR_EExSNS_SHIFT(x) ((x) * 6 - 3)
#define HRTIM_EECR_EExSNS_MASK(x) (0x3 << HRTIM_EECR_EExSNS_SHIFT(x))

#define HRTIM_EECR_EExSNS_LEVEL(x)     (0 << HRTIM_EECR_EExSNS_SHIFT(x))
#define HRTIM_EECR_EExSNS_RISING(x)    (1 << HRTIM_EECR_EExSNS_SHIFT(x))
#define HRTIM_EECR_EExSNS_FALLING(x)   (2 << HRTIM_EECR_EExSNS_SHIFT(x))
#define HRTIM_EECR_EExSNS_BOTH(x)      (3 << HRTIM_EECR_EExSNS_SHIFT(x))

/** EExPOL: External Event x Polarity */
#define HRTIM_EECR_EExPOL      (1 << ((x) * 6 - 4))

/** EExSRC: External Event x Source */
#define HRTIM_EECR_EExSRC_SHIFT(x) ((x) * 6 - 6)
#define HRTIM_EECR_EExSRC_MASK(x) (0x3 << HRTIM_EECR_EExSRC_SHIFT(x))


/* --- HRTIM_EECR3 values -------------------------------------------- */

/** EExF: External Event x Filter */
#define HRTIM_EECR3_EExF_SHIFT(x) ((x - 6) * 4)
#define HRTIM_EECR3_EExF_MASK(x) (0xF << HRTIM_EECR3_EExF_SHIFT(x))

/**@}*/

/** @defgroup hrtim_adc1r_values HRTIM_ADC1R Values
 * @ingroup hrtim_defines
 * @{
 */

/** AD1TEPER: ADC trigger 1 on Timer E Period */
#define HRTIM_ADC1R_AD1TEPER    (1 << 31)

/** AD1TE4: ADC trigger 1 on Timer E Compare 4 */
#define HRTIM_ADC1R_AD1TEC4     (1 << 30)

/** AD1TE3: ADC trigger 1 on Timer E Compare 3 */
#define HRTIM_ADC1R_AD1TEC3     (1 << 29)

/** AD1TE2: ADC trigger 1 on Timer E Compare 2 */
#define HRTIM_ADC1R_AD1TEC2     (1 << 28)

/** AD1TDPER: ADC trigger 1 on Timer D Period */
#define HRTIM_ADC1R_AD1TDPER    (1 << 27)

/** AD1TD4: ADC trigger 1 on Timer D Compare 4 */
#define HRTIM_ADC1R_AD1TDC4     (1 << 26)

/** AD1TD3: ADC trigger 1 on Timer D Compare 3 */
#define HRTIM_ADC1R_AD1TDC3     (1 << 25)

/** AD1TD2: ADC trigger 1 on Timer D Compare 2 */
#define HRTIM_ADC1R_AD1TDC2     (1 << 24)

/** AD1TCPER: ADC trigger 1 on Timer C Period */
#define HRTIM_ADC1R_AD1TCPER    (1 << 23)

/** AD1TC4: ADC trigger 1 on Timer C Compare 4 */
#define HRTIM_ADC1R_AD1TCC4     (1 << 22)

/** AD1TC3: ADC trigger 1 on Timer C Compare 3 */
#define HRTIM_ADC1R_AD1TCC3     (1 << 21)

/** AD1TC2: ADC trigger 1 on Timer C Compare 2 */
#define HRTIM_ADC1R_AD1TCC2     (1 << 20)

/** AD1TBRST: ADC trigger 1 on Timer B Reset and counter roll-over */
#define HRTIM_ADC1R_AD1TBRST    (1 << 19)

/** AD1TBPER: ADC trigger 1 on Timer B Period */
#define HRTIM_ADC1R_AD1TBPER    (1 << 18)

/** AD1TB4: ADC trigger 1 on Timer B Compare 4 */
#define HRTIM_ADC1R_AD1TBC4     (1 << 17)

/** AD1TB3: ADC trigger 1 on Timer B Compare 3 */
#define HRTIM_ADC1R_AD1TBC3     (1 << 16)

/** AD1TB2: ADC trigger 1 on Timer B Compare 2 */
#define HRTIM_ADC1R_AD1TBC2     (1 << 15)

/** AD1TARST: ADC trigger 1 on Timer A Reset and counter roll-over */
#define HRTIM_ADC1R_AD1TARST    (1 << 14)

/** AD1TAPER: ADC trigger 1 on Timer A Period */
#define HRTIM_ADC1R_AD1TAPER    (1 << 13)

/** AD1TA4: ADC trigger 1 on Timer A Compare 4 */
#define HRTIM_ADC1R_AD1TAC4     (1 << 12)

/** AD1TA3: ADC trigger 1 on Timer A Compare 3 */
#define HRTIM_ADC1R_AD1TAC3     (1 << 11)

/** AD1TA2: ADC trigger 1 on Timer A Compare 2 */
#define HRTIM_ADC1R_AD1TAC2     (1 << 10)

/** AD1EEV5: ADC trigger 1 on External Event 5 */
#define HRTIM_ADC1R_AD1EEV5     (1 << 9)

/** AD1EEV4: ADC trigger 1 on External Event 4 */
#define HRTIM_ADC1R_AD1EEV4     (1 << 8)

/** AD1EEV3: ADC trigger 1 on External Event 3 */
#define HRTIM_ADC1R_AD1EEV3     (1 << 7)

/** AD1EEV2: ADC trigger 1 on External Event 2 */
#define HRTIM_ADC1R_AD1EEV2     (1 << 6)

/** AD1EEV1: ADC trigger 1 on External Event 1 */
#define HRTIM_ADC1R_AD1EEV1     (1 << 5)

/** AD1MPER: ADC trigger 1 on Master Period */
#define HRTIM_ADC1R_AD1MPER     (1 << 4)

/** AD1MC4: ADC trigger 1 on Master Compare 4 */
#define HRTIM_ADC1R_AD1MC4      (1 << 3)

/** AD1MC3: ADC trigger 1 on Master Compare 3 */
#define HRTIM_ADC1R_AD1MC3      (1 << 2)

/** AD1MC2: ADC trigger 1 on Master Compare 2 */
#define HRTIM_ADC1R_AD1MC2      (1 << 1)

/** AD1MC1: ADC trigger 1 on Master Compare 1 */
#define HRTIM_ADC1R_AD1MC1      (1 << 0)

/**@}*/

/** @defgroup hrtim_adc2r_values HRTIM_ADC2R Values
 * @ingroup hrtim_defines
 * @{
 */

/** AD2TERST: ADC trigger 2 on Timer E Reset and counter roll-over */
#define HRTIM_ADC2R_AD2TERST    (1 << 31)

/** AD2TE4: ADC trigger 2 on Timer E Compare 4 */
#define HRTIM_ADC2R_AD2TEC4     (1 << 30)

/** AD2TE3: ADC trigger 2 on Timer E Compare 3 */
#define HRTIM_ADC2R_AD2TEC3     (1 << 29)

/** AD2TE2: ADC trigger 2 on Timer E Compare 2 */
#define HRTIM_ADC2R_AD2TEC2     (1 << 28)

/** AD2TDRST: ADC trigger 2 on Timer D Reset and counter roll-over */
#define HRTIM_ADC2R_AD2TDRST    (1 << 27)

/** AD2TDPER: ADC trigger 2 on Timer D Period */
#define HRTIM_ADC2R_AD2TDPER    (1 << 26)

/** AD2TD4: ADC trigger 2 on Timer D Compare 4 */
#define HRTIM_ADC2R_AD2TDC4     (1 << 25)

/** AD2TD3: ADC trigger 2 on Timer D Compare 3 */
#define HRTIM_ADC2R_AD2TDC3     (1 << 24)

/** AD2TD2: ADC trigger 2 on Timer D Compare 2 */
#define HRTIM_ADC2R_AD2TDC2     (1 << 23)

/** AD2TCRST: ADC trigger 2 on Timer C Reset and counter roll-over */
#define HRTIM_ADC2R_AD2TCRST    (1 << 22)

/** AD2TCPER: ADC trigger 2 on Timer C Period */
#define HRTIM_ADC2R_AD2TCPER    (1 << 21)

/** AD2TC4: ADC trigger 2 on Timer C Compare 4 */
#define HRTIM_ADC2R_AD2TCC4     (1 << 20)

/** AD2TC3: ADC trigger 2 on Timer C Compare 3 */
#define HRTIM_ADC2R_AD2TCC3     (1 << 19)

/** AD2TC2: ADC trigger 2 on Timer C Compare 2 */
#define HRTIM_ADC2R_AD2TCC2     (1 << 18)

/** AD2TBPER: ADC trigger 2 on Timer B Period */
#define HRTIM_ADC2R_AD2TBPER    (1 << 17)

/** AD2TB4: ADC trigger 2 on Timer B Compare 4 */
#define HRTIM_ADC2R_AD2TBC4     (1 << 16)

/** AD2TB3: ADC trigger 2 on Timer B Compare 3 */
#define HRTIM_ADC2R_AD2TBC3     (1 << 15)

/** AD2TB2: ADC trigger 2 on Timer B Compare 2 */
#define HRTIM_ADC2R_AD2TBC2     (1 << 14)

/** AD2TAPER: ADC trigger 2 on Timer A Period */
#define HRTIM_ADC2R_AD2TAPER    (1 << 13)

/** AD2TA4: ADC trigger 2 on Timer A Compare 4 */
#define HRTIM_ADC2R_AD2TAC4     (1 << 12)

/** AD2TA3: ADC trigger 2 on Timer A Compare 3 */
#define HRTIM_ADC2R_AD2TAC3     (1 << 11)

/** AD2TA2: ADC trigger 2 on Timer A Compare 2 */
#define HRTIM_ADC2R_AD2TAC2     (1 << 10)

/** AD2EEV10: ADC trigger 2 on External Event 10 */
#define HRTIM_ADC2R_AD2EEV10    (1 << 9)

/** AD2EEV9: ADC trigger 2 on External Event 9 */
#define HRTIM_ADC2R_AD2EEV9     (1 << 8)

/** AD2EEV8: ADC trigger 2 on External Event 8 */
#define HRTIM_ADC2R_AD2EEV8     (1 << 7)

/** AD2EEV7: ADC trigger 2 on External Event 7 */
#define HRTIM_ADC2R_AD2EEV7     (1 << 6)

/** AD2EEV6: ADC trigger 2 on External Event 6 */
#define HRTIM_ADC2R_AD2EEV6     (1 << 5)

/** AD2MPER: ADC trigger 2 on Master Period */
#define HRTIM_ADC2R_AD2MPER     (1 << 4)

/** AD2MC4: ADC trigger 2 on Master Compare 4 */
#define HRTIM_ADC2R_AD2MC4      (1 << 3)

/** AD2MC3: ADC trigger 2 on Master Compare 3 */
#define HRTIM_ADC2R_AD2MC3      (1 << 2)

/** AD2MC2: ADC trigger 2 on Master Compare 2 */
#define HRTIM_ADC2R_AD2MC2      (1 << 1)

/** AD2MC1: ADC trigger 2 on Master Compare 1 */
#define HRTIM_ADC2R_AD2MC1      (1 << 0)

/**@}*/

/** @defgroup hrtim_adc3r_values HRTIM_ADC3R Values
 * @ingroup hrtim_defines
 * @{
 */

/** AD1TEPER: ADC trigger 1 on Timer E Period */
#define HRTIM_ADC3R_AD3TEPER    (1 << 31)

/** AD3TE4: ADC trigger 1 on Timer E Compare 4 */
#define HRTIM_ADC3R_AD3TEC4     (1 << 30)

/** AD3TE3: ADC trigger 1 on Timer E Compare 3 */
#define HRTIM_ADC3R_AD3TEC3     (1 << 29)

/** AD3TE2: ADC trigger 1 on Timer E Compare 2 */
#define HRTIM_ADC3R_AD3TEC2     (1 << 28)

/** AD3TDPER: ADC trigger 1 on Timer D Period */
#define HRTIM_ADC3R_AD3TDPER    (1 << 27)

/** AD3TD4: ADC trigger 1 on Timer D Compare 4 */
#define HRTIM_ADC3R_AD3TDC4     (1 << 26)

/** AD3TD3: ADC trigger 1 on Timer D Compare 3 */
#define HRTIM_ADC3R_AD3TDC3     (1 << 25)

/** AD3TD2: ADC trigger 1 on Timer D Compare 2 */
#define HRTIM_ADC3R_AD3TDC2     (1 << 24)

/** AD3TCPER: ADC trigger 1 on Timer C Period */
#define HRTIM_ADC3R_AD3TCPER    (1 << 23)

/** AD3TC4: ADC trigger 1 on Timer C Compare 4 */
#define HRTIM_ADC3R_AD3TCC4     (1 << 22)

/** AD3TC3: ADC trigger 1 on Timer C Compare 3 */
#define HRTIM_ADC3R_AD3TCC3     (1 << 21)

/** AD3TC2: ADC trigger 1 on Timer C Compare 2 */
#define HRTIM_ADC3R_AD3TCC2     (1 << 20)

/** AD3TBRST: ADC trigger 1 on Timer B Reset and counter roll-over */
#define HRTIM_ADC3R_AD3TBRST    (1 << 19)

/** AD3TBPER: ADC trigger 1 on Timer B Period */
#define HRTIM_ADC3R_AD3TBPER    (1 << 18)

/** AD3TB4: ADC trigger 1 on Timer B Compare 4 */
#define HRTIM_ADC3R_AD3TBC4     (1 << 17)

/** AD3TB3: ADC trigger 1 on Timer B Compare 3 */
#define HRTIM_ADC3R_AD3TBC3     (1 << 16)

/** AD3TB2: ADC trigger 1 on Timer B Compare 2 */
#define HRTIM_ADC3R_AD3TBC2     (1 << 15)

/** AD3TARST: ADC trigger 1 on Timer A Reset and counter roll-over */
#define HRTIM_ADC3R_AD3TARST    (1 << 14)

/** AD3TAPER: ADC trigger 1 on Timer A Period */
#define HRTIM_ADC3R_AD3TAPER    (1 << 13)

/** AD3TA4: ADC trigger 1 on Timer A Compare 4 */
#define HRTIM_ADC3R_AD3TAC4     (1 << 12)

/** AD3TA3: ADC trigger 1 on Timer A Compare 3 */
#define HRTIM_ADC3R_AD3TAC3     (1 << 11)

/** AD3TA2: ADC trigger 1 on Timer A Compare 2 */
#define HRTIM_ADC3R_AD3TAC2     (1 << 10)

/** AD3EEV5: ADC trigger 3 on External Event 5 */
#define HRTIM_ADC3R_AD3EEV5     (1 << 9)

/** AD3EEV4: ADC trigger 3 on External Event 4 */
#define HRTIM_ADC3R_AD3EEV4     (1 << 8)

/** AD3EEV3: ADC trigger 3 on External Event 3 */
#define HRTIM_ADC3R_AD3EEV3     (1 << 7)

/** AD3EEV2: ADC trigger 3 on External Event 2 */
#define HRTIM_ADC3R_AD3EEV2     (1 << 6)

/** AD3EEV1: ADC trigger 3 on External Event 1 */
#define HRTIM_ADC3R_AD3EEV1     (1 << 5)

/** AD3MPER: ADC trigger 3 on Master Period */
#define HRTIM_ADC3R_AD3MPER     (1 << 4)

/** AD3MC4: ADC trigger 3 on Master Compare 4 */
#define HRTIM_ADC3R_AD3MC4      (1 << 3)

/** AD3MC3: ADC trigger 3 on Master Compare 3 */
#define HRTIM_ADC3R_AD3MC3      (1 << 2)

/** AD3MC2: ADC trigger 3 on Master Compare 2 */
#define HRTIM_ADC3R_AD3MC2      (1 << 1)

/** AD3MC1: ADC trigger 3 on Master Compare 1 */
#define HRTIM_ADC3R_AD3MC1      (1 << 0)

/**@}*/

/** @defgroup hrtim_adc4r_values HRTIM_ADC4R Values
 * @ingroup hrtim_defines
 * @{
 */

/** AD4TERST: ADC trigger 2 on Timer E Reset and counter roll-over */
#define HRTIM_ADC4R_AD4TERST    (1 << 31)

/** AD4TE4: ADC trigger 2 on Timer E Compare 4 */
#define HRTIM_ADC4R_AD4TEC4     (1 << 30)

/** AD4TE3: ADC trigger 2 on Timer E Compare 3 */
#define HRTIM_ADC4R_AD4TEC3     (1 << 29)

/** AD4TE2: ADC trigger 2 on Timer E Compare 2 */
#define HRTIM_ADC4R_AD4TEC2     (1 << 28)

/** AD4TDRST: ADC trigger 2 on Timer D Reset and counter roll-over */
#define HRTIM_ADC4R_AD4TDRST    (1 << 27)

/** AD4TDPER: ADC trigger 2 on Timer D Period */
#define HRTIM_ADC4R_AD4TDPER    (1 << 26)

/** AD4TD4: ADC trigger 2 on Timer D Compare 4 */
#define HRTIM_ADC4R_AD4TDC4     (1 << 25)

/** AD4TD3: ADC trigger 2 on Timer D Compare 3 */
#define HRTIM_ADC4R_AD4TDC3     (1 << 24)

/** AD4TD2: ADC trigger 2 on Timer D Compare 2 */
#define HRTIM_ADC4R_AD4TDC2     (1 << 23)

/** AD4TCRST: ADC trigger 2 on Timer C Reset and counter roll-over */
#define HRTIM_ADC4R_AD4TCRST    (1 << 22)

/** AD4TCPER: ADC trigger 2 on Timer C Period */
#define HRTIM_ADC4R_AD4TCPER    (1 << 21)

/** AD4TC4: ADC trigger 2 on Timer C Compare 4 */
#define HRTIM_ADC4R_AD4TCC4     (1 << 20)

/** AD4TC3: ADC trigger 2 on Timer C Compare 3 */
#define HRTIM_ADC4R_AD4TCC3     (1 << 19)

/** AD4TC2: ADC trigger 2 on Timer C Compare 2 */
#define HRTIM_ADC4R_AD4TCC2     (1 << 18)

/** AD4TBPER: ADC trigger 2 on Timer B Period */
#define HRTIM_ADC4R_AD4TBPER    (1 << 17)

/** AD4TB4: ADC trigger 2 on Timer B Compare 4 */
#define HRTIM_ADC4R_AD4TBC4     (1 << 16)

/** AD4TB3: ADC trigger 2 on Timer B Compare 3 */
#define HRTIM_ADC4R_AD4TBC3     (1 << 15)

/** AD4TB2: ADC trigger 2 on Timer B Compare 2 */
#define HRTIM_ADC4R_AD4TBC2     (1 << 14)

/** AD4TAPER: ADC trigger 2 on Timer A Period */
#define HRTIM_ADC4R_AD4TAPER    (1 << 13)

/** AD4TA4: ADC trigger 2 on Timer A Compare 4 */
#define HRTIM_ADC4R_AD4TAC4     (1 << 12)

/** AD4TA3: ADC trigger 2 on Timer A Compare 3 */
#define HRTIM_ADC4R_AD4TAC3     (1 << 11)

/** AD4TA2: ADC trigger 2 on Timer A Compare 2 */
#define HRTIM_ADC4R_AD4TAC2     (1 << 10)

/** AD4EEV10: ADC trigger 4 on External Event 10 */
#define HRTIM_ADC4R_AD4EEV10    (1 << 9)

/** AD4EEV9: ADC trigger 4 on External Event 9 */
#define HRTIM_ADC4R_AD4EEV9     (1 << 8)

/** AD4EEV8: ADC trigger 4 on External Event 8 */
#define HRTIM_ADC4R_AD4EEV8     (1 << 7)

/** AD4EEV7: ADC trigger 4 on External Event 7 */
#define HRTIM_ADC4R_AD4EEV7     (1 << 6)

/** AD4EEV6: ADC trigger 4 on External Event 6 */
#define HRTIM_ADC4R_AD4EEV6     (1 << 5)

/** AD4MPER: ADC trigger 4 on Master Period */
#define HRTIM_ADC4R_AD4MPER     (1 << 4)

/** AD4MC4: ADC trigger 4 on Master Compare 4 */
#define HRTIM_ADC4R_AD4MC4      (1 << 3)

/** AD4MC3: ADC trigger 4 on Master Compare 3 */
#define HRTIM_ADC4R_AD4MC3      (1 << 2)

/** AD4MC2: ADC trigger 4 on Master Compare 2 */
#define HRTIM_ADC4R_AD4MC2      (1 << 1)

/** AD4MC1: ADC trigger 4 on Master Compare 1 */
#define HRTIM_ADC4R_AD4MC1      (1 << 0)

/**@}*/

/** @defgroup hrtim_dllcr_values HRTIM_DLLCR Values
 * @ingroup hrtim_defines
 * @{
 */

/** CALRTE[3:2]: DLL Calibration rate */
#define HRTIM_DLLCR_CALRTE_SHIFT 2
#define HRTIM_DLLCR_CALRTE_MASK (0x3 << HRTIM_DLLCR_CALRTE_SHIFT)

#define HRTIM_DLLCR_CALRTE_1048576     (0 << HRTIM_DLLCR_CALRTE_SHIFT)
#define HRTIM_DLLCR_CALRTE_131072      (1 << HRTIM_DLLCR_CALRTE_SHIFT)
#define HRTIM_DLLCR_CALRTE_16384       (2 << HRTIM_DLLCR_CALRTE_SHIFT)
#define HRTIM_DLLCR_CALRTE_2048        (3 << HRTIM_DLLCR_CALRTE_SHIFT)

/** CALEN: DLL Calibration Enable */
#define HRTIM_DLLCR_CALEN       (1 << 1)

/** CAL: DLL Calibration Start */
#define HRTIM_DLLCR_CAL         (1 << 0)

/**@}*/

/** @defgroup hrtim_fltinr1_values HRTIM_FLTINR1 Values
 * @ingroup hrtim_defines
 * @{
 */

/** FLTxLCK: FLTxLCK */
#define HRTIM_FLTINR1_FLTxLCK(x)   (1 << ((x) * 8 - 1))

/** FLTxF: FLTxF */
#define HRTIM_FLTINR1_FLTxF_SHIFT(x) ((x) * 8 - 5)
#define HRTIM_FLTINR1_FLTxF_MASK(x) (0xf << HRTIM_FLTINR1_FLTxF_SHIFT(x))

/** FLTxSRC: FLTxSRC */
#define HRTIM_FLTINR1_FLTxSRC(x)   (1 << ((x) * 8 - 6))

/** FLTxP: FLTxP */
#define HRTIM_FLTINR1_FLTxP(x)     (1 << ((x) * 8 - 7))

/** FLTxE: FLTxE */
#define HRTIM_FLTINR1_FLTxE(x)     (1 << ((x) * 8 - 8))

/**@}*/

/** @defgroup hrtim_fltinr2_values HRTIM_FLTINR2 Values
 * @ingroup hrtim_defines
 * @{
 */

/** FLTSD[25:24]: FLTSD */
#define HRTIM_FLTINR2_FLTSD_SHIFT 24
#define HRTIM_FLTINR2_FLTSD_MASK (0x3 << HRTIM_FLTINR2_FLTSD_SHIFT)

#define HRTIM_FLTINR2_FLTSD_DIV1    (0 << HRTIM_FLTINR2_FLTSD_SHIFT)
#define HRTIM_FLTINR2_FLTSD_DIV2    (1 << HRTIM_FLTINR2_FLTSD_SHIFT)
#define HRTIM_FLTINR2_FLTSD_DIV4    (2 << HRTIM_FLTINR2_FLTSD_SHIFT)
#define HRTIM_FLTINR2_FLTSD_DIV8    (3 << HRTIM_FLTINR2_FLTSD_SHIFT)

/** FLT5LCK: FLT5LCK */
#define HRTIM_FLTINR2_FLT5LCK   (1 << 7)

/** FLT5F[6:3]: FLT5F */
#define HRTIM_FLTINR2_FLT5F_SHIFT 3
#define HRTIM_FLTINR2_FLT5F_MASK (0xf << HRTIM_FLTINR2_FLT5F_SHIFT)

/** FLT5SRC: FLT5SRC */
#define HRTIM_FLTINR2_FLT5SRC   (1 << 2)

/** FLT5P: FLT5P */
#define HRTIM_FLTINR2_FLT5P     (1 << 1)

/** FLT5E: FLT5E */
#define HRTIM_FLTINR2_FLT5E     (1 << 0)

/**@}*/

/** @defgroup hrtim_bmdupdr_values HRTIM_BDMUPDR Values
 * @ingroup hrtim_defines
 * @{
 */

/** MCMP4: MCMP4 register update enable */
#define HRTIM_BDMUPDR_MCMP4     (1 << 9)

/** MCMP3: MCMP3 register update enable */
#define HRTIM_BDMUPDR_MCMP3     (1 << 8)

/** MCMP2: MCMP2 register update enable */
#define HRTIM_BDMUPDR_MCMP2     (1 << 7)

/** MCMP1: MCMP1 register update enable */
#define HRTIM_BDMUPDR_MCMP1     (1 << 6)

/** MREP: MREP register update enable */
#define HRTIM_BDMUPDR_MREP      (1 << 5)

/** MPER: MPER register update enable */
#define HRTIM_BDMUPDR_MPER      (1 << 4)

/** MCNT: MCNT register update enable */
#define HRTIM_BDMUPDR_MCNT      (1 << 3)

/** MDIER: MDIER register update enable */
#define HRTIM_BDMUPDR_MDIER     (1 << 2)

/** MICR: MICR register update enable */
#define HRTIM_BDMUPDR_MICR      (1 << 1)

/** MCR: MCR register update enable */
#define HRTIM_BDMUPDR_MCR       (1 << 0)

/**@}*/

/** @defgroup hrtim_bdtxupr_values HRTIM_BDTxUPR Values
 * @ingroup hrtim_defines
 * @{
 */

/** TIMxFLTR: HRTIM_FLTxR register update enable */
#define HRTIM_BDTxUPR_TIMxFLTR  (1 << 20)

/** TIMxOUTR: HRTIM_OUTxR register update enable */
#define HRTIM_BDTxUPR_TIMxOUTR  (1 << 19)

/** TIMxCHPR: HRTIM_CHPxR register update enable */
#define HRTIM_BDTxUPR_TIMxCHPR  (1 << 18)

/** TIMxRSTR: HRTIM_RSTxR register update enable */
#define HRTIM_BDTxUPR_TIMxRSTR  (1 << 17)

/** TIMxEEFR2: HRTIM_EEFxR2 register update enable */
#define HRTIM_BDTxUPR_TIMxEEFR2 (1 << 16)

/** TIMxEEFR1: HRTIM_EEFxR1 register update enable */
#define HRTIM_BDTxUPR_TIMxEEFR1 (1 << 15)

/** TIMxRST2R: HRTIM_RST2xR register update enable */
#define HRTIM_BDTxUPR_TIMxRST2R (1 << 14)

/** TIMxSET2R: HRTIM_SET2xR register update enable */
#define HRTIM_BDTxUPR_TIMxSET2R (1 << 13)

/** TIMxRST1R: HRTIM_RST1xR register update enable */
#define HRTIM_BDTxUPR_TIMxRST1R (1 << 12)

/** TIMxSET1R: HRTIM_SET1xR register update enable */
#define HRTIM_BDTxUPR_TIMxSET1R (1 << 11)

/** TIMx_DTxR: HRTIM_DTxR register update enable */
#define HRTIM_BDTxUPR_TIMx_DTxR (1 << 10)

/** TIMxCMP4: HRTIM_CMP4xR register update enable */
#define HRTIM_BDTxUPR_TIMxCMP4  (1 << 9)

/** TIMxCMP3: HRTIM_CMP3xR register update enable */
#define HRTIM_BDTxUPR_TIMxCMP3  (1 << 8)

/** TIMxCMP2: HRTIM_CMP2xR register update enable */
#define HRTIM_BDTxUPR_TIMxCMP2  (1 << 7)

/** TIMxCMP1: HRTIM_CMP1xR register update enable */
#define HRTIM_BDTxUPR_TIMxCMP1  (1 << 6)

/** TIMxREP: HRTIM_REPxR register update enable */
#define HRTIM_BDTxUPR_TIMxREP   (1 << 5)

/** TIMxPER: HRTIM_PERxR register update enable */
#define HRTIM_BDTxUPR_TIMxPER   (1 << 4)

/** TIMxCNT: HRTIM_CNTxR register update enable */
#define HRTIM_BDTxUPR_TIMxCNT   (1 << 3)

/** TIMxDIER: HRTIM_TIMxDIER register update enable */
#define HRTIM_BDTxUPR_TIMxDIER  (1 << 2)

/** TIMxICR: HRTIM_TIMxICR register update enable */
#define HRTIM_BDTxUPR_TIMxICR   (1 << 1)

/** TIMxCR: HRTIM_TIMxCR register update enable */
#define HRTIM_BDTxUPR_TIMxCR    (1 << 0)

/**@}*/

/** @defgroup hrtim_mcr_values HRTIM_MCR Values
 * @ingroup hrtim_defines
 * @{
 */

/** BRSTDMA[31:30]: Burst DMA Update */
#define HRTIM_MCR_BRSTDMA_SHIFT 30
#define HRTIM_MCR_BRSTDMA_MASK  (0x3 << HRTIM_MCR_BRSTDMA_SHIFT)

#define HRTIM_MCR_BRSTDMA_INDEP      (0 << HRTIM_MCR_BRSTDMA_SHIFT)
#define HRTIM_MCR_BRSTDMA_COMPL      (1 << HRTIM_MCR_BRSTDMA_SHIFT)
#define HRTIM_MCR_BRSTDMA_ROLLOVR    (2 << HRTIM_MCR_BRSTDMA_SHIFT)

/** MREPU: Master Timer Repetition update */
#define HRTIM_MCR_MREPU         (1 << 29)

/** PREEN: Preload enable */
#define HRTIM_MCR_PREEN         (1 << 27)

/** DACSYNC[26:25]: AC Synchronization */
#define HRTIM_MCR_DACSYNC_SHIFT 25
#define HRTIM_MCR_DACSYNC_MASK  (0x3 << HRTIM_MCR_DACSYNC_SHIFT)

/** TECEN: Timer E counter enable */
#define HRTIM_MCR_TECEN         (1 << 21)

/** TDCEN: Timer D counter enable */
#define HRTIM_MCR_TDCEN         (1 << 20)

/** TCCEN: Timer C counter enable */
#define HRTIM_MCR_TCCEN         (1 << 19)

/** TBCEN: Timer B counter enable */
#define HRTIM_MCR_TBCEN         (1 << 18)

/** TACEN: Timer A counter enable */
#define HRTIM_MCR_TACEN         (1 << 17)

/** MCEN: Master Counter enable */
#define HRTIM_MCR_MCEN          (1 << 16)

/** SYNC_SRC[15:14]: Synchronization source */
#define HRTIM_MCR_SYNC_SRC_SHIFT 14
#define HRTIM_MCR_SYNC_SRC_MASK (0x3 << HRTIM_MCR_SYNC_SRC_SHIFT)

#define HRTIM_MCR_SYNC_SRC_MSTART         (0 << HRTIM_MCR_SYNC_SRC_SHIFT)
#define HRTIM_MCR_SYNC_SRC_MCMP1          (1 << HRTIM_MCR_SYNC_SRC_SHIFT)
#define HRTIM_MCR_SYNC_SRC_TIMA_START     (2 << HRTIM_MCR_SYNC_SRC_SHIFT)
#define HRTIM_MCR_SYNC_SRC_TIMA_CMP1      (3 << HRTIM_MCR_SYNC_SRC_SHIFT)

/** SYNC_OUT[13:12]: Synchronization output */
#define HRTIM_MCR_SYNC_OUT_SHIFT 12
#define HRTIM_MCR_SYNC_OUT_MASK (0x3 << HRTIM_MCR_SYNC_OUT_SHIFT)

#define HRTIM_MCR_SYNC_OUT_DISABLE     (0 << HRTIM_MCR_SYNC_OUT_SHIFT)
#define HRTIM_MCR_SYNC_OUT_POS         (2 << HRTIM_MCR_SYNC_OUT_SHIFT)
#define HRTIM_MCR_SYNC_OUT_NEG         (3 << HRTIM_MCR_SYNC_OUT_SHIFT)

/** SYNCSTRTM: Synchronization Starts Master */
#define HRTIM_MCR_SYNCSTRTM     (1 << 11)

/** SYNCRSTM: Synchronization Resets Master */
#define HRTIM_MCR_SYNCRSTM      (1 << 10)

/** SYNC_IN[9:8]: ynchronization input */
#define HRTIM_MCR_SYNC_IN_SHIFT 8
#define HRTIM_MCR_SYNC_IN_MASK  (0x3 << HRTIM_MCR_SYNC_IN_SHIFT)

#define HRTIM_MCR_SYNC_IN_DISABLE      (0 << HRTIM_MCR_SYNC_IN_SHIFT)
#define HRTIM_MCR_SYNC_IN_INT          (1 << HRTIM_MCR_SYNC_IN_SHIFT)
#define HRTIM_MCR_SYNC_IN_EXT          (2 << HRTIM_MCR_SYNC_IN_SHIFT)

/** HALF: Half mode enable */
#define HRTIM_MCR_HALF          (1 << 5)

/** RETRIG: Master Re-triggerable mode */
#define HRTIM_MCR_RETRIG        (1 << 4)

/** CONT: Master Continuous mode */
#define HRTIM_MCR_CONT          (1 << 3)

/** CK_PSC[2:0]: HRTIM Master Clock prescaler */
#define HRTIM_MCR_CK_PSC_SHIFT  0
#define HRTIM_MCR_CK_PSC_MASK   (0x7 << HRTIM_MCR_CK_PSC_SHIFT)

/**@}*/

/** @defgroup hrtim_misr_values HRTIM_MISR Values
 * @ingroup hrtim_defines
 * @{
 */

/** MUPD: Master Update Interrupt Flag */
#define HRTIM_MISR_MUPD         (1 << 6)

/** SYNC: Sync Input Interrupt Flag */
#define HRTIM_MISR_SYNC         (1 << 5)

/** MREP: Master Repetition Interrupt Flag */
#define HRTIM_MISR_MREP         (1 << 4)

/** MCMP4: Master Compare 4 Interrupt Flag */
#define HRTIM_MISR_MCMP4        (1 << 3)

/** MCMP3: Master Compare 3 Interrupt Flag */
#define HRTIM_MISR_MCMP3        (1 << 2)

/** MCMP2: Master Compare 2 Interrupt Flag */
#define HRTIM_MISR_MCMP2        (1 << 1)

/** MCMP1: Master Compare 1 Interrupt Flag */
#define HRTIM_MISR_MCMP1        (1 << 0)

/**@}*/

/** @defgroup hrtim_micr_values HRTIM_MICR Values
 * @ingroup hrtim_defines
 * @{
 */

/** MUPDC: Master update Interrupt flag clear */
#define HRTIM_MICR_MUPDC        (1 << 6)

/** SYNCC: Sync Input Interrupt flag clear */
#define HRTIM_MICR_SYNCC        (1 << 5)

/** MREPC: Repetition Interrupt flag clear */
#define HRTIM_MICR_MREPC        (1 << 4)

/** MCMP4C: Master Compare 4 Interrupt flag clear */
#define HRTIM_MICR_MCMP4C       (1 << 3)

/** MCMP3C: Master Compare 3 Interrupt flag clear */
#define HRTIM_MICR_MCMP3C       (1 << 2)

/** MCMP2C: Master Compare 2 Interrupt flag clear */
#define HRTIM_MICR_MCMP2C       (1 << 1)

/** MCMP1C: Master Compare 1 Interrupt flag clear */
#define HRTIM_MICR_MCMP1C       (1 << 0)

/**@}*/

/** @defgroup hrtim_mdier_values HRTIM_MDIER Values
 * @ingroup hrtim_defines
 * @{
 */

/** MUPDDE: Master Update DMA request Enable */
#define HRTIM_MDIER_MUPDDE     (1 << 22)

/** SYNCDE: Sync Input DMA request Enable */
#define HRTIM_MDIER_SYNCDE     (1 << 21)

/** MREPDE: Master Repetition DMA request Enable */
#define HRTIM_MDIER_MREPDE     (1 << 20)

/** MCMP4DE: Master Compare 4 DMA request Enable */
#define HRTIM_MDIER_MCMP4DE    (1 << 19)

/** MCMP3DE: Master Compare 3 DMA request Enable */
#define HRTIM_MDIER_MCMP3DE    (1 << 18)

/** MCMP2DE: Master Compare 2 DMA request Enable */
#define HRTIM_MDIER_MCMP2DE    (1 << 17)

/** MCMP1DE: Master Compare 1 DMA request Enable */
#define HRTIM_MDIER_MCMP1DE    (1 << 16)

/** MUPDIE: Master Update Interrupt Enable */
#define HRTIM_MDIER_MUPDIE     (1 << 6)

/** SYNCIE: Sync Input Interrupt Enable */
#define HRTIM_MDIER_SYNCIE     (1 << 5)

/** MREPIE: Master Repetition Interrupt Enable */
#define HRTIM_MDIER_MREPIE     (1 << 4)

/** MCMP4IE: Master Compare 4 Interrupt Enable */
#define HRTIM_MDIER_MCMP4IE    (1 << 3)

/** MCMP3IE: Master Compare 3 Interrupt Enable */
#define HRTIM_MDIER_MCMP3IE    (1 << 2)

/** MCMP2IE: Master Compare 2 Interrupt Enable */
#define HRTIM_MDIER_MCMP2IE    (1 << 1)

/** MCMP1IE: Master Compare 1 Interrupt Enable */
#define HRTIM_MDIER_MCMP1IE    (1 << 0)

/**@}*/

/** @defgroup hrtim_timxcr_values HRTIM_TIMxCR Values
 * @ingroup hrtim_defines
 * @{
 */

/** UPDGAT[31:28]: Update Gating */
#define HRTIM_TIMx_CR_UPDGAT_SHIFT    28
#define HRTIM_TIMx_CR_UPDGAT_MASK     (0xf << HRTIM_TIMx_CR_UPDGAT_SHIFT)

#define HRTIM_TIMx_CR_UPDGAT_INDEP         (0 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_DMA           (1 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_DMA_POST      (2 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_IN1           (3 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_IN2           (4 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_IN3           (5 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_IN1_POST      (6 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_IN2_POST      (7 << HRTIM_TIMx_CR_UPDGAT_SHIFT)
#define HRTIM_TIMx_CR_UPDGAT_IN3_POST      (8 << HRTIM_TIMx_CR_UPDGAT_SHIFT)

/** PREEN: Preload enable */
#define HRTIM_TIMx_CR_PREEN           (1 << 27)

/** DACSYNC[26:25]: DAC Synchronization */
#define HRTIM_TIMx_CR_DACSYNC_SHIFT   25
#define HRTIM_TIMx_CR_DACSYNC_MASK    (0x3 << HRTIM_TIMx_CR_DACSYNC_SHIFT)

#define HRTIM_TIMx_CR_DACSYNC_NONE        (0 << HRTIM_TIMx_CR_DACSYNC_SHIFT)
#define HRTIM_TIMx_CR_DACSYNC_1           (1 << HRTIM_TIMx_CR_DACSYNC_SHIFT)
#define HRTIM_TIMx_CR_DACSYNC_2           (2 << HRTIM_TIMx_CR_DACSYNC_SHIFT)
#define HRTIM_TIMx_CR_DACSYNC_3           (3 << HRTIM_TIMx_CR_DACSYNC_SHIFT)

/** MSTU: Master Timer update */
#define HRTIM_TIMx_CR_MSTU            (1 << 24)

/** TEU: Timer E update */
#define HRTIM_TIMx_CR_TEU             (1 << 23)

/** TDU: Timer D update */
#define HRTIM_TIMx_CR_TDU             (1 << 22)

/** TCU: Timer C update */
#define HRTIM_TIMx_CR_TCU             (1 << 21)

/** TBU: Timer B update */
#define HRTIM_TIMx_CR_TBU             (1 << 20)

/** TxRSTU: Timer x reset update */
#define HRTIM_TIMx_CR_TxRSTU          (1 << 18)

/** TxREPU: Timer x Repetition update */
#define HRTIM_TIMx_CR_TxREPU          (1 << 17)

/** DELCMP4[15:14]: CMP4 auto-delayed mode */
#define HRTIM_TIMx_CR_DELCMP4_SHIFT   14
#define HRTIM_TIMx_CR_DELCMP4_MASK    (0x3 << HRTIM_TIMx_CR_DELCMP4_SHIFT)

#define HRTIM_TIMx_CR_DELCMP4_ALWAYS        (0 << HRTIM_TIMx_CR_DELCMP4_SHIFT)
#define HRTIM_TIMx_CR_DELCMP4_CAP2          (1 << HRTIM_TIMx_CR_DELCMP4_SHIFT)
#define HRTIM_TIMx_CR_DELCMP4_CAP2_COMP1    (2 << HRTIM_TIMx_CR_DELCMP4_SHIFT)
#define HRTIM_TIMx_CR_DELCMP4_CAP2_COMP3    (3 << HRTIM_TIMx_CR_DELCMP4_SHIFT)

/** DELCMP2[13:12]: CMP2 auto-delayed mode */
#define HRTIM_TIMx_CR_DELCMP2_SHIFT   12
#define HRTIM_TIMx_CR_DELCMP2_MASK    (0x3 << HRTIM_TIMx_CR_DELCMP2_SHIFT)

#define HRTIM_TIMx_CR_DELCMP2_ALWAYS        (0x << HRTIM_TIMx_CR_DELCMP2_SHIFT)
#define HRTIM_TIMx_CR_DELCMP2_CAP1          (0x << HRTIM_TIMx_CR_DELCMP2_SHIFT)
#define HRTIM_TIMx_CR_DELCMP2_CAP1_COMP1    (0x << HRTIM_TIMx_CR_DELCMP2_SHIFT)
#define HRTIM_TIMx_CR_DELCMP2_CAP1_COMP3    (0x << HRTIM_TIMx_CR_DELCMP2_SHIFT)

/** SYNCSTRTx: Synchronization Starts Timer x */
#define HRTIM_TIMx_CR_SYNCSTRTx       (1 << 11)

/** SYNCRSTx: Synchronization Resets Timer x */
#define HRTIM_TIMx_CR_SYNCRSTx        (1 << 10)

/** PSHPLL: Push-Pull mode enable */
#define HRTIM_TIMx_CR_PSHPLL          (1 << 6)

/** HALF: Half mode enable */
#define HRTIM_TIMx_CR_HALF            (1 << 5)

/** RETRIG: Re-triggerable mode */
#define HRTIM_TIMx_CR_RETRIG          (1 << 4)

/** CONT: Continuous mode */
#define HRTIM_TIMx_CR_CONT            (1 << 3)

/** CK_PSCx[2:0]: HRTIM Timer x Clock prescaler */
#define HRTIM_TIMx_CR_CK_PSCx_SHIFT   0
#define HRTIM_TIMx_CR_CK_PSCx_MASK    (0x7 << HRTIM_TIMx_CR_CK_PSCx_SHIFT)

/**@}*/

/** @defgroup hrtim_timxisr_values HRTIM_TIMxISR Values
 * @ingroup hrtim_defines
 * @{
 */

/** O2STAT: Output 2 State */
#define HRTIM_TIMx_ISR_O2STAT          (1 << 19)

/** O1STAT: Output 1 State */
#define HRTIM_TIMx_ISR_O1STAT          (1 << 18)

/** IPPSTAT: Idle Push Pull Status */
#define HRTIM_TIMx_ISR_IPPSTAT         (1 << 17)

/** CPPSTAT: Current Push Pull Status */
#define HRTIM_TIMx_ISR_CPPSTAT         (1 << 16)

/** DLYPRT: Delayed Protection Flag */
#define HRTIM_TIMx_ISR_DLYPRT          (1 << 14)

/** RST: Reset Interrupt Flag */
#define HRTIM_TIMx_ISR_RST             (1 << 13)

/** RSTx2: Output 2 Reset Interrupt Flag */
#define HRTIM_TIMx_ISR_RSTx2           (1 << 12)

/** SETx2: Output 2 Set Interrupt Flag */
#define HRTIM_TIMx_ISR_SETx2           (1 << 11)

/** RSTx1: Output 1 Reset Interrupt Flag */
#define HRTIM_TIMx_ISR_RSTx1           (1 << 10)

/** SETx1: Output 1 Set Interrupt Flag */
#define HRTIM_TIMx_ISR_SETx1           (1 << 9)

/** CPT2: Capture2 Interrupt Flag */
#define HRTIM_TIMx_ISR_CPT2            (1 << 8)

/** CPT1: Capture1 Interrupt Flag */
#define HRTIM_TIMx_ISR_CPT1            (1 << 7)

/** UPD: Update Interrupt Flag */
#define HRTIM_TIMx_ISR_UPD             (1 << 6)

/** REP: Repetition Interrupt Flag */
#define HRTIM_TIMx_ISR_REP             (1 << 4)

/** CMP4: Compare 4 Interrupt Flag */
#define HRTIM_TIMx_ISR_CMP4            (1 << 3)

/** CMP3: Compare 3 Interrupt Flag */
#define HRTIM_TIMx_ISR_CMP3            (1 << 2)

/** CMP2: Compare 2 Interrupt Flag */
#define HRTIM_TIMx_ISR_CMP2            (1 << 1)

/** CMP1: Compare 1 Interrupt Flag */
#define HRTIM_TIMx_ISR_CMP1            (1 << 0)

/**@}*/

/** @defgroup hrtim_timxicr_values HRTIM_TIMxICR Values
 * @ingroup hrtim_defines
 * @{
 */

/** DLYPRTC: Delayed Protection Flag Clear */
#define HRTIM_TIMx_ICR_DLYPRTC       (1 << 14)

/** RSTC: Reset Interrupt flag Clear */
#define HRTIM_TIMx_ICR_RSTC          (1 << 13)

/** RSTx2C: Output 2 Reset flag Clear */
#define HRTIM_TIMx_ICR_RSTx2C        (1 << 12)

/** SET2xC: Output 2 Set flag Clear */
#define HRTIM_TIMx_ICR_SET2xC        (1 << 11)

/** RSTx1C: Output 1 Reset flag Clear */
#define HRTIM_TIMx_ICR_RSTx1C        (1 << 10)

/** SET1xC: Output 1 Set flag Clear */
#define HRTIM_TIMx_ICR_SET1xC        (1 << 9)

/** CPT2C: Capture2 Interrupt flag Clear */
#define HRTIM_TIMx_ICR_CPT2C         (1 << 8)

/** CPT1C: Capture1 Interrupt flag Clear */
#define HRTIM_TIMx_ICR_CPT1C         (1 << 7)

/** UPDC: Update Interrupt flag Clear */
#define HRTIM_TIMx_ICR_UPDC          (1 << 6)

/** REPC: Repetition Interrupt flag Clear */
#define HRTIM_TIMx_ICR_REPC          (1 << 4)

/** CMP4C: Compare 4 Interrupt flag Clear */
#define HRTIM_TIMx_ICR_CMP4C         (1 << 3)

/** CMP3C: Compare 3 Interrupt flag Clear */
#define HRTIM_TIMx_ICR_CMP3C         (1 << 2)

/** CMP2C: Compare 2 Interrupt flag Clear */
#define HRTIM_TIMx_ICR_CMP2C         (1 << 1)

/** CMP1C: Compare 1 Interrupt flag Clear */
#define HRTIM_TIMx_ICR_CMP1C         (1 << 0)

/**@}*/

/** @defgroup hrtim_timxdier_values HRTIM_TIMxDIER Values
 * @ingroup hrtim_defines
 * @{
 */

/** DLYPRTDE: Delay Protection DMA request Enable */
#define HRTIM_TIMx_DIER_DLYPRTDE      (1 << 30)

/** RSTDE: Reset/roll-over DMA request Enable */
#define HRTIM_TIMx_DIER_RSTDE         (1 << 29)

/** RSTx2DE: Output 2 Reset DMA request Enable */
#define HRTIM_TIMx_DIER_RSTx2DE       (1 << 28)

/** SETx2DE: Output 2 Set DMA request Enable */
#define HRTIM_TIMx_DIER_SETx2DE       (1 << 27)

/** RSTx1DE: Output 1 Reset DMA request Enable */
#define HRTIM_TIMx_DIER_RSTx1DE       (1 << 26)

/** SET1xDE: Output 1 Set DMA request Enable*/
#define HRTIM_TIMx_DIER_SET1xDE       (1 << 25)

/** CPT2DE: Capture 2 DMA request Enable */
#define HRTIM_TIMx_DIER_CPT2DE        (1 << 24)

/** CPT1DE: Capture 1 DMA request Enable */
#define HRTIM_TIMx_DIER_CPT1DE        (1 << 23)

/** UPDDE: Update DMA request Enable */
#define HRTIM_TIMx_DIER_UPDDE         (1 << 22)

/** REPDE: Repetition DMA request Enable */
#define HRTIM_TIMx_DIER_REPDE         (1 << 20)

/** CMP4DE: Compare 4 DMA request Enable */
#define HRTIM_TIMx_DIER_CMP4DE        (1 << 19)

/** CMP3DE: Compare 3 DMA request Enable */
#define HRTIM_TIMx_DIER_CMP3DE        (1 << 18)

/** CMP2DE: Compare 2 DMA request Enable */
#define HRTIM_TIMx_DIER_CMP2DE        (1 << 17)

/** CMP1DE: Compare 1 DMA request Enable */
#define HRTIM_TIMx_DIER_CMP1DE        (1 << 16)

/** DLYPRTIE: Delay Protection Interrupt Enable */
#define HRTIM_TIMx_DIER_DLYPRTIE      (1 << 14)

/** RSTIE: Reset/roll-over Interrupt Enable */
#define HRTIM_TIMx_DIER_RSTIE         (1 << 13)

/** RSTx2IE: Output 2 Reset Interrupt Enable */
#define HRTIM_TIMx_DIER_RSTx2IE       (1 << 12)

/** SETx2IE: Output 2 Set Interrupt Enable */
#define HRTIM_TIMx_DIER_SETx2IE       (1 << 11)

/** RSTx1IE: Output 1 Reset Interrupt Enable */
#define HRTIM_TIMx_DIER_RSTx1IE       (1 << 10)

/** SET1xIE: Output 1 Set Interrupt Enable */
#define HRTIM_TIMx_DIER_SET1xIE       (1 << 9)

/** CPT2IE: Capture 2 Interrupt Enable */
#define HRTIM_TIMx_DIER_CPT2IE        (1 << 8)

/** CPT1IE: Capture 1 Interrupt Enable */
#define HRTIM_TIMx_DIER_CPT1IE        (1 << 7)

/** UPDIE: Update Interrupt Enable */
#define HRTIM_TIMx_DIER_UPDIE         (1 << 6)

/** REPIE: Repetition Interrupt Enable */
#define HRTIM_TIMx_DIER_REPIE         (1 << 4)

/** CMP4IE: Compare 4 Interrupt Enable */
#define HRTIM_TIMx_DIER_CMP4IE        (1 << 3)

/** CMP3IE: Compare 3 Interrupt Enable */
#define HRTIM_TIMx_DIER_CMP3IE        (1 << 2)

/** CMP2IE: Compare 2 Interrupt Enable */
#define HRTIM_TIMx_DIER_CMP2IE        (1 << 1)

/** CMP1IE: Compare 1 Interrupt Enable */
#define HRTIM_TIMx_DIER_CMP1IE        (1 << 0)

/**@}*/

/** @defgroup hrtim_timxcmp1c_values HRTIM_TIMxCMP1C Values
 * @ingroup hrtim_defines
 * @{
 */

/** REPx[23:16]: Timerx Repetition value (aliased from HRTIM_REPx register) */
#define HRTIM_TIMx_CMP1C_REPx_SHIFT    16
#define HRTIM_TIMx_CMP1C_REPx_MASK     (0xff << HRTIM_TIMx_CMP1C_REPx_SHIFT)

/** CMP1x[15:0]: Timerx Compare 1 value */
#define HRTIM_TIMx_CMP1C_CMP1x_SHIFT   0
#define HRTIM_TIMx_CMP1C_CMP1x_MASK    (0xffff << HRTIM_TIMx_CMP1C_CMP1x_SHIFT)

/**@}*/

/** @defgroup hrtim_timxdt_values HRTIM_TIMxDT Values
 * @ingroup hrtim_defines
 * @{
 */

/** DTFLKx: Deadtime Falling Lock */
#define HRTIM_TIMx_DT_DTFLKx           (1 << 31)

/** DTFSLKx: Deadtime Falling Sign Lock */
#define HRTIM_TIMx_DT_DTFSLKx          (1 << 30)

/** SDTFx: Sign Deadtime Falling value */
#define HRTIM_TIMx_DT_SDTFx            (1 << 25)

/** DTFx[24:16]: Deadtime Falling value */
#define HRTIM_TIMx_DT_DTFx_SHIFT       16
#define HRTIM_TIMx_DT_DTFx_MASK        (0x1ff << HRTIM_TIMx_DT_DTFx_SHIFT)

/** DTRLKx: Deadtime Rising Lock */
#define HRTIM_TIMx_DT_DTRLKx           (1 << 15)

/** DTRSLKx: Deadtime Rising Sign Lock */
#define HRTIM_TIMx_DT_DTRSLKx          (1 << 14)

/** DTPRSC[12:10]: Deadtime Prescaler */
#define HRTIM_TIMx_DT_DTPRSC_SHIFT     10
#define HRTIM_TIMx_DT_DTPRSC_MASK      (0x7 << HRTIM_TIMx_DT_DTPRSC_SHIFT)

/** SDTRx: Sign Deadtime Rising value */
#define HRTIM_TIMx_DT_SDTRx            (1 << 9)

/** DTRx[8:0]: Deadtime Rising value */
#define HRTIM_TIMx_DT_DTRx_SHIFT       0
#define HRTIM_TIMx_DT_DTRx_MASK        (0x1ff << HRTIM_TIMx_DT_DTRx_SHIFT)

/**@}*/

/** @defgroup hrtim_timxsety_values HRTIM_TIMxSETy Values
 * @ingroup hrtim_defines
 * @{
 */

/** UPDATE: Registers update (transfer preload to active) */
#define HRTIM_TIMx_SETy_UPDATE         (1 << 31)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIMx_SETy_EXTEVNT10      (1 << 30)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIMx_SETy_EXTEVNT9       (1 << 29)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIMx_SETy_EXTEVNT8       (1 << 28)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIMx_SETy_EXTEVNT7       (1 << 27)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIMx_SETy_EXTEVNT6       (1 << 26)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIMx_SETy_EXTEVNT5       (1 << 25)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIMx_SETy_EXTEVNT4       (1 << 24)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIMx_SETy_EXTEVNT3       (1 << 23)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIMx_SETy_EXTEVNT2       (1 << 22)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIMx_SETy_EXTEVNT1       (1 << 21)

/** TIMEVNT9: Timer Event 9 */
#define HRTIM_TIMx_SETy_TIMEVNT9       (1 << 20)

/** TIMEVNT8: Timer Event 8 */
#define HRTIM_TIMx_SETy_TIMEVNT8       (1 << 19)

/** TIMEVNT7: Timer Event 7 */
#define HRTIM_TIMx_SETy_TIMEVNT7       (1 << 18)

/** TIMEVNT6: Timer Event 6 */
#define HRTIM_TIMx_SETy_TIMEVNT6       (1 << 17)

/** TIMEVNT5: Timer Event 5 */
#define HRTIM_TIMx_SETy_TIMEVNT5       (1 << 16)

/** TIMEVNT4: Timer Event 4 */
#define HRTIM_TIMx_SETy_TIMEVNT4       (1 << 15)

/** TIMEVNT3: Timer Event 3 */
#define HRTIM_TIMx_SETy_TIMEVNT3       (1 << 14)

/** TIMEVNT2: Timer Event 2 */
#define HRTIM_TIMx_SETy_TIMEVNT2       (1 << 13)

/** TIMEVNT1: Timer Event 1 */
#define HRTIM_TIMx_SETy_TIMEVNT1       (1 << 12)

/** MSTCMP4: Master Compare 4 */
#define HRTIM_TIMx_SETy_MSTCMP4        (1 << 11)

/** MSTCMP3: Master Compare 3 */
#define HRTIM_TIMx_SETy_MSTCMP3        (1 << 10)

/** MSTCMP2: Master Compare 2 */
#define HRTIM_TIMx_SETy_MSTCMP2        (1 << 9)

/** MSTCMP1: Master Compare 1 */
#define HRTIM_TIMx_SETy_MSTCMP1        (1 << 8)

/** MSTPER: Master Period */
#define HRTIM_TIMx_SETy_MSTPER         (1 << 7)

/** CMP4: Timer x compare 4 */
#define HRTIM_TIMx_SETy_CMP4           (1 << 6)

/** CMP3: Timer x compare 3 */
#define HRTIM_TIMx_SETy_CMP3           (1 << 5)

/** CMP2: Timer x compare 2 */
#define HRTIM_TIMx_SETy_CMP2           (1 << 4)

/** CMP1: Timer x compare 1 */
#define HRTIM_TIMx_SETy_CMP1           (1 << 3)

/** PER: Timer x Period */
#define HRTIM_TIMx_SETy_PER            (1 << 2)

/** RESYNC: Timer x resynchronizaton */
#define HRTIM_TIMx_SETy_RESYNC         (1 << 1)

/** SST: Software Set trigger */
#define HRTIM_TIMx_SETy_SST            (1 << 0)

/**@}*/

/** @defgroup hrtim_timxrsty_values HRTIM_TIMxRSTy Values
 * @ingroup hrtim_defines
 * @{
 */

/** UPDATE: Registers update (transfer preload to active) */
#define HRTIM_TIMx_RSTy_UPDATE         (1 << 31)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIMx_RSTy_EXTEVNT10      (1 << 30)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIMx_RSTy_EXTEVNT9       (1 << 29)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIMx_RSTy_EXTEVNT8       (1 << 28)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIMx_RSTy_EXTEVNT7       (1 << 27)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIMx_RSTy_EXTEVNT6       (1 << 26)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIMx_RSTy_EXTEVNT5       (1 << 25)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIMx_RSTy_EXTEVNT4       (1 << 24)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIMx_RSTy_EXTEVNT3       (1 << 23)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIMx_RSTy_EXTEVNT2       (1 << 22)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIMx_RSTy_EXTEVNT1       (1 << 21)

/** TIMEVNT9: Timer Event 9 */
#define HRTIM_TIMx_RSTy_TIMEVNT9       (1 << 20)

/** TIMEVNT8: Timer Event 8 */
#define HRTIM_TIMx_RSTy_TIMEVNT8       (1 << 19)

/** TIMEVNT7: Timer Event 7 */
#define HRTIM_TIMx_RSTy_TIMEVNT7       (1 << 18)

/** TIMEVNT6: Timer Event 6 */
#define HRTIM_TIMx_RSTy_TIMEVNT6       (1 << 17)

/** TIMEVNT5: Timer Event 5 */
#define HRTIM_TIMx_RSTy_TIMEVNT5       (1 << 16)

/** TIMEVNT4: Timer Event 4 */
#define HRTIM_TIMx_RSTy_TIMEVNT4       (1 << 15)

/** TIMEVNT3: Timer Event 3 */
#define HRTIM_TIMx_RSTy_TIMEVNT3       (1 << 14)

/** TIMEVNT2: Timer Event 2 */
#define HRTIM_TIMx_RSTy_TIMEVNT2       (1 << 13)

/** TIMEVNT1: Timer Event 1 */
#define HRTIM_TIMx_RSTy_TIMEVNT1       (1 << 12)

/** MSTCMP4: Master Compare 4 */
#define HRTIM_TIMx_RSTy_MSTCMP4        (1 << 11)

/** MSTCMP3: Master Compare 3 */
#define HRTIM_TIMx_RSTy_MSTCMP3        (1 << 10)

/** MSTCMP2: Master Compare 2 */
#define HRTIM_TIMx_RSTy_MSTCMP2        (1 << 9)

/** MSTCMP1: Master Compare 1 */
#define HRTIM_TIMx_RSTy_MSTCMP1        (1 << 8)

/** MSTPER: Master Period */
#define HRTIM_TIMx_RSTy_MSTPER         (1 << 7)

/** CMP4: Timer x compare 4 */
#define HRTIM_TIMx_RSTy_CMP4           (1 << 6)

/** CMP3: Timer x compare 3 */
#define HRTIM_TIMx_RSTy_CMP3           (1 << 5)

/** CMP2: Timer x compare 2 */
#define HRTIM_TIMx_RSTy_CMP2           (1 << 4)

/** CMP1: Timer x compare 1 */
#define HRTIM_TIMx_RSTy_CMP1           (1 << 3)

/** PER: Timer x Period */
#define HRTIM_TIMx_RSTy_PER            (1 << 2)

/** RESYNC: Timer x resynchronizaton */
#define HRTIM_TIMx_RSTy_RESYNC         (1 << 1)

/** SST: Software Reset trigger */
#define HRTIM_TIMx_RSTy_SRT            (1 << 0)

/**@}*/

/** @defgroup hrtim_timxeef1_values HRTIM_TIMxEEF1 Values
 * @ingroup hrtim_defines
 * @{
 */

/** EExFLTR:25]: External Event x filter */
#define HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x)      ((x) * 6 - 5)
#define HRTIM_TIMx_EEF1_EExFLTR_MASK(x)       (0xf << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))

#define HRTIM_TIMx_EEF1_EExFLTR_NONE(x)           ( 0 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_CMP1(x)           ( 1 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_CMP2(x)           ( 2 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_CMP3(x)           ( 3 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_CMP4(x)           ( 4 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR1(x)       ( 5 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR2(x)       ( 6 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR3(x)       ( 7 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR4(x)       ( 8 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR5(x)       ( 9 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR6(x)       (10 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR7(x)       (11 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMFLTR8(x)       (12 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_WND_CMP2(x)       (13 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_WND_CMP3(x)       (14 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF1_EExFLTR_TIMWIN(x)         (15 << HRTIM_TIMx_EEF1_EExFLTR_SHIFT(x))

/** EExLTCH: External Event x latch */
#define HRTIM_TIMx_EEF1_EExLTCH            (1 << ((x) * 6 - 6))

/**@}*/

/** @defgroup hrtim_timxeef2_values HRTIM_TIMxEEF2 Values
 * @ingroup hrtim_defines
 * @{
 */

/** EExFLTR:25]: External Event x filter */
#define HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x)      (((x) - 6) * 6 + 1)
#define HRTIM_TIMx_EEF2_EExFLTR_MASK(x)       (0xf << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))

#define HRTIM_TIMx_EEF2_EExFLTR_NONE(x)           ( 0 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_CMP1(x)           ( 1 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_CMP2(x)           ( 2 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_CMP3(x)           ( 3 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_CMP4(x)           ( 4 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR1(x)       ( 5 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR2(x)       ( 6 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR3(x)       ( 7 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR4(x)       ( 8 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR5(x)       ( 9 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR6(x)       (10 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR7(x)       (11 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMFLTR8(x)       (12 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_WND_CMP2(x)       (13 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_WND_CMP3(x)       (14 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))
#define HRTIM_TIMx_EEF2_EExFLTR_TIMWIN(x)         (15 << HRTIM_TIMx_EEF2_EExFLTR_SHIFT(x))

/** EExLTCH: External Event x latch */
#define HRTIM_TIMx_EEF2_EExLTCH            (1 << (((x) - 6) * 6))

/**@}*/

/** @defgroup hrtim_timarst_values HRTIM_TIMA_RST Values
 * @ingroup hrtim_defines
 * Only bits 30:19 differ between TIMx_RST registers.
 * @sa hrtim_timarst_values
 * @sa hrtim_timbrst_values
 * @sa hrtim_timcrst_values
 * @sa hrtim_timdrst_values
 * @sa hrtim_timerst_values
 * @{
 */

/** TIMECMP4: Timer E Compare 4 */
#define HRTIM_TIMA_RST_TIMECMP4        (1 << 30)

/** TIMECMP2: Timer E Compare 2 */
#define HRTIM_TIMA_RST_TIMECMP2        (1 << 29)

/** TIMECMP1: Timer E Compare 1 */
#define HRTIM_TIMA_RST_TIMECMP1        (1 << 28)

/** TIMDCMP4: Timer D Compare 4 */
#define HRTIM_TIMA_RST_TIMDCMP4        (1 << 27)

/** TIMDCMP2: Timer D Compare 2 */
#define HRTIM_TIMA_RST_TIMDCMP2        (1 << 26)

/** TIMDCMP1: Timer D Compare 1 */
#define HRTIM_TIMA_RST_TIMDCMP1        (1 << 25)

/** TIMCCMP4: Timer C Compare 4 */
#define HRTIM_TIMA_RST_TIMCCMP4        (1 << 24)

/** TIMCCMP2: Timer C Compare 2 */
#define HRTIM_TIMA_RST_TIMCCMP2        (1 << 23)

/** TIMCCMP1: Timer C Compare 1 */
#define HRTIM_TIMA_RST_TIMCCMP1        (1 << 22)

/** TIMBCMP4: Timer B Compare 4 */
#define HRTIM_TIMA_RST_TIMBCMP4        (1 << 21)

/** TIMBCMP2: Timer B Compare 2 */
#define HRTIM_TIMA_RST_TIMBCMP2        (1 << 20)

/** TIMBCMP1: Timer B Compare 1 */
#define HRTIM_TIMA_RST_TIMBCMP1        (1 << 19)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIMA_RST_EXTEVNT10       (1 << 18)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIMA_RST_EXTEVNT9        (1 << 17)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIMA_RST_EXTEVNT8        (1 << 16)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIMA_RST_EXTEVNT7        (1 << 15)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIMA_RST_EXTEVNT6        (1 << 14)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIMA_RST_EXTEVNT5        (1 << 13)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIMA_RST_EXTEVNT4        (1 << 12)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIMA_RST_EXTEVNT3        (1 << 11)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIMA_RST_EXTEVNT2        (1 << 10)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIMA_RST_EXTEVNT1        (1 << 9)

/** MSTCMP4: Master compare 4 */
#define HRTIM_TIMA_RST_MSTCMP4         (1 << 8)

/** MSTCMP3: Master compare 3 */
#define HRTIM_TIMA_RST_MSTCMP3         (1 << 7)

/** MSTCMP2: Master compare 2 */
#define HRTIM_TIMA_RST_MSTCMP2         (1 << 6)

/** MSTCMP1: Master compare 1 */
#define HRTIM_TIMA_RST_MSTCMP1         (1 << 5)

/** MSTPER: Master timer Period */
#define HRTIM_TIMA_RST_MSTPER          (1 << 4)

/** CMP4: Timer A compare 4 reset */
#define HRTIM_TIMA_RST_CMP4            (1 << 3)

/** CMP2: Timer A compare 2 reset */
#define HRTIM_TIMA_RST_CMP2            (1 << 2)

/** UPDT: Timer A Update reset */
#define HRTIM_TIMA_RST_UPDT            (1 << 1)

/**@}*/

/** @defgroup hrtim_timbrst_values HRTIM_TIMB_RST Values
 * @ingroup hrtim_defines
 * Only bits 30:19 differ between TIMx_RST registers.
 * @sa hrtim_timarst_values
 * @sa hrtim_timbrst_values
 * @sa hrtim_timcrst_values
 * @sa hrtim_timdrst_values
 * @sa hrtim_timerst_values
 * @{
 */

/** TIMECMP4: Timer E Compare 4 */
#define HRTIM_TIMB_RST_TIMECMP4        (1 << 30)

/** TIMECMP2: Timer E Compare 2 */
#define HRTIM_TIMB_RST_TIMECMP2        (1 << 29)

/** TIMECMP1: Timer E Compare 1 */
#define HRTIM_TIMB_RST_TIMECMP1        (1 << 28)

/** TIMDCMP4: Timer D Compare 4 */
#define HRTIM_TIMB_RST_TIMDCMP4        (1 << 27)

/** TIMDCMP2: Timer D Compare 2 */
#define HRTIM_TIMB_RST_TIMDCMP2        (1 << 26)

/** TIMDCMP1: Timer D Compare 1 */
#define HRTIM_TIMB_RST_TIMDCMP1        (1 << 25)

/** TIMCCMP4: Timer C Compare 4 */
#define HRTIM_TIMB_RST_TIMCCMP4        (1 << 24)

/** TIMCCMP2: Timer C Compare 2 */
#define HRTIM_TIMB_RST_TIMCCMP2        (1 << 23)

/** TIMCCMP1: Timer C Compare 1 */
#define HRTIM_TIMB_RST_TIMCCMP1        (1 << 22)

/** TIMACMP4: Timer A Compare 4 */
#define HRTIM_TIMB_RST_TIMACMP4        (1 << 21)

/** TIMACMP2: Timer A Compare 2 */
#define HRTIM_TIMB_RST_TIMACMP2        (1 << 20)

/** TIMACMP1: Timer A Compare 1 */
#define HRTIM_TIMB_RST_TIMACMP1        (1 << 19)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIMB_RST_EXTEVNT10       (1 << 18)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIMB_RST_EXTEVNT9        (1 << 17)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIMB_RST_EXTEVNT8        (1 << 16)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIMB_RST_EXTEVNT7        (1 << 15)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIMB_RST_EXTEVNT6        (1 << 14)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIMB_RST_EXTEVNT5        (1 << 13)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIMB_RST_EXTEVNT4        (1 << 12)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIMB_RST_EXTEVNT3        (1 << 11)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIMB_RST_EXTEVNT2        (1 << 10)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIMB_RST_EXTEVNT1        (1 << 9)

/** MSTCMP4: Master compare 4 */
#define HRTIM_TIMB_RST_MSTCMP4         (1 << 8)

/** MSTCMP3: Master compare 3 */
#define HRTIM_TIMB_RST_MSTCMP3         (1 << 7)

/** MSTCMP2: Master compare 2 */
#define HRTIM_TIMB_RST_MSTCMP2         (1 << 6)

/** MSTCMP1: Master compare 1 */
#define HRTIM_TIMB_RST_MSTCMP1         (1 << 5)

/** MSTPER: Master timer Period */
#define HRTIM_TIMB_RST_MSTPER          (1 << 4)

/** CMP4: Timer A compare 4 reset */
#define HRTIM_TIMB_RST_CMP4            (1 << 3)

/** CMP2: Timer A compare 2 reset */
#define HRTIM_TIMB_RST_CMP2            (1 << 2)

/** UPDT: Timer A Update reset */
#define HRTIM_TIMB_RST_UPDT            (1 << 1)

/**@}*/

/** @defgroup hrtim_timcrst_values HRTIM_TIMC_RST Values
 * @ingroup hrtim_defines
 * Only bits 30:19 differ between TIMx_RST registers.
 * @sa hrtim_timarst_values
 * @sa hrtim_timbrst_values
 * @sa hrtim_timcrst_values
 * @sa hrtim_timdrst_values
 * @sa hrtim_timerst_values
 * @{
 */

/** TIMECMP4: Timer E Compare 4 */
#define HRTIM_TIMC_RST_TIMECMP4        (1 << 30)

/** TIMECMP2: Timer E Compare 2 */
#define HRTIM_TIMC_RST_TIMECMP2        (1 << 29)

/** TIMECMP1: Timer E Compare 1 */
#define HRTIM_TIMC_RST_TIMECMP1        (1 << 28)

/** TIMDCMP4: Timer D Compare 4 */
#define HRTIM_TIMC_RST_TIMDCMP4        (1 << 27)

/** TIMDCMP2: Timer D Compare 2 */
#define HRTIM_TIMC_RST_TIMDCMP2        (1 << 26)

/** TIMDCMP1: Timer D Compare 1 */
#define HRTIM_TIMC_RST_TIMDCMP1        (1 << 25)

/** TIMBCMP4: Timer B Compare 4 */
#define HRTIM_TIMC_RST_TIMBCMP4        (1 << 24)

/** TIMBCMP2: Timer B Compare 2 */
#define HRTIM_TIMC_RST_TIMBCMP2        (1 << 23)

/** TIMBCMP1: Timer B Compare 1 */
#define HRTIM_TIMC_RST_TIMBCMP1        (1 << 22)

/** TIMACMP4: Timer A Compare 4 */
#define HRTIM_TIMC_RST_TIMACMP4        (1 << 21)

/** TIMACMP2: Timer A Compare 2 */
#define HRTIM_TIMC_RST_TIMACMP2        (1 << 20)

/** TIMACMP1: Timer A Compare 1 */
#define HRTIM_TIMC_RST_TIMACMP1        (1 << 19)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIMC_RST_EXTEVNT10       (1 << 18)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIMC_RST_EXTEVNT9        (1 << 17)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIMC_RST_EXTEVNT8        (1 << 16)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIMC_RST_EXTEVNT7        (1 << 15)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIMC_RST_EXTEVNT6        (1 << 14)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIMC_RST_EXTEVNT5        (1 << 13)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIMC_RST_EXTEVNT4        (1 << 12)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIMC_RST_EXTEVNT3        (1 << 11)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIMC_RST_EXTEVNT2        (1 << 10)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIMC_RST_EXTEVNT1        (1 << 9)

/** MSTCMP4: Master compare 4 */
#define HRTIM_TIMC_RST_MSTCMP4         (1 << 8)

/** MSTCMP3: Master compare 3 */
#define HRTIM_TIMC_RST_MSTCMP3         (1 << 7)

/** MSTCMP2: Master compare 2 */
#define HRTIM_TIMC_RST_MSTCMP2         (1 << 6)

/** MSTCMP1: Master compare 1 */
#define HRTIM_TIMC_RST_MSTCMP1         (1 << 5)

/** MSTPER: Master timer Period */
#define HRTIM_TIMC_RST_MSTPER          (1 << 4)

/** CMP4: Timer A compare 4 reset */
#define HRTIM_TIMC_RST_CMP4            (1 << 3)

/** CMP2: Timer A compare 2 reset */
#define HRTIM_TIMC_RST_CMP2            (1 << 2)

/** UPDT: Timer A Update reset */
#define HRTIM_TIMC_RST_UPDT            (1 << 1)

/**@}*/

/** @defgroup hrtim_timdrst_values HRTIM_TIMD_RST Values
 * @ingroup hrtim_defines
 * Only bits 30:19 differ between TIMx_RST registers.
 * @sa hrtim_timarst_values
 * @sa hrtim_timbrst_values
 * @sa hrtim_timcrst_values
 * @sa hrtim_timdrst_values
 * @sa hrtim_timerst_values
 * @{
 */

/** TIMECMP4: Timer E Compare 4 */
#define HRTIM_TIMD_RST_TIMECMP4        (1 << 30)

/** TIMECMP2: Timer E Compare 2 */
#define HRTIM_TIMD_RST_TIMECMP2        (1 << 29)

/** TIMECMP1: Timer E Compare 1 */
#define HRTIM_TIMD_RST_TIMECMP1        (1 << 28)

/** TIMCCMP4: Timer C Compare 4 */
#define HRTIM_TIMD_RST_TIMCCMP4        (1 << 27)

/** TIMCCMP2: Timer C Compare 2 */
#define HRTIM_TIMD_RST_TIMCCMP2        (1 << 26)

/** TIMCCMP1: Timer C Compare 1 */
#define HRTIM_TIMD_RST_TIMCCMP1        (1 << 25)

/** TIMBCMP4: Timer B Compare 4 */
#define HRTIM_TIMD_RST_TIMBCMP4        (1 << 24)

/** TIMBCMP2: Timer B Compare 2 */
#define HRTIM_TIMD_RST_TIMBCMP2        (1 << 23)

/** TIMBCMP1: Timer B Compare 1 */
#define HRTIM_TIMD_RST_TIMBCMP1        (1 << 22)

/** TIMACMP4: Timer A Compare 4 */
#define HRTIM_TIMD_RST_TIMACMP4        (1 << 21)

/** TIMACMP2: Timer A Compare 2 */
#define HRTIM_TIMD_RST_TIMACMP2        (1 << 20)

/** TIMACMP1: Timer A Compare 1 */
#define HRTIM_TIMD_RST_TIMACMP1        (1 << 19)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIMD_RST_EXTEVNT10       (1 << 18)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIMD_RST_EXTEVNT9        (1 << 17)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIMD_RST_EXTEVNT8        (1 << 16)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIMD_RST_EXTEVNT7        (1 << 15)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIMD_RST_EXTEVNT6        (1 << 14)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIMD_RST_EXTEVNT5        (1 << 13)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIMD_RST_EXTEVNT4        (1 << 12)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIMD_RST_EXTEVNT3        (1 << 11)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIMD_RST_EXTEVNT2        (1 << 10)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIMD_RST_EXTEVNT1        (1 << 9)

/** MSTCMP4: Master compare 4 */
#define HRTIM_TIMD_RST_MSTCMP4         (1 << 8)

/** MSTCMP3: Master compare 3 */
#define HRTIM_TIMD_RST_MSTCMP3         (1 << 7)

/** MSTCMP2: Master compare 2 */
#define HRTIM_TIMD_RST_MSTCMP2         (1 << 6)

/** MSTCMP1: Master compare 1 */
#define HRTIM_TIMD_RST_MSTCMP1         (1 << 5)

/** MSTPER: Master timer Period */
#define HRTIM_TIMD_RST_MSTPER          (1 << 4)

/** CMP4: Timer A compare 4 reset */
#define HRTIM_TIMD_RST_CMP4            (1 << 3)

/** CMP2: Timer A compare 2 reset */
#define HRTIM_TIMD_RST_CMP2            (1 << 2)

/** UPDT: Timer A Update reset */
#define HRTIM_TIMD_RST_UPDT            (1 << 1)

/**@}*/

/** @defgroup hrtim_timerst_values HRTIM_TIME_RST Values
 * @ingroup hrtim_defines
 * Only bits 30:19 differ between TIMx_RST registers.
 * @sa hrtim_timarst_values
 * @sa hrtim_timbrst_values
 * @sa hrtim_timcrst_values
 * @sa hrtim_timdrst_values
 * @sa hrtim_timerst_values
 * @{
 */

/** TIMDCMP4: Timer D Compare 4 */
#define HRTIM_TIME_RST_TIMDCMP4        (1 << 30)

/** TIMDCMP2: Timer D Compare 2 */
#define HRTIM_TIME_RST_TIMDCMP2        (1 << 29)

/** TIMDCMP1: Timer D Compare 1 */
#define HRTIM_TIME_RST_TIMDCMP1        (1 << 28)

/** TIMCCMP4: Timer C Compare 4 */
#define HRTIM_TIME_RST_TIMCCMP4        (1 << 27)

/** TIMCCMP2: Timer C Compare 2 */
#define HRTIM_TIME_RST_TIMCCMP2        (1 << 26)

/** TIMCCMP1: Timer C Compare 1 */
#define HRTIM_TIME_RST_TIMCCMP1        (1 << 25)

/** TIMBCMP4: Timer B Compare 4 */
#define HRTIM_TIME_RST_TIMBCMP4        (1 << 24)

/** TIMBCMP2: Timer B Compare 2 */
#define HRTIM_TIME_RST_TIMBCMP2        (1 << 23)

/** TIMBCMP1: Timer B Compare 1 */
#define HRTIM_TIME_RST_TIMBCMP1        (1 << 22)

/** TIMACMP4: Timer A Compare 4 */
#define HRTIM_TIME_RST_TIMACMP4        (1 << 21)

/** TIMACMP2: Timer A Compare 2 */
#define HRTIM_TIME_RST_TIMACMP2        (1 << 20)

/** TIMACMP1: Timer A Compare 1 */
#define HRTIM_TIME_RST_TIMACMP1        (1 << 19)

/** EXTEVNT10: External Event 10 */
#define HRTIM_TIME_RST_EXTEVNT10       (1 << 18)

/** EXTEVNT9: External Event 9 */
#define HRTIM_TIME_RST_EXTEVNT9        (1 << 17)

/** EXTEVNT8: External Event 8 */
#define HRTIM_TIME_RST_EXTEVNT8        (1 << 16)

/** EXTEVNT7: External Event 7 */
#define HRTIM_TIME_RST_EXTEVNT7        (1 << 15)

/** EXTEVNT6: External Event 6 */
#define HRTIM_TIME_RST_EXTEVNT6        (1 << 14)

/** EXTEVNT5: External Event 5 */
#define HRTIM_TIME_RST_EXTEVNT5        (1 << 13)

/** EXTEVNT4: External Event 4 */
#define HRTIM_TIME_RST_EXTEVNT4        (1 << 12)

/** EXTEVNT3: External Event 3 */
#define HRTIM_TIME_RST_EXTEVNT3        (1 << 11)

/** EXTEVNT2: External Event 2 */
#define HRTIM_TIME_RST_EXTEVNT2        (1 << 10)

/** EXTEVNT1: External Event 1 */
#define HRTIM_TIME_RST_EXTEVNT1        (1 << 9)

/** MSTCMP4: Master compare 4 */
#define HRTIM_TIME_RST_MSTCMP4         (1 << 8)

/** MSTCMP3: Master compare 3 */
#define HRTIM_TIME_RST_MSTCMP3         (1 << 7)

/** MSTCMP2: Master compare 2 */
#define HRTIM_TIME_RST_MSTCMP2         (1 << 6)

/** MSTCMP1: Master compare 1 */
#define HRTIM_TIME_RST_MSTCMP1         (1 << 5)

/** MSTPER: Master timer Period */
#define HRTIM_TIME_RST_MSTPER          (1 << 4)

/** CMP4: Timer A compare 4 reset */
#define HRTIM_TIME_RST_CMP4            (1 << 3)

/** CMP2: Timer A compare 2 reset */
#define HRTIM_TIME_RST_CMP2            (1 << 2)

/** UPDT: Timer A Update reset */
#define HRTIM_TIME_RST_UPDT            (1 << 1)

/**@}*/

/** @defgroup hrtim_timxchp_values HRTIM_TIMxCHP Values
 * @ingroup hrtim_defines
 * @{
 */

/** STRTPW[10:7]: STRTPW */
#define HRTIM_TIMx_CHP_STRTPW_SHIFT    7
#define HRTIM_TIMx_CHP_STRTPW_MASK     (0xf << HRTIM_TIMx_CHP_STRTPW_SHIFT)

/** CHPDTY[6:4]: Timerx chopper duty cycle value */
#define HRTIM_TIMx_CHP_CHPDTY_SHIFT    4
#define HRTIM_TIMx_CHP_CHPDTY_MASK     (0x7 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)

#define HRTIM_TIMx_CHP_CHPDTY_0_8         (0 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_1_8         (1 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_2_8         (2 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_3_8         (3 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_4_8         (4 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_5_8         (5 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_6_8         (6 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)
#define HRTIM_TIMx_CHP_CHPDTY_7_8         (7 << HRTIM_TIMx_CHP_CHPDTY_SHIFT)

/** CHPFRQ[3:0]: Timerx carrier frequency value */
#define HRTIM_TIMx_CHP_CHPFRQ_SHIFT    0
#define HRTIM_TIMx_CHP_CHPFRQ_MASK     (0xf << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)

#define HRTIM_TIMx_CHP_CHPFRQ_DIV16       ( 0 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV32       ( 1 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV48       ( 2 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV64       ( 3 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV80       ( 4 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV96       ( 5 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV112      ( 6 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV128      ( 7 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV144      ( 8 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV160      ( 9 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV176      (10 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV192      (11 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV208      (12 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV224      (13 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV240      (14 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)
#define HRTIM_TIMx_CHP_CHPFRQ_DIV256      (15 << HRTIM_TIMx_CHP_CHPFRQ_SHIFT)

/**@}*/

/** @defgroup hrtim_timxcpt1_values HRTIM_TIMxCPT1 Values
 * @ingroup hrtim_defines
 * @{
 */

/** TECMP2: Timer E Compare 2 */
#define HRTIM_TIMx_CPT1_TECMP2         (1 << 31)

/** TECMP1: Timer E Compare 1 */
#define HRTIM_TIMx_CPT1_TECMP1         (1 << 30)

/** TE1RST: Timer E output 1 Reset */
#define HRTIM_TIMx_CPT1_TE1RST         (1 << 29)

/** TE1SET: Timer E output 1 Set */
#define HRTIM_TIMx_CPT1_TE1SET         (1 << 28)

/** TDCMP2: Timer D Compare 2 */
#define HRTIM_TIMx_CPT1_TDCMP2         (1 << 27)

/** TDCMP1: Timer D Compare 1 */
#define HRTIM_TIMx_CPT1_TDCMP1         (1 << 26)

/** TD1RST: Timer D output 1 Reset */
#define HRTIM_TIMx_CPT1_TD1RST         (1 << 25)

/** TD1SET: Timer D output 1 Set */
#define HRTIM_TIMx_CPT1_TD1SET         (1 << 24)

/** TCCMP2: Timer C Compare 2 */
#define HRTIM_TIMx_CPT1_TCCMP2         (1 << 23)

/** TCCMP1: Timer C Compare 1 */
#define HRTIM_TIMx_CPT1_TCCMP1         (1 << 22)

/** TC1RST: Timer C output 1 Reset */
#define HRTIM_TIMx_CPT1_TC1RST         (1 << 21)

/** TC1SET: Timer C output 1 Set */
#define HRTIM_TIMx_CPT1_TC1SET         (1 << 20)

/** TBCMP2: Timer B Compare 2 */
#define HRTIM_TIMx_CPT1_TBCMP2         (1 << 19)

/** TBCMP1: Timer B Compare 1 */
#define HRTIM_TIMx_CPT1_TBCMP1         (1 << 18)

/** TB1RST: Timer B output 1 Reset */
#define HRTIM_TIMx_CPT1_TB1RST         (1 << 17)

/** TB1SET: Timer B output 1 Set */
#define HRTIM_TIMx_CPT1_TB1SET         (1 << 16)

/** EXEV10CPT: External Event 10 Capture */
#define HRTIM_TIMx_CPT1_EXEV10CPT      (1 << 11)

/** EXEV9CPT: External Event 9 Capture */
#define HRTIM_TIMx_CPT1_EXEV9CPT       (1 << 10)

/** EXEV8CPT: External Event 8 Capture */
#define HRTIM_TIMx_CPT1_EXEV8CPT       (1 << 9)

/** EXEV7CPT: External Event 7 Capture */
#define HRTIM_TIMx_CPT1_EXEV7CPT       (1 << 8)

/** EXEV6CPT: External Event 6 Capture */
#define HRTIM_TIMx_CPT1_EXEV6CPT       (1 << 7)

/** EXEV5CPT: External Event 5 Capture */
#define HRTIM_TIMx_CPT1_EXEV5CPT       (1 << 6)

/** EXEV4CPT: External Event 4 Capture */
#define HRTIM_TIMx_CPT1_EXEV4CPT       (1 << 5)

/** EXEV3CPT: External Event 3 Capture */
#define HRTIM_TIMx_CPT1_EXEV3CPT       (1 << 4)

/** EXEV2CPT: External Event 2 Capture */
#define HRTIM_TIMx_CPT1_EXEV2CPT       (1 << 3)

/** EXEV1CPT: External Event 1 Capture */
#define HRTIM_TIMx_CPT1_EXEV1CPT       (1 << 2)

/** UDPCPT: Update Capture */
#define HRTIM_TIMx_CPT1_UDPCPT         (1 << 1)

/** SWCPT: Software Capture */
#define HRTIM_TIMx_CPT1_SWCPT          (1 << 0)

/**@}*/

/** @defgroup hrtim_timxcpt2_values HRTIM_TIMxCPT2 Values
 * @ingroup hrtim_defines
 * @{
 */

/** TECMP2: Timer E Compare 2 */
#define HRTIM_TIMx_CPT2_TECMP2         (1 << 31)

/** TECMP1: Timer E Compare 1 */
#define HRTIM_TIMx_CPT2_TECMP1         (1 << 30)

/** TE1RST: Timer E output 1 Reset */
#define HRTIM_TIMx_CPT2_TE1RST         (1 << 29)

/** TE1SET: Timer E output 1 Set */
#define HRTIM_TIMx_CPT2_TE1SET         (1 << 28)

/** TDCMP2: Timer D Compare 2 */
#define HRTIM_TIMx_CPT2_TDCMP2         (1 << 27)

/** TDCMP1: Timer D Compare 1 */
#define HRTIM_TIMx_CPT2_TDCMP1         (1 << 26)

/** TD1RST: Timer D output 1 Reset */
#define HRTIM_TIMx_CPT2_TD1RST         (1 << 25)

/** TD1SET: Timer D output 1 Set */
#define HRTIM_TIMx_CPT2_TD1SET         (1 << 24)

/** TCCMP2: Timer C Compare 2 */
#define HRTIM_TIMx_CPT2_TCCMP2         (1 << 23)

/** TCCMP1: Timer C Compare 1 */
#define HRTIM_TIMx_CPT2_TCCMP1         (1 << 22)

/** TC1RST: Timer C output 1 Reset */
#define HRTIM_TIMx_CPT2_TC1RST         (1 << 21)

/** TC1SET: Timer C output 1 Set */
#define HRTIM_TIMx_CPT2_TC1SET         (1 << 20)

/** TBCMP2: Timer B Compare 2 */
#define HRTIM_TIMx_CPT2_TBCMP2         (1 << 19)

/** TBCMP1: Timer B Compare 1 */
#define HRTIM_TIMx_CPT2_TBCMP1         (1 << 18)

/** TB1RST: Timer B output 1 Reset */
#define HRTIM_TIMx_CPT2_TB1RST         (1 << 17)

/** TB1SET: Timer B output 1 Set */
#define HRTIM_TIMx_CPT2_TB1SET         (1 << 16)

/** EXEV10CPT: External Event 10 Capture */
#define HRTIM_TIMx_CPT2_EXEV10CPT      (1 << 11)

/** EXEV9CPT: External Event 9 Capture */
#define HRTIM_TIMx_CPT2_EXEV9CPT       (1 << 10)

/** EXEV8CPT: External Event 8 Capture */
#define HRTIM_TIMx_CPT2_EXEV8CPT       (1 << 9)

/** EXEV7CPT: External Event 7 Capture */
#define HRTIM_TIMx_CPT2_EXEV7CPT       (1 << 8)

/** EXEV6CPT: External Event 6 Capture */
#define HRTIM_TIMx_CPT2_EXEV6CPT       (1 << 7)

/** EXEV5CPT: External Event 5 Capture */
#define HRTIM_TIMx_CPT2_EXEV5CPT       (1 << 6)

/** EXEV4CPT: External Event 4 Capture */
#define HRTIM_TIMx_CPT2_EXEV4CPT       (1 << 5)

/** EXEV3CPT: External Event 3 Capture */
#define HRTIM_TIMx_CPT2_EXEV3CPT       (1 << 4)

/** EXEV2CPT: External Event 2 Capture */
#define HRTIM_TIMx_CPT2_EXEV2CPT       (1 << 3)

/** EXEV1CPT: External Event 1 Capture */
#define HRTIM_TIMx_CPT2_EXEV1CPT       (1 << 2)

/** UDPCPT: Update Capture */
#define HRTIM_TIMx_CPT2_UDPCPT         (1 << 1)

/** SWCPT: Software Capture */
#define HRTIM_TIMx_CPT2_SWCPT          (1 << 0)

/**@}*/

/** @defgroup hrtim_timxout_values HRTIM_TIMxOUT Values
 * @ingroup hrtim_defines
 * @{
 */

/** DIDL2: Output 2 Deadtime upon burst mode Idle entry */
#define HRTIM_TIMx_OUT_DIDL2           (1 << 23)

/** CHP2: Output 2 Chopper enable */
#define HRTIM_TIMx_OUT_CHP2            (1 << 22)

/** FAULT2[21:20]: Output 2 Fault state */
#define HRTIM_TIMx_OUT_FAULT2_SHIFT    20
#define HRTIM_TIMx_OUT_FAULT2_MASK     (0x3 << HRTIM_TIMx_OUT_FAULT2_SHIFT)

#define HRTIM_TIMx_OUT_FAULT2_NOOP         (0 << HRTIM_TIMx_OUT_FAULT2_SHIFT)
#define HRTIM_TIMx_OUT_FAULT2_ACTIVE       (1 << HRTIM_TIMx_OUT_FAULT2_SHIFT)
#define HRTIM_TIMx_OUT_FAULT2_INACTIVE     (2 << HRTIM_TIMx_OUT_FAULT2_SHIFT)
#define HRTIM_TIMx_OUT_FAULT2_HIGHZ        (3 << HRTIM_TIMx_OUT_FAULT2_SHIFT)

/** IDLES2: Output 2 Idle State */
#define HRTIM_TIMx_OUT_IDLES2          (1 << 19)

/** IDLEM2: Output 2 Idle mode */
#define HRTIM_TIMx_OUT_IDLEM2          (1 << 18)

/** POL2: Output 2 polarity */
#define HRTIM_TIMx_OUT_POL2            (1 << 17)

/** DLYPRT[12:10]: Delayed Protection */
#define HRTIM_TIMx_OUT_DLYPRT_SHIFT    10
#define HRTIM_TIMx_OUT_DLYPRT_MASK     (0x7 << HRTIM_TIMx_OUT_DLYPRT_SHIFT)

/** DLYPRTEN: Delayed Protection Enable */
#define HRTIM_TIMx_OUT_DLYPRTEN        (1 << 9)

/** DTEN: Deadtime enable */
#define HRTIM_TIMx_OUT_DTEN            (1 << 8)

/** DIDL1: Output 1 Deadtime upon burst mode Idle entry */
#define HRTIM_TIMx_OUT_DIDL1           (1 << 7)

/** CHP1: Output 1 Chopper enable */
#define HRTIM_TIMx_OUT_CHP1            (1 << 6)

/** FAULT1[5:4]: Output 1 Fault state */
#define HRTIM_TIMx_OUT_FAULT1_SHIFT    4
#define HRTIM_TIMx_OUT_FAULT1_MASK     (0x3 << HRTIM_TIMx_OUT_FAULT1_SHIFT)

#define HRTIM_TIMx_OUT_FAULT1_NOOP         (0 << HRTIM_TIMx_OUT_FAULT1_SHIFT)
#define HRTIM_TIMx_OUT_FAULT1_ACTIVE       (1 << HRTIM_TIMx_OUT_FAULT1_SHIFT)
#define HRTIM_TIMx_OUT_FAULT1_INACTIVE     (2 << HRTIM_TIMx_OUT_FAULT1_SHIFT)
#define HRTIM_TIMx_OUT_FAULT1_HIGHZ        (3 << HRTIM_TIMx_OUT_FAULT1_SHIFT)

/** IDLES1: Output 1 Idle State */
#define HRTIM_TIMx_OUT_IDLES1          (1 << 3)

/** IDLEM1: Output 1 Idle mode */
#define HRTIM_TIMx_OUT_IDLEM1          (1 << 2)

/** POL1: Output 1 polarity */
#define HRTIM_TIMx_OUT_POL1            (1 << 1)

/**@}*/

/** @defgroup hrtim_timxflt_values HRTIM_TIMxFLT Values
 * @ingroup hrtim_defines
 * @{
 */

/** FLTLCK: Fault sources Lock */
#define HRTIM_TIMx_FLT_FLTLCK          (1 << 31)

/** FLT5EN: Fault 5 enable */
#define HRTIM_TIMx_FLT_FLT5EN          (1 << 4)

/** FLT4EN: Fault 4 enable */
#define HRTIM_TIMx_FLT_FLT4EN          (1 << 3)

/** FLT3EN: Fault 3 enable */
#define HRTIM_TIMx_FLT_FLT3EN          (1 << 2)

/** FLT2EN: Fault 2 enable */
#define HRTIM_TIMx_FLT_FLT2EN          (1 << 1)

/** FLT1EN: Fault 1 enable */
#define HRTIM_TIMx_FLT_FLT1EN          (1 << 0)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

END_DECLS

#endif
/** @cond */
#else
#warning "hrtim_common_all.h should not be included explicitly, only via hrtim.h"
#endif
/** @endcond */

/**@}*/

