/** @defgroup ethernet_phy_ksz80x1_defines PHY KSZ80X1 Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet PHY KSZ80X1 chips
 * chips</b>
 *
 * @ingroup ETH
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 1 September 2013
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

#ifndef LIBOPENCM3_PHY_KSZ80X1_H
#define LIBOPENCM3_PHY_KSZ80X1_H

#include <libopencm3/ethernet/phy.h>

/**@{*/

/*
 * Architecture availability:
 *
 * A stands for KSZ8001 / KSZ8001L
 * B stands for KSZ8021RNL / KSZ8031RNL 
 * C stands for KSZ8041NL / KSZ8041NLJ
 * D stands for KSZ8041RNL
 * E stands for KSZ8041TL / KSZ8041FTL / KSZ8041MLL
 * F stands for KSZ8051MLL
 * G stands for KSZ8051MNL / KSZ8051RNL
 * H stands for KSZ8051MNLU / KSZ8051RNLU 
 * I stands for KSZ8081MLX /KSZ8081MNX / KSZ8081RNB
 * J stands for KSZ8081RNA / KSZ8081RND
 * K stands for KSZ8091MLX / KSZ8091MNX / KSZ8091RNB
 * L stands for KSZ8091RNA / KSZ8091RND
 *  
 * No sign marks available for all
 */

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define KSZ80X1_BCR				0x00	/* ABCDEFGHIJKL */
#define KSZ80X1_BSR				0x01	/* ABCDEFGHIJKL */
#define KSZ80X1_ID1				0x02	/* ABCDEFGHIJKL */
#define KSZ80X1_ID2				0x03	/* ABCDEFGHIJKL */
#define KSZ80X1_ANTX				0x04	/* ABCDEFGHIJKL */
#define KSZ80X1_ANRX				0x05	/* ABCDEFGHIJKL */
#define KSZ80X1_ANEXP				0x06	/* ABCDEFGHIJKL */
#define KSZ80X1_ANNPTX				0x07	/* ABCDEFGHIJKL */
#define KSZ80X1_ANNPRX				0x08	/* ABCDEFGHIJKL */

#define KSZ80X1_MMDCR				0x0D	/* ----------KL */
#define KSZ80X1_MMDAR				0x0E	/* ----------KL */

#define KSZ80X1_DRCTRL				0x10	/* -B-----HIJKL */
#define KSZ80X1_AFECTRL				0x11	/* -B---FGHIJKL */
#define KSZ80X1_AFECTRL4			0x13	/* ----------KL */
#define KSZ80X1_MIICTRL				0x14	/* ---DE------- */
#define KSZ80X1_RXERCTR				0x15	/* ABCDEFGHIJKL */
#define KSZ80X1_STRAPOVRD			0x16	/* -B---FGHIJKL */
#define KSZ80X1_STRAPSTAT			0x17	/* -B---FGHIJKL */
#define KSZ80X1_ECR				0x18	/* -B---FGHIJKL */

#define KSZ80X1_ICSR				0x1B	/* ABCDEFGHIJKL */

#define KSZ80X1_LINKMD				0x1D	/* AB--EFGHIJKL */
#define KSZ80X1_CR1				0x1E	/* ABCDEFGHIJKL */
#define KSZ80X1_CR2				0x1F	/* ABCDEFGHIJKL */

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* KSZ80X1_BCR --------------------------------------------------------------*/
/* KSZ80X1_BSR --------------------------------------------------------------*/
/* KSZ80X1_ID1 --------------------------------------------------------------*/
/* KSZ80X1_ID2 --------------------------------------------------------------*/
/* KSZ80X1_ANTX -------------------------------------------------------------*/
/* KSZ80X1_ANRX -------------------------------------------------------------*/
/* KSZ80X1_ANEXP ------------------------------------------------------------*/
/* KSZ80X1_ANNPTX -----------------------------------------------------------*/
/* KSZ80X1_ANNPRX -----------------------------------------------------------*/

/* KSZ80X1_MMDCR ------------------------------------------------------------*/

#define KSZ80X1_MMDCR_OPMODE			(3 << 14) /* ----------KL */
#define KSZ80X1_MMDCR_OPMODE_REGISTER		(0 << 14) /* ----------KL */
#define KSZ80X1_MMDCR_OPMODE_DATA		(1 << 14) /* ----------KL */
#define KSZ80X1_MMDCR_OPMODE_DATA_POSTINC	(2 << 14) /* ----------KL */
#define KSZ80X1_MMDCR_OPMODE_DATA_WPOSTINC	(3 << 14) /* ----------KL */

#define KSZ80X1_MMDCR_DEVADDR			(31 << 14) /* ----------KL */

/* KSZ80X1_MMDAR ------------------------------------------------------------*/

/* KSZ80X1_DRCTRL -----------------------------------------------------------*/

#define KSZ80X1_DRCTRL_PLLOFF			(1 << 4) /* -B-----HIJKL */

/* KSZ80X1_AFECTRL ----------------------------------------------------------*/

#define KSZ80X1_AFECTRL_SLOWOSC			(1 << 5) /* -B---FGHIJKL */

/* KSZ80X1_AFECTRL4 ---------------------------------------------------------*/

#define KSZ80X1_AFECTRL4_10TE			(1 << 4) /* ----------KL */

/* KSZ80X1_MIICTRL ----------------------------------------------------------*/
#define KSZ8051_MIICTRL_PREAM_RESTORE_100M		(1 << 7) /* ---DE------ */
#define KSZ8051_MIICTRL_PREAM_RESTORE_10M		(1 << 6) /* ---DE------ */

/* KSZ80X1_RXERCTR ----------------------------------------------------------*/

/* KSZ8051_STRAPOVRD --------------------------------------------------------*/

/* strapping options availability depends on MII/RMII availability on chip */

#define KSZ80X1_STRAPOVRD_FACTORY		(1 << 15) /* --------IJ-- */
#define KSZ80X1_STRAPOVRD_PMEWOL		(1 << 15) /* ----------KL */
#define KSZ80X1_STRAPOVRD_BCASTOFF		(1 << 9) /* -----FGHIJKL */
#define KSZ80X1_STRAPOVRD_MIIBTOB		(1 << 7) /* -----FGHI-K- */
#define KSZ80X1_STRAPOVRD_RMIIBTOB		(1 << 6) /* -B----GHIJKL */
#define KSZ80X1_STRAPOVRD_NANDTREE		(1 << 5) /* -B---FGHIJK- */
#define KSZ80X1_STRAPOVRD_RMIIOVRD		(1 << 1) /* -B----GHIJKL */
#define KSZ80X1_STRAPOVRD_MIIOVRD		(1 << 0) /* -----FGHI-K- */

/* KSZ80X1_STRAPSTAT --------------------------------------------------------*/

/* strapping options availability depends on MII/RMII availability on chip */
/* KSZ8021/KSZ8031/KSZ8091RNA/KSZ8091RND supports phy address 0 and 3 only! */

#define KSZ80X1_STRAPSTAT_PHYAD_SHIFT		13	/* -B---FGHIJKL */
#define KSZ80X1_STRAPSTAT_PHYAD		(7 << KSZ8051_STRAPSTAT_PHYAD_SHIFT)

#define KSZ80X1_STRAPSTAT_BCASTOFF		(1 << 9) /* -----FGHI-K- */
#define KSZ80X1_STRAPSTAT_MIIBTOB		(1 << 7) /* -----FGHI-K- */
#define KSZ80X1_STRAPSTAT_RMIIBTOB		(1 << 6) /* ------GHI-K- */
#define KSZ80X1_STRAPSTAT_NANDTREE		(1 << 5) /* -----FGHI-K- */
#define KSZ80X1_STRAPSTAT_RMII			(1 << 1) /* -B----GHIJKL */
#define KSZ80X1_STRAPSTAT_MII			(1 << 0) /* -----FGHI-K- */

/* KSZ80X1_ECR --------------------------------------------------------------*/

#define KSZ8051_ECR_EDPDDIS			(1 << 11) /* -B---FGHIJKL */
#define KSZ8051_ECR_100TXPREAMBLE		(1 << 10) /* -----FGHI-K- */
#define KSZ8051_ECR_10TXPREAMBLE		(1 << 6)  /* -----FGHI-K- */

/* KSZ80X1_ICSR -------------------------------------------------------------*/

#define KSZ80X1_ICSR_JABIE			(1 << 15) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_RERRIE			(1 << 14) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_PRIE			(1 << 13) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_PDFLTIE			(1 << 12) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_LPACKIE			(1 << 11) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_LDIE			(1 << 10) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_RFAULTIE			(1 << 9) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_LINKUPIE			(1 << 8) /* ABCDEFGHIJKL */

#define KSZ80X1_ICSR_JABIF			(1 << 7) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_RERRIF			(1 << 6) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_PRIF			(1 << 5) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_PDFLTIF			(1 << 4) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_LPACKIF			(1 << 3) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_LDIF			(1 << 2) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_RFAULTIF			(1 << 1) /* ABCDEFGHIJKL */
#define KSZ80X1_ICSR_LINKUPIF			(1 << 0) /* ABCDEFGHIJKL */

/* KSZ80X1_LINKMD -----------------------------------------------------------*/

#define KSZ80X1_LINKMD_TESTEN			(1 << 15) /* AB--EFGHIJKL */

#define KSZ80X1_LINKMD_TESTRES			(3 << 13) /* AB--EFGHIJKL */
#define KSZ80X1_LINKMD_TESTRES_NORMAL		(0 << 13) /* AB--EFGHIJKL */
#define KSZ80X1_LINKMD_TESTRES_OPEN		(1 << 13) /* AB--EFGHIJKL */
#define KSZ80X1_LINKMD_TESTRES_SHORT		(2 << 13) /* AB--EFGHIJKL */
#define KSZ80X1_LINKMD_TESTRES_FAILED		(3 << 13) /* AB--EFGHIJKL */

#define KSZ80X1_LINKMD_SHORTCABLE		(1 << 12)  /* -----FGHIJKL */
#define KSZ80X1_LINKMD_DISTANCE			(0x1FF << 0) /* AB--EFGHIJKL */

/* KSZ80X1_CR1 --------------------------------------------------------------*/

/* family set 1, "8041" when conflicts arise */

#define KSZ80X1_CR1_LEDMODE			(3 << 14) /* A-CDE------- */
#define KSZ80X1_CR1_LEDMODE_COL_FD_SPD_LNK	(0 << 14) /* A---------- */
#define KSZ80X1_CR1_LEDMODE_ACT_FD_SPD_LNK	(1 << 14) /* A---------- */
#define KSZ80X1_CR1_LEDMODE_ACT_FD_100_10	(2 << 14) /* A---------- */
#define KSZ80X1_CR1_LEDMODE_SPD_LNK		(0 << 14) /* --CDE------ */
#define KSZ80X1_CR1_LEDMODE_ACT_LNK		(1 << 14) /* --CDE------ */
#define KSZ8041_CR1_POLARITY			(1 << 13) /* A-CDE------ */
#define KSZ80X1_CR1_FEFAULT			(1 << 12) /* A---E------ */
#define KSZ8041_CR1_MDIX			(1 << 11) /* A-CDE------ */
#define KSZ80X1_CR1_LOOPBACK			(1 << 7)  /* A-CDE------ */

/* family set 2 */

#define KSZ80X1_CR1_FLOWCTRL			(1 << 9) /* -B---FGHIJKL */
#define KSZ80X1_CR1_LINK			(1 << 8) /* -B---FGHIJKL */
#define KSZ80X1_CR1_POLARITY			(1 << 7) /* -B---FGHIJKL */
#define KSZ80X1_CR1_MDIX			(1 << 5) /* -B---FGHIJKL */
#define KSZ80X1_CR1_ENERGY			(1 << 4) /* -B---FGHIJKL */
#define KSZ80X1_CR1_ISOLATE			(1 << 3) /* -B---FGHIJKL */

#define KSZ80X1_CR1_MODE			(7 << 0) /* -B---FGHIJKL */
#define KSZ80X1_CR1_MODE_AUTONEG		(0 << 0) /* -B---FGHIJKL */
#define KSZ80X1_CR1_MODE_10HD			(1 << 0) /* -B---FGHIJKL */
#define KSZ80X1_CR1_MODE_100HD			(2 << 0) /* -B---FGHIJKL */
#define KSZ80X1_CR1_MODE_10FD			(5 << 0) /* -B---FGHIJKL */
#define KSZ80X1_CR1_MODE_100FD			(6 << 0) /* -B---FGHIJKL */

/* KSZ80X1_CR2 --------------------------------------------------------------*/

/* refclk options availability depends on RMII availability on chip */

#define KSZ80X1_CR2_HPMDIX			(1 << 15) /* ABCDEFGHIJKL */
#define KSZ80X1_CR2_MDIXSEL			(1 << 14) /* ABCDEFGHIJKL*/
#define KSZ80X1_CR2_MDIXEN			(1 << 13) /* ABCDEFGHIJKL */
#define KSZ80X1_CR2_ENERGY			(1 << 12) /* A-CDE------- */
#define KSZ80X1_CR2_FORCE			(1 << 11) /* ABCDEFGHIJKL */
#define KSZ80X1_CR2_POWERSAVE			(1 << 10) /* ABCDEFGHIJKL */
#define KSZ80X1_CR2_IRQLVL			(1 << 9) /* ABCDEFGHIJKL */
#define KSZ80X1_CR2_JABEN			(1 << 8) /* ABCDEFGHIJKL */

/* family set 1 */

#define KSZ80X1_CR2_ANDONE			(1 << 7) /* A-CDE------- */
#define KSZ80X1_CR2_PAUSEEN			(1 << 6) /* A-CDE------- */
#define KSZ80X1_CR2_ISOLATE			(1 << 5) /* A-CDE------- */
#define KSZ80X1_CR2_MODE			(7 << 2) /* A-CDE */
#define KSZ80X1_CR2_MODE_AN			(0 << 2) /* A-CDE */
#define KSZ80X1_CR2_MODE_10HD			(1 << 2) /* A-CDE */
#define KSZ80X1_CR2_MODE_100HD			(2 << 2) /* A-CDE */
#define KSZ80X1_CR2_MODE_DEFAULT		(3 << 2) /* A--- */
#define KSZ80X1_CR2_MODE_10FD			(5 << 2) /* A-CDE */
#define KSZ80X1_CR2_MODE_100FD			(6 << 2) /* A-CDE */
#define KSZ80X1_CR2_MODE_ISOLATE		(7 << 2) /* A--- */

/* family set 2 */

#define KSZ80X1_CR2_REFCLK			(1 << 7) /* -B----GHIJKL */
#define KSZ80X1_CR2_REFCLK_25MHZ		(0 << 7) /* -B----GHIJKL */
#define KSZ80X1_CR2_REFCLK_50MHZ		(1 << 7) /* -B----GHIJKL */
#define KSZ80X1_CR2_LED				(3 << 4) /* -B---FGHIJKL */
#define KSZ80X1_CR2_LED_SPD_LNKACT		(0 << 4) /* -B---FGHIJKL */
#define KSZ80X1_CR2_LED_ACT_LNK			(1 << 4) /* -B---FGHIJKL */
#define KSZ80X1_CR2_TXDIS			(1 << 3) /* -B---FGHIJKL */
#define KSZ80X1_CR2_REMLPB			(1 << 2) /* -B---FGHIJKL */


#define KSZ80X1_CR2_SQEEN			(1 << 1) /* ABCDEFGHI-KL */
#define KSZ80X1_CR2_SCRAMBEN			(1 << 0) /* ABCDEFGHIJKL */

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

/**@}*/


#endif /* LIBOPENCM3_PHY_KSZ8051_H__ */
