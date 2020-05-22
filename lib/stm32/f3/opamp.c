/** @defgroup opamp_file OPAMP
 *
 * @ingroup STM32F3xx
 *
 * @brief <b>libopencm3 STM32F3xx OPAMP</b>
 *
 * @version 1.0.0
 *
 * @date 22 May 2020
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
/**@{*/

#include <libopencm3/stm32/opamp.h>

void opamp_enable(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_EN;
}

void opamp_disable(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_EN;
}

void opamp_lock(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_LOCK;
}


void opamp_set_calsel(uint32_t base, uint32_t calsel)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_CALSEL_MASK << OPAMP_CSR_CALSEL_SHIFT);
	OPAMP_CSR(base) |= calsel << OPAMP_CSR_CALSEL_SHIFT;
}

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

void opamp_force_vp_enable(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_FORCE_VP;
}

void opamp_force_vp_disable(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_FORCE_VP;
}

void opamp_cal_enable(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_CALON;
}

void opamp_cal_disable(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_CALON;
}


void opamp_trimoffsetn_set(uint32_t base, uint32_t trim)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_TRIMOFFSETN_MASK
		<< OPAMP_CSR_TRIMOFFSETN_SHIFT);
	OPAMP_CSR(base) |= trim << OPAMP_CSR_TRIMOFFSETN_SHIFT;
}

void opamp_trimoffsetp_set(uint32_t base, uint32_t trim)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_TRIMOFFSETP_MASK
		<< OPAMP_CSR_TRIMOFFSETP_SHIFT);
	OPAMP_CSR(base) |= trim << OPAMP_CSR_TRIMOFFSETP_SHIFT;
}

void opamp_user_trim_enable(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_USER_TRIM;
}

void opamp_user_trim_disable(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_USER_TRIM;
}


void opamp_pga_gain_select(uint32_t base, uint32_t gain)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_PGA_GAIN_MASK
		<< OPAMP_CSR_PGA_GAIN_SHIFT);
	OPAMP_CSR(base) |= gain << OPAMP_CSR_PGA_GAIN_SHIFT;
}


void opamp_vp_select(uint32_t base, uint32_t vp)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_VP_SEL_MASK
		<< OPAMP_CSR_VP_SEL_SHIFT);
	OPAMP_CSR(base) |= vp << OPAMP_CSR_VP_SEL_SHIFT;
}

void opamp_vm_select(uint32_t base, uint32_t vm)
{
	OPAMP_CSR(base) &= ~(OPAMP_CSR_VM_SEL_MASK
		<< OPAMP_CSR_VM_SEL_SHIFT);
	OPAMP_CSR(base) |= vm << OPAMP_CSR_VM_SEL_SHIFT;
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

