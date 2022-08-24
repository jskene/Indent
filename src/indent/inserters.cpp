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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "indent/indent.h"

namespace indent {

    OutputStream&
    operator<<(OutputStream& out, typename OutputStream::char_type c) {

		
		long& lineLength = out.iword(LineLength::lineLengthIndex);
		long& tabLength = out.iword(LineLength::tabLengthIndex);
		long& continuationChar = out.iword(LineLength::continuationCharIndex);
		long& column = out.iword(LineLength::columnIndex);
		long& lastBlank = out.iword(LineLength::lastBlankIndex);
		long& indentation = out.iword(Indent::indentIndex);
		
		const CType& facet = useFacet<CType>(out.getloc());
		char n = facet.narrow(c, '?');
		
		switch(n) {
		
		case ' ':
			{
				std::size_t newColumn = column + 1;
				if(!lineLength || newColumn < lineLength)
				{
					std::operator<<(out, c);
					column = newColumn;
					lastBlank = true;
				}
				else
				{
					out << typename OutputStream::char_type('\n');
				}
				break;
			}
		
		case  '\t':
			{
				std::size_t newColumn =
					((column + tabLength) / tabLength) * tabLength;
				if(!lineLength || newColumn < lineLength)
				{
					std::operator<<(out, c);
					column = newColumn;
					lastBlank = true;
				}
				else
				{
					out << typename OutputStream::char_type('\n');
				}
				break;
			}
		
		case  '\n':
			std::operator<<(out, c);
			column = 0;
			lastBlank = true;
			break;

		default:
			{
				if(column == 0)
				{
					for(std::size_t i = 0; i < indentation; i++)
					{
						std::operator<<(out, ' ');
						++column;
					}
					std::operator<<(out, c);
					++column;
				}
				else if(column == lineLength && !lastBlank)
				{
					std::operator<<(out,
						typename OutputStream::char_type(continuationChar));
					out << typename OutputStream::char_type('\n');
					out << c;
				}
				else
				{
					std::operator<<(out, c);
					++column;
					lastBlank = false;
				}
			}
			break;
		}
        return out;
    }

    OutputStream&
    operator<<(
		OutputStream& out, const typename OutputStream::char_type* string) {
     
		long& lineLength = out.iword(LineLength::lineLengthIndex);
		long& continuationChar = out.iword(LineLength::continuationCharIndex);
		long& badness = out.iword(LineLength::badnessIndex);
		long& continuation = out.iword(LineLength::continuationIndex);
		long& column = out.iword(LineLength::columnIndex);
		long& indentation = out.iword(Indent::indentIndex);
		long& allowance = out.iword(Allowance::allowanceIndex);

		const CType& facet = useFacet<CType>(out.getloc());
		
		const typename OutputStream::char_type* start = string;
		while(*start)
		{
			while(*start && facet.is(CType::blank, *start))
			{
				out << *start;
				++start;
			}
			const typename OutputStream::char_type* end = start;
			while(*end && !facet.is(CType::blank, *end))
			{
				++end;
			}
			if(end > start)
			{
				if(lineLength > 0) {
				
					std::size_t wordLength = end - start;
					std::size_t margin = column? lineLength - column :
						lineLength - indentation;
					if(margin < allowance)
					{
							// There is an allowance to give.  If word would
							// not break on this line if it is given then give it
						if(wordLength < margin)
						{
							while(start < end)
							{
								out << *start;
								++start;
							}
							allowance -= wordLength;
						}
							// If word would break on next line if allowance is
							// withheld (and word is wrapped), then withold it
						else if(wordLength >
							std::max(lineLength - indentation, allowance))
						{
							std::size_t prefix = wordLength - margin - 1;
							end = start + prefix;
							while(start < end)
							{
								out << *start;
								++start;
							}
							std::operator<<(out,
								typename OutputStream::char_type(
									continuationChar));
							out << typename OutputStream::char_type('\n');
							allowance -= prefix;
						}
							// Word would not break on next line if allowance is
							// withheld, so wrap.
						else
						{
							out << typename OutputStream::char_type('\n');
						}
					}
					else
					{
							// No allowance for this word
						if(wordLength > margin)
						{
							std::size_t prefix = margin - 1;
							if(margin < badness &&
								wordLength - prefix >= continuation)
							{
								out << typename OutputStream::char_type('\n');
							}
							else
							{
									// Print prefix the break
								end = start + prefix;
								while(start < end)
								{
									out << *start;
									++start;
								}
								std::operator<<(out,
									typename OutputStream::char_type(
										continuationChar));
								out << typename OutputStream::char_type('\n');
							}
						}
						else
						{
							while(start < end)
							{
								out << *start;
								++start;
							}
						}
					
					}
				}
				else
				{
					while(start < end)
					{
						out << *start;
						++start;
					}
				}
			}
		}
			// Possible allowance for next output
		if(allowance < 0)
		{
			allowance = -allowance;
		}
        return out;
    }

    OutputStream&
    operator<<(OutputStream& out, const String& string) {

        return out << string.c_str();
    }
    
	OutputStream& endl(OutputStream& out) {
	
		return std::flush(out << '\n');
	}
}

