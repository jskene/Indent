/**
 * @file
 * `LineLength` operators
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

#ifndef INDENT_INDENT_H_INCLUDED
# error "Do not include this header directly, instead include indent/indent.h"
#endif

namespace indent {

    template<class Stream>
    Stream&
    operator<<(Stream& out, const LineLength& manipulator) {
     
			// Allocate the array
		out.iword(LineLength::lastBlankIndex);
		
		long& lineLength = out.iword(LineLength::lineLengthIndex);
		long& tabLength = out.iword(LineLength::tabLengthIndex);
		long& continuationChar = out.iword(LineLength::continuationCharIndex);
		long& badness = out.iword(LineLength::badnessIndex);
		long& continuation = out.iword(LineLength::continuationIndex);
		lineLength = manipulator.getLineLength();
		tabLength = manipulator.getTabLength();
		continuationChar = static_cast<long>(manipulator.getContinuationChar());
		badness = manipulator.getBadness();
		continuation = manipulator.getContinuation();
        return out;
    }

    template<class Stream>
    LineLength
    getLineLength(Stream& s) {
    
		long& lineLength = s.iword(LineLength::lineLengthIndex);
		long& tabLength = s.iword(LineLength::tabLengthIndex);
		long& continuationChar = s.iword(LineLength::continuationCharIndex);
		long& badness = s.iword(LineLength::badnessIndex);
		long& continuation = s.iword(LineLength::continuationIndex);
		return LineLength {
			lineLength,
			tabLength,
			static_cast<Char>(continuationChar),
			badness,
			continuation
		};
    }
}

