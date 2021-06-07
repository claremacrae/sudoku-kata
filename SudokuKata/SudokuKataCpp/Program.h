#pragma once

#include "Utilities/IRandomValueGenerator.h"
#include "Puzzle.h"
#include <string>
#include <vector>

namespace SudokuKata
{
    class Program : public Puzzle
    {
    public:
        void Play(std::ostream& console, IRandomValueGenerator* rng);

        static void Main(std::vector<std::string>& args);
    };
}
