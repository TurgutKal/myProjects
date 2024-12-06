#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
class Queen : public Piece
{
public:
    Queen(Color color, const std::string &designation, int row, int column);

    bool isColumnMoveValid(int nextColumn, GameBoard &board, bool &value);

    bool isRowMoveValid(int nextRow, GameBoard &board);

    bool isPossiblePath(int nextRow, int nextColumn, GameBoard &board, bool isWayClear);

    bool isMoveToTheTopRightValid(int next_row, int next_column, GameBoard board);

    bool isMoveToTheTopLeftValid(int next_row, int next_column, GameBoard board);

    bool isMoveToTheButtomRightValid(int next_row, int next_column, GameBoard board);

    bool isMoveToTheButtomLeftValid(int next_row, int next_column, GameBoard board);

    bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) override;

    bool isCheckingKing(GameBoard &board) override;

};

#endif // QUEEN_H
