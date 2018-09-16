/** @addtogroup rtc_defines

@author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>

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

/*
 * This covers the "version 2" RTC peripheral.  This is completely different
 * to the v1 RTC periph on the F1 series devices.  It has BCD counters, with
 * automatic leapyear corrections and daylight savings support.
 * This peripheral is used on the F0, F2, F3, F4 and L1 devices, though some
 * only support a subset.
 */

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA RTC.H
The order of header inclusion is important. rtc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_RTC_H
/** @endcond */
#ifndef LIBOPENCM3_RTC2_H
#define LIBOPENCM3_RTC2_H

/** @defgroup rtc_registers RTC Registers
 * @ingroup rtc_defines
 * @brief Real Time Clock registers
@{*/

/** RTC time register (RTC_TR) */
#define RTC_TR          MMIO32(RTC_BASE + 0x00)

/** RTC date register (RTC_DR) */
#define RTC_DR          MMIO32(RTC_BASE + 0x04)

/** RTC control register (RTC_CR) */
#define RTC_CR          MMIO32(RTC_BASE + 0x08)

/** RTC initialization and status register (RTC_ISR) */
#define RTC_ISR         MMIO32(RTC_BASE + 0x0c)

/** RTC prescaler register (RTC_PRER) */
#define RTC_PRER        MMIO32(RTC_BASE + 0x10)

/** RTC wakeup timer register (RTC_WUTR) */
#define RTC_WUTR        MMIO32(RTC_BASE + 0x14)

/** RTC calibration register (RTC_CALIBR) NB: see also RTC_CALR */
#define RTC_CALIBR      MMIO32(RTC_BASE + 0x18)

/** RTC alarm X register (RTC_ALRMxR) */
#define RTC_ALRMAR      MMIO32(RTC_BASE + 0x1c)
#define RTC_ALRMBR      MMIO32(RTC_BASE + 0x20)

/** RTC write protection register (RTC_WPR)*/
#define RTC_WPR         MMIO32(RTC_BASE + 0x24)

/** RTC sub second register (RTC_SSR) (high and med+ only) */
#define RTC_SSR         MMIO32(RTC_BASE + 0x28)

/** RTC shift control register (RTC_SHIFTR) (high and med+ only) */
#define RTC_SHIFTR      MMIO32(RTC_BASE + 0x2c)

/** RTC time stamp time register (RTC_TSTR) */
#define RTC_TSTR        MMIO32(RTC_BASE + 0x30)
/** RTC time stamp date register (RTC_TSDR) */
#define RTC_TSDR        MMIO32(RTC_BASE + 0x34)
/** RTC timestamp sub second register (RTC_TSSSR) (high and med+ only) */
#define RTC_TSSSR       MMIO32(RTC_BASE + 0x38)

/** RTC calibration register (RTC_CALR) (high and med+ only) */
#define RTC_CALR        MMIO32(RTC_BASE + 0x3c)

/** RTC tamper and alternate function configuration register (RTC_TAFCR) */
#define RTC_TAFCR       MMIO32(RTC_BASE + 0x40)

/** RTC alarm X sub second register (RTC_ALRMxSSR) (high and med+ only) */
#define RTC_ALRMASSR    MMIO32(RTC_BASE + 0x44)
#define RTC_ALRMBSSR    MMIO32(RTC_BASE + 0x48)

#define RTC_BKP_BASE    (RTC_BASE + 0x50)
/** RTC backup registers (RTC_BKPxR) */
#define RTC_BKPXR(reg)  MMIO32(RTC_BKP_BASE + (4 * (reg)))

/*@}*/


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
/*@}*/

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
#define RTC_DR_MT         (1<<12)
/** Month tens in BCD format mask */
#define RTC_DR_MT_SHIFT   (12)
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
/*@}*/

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
#define RTC_CR_COE    (1<<23)

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
/*@}*/

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
/** Course digital calibration enable */
#define RTC_CR_DCE              (1<<7)
/** Hour format */
#define RTC_CR_FMT              (1<<6)
/** Bypass the shadow registers */
#define RTC_CR_BYPSHAD          (1<<5)
/** Reference clock detection enable */
#define RTC_CR_REFCKON          (1<<4)
/** Timestamp event active edge */
#define RTC_CR_TSEDGE           (1<<3)

/* RTC_CR_WUCKSEL: Wakeup clock selection */
#define RTC_CR_WUCLKSEL_SHIFT      (0)
#define RTC_CR_WUCLKSEL_MASK       (0x7)
#define RTC_CR_WUCLKSEL_RTC_DIV16  (0x0)
#define RTC_CR_WUCLKSEL_RTC_DIV8   (0x1)
#define RTC_CR_WUCLKSEL_RTC_DIV4   (0x2)
#define RTC_CR_WUCLKSEL_RTC_DIV2   (0x3)
#define RTC_CR_WUCLKSEL_SPRE       (0x4)
#define RTC_CR_WUCLKSEL_SPRE_216   (0x6)
/*@}*/

/** @defgroup rtc_isr_values RTC initialization and status register (RTC_ISR) values
 * @ingroup rtc_registers
 * Note: Bits [31:17] and [15] are reserved, and must be kept at reset value.
 * Note: This register is write protected (except for RTC_ISR[13:8] bits).
@{*/
/** RECALPF: Recalib pending flag */
#define RTC_ISR_RECALPF            (1<<16)
/** TAMP3F: TAMPER3 detection flag (not on F4)*/
#define RTC_ISR_TAMP3F             (1<<15)
/** TAMP2F: TAMPER2 detection flag */
#define RTC_ISR_TAMP2F             (1<<14)
/** TAMP1F: TAMPER detection flag */
#define RTC_ISR_TAMP1F             (1<<13)
/** TSOVF: Timestamp overflow flag */
#define RTC_ISR_TSOVF              (1<<12)
/** TSF: Timestamp flag */
#define RTC_ISR_TSF                (1<<11)
/** WUTF: Wakeup timer flag */
#define RTC_ISR_WUTF               (1<<10)
/** ALRBF: Alarm B flag */
#define RTC_ISR_ALRBF              (1<<9)
/** ALRAF: Alarm A flag */
#define RTC_ISR_ALRAF              (1<<8)
/** INIT: Initialization mode */
#define RTC_ISR_INIT               (1<<7)
/** INITF: Initialization flag */
#define RTC_ISR_INITF              (1<<6)
/** RSF: Registers sync flag */
#define RTC_ISR_RSF                (1<<5)
/** INITS: Init status flag */
#define RTC_ISR_INITS              (1<<4)
/** SHPF: Shift operation pending */
#define RTC_ISR_SHPF               (1<<3)
/** WUTWF: Wakeup timer write flag */
#define RTC_ISR_WUTWF              (1<<2)
/** ALRBWF: Alarm B write flag */
#define RTC_ISR_ALRBWF             (1<<1)
/** ALRAWF: Alarm A write flag */
#define RTC_ISR_ALRAWF             (1<<0)
/*@}*/

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
/*@}*/

/* RTC calibration register (RTC_CALIBR) ------------------------ */
#define RTC_CALIBR_DCS            (1 << 7)

#define RTC_CALIBR_DC_SHIFT       (0)
#define RTC_CALIBR_DC_MASK        (0x1f)

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
/*@}*/

/* RTC shift control register (RTC_SHIFTR) ---------------------- */
#define RTC_SHIFTR_ADD1S          (31)

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
/*@}*/

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
/*@}*/

/** @defgroup rtc_calr_values RTC calibration register (RTC_CALR) values
 * @ingroup rtc_registers
@{*/
#define RTC_CALR_CALP             (1 << 15)
#define RTC_CALR_CALW8            (1 << 14)
#define RTC_CALR_CALW16           (1 << 13)
#define RTC_CALR_CALM_SHIFT       (0)
#define RTC_CALR_CALM_MASK        (0x1ff)
/*@}*/

/** @defgroup rtc_tafcr_values RTC tamper and alternate function configuration register (RTC_TAFCR) values
 * @ingroup rtc_registers
@{*/
#define RTC_TAFCR_ALARMOUTTYPE    (1<<18)
#define RTC_TAFCR_TAMPPUDIS       (1<<15)

#define RTC_TAFCR_TAMPPRCH_SHIFT  (13)
#define RTC_TAFCR_TAMPPRCH_MASK   (0x3)
#define RTC_TAFCR_TAMPPRCH_1RTC   (0x0)
#define RTC_TAFCR_TAMPPRCH_2RTC   (0x1)
#define RTC_TAFCR_TAMPPRCH_4RTC   (0x2)
#define RTC_TAFCR_TAMPPRCH_8RTC   (0x3)

#define RTC_TAFCR_TAMPFLT_SHIFT   (11)
#define RTC_TAFCR_TAMPFLT_MASK    (0x3)
#define RTC_TAFCR_TAMPFLT_EDGE1   (0x0)
#define RTC_TAFCR_TAMPFLT_EDGE2   (0x1)
#define RTC_TAFCR_TAMPFLT_EDGE4   (0x2)
#define RTC_TAFCR_TAMPFLT_EDGE8   (0x3)

#define RTC_TAFCR_TAMPFREQ_SHIFT     (8)
#define RTC_TAFCR_TAMPFREQ_MASK      (0x7)
#define RTC_TAFCR_TAMPFREQ_RTCDIV32K (0x0)
#define RTC_TAFCR_TAMPFREQ_RTCDIV16K (0x1)
#define RTC_TAFCR_TAMPFREQ_RTCDIV8K  (0x2)
#define RTC_TAFCR_TAMPFREQ_RTCDIV4K  (0x3)
#define RTC_TAFCR_TAMPFREQ_RTCDIV2K  (0x4)
#define RTC_TAFCR_TAMPFREQ_RTCDIV1K  (0x5)
#define RTC_TAFCR_TAMPFREQ_RTCDIV512 (0x6)
#define RTC_TAFCR_TAMPFREQ_RTCDIV256 (0x7)

#define RTC_TAFCR_TAMPTS          (1<<7)
#define RTC_TAFCR_TAMP3TRG        (1<<6)
#define RTC_TAFCR_TAMP3E          (1<<5)
#define RTC_TAFCR_TAMP2TRG        (1<<4)
#define RTC_TAFCR_TAMP2E          (1<<3)
#define RTC_TAFCR_TAMPIE          (1<<2)
#define RTC_TAFCR_TAMP1TRG        (1<<1)
#define RTC_TAFCR_TAMP1E          (1<<0)
/*@}*/

/* RTC alarm X sub second register ------------------------------ */
/* Note: Applies to RTC_ALRMASSR and RTC_ALRMBSSR */
#define RTC_ALRMXSSR_MASKSS_SHIFT (24)
#define RTC_ALARXSSR_MASKSS_MASK  (0xf)

#define RTC_ALRMXSSR_SS_SHIFT     (0)
#define RTC_ALARXSSR_SS_MASK      (0x7fff)


BEGIN_DECLS

void rtc_set_prescaler(uint32_t sync, uint32_t async);
void rtc_wait_for_synchro(void);
void rtc_lock(void);
void rtc_unlock(void);
void rtc_set_wakeup_time(uint16_t wkup_time, uint8_t rtc_cr_wucksel);
void rtc_clear_wakeup_flag(void);

END_DECLS
/**@}*/

#endif  /* RTC2_H */
/** @cond */
#else
#warning "rtc_common_l1f024.h should not be included explicitly, only via rtc.h"
#endif
/** @endcond */


