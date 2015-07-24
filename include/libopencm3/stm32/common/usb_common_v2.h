/** @addtogroup usb_defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY !
 * Use top-level <libopencm3/stm32/usb.h>
 *
 * Additional definitions for F0 devices :
 * -F0x0 (RM0360),
 * -F04x, F0x2, F0x8 (RM0091)
 */

/** @cond */
#ifdef LIBOPENCM3_USB_H
/** @endcond */
#ifndef LIBOPENCM3_USB_COMMON_V2_H
#define LIBOPENCM3_USB_COMMON_V2_H

#include <libopencm3/stm32/common/usb_common_all.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define USB_LPMCSR_REG		(&MMIO32(USB_DEV_FS_BASE + 0x54))
#define USB_BCDR_REG		(&MMIO32(USB_DEV_FS_BASE + 0x58))

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* USB_CNTR Values ----------------------------------------------------------*/

#define USB_CNTR_L1REQM		(1 << 7)
#define USB_CNTR_L1RESUME	(1 << 5)

/* USB_ISTR Values ----------------------------------------------------------*/

#define USB_ISTR_L1REQ		(1 << 7)

/* USB_LPMCSR Values --------------------------------------------------------*/

#define USB_LPMCSR_BESL_SHIFT	4
#define USB_LPMCSR_BESL		(15 << USB_LPMCSR_BESL_SHIFT)

#define USB_LPMCSR_REMWAKE	(1 << 3)
#define USB_LPMCSR_LPMACK	(1 << 1)
#define USB_LPMCSR_LPMEN	(1 << 0)

/* USB_BCDR Values ----------------------------------------------------------*/

#define USB_BCDR_DPPU		(1 << 15)
#define USB_BCDR_PS2DET		(1 << 7)
#define USB_BCDR_SDET		(1 << 6)
#define USB_BCDR_PDET		(1 << 5)
#define USB_BCDR_DCDET		(1 << 4)
#define USB_BCDR_SDEN		(1 << 3)
#define USB_BCDR_PDEN		(1 << 2)
#define USB_BCDR_DCDEN		(1 << 1)
#define USB_BCDR_BCDEN		(1 << 0)

/* --- USB BTABLE registers ------------------------------------------------ */

#define USB_EP_TX_ADDR(ep) \
	((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 0) * 1))

#define USB_EP_TX_COUNT(ep) \
	((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 2) * 1))

#define USB_EP_RX_ADDR(ep) \
	((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 4) * 1))

#define USB_EP_RX_COUNT(ep) \
	((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 6) * 1))

/* --- USB BTABLE manipulators --------------------------------------------- */

#define USB_GET_EP_TX_BUFF(ep) \
	(USB_PMA_BASE + (uint8_t *)(USB_GET_EP_TX_ADDR(ep) * 1))

#define USB_GET_EP_RX_BUFF(ep) \
	(USB_PMA_BASE + (uint8_t *)(USB_GET_EP_RX_ADDR(ep) * 1))

#endif
/** @cond */
#else
#error "usb_common_v2.h should not be included directly, only via usb.h"
#endif
/** @endcond */

