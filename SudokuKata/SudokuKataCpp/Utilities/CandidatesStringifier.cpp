#include "CandidatesStringifier.h"

namespace SudokuKata::Utilities
{

    std::wstring CandidatesStringifier::ConvertToString(std::vector<int>& candidateMasks)
    {
        auto blockDivider = L"++=====+=====+=====++=====+=====+=====++=====+=====+=====++\n";
        auto rowDivider = L"++-----+-----+-----++-----+-----+-----++-----+-----+-----++\n";
        std::wstring result = blockDivider;

        for (int row = 0; row < 9; row++)
        {
            std::wstring line1 = L"||";
            std::wstring line2 = L"||";
            std::wstring line3 = L"||";
            for (int col = 0; col < 9; col++)
            {
                // var index = CellPosition.Index(row, col);
                auto index = (9 * row) + col;
                auto mask = candidateMasks[index];
                line1 += RowForOneCell(index, mask, 1, 2, 3);
                line2 += RowForOneCell(index, mask, 4, 5, 6);
                line3 += RowForOneCell(index, mask, 7, 8, 9);
            }

            result += line1 + L"\n";
            result += line2 + L"\n";
            result += line3 + L"\n";
            result += IsAtBlockBoundary(row) ? blockDivider : rowDivider;
        }

        return result;
    }

    bool CandidatesStringifier::IsAtBlockBoundary(int value)
    {
        return (value + 1) % 3 == 0;
    }

    std::wstring CandidatesStringifier::RowForOneCell(
        int index, int mask, int digitIndex1, int digitIndex2, int digitIndex3)
    {
        std::wstring result = L" ";
        result += CharacterForDigit(mask, digitIndex1);
        result += CharacterForDigit(mask, digitIndex2);
        result += CharacterForDigit(mask, digitIndex3);
        result += IsAtBlockBoundary(index) ? L" ||" : L" |";
        return result;
    }

    std::wstring CandidatesStringifier::CharacterForDigit(int mask, int digit)
    {
        std::wstring blank = StringHelper::toString(L'.');
        auto digitMask = 1 << (digit - 1);
        auto character = ((mask & digitMask) != 0) ? std::to_wstring(digit) : blank;
        return character;
    }
}
