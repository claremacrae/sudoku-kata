#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>
#include "Utilities/IRandomValueGenerator.h"
namespace SudokuKata
{

    class Puzzle
    {
    protected:
        static std::vector<int> ConstructBoardToSolve(std::vector<std::vector<char>>& board,
                                                      IRandomValueGenerator* rng);
        static std::vector<std::vector<char>> ConstructFullBoard();
        std::vector<std::vector<char>> board;
        std::vector<int> state;
    };

}

#endif //PUZZLE_H
