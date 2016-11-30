/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <string.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/tools.h>
#include <libopencm3/stm32/otg_hs.h>
#include <libopencm3/stm32/otg_fs.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"
#include "usb_fx07_common.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 512

static struct _usbd_device usbd_hs_dev;
static struct _usbd_device usbd_fs_dev;

static usbd_device *stm32f207_fs_usbd_init(void);
static usbd_device *stm32f207_hs_usbd_init(void);

const struct _usbd_driver stm32f207_usbd_hs_driver = {
    .init = stm32f207_hs_usbd_init,
	.set_address = stm32fx07_set_address,
	.ep_setup = stm32fx07_ep_setup,
	.ep_reset = stm32fx07_endpoints_reset,
	.ep_stall_set = stm32fx07_ep_stall_set,
	.ep_stall_get = stm32fx07_ep_stall_get,
	.ep_nak_set = stm32fx07_ep_nak_set,
	.ep_write_packet = stm32fx07_ep_write_packet,
	.ep_read_packet = stm32fx07_ep_read_packet,
	.poll = stm32fx07_poll,
	.disconnect = stm32fx07_disconnect,
	.base_address = USB_OTG_HS_BASE,
	.set_address_before_status = 1,
	.rx_fifo_size = RX_FIFO_SIZE,
};

const struct _usbd_driver stm32f207_usbd_fs_driver = {
    .init = stm32f207_fs_usbd_init,
    .set_address = stm32fx07_set_address,
    .ep_setup = stm32fx07_ep_setup,
    .ep_reset = stm32fx07_endpoints_reset,
    .ep_stall_set = stm32fx07_ep_stall_set,
    .ep_stall_get = stm32fx07_ep_stall_get,
    .ep_nak_set = stm32fx07_ep_nak_set,
    .ep_write_packet = stm32fx07_ep_write_packet,
    .ep_read_packet = stm32fx07_ep_read_packet,
    .poll = stm32fx07_poll,
    .disconnect = stm32fx07_disconnect,
    .base_address = USB_OTG_FS_BASE,
    .set_address_before_status = 1,
    .rx_fifo_size = RX_FIFO_SIZE,
};

/** Initialize the USB device controller hardware of the STM32. */
usbd_device *stm32f207_usbd_init_dev(usbd_device* dev)
{
    const usbd_driver *driver = dev->driver;
    uint32_t base = driver->base_address;

    OTGx_GLOBAL(base).GINTSTS = OTG_GINTSTS_MMIS;
    OTGx_GLOBAL(base).GUSBCFG   |= OTG_GUSBCFG_PHYSEL;
    /* Enable VBUS sensing in device mode and power down the PHY. */
    OTGx_GLOBAL(base).GCCFG     |= OTG_GCCFG_VBUSBSEN | OTG_GCCFG_PWRDWN;

    /* Wait for AHB idle. */
    while ((OTGx_GLOBAL(base).GRSTCTL & OTG_GRSTCTL_AHBIDL) == 0);
    /* Do core soft reset. */
    OTGx_GLOBAL(base).GRSTCTL |= OTG_GRSTCTL_CSRST;
    while ((OTGx_GLOBAL(base).GRSTCTL & OTG_GRSTCTL_CSRST) != 0);

    /* Force peripheral only mode. */
    OTGx_GLOBAL(base).GUSBCFG |= OTG_GUSBCFG_FDMOD | OTG_GUSBCFG_TRDT_MASK;

    /* Full speed device. */
    OTGx_DEVICE(base).DCFG |= OTG_DCFG_DSPD;

    /* Restart the PHY clock. */
    OTGx_PCGCCTL(base) = 0;

    OTGx_GLOBAL(base).GRXFSIZ   = driver->rx_fifo_size;
    dev->fifo_mem_top           = driver->rx_fifo_size;

    /* Unmask interrupts for TX and RX. */
    OTGx_GLOBAL(base).GAHBCFG |= OTG_GAHBCFG_GINT;
    OTGx_GLOBAL(base).GINTMSK = OTG_GINTMSK_ENUMDNEM |
             OTG_GINTMSK_RXFLVLM |
             OTG_GINTMSK_IEPINT |
             OTG_GINTMSK_USBSUSPM |
             OTG_GINTMSK_WUIM;
    OTGx_DEVICE(base).DAINTMSK = 0xF;
    OTGx_DEVICE(base).DIEPMSK = OTG_DIEPMSK_XFRCM;

    return dev;
}

static 
usbd_device *stm32f207_fs_usbd_init(void)
{
    usbd_fs_dev.driver = &stm32f207_usbd_fs_driver;
    return stm32f207_usbd_init_dev(&usbd_fs_dev);
}

static 
usbd_device *stm32f207_hs_usbd_init(void)
{
    usbd_hs_dev.driver = &stm32f207_usbd_hs_driver;
    return stm32f207_usbd_init_dev(&usbd_hs_dev);
}
