#include "catch2/catch.hpp"

#include "Utilities/WStringHelpers.h"

TEST_CASE("wstring to string")
{
    std::string ws = "0000";
    std::string s = toString(ws);
    CHECK(s == "0000");
}

TEST_CASE("string to wstring")
{
    std::string s = "0000";
    std::string ws = toWString(s);
    CHECK(ws == "0000");
}
