#include "gamelogic.h"

#include <iostream>

GameLogic::GameLogic() {
    board.setPieces();
    currentPlayer = WHITE;
}

bool GameLogic::isInputInvalid(int currentRow, char currentColumn, int newRow, char newColumn) {
    return newColumn < 'a' || newColumn > 'h' || currentColumn < 'a' || currentColumn > 'h' || newRow < 1 || newRow > 8
           ||
           currentRow < 1 || currentRow > 8;
}

bool GameLogic::isInputFalse(int currentRow, char currentColumn, int newRow, char newColumn,
    int currentColumnAsNumber) {
    return isInputInvalid(currentRow, currentColumn, newRow,newColumn) || board.isThereAnEnemyPiece(currentRow,currentColumnAsNumber,currentPlayer);
}

void GameLogic::userInteraction() {
    int currentRow{};
    char currentColumn{};
    int newRow{};
    char newColumn{};
    int newColumnAsNumber{};
    int currentColumnAsNumber{};
    
    board.showBoard();
    do {
        if (currentPlayer == WHITE) {
            std::cout << "White's turn:" << std::endl;
        } else {
            std::cout << "Black's turn:" << std::endl;
        }
            std::cout << "Enter the current column(a-h): ";
            std::cin >> currentColumn;
            currentColumnAsNumber = currentColumn - 'a';
            std::cout << "Enter the current row(1-8): ";
            std::cin >> currentRow;
            currentRow -= 1;
            std::cout << "Enter the new column(a-h): ";
            std::cin >> newColumn;
            newColumnAsNumber = newColumn - 'a';
            std::cout << "Enter the new row(1-8): ";
            std::cin >> newRow;
            newRow -= 1;


            if (isInputFalse(currentRow, currentColumn, newRow, newColumn, currentColumnAsNumber)) {
                std::cout << "Invalid input" << std::endl;
            }
        }while (isInputFalse(currentRow, currentColumn, newRow, newColumn, currentColumnAsNumber));


        board.makeMove(currentRow, currentColumnAsNumber, newRow, newColumnAsNumber);

        if (currentPlayer == BLACK) {
            currentPlayer = WHITE;
        }else {
            currentPlayer = BLACK;
        }

}

