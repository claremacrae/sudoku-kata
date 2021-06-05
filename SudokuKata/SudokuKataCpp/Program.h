﻿#pragma once

#include "Utilities/IRandomValueGenerator.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <iostream>

namespace SudokuKata
{
    class Program
    {
    public:
        static void Play(std::wostream& console, IRandomValueGenerator* rng);

        static void Main(std::vector<std::wstring>& args);
    };
}
