#pragma once

#include <string>

using namespace ApprovalTests;
using namespace Newtonsoft::Json;

namespace SudokuKataTests::TestHelpers
{
	class ApprovalsHelpers final
	{
	public:
		template<typename T>
		static void VerifyAsJson(T objectUnderTest, const std::wstring &description)
		{
			auto asJson = JsonConvert::SerializeObject(objectUnderTest, Formatting::Indented);
			Approvals::Verify(description + asJson);
		}
	};
}
