#pragma once

#include "IRandomValueGenerator.h"
#include <string>
#include <deque>

namespace SudokuKata
{
	class FileReadingRandomNumber : public IRandomValueGenerator
	{
	private:
		std::deque<int> _results = std::deque<int>();

	public:
		FileReadingRandomNumber();

		int Next() override;

		int Next(int limit) override;

		void ReadValuesFromFile(const std::wstring &seedsFile);
	};
}
