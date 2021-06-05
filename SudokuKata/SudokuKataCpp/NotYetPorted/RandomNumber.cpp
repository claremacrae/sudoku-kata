#include "RandomNumber.h"

namespace SudokuKata
{

    RandomNumber::RandomNumber()
    {
        rnd = new Random();
    }

    RandomNumber::RandomNumber(int seed)
    {
        rnd = new Random(seed);
    }

    int RandomNumber::Next()
    {
        auto next = rnd->Next();
        // Console.WriteLine(">>> Next random number: {0}.", next);
        return next;
    }

    int RandomNumber::Next(int limit)
    {
        auto next = rnd->Next(limit);
        // Console.WriteLine(">>> Next random number: {0} out of {1}.", next, limit);
        return next;
    }
}
