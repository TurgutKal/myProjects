#include "rook.h"
#include "gameboard.h"

Rook::Rook(Color color, const std::string &designation, int row, int column) : Piece(color, designation, row, column)
{}

bool Rook::isColumnMoveValid(int nextColumn, GameBoard &board) {
    if(nextColumn > column){
        for (int i = column + 1; i < nextColumn; i++) {
            if (board.isTherePiece(row, i)) {
                return false;
            }
        }
    }else if(nextColumn < column){
        for (int i = column - 1; i > nextColumn; i--) {
            if (board.isTherePiece(row, i)) {
                return false;
            }
        }
    }
    return true;
}

bool Rook::isRowMoveValid(int nextRow, GameBoard &board) {
    if(row < nextRow){
        for (int i = row + 1; i < nextRow; i++) {
            if (board.isTherePiece(i, column)) {
                return false;
            }
        }
    }else if(row > nextRow){
        for (int i = row - 1; i > nextRow; i--) {
            if (board.isTherePiece(i, column)) {
                return false;
            }
        }
    }
    return true;
}

bool Rook::isPossiblePath(int nextRow, int nextColumn, GameBoard &board, bool isWayClear) {
    return isWayClear && !board.isThereAnAllyPiece(nextRow, nextColumn, color);
}

bool Rook::isMoveValid(int nextRow, int nextColumn, GameBoard &board) {
    bool isWayClear{};

    if (row == nextRow) {
        isWayClear = isColumnMoveValid(nextColumn, board);
    }

    if (column == nextColumn && row < nextRow) {
        isWayClear = isRowMoveValid(nextRow, board);
    }

    if (isPossiblePath(nextRow, nextColumn, board, isWayClear)) {
        return true;
    }
    else {
        return false;
    }
}

bool Rook::isCheckingKing(GameBoard &board)
{
    for (int i = row + 1; i < 8; i++) {
        if(board.isTherePiece(i,column) && !board.isEnemyKing(i,column,color)){
            break;
        }
        if (board.isEnemyKing(i,column,color)) {
            return true;
        }
    }
    for (int i = column + 1; i < 8; i++) {
        if(board.isTherePiece(row,i) && !board.isEnemyKing(row,i,color)){
            break;
        }
        if (board.isEnemyKing(row,i,color)) {
            return true;
        }
    }
    for (int i = column - 1; i < 0; i--) {
        if(board.isTherePiece(row,i) && !board.isEnemyKing(row,i,color)){
            break;
        }
        if (board.isEnemyKing(row,i,color)) {
            return true;
        }
    }
    for (int i = row - 1; i < 0; i--) {
        if(board.isTherePiece(i,column) && !board.isEnemyKing(i,column,color)){
            break;
        }
        if (board.isEnemyKing(i,column,color)) {
            return true;
        }
    }
    return false;
}
