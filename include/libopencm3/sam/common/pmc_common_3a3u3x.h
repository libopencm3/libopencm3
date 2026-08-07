/**
 * @addtogroup pmc_defines
 * @{
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015 Felix Held <felix-libopencm3@felixheld.de>
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

/** @cond */
#if defined(LIBOPENCM3_PMC_H)
/** @endcond */

#ifndef LIBOPENCM3_PMC_COMMON_3A3U3X_H
#define LIBOPENCM3_PMC_COMMON_3A3U3X_H


/* --- Power Management Controller (PMC) registers ----------------------- */
/**
 * @addtogroup pmc_registers
 * @{
 */

/** UTMI Clock Register */
#define CKGR_UCKR			MMIO32(PMC_BASE + 0x001C)

/** @} */

/* --- Register contents --------------------------------------------------- */

/**
 * @defgroup pmc_ckgr_uckr PMC UTMI Clock Configuration Register (CKGR_UCKR)
 * @{
 */

/**
 * @defgroup pmc_ckgr_uckr_upllcount UTMI PLL Start-up Time
 * @{
 */
#define CKGR_UCKR_UPLLCOUNT_SHIFT	20
#define CKGR_UCKR_UPLLCOUNT_MASK	(0x0F << CKGR_UCKR_UPLLCOUNT_SHIFT)
/** @} */

/** UTMI PLL Enable */
#define CKGR_UCKR_UPLLEN		(0x01 << 16)
/** @} */

/**
 * @addtogroup pmc_mckr
 * @{
 */

/** UPLL Divide by 2 */
#define PMC_MCKR_UPLLDIV2		(0x01 << 13)

/** Master Clock Source Selection */
#define PMC_MCKR_CSS_UPLL_CLK		(3 << PMC_MCKR_CSS_SHIFT)
/** @} */

/**
 * @addtogroup pmc_pck0
 * @{
 */

/** Master Clock Source Selection */
#define PMC_PCK0_CSS_UPLL_CLK		(3 << PMC_PCK0_CSS_SHIFT)
/** @} */

/**
 * @addtogroup pmc_pck1
 * @{ */

/** Master Clock Source Selection */
#define PMC_PCK1_CSS_UPLL_CLK		(3 << PMC_PCK1_CSS_SHIFT)
/** @} */

/**
 * @addtogroup pmc_pck2
 * @{
 */

/** Master Clock Source Selection */
#define PMC_PCK2_CSS_UPLL_CLK		(3 << PMC_PCK2_CSS_SHIFT)
/** @} */

/**
 * @addtogroup pmc_ier
 * @{
 */

/** UTMI PLL Lock Interrupt Enable */
#define PMC_IER_LOCKU			(0x01 << 6)
/** @} */

/**
 * @addtogroup pmc_idr
 * @{
 */

/** UTMI PLL Lock Interrupt Disable */
#define PMC_IDR_LOCKU			(0x01 << 6)
/** @} */

/**
 * @addtogroup pmc_sr
 * @{
 */

/** UTMI PLL Lock Status */
#define PMC_SR_LOCKU			(0x01 << 6)
/** @} */

/**
 * @addtogroup pmc_imr
 * @{
 */

/** UTMI PLL Lock Interrupt Mask */
#define PMC_IMR_LOCKU			(0x01 << 6)
/** @} */

#endif

/** @cond */
#else
#warning "pmc_common_3a3u3x.h should not be included explicitly, only via pmc.h"
#endif
/** @endcond */

/** @} */
