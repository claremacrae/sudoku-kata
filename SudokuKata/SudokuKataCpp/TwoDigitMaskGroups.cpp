#include "TwoDigitMaskGroups.h"
#include <fmt/format.h>
#include <cassert>

TwoDigitMaskGroups::TwoDigitMaskGroups(int mask,
                                       int discriminator,
                                       const std::wstring& description,
                                       const std::vector<CellGroups>& cells)
    : Mask(mask), Discriminator(discriminator), Description(description), Cells(cells)
{
    assert(cells.size() == 9);
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
    for (const auto& cell : Cells)
    {
        result += fmt::format(L"   {0}\n", cell.ToString());
    }
    return result;
}
