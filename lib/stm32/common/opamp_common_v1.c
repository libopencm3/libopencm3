/** @addtogroup opamp_file OPAMP peripheral API
 * @ingroup peripheral_apis
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

/**@{*/

#include <libopencm3/stm32/opamp.h>

bool opamp_read_outcal(uint32_t base)
{
	return (OPAMP_CSR(base) >> OPAMP_CSR_OUTCAL_SHIFT)
		& OPAMP_CSR_OUTCAL_MASK;
}

void opamp_tcm_enable(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_TCM_EN;
}

void opamp_tcm_disable(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_TCM_EN;
}

void opamp_vps_select(uint32_t base, uint32_t vps)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_VPS_SEL_MASK
		<< OPAMP_CSR_VPS_SEL_SHIFT);
	OPAMP_CSR(base) |= vps << OPAMP_CSR_VPS_SEL_SHIFT;
}

void opamp_vms_select(uint32_t base, uint32_t vms)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_VMS_SEL_MASK
		<< OPAMP_CSR_VMS_SEL_SHIFT);
	OPAMP_CSR(base) |= vms << OPAMP_CSR_VMS_SEL_SHIFT;
}

/**@}*/
