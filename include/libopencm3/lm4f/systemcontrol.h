/** @defgroup systemcontrol_defines System Control

@brief <b>Defined Constants and Types for the LM4F System Control</b>

@ingroup LM4Fxx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012
Alexandru Gagniuc <mr.nuke.me@gmail.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#ifndef LM4F_SYSTEMCONTROL_H
#define LM4F_SYSTEMCONTROL_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lm4f/memorymap.h>

#define SYSCTL_DID0_OFFSET	0x000
#define SYSCTL_DID0			MMIO32(SYSCTL_BASE + SYSCTL_DID0_OFFSET)
#define SYSCTL_DID1_OFFSET	0x004
#define SYSCTL_DID1			MMIO32(SYSCTL_BASE + SYSCTL_DID1_OFFSET)
#define SYSCTL_PBORCTL_OFFSET	0x030
#define SYSCTL_PBORCTL			MMIO32(SYSCTL_BASE + SYSCTL_PBORCTL_OFFSET)
#define SYSCTL_LDORCTL_OFFSET	0x034
#define SYSCTL_LDORCTL			MMIO32(SYSCTL_BASE + SYSCTL_LDORCTL_OFFSET)
#define SYSCTL_RIS_OFFSET	0x050
#define SYSCTL_RIS			MMIO32(SYSCTL_BASE + SYSCTL_RIS_OFFSET)
#define SYSCTL_IMC_OFFSET	0x054
#define SYSCTL_IMC			MMIO32(SYSCTL_BASE + SYSCTL_IMC_OFFSET)
#define SYSCTL_MISC_OFFSET	0x058
#define SYSCTL_MISC			MMIO32(SYSCTL_BASE + SYSCTL_MISC_OFFSET)
#define SYSCTL_RESC_OFFSET	0x05C
#define SYSCTL_RESC			MMIO32(SYSCTL_BASE + SYSCTL_RESC_OFFSET)
#define SYSCTL_RCC_OFFSET	0x060
#define SYSCTL_RCC			MMIO32(SYSCTL_BASE + SYSCTL_RCC_OFFSET)
#define SYSCTL_PLLCFG_OFFSET	0x064
#define SYSCTL_PLLCFG			MMIO32(SYSCTL_BASE + SYSCTL_PLLCFG_OFFSET)
#define SYSCTL_GPIOHBCTL_OFFSET	0x06C
#define SYSCTL_GPIOHBCTL		MMIO32(SYSCTL_BASE + SYSCTL_GPIOHBCTL_OFFSET)
#define SYSCTL_RCC2_OFFSET	0x070
#define SYSCTL_RCC2			MMIO32(SYSCTL_BASE + SYSCTL_RCC2_OFFSET)
#define SYSCTL_MOSCCTL_OFFSET	0x07C
#define SYSCTL_MOSCCTL			MMIO32(SYSCTL_BASE + SYSCTL_MOSCCTL_OFFSET)
#define SYSCTL_DSLPCLKCFG_OFFSET	0x144
#define SYSCTL_DSLPCLKCFG		MMIO32(SYSCTL_BASE + SYSCTL_DSLPCLKCFG_OFFSET)
#define SYSCTL_SYSPROP_OFFSET	0x14C
#define SYSCTL_SYSPROP			MMIO32(SYSCTL_BASE + SYSCTL_SYSPROP_OFFSET)
#define SYSCTL_PIOSCCAL_OFFSET	0x150
#define SYSCTL_PIOSCCAL			MMIO32(SYSCTL_BASE + SYSCTL_PIOSCCAL_OFFSET)
#define SYSCTL_PIOSCSTAT_OFFSET	0x154
#define SYSCTL_PIOSCSTAT		MMIO32(SYSCTL_BASE + SYSCTL_PIOSCSTAT_OFFSET)
#define SYSCTL_PLLFREQ0_OFFSET	0x160
#define SYSCTL_PLLFREQ0			MMIO32(SYSCTL_BASE + SYSCTL_PLLFREQ0_OFFSET)
#define SYSCTL_PLLFREQ1_OFFSET	0x164
#define SYSCTL_PLLFREQ1			MMIO32(SYSCTL_BASE + SYSCTL_PLLFREQ1_OFFSET)
#define SYSCTL_PLLSTAT_OFFSET	0x168
#define SYSCTL_PLLSTAT			MMIO32(SYSCTL_BASE + SYSCTL_PLLSTAT_OFFSET)
/* Peripheral present */
#define SYSCTL_PPWD_OFFSET	0x300
#define SYSCTL_PPWD			MMIO32(SYSCTL_BASE + SYSCTL_PPWD_OFFSET)
#define SYSCTL_PPTIMER_OFFSET	0x304
#define SYSCTL_PPTIMER			MMIO32(SYSCTL_BASE + SYSCTL_PPTIMER_OFFSET)
#define SYSCTL_PPGPIO_OFFSET	0x308
#define SYSCTL_PPGPIO			MMIO32(SYSCTL_BASE + SYSCTL_PPGPIO_OFFSET)
#define SYSCTL_PPDMA_OFFSET		0x30C
#define SYSCTL_PPDMA			MMIO32(SYSCTL_BASE + SYSCTL_PPDMA_OFFSET)
#define SYSCTL_PPHIB_OFFSET		0x314
#define SYSCTL_PPHIB			MMIO32(SYSCTL_BASE + SYSCTL_PPHIB_OFFSET)
#define SYSCTL_PPUART_OFFSET	0x318
#define SYSCTL_PPUART			MMIO32(SYSCTL_BASE + SYSCTL_PPUART_OFFSET)
#define SYSCTL_PPSSI_OFFSET		0x31C
#define SYSCTL_PPSSI			MMIO32(SYSCTL_BASE + SYSCTL_PPSSI_OFFSET)
#define SYSCTL_PPI2C_OFFSET		0x320
#define SYSCTL_PPI2C			MMIO32(SYSCTL_BASE + SYSCTL_PPI2C_OFFSET)
#define SYSCTL_PPUSB_OFFSET		0x328
#define SYSCTL_PPUSB			MMIO32(SYSCTL_BASE + SYSCTL_PPUSB_OFFSET)
#define SYSCTL_PPCAN_OFFSET		0x334
#define SYSCTL_PPCAN			MMIO32(SYSCTL_BASE + SYSCTL_PPCAN_OFFSET)
#define SYSCTL_PPADC_OFFSET		0x338
#define SYSCTL_PPADC			MMIO32(SYSCTL_BASE + SYSCTL_PPADC_OFFSET)
#define SYSCTL_PPACMP_OFFSET	0x33C
#define SYSCTL_PPACMP			MMIO32(SYSCTL_BASE + SYSCTL_PPACMP_OFFSET)
#define SYSCTL_PPPWM_OFFSET		0x340
#define SYSCTL_PPPWM			MMIO32(SYSCTL_BASE + SYSCTL_PPPWM_OFFSET)
#define SYSCTL_PPQEI_OFFSET		0x344
#define SYSCTL_PPQEI			MMIO32(SYSCTL_BASE + SYSCTL_PPQEI_OFFSET)
#define SYSCTL_PPEEPROM_OFFSET	0x358
#define SYSCTL_PPEEPROM			MMIO32(SYSCTL_BASE + SYSCTL_PPEEPROM_OFFSET)
#define SYSCTL_PPWTIMER_OFFSET	0x35C
#define SYSCTL_PPWTIMER			MMIO32(SYSCTL_BASE + SYSCTL_PPWTIMER_OFFSET)
/* Peripheral software reset */
#define SYSCTL_SRWD_OFFSET	0x500
#define SYSCTL_SRWD			MMIO32(SYSCTL_BASE + SYSCTL_SRWD_OFFSET)
#define SYSCTL_SRTIMER_OFFSET	0x504
#define SYSCTL_SRTIMER			MMIO32(SYSCTL_BASE + SYSCTL_SRTIMER_OFFSET)
#define SYSCTL_SRGPIO_OFFSET	0x508
#define SYSCTL_SRGPIO			MMIO32(SYSCTL_BASE + SYSCTL_SRGPIO_OFFSET)
#define SYSCTL_SRDMA_OFFSET		0x50C
#define SYSCTL_SRDMA			MMIO32(SYSCTL_BASE + SYSCTL_SRDMA_OFFSET)
#define SYSCTL_SRHIB_OFFSET		0x514
#define SYSCTL_SRHIB			MMIO32(SYSCTL_BASE + SYSCTL_SRHIB_OFFSET)
#define SYSCTL_SRUART_OFFSET	0x518
#define SYSCTL_SRUART			MMIO32(SYSCTL_BASE + SYSCTL_SRUART_OFFSET)
#define SYSCTL_SRSSI_OFFSET		0x51C
#define SYSCTL_SRSSI			MMIO32(SYSCTL_BASE + SYSCTL_SRSSI_OFFSET)
#define SYSCTL_SRI2C_OFFSET		0x520
#define SYSCTL_SRI2C			MMIO32(SYSCTL_BASE + SYSCTL_SRI2C_OFFSET)
#define SYSCTL_SRUSB_OFFSET		0x528
#define SYSCTL_SRUSB			MMIO32(SYSCTL_BASE + SYSCTL_SRUSB_OFFSET)
#define SYSCTL_SRCAN_OFFSET		0x534
#define SYSCTL_SRCAN			MMIO32(SYSCTL_BASE + SYSCTL_SRCAN_OFFSET)
#define SYSCTL_SRADC_OFFSET		0x538
#define SYSCTL_SRADC			MMIO32(SYSCTL_BASE + SYSCTL_SRADC_OFFSET)
#define SYSCTL_SRACMP_OFFSET	0x53C
#define SYSCTL_SRACMP			MMIO32(SYSCTL_BASE + SYSCTL_SRACMP_OFFSET)
#define SYSCTL_SRPWM_OFFSET		0x540
#define SYSCTL_SRPWM			MMIO32(SYSCTL_BASE + SYSCTL_SRPWM_OFFSET)
#define SYSCTL_SRQEI_OFFSET		0x544
#define SYSCTL_SRQEI			MMIO32(SYSCTL_BASE + SYSCTL_SRQEI_OFFSET)
#define SYSCTL_SREEPROM_OFFSET	0x558
#define SYSCTL_SREEPROM			MMIO32(SYSCTL_BASE + SYSCTL_SREEPROM_OFFSET)
#define SYSCTL_SRWTIMER_OFFSET	0x55C
#define SYSCTL_SRWTIMER			MMIO32(SYSCTL_BASE + SYSCTL_SRWTIMER_OFFSET)
/* Peripheral run mode clock gating control */
#define SYSCTL_RCGCWD_OFFSET	0x600
#define SYSCTL_RCGCWD			MMIO32(SYSCTL_BASE + SYSCTL_RCGCWD_OFFSET)
#define SYSCTL_RCGCTIMER_OFFSET	0x604
#define SYSCTL_RCGCTIMER		MMIO32(SYSCTL_BASE + SYSCTL_RCGCTIMER_OFFSET)
#define SYSCTL_RCGCGPIO_OFFSET	0x608
#define SYSCTL_RCGCGPIO			MMIO32(SYSCTL_BASE + SYSCTL_RCGCGPIO_OFFSET)
#define SYSCTL_RCGCDMA_OFFSET	0x60C
#define SYSCTL_RCGCDMA			MMIO32(SYSCTL_BASE + SYSCTL_RCGCDMA_OFFSET)
#define SYSCTL_RCGCHIB_OFFSET	0x614
#define SYSCTL_RCGCHIB			MMIO32(SYSCTL_BASE + SYSCTL_RCGCHIB_OFFSET)
#define SYSCTL_RCGCUART_OFFSET	0x618
#define SYSCTL_RCGCUART			MMIO32(SYSCTL_BASE + SYSCTL_RCGCUART_OFFSET)
#define SYSCTL_RCGCSSI_OFFSET	0x61C
#define SYSCTL_RCGCSSI			MMIO32(SYSCTL_BASE + SYSCTL_RCGCSSI_OFFSET)
#define SYSCTL_RCGCI2C_OFFSET	0x620
#define SYSCTL_RCGCI2C			MMIO32(SYSCTL_BASE + SYSCTL_RCGCI2C_OFFSET)
#define SYSCTL_RCGCUSB_OFFSET	0x628
#define SYSCTL_RCGCUSB			MMIO32(SYSCTL_BASE + SYSCTL_RCGCUSB_OFFSET)
#define SYSCTL_RCGCCAN_OFFSET	0x634
#define SYSCTL_RCGCCAN			MMIO32(SYSCTL_BASE + SYSCTL_RCGCCAN_OFFSET)
#define SYSCTL_RCGCADC_OFFSET	0x638
#define SYSCTL_RCGCADC			MMIO32(SYSCTL_BASE + SYSCTL_RCGCADC_OFFSET)
#define SYSCTL_RCGCACMP_OFFSET	0x63C
#define SYSCTL_RCGCACMP			MMIO32(SYSCTL_BASE + SYSCTL_RCGCACMP_OFFSET)
#define SYSCTL_RCGCPWM_OFFSET	0x640
#define SYSCTL_RCGCPWM			MMIO32(SYSCTL_BASE + SYSCTL_RCGCPWM_OFFSET)
#define SYSCTL_RCGCQEI_OFFSET	0x644
#define SYSCTL_RCGCQEI			MMIO32(SYSCTL_BASE + SYSCTL_RCGCQEI_OFFSET)
#define SYSCTL_RCGCEEPROM_OFFSET	0x658
#define SYSCTL_RCGCEEPROM		MMIO32(SYSCTL_BASE + SYSCTL_RCGCEEPROM_OFFSET)
#define SYSCTL_RCGCWTIMER_OFFSET	0x65C
#define SYSCTL_RCGCWTIMER		MMIO32(SYSCTL_BASE + SYSCTL_RCGCWTIMER_OFFSET)
/* Peripheral sleep mode clock gating control */
#define SYSCTL_SCGCWD_OFFSET	0x700
#define SYSCTL_SCGCWD			MMIO32(SYSCTL_BASE + SYSCTL_SCGCWD_OFFSET)
#define SYSCTL_SCGCTIMER_OFFSET	0x704
#define SYSCTL_SCGCTIMER		MMIO32(SYSCTL_BASE + SYSCTL_SCGCTIMER_OFFSET)
#define SYSCTL_SCGCGPIO_OFFSET	0x708
#define SYSCTL_SCGCGPIO			MMIO32(SYSCTL_BASE + SYSCTL_SCGCGPIO_OFFSET)
#define SYSCTL_SCGCDMA_OFFSET	0x70C
#define SYSCTL_SCGCDMA			MMIO32(SYSCTL_BASE + SYSCTL_SCGCDMA_OFFSET)
#define SYSCTL_SCGCHIB_OFFSET	0x714
#define SYSCTL_SCGCHIB			MMIO32(SYSCTL_BASE + SYSCTL_SCGCHIB_OFFSET)
#define SYSCTL_SCGCUART_OFFSET	0x718
#define SYSCTL_SCGCUART			MMIO32(SYSCTL_BASE + SYSCTL_SCGCUART_OFFSET)
#define SYSCTL_SCGCSSI_OFFSET	0x71C
#define SYSCTL_SCGCSSI			MMIO32(SYSCTL_BASE + SYSCTL_SCGCSSI_OFFSET)
#define SYSCTL_SCGCI2C_OFFSET	0x720
#define SYSCTL_SCGCI2C			MMIO32(SYSCTL_BASE + SYSCTL_SCGCI2C_OFFSET)
#define SYSCTL_SCGCUSB_OFFSET	0x728
#define SYSCTL_SCGCUSB			MMIO32(SYSCTL_BASE + SYSCTL_SCGCUSB_OFFSET)
#define SYSCTL_SCGCCAN_OFFSET	0x734
#define SYSCTL_SCGCCAN			MMIO32(SYSCTL_BASE + SYSCTL_SCGCCAN_OFFSET)
#define SYSCTL_SCGCADC_OFFSET	0x738
#define SYSCTL_SCGCADC			MMIO32(SYSCTL_BASE + SYSCTL_SCGCADC_OFFSET)
#define SYSCTL_SCGCACMP_OFFSET	0x73C
#define SYSCTL_SCGCACMP			MMIO32(SYSCTL_BASE + SYSCTL_SCGCACMP_OFFSET)
#define SYSCTL_SCGCPWM_OFFSET	0x740
#define SYSCTL_SCGCPWM			MMIO32(SYSCTL_BASE + SYSCTL_SCGCPWM_OFFSET)
#define SYSCTL_SCGCQEI_OFFSET	0x744
#define SYSCTL_SCGCQEI			MMIO32(SYSCTL_BASE + SYSCTL_SCGCQEI_OFFSET)
#define SYSCTL_SCGCEEPROM_OFFSET	0x758
#define SYSCTL_SCGCEEPROM		MMIO32(SYSCTL_BASE + SYSCTL_SCGCEEPROM_OFFSET)
#define SYSCTL_SCGCWTIMER_OFFSET	0x75C
#define SYSCTL_SCGCWTIMER		MMIO32(SYSCTL_BASE + SYSCTL_SCGCWTIMER_OFFSET)
/* Peripheral deep-sleep mode clock gating control */
#define SYSCTL_DCGCWD_OFFSET	0x800
#define SYSCTL_DCGCWD			MMIO32(SYSCTL_BASE + SYSCTL_DCGCWD_OFFSET)
#define SYSCTL_DCGCTIMER_OFFSET	0x804
#define SYSCTL_DCGCTIMER		MMIO32(SYSCTL_BASE + SYSCTL_DCGCTIMER_OFFSET)
#define SYSCTL_DCGCGPIO_OFFSET	0x808
#define SYSCTL_DCGCGPIO			MMIO32(SYSCTL_BASE + SYSCTL_DCGCGPIO_OFFSET)
#define SYSCTL_DCGCDMA_OFFSET	0x80C
#define SYSCTL_DCGCDMA			MMIO32(SYSCTL_BASE + SYSCTL_DCGCDMA_OFFSET)
#define SYSCTL_DCGCHIB_OFFSET	0x814
#define SYSCTL_DCGCHIB			MMIO32(SYSCTL_BASE + SYSCTL_DCGCHIB_OFFSET)
#define SYSCTL_DCGCUART_OFFSET	0x818
#define SYSCTL_DCGCUART			MMIO32(SYSCTL_BASE + SYSCTL_DCGCUART_OFFSET)
#define SYSCTL_DCGCSSI_OFFSET	0x81C
#define SYSCTL_DCGCSSI			MMIO32(SYSCTL_BASE + SYSCTL_DCGCSSI_OFFSET)
#define SYSCTL_DCGCI2C_OFFSET	0x820
#define SYSCTL_DCGCI2C			MMIO32(SYSCTL_BASE + SYSCTL_DCGCI2C_OFFSET)
#define SYSCTL_DCGCUSB_OFFSET	0x828
#define SYSCTL_DCGCUSB			MMIO32(SYSCTL_BASE + SYSCTL_DCGCUSB_OFFSET)
#define SYSCTL_DCGCCAN_OFFSET	0x834
#define SYSCTL_DCGCCAN			MMIO32(SYSCTL_BASE + SYSCTL_DCGCCAN_OFFSET)
#define SYSCTL_DCGCADC_OFFSET	0x838
#define SYSCTL_DCGCADC			MMIO32(SYSCTL_BASE + SYSCTL_DCGCADC_OFFSET)
#define SYSCTL_DCGCACMP_OFFSET	0x83C
#define SYSCTL_DCGCACMP			MMIO32(SYSCTL_BASE + SYSCTL_DCGCACMP_OFFSET)
#define SYSCTL_DCGCPWM_OFFSET	0x840
#define SYSCTL_DCGCPWM			MMIO32(SYSCTL_BASE + SYSCTL_DCGCPWM_OFFSET)
#define SYSCTL_DCGCQEI_OFFSET	0x844
#define SYSCTL_DCGCQEI			MMIO32(SYSCTL_BASE + SYSCTL_DCGCQEI_OFFSET)
#define SYSCTL_DCGCEEPROM_OFFSET	0x858
#define SYSCTL_DCGCEEPROM		MMIO32(SYSCTL_BASE + SYSCTL_DCGCEEPROM_OFFSET)
#define SYSCTL_DCGCWTIMER_OFFSET	0x85C
#define SYSCTL_DCGCWTIMER		MMIO32(SYSCTL_BASE + SYSCTL_DCGCWTIMER_OFFSET)
/* Peripheral ready */
#define SYSCTL_PRWD_OFFSET	0xA00
#define SYSCTL_PRWD			MMIO32(SYSCTL_BASE + SYSCTL_PRWD_OFFSET)
#define SYSCTL_PRTIMER_OFFSET	0xA04
#define SYSCTL_PRTIMER			MMIO32(SYSCTL_BASE + SYSCTL_PRTIMER_OFFSET)
#define SYSCTL_PRGPIO_OFFSET	0xA08
#define SYSCTL_PRGPIO			MMIO32(SYSCTL_BASE + SYSCTL_PRGPIO_OFFSET)
#define SYSCTL_PRDMA_OFFSET		0xA0C
#define SYSCTL_PRDMA			MMIO32(SYSCTL_BASE + SYSCTL_PRDMA_OFFSET)
#define SYSCTL_PRHIB_OFFSET		0xA14
#define SYSCTL_PRHIB			MMIO32(SYSCTL_BASE + SYSCTL_PRHIB_OFFSET)
#define SYSCTL_PRUART_OFFSET	0xA18
#define SYSCTL_PRUART			MMIO32(SYSCTL_BASE + SYSCTL_PRUART_OFFSET)
#define SYSCTL_PRSSI_OFFSET		0xA1C
#define SYSCTL_PRSSI			MMIO32(SYSCTL_BASE + SYSCTL_PRSSI_OFFSET)
#define SYSCTL_PRI2C_OFFSET		0xA20
#define SYSCTL_PRI2C			MMIO32(SYSCTL_BASE + SYSCTL_PRI2C_OFFSET)
#define SYSCTL_PRUSB_OFFSET		0xA28
#define SYSCTL_PRUSB			MMIO32(SYSCTL_BASE + SYSCTL_PRUSB_OFFSET)
#define SYSCTL_PRCAN_OFFSET		0xA34
#define SYSCTL_PRCAN			MMIO32(SYSCTL_BASE + SYSCTL_PRCAN_OFFSET)
#define SYSCTL_PRADC_OFFSET		0xA38
#define SYSCTL_PRADC			MMIO32(SYSCTL_BASE + SYSCTL_PRADC_OFFSET)
#define SYSCTL_PRACMP_OFFSET	0xA3C
#define SYSCTL_PRACMP			MMIO32(SYSCTL_BASE + SYSCTL_PRACMP_OFFSET)
#define SYSCTL_PRPWM_OFFSET		0xA40
#define SYSCTL_PRPWM			MMIO32(SYSCTL_BASE + SYSCTL_PRPWM_OFFSET)
#define SYSCTL_PRQEI_OFFSET		0xA44
#define SYSCTL_PRQEI			MMIO32(SYSCTL_BASE + SYSCTL_PRQEI_OFFSET)
#define SYSCTL_PREEPROM_OFFSET	0xA58
#define SYSCTL_PREEPROM			MMIO32(SYSCTL_BASE + SYSCTL_PREEPROM_OFFSET)
#define SYSCTL_PRWTIMER_OFFSET	0xA5C
#define SYSCTL_PRWTIMER			MMIO32(SYSCTL_BASE + SYSCTL_PRWTIMER_OFFSET)
/* =============================================================================
 * System Control Legacy Registers
 * ---------------------------------------------------------------------------*/
#ifdef LM4F_LEGACY_SYSCTL
#define SYSCTL_DC0_OFFSET	0x008
#define SYSCTL_DC0			MMIO32(SYSCTL_BASE + SYSCTL_DC0_OFFSET)
#define SYSCTL_DC1_OFFSET	0x010
#define SYSCTL_DC1			MMIO32(SYSCTL_BASE + SYSCTL_DC1_OFFSET)
#define SYSCTL_DC2_OFFSET	0x014
#define SYSCTL_DC2			MMIO32(SYSCTL_BASE + SYSCTL_DC2_OFFSET)
#define SYSCTL_DC3_OFFSET	0x018
#define SYSCTL_DC3			MMIO32(SYSCTL_BASE + SYSCTL_DC3_OFFSET)
#define SYSCTL_DC4_OFFSET	0x01C
#define SYSCTL_DC4			MMIO32(SYSCTL_BASE + SYSCTL_DC4_OFFSET)
#define SYSCTL_DC5_OFFSET	0x020
#define SYSCTL_DC5			MMIO32(SYSCTL_BASE + SYSCTL_DC5_OFFSET)
#define SYSCTL_DC6_OFFSET	0x024
#define SYSCTL_DC6			MMIO32(SYSCTL_BASE + SYSCTL_DC6_OFFSET)
#define SYSCTL_DC7_OFFSET	0x028
#define SYSCTL_DC7			MMIO32(SYSCTL_BASE + SYSCTL_DC7_OFFSET)
#define SYSCTL_DC8_OFFSET	0x02C
#define SYSCTL_DC8			MMIO32(SYSCTL_BASE + SYSCTL_DC8_OFFSET)
#define SYSCTL_SRCR0_OFFSET		0x040
#define SYSCTL_SRCR0			MMIO32(SYSCTL_BASE + SYSCTL_SRCR0_OFFSET)
#define SYSCTL_SRCR1_OFFSET		0x044
#define SYSCTL_SRCR1			MMIO32(SYSCTL_BASE + SYSCTL_SRCR1_OFFSET)
#define SYSCTL_SRCR2_OFFSET		0x048
#define SYSCTL_SRCR2			MMIO32(SYSCTL_BASE + SYSCTL_SRCR2_OFFSET)
#define SYSCTL_RCGC0_OFFSET		0x100
#define SYSCTL_RCGC0			MMIO32(SYSCTL_BASE + SYSCTL_RCGC0_OFFSET)
#define SYSCTL_RCGC1_OFFSET		0x104
#define SYSCTL_RCGC1			MMIO32(SYSCTL_BASE + SYSCTL_RCGC1_OFFSET)
#define SYSCTL_RCGC2_OFFSET		0x108
#define SYSCTL_RCGC2			MMIO32(SYSCTL_BASE + SYSCTL_RCGC2_OFFSET)
#define SYSCTL_SCGC0_OFFSET		0x110
#define SYSCTL_SCGC0			MMIO32(SYSCTL_BASE + SYSCTL_SCGC0_OFFSET)
#define SYSCTL_SCGC1_OFFSET		0x114
#define SYSCTL_SCGC1			MMIO32(SYSCTL_BASE + SYSCTL_SCGC1_OFFSET)
#define SYSCTL_SCGC2_OFFSET		0x118
#define SYSCTL_SCGC2			MMIO32(SYSCTL_BASE + SYSCTL_SCGC2_OFFSET)
#define SYSCTL_DCGC0_OFFSET		0x120
#define SYSCTL_DCGC0			MMIO32(SYSCTL_BASE + SYSCTL_DCGC0_OFFSET)
#define SYSCTL_DCGC1_OFFSET		0x124
#define SYSCTL_DCGC1			MMIO32(SYSCTL_BASE + SYSCTL_DCGC1_OFFSET)
#define SYSCTL_DCGC2_OFFSET		0x128
#define SYSCTL_DCGC2			MMIO32(SYSCTL_BASE + SYSCTL_DCGC2_OFFSET)
#define SYSCTL_DC9_OFFSET		0x190
#define SYSCTL_DC9			MMIO32(SYSCTL_BASE + SYSCTL_DC9_OFFSET)
#define SYSCTL_NVMSTAT_OFFSET	0x1A0
#define SYSCTL_NVMSTAT			MMIO32(SYSCTL_BASE + SYSCTL_NVMSTAT_OFFSET)
#endif /* LM4F_LEGACY_SYSCTL */

/* =============================================================================
 * SYSCTL_DID0 values
 * ---------------------------------------------------------------------------*/
/** DID0 version */
#define SYSCTL_DID0_VER_MASK		(7 << 28)
/** Device class */
#define SYSCTL_DID0_CLASS_MASK		(0xFF << 16)
/** Major revision */
#define SYSCTL_DID0_MAJOR_MASK		(0xFF << 8)
/** Minor revision */
#define SYSCTL_DID0_MAJOR_MASK		(0xFF << 8)

/* =============================================================================
 * SYSCTL_DID1 values
 * ---------------------------------------------------------------------------*/
/** DID1 version */
#define SYSCTL_DID1_VER_MASK		(0xF << 28)
/** Family */
#define SYSCTL_DID1_FAM_MASK		(0xF << 24)
/** Part number */
#define SYSCTL_DID1_PARTNO_MASK		(0xFF << 16)
/** Pin count */
#define SYSCTL_DID1_PINCOUNT_MASK	(0x7 << 13)
#define SYSCTL_DID1_PINCOUNT_28P	(0x0 << 13)
#define SYSCTL_DID1_PINCOUNT_48P	(0x1 << 13)
#define SYSCTL_DID1_PINCOUNT_100P	(0x2 << 13)
#define SYSCTL_DID1_PINCOUNT_64P	(0x3 << 13)
#define SYSCTL_DID1_PINCOUNT_144P	(0x4 << 13)
#define SYSCTL_DID1_PINCOUNT_157P	(0x5 << 13)
/** Temperature range */
#define SYSCTL_DID1_TEMP_MASK		(0x7 << 5)
#define SYSCTL_DID1_TEMP_0_70		(0x0 << 5)
#define SYSCTL_DID1_TEMP_M40_85		(0x1 << 5)
#define SYSCTL_DID1_TEMP_M40_105	(0x2 << 5)
/** Package */
#define SYSCTL_DID1_PKG_MASK		(0x3 << 5)
#define SYSCTL_DID1_PKG_SOIC		(0x0 << 5)
#define SYSCTL_DID1_PKG_LQFP		(0x1 << 5)
#define SYSCTL_DID1_PKG_BGA		(0x2 << 5)
/** ROHS compliance */
#define SYSCTL_DID1_ROHS		(1 << 2)
/** Qualification status */
#define SYSCTL_DID1_QUAL_MASK		(3 << 0)

/* =============================================================================
 * SYSCTL_PBORCTL values
 * ---------------------------------------------------------------------------*/
/** BOR interrupt or reset */
#define SYSCTL_PBORCTL_BORIOR		(1 << 1)

/* =============================================================================
 * SYSCTL_RIS values
 * ---------------------------------------------------------------------------*/
/** MOSC Power Up Raw Interrupt Status */
#define SYSCTL_RIS_MOSCPUPRIS		(1 << 8)
/** USB PLL Lock Raw Interrupt Status */
#define SYSCTL_RIS_USBPLLLRIS		(1 << 7)
/** PLL Lock Raw Interrupt Status */
#define SYSCTL_RIS_PLLLRIS		(1 << 6)
/** Main Oscillator Failure Raw Interrupt Status */
#define SYSCTL_RIS_MOFRIS		(1 << 3)
/** Brown-Out Reset Raw Interrupt Status */
#define SYSCTL_RIS_BORRIS		(1 << 1)

/* =============================================================================
 * SYSCTL_IMC values
 * ---------------------------------------------------------------------------*/
/** MOSC Power Up Raw Interrupt Status */
#define SYSCTL_IMC_MOSCPUPIM		(1 << 8)
/** USB PLL Lock Raw Interrupt Status */
#define SYSCTL_IMC_USBPLLLIM		(1 << 7)
/** PLL Lock Raw Interrupt Status */
#define SYSCTL_IMC_PLLLIM		(1 << 6)
/** Main Oscillator Failure Raw Interrupt Status */
#define SYSCTL_IMC_MOFIM		(1 << 3)
/** Brown-Out Reset Raw Interrupt Status */
#define SYSCTL_IMC_BORIM		(1 << 1)

/* =============================================================================
 * SYSCTL_MISC values
 * ---------------------------------------------------------------------------*/
/** MOSC Power Up Raw Interrupt Status */
#define SYSCTL_MISC_MOSCPUPMIS		(1 << 8)
/** USB PLL Lock Raw Interrupt Status */
#define SYSCTL_MISC_USBPLLLMIS		(1 << 7)
/** PLL Lock Raw Interrupt Status */
#define SYSCTL_MISC_PLLLMIS		(1 << 6)
/** Main Oscillator Failure Raw Interrupt Status */
#define SYSCTL_MISC_MOFMIS		(1 << 3)
/** Brown-Out Reset Raw Interrupt Status */
#define SYSCTL_MISC_BORMIS		(1 << 1)

/* =============================================================================
 * SYSCTL_RESC values
 * ---------------------------------------------------------------------------*/
/** MOSC Failure Reset */
#define SYSCTL_RESC_MOSCFAIL		(1 << 18)
/** Watchdog Timer 1 Reset */
#define SYSCTL_RESC_WDT1		(1 << 5)
/** Software Reset */
#define SYSCTL_RESC_SW			(1 << 4)
/** Watchdog Timer 0 Reset */
#define SYSCTL_RESC_WDT0		(1 << 3)
/** Brown-Out Reset */
#define SYSCTL_RESC_BOR			(1 << 2)
/** Power-On Reset */
#define SYSCTL_RESC_POR			(1 << 1)
/** External Reset */
#define SYSCTL_RESC_EXT			(1 << 0)

/* =============================================================================
 * SYSCTL_RCC values
 * ---------------------------------------------------------------------------*/
/** Auto Clock Gating */
#define SYSCTL_RCC_ACG			(1 << 27)
/** System Clock Divisor */
#define SYSCTL_RCC_SYSDIV_MASK		(0xF << 23)
/** Enable System Clock Divider */
#define SYSCTL_RCC_USESYSDIV		(1 << 22)
/** Enable PWM Clock Divisor */
#define SYSCTL_RCC_USEPWMDIV		(1 << 20)
/** PWM Unit Clock Divisor */
#define SYSCTL_RCC_PWMDIV_MASK		(0xF << 17)
#define SYSCTL_RCC_PWMDIV_2		(0x0 << 17)
#define SYSCTL_RCC_PWMDIV_4		(0x1 << 17)
#define SYSCTL_RCC_PWMDIV_8		(0x2 << 17)
#define SYSCTL_RCC_PWMDIV_16		(0x3 << 17)
#define SYSCTL_RCC_PWMDIV_32		(0x4 << 17)
#define SYSCTL_RCC_PWMDIV_64		(0x5 << 17)
/** PLL Power Down */
#define SYSCTL_RCC_PWRDN		(1 << 13)
/** PLL Bypass */
#define SYSCTL_RCC_BYPASS		(1 << 11)
/** Crystal Value */
#define SYSCTL_RCC_XTAL_MASK		(0x1F << 6)
#define SYSCTL_RCC_XTAL_4M		(0x06 << 6)
#define SYSCTL_RCC_XTAL_4M_096		(0x07 << 6)
#define SYSCTL_RCC_XTAL_4M_9152		(0x08 << 6)
#define SYSCTL_RCC_XTAL_5M		(0x09 << 6)
#define SYSCTL_RCC_XTAL_5M_12		(0x0A << 6)
#define SYSCTL_RCC_XTAL_6M		(0x0B << 6)
#define SYSCTL_RCC_XTAL_6M_144		(0x0C << 6)
#define SYSCTL_RCC_XTAL_7M_3728		(0x0D << 6)
#define SYSCTL_RCC_XTAL_8M		(0x0E << 6)
#define SYSCTL_RCC_XTAL_8M_192		(0x0F << 6)
#define SYSCTL_RCC_XTAL_10M		(0x10 << 6)
#define SYSCTL_RCC_XTAL_12M		(0x11 << 6)
#define SYSCTL_RCC_XTAL_12M_288		(0x12 << 6)
#define SYSCTL_RCC_XTAL_13M_56		(0x13 << 6)
#define SYSCTL_RCC_XTAL_14M_31818	(0x14 << 6)
#define SYSCTL_RCC_XTAL_16M		(0x15 << 6)
#define SYSCTL_RCC_XTAL_16M_384		(0x16 << 6)
#define SYSCTL_RCC_XTAL_18M		(0x17 << 6)
#define SYSCTL_RCC_XTAL_20M		(0x18 << 6)
#define SYSCTL_RCC_XTAL_24M		(0x19 << 6)
#define SYSCTL_RCC_XTAL_25M		(0x1A << 6)
/** Oscillator Source */
#define SYSCTL_RCC_OSCSRC_MASK		(0x3 << 4)
#define SYSCTL_RCC_OSCSRC_MOSC		(0x0 << 4)
#define SYSCTL_RCC_OSCSRC_PIOSC		(0x1 << 4)
#define SYSCTL_RCC_OSCSRC_PIOSC_D4	(0x2 << 4)
#define SYSCTL_RCC_OSCSRC_30K		(0x3 << 4)
/** Precision Internal Oscillator Disable */
#define SYSCTL_RCC_IOSCDIS		(1 << 1)
/** Main Oscillator Disable */
#define SYSCTL_RCC_MOSCDIS		(1 << 0)

/* =============================================================================
 * SYSCTL_GPIOHBCTL values
 * ---------------------------------------------------------------------------*/
#define SYSCTL_GPIOHBCTL_PORTQ		(1 << 14)
#define SYSCTL_GPIOHBCTL_PORTP		(1 << 13)
#define SYSCTL_GPIOHBCTL_PORTN		(1 << 12)
#define SYSCTL_GPIOHBCTL_PORTM		(1 << 11)
#define SYSCTL_GPIOHBCTL_PORTL		(1 << 10)
#define SYSCTL_GPIOHBCTL_PORTK		(1 << 9)
#define SYSCTL_GPIOHBCTL_PORTJ		(1 << 8)
#define SYSCTL_GPIOHBCTL_PORTH		(1 << 7)
#define SYSCTL_GPIOHBCTL_PORTG		(1 << 6)
#define SYSCTL_GPIOHBCTL_PORTF		(1 << 5)
#define SYSCTL_GPIOHBCTL_PORTE		(1 << 4)
#define SYSCTL_GPIOHBCTL_PORTD		(1 << 3)
#define SYSCTL_GPIOHBCTL_PORTC		(1 << 2)
#define SYSCTL_GPIOHBCTL_PORTB		(1 << 1)
#define SYSCTL_GPIOHBCTL_PORTA		(1 << 0)

/* =============================================================================
 * SYSCTL_RCC2 values
 * ---------------------------------------------------------------------------*/
/** RCC2 overides RCC */
#define SYSCTL_RCC2_USERCC2		(1 << 31)
/** Divide PLL as 400 MHz vs. 200 MHz */
#define SYSCTL_RCC2_DIV400		(1 << 30)
/** Auto Clock Gating */
#define SYSCTL_RCC2_ACG			(1 << 27)
/** System Clock Divisor 2 */
#define SYSCTL_RCC2_SYSDIV2_MASK	(0x3F << 23)
/** Additional LSB for SYSDIV2 */
#define SYSCTL_RCC2_SYSDIV2LSB		(1 << 22)
/** System clock divisor mask when RCC2_DIV400 is set */
#define SYSCTL_RCC2_SYSDIV400_MASK	(0x7F << 22)
/** Power-Down USB PLL */
#define SYSCTL_RCC2_USBPWRDN		(1 << 14)
/** PLL Power Down 2 */
#define SYSCTL_RCC2_PWRDN2		(1 << 13)
/** PLL Bypass 2 */
#define SYSCTL_RCC2_BYPASS2		(1 << 11)
/** Oscillator Source 2 */
#define SYSCTL_RCC2_OSCSRC2_MASK	(0x7 << 4)
#define SYSCTL_RCC2_OSCSRC2_MOSC	(0x0 << 4)
#define SYSCTL_RCC2_OSCSRC2_PIOSC	(0x1 << 4)
#define SYSCTL_RCC2_OSCSRC2_PIOSC_D4	(0x2 << 4)
#define SYSCTL_RCC2_OSCSRC2_30K		(0x3 << 4)
#define SYSCTL_RCC2_OSCSRC2_32K768	(0x7 << 4)

/* =============================================================================
 * SYSCTL_MOSCCTL values
 * ---------------------------------------------------------------------------*/
/** No Crystal Connected */
#define SYSCTL_MOSCCTL_NOXTAL		(1 << 2)
/** MOSC Failure Action */
#define SYSCTL_MOSCCTL_MOSCIM		(1 << 1)
/** Clock Validation for MOSC */
#define SYSCTL_MOSCCTL_CVAL		(1 << 0)

/* =============================================================================
 * SYSCTL_DSLPCLKCFG values
 * ---------------------------------------------------------------------------*/
/*TODO*/

/* =============================================================================
 * SYSCTL_SYSPROP values
 * ---------------------------------------------------------------------------*/
/** FPU present */
#define SYSCTL_SYSPROP_FPU		(1 << 0)

/* =============================================================================
 * SYSCTL_PIOSCCAL values
 * ---------------------------------------------------------------------------*/
/** Use User Trim Value */
#define SYSCTL_PIOSCCAL_UTEN		(1 << 31)
/** Start calibration */
#define SYSCTL_PIOSCCAL_CAL		(1 << 9)
/** Update trim */
#define SYSCTL_PIOSCCAL_UPDATE		(1 << 8)
/** User Trim Value */
#define SYSCTL_PIOSCCAL_UT_MASK		(0x7F << 0)

/* =============================================================================
 * SYSCTL_PIOSCSTAT values
 * ---------------------------------------------------------------------------*/
/** Default Trim Value */
#define SYSCTL_PIOSCSTAT_DT_MASK	(0x7F << 16)
/** Calibration result */
#define SYSCTL_PIOSCSTAT_RESULT_MASK	(0x3 << 8)
/** Calibration Trim Value */
#define SYSCTL_PIOSCSTAT_CT_MASK	(0x7F << 0)
/* =============================================================================
 * SYSCTL_PLLFREQ0 values
 * ---------------------------------------------------------------------------*/
/** PLL M fractional value */
#define SYSCTL_PLLFREQ0_MFRAC_MASK	(0x3FF << 10)
/** PLL M integer value */
#define SYSCTL_PLLFREQ0_MINT_MASK	(0x3FF << 0)

/* =============================================================================
 * SYSCTL_PLLFREQ1 values
 * ---------------------------------------------------------------------------*/
/** PLL Q value */
#define SYSCTL_PLLFREQ1_Q_MASK		(0x1F << 8)
/** PLL N value */
#define SYSCTL_PLLFREQ1_N_MASK		(0x1F << 0)

/* =============================================================================
 * SYSCTL_PLLSTAT values
 * ---------------------------------------------------------------------------*/
/** PLL lock */
#define SYSCTL_PLLSTAT_LOCK		(1 << 0)

/* =============================================================================
 * Convenience definitions for a readable API
 * ---------------------------------------------------------------------------*/
/**
 * \brief Clock enable definitions
 *
 * The definitions are specified in the form
 * 31:5 register offset from SYSCTL_BASE for the clock register
 * 4:0  bit offset for the given peripheral
 *
 * The names have the form [clock_type]_[periph_type]_[periph_number]
 * Where clock_type is
 *     RCC for run clock
 *     SCC for sleep clock
 *     DCC for deep-sleep clock
 */
enum lm4f_clken {
	/*
	 * Run clock control
	 */
	RCC_WD0 = SYSCTL_RCGCWD_OFFSET << 5,
	RCC_WD1,

	RCC_TIMER0 = SYSCTL_RCGCTIMER_OFFSET << 5,
	RCC_TIMER1,
	RCC_TIMER2,
	RCC_TIMER3,
	RCC_TIMER4,
	RCC_TIMER5,

	RCC_GPIOA = SYSCTL_RCGCGPIO_OFFSET << 5,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_GPIOF,
	RCC_GPIOG,
	RCC_GPIOH,
	RCC_GPIOJ,
	RCC_GPIOK,
	RCC_GPIOL,
	RCC_GPIOM,
	RCC_GPION,
	RCC_GPIOP,
	RCC_GPIOQ,

	RCC_DMA = SYSCTL_RCGCDMA_OFFSET << 5,

	RCC_HIB = SYSCTL_RCGCGPIO_OFFSET << 5,

	RCC_UART0 = SYSCTL_RCGCUART_OFFSET << 5,
	RCC_UART1,
	RCC_UART2,
	RCC_UART3,
	RCC_UART4,
	RCC_UART5,
	RCC_UART6,
	RCC_UART7,

	RCC_SSI0 = SYSCTL_RCGCSSI_OFFSET << 5,
	RCC_SSI1,
	RCC_SSI2,
	RCC_SSI3,

	RCC_I2C0 = SYSCTL_RCGCI2C_OFFSET << 5,
	RCC_I2C1,
	RCC_I2C2,
	RCC_I2C3,
	RCC_I2C4,
	RCC_I2C5,

	RCC_USB0 = SYSCTL_RCGCUSB_OFFSET << 5,

	RCC_CAN0 = SYSCTL_RCGCCAN_OFFSET << 5,
	RCC_CAN1,

	RCC_ADC0 = SYSCTL_RCGCADC_OFFSET << 5,
	RCC_ADC1,

	RCC_ACMP0 = SYSCTL_RCGCACMP_OFFSET << 5,

	RCC_PWM0 = SYSCTL_RCGCPWM_OFFSET << 5,
	RCC_PWM1,

	RCC_QEI0 = SYSCTL_RCGCQEI_OFFSET << 5,
	RCC_QEI1,

	RCC_EEPROM0 = SYSCTL_RCGCEEPROM_OFFSET << 5,

	RCC_WTIMER0 = SYSCTL_RCGCWTIMER_OFFSET << 5,
	RCC_WTIMER1,
	RCC_WTIMER2,
	RCC_WTIMER3,
	RCC_WTIMER4,
	RCC_WTIMER5,


	/*
	 * Sleep clock control
	 */
	SCC_WD0 = SYSCTL_SCGCWD_OFFSET << 5,
	SCC_WD1,

	SCC_TIMER0 = SYSCTL_SCGCTIMER_OFFSET << 5,
	SCC_TIMER1,
	SCC_TIMER2,
	SCC_TIMER3,
	SCC_TIMER4,
	SCC_TIMER5,

	SCC_GPIOA = SYSCTL_SCGCGPIO_OFFSET << 5,
	SCC_GPIOB,
	SCC_GPIOC,
	SCC_GPIOD,
	SCC_GPIOE,
	SCC_GPIOF,
	SCC_GPIOG,
	SCC_GPIOH,
	SCC_GPIOJ,
	SCC_GPIOK,
	SCC_GPIOL,
	SCC_GPIOM,
	SCC_GPION,
	SCC_GPIOP,
	SCC_GPIOQ,

	SCC_DMA = SYSCTL_SCGCDMA_OFFSET << 5,

	SCC_HIB = SYSCTL_SCGCGPIO_OFFSET << 5,

	SCC_UART0 = SYSCTL_SCGCUART_OFFSET << 5,
	SCC_UART1,
	SCC_UART2,
	SCC_UART3,
	SCC_UART4,
	SCC_UART5,
	SCC_UART6,
	SCC_UART7,

	SCC_SSI0 = SYSCTL_SCGCSSI_OFFSET << 5,
	SCC_SSI1,
	SCC_SSI2,
	SCC_SSI3,

	SCC_I2C0 = SYSCTL_SCGCI2C_OFFSET << 5,
	SCC_I2C1,
	SCC_I2C2,
	SCC_I2C3,
	SCC_I2C4,
	SCC_I2C5,

	SCC_USB0 = SYSCTL_SCGCUSB_OFFSET << 5,

	SCC_CAN0 = SYSCTL_SCGCCAN_OFFSET << 5,
	SCC_CAN1,

	SCC_ADC0 = SYSCTL_SCGCADC_OFFSET << 5,
	SCC_ADC1,

	SCC_ACMP0 = SYSCTL_SCGCACMP_OFFSET << 5,

	SCC_PWM0 = SYSCTL_SCGCPWM_OFFSET << 5,
	SCC_PWM1,

	SCC_QEI0 = SYSCTL_SCGCQEI_OFFSET << 5,
	SCC_QEI1,

	SCC_EEPROM0 = SYSCTL_SCGCEEPROM_OFFSET << 5,

	SCC_WTIMER0 = SYSCTL_SCGCWTIMER_OFFSET << 5,
	SCC_WTIMER1,
	SCC_WTIMER2,
	SCC_WTIMER3,
	SCC_WTIMER4,
	SCC_WTIMER5,

	/*
	 * Deep-sleep clock control
	 */
	DCC_WD0 = SYSCTL_DCGCWD_OFFSET << 5,
	DCC_WD1,

	DCC_TIMER0 = SYSCTL_DCGCTIMER_OFFSET << 5,
	DCC_TIMER1,
	DCC_TIMER2,
	DCC_TIMER3,
	DCC_TIMER4,
	DCC_TIMER5,

	DCC_GPIOA = SYSCTL_DCGCGPIO_OFFSET << 5,
	DCC_GPIOB,
	DCC_GPIOC,
	DCC_GPIOD,
	DCC_GPIOE,
	DCC_GPIOF,
	DCC_GPIOG,
	DCC_GPIOH,
	DCC_GPIOJ,
	DCC_GPIOK,
	DCC_GPIOL,
	DCC_GPIOM,
	DCC_GPION,
	DCC_GPIOP,
	DCC_GPIOQ,

	DCC_DMA = SYSCTL_DCGCDMA_OFFSET << 5,

	DCC_HIB = SYSCTL_DCGCGPIO_OFFSET << 5,

	DCC_UART0 = SYSCTL_DCGCUART_OFFSET << 5,
	DCC_UART1,
	DCC_UART2,
	DCC_UART3,
	DCC_UART4,
	DCC_UART5,
	DCC_UART6,
	DCC_UART7,

	DCC_SSI0 = SYSCTL_DCGCSSI_OFFSET << 5,
	DCC_SSI1,
	DCC_SSI2,
	DCC_SSI3,

	DCC_I2C0 = SYSCTL_DCGCI2C_OFFSET << 5,
	DCC_I2C1,
	DCC_I2C2,
	DCC_I2C3,
	DCC_I2C4,
	DCC_I2C5,

	DCC_USB0 = SYSCTL_DCGCUSB_OFFSET << 5,

	DCC_CAN0 = SYSCTL_DCGCCAN_OFFSET << 5,
	DCC_CAN1,

	DCC_ADC0 = SYSCTL_DCGCADC_OFFSET << 5,
	DCC_ADC1,

	DCC_ACMP0 = SYSCTL_DCGCACMP_OFFSET << 5,

	DCC_PWM0 = SYSCTL_DCGCPWM_OFFSET << 5,
	DCC_PWM1,

	DCC_QEI0 = SYSCTL_DCGCQEI_OFFSET << 5,
	DCC_QEI1,

	DCC_EEPROM0 = SYSCTL_DCGCEEPROM_OFFSET << 5,

	DCC_WTIMER0 = SYSCTL_DCGCWTIMER_OFFSET << 5,
	DCC_WTIMER1,
	DCC_WTIMER2,
	DCC_WTIMER3,
	DCC_WTIMER4,
	DCC_WTIMER5,

};

/* ============================================================================
 * Function prototypes
 * --------------------------------------------------------------------------*/
BEGIN_DECLS

void periph_clock_enable(enum lm4f_clken periph);
void periph_clock_disable(enum lm4f_clken periph);

END_DECLS

/**@}*/

#endif /* LM4F_SYSTEMCONTROL_H */

