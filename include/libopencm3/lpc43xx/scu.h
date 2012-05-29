/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_SCU_H
#define LPC43XX_SCU_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* Pin group base addresses */
#define PIN_GROUP0                      (SCU_BASE + 0x000)
#define PIN_GROUP1                      (SCU_BASE + 0x080)
#define PIN_GROUP2                      (SCU_BASE + 0x100)
#define PIN_GROUP3                      (SCU_BASE + 0x180)
#define PIN_GROUP4                      (SCU_BASE + 0x200)
#define PIN_GROUP5                      (SCU_BASE + 0x280)
#define PIN_GROUP6                      (SCU_BASE + 0x300)
#define PIN_GROUP7                      (SCU_BASE + 0x380)
#define PIN_GROUP8                      (SCU_BASE + 0x400)
#define PIN_GROUP9                      (SCU_BASE + 0x480)
#define PIN_GROUPA                      (SCU_BASE + 0x500)
#define PIN_GROUPB                      (SCU_BASE + 0x580)
#define PIN_GROUPC                      (SCU_BASE + 0x600)
#define PIN_GROUPD                      (SCU_BASE + 0x680)
#define PIN_GROUPE                      (SCU_BASE + 0x700)
#define PIN_GROUPF                      (SCU_BASE + 0x780)

#define PIN0                            0x000
#define PIN1                            0x004
#define PIN2                            0x008
#define PIN3                            0x00C
#define PIN4                            0x010
#define PIN5                            0x014
#define PIN6                            0x018
#define PIN7                            0x01C
#define PIN8                            0x020
#define PIN9                            0x024
#define PIN10                           0x028
#define PIN11                           0x02C
#define PIN12                           0x030
#define PIN13                           0x034
#define PIN14                           0x038
#define PIN15                           0x03C
#define PIN16                           0x040
#define PIN17                           0x044
#define PIN18                           0x048
#define PIN19                           0x04C
#define PIN20                           0x050


/* --- SCU registers ------------------------------------------------------- */

/* Pin configuration registers */

#define SCU_SFS(group, pin)             MMIO32(group + pin)

/* Pins P0_n */
#define SCU_SFSP0_0                     SCU_SFS(PIN_GROUP0, PIN0)
#define SCU_SFSP0_1                     SCU_SFS(PIN_GROUP0, PIN1)

/* Pins P1_n */
#define SCU_SFSP1_0                     SCU_SFS(PIN_GROUP1, PIN0)
#define SCU_SFSP1_1                     SCU_SFS(PIN_GROUP1, PIN1)
#define SCU_SFSP1_2                     SCU_SFS(PIN_GROUP1, PIN2)
#define SCU_SFSP1_3                     SCU_SFS(PIN_GROUP1, PIN3)
#define SCU_SFSP1_4                     SCU_SFS(PIN_GROUP1, PIN4)
#define SCU_SFSP1_5                     SCU_SFS(PIN_GROUP1, PIN5)
#define SCU_SFSP1_6                     SCU_SFS(PIN_GROUP1, PIN6)
#define SCU_SFSP1_7                     SCU_SFS(PIN_GROUP1, PIN7)
#define SCU_SFSP1_8                     SCU_SFS(PIN_GROUP1, PIN8)
#define SCU_SFSP1_9                     SCU_SFS(PIN_GROUP1, PIN9)
#define SCU_SFSP1_10                    SCU_SFS(PIN_GROUP1, PIN10)
#define SCU_SFSP1_11                    SCU_SFS(PIN_GROUP1, PIN11)
#define SCU_SFSP1_12                    SCU_SFS(PIN_GROUP1, PIN12)
#define SCU_SFSP1_13                    SCU_SFS(PIN_GROUP1, PIN13)
#define SCU_SFSP1_14                    SCU_SFS(PIN_GROUP1, PIN14)
#define SCU_SFSP1_15                    SCU_SFS(PIN_GROUP1, PIN15)
#define SCU_SFSP1_16                    SCU_SFS(PIN_GROUP1, PIN16)
#define SCU_SFSP1_17                    SCU_SFS(PIN_GROUP1, PIN17)
#define SCU_SFSP1_18                    SCU_SFS(PIN_GROUP1, PIN18)
#define SCU_SFSP1_19                    SCU_SFS(PIN_GROUP1, PIN19)
#define SCU_SFSP1_20                    SCU_SFS(PIN_GROUP1, PIN20)

/* Pins P2_n */
#define SCU_SFSP2_0                     SCU_SFS(PIN_GROUP2, PIN0)
#define SCU_SFSP2_1                     SCU_SFS(PIN_GROUP2, PIN1)
#define SCU_SFSP2_2                     SCU_SFS(PIN_GROUP2, PIN2)
#define SCU_SFSP2_3                     SCU_SFS(PIN_GROUP2, PIN3)
#define SCU_SFSP2_4                     SCU_SFS(PIN_GROUP2, PIN4)
#define SCU_SFSP2_5                     SCU_SFS(PIN_GROUP2, PIN5)
#define SCU_SFSP2_6                     SCU_SFS(PIN_GROUP2, PIN6)
#define SCU_SFSP2_7                     SCU_SFS(PIN_GROUP2, PIN7)
#define SCU_SFSP2_8                     SCU_SFS(PIN_GROUP2, PIN8)
#define SCU_SFSP2_9                     SCU_SFS(PIN_GROUP2, PIN9)
#define SCU_SFSP2_10                    SCU_SFS(PIN_GROUP2, PIN10)
#define SCU_SFSP2_11                    SCU_SFS(PIN_GROUP2, PIN11)
#define SCU_SFSP2_12                    SCU_SFS(PIN_GROUP2, PIN12)
#define SCU_SFSP2_13                    SCU_SFS(PIN_GROUP2, PIN13)

/* Pins P3_n */
#define SCU_SFSP3_0                     SCU_SFS(PIN_GROUP3, PIN0)
#define SCU_SFSP3_1                     SCU_SFS(PIN_GROUP3, PIN1)
#define SCU_SFSP3_2                     SCU_SFS(PIN_GROUP3, PIN2)
#define SCU_SFSP3_3                     SCU_SFS(PIN_GROUP3, PIN3)
#define SCU_SFSP3_4                     SCU_SFS(PIN_GROUP3, PIN4)
#define SCU_SFSP3_5                     SCU_SFS(PIN_GROUP3, PIN5)
#define SCU_SFSP3_6                     SCU_SFS(PIN_GROUP3, PIN6)
#define SCU_SFSP3_7                     SCU_SFS(PIN_GROUP3, PIN7)
#define SCU_SFSP3_8                     SCU_SFS(PIN_GROUP3, PIN8)

/* Pins P4_n */
#define SCU_SFSP4_0                     SCU_SFS(PIN_GROUP4, PIN0)
#define SCU_SFSP4_1                     SCU_SFS(PIN_GROUP4, PIN1)
#define SCU_SFSP4_2                     SCU_SFS(PIN_GROUP4, PIN2)
#define SCU_SFSP4_3                     SCU_SFS(PIN_GROUP4, PIN3)
#define SCU_SFSP4_4                     SCU_SFS(PIN_GROUP4, PIN4)
#define SCU_SFSP4_5                     SCU_SFS(PIN_GROUP4, PIN5)
#define SCU_SFSP4_6                     SCU_SFS(PIN_GROUP4, PIN6)
#define SCU_SFSP4_7                     SCU_SFS(PIN_GROUP4, PIN7)
#define SCU_SFSP4_8                     SCU_SFS(PIN_GROUP4, PIN8)
#define SCU_SFSP4_9                     SCU_SFS(PIN_GROUP4, PIN9)
#define SCU_SFSP4_10                    SCU_SFS(PIN_GROUP4, PIN10)

/* Pins P5_n */
#define SCU_SFSP5_0                     SCU_SFS(PIN_GROUP5, PIN0)
#define SCU_SFSP5_1                     SCU_SFS(PIN_GROUP5, PIN1)
#define SCU_SFSP5_2                     SCU_SFS(PIN_GROUP5, PIN2)
#define SCU_SFSP5_3                     SCU_SFS(PIN_GROUP5, PIN3)
#define SCU_SFSP5_4                     SCU_SFS(PIN_GROUP5, PIN4)
#define SCU_SFSP5_5                     SCU_SFS(PIN_GROUP5, PIN5)
#define SCU_SFSP5_6                     SCU_SFS(PIN_GROUP5, PIN6)
#define SCU_SFSP5_7                     SCU_SFS(PIN_GROUP5, PIN7)

/* Pins P6_n */
#define SCU_SFSP6_0                     SCU_SFS(PIN_GROUP6, PIN0)
#define SCU_SFSP6_1                     SCU_SFS(PIN_GROUP6, PIN1)
#define SCU_SFSP6_2                     SCU_SFS(PIN_GROUP6, PIN2)
#define SCU_SFSP6_3                     SCU_SFS(PIN_GROUP6, PIN3)
#define SCU_SFSP6_4                     SCU_SFS(PIN_GROUP6, PIN4)
#define SCU_SFSP6_5                     SCU_SFS(PIN_GROUP6, PIN5)
#define SCU_SFSP6_6                     SCU_SFS(PIN_GROUP6, PIN6)
#define SCU_SFSP6_7                     SCU_SFS(PIN_GROUP6, PIN7)
#define SCU_SFSP6_8                     SCU_SFS(PIN_GROUP6, PIN8)
#define SCU_SFSP6_9                     SCU_SFS(PIN_GROUP6, PIN9)
#define SCU_SFSP6_10                    SCU_SFS(PIN_GROUP6, PIN10)
#define SCU_SFSP6_11                    SCU_SFS(PIN_GROUP6, PIN11)
#define SCU_SFSP6_12                    SCU_SFS(PIN_GROUP6, PIN12)

/* Pins P7_n */
#define SCU_SFSP7_0                     SCU_SFS(PIN_GROUP7, PIN0)
#define SCU_SFSP7_1                     SCU_SFS(PIN_GROUP7, PIN1)
#define SCU_SFSP7_2                     SCU_SFS(PIN_GROUP7, PIN2)
#define SCU_SFSP7_3                     SCU_SFS(PIN_GROUP7, PIN3)
#define SCU_SFSP7_4                     SCU_SFS(PIN_GROUP7, PIN4)
#define SCU_SFSP7_5                     SCU_SFS(PIN_GROUP7, PIN5)
#define SCU_SFSP7_6                     SCU_SFS(PIN_GROUP7, PIN6)
#define SCU_SFSP7_7                     SCU_SFS(PIN_GROUP7, PIN7)

/* Pins P8_n */
#define SCU_SFSP8_0                     SCU_SFS(PIN_GROUP8, PIN0)
#define SCU_SFSP8_1                     SCU_SFS(PIN_GROUP8, PIN1)
#define SCU_SFSP8_2                     SCU_SFS(PIN_GROUP8, PIN2)
#define SCU_SFSP8_3                     SCU_SFS(PIN_GROUP8, PIN3)
#define SCU_SFSP8_4                     SCU_SFS(PIN_GROUP8, PIN4)
#define SCU_SFSP8_5                     SCU_SFS(PIN_GROUP8, PIN5)
#define SCU_SFSP8_6                     SCU_SFS(PIN_GROUP8, PIN6)
#define SCU_SFSP8_7                     SCU_SFS(PIN_GROUP8, PIN7)
#define SCU_SFSP8_8                     SCU_SFS(PIN_GROUP8, PIN8)

/* Pins P9_n */
#define SCU_SFSP9_0                     SCU_SFS(PIN_GROUP9, PIN0)
#define SCU_SFSP9_1                     SCU_SFS(PIN_GROUP9, PIN1)
#define SCU_SFSP9_2                     SCU_SFS(PIN_GROUP9, PIN2)
#define SCU_SFSP9_3                     SCU_SFS(PIN_GROUP9, PIN3)
#define SCU_SFSP9_4                     SCU_SFS(PIN_GROUP9, PIN4)
#define SCU_SFSP9_5                     SCU_SFS(PIN_GROUP9, PIN5)
#define SCU_SFSP9_6                     SCU_SFS(PIN_GROUP9, PIN6)

/* Pins PA_n */
#define SCU_SFSPA_0                     SCU_SFS(PIN_GROUPA, PIN0)
#define SCU_SFSPA_1                     SCU_SFS(PIN_GROUPA, PIN1)
#define SCU_SFSPA_2                     SCU_SFS(PIN_GROUPA, PIN2)
#define SCU_SFSPA_3                     SCU_SFS(PIN_GROUPA, PIN3)
#define SCU_SFSPA_4                     SCU_SFS(PIN_GROUPA, PIN4)

/* Pins PB_n */
#define SCU_SFSPB_0                     SCU_SFS(PIN_GROUPB, PIN0)
#define SCU_SFSPB_1                     SCU_SFS(PIN_GROUPB, PIN1)
#define SCU_SFSPB_2                     SCU_SFS(PIN_GROUPB, PIN2)
#define SCU_SFSPB_3                     SCU_SFS(PIN_GROUPB, PIN3)
#define SCU_SFSPB_4                     SCU_SFS(PIN_GROUPB, PIN4)
#define SCU_SFSPB_5                     SCU_SFS(PIN_GROUPB, PIN5)
#define SCU_SFSPB_6                     SCU_SFS(PIN_GROUPB, PIN6)

/* Pins PC_n */
#define SCU_SFSPC_0                     SCU_SFS(PIN_GROUPC, PIN0)
#define SCU_SFSPC_1                     SCU_SFS(PIN_GROUPC, PIN1)
#define SCU_SFSPC_2                     SCU_SFS(PIN_GROUPC, PIN2)
#define SCU_SFSPC_3                     SCU_SFS(PIN_GROUPC, PIN3)
#define SCU_SFSPC_4                     SCU_SFS(PIN_GROUPC, PIN4)
#define SCU_SFSPC_5                     SCU_SFS(PIN_GROUPC, PIN5)
#define SCU_SFSPC_6                     SCU_SFS(PIN_GROUPC, PIN6)
#define SCU_SFSPC_7                     SCU_SFS(PIN_GROUPC, PIN7)
#define SCU_SFSPC_8                     SCU_SFS(PIN_GROUPC, PIN8)
#define SCU_SFSPC_9                     SCU_SFS(PIN_GROUPC, PIN9)
#define SCU_SFSPC_10                    SCU_SFS(PIN_GROUPC, PIN10)
#define SCU_SFSPC_11                    SCU_SFS(PIN_GROUPC, PIN11)
#define SCU_SFSPC_12                    SCU_SFS(PIN_GROUPC, PIN12)
#define SCU_SFSPC_13                    SCU_SFS(PIN_GROUPC, PIN13)
#define SCU_SFSPC_14                    SCU_SFS(PIN_GROUPC, PIN14)

/* Pins PD_n */
#define SCU_SFSPD_0                     SCU_SFS(PIN_GROUPD, PIN0)
#define SCU_SFSPD_1                     SCU_SFS(PIN_GROUPD, PIN1)
#define SCU_SFSPD_2                     SCU_SFS(PIN_GROUPD, PIN2)
#define SCU_SFSPD_3                     SCU_SFS(PIN_GROUPD, PIN3)
#define SCU_SFSPD_4                     SCU_SFS(PIN_GROUPD, PIN4)
#define SCU_SFSPD_5                     SCU_SFS(PIN_GROUPD, PIN5)
#define SCU_SFSPD_6                     SCU_SFS(PIN_GROUPD, PIN6)
#define SCU_SFSPD_7                     SCU_SFS(PIN_GROUPD, PIN7)
#define SCU_SFSPD_8                     SCU_SFS(PIN_GROUPD, PIN8)
#define SCU_SFSPD_9                     SCU_SFS(PIN_GROUPD, PIN9)
#define SCU_SFSPD_10                    SCU_SFS(PIN_GROUPD, PIN10)
#define SCU_SFSPD_11                    SCU_SFS(PIN_GROUPD, PIN11)
#define SCU_SFSPD_12                    SCU_SFS(PIN_GROUPD, PIN12)
#define SCU_SFSPD_13                    SCU_SFS(PIN_GROUPD, PIN13)
#define SCU_SFSPD_14                    SCU_SFS(PIN_GROUPD, PIN14)
#define SCU_SFSPD_15                    SCU_SFS(PIN_GROUPD, PIN15)
#define SCU_SFSPD_16                    SCU_SFS(PIN_GROUPD, PIN16)

/* Pins PE_n */
#define SCU_SFSPE_0                     SCU_SFS(PIN_GROUPE, PIN0)
#define SCU_SFSPE_1                     SCU_SFS(PIN_GROUPE, PIN1)
#define SCU_SFSPE_2                     SCU_SFS(PIN_GROUPE, PIN2)
#define SCU_SFSPE_3                     SCU_SFS(PIN_GROUPE, PIN3)
#define SCU_SFSPE_4                     SCU_SFS(PIN_GROUPE, PIN4)
#define SCU_SFSPE_5                     SCU_SFS(PIN_GROUPE, PIN5)
#define SCU_SFSPE_6                     SCU_SFS(PIN_GROUPE, PIN6)
#define SCU_SFSPE_7                     SCU_SFS(PIN_GROUPE, PIN7)
#define SCU_SFSPE_8                     SCU_SFS(PIN_GROUPE, PIN8)
#define SCU_SFSPE_9                     SCU_SFS(PIN_GROUPE, PIN9)
#define SCU_SFSPE_10                    SCU_SFS(PIN_GROUPE, PIN10)
#define SCU_SFSPE_11                    SCU_SFS(PIN_GROUPE, PIN11)
#define SCU_SFSPE_12                    SCU_SFS(PIN_GROUPE, PIN12)
#define SCU_SFSPE_13                    SCU_SFS(PIN_GROUPE, PIN13)
#define SCU_SFSPE_14                    SCU_SFS(PIN_GROUPE, PIN14)
#define SCU_SFSPE_15                    SCU_SFS(PIN_GROUPE, PIN15)

/* Pins PF_n */
#define SCU_SFSPF_0                     SCU_SFS(PIN_GROUPF, PIN0)
#define SCU_SFSPF_1                     SCU_SFS(PIN_GROUPF, PIN1)
#define SCU_SFSPF_2                     SCU_SFS(PIN_GROUPF, PIN2)
#define SCU_SFSPF_3                     SCU_SFS(PIN_GROUPF, PIN3)
#define SCU_SFSPF_4                     SCU_SFS(PIN_GROUPF, PIN4)
#define SCU_SFSPF_5                     SCU_SFS(PIN_GROUPF, PIN5)
#define SCU_SFSPF_6                     SCU_SFS(PIN_GROUPF, PIN6)
#define SCU_SFSPF_7                     SCU_SFS(PIN_GROUPF, PIN7)
#define SCU_SFSPF_8                     SCU_SFS(PIN_GROUPF, PIN8)
#define SCU_SFSPF_9                     SCU_SFS(PIN_GROUPF, PIN9)
#define SCU_SFSPF_10                    SCU_SFS(PIN_GROUPF, PIN10)
#define SCU_SFSPF_11                    SCU_SFS(PIN_GROUPF, PIN11)

/* CLKn pins */
#define SCU_SFSCLK0                     MMIO32(SCU_BASE + 0xC00)
#define SCU_SFSCLK1                     MMIO32(SCU_BASE + 0xC04)
#define SCU_SFSCLK2                     MMIO32(SCU_BASE + 0xC08)
#define SCU_SFSCLK3                     MMIO32(SCU_BASE + 0xC0C)

/* USB1 USB1_DP/USB1_DM pins and I2C-bus open-drain pins */
#define SCU_SFSUSB                      MMIO32(SCU_BASE + 0xC80)
#define SCU_SFSI2C0                     MMIO32(SCU_BASE + 0xC84)


/* ADC pin select registers */

/* ADC0 function select register */
#define SCU_ENAIO0                      MMIO32(SCU_BASE + 0xC88)

/* ADC1 function select register */
#define SCU_ENAIO1                      MMIO32(SCU_BASE + 0xC8C)

/* Analog function select register */
#define SCU_ENAIO2                      MMIO32(SCU_BASE + 0xC90)


/* EMC clock delay register */
#define SCU_EMCDELAYCLK                 MMIO32(SCU_BASE + 0xD00)


/* Pin interrupt select registers */

/* Pin interrupt select register for pin interrupts 0 to 3 */
#define SCU_PINTSEL0                    MMIO32(SCU_BASE + 0xE00)

/* Pin interrupt select register for pin interrupts 4 to 7 */
#define SCU_PINTSEL1                    MMIO32(SCU_BASE + 0xE00)

#endif
