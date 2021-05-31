#pragma once

namespace SudokuKata
{
	class IRandomValueGenerator
	{
	public:
		virtual int Next() = 0;
		virtual int Next(int limit) = 0;
	};
}
