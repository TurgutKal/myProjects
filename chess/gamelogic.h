#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gameboard.h"
#include "piece.h"
class GameLogic
{
public:
    GameLogic();

    bool isInputInvalid(int currentRow, char currentColumn, int newRow, char newColumn);

    bool isInputFalse(int currentRow, char currentColumn, int newRow, char newColumn, int currentColumnAsNumber);

    void makeMove(int currentRow, int currentColumn, int newRow, int newColumn);
    void userInteraction();
private:
    GameBoard board;
    Color currentPlayer;
};

#endif // GAMELOGIC_H
