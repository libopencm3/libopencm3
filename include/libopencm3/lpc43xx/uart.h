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
//#define UART_ICR(port)                  MMIO32(port + 0x024)

/* Fractional Divider Register */
#define UART_FDR(port)                  MMIO32(port + 0x028)

/* Oversampling Register only for UART0/2/3 */
// #define UART_OSR(port)               MMIO32(port + 0x02C)

/* Transmit Enable Register Only for UART1 */
#define UART_TER_UART1(port)            MMIO32(port + 0x030)

/* Half-Duplex enable Register only for UART0/2/3 */
// #define UART_HDEN(port)                 MMIO32(port + 0x040)

/* Smart card Interface Register Only for UART0/2/3 */
//#define UART_SCICTRL(port)            MMIO32(port + 0x048)

/* RS-485/EIA-485 Control Register */
#define UART_RS485CTRL(port)            MMIO32(port + 0x04C)

/* RS-485/EIA-485 Address Match Register */
#define UART_RS485ADRMATCH(port)        MMIO32(port + 0x050)

/* RS-485/EIA-485 Direction Control Delay Register */
#define UART_RS485DLY(port)             MMIO32(port + 0x054)

/* Synchronous Mode Control Register only for UART0/2/3 */
//#define UART_SYNCCTRL(port)             MMIO32(port + 0x058)

/* Transmit Enable Register Only for UART0/2/3 */
#define UART_TER(port)                  MMIO32(port + 0x05C)

/* --------------------- BIT DEFINITIONS -------------------------------------- */
/***********************************************************************
* Macro defines for Macro defines for UARTn Receiver Buffer Register
**********************************************************************/
#define UART_RBR_MASKBIT                ((u8)0xFF)       /* UART Received Buffer mask bit (8 bits) */

/***********************************************************************
* Macro defines for Macro defines for UARTn Transmit Holding Register
**********************************************************************/
#define UART_THR_MASKBIT                ((u8)0xFF)       /* UART Transmit Holding mask bit (8 bits) */

/***********************************************************************
* Macro defines for Macro defines for UARTn Divisor Latch LSB register
**********************************************************************/
#define UART_LOAD_DLL(div)              ((div) & 0xFF)  /* Macro for loading least significant halfs of divisors */
#define UART_DLL_MASKBIT                ((u8)0xFF)      /* Divisor latch LSB bit mask */

/***********************************************************************
* Macro defines for Macro defines for UARTn Divisor Latch MSB register
**********************************************************************/
#define UART_DLM_MASKBIT                ((u8)0xFF)              /* Divisor latch MSB bit mask */
#define UART_LOAD_DLM(div)              (((div) >> 8) & 0xFF)   /* Macro for loading most significant halfs of divisors */

/***********************************************************************
* Macro defines for Macro defines for UART interrupt enable register
**********************************************************************/
#define UART_IER_RBRINT_EN              ((u32)(BIT0))  /* RBR Interrupt enable*/
#define UART_IER_THREINT_EN             ((u32)(BIT1))  /* THR Interrupt enable*/
#define UART_IER_RLSINT_EN              ((u32)(BIT2))  /* RX line status interrupt enable*/
#define UART1_IER_MSINT_EN              ((u32)(BIT3))  /* Modem status interrupt enable */
#define UART1_IER_CTSINT_EN             ((u32)(BIT7))  /* CTS1 signal transition interrupt enable */
#define UART_IER_ABEOINT_EN             ((u32)(BIT8))  /* Enables the end of auto-baud interrupt */
#define UART_IER_ABTOINT_EN             ((u32)(BIT9))  /* Enables the auto-baud time-out interrupt */
#define UART_IER_BITMASK                ((u32)(0x307)) /* UART interrupt enable register bit mask */
#define UART1_IER_BITMASK               ((u32)(0x38F)) /* UART1 interrupt enable register bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART interrupt identification register
**********************************************************************/
#define UART_IIR_INTSTAT_PEND           ((u32)(BIT0))  /* Interrupt Status - Active low */
#define UART_IIR_INTID_RDA              ((u32)(2<<1))  /* Interrupt identification: Receive data available*/
#define UART_IIR_INTID_RLS              ((u32)(3<<1))  /* Interrupt identification: Receive line status*/
#define UART_IIR_INTID_CTI              ((u32)(6<<1))  /* Interrupt identification: Character time-out indicator*/
#define UART_IIR_INTID_THRE             ((u32)(BIT1))  /* Interrupt identification: THRE interrupt*/
#define UART1_IIR_INTID_MODEM           ((u32)(0<<1))  /* Interrupt identification: Modem interrupt*/
#define UART_IIR_INTID_MASK             ((u32)(7<<1))  /* Interrupt identification: Interrupt ID mask */
#define UART_IIR_FIFO_EN                ((u32)(3<<6))  /* These bits are equivalent to UnFCR[0] */
#define UART_IIR_ABEO_INT               ((u32)(BIT8))  /* End of auto-baud interrupt */
#define UART_IIR_ABTO_INT               ((u32)(BIT9))  /* Auto-baud time-out interrupt */
#define UART_IIR_BITMASK                ((u32)(0x3CF)) /* UART interrupt identification register bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART FIFO control register
**********************************************************************/
#define UART_FCR_FIFO_EN                ((u8)(BIT0)) /* UART FIFO enable */
#define UART_FCR_RX_RS                  ((u8)(BIT1)) /* UART FIFO RX reset */
#define UART_FCR_TX_RS                  ((u8)(BIT2)) /* UART FIFO TX reset */
#define UART_FCR_DMAMODE_SEL            ((u8)(BIT3)) /* UART DMA mode selection */
#define UART_FCR_TRG_LEV0               ((u8)(0))    /* UART FIFO trigger level 0: 1 character */
#define UART_FCR_TRG_LEV1               ((u8)(BIT6)) /* UART FIFO trigger level 1: 4 character */
#define UART_FCR_TRG_LEV2               ((u8)(2<<6)) /* UART FIFO trigger level 2: 8 character */
#define UART_FCR_TRG_LEV3               ((u8)(3<<6)) /* UART FIFO trigger level 3: 14 character */
#define UART_FCR_BITMASK                ((u8)(0xCF)) /* UART FIFO control bit mask */
#define UART_TX_FIFO_SIZE               (16)

/**********************************************************************
* Macro defines for Macro defines for UART line control register
**********************************************************************/
#define UART_LCR_WLEN5                  ((u8)(0))    /* UART 5 bit data mode */
#define UART_LCR_WLEN6                  ((u8)(1))    /* UART 6 bit data mode */
#define UART_LCR_WLEN7                  ((u8)(2))    /* UART 7 bit data mode */
#define UART_LCR_WLEN8                  ((u8)(3))    /* UART 8 bit data mode */
#define UART_LCR_ONE_STOPBIT            ((u8)(0))    /* UART One Stop Bits */
#define UART_LCR_TWO_STOPBIT            ((u8)(BIT2)) /* UART Two Stop Bits */
#define UART_LCR_NO_PARITY              ((u8)(0))    /* UART Parity Disabled / No Parity */
#define UART_LCR_PARITY_EN              ((u8)(BIT3)) /* UART Parity Enable */
#define UART_LCR_PARITY_ODD             ((u8)(0))    /* UART Odd Parity Select */
#define UART_LCR_PARITY_EVEN            ((u8)(BIT4)) /* UART Even Parity Select */
#define UART_LCR_PARITY_SP_1             ((u8)(0x20)) /* UART force 1 stick parity */
#define UART_LCR_PARITY_SP_0             ((u8)(0x30)) /* UART force 0 stick parity */
#define UART_LCR_BREAK_EN               ((u8)(BIT6)) /* UART Transmission Break enable */
#define UART_LCR_DLAB_EN                ((u8)(BIT7)) /* UART Divisor Latches Access bit enable */
#define UART_LCR_BITMASK                ((u8)(0xFF)) /* UART line control bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART line status register
**********************************************************************/
#define UART_LSR_RDR                    ((u8)(BIT0)) /* Line status register: Receive data ready */
#define UART_LSR_OE                     ((u8)(BIT1)) /* Line status register: Overrun error */
#define UART_LSR_PE                     ((u8)(BIT2)) /* Line status register: Parity error */
#define UART_LSR_FE                     ((u8)(BIT3)) /* Line status register: Framing error */
#define UART_LSR_BI                     ((u8)(BIT4)) /* Line status register: Break interrupt */
#define UART_LSR_THRE                   ((u8)(BIT5)) /* Line status register: Transmit holding register empty */
#define UART_LSR_TEMT                   ((u8)(BIT6)) /* Line status register: Transmitter empty */
#define UART_LSR_RXFE                   ((u8)(BIT7)) /* Error in RX FIFO */
#define UART_LSR_BITMASK                ((u8)(0xFF)) /* UART Line status bit mask */
#define UART_LSR_ERROR_MASK				(UART_LSR_OE|UART_LSR_PE|UART_LSR_FE|UART_LSR_BI|UART_LSR_RXFE)

/**********************************************************************
* Macro defines for Macro defines for UART Scratch Pad Register
**********************************************************************/
#define UART_SCR_BIMASK           ((u8)(0xFF))    /* UART Scratch Pad bit mask */

/***********************************************************************
* Macro defines for Macro defines for UART Auto baudrate control register
**********************************************************************/
#define UART_ACR_START                  ((u32)(BIT0))    /* UART Auto-baud start */
#define UART_ACR_MODE                   ((u32)(BIT1))    /* UART Auto baudrate Mode 1 */
#define UART_ACR_AUTO_RESTART           ((u32)(BIT2))    /* UART Auto baudrate restart */
#define UART_ACR_ABEOINT_CLR            ((u32)(BIT8))    /* UART End of auto-baud interrupt clear */
#define UART_ACR_ABTOINT_CLR            ((u32)(BIT9))    /* UART Auto-baud time-out interrupt clear */
#define UART_ACR_BITMASK                ((u32)(0x307))   /* UART Auto Baudrate register bit mask */

/*********************************************************************
* Macro defines for Macro defines for UART IrDA control register
**********************************************************************/
#define UART_ICR_IRDAEN                 ((u32)(BIT0))            /* IrDA mode enable */
#define UART_ICR_IRDAINV                ((u32)(BIT1))            /* IrDA serial input inverted */
#define UART_ICR_FIXPULSE_EN            ((u32)(BIT2))            /* IrDA fixed pulse width mode */
#define UART_ICR_PULSEDIV(n)            ((u32)((n&0x07)<<3))     /* PulseDiv - Configures the pulse when FixPulseEn = 1 */
#define UART_ICR_BITMASK                ((u32)(0x3F))            /* UART IRDA bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART half duplex register
**********************************************************************/
#define UART_HDEN_HDEN                  ((u32)(BIT0))            /* enable half-duplex mode*/

/**********************************************************************
* Macro defines for Macro defines for UART smart card interface control register
**********************************************************************/
#define UART_SCICTRL_SCIEN              ((u32)(BIT0))           /* enable asynchronous half-duplex smart card interface*/
#define UART_SCICTRL_NACKDIS            ((u32)(BIT1))           /* NACK response is inhibited*/
#define UART_SCICTRL_PROTSEL_T1         ((u32)(BIT2))           /* ISO7816-3 protocol T1 is selected*/
#define UART_SCICTRL_TXRETRY(n)         ((u32)((n&0x07)<<5))    /* number of retransmission*/
#define UART_SCICTRL_GUARDTIME(n)       ((u32)((n&0xFF)<<8))    /* Extra guard time*/

/*********************************************************************
* Macro defines for Macro defines for UART synchronous control register
**********************************************************************/
#define UART_SYNCCTRL_SYNC              ((u32)(BIT0))   /* enable synchronous mode*/
#define UART_SYNCCTRL_CSRC_MASTER       ((u32)(BIT1))   /* synchronous master mode*/
#define UART_SYNCCTRL_FES               ((u32)(BIT2))   /* sample on falling edge*/
#define UART_SYNCCTRL_TSBYPASS          ((u32)(BIT3))   /* to be defined*/
#define UART_SYNCCTRL_CSCEN             ((u32)(BIT4))   /* continuous running clock enable (master mode only) */
#define UART_SYNCCTRL_NOSTARTSTOP       ((u32)(BIT5))   /* Do not send start/stop bit */
#define UART_SYNCCTRL_CCCLR             ((u32)(BIT6))   /* stop continuous clock */

/*********************************************************************
* Macro defines for Macro defines for UART Fractional divider register
**********************************************************************/
#define UART_FDR_DIVADDVAL(n)           ((u32)(n&0x0F))         /* Baud-rate generation pre-scaler divisor */
#define UART_FDR_MULVAL(n)              ((u32)((n<<4)&0xF0))    /* Baud-rate pre-scaler multiplier value */
#define UART_FDR_BITMASK                ((u32)(0xFF))           /* UART Fractional Divider register bit mask */

/*********************************************************************
* Macro defines for Macro defines for UART Tx Enable register
**********************************************************************/
#define UART1_TER_TXEN                  ((u8)(BIT7))    /* Transmit enable bit */
#define UART1_TER_BITMASK               ((u8)(0x80))    /* UART Transmit Enable Register bit mask */

#define UART0_2_3_TER_TXEN              ((u8)(BIT0))    /* Transmit enable bit */
#define UART0_2_3_TER_BITMASK           ((u8)(0x01))    /* UART Transmit Enable Register bit mask */

/**********************************************************************
* Macro defines for Macro defines for UART FIFO Level register
**********************************************************************/
#define UART_FIFOLVL_RX(n)              ((u32)(n&0x0F))        /* Reflects the current level of the UART receiver FIFO */
#define UART_FIFOLVL_TX(n)              ((u32)((n>>8)&0x0F))   /* Reflects the current level of the UART transmitter FIFO */
#define UART_FIFOLVL_BITMASK            ((u32)(0x0F0F))        /* UART FIFO Level Register bit mask */

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
               u16 uart_divisor,
               u8 uart_divaddval,
               u8 uart_mulval);

uart_rx_data_ready_t uart_rx_data_ready(uart_num_t uart_num);

u8 uart_read(uart_num_t uart_num);

u8 uart_read_timeout(uart_num_t uart_num, u32 rx_timeout_nb_cycles, uart_error_t* error);

void uart_write(uart_num_t uart_num, u8 data);

END_DECLS

#endif
