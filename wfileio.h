#ifndef WFILEIO_H
#define WFILEIO_H

#include <string>

using namespace std;

extern "C++"
{
	std::wstring readWFile(string filename);
	bool writeWFile(string filename, wstring fileContent);
	std::string readFile(string filename);
	bool writeFile(string filename, string fileContent);
}

#endif // WFILEIO_H
