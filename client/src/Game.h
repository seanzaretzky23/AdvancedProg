/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/


#ifndef GAME_H
#define GAME_H


#include "GameLogic.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "ConsoleBoard.h"
#include "StandardLogic.h"
#include <limits>

#define NumberOfPlayers 2

/**************************************************************
* This class is responsible for the flow of the reversi game,
* responsible and uses other class instances to run the game
**************************************************************/
class Game {


public:

    /*****************************************************************
    * enum representing the possibles types of players in reversi game
    ******************************************************************/
    enum PlayerType {HUMANPLAYER, AIPLAYER};

    /**************************************************************
    * function name: Game class default builder
    * Input: no input
    * @return Game object instance
    * Function operation: creates a Game object,
    *      creates two human players and 8X8 board (default)
    **************************************************************/
    Game();

    /**************************************************************
    * function name: Game class builder
    * Input: PlayerType firstPlayerType, PlayerType secondPlayerType
    * @return Game object instance
    * Function operation: creates a Game object,
    *      creates players of the specified types and 8X8 board (default)
    **************************************************************/
    Game(PlayerType firstPlayerType, PlayerType secondPlayerType);

    /**************************************************************
    * function name: Game class builder
    * Input: int boardSize, PlayerType firstPlayerType,
    *       PlayerType secondPlayerType
    * @return Game object instance
    * Function operation: creates a Game object,
    *      creates two players of the specified types and
    *      boardSize X boardSize board
    **************************************************************/
    Game(int boardSize, PlayerType firstPlayerType, PlayerType secondPlayerType);

    /**************************************************************
    * function name: ~Game (Game class destructor)
    * Input: no input
    * @return no output
    * Function operation: destroys the Game class instance
    **************************************************************/
    virtual ~Game();

    /**************************************************************
    * function name: playGame
    * Input: no input
    * @return void
    * Function operation: plays a game of reversi
    **************************************************************/
    virtual void playGame();

private:

    /**************************************************************
    * function name: createPlayersByTypes
    * Input: PlayerType playerType, int playersIndex
    * @return void
    * Function operation: creates the player matching to the playersIndex
    *   of the type sent as a parameter
    *   throws exception if received invalid player type or player index
    **************************************************************/
    void createPlayersByTypes(PlayerType playerType, int playersIndex);

protected:

    Player *players[NumberOfPlayers]; // players[0] is for player 1 and players[1] is for player 2
    GameLogic *gameLogic;
    Board *board;
    //variable containing true if there has been no possible moves in the last turn (to know when the game ends)
    bool noMoves;
    //variable representing if the game is over
    bool gameOver;
    bool whosTurn; // who's turn to play, true for player 1 (Black pawns), false for player 2 (White pawns)

    /**************************************************************
    * function name: playNextTurn
    * Input: int i (0 or 1, represents the index in the players array)
    * @return void
    * Function operation: performs the next turn in consideration
    *   to with which player it have been called (i)
    **************************************************************/
    virtual void playNextTurn(int i);

    /**************************************************************
    * function name: printWhosNextTurn
    * Input: no input
    * @return void
    * Function operation: prints message noticing whos next turn
    **************************************************************/
    void printWhosNextTurn() const;

    /**************************************************************
    * function name: printPlayersChosenMove
    * Input: int playersIndex, BoardCell chosenMove
    * @return void
    * Function operation: prints the chosen move of the player
    *   specified by the playersIndex
    **************************************************************/
    void printPlayersChosenMove(int playersIndex, BoardCell chosenMove) const;
};


#endif //GAME_H
