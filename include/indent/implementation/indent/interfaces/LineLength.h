/**
 * @file `LineLength` class
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
         * Sets or resets various parameters related to line breaking.
		 * Line breaking is enabled with a non-zero line length.
		 *
		 * ```
		 * 	// 78 is a good choice to keep the continuation character `-` off
		 *	// the right margin on the console.
		 * out << LineLength(78);
		 * ```
		 *
		 * Line breaking is disabled with a line length of zero.
		 *
		 * ```
		 * out << LineLength();
		 * ```
		 *
		 * The `tabLength` parameter should match the behaviour of the stream.
		 * The default value is `8`.
		 *
		 * The `badness` and `continuation` parameters affect line breaking.
		 * A word is wrapped if it needs to be, and blank space at the end
		 * of the line does not exceed `badness`, otherwise it is broken using
		 * the contination character.  However, if breaking it leaves fewer
		 * than `continuation` characters on the next line it is wrapped
		 * instead, in spite of the badness.  On the other hand if a word to
		 * be wrapped would then need to be broken, and breaking it would leave
		 * fewer than `continuation` characters on the subsequent line, it
		 * is instead broken on the first line.
		 *
		 * Note that if `badness` and `continuation` are both zero then the
		 * algorithm will always break.  If `badness` is equal to `lineLength`
		 * and `continuation` is zero then it will always wrap.
         */
    class LineLength {
      
    private:

        static const int lineLengthIndex;
        
        static const int tabLengthIndex;
        
        static const int continuationCharIndex;
        
        static const int badnessIndex;
        
        static const int continuationIndex;
        
        static const int columnIndex;
        
        static const int lastBlankIndex;
        
        std::size_t lineLength;
        
        std::size_t tabLength;
        
        Char continuationChar;
        
        std::size_t badness;
        
        std::size_t continuation;
        
        template<class Stream>
        friend Stream& operator<<(
            Stream& out, const LineLength& manipulator);
            
        friend OutputStream& operator<<(
            OutputStream& out, typename OutputStream::char_type c);

        friend OutputStream& operator<<(
            OutputStream& out, const typename OutputStream::char_type* s);

        template<class Stream>
        friend LineLength getLineLength(Stream& s);

// Construction and assignment /////////////////////////////////////////////////

    public:

        explicit LineLength(
			std::size_t lineLength = 0,
			std::size_t tabLength = 8,
			Char continationChar = '-',
			std::size_t badness = 4,
			std::size_t continuation = 2);

        LineLength(const LineLength& other) = default;
        
        LineLength(LineLength&& other);
        
        LineLength& operator=(
            const LineLength& other) = default;
        
        LineLength& operator=(LineLength&& other);
            
    protected:
    
        LineLength& clear();
        
// LineLength //////////////////////////////////////////////////////////////////

    public:

        std::size_t getLineLength() const;
        
        std::size_t getTabLength() const;
        
        Char getContinuationChar() const;
        
        std::size_t getBadness() const;
        
        std::size_t getContinuation() const;
    };

	template<class Stream>
    Stream& operator<<(Stream& out, const LineLength& manipulator);
    
    template<class Stream>
    LineLength getLineLength(Stream& s);
}
