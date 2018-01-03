/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include <algorithm>
#include <limits>

/**************************************************************
* This class is a type of Player, representing a human player
**************************************************************/
class HumanPlayer: public Player {

public:

    /**************************************************************
    * function name: HumanPlayer class builder
    * Input: SquareColor color
    * @return HumanPlayer object instance
    * Function operation: creates a HumanPlayer object of the specified color.
    *      throws an exception if color is Blank
    **************************************************************/
    HumanPlayer(SquareColor color);

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

};


#endif //HUMANPLAYER_H
