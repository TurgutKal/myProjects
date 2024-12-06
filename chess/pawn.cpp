#include "pawn.h"
#include "gameboard.h"

Pawn::Pawn(Color color, const std::string &designation, int row, int column) : Piece(color, designation, row, column) {
    if (row == 1 || row == 6) {
        isFirstmoveDone = false;
    }else
    isFirstmoveDone = true;
}

bool Pawn::isTwoStepsValid(int nextRow, int nextColumn, bool isTherePiece) {
    if (color == BLACK) {
        return nextRow == row - 2 && nextColumn == column && !isTherePiece && !isFirstmoveDone;
    }else
    return nextRow == row + 2 && nextColumn == column && !isTherePiece && !isFirstmoveDone;
}

bool Pawn::isOneStepValid(int nextRow, int nextColumn, bool isTherePiece) {
    if (color == BLACK) {
        return nextRow == row - 1 && nextColumn == column && !isTherePiece;
    }else
    return nextRow == row + 1 && nextColumn == column && !isTherePiece;
}

bool Pawn::isKillingValid(int nextRow, int nextColumn, GameBoard &board) {
    if (color == BLACK) {
        return nextRow == row - 1 && (nextColumn == column + 1 || nextColumn == column - 1) && board.isThereAnEnemyPiece(
               nextRow, nextColumn, color);
    }else
    return nextRow == row + 1 && (nextColumn == column + 1 || nextColumn == column - 1) && board.isThereAnEnemyPiece(
               nextRow, nextColumn, color);
}

bool Pawn::isMoveValid(int nextRow, int nextColumn, GameBoard &board)
{
    bool isTherePiece = board.isTherePiece(nextRow, nextColumn);

        if(isOneStepValid(nextRow, nextColumn, isTherePiece)){
            return true;
        }
        if (isTwoStepsValid(nextRow, nextColumn, isTherePiece)){
            isFirstmoveDone = true;
            return true;
        }
        if (isKillingValid(nextRow, nextColumn, board)){
            return true;
        }
        return false;
}

bool Pawn::isCheckingKing(GameBoard &board)
{

}
