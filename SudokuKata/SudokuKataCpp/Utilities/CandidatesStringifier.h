#pragma once

#include <string>
#include <vector>
#include "../stringhelper.h"

namespace SudokuKata::Utilities
{
	class CandidatesStringifier
	{
	public:
		static std::wstring ConvertToString(std::vector<int> &candidateMasks);

	private:
		static bool IsAtBlockBoundary(int value);

		static std::wstring RowForOneCell(int index, int mask, int digitIndex1, int digitIndex2, int digitIndex3);

		static std::wstring CharacterForDigit(int mask, int digit);
	};
}
