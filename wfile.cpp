#include "rdi_wfile.h"
#include "utf8_file_dir.h"

#include <sstream>
#include <fstream>
#include <codecvt>
#include <utility>
#include <assert.h>
#include <algorithm>
#include <memory>
#include <boost/filesystem.hpp>

using namespace std;

namespace RDI
{

wstring read_wfile(const string& filename)
{
    if(!file_exists(filename))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    wifstream wif(filename.c_str());
    wif.imbue(locale(wif.getloc(), new codecvt_utf8<wchar_t>));
    wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}

bool write_wfile(const string& filename, const wstring& fileContent)
{
    wofstream wof(filename.c_str());
    if(!wof.is_open())
        return false;
    wof.imbue(locale(wof.getloc(), new codecvt_utf8<wchar_t>));
    wof << fileContent;
    return true;
}

string read_file(const string &filename)
{
    if(!file_exists(filename))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    ifstream stream(filename.c_str());
    stringstream ss;
    ss << stream.rdbuf();
    return ss.str();
}

bool write_file(const string &filename, const string &fileContent)
{
    ofstream of(filename.c_str());
    if(!of.is_open())
        return false;
    of << fileContent;
    return true;
}

string get_current_directory()
{
    char* strPath = new char[512];
    CubicleSoft::UTF8::Dir::Getcwd(strPath, 512);

    string path(strPath);
    delete[] strPath;
    return path + "/";
}

vector<wstring> read_wfile_lines(const string &filename)
{
    if(!file_exists(filename))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    std::setlocale(LC_ALL, "en_US.UTF-8");
    wifstream wif(filename.c_str());
    wif.imbue(locale(wif.getloc(), new codecvt_utf8<wchar_t>));
    wstringstream wss;
    wss << wif.rdbuf();

    wstring tmp;
    vector<wstring> lines;
    while (getline(wss, tmp))
        lines.push_back(tmp);

    return lines;
}

bool write_wfile_lines(const string &filename, const vector<wstring> &linesToWrite)
{
    wofstream wof(filename.c_str());
    if(!wof.is_open())
        return false;
    wof.imbue(locale(wof.getloc(), new codecvt_utf8<wchar_t>));

    for (wstring line : linesToWrite)
        wof << line << endl;

    return true;
}

vector<string> read_file_lines(const string &filename)
{
    if(!file_exists(filename))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    ifstream stream(filename.c_str());
    stringstream ss;
    ss << stream.rdbuf();

    string tmp;
    vector<string> lines;
    while (getline(ss, tmp))
        lines.push_back(tmp);

    return lines;
}

bool write_file_lines(const string &filename, const vector<string> &linesToWrite)
{
    ofstream of(filename.c_str());
    if(!of.is_open())
        return false;

    for (string line : linesToWrite)
        of << line << endl;

    return true;
}

vector<string> get_directory_content(const string &path)
{
    DIR* dir = opendir (path.c_str());
    struct dirent *ent;
    vector<string> directoryContent;

    if (dir)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            string fileName = ent->d_name;
            if(fileName != "." && fileName != "..")
                directoryContent.push_back(fileName);
        }
    }

    closedir(dir);
    sort(directoryContent.begin(), directoryContent.end());

    return directoryContent;
}

bool append_to_wfile(const string& filename, const wstring& content)
{
    if(!file_exists(filename))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    wofstream wof;
    wof.open(filename.c_str(), ios_base::app);
    if(!wof.is_open())
        return false;
    wof.imbue(locale(wof.getloc(), new codecvt_utf8<wchar_t>));
    wof << content;
    return true;
}

bool append_to_file(const string &filename, const string &content)
{
    if(!file_exists(filename))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    ofstream of;
    of.open(filename.c_str(), ios_base::app);
    if(!of.is_open())
        return false;
    of << content;
    return true;
}

vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}

string get_absolute_path(string path)
{
    if (path.size() && path[0] != '/')
    {
        path = get_current_directory() + path;
    }

    unique_ptr<char[]> absolutePath = unique_ptr<char[]>(new char[8129]);
    assert(CubicleSoft::UTF8::File::Realpath(absolutePath.get(), 8129, path.c_str()));
    return string(absolutePath.get());
}

pair<string, string> splitPathAndFilename(string path)
{
    vector<string> pathExploded = explode(path, '/');
    string filename = pathExploded.back();
    pathExploded.pop_back();
    string restOfPath = "";

    for (string dir : pathExploded)
        restOfPath += dir + "/";

    pair<string, string> pathAndFilename;
    pathAndFilename.first = restOfPath;
    pathAndFilename.second = filename;

    return pathAndFilename;
}

bool create_directory(string path)
{
    return CubicleSoft::UTF8::Dir::Mkdir(path.c_str());
}

bool delete_directory(const string& path)
{
    return CubicleSoft::UTF8::Dir::Rmdir(path.c_str(), true);
}

bool delete_file(const string& path)
{
    if(!file_exists(path))
        throw std::runtime_error("!!!ERROR!!! File doesn't exist");

    return CubicleSoft::UTF8::File::Delete(path.c_str());
}

map<string , string> parse_config_file(const string& filename)
{
    vector<string> file_content = read_file_lines(filename);
    map<string , string> map_content;

    for(const auto &line : file_content)
    {
        size_t found;
        if ((found = line.find("=")) != string::npos)
        {
            string key = line.substr(0 , found-1);
            string value = line.substr(found+2 , string::npos);
            map_content[key] = value;
        }
    }
    return map_content;
}

bool dump_matrix(const std::string &file_name, std::vector<std::vector<float>> &input_matrix)
{
    std::vector<std::string> content;

    for(const auto& inner : input_matrix)
    {
        std::string line = "";
        for(const auto& item : inner)
        {
            line += std::to_string(item);
            line += " ";
        }
        content.push_back(line);
    }

    if(write_file_lines(file_name, content))
        return true;

    return false;
}

bool file_exists(const string &file_name)
{
    return CubicleSoft::UTF8::File::Exists(file_name.c_str());
}

bool is_directory(const std::string& path)
{
    CubicleSoft::UTF8::Dir dir;
    if (dir.Open(path.c_str()))
    {
        return true;
    }

    return false;
}

std::string extract_filename(std::string path)
{
    if (is_directory(path))
    {
        throw std::runtime_error("This is a directory.");
    }

    boost::filesystem::path boost_path(path);
    return boost_path.filename().string();
}

std::string extract_filename_without_extension(std::string path)
{
    if (is_directory(path))
    {
        throw std::runtime_error("This is a directory.");
    }

    boost::filesystem::path boost_path(path);
    return boost_path.stem().string();
}

} //namespace
