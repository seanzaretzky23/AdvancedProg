/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#ifndef CONSOLEBOARD_H
#define CONSOLEBOARD_H


#include "Board.h"
#include <string.h>
using namespace std;

/**************************************************************
* This class is a type of Board, represents a game board in the
* game reversi that works with the console
**************************************************************/
class ConsoleBoard: public Board {

public:
    /**************************************************************
    * function name: ConsoleBoard class builder
    * Input: int length, int width
    * @return ConsoleBoard object
    * Function operation: creates a ConsoleBoard object with the specified
    *          length and width, default 8 for both
    **************************************************************/
    ConsoleBoard(int length = 8, int width = 8);

    /**************************************************************
    * function name: ConsoleBoard class copy constructor
    * Input: const Board &existingBoard
    * @return ConsoleBoard object
    * Function operation: creates a ConsoleBoard object that is a copy of
    *   the received, already existing ConsoleBoard instance
    **************************************************************/
    ConsoleBoard(const Board &existingBoard);

    /**************************************************************
    * function name: printBoard
    * Input: no input
    * @return void
    * Function operation: prints the board
    **************************************************************/
    virtual void printBoard() const;

    /**************************************************************
    * function name: getCopyOfTheBoard
    * Input: no input
    * @return ConsoleBoard instance that is a copy of this
    *   ConsoleBoard instance
    * Function operation: returns onsoleBoard instance that is a
    * copy of this ConsoleBoard instance
    **************************************************************/
    virtual Board* getCopyOfTheBoard() const;

};


#endif //CONSOLEBOARD_H
