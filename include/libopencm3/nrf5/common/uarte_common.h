/** @addtogroup uarte_defines UARTE Defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2018 
 * Gerrit Maus <funk@maus.xyz>, Luong Le <novercy@live.com>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Gerrit Maus <funk@maus.xyz>, Luong Le <novercy@live.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA UARTE.H
The order of header inclusion is important. uarte.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_UARTE_H)
/** @endcond */
#ifndef LIBOPENCM3_UARTE_COMMON_H
#define LIBOPENCM3_UARTE_COMMON_H

/**@{*/
/** @defgroup uarte_reg_base UARTE register base addresses
 * @ingroup uarte_defines
 * @{
 */
#define UARTE0                     UARTE0_BASE
/**@}*/

/** @defgroup uarte_registers UARTE Registers
 * @ingroup uarte_defines
 * @brief UARTE Registers
@{*/
/* --------------------- UARTE registers for NRF52 ------------------------- */

/* Tasks Registers */
#define UART_TASKS_STARTRX(uart_base)          MMIO32((uart_base) + 0x000)
#define UARTE_TASKS_STARTRX(uart_base)         MMIO32((uart_base) + 0x000)
#define UARTE0_TASKS_STARTRX                   MMIO32((UARTE0) + 0x000)    

#define UART_TASKS_STOPRX(uart_base)           MMIO32((uart_base) + 0x004)
#define UARTE_TASKS_STOPRX(uart_base)          MMIO32((uart_base) + 0x004)
#define UARTE0_TASKS_STOPRX                    MMIO32((UARTE0) + 0x004)    

#define UART_TASKS_STARTTX(uart_base)          MMIO32((uart_base) + 0x008)
#define UARTE_TASKS_STARTTX(uart_base)         MMIO32((uart_base) + 0x008)
#define UARTE0_TASKS_STARTTX                   MMIO32((UARTE0) + 0x008)    

#define UART_TASKS_STOPTX(uart_base)           MMIO32((uart_base) + 0x00C)
#define UARTE_TASKS_STOPTX(uart_base)          MMIO32((uart_base) + 0x00C)
#define UARTE0_TASKS_STOPTX                    MMIO32((UARTE0) + 0x00C)    

#define UART_TASKS_FLUSHRX(uart_base)          MMIO32((uart_base) + 0x02C)
#define UARTE_TASKS_FLUSHRX(uart_base)         MMIO32((uart_base) + 0x02C)
#define UARTE0_TASKS_FLUSHRX                   MMIO32((UARTE0) + 0x02C)

/* Events Registers */
#define UART_EVENTS_CTS(uart_base)             MMIO32((uart_base) + 0x100)
#define UARTE_EVENTS_CTS(uart_base)            MMIO32((uart_base) + 0x100)
#define UARTE0_EVENTS_CTS                      MMIO32((UARTE0) + 0x100)

#define UART_EVENTS_NCTS(uart_base)            MMIO32((uart_base) + 0x104)
#define UARTE_EVENTS_NCTS(uart_base)           MMIO32((uart_base) + 0x104)
#define UARTE0_EVENTS_NCTS                     MMIO32((UARTE0) + 0x104)

#define UART_EVENTS_RXDRDY(uart_base)          MMIO32((uart_base) + 0x108)
#define UARTE_EVENTS_RXDRDY(uart_base)         MMIO32((uart_base) + 0x108)
#define UARTE0_EVENTS_RXDRDY                   MMIO32((UARTE0) + 0x108)

#define UART_EVENTS_ENDRX(uart_base)           MMIO32((uart_base) + 0x110)
#define UARTE_EVENTS_ENDRX(uart_base)          MMIO32((uart_base) + 0x110)
#define UARTE0_EVENTS_ENDRX                    MMIO32((UARTE0) + 0x110)

#define UART_EVENTS_TXDRDY(uart_base)          MMIO32((uart_base) + 0x11C)
#define UARTE_EVENTS_TXDRDY(uart_base)         MMIO32((uart_base) + 0x11C)
#define UARTE0_EVENTS_TXDRDY                   MMIO32((UARTE0) + 0x11C)

#define UART_EVENTS_ENDTX(uart_base)           MMIO32((uart_base) + 0x120)
#define UARTE_EVENTS_ENDTX(uart_base)          MMIO32((uart_base) + 0x120)
#define UARTE0_EVENTS_ENDTX                    MMIO32((UARTE0) + 0x120)

#define UART_EVENTS_ERROR(uart_base)           MMIO32((uart_base) + 0x124)
#define UARTE_EVENTS_ERROR(uart_base)          MMIO32((uart_base) + 0x124)
#define UARTE0_EVENTS_ERROR                    MMIO32((UARTE0) + 0x124)

#define UART_EVENTS_RXTO(uart_base)            MMIO32((uart_base) + 0x144)
#define UARTE_EVENTS_RXTO(uart_base)           MMIO32((uart_base) + 0x144)
#define UARTE0_EVENTS_RXTO                     MMIO32((UARTE0) + 0x144)

#define UART_EVENTS_RXSTARTED(uart_base)       MMIO32((uart_base) + 0x14C)
#define UARTE_EVENTS_RXSTARTED(uart_base)      MMIO32((uart_base) + 0x14C)
#define UARTE0_EVENTS_RXSTARTED                MMIO32((UARTE0) + 0x14C)

#define UART_EVENTS_TXSTARTED(uart_base)       MMIO32((uart_base) + 0x150)
#define UARTE_EVENTS_TXSTARTED(uart_base)      MMIO32((uart_base) + 0x150)
#define UARTE0_EVENTS_TXSTARTED                MMIO32((UARTE0) + 0x150)

#define UART_EVENTS_TXSTOPPED(uart_base)       MMIO32((uart_base) + 0x158)
#define UARTE_EVENTS_TXSTOPPED(uart_base)      MMIO32((uart_base) + 0x158)
#define UARTE0_EVENTS_TXSTOPPED                MMIO32((UARTE0) + 0x158)

/* Registers */
#define UART_SHORTS(uart_base)                 MMIO32((uart_base) + 0x200)
#define UARTE_SHORTS(uart_base)                MMIO32((uart_base) + 0x200)
#define UARTE0_SHORTS                          MMIO32((UARTE0) + 0x200)

#define UART_INTEN(uart_base)                  MMIO32((uart_base) + 0x300)
#define UARTE_INTEN(uart_base)                 MMIO32((uart_base) + 0x300)
#define UARTE0_INTEN                           MMIO32((UARTE0) + 0x300)

#define UART_INTENSET(uart_base)               MMIO32((uart_base) + 0x304)
#define UARTE_INTENSET(uart_base)              MMIO32((uart_base) + 0x304)
#define UARTE0_INTENSET                        MMIO32((UARTE0) + 0x304)

#define UART_INTENCLR(uart_base)               MMIO32((uart_base) + 0x308)
#define UARTE_INTENCLR(uart_base)              MMIO32((uart_base) + 0x308)
#define UARTE0_INTENCLR                        MMIO32((UARTE0) + 0x308)

#define UART_ERRORSRC(uart_base)               MMIO32((uart_base) + 0x480)
#define UARTE_ERRORSRC(uart_base)              MMIO32((uart_base) + 0x480)
#define UARTE0_ERRORSRC                        MMIO32((UARTE0) + 0x480)

#define UART_ENABLE(uart_base)                 MMIO32((uart_base) + 0x500)
#define UARTE_ENABLE(uart_base)                MMIO32((uart_base) + 0x500)
#define UARTE0_ENABLE                          MMIO32((UARTE0) + 0x500)


struct UARTE_PSEL_TYPE{
	uint32_t RTS;
	uint32_t TXD;
	uint32_t CTS;
	uint32_t RXD;
};
#define UARTE0_PSEL     (*(volatile struct UARTE_PSEL_TYPE*)((UARTE0) + 0x508))
#define UARTE_PSEL(uart_base)     (*(volatile struct UARTE_PSEL_TYPE*)((uart_base) + 0x508))

#define UART_PSEL_RTS(uart_base)               MMIO32((uart_base) + 0x508)
#define UARTE_PSEL_RTS(uart_base)              MMIO32((uart_base) + 0x508)
#define UARTE0_PSEL_RTS                        MMIO32((UARTE0) + 0x508)

#define UART_PSEL_TXD(uart_base)               MMIO32((uart_base) + 0x50C)
#define UARTE_PSEL_TXD(uart_base)              MMIO32((uart_base) + 0x50C)
#define UARTE0_PSEL_TXD                        MMIO32((UARTE0) + 0x50C)

#define UART_PSEL_CTS(uart_base)               MMIO32((uart_base) + 0x510)
#define UARTE_PSEL_CTS(uart_base)              MMIO32((uart_base) + 0x510)
#define UARTE0_PSEL_CTS                        MMIO32((UARTE0) + 0x510)

#define UART_PSEL_RXD(uart_base)               MMIO32((uart_base) + 0x514)
#define UARTE_PSEL_RXD(uart_base)              MMIO32((uart_base) + 0x514)
#define UARTE0_PSEL_RXD                        MMIO32((UARTE0) + 0x514)

#define UART_BAUDRATE(uart_base)               MMIO32((uart_base) + 0x524)
#define UARTE_BAUDRATE(uart_base)              MMIO32((uart_base) + 0x524)
#define UARTE0_BAUDRATE                        MMIO32((UARTE0) + 0x524)


struct UARTE0_RXD_TYPE{
	uint32_t PTR;
	uint32_t MAXCNT;
	uint32_t AMOUNT;
};
#define UARTE0_RXD      (*(volatile struct UARTE0_RXD_TYPE*)((UARTE0) + 0x534))
#define UARTE_RXD(uart_base)      (*(volatile struct UARTE0_RXD_TYPE*)((uart_base) + 0x534))

#define UART_RXD_PTR(uart_base)                MMIO32((uart_base) + 0x534)
#define UARTE_RXD_PTR(uart_base)               MMIO32((uart_base) + 0x534)
#define UARTE0_RXD_PTR                         MMIO32((UARTE0) + 0x534)    

#define UART_RXD_MAXCNT(uart_base)             MMIO32((uart_base) + 0x538)
#define UARTE_RXD_MAXCNT(uart_base)            MMIO32((uart_base) + 0x538)
#define UARTE0_RXD_MAXCNT                      MMIO32((UARTE0) + 0x538)    

#define UART_RXD_AMOUNT(uart_base)             MMIO32((uart_base) + 0x53C)
#define UARTE_RXD_AMOUNT(uart_base)            MMIO32((uart_base) + 0x53C)
#define UARTE0_RXD_AMOUNT                      MMIO32((UARTE0) + 0x53C)    


struct UARTE0_TXD_TYPE{
	uint32_t PTR;
	uint32_t MAXCNT;
	uint32_t AMOUNT;
};
#define UARTE0_TXD      (*(volatile struct UARTE0_TXD_TYPE*)((UARTE0) + 0x544))
#define UARTE_TXD(uart_base)      (*(volatile struct UARTE0_TXD_TYPE*)((uart_base) + 0x544))

#define UART_TXD_PTR(uart_base)                MMIO32((uart_base) + 0x544)
#define UARTE_TXD_PTR(uart_base)               MMIO32((uart_base) + 0x544)
#define UARTE0_TXD_PTR                         MMIO32((UARTE0) + 0x544)    

#define UART_TXD_MAXCNT(uart_base)             MMIO32((uart_base) + 0x548)
#define UARTE_TXD_MAXCNT(uart_base)            MMIO32((uart_base) + 0x548)
#define UARTE0_TXD_MAXCNT                      MMIO32((UARTE0) + 0x548)    

#define UART_TXD_AMOUNT(uart_base)             MMIO32((uart_base) + 0x54C)
#define UARTE_TXD_AMOUNT(uart_base)            MMIO32((uart_base) + 0x54C)
#define UARTE0_TXD_AMOUNT                      MMIO32((UARTE0) + 0x54C)

#define UART_CONFIG(uart_base)                 MMIO32((uart_base) + 0x56C)
#define UARTE_CONFIG(uart_base)                MMIO32((uart_base) + 0x56C)
#define UARTE0_CONFIG                          MMIO32((UARTE0) + 0x56C)
/**@}*/

/* --- UARTE_SHORTS values ------------------------------------------------- */
/** @defgroup uarte_shorts Set shortcut between ENDRX-STARTRX and ENDRX-STOPRX
@ingroup uarte_defines
@{*/
#define UARTE_SHORTS_ENDRX_STARTRX_DISABLED             (0 << 5)
#define UARTE_SHORTS_ENDRX_STARTRX_Disabled             (0 << 5)
#define UARTE_SHORTS_ENDRX_STARTRX_ENABLED              (1 << 5)
#define UARTE_SHORTS_ENDRX_STARTRX_Enabled              (1 << 5)
#define UARTE_SHORTS_ENDRX_STOPRX_DISABLED              (0 << 6)
#define UARTE_SHORTS_ENDRX_STOPRX_Disabled              (0 << 6)
#define UARTE_SHORTS_ENDRX_STOPRX_ENABLED               (1 << 6)
#define UARTE_SHORTS_ENDRX_STOPRX_Enabled               (1 << 6)
/**@}*/

/* --- UARTE_INTEN values -------------------------------------------------- */
/** @defgroup uarte_inten Enable or disable interrupt
@ingroup uarte_defines
@{*/
#define UARTE_INTEN_CTS_ENABLE                 (1 << 0)
#define UARTE_INTEN_NCTS_ENABLE                (1 << 1)    
#define UARTE_INTEN_RXDRDY_ENABLE              (1 << 2)    
#define UARTE_INTEN_ENDRX_ENABLE               (1 << 4)
#define UARTE_INTEN_TXDRDY_ENABLE              (1 << 7)
#define UARTE_INTEN_ENDTX_ENABLE               (1 << 8)
#define UARTE_INTEN_ERROR_ENABLE               (1 << 9)    
#define UARTE_INTEN_RXTO_ENABLE                (1 << 17)
#define UARTE_INTEN_RXSTARTED_ENABLE           (1 << 19)
#define UARTE_INTEN_TXSTARTED_ENABLE           (1 << 20)
#define UARTE_INTEN_TXSTOPPED_ENABLE           (1 << 22)
/**@}*/

/* ------------------------------------------------------------------------- */
/* Events interrupt definitions (for convenience) */
/** @defgroup uarte_events_interrupt UARTE Events Identifiers for interrupt
@ingroup uarte_defines
@{*/
#define CTS                                    (1 << 0)
#define NCTS                                   (1 << 1)    
#define RXDRDY                                 (1 << 2)
#define ENDRX                                  (1 << 4)    
#define TXDRDY                                 (1 << 7)
#define ENDTX                                  (1 << 8)    
#define ERROR                                  (1 << 9)    
#define RXTO                                   (1 << 17)    
#define RXSTARTED                              (1 << 19)
#define TXSTARTED                              (1 << 20)
#define TXSTOPPED                              (1 << 22)
/**@}*/

/* --- UARTE_INTENSET values ----------------------------------------------- */
/** @defgroup uarte_intenset Enable interrupt
@ingroup uarte_defines
@{*/
#define UARTE_INTENSET_CTS_ENABLED             (1 << 0)
#define UARTE_INTENSET_CTS_Enabled             (1 << 0)
#define UARTE_INTENSET_CTS_SET                 (1 << 0)
#define UARTE_INTENSET_CTS_Set                 (1 << 0)
#define UARTE_INTENSET_NCTS_ENABLED            (1 << 1)
#define UARTE_INTENSET_NCTS_Enabled            (1 << 1)
#define UARTE_INTENSET_NCTS_SET                (1 << 1)
#define UARTE_INTENSET_NCTS_Set                (1 << 1)
#define UARTE_INTENSET_RXDRDY_ENABLED          (1 << 2)
#define UARTE_INTENSET_RXDRDY_Enabled          (1 << 2)
#define UARTE_INTENSET_RXDRDY_SET              (1 << 2)
#define UARTE_INTENSET_RXDRDY_Set              (1 << 2)
#define UARTE_INTENSET_ENDRX_ENABLED           (1 << 4)
#define UARTE_INTENSET_ENDRX_Enabled           (1 << 4)
#define UARTE_INTENSET_ENDRX_SET               (1 << 4)
#define UARTE_INTENSET_ENDRX_Set               (1 << 4)
#define UARTE_INTENSET_TXDRDY_ENABLED          (1 << 7)
#define UARTE_INTENSET_TXDRDY_Enabled          (1 << 7)
#define UARTE_INTENSET_TXDRDY_SET              (1 << 7)
#define UARTE_INTENSET_TXDRDY_Set              (1 << 7)
#define UARTE_INTENSET_ENDTX_ENABLED           (1 << 8)
#define UARTE_INTENSET_ENDTX_Enabled           (1 << 8)
#define UARTE_INTENSET_ENDTX_SET               (1 << 8)
#define UARTE_INTENSET_ENDTX_Set               (1 << 8)
#define UARTE_INTENSET_ERROR_ENABLED           (1 << 9)
#define UARTE_INTENSET_ERROR_Enabled           (1 << 9)
#define UARTE_INTENSET_ERROR_SET               (1 << 9)
#define UARTE_INTENSET_ERROR_Set               (1 << 9)
#define UARTE_INTENSET_RXTO_ENABLED            (1 << 17)
#define UARTE_INTENSET_RXTO_Enabled            (1 << 17)
#define UARTE_INTENSET_RXTO_SET                (1 << 17)
#define UARTE_INTENSET_RXTO_Set                (1 << 17)
#define UARTE_INTENSET_RXSTARTED_ENABLED       (1 << 19)
#define UARTE_INTENSET_RXSTARTED_Enabled       (1 << 19)
#define UARTE_INTENSET_RXSTARTED_SET           (1 << 19)
#define UARTE_INTENSET_RXSTARTED_Set           (1 << 19)
#define UARTE_INTENSET_TXSTARTED_ENABLED       (1 << 20)
#define UARTE_INTENSET_TXSTARTED_Enabled       (1 << 20)
#define UARTE_INTENSET_TXSTARTED_SET           (1 << 20)
#define UARTE_INTENSET_TXSTARTED_Set           (1 << 20)
#define UARTE_INTENSET_TXSTOPPED_ENABLED       (1 << 22)
#define UARTE_INTENSET_TXSTOPPED_Enabled       (1 << 22)
#define UARTE_INTENSET_TXSTOPPED_SET           (1 << 22)
#define UARTE_INTENSET_TXSTOPPED_Set           (1 << 22)
/**@}*/

/* --- UARTE_INTENCLR values ----------------------------------------------- */
/** @defgroup uarte_intenclr Disable interrupt
@ingroup uarte_defines
@{*/
#define UARTE_INTENCLR_CTS_ENABLE              (1 << 0)
#define UARTE_INTENCLR_NCTS_ENABLE             (1 << 1)    
#define UARTE_INTENCLR_RXDRDY_ENABLE           (1 << 2)
#define UARTE_INTENCLR_ENDRX_ENABLE            (1 << 4)    
#define UARTE_INTENCLR_TXDRDY_ENABLE           (1 << 7)
#define UARTE_INTENCLR_ENDTX_ENABLE            (1 << 8)    
#define UARTE_INTENCLR_ERROR_ENABLE            (1 << 9)    
#define UARTE_INTENCLR_RXTO_ENABLE             (1 << 17)    
#define UARTE_INTENCLR_RXSTARTED_ENABLE        (1 << 19)
#define UARTE_INTENCLR_TXSTARTED_ENABLE        (1 << 20)
#define UARTE_INTENCLR_TXSTOPPED_ENABLE        (1 << 22)

#define UARTE_INTENCLR_CTS_ENABLED             (1 << 0)
#define UARTE_INTENCLR_CTS_Enabled             (1 << 0)
#define UARTE_INTENCLR_CTS_CLEAR               (1 << 0)
#define UARTE_INTENCLR_CTS_Clear               (1 << 0)
#define UARTE_INTENCLR_NCTS_ENABLED            (1 << 1)
#define UARTE_INTENCLR_NCTS_Enabled            (1 << 1)
#define UARTE_INTENCLR_NCTS_CLEAR              (1 << 1)
#define UARTE_INTENCLR_NCTS_Clear              (1 << 1)
#define UARTE_INTENCLR_RXDRDY_ENABLED          (1 << 2)
#define UARTE_INTENCLR_RXDRDY_Enabled          (1 << 2)
#define UARTE_INTENCLR_RXDRDY_CLEAR            (1 << 2)
#define UARTE_INTENCLR_RXDRDY_Clear            (1 << 2)
#define UARTE_INTENCLR_ENDRX_ENABLED           (1 << 4)
#define UARTE_INTENCLR_ENDRX_Enabled           (1 << 4)
#define UARTE_INTENCLR_ENDRX_CLEAR             (1 << 4)
#define UARTE_INTENCLR_ENDRX_Clear             (1 << 4)
#define UARTE_INTENCLR_TXDRDY_ENABLED          (1 << 7)
#define UARTE_INTENCLR_TXDRDY_Enabled          (1 << 7)
#define UARTE_INTENCLR_TXDRDY_CLEAR            (1 << 7)
#define UARTE_INTENCLR_TXDRDY_Clear            (1 << 7)
#define UARTE_INTENCLR_ENDTX_ENABLED           (1 << 8)
#define UARTE_INTENCLR_ENDTX_Enabled           (1 << 8)
#define UARTE_INTENCLR_ENDTX_CLEAR             (1 << 8)
#define UARTE_INTENCLR_ENDTX_Clear             (1 << 8)
#define UARTE_INTENCLR_ERROR_ENABLED           (1 << 9)
#define UARTE_INTENCLR_ERROR_Enabled           (1 << 9)
#define UARTE_INTENCLR_ERROR_CLEAR             (1 << 9)
#define UARTE_INTENCLR_ERROR_Clear             (1 << 9)
#define UARTE_INTENCLR_RXTO_ENABLED            (1 << 17)
#define UARTE_INTENCLR_RXTO_Enabled            (1 << 17)
#define UARTE_INTENCLR_RXTO_CLEAR              (1 << 17)
#define UARTE_INTENCLR_RXTO_Clear              (1 << 17)
#define UARTE_INTENCLR_RXSTARTED_ENABLED       (1 << 19)
#define UARTE_INTENCLR_RXSTARTED_Enabled       (1 << 19)
#define UARTE_INTENCLR_RXSTARTED_CLEAR         (1 << 19)
#define UARTE_INTENCLR_RXSTARTED_Clear         (1 << 19)
#define UARTE_INTENCLR_TXSTARTED_ENABLED       (1 << 20)
#define UARTE_INTENCLR_TXSTARTED_Enabled       (1 << 20)
#define UARTE_INTENCLR_TXSTARTED_CLEAR         (1 << 20)
#define UARTE_INTENCLR_TXSTARTED_Clear         (1 << 20)
#define UARTE_INTENCLR_TXSTOPPED_ENABLED       (1 << 22)
#define UARTE_INTENCLR_TXSTOPPED_Enabled       (1 << 22)
#define UARTE_INTENCLR_TXSTOPPED_CLEAR         (1 << 22)
#define UARTE_INTENCLR_TXSTOPPED_Clear         (1 << 22)
/**@}*/

/* --- UARTE_ERRORSRC values ----------------------------------------------- */
/** @defgroup uarte_errorsrc Error source
@ingroup uarte_defines
@{*/
#define UARTE_ERRORSRC_OVERRUN_NOTPRESENT                 (0 << 0)
#define UARTE_ERRORSRC_OVERRUN_NotPresent                 (0 << 0)
#define UARTE_ERRORSRC_OVERRUN_PRESENT                    (1 << 0)
#define UARTE_ERRORSRC_OVERRUN_Present                    (1 << 0)
#define UARTE_ERRORSRC_PARITY_NOTPRESENT                  (0 << 1)
#define UARTE_ERRORSRC_PARITY_NotPresent                  (0 << 1)
#define UARTE_ERRORSRC_PARITY_PRESENT                     (1 << 1)
#define UARTE_ERRORSRC_PARITY_Present                     (1 << 1)
#define UARTE_ERRORSRC_FRAMING_NOTPRESENT                 (0 << 2)
#define UARTE_ERRORSRC_FRAMING_NotPresent                 (0 << 2)
#define UARTE_ERRORSRC_FRAMING_PRESENT                    (1 << 2)
#define UARTE_ERRORSRC_FRAMING_Present                    (1 << 2)
#define UARTE_ERRORSRC_BREAK_NOTPRESENT                   (0 << 3)
#define UARTE_ERRORSRC_BREAK_NotPresent                   (0 << 3)
#define UARTE_ERRORSRC_BREAK_PRESENT                      (1 << 3)
#define UARTE_ERRORSRC_BREAK_Present                      (1 << 3)
/**@}*/

/* --- UARTE_ENABLE values ------------------------------------------------- */
/** @defgroup uarte_enable Enable UARTE
@ingroup uarte_defines
@{*/
#define UARTE_ENABLE_ENABLE_DISABLED                   (0)
#define UARTE_ENABLE_ENABLE_Disabled                   (0)
#define UARTE_ENABLE_ENABLE_ENABLED                    (8)
#define UARTE_ENABLE_ENABLE_Enabled                    (8)
/**@}*/

/* --- UARTE_PSEL.RTS values ----------------------------------------------- */
/** @defgroup uarte_psel_rts Select pin for RTS signal
@ingroup uarte_defines
@{*/
#define UARTE_PSEL_RTS_PIN(pin)                        (pin)
#define UARTE_PSEL_RTS_CONNECT_CONNECTED               (0 << 31)
#define UARTE_PSEL_RTS_CONNECT_Connected               (0 << 31)
#define UARTE_PSEL_RTS_CONNECT_DISCONNECTED            (1 << 31)    
#define UARTE_PSEL_RTS_CONNECT_Disconnected            (1 << 31)
/**@}*/

/* --- UARTE_PSEL.TXD values ----------------------------------------------- */
/** @defgroup uarte_psel_txd Select pin for TXD signal
@ingroup uarte_defines
@{*/
#define UARTE_PSEL_TXD_PIN(pin)                        (pin)
#define UARTE_PSEL_TXD_CONNECT_CONNECTED               (0 << 31)
#define UARTE_PSEL_TXD_CONNECT_Connected               (0 << 31)
#define UARTE_PSEL_TXD_CONNECT_DISCONNECT              (1 << 31)
#define UARTE_PSEL_TXD_CONNECT_Disconnected            (1 << 31)
/**@}*/

/* --- UARTE_PSEL.CTS values ----------------------------------------------- */
/** @defgroup uarte_psel_cts Select pin for CTS signal
@ingroup uarte_defines
@{*/
#define UARTE_PSEL_CTS_PIN(pin)                        (pin)
#define UARTE_PSEL_CTS_CONNECT_CONNECTED               (0 << 31)
#define UARTE_PSEL_CTS_CONNECT_Connected               (0 << 31)
#define UARTE_PSEL_CTS_CONNECT_DISCONNECTED            (1 << 31)
#define UARTE_PSEL_CTS_CONNECT_Disconnected            (1 << 31)
/**@}*/

/* --- UARTE_PSEL.RXD values ----------------------------------------------- */
/** @defgroup uarte_psel_rxd Select pin for RXD signal
@ingroup uarte_defines
@{*/
#define UARTE_PSEL_RXD_PIN(pin)                        (pin)
#define UARTE_PSEL_RXD_CONNECT_CONNECTED               (0 << 31)
#define UARTE_PSEL_RXD_CONNECT_Connected               (0 << 31)
#define UARTE_PSEL_RXD_CONNECT_DISCONNECTED            (1 << 31)
#define UARTE_PSEL_RXD_CONNECT_Disconnected            (1 << 31)
/**@}*/

/* --- UARTE_BAUDRATE values ----------------------------------------------- */
/** @defgroup uarte_baudrate Set baud rate for UARTE. Accuracy depends on the
HFCLK source selected
@ingroup uarte_defines
@{*/
#define BAUD1200                                       0x0004f000
#define UARTE_BAUDRATE_BAUDRATE_BAUD1200               0x0004f000
#define UARTE_BAUDRATE_BAUDRATE_Baud1200               0x0004f000
#define BAUD2400                                       0x0009d000
#define UARTE_BAUDRATE_BAUDRATE_BAUD2400               0x0009d000
#define UARTE_BAUDRATE_BAUDRATE_Baud2400               0x0009d000
#define BAUD4800                                       0x0013b000
#define UARTE_BAUDRATE_BAUDRATE_BAUD4800               0x0013b000
#define UARTE_BAUDRATE_BAUDRATE_Baud4800               0x0013b000
#define BAUD9600                                       0x00275000
#define UARTE_BAUDRATE_BAUDRATE_BAUD9600               0x00275000
#define UARTE_BAUDRATE_BAUDRATE_Baud9600               0x00275000
#define BAUD14400                                      0x003af000
#define UARTE_BAUDRATE_BAUDRATE_BAUD14400              0x003af000
#define UARTE_BAUDRATE_BAUDRATE_Baud14400              0x003af000
#define BAUD19200                                      0x004ea000
#define UARTE_BAUDRATE_BAUDRATE_BAUD19200              0x004ea000
#define UARTE_BAUDRATE_BAUDRATE_Baud19200              0x004ea000
#define BAUD28800                                      0x0075c000
#define UARTE_BAUDRATE_BAUDRATE_BAUD28800              0x0075c000
#define UARTE_BAUDRATE_BAUDRATE_Baud28800              0x0075c000
#define BAUD38400                                      0x009d0000
#define UARTE_BAUDRATE_BAUDRATE_BAUD38400              0x009d0000
#define UARTE_BAUDRATE_BAUDRATE_Baud38400              0x009d0000
#define BAUD57600                                      0x00eb0000
#define UARTE_BAUDRATE_BAUDRATE_BAUD57600              0x00eb0000
#define UARTE_BAUDRATE_BAUDRATE_Baud57600              0x00eb0000
#define BAUD76800                                      0x013a9000
#define UARTE_BAUDRATE_BAUDRATE_BAUD76800              0x013a9000
#define UARTE_BAUDRATE_BAUDRATE_Baud76800              0x013a9000
#define BAUD115200                                     0x01d60000
#define UARTE_BAUDRATE_BAUDRATE_BAUD115200             0x01d60000
#define UARTE_BAUDRATE_BAUDRATE_Baud115200             0x01d60000
#define BAUD230400                                     0x03b00000
#define UARTE_BAUDRATE_BAUDRATE_BAUD230400             0x03b00000
#define UARTE_BAUDRATE_BAUDRATE_Baud230400             0x03b00000
#define BAUD250000                                     0x04000000
#define UARTE_BAUDRATE_BAUDRATE_BAUD250000             0x04000000
#define UARTE_BAUDRATE_BAUDRATE_Baud250000             0x04000000
#define BAUD460800                                     0x07400000
#define UARTE_BAUDRATE_BAUDRATE_BAUD460800             0x07400000
#define UARTE_BAUDRATE_BAUDRATE_Baud460800             0x07400000
#define BAUD921600                                     0x0f000000
#define UARTE_BAUDRATE_BAUDRATE_BAUD921600             0x0f000000
#define UARTE_BAUDRATE_BAUDRATE_Baud921600             0x0f000000
#define BAUD1M                                         0x10000000
#define UARTE_BAUDRATE_BAUDRATE_BAUD1M                 0x10000000
#define UARTE_BAUDRATE_BAUDRATE_Baud1M                 0x10000000
/**@}*/

/* --- UARTE_CONFIG values ------------------------------------------------- */
/** @defgroup uarte_config Configurate parity and hardware flow control
@ingroup uarte_defines
@{*/
#define HWFC_ENABLED                            1
#define UARTE_CONFIG_HWFC_ENABLED               1
#define UARTE_CONFIG_HWFC_Enabled               1
#define HWFC_DISABLED                           0
#define UARTE_CONFIG_HWFC_DISABLED              0
#define UARTE_CONFIG_HWFC_Disabled              0
#define PARITY_EXCLUDED                         (0x0 << 1)
#define UARTE_CONFIG_PARITY_EXCLUDED            (0x0 << 1)
#define UARTE_CONFIG_PARITY_Excluded            (0x0 << 1)
#define PARITY_INCLUDED                         (0x7 << 1)
#define UARTE_CONFIG_PARITY_INCLUDED            (0x7 << 1)
#define UARTE_CONFIG_PARITY_Included            (0x7 << 1)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void uarte_set_baudrate(uint32_t uarte, uint32_t baud);
void uarte_config(uint32_t uarte, uint32_t flowcontrol, uint32_t parity);
void uarte_enable(uint32_t uarte);
void uarte_disable(uint32_t uarte);
void uarte_tx_pin(uint32_t uarte, int pin);
void uarte_rx_pin(uint32_t uarte, int pin);
void uarte_tx_start(uint32_t uarte);
void uarte_rx_start(uint32_t uarte);
void uarte_tx_stop(uint32_t uarte);
void uarte_rx_stop(uint32_t uarte);
void uarte_tx_init(uint32_t uarte);
void uarte_rx_init(uint32_t uarte, char event);
uint32_t uarte_received_rxdrdy(uint32_t uarte);
uint32_t uarte_received_endrx(uint32_t uarte);
uint32_t uarte_received(uint32_t uarte, char event);
void uarte_tx_packet(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt);
void uarte_rx_packet(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt);
uint32_t uarte_rx_received_ptr(uint32_t uarte);
uint32_t uarte_rx_received_maxcnt(uint32_t uarte);
void uarte_send(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt);
void uarte_send_waiting(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt);
void uarte_interrupt_enable(uint32_t uarte, uint32_t events);
void uarte_interrupt_disable(uint32_t uarte, uint32_t events);
bool uarte_get_event(uint32_t uarte, char event);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "uarte_common.h should not be included explicitly, only via uarte.h"
#endif
/** @endcond */

