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

#ifndef LIBOPENCM3_OTG_COMMON_H
#define LIBOPENCM3_OTG_COMMON_H


 
/* Core Global Control and Status Registers */
#define OTG_GOTGCTL			0x000
#define OTG_GOTGIN			0x004
#define OTG_GAHBCFG			0x008
#define OTG_GUSBCFG			0x00C
#define OTG_GRSTCTL			0x010
#define OTG_GINTSTS			0x014
#define OTG_GINTMSK			0x018
#define OTG_GRXSTSR			0x01C
#define OTG_GRXSTSP			0x020
#define OTG_GRXFSIZ			0x024
#define OTG_GNPTXFSIZ			0x028
#define OTG_GNPTXSTS			0x02C
#define OTG_GCCFG			0x038
#define OTG_CID				0x03C
#define OTG_HPTXFSIZ			0x100
#define OTG_DIEPTXF(x)			(0x104 + 4*(x-1))

/* Host-mode Control and Status Registers */
#define OTG_HCFG			0x400
#define OTG_HFIR			0x404
#define OTG_HFNUM			0x408
#define OTG_HPTXSTS			0x410
#define OTG_HAINT			0x414
#define OTG_HAINTMSK			0x418
#define OTG_HPRT			0x440
#define OTG_HCCHAR(x)			(0x500 + 0x20*(x))
#define OTG_HCINT(x)			(0x508 + 0x20*(x))
#define OTG_HCINTMSK(x)			(0x50C + 0x20*(x))
#define OTG_HCTSIZ(x)			(0x510 + 0x20*(x))


/* Device-mode Control and Status Registers */
#define OTG_DCFG			0x800
#define OTG_DCTL			0x804
#define OTG_DSTS			0x808
#define OTG_DIEPMSK			0x810
#define OTG_DOEPMSK			0x814
#define OTG_DAINT			0x818
#define OTG_DAINTMSK			0x81C
#define OTG_DVBUSDIS			0x828
#define OTG_DVBUSPULSE			0x82C
#define OTG_DIEPEMPMSK			0x834

#define OTG_DIEPCTL0			0x900
#define OTG_DIEPCTL(x)			(0x900 + 0x20*(x))
#define OTG_DOEPCTL0			0xB00
#define OTG_DOEPCTL(x)			(0xB00 + 0x20*(x))
#define OTG_DIEPINT(x)			(0x908 + 0x20*(x))
#define OTG_DOEPINT(x)			(0xB08 + 0x20*(x))
#define OTG_DIEPTSIZ0			0x910
#define OTG_DIEPTSIZ(x)			(0x910 + 0x20*(x))
#define OTG_DOEPTSIZ0			0xB10
#define OTG_DOEPTSIZ(x)			(0xB10 + 0x20*(x))
#define OTG_DTXFSTS(x)			(0x918 + 0x20*(x))

/* Power and clock gating control and status register */
#define OTG_PCGCCTL			0xE00

/* Data FIFO */
#define OTG_FIFO(x)			(((x) + 1) << 12)

#endif
