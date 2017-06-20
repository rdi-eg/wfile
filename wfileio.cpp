#include "wfileio.h"

#include <sstream>
#include <fstream>
#include <codecvt>

std::wstring readWFile(string filename)
{
	std::wifstream wif(filename.c_str());
	wif.imbue(std::locale(wif.getloc(), new std::codecvt_utf8<wchar_t>));
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}

bool writeWFile(string filename, wstring fileContent)
{
	std::wofstream wof(filename.c_str());
	if(!wof.is_open())
		return false;
	wof.imbue(std::locale(wof.getloc(), new std::codecvt_utf8<wchar_t>));
	wof << fileContent;
	return true;
}
