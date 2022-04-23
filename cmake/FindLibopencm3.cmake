include(FindPackageHandleStandardArgs)

#[=====================================[.rst
FindLibopencm3
--------------

Finds the Libopencm3 library suitable for target device specified in variable
DEVICE. You have to set this variable to full name of your MCU before calling
find_package(Libopencm3) otherwise search will fail.

Imported targets
^^^^^^^^^^^^^^^^

``Libopencm3::Libopencm3``
  Libopencm3 HAL suitable for your MCU. This library automatically configures
  compiler to link using correct automatically generated linker script, exports
  include paths and compiler definitions.

Result variables
^^^^^^^^^^^^^^^^

``Libopencm3_FOUND``
  True if Libopencm3 was found
``Libopencm3_LIBRARY``
  Library name needed to link Libopencm3
``Libopencm3_DEFINITIONS``
  Compile definitions needed to use Libopencm3 correctly
``Libopencm3_INCLUDE_DIRS``
  Path to include directories of Libopencm3
``Libopencm3_LIBRARY_DIRS``
  Path to directory where Libopencm3 libraries are present
``Libopencm3_ROOT_DIR``
  Root directory of Libopencm3
``Libopencm3_LINKER_SCRIPT``
  Path to automatically generated linker script suitable for target device
``Libopencm3_LINK_OPTIONS``
  Linker options needed to use Libopencm3 correctly
]=====================================]

cmake_minimum_required(VERSION 3.3)

find_program(PYTHON_EXE
	python
	)

if ("${PYTHON_EXE}" STREQUAL "PYTHON_EXE-NOTFOUND")
	message(FATAL_ERROR "Libopencm3 MCU support requires Python!")
endif()

if (NOT DEVICE)
	message(FATAL_ERROR "No target device selected! "
	"Please define variable DEVICE to contain *full* name of your MCU!")
endif()

get_filename_component(Libopencm3_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

set(LOCM3_DATA_FILE ${Libopencm3_ROOT_DIR}/ld/devices.data)


if (NOT EXISTS ${LOCM3_DATA_FILE})
	message(FATAL_ERROR "Unable to find device data file ${LOCM3_DATA_FILE}!")
endif()

set(Libopencm3_LINKER_SCRIPT ${CMAKE_BINARY_DIR}/gen.${DEVICE}.ld)

function(_genlink_obtain DEVICE PROPERTY OUTPUT)
	execute_process(COMMAND 
		${PYTHON_EXE} ${Libopencm3_ROOT_DIR}/scripts/genlink.py ${LOCM3_DATA_FILE} ${DEVICE} ${PROPERTY}
		OUTPUT_VARIABLE OUT_DATA
		RESULT_VARIABLE SUCCESS
		)
	if ("${SUCCESS}" EQUAL "0")
		message(DEBUG ">> ${OUT_DATA}")
		set("${OUTPUT}" "${OUT_DATA}" PARENT_SCOPE)
	else()
		message(FATAL_ERROR "Unable to obtain ${PROPERTY} for device ${DEVICE}!")
	endif()
endfunction()

_genlink_obtain(${DEVICE} FAMILY DEVICE_FAMILY)
_genlink_obtain(${DEVICE} SUBFAMILY DEVICE_SUBFAMILY)
_genlink_obtain(${DEVICE} CPU DEVICE_CPU)
_genlink_obtain(${DEVICE} FPU DEVICE_FPU)
_genlink_obtain(${DEVICE} CPPFLAGS Libopencm3_DEFINITIONS)
_genlink_obtain(${DEVICE} DEFS DEVICE_DEFS)

if ("${DEVICE_FAMILY}" STREQUAL "")
	message(FATAL_ERROR "${DEVICE} not found in ${LOCM3_DATA_FILE}")
endif()

string(REPLACE " " ";" DEVICE_DEFS ${DEVICE_DEFS})

# This essentially duplicates actions of genlink-config.mk
set(LOCM3_THUMB_DEVS 
	cortex-m0
	cortex-m0plus
	cortex-m3
	cortex-m4
	cortex-m7
	)

set(ARCH_FLAGS "")
list(APPEND ARCH_FLAGS -mcpu=${DEVICE_CPU})

if ("${DEVICE_CPU}" IN_LIST LOCM3_THUMB_DEVS)
	list(APPEND ARCH_FLAGS -mthumb)
endif()

if ("${DEVICE_FPU}" STREQUAL "soft")
	list(APPEND ARCH_FLAGS -msoft-float)
elseif("${DEVICE_FPU}" STREQUAL "hard-fpv4-sp-d16")
	list(APPEND ARCH_FLAGS -mfloat-abi=hard -mfpu=fpv4-sp-d16)
elseif("${DEVICE_FPU}" STREQUAL "hard-fpv5-sp-d16")
	list(APPEND ARCH_FLAGS -mfloat-abi=hard -mfpu=fpv5-sp-d16)
else()
	message(FATAL_ERROR "No match for the FPU flags")
endif()

# Find library for given family or subfamily
set(OPENCM3_LIBNAME
	opencm3_${DEVICE_FAMILY}
	opencm3_${DEVICE_SUBFAMILY}
	)

foreach(LOCM3_CANDIDATE ${OPENCM3_LIBNAME})
	if (EXISTS ${Libopencm3_ROOT_DIR}/lib/lib${LOCM3_CANDIDATE}.a)
		# If found, then generate the linker script
		execute_process(COMMAND ${CMAKE_C_COMPILER} 
			${ARCH_FLAGS} ${DEVICE_DEFS} 
			-P -E ${Libopencm3_ROOT_DIR}/ld/linker.ld.S 
			-o ${Libopencm3_LINKER_SCRIPT}
			RESULT_VARIABLE CPP_RESULT
			)

		if (NOT "${CPP_RESULT}" EQUAL "0")
			message(FATAL_ERROR "Unable to generate linker script for device ${DEVICE}")
		endif()

		# Provide exported variables
		set(Libopencm3_LIBRARY ${LOCM3_CANDIDATE})
		set(Libopencm3_LIBRARY_DIRS ${Libopencm3_ROOT_DIR}/lib)
		set(Libopencm3_INCLUDE_DIRS ${Libopencm3_ROOT_DIR}/include)
		set(Libopencm3_DEFINITIONS ${Libopencm3_DEFINITIONS} ${ARCH_FLAGS})
		set(Libopencm3_LINK_OPTIONS -static -nostartfiles ${ARCH_FLAGS} -T${Libopencm3_LINKER_SCRIPT})

		# Provide imported target, which wraps Libopencm3
		add_library(Libopencm3::Libopencm3 STATIC IMPORTED)
		set_target_properties(Libopencm3::Libopencm3
			PROPERTIES
			IMPORTED_LOCATION ${Libopencm3_LIBRARY_DIRS}/lib${Libopencm3_LIBRARY}.a
			INTERFACE_INCLUDE_DIRECTORIES ${Libopencm3_INCLUDE_DIRS}
			)

		set_property(TARGET Libopencm3::Libopencm3 
			PROPERTY INTERFACE_COMPILE_OPTIONS
			${Libopencm3_DEFINITIONS}
			)

		set_property(TARGET Libopencm3::Libopencm3
			PROPERTY INTERFACE_LINK_OPTIONS
			${Libopencm3_LINK_OPTIONS}
			)
		break()
	endif()
endforeach()

# Handle stuff such as REQUIRED, QUIET, etc.
find_package_handle_standard_args(Libopencm3
	FOUND_VAR Libopencm3_FOUND
	REQUIRED_VARS 
		Libopencm3_LIBRARY 
		Libopencm3_INCLUDE_DIRS
		Libopencm3_LIBRARY_DIRS
		Libopencm3_DEFINITIONS
		Libopencm3_LINKER_SCRIPT
		Libopencm3_LINK_OPTIONS
	)
