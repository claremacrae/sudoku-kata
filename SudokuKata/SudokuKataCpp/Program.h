#pragma once

#include "Utilities/IRandomValueGenerator.h"
#include <string>
#include <vector>

namespace SudokuKata
{
    class Program
    {
    public:
        void Play(std::ostream& console, IRandomValueGenerator* rng);

        static void Main(std::vector<std::string>& args);
    };
}
