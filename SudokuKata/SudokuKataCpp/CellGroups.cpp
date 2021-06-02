#include "CellGroups.h"
#include <fmt/format.h>

int CellGroups::getDiscriminator() const
{
    return Discriminator;
}

std::wstring CellGroups::getDescription() const
{
    return Description;
}

int CellGroups::getIndex() const
{
    return Index;
}

int CellGroups::getRow() const
{
    return Row;
}

int CellGroups::getColumn() const
{
    return Column;
}

CellGroups::CellGroups(
    int discriminator, const std::wstring& description, int index, int row, int column)
{
    Discriminator = discriminator;
    Description = description;
    Index = index;
    Row = row;
    Column = column;
}

std::wstring CellGroups::ToString()
{
    return fmt::format(L"{0}: {1}, {2}: {3}, {4}: {5}, {6}: {7}, {8}: {9}",
                       L"Discriminator",
                       getDiscriminator(),
                       L"Description",
                       getDescription(),
                       L"Index",
                       getIndex(),
                       L"Row",
                       getRow(),
                       L"Column",
                       getColumn());
}
