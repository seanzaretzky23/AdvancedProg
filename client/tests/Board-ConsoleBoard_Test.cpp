
#include "gtest/gtest.h"
#include "../src/ConsoleBoard.h"
#include "../src/StandardLogic.h"

//tests creation of board and the getColorOfBoardCell method
TEST(BoardTestCreation, CreationTestBlanc1)
{
    Board *testBoard = new ConsoleBoard(8,8);
    EXPECT_EQ(testBoard->getColorOfBoardCell(0,0),Blank);
    EXPECT_EQ(testBoard->getColorOfBoardCell(testBoard->getBoardLength()-1,
                                             testBoard->getBoardWidth()-1),Blank);
    delete testBoard;
}

//tests creation of board and the getColorOfBoardCell method
TEST(BoardTestCreation, CreationTestBlanc2)
{

    Board *testBoard = new ConsoleBoard(10,10);
    EXPECT_EQ(testBoard->getColorOfBoardCell(1,1),Blank);
    EXPECT_EQ(testBoard->getColorOfBoardCell(testBoard->getBoardLength()-2,
                                             testBoard->getBoardWidth()-2),Blank);
    delete testBoard;
}

//tests creation of board and the getColorOfBoardCell method
TEST(BoardTestCreation, CreationTestColor)
{

    Board *testBoard = new ConsoleBoard(8,8);
    EXPECT_EQ(testBoard->getColorOfBoardCell(BoardCell(3,4)),Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(BoardCell(4,3)),Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(3,3),White);
    EXPECT_EQ(testBoard->getColorOfBoardCell(4,4),White);
    delete testBoard;
}

//tests creation of board and the getColorOfBoardCell method
TEST(BoardTestCreation, CreationTestColor2)
{
    Board *testBoard = new ConsoleBoard(10,10);
    EXPECT_EQ(testBoard->getColorOfBoardCell(4,5),Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(5,4),Black);
    EXPECT_EQ(testBoard->getColorOfBoardCell(BoardCell(4,4)),White);
    EXPECT_EQ(testBoard->getColorOfBoardCell(BoardCell(5,5)),White);
    delete testBoard;
}

//test the Board(const Board &existingBoard) method
TEST(BoardTestCreation, CreationUsingExistingBoardTest) {
    Board *firstBoard = new ConsoleBoard(8, 8);
    Board *secondBoard = new ConsoleBoard(*firstBoard);
    ASSERT_NE(firstBoard, secondBoard);
    ASSERT_EQ(firstBoard->getBoardWidth(), secondBoard->getBoardWidth());
    ASSERT_EQ(firstBoard->getBoardLength(), secondBoard->getBoardLength());
    for (int i = 0; i < firstBoard->getBoardLength(); i++) {
        for (int j = 0; j < firstBoard->getBoardWidth(); j++) {
            EXPECT_EQ(firstBoard->getColorOfBoardCell(i, j), secondBoard->getColorOfBoardCell(i, j));
        }
    }
    delete firstBoard;
    delete secondBoard;
}

//test the getCopyOfTheBoard method
TEST(BoardTest, getCopyOfTheBoardTest) {
    Board *firstBoard = new ConsoleBoard(8, 8);
    Board *secondBoard = firstBoard->getCopyOfTheBoard();
    ASSERT_NE(firstBoard, secondBoard);
    ASSERT_EQ(firstBoard->getBoardWidth(), secondBoard->getBoardWidth());
    ASSERT_EQ(firstBoard->getBoardLength(), secondBoard->getBoardLength());
    for (int i = 0; i < firstBoard->getBoardLength(); i++) {
        for (int j = 0; j < firstBoard->getBoardWidth(); j++) {
            EXPECT_EQ(firstBoard->getColorOfBoardCell(i, j), secondBoard->getColorOfBoardCell(i, j));
        }
    }
    delete firstBoard;
    delete secondBoard;
}

//tests the method numberOfBoardCellsFilledWithColor(SquareColor color)
TEST(BoardTest, countCellsInColourTest)
{
    Board *testBoard = new ConsoleBoard(10,10);
    EXPECT_EQ(2,testBoard->numberOfBoardCellsFilledWithColor(Black));
    EXPECT_EQ(2,testBoard->numberOfBoardCellsFilledWithColor(White));
    delete testBoard;
}
//tests the method numberOfBoardCellsFilledWithColor(SquareColor color)
TEST(BoardTest, countCellsInColourEdgeTest)
{
    Board *testBoard = new ConsoleBoard(8,8);
    GameLogic* testLog = new StandardLogic(testBoard);
    testLog->makeMove(BoardCell(2,3),Black);
    testLog->makeMove(BoardCell(5,5),Black);

    EXPECT_EQ(6,testBoard->numberOfBoardCellsFilledWithColor(Black));
    EXPECT_EQ(0,testBoard->numberOfBoardCellsFilledWithColor(White));
    delete testBoard;
    delete testLog;
}

//test the getBoardWidth and getBoardLength methods
TEST(BoardTest, getWidthLengthTest) {
    Board *board = new ConsoleBoard(8,8);
    EXPECT_EQ(8, board->getBoardWidth());
    EXPECT_EQ(8, board->getBoardLength());
    delete board;
}

//tests the validBoardCell methods
TEST(BoardTest, validBoardCellTest) {
    Board *board = new ConsoleBoard(8, 8);
    for (int i = 0; i < board->getBoardLength(); i++) {
        for (int j = 0; j < board->getBoardWidth(); j++) {
            EXPECT_TRUE(board->validBoardCell(i, j));
            EXPECT_TRUE(board->validBoardCell(BoardCell(i, j)));
        }
    }
    delete board;
}
