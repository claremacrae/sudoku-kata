#include "Utilities/WStringHelpers.h"

#include <codecvt>
#include <locale>

std::string toString(const std::string& wstr)
{
    return wstr;
}

std::string toString(const char* wstr)
{
    return std::string(wstr);
}

std::string toWString(const std::string& str)
{
    return str;
}
