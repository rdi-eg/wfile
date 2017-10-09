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
		std::wstring readWFile(const std::string &filename);
		std::vector<std::wstring> readLinesWFile(const std::string &filename);
		bool writeWFile(const std::string &filename, const std::wstring &fileContent);
		bool appendToWFile(const std::string &filename, const std::wstring &content);
		bool writeLinesWFile(const std::string& filename, const std::vector<std::wstring>& linesToWrite);
		std::string readFile(const std::string& filename);
		std::vector<std::string> readLinesFile(const std::string& filename);
		bool writeFile(const std::string& filename, const std::string& fileContent);
		bool appendToFile(const std::string& filename, const std::string& content);
		bool writeLinesFile(const std::string& filename, const std::vector<std::string>& linesToWrite);
		bool deleteFile(std::string path);
		std::string absolutePath(std::string path);
		std::string getCurrentDirectory(); // returns the location of the binary ex "/home/rdi/bin"
		std::vector<std::string> getDirectoryContent(const std::string& path);
		bool createDirectory(std::string path);
		bool deleteDirectory(std::string path);
	}
} // namespace

#endif // WFILEIO_H
