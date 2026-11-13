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
 * Use top-level <libopencm3/stm32/st_usbfs.h>
 *
 * Additional definitions for F1, F3, L1 devices:
 * -F102, F103 (RM0008)
 * -F302x{B,C}; *NOT* F302x{6,8,D,E} !! (USB_BTABLE access issues) (RM0365)
 * -F303x{B,C}; *NOT* F303x{D,E} !! (USB_BTABLE access issues) (RM0316)
 * -F37x (RM0313)
 * -L1xx (RM0038)
 */

/** @cond */
#ifdef LIBOPENCM3_ST_USBFS_H
/** @endcond */
#ifndef LIBOPENCM3_ST_USBFS_V1_H
#define LIBOPENCM3_ST_USBFS_V1_H

#include <libopencm3/stm32/common/st_usbfs_common.h>

/* --- USB interrupt status register masks / bits -------------------------- */

#define USB_ISTR_RCWBITS	(USB_ISTR_CTR | \
					USB_ISTR_PMAOVR | \
					USB_ISTR_ERR | \
					USB_ISTR_WKUP | \
					USB_ISTR_SUSP | \
					USB_ISTR_RESET | \
					USB_ISTR_SOF | \
					USB_ISTR_ESOF)		/* these bits are all "rc_w0" : writing 1 is safe */

/* --- USB interrupt status register manipulators -------------------------- */

/* Note: CTR and DIR are read only! */
#define USB_CLR_ISTR_PMAOVR()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_PMAOVR))
#define USB_CLR_ISTR_ERR()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_ERR))
#define USB_CLR_ISTR_WKUP()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_WKUP))
#define USB_CLR_ISTR_SUSP()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_SUSP))
#define USB_CLR_ISTR_RESET()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_RESET))
#define USB_CLR_ISTR_SOF()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_SOF))
#define USB_CLR_ISTR_ESOF()	SET_REG(USB_ISTR_REG, USB_ISTR_RCWBITS & (~USB_ISTR_ESOF))

/* --- USB BTABLE Registers ------------------------------------------------ */

#define USB_EP_TX_ADDR(EP) \
	((uint32_t *)(USB_PMA_BASE + (USB_GET_BTABLE + EP * 8 + 0) * 2))

#define USB_EP_TX_COUNT(EP) \
	((uint32_t *)(USB_PMA_BASE + (USB_GET_BTABLE + EP * 8 + 2) * 2))

#define USB_EP_RX_ADDR(EP) \
	((uint32_t *)(USB_PMA_BASE + (USB_GET_BTABLE + EP * 8 + 4) * 2))

#define USB_EP_RX_COUNT(EP) \
	((uint32_t *)(USB_PMA_BASE + (USB_GET_BTABLE + EP * 8 + 6) * 2))

/* --- USB BTABLE manipulators --------------------------------------------- */

#define USB_GET_EP_TX_BUFF(EP) \
	(USB_PMA_BASE + (uint8_t *)(USB_GET_EP_TX_ADDR(EP) * 2))

#define USB_GET_EP_RX_BUFF(EP) \
	(USB_PMA_BASE + (uint8_t *)(USB_GET_EP_RX_ADDR(EP) * 2))

#endif
/** @cond */
#else
#error "st_usbfs_v1.h should not be included directly, only via st_usbfs.h"
#endif
/** @endcond */

