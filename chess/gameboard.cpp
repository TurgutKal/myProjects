#include "gameboard.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include <iostream>
#include <string>

GameBoard::GameBoard() {

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            gameboard[i][j] = nullptr;
        }
    }

}

void GameBoard::setPieces()
{
    for(int i = 0; i < row; i++)
    {
        gameboard[1][i] = new Pawn(WHITE,"wPawn",1,i);
        gameboard[6][i] = new Pawn(BLACK,"bPawn",6,i);
    }

    gameboard[0][0] = new Rook(WHITE,"wRook",0,0);
    gameboard[0][7] = new Rook(WHITE,"wRook",0,7);
    gameboard[7][0] = new Rook(BLACK,"bRook",7,0);
    gameboard[7][7] = new Rook(BLACK,"bRook",7,7);

    gameboard[0][1] = new Knight(WHITE,"wKnight",0,1);
    gameboard[0][6] = new Knight(WHITE,"wKnight",0,6);
    gameboard[7][1] = new Knight(BLACK,"bKnight",7,1);
    gameboard[7][6] = new Knight(BLACK,"bKnight",7,6);

    gameboard[0][2] = new Bishop(WHITE,"wBishop",0,2);
    gameboard[0][5] = new Bishop(WHITE,"wBishop",0,5);
    gameboard[7][2] = new Bishop(BLACK,"bBishop",7,2);
    gameboard[7][5] = new Bishop(BLACK,"bBishop",7,5);

    gameboard[0][3] = new Queen(WHITE,"wQueen",0,3);
    gameboard[0][4] = new King(WHITE,"wKing",0,4);

    gameboard[7][3] = new Queen(BLACK,"bQueen",7,3);
    gameboard[7][4] = new King(BLACK,"bKing",7,4);
}

void GameBoard::showBoard()
{
    for(int i = 0; i < row; i++){
        std::cout << i + 1 << "  ";
        for(int j = 0; j < column; j++)
        {
            std::cout.width(10);
            std::cout.setf(std::ios::left);
            if(gameboard[i][j] == nullptr){
                std::cout << "------";
            }else{
                std::cout << gameboard[i][j]->getDesignation();
            }
        }
        std::cout << std::endl;
    }
    std::cout << "     ";
    for(int i = 0; i < 8; i++){
        std::cout.width(10);
        std::cout.setf(std::ios::left);
        char output = 'a'+i;
        std::cout << output;
    }
    std::cout << std::endl;
}

void GameBoard::makeMove(int currentRow, int currentColumn, int newRow, int newColumn)
{
    if (!gameboard[currentRow][currentColumn]->isMoveValid(newRow, newColumn, *this)) {
        std::cout << "Invalid move" << std::endl;
    }
    gameboard[newRow][newColumn] = gameboard[currentRow][currentColumn];
    gameboard[currentRow][currentColumn] = nullptr;

    gameboard[newRow][newColumn]->setRow(newRow);
    gameboard[newRow][newColumn]->setColumn(newColumn);
}

bool GameBoard::isTherePiece(int row, int column) {
    return gameboard[row][column] != nullptr;
}

bool GameBoard::isThereAnEnemyPiece(int row, int column, Color color) {
    return gameboard[row][column] != nullptr && gameboard[row][column]->getColor() != color;
}

bool GameBoard::isThereAnAllyPiece(int row, int column, Color color) {
    return gameboard[row][column] != nullptr && gameboard[row][column]->getColor() == color;
}

bool GameBoard::isEnemyKing(int row, int column, Color color)
{
    if(color == WHITE){
        return gameboard[row][column]->getDesignation() == "bKing";
    }else{
        return gameboard[row][column]->getDesignation() == "wKing";
    }
}


