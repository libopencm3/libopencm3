/** @defgroup usb_defines USB Defines

@brief <b>Defined Constants and Types for the STM32F* USB drivers</b>

@ingroup STM32Fx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Piotr Esden-Tempski <piotr@esden.net>

@date 11 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Piotr Esden-Tempski <piotr@esden.net>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY !
 * Use top-level <libopencm3/stm32/st_usbfs.h>
 */

/**@{*/

/** @cond */
#ifdef LIBOPENCM3_ST_USBFS_H
/** @endcond */
#ifndef LIBOPENCM3_ST_USBFS_COMMON_H
#define LIBOPENCM3_ST_USBFS_COMMON_H

#include <libopencm3/stm32/tools.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/* --- USB general registers ----------------------------------------------- */

/* USB Control register */
#define USB_CNTR_REG		(&MMIO32(USB_DEV_FS_BASE + 0x40))
/* USB Interrupt status register */
#define USB_ISTR_REG		(&MMIO32(USB_DEV_FS_BASE + 0x44))
/* USB Frame number register */
#define USB_FNR_REG		(&MMIO32(USB_DEV_FS_BASE + 0x48))
/* USB Device address register */
#define USB_DADDR_REG		(&MMIO32(USB_DEV_FS_BASE + 0x4C))
/* USB Buffer table address register */
#define USB_BTABLE_REG		(&MMIO32(USB_DEV_FS_BASE + 0x50))

/* USB EP register */
#define USB_EP_REG(EP)		(&MMIO32(USB_DEV_FS_BASE) + (EP))


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- USB control register masks / bits ----------------------------------- */

/* Interrupt mask bits, set to 1 to enable interrupt generation */
#define USB_CNTR_CTRM		0x8000
#define USB_CNTR_PMAOVRM	0x4000
#define USB_CNTR_ERRM		0x2000
#define USB_CNTR_WKUPM		0x1000
#define USB_CNTR_SUSPM		0x0800
#define USB_CNTR_RESETM		0x0400
#define USB_CNTR_SOFM		0x0200
#define USB_CNTR_ESOFM		0x0100

/* Request/Force bits */
#define USB_CNTR_RESUME		0x0010 /* Resume request */
#define USB_CNTR_FSUSP		0x0008 /* Force suspend */
#define USB_CNTR_LP_MODE	0x0004 /* Low-power mode */
#define USB_CNTR_PWDN		0x0002 /* Power down */
#define USB_CNTR_FRES		0x0001 /* Force reset */

/* --- USB interrupt status register masks / bits -------------------------- */

#define USB_ISTR_CTR		0x8000 /* Correct Transfer */
#define USB_ISTR_PMAOVR		0x4000 /* Packet Memory Area Over / Underrun */
#define USB_ISTR_ERR		0x2000 /* Error */
#define USB_ISTR_WKUP		0x1000 /* Wake up */
#define USB_ISTR_SUSP		0x0800 /* Suspend mode request */
#define USB_ISTR_RESET		0x0400 /* USB RESET request */
#define USB_ISTR_SOF		0x0200 /* Start Of Frame */
#define USB_ISTR_ESOF		0x0100 /* Expected Start Of Frame */
#define USB_ISTR_DIR		0x0010 /* Direction of transaction */
#define USB_ISTR_EP_ID		0x000F /* Endpoint Identifier */

/* --- USB interrupt status register manipulators -------------------------- */

/* Note: CTR is read only! */
#define USB_CLR_ISTR_PMAOVR()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_PMAOVR)
#define USB_CLR_ISTR_ERR()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_ERR)
#define USB_CLR_ISTR_WKUP()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_WKUP)
#define USB_CLR_ISTR_SUSP()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_SUSP)
#define USB_CLR_ISTR_RESET()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_RESET)
#define USB_CLR_ISTR_SOF()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_SOF)
#define USB_CLR_ISTR_ESOF()	CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_ESOF)

/* --- USB Frame Number Register bits -------------------------------------- */

#define USB_FNR_RXDP		(1 << 15)
#define USB_FNR_RXDM		(1 << 14)
#define USB_FNR_LCK		(1 << 13)

#define USB_FNR_LSOF_SHIFT	11
#define USB_FNR_LSOF		(3 << USB_FNR_LSOF_SHIFT)

#define USB_FNR_FN		(0x7FF << 0)

/* --- USB device address register masks / bits ---------------------------- */

#define USB_DADDR_EF		(1 << 7)
#define USB_DADDR_ADDR		0x007F

/* USB_BTABLE Values ------------------------------------------------------- */

#define USB_BTABLE_BTABLE	0xFFF8

/* --- USB device address register manipulators ---------------------------- */

/* --- USB endpoint register offsets --------------------------------------- */

#define USB_EP0			0
#define USB_EP1			1
#define USB_EP2			2
#define USB_EP3			3
#define USB_EP4			4
#define USB_EP5			5
#define USB_EP6			6
#define USB_EP7			7

/* --- USB endpoint register masks / bits ---------------------------------- */

/* Masks and toggle bits */
#define USB_EP_RX_CTR		0x8000 /* Correct transfer RX */
#define USB_EP_RX_DTOG		0x4000 /* Data toggle RX */
#define USB_EP_RX_STAT		0x3000 /* Endpoint status for RX */

#define USB_EP_SETUP		0x0800 /* Setup transaction completed */
#define USB_EP_TYPE		0x0600 /* Endpoint type */
#define USB_EP_KIND		0x0100 /* Endpoint kind.
				* When set and type=bulk    -> double buffer
				* When set and type=control -> status out
				*/

#define USB_EP_TX_CTR		0x0080 /* Correct transfer TX */
#define USB_EP_TX_DTOG		0x0040 /* Data toggle TX */
#define USB_EP_TX_STAT		0x0030 /* Endpoint status for TX */

#define USB_EP_ADDR		0x000F /* Endpoint Address */

/* Masking all toggle bits */
#define USB_EP_NTOGGLE_MSK	(USB_EP_RX_CTR | \
				 USB_EP_SETUP | \
				 USB_EP_TYPE | \
				 USB_EP_KIND | \
				 USB_EP_TX_CTR | \
				 USB_EP_ADDR)

/* All non toggle bits plus EP_RX toggle bits */
#define USB_EP_RX_STAT_TOG_MSK	(USB_EP_RX_STAT | USB_EP_NTOGGLE_MSK)
/* All non toggle bits plus EP_TX toggle bits */
#define USB_EP_TX_STAT_TOG_MSK	(USB_EP_TX_STAT | USB_EP_NTOGGLE_MSK)

/* Endpoint status bits for USB_EP_RX_STAT bit field */
#define USB_EP_RX_STAT_DISABLED	0x0000
#define USB_EP_RX_STAT_STALL	0x1000
#define USB_EP_RX_STAT_NAK	0x2000
#define USB_EP_RX_STAT_VALID	0x3000

/* Endpoint status bits for USB_EP_TX_STAT bit field */
#define USB_EP_TX_STAT_DISABLED	0x0000
#define USB_EP_TX_STAT_STALL	0x0010
#define USB_EP_TX_STAT_NAK	0x0020
#define USB_EP_TX_STAT_VALID	0x0030

/* Endpoint type bits for USB_EP_TYPE bit field */
#define USB_EP_TYPE_BULK	0x0000
#define USB_EP_TYPE_CONTROL	0x0200
#define USB_EP_TYPE_ISO		0x0400
#define USB_EP_TYPE_INTERRUPT	0x0600

/* --- USB endpoint register manipulators ---------------------------------- */

/*
 * Set USB endpoint tx/rx status.
 *
 * USB status field is changed using an awkward toggle mechanism, that
 * is why we use some helper macros for that.
 */
#define USB_SET_EP_RX_STAT(EP, STAT) \
	TOG_SET_REG_BIT_MSK_AND_SET(USB_EP_REG(EP), \
		USB_EP_RX_STAT_TOG_MSK, STAT, USB_EP_RX_CTR | USB_EP_TX_CTR)

#define USB_SET_EP_TX_STAT(EP, STAT) \
	TOG_SET_REG_BIT_MSK_AND_SET(USB_EP_REG(EP), \
		USB_EP_TX_STAT_TOG_MSK, STAT, USB_EP_RX_CTR | USB_EP_TX_CTR)

/*
 * Macros for clearing and setting USB endpoint register bits that do
 * not use the toggle mechanism.
 *
 * Because the register contains some bits that use the toggle
 * mechanism we need a helper macro here. Otherwise the code gets really messy.
 */
#define USB_CLR_EP_NTOGGLE_BIT_AND_SET(EP, BIT, EXTRA_BITS) \
	CLR_REG_BIT_MSK_AND_SET(USB_EP_REG(EP), \
		USB_EP_NTOGGLE_MSK, BIT, EXTRA_BITS)

#define USB_CLR_EP_RX_CTR(EP) \
	USB_CLR_EP_NTOGGLE_BIT_AND_SET(EP, USB_EP_RX_CTR, USB_EP_TX_CTR)

#define USB_CLR_EP_TX_CTR(EP) \
	USB_CLR_EP_NTOGGLE_BIT_AND_SET(EP, USB_EP_TX_CTR, USB_EP_RX_CTR)


#define USB_SET_EP_TYPE(EP, TYPE) \
	SET_REG(USB_EP_REG(EP), \
		(GET_REG(USB_EP_REG(EP)) & \
		(USB_EP_NTOGGLE_MSK & \
		(~USB_EP_TYPE))) | TYPE)

#define USB_SET_EP_KIND(EP) \
	SET_REG(USB_EP_REG(EP), \
		(GET_REG(USB_EP_REG(EP)) & \
		(USB_EP_NTOGGLE_MSK & \
		(~USB_EP_KIND))) | USB_EP_KIND)

#define USB_CLR_EP_KIND(EP) \
	SET_REG(USB_EP_REG(EP), \
		(GET_REG(USB_EP_REG(EP)) & \
		(USB_EP_NTOGGLE_MSK & (~USB_EP_KIND))))

#define USB_SET_EP_STAT_OUT(EP)	USB_SET_EP_KIND(EP)
#define USB_CLR_EP_STAT_OUT(EP)	USB_CLR_EP_KIND(EP)

#define USB_SET_EP_ADDR(EP, ADDR) \
	SET_REG(USB_EP_REG(EP), \
		((GET_REG(USB_EP_REG(EP)) & \
		(USB_EP_NTOGGLE_MSK & \
		(~USB_EP_ADDR))) | ADDR))

/* Macros for clearing DTOG bits */
#define USB_CLR_EP_TX_DTOG(EP) \
	SET_REG(USB_EP_REG(EP), \
		GET_REG(USB_EP_REG(EP)) & \
		(USB_EP_NTOGGLE_MSK | USB_EP_TX_DTOG))

#define USB_CLR_EP_RX_DTOG(EP) \
	SET_REG(USB_EP_REG(EP), \
		GET_REG(USB_EP_REG(EP)) & \
		(USB_EP_NTOGGLE_MSK | USB_EP_RX_DTOG))


/* --- USB BTABLE registers ------------------------------------------------ */

#define USB_GET_BTABLE		GET_REG(USB_BTABLE_REG)

/* --- USB BTABLE manipulators --------------------------------------------- */

#define USB_GET_EP_TX_ADDR(EP)		GET_REG(USB_EP_TX_ADDR(EP))
#define USB_GET_EP_TX_COUNT(EP)		GET_REG(USB_EP_TX_COUNT(EP))
#define USB_GET_EP_RX_ADDR(EP)		GET_REG(USB_EP_RX_ADDR(EP))
#define USB_GET_EP_RX_COUNT(EP)		GET_REG(USB_EP_RX_COUNT(EP))
#define USB_SET_EP_TX_ADDR(EP, ADDR)	SET_REG(USB_EP_TX_ADDR(EP), ADDR)
#define USB_SET_EP_TX_COUNT(EP, COUNT)	SET_REG(USB_EP_TX_COUNT(EP), COUNT)
#define USB_SET_EP_RX_ADDR(EP, ADDR)	SET_REG(USB_EP_RX_ADDR(EP), ADDR)
#define USB_SET_EP_RX_COUNT(EP, COUNT)	SET_REG(USB_EP_RX_COUNT(EP), COUNT)



/**@}*/

#endif
/** @cond */
#else
#error "st_usbfs_common.h should not be included explicitly, only via st_usbfs.h"
#endif
/** @endcond */

