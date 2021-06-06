#include "FileReadingRandomNumber.h"

#include <fstream>
#include <cstring>
#include <iostream>

namespace SudokuKata
{

    FileReadingRandomNumber::FileReadingRandomNumber()
    {
        // User must call ReadValuesFromFile() to complete the initialisation
    }

    int FileReadingRandomNumber::Next()
    {
        if (_results.empty())
        {
            throw std::runtime_error("No more values left in FileReadingRandomNumber");
        }
        auto result = _results.front();
        // std::cout << ">>> Next random number: "<< result << ".\n" << std::endl;
        _results.pop_front();
        return result;
    }

    int FileReadingRandomNumber::Next(int limit)
    {
        // limit is intentionally unused
        return Next();
    }

    void FileReadingRandomNumber::ReadValuesFromFile(const std::string& seedsFile)
    {
            std::ifstream ifs(seedsFile);

            if (!ifs)
                throw std::runtime_error(seedsFile + ": " + std::strerror(errno));

            while (ifs)
            {
                int r;
                ifs >> r;
                _results.push_back(r);
            }
            // std::cout << _results.size() << " lines read from " << seedsFile << '\n';
    }
}
