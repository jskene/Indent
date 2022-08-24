
/**
 * @file Text formatting types
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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include <cstddef>
	// std::max
#include <algorithm>
	// Must include output streams, strings and string streams
#include "indent/config.h"

#define INDENT_INDENT_H_INCLUDED

namespace indent {

	class LineLength;
	class Indent;
	class Allowance;
	
	using Char = INDENT_CHAR;
	using OutputStream = INDENT_IOS_NAMESPACE::basic_ostream<Char>;
	using String = INDENT_IOS_NAMESPACE::basic_string<Char>;
	using StringStream = INDENT_IOS_NAMESPACE::basic_stringstream<Char>;
	using Locale = INDENT_IOS_NAMESPACE::locale;
	using CType = INDENT_IOS_NAMESPACE::ctype<Char>;
	
	template<class Facet>
	const Facet& useFacet(const Locale& loc) {
	
		return std::use_facet<Facet>(loc);
	}
}

#include "indent/implementation/indent/interfaces/LineLength.h"
#include "indent/implementation/indent/interfaces/Indent.h"
#include "indent/implementation/indent/interfaces/Allowance.h"
#include "indent/implementation/indent/interfaces/inserters.h"

#include "indent/implementation/indent/operations/LineLength.h"
#include "indent/implementation/indent/operations/Indent.h"
#include "indent/implementation/indent/operations/Allowance.h"
