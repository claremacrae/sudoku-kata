#pragma once

#include <string>
#include <vector>

namespace SudokuKata::Utilities
{
    class GridStringifier
    {
    public:
        static std::wstring ConvertToString(std::vector<int>& board);

    private:
        static std::wstring ToRowNumbered(std::vector<int>& board, int row);

        static std::wstring ToRow(std::vector<int>& board,
                                  int index0,
                                  int index1,
                                  int index2,
                                  int index3,
                                  int index4,
                                  int index5,
                                  int index6,
                                  int index7,
                                  int index8);

        static std::wstring ToTriplet(std::vector<int>& board, int index0, int index1, int index2);

        static std::wstring ToCell(int value);

    public:
        static std::wstring ConvertToCode(std::vector<int>& board);
    };
}
