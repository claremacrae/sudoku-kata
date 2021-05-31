#pragma once

#include "Utilities/IRandomValueGenerator.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <iostream>
#include "rectangularvectors.h"
#include "stringhelper.h"
#include "stringbuilder.h"

using namespace SudokuKata::Utilities;

namespace SudokuKata
{
	class Program
	{
	public:
		static void Play(IRandomValueGenerator *rng);

		static void Main(std::vector<std::wstring> &args);
	};
}
