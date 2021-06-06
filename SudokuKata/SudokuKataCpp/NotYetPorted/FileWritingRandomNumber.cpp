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

    void FileWritingRandomNumber::WriteValuesToFile(const std::string& seedsFile)
    {
        TextWriter tw = StreamWriter(seedsFile);
        for (auto s : _results)
        {
            tw.WriteLine(s);
        }
    }

    int FileWritingRandomNumber::LogNumber(int next)
    {
        _results.push_back(next);
        return next;
    }
}
