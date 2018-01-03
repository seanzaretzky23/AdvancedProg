/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "BoardCell.h"
#include <vector>
#include "SquareColorEnum.h"
#include "Board.h"
using namespace std;

/**************************************************************
* The abstract GameLogic class is responsible for the logic of
* the game reversi (mainly rules regarding moves in the game)
**************************************************************/
class GameLogic {

public:
    /**************************************************************
    * function name: GameLogic class builder
    * Input: Board *board
    * @return GameLogic object instance
    * Function operation: creates a GameLogic object instance.
    **************************************************************/
    GameLogic(Board *board);

    /**************************************************************
    * function name: possibleMovesForColor
    * Input: SquareColor color
    * @return vector<BoardCell> (list of possible moves)
    * Function operation: returns the list of possible moves for the player
    *       of the received color to preform.
    **************************************************************/
    virtual vector<BoardCell> possibleMovesForColor(SquareColor color) const = 0;

    /**************************************************************
    * function name: makeMove
    * Input: const BoardCell &boardCell, SquareColor color
    * @return bool representing who's turn it is to go next,
    *       !!! true for the Black, false for the White !!!
    * Function operation: makes the requested move on the board and returns the
    *       player to play the next turn (!assums the move being made is one of the valid options
    *       returned by possibleMovesForColor)
    **************************************************************/
    virtual bool makeMove(const BoardCell &boardCell, SquareColor color) = 0;

/**************************************************************
    * function name: whoHasMorePoints
    * Input: no input
    * @return int representing which player has more points,
    *       !!! 1 for the Black (player1), 2 for the White (player2)
    *       and 3 for a tie!!!
    * Function operation: returns which player has more points
    **************************************************************/
    virtual int whoHasMorePoints() const = 0;

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
    virtual int numberOfPointsOfColor(SquareColor color) const = 0;

    /**************************************************************
    * function name: getGameBoardCopy
    * Input: no input
    * @return return a copy of the gameBoard (needs to be freed)
    * Function operation: returns a copy of the gameBoard
    **************************************************************/
    Board* getGameBoardCopy() const;

    /**************************************************************
    * function name: getThisTypeOfGameLogicWithReceivedBoard
    * Input: Board *board
    * @return return game logic class of the same type as the game logic
    *   type who's method had been called, with requested board
    * Function operation: returns game logic class of the same
    *   type as the game logic type who's method had been called,
    *   with requested board (GameLogic as an interface),
    *   !!! returned instance needs to be freed !!!
    **************************************************************/
    virtual GameLogic* getThisTypeOfGameLogicWithReceivedBoard(Board *board) const = 0;

    /**************************************************************
    * function name: setGameBoard
    * Input: Board *board
    * @return void
    * Function operation: sets the received board as the gameBoard
    *       of the gameLogic instance
    **************************************************************/
    void setGameBoard(Board *board);

protected:
    /**************************************************************
    * function name: turnAllPawnsBetweenTheCells
    * Input: const BoardCell &boardCell1, const BoardCell &boardCell2
    * @return void
    * Function operation: assumes the two received boardCells are valid
    *       and represent two boardCells of same color with line of
    *       boardCells of the opposite color between them.
    **************************************************************/
    void turnAllPawnsBetweenTheCells(const BoardCell &boardCell1, const BoardCell &boardCell2);

    /**************************************************************
    * function name: turnAllPawnsBetweenSameRowCells
    * Input: const BoardCell &boardCell1, const BoardCell &boardCell2
    * @return void
    * Function operation: assumes the two received boardCells are valid
    *       and represent two boardCells of same color with line of
    *       boardCells of the opposite color between them.
    *       also assums boardCell1 is to the left of boardCell2
    **************************************************************/
    void turnAllPawnsBetweenSameRowCells(const BoardCell &boardCell1, const BoardCell &boardCell2);

    /**************************************************************
    * function name: turnAllPawnsBetweenSameColCells
    * Input: const BoardCell &boardCell1, const BoardCell &boardCell2
    * @return void
    * Function operation: assumes the two received boardCells are valid
    *       and represent two boardCells of same color with line of
    *       boardCells of the opposite color between them.
    *       also assums boardCell1 is higher than boardCell2
    **************************************************************/
    void turnAllPawnsBetweenSameColCells(const BoardCell &boardCell1, const BoardCell &boardCell2);

    /**************************************************************
    * function name: turnAllPawnsBetweenSameDiagCells
    * Input: const BoardCell &boardCell1, const BoardCell &boardCell2
    * @return void
    * Function operation: assumes the two received boardCells are valid
    *       and represent two boardCells of same color with line of
    *       boardCells of the opposite color between them.
    **************************************************************/
    void turnAllPawnsBetweenSameDiagCells(const BoardCell &boardCell1, const BoardCell &boardCell2);


protected:
    Board *gameBoard;
};


#endif //GAMELOGIC_H
