#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "piece.h"
#include <array>

enum Color;

class GameBoard
{
public:
    GameBoard();
    void setPieces();
    void showBoard();
    void makeMove(int currentRow, int currentColumn, int newRow, int newColumn);
    bool isTherePiece(int row, int column);
    bool isThereAnEnemyPiece(int row, int column, Color color);
    bool isThereAnAllyPiece(int row, int column, Color color);
    bool isEnemyKing(int row, int column, Color color);
    bool isKingCheck();
private:
    const int row = 8;
    const int column = 8;
    std::array<std::array<Piece*,8>,8>gameboard;

};

#endif // GAMEBOARD_H
