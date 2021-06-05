#pragma once

#include "CellGroups.h"

#include <string>
#include <vector>

class GroupsWithNMasks
{
public:
    int Mask = 0;
    std::wstring Description;
    std::vector<CellGroups> Cells;
    std::vector<CellGroups> CellsWithMask;
    int CleanableCellsCount = 0;

public:
    GroupsWithNMasks(int mask,
                     const std::wstring& description,
                     const std::vector<CellGroups>& cells
//                     const std::vector<CellGroups>& cellsWithMask,
//                     int cleanableCellsCount
                     );

    std::wstring ToString() const;
};
