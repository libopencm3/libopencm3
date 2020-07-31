/** @defgroup debugging Debugging
@ingroup CM3_defines

@brief Macros and functions to aid in debugging

@version 1.0.0

@date 25 September 2012

Two preprocessor defines control the behavior of assertion check macros in
this module. They allow the choice between generated code size and ease of
debugging.

If NDEBUG is defined, all assertion checks are disabled and macros do not
generate any code.

If CM3_ASSERT_VERBOSE is defined, information regarding the position of
assertion checks will be stored in the binary, allowing for more
informative error messages, but also significantly increased code size. As
default assertion checks do not use this information it is only useful if
the application linked with libopencm3 defines its own
cm3_assert_failed_verbose() implementation.

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Tomaz Solc <tomaz.solc@tablix.org>
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

#ifndef LIBOPENCM3_CM3_ASSERT_H
#define LIBOPENCM3_CM3_ASSERT_H

#include <libopencm3/cm3/common.h>

#define CM3_LIKELY(expr) (__builtin_expect(!!(expr), 1))

#ifdef NDEBUG
# define cm3_assert(expr) (void)0
# define cm3_assert_not_reached() do { } while (1)
#else
# ifdef CM3_ASSERT_VERBOSE
#  define cm3_assert(expr) do { \
				if (CM3_LIKELY(expr)) { \
					(void)0; \
				} else { \
					cm3_assert_failed_verbose( \
						__FILE__, __LINE__, \
						__func__, #expr); \
				} \
			   } while (0)
#  define cm3_assert_not_reached() \
	cm3_assert_failed_verbose( \
			__FILE__, __LINE__, \
			__func__, 0)
# else
/** @brief Check if assertion is true.
 *
 * If NDEBUG macro is defined, this macro generates no code. Otherwise
 * cm3_assert_failed() or cm3_assert_failed_verbose() is called if assertion
 * is false.
 *
 * The purpose of this macro is to aid in debugging libopencm3 and
 * applications using it. It can be used for example to check if function
 * arguments are within expected ranges and stop execution in case an
 * unexpected state is reached.
 *
 * @param expr expression to check */
#  define cm3_assert(expr) do { \
				if (CM3_LIKELY(expr)) { \
					(void)0; \
				} else { \
					cm3_assert_failed(); \
				} \
			} while (0)
/** @brief Check if unreachable code is reached.
 *
 * If NDEBUG macro is defined, this macro generates code for an infinite loop.
 * Otherwise cm3_assert_failed() or cm3_assert_failed_verbose() is called if
 * the macro is ever reached.
 *
 * The purpose of this macro is to aid in debugging libopencm3 and
 * applications using it. It can be used for example to stop execution if an
 * unreachable portion of code is reached. */
#  define cm3_assert_not_reached() cm3_assert_failed()
# endif
#endif

BEGIN_DECLS

/** @brief Called on a failed assertion.
 *
 * Halts execution in an infinite loop. This function never returns.
 *
 * Defined as a weak symbol, so applications can define their own
 * implementation. Usually, a custom implementation of this function should
 * report an error in some way (print a message to a debug console, display,
 * LED, ...) and halt execution or reboot the device. */
void cm3_assert_failed(void) __attribute__((__noreturn__));

/** @brief Called on a failed assertion with verbose messages enabled.
 *
 * Halts execution in an infinite loop. This function never returns.
 *
 * Defined as a weak symbol, so applications can define their own
 * implementation. Usually, a custom implementation of this function should
 * report an error in some way (print a message to a debug console, display,
 * LED, ...) and halt execution or reboot the device.
 *
 * @param file File name where the failed assertion occurred
 * @param line Line number where the failed assertion occurred
 * @param func Name of the function where the failed assertion occurred
 * @param assert_expr Expression that evaluated to false (can be NULL) */
void cm3_assert_failed_verbose(const char *file, int line, const char *func,
		const char *assert_expr) __attribute__((__noreturn__));

END_DECLS

#endif

/**@}*/
