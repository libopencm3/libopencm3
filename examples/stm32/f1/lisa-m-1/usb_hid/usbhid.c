/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2011 Piotr Esden-Tempski <piotr@esden.net>
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

#include <stdlib.h>
#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/otg_fs.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/hid.h>
#include "adxl345.h"

/* Define this to include the DFU APP interface. */
#define INCLUDE_DFU_INTERFACE

#ifdef INCLUDE_DFU_INTERFACE
#include <libopencm3/cm3/scb.h>
#include <libopencm3/usb/dfu.h>
#endif

static usbd_device *usbd_dev;

const struct usb_device_descriptor dev = {
	.bLength = USB_DT_DEVICE_SIZE,
	.bDescriptorType = USB_DT_DEVICE,
	.bcdUSB = 0x0200,
	.bDeviceClass = 0,
	.bDeviceSubClass = 0,
	.bDeviceProtocol = 0,
	.bMaxPacketSize0 = 64,
	.idVendor = 0x0483,
	.idProduct = 0x5710,
	.bcdDevice = 0x0200,
	.iManufacturer = 1,
	.iProduct = 2,
	.iSerialNumber = 3,
	.bNumConfigurations = 1,
};

/* I have no idea what this means. I haven't read the HID spec. */
static const u8 hid_report_descriptor[] = {
	0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01,
	0xA1, 0x00, 0x05, 0x09, 0x19, 0x01, 0x29, 0x03,
	0x15, 0x00, 0x25, 0x01, 0x95, 0x03, 0x75, 0x01,
	0x81, 0x02, 0x95, 0x01, 0x75, 0x05, 0x81, 0x01,
	0x05, 0x01, 0x09, 0x30, 0x09, 0x31, 0x09, 0x38,
	0x15, 0x81, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x03,
	0x81, 0x06, 0xC0, 0x09, 0x3c, 0x05, 0xff, 0x09,
	0x01, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95,
	0x02, 0xb1, 0x22, 0x75, 0x06, 0x95, 0x01, 0xb1,
	0x01, 0xc0,
};

static const struct {
	struct usb_hid_descriptor hid_descriptor;
	struct {
		u8 bReportDescriptorType;
		u16 wDescriptorLength;
	} __attribute__((packed)) hid_report;
} __attribute__((packed)) hid_function = {
	.hid_descriptor = {
		.bLength = sizeof(hid_function),
		.bDescriptorType = USB_DT_HID,
		.bcdHID = 0x0100,
		.bCountryCode = 0,
		.bNumDescriptors = 1,
	},
	.hid_report = {
		.bReportDescriptorType = USB_DT_REPORT,
		.wDescriptorLength = sizeof(hid_report_descriptor),
	}
};

const struct usb_endpoint_descriptor hid_endpoint = {
	.bLength = USB_DT_ENDPOINT_SIZE,
	.bDescriptorType = USB_DT_ENDPOINT,
	.bEndpointAddress = 0x81,
	.bmAttributes = USB_ENDPOINT_ATTR_INTERRUPT,
	.wMaxPacketSize = 4,
	.bInterval = 0x02,
};

const struct usb_interface_descriptor hid_iface = {
	.bLength = USB_DT_INTERFACE_SIZE,
	.bDescriptorType = USB_DT_INTERFACE,
	.bInterfaceNumber = 0,
	.bAlternateSetting = 0,
	.bNumEndpoints = 1,
	.bInterfaceClass = USB_CLASS_HID,
	.bInterfaceSubClass = 1, /* boot */
	.bInterfaceProtocol = 2, /* mouse */
	.iInterface = 0,

	.endpoint = &hid_endpoint,

	.extra = &hid_function,
	.extralen = sizeof(hid_function),
};

#ifdef INCLUDE_DFU_INTERFACE
const struct usb_dfu_descriptor dfu_function = {
	.bLength = sizeof(struct usb_dfu_descriptor),
	.bDescriptorType = DFU_FUNCTIONAL,
	.bmAttributes = USB_DFU_CAN_DOWNLOAD | USB_DFU_WILL_DETACH,
	.wDetachTimeout = 255,
	.wTransferSize = 1024,
	.bcdDFUVersion = 0x011A,
};

const struct usb_interface_descriptor dfu_iface = {
	.bLength = USB_DT_INTERFACE_SIZE,
	.bDescriptorType = USB_DT_INTERFACE,
	.bInterfaceNumber = 1,
	.bAlternateSetting = 0,
	.bNumEndpoints = 0,
	.bInterfaceClass = 0xFE,
	.bInterfaceSubClass = 1,
	.bInterfaceProtocol = 1,
	.iInterface = 0,

	.extra = &dfu_function,
	.extralen = sizeof(dfu_function),
};
#endif

const struct usb_interface ifaces[] = {{
	.num_altsetting = 1,
	.altsetting = &hid_iface,
#ifdef INCLUDE_DFU_INTERFACE
}, {
	.num_altsetting = 1,
	.altsetting = &dfu_iface,
#endif
}};

const struct usb_config_descriptor config = {
	.bLength = USB_DT_CONFIGURATION_SIZE,
	.bDescriptorType = USB_DT_CONFIGURATION,
	.wTotalLength = 0,
#ifdef INCLUDE_DFU_INTERFACE
	.bNumInterfaces = 2,
#else
	.bNumInterfaces = 1,
#endif
	.bConfigurationValue = 1,
	.iConfiguration = 0,
	.bmAttributes = 0xC0,
	.bMaxPower = 0x32,

	.interface = ifaces,
};

static const char *usb_strings[] = {
	"x",
	"Black Sphere Technologies",
	"HID Demo",
	"DEMO",
};

static int hid_control_request(usbd_device *usbd_dev, struct usb_setup_data *req, u8 **buf, u16 *len,
			void (**complete)(usbd_device *usbd_dev, struct usb_setup_data *req))
{
	(void)complete;
	(void)usbd_dev;

	if((req->bmRequestType != 0x81) ||
	   (req->bRequest != USB_REQ_GET_DESCRIPTOR) ||
	   (req->wValue != 0x2200))
		return 0;

	/* Handle the HID report descriptor. */
	*buf = (u8 *)hid_report_descriptor;
	*len = sizeof(hid_report_descriptor);

	return 1;
}

#ifdef INCLUDE_DFU_INTERFACE
static void dfu_detach_complete(usbd_device *usbd_dev, struct usb_setup_data *req)
{
	(void)req;
	(void)usbd_dev;

	gpio_set_mode(GPIOA, GPIO_MODE_INPUT, 0, GPIO15);
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO10);
	gpio_set(GPIOA, GPIO10);
	scb_reset_core();
}

static int dfu_control_request(usbd_device *usbd_dev, struct usb_setup_data *req, u8 **buf, u16 *len,
			void (**complete)(usbd_device *usbd_dev, struct usb_setup_data *req))
{
	(void)buf;
	(void)len;
	(void)usbd_dev;

	if ((req->bmRequestType != 0x21) || (req->bRequest != DFU_DETACH))
		return 0; /* Only accept class request. */

	*complete = dfu_detach_complete;

	return 1;
}
#endif

static void hid_set_config(usbd_device *usbd_dev, u16 wValue)
{
	(void)wValue;

	usbd_ep_setup(usbd_dev, 0x81, USB_ENDPOINT_ATTR_INTERRUPT, 4, NULL);

	usbd_register_control_callback(
				usbd_dev,
				USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
				USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT,
				hid_control_request);
#ifdef INCLUDE_DFU_INTERFACE
	usbd_register_control_callback(
				usbd_dev,
				USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
				USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT,
				dfu_control_request);
#endif

	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB_DIV8);
	systick_set_reload(100000);
	systick_interrupt_enable();
	systick_counter_enable();
}

static u8 spi_readwrite(u32 spi, u8 data)
{
	while (SPI_SR(spi) & SPI_SR_BSY)
		;
	SPI_DR(spi) = data;
	while (!(SPI_SR(spi) & SPI_SR_RXNE))
		;
	return SPI_DR(spi);
}

static u8 accel_read(u8 addr)
{
	u8 ret;
	gpio_clear(GPIOB, GPIO12);
	spi_readwrite(SPI2, addr | 0x80);
	ret = spi_readwrite(SPI2, 0);
	gpio_set(GPIOB, GPIO12);
	return ret;
}

static void accel_write(u8 addr, u8 data)
{
	gpio_clear(GPIOB, GPIO12);
	spi_readwrite(SPI2, addr);
	spi_readwrite(SPI2, data);
	gpio_set(GPIOB, GPIO12);
}

static void accel_get(s16 *x, s16 *y, s16 *z)
{
	if (x)
		*x = accel_read(ADXL345_DATAX0) |
			(accel_read(ADXL345_DATAX1) << 8);
	if (y)
		*y = accel_read(ADXL345_DATAY0) |
			(accel_read(ADXL345_DATAY1) << 8);
	if (z)
		*z = accel_read(ADXL345_DATAZ0) |
			(accel_read(ADXL345_DATAZ1) << 8);
}

int main(void)
{
	int i;

	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_SPI2EN);
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_OTGFSEN);

	/* Configure SPI2: PB13(SCK), PB14(MISO), PB15(MOSI). */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_10_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      GPIO_SPI2_SCK | GPIO_SPI2_MOSI);
	gpio_set_mode(GPIOB, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT,
		      GPIO_SPI2_MISO);
	/* Enable CS pin on PB12. */
	gpio_set(GPIOB, GPIO12);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_10_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);

	/* Force to SPI mode. This should be default after reset! */
	SPI2_I2SCFGR = 0;
	spi_init_master(SPI2,
			SPI_CR1_BAUDRATE_FPCLK_DIV_256,
			SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_2,
			SPI_CR1_DFF_8BIT,
			SPI_CR1_MSBFIRST);
	/* Ignore the stupid NSS pin. */
	spi_enable_software_slave_management(SPI2);
	spi_set_nss_high(SPI2);
	spi_enable(SPI2);

	(void)accel_read(ADXL345_DEVID);
	accel_write(ADXL345_POWER_CTL, ADXL345_POWER_CTL_MEASURE);
	accel_write(ADXL345_DATA_FORMAT, ADXL345_DATA_FORMAT_LALIGN);

	/* USB_DETECT as input. */
	gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT, GPIO8);

	/* Green LED off, as output. */
	gpio_set(GPIOC, GPIO2);
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO2);

	usbd_dev = usbd_init(&stm32f107_usb_driver, &dev, &config, usb_strings);
	usbd_register_set_config_callback(usbd_dev, hid_set_config);

	/* Delay some seconds to show that pull-up switch works. */
	for (i = 0; i < 0x800000; i++)
		__asm__("nop");

	/* Wait for USB Vbus. */
	while (gpio_get(GPIOA, GPIO8) == 0)
		__asm__("nop");

	/* Green LED on, connect USB. */
	gpio_clear(GPIOC, GPIO2);
	// OTG_FS_GCCFG &= ~OTG_FS_GCCFG_VBUSBSEN;

	while (1)
		usbd_poll(usbd_dev);
}

void sys_tick_handler(void)
{
	s16 x, y;
	u8 buf[4] = {0, 0, 0, 0};

	accel_get(&x, &y, NULL);
	buf[1] = x >> 9;
	buf[2] = y >> 9;

	usbd_ep_write_packet(usbd_dev, 0x81, buf, 4);
}
