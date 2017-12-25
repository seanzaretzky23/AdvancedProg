/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Game.h"

Game::Game(): whosTurn(true), noMoves(false), gameOver(false) {
    //creating first player
    this->createPlayersByTypes(HUMANPLAYER, 0);
    //creating second player
    this->createPlayersByTypes(HUMANPLAYER, 1);
    //calling for ConsoleBoard with the default parameters
    this->board = new ConsoleBoard;
    this->gameLogic = new StandardLogic(this->board);
}


Game::Game(PlayerType firstPlayerType, PlayerType secondPlayerType): whosTurn(true), noMoves(false), gameOver(false) {
    //creating first player
    this->createPlayersByTypes(firstPlayerType, 0);
    //creating second player
    this->createPlayersByTypes(secondPlayerType, 1);
    //calling for ConsoleBoard with the default parameters
    this->board = new ConsoleBoard;
    this->gameLogic = new StandardLogic(this->board);
}

Game::Game(int boardSize, PlayerType firstPlayerType, PlayerType secondPlayerType): whosTurn(true),
                                                                                    noMoves(false), gameOver(false) {
    //creating first player
    this->createPlayersByTypes(firstPlayerType, 0);
    //creating second player
    this->createPlayersByTypes(secondPlayerType, 1);
    this->board = new ConsoleBoard(boardSize, boardSize);
    this->gameLogic = new StandardLogic(this->board);
}


Game::~Game() {
    delete this->board;
    delete this->gameLogic;
    delete this->players[0];
    delete this->players[1];
}

void Game::createPlayersByTypes(PlayerType playerType, int playersIndex) {
    if (playersIndex < NumberOfPlayers && playersIndex >= 0) {
        switch (playerType) {
            case HUMANPLAYER:
                if (playersIndex == 0) {
                    //first player
                    this->players[playersIndex] = new HumanPlayer(Black);
                } else {
                    //second player
                    this->players[playersIndex] = new HumanPlayer(White);
                }
                break;
            case AIPLAYER:
                if (playersIndex == 0) {
                    //first player
                    this->players[playersIndex] = new AIPlayer(Black);
                } else {
                    //second player
                    this->players[playersIndex] = new AIPlayer(White);
                }
                break;
            default:
                throw invalid_argument("invalid player type");
        }
    } else {
        throw invalid_argument("invalid player index");
    }
}

void Game::playGame() {
    while (true) {
        if (this->board->gameBoardFull()) {
            this->gameOver = true;
        }
        if (this->gameOver) {
            int winner = this->gameLogic->whoHasMorePoints();
            cout << "Game is over. the final board:" << endl;
            this->board->printBoard();
            switch(winner) {
                case 1:
                    cout << "Player1 (" + SquareColorEnum::blackWhiteColorToStringSymbol(Black) +
                            ") is the winner" << endl;
                    break;
                case 2:
                    cout << "player2 (" + SquareColorEnum::blackWhiteColorToStringSymbol(White) +
                            ") is the winner" << endl;
                    break;
                case 3:
                    cout << "Its a tie" << endl;
            }
            break;
        }
        if (!this->noMoves) {
            cout << "Current board:\n" << endl;
            this->board->printBoard();
        }
        switch (whosTurn) {
            case true:
                //next turn belongs to player 1
                this->playNextTurn(0);
                break;

            case false:
                //next turn belongs to player 2
                this->playNextTurn(1);
                break;
        }
    }
}

void Game::printWhosNextTurn() const {
    switch (this->whosTurn) {
        case true:
            cout << SquareColorEnum::blackWhiteColorToStringSymbol(Black) + ": It's your move." << endl;
            break;
        case false:
            cout << SquareColorEnum::blackWhiteColorToStringSymbol(White) + ": It's your move." << endl;
            break;
    }
}

void Game::printPlayersChosenMove(int playersIndex, BoardCell chosenMove) const {
    string playersSymbol = SquareColorEnum::blackWhiteColorToStringSymbol(this->players[playersIndex]->getColor());
    cout << playersSymbol + " played " + chosenMove.boardCellToString() << endl;
}

void Game::playNextTurn(int i) {
    vector<BoardCell> possibleMoves;
    BoardCell *chosenMove = NULL;

    this->printWhosNextTurn();

    possibleMoves = this->gameLogic->possibleMovesForColor(this->players[i]->getColor());
    if (possibleMoves.size() != 0) {
        this->noMoves = false;
        chosenMove = new BoardCell(this->players[i]->makeMove(possibleMoves, *this->gameLogic));
        this->whosTurn = this->gameLogic->makeMove(*chosenMove, this->players[i]->getColor());
        this->printPlayersChosenMove(i, *chosenMove);
    } else {
        if (this->noMoves == false) {
            this->noMoves = true;
            cout << "No possible moves. Play passes back to the other player. Press enter to continue." << endl;
            cin.ignore(numeric_limits<streamsize >::max(), '\n');
            this->whosTurn = !this->whosTurn;
        } else {
            //neither one of the players has valid moves left to make
            this->gameOver = true;
            cout << "No possible moves. Press enter to continue." << endl;
            cin.ignore(numeric_limits<streamsize >::max(), '\n');
        }
    }

    delete chosenMove;
}


