/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include <algorithm>

/**************************************************************
* This class is a type of Player, representing an AI player
**************************************************************/
class AIPlayer: public Player {

public:

    /**************************************************************
    * function name: AIPlayer class builder
    * Input: SquareColor color
    * @return AIPlayer object instance
    * Function operation: creates a AIPlayer object of the specified color.
    *      throws an exception if color is Blank
    **************************************************************/
    AIPlayer(SquareColor color);

    /**************************************************************
    * function name: makeMove
    * Input: vector<BoardCell> possibleMoves,
    *   const GameLogic &gameLogic (for computations in order to
    *   choose the best move)
    * @return BoardCell representing player's choice for the next move
    * Function operation: asks the player for input on its next move
    *   untill a valid choice is entered
    **************************************************************/
    virtual BoardCell makeMove(vector<BoardCell> possibleMoves, const GameLogic &gameLogic) const;

protected:

    /**************************************************************
    * function name: findIndexOfMaxValue
    * Input: ector<int> values
    * @return int
    * Function operation: returns the index of the max value in the
    *       received vector, -1 if empty
    **************************************************************/
    int findIndexOfMaxValue(vector<int> values) const;

    /**************************************************************
    * function name: findIndexOfMinValue
    * Input: ector<int> values
    * @return int
    * Function operation: returns the index of the min value in the
    *       received vector, -1 if empty
    **************************************************************/
    int findIndexOfMinValue(vector<int> values) const;
};


#endif
