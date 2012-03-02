/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <libopencm3/stm32/f1/ethernet.h>

void eth_smi_write(u8 phy, u8 reg, u16 data)
{
	/* Set PHY and register addresses for write access. */
	ETH_MACMIIAR &= ~(ETH_MACMIIAR_MR | ETH_MACMIIAR_PA);
	ETH_MACMIIAR |= (phy << 11) | (reg << 6) | ETH_MACMIIAR_MW;

	/* Set register value. */
	ETH_MACMIIDR = data;

	/* Begin transaction. */
	ETH_MACMIIAR |= ETH_MACMIIAR_MB;

	/* Wait for not busy. */
	while (ETH_MACMIIAR & ETH_MACMIIAR_MB);
}

u16 eth_smi_read(u8 phy, u8 reg)
{
	/* Set PHY and register addresses for write access. */
	ETH_MACMIIAR &= ~(ETH_MACMIIAR_MR | ETH_MACMIIAR_PA | ETH_MACMIIAR_MW);
	ETH_MACMIIAR |= (phy << 11) | (reg << 6);

	/* Begin transaction. */
	ETH_MACMIIAR |= ETH_MACMIIAR_MB;

	/* Wait for not busy. */
	while (ETH_MACMIIAR & ETH_MACMIIAR_MB);

	/* Set register value. */
	return (u16)(ETH_MACMIIDR);
}
