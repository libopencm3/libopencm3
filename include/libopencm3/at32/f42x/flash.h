/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup AT32F42x_defines
 *
 * @brief Defined Constants and Types for the AT32F42x FLASH Memory
 *
 * @version 1.0.0
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

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

/**@{*/

#include <libopencm3/stm32/common/flash_common_all.h>
#include <libopencm3/at32/common/flash_common_at32.h>

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- FLASH_ACR (FLASH_PSR) values ---------------------------------------- */

#define FLASH_ACR_LAT_DIS		(1 << 8)	/* PFT_LAT_DIS */
#define FLASH_ACR_PRFTB2S		(1 << 7)	/* PFT_ENF2 */
#define FLASH_ACR_PRFTB2E		(1 << 6)	/* PFT_EN2 */
#define FLASH_ACR_PRFTBS		(1 << 5)	/* PFT_ENF */
#define FLASH_ACR_PRFTBE		(1 << 4)	/* PFT_EN */
#define FLASH_ACR_HLFCYA		(1 << 3)	/* HFCYC_EN */
/* LATENCY (WTCYC) [2:0] */
#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY_MASK		7

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY_000_032MHZ	0
#define FLASH_ACR_LATENCY_032_064MHZ	1
#define FLASH_ACR_LATENCY_064_096MHZ	2
#define FLASH_ACR_LATENCY_096_120MHZ	3
#define FLASH_ACR_LATENCY_0WS		0
#define FLASH_ACR_LATENCY_1WS		1
#define FLASH_ACR_LATENCY_2WS		2
#define FLASH_ACR_LATENCY_3WS		3
/**@}*/

#define FLASH_ACR_PRFTEN		FLASH_ACR_PRFTBE

/* --- FLASH_CR (FLASH_CTRL) values ---------------------------------------- */
/* TODO */

/* --- FLASH_OBR values ---------------------------------------------------- */
/* TODO */

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_halfcycle_enable(void);
void flash_halfcycle_disable(void);
void flash_unlock_upper(void);
void flash_lock_upper(void);
void flash_clear_pgerr_flag_upper(void);
void flash_clear_eop_flag_upper(void);
void flash_clear_wrprterr_flag_upper(void);

END_DECLS

/**@}*/

#endif
