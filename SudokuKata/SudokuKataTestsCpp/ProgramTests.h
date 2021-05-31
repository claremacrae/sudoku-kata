#pragma once

#include <string>
#include <stdexcept>
#include "tangible_filesystem.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace SudokuKata { class IRandomValueGenerator; }

using namespace ApprovalTests;
using namespace SudokuKata;
using namespace ApprovalTests::Namers;
using namespace SudokuKataTests::TestHelpers;
using namespace Xunit;
using namespace Xunit::Abstractions;

namespace SudokuKataTests
{
	//  ^^^ Prevent running in parallel with other tests that write to console
	//  This test works by capturing any output to standard output.
	//  It must not run in parallel with any other tests that also write to standard output.
	//  Any other tests that also capture console output should also be put in the same Collection.
	//  See https://stackoverflow.com/a/47174842/104370
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Collection("Sequential")] public class ProgramTests
	class ProgramTests
	{
	private:
		ITestOutputHelper *const _testOutputHelper;

	public:
		virtual ~ProgramTests()
		{
			delete _testOutputHelper;
		}

		ProgramTests(ITestOutputHelper *testOutputHelper);

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Fact] public void TestSeed()
		void TestSeed();

	private:
		static std::wstring SeedSectionName(int seed);

		static void VerifySudokuForSeed(int seed, IRandomValueGenerator *randomValueGenerator);

		static std::wstring GetSeedsFileName(int seed);
	};
}
