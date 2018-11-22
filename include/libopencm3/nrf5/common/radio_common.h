/** @addtogroup radio_defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA RADIO.H
The order of header inclusion is important. radio.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_RADIO_H)
/** @endcond */
#ifndef LIBOPENCM3_RADIO_COMMON_H
#define LIBOPENCM3_RADIO_COMMON_H

/**@{*/

/** @defgroup radio_registers RADIO Registers
 * @ingroup radio_defines
 * @brief RADIO Registers
@{*/
/* --------------------- RADIO registers for NRF52 ------------------------- */
/*Tasks Registers*/
#define RADIO_TASKS_TXEN                 MMIO32((RADIO_BASE) + 0x000)
#define RADIO_TASKS_RXEN                 MMIO32((RADIO_BASE) + 0x004)
#define RADIO_TASKS_START                MMIO32((RADIO_BASE) + 0x008)
#define RADIO_TASKS_STOP                 MMIO32((RADIO_BASE) + 0x00C)
#define RADIO_TASKS_DISABLE              MMIO32((RADIO_BASE) + 0x010)
#define RADIO_TASKS_RSSISTART            MMIO32((RADIO_BASE) + 0x014)
#define RADIO_TASKS_RSSISTOP             MMIO32((RADIO_BASE) + 0x018)
#define RADIO_TASKS_BCSTART              MMIO32((RADIO_BASE) + 0x01C)
#define RADIO_TASKS_BCSTOP               MMIO32((RADIO_BASE) + 0x020)

/*Events Register*/
#define RADIO_EVENTS_READY               MMIO32((RADIO_BASE) + 0x100)
#define RADIO_EVENTS_ADDRESS             MMIO32((RADIO_BASE) + 0x104)
#define RADIO_EVENTS_PAYLOAD             MMIO32((RADIO_BASE) + 0x108)
#define RADIO_EVENTS_END                 MMIO32((RADIO_BASE) + 0x10C)
#define RADIO_EVENTS_DISABLED            MMIO32((RADIO_BASE) + 0x110)
#define RADIO_EVENTS_DEVMATCH            MMIO32((RADIO_BASE) + 0x114)
#define RADIO_EVENTS_DEVMISS             MMIO32((RADIO_BASE) + 0x118)
#define RADIO_EVENTS_RSSIEND             MMIO32((RADIO_BASE) + 0x11C)
#define RADIO_EVENTS_BCMATCH             MMIO32((RADIO_BASE) + 0x128)
#define RADIO_EVENTS_CRCOK               MMIO32((RADIO_BASE) + 0x130)
#define RADIO_EVENTS_CRCERROR            MMIO32((RADIO_BASE) + 0x134)

/* Registers */
#define RADIO_SHORTS                     MMIO32((RADIO_BASE) + 0x200)
#define RADIO_INTENSET                   MMIO32((RADIO_BASE) + 0x304)
#define RADIO_INTENCLR                   MMIO32((RADIO_BASE) + 0x308)
#define RADIO_CRCSTATUS                  MMIO32((RADIO_BASE) + 0x400)
#define RADIO_RXMATCH                    MMIO32((RADIO_BASE) + 0x408)
#define RADIO_RXCRC                      MMIO32((RADIO_BASE) + 0x40C)
#define RADIO_DAI                        MMIO32((RADIO_BASE) + 0x410)
#define RADIO_PACKETPTR                  MMIO32((RADIO_BASE) + 0x504)
#define RADIO_FREQUENCY                  MMIO32((RADIO_BASE) + 0x508)
#define RADIO_TXPOWER                    MMIO32((RADIO_BASE) + 0x50C)
#define RADIO_MODE                       MMIO32((RADIO_BASE) + 0x510)
#define RADIO_PCNF0                      MMIO32((RADIO_BASE) + 0x514)
#define RADIO_PCNF1                      MMIO32((RADIO_BASE) + 0x518)
#define RADIO_BASE0                      MMIO32((RADIO_BASE) + 0x51C)
#define RADIO_BASE1                      MMIO32((RADIO_BASE) + 0x520)
#define RADIO_PREFIX0                    MMIO32((RADIO_BASE) + 0x524)
#define RADIO_PREFIX1                    MMIO32((RADIO_BASE) + 0x528)
#define RADIO_TXADDRESS                  MMIO32((RADIO_BASE) + 0x52C)
#define RADIO_RXADDRESSES                MMIO32((RADIO_BASE) + 0x530)
#define RADIO_CRCCNF                     MMIO32((RADIO_BASE) + 0x534)
#define RADIO_CRCPOLY                    MMIO32((RADIO_BASE) + 0x538)
#define RADIO_CRCINIT                    MMIO32((RADIO_BASE) + 0x53C)
/*Offset 0x540 reserved*/
#define RADIO_TIFS                       MMIO32((RADIO_BASE) + 0x544)
#define RADIO_RSSISAMPLE                 MMIO32((RADIO_BASE) + 0x548)
#define RADIO_STATE                      MMIO32((RADIO_BASE) + 0x550)
#define RADIO_DATAWHITEIV                MMIO32((RADIO_BASE) + 0x554)
#define RADIO_BCC                        MMIO32((RADIO_BASE) + 0x560)
#define RADIO_DAB                        PTRIO32((RADIO_BASE) + 0x600)
#define RADIO_DAP                        PTRIO32((RADIO_BASE) + 0x620)
#define RADIO_DACNF                      MMIO32((RADIO_BASE) + 0x640)
#define RADIO_MODECNF0                   MMIO32((RADIO_BASE) + 0x650)
#define RADIO_POWER                      MMIO32((RADIO_BASE) + 0xFFC)
/**@}*/

/* --- RADIO_SHORTS values ------------------------------------------------- */
/** @defgroup radio_shorts Set shortcut between events and tasks registers
@ingroup radio_defines
@{*/
#define RADIO_SHORTS_READY_START_ENABLED           (1 << 0)
#define RADIO_SHORTS_READY_START_Enabled           (1 << 0)
#define RADIO_SHORTS_END_DISABLE_ENABLED           (1 << 1)
#define RADIO_SHORTS_END_DISABLE_Enabled           (1 << 1)
#define RADIO_SHORTS_DISABLED_TXEN_ENABLED         (1 << 2)
#define RADIO_SHORTS_DISABLED_TXEN_Enabled         (1 << 2)
#define RADIO_SHORTS_DISABLED_RXEN_ENABLED         (1 << 3)
#define RADIO_SHORTS_DISABLED_RXEN_Enabled         (1 << 3)
#define RADIO_SHORTS_ADDRESS_RSSISTART_ENABLED     (1 << 4)
#define RADIO_SHORTS_ADDRESS_RSSISTART_Enabled     (1 << 4)
#define RADIO_SHORTS_END_START_ENABLED             (1 << 5)
#define RADIO_SHORTS_END_START_Enabled             (1 << 5)
#define RADIO_SHORTS_ADDRESS_BCSTART_ENABLED       (1 << 6)
#define RADIO_SHORTS_ADDRESS_BCSTART_Enabled       (1 << 6)
#define RADIO_SHORTS_DISABLED_RSSISTOP_ENABLED     (1 << 8)
#define RADIO_SHORTS_DISABLED_RSSISTOP_Enabled     (1 << 8)
/**@}*/

/* ------------------------------------------------------------------------- */
/* Events interrupt definitions (for convenience) */
/** @defgroup radio_events_interrupt RADIO Events Identifiers for interrupt
@ingroup radio_defines
@{*/
#define READY                                      (1 << 0)
#define ADDRESS                                    (1 << 1)    
#define PAYLOAD                                    (1 << 2)
#define END                                        (1 << 3)    
#define DISABLED                                   (1 << 4)
#define DEVMATCH                                   (1 << 5)    
#define DEVMISS                                    (1 << 6)    
#define RSSIEND                                    (1 << 7)    
#define BCMATCH                                    (1 << 10)
#define CRCOK                                      (1 << 12)
#define CRCERROR                                   (1 << 13)
/**@}*/

/* --- RADIO_INTENSET values ----------------------------------------------- */
/** @defgroup radio_intenset Enable interrupt
@ingroup radio_defines
@{*/
#define RADIO_INTENSET_READY_ENABLED               (1 << 0)
#define RADIO_INTENSET_READY_Enabled               (1 << 0)
#define RADIO_INTENSET_READY_SET                   (1 << 0)
#define RADIO_INTENSET_READY_Set                   (1 << 0)
#define RADIO_INTENSET_ADDRESS_ENABLED             (1 << 1)
#define RADIO_INTENSET_ADDRESS_Enabled             (1 << 1)
#define RADIO_INTENSET_ADDRESS_SET                 (1 << 1)
#define RADIO_INTENSET_ADDRESS_Set                 (1 << 1)
#define RADIO_INTENSET_PAYLOAD_ENABLED             (1 << 2)
#define RADIO_INTENSET_PAYLOAD_Enabled             (1 << 2)
#define RADIO_INTENSET_PAYLOAD_SET                 (1 << 2)
#define RADIO_INTENSET_PAYLOAD_Set                 (1 << 2)
#define RADIO_INTENSET_END_ENABLED                 (1 << 3)
#define RADIO_INTENSET_END_Enabled                 (1 << 3)
#define RADIO_INTENSET_END_SET                     (1 << 3)
#define RADIO_INTENSET_END_Set                     (1 << 3)
#define RADIO_INTENSET_DISABLED_ENABLED            (1 << 4)
#define RADIO_INTENSET_DISABLED_Enabled            (1 << 4)
#define RADIO_INTENSET_DISABLED_SET                (1 << 4)
#define RADIO_INTENSET_DISABLED_Set                (1 << 4)
#define RADIO_INTENSET_DEVMATCH_ENABLED            (1 << 5)
#define RADIO_INTENSET_DEVMATCH_Enabled            (1 << 5)
#define RADIO_INTENSET_DEVMATCH_SET                (1 << 5)
#define RADIO_INTENSET_DEVMATCH_Set                (1 << 5)
#define RADIO_INTENSET_DEVMISS_ENABLED             (1 << 6)
#define RADIO_INTENSET_DEVMISS_Enabled             (1 << 6)
#define RADIO_INTENSET_DEVMISS_SET                 (1 << 6)
#define RADIO_INTENSET_DEVMISS_Set                 (1 << 6)
#define RADIO_INTENSET_RSSIEND_ENABLED             (1 << 7)
#define RADIO_INTENSET_RSSIEND_Enabled             (1 << 7)
#define RADIO_INTENSET_RSSIEND_SET                 (1 << 7)
#define RADIO_INTENSET_RSSIEND_Set                 (1 << 7)
#define RADIO_INTENSET_BCMATCH_ENABLED             (1 << 10)
#define RADIO_INTENSET_BCMATCH_Enabled             (1 << 10)
#define RADIO_INTENSET_BCMATCH_SET                 (1 << 10)
#define RADIO_INTENSET_BCMATCH_Set                 (1 << 10)
#define RADIO_INTENSET_CRCOK_ENABLED               (1 << 12)
#define RADIO_INTENSET_CRCOK_Enabled               (1 << 12)
#define RADIO_INTENSET_CRCOK_SET                   (1 << 12)
#define RADIO_INTENSET_CRCOK_Set                   (1 << 12)
#define RADIO_INTENSET_CRCERROR_ENABLED            (1 << 13)
#define RADIO_INTENSET_CRCERROR_Enabled            (1 << 13)
#define RADIO_INTENSET_CRCERROR_SET                (1 << 13)
#define RADIO_INTENSET_CRCERROR_Set                (1 << 13)
/**@}*/

/* --- RADIO_INTENCLR values ----------------------------------------------- */
/** @defgroup radio_intenclr Disable interrupt
@ingroup radio_defines
@{*/
#define RADIO_INTENCLR_READY_ENABLED               (1 << 0)
#define RADIO_INTENCLR_READY_Enabled               (1 << 0)
#define RADIO_INTENCLR_READY_CLEAR                 (1 << 0)
#define RADIO_INTENCLR_READY_Clear                 (1 << 0)
#define RADIO_INTENCLR_ADDRESS_ENABLED             (1 << 1)
#define RADIO_INTENCLR_ADDRESS_Enabled             (1 << 1)
#define RADIO_INTENCLR_ADDRESS_CLEAR               (1 << 1)
#define RADIO_INTENCLR_ADDRESS_Clear               (1 << 1)
#define RADIO_INTENCLR_PAYLOAD_ENABLED             (1 << 2)
#define RADIO_INTENCLR_PAYLOAD_Enabled             (1 << 2)
#define RADIO_INTENCLR_PAYLOAD_CLEAR               (1 << 2)
#define RADIO_INTENCLR_PAYLOAD_Clear               (1 << 2)
#define RADIO_INTENCLR_END_ENABLED                 (1 << 3)
#define RADIO_INTENCLR_END_Enabled                 (1 << 3)
#define RADIO_INTENCLR_END_CLEAR                   (1 << 3)
#define RADIO_INTENCLR_END_Clear                   (1 << 3)
#define RADIO_INTENCLR_DISABLED_ENABLED            (1 << 4)
#define RADIO_INTENCLR_DISABLED_Enabled            (1 << 4)
#define RADIO_INTENCLR_DISABLED_CLEAR              (1 << 4)
#define RADIO_INTENCLR_DISABLED_Clear              (1 << 4)
#define RADIO_INTENCLR_DEVMATCH_ENABLED            (1 << 5)
#define RADIO_INTENCLR_DEVMATCH_Enabled            (1 << 5)
#define RADIO_INTENCLR_DEVMATCH_CLEAR              (1 << 5)
#define RADIO_INTENCLR_DEVMATCH_Clear              (1 << 5)
#define RADIO_INTENCLR_DEVMISS_ENABLED             (1 << 6)
#define RADIO_INTENCLR_DEVMISS_Enabled             (1 << 6)
#define RADIO_INTENCLR_DEVMISS_CLEAR               (1 << 6)
#define RADIO_INTENCLR_DEVMISS_Clear               (1 << 6)
#define RADIO_INTENCLR_RSSIEND_ENABLED             (1 << 7)
#define RADIO_INTENCLR_RSSIEND_Enabled             (1 << 7)
#define RADIO_INTENCLR_RSSIEND_CLEAR               (1 << 7)
#define RADIO_INTENCLR_RSSIEND_Clear               (1 << 7)
#define RADIO_INTENCLR_BCMATCH_ENABLED             (1 << 10)
#define RADIO_INTENCLR_BCMATCH_Enabled             (1 << 10)
#define RADIO_INTENCLR_BCMATCH_CLEAR               (1 << 10)
#define RADIO_INTENCLR_BCMATCH_Clear               (1 << 10)
#define RADIO_INTENCLR_CRCOK_ENABLED               (1 << 12)
#define RADIO_INTENCLR_CRCOK_Enabled               (1 << 12)
#define RADIO_INTENCLR_CRCOK_CLEAR                 (1 << 12)
#define RADIO_INTENCLR_CRCOK_Clear                 (1 << 12)
#define RADIO_INTENCLR_CRCERROR_ENABLED            (1 << 13)
#define RADIO_INTENCLR_CRCERROR_Enabled            (1 << 13)
#define RADIO_INTENCLR_CRCERROR_CLEAR              (1 << 13)
#define RADIO_INTENCLR_CRCERROR_Clear              (1 << 13)
/**@}*/

/* --- RADIO_CRCSTATUS values ---------------------------------------------- */
/** @defgroup radio_crcstatus CRC status
@ingroup radio_defines
@{*/
#define RADIO_CRCSTATUS_CRCSTATUS_CRCERROR        (0) 
#define RADIO_CRCSTATUS_CRCSTATUS_CRCError        (0)
#define RADIO_CRCSTATUS_CRCSTATUS_CRCOK           (1) 
#define RADIO_CRCSTATUS_CRCSTATUS_CRCOk           (1)
/**@}*/

/* --- RADIO_FREQUENCY values ---------------------------------------------- */
/** @defgroup radio_frequency Set frequency
@ingroup radio_defines
@{*/
#define RADIO_FREQUENCY_FREQUENCY(n)            (n) //value 0..100
#define MAP_DEFAULT                             (0 << 8)
#define RADIO_FREQUENCY_MAP_DEFAULT             (0 << 8)
#define RADIO_FREQUENCY_MAP_Default             (0 << 8)
#define MAP_LOW                                 (1 << 8)
#define RADIO_FREQUENCY_MAP_LOW                 (1 << 8)
#define RADIO_FREQUENCY_MAP_Low                 (1 << 8)
/**@}*/

/* --- RADIO_TXPOWER values ------------------------------------------------ */
/** @defgroup radio_txpower Set output power
@ingroup radio_defines
@{*/
#define TXPOWER_POS4DBM                         0x04
#define RADIO_TXPOWER_TXPOWER_POS4DBM           0x04 //+4 dBm
#define RADIO_TXPOWER_TXPOWER_Pos4dBm           0x04
#define TXPOWER_POS3DBM                         0x03
#define RADIO_TXPOWER_TXPOWER_POS3DBM           0x03 //+3 dBm
#define RADIO_TXPOWER_TXPOWER_Pos3dBm           0x03
#define TXPOWER_0DBM                            0x00
#define RADIO_TXPOWER_TXPOWER_0DBM              0x00 //0 dBm
#define RADIO_TXPOWER_TXPOWER_0dBm              0x00
#define TXPOWER_NEG4DBM                         0xFC
#define RADIO_TXPOWER_TXPOWER_NEG4DBM           0xFC //-4 dBm
#define RADIO_TXPOWER_TXPOWER_Neg4dBm           0xFC
#define TXPOWER_NEG8DBM                         0xF8
#define RADIO_TXPOWER_TXPOWER_NEG8DBM           0xF8 //-8 dBm
#define RADIO_TXPOWER_TXPOWER_Neg8dBm           0xF8
#define TXPOWER_NEG12DBM                        0xF4
#define RADIO_TXPOWER_TXPOWER_NEG12DBM          0xF4 //-12 dBm
#define RADIO_TXPOWER_TXPOWER_Neg12dBm          0xF4
#define TXPOWER_NEG16DBM                        0xF0
#define RADIO_TXPOWER_TXPOWER_NEG16DBM          0xF0 //-16 dBm
#define RADIO_TXPOWER_TXPOWER_Neg16dBm          0xF0
#define TXPOWER_NEG20DBM                        0xEC
#define RADIO_TXPOWER_TXPOWER_NEG20DBM          0xEC //-20 dBm
#define RADIO_TXPOWER_TXPOWER_Neg20dBm          0xEC
#define TXPOWER_NEG30DBM                        0xD8
#define RADIO_TXPOWER_TXPOWER_NEG30DBM          0xD8 //-40 dBm (Deprecated)
#define RADIO_TXPOWER_TXPOWER_Neg30dBm          0xD8
#define TXPOWER_NEG40DBM                        0xD8
#define RADIO_TXPOWER_TXPOWER_NEG40DBM          0xD8 //-40 dBm
#define RADIO_TXPOWER_TXPOWER_Neg40dBm          0xD8
/**@}*/

/* --- RADIO_MODE values --------------------------------------------------- */
/** @defgroup radio_mode Set mode for data rate and modulation
@ingroup radio_defines
@{*/
#define NRF_1MBIT                               (0)
#define RADIO_MODE_MODE_NRF_1MBIT               (0)
#define RADIO_MODE_MODE_Nrf_1Mbit               (0)
#define NRF_2MBIT                               (1)
#define RADIO_MODE_MODE_NRF_2MBIT               (1)
#define RADIO_MODE_MODE_Nrf_2Mbit               (1)
#define NRF_250KBIT                             (2) 
#define RADIO_MODE_MODE_NRF_250KBIT             (2) //(Deprecated)
#define RADIO_MODE_MODE_Nrf_250Kbit             (2)
#define BLE_1MBIT                               (3)
#define RADIO_MODE_MODE_BLE_1MBIT               (3)
#define RADIO_MODE_MODE_Ble_1Mbit               (3)
#define BLE_2MBIT                               (4)
#define RADIO_MODE_MODE_BLE_2MBIT               (4)
#define RADIO_MODE_MODE_Ble_2Mbit               (4)
/**@}*/

/* --- RADIO_PCNF0 values -------------------------------------------------- */
/** @defgroup radio_pcnf0 Configurates packet register 0
@ingroup radio_defines
@{*/
#define RADIO_PCNF0_LFLEN(n)                 (((n)&0x0f) << 0)
#define RADIO_PCNF0_S0LEN(n)                 (((n)&0x01) << 8)
#define RADIO_PCNF0_S1LEN(n)                 (((n)&0x0f) << 16)
#define S1INCL_AUTOMATIC                     (0 << 20)
#define RADIO_PCNF0_S1INCL_AUTOMATIC         (0 << 20)
#define RADIO_PCNF0_S1INCL_Automatic         (0 << 20)
#define S1INCL_INCLUDE                       (1 << 20)
#define RADIO_PCNF0_S1INCL_INCLUDE           (1 << 20)
#define RADIO_PCNF0_S1INCL_Include           (1 << 20)
#define PLEN_8BIT                            (0 << 24)
#define RADIO_PCNF0_PLEN_8BIT                (0 << 24)
#define RADIO_PCNF0_PLEN_8bit                (0 << 24)
#define PLEN_16BIT                           (1 << 24)
#define RADIO_PCNF0_PLEN_16BIT               (1 << 24)
#define RADIO_PCNF0_PLEN_16bit               (1 << 24)
/**@}*/

/* --- RADIO_PCNF1 values -------------------------------------------------- */
/** @defgroup radio_pcnf1 Configurates packet register 1
@ingroup radio_defines
@{*/
#define RADIO_PCNF1_MAXLEN(n)                ((uint8_t)(n) << 0)
#define RADIO_PCNF1_STATLEN(n)               ((uint8_t)(n) << 8)
#define RADIO_PCNF1_BALEN(n)                 (n << 16) //Value 2..4
#define ENDIAN_LITTLE                        (0 << 24)
#define RADIO_PCNF1_ENDIAN_LITTLE            (0 << 24)
#define RADIO_PCNF1_ENDIAN_Little            (0 << 24)
#define ENDIAN_BIG                           (1 << 24)
#define RADIO_PCNF1_ENDIAN_BIG               (1 << 24)
#define RADIO_PCNF1_ENDIAN_Big               (1 << 24)
#define RADIO_PCNF1_WHITEEN_DISABLED         (0 << 25)
#define RADIO_PCNF1_WHITEEN_Disabled         (0 << 25)
#define RADIO_PCNF1_WHITEEN_ENABLED          (1 << 25)
#define RADIO_PCNF1_WHITEEN_Enabed           (1 << 25)
/**@}*/

/* --- RADIO_PREFIX0 values ------------------------------------------------ */
/** @defgroup radio_prefix0 Set prefix address for logical addresses 0-3
@ingroup radio_defines
@{*/
#define RADIO_PREFIX0_AP0(n)                ((uint8_t)(n) << 0)
#define RADIO_PREFIX0_AP1(n)                ((uint8_t)(n) << 8)
#define RADIO_PREFIX0_AP2(n)                ((uint8_t)(n) << 16)
#define RADIO_PREFIX0_AP3(n)                ((uint8_t)(n) << 24)
/**@}*/

/* --- RADIO_PREFIX1 values ------------------------------------------------ */
/** @defgroup radio_prefix1 Set prefix address for logical addresses 4-7
@ingroup radio_defines
@{*/
#define RADIO_PREFIX1_AP4(n)                ((uint8_t)(n) << 0)
#define RADIO_PREFIX1_AP5(n)                ((uint8_t)(n) << 8)
#define RADIO_PREFIX1_AP6(n)                ((uint8_t)(n) << 16)
#define RADIO_PREFIX1_AP7(n)                ((uint8_t)(n) << 24)
/**@}*/

/* --- RADIO_RXADDRESSES values -------------------------------------------- */
/** @defgroup radio_rxaddresses Select logical address for reception
@ingroup radio_defines
@{*/
#define RADIO_RXADDRESSES_ADDR0_DISABLED        (0 << 0)
#define RADIO_RXADDRESSES_ADDR0_Disabled        (0 << 0)
#define RADIO_RXADDRESSES_ADDR0_ENABLED         (1 << 0)
#define RADIO_RXADDRESSES_ADDR0_Enabled         (1 << 0)
#define RADIO_RXADDRESSES_ADDR1_DISABLED        (0 << 1)
#define RADIO_RXADDRESSES_ADDR1_Disabled        (0 << 1)
#define RADIO_RXADDRESSES_ADDR1_ENABLED         (1 << 1)
#define RADIO_RXADDRESSES_ADDR1_Enabled         (1 << 1)
#define RADIO_RXADDRESSES_ADDR2_DISABLED        (0 << 2)
#define RADIO_RXADDRESSES_ADDR2_Disabled        (0 << 2)
#define RADIO_RXADDRESSES_ADDR2_ENABLED         (1 << 2)
#define RADIO_RXADDRESSES_ADDR2_Enabled         (1 << 2)
#define RADIO_RXADDRESSES_ADDR3_DISABLED        (0 << 3)
#define RADIO_RXADDRESSES_ADDR3_Disabled        (0 << 3)
#define RADIO_RXADDRESSES_ADDR3_ENABLED         (1 << 3)
#define RADIO_RXADDRESSES_ADDR3_Enabled         (1 << 3)
#define RADIO_RXADDRESSES_ADDR4_DISABLED        (0 << 4)
#define RADIO_RXADDRESSES_ADDR4_Disabled        (0 << 4)
#define RADIO_RXADDRESSES_ADDR4_ENABLED         (1 << 4)
#define RADIO_RXADDRESSES_ADDR4_Enabled         (1 << 4)
#define RADIO_RXADDRESSES_ADDR5_DISABLED        (0 << 5)
#define RADIO_RXADDRESSES_ADDR5_Disabled        (0 << 5)
#define RADIO_RXADDRESSES_ADDR5_ENABLED         (1 << 5)
#define RADIO_RXADDRESSES_ADDR5_Enabled         (1 << 5)
#define RADIO_RXADDRESSES_ADDR6_DISABLED        (0 << 6)
#define RADIO_RXADDRESSES_ADDR6_Disabled        (0 << 6)
#define RADIO_RXADDRESSES_ADDR6_ENABLED         (1 << 6)
#define RADIO_RXADDRESSES_ADDR6_Enabled         (1 << 6)
#define RADIO_RXADDRESSES_ADDR7_DISABLED        (0 << 7)
#define RADIO_RXADDRESSES_ADDR7_Disabled        (0 << 7)
#define RADIO_RXADDRESSES_ADDR7_ENABLED         (1 << 7)
#define RADIO_RXADDRESSES_ADDR7_Enabled         (1 << 7)
/**@}*/

/* --- RADIO_CRCCNF values ------------------------------------------------- */
/** @defgroup radio_crccnf Configurates CRC length and CRC calculation
@ingroup radio_defines
@{*/
#define RADIO_CRCCNF_LEN(n)                 ((n)&0x03) //Value 1..3
#define RADIO_CRCCNF_LEN_DISABLED           (0)
#define RADIO_CRCCNF_LEN_Disabled           (0)
#define RADIO_CRCCNF_LEN_ONE                (1)
#define RADIO_CRCCNF_LEN_One                (1)
#define RADIO_CRCCNF_LEN_TWO                (2)
#define RADIO_CRCCNF_LEN_Two                (2)
#define RADIO_CRCCNF_LEN_THREE              (3)
#define RADIO_CRCCNF_LEN_Three              (3)
#define SKIPADDR_INCLUDE                    (0 << 8)
#define RADIO_CRCCNF_SKIPADDR_INCLUDE       (0 << 8)
#define RADIO_CRCCNF_SKIPADDR_Include       (0 << 8)
#define SKIPADDR_SKIP                       (1 << 8)
#define RADIO_CRCCNF_SKIPADDR_SKIP          (1 << 8)
#define RADIO_CRCCNF_SKIPADDR_Skip          (1 << 8)
/**@}*/

/* --- RADIO_STATE values -------------------------------------------------- */
/** @defgroup radio_state Current radio state
@ingroup radio_defines
@{*/
#define RADIO_STATE_STATE_DISABLED             (0)
#define RADIO_STATE_STATE_Disabled             (0)
#define RADIO_STATE_STATE_RXRU                 (1)
#define RADIO_STATE_STATE_RxRu                 (1)
#define RADIO_STATE_STATE_RXIDLE               (2)
#define RADIO_STATE_STATE_RxIdle               (2)
#define RADIO_STATE_STATE_RX                   (3)
#define RADIO_STATE_STATE_Rx                   (3)
#define RADIO_STATE_STATE_RXDISABLE            (4)
#define RADIO_STATE_STATE_RxDisable            (4)
#define RADIO_STATE_STATE_TXRU                 (9)
#define RADIO_STATE_STATE_TxRu                 (9)
#define RADIO_STATE_STATE_TXIDLE               (10)
#define RADIO_STATE_STATE_TxIdle               (10)
#define RADIO_STATE_STATE_TX                   (11)
#define RADIO_STATE_STATE_Tx                   (11)
#define RADIO_STATE_STATE_TXDISABLE            (12)
#define RADIO_STATE_STATE_TxDisable            (12)
/**@}*/

/* --- RADIO_DACNF values -------------------------------------------------- */
/** @defgroup radio_dacnf Configurates device address match
@ingroup radio_defines
@{*/
#define RADIO_DACNF_ENA0_DISABLED         (0 << 0)
#define RADIO_DACNF_ENA0_Disabled         (0 << 0)
#define RADIO_DACNF_ENA0_ENABLED          (1 << 0)
#define RADIO_DACNF_ENA0_Enabled          (1 << 0)
#define RADIO_DACNF_ENA1_DISABLED         (0 << 1)
#define RADIO_DACNF_ENA1_Disabled         (0 << 1)
#define RADIO_DACNF_ENA1_ENABLED          (1 << 1)
#define RADIO_DACNF_ENA1_Enabled          (1 << 1)
#define RADIO_DACNF_ENA2_DISABLED         (0 << 2)
#define RADIO_DACNF_ENA2_Disabled         (0 << 2)
#define RADIO_DACNF_ENA2_ENABLED          (1 << 2)
#define RADIO_DACNF_ENA2_Enabled          (1 << 2)
#define RADIO_DACNF_ENA3_DISABLED         (0 << 3)
#define RADIO_DACNF_ENA3_Disabled         (0 << 3)
#define RADIO_DACNF_ENA3_ENABLED          (1 << 3)
#define RADIO_DACNF_ENA3_Enabled          (1 << 3)
#define RADIO_DACNF_ENA4_DISABLED         (0 << 4)
#define RADIO_DACNF_ENA4_Disabled         (0 << 4)
#define RADIO_DACNF_ENA4_ENABLED          (1 << 4)
#define RADIO_DACNF_ENA4_Enabled          (1 << 4)
#define RADIO_DACNF_ENA5_DISABLED         (0 << 5)
#define RADIO_DACNF_ENA5_Disabled         (0 << 5)
#define RADIO_DACNF_ENA5_ENABLED          (1 << 5)
#define RADIO_DACNF_ENA5_Enabled          (1 << 5)
#define RADIO_DACNF_ENA6_DISABLED         (0 << 6)
#define RADIO_DACNF_ENA6_Disabled         (0 << 6)
#define RADIO_DACNF_ENA6_ENABLED          (1 << 6)
#define RADIO_DACNF_ENA6_Enabled          (1 << 6)
#define RADIO_DACNF_ENA7_DISABLED         (0 << 7)
#define RADIO_DACNF_ENA7_Disabled         (0 << 7)
#define RADIO_DACNF_ENA7_ENABLED          (1 << 7)
#define RADIO_DACNF_ENA7_Enabled          (1 << 7)
#define RADIO_DACNF_TXADD(n)              (1 << (n+8))
#define RADIO_DACNF_TXADD0                (1 << 8)
#define RADIO_DACNF_TXADD1                (1 << 9)
#define RADIO_DACNF_TXADD2                (1 << 10)
#define RADIO_DACNF_TXADD3                (1 << 11)
#define RADIO_DACNF_TXADD4                (1 << 12)
#define RADIO_DACNF_TXADD5                (1 << 13)
#define RADIO_DACNF_TXADD6                (1 << 14)
#define RADIO_DACNF_TXADD7                (1 << 15)
/**@}*/

/* --- RADIO_MODECNF0 values ----------------------------------------------- */
/** @defgroup radio_modecnf0 Configurates radio mode
@ingroup radio_defines
@{*/
#define RADIO_MODECNF0_RU_DEFAULT         (0 << 0)
#define RADIO_MODECNF0_RU_Defaut          (0 << 0)
#define RADIO_MODECNF0_RU_FAST            (1 << 0)
#define RADIO_MODECNF0_RU_Fast            (1 << 0)
#define RADIO_MODECNF0_DTX_B1             (0 << 8)
#define RADIO_MODECNF0_DTX_B0             (1 << 8)
#define RADIO_MODECNF0_DTX_CENTER         (0x2 << 8)
#define RADIO_MODECNF0_DTX_Center         (0x2 << 8)
/**@}*/

/* --- RADIO_POWER values -------------------------------------------------- */
/** @defgroup radio_power Enable/Disable peripheral power control
@ingroup radio_defines
@{*/
#define RADIO_POWER_POWER_DISABLED        (0)
#define RADIO_POWER_POWER_Disabled        (0)
#define RADIO_POWER_POWER_ENABLED         (1)
#define RADIO_POWER_POWER_Enabled         (1)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void radio_set_s0(uint8_t s0len);
void radio_set_lf(uint8_t lflen);
void radio_set_s1(uint8_t s1len, uint32_t s1incl);
void radio_set_maxlen(uint8_t maxlen);
void radio_set_statlen(uint8_t statlen);
void radio_set_endian(uint32_t endian);
void radio_packet_config(uint8_t s0len, uint8_t lflen, uint8_t s1len, 
	uint32_t s1incl, uint8_t maxlen, uint8_t statlen, uint32_t endian);
void radio_preamble(uint32_t plen);
void radio_address_config(uint8_t balen, uint8_t logical, uint32_t base_addr, 
	uint8_t pre_addr);
void radio_txaddress(uint8_t logical);
void radio_rxaddress(uint8_t logical);
void radio_mode(uint32_t mode);
void radio_output_power(uint32_t txpower);
void radio_frequency(uint8_t freq, uint32_t map);
void radio_packet_ptr(uint32_t *ptr);
void radio_tx_enable(void);
void radio_rx_enable(void);
void radio_start(void);
void radio_stop(void);
void radio_disable(void);
uint32_t radio_address_completed(void);
uint32_t radio_payload_completed(void);
uint32_t radio_packet_completed(void);
void radio_packet_completed_reset(void);
void radio_send(uint32_t *ptr);
void radio_send_waiting(uint32_t *ptr);
void radio_interrupt_enable(uint32_t events);
void radio_interrupt_disable(uint32_t events);
bool radio_get_event(char event);
void radio_match(uint8_t logical, uint32_t dab, uint16_t dap);
void radio_crc_config(uint8_t len, uint32_t skipaddr);
void radio_crc_poly(uint32_t crcpoly);
void radio_crc_init(uint32_t crcinit);
void radio_crc(uint8_t len, uint32_t skipaddr, uint32_t crcpoly, 
	uint32_t crcinit);
uint32_t radio_crc_ok(void);
void radio_crc_ok_reset(void);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "radio_common.h should not be included explicitly, only via radio.h"
#endif
/** @endcond */

