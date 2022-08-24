/**
 * @file `Allowance` class
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

        /**
         * Setting an allowance of `n` requires the line breaking algorithm to
		 * allow for `n` characters on the line following the next break, if
		 * there is one.  The allowance hence applies after the next output
		 * operation.  If the next output operation is zero length a break
		 * may be inserted.  If the allowance exceeds the line length then
		 * the subsequent output operation may also exceed the line length.
         */
    class Allowance {
      
    private:

        static const int allowanceIndex;

        std::size_t allowance;
                
        template<class Stream>
        friend Stream& operator<<(
            Stream& out, const Allowance& manipulator);
            
        friend OutputStream& operator<<(
            OutputStream& out, typename OutputStream::char_type c);

        friend OutputStream& operator<<(
            OutputStream& out, const typename OutputStream::char_type* s);
            
        template<class Stream>
        friend Allowance getAllowance(Stream& s);

// Construction and assignment /////////////////////////////////////////////////

    public:

        explicit Allowance(std::size_t allowance = 0);

        Allowance(const Allowance& other) = default;
        
        Allowance(Allowance&& other);
        
        Allowance& operator=(
            const Allowance& other) = default;
        
        Allowance& operator=(Allowance&& other);
            
    protected:
    
        Allowance& clear();
        
// Comparison //////////////////////////////////////////////////////////////////

    public:
    
        bool operator==(const Allowance& other) const;
        
        bool operator!=(const Allowance& other) const;

// Allowance //////////////////////////////////////////////////////////////////////

    public:

        std::size_t getAllowance() const;
    };

    template<class Stream>
    Stream& operator<<(Stream& out, const Allowance& manipulator);
    
    template<class Stream>
    Allowance getAllowance(Stream& s);
}
