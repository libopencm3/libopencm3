/** @addtogroup exti_file EXTI peripheral API
 * @ingroup peripheral_apis
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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
 *
 * This provides the code for the "next gen" EXTI block provided in F2/F4/F7/L1
 * devices.  (differences only in the source selection)
 */
/**@{*/


#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>

#if defined(EXTI_EXTICR)
	#define EXTICR_SELECTION_FIELDSIZE	EXTI_EXTICR_FIELDSIZE
	#define EXTICR_SELECTION_REG(x)	EXTI_EXTICR(x)
#elif defined(AFIO_EXTICR)
	#define EXTICR_SELECTION_FIELDSIZE	AFIO_EXTICR_FIELDSIZE
	#define EXTICR_SELECTION_REG(x)	AFIO_EXTICR(x)
#else
	#include <libopencm3/stm32/syscfg.h>
	#define EXTICR_SELECTION_FIELDSIZE	SYSCFG_EXTICR_FIELDSIZE
	#define EXTICR_SELECTION_REG(x)	SYSCFG_EXTICR(x)
#endif


/*---------------------------------------------------------------------------*/
/** @brief Set trigger  [31:0] extended interrupts.

Set trigger values   extended [31:0] interrupts

@param[in] extis extended interrupt number [31:0]  @ref exti_values.
@param[in] trig extended interrupt front type @ref exti_trigger_values.
*/

void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig)
{

#if defined(EXTI_RTSR1) && defined(EXTI_FTSR1)
	switch (trig) {
	case EXTI_TRIGGER_RISING:
		EXTI_RTSR1 |= extis;
		EXTI_FTSR1 &= ~extis;
		break;
	case EXTI_TRIGGER_FALLING:
		EXTI_RTSR1 &= ~extis;
		EXTI_FTSR1 |= extis;
		break;
	case EXTI_TRIGGER_BOTH:
		EXTI_RTSR1 |= extis;
		EXTI_FTSR1 |= extis;
		break;
	}
#else
	switch (trig) {
	case EXTI_TRIGGER_RISING:
		EXTI_RTSR |= extis;
		EXTI_FTSR &= ~extis;
		break;
	case EXTI_TRIGGER_FALLING:
		EXTI_RTSR &= ~extis;
		EXTI_FTSR |= extis;
		break;
	case EXTI_TRIGGER_BOTH:
		EXTI_RTSR |= extis;
		EXTI_FTSR |= extis;
		break;
	}
#endif
	
}


/*---------------------------------------------------------------------------*/
/** @brief Set trigger for [63:32] extended interrupts.

Set trigger values  extended [63:32] interrupts

@param[in] extis extended interrupt number [63:32]  @ref exti_values.
@param[in] trig extended interrupt front type @ref exti_trigger_values.
*/

void exti_set_trigger2(uint32_t extis, enum exti_trigger_type trig)
{
	
#if defined(EXTI_RTSR2) && defined(EXTI_FTSR2)
	switch (trig) {
	case EXTI_TRIGGER_RISING:
		EXTI_RTSR2 |= extis;
		EXTI_FTSR2 &= ~extis;
		break;
	case EXTI_TRIGGER_FALLING:
		EXTI_RTSR2 &= ~extis;
		EXTI_FTSR2 |= extis;
		break;
	case EXTI_TRIGGER_BOTH:
		EXTI_RTSR2 |= extis;
		EXTI_FTSR2 |= extis;
		break;
	}
#else
	exti_set_trigger(extis, trig);
#endif

}



/*---------------------------------------------------------------------------*/
/** @brief Enable request [31:0] extended interrupts.

Enable request  extended [31:0] interrupts (unmask Interrupt and Event request from Line x [31:0] )

@param[in] extis extended interrupt number [31:0]  @ref exti_values.
*/

void exti_enable_request(uint32_t extis)
{
	
#if defined(EXTI_IMR1) && defined(EXTI_EMR1)
	/* Enable interrupts. */
	EXTI_IMR1 |= extis;

	/* Enable events. */
	EXTI_EMR1 |= extis;
#else
	/* Enable interrupts. */
	EXTI_IMR |= extis;

	/* Enable events. */
	EXTI_EMR |= extis;
#endif
	
}



/*---------------------------------------------------------------------------*/
/** @brief Enable request [63:32] extended interrupts.

Enable request  extended [63:32] interrupts (unmask Interrupt and Event request from Line x [63:32] )

@param[in] extis extended interrupt number [63:32]  @ref exti_values.
*/

void exti_enable_request2(uint32_t extis)
{
	
#if defined(EXTI_IMR2) && defined(EXTI_EMR2)
	/* Enable interrupts. */
	EXTI_IMR2 |= extis;

	/* Enable events. */
	EXTI_EMR2 |= extis;
#else
	exti_enable_request(extis);
#endif
	
}




/*---------------------------------------------------------------------------*/
/** @brief Disable request [31:0] extended interrupts.

Disable request  extended [31:0] interrupts (unmask Interrupt request from Line x [31:0] )

@param[in] extis extended interrupt number [31:0]  @ref exti_values.
*/

void exti_disable_request(uint32_t extis)
{
	
#if defined(EXTI_IMR1) && defined(EXTI_EMR1)
	/* Disable interrupts. */
	EXTI_IMR1 &= ~extis;

	/* Disable events. */
	EXTI_EMR1 &= ~extis;
#else
	/* Disable interrupts. */
	EXTI_IMR &= ~extis;

	/* Disable events. */
	EXTI_EMR &= ~extis;
#endif
}



/*---------------------------------------------------------------------------*/
/** @brief Disable request [63:32] extended interrupts.

Disable request  extended [63:32] interrupts (unmask Interrupt request from Line x [63:32] )

@param[in] extis extended interrupt number [63:32]  @ref exti_values.
*/

void exti_disable_request2(uint32_t extis)
{
	
#if defined(EXTI_IMR2) && defined(EXTI_EMR2)
	/* Disable interrupts. */
	EXTI_IMR2 &= ~extis;

	/* Disable events. */
	EXTI_EMR2 &= ~extis;
#else
	exti_disable_request(extis);
#endif 

}



/*---------------------------------------------------------------------------*/
/** @brief Reset the interrupt request [31:0] extended interrupts.

Reset the interrupt request by writing a 1 to the corresponding pending bit register.

@param[in] extis extended interrupt number [31:0]  @ref exti_values.
*/ 
 
void exti_reset_request(uint32_t extis)
{
#if defined(EXTI_RPR1) && defined(EXTI_FPR1)
	EXTI_RPR1 = extis;
	EXTI_FPR1 = extis;
#else

	#if defined(EXTI_PR1) 
		EXTI_PR1 = extis;
	#else
		EXTI_PR = extis;
	#endif
	
#endif
}



/*---------------------------------------------------------------------------*/
/** @brief Reset the interrupt request [63:32] extended interrupts.

Reset the interrupt request by writing a 1 to the corresponding pending bit register.

@param[in] extis extended interrupt number [63:32]  @ref exti_values.
*/ 
 
void exti_reset_request2(uint32_t extis)
{

#if defined(EXTI_PR2) 
	EXTI_PR2 = extis;
#else
	exti_reset_request(extis);
#endif

}



/*---------------------------------------------------------------------------*/
/** @brief Check the flag of a given [31:0] extended interrupts.

Check the flag of a given EXTI interrupt.

@param[in] extis extended interrupt number [31:0]  @ref exti_values.
*/  
 
uint32_t exti_get_flag_status(uint32_t exti)
{
#if defined(EXTI_RPR1) && defined(EXTI_FPR1)
	return (EXTI_RPR1 & exti) | (EXTI_FPR1 & exti);
#else
	#if defined(EXTI_PR1)
		return EXTI_PR1 & exti;
	#else
		return EXTI_PR & exti;
	#endif
#endif
}



/*---------------------------------------------------------------------------*/
/** @brief Check the flag of a given [63:32] extended interrupts.

Check the flag of a given EXTI interrupt.

@param[in] extis extended interrupt number [63:32]  @ref exti_values.
*/  
 
uint32_t exti_get_flag_status2(uint32_t exti)
{

#if defined(EXTI_PR2)
	return EXTI_PR2 & exti;
#else
	return exti_get_flag_status(exti);
#endif

}


 
/*---------------------------------------------------------------------------*/
/** @brief Select extended interrupts source.

Remap an external interrupt line to the corresponding pin on the specified GPIO port.

TODO: This could be rewritten in fewer lines of code.

@param[in] extis extended interrupt number  @ref exti_values.
@param[in] gpioport gpio extended interrupt port  @ref gpio_port_id.
*/  
  
void exti_select_source(uint32_t exti, uint32_t gpioport)
{
	uint32_t line;
	for (line = 0; line < 16; line++) {
		if (!(exti & (1 << line))) {
			continue;
		}

		uint32_t bits = 0;

		switch (gpioport) {
		case GPIOA:
			bits = 0;
			break;
		case GPIOB:
			bits = 1;
			break;
		case GPIOC:
			bits = 2;
			break;
		case GPIOD:
			bits = 3;
			break;
#if defined(GPIOE) && defined(GPIO_PORT_E_BASE)
		case GPIOE:
			bits = 4;
			break;
#endif
#if defined(GPIOF) && defined(GPIO_PORT_F_BASE)
		case GPIOF:
			bits = 5;
			break;
#endif
#if defined(GPIOG) && defined(GPIO_PORT_G_BASE)
		case GPIOG:
			bits = 6;
			break;
#endif
#if defined(GPIOH) && defined(GPIO_PORT_H_BASE)
		case GPIOH:
			bits = 7;
			break;
#endif
#if defined(GPIOI) && defined(GPIO_PORT_I_BASE)
		case GPIOI:
			bits = 8;
			break;
#endif
#if defined(GPIOJ) && defined(GPIO_PORT_J_BASE)
		case GPIOJ:
			bits = 9;
			break;
#endif
#if defined(GPIOK) && defined(GPIO_PORT_K_BASE)
		case GPIOK:
			bits = 10;
			break;
#endif
		}

		uint8_t shift = (uint8_t)(EXTICR_SELECTION_FIELDSIZE * (line % 4));
		uint32_t mask = ((1 << EXTICR_SELECTION_FIELDSIZE) - 1) << shift;
		uint32_t reg = line / 4;

		EXTICR_SELECTION_REG(reg) = (EXTICR_SELECTION_REG(reg) & ~mask) | (bits << shift);
	};
}
/**@}*/

