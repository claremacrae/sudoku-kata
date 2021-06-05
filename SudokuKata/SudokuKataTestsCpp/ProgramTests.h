#pragma once

#include <string>
#include <stdexcept>

namespace SudokuKata
{
    class IRandomValueGenerator;
}

namespace SudokuKataTests
{
    class ProgramTests
    {
    public:
        static std::string SeedSectionName(int seed);

        static void VerifySudokuForSeed(SudokuKata::IRandomValueGenerator* randomValueGenerator);

        static std::string GetSeedsFileName();
    };
}
