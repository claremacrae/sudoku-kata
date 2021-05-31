#include "ProgramTests.h"

using namespace ApprovalTests;
using namespace SudokuKata;
using namespace ApprovalTests::Namers;
using namespace SudokuKataTests::TestHelpers;
using namespace Xunit;
using namespace Xunit::Abstractions;

namespace SudokuKataTests
{

	ProgramTests::ProgramTests(ITestOutputHelper *testOutputHelper) : _testOutputHelper(testOutputHelper)
	{
	}

	void ProgramTests::TestSeed()
	{
		auto errors = 0;
		for (int seed = 0; seed < 20; seed++)
		{
			// var randomValueGenerator = new FileWritingRandomNumber(seed);
			auto randomValueGenerator = new FileReadingRandomNumber();

			auto section = SeedSectionName(seed);

//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (var cleanup = NamerFactory.AsEnvironmentSpecificTest("" + section))
			{
				auto cleanup = NamerFactory::AsEnvironmentSpecificTest(L"" + section);
				randomValueGenerator->ReadValuesFromFile(GetSeedsFileName(seed));
			}

//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (var cleanup = NamerFactory.AsEnvironmentSpecificTest("" + section))
			{
				auto cleanup = NamerFactory::AsEnvironmentSpecificTest(L"" + section);
				try
				{
					VerifySudokuForSeed(seed, randomValueGenerator);
				}
				catch (const std::runtime_error &e)
				{
					_testOutputHelper->WriteLine(e.what());
					errors += 1;
				}
			}

			// using (var cleanup = NamerFactory.AsEnvironmentSpecificTest("" + section))
			// {
			//     var seedsFile = GetSeedsFileName(seed);
			//     randomValueGenerator.WriteValuesToFile(seedsFile);
			// }

//C# TO C++ CONVERTER TODO TASK: A 'delete randomValueGenerator' statement was not added since randomValueGenerator was passed to a method or constructor. Handle memory management manually.
		}
		Assert::Equal(0, errors);
	}

	std::wstring ProgramTests::SeedSectionName(int seed)
	{
		return std::wstring::Format(L"{0:D4}", seed);
	}

	void ProgramTests::VerifySudokuForSeed(int seed, IRandomValueGenerator *randomValueGenerator)
	{
		auto currentConsoleOut = Console::Out;
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (var consoleOutput = new ConsoleUtilities.ConsoleOutput())
		{
			auto consoleOutput = ConsoleUtilities::ConsoleOutput();
			Program::Play(randomValueGenerator);
			std::wstring s = consoleOutput.GetOuput();
			Approvals::Verify(s);
		}
		Assert::Equal(currentConsoleOut, Console::Out);
	}

	std::wstring ProgramTests::GetSeedsFileName(int seed)
	{
		auto namer = Approvals::GetDefaultNamer();
		auto basename = FileSystem::combine(namer->SourcePath, namer->Name);
		auto seedsFile = basename + L".seeds.txt";
		return seedsFile;
	}
}
