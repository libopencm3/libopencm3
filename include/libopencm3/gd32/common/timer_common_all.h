/** @addtogroup timer_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2009 Piotr Esden-Tempski <piotr@esden.net>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Piotr Esden-Tempski <piotr@esden.net>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA TIMER.H
The order of header inclusion is important. timer.h includes the device
specific memorymap.h header before including this header file.*/

#pragma once
/* --- Convenience macros -------------------------------------------------- */

/* Timer register base addresses (for convenience) */
/****************************************************************************/
/** @defgroup tim_reg_base Timer register base addresses
@{*/
#define TIM0				TIM0_BASE
#define TIM1				TIM1_BASE
#define TIM2				TIM2_BASE
#define TIM5				TIM5_BASE
#define TIM13				TIM13_BASE
#define TIM14				TIM14_BASE
#define TIM15				TIM15_BASE
#define TIM16				TIM16_BASE
/**@}*/

/* --- Timer registers ----------------------------------------------------- */

/* Control register 1 (TIMx_CTL0) */
#define TIM_CTL0(tim_base)               MMIO32((tim_base) + 0x00)
#define TIM1_CTL0			TIM_CTL0(TIM1)
#define TIM2_CTL0			TIM_CTL0(TIM2)
#define TIM3_CTL0			TIM_CTL0(TIM3)
#define TIM4_CTL0			TIM_CTL0(TIM4)
#define TIM5_CTL0			TIM_CTL0(TIM5)
#define TIM6_CTL0			TIM_CTL0(TIM6)
#define TIM7_CTL0			TIM_CTL0(TIM7)
#define TIM8_CTL0			TIM_CTL0(TIM8)
#define TIM9_CTL0			TIM_CTL0(TIM9)
#define TIM10_CTL0			TIM_CTL0(TIM10)
#define TIM11_CTL0			TIM_CTL0(TIM11)
#define TIM12_CTL0			TIM_CTL0(TIM12)
#define TIM13_CTL0			TIM_CTL0(TIM13)
#define TIM14_CTL0			TIM_CTL0(TIM14)
#define TIM15_CTL0			TIM_CTL0(TIM15)
#define TIM16_CTL0			TIM_CTL0(TIM16)
#define TIM17_CTL0			TIM_CTL0(TIM17)

/* Control register 2 (TIMx_CTL1) */
#define TIM_CTL1(tim_base)		MMIO32((tim_base) + 0x04)
#define TIM1_CTL1			TIM_CTL1(TIM1)
#define TIM2_CTL1			TIM_CTL1(TIM2)
#define TIM3_CTL1			TIM_CTL1(TIM3)
#define TIM4_CTL1			TIM_CTL1(TIM4)
#define TIM5_CTL1			TIM_CTL1(TIM5)
#define TIM6_CTL1			TIM_CTL1(TIM6)
#define TIM7_CTL1			TIM_CTL1(TIM7)
#define TIM8_CTL1			TIM_CTL1(TIM8)
#define TIM15_CTL1			TIM_CTL1(TIM15)
#define TIM16_CTL1			TIM_CTL1(TIM16)
#define TIM17_CTL1			TIM_CTL1(TIM17)

/* Slave mode control register (TIMx_SMCFG) */
#define TIM_SMCFG(tim_base)		MMIO32((tim_base) + 0x08)
#define TIM1_SMCFG			TIM_SMCFG(TIM1)
#define TIM2_SMCFG			TIM_SMCFG(TIM2)
#define TIM3_SMCFG			TIM_SMCFG(TIM3)
#define TIM4_SMCFG			TIM_SMCFG(TIM4)
#define TIM5_SMCFG			TIM_SMCFG(TIM5)
#define TIM8_SMCFG			TIM_SMCFG(TIM8)
#define TIM9_SMCFG			TIM_SMCFG(TIM9)
#define TIM12_SMCFG			TIM_SMCFG(TIM12)
#define TIM15_SMCFG			TIM_SMCFG(TIM15)

/* DMA/Interrupt enable register (TIMx_DMAINTEN) */
#define TIM_DMAINTEN(tim_base)		MMIO32((tim_base) + 0x0C)
#define TIM1_DMAINTEN			TIM_DMAINTEN(TIM1)
#define TIM2_DMAINTEN			TIM_DMAINTEN(TIM2)
#define TIM3_DMAINTEN			TIM_DMAINTEN(TIM3)
#define TIM4_DMAINTEN			TIM_DMAINTEN(TIM4)
#define TIM5_DMAINTEN			TIM_DMAINTEN(TIM5)
#define TIM6_DMAINTEN			TIM_DMAINTEN(TIM6)
#define TIM7_DMAINTEN			TIM_DMAINTEN(TIM7)
#define TIM8_DMAINTEN			TIM_DMAINTEN(TIM8)
#define TIM9_DMAINTEN			TIM_DMAINTEN(TIM9)
#define TIM10_DMAINTEN			TIM_DMAINTEN(TIM10)
#define TIM11_DMAINTEN			TIM_DMAINTEN(TIM11)
#define TIM12_DMAINTEN			TIM_DMAINTEN(TIM12)
#define TIM13_DMAINTEN			TIM_DMAINTEN(TIM13)
#define TIM14_DMAINTEN			TIM_DMAINTEN(TIM14)
#define TIM15_DMAINTEN			TIM_DMAINTEN(TIM15)
#define TIM16_DMAINTEN			TIM_DMAINTEN(TIM16)
#define TIM17_DMAINTEN			TIM_DMAINTEN(TIM17)

/* Status register (TIMx_INTF) */
#define TIM_INTF(tim_base)		MMIO32((tim_base) + 0x10)
#define TIM1_INTF			TIM_INTF(TIM1)
#define TIM2_INTF			TIM_INTF(TIM2)
#define TIM3_INTF			TIM_INTF(TIM3)
#define TIM4_INTF			TIM_INTF(TIM4)
#define TIM5_INTF			TIM_INTF(TIM5)
#define TIM6_INTF			TIM_INTF(TIM6)
#define TIM7_INTF			TIM_INTF(TIM7)
#define TIM8_INTF			TIM_INTF(TIM8)
#define TIM9_INTF			TIM_INTF(TIM9)
#define TIM10_INTF			TIM_INTF(TIM10)
#define TIM11_INTF			TIM_INTF(TIM11)
#define TIM12_INTF			TIM_INTF(TIM12)
#define TIM13_INTF			TIM_INTF(TIM13)
#define TIM14_INTF			TIM_INTF(TIM14)
#define TIM15_INTF			TIM_INTF(TIM15)
#define TIM16_INTF			TIM_INTF(TIM16)
#define TIM17_INTF			TIM_INTF(TIM17)

/* Event generation register (TIMx_SWEVG) */
#define TIM_SWEVG(tim_base)		MMIO32((tim_base) + 0x14)
#define TIM1_SWEVG			TIM_SWEVG(TIM1)
#define TIM2_SWEVG			TIM_SWEVG(TIM2)
#define TIM3_SWEVG			TIM_SWEVG(TIM3)
#define TIM4_SWEVG			TIM_SWEVG(TIM4)
#define TIM5_SWEVG			TIM_SWEVG(TIM5)
#define TIM6_SWEVG			TIM_SWEVG(TIM6)
#define TIM7_SWEVG			TIM_SWEVG(TIM7)
#define TIM8_SWEVG			TIM_SWEVG(TIM8)
#define TIM9_SWEVG			TIM_SWEVG(TIM9)
#define TIM10_SWEVG			TIM_SWEVG(TIM10)
#define TIM11_SWEVG			TIM_SWEVG(TIM11)
#define TIM12_SWEVG			TIM_SWEVG(TIM12)
#define TIM13_SWEVG			TIM_SWEVG(TIM13)
#define TIM14_SWEVG			TIM_SWEVG(TIM14)
#define TIM15_SWEVG			TIM_SWEVG(TIM15)
#define TIM16_SWEVG			TIM_SWEVG(TIM16)
#define TIM17_SWEVG			TIM_SWEVG(TIM17)

/* Capture/compare mode register 1 (TIMx_CHCTL0) */
#define TIM_CHCTL0(tim_base)		MMIO32((tim_base) + 0x18)
#define TIM1_CHCTL0			TIM_CHCTL0(TIM1)
#define TIM2_CHCTL0			TIM_CHCTL0(TIM2)
#define TIM3_CHCTL0			TIM_CHCTL0(TIM3)
#define TIM4_CHCTL0			TIM_CHCTL0(TIM4)
#define TIM5_CHCTL0			TIM_CHCTL0(TIM5)
#define TIM8_CHCTL0			TIM_CHCTL0(TIM8)
#define TIM9_CHCTL0			TIM_CHCTL0(TIM9)
#define TIM10_CHCTL0			TIM_CHCTL0(TIM10)
#define TIM11_CHCTL0			TIM_CHCTL0(TIM11)
#define TIM12_CHCTL0			TIM_CHCTL0(TIM12)
#define TIM13_CHCTL0			TIM_CHCTL0(TIM13)
#define TIM14_CHCTL0			TIM_CHCTL0(TIM14)
#define TIM15_CHCTL0			TIM_CHCTL0(TIM15)
#define TIM16_CHCTL0			TIM_CHCTL0(TIM16)
#define TIM17_CHCTL0			TIM_CHCTL0(TIM17)

/* Capture/compare mode register 2 (TIMx_CHCTL1) */
#define TIM_CHCTL1(tim_base)		MMIO32((tim_base) + 0x1C)
#define TIM1_CHCTL1			TIM_CHCTL1(TIM1)
#define TIM2_CHCTL1			TIM_CHCTL1(TIM2)
#define TIM3_CHCTL1			TIM_CHCTL1(TIM3)
#define TIM4_CHCTL1			TIM_CHCTL1(TIM4)
#define TIM5_CHCTL1			TIM_CHCTL1(TIM5)
#define TIM8_CHCTL1			TIM_CHCTL1(TIM8)

/* Capture/compare enable register (TIMx_CCER) */
#define TIM_CCER(tim_base)		MMIO32((tim_base) + 0x20)
#define TIM1_CCER			TIM_CCER(TIM1)
#define TIM2_CCER			TIM_CCER(TIM2)
#define TIM3_CCER			TIM_CCER(TIM3)
#define TIM4_CCER			TIM_CCER(TIM4)
#define TIM5_CCER			TIM_CCER(TIM5)
#define TIM8_CCER			TIM_CCER(TIM8)
#define TIM9_CCER			TIM_CCER(TIM9)
#define TIM10_CCER			TIM_CCER(TIM10)
#define TIM11_CCER			TIM_CCER(TIM11)
#define TIM12_CCER			TIM_CCER(TIM12)
#define TIM13_CCER			TIM_CCER(TIM13)
#define TIM14_CCER			TIM_CCER(TIM14)
#define TIM15_CCER			TIM_CCER(TIM15)
#define TIM16_CCER			TIM_CCER(TIM16)
#define TIM17_CCER			TIM_CCER(TIM17)

/* Counter (TIMx_CNT) */
#define TIM_CNT(tim_base)		MMIO32((tim_base) + 0x24)
#define TIM1_CNT			TIM_CNT(TIM1)
#define TIM2_CNT			TIM_CNT(TIM2)
#define TIM3_CNT			TIM_CNT(TIM3)
#define TIM4_CNT			TIM_CNT(TIM4)
#define TIM5_CNT			TIM_CNT(TIM5)
#define TIM6_CNT			TIM_CNT(TIM6)
#define TIM7_CNT			TIM_CNT(TIM7)
#define TIM8_CNT			TIM_CNT(TIM8)
#define TIM9_CNT			TIM_CNT(TIM9)
#define TIM10_CNT			TIM_CNT(TIM10)
#define TIM11_CNT			TIM_CNT(TIM11)
#define TIM12_CNT			TIM_CNT(TIM12)
#define TIM13_CNT			TIM_CNT(TIM13)
#define TIM14_CNT			TIM_CNT(TIM14)
#define TIM15_CNT			TIM_CNT(TIM15)
#define TIM16_CNT			TIM_CNT(TIM16)
#define TIM17_CNT			TIM_CNT(TIM17)

/* Prescaler (TIMx_PSC) */
#define TIM_PSC(tim_base)		MMIO32((tim_base) + 0x28)
#define TIM1_PSC			TIM_PSC(TIM1)
#define TIM2_PSC			TIM_PSC(TIM2)
#define TIM3_PSC			TIM_PSC(TIM3)
#define TIM4_PSC			TIM_PSC(TIM4)
#define TIM5_PSC			TIM_PSC(TIM5)
#define TIM6_PSC			TIM_PSC(TIM6)
#define TIM7_PSC			TIM_PSC(TIM7)
#define TIM8_PSC			TIM_PSC(TIM8)
#define TIM9_PSC			TIM_PSC(TIM9)
#define TIM10_PSC			TIM_PSC(TIM10)
#define TIM11_PSC			TIM_PSC(TIM11)
#define TIM12_PSC			TIM_PSC(TIM12)
#define TIM13_PSC			TIM_PSC(TIM13)
#define TIM14_PSC			TIM_PSC(TIM14)
#define TIM15_PSC			TIM_PSC(TIM15)
#define TIM16_PSC			TIM_PSC(TIM16)
#define TIM17_PSC			TIM_PSC(TIM17)

/* Auto-reload register (TIMx_CAR) */
#define TIM_CAR(tim_base)		MMIO32((tim_base) + 0x2C)
#define TIM1_CAR			TIM_CAR(TIM1)
#define TIM2_CAR			TIM_CAR(TIM2)
#define TIM3_CAR			TIM_CAR(TIM3)
#define TIM4_CAR			TIM_CAR(TIM4)
#define TIM5_CAR			TIM_CAR(TIM5)
#define TIM6_CAR			TIM_CAR(TIM6)
#define TIM7_CAR			TIM_CAR(TIM7)
#define TIM8_CAR			TIM_CAR(TIM8)
#define TIM9_CAR			TIM_CAR(TIM9)
#define TIM10_CAR			TIM_CAR(TIM10)
#define TIM11_CAR			TIM_CAR(TIM11)
#define TIM12_CAR			TIM_CAR(TIM12)
#define TIM13_CAR			TIM_CAR(TIM13)
#define TIM14_CAR			TIM_CAR(TIM14)
#define TIM15_CAR			TIM_CAR(TIM15)
#define TIM16_CAR			TIM_CAR(TIM16)
#define TIM17_CAR			TIM_CAR(TIM17)

/* Repetition counter register (TIMx_CREP) */
#define TIM_CREP(tim_base)		MMIO32((tim_base) + 0x30)
#define TIM1_CREP			TIM_CREP(TIM1)
#define TIM8_CREP			TIM_CREP(TIM8)
#define TIM15_CREP			TIM_CREP(TIM15)
#define TIM16_CREP			TIM_CREP(TIM16)
#define TIM17_CREP			TIM_CREP(TIM17)

/* Capture/compare register 1 (TIMx_CH0CV) */
#define TIM_CH0CV(tim_base)		MMIO32((tim_base) + 0x34)
#define TIM1_CH0CV			TIM_CH0CV(TIM1)
#define TIM2_CH0CV			TIM_CH0CV(TIM2)
#define TIM3_CH0CV			TIM_CH0CV(TIM3)
#define TIM4_CH0CV			TIM_CH0CV(TIM4)
#define TIM5_CH0CV			TIM_CH0CV(TIM5)
#define TIM8_CH0CV			TIM_CH0CV(TIM8)
#define TIM9_CH0CV			TIM_CH0CV(TIM9)
#define TIM10_CH0CV			TIM_CH0CV(TIM10)
#define TIM11_CH0CV			TIM_CH0CV(TIM11)
#define TIM12_CH0CV			TIM_CH0CV(TIM12)
#define TIM13_CH0CV			TIM_CH0CV(TIM13)
#define TIM14_CH0CV			TIM_CH0CV(TIM14)
#define TIM15_CH0CV			TIM_CH0CV(TIM15)
#define TIM16_CH0CV			TIM_CH0CV(TIM16)
#define TIM17_CH0CV			TIM_CH0CV(TIM17)

/* Capture/compare register 2 (TIMx_CH1CV) */
#define TIM_CH1CV(tim_base)		MMIO32((tim_base) + 0x38)
#define TIM1_CH1CV			TIM_CH1CV(TIM1)
#define TIM2_CH1CV			TIM_CH1CV(TIM2)
#define TIM3_CH1CV			TIM_CH1CV(TIM3)
#define TIM4_CH1CV			TIM_CH1CV(TIM4)
#define TIM5_CH1CV			TIM_CH1CV(TIM5)
#define TIM8_CH1CV			TIM_CH1CV(TIM8)
#define TIM9_CH1CV			TIM_CH1CV(TIM9)
#define TIM12_CH1CV			TIM_CH1CV(TIM12)
#define TIM15_CH1CV			TIM_CH1CV(TIM15)

/* Capture/compare register 3 (TIMx_CH2CV) */
#define TIM_CH2CV(tim_base)		MMIO32((tim_base) + 0x3C)
#define TIM1_CH2CV			TIM_CH2CV(TIM1)
#define TIM2_CH2CV			TIM_CH2CV(TIM2)
#define TIM3_CH2CV			TIM_CH2CV(TIM3)
#define TIM4_CH2CV			TIM_CH2CV(TIM4)
#define TIM5_CH2CV			TIM_CH2CV(TIM5)
#define TIM8_CH2CV			TIM_CH2CV(TIM8)

/* Capture/compare register 4 (TIMx_CH3CV) */
#define TIM_CH3CV(tim_base)		MMIO32((tim_base) + 0x40)
#define TIM1_CH3CV			TIM_CH3CV(TIM1)
#define TIM2_CH3CV			TIM_CH3CV(TIM2)
#define TIM3_CH3CV			TIM_CH3CV(TIM3)
#define TIM4_CH3CV			TIM_CH3CV(TIM4)
#define TIM5_CH3CV			TIM_CH3CV(TIM5)
#define TIM8_CH3CV			TIM_CH3CV(TIM8)

/* Break and dead-time register (TIMx_CCHP) */
#define TIM_CCHP(tim_base)		MMIO32((tim_base) + 0x44)
#define TIM1_CCHP			TIM_CCHP(TIM1)
#define TIM8_CCHP			TIM_CCHP(TIM8)
#define TIM15_CCHP			TIM_CCHP(TIM15)
#define TIM16_CCHP			TIM_CCHP(TIM16)
#define TIM17_CCHP			TIM_CCHP(TIM17)

/* DMA control register (TIMx_DMACFG) */
#define TIM_DMACFG(tim_base)		MMIO32((tim_base) + 0x48)
#define TIM1_DMACFG			TIM_DMACFG(TIM1)
#define TIM2_DMACFG			TIM_DMACFG(TIM2)
#define TIM3_DMACFG			TIM_DMACFG(TIM3)
#define TIM4_DMACFG			TIM_DMACFG(TIM4)
#define TIM5_DMACFG			TIM_DMACFG(TIM5)
#define TIM8_DMACFG			TIM_DMACFG(TIM8)
#define TIM15_DMACFG			TIM_DMACFG(TIM15)
#define TIM16_DMACFG			TIM_DMACFG(TIM16)
#define TIM17_DMACFG			TIM_DMACFG(TIM17)

/* DMA address for full transfer (TIMx_DMATB) */
#define TIM_DMATB(tim_base)		MMIO32((tim_base) + 0x4C)
#define TIM1_DMATB			TIM_DMATB(TIM1)
#define TIM2_DMATB			TIM_DMATB(TIM2)
#define TIM3_DMATB			TIM_DMATB(TIM3)
#define TIM4_DMATB			TIM_DMATB(TIM4)
#define TIM5_DMATB			TIM_DMATB(TIM5)
#define TIM8_DMATB			TIM_DMATB(TIM8)
#define TIM15_DMATB			TIM_DMATB(TIM15)
#define TIM16_DMATB			TIM_DMATB(TIM16)
#define TIM17_DMATB			TIM_DMATB(TIM17)

/* --- TIMx_CTL0 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr1_cdr TIMx_CTL0 CKD[1:0] Clock Division Ratio
@{*/
/* CKD[1:0]: Clock division */
#define TIM_CTL0_CKD_CK_INT		(0x0 << 8)
#define TIM_CTL0_CKD_CK_INT_MUL_2	(0x1 << 8)
#define TIM_CTL0_CKD_CK_INT_MUL_4	(0x2 << 8)
#define TIM_CTL0_CKD_CK_INT_MASK	(0x3 << 8)
/**@}*/

/* ARPE: Auto-reload shadow enable */
#define TIM_CTL0_ARSE			(1 << 7)

/* CAM[1:0]: Center-aligned mode selection */
/****************************************************************************/
/** @defgroup tim_x_cr1_cms TIMx_CTL0 CAM[1:0]: Center-aligned Mode Selection
@{*/
#define TIM_CTL0_CAM_EDGE		(0x0 << 5)
#define TIM_CTL0_CAM_CENTER_1		(0x1 << 5)
#define TIM_CTL0_CAM_CENTER_2		(0x2 << 5)
#define TIM_CTL0_CAM_CENTER_3		(0x3 << 5)
#define TIM_CTL0_CAM_MASK		(0x3 << 5)
/**@}*/

/* DIR: Direction */
/****************************************************************************/
/** @defgroup tim_x_cr1_dir TIMx_CTL0 DIR: Direction
@{*/
#define TIM_CTL0_DIR_UP			(0 << 4)
#define TIM_CTL0_DIR_DOWN		(1 << 4)
/**@}*/

/* SPM: One pulse mode */
#define TIM_CTL0_SPM			(1 << 3)

/* UPS: Update request source */
#define TIM_CTL0_UPS			(1 << 2)

/* UPDIS: Update disable */
#define TIM_CTL0_UPDIS			(1 << 1)

/* CEN: Counter enable */
#define TIM_CTL0_CEN			(1 << 0)

/* --- TIMx_CTL1 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr2_ois TIMx_CTL1_OIS: Force Output Idle State Control Values
@{*/
/* ISO3:*//** Output idle state 4 (OC4 output) */
#define TIM_CTL1_ISO3			(1 << 14)

/* ISO2N:*//** Output idle state 3 (OC3N output) */
#define TIM_CTL1_ISO2N			(1 << 13)

/* ISO2:*//** Output idle state 3 (OC3 output) */
#define TIM_CTL1_ISO2			(1 << 12)

/* ISO1N:*//** Output idle state 2 (OC2N output) */
#define TIM_CTL1_ISO1N			(1 << 11)

/* ISO1:*//** Output idle state 2 (OC2 output) */
#define TIM_CTL1_ISO1			(1 << 10)

/* ISO0N:*//** Output idle state 1 (OC1N output) */
#define TIM_CTL1_ISO0N			(1 << 9)

/* ISO0:*//** Output idle state 1 (OC1 output) */
#define TIM_CTL1_ISO0			(1 << 8)
#define TIM_CTL1_ISO_MASK		(0x7f << 8)
/**@}*/

/* TI0S: TI0 selection */
#define TIM_CTL1_TI0S			(1 << 7)

/* MMS[2:0]: Master mode selection */
/****************************************************************************/
/** @defgroup tim_mastermode TIMx_CTL1 MMS[6:4]: Master Mode Selection
@{*/
#define TIM_CTL1_MMC_RESET		(0x0 << 4)
#define TIM_CTL1_MMC_ENABLE		(0x1 << 4)
#define TIM_CTL1_MMC_UPDATE		(0x2 << 4)
#define TIM_CTL1_MMC_COMPARE_PULSE	(0x3 << 4)
#define TIM_CTL1_MMC_COMPARE_OC0REF	(0x4 << 4)
#define TIM_CTL1_MMC_COMPARE_OC1REF	(0x5 << 4)
#define TIM_CTL1_MMC_COMPARE_OC2REF	(0x6 << 4)
#define TIM_CTL1_MMC_COMPARE_OC3REF	(0x7 << 4)
#define TIM_CTL1_MMC_MASK		(0x7 << 4)
/**@}*/

/* CCDS: Capture/compare DMA selection */
#define TIM_CTL1_DMAS			(1 << 3)

/* CCUS: Capture/compare control update selection */
#define TIM_CTL1_CCUC			(1 << 2)

/* CCPC: Capture/compare shadow control */
#define TIM_CTL1_CCSE			(1 << 0)

/* --- TIMx_SMCFG values ---------------------------------------------------- */

/* ETP: External trigger polarity */
#define TIM_SMCFG_ETP			(1 << 15)

/* SMC1: External clock enable */
#define TIM_SMCFG_SMC1			(1 << 14)

/* ETPSC[1:0]: External trigger prescaler */
#define TIM_SMCFG_ETPSC_OFF		(0x0 << 12)
#define TIM_SMCFG_ETPSC_ETRP_DIV_2	(0x1 << 12)
#define TIM_SMCFG_ETPSC_ETRP_DIV_4	(0x2 << 12)
#define TIM_SMCFG_ETPSC_ETRP_DIV_8	(0x3 << 12)
#define TIM_SMCFG_ETPSC_MASK		(0X3 << 12)

/* ETFC[3:0]: External trigger filter */
#define TIM_SMCFG_ETFC_OFF		(0x0 << 8)
#define TIM_SMCFG_ETFC_CK_INT_N_2	(0x1 << 8)
#define TIM_SMCFG_ETFC_CK_INT_N_4	(0x2 << 8)
#define TIM_SMCFG_ETFC_CK_INT_N_8	(0x3 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_2_N_6	(0x4 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_2_N_8	(0x5 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_4_N_6	(0x6 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_4_N_8	(0x7 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_8_N_6	(0x8 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_8_N_8	(0x9 << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_16_N_5	(0xA << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_16_N_6	(0xB << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_16_N_8	(0xC << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_32_N_5	(0xD << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_32_N_6	(0xE << 8)
#define TIM_SMCFG_ETFC_DTS_DIV_32_N_8	(0xF << 8)
#define TIM_SMCFG_ETFC_MASK		(0xF << 8)

/* MSM: Master/slave mode */
#define TIM_SMCFG_MSM			(1 << 7)

/* TRGS[2:0]: Trigger selection */
/** @defgroup tim_ts TIMx_SMCFG TRGS Trigger selection
@{*/
/** Internal Trigger 0 (ITR0) */
#define TIM_SMCFG_TRGS_ITR0		(0x0 << 4)
/** Internal Trigger 1 (ITR1) */
#define TIM_SMCFG_TRGS_ITR1		(0x1 << 4)
/** Internal Trigger 2 (ITR2) */
#define TIM_SMCFG_TRGS_ITR2		(0x2 << 4)
/** Internal Trigger 3 (ITR3) */
#define TIM_SMCFG_TRGS_ITR3		(0x3 << 4)
/** TI0 Edge Detector (TI0F_ED) */
#define TIM_SMCFG_TRGS_TI0F_ED		(0x4 << 4)
/** Filtered Timer Input 1 (TI0FP1) */
#define TIM_SMCFG_TRGS_TI0FP1		(0x5 << 4)
/** Filtered Timer Input 2 (TI2FP2) */
#define TIM_SMCFG_TRGS_TI2FP2		(0x6 << 4)
/** External Trigger input (ETRF) */
#define TIM_SMCFG_TRGS_ETRF		(0x7 << 4)
#define TIM_SMCFG_TRGS_MASK		(0x7 << 4)
/**@}*/

/* SMC[2:0]: Slave mode selection */
/** @defgroup tim_sms TIMx_SMCFG SMC Slave mode selection
@{*/
/** Slave mode disabled */
#define TIM_SMCFG_SMC_OFF		(0x0 << 0)
/** Encoder mode 1 - Counter counts up/down on TI2FP2 edge depending on TI0FP1
level. */
#define TIM_SMCFG_SMC_EM1		(0x1 << 0)
/** Encoder mode 2 - Counter counts up/down on TI0FP1 edge depending on TI2FP2
level. */
#define TIM_SMCFG_SMC_EM2		(0x2 << 0)
/** Encoder mode 3 - Counter counts up/down on both TI0FP1 and TI2FP2 edges
depending on the level of the complementary input. */
#define TIM_SMCFG_SMC_EM3		(0x3 << 0)
/** Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes
 * the counter and generates an update of the registers.
 */
#define TIM_SMCFG_SMC_RM			(0x4 << 0)
/** Gated Mode - The counter clock is enabled when the trigger input (TRGI) is
 * high.
 */
#define TIM_SMCFG_SMC_GM			(0x5 << 0)
/**  Trigger Mode - The counter starts at a rising edge of the trigger TRGI. */
#define TIM_SMCFG_SMC_TM			(0x6 << 0)
/** External Clock Mode 1 - Rising edges of the selected trigger (TRGI) clock
 * the counter.
 */
#define TIM_SMCFG_SMC_ECM1		(0x7 << 0)
#define TIM_SMCFG_SMC_MASK		(0x7 << 0)
/**@}*/

/* --- TIMx_DMAINTEN values ---------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_irq_enable TIMx_DMAINTEN Timer DMA and Interrupt Enable Values
@{*/
/* TRGDEN:*//** Trigger DMA request enable */
#define TIM_DMAINTEN_TRGDEN			(1 << 14)

/* CMTDEN:*//** COM DMA request enable */
#define TIM_DMAINTEN_CMTDEN			(1 << 13)

/* CH3DEN:*//** Capture/Compare 4 DMA request enable */
#define TIM_DMAINTEN_CH3DEN			(1 << 12)

/* CH2DEN:*//** Capture/Compare 3 DMA request enable */
#define TIM_DMAINTEN_CH2DEN			(1 << 11)

/* CH1DEN:*//** Capture/Compare 2 DMA request enable */
#define TIM_DMAINTEN_CH1DEN			(1 << 10)

/* CH0DEN:*//** Capture/Compare 1 DMA request enable */
#define TIM_DMAINTEN_CH0DEN			(1 << 9)

/* UPDEN*//**: Update DMA request enable */
#define TIM_DMAINTEN_UPDEN			(1 << 8)

/* BRKIE:*//** Break interrupt enable */
#define TIM_DMAINTEN_BRKIE			(1 << 7)

/* TRGIE:*//** Trigger interrupt enable */
#define TIM_DMAINTEN_TRGIE			(1 << 6)

/* CMTIE:*//** COM interrupt enable */
#define TIM_DMAINTEN_CMTIE			(1 << 5)

/* CH3IE:*//** Capture/compare 4 interrupt enable */
#define TIM_DMAINTEN_CH3IE			(1 << 4)

/* CH2IE:*//** Capture/compare 3 interrupt enable */
#define TIM_DMAINTEN_CH2IE			(1 << 3)

/* CH1IE:*//** Capture/compare 2 interrupt enable */
#define TIM_DMAINTEN_CH1IE			(1 << 2)

/* CH0IE:*//** Capture/compare 1 interrupt enable */
#define TIM_DMAINTEN_CH0IE			(1 << 1)

/* UPIE:*//** Update interrupt enable */
#define TIM_DMAINTEN_UPIE			(1 << 0)
/**@}*/

/* --- TIMx_INTF values ------------------------------------------------------ */
/****************************************************************************/
/** @defgroup tim_sr_values TIMx_INTF Timer Status Register Flags
@{*/

/* CH3OF:*//** Capture/compare 4 overcapture flag */
#define TIM_INTF_CH3OF			(1 << 12)

/* CH2OF:*//** Capture/compare 3 overcapture flag */
#define TIM_INTF_CH2OF			(1 << 11)

/* CH1OF:*//** Capture/compare 2 overcapture flag */
#define TIM_INTF_CH1OF			(1 << 10)

/* CH0OF:*//** Capture/compare 1 overcapture flag */
#define TIM_INTF_CH0OF			(1 << 9)

/* BRKIF:*//** Break interrupt flag */
#define TIM_INTF_BRKIF			(1 << 7)

/* TRGIF:*//** Trigger interrupt flag */
#define TIM_INTF_TRGIF			(1 << 6)

/* CMTIF:*//** CMT interrupt flag */
#define TIM_INTF_CMTIF			(1 << 5)

/* CH3IF:*//** Capture/compare 4 interrupt flag */
#define TIM_INTF_CH3IF			(1 << 4)

/* CH2IF:*//** Capture/compare 3 interrupt flag */
#define TIM_INTF_CH2IF			(1 << 3)

/* CH1IF:*//** Capture/compare 2 interrupt flag */
#define TIM_INTF_CH1IF			(1 << 2)

/* CH0IF:*//** Capture/compare 1 interrupt flag */
#define TIM_INTF_CH0IF			(1 << 1)

/* UPIF:*//** Update interrupt flag */
#define TIM_INTF_UPIF			(1 << 0)
/**@}*/

/* --- TIMx_SWEVG values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_event_gen TIMx_SWEVG Timer Event Generator Values
@{*/

/* BRKG:*//** Break generation */
#define TIM_SWEVG_BRKG			(1 << 7)

/* TRGG:*//** Trigger generation */
#define TIM_SWEVG_TRGG			(1 << 6)

/* CMTG:*//** Capture/compare control update generation */
#define TIM_SWEVG_CMTG			(1 << 5)

/* CH3G:*//** Capture/compare 4 generation */
#define TIM_SWEVG_CH3G			(1 << 4)

/* CH2G:*//** Capture/compare 3 generation */
#define TIM_SWEVG_CH2G			(1 << 3)

/* CH1G:*//** Capture/compare 2 generation */
#define TIM_SWEVG_CH1G			(1 << 2)

/* CH0G:*//** Capture/compare 1 generation */
#define TIM_SWEVG_CH0G			(1 << 1)

/* UPG:*//** Update generation */
#define TIM_SWEVG_UPG			(1 << 0)
/**@}*/

/* --- TIMx_CHCTL0 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* CH1COMCEN: Output compare 1 clear enable */
#define TIM_CHCTL0_CH1COMCEN			(1 << 15)

/* CH1COMCTL[2:0]: Output compare 1 mode */
#define TIM_CHCTL0_CH1COMCTL_FROZEN	(0x0 << 12)
#define TIM_CHCTL0_CH1COMCTL_ACTIVE	(0x1 << 12)
#define TIM_CHCTL0_CH1COMCTL_INACTIVE	(0x2 << 12)
#define TIM_CHCTL0_CH1COMCTL_TOGGLE	(0x3 << 12)
#define TIM_CHCTL0_CH1COMCTL_FORCE_LOW	(0x4 << 12)
#define TIM_CHCTL0_CH1COMCTL_FORCE_HIGH	(0x5 << 12)
#define TIM_CHCTL0_CH1COMCTL_PWM0	(0x6 << 12)
#define TIM_CHCTL0_CH1COMCTL_PWM1	(0x7 << 12)
#define TIM_CHCTL0_CH1COMCTL_MASK	(0x7 << 12)

/* CH1COMSEN: Output compare 1 shadow enable */
#define TIM_CHCTL0_CH1COMSEN			(1 << 11)

/* CH1COMFEN: Output compare 1 fast enable */
#define TIM_CHCTL0_CH1COMFEN			(1 << 10)

/* CH1MS[1:0]: Capture/compare 1 selection */
/* Note: CH1MS bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CHCTL0_CH1MS_OUT		(0x0 << 8)
#define TIM_CHCTL0_CH1MS_IN_TI2		(0x1 << 8)
#define TIM_CHCTL0_CH1MS_IN_TI0		(0x2 << 8)
#define TIM_CHCTL0_CH1MS_IN_TRC		(0x3 << 8)
#define TIM_CHCTL0_CH1MS_MASK		(0x3 << 8)

/* CH0COMCEN: Output compare 0 clear enable */
#define TIM_CHCTL0_CH0COMCEN                 (1 << 7)

/* CH0COMCTL[2:0]: Output compare 0 mode */
#define TIM_CHCTL0_CH0COMCTL_FROZEN	(0x0 << 4)
#define TIM_CHCTL0_CH0COMCTL_ACTIVE	(0x1 << 4)
#define TIM_CHCTL0_CH0COMCTL_INACTIVE	(0x2 << 4)
#define TIM_CHCTL0_CH0COMCTL_TOGGLE	(0x3 << 4)
#define TIM_CHCTL0_CH0COMCTL_FORCE_LOW	(0x4 << 4)
#define TIM_CHCTL0_CH0COMCTL_FORCE_HIGH	(0x5 << 4)
#define TIM_CHCTL0_CH0COMCTL_PWM0	(0x6 << 4)
#define TIM_CHCTL0_CH0COMCTL_PWM1	(0x7 << 4)
#define TIM_CHCTL0_CH0COMCTL_MASK	(0x7 << 4)

/* CH0COMSEN: Output compare 0 shadow enable */
#define TIM_CHCTL0_CH0COMSEN			(1 << 3)

/* CH0COMFEN: Output compare 0 fast enable */
#define TIM_CHCTL0_CH0COMFEN			(1 << 2)

/* CH0MS[1:0]: Capture/compare 0 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CHCTL0_CH0MS_OUT		(0x0 << 0)
#define TIM_CHCTL0_CH0MS_IN_TI2		(0x2 << 0)
#define TIM_CHCTL0_CH0MS_IN_TI0		(0x1 << 0)
#define TIM_CHCTL0_CH0MS_IN_TRC		(0x3 << 0)
#define TIM_CHCTL0_CH0MS_MASK		(0x3 << 0)

/* --- Input capture mode --- */

/* CH1CAPFLT[3:0]: Input capture 1 filter */
#define TIM_CHCTL0_CH1CAPFLT_OFF		(0x0 << 12)
#define TIM_CHCTL0_CH1CAPFLT_CK_INT_N_2	(0x1 << 12)
#define TIM_CHCTL0_CH1CAPFLT_CK_INT_N_4	(0x2 << 12)
#define TIM_CHCTL0_CH1CAPFLT_CK_INT_N_8	(0x3 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_2_N_6	(0x4 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_2_N_8	(0x5 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_4_N_6	(0x6 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_4_N_8	(0x7 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_8_N_6	(0x8 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_8_N_8	(0x9 << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_16_N_5	(0xA << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_16_N_6	(0xB << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_16_N_8	(0xC << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_32_N_5	(0xD << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_32_N_6	(0xE << 12)
#define TIM_CHCTL0_CH1CAPFLT_DTS_DIV_32_N_8	(0xF << 12)
#define TIM_CHCTL0_CH1CAPFLT_MASK		(0xF << 12)

/* CH1CAPPSC[1:0]: Input capture 1 prescaler */
#define TIM_CHCTL0_CH1CAPPSC_OFF	(0x0 << 10)
#define TIM_CHCTL0_CH1CAPPSC_2		(0x1 << 10)
#define TIM_CHCTL0_CH1CAPPSC_4		(0x2 << 10)
#define TIM_CHCTL0_CH1CAPPSC_8		(0x3 << 10)
#define TIM_CHCTL0_CH1CAPPSC_MASK	(0x3 << 10)

/* CH0CAPFLT[3:0]: Input capture 1 filter */
#define TIM_CHCTL0_CH0CAPFLT_OFF		(0x0 << 4)
#define TIM_CHCTL0_CH0CAPFLT_CK_INT_N_2		(0x1 << 4)
#define TIM_CHCTL0_CH0CAPFLT_CK_INT_N_4		(0x2 << 4)
#define TIM_CHCTL0_CH0CAPFLT_CK_INT_N_8		(0x3 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_2_N_6	(0x4 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_2_N_8	(0x5 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_4_N_6	(0x6 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_4_N_8	(0x7 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_8_N_6	(0x8 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_8_N_8	(0x9 << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_16_N_5	(0xA << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_16_N_6	(0xB << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_16_N_8	(0xC << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_32_N_5	(0xD << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_32_N_6	(0xE << 4)
#define TIM_CHCTL0_CH0CAPFLT_DTF_DIV_32_N_8	(0xF << 4)
#define TIM_CHCTL0_CH0CAPFLT_MASK		(0xF << 4)

/* CH0CAPPSC[1:0]: Input capture 1 prescaler */
#define TIM_CHCTL0_CH0CAPPSC_OFF	(0x0 << 2)
#define TIM_CHCTL0_CH0CAPPSC_2		(0x1 << 2)
#define TIM_CHCTL0_CH0CAPPSC_4		(0x2 << 2)
#define TIM_CHCTL0_CH0CAPPSC_8		(0x3 << 2)
#define TIM_CHCTL0_CH0CAPPSC_MASK	(0x3 << 2)

/* --- TIMx_CHCTL1 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* CH3COMCEN: Output compare 3 clear enable */
#define TIM_CHCTL1_CH3COMCEN			(1 << 15)

/* CH3COMCTL[2:0]: Output compare 3 mode */
#define TIM_CHCTL1_CH3COMCTL_FROZEN	(0x0 << 12)
#define TIM_CHCTL1_CH3COMCTL_ACTIVE	(0x1 << 12)
#define TIM_CHCTL1_CH3COMCTL_INACTIVE	(0x2 << 12)
#define TIM_CHCTL1_CH3COMCTL_TOGGLE	(0x3 << 12)
#define TIM_CHCTL1_CH3COMCTL_FORCE_LOW	(0x4 << 12)
#define TIM_CHCTL1_CH3COMCTL_FORCE_HIGH	(0x5 << 12)
#define TIM_CHCTL1_CH3COMCTL_PWM0	(0x6 << 12)
#define TIM_CHCTL1_CH3COMCTL_PWM1	(0x7 << 12)
#define TIM_CHCTL1_CH3COMCTL_MASK	(0x7 << 12)

/* CH3COMSEN: Output compare 3 shadow enable */
#define TIM_CHCTL1_CH3COMSEN			(1 << 11)

/* CH3COMFEN: Output compare 3 fast enable */
#define TIM_CHCTL1_CH3COMFEN			(1 << 10)

/* CH3MS[1:0]: Capture/compare 4 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CHCTL1_CH3MS_OUT		(0x0 << 8)
#define TIM_CHCTL1_CH3MS_IN_TI4		(0x1 << 8)
#define TIM_CHCTL1_CH3MS_IN_TI3		(0x2 << 8)
#define TIM_CHCTL1_CH3MS_IN_TRC		(0x3 << 8)
#define TIM_CHCTL1_CH3MS_MASK		(0x3 << 8)

/* CH2COMCEN: Output compare 2 clear enable */
#define TIM_CHCTL1_CH2COMCEN			(1 << 7)

/* CH2COMCTL[2:0]: Output compare 2 mode */
#define TIM_CHCTL1_CH2COMCTL_FROZEN		(0x0 << 4)
#define TIM_CHCTL1_CH2COMCTL_ACTIVE		(0x1 << 4)
#define TIM_CHCTL1_CH2COMCTL_INACTIVE		(0x2 << 4)
#define TIM_CHCTL1_CH2COMCTL_TOGGLE		(0x3 << 4)
#define TIM_CHCTL1_CH2COMCTL_FORCE_LOW	(0x4 << 4)
#define TIM_CHCTL1_CH2COMCTL_FORCE_HIGH	(0x5 << 4)
#define TIM_CHCTL1_CH2COMCTL_PWM0		(0x6 << 4)
#define TIM_CHCTL1_CH2COMCTL_PWM1		(0x7 << 4)
#define TIM_CHCTL1_CH2COMCTL_MASK		(0x7 << 4)

/* CH2COMSEN: Output compare 3 shadow enable */
#define TIM_CHCTL1_CH2COMSEN			(1 << 3)

/* CH2COMFEN: Output compare 3 fast enable */
#define TIM_CHCTL1_CH2COMFEN			(1 << 2)

/* CH2MS[1:0]: Capture/compare 3 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CHCTL1_CH2MS_OUT		(0x0 << 0)
#define TIM_CHCTL1_CH2MS_IN_TI3		(0x1 << 0)
#define TIM_CHCTL1_CH2MS_IN_TI4		(0x2 << 0)
#define TIM_CHCTL1_CH2MS_IN_TRC		(0x3 << 0)
#define TIM_CHCTL1_CH2MS_MASK		(0x3 << 0)

/* --- Input capture mode --- */

/* CH3CAPFLT[3:0]: Input capture 3 filter */
#define TIM_CHCTL1_CH3CAPFLT_OFF		(0x0 << 12)
#define TIM_CHCTL1_CH3CAPFLT_CK_INT_N_2		(0x1 << 12)
#define TIM_CHCTL1_CH3CAPFLT_CK_INT_N_4		(0x2 << 12)
#define TIM_CHCTL1_CH3CAPFLT_CK_INT_N_8		(0x3 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_2_N_6	(0x4 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_2_N_8	(0x5 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_4_N_6	(0x6 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_4_N_8	(0x7 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_8_N_6	(0x8 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_8_N_8	(0x9 << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_16_N_5	(0xA << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_16_N_6	(0xB << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_16_N_8	(0xC << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_32_N_5	(0xD << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_32_N_6	(0xE << 12)
#define TIM_CHCTL1_CH3CAPFLT_DTS_DIV_32_N_8	(0xF << 12)
#define TIM_CHCTL1_CH3CAPFLT_MASK		(0xF << 12)

/* CH3CAPPSC[1:0]: Input capture 3 prescaler */
#define TIM_CHCTL1_CH3CAPPSC_OFF	(0x0 << 10)
#define TIM_CHCTL1_CH3CAPPSC_2		(0x1 << 10)
#define TIM_CHCTL1_CH3CAPPSC_4		(0x2 << 10)
#define TIM_CHCTL1_CH3CAPPSC_8		(0x3 << 10)
#define TIM_CHCTL1_CH3CAPPSC_MASK	(0x3 << 10)

/* CH2CAPFLT[3:0]: Input capture 2 filter */
#define TIM_CHCTL1_CH2CAPFLT_OFF		(0x0 << 4)
#define TIM_CHCTL1_CH2CAPFLT_CK_INT_N_2		(0x1 << 4)
#define TIM_CHCTL1_CH2CAPFLT_CK_INT_N_4		(0x2 << 4)
#define TIM_CHCTL1_CH2CAPFLT_CK_INT_N_8		(0x3 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_2_N_6	(0x4 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_2_N_8	(0x5 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_4_N_6	(0x6 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_4_N_8	(0x7 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_8_N_6	(0x8 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_8_N_8	(0x9 << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_16_N_5	(0xA << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_16_N_6	(0xB << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_16_N_8	(0xC << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_32_N_5	(0xD << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_32_N_6	(0xE << 4)
#define TIM_CHCTL1_CH2CAPFLT_DTS_DIV_32_N_8	(0xF << 4)
#define TIM_CHCTL1_CH2CAPFLT_MASK		(0xF << 4)

/* CH2CAPPSC[1:0]: Input capture 2 prescaler */
#define TIM_CHCTL1_CH2CAPPSC_OFF	(0x0 << 2)
#define TIM_CHCTL1_CH2CAPPSC_2		(0x1 << 2)
#define TIM_CHCTL1_CH2CAPPSC_4		(0x2 << 2)
#define TIM_CHCTL1_CH2CAPPSC_8		(0x3 << 2)
#define TIM_CHCTL1_CH2CAPPSC_MASK	(0x3 << 2)

/* --- TIMx_CCER values ---------------------------------------------------- */

/* CH3P: Capture/compare 4 output polarity */
#define TIM_CCER_CH3P			(1 << 13)

/* CH3EN: Capture/compare 4 output enable */
#define TIM_CCER_CH3EN			(1 << 12)

/* CH2NP: Capture/compare 3 complementary output polarity */
#define TIM_CCER_CH2NP			(1 << 11)

/* CH2NEN: Capture/compare 3 complementary output enable */
#define TIM_CCER_CH2NEN			(1 << 10)

/* CH2P: Capture/compare 3 output polarity */
#define TIM_CCER_CH2P			(1 << 9)

/* CH2EN: Capture/compare 3 output enable */
#define TIM_CCER_CH2EN			(1 << 8)

/* CH1NP: Capture/compare 2 complementary output polarity */
#define TIM_CCER_CH1NP			(1 << 7)

/* CH1NEN: Capture/compare 2 complementary output enable */
#define TIM_CCER_CH1NEN			(1 << 6)

/* CH1P: Capture/compare 2 output polarity */
#define TIM_CCER_CH1P			(1 << 5)

/* CH1EN: Capture/compare 2 output enable */
#define TIM_CCER_CH1EN			(1 << 4)

/* CH0NP: Capture/compare 1 complementary output polarity */
#define TIM_CCER_CH0NP			(1 << 3)

/* CH0NEN: Capture/compare 1 complementary output enable */
#define TIM_CCER_CH0NEN			(1 << 2)

/* CH0P: Capture/compare 1 output polarity */
#define TIM_CCER_CH0P			(1 << 1)

/* CH0EN: Capture/compare 1 output enable */
#define TIM_CCER_CH0EN			(1 << 0)

/* --- TIMx_CNT values ----------------------------------------------------- */

/* CNT[15:0]: Counter value */

/* --- TIMx_PSC values ----------------------------------------------------- */

/* PSC[15:0]: Prescaler value */

/* --- TIMx_CAR values ----------------------------------------------------- */

/* CAR[15:0]: Prescaler value */

/* --- TIMx_CREP values ----------------------------------------------------- */

/* REP[15:0]: Repetition counter value */

/* --- TIMx_CH0CV values ---------------------------------------------------- */

/* CH0CV[15:0]: Capture/compare 1 value */

/* --- TIMx_CH1CV values ---------------------------------------------------- */

/* CH1CV[15:0]: Capture/compare 2 value */

/* --- TIMx_CH2CV values ---------------------------------------------------- */

/* CH2CV[15:0]: Capture/compare 3 value */

/* --- TIMx_CH3CV values ---------------------------------------------------- */

/* CH3CV[15:0]: Capture/compare 4 value */

/* --- TIMx_CCHP values ---------------------------------------------------- */

/* POEN: Primary output enable */
#define TIM_CCHP_POEN			(1 << 15)

/* OAEN: Automatic output enable */
#define TIM_CCHP_OAEN			(1 << 14)

/* BRKP: Break polarity */
#define TIM_CCHP_BRKP			(1 << 13)

/* BRKEN: Break enable */
#define TIM_CCHP_BRKEN			(1 << 12)

/* ROS: Run mode Off-state selection */
#define TIM_CCHP_ROS			(1 << 11)

/* IOS: Idle Off-state selection */
#define TIM_CCHP_IOS			(1 << 10)

/* PROT[1:0]: Protection configuration */
/****************************************************************************/
/** @defgroup tim_lock TIM_CCHP_PROT Timer Lock Values
@{*/
#define TIM_CCHP_PROT_OFF		(0x0 << 8)
#define TIM_CCHP_PROT_LEVEL_1		(0x1 << 8)
#define TIM_CCHP_PROT_LEVEL_2		(0x2 << 8)
#define TIM_CCHP_PROT_LEVEL_3		(0x3 << 8)
#define TIM_CCHP_PROT_MASK		(0x3 << 8)
/**@}*/

/* DTCFG[7:0]: Dead-time generator set-up */
#define TIM_CCHP_DTCFG_MASK		0x00FF

/* --- TIMx_DMACFG values ----------------------------------------------------- */

/* DMATC[4:0]: DMA burst length */
#define TIM_DMACFG_DMATC_MASK		(0x1F << 8)

/* DMATA[4:0]: DMA base address */
#define TIM_DMACFG_DMATA_MASK		(0x1F << 0)

/* --- TIMx_DMATB values ---------------------------------------------------- */

/* DMATB[15:0]: DMA register for burst accesses */

/* --- TIMx convenience defines -------------------------------------------- */

/** Output Compare channel designators */
enum tim_oc_id {
	TIM_OC0 = 0,
	TIM_OC0N,
	TIM_OC1,
	TIM_OC1N,
	TIM_OC2,
	TIM_OC2N,
	TIM_OC3,
};

/** Output Compare mode designators */
enum tim_oc_mode {
	TIM_COMCTL_FROZEN,
	TIM_COMCTL_ACTIVE,
	TIM_COMCTL_INACTIVE,
	TIM_COMCTL_TOGGLE,
	TIM_COMCTL_FORCE_LOW,
	TIM_COMCTL_FORCE_HIGH,
	TIM_COMCTL_PWM0,
	TIM_COMCTL_PWM1,
};

/** Input Capture channel designators */
enum tim_ic_id {
	TIM_IC0,
	TIM_IC1,
	TIM_IC2,
	TIM_IC3,
};

/** Input Capture input filter. The frequency used to sample the
input and the number of events needed to validate an output transition.

TIM_IC_CK_INT_N_x No division from the Deadtime and Sampling Clock frequency
(DTF), filter length x
TIM_IC_DTF_DIV_y_N_x Division by y from the DTF, filter length x
 */
enum tim_ic_filter {
	TIM_IC_OFF,
	TIM_IC_CK_INT_N_2,
	TIM_IC_CK_INT_N_4,
	TIM_IC_CK_INT_N_8,
	TIM_IC_DTS_DIV_2_N_6,
	TIM_IC_DTS_DIV_2_N_8,
	TIM_IC_DTS_DIV_4_N_6,
	TIM_IC_DTS_DIV_4_N_8,
	TIM_IC_DTS_DIV_8_N_6,
	TIM_IC_DTS_DIV_8_N_8,
	TIM_IC_DTS_DIV_16_N_5,
	TIM_IC_DTS_DIV_16_N_6,
	TIM_IC_DTS_DIV_16_N_8,
	TIM_IC_DTS_DIV_32_N_5,
	TIM_IC_DTS_DIV_32_N_6,
	TIM_IC_DTS_DIV_32_N_8,
};

/** Input Capture input prescaler.

TIM_IC_PSC_x Input capture is done every x events*/
enum tim_ic_psc {
	TIM_IC_PSC_OFF,
	TIM_IC_PSC_2,
	TIM_IC_PSC_4,
	TIM_IC_PSC_8,
};

/** Input Capture input source.

The direction of the channel (input/output) as well as the input used.
 */
enum tim_ic_input {
	TIM_IC_OUT = 0,
	TIM_IC_IN_TI0 = 1,
	TIM_IC_IN_TI1 = 2,
	TIM_IC_IN_TRC = 3,
};

/** Slave external trigger polarity */
enum tim_et_pol {
	TIM_ET_RISING,
	TIM_ET_FALLING,
};

/** External clock mode 2 */
enum tim_ecm2_state {
    TIM_ECM2_DISABLED,
    TIM_ECM2_ENABLED,
};

/* --- TIM function prototypes --------------------------------------------- */

BEGIN_DECLS

void timer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void timer_disable_irq(uint32_t timer_peripheral, uint32_t irq);
bool timer_interrupt_source(uint32_t timer_peripheral, uint32_t flag);
bool timer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_clear_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_set_mode(uint32_t timer_peripheral, uint32_t clock_div,
		    uint32_t alignment, uint32_t direction);
void timer_set_clock_division(uint32_t timer_peripheral, uint32_t clock_div);
void timer_enable_shadow(uint32_t timer_peripheral);
void timer_disable_shadow(uint32_t timer_peripheral);
void timer_set_alignment(uint32_t timer_peripheral, uint32_t alignment);
void timer_direction_up(uint32_t timer_peripheral);
void timer_direction_down(uint32_t timer_peripheral);
void timer_one_shot_mode(uint32_t timer_peripheral);
void timer_continuous_mode(uint32_t timer_peripheral);
void timer_update_on_any(uint32_t timer_peripheral);
void timer_update_on_overflow(uint32_t timer_peripheral);
void timer_enable_update_event(uint32_t timer_peripheral);
void timer_disable_update_event(uint32_t timer_peripheral);
void timer_enable_counter(uint32_t timer_peripheral);
void timer_disable_counter(uint32_t timer_peripheral);
void timer_set_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_reset_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_set_ti1_ch123_xor(uint32_t timer_peripheral);
void timer_set_ti1_ch1(uint32_t timer_peripheral);
void timer_set_master_mode(uint32_t timer_peripheral, uint32_t mode);
void timer_set_dma_on_compare_event(uint32_t timer_peripheral);
void timer_set_dma_on_update_event(uint32_t timer_peripheral);
void timer_enable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_disable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_enable_shadow_complementry_enable_bits(uint32_t timer_peripheral);
void timer_disable_shadow_complementry_enable_bits(uint32_t timer_peripheral);
void timer_set_prescaler(uint32_t timer_peripheral, uint32_t value);
void timer_set_repetition_counter(uint32_t timer_peripheral, uint32_t value);
void timer_set_period(uint32_t timer_peripheral, uint32_t period);
void timer_enable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_fast_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_slow_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id,
		       enum tim_oc_mode oc_mode);
void timer_enable_oc_shadow(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_shadow(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_polarity_high(uint32_t timer_peripheral,
				enum tim_oc_id oc_id);
void timer_set_oc_polarity_low(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_enable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_idle_state_set(uint32_t timer_peripheral,
				 enum tim_oc_id oc_id);
void timer_set_oc_idle_state_unset(uint32_t timer_peripheral,
				   enum tim_oc_id oc_id);
void timer_set_oc_value(uint32_t timer_peripheral, enum tim_oc_id oc_id,
			uint32_t value);
void timer_enable_break_main_output(uint32_t timer_peripheral);
void timer_disable_break_main_output(uint32_t timer_peripheral);
void timer_enable_break_automatic_output(uint32_t timer_peripheral);
void timer_disable_break_automatic_output(uint32_t timer_peripheral);
void timer_set_break_polarity_high(uint32_t timer_peripheral);
void timer_set_break_polarity_low(uint32_t timer_peripheral);
void timer_enable_break(uint32_t timer_peripheral);
void timer_disable_break(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_break_lock(uint32_t timer_peripheral, uint32_t lock);
void timer_set_deadtime(uint32_t timer_peripheral, uint32_t deadtime);
void timer_generate_event(uint32_t timer_peripheral, uint32_t event);
uint32_t timer_get_counter(uint32_t timer_peripheral);
void timer_set_counter(uint32_t timer_peripheral, uint32_t count);

void timer_ic_set_filter(uint32_t timer, enum tim_ic_id ic,
			 enum tim_ic_filter flt);
void timer_ic_set_prescaler(uint32_t timer, enum tim_ic_id ic,
			    enum tim_ic_psc psc);
void timer_ic_set_input(uint32_t timer, enum tim_ic_id ic,
			enum tim_ic_input in);
void timer_ic_enable(uint32_t timer, enum tim_ic_id ic);
void timer_ic_disable(uint32_t timer, enum tim_ic_id ic);

void timer_slave_set_filter(uint32_t timer, enum tim_ic_filter flt);
void timer_slave_set_prescaler(uint32_t timer, enum tim_ic_psc psc);
void timer_slave_set_polarity(uint32_t timer, enum tim_et_pol pol);
void timer_slave_set_mode(uint32_t timer, uint8_t mode);
void timer_slave_set_trigger(uint32_t timer, uint8_t trigger);
void timer_slave_set_extclockmode2(uint32_t timer_peripheral,
            enum tim_ecm2_state state);

END_DECLS

/**@}*/
