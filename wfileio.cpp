#include "wfileio.h"
#include "utf8_file_dir.h"

#include <sstream>
#include <fstream>
#include <codecvt>

namespace RDI
{

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

std::string readFile(string filename)
{
	std::ifstream stream(filename.c_str());
	std::stringstream ss;
	ss << stream.rdbuf();
	return ss.str();
}

bool writeFile(string filename, string fileContent)
{
	std::ofstream of(filename.c_str());
	if(!of.is_open())
		return false;
	of << fileContent;
	return true;
}

string getCurrentDirectory()
{
	char* strPath = new char[512];
	CubicleSoft::UTF8::Dir::Getcwd(strPath, 512);

	string path(strPath);
	delete[] strPath;
	return path;
}

} //namespace
