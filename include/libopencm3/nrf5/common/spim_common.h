/** @addtogroup spim_defines SPIM Defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SPIM.H
The order of header inclusion is important. spim.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_SPIM_H)
/** @endcond */
#ifndef LIBOPENCM3_SPIM_COMMON_H
#define LIBOPENCM3_SPIM_COMMON_H

/**@{*/
/** @defgroup spim_reg_base SPIM register base addresses
 * @ingroup spim_defines
 * @{
 */
#define SPIM0                            SPIM0_BASE
#define SPIM1                            SPIM1_BASE
#define SPIM2                            SPIM2_BASE
/**@}*/

/** @defgroup spim_registers SPIM Registers
 * @ingroup spim_defines
 * @brief SPIM Registers
@{*/
/* --------------------- SPIM registers for NRF52 ------------------------- */

/* Tasks Registers */
#define SPIM_TASKS_START(spim_base)              MMIO32((spim_base) + 0x010)
#define SPIM0_TASKS_START                        MMIO32((SPIM0) + 0x010)
#define SPIM1_TASKS_START                        MMIO32((SPIM1) + 0x010)
#define SPIM2_TASKS_START                        MMIO32((SPIM2) + 0x010)

#define SPIM_TASKS_STOP(spim_base)               MMIO32((spim_base) + 0x014)
#define SPIM0_TASKS_STOP                         MMIO32((SPIM0) + 0x014)
#define SPIM1_TASKS_STOP                         MMIO32((SPIM1) + 0x014)
#define SPIM2_TASKS_STOP                         MMIO32((SPIM2) + 0x014)

#define SPIM_TASKS_SUSPEND(spim_base)            MMIO32((spim_base) + 0x01C)
#define SPIM0_TASKS_SUSPEND                      MMIO32((SPIM0) + 0x01C)
#define SPIM1_TASKS_SUSPEND                      MMIO32((SPIM1) + 0x01C)
#define SPIM2_TASKS_SUSPEND                      MMIO32((SPIM2) + 0x01C)

#define SPIM_TASKS_RESUME(spim_base)             MMIO32((spim_base) + 0x020)
#define SPIM0_TASKS_RESUME                       MMIO32((SPIM0) + 0x020)
#define SPIM1_TASKS_RESUME                       MMIO32((SPIM1) + 0x020)
#define SPIM2_TASKS_RESUME                       MMIO32((SPIM2) + 0x020)

/*Events Register*/
#define SPIM_EVENTS_STOPPED(spim_base)           MMIO32((spim_base) + 0x104)
#define SPIM0_EVENTS_STOPPED                     MMIO32((SPIM0) + 0x104)
#define SPIM1_EVENTS_STOPPED                     MMIO32((SPIM1) + 0x104)
#define SPIM2_EVENTS_STOPPED                     MMIO32((SPIM2) + 0x104)

#define SPIM_EVENTS_ENDRX(spim_base)             MMIO32((spim_base) + 0x110)
#define SPIM0_EVENTS_ENDRX                       MMIO32((SPIM0) + 0x110)
#define SPIM1_EVENTS_ENDRX                       MMIO32((SPIM1) + 0x110)
#define SPIM2_EVENTS_ENDRX                       MMIO32((SPIM2) + 0x110)

#define SPIM_EVENTS_END(spim_base)               MMIO32((spim_base) + 0x118)
#define SPIM0_EVENTS_END                         MMIO32((SPIM0) + 0x118)
#define SPIM1_EVENTS_END                         MMIO32((SPIM1) + 0x118)
#define SPIM2_EVENTS_END                         MMIO32((SPIM2) + 0x118)

#define SPIM_EVENTS_ENDTX(spim_base)             MMIO32((spim_base) + 0x120)
#define SPIM0_EVENTS_ENDTX                       MMIO32((SPIM0) + 0x120)
#define SPIM1_EVENTS_ENDTX                       MMIO32((SPIM1) + 0x120)
#define SPIM2_EVENTS_ENDTX                       MMIO32((SPIM2) + 0x120)

#define SPIM_EVENTS_STARTED(spim_base)           MMIO32((spim_base) + 0x14C)
#define SPIM0_EVENTS_STARTED                     MMIO32((SPIM0) + 0x14C)
#define SPIM1_EVENTS_STARTED                     MMIO32((SPIM1) + 0x14C)
#define SPIM2_EVENTS_STARTED                     MMIO32((SPIM2) + 0x14C)

/***/
#define SPIM_SHORTS(spim_base)                   MMIO32((spim_base) + 0x200)
#define SPIM0_SHORTS                             MMIO32((SPIM0) + 0x200)
#define SPIM1_SHORTS                             MMIO32((SPIM1) + 0x200)
#define SPIM2_SHORTS                             MMIO32((SPIM2) + 0x200)

#define SPIM_INTENSET(spim_base)                 MMIO32((spim_base) + 0x304)
#define SPIM0_INTENSET                           MMIO32((SPIM0) + 0x304)
#define SPIM1_INTENSET                           MMIO32((SPIM1) + 0x304)
#define SPIM2_INTENSET                           MMIO32((SPIM2) + 0x304)

#define SPIM_INTENCLR(spim_base)                 MMIO32((spim_base) + 0x308)
#define SPIM0_INTENCLR                           MMIO32((SPIM0) + 0x308)
#define SPIM1_INTENCLR                           MMIO32((SPIM1) + 0x308)
#define SPIM2_INTENCLR                           MMIO32((SPIM2) + 0x308)

#define SPIM_ENABLE(spim_base)                   MMIO32((spim_base) + 0x500)
#define SPIM0_ENABLE                             MMIO32((SPIM0) + 0x500)
#define SPIM1_ENABLE                             MMIO32((SPIM1) + 0x500)
#define SPIM2_ENABLE                             MMIO32((SPIM2) + 0x500)

struct SPIM_PSEL_TYPE{
	uint32_t SCK;
	uint32_t MOSI;
	uint32_t MISO;
};
#define SPIM_PSEL(SPIM_BASE)      (*(volatile struct SPIM_PSEL_TYPE*)((SPIM_BASE) + 0x508))
#define SPIM0_PSEL      (*(volatile struct SPIM_PSEL_TYPE*)((SPIM0) + 0x508))

#define SPIM1_PSEL      (*(volatile struct SPIM_PSEL_TYPE*)((SPIM1) + 0x508))

#define SPIM2_PSEL      (*(volatile struct SPIM_PSEL_TYPE*)((SPIM2) + 0x508))

#define SPIM_PSEL_SCK(spim_base)                 MMIO32((spim_base) + 0x508)
#define SPIM0_PSEL_SCK                           MMIO32((SPIM0) + 0x508)
#define SPIM1_PSEL_SCK                           MMIO32((SPIM1) + 0x508)
#define SPIM2_PSEL_SCK                           MMIO32((SPIM2) + 0x508)

#define SPIM_PSEL_MOSI(spim_base)                MMIO32((spim_base) + 0x50C)
#define SPIM0_PSEL_MOSI                          MMIO32((SPIM0) + 0x50C)
#define SPIM1_PSEL_MOSI                          MMIO32((SPIM1) + 0x50C)
#define SPIM2_PSEL_MOSI                          MMIO32((SPIM2) + 0x50C)

#define SPIM_PSEL_MISO(spim_base)                MMIO32((spim_base) + 0x510)
#define SPIM0_PSEL_MISO                          MMIO32((SPIM0) + 0x510)
#define SPIM1_PSEL_MISO                          MMIO32((SPIM1) + 0x510)
#define SPIM2_PSEL_MISO                          MMIO32((SPIM2) + 0x510)

#define SPIM_FREQUENCY(spim_base)                MMIO32((spim_base) + 0x524)
#define SPIM0_FREQUENCY                          MMIO32((SPIM0) + 0x524)
#define SPIM1_FREQUENCY                          MMIO32((SPIM1) + 0x524)
#define SPIM2_FREQUENCY                          MMIO32((SPIM2) + 0x524)

struct SPIM_RXD_TYPE{
	uint32_t PTR;
	uint32_t MAXCNT;
	uint32_t AMOUNT;
	uint32_t LIST;
};
#define SPIM_RXD(SPIM_BASE)       (*(volatile struct SPIM_RXD_TYPE*)((SPIM_BASE) + 0x534))
#define SPIM0_RXD       (*(volatile struct SPIM_RXD_TYPE*)((SPIM0) + 0x534))


#define SPIM1_RXD       (*(volatile struct SPIM_RXD_TYPE*)((SPIM1) + 0x534))

#define SPIM2_RXD       (*(volatile struct SPIM_RXD_TYPE*)((SPIM2) + 0x534))

#define SPIM_RXD_PTR(spim_base)                  MMIO32((spim_base) + 0x534)
#define SPIM0_RXD_PTR                            MMIO32((SPIM0) + 0x534)
#define SPIM1_RXD_PTR                            MMIO32((SPIM1) + 0x534)
#define SPIM2_RXD_PTR                            MMIO32((SPIM2) + 0x534)

#define SPIM_RXD_MAXCNT(spim_base)               MMIO32((spim_base) + 0x538)
#define SPIM0_RXD_MAXCNT                         MMIO32((SPIM0) + 0x538)
#define SPIM1_RXD_MAXCNT                         MMIO32((SPIM1) + 0x538)
#define SPIM2_RXD_MAXCNT                         MMIO32((SPIM2) + 0x538)

#define SPIM_RXD_AMOUNT(spim_base)               MMIO32((spim_base) + 0x53C)
#define SPIM0_RXD_AMOUNT                         MMIO32((SPIM0) + 0x53C)
#define SPIM1_RXD_AMOUNT                         MMIO32((SPIM1) + 0x53C)
#define SPIM2_RXD_AMOUNT                         MMIO32((SPIM2) + 0x53C)

#define SPIM_RXD_LIST(spim_base)                 MMIO32((spim_base) + 0x540)
#define SPIM0_RXD_LIST                           MMIO32((SPIM0) + 0x540)
#define SPIM1_RXD_LIST                           MMIO32((SPIM1) + 0x540)
#define SPIM2_RXD_LIST                           MMIO32((SPIM2) + 0x540)

struct SPIM_TXD_TYPE{
	uint32_t PTR;
	uint32_t MAXCNT;
	uint32_t AMOUNT;
	uint32_t LIST;
};
#define SPIM_TXD(SPIM_BASE)       (*(volatile struct SPIM_TXD_TYPE*)((SPIM_BASE) + 0x544))
#define SPIM0_TXD       (*(volatile struct SPIM_TXD_TYPE*)((SPIM0) + 0x544))


#define SPIM1_TXD       (*(volatile struct SPIM_TXD_TYPE*)((SPIM1) + 0x544))

#define SPIM2_TXD       (*(volatile struct SPIM_TXD_TYPE*)((SPIM2) + 0x544))

#define SPIM_TXD_PTR(spim_base)                  MMIO32((spim_base) + 0x544)
#define SPIM0_TXD_PTR                            MMIO32((SPIM0) + 0x544)
#define SPIM1_TXD_PTR                            MMIO32((SPIM1) + 0x544)
#define SPIM2_TXD_PTR                            MMIO32((SPIM2) + 0x544)

#define SPIM_TXD_MAXCNT(spim_base)               MMIO32((spim_base) + 0x548)
#define SPIM0_TXD_MAXCNT                         MMIO32((SPIM0) + 0x548)
#define SPIM1_TXD_MAXCNT                         MMIO32((SPIM1) + 0x548)
#define SPIM2_TXD_MAXCNT                         MMIO32((SPIM2) + 0x548)

#define SPIM_TXD_AMOUNT(spim_base)               MMIO32((spim_base) + 0x54C)
#define SPIM0_TXD_AMOUNT                         MMIO32((SPIM0) + 0x54C)
#define SPIM1_TXD_AMOUNT                         MMIO32((SPIM1) + 0x54C)
#define SPIM2_TXD_AMOUNT                         MMIO32((SPIM2) + 0x54C)

#define SPIM_TXD_LIST(spim_base)                 MMIO32((spim_base) + 0x550)
#define SPIM0_TXD_LIST                           MMIO32((SPIM0) + 0x550)
#define SPIM1_TXD_LIST                           MMIO32((SPIM1) + 0x550)
#define SPIM2_TXD_LIST                           MMIO32((SPIM2) + 0x550)

#define SPIM_CONFIG(spim_base)                   MMIO32((spim_base) + 0x554)
#define SPIM0_CONFIG                             MMIO32((SPIM0) + 0x554)
#define SPIM1_CONFIG                             MMIO32((SPIM1) + 0x554)
#define SPIM2_CONFIG                             MMIO32((SPIM2) + 0x554)

#define SPIM_ORC(spim_base)                      MMIO32((spim_base) + 0x5C0)
#define SPIM0_ORC                                MMIO32((SPIM0) + 0x5C0)
#define SPIM1_ORC                                MMIO32((SPIM1) + 0x5C0)
#define SPIM2_ORC                                MMIO32((SPIM2) + 0x5C0)
/**@}*/

/* --- SPIM_SHORTS values -------------------------------------------------- */
/** @defgroup spim_shorts Set shortcut between END event and START task
@ingroup spim_defines
@{*/
#define SPIM_SHORTS_END_START_ENABLED             (1 << 17)
#define SPIM_SHORTS_END_START_Enabled             (1 << 17)
/**@}*/

/* --- SPIM_INTENSET values ------------------------------------------------ */
/** @defgroup spim_intenset Enable interrupt
@ingroup spim_defines
@{*/
#define SPIM_INTENSET_STOPPED_SET             (1 << 1)
#define SPIM_INTENSET_ENDRX_SET               (1 << 4)
#define SPIM_INTENSET_END_SET                 (1 << 6)
#define SPIM_INTENSET_ENDTX_SET               (1 << 8)
#define SPIM_INTENSET_STARTED_SET             (1 << 19)
/**@}*/

/* --- SPIM_INTENCLR values ------------------------------------------------ */
/** @defgroup spim_intenclr Disable interrupt
@ingroup spim_defines
@{*/
#define SPIM_INTENCLR_STOPPED_CLR            (1 << 1)
#define SPIM_INTENCLR_ENDRX_CLR               (1 << 4)
#define SPIM_INTENCLR_END_CLR                 (1 << 6)
#define SPIM_INTENCLR_ENDTX_CLR               (1 << 8)
#define SPIM_INTENCLR_STARTED_CLR             (1 << 19)
#define SPIM_INTENCLR_STOPPED_CLEAR            (1 << 1)
#define SPIM_INTENCLR_ENDRX_CLEAR               (1 << 4)
#define SPIM_INTENCLR_END_CLEAR                 (1 << 6)
#define SPIM_INTENCLR_ENDTX_CLEAR               (1 << 8)
#define SPIM_INTENCLR_STARTED_CLEAR             (1 << 19)
/**@}*/

/* --- SPIM_ENABLE values -------------------------------------------------- */
/** @defgroup spim_enable Enable SPIM
@ingroup spim_defines
@{*/
#define SPIM_ENABLE_ENABLE_ENABLED               (7)
#define SPIM_ENABLE_ENABLE_DISABLED              (0)
/**@}*/

/* --- SPIM_PSEL.SCK values ------------------------------------------------ */
/** @defgroup spim_psel_sck Select pin for SCK
@ingroup spim_defines
@{*/
#define SPIM_PSEL_SCK_PIN(n)                     (n)
#define SPIM_PSEL_SCK_CONNECT_CONNECTED          (0)
#define SPIM_PSEL_SCK_CONNECT_DISCONNECTED       (1)
/**@}*/

/* --- SPIM_PSEL.MOSI values ----------------------------------------------- */
/** @defgroup spim_psel_mosi Select pin for MOSI signal
@ingroup spim_defines
@{*/
#define SPIM_PSEL_MOSI_PIN(n)                    (n)
#define SPIM_PSEL_MOSI_CONNECT_CONNECTED         (0)
#define SPIM_PSEL_MOSI_CONNECT_DISCONNECTED      (1)
/**@}*/

/* --- SPIM_PSEL.MISO values ----------------------------------------------- */
/** @defgroup spim_psel_miso Select pin for MISO signal
@ingroup spim_defines
@{*/
#define SPIM_PSEL_MISO_PIN(n)                    (n)
#define SPIM_PSEL_MISO_CONNECT_CONNECTED         (0)
#define SPIM_PSEL_MISO_CONNECT_DISCONNECTED      (1)
/**@}*/

/* --- SPIM_FREQUENCY values ----------------------------------------------- */
/** @defgroup spim_frequency Set SPI frequency
@ingroup spim_defines
@{*/
/*Accuracy depends on the HFCLK source selected*/
#define SPIM_FREQUENCY_FREQUENCY_K125            (0x02000000) //125 kbps
#define SPIM_FREQUENCY_FREQUENCY_K250            (0x04000000) //250 kbps
#define SPIM_FREQUENCY_FREQUENCY_K500            (0x08000000) //500 kbps
#define SPIM_FREQUENCY_FREQUENCY_M1              (0x10000000) //1 Mbps
#define SPIM_FREQUENCY_FREQUENCY_M2              (0x20000000) //2 Mbps
#define SPIM_FREQUENCY_FREQUENCY_M4              (0x40000000) //4 Mbps
#define SPIM_FREQUENCY_FREQUENCY_M8              (0x80000000) //8 Mbps
/**@}*/

/* --- SPIM_RXD.PTR values ------------------------------------------------- */
/** @defgroup spim_rxd_ptr Data pointer configuration for RXD buffer
@ingroup spim_defines
@{*/
#define SPIM_RXD_LIST_LIST_DISABLED              (0) // Disable EasyDMA list
#define SPIM_RXD_LIST_LIST_ARRAYLIST             (1) // Use array list
/**@}*/

/* --- SPIM_TXD.PTR values ------------------------------------------------- */
/** @defgroup spim_txd_ptr Data pointer configuration for TXD buffer
@ingroup spim_defines
@{*/
#define SPIM_TXD_LIST_LIST_DISABLED              (0) // Disable EasyDMA list
#define SPIM_TXD_LIST_LIST_ARRAYLIST             (1) // Use array list
/**@}*/

/* --- SPIM_CONFIG values -------------------------------------------------- */
/** @defgroup spim_config Bit order, Serial clock phase and polarity 
configuration
@ingroup spim_defines
@{*/
#define SPIM_CONFIG_ORDER_MSBFIRST               (0 << 0)
#define SPIM_CONFIG_ORDER_LSBFIRST               (1 << 0)
//Sample on leading edge of clock, shift serial data on trailing edge
#define SPIM_CONFIG_CPHA_LEADING                 (0 << 1)
//Sample on trailing edge of clock, shift serial data on leading edge
#define SPIM_CONFIG_CPHA_TRAILING                (1 << 1)
//Serial clock polarity
#define SPIM_CONFIG_CPOL_ACTIVEHIGH              (0 << 2) 
#define SPIM_CONFIG_CPOL_ACTIVELOW               (1 << 2)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

//funktion();
//funktion();
//funktion();
//funktion();

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "spim_common.h should not be included explicitly, only via spim.h"
#endif
/** @endcond */

