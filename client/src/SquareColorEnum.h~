/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#ifndef SQUARECOLORENUM_H
#define SQUARECOLORENUM_H

#include <stdexcept>
#include <string.h>
using namespace std;

/**************************************************************
* enum representing the possibles colors of pawns on the game
* board of reversi
**************************************************************/
enum SquareColor {Black, White, Blank};

class SquareColorEnum {
public:

    /**************************************************************
   * function name: blackWhiteColorToStringSymbol
   * Input: SquareColor color
   * @return string representing the symbol of the received pawn color
   *    throws exception if the received color isn't a color of pawn
   *    meaning not black or white
   **************************************************************/
    static string blackWhiteColorToStringSymbol(SquareColor color) {
        switch (color) {
            case Black:
                return "X";
            case White:
                return "O";
            default:
                throw invalid_argument("color parameter can only be black or white to be represented as string");
        }
    }

    /**************************************************************
   * function name: getOppositeColor
   * Input: SquareColor color
   * @return returns the opposite of the received pawn(board cell)
   *    color, for White returns Black, for Black returns White
   *    !!! throws exception if the received color is Blank !!!
   **************************************************************/
    static SquareColor getOppositeColor(SquareColor color) {
        switch (color) {
            case White:
                return Black;
            case Black:
                return White;
            default:
                throw invalid_argument("received color can only be Black or White");
        }
    }
};


#endif //SQUARECOLORENUM_H
