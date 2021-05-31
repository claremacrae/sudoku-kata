#include "FileReadingRandomNumber.h"

namespace SudokuKata
{

	FileReadingRandomNumber::FileReadingRandomNumber()
	{
		// User must call ReadValuesFromFile() to complete the initialisation
	}

	int FileReadingRandomNumber::Next()
	{
		auto result = _results.pop_front();
		return result;
	}

	int FileReadingRandomNumber::Next(int limit)
	{
		// limit is intentionally unused
		return Next();
	}

	void FileReadingRandomNumber::ReadValuesFromFile(const std::wstring &seedsFile)
	{
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (TextReader reader = File.OpenText(seedsFile))
		{
			TextReader reader = File::OpenText(seedsFile);
			std::wstring line;
			while ((line = reader.ReadLine()) != L"")
			{
				int r = std::stoi(line);
				_results.push_back(r);
			}
		}
	}
}
