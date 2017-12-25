
#include "gtest/gtest.h"
#include "../src/StandardLogic.h"
#include "../src/ConsoleBoard.h"
#define BLACK_WON 1
#define WHITE_WON 2
#define TIE 3


//tests the possibleMovesForColor method
TEST(StandartLogicTest, possibleMovseTest)
{

    vector<BoardCell> testVec;
    vector<BoardCell> testVec2;
    ConsoleBoard *testBoard = new ConsoleBoard(8, 8);
    StandardLogic *testLogic = new StandardLogic(testBoard);
    testVec = testLogic->possibleMovesForColor(Black);
    testVec2.push_back(BoardCell(2,3));
    testVec2.push_back(BoardCell(3,2));
    testVec2.push_back(BoardCell(4,5));
    testVec2.push_back(BoardCell(5,4));
    EXPECT_EQ(testVec, testVec2);
    delete(testBoard);
    delete(testLogic);

}

//tests the possibleMovesForColor method edge case
TEST(StandartLogicTest, possibleMovseEdgeTest)
{
    vector<BoardCell> testVec;
    vector<BoardCell> testVec2;
    ConsoleBoard *testBoard = new ConsoleBoard(2, 2);
    StandardLogic *testLogic = new StandardLogic(testBoard);
    testVec = testLogic->possibleMovesForColor(Black);
    EXPECT_EQ(testVec,testVec2);
    delete(testBoard);
    delete(testLogic);

}

//test the possibleMovesForColor method exception throw case
TEST(StandartLogicTest, possibleMovseEdgeExceptionThrowTest) {
    ConsoleBoard *testBoard = new ConsoleBoard(8, 8);
    StandardLogic *testLogic = new StandardLogic(testBoard);
    EXPECT_THROW(testLogic->possibleMovesForColor(Blank), exception);
    delete(testBoard);
    delete(testLogic);
}

//tests the makeMove method
TEST(StandartLogicTest, makeMoveTest1)
{
    ConsoleBoard* testBoard = new ConsoleBoard(8, 8);
    StandardLogic* testLogic = new StandardLogic(testBoard);
    testLogic->makeMove(BoardCell(2,3), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(2,3), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(3,4), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(4,3), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(3,3), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(4,4), White);
    delete(testBoard);
    delete(testLogic);
}

//tests the makeMove method
TEST(StandartLogicTest, makeMoveTest2)
{
    ConsoleBoard* testBoard = new ConsoleBoard(8, 8);
    StandardLogic* testLogic = new StandardLogic(testBoard);
    testLogic->makeMove(BoardCell(2,3), Black);
    testLogic->makeMove(BoardCell(2,2), White);
    EXPECT_EQ(testBoard->getColorOfBoardCell(2,2), White);
    EXPECT_EQ(testBoard->getColorOfBoardCell(2,3), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(3,4), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(4,3), Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(3,3), White);
    EXPECT_EQ(testBoard->getColorOfBoardCell(4,4), White);
    delete(testBoard);
    delete(testLogic);
}

//tests the whoHasMorePoints
TEST(StandartLogicTest, whoHasMorePointsTest)
{
    ConsoleBoard* testBoard = new ConsoleBoard(8, 8);
    StandardLogic* testLogic = new StandardLogic(testBoard);
    testLogic->makeMove(BoardCell(2,3), Black);
    EXPECT_EQ(testLogic->whoHasMorePoints(), BLACK_WON);
    delete(testBoard);
    delete(testLogic);
}

//tests the whoHasMorePoints
TEST(StandartLogicTest, whoHasMorePointsTestTieCase)
{
    ConsoleBoard* testBoard = new ConsoleBoard(8, 8);
    StandardLogic* testLogic = new StandardLogic(testBoard);
    EXPECT_EQ(testLogic->whoHasMorePoints(), TIE);
    delete(testBoard);
    delete(testLogic);
}


//tests the whoHasMorePoints in an edge case
TEST(StandartLogicTest, whoHasMorePointsTestTieEdge)
{
    ConsoleBoard* testBoard = new ConsoleBoard(2, 2);
    StandardLogic* testLogic = new StandardLogic(testBoard);
    EXPECT_EQ(testLogic->whoHasMorePoints(),TIE);
    delete(testBoard);
    delete(testLogic);
}

//tests the numberOfPointsOfColor method
TEST(StandartLogicTest, numberOfPointsOfColorTest) {
    ConsoleBoard* testBoard = new ConsoleBoard(8, 8);
    StandardLogic* testLogic = new StandardLogic(testBoard);
    testLogic->makeMove(BoardCell(2,3), Black);
    EXPECT_GT(testLogic->numberOfPointsOfColor(Black), testLogic->numberOfPointsOfColor(White));
    EXPECT_EQ(testLogic->numberOfPointsOfColor(Black), 4);
    EXPECT_EQ(testLogic->numberOfPointsOfColor(White), 1);
    delete(testBoard);
    delete(testLogic);
}