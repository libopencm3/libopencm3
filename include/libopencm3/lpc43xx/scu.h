/** @defgroup scu_defines System Control Unit Defines

@brief <b>Defined Constants and Types for the LPC43xx System Control Unit</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
* This file is part of the libopencm3 project.
*
* Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_SCU_H
#define LPC43XX_SCU_H

/**@{*/

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

#define SCU_SFS(group, pin)             MMIO32((group) + (pin))

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
#define SCU_PINTSEL1                    MMIO32(SCU_BASE + 0xE04)

/**************************/
/* SCU I2C0 Configuration */
/**************************/
/*
* Select input glitch filter time constant for the SCL pin.
*  0 = 50 ns glitch filter.
*  1 = 3ns glitch filter.
*/
#define SCU_SCL_EFP    (BIT0)

/* BIT1 Reserved. Always write a 0 to this bit. */

/*
* Select I2C mode for the SCL pin.
*  0 = Standard/Fast mode transmit.
*  1 = Fast-mode Plus transmit.
*/
#define SCU_SCL_EHD    (BIT2)

/*
* Enable the input receiver for the SCL pin.
* Always write a 1 to this bit when using the
* I2C0.
*  0 = Disabled.
*  1 = Enabled.
*/
#define SCU_SCL_EZI_EN    (BIT3)

/* BIT4-6 Reserved. */

/*
* Enable or disable input glitch filter for the
* SCL pin. The filter time constant is
* determined by bit EFP.
*  0 = Enable input filter.
*  1 = Disable input filter.
*/
#define SCU_SCL_ZIF_DIS    (BIT7)

/*
* Select input glitch filter time constant for the SDA pin.
*  0 = 50 ns glitch filter.
*  1 = 3ns glitch filter.
*/
#define SCU_SDA_EFP    (BIT8)

/* BIT9 Reserved. Always write a 0 to this bit. */

/*
* Select I2C mode for the SDA pin.
*  0 = Standard/Fast mode transmit.
*  1 = Fast-mode Plus transmit.
*/
#define SCU_SDA_EHD    (BIT10)

/*
* Enable the input receiver for the SDA pin.
* Always write a 1 to this bit when using the
* I2C0.
*  0 = Disabled.
*  1 = Enabled.
*/
#define SCU_SDA_EZI_EN    (BIT11)

/* BIT 12-14 - Reserved */

/*
* Enable or disable input glitch filter for the
* SDA pin. The filter time constant is
* determined by bit SDA_EFP.
*  0 = Enable input filter.
*   1 = Disable input filter.
*/
#define SCU_SDA_ZIF_DIS    (BIT15)

/* Standard mode for I2C SCL/SDA Standard/Fast mode */
#define SCU_I2C0_NOMINAL    (SCU_SCL_EZI_EN | SCU_SDA_EZI_EN)

/* Standard mode for I2C SCL/SDA Fast-mode Plus transmit */
#define SCU_I2C0_FAST    (SCU_SCL_EFP | SCU_SCL_EHD | SCU_SCL_EZI_EN | \
			  SCU_SCL_ZIF_DIS | SCU_SDA_EFP | SCU_SDA_EHD | \
			  SCU_SDA_EZI_EN)

/*
* SCU PIN Normal Drive:
* The configuration registers for normal-drive pins control the following pins:
*  - P0_0 and P0_1
*  - P1_0 to P1_16 and P1_18 to P1_20
*  - P2_0 to P2_2 and P2_6 to P2_13
*  - P3_0 to P3_2 and P3_4 to P3_8
*  - P4_0 to P4_10
*  - P5_0 to P5_7
*  - P6_0 to P6_12
*  - P7_0 to P7_7
*  - P8_3 to P8_8
*  - P9_0 to P9_6
*  - PA_0 and PA_4
*  - PB_0 to PB_6
*  - PC_0 to PC_14
*  - PE_0 to PE_15
*  - PF_0 to PF_11
*
* Pin configuration registers for High-Drive pins.
* The configuration registers for high-drive pins control the following pins:
*  - P1_17
*  - P2_3 to P2_5
*  - P8_0 to P8_2
*  - PA_1 to PA_3
*
* Pin configuration registers for High-Speed pins.
* This register controls the following pins:
*  - P3_3 and pins CLK0 to CLK3.
*/
typedef enum {
	/* Group Port 0 */
	P0_0 = (PIN_GROUP0+PIN0),
	P0_1 = (PIN_GROUP0+PIN1),

	/* Group Port 1 */
	P1_0  = (PIN_GROUP1+PIN0),
	P1_1  = (PIN_GROUP1+PIN1),
	P1_2  = (PIN_GROUP1+PIN2),
	P1_3  = (PIN_GROUP1+PIN3),
	P1_4  = (PIN_GROUP1+PIN4),
	P1_5  = (PIN_GROUP1+PIN5),
	P1_6  = (PIN_GROUP1+PIN6),
	P1_7  = (PIN_GROUP1+PIN7),
	P1_8  = (PIN_GROUP1+PIN8),
	P1_9  = (PIN_GROUP1+PIN9),
	P1_10 = (PIN_GROUP1+PIN10),
	P1_11 = (PIN_GROUP1+PIN11),
	P1_12 = (PIN_GROUP1+PIN12),
	P1_13 = (PIN_GROUP1+PIN13),
	P1_14 = (PIN_GROUP1+PIN14),
	P1_15 = (PIN_GROUP1+PIN15),
	P1_16 = (PIN_GROUP1+PIN16),

	/* P1_17 is High-Drive pin */
	P1_17 = (PIN_GROUP1+PIN17),

	P1_18 = (PIN_GROUP1+PIN18),
	P1_19 = (PIN_GROUP1+PIN19),
	P1_20 = (PIN_GROUP1+PIN20),

	/* Group Port 2 */
	P2_0  = (PIN_GROUP2+PIN0),
	P2_1  = (PIN_GROUP2+PIN1),
	P2_2  = (PIN_GROUP2+PIN2),

	/* P2_3 to P2_5 are High-Drive pins */
	P2_3  = (PIN_GROUP2+PIN3),
	P2_4  = (PIN_GROUP2+PIN4),
	P2_5  = (PIN_GROUP2+PIN5),

	P2_6  = (PIN_GROUP2+PIN6),
	P2_7  = (PIN_GROUP2+PIN7),
	P2_8  = (PIN_GROUP2+PIN8),
	P2_9  = (PIN_GROUP2+PIN9),
	P2_10 = (PIN_GROUP2+PIN10),
	P2_11 = (PIN_GROUP2+PIN11),
	P2_12 = (PIN_GROUP2+PIN12),
	P2_13 = (PIN_GROUP2+PIN13),

	/* Group Port 3 */
	P3_0  = (PIN_GROUP3+PIN0),
	P3_1  = (PIN_GROUP3+PIN1),
	P3_2  = (PIN_GROUP3+PIN2),

	/* P3_3 is High-Speed pin */
	P3_3  = (PIN_GROUP3+PIN3),

	P3_4  = (PIN_GROUP3+PIN4),
	P3_5  = (PIN_GROUP3+PIN5),
	P3_6  = (PIN_GROUP3+PIN6),
	P3_7  = (PIN_GROUP3+PIN7),
	P3_8  = (PIN_GROUP3+PIN8),

	/* Group Port 4 */
	P4_0  = (PIN_GROUP4+PIN0),
	P4_1  = (PIN_GROUP4+PIN1),
	P4_2  = (PIN_GROUP4+PIN2),
	P4_3  = (PIN_GROUP4+PIN3),
	P4_4  = (PIN_GROUP4+PIN4),
	P4_5  = (PIN_GROUP4+PIN5),
	P4_6  = (PIN_GROUP4+PIN6),
	P4_7  = (PIN_GROUP4+PIN7),
	P4_8  = (PIN_GROUP4+PIN8),
	P4_9  = (PIN_GROUP4+PIN9),
	P4_10 = (PIN_GROUP4+PIN10),

	/* Group Port 5 */
	P5_0  = (PIN_GROUP5+PIN0),
	P5_1  = (PIN_GROUP5+PIN1),
	P5_2  = (PIN_GROUP5+PIN2),
	P5_3  = (PIN_GROUP5+PIN3),
	P5_4  = (PIN_GROUP5+PIN4),
	P5_5  = (PIN_GROUP5+PIN5),
	P5_6  = (PIN_GROUP5+PIN6),
	P5_7  = (PIN_GROUP5+PIN7),

	/* Group Port 6 */
	P6_0  = (PIN_GROUP6+PIN0),
	P6_1  = (PIN_GROUP6+PIN1),
	P6_2  = (PIN_GROUP6+PIN2),
	P6_3  = (PIN_GROUP6+PIN3),
	P6_4  = (PIN_GROUP6+PIN4),
	P6_5  = (PIN_GROUP6+PIN5),
	P6_6  = (PIN_GROUP6+PIN6),
	P6_7  = (PIN_GROUP6+PIN7),
	P6_8  = (PIN_GROUP6+PIN8),
	P6_9  = (PIN_GROUP6+PIN9),
	P6_10 = (PIN_GROUP6+PIN10),
	P6_11 = (PIN_GROUP6+PIN11),
	P6_12 = (PIN_GROUP6+PIN12),

	/* Group Port 7 */
	P7_0  = (PIN_GROUP7+PIN0),
	P7_1  = (PIN_GROUP7+PIN1),
	P7_2  = (PIN_GROUP7+PIN2),
	P7_3  = (PIN_GROUP7+PIN3),
	P7_4  = (PIN_GROUP7+PIN4),
	P7_5  = (PIN_GROUP7+PIN5),
	P7_6  = (PIN_GROUP7+PIN6),
	P7_7  = (PIN_GROUP7+PIN7),

	/* Group Port 8 */
	/* P8_0 to P8_2 are High-Drive pins */
	P8_0  = (PIN_GROUP8+PIN0),
	P8_1  = (PIN_GROUP8+PIN1),
	P8_2  = (PIN_GROUP8+PIN2),

	P8_3  = (PIN_GROUP8+PIN3),
	P8_4  = (PIN_GROUP8+PIN4),
	P8_5  = (PIN_GROUP8+PIN5),
	P8_6  = (PIN_GROUP8+PIN6),
	P8_7  = (PIN_GROUP8+PIN7),
	P8_8  = (PIN_GROUP8+PIN8),

	/* Group Port 9 */
	P9_0  = (PIN_GROUP9+PIN0),
	P9_1  = (PIN_GROUP9+PIN1),
	P9_2  = (PIN_GROUP9+PIN2),
	P9_3  = (PIN_GROUP9+PIN3),
	P9_4  = (PIN_GROUP9+PIN4),
	P9_5  = (PIN_GROUP9+PIN5),
	P9_6  = (PIN_GROUP9+PIN6),

	/* Group Port A */
	PA_0  = (PIN_GROUPA+PIN0),
	/* PA_1 to PA_3 are Normal & High-Drive Pins */
	PA_1  = (PIN_GROUPA+PIN1),
	PA_2  = (PIN_GROUPA+PIN2),
	PA_3  = (PIN_GROUPA+PIN3),
	PA_4  = (PIN_GROUPA+PIN4),

	/* Group Port B */
	PB_0   = (PIN_GROUPB+PIN0),
	PB_1   = (PIN_GROUPB+PIN1),
	PB_2   = (PIN_GROUPB+PIN2),
	PB_3   = (PIN_GROUPB+PIN3),
	PB_4   = (PIN_GROUPB+PIN4),
	PB_5   = (PIN_GROUPB+PIN5),
	PB_6   = (PIN_GROUPB+PIN6),

	/* Group Port C */
	PC_0   = (PIN_GROUPC+PIN0),
	PC_1   = (PIN_GROUPC+PIN1),
	PC_2   = (PIN_GROUPC+PIN2),
	PC_3   = (PIN_GROUPC+PIN3),
	PC_4   = (PIN_GROUPC+PIN4),
	PC_5   = (PIN_GROUPC+PIN5),
	PC_6   = (PIN_GROUPC+PIN6),
	PC_7   = (PIN_GROUPC+PIN7),
	PC_8   = (PIN_GROUPC+PIN8),
	PC_9   = (PIN_GROUPC+PIN9),
	PC_10  = (PIN_GROUPC+PIN10),
	PC_11  = (PIN_GROUPC+PIN11),
	PC_12  = (PIN_GROUPC+PIN12),
	PC_13  = (PIN_GROUPC+PIN13),
	PC_14  = (PIN_GROUPC+PIN14),

	/* Group Port D (seems not configurable through SCU, not defined in
	 * UM10503.pdf Rev.1, keep it here)
	 */
	PD_0   = (PIN_GROUPD+PIN0),
	PD_1   = (PIN_GROUPD+PIN1),
	PD_2   = (PIN_GROUPD+PIN2),
	PD_3   = (PIN_GROUPD+PIN3),
	PD_4   = (PIN_GROUPD+PIN4),
	PD_5   = (PIN_GROUPD+PIN5),
	PD_6   = (PIN_GROUPD+PIN6),
	PD_7   = (PIN_GROUPD+PIN7),
	PD_8   = (PIN_GROUPD+PIN8),
	PD_9   = (PIN_GROUPD+PIN9),
	PD_10  = (PIN_GROUPD+PIN10),
	PD_11  = (PIN_GROUPD+PIN11),
	PD_12  = (PIN_GROUPD+PIN12),
	PD_13  = (PIN_GROUPD+PIN13),
	PD_14  = (PIN_GROUPD+PIN14),
	PD_15  = (PIN_GROUPD+PIN15),
	PD_16  = (PIN_GROUPD+PIN16),

	/* Group Port E */
	PE_0   = (PIN_GROUPE+PIN0),
	PE_1   = (PIN_GROUPE+PIN1),
	PE_2   = (PIN_GROUPE+PIN2),
	PE_3   = (PIN_GROUPE+PIN3),
	PE_4   = (PIN_GROUPE+PIN4),
	PE_5   = (PIN_GROUPE+PIN5),
	PE_6   = (PIN_GROUPE+PIN6),
	PE_7   = (PIN_GROUPE+PIN7),
	PE_8   = (PIN_GROUPE+PIN8),
	PE_9   = (PIN_GROUPE+PIN9),
	PE_10  = (PIN_GROUPE+PIN10),
	PE_11  = (PIN_GROUPE+PIN11),
	PE_12  = (PIN_GROUPE+PIN12),
	PE_13  = (PIN_GROUPE+PIN13),
	PE_14  = (PIN_GROUPE+PIN14),
	PE_15  = (PIN_GROUPE+PIN15),

	/* Group Port F */
	PF_0   = (PIN_GROUPF+PIN0),
	PF_1   = (PIN_GROUPF+PIN1),
	PF_2   = (PIN_GROUPF+PIN2),
	PF_3   = (PIN_GROUPF+PIN3),
	PF_4   = (PIN_GROUPF+PIN4),
	PF_5   = (PIN_GROUPF+PIN5),
	PF_6   = (PIN_GROUPF+PIN6),
	PF_7   = (PIN_GROUPF+PIN7),
	PF_8   = (PIN_GROUPF+PIN8),
	PF_9   = (PIN_GROUPF+PIN9),
	PF_10  = (PIN_GROUPF+PIN10),
	PF_11  = (PIN_GROUPF+PIN11),

	/* Group Clock 0 to 3 High-Speed pins */
	CLK0 = (SCU_BASE + 0xC00),
	CLK1 = (SCU_BASE + 0xC04),
	CLK2 = (SCU_BASE + 0xC08),
	CLK3 = (SCU_BASE + 0xC0C)

} scu_grp_pin_t;

/*
* Pin Configuration to be used for scu_pinmux() parameter scu_conf
* For normal-drive pins, high-drive pins, high-speed pins
*/
/*
* Function BIT0 to 2.
* Common to normal-drive pins, high-drive pins, high-speed pins.
*/
#define SCU_CONF_FUNCTION0    (0x0)
#define SCU_CONF_FUNCTION1    (0x1)
#define SCU_CONF_FUNCTION2    (0x2)
#define SCU_CONF_FUNCTION3    (0x3)
#define SCU_CONF_FUNCTION4    (0x4)
#define SCU_CONF_FUNCTION5    (0x5)
#define SCU_CONF_FUNCTION6    (0x6)
#define SCU_CONF_FUNCTION7    (0x7)

/*
* Enable pull-down resistor at pad
* By default=0 Disable pull-down.
* Available to normal-drive pins, high-drive pins, high-speed pins
*/
#define SCU_CONF_EPD_EN_PULLDOWN        (BIT3)

/*
* Disable pull-up resistor at pad.
* By default=0 the pull-up resistor is enabled at reset.
* Available to normal-drive pins, high-drive pins, high-speed pins
*/
#define SCU_CONF_EPUN_DIS_PULLUP        (BIT4)

/*
* Select Slew Rate.
* By Default=0 Slow.
* Available to normal-drive and high-speed pins, reserved for high-drive pins.
*/
#define SCU_CONF_EHS_FAST                (BIT5)

/*
* Input buffer enable.
* By Default=0 Disable Input Buffer.
* The input buffer is disabled by default at reset and must be enabled for
* receiving(in normal/highspeed-drive) or to transfer data from the I/O buffer
* to the pad(in high-drive pins).
* Available to normal-drive pins, high-drive pins, high-speed pins.
*/
#define SCU_CONF_EZI_EN_IN_BUFFER        (BIT6)

/*
* Input glitch filter. Disable the input glitch filter for clocking signals
* higher than 30 MHz.
* Available to normal-drive pins, high-drive pins, high-speed pins.
*/
#define SCU_CONF_ZIF_DIS_IN_GLITCH_FILT    (BIT7)

/*
* Select drive strength. (default=0 Normal-drive: 4 mA drive strength) (BIT8/9).
* Available to high-drive pins, reserved for others.
*/
#define SCU_CONF_EHD_NORMAL_DRIVE_8MILLIA    (0x100)
#define SCU_CONF_EHD_NORMAL_DRIVE_14MILLIA    (0x200)
#define SCU_CONF_EHD_NORMAL_DRIVE_20MILLIA    (0x300)

/* BIT10 to 31 are Reserved */

/* Configuration for different I/O pins types */
#define SCU_EMC_IO      (SCU_CONF_EPD_EN_PULLDOWN | \
			 SCU_CONF_EHS_FAST | \
			 SCU_CONF_EZI_EN_IN_BUFFER | \
			 SCU_CONF_ZIF_DIS_IN_GLITCH_FILT)
#define SCU_LCD         (SCU_CONF_EPUN_DIS_PULLUP | \
			 SCU_CONF_EHS_FAST | \
			 SCU_CONF_EZI_EN_IN_BUFFER | \
			 SCU_CONF_ZIF_DIS_IN_GLITCH_FILT)
#define SCU_CLK_IN      (SCU_CONF_EPD_EN_PULLDOWN | \
			 SCU_CONF_EHS_FAST | \
			 SCU_CONF_EZI_EN_IN_BUFFER | \
			 SCU_CONF_ZIF_DIS_IN_GLITCH_FILT)
#define SCU_CLK_OUT     (SCU_CONF_EPD_EN_PULLDOWN | \
			 SCU_CONF_EHS_FAST | \
			 SCU_CONF_EZI_EN_IN_BUFFER | \
			 SCU_CONF_ZIF_DIS_IN_GLITCH_FILT)
#define SCU_GPIO_PUP    (SCU_CONF_EZI_EN_IN_BUFFER)
#define SCU_GPIO_PDN    (SCU_CONF_EPUN_DIS_PULLUP | \
			 SCU_CONF_EPD_EN_PULLDOWN | \
			 SCU_CONF_EZI_EN_IN_BUFFER)
#define SCU_GPIO_NOPULL (SCU_CONF_EPUN_DIS_PULLUP | \
			 SCU_CONF_EZI_EN_IN_BUFFER)
#define SCU_GPIO_FAST   (SCU_CONF_EPUN_DIS_PULLUP | \
			 SCU_CONF_EHS_FAST | \
			 SCU_CONF_EZI_EN_IN_BUFFER | \
			 SCU_CONF_ZIF_DIS_IN_GLITCH_FILT)
#define SCU_UART_RX_TX  (SCU_CONF_EPUN_DIS_PULLUP | \
			 SCU_CONF_EPD_EN_PULLDOWN | \
			 SCU_CONF_EZI_EN_IN_BUFFER)
#define SCU_SSP_IO      (SCU_CONF_EPUN_DIS_PULLUP | \
			 SCU_CONF_EHS_FAST | \
			 SCU_CONF_EZI_EN_IN_BUFFER | \
			 SCU_CONF_ZIF_DIS_IN_GLITCH_FILT)

BEGIN_DECLS

void scu_pinmux(scu_grp_pin_t group_pin, uint32_t scu_conf);

END_DECLS

/**@}*/

#endif
