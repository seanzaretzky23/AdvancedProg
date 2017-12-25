#include "gtest/gtest.h"
#include "../src/AIPlayer.h"
#include "../src/ConsoleBoard.h"
#include "../src/StandardLogic.h"

//tests the makeMove method
TEST(AIPlayerTest, makeMoveTest1) {
    AIPlayer *player = new AIPlayer(Black);
    Board *board = new ConsoleBoard(8, 8);
    GameLogic *gameLogic = new StandardLogic(board);
    vector<BoardCell> moves = gameLogic->possibleMovesForColor(player->getColor());
    EXPECT_EQ(player->makeMove(moves, *gameLogic), BoardCell(2, 3));
    delete player;
    delete board;
    delete gameLogic;
}

//tests the makeMove method
TEST(AIPlayerTest, makeMoveTest2) {
    AIPlayer *player = new AIPlayer(White);
    Board *board = new ConsoleBoard(8, 8);
    GameLogic *gameLogic = new StandardLogic(board);
    gameLogic->makeMove(BoardCell(2, 3), Black);
    vector<BoardCell> moves = gameLogic->possibleMovesForColor(player->getColor());
    EXPECT_TRUE((player->makeMove(moves, *gameLogic) == BoardCell(2, 2)) ||
                (player->makeMove(moves, *gameLogic) == BoardCell(4, 2)));
    delete player;
    delete board;
    delete gameLogic;
}


//tests the makeMove method
TEST(AIPlayerTest, makeMoveTest3) {
    AIPlayer *player = new AIPlayer(Black);
    Board *board = new ConsoleBoard(8, 8);
    GameLogic *gameLogic = new StandardLogic(board);
    gameLogic->makeMove(BoardCell(2, 3), Black);
    vector<BoardCell> moves = gameLogic->possibleMovesForColor(player->getColor());
    EXPECT_TRUE((player->makeMove(moves, *gameLogic) == BoardCell(5, 4)) ||
                (player->makeMove(moves, *gameLogic) == BoardCell(4, 5)) ||
                (player->makeMove(moves, *gameLogic) == BoardCell(5, 5)));
    delete player;
    delete board;
    delete gameLogic;
}

//tests the makeMove method
TEST(AIPlayerTest, makeMoveTest4) {
    AIPlayer *player = new AIPlayer(Black);
    Board *board = new ConsoleBoard(8, 8);
    GameLogic *gameLogic = new StandardLogic(board);
    gameLogic->makeMove(BoardCell(2, 3), Black);
    board->setColorOfRequestedCell(BoardCell(2, 2), White);
    board->setColorOfRequestedCell(BoardCell(2, 4), Black);
    board->setColorOfRequestedCell(BoardCell(5, 5), Black);
    board->setColorOfRequestedCell(BoardCell(4, 5), Black);
    board->setColorOfRequestedCell(BoardCell(6, 6), Black);
    board->setColorOfRequestedCell(BoardCell(4, 6), Black);
    board->setColorOfRequestedCell(BoardCell(6, 7), Black);
    board->setColorOfRequestedCell(BoardCell(2, 5), Black);
    board->setColorOfRequestedCell(BoardCell(2, 6), Black);
    board->setColorOfRequestedCell(BoardCell(2, 7), Black);
    board->setColorOfRequestedCell(BoardCell(7, 7), Black);
    vector<BoardCell> moves = gameLogic->possibleMovesForColor(player->getColor());
    EXPECT_EQ(player->makeMove(moves, *gameLogic), BoardCell(5, 4));
    delete player;
    delete board;
    delete gameLogic;
}