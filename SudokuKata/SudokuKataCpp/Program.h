#pragma once

#include <iostream>
#include <string>

#define SUDOKU_EXPORT _declspec(dllexport)

extern "C"
{
    SUDOKU_EXPORT
    int getLine()
    {
        return 42;
    }
}


class Program
{
};

