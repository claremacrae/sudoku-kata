#pragma once

#include "IRandomValueGenerator.h"

namespace SudokuKata
{
    class RandomNumber : public IRandomValueGenerator
    {
    private:
        Random* rnd;

    public:
        virtual ~RandomNumber()
        {
            delete rnd;
        }

        RandomNumber();

        RandomNumber(int seed);

        int Next() override;

        int Next(int limit) override;
    };
}
