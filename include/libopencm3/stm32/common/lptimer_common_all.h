/** @addtogroup lptimer_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2009 Piotr Esden-Tempski <piotr@esden.net>
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

/** @cond */
#if defined(LIBOPENCM3_LPTIMER_H)
/** @endcond */
#ifndef LIBOPENCM3_LPTIMER_COMMON_H
#define LIBOPENCM3_LPTIMER_COMMON_H

/* --- LPTIM (low power timer) ------------------------------------------- */

#define LPTIM_ISR(tim_base)		MMIO32((tim_base) + 0x00)
#define LPTIM_ICR(tim_base)		MMIO32((tim_base) + 0x04)
#define LPTIM_IER(tim_base)		MMIO32((tim_base) + 0x08)
#define LPTIM_CFGR(tim_base)		MMIO32((tim_base) + 0x0C)
#define LPTIM_CR(tim_base)		MMIO32((tim_base) + 0x10)
#define LPTIM_CMP(tim_base)		MMIO32((tim_base) + 0x14)
#define LPTIM_ARR(tim_base)		MMIO32((tim_base) + 0x18)
#define LPTIM_CNT(tim_base)		MMIO32((tim_base) + 0x1C)

#define LPTIM1_ISR			LPTIM_ISR(LPTIM1_BASE)
#define LPTIM1_ICR			LPTIM_ICR(LPTIM1_BASE)
#define LPTIM1_IER			LPTIM_IER(LPTIM1_BASE)
#define LPTIM1_CFGR			LPTIM_CFGR(LPTIM1_BASE)
#define LPTIM1_CR			LPTIM_CR(LPTIM1_BASE)
#define LPTIM1_CMP			LPTIM_CMP(LPTIM1_BASE)
#define LPTIM1_ARR			LPTIM_ARR(LPTIM1_BASE)
#define LPTIM1_CNT			LPTIM_CNT(LPTIM1_BASE)

#if defined(LPTIM2_BASE)
#define LPTIM2_ISR			LPTIM_ISR(LPTIM2_BASE)
#define LPTIM2_ICR			LPTIM_ICR(LPTIM2_BASE)
#define LPTIM2_IER			LPTIM_IER(LPTIM2_BASE)
#define LPTIM2_CFGR			LPTIM_CFGR(LPTIM2_BASE)
#define LPTIM2_CR			LPTIM_CR(LPTIM2_BASE)
#define LPTIM2_CMP			LPTIM_CMP(LPTIM2_BASE)
#define LPTIM2_ARR			LPTIM_ARR(LPTIM2_BASE)
#define LPTIM2_CNT			LPTIM_CNT(LPTIM2_BASE)
#endif

/** @defgroup lptim_isr LPTIM_ISR Interrupt and Status Register
@{*/

/** LPTIM_ISR_CMPM Compare match */
#define LPTIM_ISR_CMPM			(1 << 0)

/** LPTIM_ISR_ARRM Autoreload match */
#define LPTIM_ISR_ARRM			(1 << 1)

/** LPTIM_ISR_EXTTRIG External trigger edge event */
#define LPTIM_ISR_EXTTRIG		(1 << 2)

/** LPTIM_ISR_CMPOK Compare register update OK */
#define LPTIM_ISR_CMPOK			(1 << 3)

/** LPTIM_ISR_ARROK Autoreload register update OK */
#define LPTIM_ISR_ARROK			(1 << 4)

/** LPTIM_ISR_UP Counter direction change down to up */
#define LPTIM_ISR_UP			(1 << 5)

/** LPTIM_ISR_DOWN Counter direction change up to down */
#define LPTIM_ISR_DOWN			(1 << 6)

/**@}*/

/** @defgroup lptim_icr LPTIM_ICR Interrupt Clear Register 
@{*/

/** LPTIM_ICR_CMPMCF compare match Clear Flag */
#define LPTIM_ICR_CMPMCF		(1 << 0)

/** LPTIM_ICR_ARRMCF Autoreload match Clear Flag */
#define LPTIM_ICR_ARRMCF		(1 << 1)

/** LPTIM_ICR_EXTTRIGCF External trigger valid edge Clear Flag */
#define LPTIM_ICR_EXTTRIGCF		(1 << 2)

/** LPTIM_ICR_CMPOKCF Compare register update OK Clear Flag */
#define LPTIM_ICR_CMPOKCF		(1 << 3)

/** LPTIM_ICR_ARROKCF Autoreload register update OK Clear Flag */
#define LPTIM_ICR_ARROKCF		(1 << 4)

/** LPTIM_ICR_UPCF Direction change to UP Clear Flag */
#define LPTIM_ICR_UPCF			(1 << 5)

/** LPTIM_ICR_DOWNCF Direction change to down Clear Flag */
#define LPTIM_ICR_DOWNCF		(1 << 6)

/**@}*/

/** @defgroup lptim_ier LPTIM_IER Interrupt Enable Register
@{*/

/** LPTIM_IER_CMPMIE Compare match Interrupt Enable */
#define LPTIM_IER_CMPMIE		(1 << 0)

/** LPTIM_IER_ARRMIE Autoreload match Interrupt Enable */
#define LPTIM_IER_ARRMIE		(1 << 1)

/** LPTIM_IER_EXTTRIGIE External trigger valid edge Interrupt Enable */
#define LPTIM_IER_EXTTRIGIE		(1 << 2)

/** LPTIM_IER_CMPOKIE Compare register update OK Interrupt Enable */
#define LPTIM_IER_CMPOKIE		(1 << 3)

/** LPTIM_IER_ARROKIE Autoreload register update OK Interrupt Enable */
#define LPTIM_IER_ARROKIE		(1 << 4)

/** LPTIM_IER_UPIE Direction change to UP Interrupt Enable */
#define LPTIM_IER_UPIE			(1 << 5)

/** LPTIM_IER_DOWNIE Direction change to down Interrupt Enable */
#define LPTIM_IER_DOWNIE		(1 << 6)

/**@}*/

/** @defgroup lptim_cfgr LPTIM_CFGR Configuration Register
@{*/

/** CKSEL: Select internal (0) or external clock source (1) */
#define LPTIM_CFGR_CKSEL		(1 << 0)

#define LPTIM_CFGR_CKPOL_SHIFT		1
#define LPTIM_CFGR_CKPOL_MASK		0x03
#define LPTIM_CFGR_CKPOL		(3 << LPTIM_CFGR_CKPOL_SHIFT)
/** @defgroup lptim_cfgr_ckpol LPTIM_CFGR CKPOL Clock Polarity
@{*/
#define LPTIM_CFGR_CKPOL_RISING		(0 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_FALLING	(1 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_BOTH		(2 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_1		(0 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_2		(1 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_3		(2 << LPTIM_CFGR_CKPOL_SHIFT)
/**@}*/

#define LPTIM_CFGR_CKFLT_SHIFT		3
#define LPTIM_CFGR_CKFLT_MASK		0x03
#define LPTIM_CFGR_CKFLT		(3 << LPTIM_CFGR_CKFLT_SHIFT)
/** @defgroup lptim_cfgr_ckflt LPTIM_CFGR CKFLT Configurable digital filter for external clock
@{*/
#define LPTIM_CFGR_CKFLT_2		(1 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_4		(2 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_8		(3 << LPTIM_CFGR_CKFLT_SHIFT)
/**@}*/

#define LPTIM_CFGR_TRGFLT_SHIFT		6
#define LPTIM_CFGR_TRGFLT_MASK		0x03
#define LPTIM_CFGR_TRGFLT		(3 << LPTIM_CFGR_TRGFLT_SHIFT)
/** @defgroup lptim_cfgr_trgflt LPTIM_CFGR TRGFLT Configurable digital filter for trigger
@{*/
#define LPTIM_CFGR_TRGFLT_2		(1 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_4		(2 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_8		(3 << LPTIM_CFGR_TRGFLT_SHIFT)
/**@}*/

#define LPTIM_CFGR_PRESC_SHIFT		9
#define LPTIM_CFGR_PRESC_MASK		0x07
#define LPTIM_CFGR_PRESC		(7 << LPTIM_CFGR_PRESC_SHIFT)
/** @defgroup lptim_cfgr_presc LPTIM_CFGR PRESC Clock prescaler
@{*/
#define LPTIM_CFGR_PRESC_1		(0 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_2		(1 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_4		(2 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_8		(3 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_16		(4 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_32		(5 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_64		(6 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_128		(7 << LPTIM_CFGR_PRESC_SHIFT)
/**@}*/

#define LPTIM_CFGR_TRIGSEL_SHIFT	13
#define LPTIM_CFGR_TRIGSEL_MASK		0x07
#define LPTIM_CFGR_TRIGSEL		(7 << LPTIM_CFGR_TRIGSEL_SHIFT)
/** @defgroup lptim_cfgr_trigsel LPTIM_CFGR TRIGSEL Trigger selector
@{*/
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG0	(0 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG1	(1 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG2	(2 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG3	(3 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG4	(4 << LPTIM_CFGR_TRIGSEL_SHIFT)
/* 5 is reserved */
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG6	(6 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG7	(7 << LPTIM_CFGR_TRIGSEL_SHIFT)
/**@}*/

#define LPTIM_CFGR_TRIGEN_SHIFT		17
#define LPTIM_CFGR_TRIGEN_MASK		0x07
#define LPTIM_CFGR_TRIGEN		(3 << LPTIM_CFGR_TRIGEN_SHIFT)
/** @defgroup LPTIM_CFGR_TRIGEN LPTIM_CFGR TRIGEN Trigger enable and polarity
@{*/
#define LPTIM_CFGR_TRIGEN_SW		(0 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_RISING	(1 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_FALLING	(2 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_BOTH		(3 << LPTIM_CFGR_TRIGEN_SHIFT)
/**@}*/

/** TIMOUT: Timeout enable */
#define LPTIM_CFGR_TIMOUT		(1 << 19)

/** WAVE: Waveform shape */
#define LPTIM_CFGR_WAVE			(1 << 20)

/** WAVPOL: Waveform shape polarity */
#define LPTIM_CFGR_WAVPOL		(1 << 21)

/** PRELOAD: Register update mode */
#define LPTIM_CFGR_PRELOAD		(1 << 22)

/** COUNTMODE: Counter mode enable */
#define LPTIM_CFGR_COUNTMODE		(1 << 23)

/** ENC: Encoder mode enable */
#define LPTIM_CFGR_ENC			(1 << 24)

/**@}*/

/** @defgroup lptim_cr LPTIM_CR Control Register
@{*/

/** ENABLE: LPTIM Enable */
#define LPTIM_CR_ENABLE			(1 << 0)

/** SNGSTRT: Start in Single Mode */
#define LPTIM_CR_SNGSTRT		(1 << 1)

/** CNGSTRT: Start in Continuous Mode */
#define LPTIM_CR_CNTSTRT		(1 << 2)

/**@}*/

/* --- LPTIM function prototypes --------------------------------------------- */

BEGIN_DECLS

void lptimer_enable(uint32_t timer_peripheral);
void lptimer_disable(uint32_t timer_peripheral);

void lptimer_start_counter(uint32_t timer_peripheral, uint32_t mode);
void lptimer_set_counter(uint32_t timer_peripheral, uint16_t count);
uint16_t lptimer_get_counter(uint32_t timer_peripheral);
void lptimer_set_compare(uint32_t timer_peripheral, uint16_t compare_value);
void lptimer_set_period(uint32_t lptimer_peripheral, uint16_t period_value);
void lptimer_enable_preload(uint32_t lptimer_peripheral);
void lptimer_disable_preload(uint32_t lptimer_peripheral);
void lptimer_set_waveform_polarity_high(uint32_t lptimer_peripheral);
void lptimer_set_waveform_polarity_low(uint32_t lptimer_peripheral);

void lptimer_set_prescaler(uint32_t timer_peripheral, uint32_t prescaler);
void lptimer_enable_trigger(uint32_t lptimer_peripheral, uint32_t trigen);
void lptimer_select_trigger_source(uint32_t lptimer_peripheral, uint32_t trigger_source);
void lptimer_set_internal_clock_source(uint32_t timer_peripheral);
void lptimer_set_external_clock_source(uint32_t timer_peripheral);

void lptimer_clear_flag(uint32_t timer_peripheral, uint32_t flag);
bool lptimer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void lptimer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void lptimer_disable_irq(uint32_t timer_peripheral, uint32_t irq);


END_DECLS

#endif
/** @cond */
#else
#warning "lptimer_common_all.h should not be included directly, only via lptimer.h"
#endif
/** @endcond */

/**@}*/
