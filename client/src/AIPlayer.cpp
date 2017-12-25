/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include <limits>
#include "AIPlayer.h"

AIPlayer::AIPlayer(SquareColor color): Player(color) {}

BoardCell AIPlayer::makeMove(vector<BoardCell> possibleMoves, const GameLogic &gameLogic) const {
    if (possibleMoves.size() == 0) {
        throw invalid_argument("empty possibleMoves vector is invalid");
    }

    //for each possible move of AI player (by order) the max grade the opponent can generate
    vector<int> maxGradesForMoves;
    SquareColor opponentsColor = SquareColorEnum::getOppositeColor(this->getColor());

    //iterating over AIplayer's possible moves
    for (vector<BoardCell>::iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {
        Board *boardForAIMove = gameLogic.getGameBoardCopy();
        GameLogic *gameLogicTmp = gameLogic.getThisTypeOfGameLogicWithReceivedBoard(boardForAIMove);
        //AIPlayer makes one of its possible moves temporarily
        gameLogicTmp->makeMove(*it, this->getColor());
        //opponent's possible moves after aiplayer's temporary move
        vector<BoardCell> opponentsPossibleMoves = gameLogicTmp->possibleMovesForColor(opponentsColor);

        //if there is a move that the AIPlayer can do to make the opponent not able to make move it will choose that
        if (opponentsPossibleMoves.size() == 0) {
            delete boardForAIMove;
            delete gameLogicTmp;
            return *it;
        }
        vector<int> gradesForOpponentsMoves;
        //iterating over opponent's possible moves after AIplayer made a move of the possible moves for it
        for (vector<BoardCell>::iterator itOpponent = opponentsPossibleMoves.begin();
             itOpponent != opponentsPossibleMoves.end(); itOpponent++) {

            Board *boardForOpponentMove = boardForAIMove->getCopyOfTheBoard();
            gameLogicTmp->setGameBoard(boardForOpponentMove);
            gameLogicTmp->makeMove(*itOpponent, opponentsColor);
            //opponent's number of points minus AI's number of points
            int opponentsGradeForMove = gameLogicTmp->numberOfPointsOfColor(opponentsColor) -
                    gameLogicTmp->numberOfPointsOfColor(this->getColor());
            gradesForOpponentsMoves.push_back(opponentsGradeForMove);
            delete boardForOpponentMove;
        }
        int indexOfMoveGivesMaxGradeToOpponent = this->findIndexOfMaxValue(gradesForOpponentsMoves);
        maxGradesForMoves.push_back(gradesForOpponentsMoves[indexOfMoveGivesMaxGradeToOpponent]);
        delete boardForAIMove;
        delete gameLogicTmp;
    }

    int indexOfMinMaxMoveForAIplayer = this->findIndexOfMinValue(maxGradesForMoves);
    return possibleMoves[indexOfMinMaxMoveForAIplayer];
}

int AIPlayer::findIndexOfMaxValue(vector<int> values) const {
    if (values.empty()) {
        return -1;
    } else {
        int maxValue = values[0];
        int indexOfMax = 0;
        for (int i = 1; i < values.size(); i++){
            if (values[i] > maxValue) {
                maxValue = values[i];
                indexOfMax = i;
            }
        }
        return indexOfMax;
    }
}

int AIPlayer::findIndexOfMinValue(vector<int> values) const {
    if (values.empty()) {
        return -1;
    } else {
        int minValue = values[0];
        int indexOfMin = 0;
        for (int i = 1; i < values.size(); i++){
            if (values[i] < minValue) {
                minValue = values[i];
                indexOfMin = i;
            }
        }
        return indexOfMin;
    }
}