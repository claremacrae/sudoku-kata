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
    auto result = fmt::format(L"{0}: {1}, {2}: {3}, {4}: {5}\n",
                              L"Mask",
                              Mask,
                              L"Discriminator",
                              Discriminator,
                              L"Description",
                              Description);
    for (auto cellGroups : Cells)
    {
        for (const auto& cell : cellGroups.second)
        {
            result += StringHelper::formatSimple(L"{0}\n", cell.ToString());
        }
    }

    return result;
}
