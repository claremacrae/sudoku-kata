#include "GroupsWithNMasks.h"

#include <fmt/format.h>

GroupsWithNMasks::GroupsWithNMasks(int mask,
                                   const std::wstring& description,
                                   const std::vector<CellGroups>& cells,
                                   const std::vector<CellGroups>& cellsWithMask,
                                   int cleanableCellsCount
                                   )
{
    Mask = mask;
    Description = description;
    Cells = cells;
    CellsWithMask = cellsWithMask;
    CleanableCellsCount = cleanableCellsCount;
}

std::wstring GroupsWithNMasks::ToString() const
{
    std::wstring result = fmt::format(
        L"{{ Mask = {0}, Description = {1}, Cells = {2}, "
        L"CellsWithMask = {3}, CleanableCellsCount = {4}",
        Mask,
        Description,
        Cells.size(),
        CellsWithMask.size(),
        CleanableCellsCount
        );
    result += L"\n   Cells:";
    //                                     std::wstring valuesReport = fmt::format(L"{}", fmt::join(valuesToRemove, L", "));

//    result += string.Join("\n      ", Cells);
//    result += fmt::format(L"{}", fmt::join(Cells, L"\n      "));
    for (const auto& item : Cells)
    {
        result += L"\n      ";
        result += item.ToString();
    }
    result += L"\n   CellsWithMask:";
//    result += fmt::format(L"{}", fmt::join(CellsWithMask, L"\n      "));
    for (const auto& item : CellsWithMask)
    {
        result += L"\n      ";
        result += item.ToString();
    }

    //    result += string.Join("\n      ", CellsWithMask);
    result += L"\n}";
    return result;
}
