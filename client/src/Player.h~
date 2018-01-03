/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H


#include "SquareColorEnum.h"
#include "BoardCell.h"
#include "GameLogic.h"
#include <stdexcept>
#include <vector>

/**************************************************************
* The abstract Player class represents the general player playing
* the game of reversi
**************************************************************/
using namespace std;

class Player {

public:
    /**************************************************************
    * function name: Player class builder
    * Input: SquareColor color
    * @return Player object instance
    * Function operation: creates a Player object of the specified color.
     *      throws an exception if color is Blank
    **************************************************************/
    Player(SquareColor color);

    /**************************************************************
    * function name: getColor
    * Input: no input
    * @return the color of the player
    **************************************************************/
    SquareColor getColor() const;

    /**************************************************************
    * function name: makeMove
    * Input: vector<BoardCell> possibleMoves,
    *   const GameLogic &gameLogic (for computations in order to
    *   choose the best move)
    * @return BoardCell representing player's choice for the next move
    **************************************************************/
    virtual BoardCell makeMove(vector<BoardCell> possibleMoves, const GameLogic &gameLogic) const = 0;


protected:
    SquareColor playersColor;
};


#endif //PLAYER_H
