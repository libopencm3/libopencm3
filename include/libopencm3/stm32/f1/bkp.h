/**
 * @defgroup bkp_defines BKP Defines
 * @ingroup STM32F1xx_defines
 * @brief <b>Defined Constants and Types for the Backup Registers</b>
 *
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#ifndef LIBOPENCM3_BKP_H
#define LIBOPENCM3_BKP_H

/** @defgroup BKP_registers BKP Registers
 * @ingroup bkp_defines
@{*/
/* Backup data register 1 (BKP_DR1) */
#define BKP_DR1				MMIO32(BACKUP_REGS_BASE + 0x04)

/* Backup data register 2 (BKP_DR2) */
#define BKP_DR2				MMIO32(BACKUP_REGS_BASE + 0x08)

/* Backup data register 3 (BKP_DR3) */
#define BKP_DR3				MMIO32(BACKUP_REGS_BASE + 0x0C)

/* Backup data register 4 (BKP_DR4) */
#define BKP_DR4				MMIO32(BACKUP_REGS_BASE + 0x10)

/* Backup data register 5 (BKP_DR5) */
#define BKP_DR5				MMIO32(BACKUP_REGS_BASE + 0x14)

/* Backup data register 6 (BKP_DR6) */
#define BKP_DR6				MMIO32(BACKUP_REGS_BASE + 0x18)

/* Backup data register 7 (BKP_DR7) */
#define BKP_DR7				MMIO32(BACKUP_REGS_BASE + 0x1C)

/* Backup data register 8 (BKP_DR8) */
#define BKP_DR8				MMIO32(BACKUP_REGS_BASE + 0x20)

/* Backup data register 9 (BKP_DR9) */
#define BKP_DR9				MMIO32(BACKUP_REGS_BASE + 0x24)

/* Backup data register 10 (BKP_DR10) */
#define BKP_DR10			MMIO32(BACKUP_REGS_BASE + 0x28)

/** RTC clock calibration register (BKP_RTCCR) */
#define BKP_RTCCR			MMIO32(BACKUP_REGS_BASE + 0x2C)

/** Backup control register (BKP_CR) */
#define BKP_CR				MMIO32(BACKUP_REGS_BASE + 0x30)

/** Backup control/status register (BKP_CSR) */
#define BKP_CSR				MMIO32(BACKUP_REGS_BASE + 0x34)

/* Backup data register 11 (BKP_DR11) */
#define BKP_DR11			MMIO32(BACKUP_REGS_BASE + 0x40)

/* Backup data register 12 (BKP_DR12) */
#define BKP_DR12			MMIO32(BACKUP_REGS_BASE + 0x44)

/* Backup data register 13 (BKP_DR13) */
#define BKP_DR13			MMIO32(BACKUP_REGS_BASE + 0x48)

/* Backup data register 14 (BKP_DR14) */
#define BKP_DR14			MMIO32(BACKUP_REGS_BASE + 0x4C)

/* Backup data register 15 (BKP_DR15) */
#define BKP_DR15			MMIO32(BACKUP_REGS_BASE + 0x50)

/* Backup data register 16 (BKP_DR16) */
#define BKP_DR16			MMIO32(BACKUP_REGS_BASE + 0x54)

/* Backup data register 17 (BKP_DR17) */
#define BKP_DR17			MMIO32(BACKUP_REGS_BASE + 0x58)

/* Backup data register 18 (BKP_DR18) */
#define BKP_DR18			MMIO32(BACKUP_REGS_BASE + 0x5C)

/* Backup data register 19 (BKP_DR19) */
#define BKP_DR19			MMIO32(BACKUP_REGS_BASE + 0x60)

/* Backup data register 20 (BKP_DR20) */
#define BKP_DR20			MMIO32(BACKUP_REGS_BASE + 0x64)

/* Backup data register 21 (BKP_DR21) */
#define BKP_DR21			MMIO32(BACKUP_REGS_BASE + 0x68)

/* Backup data register 22 (BKP_DR22) */
#define BKP_DR22			MMIO32(BACKUP_REGS_BASE + 0x6C)

/* Backup data register 23 (BKP_DR23) */
#define BKP_DR23			MMIO32(BACKUP_REGS_BASE + 0x70)

/* Backup data register 24 (BKP_DR24) */
#define BKP_DR24			MMIO32(BACKUP_REGS_BASE + 0x74)

/* Backup data register 25 (BKP_DR25) */
#define BKP_DR25			MMIO32(BACKUP_REGS_BASE + 0x78)

/* Backup data register 26 (BKP_DR26) */
#define BKP_DR26			MMIO32(BACKUP_REGS_BASE + 0x7C)

/* Backup data register 27 (BKP_DR27) */
#define BKP_DR27			MMIO32(BACKUP_REGS_BASE + 0x80)

/* Backup data register 28 (BKP_DR28) */
#define BKP_DR28			MMIO32(BACKUP_REGS_BASE + 0x84)

/* Backup data register 29 (BKP_DR29) */
#define BKP_DR29			MMIO32(BACKUP_REGS_BASE + 0x88)

/* Backup data register 30 (BKP_DR30) */
#define BKP_DR30			MMIO32(BACKUP_REGS_BASE + 0x8C)

/* Backup data register 31 (BKP_DR31) */
#define BKP_DR31			MMIO32(BACKUP_REGS_BASE + 0x90)

/* Backup data register 32 (BKP_DR32) */
#define BKP_DR32			MMIO32(BACKUP_REGS_BASE + 0x94)

/* Backup data register 33 (BKP_DR33) */
#define BKP_DR33			MMIO32(BACKUP_REGS_BASE + 0x98)

/* Backup data register 34 (BKP_DR34) */
#define BKP_DR34			MMIO32(BACKUP_REGS_BASE + 0x9C)

/* Backup data register 35 (BKP_DR35) */
#define BKP_DR35			MMIO32(BACKUP_REGS_BASE + 0xA0)

/* Backup data register 36 (BKP_DR36) */
#define BKP_DR36			MMIO32(BACKUP_REGS_BASE + 0xA4)

/* Backup data register 37 (BKP_DR37) */
#define BKP_DR37			MMIO32(BACKUP_REGS_BASE + 0xA8)

/* Backup data register 38 (BKP_DR38) */
#define BKP_DR38			MMIO32(BACKUP_REGS_BASE + 0xAC)

/* Backup data register 39 (BKP_DR39) */
#define BKP_DR39			MMIO32(BACKUP_REGS_BASE + 0xB0)

/* Backup data register 40 (BKP_DR40) */
#define BKP_DR40			MMIO32(BACKUP_REGS_BASE + 0xB4)

/* Backup data register 41 (BKP_DR41) */
#define BKP_DR41			MMIO32(BACKUP_REGS_BASE + 0xB8)

/* Backup data register 42 (BKP_DR42) */
#define BKP_DR42			MMIO32(BACKUP_REGS_BASE + 0xBC)
/**@}*/

/** @defgroup BKP_RTCCR_Values BKP_RTCCR Values
 * @ingroup bkp_defines
@{*/
/** ASOS: Alarm or second output selection */
#define BKP_RTCCR_ASOS			(1 << 9)

/** ASOE: Alarm or second output enable */
#define BKP_RTCCR_ASOE			(1 << 8)

/** CCO: Calibration clock output */
#define BKP_RTCCR_CCO			(1 << 7)

/** CAL[6:0]: Calibration value */
#define BKP_RTCCR_CAL_LSB		0
/**@}*/

/** @defgroup BKP_CR_Values BKP_CR Values
 * @ingroup bkp_defines
@{*/
/** TPAL: TAMPER pin active level */
#define BKP_CR_TPAL			(1 << 1)

/** TPE: TAMPER pin enable */
#define BKP_CR_TPE			(1 << 0)
/**@}*/

/** @defgroup BKP_CSR_Values BKP_CSR Values
 * @ingroup bkp_defines
@{*/
/** TIF: Tamper interrupt flag */
#define BKP_CSR_TIF			(1 << 9)

/** TEF: Tamper event flag */
#define BKP_CSR_TEF			(1 << 8)

/** TPIE: TAMPER pin interrupt enable */
#define BKP_CSR_TPIE			(1 << 2)

/** CTI: Clear tamper interrupt */
#define BKP_CSR_CTI			(1 << 1)

/** CTE: Clear tamper event */
#define BKP_CSR_CTE			(1 << 0)
/**@}*/

#endif
