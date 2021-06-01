#include "Utilities/WStringHelpers.h"

#include <codecvt>
#include <locale>

std::string toString(const std::wstring &wstr)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> utf8_converter;
    return utf8_converter.to_bytes(wstr);
}

std::string toString(const wchar_t *wstr)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> utf8_converter;
    return utf8_converter.to_bytes(wstr);
}

std::wstring toWString(const std::string &str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide = converter.from_bytes(str);
    return wide;
}
