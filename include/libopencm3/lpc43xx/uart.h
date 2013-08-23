/*
* This file is part of the libopencm3 project.
*
* Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#ifndef LPC43XX_UART_H
#define LPC43XX_UART_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* UART port base addresses (for convenience) */
#define UART0                           USART0_BASE /* APB0 */
#define UART1                           UART1_BASE  /* APB0 */
#define UART2                           USART2_BASE /* APB2 */
#define UART3                           USART3_BASE /* APB2 */

/* --- UART registers ------------------------------------------------------- */

/* Receiver Buffer Register (DLAB=0) Read Only */
#define UART_RBR(port)                  MMIO32(port + 0x000) /* 8bits */

/* Transmitter Holding Register (DLAB=0) Write Only */
#define UART_THR(port)                  MMIO32(port + 0x000) /* 8bits */

/* Divisor Latch LSB Register (DLAB=1) */
#define UART_DLL(port)                  MMIO32(port + 0x000) /* 8bits */

/* Divisor Latch MSB Register (DLAB=1) */
#define UART_DLM(port)                  MMIO32(port + 0x004) /* 8bits */

/* Interrupt Enable Register (DLAB=0) */
#define UART_IER(port)                  MMIO32(port + 0x004)

/* Interrupt ID Register Read Only */
#define UART_IIR(port)                  MMIO32(port + 0x008)

/* FIFO Control Register Write Only */
#define UART_FCR(port)                  MMIO32(port + 0x008)

/* Line Control Register */
#define UART_LCR(port)                  MMIO32(port + 0x00C)

/* MCR only for UART1 */

/* Line Status Register */
#define UART_LSR(port)                  MMIO32(port + 0x014)

/* Auto Baud Control Register */
#define UART_ACR(port)                  MMIO32(port + 0x020)

/* IrDA Control Register only for UART0/2/3 */
#define UART_ICR(port)                  MMIO32(port + 0x024)

/* Fractional Divider Register */
#define UART_FDR(port)                  MMIO32(port + 0x028)

/* Oversampling Register only for UART0/2/3 */
#define UART_OSR(port)                  MMIO32(port + 0x02C)

/* Half-Duplex enable Register only for UART0/2/3 */
#define UART_HDEN(port)                 MMIO32(port + 0x040)

/* Smart card Interface Register Only for UART0/2/3 */
#define UART_SCICTRL(port)              MMIO32(port + 0x048)

/* RS-485/EIA-485 Control Register */
#define UART_RS485CTRL(port)            MMIO32(port + 0x04C)

/* RS-485/EIA-485 Address Match Register */
#define UART_RS485ADRMATCH(port)        MMIO32(port + 0x050)

/* RS-485/EIA-485 Direction Control Delay Register */
#define UART_RS485DLY(port)             MMIO32(port + 0x054)

/* Synchronous Mode Control Register only for UART0/2/3 */
#define UART_SYNCCTRL(port)             MMIO32(port + 0x058)

/* Transmit Enable Register */
#define UART_TER(port)                  MMIO32(port + 0x05C)

/* --------------------- BIT DEFINITIONS ----------------------------------- */
/***********************************************************************
* Macro defines for Macro defines for UARTn Receiver Buffer Register
**********************************************************************/
/* UART Received Buffer mask bit (8 bits) */
#define UART_RBR_MASKBIT                ((uint8_t)0xFF)

/***********************************************************************
* Macro defines for Macro defines for UARTn Transmit Holding Register
**********************************************************************/
/* UART Transmit Holding mask bit (8 bits) */
#define UART_THR_MASKBIT                ((uint8_t)0xFF)

/***********************************************************************
* Macro defines for Macro defines for UARTn Divisor Latch LSB register
**********************************************************************/
/* Macro for loading least significant halfs of divisors */
#define UART_LOAD_DLL(div)              ((div) & 0xFF)

/* Divisor latch LSB bit mask */
#define UART_DLL_MASKBIT                ((uint8_t)0xFF)

/***********************************************************************
* Macro defines for Macro defines for UARTn Divisor Latch MSB register
**********************************************************************/
/* Divisor latch MSB bit mask */
#define UART_DLM_MASKBIT                ((uint8_t)0xFF)

/* Macro for loading most significant halfs of divisors */
#define UART_LOAD_DLM(div)              (((div) >> 8) & 0xFF)

/***********************************************************************
* Macro defines for Macro defines for UART interrupt enable register
**********************************************************************/
/* RBR Interrupt enable*/
#define UART_IER_RBRINT_EN              (1 << 0)
/* THR Interrupt enable*/
#define UART_IER_THREINT_EN             (1 << 1)
/* RX line status interrupt enable*/
#define UART_IER_RLSINT_EN              (1 << 2)
/* Modem status interrupt enable */
#define UART1_IER_MSINT_EN              (1 << 3)
/* CTS1 signal transition interrupt enable */
#define UART1_IER_CTSINT_EN             (1 << 7)
/* Enables the end of auto-baud interrupt */
#define UART_IER_ABEOINT_EN             (1 << 8)
/* Enables the auto-baud time-out interrupt */
#define UART_IER_ABTOINT_EN             (1 << 9)
/* UART interrupt enable register bit mask */
#define UART_IER_BITMASK                ((uint32_t)(0x307))
/* UART1 interrupt enable register bit mask */
#define UART1_IER_BITMASK               ((uint32_t)(0x38F))

/**********************************************************************
* Macro defines for Macro defines for UART interrupt identification register
**********************************************************************/

/* Interrupt Status - Active low */
#define UART_IIR_INTSTAT_PEND           (1 << 0)
/* Interrupt identification: Modem interrupt*/
#define UART1_IIR_INTID_MODEM           (0 << 1)
/* Interrupt identification: THRE interrupt*/
#define UART_IIR_INTID_THRE             (1 << 1)
/* Interrupt identification: Receive data available*/
#define UART_IIR_INTID_RDA              (2 << 1)
/* Interrupt identification: Receive line status*/
#define UART_IIR_INTID_RLS              (3 << 1)
/* Interrupt identification: Character time-out indicator*/
#define UART_IIR_INTID_CTI              (6 << 1)
/* Interrupt identification: Interrupt ID mask */
#define UART_IIR_INTID_MASK             (7 << 1)
/* These bits are equivalent to UnFCR[0] */
#define UART_IIR_FIFO_EN                (3 << 6)
/* End of auto-baud interrupt */
#define UART_IIR_ABEO_INT               (1 << 8)
/* Auto-baud time-out interrupt */
#define UART_IIR_ABTO_INT               (1 << 9)
/* UART interrupt identification register bit mask */
#define UART_IIR_BITMASK                ((uint32_t)(0x3CF))

/**********************************************************************
* Macro defines for Macro defines for UART FIFO control register
**********************************************************************/
/* UART FIFO enable */
#define UART_FCR_FIFO_EN                (1 << 0)
/* UART FIFO RX reset */
#define UART_FCR_RX_RS                  (1 << 1)
/* UART FIFO TX reset */
#define UART_FCR_TX_RS                  (1 << 2)
/* UART DMA mode selection */
#define UART_FCR_DMAMODE_SEL            (1 << 3)
/* UART FIFO trigger level 0: 1 character */
#define UART_FCR_TRG_LEV0               (0 << 6)
/* UART FIFO trigger level 1: 4 character */
#define UART_FCR_TRG_LEV1               (1 << 6)
/* UART FIFO trigger level 2: 8 character */
#define UART_FCR_TRG_LEV2               (2 << 6)
/* UART FIFO trigger level 3: 14 character */
#define UART_FCR_TRG_LEV3               (3 << 6)
/* UART FIFO control bit mask */
#define UART_FCR_BITMASK                ((uint8_t)(0xCF))
#define UART_TX_FIFO_SIZE               (16)

/**********************************************************************
* Macro defines for Macro defines for UART line control register
**********************************************************************/
/* UART 5 bit data mode */
#define UART_LCR_WLEN5                  (0 << 0)
/* UART 6 bit data mode */
#define UART_LCR_WLEN6                  (1 << 0)
/* UART 7 bit data mode */
#define UART_LCR_WLEN7                  (2 << 0)
/* UART 8 bit data mode */
#define UART_LCR_WLEN8                  (3 << 0)
/* UART One Stop Bits */
#define UART_LCR_ONE_STOPBIT            (0 << 2)
/* UART Two Stop Bits */
#define UART_LCR_TWO_STOPBIT            (1 << 2)

/* UART Parity Disabled / No Parity */
#define UART_LCR_NO_PARITY              (0 << 3)
/* UART Parity Enable */
#define UART_LCR_PARITY_EN              (1 << 3)
/* UART Odd Parity Select */
#define UART_LCR_PARITY_ODD             (0 << 4)
/* UART Even Parity Select */
#define UART_LCR_PARITY_EVEN            (1 << 4)
/* UART force 1 stick parity */
#define UART_LCR_PARITY_SP_1            (1 << 5)
/* UART force 0 stick parity */
#define UART_LCR_PARITY_SP_0            ((1 << 5) | (1 << 4))
/* UART Transmission Break enable */
#define UART_LCR_BREAK_EN               (1 << 6)
/* UART Divisor Latches Access bit enable */
#define UART_LCR_DLAB_EN                (1 << 7)
/* UART line control bit mask */
#define UART_LCR_BITMASK                ((uint8_t)(0xFF))

/**********************************************************************
* Macro defines for Macro defines for UART line status register
**********************************************************************/
/* Line status register: Receive data ready */
#define UART_LSR_RDR                    (1 << 0)
/* Line status register: Overrun error */
#define UART_LSR_OE                     (1 << 1)
/* Line status register: Parity error */
#define UART_LSR_PE                     (1 << 2)
/* Line status register: Framing error */
#define UART_LSR_FE                     (1 << 3)
/* Line status register: Break interrupt */
#define UART_LSR_BI                     (1 << 4)
/* Line status register: Transmit holding register empty */
#define UART_LSR_THRE                   (1 << 5)
/* Line status register: Transmitter empty */
#define UART_LSR_TEMT                   (1 << 6)
/* Error in RX FIFO */
#define UART_LSR_RXFE                   (1 << 7)
/* UART Line status bit mask */
#define UART_LSR_BITMASK                ((uint8_t)(0xFF))
#define UART_LSR_ERROR_MASK \
	(UART_LSR_OE | UART_LSR_PE | UART_LSR_FE | UART_LSR_BI | UART_LSR_RXFE)

/**********************************************************************
* Macro defines for Macro defines for UART Scratch Pad Register
**********************************************************************/

/* UART Scratch Pad bit mask */
#define UART_SCR_BIMASK           ((uint8_t)(0xFF))

/***********************************************************************
* Macro defines for Macro defines for UART Auto baudrate control register
**********************************************************************/

/* UART Auto-baud start */
#define UART_ACR_START                  (1 << 0)
/* UART Auto baudrate Mode 1 */
#define UART_ACR_MODE                   (1 << 1)
/* UART Auto baudrate restart */
#define UART_ACR_AUTO_RESTART           (1 << 2)
/* UART End of auto-baud interrupt clear */
#define UART_ACR_ABEOINT_CLR            (1 << 8)
/* UART Auto-baud time-out interrupt clear */
#define UART_ACR_ABTOINT_CLR            (1 << 9)
/* UART Auto Baudrate register bit mask */
#define UART_ACR_BITMASK                ((uint32_t)(0x307))

/*********************************************************************
* Macro defines for Macro defines for UART IrDA control register
**********************************************************************/
/* IrDA mode enable */
#define UART_ICR_IRDAEN                 (1 << 0)
/* IrDA serial input inverted */
#define UART_ICR_IRDAINV                (1 << 1)
/* IrDA fixed pulse width mode */
#define UART_ICR_FIXPULSE_EN            (1 << 2)
/* PulseDiv - Configures the pulse when FixPulseEn = 1 */
#define UART_ICR_PULSEDIV(n)            ((uint32_t)((n&0x07)<<3))
/* UART IRDA bit mask */
#define UART_ICR_BITMASK                ((uint32_t)(0x3F))

/**********************************************************************
* Macro defines for Macro defines for UART half duplex register
**********************************************************************/
/* enable half-duplex mode*/
#define UART_HDEN_HDEN                  (1 << 0)

/**********************************************************************
* Macro defines for Macro defines for UART smart card interface control register
**********************************************************************/
/* enable asynchronous half-duplex smart card interface*/
#define UART_SCICTRL_SCIEN              (1 << 0)
/* NACK response is inhibited*/
#define UART_SCICTRL_NACKDIS            (1 << 1)
/* ISO7816-3 protocol T1 is selected*/
#define UART_SCICTRL_PROTSEL_T1         (1 << 2)
/* number of retransmission*/
#define UART_SCICTRL_TXRETRY(n)         ((uint32_t)((n&0x07)<<5))
/* Extra guard time*/
#define UART_SCICTRL_GUARDTIME(n)       ((uint32_t)((n&0xFF)<<8))

/*********************************************************************
* Macro defines for Macro defines for UART synchronous control register
**********************************************************************/
/* enable synchronous mode*/
#define UART_SYNCCTRL_SYNC              (1 << 0)
/* synchronous master mode*/
#define UART_SYNCCTRL_CSRC_MASTER       (1 << 1)
/* sample on falling edge*/
#define UART_SYNCCTRL_FES               (1 << 2)
/* to be defined*/
#define UART_SYNCCTRL_TSBYPASS          (1 << 3)
/* continuous running clock enable (master mode only) */
#define UART_SYNCCTRL_CSCEN             (1 << 4)
/* Do not send start/stop bit */
#define UART_SYNCCTRL_NOSTARTSTOP       (1 << 5)
/* stop continuous clock */
#define UART_SYNCCTRL_CCCLR             (1 << 6)

/*********************************************************************
* Macro defines for Macro defines for UART Fractional divider register
**********************************************************************/

/* Baud-rate generation pre-scaler divisor */
#define UART_FDR_DIVADDVAL(n)           ((uint32_t)(n&0x0F))
/* Baud-rate pre-scaler multiplier value */
#define UART_FDR_MULVAL(n)              ((uint32_t)((n<<4)&0xF0))
/* UART Fractional Divider register bit mask */
#define UART_FDR_BITMASK                ((uint32_t)(0xFF))

/*********************************************************************
* Macro defines for Macro defines for UART Tx Enable register
**********************************************************************/

#define UART_TER_TXEN                   (1 << 0)    /* Transmit enable bit */

/**********************************************************************
* Macro defines for Macro defines for UART FIFO Level register
**********************************************************************/
/* Reflects the current level of the UART receiver FIFO */
#define UART_FIFOLVL_RX(n)              ((uint32_t)(n&0x0F))
/* Reflects the current level of the UART transmitter FIFO */
#define UART_FIFOLVL_TX(n)              ((uint32_t)((n>>8)&0x0F))
/* UART FIFO Level Register bit mask */
#define UART_FIFOLVL_BITMASK            ((uint32_t)(0x0F0F))

/*********************************************************************
* UART enum
**********************************************************************/

/*
* UART Databit type definitions
*/
typedef enum {
	UART_DATABIT_5 = UART_LCR_WLEN5,/* UART 5 bit data mode */
	UART_DATABIT_6 = UART_LCR_WLEN6,/* UART 6 bit data mode */
	UART_DATABIT_7 = UART_LCR_WLEN7,/* UART 7 bit data mode */
	UART_DATABIT_8 = UART_LCR_WLEN8/* UART 8 bit data mode */
} uart_databit_t;

/*
* UART Stop bit type definitions
*/
typedef enum {
	/* UART 1 Stop Bits Select */
	UART_STOPBIT_1 = UART_LCR_ONE_STOPBIT,
	/* UART 2 Stop Bits Select */
	UART_STOPBIT_2 = UART_LCR_TWO_STOPBIT
} uart_stopbit_t;

/*
* UART Parity type definitions
*/
typedef enum {
	/* No parity */
	UART_PARITY_NONE = UART_LCR_NO_PARITY,
	/* Odd parity */
	UART_PARITY_ODD = (UART_LCR_PARITY_ODD | UART_LCR_PARITY_EN),
	/* Even parity */
	UART_PARITY_EVEN = (UART_LCR_PARITY_EVEN | UART_LCR_PARITY_EN),
	/* Forced 1 stick parity */
	UART_PARITY_SP_1 = (UART_LCR_PARITY_SP_1 | UART_LCR_PARITY_EN),
	/* Forced 0 stick parity */
	UART_PARITY_SP_0  = (UART_LCR_PARITY_SP_0 | UART_LCR_PARITY_EN)
} uart_parity_t;

typedef enum {
	UART0_NUM = UART0,
	UART1_NUM = UART1,
	UART2_NUM = UART2,
	UART3_NUM = UART3
} uart_num_t;

typedef enum {
	UART_NO_ERROR = 0,
	UART_TIMEOUT_ERROR = 1
} uart_error_t;

typedef enum {
	UART_RX_NO_DATA = 0,
	UART_RX_DATA_READY = 1,
	UART_RX_DATA_ERROR = 2
} uart_rx_data_ready_t;

/* function prototypes */

BEGIN_DECLS

/* Init UART and set PLL1 as clock source (PCLK) */
void uart_init(uart_num_t uart_num, uart_databit_t data_nb_bits,
	    uart_stopbit_t data_nb_stop, uart_parity_t data_parity,
	    uint16_t uart_divisor, uint8_t uart_divaddval, uint8_t uart_mulval);

uart_rx_data_ready_t uart_rx_data_ready(uart_num_t uart_num);
uint8_t uart_read(uart_num_t uart_num);
uint8_t uart_read_timeout(uart_num_t uart_num, uint32_t rx_timeout_nb_cycles,
	    uart_error_t *error);
void uart_write(uart_num_t uart_num, uint8_t data);

END_DECLS

#endif
