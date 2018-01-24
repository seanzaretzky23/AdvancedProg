/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/
#include "RemoteGame.h"
#define BUFFER_SIZE 4096
#define INVALID_CHOICE_FROM_CLIENT (-1)

RemoteGame::RemoteGame(const char *serverIP, int serverPort, int boardSize):
        serverIP(serverIP), serverPort(serverPort), clientSocket(0), whichPlayerIsHuman(-1){
    this->whosTurn = true;
    this->noMoves = false;
    this->gameOver = false;
    //calling for ConsoleBoard with the default parameters
    this->board = new ConsoleBoard(boardSize, boardSize);
    this->gameLogic = new StandardLogic(this->board);

    try {
        this->gamePrep();
    } catch(const char * msg) {
        cout << msg << endl;
        exit(-1);
    }
}


void RemoteGame::gamePrep() {
    int key;
    int numberOfBytesTransferred = 0;
    char buffer[BUFFER_SIZE];
    string commandToServer = "";
    string gameName;
    bool flagStartOrJoin = false;
    while (!flagStartOrJoin) {
        //creating communication with the server
        try {
            this->createConnectionToServer();
        } catch (const char *msg) {
            cout << "Error accured during connecting to server in RemoteGame. Reason: " << msg << endl;
            exit(-1);
        }
        //message
        cout << "Please choose an option:" << endl;
        cout << "1. start a game" << endl;
        cout << "2. print list of games open to join" << endl;
        cout << "3. join a game with a waiting player" << endl;

        cin >> key;
        if (cin.fail())
            key = INVALID_CHOICE_FROM_CLIENT;
        memset(buffer, '\0', BUFFER_SIZE);
        switch (key) {
            case 1: {
                flagStartOrJoin = this->startGameCommandReceiver();
                if(!flagStartOrJoin) {
                    cout << "invalid game name to start, this game already exists\n" << endl;
                }
                break;
            }
            case 2: {
                strcpy(buffer, "list_games");
                //write command to server
                numberOfBytesTransferred = write(this->clientSocket, buffer, strlen(buffer) + 1);
                if (numberOfBytesTransferred == -1) {
                    throw "Error writing message to server (list of games command option) in RemoteGame";
                }
                //read server answer
                numberOfBytesTransferred = read(this->clientSocket, buffer, sizeof(buffer));
                if (numberOfBytesTransferred == -1 || numberOfBytesTransferred == 0) {
                    throw "Error reading message from server (receiving the games list) in RemoteGame";
                }
                cout  << buffer << endl << endl; // edit the buffer representing the list of games!!!!!!!
                break;
            }
            case 3: {
                flagStartOrJoin = this->joinGameCommandReceiver();
                if(!flagStartOrJoin) {
                    cout << "invalid game name to join, this game doesnt exist\n" << endl;
                }
                break;
            }
            default: {
                cout << "invalid choise!" << endl;
            }
        }
        //clearing input error flag and ignoring bad input
        cin.clear();
        cin.ignore(numeric_limits<streamsize >::max(), '\n');
    }

    //receiving what is the order of players (human player and remote player) from the server and creating the players
    try {
        this->createPlayersBasedOnServer();
    } catch (const char *msg) {
        cout << "Error accured during reading from server in RemoteGame. Reason: " << msg << endl;
        exit(-1);
    }
}


bool RemoteGame::startGameCommandReceiver() {
    int numberOfBytesTransferred = 0;
    char buffer[BUFFER_SIZE];
    string commandToServer = "";
    string gameName;
    bool validName = false;

    cout << "Please name the game you want to start, game name needs to be one word"
            "(only the first will be taken) and one that doesn't already exist" << endl;
    cin >> gameName;
    commandToServer = "start " + gameName;
    strcpy(buffer, commandToServer.c_str());
    //write command to server
    numberOfBytesTransferred = write(this->clientSocket, buffer, strlen(buffer) + 1);
    if (numberOfBytesTransferred == -1) {
        throw "Error writing message to server (chosen command option) in RemoteGame";
    }
    numberOfBytesTransferred = read(this->clientSocket, buffer, sizeof(buffer));
    if (numberOfBytesTransferred == -1 || numberOfBytesTransferred == 0) {
        throw "Error reading confirmation of command execution from server in RemoteGame";
    }
    if(strcmp(buffer, "-1") != 0) {
        validName = true;
    }
    return validName;
}

bool RemoteGame::joinGameCommandReceiver() {
    int numberOfBytesTransferred = 0;
    char buffer[BUFFER_SIZE];
    string commandToServer = "";
    string gameName;
    bool validName = false;

    cout << "Please name the game you want to join to, game name needs to be one word"
            "(only the first will be taken) and one that is already open" << endl;
    cin >> gameName;
    commandToServer = "join " + gameName;
    strcpy(buffer, commandToServer.c_str());
    //write command to server
    numberOfBytesTransferred = write(this->clientSocket, buffer, strlen(buffer) + 1);
    if (numberOfBytesTransferred == -1) {
        throw "Error writing message to server (chosen command option) in RemoteGame";
    }
    numberOfBytesTransferred = read(this->clientSocket, buffer, sizeof(buffer));
    if (numberOfBytesTransferred == -1 || numberOfBytesTransferred == 0) {
        throw "Error reading confirmation of command execution from server in RemoteGame";
    }
    if(strcmp(buffer, "-1") != 0) {
        validName = true;
    }
    return validName;
}


void RemoteGame::createPlayersBasedOnServer() {
    char buffer[BUFFER_SIZE];
    int numberOfBytesTransferred;
    cout << "waiting for other player to join\n" << endl;
    numberOfBytesTransferred = read(this->clientSocket, buffer, sizeof(buffer));
    if (numberOfBytesTransferred == -1) {
        throw "Error reading order of players from server in RemoteGame";
    }
    //converting received message from char * to string for conversion purposes
    string receivedStr = string (buffer);
    //the number representation of the string sent by the server for determining which player is the human one
    int numberReceivedFromServer;
    // stringstream used for the conversion initialized with the contents of receivedStr
    stringstream convert(receivedStr);
    if (!(convert >> numberReceivedFromServer) || (numberReceivedFromServer != 1 && numberReceivedFromServer != 2)) {
        //invalid opening message from the server
        throw "invalid opening message from the server in RemoteGame, possible reason: server connection expired";
    } else {
        this->whichPlayerIsHuman = numberReceivedFromServer - 1;
        switch(this->whichPlayerIsHuman) {
            case 0:
                this->players[0] = new HumanPlayer(Black);
                this->players[1] = new RemotePlayer(White, this->clientSocket);
                break;
            case 1:
                this->players[0] = new RemotePlayer(Black, this->clientSocket);
                this->players[1] = new HumanPlayer(White);
                break;
        }
    }
}

void RemoteGame::createConnectionToServer() {
    // Create a socket point
    this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->clientSocket == -1) {
        throw "Error opening socket in RemoteGame";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(this->serverIP, &address)) {
        throw "Can't parse IP address in RemoteGame";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable in RemoteGame";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(this->serverPort);
    // Establish a connection with the TCP server
    if (connect(this->clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server in RemoteGame";
    }
}

RemoteGame::~RemoteGame() {
    close(this->clientSocket);
}

void RemoteGame::playGame() {
    //buffer for server communication
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    while (true) {
        if (this->board->gameBoardFull()) {
            this->gameOver = true;

            if ((this->whichPlayerIsHuman == 0 && this->whosTurn == true) ||
                    (this->whichPlayerIsHuman == 1 && this->whosTurn == false)) {
                strcpy(buffer, "END");
                this->sendMessageToTheServer(buffer);
            }
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

void RemoteGame::playNextTurn(int i) {
    vector<BoardCell> possibleMoves;

    //buffer for server communication
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    this->printWhosNextTurn();
    try {
        possibleMoves = this->gameLogic->possibleMovesForColor(this->players[i]->getColor());
        if (possibleMoves.size() != 0) {
            this->noMoves = false;
            BoardCell chosenMove = BoardCell(this->players[i]->makeMove(possibleMoves, *this->gameLogic));
            try {
                this->whosTurn = this->gameLogic->makeMove(chosenMove, this->players[i]->getColor());
            } catch (char const *msg) {
                cout << msg << endl;
            }
            this->printPlayersChosenMove(i, chosenMove);

            if (this->whichPlayerIsHuman == i) {
                strcpy(buffer, (chosenMove.boardCellToString()).c_str());
                this->sendMessageToTheServer(buffer);
            }
        } else {
            if (this->noMoves == false) {
                this->noMoves = true;
                cout << "No possible moves. Play passes back to the other player. Press enter to continue." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                this->whosTurn = !this->whosTurn;

                if (this->whichPlayerIsHuman == i) {
                    strcpy(buffer, "NoMove");
                    this->sendMessageToTheServer(buffer);
                }
            } else {
                //neither one of the players has valid moves left to make
                this->gameOver = true;
                cout << "No possible moves. Press enter to continue." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (this->whichPlayerIsHuman == i) {
                    strcpy(buffer, "END");
                    this->sendMessageToTheServer(buffer);
                }
            }
        }
    } catch (char const *msg) {
        cout << msg << " Reason for error: server connection expired" <<  endl;
        exit(-1);
    } catch(...) {
        cout << "error accured In RemoteGame" << endl;
    }
}

void RemoteGame::sendMessageToTheServer(const char *message) {
    //variable for server communication (for validity checks)
    int numberOfBytesTransferred;

    if (message != NULL) {
        numberOfBytesTransferred = write(this->clientSocket, message, strlen(message));
        if (numberOfBytesTransferred == -1) {
            throw "Error writing message to server in RemoteGame";
        }
    } else {
        throw "Error: can't send empy message to server. in RemoteGame";
    }
}

