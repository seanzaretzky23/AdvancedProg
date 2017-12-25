
#include "gtest/gtest.h"
#include "../src/BoardCell.h"

//tests the boardCellToString method
TEST(BoardCellTest,ToStringTest)
{
    BoardCell *testCell = new BoardCell(1,1);
    EXPECT_EQ(testCell->boardCellToString(),"(2,2)");
    delete testCell;
}

//tests the == operator method
TEST(BoardCellTest, equalityOperatorTest) {
    BoardCell firstCell(3, 3);
    BoardCell *secondCell = new BoardCell(3, 3);
    EXPECT_TRUE(firstCell == (*secondCell));
    delete secondCell;
}
//tests the creation from string
TEST(BoardCellTest,CreateFromString)
{
    BoardCell theCell = BoardCell("(1,2)");
    EXPECT_EQ(theCell.getXCor(),0);
    EXPECT_EQ(theCell.getYCor(),1);
}
//tests the creation from string
TEST(BoardCellTest,CreateFromStringBigNum)
{
    BoardCell theCell = BoardCell("(1234,2567)");
    EXPECT_EQ(theCell.getXCor(),1233);
    EXPECT_EQ(theCell.getYCor(),2566);
}
//tests the creation from string checks for throwing exception on bad input
TEST(BoardCellTest,CreateFromStringException)
{
    EXPECT_ANY_THROW(BoardCell theCell=BoardCell("..."));

}
//tests the creation from string checks for throwing exception on bad input
TEST(BoardCellTest,CreateFromStringEceptionBadStart)
{
    EXPECT_ANY_THROW(BoardCell theCell=BoardCell(",(3,4)"));

}
//tests the creation from string checks for throwing exception on bad input
TEST(BoardCellTest,CreateFromStringEceptionBadEnd)
{
    EXPECT_ANY_THROW(BoardCell theCell=BoardCell("(3,4,),"));

}
//tests the creation from string checks for throwing exception on bad input
TEST(BoardCellTest,CreateFromStringEceptionBadMiddle)
{
    EXPECT_ANY_THROW(BoardCell theCell=BoardCell("(3,,,,4)"));

}
