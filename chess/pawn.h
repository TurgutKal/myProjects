#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn : public Piece
{
public:
    Pawn(Color color, const std::string &designation, int row, int column);

    bool isTwoStepsValid(int nextRow, int nextColumn, bool isTherePiece);

    bool isOneStepValid(int nextRow, int nextColumn, bool isTherePiece);

    bool isKillingValid(int nextRow, int nextColumn, GameBoard &board);

    bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) override;

    bool isCheckingKing(GameBoard &board) override;
private:
    bool isFirstmoveDone;

};

#endif // PAWN_H
