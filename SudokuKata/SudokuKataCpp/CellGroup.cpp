#include "CellGroup.h"
#include <fmt/format.h>

std::string CellGroup::getDescription() const
{
    return Description;
}

int CellGroup::getIndex() const
{
    return Index;
}

int CellGroup::getRow() const
{
    return Row;
}

int CellGroup::getColumn() const
{
    return Column;
}

CellGroup::CellGroup(
    int discriminator, const std::string& description, int index, int row, int column)
    : Discriminator(discriminator), Description(description), Index(index), Row(row), Column(column)
{
}

std::string CellGroup::ToString() const
{
    return fmt::format("{0}: {1}, {2}: {3}, {4}: {5}, {6}: {7}, {8}: {9}",
                       "Discriminator",
                       Discriminator,
                       "Description",
                       getDescription(),
                       "Index",
                       getIndex(),
                       "Row",
                       getRow(),
                       "Column",
                       getColumn());
}
