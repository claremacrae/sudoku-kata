#include "CellGroups.h"
#include <fmt/format.h>

int CellGroups::getDiscriminator() const
{
    return Discriminator;
}

std::string CellGroups::getDescription() const
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
    int discriminator, const std::string& description, int index, int row, int column)
    : Discriminator(discriminator), Description(description), Index(index), Row(row), Column(column)
{
}

std::string CellGroups::ToString() const
{
    return fmt::format("{0}: {1}, {2}: {3}, {4}: {5}, {6}: {7}, {8}: {9}",
                       "Discriminator",
                       getDiscriminator(),
                       "Description",
                       getDescription(),
                       "Index",
                       getIndex(),
                       "Row",
                       getRow(),
                       "Column",
                       getColumn());
}
