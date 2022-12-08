/** @addtogroup crs_defines
 *
 * @date 7 Dec 2022
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_CRS_H
#define LIBOPENCM3_CRS_H
/**@{*/

/* --- CRS registers ------------------------------------------------------- */
#define CRS_SR			MMIO32(CRS_BASE + 0x00)		/* ACC_STS */
#define CRS_CR1			MMIO32(CRS_BASE + 0x04)		/* ACC_CTRL1 */
#define CRS_CR2			MMIO32(CRS_BASE + 0x08)		/* ACC_CTRL2 */
#define CRS_CFGR1		MMIO16(CRS_BASE + 0x0c)		/* ACC_C1 */
#define CRS_CFGR2		MMIO16(CRS_BASE + 0x10)		/* ACC_C2 */
#define CRS_CFGR3		MMIO16(CRS_BASE + 0x14)		/* ACC_C3 */

/* --- CRS_SR (ACC_STS) values --------------------------------------------- */
#define CRS_SR_RSLOST		(1 << 1)			/* RSLOST */
#define CRS_SR_CALRDY		(1 << 0)			/* CALRDY */

/* --- CRS_CR1 (ACC_CTRL1) values ------------------------------------------ */
/* STEP [11:8] */
#define CRS_CR1_CALRDYIEN	(1 << 5)			/* CALRDYIEN */
#define CRS_CR1_EIEN		(1 << 4)			/* EIEN */
#define CRS_CR1_ENTRIM		(1 << 1)			/* ENTRIM */
#define CRS_CR1_CALON		(1 << 0)			/* CALON */

#define CRS_CR1_STEP_SHIFT	8
#define CRS_CR1_STEP_MASK	0xf

/* --- CRS_CR2 (ACC_CTRL2) values ------------------------------------------ */
/* HSITRIM (HICKTRIM) [13:8] */
/* HSICAL  (HICKCAL)  [7:0]  */
#define CRS_CR2_HSITRIM_SHIFT	8
#define CRS_CR2_HSITRIM_MASK	0x3f
#define CRS_CR2_HSICAL_SHIFT	0
#define CRS_CR2_HSICAL_MASK	0xf

/* --- CRS_CFGRx (ACC_Cx) default values ----------------------------------- */
#define CRS_CFGR_LOW		0x1f2c
#define CRS_CFGR_CENTER		0x1f40
#define CRS_CFGR_HIGH		0x1f54

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void crs_enable_calrdy_interrupt(void);
void crs_disable_calrdy_interrupt(void);
void crs_enable_reflost_interrupt(void);
void crs_disable_reflost_interrupt(void);
void crs_autotrim_usb_enable(void);

END_DECLS
/**@}*/

#endif
