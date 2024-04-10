/** @addtogroup quadspi_defines
 * @author Chuck McManis <cmcmanis@mcmanis.com> 2016
 * @copyright SPDX: LGPL-3.0-or-later
 * @{
 */

#pragma once

/** @addtogroup quadspi_registers QuadSPI Registers
 * @{
 */
/** QUADSPI Control register */
#define QUADSPI_CR(quadspi_base)      MMIO32(quadspi_base + 0x0U)
#define QUADSPI1_CR			QUADSPI_CR(QUADSPI1_BASE)
#define QUADSPI2_CR			QUADSPI_CR(QUADSPI2_BASE)

/** QUADSPI Device Configuration */
#define QUADSPI_DCR(quadspi_base)     MMIO32(quadspi_base + 0x4U)
#define QUADSPI1_DCR		QUADSPI_DCR(QUADSPI1_BASE)
#define QUADSPI2_DCR		QUADSPI_DCR(QUADSPI2_BASE)

/** QUADSPI Status Register */
#define QUADSPI_SR(quadspi_base)      MMIO32(quadspi_base + 0x8U)
#define QUADSPI1_SR			QUADSPI_SR(QUADSPI1_BASE)
#define QUADSPI2_SR			QUADSPI_SR(QUADSPI2_BASE)

/** QUADSPI Flag Clear Register */
#define QUADSPI_FCR(quadspi_base)     MMIO32(quadspi_base + 0xCU)
#define QUADSPI1_FCR		QUADSPI_FCR(QUADSPI1_BASE)
#define QUADSPI2_FCR		QUADSPI_FCR(QUADSPI2_BASE)

/** QUADSPI Data Length Register */
#define QUADSPI_DLR(quadspi_base)     MMIO32(quadspi_base + 0x10U)
#define QUADSPI1_DLR		QUADSPI_DLR(QUADSPI1_BASE)
#define QUADSPI2_DLR		QUADSPI_DLR(QUADSPI2_BASE)

/** QUADSPI Communication Configuration Register */
#define QUADSPI_CCR(quadspi_base)     MMIO32(quadspi_base + 0x14U)
#define QUADSPI1_CCR		QUADSPI_CCR(QUADSPI1_BASE)
#define QUADSPI2_CCR		QUADSPI_CCR(QUADSPI2_BASE)

/** QUADSPI address register */
#define QUADSPI_AR(quadspi_base)      MMIO32(quadspi_base + 0x18U)
#define QUADSPI1_AR			QUADSPI_AR(QUADSPI1_BASE)
#define QUADSPI2_AR			QUADSPI_AR(QUADSPI2_BASE)

/** QUADSPI alternate bytes register */
#define QUADSPI_ABR(quadspi_base)     MMIO32(quadspi_base + 0x1CU)
#define QUADSPI1_ABR		QUADSPI_ABR(QUADSPI1_BASE)
#define QUADSPI2_ABR		QUADSPI_ABR(QUADSPI2_BASE)

/** QUADSPI data register */
#define QUADSPI_DR(quadspi_base)      MMIO32(quadspi_base + 0x20U)
#define QUADSPI1_DR			QUADSPI_DR(QUADSPI1_BASE)
#define QUADSPI2_DR			QUADSPI_DR(QUADSPI2_BASE)
/** BYTE addressable version for fetching bytes from the interface */
#define QUADSPI_BYTE_DR(quadspi_base)     MMIO8(quadspi_base + 0x20U)
#define QUADSPI1_BYTE_DR	QUADSPI_BYTE_DR(QUADSPI1_BASE)
#define QUADSPI2_BYTE_DR	QUADSPI_BYTE_DR(QUADSPI2_BASE)

/** QUADSPI polling status */
#define QUADSPI_PSMKR(quadspi_base)     MMIO32(quadspi_base + 0x24U)
#define QUADSPI1_PSMKR		QUADSPI_PSMKR(QUADSPI1_BASE)
#define QUADSPI2_PSMKR		QUADSPI_PSMKR(QUADSPI2_BASE)

/** QUADSPI polling status match */
#define QUADSPI_PSMAR(quadspi_base)     MMIO32(quadspi_base + 0x28U)
#define QUADSPI1_PSMAR		QUADSPI_PSMAR(QUADSPI1_BASE)
#define QUADSPI2_PSMAR		QUADSPI_PSMAR(QUADSPI2_BASE)

/** QUADSPI polling interval register */
#define QUADSPI_PIR(quadspi_base)     MMIO32(quadspi_base + 0x2CU)
#define QUADSPI1_PIR		QUADSPI_PIR(QUADSPI1_BASE)
#define QUADSPI2_PIR		QUADSPI_PIR(QUADSPI2_BASE)

/** QUADSPI low power timeout */
#define QUADSPI_LPTR(quadspi_base)      MMIO32(quadspi_base + 0x30U)
#define QUADSPI1_LPTR		QUADSPI_LPTR(QUADSPI1_BASE)
#define QUADSPI2_LPTR		QUADSPI_LPTR(QUADSPI2_BASE)
/**@}*/

#define QUADSPI_CR_PRESCALE_MASK  0xff
#define QUADSPI_CR_PRESCALE_SHIFT 24
#define QUADSPI_CR_PMM      (1 << 23)
#define QUADSPI_CR_APMS     (1 << 22)
/* bit 21 is reserved */
#define QUADSPI_CR_TOIE     (1 << 20)
#define QUADSPI_CR_SMIE     (1 << 19)
#define QUADSPI_CR_FTIE     (1 << 18)
#define QUADSPI_CR_TCIE     (1 << 17)
#define QUADSPI_CR_TEIE     (1 << 16)

/* bits 15:13 reserved */
#define QUADSPI_CR_FTHRES_MASK    0x1f
#define QUADSPI_CR_FTHRES_SHIFT   8
#define QUADSPI_CR_FSEL     (1 << 7)
#define QUADSPI_CR_DFM      (1 << 6)
/* bit 5 reserved */
#define QUADSPI_CR_SSHIFT   (1 << 4)
#define QUADSPI_CR_TCEN     (1 << 3)
/* bit 2 reserved on h7, DMAEN on f4 */
#define QUADSPI_CR_ABORT    (1 << 1)
#define QUADSPI_CR_EN     (1 << 0)

/* bits 31:21 reserved */
#define QUADSPI_DCR_FSIZE_MASK    0x1f
#define QUADSPI_DCR_FSIZE_SHIFT   16
/* bits 15:11 reserved */
#define QUADSPI_DCR_CSHT_MASK   0x7
#define QUADSPI_DCR_CSHT_SHIFT    8
/* bits 7:1 reserved */
#define QUADSPI_DCR_CKMODE    (1 << 0)

/* bits 31:14 reserved */
#define QUADSPI_SR_FLEVEL_MASK    0x3f
#define QUADSPI_SR_FLEVEL_SHIFT   8

/* bits 7:6 reserved */
#define QUADSPI_SR_BUSY     (1 << 5)
#define QUADSPI_SR_TOF      (1 << 4)
#define QUADSPI_SR_SMF      (1 << 3)
#define QUADSPI_SR_FTF      (1 << 2)
#define QUADSPI_SR_TCF      (1 << 1)
#define QUADSPI_SR_TEF      (1 << 0)

/* bits 31:5 reserved */
#define QUADSPI_FCR_CTOF    (1 << 4)
#define QUADSPI_FCR_CSMF    (1 << 3)
/* bit 2 reserved */
#define QUADSPI_FCR_CTCF    (1 << 1)
#define QUADSPI_FCR_CTEF    (1 << 0)

#define QUADSPI_CCR_DDRM    (1 << 31)
#define QUADSPI_CCR_DHHC    (1 << 30)
/* bit 29 reserved on F4, FRCM on H7 */
#define QUADSPI_CCR_SIOO    (1 << 28)
#define QUADSPI_CCR_FMODE_MASK    0x3
#define QUADSPI_CCR_FMODE_SHIFT   26
#define QUADSPI_CCR_DMODE_MASK    0x3
#define QUADSPI_CCR_DMODE_SHIFT   24
/* bit 23 reserved */
#define QUADSPI_CCR_DCYC_MASK   0x1f
#define QUADSPI_CCR_DCYC_SHIFT    18

#define QUADSPI_CCR_ABSIZE_MASK   0x3
#define QUADSPI_CCR_ABSIZE_SHIFT  16

#define QUADSPI_CCR_ABMODE_MASK   0x3
#define QUADSPI_CCR_ABMODE_SHIFT  14

#define QUADSPI_CCR_ADSIZE_MASK   0x3
#define QUADSPI_CCR_ADSIZE_SHIFT  12

#define QUADSPI_CCR_ADMODE_MASK   0x3
#define QUADSPI_CCR_ADMODE_SHIFT  10

#define QUADSPI_CCR_IMODE_MASK    0x3
#define QUADSPI_CCR_IMODE_SHIFT   8

#define QUADSPI_CCR_INST_MASK   0xff
#define QUADSPI_CCR_INST_SHIFT    0

/* MODE values */
#define QUADSPI_CCR_MODE_NONE   0
#define QUADSPI_CCR_MODE_1LINE    1
#define QUADSPI_CCR_MODE_2LINE    2
#define QUADSPI_CCR_MODE_4LINE    3

/* FMODE values */
#define QUADSPI_CCR_FMODE_IWRITE  0
#define QUADSPI_CCR_FMODE_IREAD   1
#define QUADSPI_CCR_FMODE_APOLL   2
#define QUADSPI_CCR_FMODE_MEMMAP  3

/**@}*/


/**
 * @defgroup quadspi_file QuadSPI peripheral API
 * @brief APIs for the specialized SPI Flash peripheral
 * @ingroup peripheral_apis
 * @copyright SPDX: LGPL-3.0-or-later
 *
 * The QUADSPI is a specialized communication interface targeting single,
 * dual or quad SPI Flash memories
 * @{
 */

BEGIN_DECLS

/**
 * Enable the quadspi peripheral.
 */
void quadspi_enable(uint32_t quadspi);

/**
 * Disable the quadspi peripheral.
 */
void quadspi_disable(uint32_t quadspi);

END_DECLS

/**@}*/
