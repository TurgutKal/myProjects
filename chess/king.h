#ifndef KING_H
#define KING_H

#include "piece.h"
class King : public Piece
{
public:
    King(Color color, const std::string &designation, int row, int column);

    bool isPossibleToMove(int nextRow, int nextColumn, bool isTherePiece, int i, int j);
    bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) override;
    bool isCheckingKing(GameBoard &board) override;
private:
    bool isCheck;

};

#endif // KING_H
