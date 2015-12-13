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

#ifndef LIBOPENCM3_EFM32_I2C_H
#define LIBOPENCM3_EFM32_I2C_H

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define I2C_CTRL(base)		MMIO32((base) + 0x000)
#define I2C_CMD(base)		MMIO32((base) + 0x004)
#define I2C_STATE(base)		MMIO32((base) + 0x008)
#define I2C_STATUS(base)	MMIO32((base) + 0x00C)
#define I2C_CLKDIV(base)	MMIO32((base) + 0x010)
#define I2C_SADDR(base)		MMIO32((base) + 0x014)
#define I2C_SADDRMASK(base)	MMIO32((base) + 0x018)
#define I2C_RXDATA(base)	MMIO32((base) + 0x01C)
#define I2C_RXDATAP(base)	MMIO32((base) + 0x020)
#define I2C_TXDATA(base)	MMIO32((base) + 0x024)
#define I2C_IF(base)		MMIO32((base) + 0x028)
#define I2C_IFS(base)		MMIO32((base) + 0x02C)
#define I2C_IFC(base)		MMIO32((base) + 0x030)
#define I2C_IEN(base)		MMIO32((base) + 0x034)
#define I2C_ROUTE(base)		MMIO32((base) + 0x038)

/* I2C_CTRL */
#define I2C_CTRL_CLTO_SHIFT	(16)
#define I2C_CTRL_CLTO_MASK	(0x7 << I2C_CTRL_CLTO_SHIFT)
#define I2C_CTRL_CLTO(v)	\
	(((v) << I2C_CTRL_CLTO_SHIFT) & I2C_CTRL_CLTO_MASK)
#define I2C_CTRL_CLTO_OFF	I2C_CTRL_CLTO(0)
#define I2C_CTRL_CLTO_40PCC	I2C_CTRL_CLTO(1)
#define I2C_CTRL_CLTO_80PCC	I2C_CTRL_CLTO(2)
#define I2C_CTRL_CLTO_160PCC	I2C_CTRL_CLTO(3)
#define I2C_CTRL_CLTO_320PPC	I2C_CTRL_CLTO(4)
#define I2C_CTRL_CLTO_1024PPC	I2C_CTRL_CLTO(5)

#define I2C_CTRL_GIBITO		(1 << 15)

#define I2C_CTRL_BTO_SHIFT	(12)
#define I2C_CTRL_BTO_MASK	(0x3 << I2C_CTRL_BTO_SHIFT)
#define I2C_CTRL_BTO(v)		\
	(((v) << I2C_CTRL_BTO_SHIFT) & I2C_CTRL_BTO_MASK)
#define I2C_CTRL_BTO_OFF	I2C_CTRL_BTO(0)
#define I2C_CTRL_BTO_40PCC	I2C_CTRL_BTO(1)
#define I2C_CTRL_BTO_80PCC	I2C_CTRL_BTO(2)
#define I2C_CTRL_BTO_160PCC	I2C_CTRL_BTO(3)

#define I2C_CTRL_CLHR_SHIFT		(12)
#define I2C_CTRL_CLHR_MASK		(0x3 << I2C_CTRL_CLHR_SHIFT)
#define I2C_CTRL_CLHR(v)		\
	(((v) << I2C_CTRL_CLHR_SHIFT) & I2C_CTRL_CLHR_MASK)
#define I2C_CTRL_CLHR_STANDARD		I2C_CTRL_CLHR(0)
#define I2C_CTRL_CLHR_ASYMMETRIC	I2C_CTRL_CLHR(1)
#define I2C_CTRL_CLHR_FAST		I2C_CTRL_CLHR(2)

#define I2C_CTRL_GCAMEN		(1 << 6)
#define I2C_CTRL_ARBDIS		(1 << 5)
#define I2C_CTRL_AUTOSN		(1 << 4)
#define I2C_CTRL_AUTOSE		(1 << 3)
#define I2C_CTRL_AUTOACK	(1 << 2)
#define I2C_CTRL_SLAVE		(1 << 1)
#define I2C_CTRL_EN		(1 << 0)

/* I2C_CMD */
#define I2C_CMD_CLEARPC		(1 << 7)
#define I2C_CMD_CLEARTX		(1 << 6)
#define I2C_CMD_ABORT		(1 << 5)
#define I2C_CMD_CONT		(1 << 4)
#define I2C_CMD_NACK		(1 << 3)
#define I2C_CMD_ACK		(1 << 2)
#define I2C_CMD_STOP		(1 << 1)
#define I2C_CMD_START		(1 << 0)

/* I2C_STATE */
#define I2C_STATE_STATE_SHIFT	(5)
#define I2C_STATE_STATE_MASK	(0x7 << I2C_STATE_STATE_SHIFT)
#define I2C_STATE_STATE(v)	\
	(((v) << I2C_STATE_STATE_SHIFT) & I2C_STATE_STATE_MASK)
#define I2C_STATE_STATE_IDLE	I2C_STATE_STATE(0)
#define I2C_STATE_STATE_WAIT	I2C_STATE_STATE(1)
#define I2C_STATE_STATE_START	I2C_STATE_STATE(2)
#define I2C_STATE_STATE_ADDR	I2C_STATE_STATE(3)
#define I2C_STATE_STATE_ADDRACK	I2C_STATE_STATE(4)
#define I2C_STATE_STATE_DATA	I2C_STATE_STATE(5)
#define I2C_STATE_STATE_DATAACK	I2C_STATE_STATE(6)

#define I2C_STATE_BUSHOLD	(1 << 4)
#define I2C_STATE_NACKED	(1 << 3)
#define I2C_STATE_TRANSMITTER	(1 << 2)
#define I2C_STATE_MASTER	(1 << 1)
#define I2C_STATE_BUSY		(1 << 0)

/* I2C_STATUS */
#define I2C_STATUS_RXDATAV	(1 << 8)
#define I2C_STATUS_TXBL		(1 << 7)
#define I2C_STATUS_TXC		(1 << 6)
#define I2C_STATUS_PABORT	(1 << 5)
#define I2C_STATUS_PCONT	(1 << 4)
#define I2C_STATUS_PNACK	(1 << 3)
#define I2C_STATUS_PACK		(1 << 2)
#define I2C_STATUS_PSTOP	(1 << 1)
#define I2C_STATUS_PSTART	(1 << 0)

/* I2C_CLKDIV */
#define I2C_CLKDIV_DIV_SHIFT	(0)
#define I2C_CLKDIV_DIV_MASK	(0xFF << I2C_CLKDIV_DIV_SHIFT)
#define I2C_CLKDIV_DIV(v)	\
	(((v) << I2C_CLKDIV_DIV_SHIFT) & I2C_CLKDIV_DIV_MASK)

/* I2C_SADDR */
#define I2C_SADDR_ADDR_SHIFT	(0)
#define I2C_SADDR_ADDR_MASK	(0xFF << I2C_SADDR_ADDR_SHIFT)
#define I2C_SADDR_ADDR(v)	\
	(((v) << I2C_SADDR_ADDR_SHIFT) & I2C_SADDR_ADDR_MASK)

/* I2C_SADDRMASK */
#define I2C_SADDRMASK_MASK_SHIFT	(0)
#define I2C_SADDRMASK_MASK_MASK		(0xFF << I2C_SADDRMASK_MASK_SHIFT)
#define I2C_SADDRMASK_MASK(v)		\
	(((v) << I2C_SADDRMASK_MASK_SHIFT) & I2C_SADDRMASK_MASK_MASK)

/* I2C_IF */
#define I2C_IF_SSTOP		(1 << 16)
#define I2C_IF_CLTO		(1 << 15)
#define I2C_IF_BITO		(1 << 14)
#define I2C_IF_RXUF		(1 << 13)
#define I2C_IF_TXOF		(1 << 12)
#define I2C_IF_BUSHOLD		(1 << 11)
#define I2C_IF_BUSERR		(1 << 10)
#define I2C_IF_ARBLOST		(1 << 9)
#define I2C_IF_MSTOP		(1 << 8)
#define I2C_IF_NACK		(1 << 7)
#define I2C_IF_ACK		(1 << 6)
#define I2C_IF_RXDATAV		(1 << 5)
#define I2C_IF_TXBL		(1 << 4)
#define I2C_IF_TXC		(1 << 3)
#define I2C_IF_ADDR		(1 << 2)
#define I2C_IF_RSTART		(1 << 1)
#define I2C_IF_START		(1 << 0)

/* I2C_IFS */
#define I2C_IFS_SSTOP		(1 << 16)
#define I2C_IFS_CLTO		(1 << 15)
#define I2C_IFS_BITO		(1 << 14)
#define I2C_IFS_RXUF		(1 << 13)
#define I2C_IFS_TXOF		(1 << 12)
#define I2C_IFS_BUSHOLD		(1 << 11)
#define I2C_IFS_BUSERR		(1 << 10)
#define I2C_IFS_ARBLOST		(1 << 9)
#define I2C_IFS_MSTOP		(1 << 8)
#define I2C_IFS_NACK		(1 << 7)
#define I2C_IFS_ACK		(1 << 6)
#define I2C_IFS_RXDATAV		(1 << 5)
#define I2C_IFS_TXBL		(1 << 4)
#define I2C_IFS_TXC		(1 << 3)
#define I2C_IFS_ADDR		(1 << 2)
#define I2C_IFS_RSTART		(1 << 1)
#define I2C_IFS_START		(1 << 0)

/* I2C_IFC */
#define I2C_IFC_SSTOP		(1 << 16)
#define I2C_IFC_CLTO		(1 << 15)
#define I2C_IFC_BITO		(1 << 14)
#define I2C_IFC_RXUF		(1 << 13)
#define I2C_IFC_TXOF		(1 << 12)
#define I2C_IFC_BUSHOLD		(1 << 11)
#define I2C_IFC_BUSERR		(1 << 10)
#define I2C_IFC_ARBLOST		(1 << 9)
#define I2C_IFC_MSTOP		(1 << 8)
#define I2C_IFC_NACK		(1 << 7)
#define I2C_IFC_ACK		(1 << 6)
#define I2C_IFC_RXDATAV		(1 << 5)
#define I2C_IFC_TXBL		(1 << 4)
#define I2C_IFC_TXC		(1 << 3)
#define I2C_IFC_ADDR		(1 << 2)
#define I2C_IFC_RSTART		(1 << 1)
#define I2C_IFC_START		(1 << 0)

/* I2C_IEN */
#define I2C_IEN_SSTOP		(1 << 16)
#define I2C_IEN_CLTO		(1 << 15)
#define I2C_IEN_BITO		(1 << 14)
#define I2C_IEN_RXUF		(1 << 13)
#define I2C_IEN_TXOF		(1 << 12)
#define I2C_IEN_BUSHOLD		(1 << 11)
#define I2C_IEN_BUSERR		(1 << 10)
#define I2C_IEN_ARBLOST		(1 << 9)
#define I2C_IEN_MSTOP		(1 << 8)
#define I2C_IEN_NACK		(1 << 7)
#define I2C_IEN_ACK		(1 << 6)
#define I2C_IEN_RXDATAV		(1 << 5)
#define I2C_IEN_TXBL		(1 << 4)
#define I2C_IEN_TXC		(1 << 3)
#define I2C_IEN_ADDR		(1 << 2)
#define I2C_IEN_RSTART		(1 << 1)
#define I2C_IEN_START		(1 << 0)

/* I2C_ROUTE */
#define I2C_ROUTE_LOCATION_SHIFT	(8)
#define I2C_ROUTE_LOCATION_MASK		(0x7 << I2C_ROUTE_LOCATION_SHIFT)
#define I2C_ROUTE_LOCATION(v)		\
	(((v) << I2C_ROUTE_LOCATION_SHIFT) & I2C_ROUTE_LOCATION_MASK)
#define I2C_ROUTE_LOCATION_LOCx(x)	I2C_ROUTE_LOCATION(x)
#define I2C_ROUTE_LOCATION_LOC0		I2C_ROUTE_LOCATION_LOCx(0)
#define I2C_ROUTE_LOCATION_LOC1		I2C_ROUTE_LOCATION_LOCx(1)
#define I2C_ROUTE_LOCATION_LOC2		I2C_ROUTE_LOCATION_LOCx(2)
#define I2C_ROUTE_LOCATION_LOC3		I2C_ROUTE_LOCATION_LOCx(3)
#define I2C_ROUTE_LOCATION_LOC4		I2C_ROUTE_LOCATION_LOCx(4)
#define I2C_ROUTE_LOCATION_LOC5		I2C_ROUTE_LOCATION_LOCx(5)
#define I2C_ROUTE_LOCATION_LOC6		I2C_ROUTE_LOCATION_LOCx(6)

#define I2C_ROUTE_SCLPEN		(1 << 1)
#define I2C_ROUTE_SDAPEN		(1 << 0)

/* I2C0 */
#define I2C0			I2C0_BASE
#define I2C0_CTRL		I2C_CTRL(base)
#define I2C0_CMD		I2C_CMD(base)
#define I2C0_STATE		I2C_STATE(base)
#define I2C0_STATUS		I2C_STATUS(base)
#define I2C0_CLKDIV		I2C_CLKDIV(base)
#define I2C0_SADDR		I2C_SADDR(base)
#define I2C0_SADDRMASK		I2C_SADDRMASK(base)
#define I2C0_RXDATA		I2C_RXDATA(base)
#define I2C0_RXDATAP		I2C_RXDATAP(base)
#define I2C0_TXDATA		I2C_TXDATA(base)
#define I2C0_IF			I2C_IF(base)
#define I2C0_IFS		I2C_IFS(base)
#define I2C0_IFC		I2C_IFC(base)
#define I2C0_IEN		I2C_IEN(base)
#define I2C0_ROUTE		I2C_ROUTE(base)

/* I2C1 */
#define I2C1			I2C1_BASE
#define I2C1_CTRL		I2C_CTRL(base)
#define I2C1_CMD		I2C_CMD(base)
#define I2C1_STATE		I2C_STATE(base)
#define I2C1_STATUS		I2C_STATUS(base)
#define I2C1_CLKDIV		I2C_CLKDIV(base)
#define I2C1_SADDR		I2C_SADDR(base)
#define I2C1_SADDRMASK		I2C_SADDRMASK(base)
#define I2C1_RXDATA		I2C_RXDATA(base)
#define I2C1_RXDATAP		I2C_RXDATAP(base)
#define I2C1_TXDATA		I2C_TXDATA(base)
#define I2C1_IF			I2C_IF(base)
#define I2C1_IFS		I2C_IFS(base)
#define I2C1_IFC		I2C_IFC(base)
#define I2C1_IEN		I2C_IEN(base)
#define I2C1_ROUTE		I2C_ROUTE(base)

#endif

