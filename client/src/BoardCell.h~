/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/**************************************************************
* The BordCell class, representing a cell in the game board of
* the game (representing loction on the board, row and col)
**************************************************************/
class BoardCell {

public:
    /**************************************************************
    * function name: BoardCell class builder
    * Input: int xCor, int yCor
    * @return BoardCell object instance
    * Function operation: creates a BoardCell object
    *   with the specified co'ordinates
    **************************************************************/
    BoardCell(int xCor, int yCor);

    /**************************************************************
     * function name: BoardCell class builder
     * Input: string str
     * @return BoardCell object instance
     * Function operation: creates a BoardCell object from string;
     * throw exception if:
     * not starting with '('
     * not ending with ')'
     * no , in the middle
     * more than one char in the middle.
     **************************************************************/
    BoardCell(const string &str);

    /**************************************************************
    * function name: BoardCell copy constructor
    * Input: const BoardCell &existingBoardCell
    * @return BoardCell object instance
    * Function operation: creates a BoardCell object that is a copy
    *       of the received instance of BoardCell
    **************************************************************/
    BoardCell(const BoardCell &existingBoardCell);

    /**************************************************************
    * function name: getXCor
    * Input: no input
    * @return int
    * Function operation: returns the xCor of the BoardCell instance
    **************************************************************/
    int getXCor() const;

    /**************************************************************
    * function name: getYCor
    * Input: no input
    * @return int
    * Function operation: returns the yCor of the BoardCell instance
    **************************************************************/
    int getYCor() const;

    /**************************************************************
    * function name: boardCellToString
    * Input: no input
    * @return string
    * Function operation: returns the string that represents
    *       the BoardCell instance
    **************************************************************/
    string boardCellToString() const;

    /**************************************************************
    * function name: operator ==
    * Input: const BoardCell &boardCell
    * @return bool
    * Function operation: overloads the == operator for BoardCell class
    *       returns true if received instance equals to this instance,
    *       false otherwise
    **************************************************************/
    bool operator ==(const BoardCell &boardCell) const;


private:
    int xCor;
    int yCor;
};


#endif BOARDCELL_H
