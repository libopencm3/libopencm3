/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopenstm32/rcc.h>
#include <libopenstm32/gpio.h>
#include <libopenstm32/timer.h>

#define GAMMA_3_0

/*
 * Gamma correction table
 *
 * The nonlinear tables are calculating with the function:
 * Iout = Iin ** gamma
 */
static const uint16_t gamma_table[] = {
#ifdef GAMMA_LINEAR
        1,	4,	9,	17,	26,	37,	51,	67,
        84,	104,	126,	149,	175,	203,	233,	265,
        299,	334,	372,	412,	454,	499,	545,	593,
        643,	695,	749,	805,	864,	924,	986,	1050,
        1116,	1185,	1255,	1327,	1402,	1478,	1556,	1637,
        1719,	1803,	1890,	1978,	2068,	2161,	2255,	2352,
        2450,	2550,	2653,	2757,	2864,	2972,	3082,	3195,
        3309,	3426,	3544,	3664,	3787,	3911,	4038,	4166,
        4296,	4429,	4563,	4700,	4838,	4978,	5121,	5265,
        5411,	5560,	5710,	5862,	6017,	6173,	6331,	6492,
        6654,	6818,	6985,	7153,	7323,	7495,	7670,	7846,
        8024,	8204,	8387,	8571,	8757,	8945,	9135,	9327,
        9521,	9718,	9916,	10116,	10318,	10522,	10728,	10936,
        11146,	11358,	11572,	11788,	12006,	12226,	12448,	12672,
        12897,	13125,	13355,	13587,	13821,	14057,	14294,	14534,
        14776,	15020,	15265,	15513,	15763,	16014,	16268,	16524,
        16781,	17041,	17302,	17566,	17831,	18099,	18368,	18640,
        18913,	19189,	19466,	19745,	20027,	20310,	20595,	20883,
        21172,	21463,	21756,	22051,	22349,	22648,	22949,	23252,
        23557,	23864,	24173,	24484,	24797,	25112,	25429,	25748,
        26069,	26391,	26716,	27043,	27372,	27702,	28035,	28370,
        28707,	29045,	29386,	29728,	30073,	30419,	30768,	31118,
        31471,	31825,	32182,	32540,	32900,	33263,	33627,	33993,
        34361,	34731,	35104,	35478,	35854,	36232,	36612,	36994,
        37378,	37764,	38152,	38542,	38933,	39327,	39723,	40121,
        40521,	40922,	41326,	41732,	42139,	42549,	42960,	43374,
        43789,	44207,	44626,	45048,	45471,	45896,	46324,	46753,
        47184,	47617,	48052,	48490,	48929,	49370,	49813,	50258,
        50705,	51154,	51604,	52057,	52512,	52969,	53428,	53888,
        54351,	54816,	55282,	55751,	56222,	56694,	57169,	57645,
        58123,	58604,	59086,	59570,	60057,	60545,	61035,	61527,
        62021,	62517,	63016,	63516,	64018,	64521,	65027,	65535
#else
#ifdef GAMMA_1_3
        // Gamma 1.3
        0,	1,	2,	4,	6,	8,	10,	13,
        15,	17,	20,	23,	25,	28,	31,	34,
        37,	40,	43,	46,	49,	52,	56,	59,
        62,	66,	69,	73,	76,	80,	83,	87,
        91,	94,	98,	102,	105,	109,	113,	117,
        121,	125,	129,	133,	137,	141,	145,	149,
        153,	157,	162,	166,	170,	174,	179,	183,
        187,	192,	196,	200,	205,	209,	214,	218,
        223,	227,	232,	237,	241,	246,	250,	255,
        260,	264,	269,	274,	279,	283,	288,	293,
        298,	303,	308,	312,	317,	322,	327,	332,
        337,	342,	347,	352,	357,	362,	367,	372,
        378,	383,	388,	393,	398,	403,	408,	414,
        419,	424,	429,	435,	440,	445,	451,	456,
        461,	467,	472,	477,	483,	488,	494,	499,
        505,	510,	516,	521,	527,	532,	538,	543,
        549,	554,	560,	566,	571,	577,	582,	588,
        594,	599,	605,	611,	617,	622,	628,	634,
        640,	645,	651,	657,	663,	669,	674,	680,
        686,	692,	698,	704,	710,	716,	722,	727,
        733,	739,	745,	751,	757,	763,	769,	775,
        781,	788,	794,	800,	806,	812,	818,	824,
        830,	836,	842,	849,	855,	861,	867,	873,
        880,	886,	892,	898,	904,	911,	917,	923,
        930,	936,	942,	949,	955,	961,	968,	974,
        980,	987,	993,	999,	1006,	1012,	1019,	1025,
        1032,	1038,	1044,	1051,	1057,	1064,	1070,	1077,
        1083,	1090,	1096,	1103,	1110,	1116,	1123,	1129,
        1136,	1142,	1149,	1156,	1162,	1169,	1176,	1182,
        1189,	1196,	1202,	1209,	1216,	1222,	1229,	1236,
        1242,	1249,	1256,	1263,	1269,	1276,	1283,	1290,
        1297,	1303,	1310,	1317,	1324,	1331,	1337,	1344
#else
#ifdef GAMMA_3_0
        // gamma = 3.0014
        0,	1,	4,	9,	16,	25,	36,	49,
        64,	81,	100,	121,	145,	170,	197,	226,
        257,	290,	325,	362,	402,	443,	486,	531,
        579,	628,	679,	732,	788,	845,	904,	966,
        1029,	1094,	1162,	1231,	1303,	1376,	1451,	1529,
        1608,	1690,	1773,	1859,	1946,	2036,	2127,	2221,
        2317,	2414,	2514,	2615,	2719,	2825,	2932,	3042,
        3154,	3267,	3383,	3501,	3621,	3742,	3866,	3992,
        4120,	4250,	4382,	4516,	4651,	4789,	4929,	5071,
        5215,	5361,	5509,	5659,	5811,	5965,	6121,	6279,
        6439,	6601,	6766,	6932,	7100,	7270,	7442,	7616,
        7793,	7971,	8151,	8333,	8518,	8704,	8892,	9083,
        9275,	9469,	9666,	9864,	10065,	10267,	10472,	10678,
        10887,	11097,	11310,	11524,	11741,	11959,	12180,	12403,
        12627,	12854,	13082,	13313,	13546,	13781,	14017,	14256,
        14497,	14740,	14984,	15231,	15480,	15731,	15984,	16239,
        16496,	16755,	17016,	17279,	17544,	17811,	18080,	18351,
        18624,	18899,	19176,	19455,	19736,	20019,	20304,	20592,
        20881,	21172,	21465,	21761,	22058,	22357,	22658,	22962,
        23267,	23574,	23884,	24195,	24509,	24824,	25142,	25461,
        25783,	26106,	26432,	26759,	27089,	27420,	27754,	28090,
        28427,	28767,	29109,	29452,	29798,	30146,	30495,	30847,
        31201,	31557,	31915,	32275,	32636,	33000,	33366,	33734,
        34104,	34476,	34850,	35226,	35604,	35984,	36366,	36750,
        37136,	37524,	37915,	38307,	38701,	39097,	39495,	39896,
        40298,	40702,	41108,	41517,	41927,	42339,	42754,	43170,
        43589,	44009,	44431,	44856,	45282,	45711,	46141,	46574,
        47008,	47445,	47884,	48324,	48767,	49212,	49658,	50107,
        50558,	51010,	51465,	51922,	52381,	52841,	53304,	53769,
        54236,	54705,	55176,	55649,	56124,	56601,	57080,	57561,
        58044,	58529,	59016,	59505,	59996,	60489,	60984,	61481,
        61981,	62482,	62985,	63490,	63998,	64507,	65018,	65531
#endif
#endif
#endif
};

/* Set STM32 to 72 MHz. */
void clock_setup(void)
{
  	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(SW_SYSCLKSEL_HSICLK);

	/* Set the PLL multiplication factor to 9. */
	rcc_set_pll_multiplication_factor(PLLMUL_PLL_CLK_MUL9);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(PLLSRC_HSI_CLK_DIV2);

	rcc_set_pllxtpre(PLLXTPRE_HSE_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(SW_SYSCLKSEL_PLLCLK);

        /* Enable TIM3 clock. */
	rcc_peripheral_enable_clock(&RCC_APB1ENR, TIM3EN);

  	/* Enable GPIOC, Alternate Function clocks. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, IOPCEN | AFIOEN);

}

void gpio_setup(void)
{

	/* Set GPIO6 (in GPIO port C) to
         * 'output alternate function push-pull'.
         */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO6 |
                                                      GPIO7 |
                                                      GPIO8 |
                                                      GPIO9);

        /* Remap TIM3:
         * CH1 -> PC6
         * CH2 -> PC7
         * CH3 -> PC8
         * CH4 -> PC9
         */
        AFIO_MAPR |= AFIO_MAPR_TIM3_REMAP_FULL_REMAP;
}
void tim_setup(void)
{
	/* Clock division and mode */
	TIM3_CR1 = TIM_CR1_CKD_CK_INT | TIM_CR1_CMS_EDGE;
	/* Period */
	TIM3_ARR = 65535;
	/* Prescaler */
	TIM3_PSC = 0;
	TIM3_EGR = TIM_EGR_UG;

	/* ---- */
	/* Output compare 1 mode and preload */
	TIM3_CCMR1 |= TIM_CCMR1_OC1M_PWM1 | TIM_CCMR1_OC1PE;

	/* Polarity and state */
	//TIM3_CCER = TIM_CCER_CC1P | TIM_CCER_CC1E;
	TIM3_CCER |= TIM_CCER_CC1E;

	/* Capture compare value */
	TIM3_CCR1 = 0;

	/* ---- */
	/* Output compare 2 mode and preload */
	TIM3_CCMR1 |= TIM_CCMR1_OC2M_PWM1 | TIM_CCMR1_OC2PE;

	/* Polarity and state */
	//TIM3_CCER = TIM_CCER_CC1P | TIM_CCER_CC1E;
	TIM3_CCER |= TIM_CCER_CC2E;

	/* Capture compare value */
	TIM3_CCR2 = 0;

	/* ---- */
	/* Output compare 3 mode and preload */
	TIM3_CCMR2 |= TIM_CCMR2_OC3M_PWM1 | TIM_CCMR2_OC3PE;

	/* Polarity and state */
	//TIM3_CCER = TIM_CCER_CC1P | TIM_CCER_CC1E;
	TIM3_CCER |= TIM_CCER_CC3E;

	/* Capture compare value */
	TIM3_CCR3 = 0;

	/* ---- */
	/* Output compare 4 mode and preload */
	TIM3_CCMR2 |= TIM_CCMR2_OC4M_PWM1 | TIM_CCMR2_OC4PE;

	/* Polarity and state */
	//TIM3_CCER = TIM_CCER_CC1P | TIM_CCER_CC1E;
	TIM3_CCER |= TIM_CCER_CC4E;

	/* Capture compare value */
	TIM3_CCR4 = 0;

	/* ---- */
	/* ARR reload enable */
	TIM3_CR1 |= TIM_CR1_ARPE;

	/* Counter enable */
	TIM3_CR1 |= TIM_CR1_CEN;

}

int main(void)
{
	int i, j0, j1, j2, j3, d0, d1, d2, d3;

	clock_setup();
	gpio_setup();
        tim_setup();

	j0=0;
	d0=1;
	j1=64;
	d1=1;
	j2=128;
	d2=1;
	j3=192;
	d3=1;
	while (1)
	{
		TIM3_CCR1= gamma_table[j0];
		j0+=d0;
		if(j0==255) d0=-1;
		if(j0==0) d0=1;
		TIM3_CCR2= gamma_table[j1];
		j1+=d1;
		if(j1==255) d1=-1;
		if(j1==0) d1=1;
		TIM3_CCR3= gamma_table[j2];
		j2+=d2;
		if(j2==255) d2=-1;
		if(j2==0) d2=1;
		TIM3_CCR4= gamma_table[j3];
		j3+=d3;
		if(j3==255) d3=-1;
		if(j3==0) d3=1;
		for(i=0; i< 50000; i++){}
	}

	return 0;
}
