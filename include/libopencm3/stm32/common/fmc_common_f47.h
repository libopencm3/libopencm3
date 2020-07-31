/** @addtogroup fmc_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Chuck McManis <cmcmanis@mcmanis.com>
 *
 * @date 2013
 *
 * This library supports the Flexible Memory Controller (FMC) in the STM32F4xx
 * and STM32F7xx series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Chuck McManis <cmcmanis@mcmanis.com>
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

#ifndef LIBOPENCM3_FMC_COMMON_F47_H
#define LIBOPENCM3_FMC_COMMON_F47_H

#ifndef LIBOPENCM3_FSMC_H
#error "This file should not be included directly, it is included with fsmc.h"
#endif

/* --- Convenience macros -------------------------------------------------- */
#define FMC_BANK5_BASE			0xa0000000U
#define FMC_BANK6_BASE			0xb0000000U
#define FMC_BANK7_BASE			0xc0000000U
#define FMC_BANK8_BASE			0xd0000000U

/* --- FMC registers ------------------------------------------------------ */

/* SDRAM Control Registers 1 .. 2 */
#define FMC_SDCR(x)			MMIO32(FSMC_BASE + 0x140 + 4 * (x))
#define FMC_SDCR1			FMC_SDCR(0)
#define FMC_SDCR2			FMC_SDCR(1)


/* SDRAM Timing Registers 1 .. 2 */
#define FMC_SDTR(x)			MMIO32(FSMC_BASE + 0x148 + 4 * (x))
#define FMC_SDTR1			FMC_SDTR(0)
#define FMC_SDTR2			FMC_SDTR(1)

/* SDRAM Command Mode Register */
#define FMC_SDCMR			MMIO32(FSMC_BASE + (uint32_t) 0x150)

/* SDRAM Refresh Timer Register */
#define FMC_SDRTR			MMIO32(FSMC_BASE + 0x154)

/* SDRAM Status Register */
#define FMC_SDSR			MMIO32(FSMC_BASE + (uint32_t) 0x158)

/* --- FMC_SDCRx values ---------------------------------------------------- */

/* Bits [31:15]: Reserved. */

/* RPIPE: Read Pipe */
#define FMC_SDCR_RPIPE_SHIFT		13
#define FMC_SDCR_RPIPE_MASK		(3 << FMC_SDCR_RPIPE_SHIFT)
#define FMC_SDCR_RPIPE_NONE		(0 << FMC_SDCR_RPIPE_SHIFT)
#define FMC_SDCR_RPIPE_1CLK		(1 << FMC_SDCR_RPIPE_SHIFT)
#define FMC_SDCR_RPIPE_2CLK		(2 << FMC_SDCR_RPIPE_SHIFT)

/* RBURST: Burst Read */
#define FMC_SDCR_RBURST			(1 << 12)

/* SDCLK: SDRAM Clock Configuration */
#define FMC_SDCR_SDCLK_SHIFT		10
#define FMC_SDCR_SDCLK_MASK		(3 << FMC_SDCR_SDCLK_SHIFT)
#define FMC_SDCR_SDCLK_DISABLE		(0 << FMC_SDCR_SDCLK_SHIFT)
#define FMC_SDCR_SDCLK_2HCLK		(2 << FMC_SDCR_SDCLK_SHIFT)
#define FMC_SDCR_SDCLK_3HCLK		(3 << FMC_SDCR_SDCLK_SHIFT)

/* WP: Write Protect */
#define FMC_SDCR_WP_ENABLE		(1 << 9)

/* CAS: CAS Latency */
#define FMC_SDCR_CAS_SHIFT		7
#define FMC_SDCR_CAS_1CYC		(1 << FMC_SDCR_CAS_SHIFT)
#define FMC_SDCR_CAS_2CYC		(2 << FMC_SDCR_CAS_SHIFT)
#define FMC_SDCR_CAS_3CYC		(3 << FMC_SDCR_CAS_SHIFT)

/* NB: Number of Internal banks */
#define FMC_SDCR_NB2			0
#define FMC_SDCR_NB4			(1 << 6)

/* MWID: Memory width */
#define FMC_SDCR_MWID_SHIFT		4
#define FMC_SDCR_MWID_8b		(0 << FMC_SDCR_MWID_SHIFT)
#define FMC_SDCR_MWID_16b		(1 << FMC_SDCR_MWID_SHIFT)
#define FMC_SDCR_MWID_32b		(2 << FMC_SDCR_MWID_SHIFT)

/* NR: Number of rows */
#define FMC_SDCR_NR_SHIFT		2
#define FMC_SDCR_NR_11			(0 << FMC_SDCR_NR_SHIFT)
#define FMC_SDCR_NR_12			(1 << FMC_SDCR_NR_SHIFT)
#define FMC_SDCR_NR_13			(2 << FMC_SDCR_NR_SHIFT)

/* NC: Number of Columns */
#define FMC_SDCR_NC_SHIFT		0
#define FMC_SDCR_NC_8			(0 << FMC_SDCR_NC_SHIFT)
#define FMC_SDCR_NC_9			(1 << FMC_SDCR_NC_SHIFT)
#define FMC_SDCR_NC_10			(2 << FMC_SDCR_NC_SHIFT)
#define FMC_SDCR_NC_11			(3 << FMC_SDCR_NC_SHIFT)

/* --- FMC_SDTRx values --------------------------------------------------- */

/* Bits [31:28]: Reserved. */

/* TRCD: Row to Column Delay */
#define FMC_SDTR_TRCD_SHIFT		24
#define FMC_SDTR_TRCD_MASK		(15 << FMC_SDTR_TRCD_SHIFT)

/* TRP: Row Precharge Delay */
#define FMC_SDTR_TRP_SHIFT		20
#define FMC_SDTR_TRP_MASK		(15 << FMC_SDTR_TRP_SHIFT)

/* TWR: Recovery Delay */
#define FMC_SDTR_TWR_SHIFT		16
#define FMC_SDTR_TWR_MASK		(15 << FMC_SDTR_TWR_SHIFT)

/* TRC: Row Cycle Delay */
#define FMC_SDTR_TRC_SHIFT		12
#define FMC_SDTR_TRC_MASK		(15 << FMC_SDTR_TRC_SHIFT)

/* TRAS: Self Refresh Time */
#define FMC_SDTR_TRAS_SHIFT		8
#define FMC_SDTR_TRAS_MASK		(15 << FMC_SDTR_TRAS_SHIFT)

/* TXSR: Exit Self-refresh Delay */
#define FMC_SDTR_TXSR_SHIFT		4
#define FMC_SDTR_TXSR_MASK		(15 << FMC_SDTR_TXSR_SHIFT)

/* TRMD: Load Mode Register to Active */
#define FMC_SDTR_TMRD_SHIFT		0
#define FMC_SDTR_TMRD_MASK		(15 << FMC_SDTR_TMRD_SHIFT)

/*
 * Some config bits only count in CR1 or TR1, even if you
 * are just configuring bank 2, so these masks let you copy
 * out those bits after you have computed values for CR2 and
 * TR2 and put them into CR1 and TR1
 */
#define FMC_SDTR_DNC_MASK	(FMC_SDTR_TRP_MASK | FMC_SDTR_TRC_MASK)
#define FMC_SDCR_DNC_MASK	(FMC_SDCR_SDCLK_MASK | \
				 FMC_SDCR_RPIPE_MASK  | \
				 FMC_SDCR_RBURST)

/* --- FMC_SDCMR values --------------------------------------------------- */

/* Bits [31:22]: Reserved. */

/* MRD: Mode Register Definition */
#define FMC_SDCMR_MRD_SHIFT		9
#define FMC_SDCMR_MRD_MASK		(0x1fff << FMC_SDCMR_MRD_SHIFT)

/* NRFS: Number of Auto-refresh */
#define FMC_SDCMR_NRFS_SHIFT		5
#define FMC_SDCMR_NRFS_MASK		(15 << FMC_SDCMR_NRFS_SHIFT)

/* CTB1: Command Target Bank 1 */
#define FMC_SDCMR_CTB1			(1 << 4)

/* CTB2: Command Target Bank 2 */
#define FMC_SDCMR_CTB2			(1 << 3)

/* MODE: Command Mode */
#define FMC_SDCMR_MODE_SHIFT		0
#define FMC_SDCMR_MODE_MASK		7
#define FMC_SDCMR_MODE_NORMAL			0
#define FMC_SDCMR_MODE_CLOCK_CONFIG_ENA		1
#define FMC_SDCMR_MODE_PALL			2
#define FMC_SDCMR_MODE_AUTO_REFRESH		3
#define FMC_SDCMR_MODE_LOAD_MODE_REGISTER	4
#define FMC_SDCMR_MODE_SELF_REFRESH		5
#define FMC_SDCMR_MODE_POWER_DOWN		6

/* --- FMC_SDRTR values ---------------------------------------------------- */

/* Bits [31:15]: Reserved. */

/* REIE: Refresh Error Interrupt Enable */
#define FMC_SDRTR_REIE			(1 << 14)

/* COUNT: Refresh Timer Count */
#define FMC_SDRTR_COUNT_SHIFT		1
#define FMC_SDRTR_COUNT_MASK		(0x1fff << FMC_SDRTR_COUNT_SHIFT)

/* CRE: Clear Refresh Error Flag */
#define FMC_SDRTR_CRE			(1 << 0)

/* --- FMC_SDSR values ---------------------------------------------------- */

/* Bits [31:6]: Reserved. */

/* BUSY: Set if the SDRAM is working on the command */
#define FMC_SDSR_BUSY			(1 << 5)

/* MODES: Status modes */
#define FMC_SDSR_MODE_NORMAL		0
#define FMC_SDSR_MODE_SELF_REFRESH	1
#define FMC_SDSR_MODE_POWER_DOWN	2

/* Mode shift */
#define FMC_SDSR_MODE2_SHIFT		3
#define FMC_SDSR_MODE1_SHIFT		1

/* RE: Refresh Error */
#define FMC_SDSR_RE			(1 << 0)

/* Helper function for setting the timing parameters */
struct sdram_timing {
	int trcd;		/* RCD Delay */
	int trp;		/* RP Delay */
	int twr;		/* Write Recovery Time */
	int trc;		/* Row Cycle Delay */
	int tras;		/* Self Refresh TIme */
	int txsr;		/* Exit Self Refresh Time */
	int tmrd;		/* Load to Active delay */
};

/* Mode register parameters */
#define SDRAM_MODE_BURST_LENGTH_1		((uint16_t)0x0000)
#define SDRAM_MODE_BURST_LENGTH_2		((uint16_t)0x0001)
#define SDRAM_MODE_BURST_LENGTH_4		((uint16_t)0x0002)
#define SDRAM_MODE_BURST_LENGTH_8		((uint16_t)0x0004)
#define SDRAM_MODE_BURST_TYPE_SEQUENTIAL	((uint16_t)0x0000)
#define SDRAM_MODE_BURST_TYPE_INTERLEAVED	((uint16_t)0x0008)
#define SDRAM_MODE_CAS_LATENCY_2		((uint16_t)0x0020)
#define SDRAM_MODE_CAS_LATENCY_3		((uint16_t)0x0030)
#define SDRAM_MODE_OPERATING_MODE_STANDARD	((uint16_t)0x0000)
#define SDRAM_MODE_WRITEBURST_MODE_PROGRAMMED	((uint16_t)0x0000)
#define SDRAM_MODE_WRITEBURST_MODE_SINGLE	((uint16_t)0x0200)

enum fmc_sdram_bank { SDRAM_BANK1, SDRAM_BANK2, SDRAM_BOTH_BANKS };
enum fmc_sdram_command { SDRAM_CLK_CONF, SDRAM_NORMAL, SDRAM_PALL,
			 SDRAM_AUTO_REFRESH, SDRAM_LOAD_MODE,
			 SDRAM_SELF_REFRESH, SDRAM_POWER_DOWN };

/* Send an array of timing parameters (indices above) to create SDTR register
 * value
 */
BEGIN_DECLS

uint32_t sdram_timing(struct sdram_timing *t);
void sdram_command(enum fmc_sdram_bank bank, enum fmc_sdram_command cmd,
			int autorefresh, int modereg);

END_DECLS

#endif
/**@}*/
