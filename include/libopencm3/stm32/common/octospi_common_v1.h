/** @addtogroup octospi_defines
 * @author Chuck McManis <cmcmanis@mcmanis.com> 2016
 * @copyright SPDX: LGPL-3.0-or-later
 * @{
 */

#pragma once

/** @addtogroup octospi_registers QuadSPI Registers
 * @{
 */
/** OCTOSPI Control register */
#define OCTOSPI_CR      MMIO32(OCTOSPI_BASE + 0x0U)

/** OCTOSPI Device Configuration */
#define OCTOSPI_DCR     MMIO32(OCTOSPI_BASE + 0x4U)

/** OCTOSPI Status Register */
#define OCTOSPI_SR      MMIO32(OCTOSPI_BASE + 0x8U)

/** OCTOSPI Flag Clear Register */
#define OCTOSPI_FCR     MMIO32(OCTOSPI_BASE + 0xCU)

/** OCTOSPI Data Length Register */
#define OCTOSPI_DLR     MMIO32(OCTOSPI_BASE + 0x10U)

/** OCTOSPI Communication Configuration Register */
#define OCTOSPI_CCR     MMIO32(OCTOSPI_BASE + 0x14U)

/** OCTOSPI address register */
#define OCTOSPI_AR      MMIO32(OCTOSPI_BASE + 0x18U)

/** OCTOSPI alternate bytes register */
#define OCTOSPI_ABR     MMIO32(OCTOSPI_BASE + 0x1CU)

/** OCTOSPI data register */
#define OCTOSPI_DR      MMIO32(OCTOSPI_BASE + 0x20U)
/** BYTE addressable version for fetching bytes from the interface */
#define OCTOSPI_BYTE_DR     MMIO8(OCTOSPI_BASE + 0x20U)

/** OCTOSPI polling status */
#define OCTOSPI_PSMKR     MMIO32(OCTOSPI_BASE + 0x24U)

/** OCTOSPI polling status match */
#define OCTOSPI_PSMAR     MMIO32(OCTOSPI_BASE + 0x28U)

/** OCTOSPI polling interval register */
#define OCTOSPI_PIR     MMIO32(OCTOSPI_BASE + 0x2CU)

/** OCTOSPI low power timeout */
#define OCTOSPI_LPTR      MMIO32(OCTOSPI_BASE + 0x30U
/**@}*/

#define OCTOSPI_CR_PRESCALE_MASK  0xff
#define OCTOSPI_CR_PRESCALE_SHIFT 24
#define OCTOSPI_CR_PMM      (1 << 23)
#define OCTOSPI_CR_APMS     (1 << 22)
/* bit 21 is reserved */
#define OCTOSPI_CR_TOIE     (1 << 20)
#define OCTOSPI_CR_SMIE     (1 << 19)
#define OCTOSPI_CR_FTIE     (1 << 18)
#define OCTOSPI_CR_TCIE     (1 << 17)
#define OCTOSPI_CR_TEIE     (1 << 16)

/* bits 15:13 reserved */
#define OCTOSPI_CR_FTHRES_MASK    0x1f
#define OCTOSPI_CR_FTHRES_SHIFT   8
#define OCTOSPI_CR_FSEL     (1 << 7)
#define OCTOSPI_CR_DFM      (1 << 6)
/* bit 5 reserved */
#define OCTOSPI_CR_SSHIFT   (1 << 4)
#define OCTOSPI_CR_TCEN     (1 << 3)
/* bit 2 reserved on h7, DMAEN on f4 */
#define OCTOSPI_CR_ABORT    (1 << 1)
#define OCTOSPI_CR_EN     (1 << 0)

/* bits 31:21 reserved */
#define OCTOSPI_DCR_FSIZE_MASK    0x1f
#define OCTOSPI_DCR_FSIZE_SHIFT   16
/* bits 15:11 reserved */
#define OCTOSPI_DCR_CSHT_MASK   0x7
#define OCTOSPI_DCR_CSHT_SHIFT    8
/* bits 7:1 reserved */
#define OCTOSPI_DCR_CKMODE    (1 << 0)

/* bits 31:14 reserved */
#define OCTOSPI_SR_FLEVEL_MASK    0x3f
#define OCTOSPI_SR_FLEVEL_SHIFT   8

/* bits 7:6 reserved */
#define OCTOSPI_SR_BUSY     (1 << 5)
#define OCTOSPI_SR_TOF      (1 << 4)
#define OCTOSPI_SR_SMF      (1 << 3)
#define OCTOSPI_SR_FTF      (1 << 2)
#define OCTOSPI_SR_TCF      (1 << 1)
#define OCTOSPI_SR_TEF      (1 << 0)

/* bits 31:5 reserved */
#define OCTOSPI_FCR_CTOF    (1 << 4)
#define OCTOSPI_FCR_CSMF    (1 << 3)
/* bit 2 reserved */
#define OCTOSPI_FCR_CTCF    (1 << 1)
#define OCTOSPI_FCR_CTEF    (1 << 0)

#define OCTOSPI_CCR_DDRM    (1 << 31)
#define OCTOSPI_CCR_DHHC    (1 << 30)
/* bit 29 reserved on F4, FRCM on H7 */
#define OCTOSPI_CCR_SIOO    (1 << 28)
#define OCTOSPI_CCR_FMODE_MASK    0x3
#define OCTOSPI_CCR_FMODE_SHIFT   26
#define OCTOSPI_CCR_DMODE_MASK    0x3
#define OCTOSPI_CCR_DMODE_SHIFT   24
/* bit 23 reserved */
#define OCTOSPI_CCR_DCYC_MASK   0x1f
#define OCTOSPI_CCR_DCYC_SHIFT    18

#define OCTOSPI_CCR_ABSIZE_MASK   0x3
#define OCTOSPI_CCR_ABSIZE_SHIFT  16

#define OCTOSPI_CCR_ABMODE_MASK   0x3
#define OCTOSPI_CCR_ABMODE_SHIFT  14

#define OCTOSPI_CCR_ADSIZE_MASK   0x3
#define OCTOSPI_CCR_ADSIZE_SHIFT  12

#define OCTOSPI_CCR_ADMODE_MASK   0x3
#define OCTOSPI_CCR_ADMODE_SHIFT  10

#define OCTOSPI_CCR_IMODE_MASK    0x3
#define OCTOSPI_CCR_IMODE_SHIFT   8

#define OCTOSPI_CCR_INST_MASK   0xff
#define OCTOSPI_CCR_INST_SHIFT    0

/* MODE values */
#define OCTOSPI_CCR_MODE_NONE   0
#define OCTOSPI_CCR_MODE_1LINE    1
#define OCTOSPI_CCR_MODE_2LINE    2
#define OCTOSPI_CCR_MODE_4LINE    3

/* FMODE values */
#define OCTOSPI_CCR_FMODE_IWRITE  0
#define OCTOSPI_CCR_FMODE_IREAD   1
#define OCTOSPI_CCR_FMODE_APOLL   2
#define OCTOSPI_CCR_FMODE_MEMMAP  3

/**@}*/


/**
 * @defgroup octospi_file QuadSPI peripheral API
 * @brief APIs for the specialized SPI Flash peripheral
 * @ingroup peripheral_apis
 * @copyright SPDX: LGPL-3.0-or-later
 *
 * The OCTOSPI is a specialized communication interface targeting single,
 * dual, quad or octo SPI Flash memories
 * @{
 */

BEGIN_DECLS

/**
 * Enable the octospi peripheral.
 */
void octospi_enable(void);

/**
 * Disable the octospi peripheral.
 */
void octospi_disable(void);

END_DECLS

/**@}*/
