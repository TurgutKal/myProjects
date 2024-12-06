#include "piece.h"

std::string Piece::getDesignation() const
{
    return designation;
}

Color Piece::getColor() const
{
    return color;
}

void Piece::setRow(int newRow) {
    row = newRow;
}

void Piece::setColumn(int newColumn) {
    column = newColumn;
}

Piece::Piece(Color color, const std::string &designation, int row, int column) : color(color),
                                                                                 designation(designation),
                                                                                 row(row),
                                                                                 column(column)
{}
