/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#include <stdexcept>
#include "Board.h"


Board::Board(int length, int width):
        boardLength(length), boardWidth(width) {


    //checking for valid board, if valid initialize
    if (boardLength >= 2 && (boardLength % 2) == 0 && boardWidth >= 2 && (boardWidth % 2) == 0) {
        this->initializeBoard();
    } else {
        throw invalid_argument("board length and width should be greater than 2 and ");
    }
}

Board::Board(const Board &existingBoard):
        boardLength(existingBoard.getBoardLength()), boardWidth(existingBoard.getBoardWidth()) {
    for (int i = 0; i < this->boardLength; i++) {
        vector<SquareColor > row;
        for (int j = 0; j < this->boardWidth; j++) {
            row.push_back(existingBoard.getColorOfBoardCell(i, j));
        }
        this->gameBoard.push_back(row);
    }
}

void Board::initializeBoard() {
    for (int i = 0; i < this->boardLength; i++) {
        vector<SquareColor > row;
        for (int j = 0; j < this->boardWidth; j++) {
            row.push_back(Blank);
        }
        this->gameBoard.push_back(row);
    }

    //creating the middle square
    int topLeftRow, topLeftColumn;
    topLeftRow = (boardLength / 2) - 1;
    topLeftColumn = (boardWidth / 2) - 1;
    gameBoard[topLeftRow][topLeftColumn] = White;
    gameBoard[topLeftRow + 1][topLeftColumn] = Black;
    gameBoard[topLeftRow][topLeftColumn + 1] = Black;
    gameBoard[topLeftRow + 1][topLeftColumn + 1] = White;

}

SquareColor Board::getColorOfBoardCell(const BoardCell &boardCell) const {
    if (this->validBoardCell(boardCell)) {
        return this->gameBoard[boardCell.getXCor()][boardCell.getYCor()];
    } else {
        throw invalid_argument("boardCell out of bounds of the board");
    }
}

SquareColor Board::getColorOfBoardCell(int xCor, int yCor) const {
    if (this->validBoardCell(xCor, yCor)) {
        return this->gameBoard[xCor][yCor];
    } else {
        throw invalid_argument("boardCell out of bounds of the board");
    }
}

void Board::setColorOfRequestedCell(const BoardCell &boardCell, const SquareColor &color) {
    if (this->validBoardCell(boardCell)) {
        this->gameBoard[boardCell.getXCor()][boardCell.getYCor()] = color;
    } else {
        throw invalid_argument("boardCell out of bounds of the board");
    }
}

bool Board::validBoardCell(const BoardCell &boardCell) const {
    int xCor = boardCell.getXCor();
    int yCor = boardCell.getYCor();
    return validBoardCell(xCor, yCor);
}

bool Board::validBoardCell(int xCor, int yCor) const {
    return ((xCor >= 0) && (xCor < this->boardLength) && (yCor >= 0) && (yCor < this->boardWidth));
}

int Board::getBoardLength() const {
    return this->boardLength;
}

int Board::getBoardWidth() const {
    return this->boardWidth;
}

bool Board::gameBoardFull() const {
    for (int i = 0; i < this->getBoardLength(); i++) {
        for (int j = 0; j < this->getBoardWidth(); j++) {
            if (this->getColorOfBoardCell(i, j) == Blank) {
                return false;
            }
        }
    }
    return true;
}

int Board::numberOfBoardCellsFilledWithColor(SquareColor color) const {
    int colorCounter = 0;
    for (int i = 0; i < this->getBoardLength(); i++) {
        for (int j = 0; j < this->getBoardWidth(); j++) {
            if (this->getColorOfBoardCell(i, j) == color) {
                colorCounter++;
            }
        }
    }
    return colorCounter;
}