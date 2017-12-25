/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(SquareColor color): Player(color) {}

BoardCell HumanPlayer::makeMove(vector<BoardCell> possibleMoves, const GameLogic &gameLogic) const {

    if (possibleMoves.size() == 0) {
        throw invalid_argument("empty possibleMoves vector is invalid");
    }
    int row, col;
    //variable contains if the user's choice for a move was valid
    bool ok = false;

    while (!ok) {
        cout << "Your possible moves: ";

        for (int i = 0; i < possibleMoves.size(); i++) {
            if (i < possibleMoves.size() - 1) {
                cout << possibleMoves[i].boardCellToString() + ",";
            } else {
                cout << possibleMoves[i].boardCellToString() << endl;
            }
        }

        cout << "\nPlease enter your move in the format: row col\n"
                "(two integers with a space between them, for example: 3 4  )" << endl;
        cout << "notice: only the first two integers will be taken" << endl;

        cin >> row;
        if (!cin.fail()) {
            cin >> col;
            if (!cin.fail()) {
                //adjusting the received co'ordinates (the board starts at 1 but stored as starting at 0)
                row = row - 1;
                col = col - 1;
                BoardCell tmp(row, col);
                //checking if the choice is one of the offered moves
                if (find(possibleMoves.begin(), possibleMoves.end(), tmp) != possibleMoves.end()) {
                    ok = true;
                } else {
                    cout << "your choice isn't one of the offered moves" << endl;
                }
            }
        }
        if (!ok) {
            cout << "invalid input, try again\n" << endl;
        }
        //clearing input error flag and ignoring previous bad input
        cin.clear();
        cin.ignore(numeric_limits<streamsize >::max(), '\n');
    }
    BoardCell chosenCell(row, col);
    return chosenCell;
}
