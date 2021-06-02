﻿#pragma once

#include "IRandomValueGenerator.h"
#include "RandomNumber.h"
#include <string>
#include <vector>

namespace SudokuKata
{
    class FileWritingRandomNumber : public IRandomValueGenerator
    {
    private:
        RandomNumber* rnd;
        std::vector<int> _results = std::vector<int>();

    public:
        virtual ~FileWritingRandomNumber()
        {
            delete rnd;
        }

        FileWritingRandomNumber(int seed);

        int Next() override;

        int Next(int limit) override;

        void WriteValuesToFile(const std::wstring& seedsFile);

    private:
        int LogNumber(int next);
    };
}
