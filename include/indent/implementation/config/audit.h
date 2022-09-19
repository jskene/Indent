/**
 * @file
 * Indent library compile-time settings
 *
 * # Library compile-time settings
 *
 * This header ensures that a full and consistent set of the macros
 * representing choices about the way Indent works have been defined.
 * Where necessary it uses guesses and extrapolations to complete this set.
 * This may result in preprocessor warnings and/or errors.  This header
 * documents all relevant settings and their legitimate values.
 *
 * One possibility is to give these settings via command-line arguments to the
 * compiler (e.g. `-D` arguments under GCC).  However, user code will
 * subsequently need to use the same settings that Floods was compiled with.
 * Therefore a better choice usually is to *convey* these settings by editing
 * the header `bagman/implemention/settings.h`, which is normally included
 * before this header, and distribute that header if Floods is later installed.
 *
 * In general:
 * - each macro can be overridden by defining it prior to including this
 *  header.  Do so with caution.  If overridden values do not reflect actual
 *  platform characteristics then errors are likely;
 * - macro definitions can make use of the macros defined in
 *  `platen/implementation/earlymacros.h`, which is normally included before
 *  this header;
 * - if a macro is *not* overridden and there is a usual way to guess it
 *  based on predefined macros for the various supported compilers, it will
 *  be silently guessed;
 * - if a macro is *not* overridden and there is not a usual way to guess
 *  it, but a default value can be used, then a warning will be issued
 *  stating what default value is used.  See below for the purpose and
 *  recommended values for these macros.  Because these warnings might be
 *  annoying they can be suppressed by defining `PLATEN_GUESS_QUIETLY`;
 * - If a guess is needed and can't be made, a preprocessor error will occur;
 * - If settings are given that are mutually inconsistent, a preprocessor
 *  error will occur.
 *
 * # Copyright and license
 *
 * Copyright 2022 James Skene
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#pragma once

#ifndef INDENT_CONFIG_H_INCLUDED
# error "Do not include directly - instead include indent/config.h"
#endif

#pragma once
 
 #if !defined(INDENT_IOS_NAMESPACE) && \
	!defined(INDENT_USE_STD) && \
	!defined(INDENT_USE_FLOODS)
# ifdef INDENT_GUESS_QUIETLY
#  define INDENT_USE_STD
# else
#  warning "INDENT_IOS_NAMESPACE not defined, guessing INDENT_USE_STD"
# endif
#endif

#ifdef INDENT_USE_STD

# include <ostream>
# include <string>
# include <sstream>

# ifndef INDENT_CHAR
#  define INDENT_CHAR char
# endif

# define INDENT_IOS_NAMESPACE std
#endif

#ifdef INDENT_USE_FLOODS

# include <floods/floods.h>
# include <floods/sstream.h>

# ifndef INDENT_CHAR
#  define INDENT_CHAR char
# endif

# define INDENT_IOS_NAMESPACE floods

#endif

#ifndef INDENT_CHAR
# ifdef INDENT_GUESS_QUIETLY
#  define INDENT_CHAR char
# else
#  warning "INDENT_CHAR not defined, guessing `char`"
#  define INDENT_CHAR char
# endif
#endif

#ifndef INDENT_IOS_NAMESPACE
# ifdef INDENT_GUESS_QUIETLY
#  define INDENT_IOS_NAMESPACE std
# else
#  warning "INDENT_IOS_NAMESPACE not defined, guessing `std`"
#  define INDENT_IOS_NAMESPACE std
# endif
#endif

