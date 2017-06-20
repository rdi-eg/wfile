#ifndef WFILEIO_H
#define WFILEIO_H

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
bool writeLinesWFile(string filename, vector<wstring> linesToWrite);
string readFile(string filename);
vector<string> readLinesFile(string filename);
bool writeFile(string filename, string fileContent);
bool writeLinesFile(string filename, vector<string> linesToWrite);
string getCurrentDirectory(); // returns the location of the binary ex "/home/rdi/bin"
}
} // namespace

#endif // WFILEIO_H
