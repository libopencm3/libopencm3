/** @addtogroup rtc_defines
 * @author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>
 *
 * @brief This covers the "version 2" RTC peripheral.
 *
 * This is completely different
 * to the v1 RTC periph on the F1 series devices.  It has BCD counters, with
 * automatic leapyear corrections and daylight savings support.
 * This peripheral is used on the F0, F2, F3, F4 and L1 devices, though some
 * only support a subset. For L5 it's a bit different again so we modify it.
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

#ifndef LIBOPENCM3_RTC2_H
#define LIBOPENCM3_RTC2_H

/**@{*/

/** @defgroup rtc_registers RTC Registers
 * @ingroup rtc_defines
 * @brief Real Time Clock registers
@{*/

/** RTC time register (RTC_TR) */
#define RTC_TR          MMIO32(RTC_BASE + 0x00)

/** RTC date register (RTC_DR) */
#define RTC_DR          MMIO32(RTC_BASE + 0x04)

/** RTC sub second register (RTC_SSR) */
#define RTC_SSR          MMIO32(RTC_BASE + 0x08)

/** RTC initialization control and status register (RTC_ICSR) */
#define RTC_ICSR         MMIO32(RTC_BASE + 0x0c)

/** RTC prescaler register (RTC_PRER) */
#define RTC_PRER        MMIO32(RTC_BASE + 0x10)

/** RTC wakeup timer register (RTC_WUTR) */
#define RTC_WUTR        MMIO32(RTC_BASE + 0x14)

/** RTC control register (RTC_CR) */
#define RTC_CR		MMIO32(RTC_BASE + 0x18)

/** RTC privilege mode control register (RTC_PRIVCR) */
#define RTC_PRIVCR	MMIO32(RTC_BASE + 0x1c)

/** RTC secure mode control register (RTC_SMCR) */
#define RTC_SMCR	MMIO32(RTC_BASE + 0x20)

/** RTC write protection register (RTC_WPR)*/
#define RTC_WPR         MMIO32(RTC_BASE + 0x24)

/** RTC calibration register (RTC_CALR) */
#define RTC_CALR        MMIO32(RTC_BASE + 0x28)

/** RTC shift control register (RTC_SHIFTR) */
#define RTC_SHIFTR      MMIO32(RTC_BASE + 0x2c)

/** RTC time stamp time register (RTC_TSTR) */
#define RTC_TSTR        MMIO32(RTC_BASE + 0x30)
/** RTC time stamp date register (RTC_TSDR) */
#define RTC_TSDR        MMIO32(RTC_BASE + 0x34)
/** RTC timestamp sub second register (RTC_TSSSR) */
#define RTC_TSSSR       MMIO32(RTC_BASE + 0x38)

/** RTC alarm X register (RTC_ALRMxR) */
#define RTC_ALRMAR      MMIO32(RTC_BASE + 0x40)
#define RTC_ALRMBR      MMIO32(RTC_BASE + 0x48)

/** RTC alarm X sub second register (RTC_ALRMxR) */
#define RTC_ALRMASSR    MMIO32(RTC_BASE + 0x44)
#define RTC_ALRMBSSR    MMIO32(RTC_BASE + 0x4c)

/** RTC status register (RTC_SR) */
#define RTC_SR          MMIO32(RTC_BASE + 0x50)

/** RTC non-secure masked interrupt status register (RTC_MISR) */
#define RTC_MISR        MMIO32(RTC_BASE + 0x54)

/** RTC secure masked interrupt status register (RTC_SMISR) */
#define RTC_SMISR       MMIO32(RTC_BASE + 0x58)

/** RTC status clear register (RTC_SCR) */
#define RTC_SCR         MMIO32(RTC_BASE + 0x5c)

/**@}*/


/** @defgroup rtc_tr_values RTC Time register (RTC_TR) values
 * @ingroup rtc_registers
 * Note: Bits [31:23], 15, and 7 are reserved, and must be kept at reset value.
@{*/
/** AM/PM notation */
#define RTC_TR_PM         (1 << 22)
/** Hour tens in BCD format shift */
#define RTC_TR_HT_SHIFT   (20)
/** Hour tens in BCD format mask */
#define RTC_TR_HT_MASK    (0x3)
/** Hour units in BCD format shift */
#define RTC_TR_HU_SHIFT   (16)
/** Hour units in BCD format mask */
#define RTC_TR_HU_MASK    (0xf)
/** Minute tens in BCD format shift */
#define RTC_TR_MNT_SHIFT  (12)
/** Minute tens in BCD format mask */
#define RTC_TR_MNT_MASK   (0x7)
/** Minute units in BCD format shift */
#define RTC_TR_MNU_SHIFT  (8)
/** Minute units in BCD format mask */
#define RTC_TR_MNU_MASK   (0xf)
/** Second tens in BCD format shift */
#define RTC_TR_ST_SHIFT   (4)
/** Second tens in BCD format mask */
#define RTC_TR_ST_MASK    (0x7)
/** Second units in BCD format shift */
#define RTC_TR_SU_SHIFT   (0)
/** Second units in BCD format mask */
#define RTC_TR_SU_MASK    (0xf)
/**@}*/

/** @defgroup rtc_dr_values RTC Date register (RTC_DR) values
 * @ingroup rtc_registers
 * Note: Bits [31:24] and [7:6] are reserved, and must be kept at reset value.
@{*/
/** Year tens in BCD format shift */
#define RTC_DR_YT_SHIFT   (20)
/** Year tens in BCD format mask */
#define RTC_DR_YT_MASK    (0xf)
/** Year units in BCD format shift */
#define RTC_DR_YU_SHIFT   (16)
/** Year units in BCD format mask */
#define RTC_DR_YU_MASK    (0xf)
/** Weekday units shift */
#define RTC_DR_WDU_SHIFT  (13)
/** Weekday units mask */
#define RTC_DR_WDU_MASK   (0x7)
/** Month tens in BCD format shift */
#define RTC_DR_MT_SHIFT   (12)
/** Month tens in BCD format mask */
#define RTC_DR_MT_MASK    (1)
/** Month units in BCD format shift */
#define RTC_DR_MU_SHIFT   (8)
/** Month units in BCD format mask */
#define RTC_DR_MU_MASK    (0xf)
/** Date tens in BCD format shift */
#define RTC_DR_DT_SHIFT   (4)
/** Date tens in BCD format mask */
#define RTC_DR_DT_MASK    (0x3)
/** Date units in BCD format shift */
#define RTC_DR_DU_SHIFT   (0)
/** Date units in BCD format mask */
#define RTC_DR_DU_MASK    (0xf)
/**@}*/

/** @defgroup rtc_icsr_values RTC initialization control and status register (RTC_ICSR) values
 * @ingroup rtc_registers
 * Note: Bits [31:17] and [15] are reserved, and must be kept at reset value.
 * Note: This register is write protected (except for RTC_ICSR[13:8] bits).
@{*/
/** RECALPF: Recalib pending flag */
#define RTC_ICSR_RECALPF            (1<<16)
/** INIT: Initialization mode */
#define RTC_ICSR_INIT               (1<<7)
/** INITF: Initialization flag */
#define RTC_ICSR_INITF              (1<<6)
/** RSF: Registers sync flag */
#define RTC_ICSR_RSF                (1<<5)
/** INITS: Init status flag */
#define RTC_ICSR_INITS              (1<<4)
/** SHPF: Shift operation pending */
#define RTC_ICSR_SHPF               (1<<3)
/** WUTWF: Wakeup timer write flag */
#define RTC_ICSR_WUTWF              (1<<2)
/**@}*/

/** @defgroup rtc_prer_values RTC prescaler register (RTC_PRER) values
 * @ingroup rtc_registers
@{*/
/** Async prescaler factor shift */
#define RTC_PRER_PREDIV_A_SHIFT   (16)
/** Async prescaler factor mask */
#define RTC_PRER_PREDIV_A_MASK    (0x7f)
/** Sync prescaler factor shift */
#define RTC_PRER_PREDIV_S_SHIFT   (0)
/** Sync prescaler factor mask */
#define RTC_PRER_PREDIV_S_MASK    (0x7fff)
/**@}*/

/** @defgroup rtc_wutr_values RTC wakeup timer register (RTC_WUTR) values
 * @ingroup rtc_registers
@{*/
/** Wakeup auto-reload output clear value */
#define RTC_WUTR_WUTOCLR_SHIFT    (16)
/** Async prescaler factor mask */
#define RTC_WUTR_WUTOCLR_MASK     (0xffff)
/** Sync prescaler factor shift */
#define RTC_WUTR_WUT_SHIFT        (0)
/** Sync prescaler factor mask */
#define RTC_WUTR_WUT_MASK         (0xffff)
/**@}*/

/** @defgroup rtc_cr_values RTC control register (RTC_CR) values
 * @ingroup rtc_registers
 * Note: Bits [31:24] are reserved, and must be kept at reset value.
 * Note: Bits 7, 6 and 4 of this register can be written in initialization mode
 * only (RTC_ICSR/INITF = 1).
@{*/
/* Note: Bits 2 to 0 of this register can be written only when RTC_CR WUTE bit
 * = 0 and RTC_ICSR WUTWF bit = 1.
 */
/** RTC_OUT2 output enable */
#define RTC_CR_OUT2EN           (1<<31)
/** TAMPALRM output type */
#define RTC_CR_TAMPALRM_TYPE    (1<<30)
/** TAMPALRM pull-up enable */
#define RTC_CR_TAMPALRM_PU      (1<<29)
/** Tamper detection output enable on TAMPALRM */
#define RTC_CR_TAMPOE           (1<<26)
/** Activate timestamp on tamper detection event */
#define RTC_CR_TAMPTS           (1<<25)
/** timestamp on internal event enable */
#define RTC_CR_ITSE             (1<<24)
/** Calibration output enable */
#define RTC_CR_COE              (1<<23)

#define RTC_CR_OSEL_SHIFT       21
#define RTC_CR_OSEL_MASK        (0x3)
/** @defgroup rtc_cr_osel RTC_CR_OSEL: Output selection values
 * @ingroup rtc_cr_values
 * These bits are used to select the flag to be routed to AFO_ALARM RTC output
@{*/
#define RTC_CR_OSEL_DISABLED    (0x0)
#define RTC_CR_OSEL_ALARMA      (0x1)
#define RTC_CR_OSEL_ALARMB      (0x2)
#define RTC_CR_OSEL_WAKEUP      (0x3)
/**@}*/

/** Output polarity */
#define RTC_CR_POL              (1<<20)
/** Calibration output selection */
#define RTC_CR_COSEL            (1<<19)
/** Backup */
#define RTC_CR_BKP              (1<<18)
/** Subtract 1 hour (winter time change) */
#define RTC_CR_SUB1H            (1<<17)
/** Add 1 hour (summer time change) */
#define RTC_CR_ADD1H            (1<<16)
/** Timestamp interrupt enable */
#define RTC_CR_TSIE             (1<<15)
/** Wakeup timer interrupt enable */
#define RTC_CR_WUTIE            (1<<14)
/** Alarm B interrupt enable */
#define RTC_CR_ALRBIE           (1<<13)
/** Alarm A interrupt enable */
#define RTC_CR_ALRAIE           (1<<12)
/** Time stamp enable */
#define RTC_CR_TSE              (1<<11)
/** Wakeup timer enable */
#define RTC_CR_WUTE             (1<<10)
/** Alarm B enable */
#define RTC_CR_ALRBE            (1<<9)
/** Alarm A enable */
#define RTC_CR_ALRAE            (1<<8)
/** Hour format */
#define RTC_CR_FMT              (1<<6)
/** Bypass the shadow registers */
#define RTC_CR_BYPSHAD          (1<<5)
/** Reference clock detection enable */
#define RTC_CR_REFCKON          (1<<4)
/** Timestamp event active edge */
#define RTC_CR_TSEDGE           (1<<3)

/* RTC_CR_WUCKSEL: Wakeup clock selection */
#define RTC_CR_WUCKSEL_SHIFT      (0)
#define RTC_CR_WUCKSEL_MASK       (0x7)
#define RTC_CR_WUCKSEL_RTC_DIV16  (0x0)
#define RTC_CR_WUCKSEL_RTC_DIV8   (0x1)
#define RTC_CR_WUCKSEL_RTC_DIV4   (0x2)
#define RTC_CR_WUCKSEL_RTC_DIV2   (0x3)
#define RTC_CR_WUCKSEL_SPRE       (0x4)
#define RTC_CR_WUCKSEL_SPRE_216   (0x6)
/**@}*/

/** @defgroup rtc_smcr_values RTC secure mode control register values
 * @ingroup rtc_registers
@{*/
/** RTC global protection */
#define RTC_SMCR_DECPROT          (1<<15)
/** Initialization protection */
#define RTC_SMCR_INITDPROT        (1<<14)
/** Shift register, daylight saving, calibration and reference clock protection */
#define RTC_SMCR_CALDPROT         (1<<13)
/** Timestamp protection */
#define RTC_SMCR_TSDPROT          (1<<3)
/** Wakeup timer protection */
#define RTC_SMCR_WUTDPROT         (1<<2)
/** Alarm B protection */
#define RTC_SMCR_ALRBDPROT        (1<<1)
/** Alarm A protection */
#define RTC_SMCR_ALRADPROT        (1<<0)
/**@}*/

/** @defgroup rtc_calr_values RTC calibration register (RTC_CALR) values
 * @ingroup rtc_registers
@{*/
#define RTC_CALR_CALP             (1 << 15)
#define RTC_CALR_CALW8            (1 << 14)
#define RTC_CALR_CALW16           (1 << 13)
#define RTC_CALR_CALM_SHIFT       (0)
#define RTC_CALR_CALM_MASK        (0x1ff)
/**@}*/

/* RTC shift control register (RTC_SHIFTR) ---------------------- */
#define RTC_SHIFTR_ADD1S          (1<<31)

#define RTC_SHIFTR_SUBFS_SHIFT    (0)
#define RTC_SHIFTR_SUBFS_MASK     (0x7fff)

/** @defgroup rtc_tstr_values RTC time stamp time register (RTC_TSTR) values
 * @ingroup rtc_registers
@{*/
#define RTC_TSTR_PM               (1<<22)
#define RTC_TSTR_HT_SHIFT         (20)
#define RTC_TSTR_HT_MASK          (0x3)
#define RTC_TSTR_HU_SHIFT         (16)
#define RTC_TSTR_HU_MASK          (0xf)
#define RTC_TSTR_MNT_SHIFT        (12)
#define RTC_TSTR_MNT_MASK         (0x7)
#define RTC_TSTR_MNU_SHIFT        (8)
#define RTC_TSTR_MNU_MASK         (0xf)
#define RTC_TSTR_ST_SHIFT         (4)
#define RTC_TSTR_ST_MASK          (0x7)
#define RTC_TSTR_SU_SHIFT         (0)
#define RTC_TSTR_SU_MASK          (0xf)
/**@}*/

/** @defgroup rtc_tsdr_values RTC time stamp date register (RTC_TSDR) values
 * @ingroup rtc_registers
@{*/
#define RTC_TSDR_WDU_SHIFT        (13)
#define RTC_TSDR_WDU_MASK         (0x7)
#define RTC_TSDR_MT               (1<<12)
#define RTC_TSDR_MU_SHIFT         (8)
#define RTC_TSDR_MU_MASK          (0xf)
#define RTC_TSDR_DT_SHIFT         (4)
#define RTC_TSDR_DT_MASK          (0x3)
#define RTC_TSDR_DU_SHIFT         (0)
#define RTC_TSDR_DU_MASK          (0xf)
/**@}*/

/** @defgroup rtc_alarm_values RTC Alarm register values
 * @ingroup rtc_registers
 * Applies to RTC_ALRMAR and RTC_ALRMBR
@{*/
#define RTC_ALRMXR_MSK4           (1<<31)
#define RTC_ALRMXR_WDSEL          (1<<30)
#define RTC_ALRMXR_DT_SHIFT       (28)
#define RTC_ALRMXR_DT_MASK        (0x3)
#define RTC_ALRMXR_DU_SHIFT       (24)
#define RTC_ALRMXR_DU_MASK        (0xf)
#define RTC_ALRMXR_MSK3           (1<<23)
#define RTC_ALRMXR_PM             (1<<22)
#define RTC_ALRMXR_HT_SHIFT       (20)
#define RTC_ALRMXR_HT_MASK        (0x3)
#define RTC_ALRMXR_HU_SHIFT       (16)
#define RTC_ALRMXR_HU_MASK        (0xf)
#define RTC_ALRMXR_MSK2           (1<<15)
#define RTC_ALRMXR_MNT_SHIFT      (12)
#define RTC_ALRMXR_MNT_MASK       (0x7)
#define RTC_ALRMXR_MNU_SHIFT      (8)
#define RTC_ALRMXR_MNU_MASK       (0xf)
#define RTC_ALRMXR_MSK1           (1<<7)
#define RTC_ALRMXR_ST_SHIFT       (4)
#define RTC_ALRMXR_ST_MASK        (0x7)
#define RTC_ALRMXR_SU_SHIFT       (0)
#define RTC_ALRMXR_SU_MASK        (0xf)
/**@}*/

/* RTC alarm X sub second register ------------------------------ */
/* Note: Applies to RTC_ALRMASSR and RTC_ALRMBSSR */
#define RTC_ALRMXSSR_MASKSS_SHIFT (24)
#define RTC_ALARXSSR_MASKSS_MASK  (0xf)

#define RTC_ALRMXSSR_SS_SHIFT     (0)
#define RTC_ALARXSSR_SS_MASK      (0x7fff)

/** @defgroup rtc_sr_values RTC status register values
 * @ingroup rtc_registers
@{*/
/** Internal timestamp flag */
#define RTC_SR_ITSF               (1<<5)
/** Timestamp overflow flag */
#define RTC_SR_TSOVF              (1<<4)
/** Timestamp flag */
#define RTC_SR_TSF                (1<<3)
/** Wakeup timer flag */
#define RTC_SR_WUTF               (1<<2)
/** Alarm B flag */
#define RTC_SR_ALRBF              (1<<1)
/** Alarm A flag */
#define RTC_SR_ALRAF              (1<<0)
/**@}*/

/** @defgroup rtc_misr_values RTC non-secure masked interrupt status register values
 * @ingroup rtc_registers
@{*/
/** Internal timestamp non-secure masked flag */
#define RTC_MISR_ITSMF            (1<<5)
/** Timestamp overflow non-secure masked flag */
#define RTC_MISR_TSOVMF           (1<<4)
/** Timestamp non-secure masked flag */
#define RTC_MISR_TSMF             (1<<3)
/** Wakeup timer non-secure masked flag */
#define RTC_MISR_WUTMF            (1<<2)
/** Alarm B non-secure masked flag */
#define RTC_MISR_ALRBMF           (1<<1)
/** Alarm A masked flag */
#define RTC_MISR_ALRAMF           (1<<0)
/**@}*/

/** @defgroup rtc_smisr_values RTC secure masked interrupt status register values
 * @ingroup rtc_registers
@{*/
/** Internal timestamp interrupt secure masked flag */
#define RTC_SMISR_ITSMF           (1<<5)
/** Timestamp overflow interrupt secure masked flag */
#define RTC_SMISR_TSOVMF          (1<<4)
/** Timestamp interrupt secure masked flag */
#define RTC_SMISR_TSMF            (1<<3)
/** Wakeup timer interrupt secure masked flag */
#define RTC_SMISR_WUTMF           (1<<2)
/** Alarm B interrupt secure masked flag */
#define RTC_SMISR_ALRBMF          (1<<1)
/** Alarm A interrupt secure masked flag */
#define RTC_SMISR_ALRAMF          (1<<0)
/**@}*/

/** @defgroup rtc_scr_values RTC status clear register values
 * @ingroup rtc_registers
@{*/
/** Clear internal timestamp flag */
#define RTC_SCR_CITSF             (1<<5)
/** Clear timestamp overflow flag */
#define RTC_SCR_CTSOVF            (1<<4)
/** Clear timestamp flag */
#define RTC_SCR_CTSF              (1<<3)
/** Clear wakeup timer flag */
#define RTC_SCR_CWUTF             (1<<2)
/** Clear alarm B flag */
#define RTC_SCR_CALRBF            (1<<1)
/** Clear alarm A flag */
#define RTC_SCR_CALRAF            (1<<0)
/**@}*/

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

/* the following are taken from f4/rtc.h */
void rtc_enable_wakeup_timer(void);
void rtc_disable_wakeup_timer(void);
void rtc_enable_wakeup_timer_interrupt(void);
void rtc_disable_wakeup_timer_interrupt(void);

END_DECLS
/**@}*/

#endif  /* RTC2_H */
