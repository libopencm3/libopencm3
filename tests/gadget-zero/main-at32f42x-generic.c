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

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include <stdio.h>
#include "usb-gadget0.h"

#define ER_DEBUG
#ifdef ER_DEBUG
#define ER_DPRINTF(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do { } while (0)
#endif

int main(void)
{
	rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_48MHZ]);
	rcc_set_hsi_div(RCC_CFGR3_HSIDIV_NODIV);
	rcc_set_usb_clock_source(RCC_HSI);

	rcc_periph_clock_enable(RCC_CRS);
	rcc_periph_clock_enable(RCC_GPIOA);

	crs_autotrim_usb_enable();

	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO0);
	gpio_set(GPIOA, GPIO0);

	usbd_device *usbd_dev = gadget0_init(&at32_otgfs_driver,
					     "at32f42x-generic");

	ER_DPRINTF("bootup complete\n");

	while (1) {
		gadget0_run(usbd_dev);
		gpio_toggle(GPIOA, GPIO0);
	}
}
