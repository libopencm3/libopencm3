/** @addtogroup msc_defines
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#pragma once

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

#define MSC_CTRL		MMIO32(MSC_BASE + 0x000)
#define MSC_READCTRL		MMIO32(MSC_BASE + 0x004)
#define MSC_WRITECTRL		MMIO32(MSC_BASE + 0x008)
#define MSC_WRITECMD		MMIO32(MSC_BASE + 0x00C)
#define MSC_ADDRB		MMIO32(MSC_BASE + 0x010)
#define MSC_WDATA		MMIO32(MSC_BASE + 0x018)
#define MSC_STATUS		MMIO32(MSC_BASE + 0x01C)
#define MSC_IF			MMIO32(MSC_BASE + 0x02C)
#define MSC_IFS			MMIO32(MSC_BASE + 0x030)
#define MSC_IFC			MMIO32(MSC_BASE + 0x034)
#define MSC_IEN			MMIO32(MSC_BASE + 0x038)
#define MSC_LOCK		MMIO32(MSC_BASE + 0x03C)
#define MSC_CMD			MMIO32(MSC_BASE + 0x040)
#define MSC_CACHEHITS		MMIO32(MSC_BASE + 0x044)
#define MSC_CACHEMISSES		MMIO32(MSC_BASE + 0x048)
#define MSC_TIMEBASE		MMIO32(MSC_BASE + 0x050)
#define MSC_MASSLOCK		MMIO32(MSC_BASE + 0x054)

/* MSC_CTRL */
#define MSC_CTRL_BUSFAULT	(1 << 0)

/* MSC_READCTRL */
#define MSC_READCTRL_BUSSTRATEGY_SHIFT	(16)
#define MSC_READCTRL_BUSSTRATEGY_MASK	\
	(0x3 << MSC_READCTRL_BUSSTRATEGY_SHIFT)
#define MSC_READCTRL_BUSSTRATEGY(v)	\
	(((v) << MSC_READCTRL_BUSSTRATEGY_SHIFT) & \
	MSC_READCTRL_BUSSTRATEGY_MASK)

#define MSC_READCTRL_BUSSTRATEGY_CPU	MSC_READCTRL_BUSSTRATEGY(0)
#define MSC_READCTRL_BUSSTRATEGY_DMA	MSC_READCTRL_BUSSTRATEGY(1)
#define MSC_READCTRL_BUSSTRATEGY_DMAEM1	MSC_READCTRL_BUSSTRATEGY(2)
#define MSC_READCTRL_BUSSTRATEGY_NONE	MSC_READCTRL_BUSSTRATEGY(3)

#define MSC_READCTRL_RAMCEN	(1 << 7)
#define MSC_READCTRL_EBICDIS	(1 << 6)
#define MSC_READCTRL_ICCDIS	(1 << 5)
#define MSC_READCTRL_AIDIS	(1 << 4)
#define MSC_READCTRL_IFCDIS	(1 << 3)

#define MSC_READCTRL_MODE_SHIFT		(0)
#define MSC_READCTRL_MODE_MASK		(0x7 << MSC_READCTRL_MODE_SHIFT)
#define MSC_READCTRL_MODE(v)		\
	(((v) << MSC_READCTRL_MODE_SHIFT) & MSC_READCTRL_MODE_MASK)
#define MSC_READCTRL_MODE_WS0		0
#define MSC_READCTRL_MODE_WS1		1
#define MSC_READCTRL_MODE_WS0SCBTP	2
#define MSC_READCTRL_MODE_WS1SCBTP	3
#define MSC_READCTRL_MODE_WS2		4
#define MSC_READCTRL_MODE_WS2SCBTP	5

/* MSC_WRITECTRL */
#define MSC_WRITECTRL_IRQERASEABORT	(1 << 1)
#define MSC_WRITECTRL_WREN		(1 << 0)

/* MSC_WRITECMD */
#define MSC_WRITECMD_CLEARWDATA		(1 << 12)
#define MSC_WRITECMD_ERASEMAIN0		(1 << 8)
#define MSC_WRITECMD_ERASEABORT		(1 << 5)
#define MSC_WRITECMD_WRITETRIG		(1 << 4)
#define MSC_WRITECMD_WRITEONCE		(1 << 3)
#define MSC_WRITECMD_WRITEEND		(1 << 2)
#define MSC_WRITECMD_ERASEPAGE		(1 << 1)
#define MSC_WRITECMD_LADDRIM		(1 << 0)

/* MSC_STATUS */
#define MSC_STATUS_PCRUNNING		(1 << 6)
#define MSC_STATUS_ERASEABORTED		(1 << 5)
#define MSC_STATUS_WORDTIMEOUT		(1 << 4)
#define MSC_STATUS_WDATAREADY		(1 << 3)
#define MSC_STATUS_INVADDR		(1 << 2)
#define MSC_STATUS_LOCKED		(1 << 1)
#define MSC_STATUS_BUSY			(1 << 0)

/* MSC_IF */
#define MSC_IF_CMOF		(1 << 3)
#define MSC_IF_CHOF		(1 << 2)
#define MSC_IF_WRITE		(1 << 1)
#define MSC_IF_ERASE		(1 << 0)

/* MSC_IFS */
#define MSC_IFS_CMOF		(1 << 3)
#define MSC_IFS_CHOF		(1 << 2)
#define MSC_IFS_WRITE		(1 << 1)
#define MSC_IFS_ERASE		(1 << 0)

/* MSC_IFC */
#define MSC_IFC_CMOF		(1 << 3)
#define MSC_IFC_CHOF		(1 << 2)
#define MSC_IFC_WRITE		(1 << 1)
#define MSC_IFC_ERASE		(1 << 0)

/* MSC_*IEN */
#define MSC_IEN_CMOF		(1 << 3)
#define MSC_IEN_CHOF		(1 << 2)
#define MSC_IEN_WRITE		(1 << 1)
#define MSC_IEN_ERASE		(1 << 0)

/* MSC_LOCK */
#define MSC_LOCK_LOCKKEY_SHIFT		(0)
#define MSC_LOCK_LOCKKEY(v)		((v) << MSC_LOCK_LOCKKEY_SHIFT)
#define MSC_LOCK_LOCKKEY_UNLOCKED	MSC_LOCK_LOCKKEY(0)
#define MSC_LOCK_LOCKKEY_LOCKED		MSC_LOCK_LOCKKEY(1)
#define MSC_LOCK_LOCKKEY_LOCK		MSC_LOCK_LOCKKEY(0)
#define MSC_LOCK_LOCKKEY_UNLOCK		MSC_LOCK_LOCKKEY(0x1B71)

/* MSC_CMD */
#define MSC_CMD_STOPPC			(1 << 2)
#define MSC_CMD_STARTPC			(1 << 1)
#define MSC_CMD_INVCACHE		(1 << 0)

/* MSC_TIMEBASE */
#define MSC_TIMEBASE_PERIOD		(1 << 16)

#define MSC_TIMEBASE_BASE_SHIFT		(0)
#define MSC_TIMEBASE_BASE_MASK		(0x3F << MSC_TIMEBASE_BASE_SHIFT)
#define MSC_TIMEBASE_BASE(v)		\
	(((v) << MSC_TIMEBASE_BASE_SHIFT) & MSC_TIMEBASE_BASE_MASK)

/* MSC_MASSLOCK */
#define MSC_MASSLOCK_LOCKKEY_SHIFT	(0)
#define MSC_MASSLOCK_LOCKKEY(v)		((v) << MSC_MASSLOCK_LOCKKEY_SHIFT)
#define MSC_MASSLOCK_LOCKKEY_UNLOCKED	MSC_MASSLOCK_LOCKKEY(0)
#define MSC_MASSLOCK_LOCKKEY_LOCKED	MSC_MASSLOCK_LOCKKEY(1)
#define MSC_MASSLOCK_LOCKKEY_LOCK	MSC_MASSLOCK_LOCKKEY(0)
#define MSC_MASSLOCK_LOCKKEY_UNLOCK	MSC_MASSLOCK_LOCKKEY(0x631A)

/**@}*/