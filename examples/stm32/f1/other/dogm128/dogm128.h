/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#ifndef DOGM128_H
#define DOGM128_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/spi.h>

/*
 * PB10 GPIO       - ~RESET
 * PB12 SPI2_NSS   - ~CS1
 * PB13 SPI2_SCK   - SCL
 * PB14 SPI2_MISO  - A0
 * PB15 SPI2_MOSI  - SI
 */

#define DOGM128_SPI				SPI2
#define DOGM128_RESET_PIN			GPIO10
#define DOGM128_RESET_PORT			GPIOB
#define DOGM128_A0_PIN				GPIO14
#define DOGM128_A0_PORT				GPIOB

/* DOGM128 display commands */
#define DOGM128_PAGE_BASE			0xB0
#define DOGM128_PAGE0				0xB0
#define DOGM128_PAGE1				0xB1
#define DOGM128_PAGE2				0xB2
#define DOGM128_PAGE3				0xB3
#define DOGM128_PAGE4				0xB4
#define DOGM128_PAGE5				0xB5
#define DOGM128_PAGE6				0xB6
#define DOGM128_PAGE7				0xB7
#define DOGM128_DISPLAY_ON			0xAF
#define DOGM128_DISPLAY_OFF			0xAE
#define DOGM128_DISPLAY_START_ADDRESS_BASE	0x40
#define DOGM128_ADC_NORMAL			0xA0
#define DOGM128_ADC_REVERSE			0xA1
#define DOGM128_DISPLAY_NORMAL			0xA6
#define DOGM128_DISPLAY_REVERSE			0xA7
#define DOGM128_ALL_POINTS_ON			0xA5
#define DOGM128_ALL_POINTS_OFF			0xA4
#define DOGM128_BIAS_19				0xA2
#define DOGM128_BIAS_17				0xA3
#define DOGM128_INTERNAL_RESET			0xE2
#define DOGM128_COM_OUTPUT_SCAN_NORMAL		0xC0
#define DOGM128_COM_OUTPUT_SCAN_REVERSE		0xC8
#define DOGM128_POWER_CONTROL_BASE		0x28
#define DOGM128_V0_OUTPUT_RESISTOR_BASE		0x20
#define DOGM128_ELECTRONIC_VOLUME_MODE_SET	0x81
#define DOGM128_STATIC_INDICATOR_OFF		0xAC
#define DOGM128_STATIC_INDICATOR_ON		0xAD
#define DOGM128_BOOSTER_RATIO_SET		0xF8

extern const u8 dogm128_font[96][6];
extern u8 dogm128_ram[1024];
extern u8 dogm128_cursor_x;
extern u8 dogm128_cursor_y;

void dogm128_send_command(u8 command);
void dogm128_set_cursor(u8 xcoord, u8 ycoord);
void dogm128_print_char(u8 data);
void dogm128_print_string(char *s);
void dogm128_set_dot(u8 xcoord, u8 ycoord);
void dogm128_clear_dot(u8 xcoord, u8 ycoord);
void dogm128_send_data(u8 data);
void dogm128_init(void);
void dogm128_update_display(void);
void dogm128_clear(void);

#endif
