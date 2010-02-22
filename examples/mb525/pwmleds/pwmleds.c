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

#define GAMMA_LINEAR
#define GAMMA_1_3
#define GAMMA_3_0

/*
 * Gamma correction table
 *
 * The nonlinear tables are calculating with the function:
 * Iout = Iin ** gamma
 */
#ifdef GAMMA_LINEAR
static const uint16_t gamma_table_linear[] = {
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
};
#endif

#ifdef GAMMA_1_3
static const uint16_t gamma_table_1_3[] = {
        // Gamma 1.3
        0,	49,	120,	203,	296,	395,	501,	612,
        728,	848,	973,	1101,	1233,	1368,	1506,	1648,
        1792,	1939,	2088,	2241,	2395,	2552,	2711,	2872,
        3036,	3201,	3369,	3538,	3709,	3882,	4057,	4234,
        4412,	4592,	4774,	4957,	5142,	5329,	5517,	5706,
        5897,	6090,	6283,	6479,	6675,	6873,	7072,	7273,
        7475,	7678,	7882,	8088,	8294,	8502,	8711,	8922,
        9133,	9346,	9559,	9774,	9990,	10207,	10425,	10644,
        10864,	11086,	11308,	11531,	11755,	11981,	12207,	12434,
        12662,	12891,	13121,	13352,	13584,	13817,	14051,	14285,
        14521,	14757,	14994,	15233,	15472,	15712,	15952,	16194,
        16436,	16679,	16923,	17168,	17414,	17660,	17908,	18156,
        18405,	18654,	18905,	19156,	19408,	19660,	19914,	20168,
        20423,	20679,	20935,	21192,	21450,	21708,	21968,	22228,
        22488,	22750,	23012,	23275,	23538,	23802,	24067,	24332,
        24599,	24865,	25133,	25401,	25670,	25939,	26209,	26480,
        26751,	27023,	27296,	27569,	27843,	28118,	28393,	28669,
        28945,	29222,	29500,	29778,	30057,	30336,	30616,	30897,
        31178,	31460,	31742,	32025,	32308,	32592,	32877,	33162,
        33448,	33734,	34021,	34309,	34597,	34885,	35175,	35464,
        35754,	36045,	36337,	36628,	36921,	37214,	37507,	37801,
        38096,	38391,	38686,	38982,	39279,	39576,	39874,	40172,
        40471,	40770,	41070,	41370,	41670,	41972,	42273,	42576,
        42878,	43181,	43485,	43789,	44094,	44399,	44705,	45011,
        45317,	45625,	45932,	46240,	46549,	46858,	47167,	47477,
        47787,	48098,	48409,	48721,	49034,	49346,	49659,	49973,
        50287,	50602,	50917,	51232,	51548,	51864,	52181,	52498,
        52816,	53134,	53452,	53771,	54091,	54411,	54731,	55052,
        55373,	55694,	56016,	56339,	56662,	56985,	57309,	57633,
        57957,	58282,	58608,	58933,	59260,	59586,	59913,	60241,
        60569,	60897,	61226,	61555,	61884,	62214,	62545,	62875,
        63206,	63538,	63870,	64202,	64535,	64868,	65201,	65535
};
#endif

#ifdef GAMMA_3_0
static const uint16_t gamma_table_3_0[] = {
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
};
#endif

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
	j1=0;
	d1=1;
	j2=0;
	d2=1;
	j3=128;
	d3=1;
	while (1)
	{
		TIM3_CCR1= gamma_table_linear[j0];
		j0+=d0;
		if(j0==255) d0=-1;
		if(j0==0) d0=1;
		TIM3_CCR2= gamma_table_1_3[j1];
		j1+=d1;
		if(j1==255) d1=-1;
		if(j1==0) d1=1;
		TIM3_CCR3= gamma_table_3_0[j2];
		j2+=d2;
		if(j2==255) d2=-1;
		if(j2==0) d2=1;
		TIM3_CCR4= gamma_table_3_0[j3];
		j3+=d3;
		if(j3==255) d3=-1;
		if(j3==0) d3=1;
		for(i=0; i< 50000; i++){}
	}

	return 0;
}
