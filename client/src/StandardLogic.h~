/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#ifndef STANDARDLOGIC_H
#define STANDARDLOGIC_H

#include "GameLogic.h"
#include <stdexcept>

/**************************************************************
* This class is a type of GameLogic, representing the standard
* rules of the game of reversi.
**************************************************************/
class StandardLogic: public GameLogic {

public:
    /**************************************************************
    * function name: StandardLogic class builder
    * Input: Board *board
    * @return StandardLogic object instance
    * Function operation: creates a StandardLogic object instance,
    *       using GameLogic builder
    **************************************************************/
    StandardLogic(Board *board);

    /**************************************************************
    * function name: possibleMovesForColor
    * Input: SquareColor color
    * @return vector<BoardCell>
    * Function operation: returns a vector of possible moves for
    *       the player of received color represented by BoardCells
    *       !!! if the received color is Blank throws exception
    *       (only White and Black are legal) !!!
    **************************************************************/
    virtual vector<BoardCell> possibleMovesForColor(SquareColor color) const;

    /**************************************************************
    * function name: makeMove
    * Input: const BoardCell &boardCell, SquareColor color
    * @return bool representing who's turn it is to go next,
    *       !!! true for the Black, false for the White !!!
    * Function operation: makes the requested move on the board and returns the
    *       player to play the next turn (!if the move being made isn't one of the valid options
    *       returned by possibleMovesForColor than throws exception)
    **************************************************************/
    virtual bool makeMove(const BoardCell &boardCell, SquareColor color);

    /**************************************************************
    * function name: whoHasMorePoints
    * Input: no input
    * @return int representing which player has more points,
    *       !!! 1 for the Black (player1), 2 for the White (player2)
    *       and 3 for a tie!!!
    * Function operation: returns which player has more points
    **************************************************************/
    virtual int whoHasMorePoints() const;

    /**************************************************************
    * function name: numberOfPointsOfColor
    * Input: SquareColor color
    * @return int representing number of points of the player of
    *       the received color
    * Function operation: returns number o points of the player of
    *       the received color
    * !!! throws exception if received color is blank
    *       (doesn't represent player) !!!
    **************************************************************/
    virtual int numberOfPointsOfColor(SquareColor color) const;

    /**************************************************************
    * function name: getThisTypeOfGameLogicWithReceivedBoard
    * Input: Board *board
    * @return return game logic class of the same type as the game logic
    *   type who's method had been called, with requested board
    * Function operation: returns game logic class of the same
    *   type as the game logic type who's method had been called,
    *   with requested board (GameLogic as an interface)
    *   !!! returned instance needs to be freed !!!
    **************************************************************/
    virtual GameLogic* getThisTypeOfGameLogicWithReceivedBoard(Board *board) const;

protected:

    /**************************************************************
    * function name: boardCellsCreatingScoreLines
    * Input: const BoardCell &boardCell, const SquareColor &color
    * @return vector<BoardCell>
    * Function operation: returns a vector of boardCells that together
    * with the received boardCell (of the received color) form line
    * that give score in the game
    **************************************************************/
    virtual vector<BoardCell> boardCellsCreatingScoreLines(const BoardCell &boardCell, const SquareColor &color) const;

private:

    /**************************************************************
    * function name: initializeBoolVectorForBCCSLmethod
    * Input: vector<bool> &vec, const BoardCell &boardCell,
    *       const SquareColor &color
    * @return void
    * Function operation: initializes the vector used in the method
    *       boardCellsCreatingScoreLines
    **************************************************************/
    void initializeBoolVectorForBCCSLmethod(vector<bool> &vec, const BoardCell &boardCell, const SquareColor &color) const;

    /**************************************************************
    * function name: helperMethodForBCCSL
    * Input: vector<bool> &contSearch, int index, vector<BoardCell> &boardCells,
    *       int xCoefficient, int yCoefficient, int &xCor, int &yCor, int &i,
    *       SquareColor color
    * @return void
    * Function operation: helper method for the method:
    *       boardCellsCreatingScoreLines, that enables avoid copying
    *       code segment that is repeating in the BCCSL method
    **************************************************************/
    void helperMethodForBCCSL(vector<bool> &contSearch, int index, vector<BoardCell> &boardCells,
                                             int xCoefficient, int yCoefficient, int &xCor, int &yCor, int &i,
                                             SquareColor color) const;


};


#endif //STANDARDLOGIC_H
