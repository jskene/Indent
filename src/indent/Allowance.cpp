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

    const int Allowance::allowanceIndex = std::ios_base::xalloc();
    
// Construction and assignment /////////////////////////////////////////////////

    Allowance::
    Allowance(std::size_t allowance)
        : allowance(allowance) {}

    Allowance::
    Allowance(Allowance&& other)
        : allowance(other.allowance) {
        
        other.clear();
    }
    
    Allowance&
    Allowance::
    operator=(Allowance&& other) {
    
        if(&other != this)
        {
            this->allowance = other.allowance;
            other.clear();
        }
        return *this;
    }
    
    Allowance&
    Allowance::
    clear() {

		allowance = 0;
        return *this;
    }

// Comparison //////////////////////////////////////////////////////////////////
    
    bool
    Allowance::
    operator==(const Allowance& other) const {
    
        return allowance == other.allowance;
    }
    
    bool
    Allowance::
    operator!=(const Allowance& other) const {
    
        return allowance != other.allowance;
    }

// Allowance //////////////////////////////////////////////////////////////////////

    std::size_t
    Allowance::
    getAllowance() const {
        
        return allowance;
    }
}
