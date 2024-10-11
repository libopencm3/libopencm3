/** @addtogroup rtc_defines
 * @author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>
 *
 * @brief This covers the "version 2" RTC peripheral.
 *
 * This is completely different
 * to the v1 RTC periph on the F1 series devices.  It has BCD counters, with
 * automatic leapyear corrections and daylight savings support.
 * This peripheral is used on the F0, F2, F3, F4 and L1 devices, though some
 * only support a subset.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA RTC.H
The order of header inclusion is important. rtc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_RTC_H
/** @endcond */
#ifndef LIBOPENCM3_RTC2_H
#define LIBOPENCM3_RTC2_H

/**@{*/

/** @defgroup rtc_registers RTC Registers
 * @ingroup rtc_defines
 * @brief Real Time Clock registers
@{*/

/** RTC time register (RTC_TR) */
#define RTC_TR          MMIO32(RTC_BASE + 0x00U)

/** RTC date register (RTC_DR) */
#define RTC_DR          MMIO32(RTC_BASE + 0x04U)

/** RTC control register (RTC_CR) */
#define RTC_CR          MMIO32(RTC_BASE + 0x08U)

/** RTC initialization and status register (RTC_ISR) */
#define RTC_ISR         MMIO32(RTC_BASE + 0x0cU)

/** RTC prescaler register (RTC_PRER) */
#define RTC_PRER        MMIO32(RTC_BASE + 0x10U)

/** RTC wakeup timer register (RTC_WUTR) */
#define RTC_WUTR        MMIO32(RTC_BASE + 0x14U)

/** RTC calibration register (RTC_CALIBR) NB: see also RTC_CALR */
#define RTC_CALIBR      MMIO32(RTC_BASE + 0x18U)

/** RTC alarm X register (RTC_ALRMxR) */
#define RTC_ALRMAR      MMIO32(RTC_BASE + 0x1cU)
#define RTC_ALRMBR      MMIO32(RTC_BASE + 0x20U)

/** RTC write protection register (RTC_WPR)*/
#define RTC_WPR         MMIO32(RTC_BASE + 0x24U)

/** RTC sub second register (RTC_SSR) (high and med+ only) */
#define RTC_SSR         MMIO32(RTC_BASE + 0x28U)

/** RTC shift control register (RTC_SHIFTR) (high and med+ only) */
#define RTC_SHIFTR      MMIO32(RTC_BASE + 0x2cU)

/** RTC time stamp time register (RTC_TSTR) */
#define RTC_TSTR        MMIO32(RTC_BASE + 0x30U)
/** RTC time stamp date register (RTC_TSDR) */
#define RTC_TSDR        MMIO32(RTC_BASE + 0x34U)
/** RTC timestamp sub second register (RTC_TSSSR) (high and med+ only) */
#define RTC_TSSSR       MMIO32(RTC_BASE + 0x38U)

/** RTC calibration register (RTC_CALR) (high and med+ only) */
#define RTC_CALR        MMIO32(RTC_BASE + 0x3cU)

/** RTC tamper and alternate function configuration register (RTC_TAFCR) */
#define RTC_TAFCR       MMIO32(RTC_BASE + 0x40U)

/** RTC alarm X sub second register (RTC_ALRMxSSR) (high and med+ only) */
#define RTC_ALRMASSR    MMIO32(RTC_BASE + 0x44U)
#define RTC_ALRMBSSR    MMIO32(RTC_BASE + 0x48U)

#define RTC_OR          MMIO32(RTC_BASE + 0x4cU)

#define RTC_BKP_BASE    (RTC_BASE + 0x50U)
/** RTC backup registers (RTC_BKPxR) */
#define RTC_BKPXR(reg)  MMIO32(RTC_BKP_BASE + (4U * (reg)))

/**@}*/


/** @defgroup rtc_tr_values RTC Time register (RTC_TR) values
 * @ingroup rtc_registers
 * Note: Bits [31:23], 15, and 7 are reserved, and must be kept at reset value.
@{*/
/** AM/PM notation */
#define RTC_TR_PM         (1U << 22U)
/** Hour tens in BCD format shift */
#define RTC_TR_HT_SHIFT   (20U)
/** Hour tens in BCD format mask */
#define RTC_TR_HT_MASK    (0x3U)
/** Hour units in BCD format shift */
#define RTC_TR_HU_SHIFT   (16U)
/** Hour units in BCD format mask */
#define RTC_TR_HU_MASK    (0xfU)
/** Minute tens in BCD format shift */
#define RTC_TR_MNT_SHIFT  (12U)
/** Minute tens in BCD format mask */
#define RTC_TR_MNT_MASK   (0x7U)
/** Minute units in BCD format shift */
#define RTC_TR_MNU_SHIFT  (8U)
/** Minute units in BCD format mask */
#define RTC_TR_MNU_MASK   (0xfU)
/** Second tens in BCD format shift */
#define RTC_TR_ST_SHIFT   (4U)
/** Second tens in BCD format mask */
#define RTC_TR_ST_MASK    (0x7U)
/** Second units in BCD format shift */
#define RTC_TR_SU_SHIFT   (0U)
/** Second units in BCD format mask */
#define RTC_TR_SU_MASK    (0xfU)
/**@}*/

/** @defgroup rtc_dr_values RTC Date register (RTC_DR) values
 * @ingroup rtc_registers
 * Note: Bits [31:24] and [7:6] are reserved, and must be kept at reset value.
@{*/
/** Year tens in BCD format shift */
#define RTC_DR_YT_SHIFT   (20U)
/** Year tens in BCD format mask */
#define RTC_DR_YT_MASK    (0xfU)
/** Year units in BCD format shift */
#define RTC_DR_YU_SHIFT   (16U)
/** Year units in BCD format mask */
#define RTC_DR_YU_MASK    (0xfU)
/** Weekday units shift */
#define RTC_DR_WDU_SHIFT  (13U)
/** Weekday units mask */
#define RTC_DR_WDU_MASK   (0x7U)
/** Month tens in BCD format shift */
#define RTC_DR_MT_SHIFT   (12U)
/** Month tens in BCD format mask */
#define RTC_DR_MT_MASK    (1U)
/** Month units in BCD format shift */
#define RTC_DR_MU_SHIFT   (8U)
/** Month units in BCD format mask */
#define RTC_DR_MU_MASK    (0xfU)
/** Date tens in BCD format shift */
#define RTC_DR_DT_SHIFT   (4U)
/** Date tens in BCD format mask */
#define RTC_DR_DT_MASK    (0x3U)
/** Date units in BCD format shift */
#define RTC_DR_DU_SHIFT   (0U)
/** Date units in BCD format mask */
#define RTC_DR_DU_MASK    (0xfU)
/**@}*/

/** @defgroup rtc_cr_values RTC control register (RTC_CR) values
 * @ingroup rtc_registers
 * Note: Bits [31:24] are reserved, and must be kept at reset value.
 * Note: Bits 7, 6 and 4 of this register can be written in initialization mode
 * only (RTC_ISR/INITF = 1).
@{*/
/* Note: Bits 2 to 0 of this register can be written only when RTC_CR WUTE bit
 * = 0 and RTC_ISR WUTWF bit = 1.
 */
/** Calibration output enable */
#define RTC_CR_COE    (1U << 23U)

#define RTC_CR_OSEL_SHIFT       21U
#define RTC_CR_OSEL_MASK        (0x3U)
/** @defgroup rtc_cr_osel RTC_CR_OSEL: Output selection values
 * @ingroup rtc_cr_values
 * These bits are used to select the flag to be routed to AFO_ALARM RTC output
@{*/
#define RTC_CR_OSEL_DISABLED    (0x0U)
#define RTC_CR_OSEL_ALARMA      (0x1U)
#define RTC_CR_OSEL_ALARMB      (0x2U)
#define RTC_CR_OSEL_WAKEUP      (0x3U)
/**@}*/

/** Output polarity */
#define RTC_CR_POL              (1U << 20U)
/** Calibration output selection */
#define RTC_CR_COSEL            (1U << 19U)
/** Backup */
#define RTC_CR_BKP              (1U << 18U)
/** Subtract 1 hour (winter time change) */
#define RTC_CR_SUB1H            (1U << 17U)
/** Add 1 hour (summer time change) */
#define RTC_CR_ADD1H            (1U << 16U)
/** Timestamp interrupt enable */
#define RTC_CR_TSIE             (1U << 15U)
/** Wakeup timer interrupt enable */
#define RTC_CR_WUTIE            (1U << 14U)
/** Alarm B interrupt enable */
#define RTC_CR_ALRBIE           (1U << 13U)
/** Alarm A interrupt enable */
#define RTC_CR_ALRAIE           (1U << 12U)
/** Time stamp enable */
#define RTC_CR_TSE              (1U << 11U)
/** Wakeup timer enable */
#define RTC_CR_WUTE             (1U << 10U)
/** Alarm B enable */
#define RTC_CR_ALRBE            (1U << 9U)
/** Alarm A enable */
#define RTC_CR_ALRAE            (1U << 8U)
/** Course digital calibration enable */
#define RTC_CR_DCE              (1U << 7U)
/** Hour format */
#define RTC_CR_FMT              (1U << 6U)
/** Bypass the shadow registers */
#define RTC_CR_BYPSHAD          (1U << 5U)
/** Reference clock detection enable */
#define RTC_CR_REFCKON          (1U << 4U)
/** Timestamp event active edge */
#define RTC_CR_TSEDGE           (1U << 3U)

/* RTC_CR_WUCKSEL: Wakeup clock selection */
#define RTC_CR_WUCLKSEL_SHIFT      (0U)
#define RTC_CR_WUCLKSEL_MASK       (0x7U)
#define RTC_CR_WUCLKSEL_RTC_DIV16  (0x0U)
#define RTC_CR_WUCLKSEL_RTC_DIV8   (0x1U)
#define RTC_CR_WUCLKSEL_RTC_DIV4   (0x2U)
#define RTC_CR_WUCLKSEL_RTC_DIV2   (0x3U)
#define RTC_CR_WUCLKSEL_SPRE       (0x4U)
#define RTC_CR_WUCLKSEL_SPRE_216   (0x6U)
/**@}*/

/** @defgroup rtc_isr_values RTC initialization and status register (RTC_ISR) values
 * @ingroup rtc_registers
 * Note: Bits [31:17] and [15] are reserved, and must be kept at reset value.
 * Note: This register is write protected (except for RTC_ISR[13:8] bits).
@{*/
/** RECALPF: Recalib pending flag */
#define RTC_ISR_RECALPF            (1U << 16U)
/** TAMP3F: TAMPER3 detection flag (not on F4)*/
#define RTC_ISR_TAMP3F             (1U << 15U)
/** TAMP2F: TAMPER2 detection flag */
#define RTC_ISR_TAMP2F             (1U << 14U)
/** TAMP1F: TAMPER detection flag */
#define RTC_ISR_TAMP1F             (1U << 13U)
/** TSOVF: Timestamp overflow flag */
#define RTC_ISR_TSOVF              (1U << 12U)
/** TSF: Timestamp flag */
#define RTC_ISR_TSF                (1U << 11U)
/** WUTF: Wakeup timer flag */
#define RTC_ISR_WUTF               (1U << 10U)
/** ALRBF: Alarm B flag */
#define RTC_ISR_ALRBF              (1U << 9U)
/** ALRAF: Alarm A flag */
#define RTC_ISR_ALRAF              (1U << 8U)
/** INIT: Initialization mode */
#define RTC_ISR_INIT               (1U << 7U)
/** INITF: Initialization flag */
#define RTC_ISR_INITF              (1U << 6U)
/** RSF: Registers sync flag */
#define RTC_ISR_RSF                (1U << 5U)
/** INITS: Init status flag */
#define RTC_ISR_INITS              (1U << 4U)
/** SHPF: Shift operation pending */
#define RTC_ISR_SHPF               (1U << 3U)
/** WUTWF: Wakeup timer write flag */
#define RTC_ISR_WUTWF              (1U << 2U)
/** ALRBWF: Alarm B write flag */
#define RTC_ISR_ALRBWF             (1U << 1U)
/** ALRAWF: Alarm A write flag */
#define RTC_ISR_ALRAWF             (1U << 0U)
/**@}*/

/** @defgroup rtc_prer_values RTC prescaler register (RTC_PRER) values
 * @ingroup rtc_registers
@{*/
/** Async prescaler factor shift */
#define RTC_PRER_PREDIV_A_SHIFT   (16U)
/** Async prescaler factor mask */
#define RTC_PRER_PREDIV_A_MASK    (0x7fU)
/** Sync prescaler factor shift */
#define RTC_PRER_PREDIV_S_SHIFT   (0U)
/** Sync prescaler factor mask */
#define RTC_PRER_PREDIV_S_MASK    (0x7fffU)
/**@}*/

/* RTC calibration register (RTC_CALIBR) ------------------------ */
#define RTC_CALIBR_DCS            (1U << 7U)

#define RTC_CALIBR_DC_SHIFT       (0U)
#define RTC_CALIBR_DC_MASK        (0x1fU)

/** @defgroup rtc_alarm_values RTC Alarm register values
 * @ingroup rtc_registers
 * Applies to RTC_ALRMAR and RTC_ALRMBR
@{*/
#define RTC_ALRMXR_MSK4           (1U << 31U)
#define RTC_ALRMXR_WDSEL          (1U << 30U)
#define RTC_ALRMXR_DT_SHIFT       (28U)
#define RTC_ALRMXR_DT_MASK        (0x3U)
#define RTC_ALRMXR_DU_SHIFT       (24U)
#define RTC_ALRMXR_DU_MASK        (0xfU)
#define RTC_ALRMXR_MSK3           (1U << 23U)
#define RTC_ALRMXR_PM             (1U << 22U)
#define RTC_ALRMXR_HT_SHIFT       (20U)
#define RTC_ALRMXR_HT_MASK        (0x3U)
#define RTC_ALRMXR_HU_SHIFT       (16U)
#define RTC_ALRMXR_HU_MASK        (0xfU)
#define RTC_ALRMXR_MSK2           (1U << 15U)
#define RTC_ALRMXR_MNT_SHIFT      (12U)
#define RTC_ALRMXR_MNT_MASK       (0x7U)
#define RTC_ALRMXR_MNU_SHIFT      (8U)
#define RTC_ALRMXR_MNU_MASK       (0xfU)
#define RTC_ALRMXR_MSK1           (1U << 7U)
#define RTC_ALRMXR_ST_SHIFT       (4U)
#define RTC_ALRMXR_ST_MASK        (0x7U)
#define RTC_ALRMXR_SU_SHIFT       (0U)
#define RTC_ALRMXR_SU_MASK        (0xfU)
/**@}*/

/* RTC shift control register (RTC_SHIFTR) ---------------------- */
#define RTC_SHIFTR_ADD1S          (1U << 31U)

#define RTC_SHIFTR_SUBFS_SHIFT    (0U)
#define RTC_SHIFTR_SUBFS_MASK     (0x7fffU)

/** @defgroup rtc_tstr_values RTC time stamp time register (RTC_TSTR) values
 * @ingroup rtc_registers
@{*/
#define RTC_TSTR_PM               (1U << 22U)
#define RTC_TSTR_HT_SHIFT         (20U)
#define RTC_TSTR_HT_MASK          (0x3U)
#define RTC_TSTR_HU_SHIFT         (16U)
#define RTC_TSTR_HU_MASK          (0xfU)
#define RTC_TSTR_MNT_SHIFT        (12U)
#define RTC_TSTR_MNT_MASK         (0x7U)
#define RTC_TSTR_MNU_SHIFT        (8U)
#define RTC_TSTR_MNU_MASK         (0xfU)
#define RTC_TSTR_ST_SHIFT         (4U)
#define RTC_TSTR_ST_MASK          (0x7U)
#define RTC_TSTR_SU_SHIFT         (0U)
#define RTC_TSTR_SU_MASK          (0xfU)
/**@}*/

/** @defgroup rtc_tsdr_values RTC time stamp date register (RTC_TSDR) values
 * @ingroup rtc_registers
@{*/
#define RTC_TSDR_WDU_SHIFT        (13U)
#define RTC_TSDR_WDU_MASK         (0x7U)
#define RTC_TSDR_MT               (1U << 12U)
#define RTC_TSDR_MU_SHIFT         (8U)
#define RTC_TSDR_MU_MASK          (0xfU)
#define RTC_TSDR_DT_SHIFT         (4U)
#define RTC_TSDR_DT_MASK          (0x3U)
#define RTC_TSDR_DU_SHIFT         (0U)
#define RTC_TSDR_DU_MASK          (0xfU)
/**@}*/

/** @defgroup rtc_calr_values RTC calibration register (RTC_CALR) values
 * @ingroup rtc_registers
@{*/
#define RTC_CALR_CALP             (1U << 15U)
#define RTC_CALR_CALW8            (1U << 14U)
#define RTC_CALR_CALW16           (1U << 13U)
#define RTC_CALR_CALM_SHIFT       (0U)
#define RTC_CALR_CALM_MASK        (0x1ffU)
/**@}*/

/** @defgroup rtc_tafcr_values RTC tamper and alternate function configuration register (RTC_TAFCR) values
 * @ingroup rtc_registers
@{*/
#define RTC_TAFCR_ALARMOUTTYPE    (1U << 18U)
#define RTC_TAFCR_TAMPPUDIS       (1U << 15U)

#define RTC_TAFCR_TAMPPRCH_SHIFT  (13U)
#define RTC_TAFCR_TAMPPRCH_MASK   (0x3U)
#define RTC_TAFCR_TAMPPRCH_1RTC   (0x0U)
#define RTC_TAFCR_TAMPPRCH_2RTC   (0x1U)
#define RTC_TAFCR_TAMPPRCH_4RTC   (0x2U)
#define RTC_TAFCR_TAMPPRCH_8RTC   (0x3U)

#define RTC_TAFCR_TAMPFLT_SHIFT   (11U)
#define RTC_TAFCR_TAMPFLT_MASK    (0x3U)
#define RTC_TAFCR_TAMPFLT_EDGE1   (0x0U)
#define RTC_TAFCR_TAMPFLT_EDGE2   (0x1U)
#define RTC_TAFCR_TAMPFLT_EDGE4   (0x2U)
#define RTC_TAFCR_TAMPFLT_EDGE8   (0x3U)

#define RTC_TAFCR_TAMPFREQ_SHIFT     (8U)
#define RTC_TAFCR_TAMPFREQ_MASK      (0x7U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV32K (0x0U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV16K (0x1U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV8K  (0x2U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV4K  (0x3U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV2K  (0x4U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV1K  (0x5U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV512 (0x6U)
#define RTC_TAFCR_TAMPFREQ_RTCDIV256 (0x7U)

#define RTC_TAFCR_TAMPTS          (1U << 7U)
#define RTC_TAFCR_TAMP3TRG        (1U << 6U)
#define RTC_TAFCR_TAMP3E          (1U << 5U)
#define RTC_TAFCR_TAMP2TRG        (1U << 4U)
#define RTC_TAFCR_TAMP2E          (1U << 3U)
#define RTC_TAFCR_TAMPIE          (1U << 2U)
#define RTC_TAFCR_TAMP1TRG        (1U << 1U)
#define RTC_TAFCR_TAMP1E          (1U << 0U)
/**@}*/

/* RTC alarm X sub second register ------------------------------ */
/* Note: Applies to RTC_ALRMASSR and RTC_ALRMBSSR */
#define RTC_ALRMXSSR_MASKSS_SHIFT (24U)
#define RTC_ALARXSSR_MASKSS_MASK  (0xfU)

#define RTC_ALRMXSSR_SS_SHIFT     (0U)
#define RTC_ALARXSSR_SS_MASK      (0x7fffU)

enum rtc_weekday {
	RTC_DR_WDU_MON = 0x01,
	RTC_DR_WDU_TUE,
	RTC_DR_WDU_WED,
	RTC_DR_WDU_THU,
	RTC_DR_WDU_FRI,
	RTC_DR_WDU_SAT,
	RTC_DR_WDU_SUN,
};

BEGIN_DECLS

void rtc_set_prescaler(uint32_t sync, uint32_t async);
void rtc_wait_for_synchro(void);
void rtc_lock(void);
void rtc_unlock(void);
void rtc_set_wakeup_time(uint16_t wkup_time, uint8_t rtc_cr_wucksel);
void rtc_clear_wakeup_flag(void);
void rtc_set_init_flag(void);
void rtc_clear_init_flag(void);
bool rtc_init_flag_is_ready(void);
void rtc_wait_for_init_ready(void);
void rtc_set_bypass_shadow_register(void);
void rtc_enable_bypass_shadow_register(void);
void rtc_disable_bypass_shadow_register(void);
void rtc_set_am_format(void);
void rtc_set_pm_format(void);
void rtc_calendar_set_year(uint8_t year);
void rtc_calendar_set_weekday(enum rtc_weekday rtc_dr_wdu);
void rtc_calendar_set_month(uint8_t month);
void rtc_calendar_set_day(uint8_t day);
void rtc_calendar_set_date(uint8_t year, uint8_t month, uint8_t day, enum rtc_weekday rtc_dr_wdu);
void rtc_time_set_hour(uint8_t hour, bool use_am_notation);
void rtc_time_set_minute(uint8_t minute);
void rtc_time_set_second(uint8_t second);
void rtc_time_set_time(uint8_t hour, uint8_t minute, uint8_t second, bool use_am_notation);

END_DECLS
/**@}*/

#endif  /* RTC2_H */
/** @cond */
#else
#warning "rtc_common_l1f024.h should not be included explicitly, only via rtc.h"
#endif
/** @endcond */
