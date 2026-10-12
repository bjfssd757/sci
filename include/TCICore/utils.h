#pragma once

#include <string>
#include <windows.h>
#include <filesystem>

#define SDKAPI extern "C" __declspec(dllexport)
#define SDKAPI_STRUCT __declspec(dllexport)

bool fileExistsTest(const std::wstring& name);
std::string LPCWSTRToString(LPCWSTR str);
std::filesystem::path GetExeRootDir();
std::filesystem::path GetAllowedDLLDir();

struct TTT {
    unsigned int low, high;
};

union TConv {
    TTT t;
    unsigned long long int big;
};