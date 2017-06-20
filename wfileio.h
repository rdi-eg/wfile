#ifndef WFILEIO_H
#define WFILEIO_H

#include <string>

using namespace std;

extern "C++"
{
	std::wstring readWFile(string filename);
	bool writeWFile(string filename, wstring fileContent);
}

#endif // WFILEIO_H
