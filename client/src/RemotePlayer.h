/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROG_REMOTEPLAYER_H
#define ADVANCEDPROG_REMOTEPLAYER_H

#include "Player.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

/******************************************************************************
* This class is a type of Player, representing the behavior of a remote player
*******************************************************************************/
class RemotePlayer: public Player {
public:

    /**************************************************************
    * function name: RemotePlayer class builder
    * Input: SquareColor color, int playerSocket
    * @return RemotePlayer object instance
    * Function operation: creates a RemotePlayer object of the specified color
    *   and with a connection to specified server address.
    *   throws an exception if color is Blank
    **************************************************************/
    RemotePlayer(SquareColor color, int playerSocket);

    /**************************************************************
    * function name: makeMove
    * Input: vector<BoardCell> possibleMoves,
    *   const GameLogic &gameLogic (for computations in order to
    *   choose the best move)
    * @return BoardCell representing player's choice for the next move
    * Function operation: asks the player for input on its next move
    *   untill a valid choice is entered
    **************************************************************/
    virtual BoardCell makeMove(vector<BoardCell> possibleMoves, const GameLogic &gameLogic) const;

    /**************************************************************
    * function name: ~RemotePlayer (RemotePlayer class destructor)
    * Input: no input
    * @return no output
    * Function operation: destroys the RemotePlayer calss instance
    *   (closes the connection to the server)
    **************************************************************/
    ~RemotePlayer();

private:
    //members responsible for communication with the server
    int playerSocket;

};


#endif //ADVANCEDPROG_REMOTEPLAYER_H
