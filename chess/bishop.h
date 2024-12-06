#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
class Bishop : public Piece
{
public:
    Bishop(Color color, const std::string &designation, int row, int column);

    bool isMoveToTheTopRightValid(int nextRow, int nextColumn, GameBoard &board);

    bool isMoveToTheTopLeftValid(int nextRow, int nextColumn, GameBoard &board);

    bool isMoveToTheButtomRightValid(int nextRow, int nextColumn, GameBoard &board);

    bool isMoveToTheButtomLeftValid(int next_row, int next_column, GameBoard board);

    bool isPossiblePath(int nextRow, int nextColumn, GameBoard &board, bool isWayClear);

    bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) override;
    bool isCheckingKing(GameBoard &board) override;
};

#endif // BISHOP_H
