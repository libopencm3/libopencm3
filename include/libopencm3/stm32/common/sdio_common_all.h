/** @defgroup sdio_defines SDIO Defines
 *
 * @ingroup STM32_defines
 *
 * @brief Defined Constants, Types n Functions for the STM32 SDIO
 *
 * @version 1.0.0
 *
 * @date 18 April 2017
 *
 * LGPL License Terms @ref lgpl_license
 */

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

#ifndef SDIO_COMMON_ALL_H
#define SDIO_COMMON_ALL_H

/* --- SDIO registers ------------------------------------------------------ */
#define SDIO_POWER			MMIO32(SDIO_BASE + 0x00) /* SDIO power control register (SDIO_POWER) */
#define SDIO_CLKCR			MMIO32(SDIO_BASE + 0x04) /* SDIO clock control register (SDIO_CLKCR) */
#define SDIO_ARG			MMIO32(SDIO_BASE + 0x08) /* SDIO argument register (SDIO_ARG) */
#define SDIO_CMD			MMIO32(SDIO_BASE + 0x0C) /* SDIO command register (SDIO_CMD) */
#define SDIO_RESPCMD		MMIO32(SDIO_BASE + 0x10) /* SDIO command response register (SDIO_RESPCMD) */
#define SDIO_RESP1			MMIO32(SDIO_BASE + 0x14) /* SDIO response 1..4 register (SDIO_RESPx) */
#define SDIO_RESP2			MMIO32(SDIO_BASE + 0x18)
#define SDIO_RESP3			MMIO32(SDIO_BASE + 0x1C)
#define SDIO_RESP4			MMIO32(SDIO_BASE + 0x20)
#define SDIO_DTIMER			MMIO32(SDIO_BASE + 0x24) /* SDIO data timer register (SDIO_DTIMER) */
#define SDIO_DLEN			MMIO32(SDIO_BASE + 0x28) /* SDIO data length register (SDIO_DLEN) */
#define SDIO_DCTRL			MMIO32(SDIO_BASE + 0x2C) /* SDIO data control register (SDIO_DCTRL) */
#define SDIO_DCOUNT			MMIO32(SDIO_BASE + 0x30) /* SDIO data counter register (SDIO_DCOUNT) */
#define SDIO_STA			MMIO32(SDIO_BASE + 0x34) /* SDIO status register (SDIO_STA) */
#define SDIO_ICR			MMIO32(SDIO_BASE + 0x38) /* SDIO interrupt clear register (SDIO_ICR) */
#define SDIO_MASK			MMIO32(SDIO_BASE + 0x3C) /* SDIO mask register (SDIO_MASK) */
#define SDIO_FIFOCNT		MMIO32(SDIO_BASE + 0x48) /* SDIO FIFO counter register (SDIO_FIFOCNT) */
#define SDIO_FIFO			MMIO32(SDIO_BASE + 0x80) /* SDIO data FIFO register (SDIO_FIFO) */

/* --- SDIO_POWER values -------------------------------------------------- */
#define SDIO_POWER_PWRCTRL_SHIFT		(uint32_t)0
#define SDIO_POWER_PWRCTRL_MASK	    	(uint32_t)(0x3 << SDIO_POWER_PWRCTRL_SHIFT)
#define SDIO_POWER_PWRCTRL_PWROFF		(uint32_t)(0x0 << SDIO_POWER_PWRCTRL_SHIFT)
#define SDIO_POWER_PWRCTRL_PWRON		(uint32_t)(0x3 << SDIO_POWER_PWRCTRL_SHIFT)

/* --- SDIO_POWER values -------------------------------------------------- */
#define SDIO_CLKCR_HWFC_EN				(uint32_t)(1 << 14)
#define SDIO_CLKCR_NEGEDGE				(uint32_t)(1 << 13)
#define SDIO_CLKCR_WIDBUS_SHIFT			(uint32_t)11
#define SDIO_CLKCR_WIDBUS_MASK      	(uint32_t)(0x3 << SDIO_CLKCR_WIDBUS_SHIFT)
#define SDIO_CLKCR_BYPASS				(uint32_t)(1 << 10)
#define SDIO_CLKCR_PWRSAV				(uint32_t)(1 << 9)
#define SDIO_CLKCR_CLKEN				(uint32_t)(1 << 8)
#define SDIO_CLKCR_CLKDIV_MSK			(uint32_t)(0xFF << 0)
#define SDIO_CLKCR_CLEAR_MASK         	((uint32_t)0xFFFF8100)

/* --- SDIO_CMD values ---------------------------------------------------- */
#define SDIO_CMD_ATACMD					(uint32_t)(1 << 14)
#define SDIO_CMD_NIEN					(uint32_t)(1 << 13)
#define SDIO_CMD_ENCMDCOMPL				(uint32_t)(1 << 12)
#define SDIO_CMD_SDIOSUSPEND			(uint32_t)(1 << 11)
#define SDIO_CMD_CPSMEN					(uint32_t)(1 << 10)
#define SDIO_CMD_WAITPEND				(uint32_t)(1 << 9)
#define SDIO_CMD_WAITINT				(uint32_t)(1 << 8)
#define SDIO_CMD_WAITRESP_SHIFT			(uint32_t)6
#define SDIO_CMD_WAITRESP_MSK       	(uint32_t)(0x3 << SDIO_CMD_WAITRESP_SHIFT)
#define SDIO_CMD_CMDINDEX_MSK			(uint32_t)(0x3F << 0)
#define SDIO_CMD_CLEAR_MASK             ((uint32_t)0xFFFFF800)

/* --- SDIO_RESPCMD values ------------------------------------------------ */
#define SDIO_RESPCMD_MSK				(uint32_t)(0x3F << 0)

/* --- SDIO_DLEN values --------------------------------------------------- */
#define SDIO_DLEN_MSK			    	(uint32_t)0x1FFFFFF

/* --- SDIO_DCTRL values -------------------------------------------------- */
#define SDIO_DCTRL_SDIOEN				((uint32_t)(1 << 11))
#define SDIO_DCTRL_RWMOD				((uint32_t)(1 << 10))
#define SDIO_DCTRL_RWSTOP				((uint32_t)(1 << 9))
#define SDIO_DCTRL_RWSTART				((uint32_t)(1 << 8))
#define SDIO_DCTRL_DBLOCKSIZE_SHIFT		((uint32_t)4)
#define SDIO_DCTRL_DBLOCKSIZE_MSK		((uint32_t)(0xF << SDIO_DCTRL_DBLOCKSIZE_SHIFT))
#define SDIO_DCTRL_DMAEN				((uint32_t)(1 << 3))
#define SDIO_DCTRL_DTMODE				((uint32_t)(1 << 2))
#define SDIO_DCTRL_DTDIR				((uint32_t)(1 << 1))
#define SDIO_DCTRL_DTEN					((uint32_t)(1 << 0))
#define SDIO_DCTRL_CLEAR_MASK           ((uint32_t)0xFFFFFF08)

typedef enum
{
	SDIO_CK_RISING_EDGE,
	SDIO_CK_FALLING_EDGE,
}SDIO_CK_Polarity;

typedef enum
{
	WIDE_BUS_1 = (uint32_t)(0x0 << SDIO_CLKCR_WIDBUS_SHIFT),
	WIDE_BUS_4 = (uint32_t)(0x1 << SDIO_CLKCR_WIDBUS_SHIFT),
	WIDE_BUS_8 = (uint32_t)(0x2 << SDIO_CLKCR_WIDBUS_SHIFT),
}SDIO_WideBusMode;

typedef enum 
{
	WAIT_NO,
	WAIT_IT,
	WAIT_PEND,
}SDIO_WaitInterrupt;

typedef enum 
{
	RESPONSE_NO    = (uint32_t)(0x0 << SDIO_CMD_WAITRESP_SHIFT),
	RESPONSE_SHORT = (uint32_t)(0x1 << SDIO_CMD_WAITRESP_SHIFT),
	RESPONSE_LONG  = (uint32_t)(0x3 << SDIO_CMD_WAITRESP_SHIFT),
}SDIO_ResponseType;

typedef enum 
{
	CONTROLLER_TO_CARD,
	CARD_TO_CONTROLLER,
}SDIO_TransferDirection;

typedef enum 
{
	BLOCK_DATA_TRANSFER,
	STREAM_DATA_TRANSFER,
}SDIO_TransferMode;

typedef enum 
{
	BLOCK_LENGTH_1_B     = (uint32_t)(0x0 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_2_B     = (uint32_t)(0x1 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_4_B     = (uint32_t)(0x2 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_8_B     = (uint32_t)(0x3 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_16_B    = (uint32_t)(0x4 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_32_B    = (uint32_t)(0x5 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_64_B    = (uint32_t)(0x6 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_128_B   = (uint32_t)(0x7 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_256_B   = (uint32_t)(0x8 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_512_B   = (uint32_t)(0x9 << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_1024_B  = (uint32_t)(0xA << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_2048_B  = (uint32_t)(0xB << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_4096_B  = (uint32_t)(0xC << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_8192_B  = (uint32_t)(0xD << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
	BLOCK_LENGTH_16384_B = (uint32_t)(0xE << SDIO_DCTRL_DBLOCKSIZE_SHIFT),
}SDIO_BlockSize;

typedef enum 
{
	SDIO_CEATAEND	= (uint32_t)(1 << 23), //CE-ATA command completion signal received for CMD61
	SDIO_SDIOIT		= (uint32_t)(1 << 22), //SD I/O received
	SDIO_RXDAVL		= (uint32_t)(1 << 21), //Data available in receive FIFO
	SDIO_TXDAVL		= (uint32_t)(1 << 20), //Data available in transmit FIFO 
	SDIO_RXFIFOE	= (uint32_t)(1 << 19), //Receive FIFO empty 
	SDIO_TXFIFOE	= (uint32_t)(1 << 18), //Transmit FIFO empty 
	SDIO_RXFIFOF	= (uint32_t)(1 << 17), //Receive FIFO full 
	SDIO_TXFIFOF	= (uint32_t)(1 << 16), //Transmit FIFO full 
	SDIO_RXFIFOHF	= (uint32_t)(1 << 15), //Receive FIFO Half Full 
	SDIO_TXFIFOHE	= (uint32_t)(1 << 14), //Transmit FIFO Half Empty 
	SDIO_RXACT		= (uint32_t)(1 << 13), //Data receive in progress 
	SDIO_TXACT		= (uint32_t)(1 << 12), //Data transmit in progress 
	SDIO_CMDACT		= (uint32_t)(1 << 11), //Command transfer in progress 
	SDIO_DBCKEND	= (uint32_t)(1 << 10), //Data block sent/received (CRC check passed) 
	SDIO_STBITERR	= (uint32_t)(1 << 9),  //Start bit not detected on all data signals in wide bus mode 
	SDIO_DATAEND	= (uint32_t)(1 << 8),  //Data end (data counter, SDIDCOUNT, is zero) 
	SDIO_CMDSENT	= (uint32_t)(1 << 7),  //Command sent (no response required) 
	SDIO_CMDREND	= (uint32_t)(1 << 6),  //Command response received (CRC check passed) 
	SDIO_RXOVERR	= (uint32_t)(1 << 5),  //Received FIFO overrun error 
	SDIO_TXUNDERR	= (uint32_t)(1 << 4),  //Transmit FIFO underrun error 
	SDIO_DTIMEOUT	= (uint32_t)(1 << 3),  //Data timeout 
	SDIO_CTIMEOUT	= (uint32_t)(1 << 2),  //Command response timeout 
	SDIO_DCRCFAIL	= (uint32_t)(1 << 1),  //Data block sent/received (CRC check failed) 
	SDIO_CCRCFAIL	= (uint32_t)(1 << 0),  //Command response received (CRC check failed) 
}SDIO_Flag;

typedef enum 
{
	READ_WAIT_DATA2,
	READ_WAIT_CLK,
}SDIO_ReadWaitMode;

typedef struct
{
	SDIO_CK_Polarity polarity;
	bool bypass;
	bool power_save;
	SDIO_WideBusMode bus_wide;
	bool flow_control;
	uint8_t clock_divider;
} SDIO_config;

typedef struct
{
	uint8_t index;
	uint32_t arg;
	SDIO_ResponseType response;
	SDIO_WaitInterrupt wait;
	bool enable_CPSM;
} SDIO_command;

typedef struct
{
	uint32_t period;
	uint32_t length;
	SDIO_BlockSize size;
	SDIO_TransferDirection direction;
	SDIO_TransferMode mode;
	bool enable;
} SDIO_data_config;

/* --- Function prototypes -------------------------------------------------------------------------- */
BEGIN_DECLS
void sdio_deinit(void);
void sdio_config(SDIO_config *config);
void sdio_ck_enable(void);
void sdio_ck_disable(void);
void sdio_enable(void);
void sdio_disable(void);
void sdio_send_command(SDIO_command *cmd);
uint8_t sdio_get_cmd_response(void);
uint32_t sdio_get_card_status_1(void);
uint32_t sdio_get_card_status_2(void);
uint32_t sdio_get_card_status_3(void);
uint32_t sdio_get_card_status_4(void);
void sdio_data_config(SDIO_data_config *config);
uint32_t sdio_get_data_counter(void);
uint32_t sdio_read_fifo_data(void);
void sdio_write_fifo_data(uint32_t data);
uint32_t sdio_get_fifo_counter(void);
void sdio_read_wait_start_enable(void);
void sdio_read_wait_start_disable(void);
void sdio_read_wait_stop_enable(void);
void sdio_read_wait_stop_disable(void);
void sdio_set_read_wait_mode(SDIO_ReadWaitMode mode);
void sdio_operation_enable(void);
void sdio_operation_disable(void);
void sdio_suspend_cmd_enable(void);
void sdio_suspend_cmd_disable(void);
void sdio_completion_cmd_enable(void);
void sdio_completion_cmd_disable(void);
void sdio_CEATA_interrupt_enable(void);
void sdio_CEATA_interrupt_disable(void);
void sdio_CEATA_cmd_enable(void);
void sdio_CEATA_cmd_disable(void);
void sdio_enable_dma(void);
void sdio_disable_dma(void);
void sdio_enable_interrupt(uint32_t interrupt);
void sdio_disable_interrupt(uint32_t interrupt);
bool sdio_get_flag_status(uint32_t flag);
void sdio_clear_flag_status(uint32_t flag);
END_DECLS

#endif
