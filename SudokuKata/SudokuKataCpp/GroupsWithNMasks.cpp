#include "GroupsWithNMasks.h"

#include <fmt/format.h>

GroupsWithNMasks::GroupsWithNMasks(int mask,
                                   const std::wstring& description
//                                   const std::map<int, CellGroups>& cells
//                                   const std::vector<CellGroups>& cellsWithMask,
//                                   int cleanableCellsCount
                                   )
{
    Mask = mask;
    Description = description;
//    Cells = cells;
//    CellsWithMask = cellsWithMask;
//    CleanableCellsCount = cleanableCellsCount;
}

std::wstring GroupsWithNMasks::ToString() const
{
    std::wstring result = fmt::format(
        L"{{ Mask = {0}, Description = {1}, Cells = {2}, "
        L"CellsWithMask = {3}, CleanableCellsCount = {4} }}",
        Mask,
        Description,
        Cells.size(),
        CellsWithMask.size(),
        CleanableCellsCount
        );
    return result;
}
