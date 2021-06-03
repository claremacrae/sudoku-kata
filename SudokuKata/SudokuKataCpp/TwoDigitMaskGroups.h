#pragma once

#include <string>
#include "stringhelper.h"
#include "CellGroups.h"

#include <map>

class TwoDigitMaskGroups
{
private:
    int Mask = 0;
    int Discriminator = 0;
    std::wstring Description;
    CellGroupsMap Cells;

public:
    int getMask() const;
    int getDiscriminator() const;
    std::wstring getDescription() const;
    const CellGroupsMap& getCells() const;

    TwoDigitMaskGroups(int mask,
                       int discriminator,
                       const std::wstring& description,
                       const CellGroupsMap& cells);

    std::wstring ToString() const;
};
