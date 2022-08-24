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

    const int Indent::indentIndex = std::ios_base::xalloc();
    
// Construction and assignment /////////////////////////////////////////////////

    Indent::
    Indent()
        : indent(0) {}

    Indent::
    Indent(std::size_t indent)
        : indent(indent) {}

    Indent::
    Indent(Indent&& other)
        : indent(other.indent) {
        
        other.clear();
    }
    
    Indent&
    Indent::
    operator=(Indent&& other) {
    
        if(&other != this)
        {
            this->indent = other.indent;
            other.clear();
        }
        return *this;
    }
    
    Indent&
    Indent::
    clear() {

		indent = 0;
        return *this;
    }

// Comparison //////////////////////////////////////////////////////////////////
    
    bool
    Indent::
    operator==(const Indent& other) const {
    
        return indent == other.indent;
    }
    
    bool
    Indent::
    operator!=(const Indent& other) const {
    
        return indent != other.indent;
    }

// Indent //////////////////////////////////////////////////////////////////////

    std::size_t
    Indent::
    getIndent() const {
        
        return indent;
    }
}
