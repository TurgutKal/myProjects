#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
class Knight: public Piece
{
public:
    Knight(Color color, const std::string &designation, int row, int column);

    bool isMoveToTheTopValid(int nextRow, int nextColumn, bool isThereAnAllyPiece);

    bool isMoveToTheButtomValid(int nextRow, int nextColumn, bool isThereAnAllyPiece);

    bool isMoveToTheRightValid(int nextRow, int nextColumn, bool isThereAnAllyPiece);

    bool isMoveToTheLeftValid(int nextRow, int nextColumn, bool isThereAnAllyPiece);

    bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) override;

    bool isCheckingKing(GameBoard &board) override;

};

#endif // KNIGHT_H
