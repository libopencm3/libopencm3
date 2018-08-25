/** @defgroup systemcontrol_defines System Control Defines
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

#ifndef MSP432E4_SYSTEMCONTROL_H
#define MSP432E4_SYSTEMCONTROL_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/msp432/e4/memorymap.h>
#include <stdbool.h>

/** @defgroup sysctl_registers SYSCTL Registers
 * @brief System Control Registers
@{*/
/** Device Identification 0 */
#define SYSCTL_DID0             MMIO32(SYSCTL_BASE + 0x000)
/** Device Identification 1 */
#define SYSCTL_DID1             MMIO32(SYSCTL_BASE + 0x004)
/** Power-Temp Brownout Control */
#define SYSCTL_PTBOCTL          MMIO32(SYSCTL_BASE + 0x038)
/** Raw Interrupt Status */
#define SYSCTL_RIS              MMIO32(SYSCTL_BASE + 0x050)
/** Interrupt Mask Control */
#define SYSCTL_IMC              MMIO32(SYSCTL_BASE + 0x054)
/** RW1C Masked Interrupt Status and Clear */
#define SYSCTL_MISC             MMIO32(SYSCTL_BASE + 0x058)
/** Reset Cause */
#define SYSCTL_RESC             MMIO32(SYSCTL_BASE + 0x05C)
/** RW1C Power-Temperature Cause */
#define SYSCTL_PWRTC            MMIO32(SYSCTL_BASE + 0x060)
/** NMI Cause Register */
#define SYSCTL_NMIC             MMIO32(SYSCTL_BASE + 0x064)
/** Main Oscillator Control */
#define SYSCTL_MOSCCTL          MMIO32(SYSCTL_BASE + 0x07C)
/** Run and Sleep Mode Configuration Register */
#define SYSCTL_RSCLKCFG         MMIO32(SYSCTL_BASE + 0x0B0)
/** Memory Timing Parameter Register 0 for Main Flash and EEPROM */
#define SYSCTL_MEMTIM0          MMIO32(SYSCTL_BASE + 0x0C0)
/** Alternate Clock Configuration */
#define SYSCTL_ALTCLKCFG        MMIO32(SYSCTL_BASE + 0x138)
/** Deep Sleep Clock Configuration Register */
#define SYSCTL_DSCLKCFG         MMIO32(SYSCTL_BASE + 0x144)
/** Divisor and Source Clock Configuration */
#define SYSCTL_DIVSCLK          MMIO32(SYSCTL_BASE + 0x148)
/** System Properties */
#define SYSCTL_SYSPROP          MMIO32(SYSCTL_BASE + 0x14C)
/** Precision Internal Oscillator Calibration */
#define SYSCTL_PIOSCCAL         MMIO32(SYSCTL_BASE + 0x150)
/** Precision Internal Oscillator Statistics */
#define SYSCTL_PIOSCSTAT        MMIO32(SYSCTL_BASE + 0x154)
/** PLL Frequency 0 */
#define SYSCTL_PLLFREQ0         MMIO32(SYSCTL_BASE + 0x160)
/** PLL Frequency 1 */
#define SYSCTL_PLLFREQ1         MMIO32(SYSCTL_BASE + 0x164)
/** PLL Status */
#define SYSCTL_PLLSTAT          MMIO32(SYSCTL_BASE + 0x168)
/** Sleep Power Configuration */
#define SYSCTL_SLPPWRCFG        MMIO32(SYSCTL_BASE + 0x188)
/** Deep-Sleep Power Configuration */
#define SYSCTL_DSLPPWRCFG       MMIO32(SYSCTL_BASE + 0x18C)
/** Non-Volatile Memory Information */
#define SYSCTL_NVMSTAT          MMIO32(SYSCTL_BASE + 0x1A0)
/** LDO Sleep Power Control */
#define SYSCTL_LDOSPCTL         MMIO32(SYSCTL_BASE + 0x1B4)
/** LDO Sleep Power Calibration */
#define SYSCTL_LDOSPCAL         MMIO32(SYSCTL_BASE + 0x1B8)
/** LDO Deep-Sleep Power Control */
#define SYSCTL_LDODPCTL         MMIO32(SYSCTL_BASE + 0x1BC)
/** LDO Deep-Sleep Power Calibration */
#define SYSCTL_LDODPCAL         MMIO32(SYSCTL_BASE + 0x1C0)
/** Sleep / Deep-Sleep Power Mode Status */
#define SYSCTL_SDPMST           MMIO32(SYSCTL_BASE + 0x1CC)
/** Reset Behavior Control Register */
#define SYSCTL_RESBEHAVCTL      MMIO32(SYSCTL_BASE + 0x1D8)
/** Hardware System Service Request */
#define SYSCTL_HSSR             MMIO32(SYSCTL_BASE + 0x1F4)
/** USB Power Domain Status */
#define SYSCTL_USBPDS           MMIO32(SYSCTL_BASE + 0x280)
/** USB Memory Power Control */
#define SYSCTL_USBMPC           MMIO32(SYSCTL_BASE + 0x284)
/** Ethernet MAC Power Domain Status */
#define SYSCTL_EMACPDS          MMIO32(SYSCTL_BASE + 0x288)
/** Ethernet MAC Memory Power Control */
#define SYSCTL_EMACMPC          MMIO32(SYSCTL_BASE + 0x28C)
/** LCD Power Domain Status */
#define SYSCTL_LCDPDS           MMIO32(SYSCTL_BASE + 0x290)
/** LCD Memory Power Control */
#define SYSCTL_LCDMPC           MMIO32(SYSCTL_BASE + 0x294)
/** CAN 0 Power Domain Status */
#define SYSCTL_CAN0PDS          MMIO32(SYSCTL_BASE + 0x298)
/** CAN 0 Memory Power Control */
#define SYSCTL_CAN0MPC          MMIO32(SYSCTL_BASE + 0x29C)
/** CAN 1 Power Domain Status */
#define SYSCTL_CAN1PDS          MMIO32(SYSCTL_BASE + 0x2A0)
/** CAN 1 Memory Power Control */
#define SYSCTL_CAN1MPC          MMIO32(SYSCTL_BASE + 0x2A4)

/** Watchdog Timer Peripheral Present */
#define SYSCTL_PPWD             MMIO32(SYSCTL_BASE + 0x300)
/** 16/32-Bit General-Purpose Timer Peripheral Present */
#define SYSCTL_PPTIMER          MMIO32(SYSCTL_BASE + 0x304)
/** General-Purpose Input/Output Peripheral Present */
#define SYSCTL_PPGPIO           MMIO32(SYSCTL_BASE + 0x308)
/** Micro Direct Memory Access Peripheral Present */
#define SYSCTL_PPDMA            MMIO32(SYSCTL_BASE + 0x30C)
/** EPI Peripheral Present */
#define SYSCTL_PPEPI            MMIO32(SYSCTL_BASE + 0x310)
/** Hibernation Peripheral Present */
#define SYSCTL_PPHIB            MMIO32(SYSCTL_BASE + 0x314)
/** Universal Asynchronous Receiver/Transmitter Peripheral Present */
#define SYSCTL_PPUART           MMIO32(SYSCTL_BASE + 0x318)
/** Synchronous Serial Interface Peripheral Present */
#define SYSCTL_PPSSI            MMIO32(SYSCTL_BASE + 0x31C)
/** Inter-Integrated Circuit Peripheral Present */
#define SYSCTL_PPI2C            MMIO32(SYSCTL_BASE + 0x320)
/** Universal Serial Bus Peripheral Present */
#define SYSCTL_PPUSB            MMIO32(SYSCTL_BASE + 0x328)
/** Ethernet PHY Peripheral Present */
#define SYSCTL_PPEPHY           MMIO32(SYSCTL_BASE + 0x330)
/** Controller Area Network Peripheral Present */
#define SYSCTL_PPCAN            MMIO32(SYSCTL_BASE + 0x334)
/** Analog-to-Digital Converter Peripheral Present */
#define SYSCTL_PPADC            MMIO32(SYSCTL_BASE + 0x338)
/** Analog Comparator Peripheral Present */
#define SYSCTL_PPACMP           MMIO32(SYSCTL_BASE + 0x33C)
/** Pulse Width Modulator Peripheral Present */
#define SYSCTL_PPPWM            MMIO32(SYSCTL_BASE + 0x340)
/** Quadrature Encoder Interface Peripheral Present */
#define SYSCTL_PPQEI            MMIO32(SYSCTL_BASE + 0x344)
/** EEPROM Peripheral Present */
#define SYSCTL_PPEEPROM         MMIO32(SYSCTL_BASE + 0x358)
/** CRC and Cryptographic Modules Peripheral Present */
#define SYSCTL_PPCCM            MMIO32(SYSCTL_BASE + 0x374)
/** LCD Peripheral Present */
#define SYSCTL_PPLCD            MMIO32(SYSCTL_BASE + 0x390)
/** 1-Wire Peripheral Present */
#define SYSCTL_PPOWIRE          MMIO32(SYSCTL_BASE + 0x398)
/** Ethernet MAC Peripheral Present */
#define SYSCTL_PPEMAC           MMIO32(SYSCTL_BASE + 0x39C)
/** Power Regulator Bus Peripheral Present */
#define SYSCTL_PPPRB            MMIO32(SYSCTL_BASE + 0x3A0)

/** Watchdog Timer Software Reset */
#define SYSCTL_SRWD             MMIO32(SYSCTL_BASE + 0x500)
/** 16/32-Bit General-Purpose Timer Software Reset */
#define SYSCTL_SRTIMER          MMIO32(SYSCTL_BASE + 0x504)
/** General-Purpose Input/Output Software Reset */
#define SYSCTL_SRGPIO           MMIO32(SYSCTL_BASE + 0x508)
/** Micro Direct Memory Access Software Reset */
#define SYSCTL_SRDMA            MMIO32(SYSCTL_BASE + 0x50C)
/** EPI Software Reset */
#define SYSCTL_SREPI            MMIO32(SYSCTL_BASE + 0x510)
/** Hibernation Software Reset */
#define SYSCTL_SRHIB            MMIO32(SYSCTL_BASE + 0x514)
/** Universal Asynchronous Receiver/Transmitter Software Reset */
#define SYSCTL_SRUART           MMIO32(SYSCTL_BASE + 0x518)
/** Synchronous Serial Interface Software Reset */
#define SYSCTL_SRSSI            MMIO32(SYSCTL_BASE + 0x51C)
/** Inter-Integrated Circuit Software Reset */
#define SYSCTL_SRI2C            MMIO32(SYSCTL_BASE + 0x520)
/** Universal Serial Bus Software Reset */
#define SYSCTL_SRUSB            MMIO32(SYSCTL_BASE + 0x528)
/** Ethernet PHY Software Reset */
#define SYSCTL_SREPHY           MMIO32(SYSCTL_BASE + 0x530)
/** Controller Area Network Software Reset */
#define SYSCTL_SRCAN            MMIO32(SYSCTL_BASE + 0x534)
/** Analog-to-Digital Converter Software Reset */
#define SYSCTL_SRADC            MMIO32(SYSCTL_BASE + 0x538)
/** Analog Comparator Software Reset */
#define SYSCTL_SRACMP           MMIO32(SYSCTL_BASE + 0x53C)
/** Pulse Width Modulator Software Reset */
#define SYSCTL_SRPWM            MMIO32(SYSCTL_BASE + 0x540)
/** Quadrature Encoder Interface Software Reset */
#define SYSCTL_SRQEI            MMIO32(SYSCTL_BASE + 0x544)
/** EEPROM Software Reset */
#define SYSCTL_SREEPROM         MMIO32(SYSCTL_BASE + 0x558)
/** CRC and Cryptographic Modules Software Reset */
#define SYSCTL_SRCCM            MMIO32(SYSCTL_BASE + 0x574)
/** LCD Controller Software Reset */
#define SYSCTL_SRLCD            MMIO32(SYSCTL_BASE + 0x590)
/** 1-Wire Software Reset */
#define SYSCTL_SROWIRE          MMIO32(SYSCTL_BASE + 0x598)
/** Ethernet MAC Software Reset */
#define SYSCTL_SREMAC           MMIO32(SYSCTL_BASE + 0x59C)

/** Watchdog Timer Run Mode Clock Gating Control */
#define SYSCTL_RCGCWD           MMIO32(SYSCTL_BASE + 0x600)
/** 16/32-BitGeneral-Purpose Timer RunMode Clock Gating Control */
#define SYSCTL_RCGCTIMER        MMIO32(SYSCTL_BASE + 0x604)
/** General-Purpose Input/Output Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO         MMIO32(SYSCTL_BASE + 0x608)
/** Micro Direct Memory Access Run Mode Clock Gating Control */
#define SYSCTL_RCGCDMA          MMIO32(SYSCTL_BASE + 0x60C)
/** EPI Run Mode Clock Gating Control */
#define SYSCTL_RCGCEPI          MMIO32(SYSCTL_BASE + 0x610)
/** Hibernation Run Mode Clock Gating Control */
#define SYSCTL_RCGCHIB          MMIO32(SYSCTL_BASE + 0x614)
/** Universal Asynchronous Receiver/Transmitter RunMode Clock Gating Control */
#define SYSCTL_RCGCUART         MMIO32(SYSCTL_BASE + 0x618)
/** Synchronous Serial Interface Run Mode Clock Gating Control */
#define SYSCTL_RCGCSSI          MMIO32(SYSCTL_BASE + 0x61C)
/** Inter-Integrated Circuit Run Mode Clock Gating Control */
#define SYSCTL_RCGCI2C          MMIO32(SYSCTL_BASE + 0x620)
/** Universal Serial Bus Run Mode Clock Gating Control */
#define SYSCTL_RCGCUSB          MMIO32(SYSCTL_BASE + 0x628)
/** Ethernet PHY Run Mode Clock Gating Control */
#define SYSCTL_RCGCEPHY         MMIO32(SYSCTL_BASE + 0x630)
/** Controller Area Network RunMode Clock Gating Control */
#define SYSCTL_RCGCCAN          MMIO32(SYSCTL_BASE + 0x634)
/** Analog-to-Digital Converter Run Mode Clock Gating Control */
#define SYSCTL_RCGCADC          MMIO32(SYSCTL_BASE + 0x638)
/** Analog Comparator Run Mode Clock Gating Control */
#define SYSCTL_RCGCACMP         MMIO32(SYSCTL_BASE + 0x63C)
/** Pulse Width Modulator Run Mode Clock Gating Control */
#define SYSCTL_RCGCPWM          MMIO32(SYSCTL_BASE + 0x640)
/** Quadrature Encoder Interface Run Mode Clock Gating Control */
#define SYSCTL_RCGCQEI          MMIO32(SYSCTL_BASE + 0x644)
/** EEPROM Run Mode Clock Gating Control */
#define SYSCTL_RCGCEEPROM       MMIO32(SYSCTL_BASE + 0x658)
/** CRC and CryptographicModules RunMode ClockGating Control */
#define SYSCTL_RCGCCCM          MMIO32(SYSCTL_BASE + 0x674)
/** LCD Controller Run Mode Clock Gating Control */
#define SYSCTL_RCGCLCD          MMIO32(SYSCTL_BASE + 0x690)
/** 1-Wire Run Mode Clock Gating Control */
#define SYSCTL_RCGCOWIRE        MMIO32(SYSCTL_BASE + 0x698)
/** Ethernet MAC Run Mode Clock Gating Control */
#define SYSCTL_RCGCEMAC         MMIO32(SYSCTL_BASE + 0x69C)

/** Watchdog Timer Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCWD           MMIO32(SYSCTL_BASE + 0x700)
/** 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCTIMER        MMIO32(SYSCTL_BASE + 0x704)
/** General-Purpose Input/Output Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCGPIO         MMIO32(SYSCTL_BASE + 0x708)
/** Micro Direct Memory Access Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCDMA          MMIO32(SYSCTL_BASE + 0x70C)
/** EPI Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCEPI          MMIO32(SYSCTL_BASE + 0x710)
/** Hibernation Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCHIB          MMIO32(SYSCTL_BASE + 0x714)
/** Universal Asynchronous Receiver/Transmitter S Mode Clock Gating Control */
#define SYSCTL_SCGCUART         MMIO32(SYSCTL_BASE + 0x718)
/** Synchronous Serial Interface Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCSSI          MMIO32(SYSCTL_BASE + 0x71C)
/** Inter-Integrated Circuit Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCI2C          MMIO32(SYSCTL_BASE + 0x720)
/** Universal Serial Bus Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCUSB          MMIO32(SYSCTL_BASE + 0x728)
/** Ethernet PHY Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCEPHY         MMIO32(SYSCTL_BASE + 0x730)
/** Controller Area Network Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCCAN          MMIO32(SYSCTL_BASE + 0x734)
/** Analog-to-Digital Converter Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCADC          MMIO32(SYSCTL_BASE + 0x738)
/** Analog Comparator Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCACMP         MMIO32(SYSCTL_BASE + 0x73C)
/** PulseWidthModulator Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCPWM          MMIO32(SYSCTL_BASE + 0x740)
/** Quadrature Encoder Interface Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCQEI          MMIO32(SYSCTL_BASE + 0x744)
/** EEPROM Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCEEPROM       MMIO32(SYSCTL_BASE + 0x758)
/** CRC and Cryptographic Modules Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCCCM          MMIO32(SYSCTL_BASE + 0x774)
/** LCD Controller Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCLCD          MMIO32(SYSCTL_BASE + 0x790)
/** 1-Wire Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCOWIRE        MMIO32(SYSCTL_BASE + 0x798)
/** Ethernet MAC Sleep Mode Clock Gating Control */
#define SYSCTL_SCGCEMAC         MMIO32(SYSCTL_BASE + 0x79C)

/** Watchdog Timer Deep-SleepMode Clock Gating Control */
#define SYSCTL_DCGCWD           MMIO32(SYSCTL_BASE + 0x800)
/** Clock 16/32-Bit General-Purpose Timer Deep-Sleep Mode Gating Control */
#define SYSCTL_DCGCTIMER        MMIO32(SYSCTL_BASE + 0x804)
/** General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCGPIO         MMIO32(SYSCTL_BASE + 0x808)
/** Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCDMA          MMIO32(SYSCTL_BASE + 0x80C)
/** EPI Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCEPI          MMIO32(SYSCTL_BASE + 0x810)
/** Hibernation Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCHIB          MMIO32(SYSCTL_BASE + 0x814)
/** Universal Asynchronous Receiver/Transmitter D-S Mode Clock Gating Control*/
#define SYSCTL_DCGCUART         MMIO32(SYSCTL_BASE + 0x818)
/** Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCSSI          MMIO32(SYSCTL_BASE + 0x81C)
/** Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCI2C          MMIO32(SYSCTL_BASE + 0x820)
/** Universal Serial Bus Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCUSB          MMIO32(SYSCTL_BASE + 0x828)
/** Ethernet PHY Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCEPHY         MMIO32(SYSCTL_BASE + 0x830)
/** Controller Area Network Deep-SleepMode Clock Gating Control */
#define SYSCTL_DCGCCAN          MMIO32(SYSCTL_BASE + 0x834)
/** Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCADC          MMIO32(SYSCTL_BASE + 0x838)
/** Analog Comparator Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCACMP         MMIO32(SYSCTL_BASE + 0x83C)
/** Pulse Width Modulator Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCPWM          MMIO32(SYSCTL_BASE + 0x840)
/** Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCQEI          MMIO32(SYSCTL_BASE + 0x844)
/** EEPROM Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCEEPROM       MMIO32(SYSCTL_BASE + 0x858)
/** CRC and Cryptographic Modules Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCCCM          MMIO32(SYSCTL_BASE + 0x874)
/** LCD Controller Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCLCD          MMIO32(SYSCTL_BASE + 0x890)
/** 1-Wire Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCOWIRE        MMIO32(SYSCTL_BASE + 0x898)
/** Ethernet MAC Deep-Sleep Mode Clock Gating Control */
#define SYSCTL_DCGCEMAC         MMIO32(SYSCTL_BASE + 0x89C)

/** Watchdog Timer Power Control */
#define SYSCTL_PCWD             MMIO32(SYSCTL_BASE + 0x900)
/** 16/32-Bit General-Purpose Timer Power Control */
#define SYSCTL_PCTIMER          MMIO32(SYSCTL_BASE + 0x904)
/** General-Purpose Input/Output Power Control */
#define SYSCTL_PCGPIO           MMIO32(SYSCTL_BASE + 0x908)
/** Micro Direct Memory Access Power Control */
#define SYSCTL_PCDMA            MMIO32(SYSCTL_BASE + 0x90C)
/** External Peripheral Interface Power Control */
#define SYSCTL_PCEPI            MMIO32(SYSCTL_BASE + 0x910)
/** Hibernation Power Control */
#define SYSCTL_PCHIB            MMIO32(SYSCTL_BASE + 0x914)
/** Universal Asynchronous Receiver/Transmitter Power Control */
#define SYSCTL_PCUART           MMIO32(SYSCTL_BASE + 0x918)
/** Synchronous Serial Interface Power Control */
#define SYSCTL_PCSSI            MMIO32(SYSCTL_BASE + 0x91C)
/** Inter-Integrated Circuit Power Control */
#define SYSCTL_PCI2C            MMIO32(SYSCTL_BASE + 0x920)
/** Universal Serial Bus Power Control */
#define SYSCTL_PCUSB            MMIO32(SYSCTL_BASE + 0x928)
/** Ethernet PHY Power Control */
#define SYSCTL_PCEPHY           MMIO32(SYSCTL_BASE + 0x930)
/** Controller Area Network Power Control */
#define SYSCTL_PCCAN            MMIO32(SYSCTL_BASE + 0x934)
/** Analog-to-Digital Converter Power Control */
#define SYSCTL_PCADC            MMIO32(SYSCTL_BASE + 0x938)
/** Analog Comparator Power Control */
#define SYSCTL_PCACMP           MMIO32(SYSCTL_BASE + 0x93C)
/** Pulse Width Modulator Power Control */
#define SYSCTL_PCPWM            MMIO32(SYSCTL_BASE + 0x940)
/** Quadrature Encoder Interface Power Control */
#define SYSCTL_PCQEI            MMIO32(SYSCTL_BASE + 0x944)
/** EEPROM Power Control */
#define SYSCTL_PCEEPROM         MMIO32(SYSCTL_BASE + 0x958)
/** CRC and Cryptographic Modules Power Control */
#define SYSCTL_PCCCM            MMIO32(SYSCTL_BASE + 0x974)
/** LCD Controller Power Control */
#define SYSCTL_PCLCD            MMIO32(SYSCTL_BASE + 0x990)
/** 1-Wire Power Control */
#define SYSCTL_PCOWIRE          MMIO32(SYSCTL_BASE + 0x998)
/** Ethernet MAC Power Control */
#define SYSCTL_PCEMAC           MMIO32(SYSCTL_BASE + 0x99C)

/** Watchdog Timer Peripheral Ready */
#define SYSCTL_PRWD             MMIO32(SYSCTL_BASE + 0xA00)
/** 16/32-Bit General-Purpose Timer Peripheral Ready */
#define SYSCTL_PRTIMER          MMIO32(SYSCTL_BASE + 0xA04)
/** General-Purpose Input/Output Peripheral Ready */
#define SYSCTL_PRGPIO           MMIO32(SYSCTL_BASE + 0xA08)
/** Micro Direct Memory Access Peripheral Ready */
#define SYSCTL_PRDMA            MMIO32(SYSCTL_BASE + 0xA0C)
/** EPI Peripheral Ready */
#define SYSCTL_PREPI            MMIO32(SYSCTL_BASE + 0xA10)
/** Hibernation Peripheral Ready */
#define SYSCTL_PRHIB            MMIO32(SYSCTL_BASE + 0xA14)
/** Universal Asynchronous Receiver/Transmitter Peripheral Ready */
#define SYSCTL_PRUART           MMIO32(SYSCTL_BASE + 0xA18)
/** Synchronous Serial Interface Peripheral Ready */
#define SYSCTL_PRSSI            MMIO32(SYSCTL_BASE + 0xA1C)
/** Inter-Integrated Circuit Peripheral Ready */
#define SYSCTL_PRI2C            MMIO32(SYSCTL_BASE + 0xA20)
/** Universal Serial Bus Peripheral Ready */
#define SYSCTL_PRUSB            MMIO32(SYSCTL_BASE + 0xA28)
/** Ethernet PHY Peripheral Ready */
#define SYSCTL_PREPHY           MMIO32(SYSCTL_BASE + 0xA30)
/** Controller Area Network Peripheral Ready */
#define SYSCTL_PRCAN            MMIO32(SYSCTL_BASE + 0xA34)
/** Analog-to-Digital Converter Peripheral Ready */
#define SYSCTL_PRADC            MMIO32(SYSCTL_BASE + 0xA38)
/** Analog Comparator Peripheral Ready */
#define SYSCTL_PRACMP           MMIO32(SYSCTL_BASE + 0xA3C)
/** Pulse Width Modulator Peripheral Ready */
#define SYSCTL_PRPWM            MMIO32(SYSCTL_BASE + 0xA40)
/** Quadrature Encoder Interface Peripheral Ready */
#define SYSCTL_PRQEI            MMIO32(SYSCTL_BASE + 0xA44)
/** EEPROM Peripheral Ready */
#define SYSCTL_PREEPROM         MMIO32(SYSCTL_BASE + 0xA58)
/** CRC and Cryptographic Modules Peripheral Ready */
#define SYSCTL_PRCCM            MMIO32(SYSCTL_BASE + 0xA74)
/** LCD Controller Peripheral Ready */
#define SYSCTL_PRLCD            MMIO32(SYSCTL_BASE + 0xA90)
/** 1-Wire Peripheral Ready */
#define SYSCTL_PROWIRE          MMIO32(SYSCTL_BASE + 0xA98)
/** Ethernet MAC Peripheral Ready */
#define SYSCTL_PREMAC           MMIO32(SYSCTL_BASE + 0xA9C)

/** Unique ID 0 */
#define SYSCTL_UNIQUEID0        MMIO32(SYSCTL_BASE + 0xF20)
/** Unique ID 1 */
#define SYSCTL_UNIQUEID1        MMIO32(SYSCTL_BASE + 0xF24)
/** Unique ID 2 */
#define SYSCTL_UNIQUEID2        MMIO32(SYSCTL_BASE + 0xF28)
/** Unique ID 3 */
#define SYSCTL_UNIQUEID3        MMIO32(SYSCTL_BASE + 0xF2C)
/**@}*/

/** @defgroup sysctl_did0_values SYSCTL_DID0 Values
 * @brief System Control Device Identification 0 Register Values
@{*/
/** DID0 Version Shift */
#define SYSCTL_DID0_VER_SHIFT       (28)
/** DID0 Version Mask */
#define SYSCTL_DID0_VER_MASK        (0x7)
/** Device Class Shift */
#define SYSCTL_DID0_CLASS_SHIFT     (16)
/** Device Class Mask */
#define SYSCTL_DID0_CLASS_MASK      (0xFF)
/** Major Revision Shift */
#define SYSCTL_DID0_MAJOR_SHIFT     (8)
/** Major Revision Mask */
#define SYSCTL_DID0_MAJOR_MASK      (0xFF)
/** Minor Revision Shift */
#define SYSCTL_DID0_MINOR_SHIFT     (0)
/** Minor Revision Mask */
#define SYSCTL_DID0_MINOR_MASK      (0xFF)
/**@}*/

/** @defgroup sysctl_did1_values SYSCTL_DID1 Values
 * @brief System Control Device Identification 1 Register Values
@{*/
/** DID1 Version Shift */
#define SYSCTL_DID1_VER_SHIFT       (28)
/** DID1 Version Mask */
#define SYSCTL_DID1_VER_MASK        (0xF)
/** Family Shift */
#define SYSCTL_DID1_FAM_SHIFT       (24)
/** Family Mask */
#define SYSCTL_DID1_FAM_MASK        (0xF)
/** Part Number Shift */
#define SYSCTL_DID1_PARTNO_SHIFT    (16)
/** Part Number Mask */
#define SYSCTL_DID1_PARTNO_MASK     (0xFF)
/** Package Pin Count Shift */
#define SYSCTL_DID1_PINCOUNT_SHIFT  (13)
/** Package Pin Count Mask */
#define SYSCTL_DID1_PINCOUNT_MASK   (0x7)
/** 128-pin package */
#define SYSCTL_DID1_PINCOUNT_128P   (0x6)
/** 212-pin package */
#define SYSCTL_DID1_PINCOUNT_212P   (0x7)
/** Temperature Range Shift */
#define SYSCTL_DID1_TEMP_SHIFT      (5)
/** Temperature Range Mask */
#define SYSCTL_DID1_TEMP_MASK       (0x7)
/** 0°C to +70°C */
#define SYSCTL_DID1_TEMP_COMMERCIAL (0x0)
/** -40°C to +85°C */
#define SYSCTL_DID1_TEMP_INDUSTRIAL (0x1)
/** -40°C to +105°C */
#define SYSCTL_DID1_TEMP_EXTENDED   (0x2)
/** Package Type Shift */
#define SYSCTL_DID1_PKG_SHIFT       (3)
/** Package Type Mask */
#define SYSCTL_DID1_PKG_MASK        (0x3)
/** QFP package */
#define SYSCTL_DID1_PKG_QFP         (0x1)
/** BGA package */
#define SYSCTL_DID1_PKG_BGA         (0x2)
/** RoHS-compliance */
#define SYSCTL_DID1_ROHS            (1 << 2)
/** Qualification Status Shift */
#define SYSCTL_DID1_QUAL_SHIFT      (0)
/** Qualification Status Mask */
#define SYSCTL_DID1_QUAL_MASK       (0x3)
/** Engineering Sample */
#define SYSCTL_DID1_QUAL_SAMPLE     (0x0)
/** Pilot Production */
#define SYSCTL_DID1_QUAL_PILOT      (0x1)
/** Fully Qualified */
#define SYSCTL_DID1_QUAL_QUALIFIED  (0x2)
/**@}*/

/** @defgroup sysctl_ptboctl_values SYSCTL_PTBOCTL0 Values
 * @brief System Control Power-Temp Brownout Control Register Values
@{*/
/** VDDA Under BOR Event Action Shift */
#define SYSCTL_PTBOCTL_VDDA_UBOR_SHIFT  (8)
/** VDDA Under BOR Event Action Mask */
#define SYSCTL_PTBOCTL_VDDA_UBOR_MASK   (0x3)
/** VDDA Under BOR Event Action - No action */
#define SYSCTL_PTBOCTL_VDDA_UBOR_NO     (0x0)
/** VDDA Under BOR Event Action - System Control Interrupt */
#define SYSCTL_PTBOCTL_VDDA_UBOR_INT    (0x1)
/** VDDA Under BOR Event Action - Non-maskable interrupt */
#define SYSCTL_PTBOCTL_VDDA_UBOR_NMI    (0x2)
/** VDDA Under BOR Event Action - Reset */
#define SYSCTL_PTBOCTL_VDDA_UBOR_RESET  (0x3)
/** VDD Under BOR Event Action Shift */
#define SYSCTL_PTBOCTL_VDD_UBOR_SHIFT   (1)
/** VDD Under BOR Event Action Mask */
#define SYSCTL_PTBOCTL_VDD_UBOR_MASK    (0x3)
/** VDD Under BOR Event Action - No action */
#define SYSCTL_PTBOCTL_VDD_UBOR_NO      (0x0)
/** VDD Under BOR Event Action - System Control Interrupt */
#define SYSCTL_PTBOCTL_VDD_UBOR_INT     (0x1)
/** VDD Under BOR Event Action - Non-maskable interrupt */
#define SYSCTL_PTBOCTL_VDD_UBOR_NMI     (0x2)
/** VDD Under BOR Event Action - Reset */
#define SYSCTL_PTBOCTL_VDD_UBOR_RESET   (0x3)
/**@}*/

/** @defgroup sysctl_ric_values SYSCTL_RIS Values
 * @brief System Control Raw Interrupt Status Register Values
@{*/
/** MOSC Power Up Raw Interrupt Status */
#define SYSCTL_RIS_MOSCPUPRIS   (1 << 8)
/** PLL Lock Raw Interrupt Status */
#define SYSCTL_RIS_PLLLRIS      (1 << 6)
/** Main Oscillator Failure Raw Interrupt Status */
#define SYSCTL_RIS_MOFRIS       (1 << 3)
/** Brown-Out Reset Raw Interrupt Status */
#define SYSCTL_RIS_BORRIS       (1 << 1)
/**@}*/

/** @defgroup sysctl_imc_values SYSCTL_IMC Values
 * @brief System Control Interrupt Mask Control Register Values
@{*/
/** MOSC Power Up Raw Interrupt Mask */
#define SYSCTL_IMC_MOSCPUPIM    (1 << 8)
/** PLL Lock Raw Interrupt Mask */
#define SYSCTL_IMC_PLLLIM       (1 << 6)
/** Main Oscillator Failure Raw Interrupt Mask */
#define SYSCTL_IMC_MOFIM        (1 << 3)
/** Brown-Out Reset Raw Interrupt Mask */
#define SYSCTL_IMC_BORIM        (1 << 1)
/**@}*/

/** @defgroup sysctl_misc_values SYSCTL_MISC Values
 * @brief System Control Masked Interrupt Status and Clear Register Values
@{*/
/** MOSC Power Up Raw Interrupt Status*/
#define SYSCTL_MISC_MOSCPUPMIS  (1 << 8)
/** PLL Lock Raw Interrupt Status */
#define SYSCTL_MISC_PLLLMIS     (1 << 6)
/** Main Oscillator Failure Raw Interrupt Status */
#define SYSCTL_MISC_MOFMIS      (1 << 3)
/** Brown-Out Reset Raw Interrupt Status */
#define SYSCTL_MISC_BORMIS      (1 << 1)
/**@}*/

/** @defgroup sysctl_resc_values SYSCTL_RESC Values
 * @brief System Control Reset Cause Register Values
@{*/
/** MOSC Failure Reset */
#define SYSCTL_RESC_MOSCFAIL    (1 << 16)
/** HSSR Reset */
#define SYSCTL_RESC_HSSR        (1 << 12)
/** Watchdog Timer 1 Reset */
#define SYSCTL_RESC_WDT1        (1 << 5)
/** Software Reset */
#define SYSCTL_RESC_SW          (1 << 4)
/** Watchdog Timer 0 Reset */
#define SYSCTL_RESC_WDT0        (1 << 3)
/** Brown-Out Reset */
#define SYSCTL_RESC_BOR         (1 << 2)
/** Power-On Reset */
#define SYSCTL_RESC_POR         (1 << 1)
/** External Reset */
#define SYSCTL_RESC_EXT         (1 << 0)
/**@}*/

/** @defgroup sysctl_pwrtc_values SYSCTL_PWRTC Values
 * @brief System Control Power-Temperature Cause Register Values
@{*/
/** VDDA Under BOR Status */
#define SYSCTL_PWRTC_VDDA_UBOR  (1 << 4)
/** VDD Under BOR Status */
#define SYSCTL_PWRTC_VDD_UBOR   (1 << 0)
/**@}*/

/** @defgroup sysctl_nmic_values SYSCTL_NMIC Values
 * @brief System Control NMI Cause Register Values
@{*/
/** MOSC Failure NMI */
#define SYSCTL_NMIC_MOSCFAIL    (1 << 16)
/** Tamper Event NMI */
#define SYSCTL_NMIC_TAMPER      (1 << 9)
/** WDT1 NMI */
#define SYSCTL_NMIC_WDT1        (1 << 5)
/** WDT0 NMI */
#define SYSCTL_NMIC_WDT0        (1 << 3)
/** Power/Brownout Event NMI */
#define SYSCTL_NMIC_POWER       (1 << 2)
/** External Pin NMI */
#define SYSCTL_NMIC_EXTERNAL    (1 << 0)
/**@}*/

/** @defgroup sysctl_moscctl_values SYSCTL_MOSCCTL Values
 * @brief System Control Main Oscillator Control Register Values
@{*/
/** Oscillator Range */
#define SYSCTL_MOSCCTL_OSCRNG   (1 << 4)
/** Power Down */
#define SYSCTL_MOSCCTL_PWRDN    (1 << 3)
/** No MOSC or Crystal Connected */
#define SYSCTL_MOSCCTL_NOXTAL   (1 << 2)
/** MOSC Failure Action */
#define SYSCTL_MOSCCTL_MOSCIM   (1 << 1)
/** Clock Validation for MOSC */
#define SYSCTL_MOSCCTL_CVAL     (1 << 0)
/**@}*/

/** @defgroup sysctl_rsclkcfg_values SYSCTL_RSCLKCFG Values
 * @brief System Control Run and Sleep Mode Configuration Register Values
@{*/
/** Memory Timing Register Update */
#define SYSCTL_RSCLKCFG_MEMTIMU         (1 << 31)
/** New PLLFREQ Accept */
#define SYSCTL_RSCLKCFG_NEWFREQ         (1 << 30)
/** Auto Clock Gating */
#define SYSCTL_RSCLKCFG_ACG             (1 << 29)
/** Use PLL */
#define SYSCTL_RSCLKCFG_USEPLL          (1 << 28)
/** PLL Source Shift */
#define SYSCTL_RSCLKCFG_PLLSRC_SHIFT    (24)
/** PLL Source Mask */
#define SYSCTL_RSCLKCFG_PLLSRC_MASK     (0xF)
/** PLL Source - MOSC */
#define SYSCTL_RSCLKCFG_PLLSRC_MOSC     (0x3)
/** Oscillator Source Shift */
#define SYSCTL_RSCLKCFG_OSCSRC_SHIFT    (20)
/** Oscillator Source Mask */
#define SYSCTL_RSCLKCFG_OSCSRC_MASK     (0xF)
/** Oscillator Source - LFIOSC */
#define SYSCTL_RSCLKCFG_OSCSRC_LFIOSC   (0x2)
/** Oscillator Source - MOSC */
#define SYSCTL_RSCLKCFG_OSCSRC_MOSC     (0x3)
/** Oscillator Source - RTCOSC */
#define SYSCTL_RSCLKCFG_OSCSRC_RTCOSC   (0x4)
/** Oscillator System Clock Divisor Shift */
#define SYSCTL_RSCLKCFG_OSYSDIV_SHIFT   (10)
/** Oscillator System Clock Divisor Mask */
#define SYSCTL_RSCLKCFG_OSYSDIV_MASK    (0x3FF)
/** PLL System Clock Divisor Shift */
#define SYSCTL_RSCLKCFG_PSYSDIV_SHIFT   (0)
/** PLL System Clock Divisor Mask */
#define SYSCTL_RSCLKCFG_PSYSDIV_MASK    (0x3FF)
/**@}*/

/** @defgroup sysctl_memtim0_values SYSCTL_MEMTIM0 Values
 * @brief System Control Memory Timing Parameter Register 0 for Main Flash
 * and EEPROM Register Values
 *
 * CPU Frequency Range (f) in MHZ |FBCHT and EBCHT|FBCE and EBCE| FWS and EWS|
 * -------------------------------| ------------- | ----------- | ---------- |
 * 16                             |  0x0 (1/2)    |  0x1        |  0x0       |
 * 16  < f <= 40                  |  0x2 (1.5)    |  0x0        |  0x1       |
 * 40  < f <= 60                  |  0x3 (2)      |  0x0        |  0x2       |
 * 60  < f <= 80                  |  0x4 (2.5)    |  0x0        |  0x3       |
 * 80  < f <= 100                 |  0x5 (3)      |  0x0        |  0x4       |
 * 100 < f <= 120                 |  0x6 (3.5)    |  0x0        |  0x5       |
 *
@{*/
/** EEPROM Clock High Time Shift */
#define SYSCTL_MEMTIM0_EBCHT_SHIFT      (22)
/** EEPROM Clock High Time Mask */
#define SYSCTL_MEMTIM0_EBCHT_MASK       (0xF)
/** EBCHT - 0.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_0_POINT_5  (0x0)
/** EBCHT - 1 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_1          (0x1)
/** EBCHT - 1.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_1_POINT_5  (0x2)
/** EBCHT - 2 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_2          (0x3)
/** EBCHT - 2.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_2_POINT_5  (0x4)
/** EBCHT - 3 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_3          (0x5)
/** EBCHT - 3.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_3_POINT_5  (0x6)
/** EBCHT - 4 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_4          (0x7)
/** EBCHT - 4.5 sys clock period */
#define SYSCTL_MEMTIM0_EBCHT_4_POINT_5  (0x8)
/** EEPROM Bank Clock Edge */
#define SYSCTL_MEMTIM0_EBCE             (1 << 21)
/** EEPROM Wait States Shift */
#define SYSCTL_MEMTIM0_EWS_SHIFT        (16)
/** EEPROM Wait States Mask */
#define SYSCTL_MEMTIM0_EWS_MASK         (0xF)
/** EWS - 1 wait state */
#define SYSCTL_MEMTIM0_EWS_1            (0x1)
/** EWS - 2 wait state */
#define SYSCTL_MEMTIM0_EWS_2            (0x2)
/** EWS - 3 wait state */
#define SYSCTL_MEMTIM0_EWS_3            (0x3)
/** EWS - 4 wait state */
#define SYSCTL_MEMTIM0_EWS_4            (0x4)
/** EWS - 5 wait state */
#define SYSCTL_MEMTIM0_EWS_5            (0x5)
/** EWS - 6 wait state */
#define SYSCTL_MEMTIM0_EWS_6            (0x6)
/** EWS - 7 wait state */
#define SYSCTL_MEMTIM0_EWS_7            (0x7)
/** Flash Clock High Time Shift */
#define SYSCTL_MEMTIM0_FBCHT_SHIFT      (6)
/** Flash Clock High Time Mask */
#define SYSCTL_MEMTIM0_FBCHT_MASK       (0xF)
/** FBCHT - 0.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_0_POINT_5  (0x0)
/** FBCHT - 1   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_1          (0x1)
/** FBCHT - 1.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_1_POINT_5  (0x2)
/** FBCHT - 2   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_2          (0x3)
/** FBCHT - 2.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_2_POINT_5  (0x4)
/** FBCHT - 3   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_3          (0x5)
/** FBCHT - 3.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_3_POINT_5  (0x6)
/** FBCHT - 4   sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_4          (0x7)
/** FBCHT - 4.5 sys clock period */
#define SYSCTL_MEMTIM0_FBCHT_4_POINT_5  (0x8)
/** Flash Bank Clock Edge */
#define SYSCTL_MEMTIM0_FBCE             (1 << 5)
/** Flash Wait States Shift */
#define SYSCTL_MEMTIM0_FWS_SHIFT        (0)
/** Flash Wait States Mask */
#define SYSCTL_MEMTIM0_FWS_MASK         (0xF)
/** FWS - 1 wait state */
#define SYSCTL_MEMTIM0_FWS_1            (0x1)
/** FWS - 2 wait state */
#define SYSCTL_MEMTIM0_FWS_2            (0x2)
/** FWS - 3 wait state */
#define SYSCTL_MEMTIM0_FWS_3            (0x3)
/** FWS - 4 wait state */
#define SYSCTL_MEMTIM0_FWS_4            (0x4)
/** FWS - 5 wait state */
#define SYSCTL_MEMTIM0_FWS_5            (0x5)
/** FWS - 6 wait state */
#define SYSCTL_MEMTIM0_FWS_6            (0x6)
/** FWS - 7 wait state */
#define SYSCTL_MEMTIM0_FWS_7            (0x7)
/**@}*/

/** @defgroup sysctl_altclkcfg_values SYSCTL_ALTCLKCFG Values
 * @brief System Control Alternate Clock Configuration Register Values
@{*/
/** Alternate Clock Source Shift */
#define SYSCTL_ALTCLKCFG_ALTCLK_SHIFT   (0)
/** Alternate Clock Source Mask */
#define SYSCTL_ALTCLKCFG_ALTCLK_MASK    (0xF)
/** Alternate Clock Source - RTCOSC */
#define SYSCTL_ALTCLKCFG_ALTCLK_RTCOSC  (0x3)
/** Alternate Clock Source - LFIOSC */
#define SYSCTL_ALTCLKCFG_ALTCLK_LFIOSC  (0x4)
/**@}*/

/** @defgroup sysctl_dsclkcfg_values SYSCTL_DSCLKCFG Values
 * @brief System Control Deep Sleep Clock Configuration Register Values
@{*/
/** PIOSC Power Down */
#define SYSCTL_DSCLKCFG_PIOSCPD         (1 << 31)
/** MOSC Disable Power Down */
#define SYSCTL_DSCLKCFG_MOSCDPD         (1 << 30)
/** Deep Sleep Oscillator Source Shift */
#define SYSCTL_DSCLKCFG_DSOSCSRC_SHIFT  (20)
/** Deep Sleep Oscillator Source Mask */
#define SYSCTL_DSCLKCFG_DSOSCSRC_MASK   (0xF)
/** Deep Sleep Oscillator Source - LFIOSC */
#define SYSCTL_DSCLKCFG_DSOSCSRC_LFIOSC (0x2)
/** Deep Sleep Oscillator Source - MOSC */
#define SYSCTL_DSCLKCFG_DSOSCSRC_MOSC   (0x3)
/** Deep Sleep Oscillator Source - RTCOSC */
#define SYSCTL_DSCLKCFG_DSOSCSRC_RTCOSC (0x4)
/** Deep Sleep Clock Divisor Shift */
#define SYSCTL_DSCLKCFG_DSSYSDIV_SHIFT  (0)
/** Deep Sleep Clock Divisor Mask */
#define SYSCTL_DSCLKCFG_DSSYSDIV_MASK   (0x3FF)
/**@}*/

/** @defgroup sysctl_divsclk_values SYSCTL_DIVSCLK Values
 * @brief System Control Divisor and Source Clock Configuration Register Values
@{*/
/** DIVSCLK Enable */
#define SYSCTL_DIVSCLK_EN         (1 << 31)
/** Clock Source Shift */
#define SYSCTL_DIVSCLK_SRC_SHIFT  (16)
/** Clock Source Mask */
#define SYSCTL_DIVSCLK_SRC_MASK   (0x3)
/** Clock Source - PIOSCK */
#define SYSCTL_DIVSCLK_SRC_PIOSC  (0x1)
/** Clock Source - MOSC */
#define SYSCTL_DIVSCLK_SRC_MOSC   (0x2)
/** Divisor Value Shift */
#define SYSCTL_DIVSCLK_DIV_SHIFT  (0)
/** Divisor Value Mask */
#define SYSCTL_DIVSCLK_DIV_MASK   (0xF)
/** Divisor Value - 1 */
#define SYSCTL_DIVSCLK_DIV_1      (0x0)
/** Divisor Value - 2 */
#define SYSCTL_DIVSCLK_DIV_2      (0x1)
/**@}*/

/** @defgroup sysctl_sysprop_values SYSCTL_SYSPROP Values
 * @brief System Control System Properties Register Values
@{*/
/** LDO Sleep Mode Enable */
#define SYSCTL_SYSPROP_LDOSME    (1 << 17)
/** Temp Sense Power Down Enable */
#define SYSCTL_SYSPROP_TSPDE     (1 << 16)
/** PIOSC Power Down Present */
#define SYSCTL_SYSPROP_PIOSCPDE  (1 << 12)
/** SRAM Sleep/Deep-Sleep Standby Mode Present */
#define SYSCTL_SYSPROP_SRAMSM    (1 << 11)
/** SRAM Sleep/Deep-Sleep Low Power Mode Present */
#define SYSCTL_SYSPROP_SRAMLPM   (1 << 10)
/** Flash Memory Sleep/Deep-Sleep Low Power Mode Present */
#define SYSCTL_SYSPROP_FLASHLPM  (1 << 8)
/** Automatic LDO Sequence Control Present */
#define SYSCTL_SYSPROP_LDOSEQ    (1 << 5)
/** FPU Present */
#define SYSCTL_SYSPROP_FPU       (1 << 0)
/**@}*/

/** @defgroup sysctl_piosccal_values SYSCTL_PIOSCCAL Values
 * @brief System Control Precision Internal Oscillator
 *        Calibration Register Values
@{*/
/** Use User Trim Value */
#define SYSCTL_PIOSCCAL_UTEN      (1 << 31)
/** Start Calibration */
#define SYSCTL_PIOSCCAL_CAL       (1 << 9)
/** Update Trim */
#define SYSCTL_PIOSCCAL_UPDATE    (1 << 8)
/** User Trim Value Shift */
#define SYSCTL_PIOSCCAL_UT_SHIFT  (0)
/** User Trim Value Mask */
#define SYSCTL_PIOSCCAL_UT_MASK   (0x7F)
/**@}*/

/** @defgroup sysctl_pioscstat_values SYSCTL_PIOSCSTAT Values
 * @brief System Control Precision Internal Oscillator
 *        Statistics Register Values
@{*/
/** Default Trim Value Shift */
#define SYSCTL_PIOSCSTAT_DT_SHIFT           (16)
/** Default Trim Value Mask */
#define SYSCTL_PIOSCSTAT_DT_MASK            (0x7F)
/** Calibration Result Shift */
#define SYSCTL_PIOSCSTAT_RESULT_SHIFT       (8)
/** Calibration Result Mask */
#define SYSCTL_PIOSCSTAT_RESULT_MASK        (0x3)
/** Calibration Not Attempted */
#define SYSCTL_PIOSCSTAT_RESULT_NOT_ATTEMPT (0x0)
/** Calibration Completed */
#define SYSCTL_PIOSCSTAT_RESULT_COMPLETE    (0x1)
/** Calibration Failed */
#define SYSCTL_PIOSCSTAT_RESULT_FAIL        (0x2)
/** Calibration Value Shift */
#define SYSCTL_PIOSCSTAT_CT_SHIFT           (0)
/** Calibration Value Mask */
#define SYSCTL_PIOSCSTAT_CT_MASK            (0x7F)
/**@}*/

/** @defgroup sysctl_pllfreq0_values SYSCTL_PLLFREQ0 Values
 * @brief System Control PLL Frequency 0 Register Values
@{*/
/** PLL Power */
#define SYSCTL_PLLFREQ0_PLLPWR      (1 << 23)
/** PLL M Fractional Value Shift */
#define SYSCTL_PLLFREQ0_MFRAC_SHIFT (10)
/** PLL M Fractional Value Mask */
#define SYSCTL_PLLFREQ0_MFRAC_MASK  (0x3FF)
/** PLL M Integer Value Shift */
#define SYSCTL_PLLFREQ0_MINT_SHIFT  (0)
/** PLL M Integer Value Mask */
#define SYSCTL_PLLFREQ0_MINT_MASK   (0x3FF)
/**@}*/

/** @defgroup sysctl_pllfreq1_values SYSCTL_PLLFREQ1 Values
 * @brief System Control PLL Frequency 1 Register Values
@{*/
/** PLL Q Value Shift */
#define SYSCTL_PLLFREQ1_Q_SHIFT (8)
/** PLL Q Value Mask */
#define SYSCTL_PLLFREQ1_Q_MASK  (0x1F)
/** PLL N Value Shift */
#define SYSCTL_PLLFREQ1_N_SHIFT (0)
/** PLL N Value Mask */
#define SYSCTL_PLLFREQ1_N_MASK  (0x1F)
/**@}*/

/** @defgroup sysctl_pllstat_values SYSCTL_PLLSTAT Values
 * @brief System Control PLL Status Register Values
@{*/
/** PLL Lock */
#define SYSCTL_PLLSTAT_LOCK     (1 << 0)
/**@}*/

/** @defgroup sysctl_slppwrcfg_values SYSCTL_SLPPWRCFG Values
 * @brief System Control Sleep Power Configuration Register Values
@{*/
/** Flash Power Modes Shift */
#define SYSCTL_SLPPWRCFG_FLASHPM_SHIFT   (4)
/** Flash Power Modes Mask */
#define SYSCTL_SLPPWRCFG_FLASHPM_MASK    (0x3)
/** Flash Power Mode - Active mode */
#define SYSCTL_SLPPWRCFG_FLASHPM_ACTIVE  (0x0)
/** Flash Power Mode - Low-Power Mode */
#define SYSCTL_SLPPWRCFG_FLASHPM_LP      (0x2)
/** SRAM Power Modes Shift */
#define SYSCTL_SLPPWRCFG_SRAMPM_SHIFT    (0)
/** SRAM Power Modes Mask */
#define SYSCTL_SLPPWRCFG_SRAMPM_MASK     (0x3)
/** SRAM Power Mode - Active mode */
#define SYSCTL_SLPPWRCFG_SRAMPM_ACTIVE   (0x0)
/** SRAM Power Mode - Standby mode */
#define SYSCTL_SLPPWRCFG_SRAMPM_STANDBY  (0x1)
/** SRAM Power Mode - Low-Power Mode */
#define SYSCTL_SLPPWRCFG_SRAMPM_LP       (0x3)
/**@}*/

/** @defgroup sysctl_dslppwrcfg_values SYSCTL_DSLPPWRCFG Values
 * @brief System Control Deep-Sleep Power Configuration Register Values
@{*/
/** LDO Sleep Mode */
#define SYSCTL_DSLPPWRCFG_LDOSM           (1 << 9)
/** Temp Sense Power Down */
#define SYSCTL_DSLPPWRCFG_TSPD            (1 << 8)
/** Flash Power Modes Shift */
#define SYSCTL_DSLPPWRCFG_FLASHPM_SHIFT   (4)
/** Flash Power Modes Mask */
#define SYSCTL_DSLPPWRCFG_FLASHPM_MASK    (0x3)
/** Flash Power Mode - Active mode */
#define SYSCTL_DSLPPWRCFG_FLASHPM_ACTIVE  (0x0)
/** Flash Power Mode - Low-Power Mode */
#define SYSCTL_DSLPPWRCFG_FLASHPM_LP      (0x2)
/** SRAM Power Modes Shift */
#define SYSCTL_DSLPPWRCFG_SRAMPM_SHIFT    (0)
/** SRAM Power Modes Mask */
#define SYSCTL_DSLPPWRCFG_SRAMPM_MASK     (0x3)
/** SRAM Power Mode - Active mode */
#define SYSCTL_DSLPPWRCFG_SRAMPM_ACTIVE   (0x0)
/** SRAM Power Mode - Standby mode */
#define SYSCTL_DSLPPWRCFG_SRAMPM_STANDBY  (0x1)
/** SRAM Power Mode - Low-Power Mode */
#define SYSCTL_DSLPPWRCFG_SRAMPM_LP       (0x3)
/**@}*/

/** @defgroup sysctl_nvmstat_values SYSCTL_NVMSTAT Values
 * @brief System Control Non-Volatile Memory Information Register Values
@{*/
/** 32 Word Flash Write Buffer Available */
#define SYSCTL_NVMSTAT_FWB  (1 << 0)
/**@}*/

/** @defgroup sysctl_ldospctl_values SYSCTL_LDOSPCTL Values
 * @brief System Control LDO Sleep Power Control Register Values
@{*/
/** Voltage Adjust Enable */
#define SYSCTL_LDOSPCTL_VADJEN           (1 << 31)
/** LDO Out Voltage Shift */
#define SYSCTL_LDOSPCTL_VLDO_SHIFT       (0)
/** LDO Out Voltage Mask */
#define SYSCTL_LDOSPCTL_VLDO_MASK        (0xFF)
/** LDO Out Voltage - 0.90V */
#define SYSCTL_LDOSPCTL_VLDO_0_POINT_90  (0x12)
/** LDO Out Voltage - 0.95V */
#define SYSCTL_LDOSPCTL_VLDO_0_POINT_95  (0x13)
/** LDO Out Voltage - 1.00V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_00  (0x14)
/** LDO Out Voltage - 1.05V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_05  (0x15)
/** LDO Out Voltage - 1.10V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_10  (0x16)
/** LDO Out Voltage - 1.15V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_15  (0x17)
/** LDO Out Voltage - 1.20V */
#define SYSCTL_LDOSPCTL_VLDO_1_POINT_20  (0x18)
/**@}*/

/** @defgroup sysctl_ldospcal_values SYSCTL_LDOSPCAL Values
 * @brief System Control LDO Sleep Power Calibration Register Values
@{*/
/** Sleep With PLL Shift */
#define SYSCTL_LDOSPCAL_WITHPLL_SHIFT  (8)
/** Sleep With PLL Mask */
#define SYSCTL_LDOSPCAL_WITHPLL_MASK   (0xFF)
/** Sleep Without PLL Shift */
#define SYSCTL_LDOSPCAL_NOPLL_SHIFT    (0)
/** Sleep Without PLL Mask */
#define SYSCTL_LDOSPCAL_NOPLL_MASK     (0xFF)
/**@}*/

/** @defgroup sysctl_ldodpctl_values SYSCTL_LDODPCTL Values
 * @brief System Control LDO Deep-Sleep Power Control Register Values
@{*/
/** Voltage Adjust Enable */
#define SYSCTL_LDODPCTL_VADJEN           (1 << 31)
/** LDO Out Voltage Shift */
#define SYSCTL_LDODPCTL_VLDO_SHIFT       (0)
/** LDO Out Voltage Mask */
#define SYSCTL_LDODPCTL_VLDO_MASK        (0xFF)
/** LDO Out Voltage - 0.90V */
#define SYSCTL_LDODPCTL_VLDO_0_POINT_90  (0x12)
/** LDO Out Voltage - 0.95V */
#define SYSCTL_LDODPCTL_VLDO_0_POINT_95  (0x13)
/** LDO Out Voltage - 1.00V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_00  (0x14)
/** LDO Out Voltage - 1.05V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_05  (0x15)
/** LDO Out Voltage - 1.10V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_10  (0x16)
/** LDO Out Voltage - 1.15V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_15  (0x17)
/** LDO Out Voltage - 1.20V */
#define SYSCTL_LDODPCTL_VLDO_1_POINT_20  (0x18)
/**@}*/

/** @defgroup sysctl_ldodpcal_values SYSCTL_LDODPCAL Values
 * @brief System Control LDO Deep-Sleep Power Calibration Register Values
@{*/
/** Deep-Sleep Without PLL Shift */
#define SYSCTL_LDODPCAL_NOPLL_SHIFT  (8)
/** Deep-Sleep Without PLL Mask */
#define SYSCTL_LDODPCAL_NOPLL_MASK   (0xFF)
/** Deep-Sleep With IOSC Shift */
#define SYSCTL_LDODPCAL_30KHZ_SHIFT  (0)
/** Deep-Sleep With IOSC Mask */
#define SYSCTL_LDODPCAL_30KHZ_MASK   (0xFF)
/**@}*/

/** @defgroup sysctl_sdpmst_values SYSCTL_SDPMST Values
 * @brief System Control Sleep/Deep-Sleep Power Mode Status Register Values
@{*/
/** LDO Update Active */
#define SYSCTL_SDPMST_LDOUA     (1 << 19)
/** Flash Memory in Low Power State */
#define SYSCTL_SDPMST_FLASHLP   (1 << 18)
/** Sleep or Deep-Sleep Mode */
#define SYSCTL_SDPMST_LOWPWR    (1 << 17)
/** Sleep or Deep-Sleep Power Request Active */
#define SYSCTL_SDPMST_PRACT     (1 << 16)
/** PIOSC Power Down Request Warning */
#define SYSCTL_SDPMST_PPDW      (1 << 7)
/** VLDO Value Above Max Error */
#define SYSCTL_SDPMST_LMAXERR   (1 << 6)
/** VLDO Value Below Minimum Error in Sleep Mode */
#define SYSCTL_SDPMST_LSMINERR  (1 << 4)
/** VLDO Value Below Minimum Error in Deep-Sleep Mode */
#define SYSCTL_SDPMST_LDMINERR  (1 << 3)
/** PIOSC Power Down Request Error */
#define SYSCTL_SDPMST_PPDERR    (1 << 2)
/** Flash Memory Power Down Request Error */
#define SYSCTL_SDPMST_FPDERR    (1 << 1)
/** SRAM Power Down Request Error */
#define SYSCTL_SDPMST_SPDERR    (1 << 0)
/**@}*/

/** @defgroup sysctl_resbehavctl_values SYSCTL_RESBEHAVCTL Values
 * @brief System Control Reset Behavior Control Register Values
@{*/
/** Reset Operation - System Reset */
#define SYSCTL_RESBEHAVCTL_SYSRES        (0x2)
/** Reset Operation - Power-On-Reset */
#define SYSCTL_RESBEHAVCTL_POR           (0x3)
/** Watchdog 1 Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_WDOG1_SHIFT   (6)
/** Watchdog 1 Reset Operation Mask */
#define SYSCTL_RESBEHAVCTL_WDOG1_MASK    (0x3)
/** Watchdog 0 Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_WDOG0_SHIFT   (4)
/** Watchdog 0 Reset Operation Mask */
#define SYSCTL_RESBEHAVCTL_WDOG0_MASK    (0x3)
/** BOR Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_BOR_SHIFT     (2)
/** BOR Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_BOR_MASK      (0x3)
/** EXT Reset Operation Shift */
#define SYSCTL_RESBEHAVCTL_EXTRES_SHIFT  (2)
/** EXT Reset Operation Mask */
#define SYSCTL_RESBEHAVCTL_EXTRES_MASK   (0x3)
/**@}*/

/** @defgroup sysctl_hssr_values SYSCTL_HSSR Values
 * @brief System Control Hardware System Service Request Register Values
@{*/
/** Write Key Shift */
#define SYSCTL_HSSR_KEY_SHIFT         (24)
/** Write Key Mask */
#define SYSCTL_HSSR_KEY_MASK          (0xFF)
/** Key Value for initiate request */
#define SYSCTL_HSSR_KEY_VALUE         (0xCA)
/** Command Descriptor Pointer Shift */
#define SYSCTL_HSSR_CDOFF_SHIFT       (0)
/** Command Descriptor Pointer Mask */
#define SYSCTL_HSSR_CDOFF_MASK        (0xFFFFFF)
/** Command Descriptor - No Request */
#define SYSCTL_HSSR_CDOFF_NO_REQUEST  (0x000000)
/** Command Descriptor - Error Or Incomplete Request */
#define SYSCTL_HSSR_CDOFF_ERROR       (0xFFFFFF)
/**@}*/

/** @defgroup sysctl_usbpds_values SYSCTL_USBPDS Values
 * @brief System Control USB Power Domain Status Register Values
@{*/
/** Memory Array Power Status Shift */
#define SYSCTL_USBPDS_MEMSTAT_SHIFT     (2)
/** Memory Array Power Status Mask */
#define SYSCTL_USBPDS_MEMSTAT_MASK      (0x3)
/** Memory Array Power Status - Off */
#define SYSCTL_USBPDS_MEMSTAT_ARR_OFF   (0x0)
/** Memory Array Power Status - SRAM Retention */
#define SYSCTL_USBPDS_MEMSTAT_SRAM_RET  (0x1)
/** Memory Array Power Status - On */
#define SYSCTL_USBPDS_MEMSTAT_ARR_ON    (0x3)
/** Power Domain Status Shift */
#define SYSCTL_USBPDS_PWRSTAT_SHIFT     (0)
/** Power Domain Status Mask */
#define SYSCTL_USBPDS_PWRSTAT_MASK      (0x3)
/** Power Domain Status - Off */
#define SYSCTL_USBPDS_PWRSTAT_OFF       (0x0)
/** Power Domain Status - On */
#define SYSCTL_USBPDS_PWRSTAT_ON        (0x3)
/**@}*/

/** @defgroup sysctl_usbmpc_values SYSCTL_USBMPC Values
 * @brief System Control USB Memory Power Control Register Values
@{*/
/** Memory Array Power Control Shift */
#define SYSCTL_USBMPC_PWRCTL_SHIFT    (0)
/** Memory Array Power Control Mask */
#define SYSCTL_USBMPC_PWRCTL_MASK     (0x3)
/** Memory Array Power Control - Off */
#define SYSCTL_USBMPC_PWRCTL_ARR_OFF  (0x0)
/** Memory Array Power Control - SRAM Retention */
#define SYSCTL_USBMPC_PWRCTL_SRAM_RET (0x1)
/** Memory Array Power Control - On */
#define SYSCTL_USBMPC_PWRCTL_ARR_ON   (0x3)
/**@}*/

/** @defgroup sysctl_emacpds_values SYSCTL_EMACPDS Values
 * @brief System Control Ethernet MAC Power Domain Status Register Values
@{*/
/** Memory Array Power Status Shift */
#define SYSCTL_EMACPDS_MEMSTAT_SHIFT     (2)
/** Memory Array Power Status Mask */
#define SYSCTL_EMACPDS_MEMSTAT_MASK      (0x3)
/** Memory Array Power Status - Off */
#define SYSCTL_EMACPDS_MEMSTAT_ARR_OFF   (0x0)
/** Memory Array Power Status - On */
#define SYSCTL_EMACPDS_MEMSTAT_ARR_ON    (0x3)
/** Power Domain Status Shift*/
#define SYSCTL_EMACPDS_PWRSTAT_SHIFT     (0)
/** Power Domain Status Mask */
#define SYSCTL_EMACPDS_PWRSTAT_MASK      (0x3)
/** Power Domain Status - Off */
#define SYSCTL_EMACPDS_PWRSTAT_OFF       (0x0)
/** Power Domain Status - On */
#define SYSCTL_EMACPDS_PWRSTAT_ON        (0x3)
/**@}*/

/** @defgroup sysctl_emacmpc_values SYSCTL_EMACMPC Values
 * @brief System Control Ethernet MAC Memory Power Control Register Values
@{*/
/** Memory Array Power Control Shift */
#define SYSCTL_EMACMPC_PWRCTL_SHIFT    (0)
/** Memory Array Power Control Mask */
#define SYSCTL_EMACMPC_PWRCTL_MASK     (0x3)
/** Memory Array Power Control - Off */
#define SYSCTL_EMACMPC_PWRCTL_ARR_OFF  (0x0)
/** Memory Array Power Control - On */
#define SYSCTL_EMACMPC_PWRCTL_ARR_ON   (0x3)
/**@}*/

/** @defgroup sysctl_lcdpds_values SYSCTL_LCDPDS Values
 * @brief System Control LCD Power Domain Status Register Values
@{*/
/** Memory Array Power Status Shift */
#define SYSCTL_LCDPDS_MEMSTAT_SHIFT     (2)
/** Memory Array Power Status Mask */
#define SYSCTL_LCDPDS_MEMSTAT_MASK      (0x3)
/** Memory Array Power Status - Off */
#define SYSCTL_LCDPDS_MEMSTAT_ARR_OFF   (0x0)
/** Memory Array Power Status - On */
#define SYSCTL_LCDPDS_MEMSTAT_ARR_ON    (0x3)
/** Power Domain Status Shift*/
#define SYSCTL_LCDPDS_PWRSTAT_SHIFT     (0)
/** Power Domain Status Mask */
#define SYSCTL_LCDPDS_PWRSTAT_MASK      (0x3)
/** Power Domain Status - Off */
#define SYSCTL_LCDPDS_PWRSTAT_OFF       (0x0)
/** Power Domain Status - On */
#define SYSCTL_LCDPDS_PWRSTAT_ON        (0x3)
/**@}*/

/** @defgroup sysctl_lcdmpc_values SYSCTL_LCDMPC Values
 * @brief System Control LCD Memory Power Control Register Values
@{*/
/** Memory Array Power Control Shift */
#define SYSCTL_LCDMPC_PWRCTL_SHIFT    (0)
/** Memory Array Power Control Mask */
#define SYSCTL_LCDMPC_PWRCTL_MASK     (0x3)
/** Memory Array Power Control - Off */
#define SYSCTL_LCDMPC_PWRCTL_ARR_OFF  (0x0)
/** Memory Array Power Control - On */
#define SYSCTL_LCDMPC_PWRCTL_ARR_ON   (0x3)
/**@}*/

/** @defgroup sysctl_can0pds_values SYSCTL_CAN0PDS Values
 * @brief System Control CAN 0 Power Domain Status Register Values
@{*/
/** Memory Array Power Status Shift */
#define SYSCTL_CAN0PDS_MEMSTAT_SHIFT     (2)
/** Memory Array Power Status Mask */
#define SYSCTL_CAN0PDS_MEMSTAT_MASK      (0x3)
/** Memory Array Power Status - Off */
#define SYSCTL_CAN0PDS_MEMSTAT_ARR_OFF   (0x0)
/** Memory Array Power Status - On */
#define SYSCTL_CAN0PDS_MEMSTAT_ARR_ON    (0x3)
/** Power Domain Status Shift*/
#define SYSCTL_CAN0PDS_PWRSTAT_SHIFT     (0)
/** Power Domain Status Mask */
#define SYSCTL_CAN0PDS_PWRSTAT_MASK      (0x3)
/** Power Domain Status - Off */
#define SYSCTL_CAN0PDS_PWRSTAT_OFF       (0x0)
/** Power Domain Status - On */
#define SYSCTL_CAN0PDS_PWRSTAT_ON        (0x3)
/**@}*/

/** @defgroup sysctl_can0mpc_values SYSCTL_CAN0MPC Values
 * @brief System Control CAN 0 Memory Power Control Register Values
@{*/
/** Memory Array Power Control Shift */
#define SYSCTL_CAN0MPC_PWRCTL_SHIFT    (0)
/** Memory Array Power Control Mask */
#define SYSCTL_CAN0MPC_PWRCTL_MASK     (0x3)
/** Memory Array Power Control - Off */
#define SYSCTL_CAN0MPC_PWRCTL_ARR_OFF  (0x0)
/** Memory Array Power Control - On */
#define SYSCTL_CAN0MPC_PWRCTL_ARR_ON   (0x3)
/**@}*/

/** @defgroup sysctl_can1pds_values SYSCTL_CAN1PDS Values
 * @brief System Control CAN 1 Power Domain Status Register Values
@{*/
/** Memory Array Power Status Shift */
#define SYSCTL_CAN1PDS_MEMSTAT_SHIFT     (2)
/** Memory Array Power Status Mask */
#define SYSCTL_CAN1PDS_MEMSTAT_MASK      (0x3)
/** Memory Array Power Status - Off */
#define SYSCTL_CAN1PDS_MEMSTAT_ARR_OFF   (0x0)
/** Memory Array Power Status - On */
#define SYSCTL_CAN1PDS_MEMSTAT_ARR_ON    (0x3)
/** Power Domain Status Shift*/
#define SYSCTL_CAN1PDS_PWRSTAT_SHIFT     (0)
/** Power Domain Status Mask */
#define SYSCTL_CAN1PDS_PWRSTAT_MASK      (0x3)
/** Power Domain Status - Off */
#define SYSCTL_CAN1PDS_PWRSTAT_OFF       (0x0)
/** Power Domain Status - On */
#define SYSCTL_CAN1PDS_PWRSTAT_ON        (0x3)
/**@}*/

/** @defgroup sysctl_can1mpc_values SYSCTL_CAN1MPC Values
 * @brief System Control CAN 1 Memory Power Control Register Values
@{*/
/** Memory Array Power Control Shift */
#define SYSCTL_CAN1MPC_PWRCTL_SHIFT    (0)
/** Memory Array Power Control Mask */
#define SYSCTL_CAN1MPC_PWRCTL_MASK     (0x3)
/** Memory Array Power Control - Off */
#define SYSCTL_CAN1MPC_PWRCTL_ARR_OFF  (0x0)
/** Memory Array Power Control - On */
#define SYSCTL_CAN1MPC_PWRCTL_ARR_ON   (0x3)
/**@}*/

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
    POWER_DISABLE = false,
    POWER_ENABLE = true
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

/**@}*/

#endif /* MSP432E4_SYSTEMCONTROL_H */
