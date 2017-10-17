# wFileIO
A little C++ lib that helps you do file operations with normal and wstrings.

Based on the wonderful [Snippet Library](https://github.com/cubiclesoft/cross-platform-cpp) from CubicleSoft.

We faced some issues when dealing with non-latin characters, so we created this library to help us with file I/O operations.

# Usage

Just include `rdi_wfileio.h` and call any of the following functions.
```c++
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
	bool delete_file(std::string path);
	std::string absolute_path(std::string path);
	std::string get_current_directory(); // returns the location of the binary executable ex: "/home/rdi/bin"
	std::vector<std::string> get_directory_content(const std::string& path);
	bool create_directory(std::string path);
	bool delete_directory(std::string path);
}
```
