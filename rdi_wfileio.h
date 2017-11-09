//rdi_wfileio.h

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
#include<map>

extern "C++"
{
	namespace RDI
	{
		std::wstring read_wfile(const std::string &filename);
		std::vector<std::wstring> read_wfile_lines(const std::string &filename);
		bool write_wfile(const std::string &filename, const std::wstring &fileContent);
		bool append_to_wfile(const std::string &filename, const std::wstring &content);
		bool write_wfile_lines(const std::string& filename, const std::vector<std::wstring>& linesToWrite);
		std::string read_file(const std::string& filename);
		std::vector<std::string> read_file_lines(const std::string& filename);
		bool write_file(const std::string& filename, const std::string& fileContent);
		bool append_to_file(const std::string& filename, const std::string& content);
		bool write_file_lines(const std::string& filename, const std::vector<std::string>& linesToWrite);
		bool delete_file(const std::string& path);
		std::string absolute_path(std::string path);
		std::string get_current_directory(); // returns the location of the binary executable ex: "/home/rdi/bin"
		std::vector<std::string> get_directory_content(const std::string& path);
		bool create_directory(std::string path);
		bool delete_directory(const std::string& path);
		std::map<std::string , std::string> parse_config_file(const std::string& filename);
                bool dump_matrix(const std::string &file_name , std::vector<std::vector<float>> &input_matrix);
	}
} // namespace

#endif // RDI_WFILEIO_H
