/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#include "Player.h"

Player::Player(SquareColor color) {
    if (color == Blank) {
        throw invalid_argument("player's color can only be black or white");
    } else {
        this->playersColor = color;
    }
}

SquareColor Player::getColor() const {
    return this->playersColor;
}
