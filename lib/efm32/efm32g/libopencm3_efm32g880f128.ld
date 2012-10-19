/* lengths from d011_efm32tg840_datasheet.pdf table 1.1, offset from
 * d0034_efm32tg_reference_manual.pdf figure 5.2.
 *
 * the origins and memory structure are constant over all tinygeckos, but the
 * MEMORY section requires the use of constants, and has thus to be duplicated
 * over the chip variants.
 * */

MEMORY
{
	rom (rx) : ORIGIN = 0, LENGTH = 128k
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 16k
}

INCLUDE libopencm3_efm32g.ld;
