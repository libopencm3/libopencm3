/** @defgroup VF6xx_iomuxc_defines IO MUX Controller Defines
 *
 * @brief <b>Defined Constants and Types for the VF6xx IO MUX Controller</b>
 *
 * @ingroup VF6xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Stefan Agner <stefan@agner.ch>
 *
 * @date 03 July 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#ifndef LIBOPENCM3_VF6XX_IOMUXC_H
#define LIBOPENCM3_VF6XX_IOMUXC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/vf6xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup iomuxc_reg IO MUX Controller register
@ingroup VF6xx_iomuxc_defines

@{*/
#define IOMUXC(pad)			MMIO32(IOMUXC_BASE + (0x4 * pad))

#define IOMUXC_PAD(mode, speed, dse, pus, flags) \
	(IOMUXC_##mode) << IOMUXC_MUX_MODE_SHIFT | \
	(IOMUXC_##speed) << IOMUXC_SPEED_SHIFT | \
	(IOMUXC_##dse) << IOMUXC_DSE_SHIFT | \
	(IOMUXC_##pus) << IOMUXC_PUS_SHIFT | \
	(flags)


/* --- GPIO registers ------------------------------------------------------ */

#define IOMUXC_MUX_MODE_SHIFT		20
#define IOMUXC_MUX_MODE_MASK		(0x7 << 20)
#define IOMUXC_MUX_MODE_ALT0		0x0
#define IOMUXC_MUX_MODE_ALT1		0x1
#define IOMUXC_MUX_MODE_ALT2		0x2
#define IOMUXC_MUX_MODE_ALT3		0x3
#define IOMUXC_MUX_MODE_ALT4		0x4
#define IOMUXC_MUX_MODE_ALT5		0x5
#define IOMUXC_MUX_MODE_ALT6		0x6
#define IOMUXC_MUX_MODE_ALT7		0x7
#define IOMUXC_SPEED_SHIFT		12
#define IOMUXC_SPEED_MASK		(0x3 << 12)
#define IOMUXC_SPEED_LOW		0x0
#define IOMUXC_SPEED_MEDIUM		0x1
#define IOMUXC_SPEED_HIGH		0x3
#define IOMUXC_SRE			(0x1 << 11)
#define IOMUXC_ODE			(0x1 << 10)
#define IOMUXC_HYS			(0x1 << 9)
#define IOMUXC_DSE_SHIFT		6
#define IOMUXC_DSE_MASK			(0x7 << 6)
#define IOMUXC_DSE_OFF			0x0
#define IOMUXC_DSE_150OHM		0x1
#define IOMUXC_DSE_75OHM		0x2
#define IOMUXC_DSE_50OHM		0x3
#define IOMUXC_DSE_37OHM		0x4
#define IOMUXC_DSE_30OHM		0x5
#define IOMUXC_DSE_25OHM		0x6
#define IOMUXC_DSE_20OHM		0x7
#define IOMUXC_PUS_SHIFT		4
#define IOMUXC_PUS_MASK			(0x3 << 4)
#define IOMUXC_PUS_PD_100KOHM		0x0
#define IOMUXC_PUS_PU_47KOHM		0x1
#define IOMUXC_PUS_PU_100KOHM		0x2
#define IOMUXC_PUS_PU_22KOHM		0x3
#define IOMUXC_PKE			(0x1 << 3)
#define IOMUXC_PUE			(0x1 << 2)
#define IOMUXC_OBE			(0x1 << 1)
#define IOMUXC_IBE			(0x1 << 0)


/* --- Type definitions ---------------------------------------------------- */
/*---------------------------------------------------------------------------*/
/** @brief IO-MUX Pads

Pads available by the IO-MUX controller
*/

enum vf6xx_pad {
	PTA6,
	PTA8,
	PTA9,
	PTA10,
	PTA11,
	PTA12,
	PTA16,
	PTA17,
	PTA18,
	PTA19,
	PTA20,
	PTA21,
	PTA22,
	PTA23,
	PTA24,
	PTA25,
	PTA26,
	PTA27,
	PTA28,
	PTA29,
	PTA30,
	PTA31,
	PTB0,
	PTB1,
	PTB2,
	PTB3,
	PTB4,
	PTB5,
	PTB6,
	PTB7,
	PTB8,
	PTB9,
	PTB10,
	PTB11,
	PTB12,
	PTB13,
	PTB14,
	PTB15,
	PTB16,
	PTB17,
	PTB18,
	PTB19,
	PTB20,
	PTB21,
	PTB22,
	PTC0,
	PTC1,
	PTC2,
	PTC3,
	PTC4,
	PTC5,
	PTC6,
	PTC7,
	PTC8,
	PTC9,
	PTC10,
	PTC11,
	PTC12,
	PTC13,
	PTC14,
	PTC15,
	PTC16,
	PTC17,
	PTD31,
	PTD30,
	PTD29,
	PTD28,
	PTD27,
	PTD26,
	PTD25,
	PTD24,
	PTD23,
	PTD22,
	PTD21,
	PTD20,
	PTD19,
	PTD18,
	PTD17,
	PTD16,
	PTD0,
	PTD1,
	PTD2,
	PTD3,
	PTD4,
	PTD5,
	PTD6,
	PTD7,
	PTD8,
	PTD9,
	PTD10,
	PTD11,
	PTD12,
	PTD13,
	PTB23,
	PTB24,
	PTB25,
	PTB26,
	PTB27,
	PTB28,
	PTC26,
	PTC27,
	PTC28,
	PTC29,
	PTC30,
	PTC31,
	PTE0,
	PTE1,
	PTE2,
	PTE3,
	PTE4,
	PTE5,
	PTE6,
	PTE7,
	PTE8,
	PTE9,
	PTE10,
	PTE11,
	PTE12,
	PTE13,
	PTE14,
	PTE15,
	PTE16,
	PTE17,
	PTE18,
	PTE19,
	PTE20,
	PTE21,
	PTE22,
	PTE23,
	PTE24,
	PTE25,
	PTE26,
	PTE27,
	PTE28,
	PTA7,
};


/* --- Function prototypes ------------------------------------------------- */

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

void iomuxc_mux(enum vf6xx_pad pad, uint32_t muxc);

END_DECLS

#endif
