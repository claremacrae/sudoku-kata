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

namespace SudokuKata
{
	class Program
	{
	public:
		static void Play(std::wostream &console, IRandomValueGenerator *rng);

		static void Main(std::vector<std::wstring> &args);
	};
}
