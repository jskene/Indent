
#include <iostream>

#include "indent/indent.h"

int main(int argc, char* argv[]) {

	using namespace indent;

//	const char numbers[] =
//		"01234567891123456789022345678931234567894123456789"
//		"51234567896123456789712345678981234567899123456789";
//	const char  url[] = "http://www.somelongdomainname.com/path/path/path";
	const char lorem[] =
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
		"eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim "
		"ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut "
		"aliquip ex ea commodo consequat. Duis aute irure dolor in "
		"reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
		"pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
		"culpa qui officia deserunt mollit anim id est laborum.";

	std::cout << LineLength(78) << Indent(4) << lorem << endl << endl <<
		Indent(8) << lorem << endl;

	return 0;
}
