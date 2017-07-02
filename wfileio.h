#ifndef WFILEIO_H
#define WFILEIO_H

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
#define WINDOWS_OS
#else
#define LINUX_OS
#endif

#ifdef WINDOWS_OS
#include "windows_dirent.h"
#else
#include <dirent.h>
#endif


#include <string>
#include <vector>

using namespace std;

extern "C++"
{
	namespace RDI
	{
		wstring readWFile(string filename);
		vector<wstring> readLinesWFile(string filename);
		bool writeWFile(string filename, wstring fileContent);
		bool appendToWFile(string filename, wstring content);
		bool writeLinesWFile(string filename, vector<wstring> linesToWrite);
		string readFile(string filename);
		vector<string> readLinesFile(string filename);
		bool writeFile(string filename, string fileContent);
		bool appendToFile(string filename, string content);
		bool writeLinesFile(string filename, vector<string> linesToWrite);
		bool deleteFile(string path);
		string absolutePath(string path);
		string getCurrentDirectory(); // returns the location of the binary ex "/home/rdi/bin"
		vector<string> getDirectoryContent(string path);
		bool createDirectory(string path);
		bool deleteDirectory(string path);
	}
} // namespace

#endif // WFILEIO_H
