/**
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
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "indent/indent.h"


namespace indent {

    const int LineLength::lineLengthIndex = std::ios_base::xalloc();
    
    const int LineLength::tabLengthIndex = std::ios_base::xalloc();
    
    const int LineLength::continuationCharIndex = std::ios_base::xalloc();
    
    const int LineLength::badnessIndex = std::ios_base::xalloc();
    
    const int LineLength::continuationIndex = std::ios_base::xalloc();
    
    const int LineLength::columnIndex = std::ios_base::xalloc();
    
    const int LineLength::lastBlankIndex = std::ios_base::xalloc();
    
// Construction and assignment /////////////////////////////////////////////////

    LineLength::
    LineLength(
		std::size_t lineLength,
		std::size_t tabLength,
		Char continuationChar,
		std::size_t badness,
		std::size_t continuation)
        : lineLength(lineLength)
        , tabLength(tabLength)
        , continuationChar(continuationChar)
        , badness(badness)
        , continuation(continuation) {}

    LineLength::
    LineLength(LineLength&& other)
        : lineLength(other.lineLength)
        , tabLength(other.tabLength)
        , continuationChar(other.continuationChar)
        , badness(other.badness)
        , continuation(other.continuation) {
        
        other.clear();
    }
    
    LineLength&
    LineLength::
    operator=(LineLength&& other) {
    
        if(&other != this)
        {
            this->lineLength = other.lineLength;
            this->tabLength = other.tabLength;
            this->continuationChar = other.continuationChar;
            this->badness = other.badness;
            this->continuation = other.continuation;
            other.clear();
        }
        return *this;
    }
    
    LineLength&
    LineLength::
    clear() {

		lineLength = 0;
		tabLength = 0;
		continuationChar = char();
		badness = 0;
		continuation = 0;
        return *this;
    }

// LineLength //////////////////////////////////////////////////////////////////////

    std::size_t
    LineLength::
    getLineLength() const {
        
        return lineLength;
    }

    std::size_t
    LineLength::
    getTabLength() const {
        
        return tabLength;
    }

    Char
    LineLength::
    getContinuationChar() const {
        
        return continuationChar;
    }

    std::size_t
    LineLength::
    getBadness() const {
        
        return badness;
    }

    std::size_t
    LineLength::
    getContinuation() const {
        
        return continuation;
    }
}
