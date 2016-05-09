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
	ADCIFE_CR = ADCIFE_CR_EN;
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

void adcife_select_channel(enum adcife_channel ad)
{
	ADCIFE_SEQCFG |= ADCIFE_SEQCFG_MUXPOS_MASKED(ad);
}

void adcife_set_resolution(enum adcife_resolution res)
{
	if (ADCIFE_RESOLUTION_12BITS == res) {
		ADCIFE_SEQCFG &= ~ADCIFE_SEQCFG_RES;
	} else {
		ADCIFE_SEQCFG |= ADCIFE_SEQCFG_RES;
	}
}

void adcife_select_trigger(enum adcife_trigger trig)
{
	ADCIFE_SEQCFG &= ~ADCIFE_SEQCFG_TRGSEL_MASK;
	ADCIFE_SEQCFG |= ADCIFE_SEQCFG_TRGSEL_MASKED(trig);
}

void adcife_set_gain(enum adcife_gain gain)
{
	ADCIFE_SEQCFG &= ~ADCIFE_SEQCFG_GAIN_MASK;
	ADCIFE_SEQCFG |= ADCIFE_SEQCFG_GAIN_MASKED(gain);
}

void adcife_set_bipolar(bool enable)
{
	if (enable) {
		ADCIFE_SEQCFG |= ADCIFE_SEQCFG_BIPOLAR;
	} else {
		ADCIFE_SEQCFG &= ~ADCIFE_SEQCFG_BIPOLAR;
	}
}

void adcife_set_left_adjust(bool enable)
{
	if (enable) {
		ADCIFE_SEQCFG |= ADCIFE_SEQCFG_HWLA;
	} else {
		ADCIFE_SEQCFG &= ~ADCIFE_SEQCFG_HWLA;
	}
}

void adcife_start_conversion(void)
{
	ADCIFE_CR = ADCIFE_CR_STRIG;
}

void adcife_wait_conversion(void)
{
	while (!(ADCIFE_SR & ADCIFE_SR_SEOC));
	ADCIFE_SCR = ADCIFE_SR_SEOC;
}

struct adcife_lcv adcife_get_lcv(void)
{
	struct adcife_lcv res;
	res._lc_u.lcv = ADCIFE_LCV;
	return res;
}

void adcife_enable_interrupts(uint32_t imask)
{
	ADCIFE_IER = imask;
}

void adcife_disable_interrupts(uint32_t imask)
{
	ADCIFE_IDR = imask;
}

void adcife_timer_start(void)
{
	ADCIFE_CR = ADCIFE_CR_TSTART;
}

void adcife_timer_stop(void)
{
	ADCIFE_CR = ADCIFE_CR_TSTOP;
}

void adcife_timer_set_timeout(uint16_t timeout)
{
	ADCIFE_TIM = timeout;
}
