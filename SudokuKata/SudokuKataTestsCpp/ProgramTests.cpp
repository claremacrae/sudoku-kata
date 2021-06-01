#include "ProgramTests.h"

#include "catch2/catch.hpp"
#include "ApprovalTests.hpp"

#include "Program.h"
#include "Utilities/FileReadingRandomNumber.h"
#include "Utilities/WStringHelpers.h"

using namespace ApprovalTests;
using namespace SudokuKata;

namespace SudokuKataTests
{

	TEST_CASE("TestSeed")
	{
		auto errors = 0;
		for (int seed = 0; seed < 20; seed++)
		{
			// var randomValueGenerator = new FileWritingRandomNumber(seed);
			auto randomValueGenerator = new FileReadingRandomNumber();

			auto section = ProgramTests::SeedSectionName(seed);
			SECTION(toString(section))

			{
				randomValueGenerator->ReadValuesFromFile(ProgramTests::GetSeedsFileName(seed));
			}

			{
				try
				{
					ProgramTests::VerifySudokuForSeed(seed, randomValueGenerator);
				}
				catch (const std::runtime_error &e)
				{
#if 0
					_testOutputHelper->WriteLine(e.what());
#endif
					errors += 1;
				}
			}

			// {
			//     var seedsFile = GetSeedsFileName(seed);
			//     randomValueGenerator.WriteValuesToFile(seedsFile);
			// }

		}
		CHECK(0 == errors);
	}

	std::wstring ProgramTests::SeedSectionName(int seed)
	{
		std::wstringstream s;
		s << std::setfill ( L' ' ) << std::setw (2) << seed;
        return s.str();
    }

	void ProgramTests::VerifySudokuForSeed(int seed, IRandomValueGenerator *randomValueGenerator)
	{
#if 0
		auto currentConsoleOut = Console::Out;
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (var consoleOutput = new ConsoleUtilities.ConsoleOutput())
		{
			auto consoleOutput = ConsoleUtilities::ConsoleOutput();
#endif
			Program::Play(randomValueGenerator);
#if 0
			std::wstring s = consoleOutput.GetOuput();
			Approvals::Verify(s);
		}
		Assert::Equal(currentConsoleOut, Console::Out);
#endif
	}

	std::wstring ProgramTests::GetSeedsFileName(int seed)
	{
		auto namer = Approvals::getDefaultNamer();
//		auto basename = FileSystem::combine(namer->SourcePath, namer->Name);
//		auto seedsFile = basename + L".seeds.txt";
		auto seedsFile = toWString(namer->getApprovedFile(".seeds.txt"));
		return seedsFile;
	}
}
