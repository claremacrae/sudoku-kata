#include "GroupsWithNMasks.h"

#include <fmt/format.h>

GroupsWithNMasks::GroupsWithNMasks(int mask,
                                   const std::wstring& description,
                                   const std::vector<CellGroups>& cells,
                                   const std::vector<CellGroups>& cellsWithMask,
                                   int cleanableCellsCount)
{
    Mask = mask;
    Description = description;
    Cells = cells;
    CellsWithMask = cellsWithMask;
    CleanableCellsCount = cleanableCellsCount;
}

std::wstring GroupsWithNMasks::ToString() const
{
    std::wstring result = fmt::format(L"{{ Mask = {0}, Description = {1}, Cells = {2}, "
                                      L"CellsWithMask = {3}, CleanableCellsCount = {4}",
                                      Mask,
                                      Description,
                                      Cells.size(),
                                      CellsWithMask.size(),
                                      CleanableCellsCount);
    result += L"\n   Cells:";
    for (const auto& item : Cells)
    {
        result += L"\n      ";
        result += item.ToString();
    }
    result += L"\n   CellsWithMask:";
    for (const auto& item : CellsWithMask)
    {
        result += L"\n      ";
        result += item.ToString();
    }
    result += L"\n}";
    return result;
}
