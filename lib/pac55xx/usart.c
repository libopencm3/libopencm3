/**
 * @defgroup usart_api USART peripheral API
 * @ingroup peripheral_apis
 * @brief <b>PAC55xxxx USART Driver</b>
 * @author @htmlonly &copy; @endhtmlonly 2020 Kevin Stefanik <kevin@allocor.tech>
 * @date February 25, 2020
 *
 * This library supports the USART module in the PAC55xx SoC from Qorvo.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
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
#include <libopencm3/pac55xx/usart.h>
#include <libopencm3/cm3/common.h>

/**@{*/

/** @brief USART Set Baudrate
The baud rate is computed assuming a peripheral clock of 150MHz.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] baud unsigned 32 bit. Baud rate specified in Hz.
@return Actual baud rate.
*/
uint32_t usart_set_baudrate(uint32_t usart, uint32_t baud) {
	/* TODO Assumes 150MHz PCLK. Update this to ccs_get_peripheral_freq() like on other platforms */
	const uint32_t pclk = 150000000;
	uint32_t denom = (baud << 4); /* denominator is baud * 16. */
	uint32_t dlr = 0xFFFFu & ((pclk + denom / 2) / denom);
	USART_DLR(usart) = dlr;
	return pclk / (dlr << 4); /* Baud Rate = PCLK / (16 * UARTADLR) */
}

/** @brief USART Configure Line Control Register
This register sets the data bits, stop bits, and parity
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] data_bits unsigned 8 bit. One of USART_DATABITS_5/6/7/8.
@param[in] stop_bits unsigned 8 bit. One of USART_STOPBITS_1/1P5/2.
@param[in] parity unsigned 8 bit. One of USART_PARITY_DISABLE/ODD/EVEN/FORCE1/FORCE0
*/
void usart_configure_lcr(uint32_t usart, uint8_t data_bits, uint8_t stop_bits,
				uint8_t parity) {
	USART_LCR(usart) = USART_LCR_WLS(data_bits)
					| ((stop_bits==USART_STOPBITS_2) ? USART_LCR_SBS : 0)
					| USART_LCR_PSELPEN(parity);
}

/** @brief Enable Break Control
Enables break control bit that forces TX pin to logic low.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_break_enable(uint32_t usart) {
	USART_LCR(usart) |= USART_LCR_BCON;
}

/** @brief Disable Break Control
Disables break control bit that forces TX pin to logic low.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_break_disable(uint32_t usart) {
	USART_LCR(usart) &= ~USART_LCR_BCON;
}

/** @brief Enable Enhanced Mode
Enable enhanced mode to generate interrupts when FIFO thresholds in FCR are reached.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_enhanced_enable(uint32_t usart) {
	USART_EFR(usart) = USART_EFR_ENMODE;
}

/** @brief Disable Enhanced Mode
Disable enhanced mode to generate interrupts when FIFO thresholds in FCR are reached.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_enhanced_disable(uint32_t usart) {
	USART_EFR(usart) &= ~USART_EFR_ENMODE;
}

/** @brief Enable FIFOs
Enable both TX and RX FIFOs. This must be set before setting the trigger levels.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_fifo_enable(uint32_t usart) {
	USART_FCR(usart) |= USART_FCR_FIFOEN;
}

/** @brief Disable FIFOs
Disable both TX and RX FIFOs.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_fifo_disable(uint32_t usart) {
	USART_FCR(usart) &= ~USART_FCR_FIFOEN;
}

/** Set the TX and RX FIFO depth. This function also enables the FIFOs if not already.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] tx_depth unsigned 8 bit. One of USART_FIFO_TRIG_1/2/4/14CHAR.
@param[in] rx_depth unsigned 8 bit. One of USART_FIFO_TRIG_1/2/4/14CHAR.
*/
void usart_set_fifo_depth(uint32_t usart, uint8_t tx_depth, uint8_t rx_depth) {
	USART_FCR(usart) |= USART_FCR_FIFOEN;
	USART_FCR(usart) = USART_FCR_TXTL(tx_depth) | USART_FCR_RXTL(rx_depth) | USART_FCR_FIFOEN;
}

/** @brief Write byte to TX FIFO
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] data unsigned 8 bit. Data to write to the TX FIFO.
*/
void usart_send(uint32_t usart, uint8_t data) {
	USART_THR(usart) = (uint32_t)data;
}

/** @brief Read byte from the RX FIFO
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@return Data read from the RX FIFO.
*/
uint8_t usart_recv(uint32_t usart) {
	return (uint8_t)USART_RBR(usart);
}

/** @brief Enable RX Interrupts
Enable both the Receive Data Available and Character Timeout interrupts.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_enable_rx_interrupt(uint32_t usart) {
	USART_IER(usart) |= USART_IER_RBRIE;
}

/** @brief Disable RX Interrupts
Disable both the Receive Data Available and Character Timeout interrupts.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_disable_rx_interrupt(uint32_t usart) {
	USART_IER(usart) &= ~USART_IER_RBRIE;
}

/** @brief Enable TX Interrupt
Enable the TX Holding Register Empty interrupt.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_enable_tx_interrupt(uint32_t usart) {
	USART_IER(usart) |= USART_IER_THRIE;
}

/** @brief Disable TX Interrupt
Disable the TX Holding Register Empty interrupt.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_disable_tx_interrupt(uint32_t usart) {
	USART_IER(usart) &= ~USART_IER_THRIE;
}

/** @brief Enable RX Line Status Interrupt
Enable the RX Line Status interrupt.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_enable_rls_interrupt(uint32_t usart) {
	USART_IER(usart) |= USART_IER_RLSIE;
}

/** @brief Disable RX Line Status Interrupt
Disable the RX Line Status interrupt.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_disable_rls_interrupt(uint32_t usart) {
	USART_IER(usart) &= ~USART_IER_RLSIE;
}

/** @brief Clear the TX FIFO
Clears the TX FIFO. The bit is self-clearing.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_clear_tx_fifo(uint32_t usart) {
	USART_FCR(usart) |= USART_FCR_TXFIFORST;
}

/** @brief Clear the RX FIFO
Clears the RX FIFO. The bit is self-clearing.
@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/
void usart_clear_rx_fifo(uint32_t usart) {
	USART_FCR(usart) |= USART_FCR_RXFIFORST;
}

/**@}*/
