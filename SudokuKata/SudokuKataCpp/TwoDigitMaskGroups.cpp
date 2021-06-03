#include "TwoDigitMaskGroups.h"
#include <fmt/format.h>

int TwoDigitMaskGroups::getMask() const
{
    return Mask;
}

int TwoDigitMaskGroups::getDiscriminator() const
{
    return Discriminator;
}

std::wstring TwoDigitMaskGroups::getDescription() const
{
    return Description;
}

const CellGroupsMap& TwoDigitMaskGroups::getCells() const
{
    return Cells;
}

TwoDigitMaskGroups::TwoDigitMaskGroups(int mask,
                                       int discriminator,
                                       const std::wstring& description,
                                       const CellGroupsMap& cells)
{
    Mask = mask;
    Discriminator = discriminator;
    Description = description;
    Cells = cells;
}

std::wstring TwoDigitMaskGroups::ToString() const
{
    auto result = fmt::format(L"{0}: {1}, {2}: {3}, {4}: {5}\n",
                              L"Mask",
                              getMask(),
                              L"Discriminator",
                              getDiscriminator(),
                              L"Description",
                              getDescription());
    for (auto cellGroups : getCells())
    {
        for (const auto& cell : cellGroups.second)
        {
            result += StringHelper::formatSimple(L"{0}\n", cell.ToString());
        }
    }

    return result;
}
