#include "FileReadingRandomNumber.h"

#include <fstream>
#include <cstring>

#include "Utilities/WStringHelpers.h"

namespace SudokuKata
{

	FileReadingRandomNumber::FileReadingRandomNumber()
	{
		// User must call ReadValuesFromFile() to complete the initialisation
	}

	int FileReadingRandomNumber::Next()
	{
		auto result = _results.front();
		_results.pop_front();
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
		    std::string filepath = toString(seedsFile);
		    std::ifstream ifs(filepath);

            if(!ifs)
                throw std::runtime_error(filepath + ": " + std::strerror(errno));

            while (ifs)
            {
                int r;
                ifs >> r;
				_results.push_back(r);
            }
        }
	}
}
