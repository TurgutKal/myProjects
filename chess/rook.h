#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
class Rook : public Piece
{
public:
    Rook(Color color, const std::string &designation, int row, int column);

    bool isColumnMoveValid(int nextColumn, GameBoard &board);

    bool isRowMoveValid(int nextRow, GameBoard &board);

    bool isPossiblePath(int nextRow, int nextColumn, GameBoard &board, bool isWayClear);

    bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) override;

    bool isCheckingKing(GameBoard &board) override;

};

#endif // ROOK_H
