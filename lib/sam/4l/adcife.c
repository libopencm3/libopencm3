/** @addtogroup scif
 *
 * @brief <b>Access functions for the SAM4 Analog to Digital Converter Interface (ADCIFE)</b>
 * @ingroup SAM4
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

#include <libopencm3/sam/adcife.h>

/** @brief Enable ADC interface. Must be done before any other configuration.
 *
 * This function does it synchronously and returns only when the interface is
 * actually enabled.
 */
void adcife_enable_sync(void)
{
	ADCIFE_CFG |= ADCIFE_CR_EN;
	while (!(ADCIFE_SR & ADCIFE_SR_EN));
}

void adcife_configure(
		enum adcife_refsel ref,
		enum adcife_speed speed,
		enum adcife_clk clk,
		enum adcife_prescal prescal)
{
	ADCIFE_CFG = ADCIFE_CFG_REFSEL_MASKED(ref)
		| ADCIFE_CFG_SPEED_MASKED(speed)
		| ADCIFE_CFG_PRESCAL_MASKED(prescal)
		| clk;
}

void adcife_select_channel(ad)
{
	/* TODO */
}
