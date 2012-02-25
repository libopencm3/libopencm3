#include <libopencm3/efm32/tinygecko/devicerevision.h>

u8 devicerevision_revision_get(void)
{
	/* probably this is more elegant, more readable and closer to the spec,
	 * and i'll just get used to doing things like that:
	return (DEVICEREVISION_PID2 & 0xf0) | ((DEVICEREVISION_PID3 & 0xf0) >> 4);
	*/
	return ((DEVICEREVISION_PID2 & DEVICEREVISION_REVISION_MASK) >> DEVICEREVISION_REVISION_SHIFT << DEVICEREVISION_REVISION_LENGTH) | ((DEVICEREVISION_PID3 & DEVICEREVISION_REVISION_MASK) >> DEVICEREVISION_REVISION_SHIFT);
}
