#include "TCICore/extensions-api.h"
#include <TCICore/utils.h>
#include <fstream>

bool fileExistsTest(const std::wstring& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

std::string LPCWSTRToString(LPCWSTR wstr) {
    if (!wstr) return "";
    int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    if (sizeNeeded <= 1) return "";
    
    std::string result(sizeNeeded - 1, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, &result[0], sizeNeeded, NULL, NULL);
    return result;
}

std::filesystem::path GetExeRootDir() {
    wchar_t exePathBuf[MAX_PATH];
    GetModuleFileNameW(NULL, exePathBuf, MAX_PATH);
    std::filesystem::path serverRootDir = std::filesystem::path(exePathBuf).parent_path();
    return serverRootDir;
}

std::filesystem::path GetAllowedDLLDir() {
    return GetExeRootDir() / std::filesystem::path(ALLOWED_DIRECTORY);
}