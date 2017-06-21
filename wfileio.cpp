#include "wfileio.h"
#include "utf8_file_dir.h"

#include <sstream>
#include <fstream>
#include <codecvt>

namespace RDI
{

wstring readWFile(string filename)
{
	wifstream wif(filename.c_str());
	wif.imbue(std::locale(wif.getloc(), new codecvt_utf8<wchar_t>));
	wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}

bool writeWFile(string filename, wstring fileContent)
{
	wofstream wof(filename.c_str());
	if(!wof.is_open())
		return false;
	wof.imbue(locale(wof.getloc(), new codecvt_utf8<wchar_t>));
	wof << fileContent;
	return true;
}

string readFile(string filename)
{
	ifstream stream(filename.c_str());
	stringstream ss;
	ss << stream.rdbuf();
	return ss.str();
}

bool writeFile(string filename, string fileContent)
{
	ofstream of(filename.c_str());
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

vector<wstring> readLinesWFile(string filename)
{
	wifstream wif(filename.c_str());
	wif.imbue(std::locale(wif.getloc(), new codecvt_utf8<wchar_t>));
	wstringstream wss;
	wss << wif.rdbuf();

	wstring tmp;
	vector<wstring> lines;
	while (getline(wss, tmp))
		lines.push_back(tmp);

	return lines;
}

bool writeLinesWFile(string filename, vector<wstring> linesToWrite)
{
	wofstream wof(filename.c_str());
	if(!wof.is_open())
		return false;
	wof.imbue(locale(wof.getloc(), new codecvt_utf8<wchar_t>));

	for (wstring line : linesToWrite)
		wof << line << endl;

	return true;
}

vector<string> readLinesFile(string filename)
{
	ifstream stream(filename.c_str());
	stringstream ss;
	ss << stream.rdbuf();

	string tmp;
	vector<string> lines;
	while (getline(ss, tmp))
		lines.push_back(tmp);

	return lines;
}

bool writeLinesFile(string filename, vector<string> linesToWrite)
{
	ofstream of(filename.c_str());
	if(!of.is_open())
		return false;

	for (string line : linesToWrite)
		of << line << endl;

	return true;
}

vector<string> getDirectoryContent(string path)
{
	DIR *dir;
	struct dirent *ent;
	vector<string> directoryContent;

	if (dir = opendir (path.c_str()))
	{
		while ((ent = readdir (dir)) != NULL)
		{
			string fileName = ent->d_name;
			if(fileName != "." && fileName != "..")
				directoryContent.push_back(fileName);
		}
	}

	return directoryContent;
}

bool appendToWFile(string filename, wstring content)
{
	wofstream wof;
	wof.open(filename.c_str(), std::ios_base::app);
	if(!wof.is_open())
		return false;
	wof.imbue(locale(wof.getloc(), new codecvt_utf8<wchar_t>));
	wof << content;
	return true;
}

bool appendToFile(string filename, string content)
{
	ofstream of;
	of.open(filename.c_str(), std::ios_base::app);
	if(!of.is_open())
		return false;
	of << content;
	return true;
}

} //namespace
