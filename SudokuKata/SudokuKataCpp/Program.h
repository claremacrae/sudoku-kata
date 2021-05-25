#pragma once

#include <iostream>
#include <string>

#include <combaseapi.h>

#define SUDOKU_EXPORT _declspec(dllexport)


char* marshallString(const std::string& text)
{
    auto szSampleString = text.c_str();
    ULONG ulSize = strlen(szSampleString) + sizeof(char);
    char* pszReturn = NULL;

    pszReturn = (char*)::CoTaskMemAlloc(ulSize);
    // Copy the contents of szSampleString
    // to the memory pointed to by pszReturn.
    strcpy(pszReturn, szSampleString);
    // Return pszReturn.
    return pszReturn;
}

extern "C"
{
    SUDOKU_EXPORT
    int getInt()
    {
        return 42;
    }

    SUDOKU_EXPORT
    const char* getLine()
    {
        return "+---+---+---+";
    }

    __declspec(dllexport) char* __stdcall StringReturnAPI01()
    {
        char szSampleString[] = "+---+---+---+";
        return marshallString(szSampleString);
    }
}


class Program
{
};

