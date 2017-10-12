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

extern "C++"
{
	namespace RDI
	{
		std::wstring readWFile(std::string filename);
		std::vector<std::wstring> readLinesWFile(std::string filename);
		bool writeWFile(std::string filename, std::wstring fileContent);
		bool appendToWFile(std::string filename, std::wstring content);
		bool writeLinesWFile(std::string filename, std::vector<std::wstring> linesToWrite);
		std::string readFile(std::string filename);
		std::vector<std::string> readLinesFile(std::string filename);
		bool writeFile(std::string filename, std::string fileContent);
		bool appendToFile(std::string filename, std::string content);
		bool writeLinesFile(std::string filename, std::vector<std::string> linesToWrite);
		bool deleteFile(std::string path);
		std::string absolutePath(std::string path);
		std::string getCurrentDirectory(); // returns the location of the binary ex "/home/rdi/bin"
		std::vector<std::string> getDirectoryContent(std::string path);
		bool createDirectory(std::string path);
		bool deleteDirectory(std::string path);
	}
} // namespace

#endif // WFILEIO_H
