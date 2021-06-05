#pragma once

#include <string>
#include "CellGroups.h"

#include <vector>

class TwoDigitMaskGroups
{
public:
    const int Mask = 0;
    const int Discriminator = 0;
    const std::wstring Description;
    const std::vector<CellGroups> Cells;

public:
    TwoDigitMaskGroups(int mask,
                       int discriminator,
                       const std::wstring& description,
                       const std::vector<CellGroups>& cells);

    std::wstring ToString() const;
};
