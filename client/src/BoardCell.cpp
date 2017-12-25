/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "BoardCell.h"


BoardCell::BoardCell(int xCor, int yCor): xCor(xCor), yCor(yCor) {}

BoardCell::BoardCell(const BoardCell &existingBoardCell): xCor(existingBoardCell.getXCor()),
                                                          yCor(existingBoardCell.getYCor()) {}

int BoardCell::getXCor() const {
    return this->xCor;
}

int BoardCell::getYCor() const {
    return this->yCor;
}

string BoardCell::boardCellToString() const {
    string str;
    stringstream convertX, convertY;
    //adjusting the co'ordinates because the board starts at 1 not 0
    convertX << this->xCor + 1;
    convertY << this->yCor + 1;
    str = "(" + convertX.str() + "," + convertY.str() + ")";
    return str;
}

bool BoardCell::operator==(const BoardCell &boardCell) const {
    return ((this->xCor == boardCell.xCor) && (this->yCor == boardCell.yCor));
}

BoardCell::BoardCell(const string &str) {
    //variables helping to build the co'ordinates from the input string
    int xSum = 0, ySum = 0;
    int k;
    int i = str.length()-1;

    int j = 1;
    while(!((str[i] <= '9')&&(str[i] >= '0')))
    {
        if(str[i]!=')')
            throw "oh oh- not ) after last num";
        i--;

    }
    //get the second cord.
    while((str[i] <= '9')&&(str[i] >= '0'))
    {
        ySum += j *( str[i] - '0');
        i--;
        j *= 10;
    }
    j = 1;
    if(str[i]!=',')
        throw "oh-oh no , before last num ";
    //get the non num chars between the nums
    k=i-1;
    while(!((str[i] <= '9')&&(str[i] >= '0')))
    {
        i--;
    }
    if(i!=k)
        throw "oh-oh to many chars between nums ";
    //get the first cord.
    while((str[i] <= '9')&&(str[i] >= '0'))
    {
        xSum += j *( str[i] - '0');
        i--;
        j *= 10;
    }
    if(str[i]!='(')
        throw "oh-oh no ( before last num ";
    this->xCor = xSum-1;
    this->yCor = ySum-1;
    if(str[0]!='(')
        throw "oh-oh not starting with ( ";
    if(str[str.length()-1]!=')')
        throw "oh-oh not ending with ) ";
}