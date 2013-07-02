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

/* Transmit Enable Register Only for UART1 */
#define UART_TER_UART1(port)            MMIO32(port + 0x030)

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

/* Transmit Enable Register Only for UART0/2/3 */
#define UART_TER(port)                  MMIO32(port + 0x05C)

/* --------------------- BIT DEFINITIONS -------------------------------------- */
/***********************************************************************
* Macro defines for Macro defines for UARTn Receiver Buffer Register
**********************************************************************/
#define UART_RBR_MASKBIT                ((uint8_t)0xFF)       /* UART Received Buffer mask bit (8 bits) */

/***********************************************************************
* Macro defines for Macro defines for UARTn Transmit Holding Register
**********************************************************************/
#define UART_THR_MASKBIT                ((uint8_t)0xFF)       /* UART Transmit Holding mask bit (8 bits) */

/***********************************************************************
* Macro defines for Macro defines for UARTn Divisor Latch LSB register
**********************************************************************/
#define UART_LOAD_DLL(div)              ((div) & 0xFF)  /* Macro for loading least significant halfs of divisors */
#define UART_DLL_MASKBIT                ((uint8_t)0xFF)      /* Divisor latch LSB bit mask */

/***********************************************************************
* Macro defines for Macro defines for UARTn Divisor Latch MSB register
**********************************************************************/
#define UART_DLM_MASKBIT                ((uint8_t)0xFF)              /* Divisor latch MSB bit mask */
#define UART_LOAD_DLM(div)              (((div) >> 8) & 0xFF)   /* Macro for loading most significant halfs of divisors */

/***********************************************************************
* Macro defines for Macro defines for UART interrupt enable register
**********************************************************************/
#define UART_IER_RBRINT_EN              ((uint32_t)(BIT0))  /* RBR Interrupt enable*/
#define UART_IER_THREINT_EN             ((uint32_t)(BIT1))  /* THR Interrupt enable*/
#define UART_IER_RLSINT_EN              ((uint32_t)(BIT2))  /* RX line status interrupt enable*/
#define UART1_IER_MSINT_EN              ((uint32_t)(BIT3))  /* Modem status interrupt enable */
#define UART1_IER_CTSINT_EN             ((uint32_t)(BIT7))  /* CTS1 signal transition interrupt enable */
#define UART_IER_ABEOINT_EN             ((uint32_t)(BIT8))  /* Enables the end of auto-baud interrupt */
#define UART_IER_ABTOINT_EN             ((uint32_t)(BIT9))  /* Enables the auto-baud time-out interrupt */
#define UART_IER_BITMASK                ((uint32_t)(0x307)) /* UART interrupt enable register bit mask */
#define UART1_IER_BITMASK               ((uint32_t)(0x38F)) /* UART1 interrupt enable register bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART interrupt identification register
**********************************************************************/
#define UART_IIR_INTSTAT_PEND           ((uint32_t)(BIT0))  /* Interrupt Status - Active low */
#define UART_IIR_INTID_RDA              ((uint32_t)(2<<1))  /* Interrupt identification: Receive data available*/
#define UART_IIR_INTID_RLS              ((uint32_t)(3<<1))  /* Interrupt identification: Receive line status*/
#define UART_IIR_INTID_CTI              ((uint32_t)(6<<1))  /* Interrupt identification: Character time-out indicator*/
#define UART_IIR_INTID_THRE             ((uint32_t)(BIT1))  /* Interrupt identification: THRE interrupt*/
#define UART1_IIR_INTID_MODEM           ((uint32_t)(0<<1))  /* Interrupt identification: Modem interrupt*/
#define UART_IIR_INTID_MASK             ((uint32_t)(7<<1))  /* Interrupt identification: Interrupt ID mask */
#define UART_IIR_FIFO_EN                ((uint32_t)(3<<6))  /* These bits are equivalent to UnFCR[0] */
#define UART_IIR_ABEO_INT               ((uint32_t)(BIT8))  /* End of auto-baud interrupt */
#define UART_IIR_ABTO_INT               ((uint32_t)(BIT9))  /* Auto-baud time-out interrupt */
#define UART_IIR_BITMASK                ((uint32_t)(0x3CF)) /* UART interrupt identification register bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART FIFO control register
**********************************************************************/
#define UART_FCR_FIFO_EN                ((uint8_t)(BIT0)) /* UART FIFO enable */
#define UART_FCR_RX_RS                  ((uint8_t)(BIT1)) /* UART FIFO RX reset */
#define UART_FCR_TX_RS                  ((uint8_t)(BIT2)) /* UART FIFO TX reset */
#define UART_FCR_DMAMODE_SEL            ((uint8_t)(BIT3)) /* UART DMA mode selection */
#define UART_FCR_TRG_LEV0               ((uint8_t)(0))    /* UART FIFO trigger level 0: 1 character */
#define UART_FCR_TRG_LEV1               ((uint8_t)(BIT6)) /* UART FIFO trigger level 1: 4 character */
#define UART_FCR_TRG_LEV2               ((uint8_t)(2<<6)) /* UART FIFO trigger level 2: 8 character */
#define UART_FCR_TRG_LEV3               ((uint8_t)(3<<6)) /* UART FIFO trigger level 3: 14 character */
#define UART_FCR_BITMASK                ((uint8_t)(0xCF)) /* UART FIFO control bit mask */
#define UART_TX_FIFO_SIZE               (16)

/**********************************************************************
* Macro defines for Macro defines for UART line control register
**********************************************************************/
#define UART_LCR_WLEN5                  ((uint8_t)(0))    /* UART 5 bit data mode */
#define UART_LCR_WLEN6                  ((uint8_t)(1))    /* UART 6 bit data mode */
#define UART_LCR_WLEN7                  ((uint8_t)(2))    /* UART 7 bit data mode */
#define UART_LCR_WLEN8                  ((uint8_t)(3))    /* UART 8 bit data mode */
#define UART_LCR_ONE_STOPBIT            ((uint8_t)(0))    /* UART One Stop Bits */
#define UART_LCR_TWO_STOPBIT            ((uint8_t)(BIT2)) /* UART Two Stop Bits */
#define UART_LCR_NO_PARITY              ((uint8_t)(0))    /* UART Parity Disabled / No Parity */
#define UART_LCR_PARITY_EN              ((uint8_t)(BIT3)) /* UART Parity Enable */
#define UART_LCR_PARITY_ODD             ((uint8_t)(0))    /* UART Odd Parity Select */
#define UART_LCR_PARITY_EVEN            ((uint8_t)(BIT4)) /* UART Even Parity Select */
#define UART_LCR_PARITY_SP_1             ((uint8_t)(0x20)) /* UART force 1 stick parity */
#define UART_LCR_PARITY_SP_0             ((uint8_t)(0x30)) /* UART force 0 stick parity */
#define UART_LCR_BREAK_EN               ((uint8_t)(BIT6)) /* UART Transmission Break enable */
#define UART_LCR_DLAB_EN                ((uint8_t)(BIT7)) /* UART Divisor Latches Access bit enable */
#define UART_LCR_BITMASK                ((uint8_t)(0xFF)) /* UART line control bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART line status register
**********************************************************************/
#define UART_LSR_RDR                    ((uint8_t)(BIT0)) /* Line status register: Receive data ready */
#define UART_LSR_OE                     ((uint8_t)(BIT1)) /* Line status register: Overrun error */
#define UART_LSR_PE                     ((uint8_t)(BIT2)) /* Line status register: Parity error */
#define UART_LSR_FE                     ((uint8_t)(BIT3)) /* Line status register: Framing error */
#define UART_LSR_BI                     ((uint8_t)(BIT4)) /* Line status register: Break interrupt */
#define UART_LSR_THRE                   ((uint8_t)(BIT5)) /* Line status register: Transmit holding register empty */
#define UART_LSR_TEMT                   ((uint8_t)(BIT6)) /* Line status register: Transmitter empty */
#define UART_LSR_RXFE                   ((uint8_t)(BIT7)) /* Error in RX FIFO */
#define UART_LSR_BITMASK                ((uint8_t)(0xFF)) /* UART Line status bit mask */
#define UART_LSR_ERROR_MASK				(UART_LSR_OE|UART_LSR_PE|UART_LSR_FE|UART_LSR_BI|UART_LSR_RXFE)

/**********************************************************************
* Macro defines for Macro defines for UART Scratch Pad Register
**********************************************************************/
#define UART_SCR_BIMASK           ((uint8_t)(0xFF))    /* UART Scratch Pad bit mask */

/***********************************************************************
* Macro defines for Macro defines for UART Auto baudrate control register
**********************************************************************/
#define UART_ACR_START                  ((uint32_t)(BIT0))    /* UART Auto-baud start */
#define UART_ACR_MODE                   ((uint32_t)(BIT1))    /* UART Auto baudrate Mode 1 */
#define UART_ACR_AUTO_RESTART           ((uint32_t)(BIT2))    /* UART Auto baudrate restart */
#define UART_ACR_ABEOINT_CLR            ((uint32_t)(BIT8))    /* UART End of auto-baud interrupt clear */
#define UART_ACR_ABTOINT_CLR            ((uint32_t)(BIT9))    /* UART Auto-baud time-out interrupt clear */
#define UART_ACR_BITMASK                ((uint32_t)(0x307))   /* UART Auto Baudrate register bit mask */

/*********************************************************************
* Macro defines for Macro defines for UART IrDA control register
**********************************************************************/
#define UART_ICR_IRDAEN                 ((uint32_t)(BIT0))            /* IrDA mode enable */
#define UART_ICR_IRDAINV                ((uint32_t)(BIT1))            /* IrDA serial input inverted */
#define UART_ICR_FIXPULSE_EN            ((uint32_t)(BIT2))            /* IrDA fixed pulse width mode */
#define UART_ICR_PULSEDIV(n)            ((uint32_t)((n&0x07)<<3))     /* PulseDiv - Configures the pulse when FixPulseEn = 1 */
#define UART_ICR_BITMASK                ((uint32_t)(0x3F))            /* UART IRDA bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART half duplex register
**********************************************************************/
#define UART_HDEN_HDEN                  ((uint32_t)(BIT0))            /* enable half-duplex mode*/

/**********************************************************************
* Macro defines for Macro defines for UART smart card interface control register
**********************************************************************/
#define UART_SCICTRL_SCIEN              ((uint32_t)(BIT0))           /* enable asynchronous half-duplex smart card interface*/
#define UART_SCICTRL_NACKDIS            ((uint32_t)(BIT1))           /* NACK response is inhibited*/
#define UART_SCICTRL_PROTSEL_T1         ((uint32_t)(BIT2))           /* ISO7816-3 protocol T1 is selected*/
#define UART_SCICTRL_TXRETRY(n)         ((uint32_t)((n&0x07)<<5))    /* number of retransmission*/
#define UART_SCICTRL_GUARDTIME(n)       ((uint32_t)((n&0xFF)<<8))    /* Extra guard time*/

/*********************************************************************
* Macro defines for Macro defines for UART synchronous control register
**********************************************************************/
#define UART_SYNCCTRL_SYNC              ((uint32_t)(BIT0))   /* enable synchronous mode*/
#define UART_SYNCCTRL_CSRC_MASTER       ((uint32_t)(BIT1))   /* synchronous master mode*/
#define UART_SYNCCTRL_FES               ((uint32_t)(BIT2))   /* sample on falling edge*/
#define UART_SYNCCTRL_TSBYPASS          ((uint32_t)(BIT3))   /* to be defined*/
#define UART_SYNCCTRL_CSCEN             ((uint32_t)(BIT4))   /* continuous running clock enable (master mode only) */
#define UART_SYNCCTRL_NOSTARTSTOP       ((uint32_t)(BIT5))   /* Do not send start/stop bit */
#define UART_SYNCCTRL_CCCLR             ((uint32_t)(BIT6))   /* stop continuous clock */

/*********************************************************************
* Macro defines for Macro defines for UART Fractional divider register
**********************************************************************/
#define UART_FDR_DIVADDVAL(n)           ((uint32_t)(n&0x0F))         /* Baud-rate generation pre-scaler divisor */
#define UART_FDR_MULVAL(n)              ((uint32_t)((n<<4)&0xF0))    /* Baud-rate pre-scaler multiplier value */
#define UART_FDR_BITMASK                ((uint32_t)(0xFF))           /* UART Fractional Divider register bit mask */

/*********************************************************************
* Macro defines for Macro defines for UART Tx Enable register
**********************************************************************/
#define UART1_TER_TXEN                  ((uint8_t)(BIT7))    /* Transmit enable bit */
#define UART1_TER_BITMASK               ((uint8_t)(0x80))    /* UART Transmit Enable Register bit mask */

#define UART0_2_3_TER_TXEN              ((uint8_t)(BIT0))    /* Transmit enable bit */
#define UART0_2_3_TER_BITMASK           ((uint8_t)(0x01))    /* UART Transmit Enable Register bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART FIFO Level register
**********************************************************************/
#define UART_FIFOLVL_RX(n)              ((uint32_t)(n&0x0F))        /* Reflects the current level of the UART receiver FIFO */
#define UART_FIFOLVL_TX(n)              ((uint32_t)((n>>8)&0x0F))   /* Reflects the current level of the UART transmitter FIFO */
#define UART_FIFOLVL_BITMASK            ((uint32_t)(0x0F0F))        /* UART FIFO Level Register bit mask */

/*********************************************************************
* UART enum
**********************************************************************/

/*
* UART Databit type definitions
*/
typedef enum {
	UART_DATABIT_5       = UART_LCR_WLEN5,    /* UART 5 bit data mode */
	UART_DATABIT_6       = UART_LCR_WLEN6,    /* UART 6 bit data mode */
	UART_DATABIT_7       = UART_LCR_WLEN7,    /* UART 7 bit data mode */
	UART_DATABIT_8       = UART_LCR_WLEN8     /* UART 8 bit data mode */
} uart_databit_t;

/*
* UART Stop bit type definitions
*/
typedef enum {
	UART_STOPBIT_1       = UART_LCR_ONE_STOPBIT,    /* UART 1 Stop Bits Select */
	UART_STOPBIT_2       = UART_LCR_TWO_STOPBIT     /* UART 2 Stop Bits Select */
} uart_stopbit_t;

/*
* UART Parity type definitions
*/
typedef enum {
	UART_PARITY_NONE     = UART_LCR_NO_PARITY,    /* No parity */
	UART_PARITY_ODD      = (UART_LCR_PARITY_ODD | UART_LCR_PARITY_EN),    /* Odd parity */
	UART_PARITY_EVEN     = (UART_LCR_PARITY_EVEN | UART_LCR_PARITY_EN),    /* Even parity */
	UART_PARITY_SP_1     = (UART_LCR_PARITY_SP_1 | UART_LCR_PARITY_EN),    /* Forced 1 stick parity */
	UART_PARITY_SP_0     = (UART_LCR_PARITY_SP_0 | UART_LCR_PARITY_EN)     /* Forced 0 stick parity */
} uart_parity_t;

typedef enum {
	UART0_NUM            = UART0,
	UART1_NUM            = UART1,
	UART2_NUM            = UART2,
	UART3_NUM            = UART3
} uart_num_t;

typedef enum {
	UART_NO_ERROR        = 0,
	UART_TIMEOUT_ERROR   = 1
} uart_error_t;

typedef enum {
	UART_RX_NO_DATA        = 0,
	UART_RX_DATA_READY     = 1,
	UART_RX_DATA_ERROR     = 2
} uart_rx_data_ready_t;

/* function prototypes */

BEGIN_DECLS

/* Init UART and set PLL1 as clock source (PCLK) */
void uart_init(uart_num_t uart_num,
               uart_databit_t data_nb_bits,
               uart_stopbit_t data_nb_stop,
               uart_parity_t data_parity,
               uint16_t uart_divisor,
               uint8_t uart_divaddval,
               uint8_t uart_mulval);

uart_rx_data_ready_t uart_rx_data_ready(uart_num_t uart_num);

uint8_t uart_read(uart_num_t uart_num);

uint8_t uart_read_timeout(uart_num_t uart_num, uint32_t rx_timeout_nb_cycles, uart_error_t* error);

void uart_write(uart_num_t uart_num, uint8_t data);

END_DECLS

#endif
