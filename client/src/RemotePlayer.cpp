/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "RemotePlayer.h"
#define BUFFER_SIZE 4096

RemotePlayer::RemotePlayer(SquareColor color, int playerSocket):
        Player(color), playerSocket(playerSocket) {
}

BoardCell RemotePlayer::makeMove(vector<BoardCell> possibleMoves, const GameLogic &gameLogic) const {

    char buffer[BUFFER_SIZE];
    int numberOfBytesTransferred;

    if (possibleMoves.size() == 0) {
        throw invalid_argument("empty possibleMoves vector is invalid");
    }

    numberOfBytesTransferred = read(this->playerSocket, buffer, BUFFER_SIZE);
    if (numberOfBytesTransferred == -1 || numberOfBytesTransferred == 0) {
        throw "Error reading move from socket in RemotePlayer";
    }

    //converting the received message to boardCell
    string receivedStr = string (buffer);
    BoardCell chosenCell(receivedStr);
    return chosenCell;
}

RemotePlayer::~RemotePlayer() {
    close(this->playerSocket);
}