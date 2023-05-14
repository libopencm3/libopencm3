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

#include <libopencm3/stm32/gpio.h>

/*---------------------------------------------------------------------------*/
void _gpio_set_output_options(uint32_t gpioport, uint8_t otype,
			      uint8_t speed, uint16_t gpios)
{
	switch(speed) {
	case GPIO_OSPEED_VERYHIGH:
		/* TODO appicable to few PORTB bits,
		   treat as OSPEED_HIGH for now	 */
	case GPIO_OSPEED_HIGH:
		GPIO_HDRV(gpioport) |= gpios;
		break;
	case GPIO_OSPEED_MED:
	case GPIO_OSPEED_LOW:
		GPIO_HDRV(gpioport) &= ~gpios;
	}

#undef	gpio_set_output_options
	gpio_set_output_options(gpioport, otype, speed, gpios);
}
