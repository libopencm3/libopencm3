/**
 * @brief Memory Controller definitions for the Qorvo PAC55xx series of microcontrollers
 *
 * @addtogroup PAC55xx_memctl Memory Controller Defines
 * @ingroup PAC55xx_defines
 * @author Kevin Stefanik <kevin@allocor.tech>
 * LGPL License Terms @ref lgpl_license
 * @date 17 Mar 2020
 *
 * Definitions in this file come from the PAC55XX Family User Guide Rev 1.23
 * by Active-Semi dated November 19, 2019.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Kevin Stefanik <kevin@allocor.tech>
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
#ifndef LIBOPENCM3_PAC55XX_MEMCTL_H_
#define LIBOPENCM3_PAC55XX_MEMCTL_H_

#include <libopencm3/cm3/common.h>
#include <libopencm3/pac55xx/memorymap.h>
/**@{*/

/** @defgroup memctl_reg Memory Controller Configuration Register
@{*/
/** Memory Controller Configuration Register */
#define MEMCTL_MEMCTLR          MMIO32(MEMCTL_BASE)
#define MEMCTL_MEMCTLR_WSTATE_MASK              (0xF)
#define MEMCTL_MEMCTLR_WSTATE(ws)               ((ws) & MEMCTL_MEMCTLR_WSTATE_MASK)
#define MEMCTL_MEMCTLR_MCLKDIV_MASK             (0xF)
#define MEMCTL_MEMCTLR_MCLKDIV_SHIFT            4
/* Supported MCLK divisors: 1-16 */
#define MEMCTL_MEMCTLR_MCLKDIV(div)             (((div-1) & MEMCTL_MEMCTLR_MCLKDIV_MASK) << MEMCTL_MEMCTLR_MCLKDIV_SHIFT)
#define MEMCTL_MEMCTLR_WRITEWORDCNT_MASK        (0x3)
#define MEMCTL_MEMCTLR_WRITEWORDCNT_SHIFT       8
#define MEMCTL_MEMCTLR_WRITEWORDCNT(cnt)        (((cnt) & MEMCTL_MEMCTLR_WRITEWORDCNT_MASK) << MEMCTL_MEMCTLR_WRITEWORDCNT_SHIFT)
#define MEMCTL_MEMCTLR_SEIE                     BIT16
#define MEMCTL_MEMCTLR_DEIE                     BIT17
#define MEMCTL_MEMCTLR_INVADDRIE                BIT18
#define MEMCTL_MEMCTLR_STBY                     BIT19
#define MEMCTL_MEMCTLR_ECCDIS                   BIT20
#define MEMCTL_MEMCTLR_CACHEDIS                 BIT21
#define MEMCTL_MEMCTLR_MCLKSEL                  BIT22
/**@}*/

/** @defgroup memstatus_reg Memory Controller Status Register
@{*/
/** Memory Controller Status Register */
#define MEMCTL_MEMSTATUS       MMIO32(MEMCTL_BASE + 0x0004)
#define MEMCTL_MEMSTATUS_WBUSY                 BIT0
#define MEMCTL_MEMSTATUS_EBUSY                 BIT1
#define MEMCTL_MEMSTATUS_WRITEWORDCNT_MASK     (0x3)
#define MEMCTL_MEMSTATUS_WRITEWORDCNT_SHIFT    8
#define MEMCTL_MEMSTATUS_WRITEWORDCNT          ((MEMCTL_MEMSTATUS >> MEMCTL_MEMSTATUS_WRITEWORDCNT_SHIFT) & MEMCTL_MEMSTATUS_WRITEWORDCNT_MASK)
#define MEMCTL_MEMSTATUS_WRITEWORDCNT_4BYTES   (0)
#define MEMCTL_MEMSTATUS_WRITEWORDCNT_8BYTES   (1)
#define MEMCTL_MEMSTATUS_WRITEWORDCNT_12BYTES  (2)
#define MEMCTL_MEMSTATUS_WRITEWORDCNT_16BYTES  (3)
#define MEMCTL_MEMSTATUS_SE                    BIT16
#define MEMCTL_MEMSTATUS_DE                    BIT17
#define MEMCTL_MEMSTATUS_INVADDR               BIT18
/**@}*/

/** @defgroup flashlock_vals Flash Lock/Write Enable Register values
@{*/
/** Flash Lock Access Register */
#define MEMCTL_FLASHLOCK       MMIO32(MEMCTL_BASE + 0x0008)
#define MEMCTL_FLASHLOCK_CLEAR                 (0)
#define MEMCTL_FLASHLOCK_ALLOW_FLASH_WRITE     (0x43DF140A)
#define MEMCTL_FLASHLOCK_ALLOW_MEMCTL_WRITE    (0xD513B490)
#define MEMCTL_FLASHLOCK_ALLOW_INFO2_SWDFUSE   (0x79B4F762)
/**@}*/

/** Flash Page Address Register */
#define MEMCTL_FLASHPAGE       MMIO32(MEMCTL_BASE + 0x000C)
/** SWD Unlock Register */
#define MEMCTL_SWDUNLOCK       MMIO32(MEMCTL_BASE + 0x0010)

/** @defgroup flasherase_vals Flash Erase Enable Register values
@{*/
/** Flash Erase Enable Register */
#define MEMCTL_FLASHERASE      MMIO32(MEMCTL_BASE + 0x0020)
#define MEMCTL_FLASHERASE_PAGE_ERASE           (0x8C799CA7)
#define MEMCTL_FLASHERASE_MASS_PAGE_ERASE      (0x09EE76C9)
#define MEMCTL_FLASHERASE_INFO3_ERASE          (0x1266FF45)
/**@}*/

/**@}*/

BEGIN_DECLS

/**
 * @defgroup memctl_api Memory Controller API
 * @ingroup peripheral_apis
 * @brief <b>PAC5xx MEMCTL Driver</b>
 * @author @htmlonly &copy; @endhtmlonly 2020 Kevin Stefanik <kevin@allocor.tech>
 * @date March 7, 2020
 *
 * This library supports the MEMCTL module in the PAC55xx SoC from Qorvo.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*@{*/

/** Set the number of wait states for Flash reads.
 * @param[in] wstate  Wait states: 0-15
 */
void memctl_flash_set_wstate(uint32_t wstate);
/** Set the MCLK divisor.
 * @param[in] div  HCLK to MCLK divisor: 1-16
 */
void memctl_flash_set_mclkdiv(uint32_t div);
/** Set WRITEWORDCOUNT to 0 to reset the Flash write data buffer */
void memctl_flash_reset_write_buffer(void);
/** Enable Flash Standby Mode */
void memctl_flash_standby_mode_enable(void);
/** Disable Flash Standby Mode */
void memctl_flash_standby_mode_disable(void);
/** Enable Flash cache */
void memctl_flash_cache_enable(void);
/** Disable Flash cache */
void memctl_flash_cache_disable(void);
/** Select ROSCCLK as input to Flash Memory Controller */
void memctl_flash_select_roscclk(void);
/** Select MCLK as input to Flash Memory Controller */
void memctl_flash_select_mclk(void);
/** Enable SRAM ECC */
void memctl_sram_ecc_enable(void);
/** Disable SRAM ECC */
void memctl_sram_ecc_disable(void);
/** Enable SRAM ECC Single Bit Detection Interrupt */
void memctl_sram_ecc_single_bit_interrupt_enable(void);
/** Disable SRAM ECC Single Bit Detection Interrupt */
void memctl_sram_ecc_single_bit_interrupt_disable(void);
/** Enable SRAM ECC Dual Bit Detection Interrupt */
void memctl_sram_ecc_dual_bit_interrupt_enable(void);
/** Disable SRAM ECC Dual Bit Detection Interrupt */
void memctl_sram_ecc_dual_bit_interrupt_disable(void);
/** Enable Invalid Memory Access Interrupt */
void memctl_invaddr_interrupt_enable(void);
/** Disable Invalid Memory Access Interrupt */
void memctl_invaddr_interrupt_disable(void);

/**@}*/

END_DECLS

#endif /* LIBOPENCM3_PAC55XX_MEMCTL_H_ */
