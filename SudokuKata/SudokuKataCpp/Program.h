﻿#pragma once

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

    private:
        std::vector<std::vector<char>> board;
        std::vector<int> state;
        static std::vector<std::vector<char>> ConstructFullBoard();
        static std::vector<int> ConstructBoardToSolve(std::vector<std::vector<char>>& board1,
                                                      IRandomValueGenerator* rng);
    };
}
