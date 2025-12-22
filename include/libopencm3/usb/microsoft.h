/** @defgroup usb_microsoft_defines USB Microsoft OS Descriptors Type Definitions

@brief <b>Defined Constants and Types for the USB Microsoft OS Descriptors Type Definitions</b>

@ingroup USB_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2022
Rachel Mant <git@dragonmux.network>

@date 11 August 2022

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Rachel Mant <git@dragonmux.network>
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

#ifndef __MICROSOFT_H
#define __MICROSOFT_H

#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/bos.h>

BEGIN_DECLS

typedef uint16_t usb_char16_t;

enum microsoft_req {
	MICROSOFT_GET_DESCRIPTOR_SET = 7,
	MICROSOFT_SET_ALTERNATE_ENUM = 8,
};

enum microsoft_os_descriptor_types {
	MICROSOFT_OS_SET_HEADER = 0,
	MICROSOFT_OS_SUBSET_HEADER_CONFIGURATION = 1,
	MICROSOFT_OS_SUBSET_HEADER_FUNCTION = 2,
	MICROSOFT_OS_FEATURE_COMPATIBLE_ID = 3,
	MICROSOFT_OS_FEATURE_REG_PROPERTY = 4,
	MICROSOFT_OS_FEATURE_MIN_RESUME_TIME = 5,
	MICROSOFT_OS_FEATURE_MODEL_ID = 6,
	MICROSOFT_OS_FEATURE_CCGP_DEVICE = 7,
	MICROSOFT_OS_FEATURE_VENDOR_REVISION = 8,
};

enum microsoft_registry_types {
	REG_SZ = 1,
	REG_EXPAND_SZ = 2,
	REG_BINARY = 3,
	REG_DWORD_LITTLE_ENDIAN = 4,
	REG_DWORD_BIG_ENDIAN = 5,
	REG_LINK = 6,
	REG_MULTI_SZ = 7,
};

#define MICROSOFT_OS_DESCRIPTOR_PLATFORM_CAPABILITY_ID \
{ \
	0xd8dd60dfU, \
	0x4589U, \
	0x4cc7U, \
	0xd29cU, \
	{0x65U, 0x9dU, 0x9eU, 0x64U, 0x8aU, 0x9fU}, \
}

#define MICROSOFT_WINDOWS_VERSION_WINBLUE 0x06030000

#define MICROSOFT_OS_COMPATIBLE_ID_NONE {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}
#define MICROSOFT_OS_COMPATIBLE_ID_WINUSB {'W', 'I', 'N', 'U', 'S', 'B', '\0', '\0'}

typedef struct __attribute__((packed)) microsoft_os_descriptor_set_information {
	uint32_t dwWindowsVersion;
	uint16_t wMSOSDescriptorSetTotalLength;
	uint8_t bMS_VendorCode;
	uint8_t bAltEnumCode;
} microsoft_os_descriptor_set_information;

#define MICROSOFT_OS_DESCRIPTOR_SET_INFORMATION_SIZE sizeof(microsoft_os_descriptor_set_information)

typedef struct microsoft_os_feature_descriptor {
	uint16_t wLength;
	uint16_t wDescriptorType;
} microsoft_os_feature_descriptor;

typedef struct microsoft_os_feature_compatible_id_descriptor {
	microsoft_os_feature_descriptor header;
	char compatible_id[8];
	char sub_compatible_id[8];
} microsoft_os_feature_compatible_id_descriptor;

#define MICROSOFT_OS_FEATURE_COMPATIBLE_ID_DESCRIPTOR_SIZE sizeof(microsoft_os_feature_compatible_id_descriptor)

typedef struct microsoft_os_feature_registry_property_descriptor {
	microsoft_os_feature_descriptor header;
	uint16_t wPropertyDataType;
	uint16_t wPropertyNameLength;
	const usb_char16_t *PropertyName;
	uint16_t wPropertyDataLength;
	const void *PropertyData;
} microsoft_os_feature_registry_property_descriptor;

#define MICROSOFT_OS_FEATURE_REGISTRY_PROPERTY_DESCRIPTOR_SIZE_BASE 10U

typedef struct microsoft_os_feature_min_recovery_time_descriptor {
	microsoft_os_feature_descriptor header;
	uint8_t bResumeRecoveryTime;
	uint8_t bResumeSignalingTime;
} microsoft_os_feature_min_recovery_time_descriptor;

#define MICROSOFT_OS_FEATURE_MIN_RECOVERY_TIME_DESCRIPTOR_SIZE \
	sizeof(microsoft_os_feature_min_recovery_time_descriptor)

typedef struct microsoft_os_feature_model_id_descriptor {
	microsoft_os_feature_descriptor header;
	usb_bos_uuid ModelID;
} microsoft_os_feature_model_id_descriptor;

#define MICROSOFT_OS_FEATURE_MODEL_ID_DESCRIPTOR_SIZE sizeof(microsoft_os_feature_model_id_descriptor)

typedef struct microsoft_os_feature_descriptor microsoft_os_feature_ccgp_device_descriptor;

#define MICROSOFT_OS_FEATURE_CCGP_DEVICE_DESCRIPTOR_SIZE sizeof(microsoft_os_feature_ccgp_device_descriptor)

typedef struct microsoft_os_feature_vendor_revision_descriptor {
	microsoft_os_feature_descriptor header;
	uint16_t VendorRevision;
} microsoft_os_feature_vendor_revision_descriptor;

#define MICROSOFT_OS_FEATURE_VENDOR_REVISION_DESCRIPTOR_SIZE sizeof(microsoft_os_feature_vendor_revision_descriptor)

typedef struct microsoft_os_descriptor_function_subset_header {
	uint16_t wLength;
	uint16_t wDescriptorType;
	uint8_t bFirstInterface;
	uint8_t bReserved;
	uint16_t wTotalLength;

	/* Descriptor ends here.  The following are used internally: */
	/* This is a type-erased struct of the various feature descriptors */
	const void *feature_descriptors;
	uint8_t num_feature_descriptors;
} microsoft_os_descriptor_function_subset_header;

#define MICROSOFT_OS_DESCRIPTOR_FUNCTION_SUBSET_HEADER_SIZE 8U

typedef struct microsoft_os_descriptor_config_subset_header {
	uint16_t wLength;
	uint16_t wDescriptorType;
	uint8_t bConfigurationValue;
	uint8_t bReserved;
	uint16_t wTotalLength;

	/* Descriptor ends here.  The following are used internally: */
	const microsoft_os_descriptor_function_subset_header *function_subset_headers;
	uint8_t num_function_subset_headers;
} microsoft_os_descriptor_config_subset_header;

#define MICROSOFT_OS_DESCRIPTOR_CONFIG_SUBSET_HEADER_SIZE 8U

typedef struct microsoft_os_descriptor_set_header {
	uint16_t wLength;
	uint16_t wDescriptorType;
	uint32_t dwWindowsVersion;
	uint16_t wTotalLength;

	/* Descriptor ends here.  The following are used internally: */
	uint8_t vendor_code;
	uint8_t num_config_subset_headers;
	const microsoft_os_descriptor_config_subset_header *config_subset_headers;

} microsoft_os_descriptor_set_header;

#define MICROSOFT_OS_DESCRIPTOR_SET_HEADER_SIZE 10U

extern void microsoft_os_register_descriptor_sets(usbd_device *dev,
	const microsoft_os_descriptor_set_header *sets, uint8_t num_sets);

END_DECLS

#endif

/**@}*/
