/** @defgroup systemcontrol_defines System Control
 *
 * @ingroup MSP432E4xx_defines
 *
 * @brief Defined Constants and Types for the MSP432E4xx System Control
 *
 * @version 1.0.0
 *
 * @date 22 July 2018
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 * Copyright (C) 2018 Dmitry Rezvanov <dmitry.rezvanov@yandex.ru>
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

#ifndef MSP432E4_SYSTEMCONTROL_H
#define MSP432E4_SYSTEMCONTROL_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/msp432/e4/memorymap.h>

#define SYSCTL_DID0             MMIO32(SYSCTL_BASE + 0x000)
#define SYSCTL_DID1             MMIO32(SYSCTL_BASE + 0x004)
#define SYSCTL_PTBOCTL          MMIO32(SYSCTL_BASE + 0x038)
#define SYSCTL_RIS              MMIO32(SYSCTL_BASE + 0x050)
#define SYSCTL_IMC              MMIO32(SYSCTL_BASE + 0x054)
#define SYSCTL_MISC             MMIO32(SYSCTL_BASE + 0x058)
#define SYSCTL_RESC             MMIO32(SYSCTL_BASE + 0x05C)
#define SYSCTL_PWRTC            MMIO32(SYSCTL_BASE + 0x060)
#define SYSCTL_NMIC             MMIO32(SYSCTL_BASE + 0x064)
#define SYSCTL_MOSCCTL          MMIO32(SYSCTL_BASE + 0x07C)
#define SYSCTL_RSCLKCFG         MMIO32(SYSCTL_BASE + 0x0B0)
#define SYSCTL_MEMTIM0          MMIO32(SYSCTL_BASE + 0x0C0)
#define SYSCTL_ALTCLKCFG        MMIO32(SYSCTL_BASE + 0x138)
#define SYSCTL_DSCLKCFG         MMIO32(SYSCTL_BASE + 0x144)
#define SYSCTL_DIVSCLK          MMIO32(SYSCTL_BASE + 0x148)
#define SYSCTL_SYSPROP          MMIO32(SYSCTL_BASE + 0x14C)
#define SYSCTL_PIOSCCAL         MMIO32(SYSCTL_BASE + 0x150)
#define SYSCTL_PIOSCSTAT        MMIO32(SYSCTL_BASE + 0x154)
#define SYSCTL_PLLFREQ0         MMIO32(SYSCTL_BASE + 0x160)
#define SYSCTL_PLLFREQ1         MMIO32(SYSCTL_BASE + 0x164)
#define SYSCTL_PLLSTAT          MMIO32(SYSCTL_BASE + 0x168)
#define SYSCTL_SLPPWRCFG        MMIO32(SYSCTL_BASE + 0x188)
#define SYSCTL_DSLPPWRCFG       MMIO32(SYSCTL_BASE + 0x18C)
#define SYSCTL_NVMSTAT          MMIO32(SYSCTL_BASE + 0x1A0)
#define SYSCTL_LDOSPCTL         MMIO32(SYSCTL_BASE + 0x1B4)
#define SYSCTL_LDOSPCAL         MMIO32(SYSCTL_BASE + 0x1B8)
#define SYSCTL_LDODPCTL         MMIO32(SYSCTL_BASE + 0x1BC)
#define SYSCTL_LDODPCAL         MMIO32(SYSCTL_BASE + 0x1C0)
#define SYSCTL_SDPMST           MMIO32(SYSCTL_BASE + 0x1CC)
#define SYSCTL_RESBEHAVCTL      MMIO32(SYSCTL_BASE + 0x1D8)
#define SYSCTL_HSSR             MMIO32(SYSCTL_BASE + 0x1F4)
#define SYSCTL_USBPDS           MMIO32(SYSCTL_BASE + 0x280)
#define SYSCTL_USBMPC           MMIO32(SYSCTL_BASE + 0x284)
#define SYSCTL_EMACPDS          MMIO32(SYSCTL_BASE + 0x288)
#define SYSCTL_EMACMPC          MMIO32(SYSCTL_BASE + 0x28C)
#define SYSCTL_LCDPDS           MMIO32(SYSCTL_BASE + 0x290)
#define SYSCTL_LCDMPC           MMIO32(SYSCTL_BASE + 0x294)
#define SYSCTL_CAN0PDS          MMIO32(SYSCTL_BASE + 0x298)
#define SYSCTL_CAN0MPC          MMIO32(SYSCTL_BASE + 0x29C)
#define SYSCTL_CAN1PDS          MMIO32(SYSCTL_BASE + 0x2A0)
#define SYSCTL_CAN1MPC          MMIO32(SYSCTL_BASE + 0x2A4)

/* Peripheral present */
#define SYSCTL_PPWD             MMIO32(SYSCTL_BASE + 0x300)
#define SYSCTL_PPTIMER          MMIO32(SYSCTL_BASE + 0x304)
#define SYSCTL_PPGPIO           MMIO32(SYSCTL_BASE + 0x308)
#define SYSCTL_PPDMA            MMIO32(SYSCTL_BASE + 0x30C)
#define SYSCTL_PPEPI            MMIO32(SYSCTL_BASE + 0x310)
#define SYSCTL_PPHIB            MMIO32(SYSCTL_BASE + 0x314)
#define SYSCTL_PPUART           MMIO32(SYSCTL_BASE + 0x318)
#define SYSCTL_PPSSI            MMIO32(SYSCTL_BASE + 0x31C)
#define SYSCTL_PPI2C            MMIO32(SYSCTL_BASE + 0x320)
#define SYSCTL_PPUSB            MMIO32(SYSCTL_BASE + 0x328)
#define SYSCTL_PPEPHY           MMIO32(SYSCTL_BASE + 0x330)
#define SYSCTL_PPCAN            MMIO32(SYSCTL_BASE + 0x334)
#define SYSCTL_PPADC            MMIO32(SYSCTL_BASE + 0x338)
#define SYSCTL_PPACMP           MMIO32(SYSCTL_BASE + 0x33C)
#define SYSCTL_PPPWM            MMIO32(SYSCTL_BASE + 0x340)
#define SYSCTL_PPQEI            MMIO32(SYSCTL_BASE + 0x344)
#define SYSCTL_PPEEPROM         MMIO32(SYSCTL_BASE + 0x358)
#define SYSCTL_PPCCM            MMIO32(SYSCTL_BASE + 0x374)
#define SYSCTL_PPLCD            MMIO32(SYSCTL_BASE + 0x390)
#define SYSCTL_PPOWIRE          MMIO32(SYSCTL_BASE + 0x398)
#define SYSCTL_PPEMAC           MMIO32(SYSCTL_BASE + 0x39C)
#define SYSCTL_PPPRB            MMIO32(SYSCTL_BASE + 0x3A0)

/* Peripheral software reset */
#define SYSCTL_SRWD             MMIO32(SYSCTL_BASE + 0x500)
#define SYSCTL_SRTIMER          MMIO32(SYSCTL_BASE + 0x504)
#define SYSCTL_SRGPIO           MMIO32(SYSCTL_BASE + 0x508)
#define SYSCTL_SRDMA            MMIO32(SYSCTL_BASE + 0x50C)
#define SYSCTL_SREPI            MMIO32(SYSCTL_BASE + 0x510)
#define SYSCTL_SRHIB            MMIO32(SYSCTL_BASE + 0x514)
#define SYSCTL_SRUART           MMIO32(SYSCTL_BASE + 0x518)
#define SYSCTL_SRSSI            MMIO32(SYSCTL_BASE + 0x51C)
#define SYSCTL_SRI2C            MMIO32(SYSCTL_BASE + 0x520)
#define SYSCTL_SRUSB            MMIO32(SYSCTL_BASE + 0x528)
#define SYSCTL_SREPHY           MMIO32(SYSCTL_BASE + 0x530)
#define SYSCTL_SRCAN            MMIO32(SYSCTL_BASE + 0x534)
#define SYSCTL_SRADC            MMIO32(SYSCTL_BASE + 0x538)
#define SYSCTL_SRACMP           MMIO32(SYSCTL_BASE + 0x53C)
#define SYSCTL_SRPWM            MMIO32(SYSCTL_BASE + 0x540)
#define SYSCTL_SRQEI            MMIO32(SYSCTL_BASE + 0x544)
#define SYSCTL_SREEPROM         MMIO32(SYSCTL_BASE + 0x558)
#define SYSCTL_SRCCM            MMIO32(SYSCTL_BASE + 0x574)
#define SYSCTL_SRLCD            MMIO32(SYSCTL_BASE + 0x590)
#define SYSCTL_SROWIRE          MMIO32(SYSCTL_BASE + 0x598)
#define SYSCTL_SREMAC           MMIO32(SYSCTL_BASE + 0x59C)

/* Peripheral run mode clock gating control */
#define SYSCTL_RCGCWD           MMIO32(SYSCTL_BASE + 0x600)
#define SYSCTL_RCGCTIMER        MMIO32(SYSCTL_BASE + 0x604)
#define SYSCTL_RCGCGPIO         MMIO32(SYSCTL_BASE + 0x608)
#define SYSCTL_RCGCDMA          MMIO32(SYSCTL_BASE + 0x60C)
#define SYSCTL_RCGCHIB          MMIO32(SYSCTL_BASE + 0x614)
#define SYSCTL_RCGCUART         MMIO32(SYSCTL_BASE + 0x618)
#define SYSCTL_RCGCSSI          MMIO32(SYSCTL_BASE + 0x61C)
#define SYSCTL_RCGCI2C          MMIO32(SYSCTL_BASE + 0x620)
#define SYSCTL_RCGCUSB          MMIO32(SYSCTL_BASE + 0x628)
#define SYSCTL_RCGCEPHY         MMIO32(SYSCTL_BASE + 0x630)
#define SYSCTL_RCGCCAN          MMIO32(SYSCTL_BASE + 0x634)
#define SYSCTL_RCGCADC          MMIO32(SYSCTL_BASE + 0x638)
#define SYSCTL_RCGCACMP         MMIO32(SYSCTL_BASE + 0x63C)
#define SYSCTL_RCGCPWM          MMIO32(SYSCTL_BASE + 0x640)
#define SYSCTL_RCGCQEI          MMIO32(SYSCTL_BASE + 0x644)
#define SYSCTL_RCGCEEPROM       MMIO32(SYSCTL_BASE + 0x658)
#define SYSCTL_RCGCCCM          MMIO32(SYSCTL_BASE + 0x674)
#define SYSCTL_RCGCLCD          MMIO32(SYSCTL_BASE + 0x690)
#define SYSCTL_RCGCOWIRE        MMIO32(SYSCTL_BASE + 0x698)
#define SYSCTL_RCGCEMAC         MMIO32(SYSCTL_BASE + 0x69C)

/* Peripheral sleep mode clock gating control */
#define SYSCTL_SCGCWD           MMIO32(SYSCTL_BASE + 0x700)
#define SYSCTL_SCGCTIMER        MMIO32(SYSCTL_BASE + 0x704)
#define SYSCTL_SCGCGPIO         MMIO32(SYSCTL_BASE + 0x708)
#define SYSCTL_SCGCDMA          MMIO32(SYSCTL_BASE + 0x70C)
#define SYSCTL_SCGCEPI          MMIO32(SYSCTL_BASE + 0x710)
#define SYSCTL_SCGCHIB          MMIO32(SYSCTL_BASE + 0x714)
#define SYSCTL_SCGCUART         MMIO32(SYSCTL_BASE + 0x718)
#define SYSCTL_SCGCSSI          MMIO32(SYSCTL_BASE + 0x71C)
#define SYSCTL_SCGCI2C          MMIO32(SYSCTL_BASE + 0x720)
#define SYSCTL_SCGCUSB          MMIO32(SYSCTL_BASE + 0x728)
#define SYSCTL_SCGCEPHY         MMIO32(SYSCTL_BASE + 0x730)
#define SYSCTL_SCGCCAN          MMIO32(SYSCTL_BASE + 0x734)
#define SYSCTL_SCGCADC			MMIO32(SYSCTL_BASE + 0x738)
#define SYSCTL_SCGCACMP			MMIO32(SYSCTL_BASE + 0x73C)
#define SYSCTL_SCGCPWM			MMIO32(SYSCTL_BASE + 0x740)
#define SYSCTL_SCGCQEI			MMIO32(SYSCTL_BASE + 0x744)
#define SYSCTL_SCGCEEPROM		MMIO32(SYSCTL_BASE + 0x758)
#define SYSCTL_SCGCCCM          MMIO32(SYSCTL_BASE + 0x774)
#define SYSCTL_SCGCLCD          MMIO32(SYSCTL_BASE + 0x790)
#define SYSCTL_SCGCOWIRE        MMIO32(SYSCTL_BASE + 0x798)
#define SYSCTL_SCGCEMAC         MMIO32(SYSCTL_BASE + 0x79C)

/* Peripheral deep-sleep mode clock gating control */
#define SYSCTL_DCGCWD			MMIO32(SYSCTL_BASE + 0x800)
#define SYSCTL_DCGCTIMER		MMIO32(SYSCTL_BASE + 0x804)
#define SYSCTL_DCGCGPIO			MMIO32(SYSCTL_BASE + 0x808)
#define SYSCTL_DCGCDMA			MMIO32(SYSCTL_BASE + 0x80C)
#define SYSCTL_DCGCEPI          MMIO32(SYSCTL_BASE + 0x810)
#define SYSCTL_DCGCHIB			MMIO32(SYSCTL_BASE + 0x814)
#define SYSCTL_DCGCUART			MMIO32(SYSCTL_BASE + 0x818)
#define SYSCTL_DCGCSSI			MMIO32(SYSCTL_BASE + 0x81C)
#define SYSCTL_DCGCI2C			MMIO32(SYSCTL_BASE + 0x820)
#define SYSCTL_DCGCUSB			MMIO32(SYSCTL_BASE + 0x828)
#define SYSCTL_DCGCEPHY         MMIO32(SYSCTL_BASE + 0x830)
#define SYSCTL_DCGCCAN			MMIO32(SYSCTL_BASE + 0x834)
#define SYSCTL_DCGCADC			MMIO32(SYSCTL_BASE + 0x838)
#define SYSCTL_DCGCACMP			MMIO32(SYSCTL_BASE + 0x83C)
#define SYSCTL_DCGCPWM			MMIO32(SYSCTL_BASE + 0x840)
#define SYSCTL_DCGCQEI			MMIO32(SYSCTL_BASE + 0x844)
#define SYSCTL_DCGCEEPROM		MMIO32(SYSCTL_BASE + 0x858)
#define SYSCTL_DCGCCCM          MMIO32(SYSCTL_BASE + 0x874)
#define SYSCTL_DCGCLCD          MMIO32(SYSCTL_BASE + 0x890)
#define SYSCTL_DCGCOWIRE        MMIO32(SYSCTL_BASE + 0x898)
#define SYSCTL_DCGCEMAC         MMIO32(SYSCTL_BASE + 0x89C)

/* Power Control */
#define SYSCTL_PCWD             MMIO32(SYSCTL_BASE + 0x900)
#define SYSCTL_PCTIMER          MMIO32(SYSCTL_BASE + 0x904)
#define SYSCTL_PCGPIO           MMIO32(SYSCTL_BASE + 0x908)
#define SYSCTL_PCDMA            MMIO32(SYSCTL_BASE + 0x90C)
#define SYSCTL_PCEPI            MMIO32(SYSCTL_BASE + 0x910)
#define SYSCTL_PCHIB            MMIO32(SYSCTL_BASE + 0x914)
#define SYSCTL_PCUART           MMIO32(SYSCTL_BASE + 0x918)
#define SYSCTL_PCSSI            MMIO32(SYSCTL_BASE + 0x91C)
#define SYSCTL_PCI2C            MMIO32(SYSCTL_BASE + 0x920)
#define SYSCTL_PCUSB            MMIO32(SYSCTL_BASE + 0x928)
#define SYSCTL_PCEPHY           MMIO32(SYSCTL_BASE + 0x930)
#define SYSCTL_PCCAN            MMIO32(SYSCTL_BASE + 0x934)
#define SYSCTL_PCADC            MMIO32(SYSCTL_BASE + 0x938)
#define SYSCTL_PCACMP           MMIO32(SYSCTL_BASE + 0x93C)
#define SYSCTL_PCPWM            MMIO32(SYSCTL_BASE + 0x940)
#define SYSCTL_PCQEI            MMIO32(SYSCTL_BASE + 0x944)
#define SYSCTL_PCEEPROM         MMIO32(SYSCTL_BASE + 0x958)
#define SYSCTL_PCCCM            MMIO32(SYSCTL_BASE + 0x974)
#define SYSCTL_PCLCD            MMIO32(SYSCTL_BASE + 0x990)
#define SYSCTL_PCOWIRE          MMIO32(SYSCTL_BASE + 0x998)
#define SYSCTL_PCEMAC           MMIO32(SYSCTL_BASE + 0x99C)

/* Peripheral ready */
#define SYSCTL_PRWD             MMIO32(SYSCTL_BASE + 0xA00)
#define SYSCTL_PRTIMER          MMIO32(SYSCTL_BASE + 0xA04)
#define SYSCTL_PRGPIO           MMIO32(SYSCTL_BASE + 0xA08)
#define SYSCTL_PRDMA            MMIO32(SYSCTL_BASE + 0xA0C)
#define SYSCTL_PREPI            MMIO32(SYSCTL_BASE + 0xA10)
#define SYSCTL_PRHIB            MMIO32(SYSCTL_BASE + 0xA14)
#define SYSCTL_PRUART           MMIO32(SYSCTL_BASE + 0xA18)
#define SYSCTL_PRSSI            MMIO32(SYSCTL_BASE + 0xA1C)
#define SYSCTL_PRI2C            MMIO32(SYSCTL_BASE + 0xA20)
#define SYSCTL_PRUSB            MMIO32(SYSCTL_BASE + 0xA28)
#define SYSCTL_PREPHY           MMIO32(SYSCTL_BASE + 0xA30)
#define SYSCTL_PRCAN            MMIO32(SYSCTL_BASE + 0xA34)
#define SYSCTL_PRADC            MMIO32(SYSCTL_BASE + 0xA38)
#define SYSCTL_PRACMP           MMIO32(SYSCTL_BASE + 0xA3C)
#define SYSCTL_PRPWM            MMIO32(SYSCTL_BASE + 0xA40)
#define SYSCTL_PRQEI            MMIO32(SYSCTL_BASE + 0xA44)
#define SYSCTL_PREEPROM         MMIO32(SYSCTL_BASE + 0xA58)
#define SYSCTL_PRCCM            MMIO32(SYSCTL_BASE + 0xA74)
#define SYSCTL_PRLCD            MMIO32(SYSCTL_BASE + 0xA90)
#define SYSCTL_PROWIRE          MMIO32(SYSCTL_BASE + 0xA98)
#define SYSCTL_PREMAC           MMIO32(SYSCTL_BASE + 0xA9C)

/* Unique ID */
#define SYSCTL_UNIQUEID0        MMIO32(SYSCTL_BASE + 0xF20)
#define SYSCTL_UNIQUEID1        MMIO32(SYSCTL_BASE + 0xF24)
#define SYSCTL_UNIQUEID2        MMIO32(SYSCTL_BASE + 0xF28)
#define SYSCTL_UNIQUEID3        MMIO32(SYSCTL_BASE + 0xF2C)

/* SYSCTL Device Identification 0 Register (SYSCTL_DID0) -------------------- */
#define SYSCTL_DID0_VER_SHIFT       (28)   /* DID0 Version Shift */
#define SYSCTL_DID0_VER_MASK        (0x7)  /* DID0 Version Mask */
#define SYSCTL_DID0_CLASS_SHIFT     (16)   /* Device Class Shift */
#define SYSCTL_DID0_CLASS_MASK      (0xFF) /* Device Class Mask */
#define SYSCTL_DID0_MAJOR_SHIFT     (8)    /* Major Revision Shift */
#define SYSCTL_DID0_MAJOR_MASK      (0xFF) /* Major Revision Mask */
#define SYSCTL_DID0_MINOR_SHIFT     (0)    /* Minor Revision Shift */
#define SYSCTL_DID0_MINOR_MASK      (0xFF) /* Minor Revision Mask */

/* SYSCTL Device Identification 1 Register (SYSCTL_DID1) -------------------- */
#define SYSCTL_DID1_VER_SHIFT       (28)     /* DID1 Version Shift */
#define SYSCTL_DID1_VER_MASK        (0xF)    /* DID1 Version Mask */
#define SYSCTL_DID1_FAM_SHIFT       (24)     /* Family Shift */
#define SYSCTL_DID1_FAM_MASK        (0xF)    /* Family Mask */
#define SYSCTL_DID1_PARTNO_SHIFT    (16)     /* Part Number Shift */
#define SYSCTL_DID1_PARTNO_MASK     (0xFF)   /* Part Number Mask */
#define SYSCTL_DID1_PINCOUNT_SHIFT  (13)     /* Package Pin Count Shift */
#define SYSCTL_DID1_PINCOUNT_MASK   (0x7)    /* Package Pin Count Mask */
#define SYSCTL_DID1_PINCOUNT_128P   (0x6)    /* 128-pin package */
#define SYSCTL_DID1_PINCOUNT_212P   (0x7)    /* 212-pin package */
#define SYSCTL_DID1_TEMP_SHIFT      (5)      /* Temperature Range Shift */
#define SYSCTL_DID1_TEMP_MASK       (0x7)    /* Temperature Range Mask */
#define SYSCTL_DID1_TEMP_COMMERCIAL (0x0)    /* 0°C to +70°C */
#define SYSCTL_DID1_TEMP_INDUSTRIAL (0x1)    /* -40°C to +85°C */
#define SYSCTL_DID1_TEMP_EXTENDED   (0x2)    /* -40°C to +105°C */
#define SYSCTL_DID1_PKG_SHIFT       (3)      /* Package Type Shift */
#define SYSCTL_DID1_PKG_MASK        (0x3)    /* Package Type Mask */
#define SYSCTL_DID1_PKG_QFP         (0x1)    /* QFP package */
#define SYSCTL_DID1_PKG_BGA         (0x2)    /* BGA package */
#define SYSCTL_DID1_ROHS            (1 << 2) /* RoHS-compliance */
#define SYSCTL_DID1_QUAL_SHIFT      (0)      /* Qualification Status Shift */
#define SYSCTL_DID1_QUAL_MASK       (0x3)    /* Qualification Status Mask */
#define SYSCTL_DID1_QUAL_SAMPLE     (0x0)    /* Engineering Sample */
#define SYSCTL_DID1_QUAL_PILOT      (0x1)    /* Pilot Production */
#define SYSCTL_DID1_QUAL_QUALIFIED  (0x2)    /* Fully Qualified */

/* SYSCTL Power-Temp Brownout Control (SYSCTL_PTBOCTL) ---------------------- */
#define SYSCTL_PTBOCTL_VDDA_UBOR_SHIFT  (8)   /* VDDA_UBOR Shift */
#define SYSCTL_PTBOCTL_VDDA_UBOR_MASK   (0x3) /* VDDA_UBOR Mask */
#define SYSCTL_PTBOCTL_VDDA_UBOR_NO     (0x0) /* No action */
#define SYSCTL_PTBOCTL_VDDA_UBOR_INT    (0x1) /* System Control Interrupt */
#define SYSCTL_PTBOCTL_VDDA_UBOR_NMI    (0x2) /* Non-maskable interrupt */
#define SYSCTL_PTBOCTL_VDDA_UBOR_RESET  (0x3) /* Reset */
#define SYSCTL_PTBOCTL_VDD_UBOR_SHIFT   (1)   /* VDD_UBOR Shift */
#define SYSCTL_PTBOCTL_VDD_UBOR_MASK    (0x3) /* VDD_UBOR Mask */
#define SYSCTL_PTBOCTL_VDD_UBOR_NO      (0x0) /* No action */
#define SYSCTL_PTBOCTL_VDD_UBOR_INT     (0x1) /* System Control Interrupt */
#define SYSCTL_PTBOCTL_VDD_UBOR_NMI     (0x2) /* Non-maskable interrupt */
#define SYSCTL_PTBOCTL_VDD_UBOR_RESET   (0x3) /* Reset */

/* SYSCTL Raw Interrupt Status (SYSCTL_RIS) --------------------------------- */
#define SYSCTL_RIS_MOSCPUPRIS   (1 << 8) /* MOSC Power Up Raw Interrupt Status*/
#define SYSCTL_RIS_PLLLRIS      (1 << 6) /* PLL Lock Raw Interrupt Status */
#define SYSCTL_RIS_MOFRIS       (1 << 3) /* Main Oscillator Failure Raw
                                          * Interrupt Status */
#define SYSCTL_RIS_BORRIS       (1 << 1) /* Brown-Out Reset Raw Interrupt
                                          * Status */

/* SYSCTL Interrupt Mask Control (SYSCTL_IMC) ------------------------------- */
#define SYSCTL_IMC_MOSCPUPIM    (1 << 8) /* MOSC Power Up Raw Interrupt Status*/
#define SYSCTL_IMC_PLLLIM       (1 << 6) /* PLL Lock Raw Interrupt Status */
#define SYSCTL_IMC_MOFIM        (1 << 3) /* Main Oscillator Failure Raw
                                          * Interrupt Status */
#define SYSCTL_IMC_BORIM        (1 << 1) /* Brown-Out Reset Raw
                                          * Interrupt Status */

/* SYSCTL Masked Interrupt Status and Clear (SYSCTL_MISC) ------------------- */
#define SYSCTL_MISC_MOSCPUPMIS  (1 << 8) /* MOSC Power Up Raw Interrupt Status*/
#define SYSCTL_MISC_PLLLMIS     (1 << 6) /* PLL Lock Raw Interrupt Status */
#define SYSCTL_MISC_MOFMIS      (1 << 3) /* Main Oscillator Failure Raw
                                          * Interrupt Status */
#define SYSCTL_MISC_BORMIS      (1 << 1) /* Brown-Out Reset Raw
                                          * Interrupt Status */

/* SYSCTL Reset Cause Register (SYSCTL_RESC) -------------------------------- */
#define SYSCTL_RESC_MOSCFAIL    (1 << 16) /* MOSC Failure Reset */
#define SYSCTL_RESC_HSSR        (1 << 12) /* HSSR Reset */
#define SYSCTL_RESC_WDT1        (1 << 5)  /* Watchdog Timer 1 Reset */
#define SYSCTL_RESC_SW          (1 << 4)  /* Software Reset */
#define SYSCTL_RESC_WDT0        (1 << 3)  /* Watchdog Timer 0 Reset */
#define SYSCTL_RESC_BOR         (1 << 2)  /* Brown-Out Reset */
#define SYSCTL_RESC_POR         (1 << 1)  /* Power-On Reset */
#define SYSCTL_RESC_EXT         (1 << 0)  /* External Reset */

/* SYSCTL Power-Temperature Cause Register (SYSCTL_PWRTC) ------------------- */
#define SYSCTL_PWRTC_VDDA_UBOR  (1 << 4) /* VDDA Under BOR Status */
#define SYSCTL_PWRTC_VDD_UBOR   (1 << 0) /* VDD Under BOR Status */

/* SYSCTL NMI Cause Register (SYSCTL_NMIC) ---------------------------------- */
#define SYSCTL_NMIC_MOSCFAIL    (1 << 16) /* MOSC Failure NMI */
#define SYSCTL_NMIC_TAMPER      (1 << 9)  /* Tamper Event NMI */
#define SYSCTL_NMIC_WDT1        (1 << 5)  /* WDT1 NMI */
#define SYSCTL_NMIC_WDT0        (1 << 3)  /* WDT0 NMI */
#define SYSCTL_NMIC_POWER       (1 << 2)  /* Power/Brownout Event NMI */
#define SYSCTL_NMIC_EXTERNAL    (1 << 0)  /* External Pin NMI */

/* SYSCTL Main Oscillator Control (SYSCTL_MOSCCTL) -------------------------- */
#define SYSCTL_MOSCCTL_OSCRNG   (1 << 4) /* Oscillator Range */
#define SYSCTL_MOSCCTL_PWRDN    (1 << 3) /* Power Down */
#define SYSCTL_MOSCCTL_NOXTAL   (1 << 2) /* No MOSC or Crystal Connected */
#define SYSCTL_MOSCCTL_MOSCIM   (1 << 1) /* MOSC Failure Action */
#define SYSCTL_MOSCCTL_CVAL     (1 << 0) /* Clock Validation for MOSC */

/* SYSCTL Run and Sleep Mode Configuration Register (SYSCTL_RSCLKCFG) ------- */
#define SYSCTL_RSCLKCFG_MEMTIMU         (1 << 31) /* Memory Timing Update */
#define SYSCTL_RSCLKCFG_NEWFREQ         (1 << 30) /* New PLLFREQ Accept */
#define SYSCTL_RSCLKCFG_ACG             (1 << 29) /* Auto Clock Gating */
#define SYSCTL_RSCLKCFG_USEPLL          (1 << 28) /* Use PLL */
#define SYSCTL_RSCLKCFG_PLLSRC_SHIFT    (24)      /* PLL Source Shift */
#define SYSCTL_RSCLKCFG_PLLSRC_MASK     (0xF)     /* PLL Source Mask */
#define SYSCTL_RSCLKCFG_PLLSRC_MOSC     (0x3)     /* PLL Source - MOSC */
#define SYSCTL_RSCLKCFG_OSCSRC_SHIFT    (20)      /* OSCCLK Source Shift */
#define SYSCTL_RSCLKCFG_OSCSRC_MASK     (0xF)     /* OSCCLK Source Mask */
#define SYSCTL_RSCLKCFG_OSCSRC_LFIOSC   (0x2)     /* OSCCLK Source - LFIOSC */
#define SYSCTL_RSCLKCFG_OSCSRC_MOSC     (0x3)     /* OSCCLK Source - MOSC */
#define SYSCTL_RSCLKCFG_OSCSRC_RTCOSC   (0x4)     /* OSCCLK Source - RTCOSC */
#define SYSCTL_RSCLKCFG_OSYSDIV_SHIFT   (10)      /* Oscillator Divisor Shift */
#define SYSCTL_RSCLKCFG_OSYSDIV_MASK    (0x3FF)   /* Oscillator Divisor Mask */
#define SYSCTL_RSCLKCFG_PSYSDIV_SHIFT   (0)       /* PLL Divisor Shift */
#define SYSCTL_RSCLKCFG_PSYSDIV_MASK    (0x3FF)   /* PLL Divisor Mask */

/* SYSCTL Memory Timing Parameter Register 0 for Main Flash and EEPROM ------ */
#define SYSCTL_MEMTIM0_EBCHT_SHIFT      (22)  /* EEPROM Clock High Time Shift */
#define SYSCTL_MEMTIM0_EBCHT_MASK       (0xF) /* EEPROM Clock High Time Mask */
#define SYSCTL_MEMTIM0_EBCHT_0_POINT_5  (0x0) /* EBCHT - 0.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_1          (0x1) /* EBCHT - 1   sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_1_POINT_5  (0x2) /* EBCHT - 1.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_2          (0x3) /* EBCHT - 2   sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_2_POINT_5  (0x4) /* EBCHT - 2.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_3          (0x5) /* EBCHT - 3   sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_3_POINT_5  (0x6) /* EBCHT - 3.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_4          (0x7) /* EBCHT - 4   sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_4_POINT_5  (0x8) /* EBCHT - 4.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCE             (1 << 21) /* EEPROM Bank Clock Edge */
#define SYSCTL_MEMTIM0_EWS_SHIFT        (16)  /* EEPROM Wait States Shift */
#define SYSCTL_MEMTIM0_EWS_MASK         (0xF) /* EEPROM Wait States Mask */
#define SYSCTL_MEMTIM0_EWS_1            (0x1) /* EWS - 1 wait state */
#define SYSCTL_MEMTIM0_EWS_2            (0x2) /* EWS - 2 wait state */
#define SYSCTL_MEMTIM0_EWS_3            (0x3) /* EWS - 3 wait state */
#define SYSCTL_MEMTIM0_EWS_4            (0x4) /* EWS - 4 wait state */
#define SYSCTL_MEMTIM0_EWS_5            (0x5) /* EWS - 5 wait state */
#define SYSCTL_MEMTIM0_EWS_6            (0x6) /* EWS - 6 wait state */
#define SYSCTL_MEMTIM0_EWS_7            (0x7) /* EWS - 7 wait state */
#define SYSCTL_MEMTIM0_FBCHT_SHIFT      (6)   /* Flash Clock High Time Shift */
#define SYSCTL_MEMTIM0_FBCHT_MASK       (0xF) /* Flash Clock High Time Mask */
#define SYSCTL_MEMTIM0_FBCHT_0_POINT_5  (0x0) /* FBCHT - 0.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_1          (0x1) /* FBCHT - 1   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_1_POINT_5  (0x2) /* FBCHT - 1.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_2          (0x3) /* FBCHT - 2   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_2_POINT_5  (0x4) /* FBCHT - 2.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_3          (0x5) /* FBCHT - 3   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_3_POINT_5  (0x6) /* FBCHT - 3.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_4          (0x7) /* FBCHT - 4   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_4_POINT_5  (0x8) /* FBCHT - 4.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCE             (1 << 5) /* Flash Bank Clock Edge */
#define SYSCTL_MEMTIM0_FWS_SHIFT        (0)   /* Flash Wait States Shift */
#define SYSCTL_MEMTIM0_FWS_MASK         (0xF) /* Flash Wait States Mask */
#define SYSCTL_MEMTIM0_FWS_1            (0x1) /* FWS - 1 wait state */
#define SYSCTL_MEMTIM0_FWS_2            (0x2) /* FWS - 2 wait state */
#define SYSCTL_MEMTIM0_FWS_3            (0x3) /* FWS - 3 wait state */
#define SYSCTL_MEMTIM0_FWS_4            (0x4) /* FWS - 4 wait state */
#define SYSCTL_MEMTIM0_FWS_5            (0x5) /* FWS - 5 wait state */
#define SYSCTL_MEMTIM0_FWS_6            (0x6) /* FWS - 6 wait state */
#define SYSCTL_MEMTIM0_FWS_7            (0x7) /* FWS - 7 wait state */

/* SYSCTL Alternate Clock Configuration Register (SYSCTL_ALTCLKCFG) --------- */
#define SYSCTL_ALTCLKCFG_ALTCLK_SHIFT   (0)   /* Alternate Clock Source Shift */
#define SYSCTL_ALTCLKCFG_ALTCLK_MASK    (0xF) /* Alternate Clock Source Mask */
#define SYSCTL_ALTCLKCFG_ALTCLK_RTCOSC  (0x3) /* ALTCLK - RTCOSC */
#define SYSCTL_ALTCLKCFG_ALTCLK_LFIOSC  (0x4) /* ALTCLK - LFIOSC */

/* SYSCTL Deep Sleep Clock Configuration Register (SYSCTL_DSCLKCFG) --------- */
#define SYSCTL_DSCLKCFG_PIOSCPD         (1 << 31) /* PIOSC Power Down */
#define SYSCTL_DSCLKCFG_MOSCDPD         (1 << 30) /* MOSC Disable Power Down */
#define SYSCTL_DSCLKCFG_DSOSCSRC_SHIFT  (20)      /* DS Osc Source Shift */
#define SYSCTL_DSCLKCFG_DSOSCSRC_MASK   (0xF)     /* DS Osc Source Mask */
#define SYSCTL_DSCLKCFG_DSOSCSRC_LFIOSC (0x2)     /* DS Osc Source - LFIOSC */
#define SYSCTL_DSCLKCFG_DSOSCSRC_MOSC   (0x3)     /* DS Osc Source - MOSC */
#define SYSCTL_DSCLKCFG_DSOSCSRC_RTCOSC (0x4)     /* DS Osc Source - RTCOSC */
#define SYSCTL_DSCLKCFG_DSSYSDIV_SHIFT  (0)       /* DS Clock Divisor Shift */
#define SYSCTL_DSCLKCFG_DSSYSDIV_MASK   (0x3FF)   /* DS Clock Divisor Mask */

/* SYSCTL Divisor and Source Clock Configuration Register (SYSCTL_DIVSCLK) -- */
#define SYSCTL_DIVSCLK_EN         (1 << 31) /* DIVSCLK Enable */
#define SYSCTL_DIVSCLK_SRC_SHIFT  (16)      /* DIVSCLK Clock Source Shift */
#define SYSCTL_DIVSCLK_SRC_MASK   (0x3)     /* DIVSCLK Clock Source Mask */
#define SYSCTL_DIVSCLK_SRC_PIOSC  (0x1)     /* DIVSCLK Clock Source - PIOSCK */
#define SYSCTL_DIVSCLK_SRC_MOSC   (0x2)     /* DIVSCLK Clock Source - MOSC */
#define SYSCTL_DIVSCLK_DIV_SHIFT  (0)       /* DIVSCLK Divisor Value Shift */
#define SYSCTL_DIVSCLK_DIV_MASK   (0xF)     /* DIVSCLK Divisor Value Mask */
#define SYSCTL_DIVSCLK_DIV_1      (0x0)     /* DIVSCLK Divisor Value - 1 */
#define SYSCTL_DIVSCLK_DIV_2      (0x1)     /* DIVSCLK Divisor Value - 2 */

/* SYSCTL System Properties Register (SYSCLK_SYSPROP) ----------------------- */
#define SYSCTL_SYSPROP_LDOSME    (1 << 17) /* LDO Sleep Mode Enable */
#define SYSCTL_SYSPROP_TSPDE     (1 << 16) /* Temp Sense Power Down Enable */
#define SYSCTL_SYSPROP_PIOSCPDE  (1 << 12) /* PIOSC Power Down Present */
#define SYSCTL_SYSPROP_SRAMSM    (1 << 11) /* SRAM S\DS Standby Mode Present */
#define SYSCTL_SYSPROP_SRAMLPM   (1 << 10) /* SRAM S\DS LP Mode Present */
#define SYSCTL_SYSPROP_FLASHLPM  (1 << 8)  /* Flash S\DS LP Mode Present */
#define SYSCTL_SYSPROP_LDOSEQ    (1 << 5)  /* LDO Sequence Control Present */
#define SYSCTL_SYSPROP_FPU       (1 << 0)  /* FPU Present */

/* SYSCTL Precision Internal Oscillator Calibration Register (SYSCTL_PIOSCCAL)*/
#define SYSCTL_PIOSCCAL_UTEN      (1 << 31) /* Use User Trim Value */
#define SYSCTL_PIOSCCAL_CAL       (1 << 9)  /* Start Calibration */
#define SYSCTL_PIOSCCAL_UPDATE    (1 << 8)  /* Update Trim */
#define SYSCTL_PIOSCCAL_UT_SHIFT  (0)       /* User Trim Value Shift */
#define SYSCTL_PIOSCCAL_UT_MASK   (0x7F)    /* User Trim Value Mask */

/* SYSCTL Precision Internal Oscillator Statistic Register (SYSCTL_PIOSCSTAT) */
#define SYSCTL_PIOSCSTAT_DT_SHIFT           (16)   /* Default Trim Value Shift */
#define SYSCTL_PIOSCSTAT_DT_MASK            (0x7F) /* Default Trim Value Mask */
#define SYSCTL_PIOSCSTAT_RESULT_SHIFT       (8)    /* Calibration Result Shift */
#define SYSCTL_PIOSCSTAT_RESULT_MASK        (0x3)  /* Calibration Result Mask */
#define SYSCTL_PIOSCSTAT_RESULT_NOT_ATTEMPT (0x0)  /* Calibration Not Attempted */
#define SYSCTL_PIOSCSTAT_RESULT_COMPLETE    (0x1)  /* Calibration Completed */
#define SYSCTL_PIOSCSTAT_RESULT_FAIL        (0x2)  /* Calibration Failed */
#define SYSCTL_PIOSCSTAT_CT_SHIFT           (0)    /* Calibration Value Shift */
#define SYSCTL_PIOSCSTAT_CT_MASK            (0x7F) /* Calibration Value Mask */

/* SYSCTL PLL Frequency 0 Register (SYSCTL_PLLFREQ0) ------------------------ */
#define SYSCTL_PLLFREQ0_PLLPWR      (1 << 23) /* PLL Power */
#define SYSCTL_PLLFREQ0_MFRAC_SHIFT (10)      /* PLL M Fractional Value Shift */
#define SYSCTL_PLLFREQ0_MFRAC_MASK  (0x3FF)   /* PLL M Fractional Value Mask */
#define SYSCTL_PLLFREQ0_MINT_SHIFT  (0)       /* PLL M Integer Value Shift */
#define SYSCTL_PLLFREQ0_MINT_MASK   (0x3FF)   /* PLL M Integer Value Mask */

/* SYSCTL PLL Frequency 1 Register (SYSCTL_PLLFREQ1) ------------------------ */
#define SYSCTL_PLLFREQ1_Q_SHIFT (8)      /* PLL Q Value Shift */
#define SYSCTL_PLLFREQ1_Q_MASK  (0x1F)   /* PLL Q Value Mask */
#define SYSCTL_PLLFREQ1_N_SHIFT (0)      /* PLL N Value Shift */
#define SYSCTL_PLLFREQ1_N_MASK  (0x1F)   /* PLL N Value Mask */

/* SYSCTL PLL Status Register (SYSCTL_PLLSTAT) ------------------------------ */
#define SYSCTL_PLLSTAT_LOCK     (1 << 0) /* PLL Lock */

/* SYSCTL Sleep Power Configuration Register (SYSCTL_SLPPWRCFG) ------------- */
#define SYSCTL_SLPPWRCFG_FLASHPM_SHIFT   (4)   /* Flash Power Modes Shift */
#define SYSCTL_SLPPWRCFG_FLASHPM_MASK    (0x3) /* Flash Power Modes Mask */
#define SYSCTL_SLPPWRCFG_FLASHPM_ACTIVE  (0x0) /* Active mode */
#define SYSCTL_SLPPWRCFG_FLASHPM_LP      (0x2) /* Low-Power Mode */
#define SYSCTL_SLPPWRCFG_SRAMPM_SHIFT    (0)   /* SRAM Power Modes Shift */
#define SYSCTL_SLPPWRCFG_SRAMPM_MASK     (0x3) /* SRAM Power Modes Mask */
#define SYSCTL_SLPPWRCFG_SRAMPM_ACTIVE   (0x0) /* Active mode */
#define SYSCTL_SLPPWRCFG_SRAMPM_STANDBY  (0x1) /* Standby mode */
#define SYSCTL_SLPPWRCFG_SRAMPM_LP       (0x3) /* Low-Power Mode */

/* SYSCTL Deep-Sleep Power Configuration Register (SYSCTL_SLPPWRCFG) -------- */
#define SYSCTL_DSLPPWRCFG_LDOSM           (1 << 9) /* LDO Sleep Mode */
#define SYSCTL_DSLPPWRCFG_TSPD            (1 << 8) /* Temp Sense Power Down */
#define SYSCTL_DSLPPWRCFG_FLASHPM_SHIFT   (4)      /* Flash Power Modes Shift */
#define SYSCTL_DSLPPWRCFG_FLASHPM_MASK    (0x3)    /* Flash Power Modes Mask */
#define SYSCTL_DSLPPWRCFG_FLASHPM_ACTIVE  (0x0)    /* Active mode */
#define SYSCTL_DSLPPWRCFG_FLASHPM_LP      (0x2)    /* Low-Power Mode */
#define SYSCTL_DSLPPWRCFG_SRAMPM_SHIFT    (0)      /* SRAM Power Modes Shift */
#define SYSCTL_DSLPPWRCFG_SRAMPM_MASK     (0x3)    /* SRAM Power Modes Mask */
#define SYSCTL_DSLPPWRCFG_SRAMPM_ACTIVE   (0x0)    /* Active mode */
#define SYSCTL_DSLPPWRCFG_SRAMPM_STANDBY  (0x1)    /* Standby mode */
#define SYSCTL_DSLPPWRCFG_SRAMPM_LP       (0x3)    /* Low-Power Mode */

/* SYSCTL Non-Volatile Memory Information Register (SYSCTL_NVMSTAT) --------- */
#define SYSCTL_NVMSTAT_FWB  (1 << 0)  /* 32 Word Flash Write Buffer Available */

/* SYSCTL LDO Sleep Power Control Register (SYSCTL_LDOSPCTL) ---------------- */
#define SYSCTL_LDOSPCTL_VADJEN           (1 << 31) /* Voltage Adjust Enable */
#define SYSCTL_LDOSPCTL_VLDO_SHIFT       (0)       /* LDO Out Voltage Shift */
#define SYSCTL_LDOSPCTL_VLDO_MASK        (0xFF)    /* LDO Out Voltage Mask */
#define SYSCTL_LDOSPCTL_VLDO_0_POINT_90  (0x12)    /* LDO Out Voltage - 0.90V */
#define SYSCTL_LDOSPCTL_VLDO_0_POINT_95  (0x13)    /* LDO Out Voltage - 0.95V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_00  (0x14)    /* LDO Out Voltage - 1.00V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_05  (0x15)    /* LDO Out Voltage - 1.05V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_10  (0x16)    /* LDO Out Voltage - 1.10V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_15  (0x17)    /* LDO Out Voltage - 1.15V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_20  (0x18)    /* LDO Out Voltage - 1.20V */

/* SYSCTL LDO Sleep Power Calibration Register (SYSCTL_LDOSPCAL) ------------ */
#define SYSCTL_LDOSPCAL_WITHPLL_SHIFT  (8)    /* Sleep With PLL Shift */
#define SYSCTL_LDOSPCAL_WITHPLL_MASK   (0xFF) /* Sleep With PLL Mask */
#define SYSCTL_LDOSPCAL_NOPLL_SHIFT    (0)    /* Sleep Without PLL Shift */
#define SYSCTL_LDOSPCAL_NOPLL_MASK     (0xFF) /* Sleep Without PLL Mask */

/* SYSCTL LDO Deep-Sleep Power Control Register (SYSCTL_LDODPCTL) ----------- */
#define SYSCTL_LDODPCTL_VADJEN           (1 << 31) /* Voltage Adjust Enable */
#define SYSCTL_LDODPCTL_VLDO_SHIFT       (0)       /* LDO Out Voltage Shift */
#define SYSCTL_LDODPCTL_VLDO_MASK        (0xFF)    /* LDO Out Voltage Mask */
#define SYSCTL_LDODPCTL_VLDO_0_POINT_90  (0x12)    /* LDO Out Voltage - 0.90V */
#define SYSCTL_LDODPCTL_VLDO_0_POINT_95  (0x13)    /* LDO Out Voltage - 0.95V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_00  (0x14)    /* LDO Out Voltage - 1.00V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_05  (0x15)    /* LDO Out Voltage - 1.05V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_10  (0x16)    /* LDO Out Voltage - 1.10V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_15  (0x17)    /* LDO Out Voltage - 1.15V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_20  (0x18)    /* LDO Out Voltage - 1.20V */

/* SYSCTL LDO Deep-Sleep Power Calibration Register (SYSCTL_LDODPCAL) ------- */
#define SYSCTL_LDODPCAL_NOPLL_SHIFT  (8)    /* Deep-Sleep Without PLL Shift */
#define SYSCTL_LDODPCAL_NOPLL_MASK   (0xFF) /* Deep-Sleep Without PLL Mask */
#define SYSCTL_LDODPCAL_30KHZ_SHIFT  (0)    /* Deep-Sleep With IOSC Shift */
#define SYSCTL_LDODPCAL_30KHZ_MASK   (0xFF) /* Deep-Sleep With IOSC Mask */

/* SYSCTL Sleep\Deep-Sleep Power Mode Status Register (SYSCTL_SDPMST) ------- */
#define SYSCTL_SDPMST_LDOUA     (1 << 19) /* LDO Update Active */
#define SYSCTL_SDPMST_FLASHLP   (1 << 18) /* Flash in Low Power State */
#define SYSCTL_SDPMST_LOWPWR    (1 << 17) /* S\DS Mode */
#define SYSCTL_SDPMST_PRACT     (1 << 16) /* S\DS Power Request Active */
#define SYSCTL_SDPMST_PPDW      (1 << 7)  /* PIOSC Power Down Request Warning */
#define SYSCTL_SDPMST_LMAXERR   (1 << 6)  /* VLDO Value Above Max Error */
#define SYSCTL_SDPMST_LSMINERR  (1 << 4)  /* VLDO Value Below Min Error in S */
#define SYSCTL_SDPMST_LDMINERR  (1 << 3)  /* VLDO Value Below Min Error in DS*/
#define SYSCTL_SDPMST_PPDERR    (1 << 2)  /* PIOSC Power Down Request Error */
#define SYSCTL_SDPMST_FPDERR    (1 << 1)  /* Flash Power Down Request Error */
#define SYSCTL_SDPMST_SPDERR    (1 << 0)  /* SRAM Power Down Request Error */

/* SYSCTL Reset Behavior Control Register (SYSCTL_RESBEHAVCTL) -------------- */
#define SYSCTL_RESBEHAVCTL_WDOG1_SHIFT   (6)   /* WDOG1 Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_WDOG1_MASK    (0x3  /* WDOG1 Reset Operation Mask */
#define SYSCTL_RESBEHAVCTL_WDOG1_SYSRES  (0x2) /* WDOG1 - System Reset */
#define SYSCTL_RESBEHAVCTL_WDOG1_POR     (0x3) /* WDOG1 - Power-On-Reset */
#define SYSCTL_RESBEHAVCTL_WDOG0_SHIFT   (4)   /* WDOG0 Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_WDOG0_MASK    (0x3) /* WDOG0 Reset Operation Mask */
#define SYSCTL_RESBEHAVCTL_WDOG0_SYSRES  (0x2) /* WDOG0 - System Reset */
#define SYSCTL_RESBEHAVCTL_WDOG0_POR     (0x3) /* WDOG0 - Power-On-Reset */
#define SYSCTL_RESBEHAVCTL_BOR_SHIFT     (2)   /* BOR Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_BOR_MASK      (0x3) /* BOR Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_BOR_SYSRES    (0x2) /* BOR - System Reset */
#define SYSCTL_RESBEHAVCTL_BOR_POR       (0x3) /* BOR - Power-On-Reset */
#define SYSCTL_RESBEHAVCTL_EXTRES_SHIFT  (2)   /* EXT Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_EXTRES_MASK   (0x3) /* EXT Reset Operation Mask */
#define SYSCTL_RESBEHAVCTL_EXTRES_SYSRES (0x2) /* EXT Reset - System Reset */
#define SYSCTL_RESBEHAVCTL_EXTRES_POR    (0x3) /* EXT Reset - Power-On-Reset */

/* SYSCTL Hardware System Service Request Register (SYSCTL_HSSR) ------------ */
#define SYSCTL_HSSR_KEY_SHIFT    (24)       /* Write Key Shift */
#define SYSCTL_HSSR_KEY_MASK     (0xFF)     /* Write Key Mask */
#define SYSCTL_HSSR_KEY_VALUE    (0xCA)     /* Key Value for initiate request */
#define SYSCTL_HSSR_CDOFF_SHIFT  (0)        /* Command Descriptor Shift */
#define SYSCTL_HSSR_CDOFF_MASK   (0xFFFFFF) /* Command Descriptor Mask */
#define SYSCTL_HSSR_CDOFF_NO_REQ (0x000000) /* No Request */
#define SYSCTL_HSSR_CDOFF_ERROR  (0xFFFFFF) /* Error or not complete request */

/* SYSCTL USB Power Domain Status Register (SYSCTL_USBPDS) ------------------ */
#define SYSCTL_USBPDS_MEMSTAT_SHIFT     (2)   /* Memory Power Status Shift */
#define SYSCTL_USBPDS_MEMSTAT_MASK      (0x3) /* Memory Power Status Mask */
#define SYSCTL_USBPDS_MEMSTAT_ARR_OFF   (0x0) /* Memory Array Off */
#define SYSCTL_USBPDS_MEMSTAT_SRAM_RET  (0x1) /* SRAM Retention */
#define SYSCTL_USBPDS_MEMSTAT_ARR_ON    (0x3) /* Memory Array On */
#define SYSCTL_USBPDS_PWRSTAT_SHIFT     (0)   /* Power Domain Status Shift */
#define SYSCTL_USBPDS_PWRSTAT_MASK      (0x3) /* Power Domain Status Mask */
#define SYSCTL_USBPDS_PWRSTAT_OFF       (0x0) /* Power Domain Off */
#define SYSCTL_USBPDS_PWRSTAT_ON        (0x3) /* Power Domain On */

/* SYSCTL USB Memory Power Control Register (SYSCTL_USBMPC) ----------------- */
#define SYSCTL_USBMPC_PWRCTL_SHIFT    (0)   /* Memory Power Control Shift */
#define SYSCTL_USBMPC_PWRCTL_MASK     (0x3) /* Memory Power Control Mask */
#define SYSCTL_USBMPC_PWRCTL_ARR_OFF  (0x0) /* Memory Array Off */
#define SYSCTL_USBMPC_PWRCTL_SRAM_RET (0x1) /* SRAM Retention */
#define SYSCTL_USBMPC_PWRCTL_ARR_ON   (0x3) /* Memory Array On */

/* SYSCTL Ethernet Power Domain Status Register (SYSCTL_EMACPDS) ------------ */
#define SYSCTL_EMACPDS_MEMSTAT_SHIFT     (2)   /* Memory Power Status Shift */
#define SYSCTL_EMACPDS_MEMSTAT_MASK      (0x3) /* Memory Power Status Mask */
#define SYSCTL_EMACPDS_MEMSTAT_ARR_OFF   (0x0) /* Memory Array Off */
#define SYSCTL_EMACPDS_MEMSTAT_ARR_ON    (0x3) /* Memory Array On */
#define SYSCTL_EMACPDS_PWRSTAT_SHIFT     (0)   /* Power Domain Status Shift*/
#define SYSCTL_EMACPDS_PWRSTAT_MASK      (0x3) /* Power Domain Status Mask */
#define SYSCTL_EMACPDS_PWRSTAT_OFF       (0x0) /* Power Domain Off */
#define SYSCTL_EMACPDS_PWRSTAT_ON        (0x3) /* Power Domain On */

/* SYSCTL Ethernet Memory Power Control Register (SYSCTL_EMACMPC) ----------- */
#define SYSCTL_EMACMPC_PWRCTL_SHIFT    (0)   /* Memory Power Control Shift */
#define SYSCTL_EMACMPC_PWRCTL_MASK     (0x3) /* Memory Power Control Mask */
#define SYSCTL_EMACMPC_PWRCTL_ARR_OFF  (0x0) /* Memory Array Off */
#define SYSCTL_EMACMPC_PWRCTL_ARR_ON   (0x3) /* Memory Array On */

/* SYSCTL LCD Power Domain Status Register (SYSCTL_LCDPDS) ------------------ */
#define SYSCTL_LCDPDS_MEMSTAT_SHIFT     (2)   /* Memory Power Status Shift */
#define SYSCTL_LCDPDS_MEMSTAT_MASK      (0x3) /* Memory Power Status Mask */
#define SYSCTL_LCDPDS_MEMSTAT_ARR_OFF   (0x0) /* Memory Array Off */
#define SYSCTL_LCDPDS_MEMSTAT_ARR_ON    (0x3) /* Memory Array On */
#define SYSCTL_LCDPDS_PWRSTAT_SHIFT     (0)   /* Power Domain Status Shift*/
#define SYSCTL_LCDPDS_PWRSTAT_MASK      (0x3) /* Power Domain Status Mask */
#define SYSCTL_LCDPDS_PWRSTAT_OFF       (0x0) /* Power Domain Off */
#define SYSCTL_LCDPDS_PWRSTAT_ON        (0x3) /* Power Domain On */

/* SYSCTL LCD Memory Power Control Register (SYSCTL_LCDMPC) ----------------- */
#define SYSCTL_LCDMPC_PWRCTL_SHIFT    (0)   /* Memory Power Control Shift */
#define SYSCTL_LCDMPC_PWRCTL_MASK     (0x3) /* Memory Power Control Mask */
#define SYSCTL_LCDMPC_PWRCTL_ARR_OFF  (0x0) /* Memory Array Off */
#define SYSCTL_LCDMPC_PWRCTL_ARR_ON   (0x3) /* Memory Array On */

/* SYSCTL CAN0 Power Domain Status Register (SYSCTL_CAN0PDS) ---------------- */
#define SYSCTL_CAN0PDS_MEMSTAT_SHIFT     (2)   /* Memory Power Status Shift */
#define SYSCTL_CAN0PDS_MEMSTAT_MASK      (0x3) /* Memory Power Status Mask */
#define SYSCTL_CAN0PDS_MEMSTAT_ARR_OFF   (0x0) /* Memory Array Off */
#define SYSCTL_CAN0PDS_MEMSTAT_ARR_ON    (0x3) /* Memory Array On */
#define SYSCTL_CAN0PDS_PWRSTAT_SHIFT     (0)   /* Power Domain Status Shift*/
#define SYSCTL_CAN0PDS_PWRSTAT_MASK      (0x3) /* Power Domain Status Mask */
#define SYSCTL_CAN0PDS_PWRSTAT_OFF       (0x0) /* Power Domain Off */
#define SYSCTL_CAN0PDS_PWRSTAT_ON        (0x3) /* Power Domain On */

/* SYSCTL CAN0 Memory Power Control Register (SYSCTL_CAN0PDS) --------------- */
#define SYSCTL_CAN0MPC_PWRCTL_SHIFT    (0)   /* Memory Power Control Shift */
#define SYSCTL_CAN0MPC_PWRCTL_MASK     (0x3) /* Memory Power Control Mask */
#define SYSCTL_CAN0MPC_PWRCTL_ARR_OFF  (0x0) /* Memory Array Off */
#define SYSCTL_CAN0MPC_PWRCTL_ARR_ON   (0x3) /* Memory Array On */

/* SYSCTL CAN1 Power Domain Status Register (SYSCTL_CAN1PDS) ---------------- */
#define SYSCTL_CAN1PDS_MEMSTAT_SHIFT     (2)   /* Memory Power Status Shift */
#define SYSCTL_CAN1PDS_MEMSTAT_MASK      (0x3) /* Memory Power Status Mask */
#define SYSCTL_CAN1PDS_MEMSTAT_ARR_OFF   (0x0) /* Memory Array Off */
#define SYSCTL_CAN1PDS_MEMSTAT_ARR_ON    (0x3) /* Memory Array On */
#define SYSCTL_CAN1PDS_PWRSTAT_SHIFT     (0)   /* Power Domain Status Shift*/
#define SYSCTL_CAN1PDS_PWRSTAT_MASK      (0x3) /* Power Domain Status Mask */
#define SYSCTL_CAN1PDS_PWRSTAT_OFF       (0x0) /* Power Domain Off */
#define SYSCTL_CAN1PDS_PWRSTAT_ON        (0x3) /* Power Domain On */

/* SYSCTL CAN0 Memory Power Control Register (SYSCTL_CAN1PDS) --------------- */
#define SYSCTL_CAN1MPC_PWRCTL_SHIFT    (0)   /* Memory Power Control Shift */
#define SYSCTL_CAN1MPC_PWRCTL_MASK     (0x3) /* Memory Power Control Mask */
#define SYSCTL_CAN1MPC_PWRCTL_ARR_OFF  (0x0) /* Memory Array Off */
#define SYSCTL_CAN1MPC_PWRCTL_ARR_ON   (0x3) /* Memory Array On */

/**
 * @brief Clock mode definitions
 * The definitions are specified in the form offset from
 * SYSCTL_BASE
 * @li CLOCK_RUN        - Run mode
 * @li CLOCK_SLEEP      - Sleep mode
 * @li CLOCK_DEEP_SLEEP - Deep-Sleep Mode
 */
enum msp432_clock_mode {
    CLOCK_RUN = 0x600,
    CLOCK_SLEEP = 0x700,
    CLOCK_DEEP_SLEEP = 0x800
};

/**
 * @brief Power mode definitions
 *
 * @li POWER_DISABLE - Module is not powered and does not receive a clock
 * @li POWER_ENABLE  - Module is powered but does not receive a clock
 *
 * @note If the module is in run, sleep or deep-sleep mode - the module
 * is powered and receives a clock regardless of the value of power mode.
 */
enum msp432_power_mode {
    POWER_DISABLE = 0,
    POWER_ENABLE
};

#define _REG_BIT(base, bit)     (((base) << 5) + (bit))

/**
 * @brief Peripheral list definitions
 * The definitions are specified in the form
 * 31:5 register offset from first register for SR, PP, RCGC,
 * SCGC, DCGC, PC, PR
 * 4:0  bit offset for the given peripheral
 */
enum msp432_periph {

    PERIPH_WD0 = _REG_BIT(0x00, 0),
    PERIPH_WD1,

    PERIPH_TIMER0 = _REG_BIT(0x04, 0),
    PERIPH_TIMER1,
    PERIPH_TIMER2,
    PERIPH_TIMER3,
    PERIPH_TIMER4,
    PERIPH_TIMER5,
    PERIPH_TIMER6,
    PERIPH_TIMER7,

    PERIPH_GPIOA = _REG_BIT(0x08, 0),
    PERIPH_GPIOB,
    PERIPH_GPIOC,
    PERIPH_GPIOD,
    PERIPH_GPIOE,
    PERIPH_GPIOF,
    PERIPH_GPIOG,
    PERIPH_GPIOH,
    PERIPH_GPIOJ,
    PERIPH_GPIOK,
    PERIPH_GPIOL,
    PERIPH_GPIOM,
    PERIPH_GPION,
    PERIPH_GPIOP,
    PERIPH_GPIOQ,
    PERIPH_GPIOR,
    PERIPH_GPIOS,
    PERIPH_GPIOT,

    PERIPH_DMA = _REG_BIT(0x0C, 0),

    PERIPH_EPI = _REG_BIT(0x10, 0),

    PERIPH_HIB = _REG_BIT(0x14, 0),

    PERIPH_UART0 = _REG_BIT(0x18, 0),
    PERIPH_UART1,
    PERIPH_UART2,
    PERIPH_UART3,
    PERIPH_UART4,
    PERIPH_UART5,
    PERIPH_UART6,
    PERIPH_UART7,

    PERIPH_SSI0 = _REG_BIT(0x1C, 0),
    PERIPH_SSI1,
    PERIPH_SSI2,
    PERIPH_SSI3,

    PERIPH_I2C0 = _REG_BIT(0x20, 0),
    PERIPH_I2C1,
    PERIPH_I2C2,
    PERIPH_I2C3,
    PERIPH_I2C4,
    PERIPH_I2C5,
    PERIPH_I2C6,
    PERIPH_I2C7,
    PERIPH_I2C8,
    PERIPH_I2C9,

    PERIPH_USB0 = _REG_BIT(0x28, 0),

    PERIPH_EPHY = _REG_BIT(0x30, 0),

    PERIPH_CAN0 = _REG_BIT(0x34, 0),
    PERIPH_CAN1,

    PERIPH_ADC0 = _REG_BIT(0x38, 0),
    PERIPH_ADC1,

    PERIPH_ACMP = _REG_BIT(0x3C, 0),

    PERIPH_PWM = _REG_BIT(0x40, 0),

    PERIPH_QEI = _REG_BIT(0x44, 0),

    PERIPH_EEPROM = _REG_BIT(0x58, 0),

    PERIPH_CCM = _REG_BIT(0x74, 0),

    PERIPH_LCD = _REG_BIT(0x90, 0),

    PERIPH_OWIRE = _REG_BIT(0x98, 0),

    PERIPH_EMAC = _REG_BIT(0x9C, 0),

    PERIPH_PRB = _REG_BIT(0xA0, 0)
};

#undef _REG_BIT

/* Function prototypes ------------------------------------------------------ */

BEGIN_DECLS

void sysctl_periph_clock_enable(enum msp432_clock_mode clock_mode,
                                enum msp432_periph periph);
void sysctl_periph_clock_disable(enum msp432_clock_mode clock_mode,
                                 enum msp432_periph periph);

void sysctl_periph_reset(enum msp432_periph periph);
void sysctl_periph_clear_reset(enum msp432_periph periph);

bool sysctl_periph_is_present(enum msp432_periph periph);
bool sysctl_periph_is_ready(enum msp432_periph periph);
void sysctl_periph_set_power_state(enum msp432_power_mode power_mode,
                                   enum msp432_periph periph);

END_DECLS

#endif /* MSP432E4_SYSTEMCONTROL_H */

/**@}*/
