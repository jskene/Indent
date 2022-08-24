/**
 * @file `Indent` class
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
         * A stream manipulator
         */
    class Indent {
      
    private:

        static const int indentIndex;

        std::size_t indent;
                
        template<class Stream>
        friend Stream& operator<<(
            Stream& out, const Indent& manipulator);

        friend OutputStream& operator<<(
            OutputStream& out, typename OutputStream::char_type c);

        friend OutputStream& operator<<(
            OutputStream& out, const typename OutputStream::char_type* s);

        template<class Stream>
        friend Indent getIndent(Stream& s);

// Construction and assignment /////////////////////////////////////////////////

    public:

            /**
             * Create a manipulator that clears the indentation.
             */
        Indent();

        explicit Indent(std::size_t indent);

        Indent(const Indent& other) = default;
        
        Indent(Indent&& other);
        
        Indent& operator=(
            const Indent& other) = default;
        
        Indent& operator=(Indent&& other);
            
    protected:
    
        Indent& clear();
        
// Comparison //////////////////////////////////////////////////////////////////

    public:
    
        bool operator==(const Indent& other) const;
        
        bool operator!=(const Indent& other) const;

// Indent //////////////////////////////////////////////////////////////////////

    public:

        std::size_t getIndent() const;
    };

    template<class Stream>
    Stream& operator<<(Stream& out, const Indent& manipulator);
    
    template<class Stream>
    Indent getIndent(Stream& s);
}
