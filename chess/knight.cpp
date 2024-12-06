#include "knight.h"
#include "gameboard.h"
Knight::Knight(Color color, const std::string &designation, int row, int column) : Piece(color, designation, row, column)
{}

bool Knight::isMoveToTheTopValid(int nextRow, int nextColumn, bool isThereAnAllyPiece) {
    return nextRow == row + 2 && (nextColumn == column + 1 || nextColumn == column - 1) && !isThereAnAllyPiece; ;
}

bool Knight::isMoveToTheButtomValid(int nextRow, int nextColumn, bool isThereAnAllyPiece) {
    return nextRow == row - 2 && (nextColumn == column + 1 || nextColumn == column - 1) && !isThereAnAllyPiece;
}

bool Knight::isMoveToTheRightValid(int nextRow, int nextColumn, bool isThereAnAllyPiece) {
    return column == nextColumn + 2 && (row == nextRow + 1 || row == nextRow - 1) && !isThereAnAllyPiece;
}

bool Knight::isMoveToTheLeftValid(int nextRow, int nextColumn, bool isThereAnAllyPiece) {
    return column == nextColumn - 2 && (row == nextRow + 1 || row == nextRow - 1) && !isThereAnAllyPiece;
}

bool Knight::isMoveValid(int nextRow, int nextColumn, GameBoard &board) {
    bool isThereAnAllyPiece = board.isThereAnAllyPiece(nextRow, nextColumn, color);
    if (isMoveToTheTopValid(nextRow, nextColumn, isThereAnAllyPiece)) {
        return true;
    }
    if (isMoveToTheButtomValid(nextRow, nextColumn, isThereAnAllyPiece)) {
        return true;
    }
    if (isMoveToTheRightValid(nextRow, nextColumn, isThereAnAllyPiece)) {
        return true;
    }
    if (isMoveToTheLeftValid(nextRow, nextColumn, isThereAnAllyPiece)) {
        return true;
    }
    return false;

}

bool Knight::isCheckingKing(GameBoard &board)
{

}
