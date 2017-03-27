/** @addtogroup usart_file

 @author @htmlonly &copy; @endhtmlonly 2016 Cem Basoglu <cem.basoglu@web.de>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Cem Basoglu <cem.basoglu@web.de>
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

/**@{*/

#include <libopencm3/stm32/usart.h>

/*---------------------------------------------------------------------------*/
/** @brief USART enable data inversion

 Logical data from the data register are send/received in negative/inverse
 logic. (1=L, 0=H). The parity bit is also inverted.

 @note This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_enable_data_inversion(uint32_t usart)
{
	USART_CR2(usart) |= USART_CR2_DATAINV;
}

/*---------------------------------------------------------------------------*/
/** @brief USART disable data inversion

 Logical data from the data register are send/received in positive/direct logic.
 (1=H, 0=L)

 @note This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_disable_data_inversion(uint32_t usart)
{
	USART_CR2(usart) &= ~USART_CR2_DATAINV;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Enable TX pin active level inversion

 TX pin signal values are inverted. (VDD =0/mark, Gnd=1/idle).

 @note This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_enable_tx_inversion(uint32_t usart)
{
	USART_CR2(usart) |= USART_CR2_TXINV;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Disable TX pin active level inversion

 TX pin signal works using the standard logic levels (VDD =1/idle, Gnd=0/mark)

 @note This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_disable_tx_inversion(uint32_t usart)
{
	USART_CR2(usart) &= ~USART_CR2_TXINV;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Enable RX pin active level inversion

 RX pin signal values are inverted. (VDD =0/mark, Gnd=1/idle).

 This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_enable_rx_inversion(uint32_t usart)
{
	USART_CR2(usart) |= USART_CR2_RXINV;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Disable RX pin active level inversion

 RX pin signal works using the standard logic levels (VDD =1/idle, Gnd=0/mark)

 This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_disable_rx_inversion(uint32_t usart)
{

	USART_CR2(usart) &= ~USART_CR2_RXINV;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Enable Half-duplex

 - The TX and RX lines are internally connected.
 - The RX pin is no longer used
 - The TX pin is always released when no data is transmitted. Thus,
 it acts as a standard I/O in idle or in reception. It means
 that the I/O must be configured so that TX is configured as
 alternate function open-drain with an external pull-up.

 Apart from this, the communication protocol is similar to normal USART mode.
 Any conflicts on the line must be managed by software

 This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_enable_halfduplex(uint32_t usart)
{
	USART_CR3(usart) |= USART_CR3_HDSEL;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Disable Half-duplex

 This bit field can only be written when the USART is disabled.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_disable_halfduplex(uint32_t usart)
{
	USART_CR3(usart) &= ~USART_CR3_HDSEL;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Set receiver timeout value

 Sets the receive timeout value in terms of number of bit duration.
 The RTOF @ref usart_isr_rtof is set if, after the last received character,
 no new start bit is detected for more than the receive timeout value.

 @note The timeout value can also be written when USART is enabled.
 If the new value is lower/equals the internal hardware counter,
 the RTOF flag will be set.

 @param[in] usart USART block register address base @ref usart_reg_base
 @param[in] value The receive timeout value in terms of number of bit duration.
 */
void usart_set_rx_timeout_value(uint32_t usart, uint32_t value)
{
	uint32_t reg;
	reg = USART_RTOR(usart) & ~USART_RTOR_RTO_MASK;
	reg |= (USART_RTOR_RTO_VAL(value) & USART_RTOR_RTO_MASK);
	USART_RTOR(usart) = reg;
}

/*---------------------------------------------------------------------------*/
/** @brief USART enable receive timeout function

 @note If the USART does not support the Receiver timeout feature,
 this bit is reserved and forced by hardware to ‘0’.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_enable_rx_timeout(uint32_t usart)
{
	USART_CR2(usart) |= USART_CR2_RTOEN;
}

/*---------------------------------------------------------------------------*/
/** @brief USART disable receive timeout function

 @note If the USART does not support the Receiver timeout feature,
 this bit is reserved and forced by hardware to ‘0’.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_disable_rx_timeout(uint32_t usart)
{
	USART_CR2(usart) &= ~USART_CR2_RTOEN;
}

/*---------------------------------------------------------------------------*/
/** @brief USART enable receive timeout interrupt

 An interrupt is generated when the RTOF Flag is set
 in the ISR @ref usart_isr register.

 @note If the USART does not support the Receiver timeout feature,
 this bit is reserved and forced by hardware to ‘0’.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_enable_rx_timeout_interrupt(uint32_t usart)
{
	USART_CR1(usart) |= USART_CR1_RTOIE;
}

/*---------------------------------------------------------------------------*/
/** @brief USART disable receive timeout interrupt

 @note If the USART does not support the Receiver timeout feature,
 this bit is reserved and forced by hardware to ‘0’.

 @param[in] usart USART block register address base @ref usart_reg_base
 */
void usart_disable_rx_timeout_interrupt(uint32_t usart)
{
	USART_CR1(usart) &= ~USART_CR1_RTOIE;
}

/**@}*/
