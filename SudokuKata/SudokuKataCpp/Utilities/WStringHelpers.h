#pragma once

#include <codecvt>
#include <locale>

std::string toString(const std::wstring &wstr);

std::string toString(const wchar_t *wstr);

std::wstring toWString(const std::string &str);
