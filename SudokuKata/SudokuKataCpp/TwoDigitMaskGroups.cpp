#include "TwoDigitMaskGroups.h"
#include <fmt/format.h>

TwoDigitMaskGroups::TwoDigitMaskGroups(int mask,
                                       int discriminator,
                                       const std::wstring& description,
                                       const CellGroupsMap& cells)
    : Mask(mask), Discriminator(discriminator), Description(description), Cells(cells)

{
}

std::wstring TwoDigitMaskGroups::ToString() const
{
    int result1;
    result1 = Mask;
    int result2;
    result2 = Discriminator;
    std::wstring result3;
    result3 = Description;
    auto result = fmt::format(L"{0}: {1}, {2}: {3}, {4}: {5}\n",
                              L"Mask",
                              result1,
                              L"Discriminator",
                              result2,
                              L"Description",
                              result3);
    for (auto cellGroups : Cells)
    {
        for (const auto& cell : cellGroups.second)
        {
            result += StringHelper::formatSimple(L"{0}\n", cell.ToString());
        }
    }

    return result;
}
