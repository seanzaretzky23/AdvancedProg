/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "StandardLogic.h"

StandardLogic::StandardLogic(Board *board): GameLogic(board) {}

vector<BoardCell> StandardLogic::possibleMovesForColor(SquareColor color) const {
    vector<BoardCell> possibleMoves;

    if (color == Blank) {
        throw invalid_argument("only Black and White are valid inputs");
    }

    for (int i = 0; i < this->gameBoard->getBoardLength(); i++) {
        for (int j = 0; j < this->gameBoard->getBoardWidth(); j++) {
            BoardCell tmp(i, j);
            if ((this->gameBoard->getColorOfBoardCell(i, j) == Blank) &&
                    (!boardCellsCreatingScoreLines(tmp, color).empty())) {
                possibleMoves.push_back(tmp);
            }
        }
    }

    return possibleMoves;
}

vector<BoardCell> StandardLogic::boardCellsCreatingScoreLines(const BoardCell &boardCell, const SquareColor &color) const {

    vector<BoardCell> boardCells;

    //boolean array of size 8 representing if we want to continue the search in each one
    //of the 8 directions from the received boardCell
    // (starting from 0 for bottom right corner and moving counter clockwise)
    vector<bool> contSearch;

    //board dimensions
    int boardLength = this->gameBoard->getBoardLength();
    int boardWidth = this->gameBoard->getBoardWidth();

    //the co'ordinates of the boardCell
    int xCor, yCor;
    xCor = boardCell.getXCor();
    yCor = boardCell.getYCor();

    initializeBoolVectorForBCCSLmethod(contSearch, boardCell, color);

    int mainLoopSize = max (max (xCor + 1, yCor + 1), max (boardLength - xCor, boardWidth - yCor));

    //the main loop of this method
    for (int i = 2; i < mainLoopSize; i++) {
        //checking each of the 8 directions around the boardCell
        this->helperMethodForBCCSL(contSearch, 0, boardCells, 1, 1, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 1, boardCells, 1, 0, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 2, boardCells, 1, -1, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 3, boardCells, 0, -1, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 4, boardCells, -1, -1, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 5, boardCells, -1, 0, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 6, boardCells, -1, 1, xCor, yCor, i, color);
        this->helperMethodForBCCSL(contSearch, 7, boardCells, 0, 1, xCor, yCor, i, color);

    }
    return boardCells;
}

void StandardLogic::helperMethodForBCCSL(vector<bool> &contSearch, int index, vector<BoardCell> &boardCells,
                                         int xCoefficient, int yCoefficient, int &xCor, int &yCor, int &i,
                                         SquareColor color) const {
    if (contSearch[index] && this->gameBoard->validBoardCell(xCor + (xCoefficient * i), yCor + (yCoefficient * i))) {
        if (this->gameBoard->getColorOfBoardCell(xCor + (xCoefficient * i), yCor + (yCoefficient * i)) == color) {
            boardCells.push_back(BoardCell(xCor + (xCoefficient * i), yCor + (yCoefficient * i)));
            contSearch[index] = false;
        } else {
            if (this->gameBoard->getColorOfBoardCell(xCor + (xCoefficient * i), yCor + (yCoefficient * i)) == Blank) {
                contSearch[index] = false;
            }
        }
    }
}

void StandardLogic::initializeBoolVectorForBCCSLmethod(vector<bool> &vec, const BoardCell &boardCell,
                                                       const SquareColor &color) const {
    SquareColor oppositeColor;
    if (color == White) {
        oppositeColor = Black;
    } else {
        oppositeColor = White;
    }

    //the co'ordinates of the boardCell
    int xCor, yCor;
    xCor = boardCell.getXCor();
    yCor = boardCell.getYCor();


    for (int i = 0; i < 8; i++) {
        vec.push_back(false);
    }

    vec[0] = (this->gameBoard->validBoardCell(xCor + 1, yCor + 1) &&
              this->gameBoard->getColorOfBoardCell(xCor + 1, yCor + 1) == oppositeColor);

    vec[1] = (this->gameBoard->validBoardCell(xCor + 1, yCor) &&
              this->gameBoard->getColorOfBoardCell(xCor + 1, yCor) == oppositeColor);

    vec[2] = (this->gameBoard->validBoardCell(xCor + 1, yCor - 1) &&
              this->gameBoard->getColorOfBoardCell(xCor + 1, yCor - 1) == oppositeColor);

    vec[3] = (this->gameBoard->validBoardCell(xCor, yCor - 1) &&
              this->gameBoard->getColorOfBoardCell(xCor, yCor - 1) == oppositeColor);

    vec[4] = (this->gameBoard->validBoardCell(xCor - 1, yCor - 1) &&
              this->gameBoard->getColorOfBoardCell(xCor - 1, yCor - 1) == oppositeColor);

    vec[5] = (this->gameBoard->validBoardCell(xCor - 1, yCor) &&
              this->gameBoard->getColorOfBoardCell(xCor - 1, yCor) == oppositeColor);

    vec[6] = (this->gameBoard->validBoardCell(xCor - 1, yCor + 1) &&
              this->gameBoard->getColorOfBoardCell(xCor - 1, yCor + 1) == oppositeColor);

    vec[7] = (this->gameBoard->validBoardCell(xCor, yCor + 1) &&
              this->gameBoard->getColorOfBoardCell(xCor, yCor + 1) == oppositeColor);
}

bool StandardLogic::makeMove(const BoardCell &boardCell, SquareColor color) {
    vector<BoardCell> options = possibleMovesForColor(color);

    //variable containing if the received boardCell is one of the boardCells in options vector
    bool ok = false;
    for (int i = 0; (i < options.size()) && !ok; i++) {
        if (boardCell == options[i]) {
            ok = true;
        }
    }

    if (ok) {
        this->gameBoard->setColorOfRequestedCell(boardCell, color);
        //flipping boardCells of the opposite color that need to be flipped after current move
        vector<BoardCell>  cellsUntilWhichToFlip = this->boardCellsCreatingScoreLines(boardCell, color);
        for (int i = 0; i < cellsUntilWhichToFlip.size(); i++) {
            this->turnAllPawnsBetweenTheCells(boardCell, cellsUntilWhichToFlip[i]);
        }

        if (color == White) {
            return true; //Black
        } else {
            return false; //White
        }
    } else {
        throw invalid_argument("this boardCell isn't one of the options for a valid move");
    }
}

int StandardLogic::whoHasMorePoints() const {
    int whiteCounter, blackCounter;
    whiteCounter = this->numberOfPointsOfColor(White);
    blackCounter = this->numberOfPointsOfColor(Black);

    if (whiteCounter > blackCounter) {
        return 2;
    } else {
        if (blackCounter > whiteCounter) {
            return 1;
        } else {
            return 3;
        }
    }
}

int StandardLogic::numberOfPointsOfColor(SquareColor color) const {
    if (color == Blank) {
        throw invalid_argument("received color can only be of value representing player (Black or White)");
    } else {
        return this->gameBoard->numberOfBoardCellsFilledWithColor(color);
    }
}

GameLogic* StandardLogic::getThisTypeOfGameLogicWithReceivedBoard(Board *board) const {
    return new StandardLogic(board);
}


