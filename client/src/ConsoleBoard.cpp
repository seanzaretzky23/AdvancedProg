/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#include "ConsoleBoard.h"

ConsoleBoard::ConsoleBoard(int length, int width): Board(length, width) {}

ConsoleBoard::ConsoleBoard(const Board &existingBoard): Board(existingBoard) {}

void ConsoleBoard::printBoard() const {
    cout << " " << '|';
    for (int j = 1; j <= boardLength; j++) {
        cout << ' ' << j << ' ' << '|';
    }
    cout << "" << endl;
    for (int j = 0; j < (4 * boardLength) + 2; j++) {
        cout << '.';
    }
    cout << "" << endl;
    for (int i = 0; i < boardWidth; i++) {
        cout << i + 1 << '|';
        for (int j = 0; j < boardLength; j++) {

            string pawnToPrint;
            switch (this->gameBoard[i][j]) {
                case Black:
                    pawnToPrint = SquareColorEnum::blackWhiteColorToStringSymbol(Black);
                    break;
                case White:
                    pawnToPrint = SquareColorEnum::blackWhiteColorToStringSymbol(White);;
                    break;
                default:
                    pawnToPrint = " ";
                    break;
            }
            cout << ' ' << pawnToPrint << " |";
        }
        cout << "" << endl;
        for (int j = 0; j < (4 * boardLength) + 2; j++) {
            cout << '.';
        }
        cout << "" << endl;
    }

}

Board* ConsoleBoard::getCopyOfTheBoard() const {
    return new ConsoleBoard(*this);
}
