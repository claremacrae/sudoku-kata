#include "FileWritingRandomNumber.h"

namespace SudokuKata
{

    FileWritingRandomNumber::FileWritingRandomNumber(int seed)
    {
        rnd = new RandomNumber(seed);
    }

    int FileWritingRandomNumber::Next()
    {
        return LogNumber(rnd->Next());
    }

    int FileWritingRandomNumber::Next(int limit)
    {
        return LogNumber(rnd->Next(limit));
    }

    void FileWritingRandomNumber::WriteValuesToFile(const std::wstring& seedsFile)
    {
        //C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
        //ORIGINAL LINE: using(TextWriter tw = new StreamWriter(seedsFile))
        {
            TextWriter tw = StreamWriter(seedsFile);
            for (auto s : _results)
            {
                tw.WriteLine(s);
            }
        }
    }

    int FileWritingRandomNumber::LogNumber(int next)
    {
        _results.push_back(next);
        return next;
    }
}
