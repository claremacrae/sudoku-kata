#include "GridStringifier.h"

namespace SudokuKata::Utilities
{

	std::wstring GridStringifier::ConvertToString(std::vector<int> &board)
	{
		const std::wstring divider = L"+---+---+---+\n";
		auto result = divider;
		result += ToRowNumbered(board, 0);
		result += ToRowNumbered(board, 1);
		result += ToRowNumbered(board, 2);
		result += divider;
		result += ToRowNumbered(board, 3);
		result += ToRowNumbered(board, 4);
		result += ToRowNumbered(board, 5);
		result += divider;
		result += ToRowNumbered(board, 6);
		result += ToRowNumbered(board, 7);
		result += ToRowNumbered(board, 8);
		result += divider;
		return result;
	}

	std::wstring GridStringifier::ToRowNumbered(std::vector<int> &board, int row)
	{
		auto o = row * 9;
		return ToRow(board, o + 0, o + 1, o + 2, o + 3, o + 4, o + 5, o + 6, o + 7, o + 8);
	}

	std::wstring GridStringifier::ToRow(std::vector<int> &board, int index0, int index1, int index2, int index3, int index4, int index5, int index6, int index7, int index8)
	{
		std::wstring row = L"|";
		row += ToTriplet(board, index0, index1, index2);
		row += L"|";
		row += ToTriplet(board, index3, index4, index5);
		row += L"|";
		row += ToTriplet(board, index6, index7, index8);
		row += L"|";
		row += L"\n";
		return row;
	}

	std::wstring GridStringifier::ToTriplet(std::vector<int> &board, int index0, int index1, int index2)
	{
		auto value1 = board[index0];
		auto value2 = board[index1];
		auto value3 = board[index2];
		return ToCell(value1) + ToCell(value2) + ToCell(value3);
	}

	std::wstring GridStringifier::ToCell(int value)
	{
		return value == 0 ? L"." : std::to_wstring(value);
	}

	std::wstring GridStringifier::ConvertToCode(std::vector<int> &board)
	{
		return std::wstring::Join(L"", board);
	}
}
