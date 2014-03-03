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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA USB.H
 * The order of header inclusion is important. usart.h includes the device
 * specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_USB_H
/** @endcond */
#ifndef LIBOPENCM3_USB_COMMON_V1_H
#define LIBOPENCM3_USB_COMMON_V1_H

#include <libopencm3/stm32/common/usb_common_all.h>

/* --- USB BTABLE registers ------------------------------------------------ */

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* USB_BTABLE Values ------------------------------------------------------- */

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
#warning "usb_common_v1.h should not be included directly, only via usb.h"
#endif
/** @endcond */

