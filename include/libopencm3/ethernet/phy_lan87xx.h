/** @defgroup ethernet_phy_lan87xx_defines PHY LAN8710 Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet PHY LAN87xx chips</b>
 *
 * @ingroup ETH
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 6 February 2014
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_PHY_LAN87XX_H
#define LIBOPENCM3_PHY_LAN87XX_H

#include <libopencm3/ethernet/phy.h>

/**@{*/

/*
 * Architecture availability:
 * 
 * A stands for LAN8700
 * B stands for LAN8710A
 * C stands for LAN8720A
 * D stands for LAN8740A
 * E stands for LAN8741A
 * F stands for LAN8742A
 */

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define LAN87XX_BCR				0x00	/* ABCDEF */
#define LAN87XX_BSR				0x01	/* ABCDEF */
#define LAN87XX_PID1				0x02	/* ABCDEF */
#define LAN87XX_PID2				0x03	/* ABCDEF */
#define LAN87XX_ANA				0x04	/* ABCDEF */
#define LAN87XX_ANLPA				0x05	/* ABCDEF */
#define LAN87XX_ANE				0x06	/* ABCDEF */
#define LAN87XX_ANNPTX				0x07	/* ---DEF */
#define LAN87XX_ANNPRX				0x08	/* ---DEF */

#define LAN87XX_MMDACR				0x0D	/* ---DEF */
#define LAN87XX_MMDADR				0x0E	/* ---DEF */

#define LAN87XX_REVISION			0x10	/* A----- */
#define LAN87XX_EDPDNLP				0x10	/* ---DEF */
#define LAN87XX_MCS				0x11	/* ABCDEF */
#define LAN87XX_SM				0x12	/* ABCDEF */

#define LAN87XX_TDRDCR				0x18	/* ---D-F */
#define LAN87XX_TDRCSR				0x19	/* ---D-F */
#define LAN87XX_ERRCNT				0x1A	/* -BCDEF */
#define LAN87XX_CSR				0x1B	/* ABCDEF */
#define LAN87XX_CBLN				0x1C	/* ---D-F */
#define LAN87XX_ISR				0x1D	/* ABCDEF */
#define LAN87XX_IMR				0x1E	/* ABCDEF */
#define LAN87XX_SCSR				0x1F	/* ABCDEF */


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* LAN87XX_BCR --------------------------------------------------------------*/
/* LAN87XX_BSR --------------------------------------------------------------*/
/* LAN87XX_PID1 -------------------------------------------------------------*/
/* LAN87XX_PID2 -------------------------------------------------------------*/
/* LAN87XX_ANA --------------------------------------------------------------*/
/* LAN87XX_ANLPA ------------------------------------------------------------*/
/* LAN87XX_ANE --------------------------------------------------------------*/
/* LAN87XX_ANNPTX -----------------------------------------------------------*/
/* LAN87XX_ANNPRX -----------------------------------------------------------*/

/* LAN87XX_MMDACR -----------------------------------------------------------*/

/* the MMD provides register access into bare PHY chip. MMD provides its own
 * register address space, completely different between devices.
 * It should be implemented later.
 */
 
#define LAN87XX_MMDACR_FUNC_SHIFT		14		/* ---DEF */
#define LAN87XX_MMDACR_FUNC			(3 << LAN87XX_MMDACR_FUNC_SHIFT)
#define LAN87XX_MMDACR_FUNC_ADDRESS		(0 << LAN87XX_MMDACR_FUNC_SHIFT)
#define LAN87XX_MMDACR_FUNC_DATA		(1 << LAN87XX_MMDACR_FUNC_SHIFT)

#define LAN87XX_MMDACR_DEVAD			(31 << 0)	/* ---DEF */
#define LAN87XX_MMDACR_DEVAD_PCS		(3 << 0)	/* ---DEF */
#define LAN87XX_MMDACR_DEVAD_ANN		(7 << 0)	/* ---DE- */
#define LAN87XX_MMDACR_DEVAD_VENDOR		(30 << 0)	/* ---DE- */

/* LAN87XX_MMDADR -----------------------------------------------------------*/

/* LAN87XX_REVISION ---------------------------------------------------------*/
/* note this register is valid only on original LAN8700 */

/* LAN87XX_EDPDNLP ----------------------------------------------------------*/
/* note this register is valid only on newer than original LAN8700 */

#define LAN87XX_EDPDNLP_TXEN			(1 << 15)	/* ---DEF */

#define LAN87XX_EDPDNLP_TXTIM_SHIFT		13		/* ---DEF */
#define LAN87XX_EDPDNLP_TXTIM			(3<<LAN87XX_EDPDNLP_TXTIM_SHIFT)
#define LAN87XX_EDPDNLP_TXTIM_1024MS		(0<<LAN87XX_EDPDNLP_TXTIM_SHIFT)
#define LAN87XX_EDPDNLP_TXTIM_0768MS		(1<<LAN87XX_EDPDNLP_TXTIM_SHIFT)
#define LAN87XX_EDPDNLP_TXTIM_0512MS		(2<<LAN87XX_EDPDNLP_TXTIM_SHIFT)
#define LAN87XX_EDPDNLP_TXTIM_0256MS		(3<<LAN87XX_EDPDNLP_TXTIM_SHIFT)

#define LAN87XX_EDPDNLP_RXWAKEEN		(1 << 12)	/* ---DEF */

#define LAN87XX_EDPDNLP_RXTIM_SHIFT		10		/* ---DEF */
#define LAN87XX_EDPDNLP_RXTIM			(3<<LAN87XX_EDPDNLP_RXTIM_SHIFT)
#define LAN87XX_EDPDNLP_RXTIM_0064MS		(0<<LAN87XX_EDPDNLP_RXTIM_SHIFT)
#define LAN87XX_EDPDNLP_RXTIM_0256MS		(1<<LAN87XX_EDPDNLP_RXTIM_SHIFT)
#define LAN87XX_EDPDNLP_RXTIM_0512MS		(2<<LAN87XX_EDPDNLP_RXTIM_SHIFT)
#define LAN87XX_EDPDNLP_RXTIM_1024MS		(3<<LAN87XX_EDPDNLP_RXTIM_SHIFT)

#define LAN87XX_EDPDNLP_EXTCROSSOVER		(1 << 1)	/* ---DEF */
#define LAN87XX_EDPDNLP_EXTMANCROSSOVER		(1 << 0)	/* ---DEF */

/* LAN87XX_MCS --------------------------------------------------------------*/

#define LAN87XX_MCS_EDPWRDOWN			(1 << 13)	/* ABCDEF */
#define LAN87XX_MCS_LOWSQEN			(1 << 11)	/* A----- */
#define LAN87XX_MCS_MDPREBP			(1 << 10)	/* A----- */
#define LAN87XX_MCS_FARLOOPBACK			(1 << 9)	/* ABCDEF */
#define LAN87XX_MCS_ALTINT			(1 << 6)	/* ABCDEF */
#define LAN87XX_MCS_PHYADBP			(1 << 3)	/* A----- */
#define LAN87XX_MCS_FORCELINK			(1 << 2)	/* A----- */
#define LAN87XX_MCS_ENERGYON			(1 << 1)	/* ABCDEF */

/* LAN87XX_SM ---------------------------------------------------------------*/

/* @LAN8720A: Should write as 1 (only RMII supported) */
/* @LAN8742A: Don't care bit on LAN8742A (only RMII supported) */
#define LAN87XX_SM_MIIMODE			(1 << 14)	/* ABCDE- */
#define LAN87XX_SM_MIIMODE_MII			(0 << 14)	/* ABCDE- */
#define LAN87XX_SM_MIIMODE_RMII			(1 << 14)	/* ABCDE- */

#define LAN87XX_SM_MODE_SHIFT			5		/* ABCDEF */
#define LAN87XX_SM_MODE				(7 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_10HD			(0 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_10FD			(1 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_100HD			(2 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_100FD			(3 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_100HD_AN		(4 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_REPEATER		(5 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_POWERDOWN		(6 << LAN87XX_SM_MODE_SHIFT)
#define LAN87XX_SM_MODE_ALL			(7 << LAN87XX_SM_MODE_SHIFT)

#define LAN87XX_SM_PHYAD			(0x1F << 0)	/* ABCDEF */

/* LAN87XX_TDRDCR -----------------------------------------------------------*/

/*this register is applicable only on @LAN8740A and @LAN8742A */

#define LAN87XX_TDRDCR_DELAY			(15 << 0)	/* ---D-F */
#define LAN87XX_TDRDCR_DELAY			(15 << 0)	/* ---D-F */

#define LAN87XX_TDRDCR_LBCR_SHIFT		12		/* ---D-F */
#define LAN87XX_TDRDCR_LBCR			(7 << LAN87XX_TDRDCR_LBCR_SHIFT)

#define LAN87XX_TDRDCR_LPAT_SHIFT		6		/* ---D-F */
#define LAN87XX_TDRDCR_LPAT			(7 << LAN87XX_TDRDCR_LPAT_SHIFT)

#define LAN87XX_TDRDCR_HPAT_SHIFT		0		/* ---D-F */
#define LAN87XX_TDRDCR_HPAT			(7 << LAN87XX_TDRDCR_HPAT_SHIFT)

/* LAN87XX_TDRCSR -----------------------------------------------------------*/

/*this register is applicable only on @LAN8740A and @LAN8742A */

#define LAN87XX_TDRCSR_ENABLE			(1 << 15)	/* ---D-F */
#define LAN87XX_TDRCSR_ADFILTER			(1 << 14)	/* ---D-F */

#define LAN87XX_TDRCSR_COND_SHIFT		9		/* ---D-F */
#define LAN87XX_TDRCSR_COND_DEFAULT		(0 << LAN87XX_TDRCSR_COND_SHIFT)
#define LAN87XX_TDRCSR_COND_SHORTED		(1 << LAN87XX_TDRCSR_COND_SHIFT)
#define LAN87XX_TDRCSR_COND_OPEN		(2 << LAN87XX_TDRCSR_COND_SHIFT)
#define LAN87XX_TDRCSR_COND_MATCH		(3 << LAN87XX_TDRCSR_COND_SHIFT)

#define LAN87XX_TDRCSR_STATUS			(1 << 8)	/* ---D-F */

/* note for @LAN8742A the coefficients to meters are in table in DS page 55 */
/* note for @LAN8740A the coefficients to meters are in table in DS page 58 */
#define LAN87XX_TDRCSR_LENGTH			(15 << 0)	/* ---D-F */


/* LAN87XX_ERRCNT -----------------------------------------------------------*/

/* 16bit register not applicable for old @LAN8700 */

/* LAN87XX_CSR --------------------------------------------------------------*/

#define LAN87XX_CSR_AMDIXCTRL			(1 << 15)	/* ABCDEF */
#define LAN87XX_CSR_CH_SELECT			(1 << 13)	/* ABCDEF */
#define LAN87XX_CSR_SQEOFF			(1 << 11)	/* ABCDEF */
#define LAN87XX_CSR_XPOL			(1 << 4)	/* ABCDEF */

/* LAN87XX_CBLN --------------------------------------------------------------*/

/* register applicable only on @LAN8740A and LAN8742A */

#define LAN87XX_CBLN_CBLN_SHIFT			12		/* ---D-F */
#define LAN87XX_CBLN_CBLN			(15 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_006M			(4 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_017M			(5 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_027M			(6 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_038M			(7 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_049M			(8 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_059M			(9 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_070M			(10 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_081M			(11 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_091M			(12 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_102M			(13 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_113M			(14 << LAN87XX_CBLN_CBLN_SHIFT)
#define LAN87XX_CBLN_CBLN_123M			(15 << LAN87XX_CBLN_CBLN_SHIFT)


/* LAN87XX_ISR --------------------------------------------------------------*/

#define LAN87XX_ISR_WOLF			(1 << 8)	/* ---D-F */
#define LAN87XX_ISR_ENERGYONF			(1 << 7)	/* ABCDEF */
#define LAN87XX_ISR_ANCOMPF			(1 << 6)	/* ABCDEF */
#define LAN87XX_ISR_RFAULTF			(1 << 5)	/* ABCDEF */
#define LAN87XX_ISR_LINKDOWNF			(1 << 4)	/* ABCDEF */
#define LAN87XX_ISR_ANLPACKF			(1 << 3)	/* ABCDEF */
#define LAN87XX_ISR_PDFAULTF			(1 << 2)	/* ABCDEF */
#define LAN87XX_ISR_ANPAGEF			(1 << 1)	/* ABCDEF */

/* LAN8710_IMR --------------------------------------------------------------*/

#define LAN87XX_IMR_WOLE			(1 << 8)	/* ---D-F */
#define LAN87XX_IMR_ENERGYONE			(1 << 7)	/* ABCDEF */
#define LAN87XX_IMR_ANCOMPE			(1 << 6)	/* ABCDEF */
#define LAN87XX_IMR_RFAULTE			(1 << 5)	/* ABCDEF */
#define LAN87XX_IMR_LINKDOWNE			(1 << 4)	/* ABCDEF */
#define LAN87XX_IMR_ANLPACKE			(1 << 3)	/* ABCDEF */
#define LAN87XX_IMR_PDFAULTE			(1 << 2)	/* ABCDEF */
#define LAN87XX_IMR_ANPAGEE			(1 << 1)	/* ABCDEF */

/* LAN8710_SCSR -------------------------------------------------------------*/

#define LAN87XX_SCSR_AUTODONE			(1 << 12)	/* ABCDEF */

#define LAN87XX_SCSR_GPO2			(1 << 9)	/* A----- */
#define LAN87XX_SCSR_GPO1			(1 << 8)	/* A----- */
#define LAN87XX_SCSR_GPO0			(1 << 7)	/* A----- */

/* @LAN8742A: should write as 1 */
/* @LAN8720A: should write as 1 */ 
#define LAN87XX_SCSR_ENABLE4B5B			(1 << 6)	/* AB-DE- */

#define LAN87XX_SCSR_SPEED_SHIFT		2		/* ABCDEF */
#define LAN87XX_SCSR_SPEED			(7 << LAN87XX_SCSR_SPEED_SHIFT)
#define LAN87XX_SCSR_SPEED_10HD			(1 << LAN87XX_SCSR_SPEED_SHIFT)
#define LAN87XX_SCSR_SPEED_100HD		(2 << LAN87XX_SCSR_SPEED_SHIFT)
#define LAN87XX_SCSR_SPEED_10FD			(5 << LAN87XX_SCSR_SPEED_SHIFT)
#define LAN87XX_SCSR_SPEED_100FD		(6 << LAN87XX_SCSR_SPEED_SHIFT)

#define LAN87XX_SCSR_NOSCRAMBLE			(1 << 0)	/* A----- */

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

/**@}*/


#endif /* LIBOPENCM3_PHY_LAN87XX_H__ */
