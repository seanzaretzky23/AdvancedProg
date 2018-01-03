/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Game.h"
#include "RemoteGame.h"
#include "ReadFile.cpp"
#define CONFIG_FILE "configFileClient.txt"

/**************************************************************
 * function name: main
 * Input: no input
 * @return int
 * Function operation: creates a Board object and prints it
 **************************************************************/
int main()
{
    string strIp;
    string strPort;
    try {
        strIp = ReadIP(CONFIG_FILE);
        strPort = ReadPort(CONFIG_FILE);
    } catch (const char * exc) {
        cout << "error in main: " << exc << endl;
        exit (-1);
    }
    //converting port to int
    int port;
    stringstream convert(strPort);
    if(!(convert >> port))
        throw "invalid port description";
    bool validChoice = false;
    int choice;
    Game *game;
    while (!validChoice) {
        cout << "for playing against another human player press 1, for AI player press 2,"
                "for remote game press 3" << endl;
        cin >> choice;
        if (!cin.fail() && (choice == 1 || choice == 2 || choice == 3)) {
            validChoice = true;
        }
        //clearing input error flag and ignoring bad input
        cin.clear();
        cin.ignore(numeric_limits<streamsize >::max(), '\n');
    }
    switch (choice) {
        case 1:
            game = new Game(Game::HUMANPLAYER, Game::HUMANPLAYER);
            break;
        case 2:
            game = new Game(Game::HUMANPLAYER, Game::AIPLAYER);
            break;
        case 3:
            game = new RemoteGame(strIp.c_str(), port);
            break;
    }
    game->playGame();
    delete game;

}