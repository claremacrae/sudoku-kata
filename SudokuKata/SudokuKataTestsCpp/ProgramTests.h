#pragma once

#include <string>
#include <stdexcept>
#include "tangible_filesystem.h"

namespace SudokuKata { class IRandomValueGenerator; }

namespace SudokuKataTests
{
	class ProgramTests
	{
	public:
		static std::wstring SeedSectionName(int seed);

		static void VerifySudokuForSeed(std::wstringstream &console,
                                        int seed,
                                        SudokuKata::IRandomValueGenerator *randomValueGenerator);

		static std::wstring GetSeedsFileName(int seed);
	};
}
