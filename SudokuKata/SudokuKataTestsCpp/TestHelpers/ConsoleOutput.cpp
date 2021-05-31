#include "ConsoleOutput.h"

namespace SudokuKataTests::TestHelpers
{

	ConsoleUtilities::ConsoleOutput::ConsoleOutput()
	{
		stringWriter = new StringWriter();
		originalOutput = Console::Out;
		Console::SetOut(stringWriter);
	}

	std::wstring ConsoleUtilities::ConsoleOutput::GetOuput()
	{
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
		return stringWriter->ToString();
	}

	void ConsoleUtilities::ConsoleOutput::Dispose()
	{
		delete originalOutput;
		Console::SetOut(originalOutput);
		stringWriter->Dispose();
	}
}
