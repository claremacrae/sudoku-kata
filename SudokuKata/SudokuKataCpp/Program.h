#pragma once

#include "Utilities/IRandomValueGenerator.h"
#include <string>
#include <vector>

namespace SudokuKata
{
    class Program
    {
    public:
        static void Play(std::wostream& console, IRandomValueGenerator* rng);

        static void Main(std::vector<std::wstring>& args);
    };
}
