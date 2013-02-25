/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
 *							 2012 Sergey Krukowski <softsr@yahoo.de>
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
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/f4/flash.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/dfu.h>

#define USE_LED

#ifdef USE_LED
#define RED		 GPIO13
#define GREEN	 GPIO14
#define YELLOW GPIO15

#define LED_ON(_led) 				gpio_clear(GPIOA, _led);
#define LED_OFF(_led) 			gpio_set(GPIOA, _led);
#define LED_TOGGLE(_led) 		gpio_toggle(GPIOA, _led);
#endif

#define APP_ADDRESS	0x08004000
#define SECTOR_SIZE	2048

/* Commands sent with wBlockNum == 0 as per ST implementation. */
#define CMD_SETADDR	0x21
#define CMD_ERASE	0x41

#define USER_AP_WP 0x20000

/* We need a special large control buffer for this device: */
u8 usbd_control_buffer[SECTOR_SIZE];

u32 sector_addr[12] = {0x08000000, 0x08004000, 0x08008000, 0x0800C000, 
											 0x08010000, 0x08020000, 0x08040000, 
											 0x08060000, 0x08080000, 0x080A0000, 
											 0x080C0000, 0x080E0000};
u16 sector_erase_time[12]= {500, 1000, 500, 500, 
											 1000, 1500, 1500, 
											 1500, 1500, 1500, 
											 1500, 1500};
u8 sector_num = 1;

static enum dfu_state usbdfu_state = STATE_DFU_IDLE;

static struct {
	u8 buf[sizeof(usbd_control_buffer)];
	u16 len;
	u32 addr;
	u16 blocknum;
} prog;

const struct usb_device_descriptor dev = {
	.bLength = USB_DT_DEVICE_SIZE,
	.bDescriptorType = USB_DT_DEVICE,
	.bcdUSB = 0x0200,
	.bDeviceClass = 0,
	.bDeviceSubClass = 0,
	.bDeviceProtocol = 0,
	.bMaxPacketSize0 = 64,
	.idVendor = 0x0483,
	.idProduct = 0xDF11,
	.bcdDevice = 0x0200,
	.iManufacturer = 1,
	.iProduct = 2,
	.iSerialNumber = 3,
	.bNumConfigurations = 1,
};

const struct usb_dfu_descriptor dfu_function = {
	.bLength = sizeof(struct usb_dfu_descriptor),
	.bDescriptorType = DFU_FUNCTIONAL,
	.bmAttributes = USB_DFU_CAN_DOWNLOAD | USB_DFU_WILL_DETACH,
	.wDetachTimeout = 255,
	.wTransferSize = SECTOR_SIZE,
	.bcdDFUVersion = 0x011A,
};

const struct usb_interface_descriptor iface = {
	.bLength = USB_DT_INTERFACE_SIZE,
	.bDescriptorType = USB_DT_INTERFACE,
	.bInterfaceNumber = 0,
	.bAlternateSetting = 0,
	.bNumEndpoints = 0,
	.bInterfaceClass = 0xFE, /* Device Firmware Upgrade */
	.bInterfaceSubClass = 1,
	.bInterfaceProtocol = 2,

	/* The ST Microelectronics DfuSe application needs this string.
	 * The format isn't documented... */
	.iInterface = 4,

	.extra = &dfu_function,
	.extralen = sizeof(dfu_function),
};

const struct usb_interface ifaces[] = {{
	.num_altsetting = 1,
	.altsetting = &iface,
}};

const struct usb_config_descriptor config = {
	.bLength = USB_DT_CONFIGURATION_SIZE,
	.bDescriptorType = USB_DT_CONFIGURATION,
	.wTotalLength = 0,
	.bNumInterfaces = 1,
	.bConfigurationValue = 1,
	.iConfiguration = 0,
	.bmAttributes = 0xC0,
	.bMaxPower = 0x32,

	.interface = ifaces,
};

static const char *usb_strings[] = {
	"Black Sphere Technologies",
	"DFU Demo",
	"DEMO",
	/* This string is used by ST Microelectronics' DfuSe utility. */
	"@Internal Flash   /0x08000000/8*001Ka,56*001Kg",
};

static u8 usbdfu_getstatus(usbd_device *usbd_dev, u32 *bwPollTimeout)
{
	(void)usbd_dev;
	
	switch (usbdfu_state) {
	case STATE_DFU_DNLOAD_SYNC:
		usbdfu_state = STATE_DFU_DNBUSY;
		*bwPollTimeout = 70;
		
		if (prog.blocknum == 0 && prog.buf[0] == CMD_ERASE)
			if(*(u32 *)(prog.buf + 1) == sector_addr[sector_num])
				*bwPollTimeout = sector_erase_time[sector_num];
		
		return DFU_STATUS_OK;
	case STATE_DFU_MANIFEST_SYNC:
		/* Device will reset when read is complete. */
		usbdfu_state = STATE_DFU_MANIFEST;
		return DFU_STATUS_OK;
	default:
		return DFU_STATUS_OK;
	}
}

static void usbdfu_getstatus_complete(usbd_device *usbd_dev, struct usb_setup_data *req)
{
	int i;
	u32 addr;
	(void)req;
	(void)usbd_dev;
	
	switch (usbdfu_state) {
	case STATE_DFU_DNBUSY:
		flash_unlock();
		if (prog.blocknum == 0) {
			switch (prog.buf[0]) {
			case CMD_ERASE:
				addr = *(u32 *)(prog.buf + 1);
				/* Unprotect user application area */
				if(addr == APP_ADDRESS) {
					#ifdef USE_LED
						LED_ON(GREEN)
					#endif
						flash_program_option_bytes(FLASH_OPTCR | USER_AP_WP);
					#ifdef USE_LED
						LED_OFF(GREEN)
					#endif
				}
				if(addr == sector_addr[sector_num] && (addr >= APP_ADDRESS)) {
			#ifdef USE_LED
					LED_ON(YELLOW)
			#endif
					flash_erase_sector((sector_num&0x0F) << 3, 2<<8);
			#ifdef USE_LED
					LED_OFF(YELLOW)
			#endif
					sector_num++;
				}
			case CMD_SETADDR:
				prog.addr = *(u32 *)(prog.buf + 1);
			}
		} else {
		
			u32 baseaddr = prog.addr + ((prog.blocknum - 2) *
				       dfu_function.wTransferSize);
			if(baseaddr >= APP_ADDRESS) {
			#ifdef USE_LED	
				LED_ON(GREEN)
			#endif
				
				for (i = 0; i < prog.len; i += 4)
					flash_program_word(baseaddr + i,
						*(u32 *)(prog.buf + i), 2<<8);
				
			#ifdef USE_LED	
				LED_OFF(GREEN)
			#endif
			}
		}
		flash_lock();
		
		/* Jump straight to dfuDNLOAD-IDLE, skipping dfuDNLOAD-SYNC. */
		usbdfu_state = STATE_DFU_DNLOAD_IDLE;
		return;
	case STATE_DFU_MANIFEST:
		/* USB device must detach, we just reset... */
		scb_reset_system();
		return; /* Will never return. */
	default:
		return;
	}
}

static int usbdfu_control_request(usbd_device *usbd_dev, struct usb_setup_data *req, u8 **buf,
		u16 *len, void (**complete)(usbd_device *usbd_dev, struct usb_setup_data *req))
{
	if ((req->bmRequestType & 0x7F) != 0x21)
		return 0; /* Only accept class request. */
	switch (req->bRequest) {
	case DFU_DNLOAD:
		if ((len == NULL) || (*len == 0)) {
			usbdfu_state = STATE_DFU_MANIFEST_SYNC;
			return 1;
		} else {
			/* Copy download data for use on GET_STATUS. */
			prog.blocknum = req->wValue;
			prog.len = *len;	
			memcpy(prog.buf, *buf, *len);
			usbdfu_state = STATE_DFU_DNLOAD_SYNC;
			return 1;
		}
	case DFU_CLRSTATUS:
		/* Clear error and return to dfuIDLE. */
		if (usbdfu_state == STATE_DFU_ERROR)
			usbdfu_state = STATE_DFU_IDLE;
		return 1;
	case DFU_ABORT:
		/* Abort returns to dfuIDLE state. */
		usbdfu_state = STATE_DFU_IDLE;
		return 1;
	case DFU_UPLOAD:
		/* Upload not supported for now. */
		return 0;
	case DFU_GETSTATUS:
		{
		u32 bwPollTimeout = 0; /* 24-bit integer in DFU class spec */
		(*buf)[0] = usbdfu_getstatus(usbd_dev, &bwPollTimeout);
		(*buf)[1] = bwPollTimeout & 0xFF;
		(*buf)[2] = (bwPollTimeout >> 8) & 0xFF;
		(*buf)[3] = (bwPollTimeout >> 16) & 0xFF;
		(*buf)[4] = usbdfu_state;
		(*buf)[5] = 0; /* iString not used here */
		*len = 6;
		*complete = usbdfu_getstatus_complete;
		return 1;
		}
	case DFU_GETSTATE:
		/* Return state with no state transision. */
		*buf[0] = usbdfu_state;
		*len = 1;
		return 1;
	}

	return 0;
}

bool gpio_force_bootloader()
{
		/* Enable clock for the "force bootloader" pin bank and check for it */
		rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);
		gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, GPIO9);
		gpio_clear(GPIOA, GPIO9);
    
		if(gpio_get(GPIOA, GPIO9)) {
			rcc_peripheral_disable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);
			return true;
		}
	rcc_peripheral_disable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);
	return false;
}

int main(void)
{
	if (!(gpio_force_bootloader() && 1)
				 || (FLASH_OPTCR & USER_AP_WP)
			) 
	{
		/* Boot the application if it's valid. */
		 {
			/* Write protect user application area */
			flash_program_option_bytes(FLASH_OPTCR & ~USER_AP_WP);
			/* Set vector table base address. */
			SCB_VTOR = APP_ADDRESS & 0xFFFF;
			/* Initialise master stack pointer. */
			asm volatile("msr msp, %0"::"g"
				     (*(volatile u32 *)APP_ADDRESS));
			/* Jump to application. */
			(*(void (**)())(APP_ADDRESS + 4))();
		}
	}

	usbd_device *usbd_dev;
	
	rcc_clock_setup_hse_3v3(&hse_12mhz_3v3[CLOCK_3V3_48MHZ]);

	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13 | GPIO14 | GPIO15);
	gpio_clear(GPIOA, GPIO13);
	gpio_set(GPIOA, GPIO14 | GPIO15);
	
	/* Write protect bootloader sector if not yet */
	if((FLASH_OPTCR & 0x10000))
    flash_program_option_bytes(FLASH_OPTCR & ~0x10000);
	
	rcc_peripheral_enable_clock(&RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, 
			GPIO9 | GPIO11 | GPIO12);
	gpio_set_af(GPIOA, GPIO_AF10, GPIO9 | GPIO11 | GPIO12);

	usbd_dev = usbd_init(&otgfs_usb_driver, &dev, &config, usb_strings, 4);
	usbd_set_control_buffer_size(usbd_dev, sizeof(usbd_control_buffer));
	usbd_register_control_callback(
				usbd_dev,
				USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
				USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT,
				usbdfu_control_request);

	while (1)
		usbd_poll(usbd_dev);
}

