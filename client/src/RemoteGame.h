/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROG_REMOTEGAME_H
#define ADVANCEDPROG_REMOTEGAME_H

#include "Game.h"
#include "RemotePlayer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

class RemoteGame: public Game
{
public:
    /**************************************************************
    * function name: RemoteGame class builder
    * Input: const char *serverIP, int serverPort, int boardSize (default is 8)
    * @return RemoteGame object instance
    * Function operation: creates a RemoteGame object,
    *      connected to the server whos address has been passed,
    *      creates player of type human player and a remote player, their order
    *      based on what is received from the server.
    *      also, creates boardSize X boardSize board
    **************************************************************/
    RemoteGame(const char *serverIP, int serverPort, int boardSize = 8);

    /**************************************************************
    * function name: ~RemoteGame (RemoteGame class destructor)
    * Input: no input
    * @return no output
    * Function operation: destroys the RemoteGame class instance
    **************************************************************/
    virtual ~RemoteGame();

    /**************************************************************
    * function name: playGame
    * Input: no input
    * @return void
    * Function operation: plays a game of reversi
    **************************************************************/
    virtual void playGame();

protected:

    /**************************************************************
    * function name: playNextTurn
    * Input: int i (0 or 1, represents the index in the players array)
    * @return void
    * Function operation: performs the next turn in consideration
    *   to with which player it have been called (i)
    **************************************************************/
    virtual void playNextTurn(int i);

private:
    //members responsible for communication with the server
    const char *serverIP;
    int serverPort;
    int clientSocket;
    //0 if the first player is the human and 1 if the second
    int whichPlayerIsHuman;

    /*****************************************************************
    * function name: createConnectionToServer
    * Input: no input
    * @return void
    * Function operation: method responsible for connecting to server
    *****************************************************************/
    void createConnectionToServer();

    /*****************************************************************
    * function name: createPlayersBasedOnServer
    * Input: no input
    * @return void
    * Function operation: method responsible for creating players
    *   receiving what is the order of players (human player and remote player)
    *   from the server and creating the players
    *****************************************************************/
    void createPlayersBasedOnServer();

    /**********************************************************************
    * function name: sendMessageToTheServer
    * Input: const char *message
    * @return void
    * Function operation: method responsible for sending message to server
    **********************************************************************/
    void sendMessageToTheServer(const char *message);
};

#endif //ADVANCEDPROG_REMOTEGAME_H
