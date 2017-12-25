/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "GameLogic.h"


GameLogic::GameLogic(Board *board): gameBoard(board) {}

void GameLogic::turnAllPawnsBetweenTheCells(const BoardCell &boardCell1, const BoardCell &boardCell2) {
    int xCor1, yCor1, xCor2, yCor2;
    xCor1 = boardCell1.getXCor();
    yCor1 = boardCell1.getYCor();
    xCor2 = boardCell2.getXCor();
    yCor2 = boardCell2.getYCor();

    //finding how the boardCells are placed one relatively to the other and calling to helper methods
    if (xCor1 == xCor2) {
        if (yCor1 > yCor2) {
            turnAllPawnsBetweenSameColCells(boardCell1, boardCell2);
        } else {
            turnAllPawnsBetweenSameColCells(boardCell2, boardCell1);
        }
    } else {
        if (yCor1 == yCor2) {
            if (xCor1 < xCor2) {
                turnAllPawnsBetweenSameRowCells(boardCell1, boardCell2);
            } else {
                turnAllPawnsBetweenSameRowCells(boardCell2, boardCell1);
            }
        } else {
            turnAllPawnsBetweenSameDiagCells(boardCell1, boardCell2);
        }
    }

}

void GameLogic::turnAllPawnsBetweenSameRowCells(const BoardCell &boardCell1, const BoardCell &boardCell2) {
    SquareColor color = this->gameBoard->getColorOfBoardCell(boardCell1);

    //starting co'ordinates are of boardCell1
    int xCor, yCor;
    xCor = boardCell1.getXCor();
    yCor = boardCell1.getYCor();

    //finish x co'ordinate
    int xCorF = boardCell2.getXCor();

    for (int i = 1; xCor + i < xCorF; i++) {
        BoardCell boardCellTmp(xCor + i, yCor);
        this->gameBoard->setColorOfRequestedCell(boardCellTmp, color);
    }
}

void GameLogic::turnAllPawnsBetweenSameColCells(const BoardCell &boardCell1, const BoardCell &boardCell2) {
    SquareColor color = this->gameBoard->getColorOfBoardCell(boardCell1);

    //starting co'ordinates are of boardCell1
    int xCor, yCor;
    xCor = boardCell1.getXCor();
    yCor = boardCell1.getYCor();

    //finish y co'ordinate
    int yCorF = boardCell2.getYCor();

    for (int i = 1; yCor - i > yCorF; i++) {
        BoardCell boardCellTmp(xCor, yCor - i);
        this->gameBoard->setColorOfRequestedCell(boardCellTmp, color);
    }
}

void GameLogic::turnAllPawnsBetweenSameDiagCells(const BoardCell &boardCell1, const BoardCell &boardCell2) {

    SquareColor color = this->gameBoard->getColorOfBoardCell(boardCell1);

    int xCor1, yCor1, xCor2, yCor2;
    xCor1 = boardCell1.getXCor();
    yCor1 = boardCell1.getYCor();
    xCor2 = boardCell2.getXCor();
    yCor2 = boardCell2.getYCor();

    if (xCor1 < xCor2) {
        if (yCor1 < yCor2) {
            for (int i = 1; xCor1 + i < xCor2 ; i++) {
                BoardCell boardCellTmp(xCor1 + i, yCor1 + i);
                this->gameBoard->setColorOfRequestedCell(boardCellTmp, color);
            }
        } else {
            //yCor1 > yCor2
            for (int i = 1; xCor1 + i < xCor2 ; i++) {
                BoardCell boardCellTmp(xCor1 + i, yCor1 - i);
                this->gameBoard->setColorOfRequestedCell(boardCellTmp, color);
            }
        }
    } else {
        turnAllPawnsBetweenSameDiagCells(boardCell2, boardCell1);
    }
}

Board* GameLogic::getGameBoardCopy() const {
    return this->gameBoard->getCopyOfTheBoard();
}

void GameLogic::setGameBoard(Board *board) {
    this->gameBoard = board;
}