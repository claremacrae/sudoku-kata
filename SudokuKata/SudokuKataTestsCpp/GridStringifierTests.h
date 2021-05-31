#pragma once

#include <vector>

using namespace ApprovalTests;
using namespace SudokuKata;
using namespace SudokuKata::Utilities;
using namespace Xunit;

namespace SudokuKataTests
{
	class GridStringifierTests
	{
	public:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Fact] public void TestPopulatedBoard()
		void TestPopulatedBoard();

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Fact] public void TestPopulatedBoardAsCode()
		void TestPopulatedBoardAsCode();

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Fact] public void TestPartialBoard()
		void TestPartialBoard();

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Fact] public void TestPartialBoardAsCode()
		void TestPartialBoardAsCode();

	private:
		static void VerifyBoardAsString(std::vector<int> &input);

		static void VerifyBoardAsCode(std::vector<int> &input);
	};
}
