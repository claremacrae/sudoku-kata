#include "ProgramTests.h"

#include "catch2/catch.hpp"
#include "ApprovalTests.hpp"

#include "Program.h"
#include "Utilities/FileReadingRandomNumber.h"
#include "Utilities/WStringHelpers.h"
#include "stringhelper.h"

using namespace ApprovalTests;
using namespace SudokuKata;

namespace SudokuKataTests
{

	TEST_CASE("TestSeed")
	{
		auto errors = 0;
		for (int seed = 0; seed < 20; seed++)
		{
		    std::wstringstream output;

			// var randomValueGenerator = new FileWritingRandomNumber(seed);
			auto randomValueGenerator = new FileReadingRandomNumber();

			std::wstring section = ProgramTests::SeedSectionName(seed);
            const std::string string = toString(section);
            auto sectionDisposer = NamerFactory::appendToOutputFilename(string);

			{
			    std::cout << "=============================================================" << std::endl;
				randomValueGenerator->ReadValuesFromFile(ProgramTests::GetSeedsFileName(seed));
			}

			{
				try
				{
                    ProgramTests::VerifySudokuForSeed(output, seed, randomValueGenerator);
				}
				catch (const std::exception &e)
				{
				    output << "ERROR: " << e.what() << std::endl;
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
		s << std::setfill ( L'0' ) << std::setw (4) << seed;
        return s.str();
    }

	void ProgramTests::VerifySudokuForSeed(std::wstringstream &console,
                                           int seed,
                                           SudokuKata::IRandomValueGenerator *randomValueGenerator)
	{
		{
			Program::Play(randomValueGenerator);
			std::wstring s = console.str();
			Approvals::verify(toString(s));
		}
	}

	std::wstring ProgramTests::GetSeedsFileName(int seed)
	{
		auto namer = Approvals::getDefaultNamer();
//		auto basename = FileSystem::combine(namer->SourcePath, namer->Name);
//		auto seedsFile = basename + L".seeds.txt";
		auto seedsFile = toWString(namer->getApprovedFile(".seeds.txt"));
		return StringHelper::replace(seedsFile, L".approved", L"");
	}
}
