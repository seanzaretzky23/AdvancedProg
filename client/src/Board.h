/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#ifndef BOARD_H_
#define BOARD_H_

#include "BoardCell.h"
#include <iostream>
#include <vector>
#include "SquareColorEnum.h"

using namespace std;

/**************************************************************
* The abstrac Board class, representing the general form of the
* game boad in reversi game
**************************************************************/
class Board {

public:
    /***********************************************************
    * function name: Board class builder
    * Input: int length, int width
    * @return Board object
    * Function operation: creates a Board object with the specified
    *       length and width, default 8 for both
    *       if parameters are invalid
    **************************************************************/
    Board(int length = 8, int width = 8);

    /**************************************************************
    * function name: Board class copy constructor
    * Input: const Board &existingBoard
    * @return Board object
    * Function operation: creates a Board object that is a copy of
    *   the received, already existing board instance
    **************************************************************/
    Board(const Board &existingBoard);

    /**************************************************************
    * function name: initializeBoard
    * Input: no input
    * @return void
    * Function operation: initializes the gameBoard to its starting state
    **************************************************************/
    virtual void initializeBoard();

    /**************************************************************
    * function name: printBoard
    * Input: no input
    * @return void
    * Function operation: prints the board
    **************************************************************/
    virtual void printBoard() const = 0;

    /**************************************************************
    * function name: getColorOfBoardCell
    * Input: const BoardCell& boardCell
    * @return SquareColor
    * Function operation: returns the color at the requested cell
    *       of the board.
    *       !!! throws exception if the boardCell doesn't represent
    *       a valid cell in the board !!!
    **************************************************************/
    SquareColor getColorOfBoardCell(const BoardCell &boardCell) const;

    /**************************************************************
    * function name: getColorOfBoardCell
    * Input: int xCor, int yCor
    * @return SquareColor
    * Function operation: returns the color at the requested cell
    *       of the board (represented by its co;ordinates).
    *       !!! throws exception if the boardCell doesn't represent
    *       a valid cell in the board !!!
    **************************************************************/
    SquareColor getColorOfBoardCell(int xCor, int yCor) const;

    /**************************************************************
    * function name: setColorOfRequestedCell
    * Input: const BoardCell& boardCell, const SquareColor &color
    * @return void
    * Function operation: assignes the requested color at the requested cell
    *       of the board.
    *       !!! throws exception if the boardCell doesn't represent
    *       a valid cell in the board !!!
    **************************************************************/
    void setColorOfRequestedCell(const BoardCell &boardCell, const SquareColor &color);

    /**************************************************************
    * function name: getBoardLength
    * Input: no input
    * @return int
    * Function operation: returns the length of the gameBoard in
    *       this instance of Board
    **************************************************************/
    int getBoardLength() const;

    /**************************************************************
    * function name: getBoardWidth
    * Input: no input
    * @return int
    * Function operation: returns the width of the gameBoard in
    *       this instance of Board
    **************************************************************/
    int getBoardWidth() const;


    /**************************************************************
    * function name: validBoardCell
    * Input: const BoardCell& boardCell
    * @return bool
    * Function operation: returns true if boardCell represents a cell
    *       a cell in the bounds of the board and false otherwise
    **************************************************************/
    bool validBoardCell(const BoardCell &boardCell) const;

    /**************************************************************
    * function name: validBoardCell
    * Input: int xCor, int yCor (represent a boardCell instance)
    * @return bool
    * Function operation: returns true if boardCell represents a cell
    *       a cell in the bounds of the board and false otherwise
    **************************************************************/
    bool validBoardCell(int xCor, int yCor) const;

    /**************************************************************
    * function name: gameBoardFull
    * Input: no input
    * @return bool
    * Function operation: returns true if the board is full
    *       (there are no Blank cells) and false otherwise
    **************************************************************/
    bool gameBoardFull() const;

    /**************************************************************
    * function name: numberOfBoardCellsFilledWithColor
    * Input: SquareColor color
    * @return int
    * Function operation: returns number of board cells on the board
    *       taken by the received color
    **************************************************************/
    int numberOfBoardCellsFilledWithColor(SquareColor color) const;

    /**************************************************************
    * function name: getCopyOfTheBoard
    * Input: no input
    * @return Board instance that is a copy of this Board instance
    * Function operation: returns Board instance that is a copy
    * of this board instance
    **************************************************************/
    virtual Board* getCopyOfTheBoard() const = 0;

protected:
    int boardLength;
    int boardWidth;
    vector<vector<SquareColor > > gameBoard;
};

#endif /* BOARD_H_ */
