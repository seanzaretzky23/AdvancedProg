
#include "gtest/gtest.h"
#include "../src/HumanPlayer.h"

//testing the getColor method and the constructor
TEST(PlayerTest, getColorTest)
{
    Player* player = new HumanPlayer(Black);
    Player* player2 = new HumanPlayer(White);

    EXPECT_EQ(player->getColor(), Black);
    EXPECT_EQ(player2->getColor(), White);

    delete player;
    delete player2;
}

//testing the constructor in edge case
TEST(PlayerTest, ConstructorExcpetionTest) {
    EXPECT_THROW(HumanPlayer player(Blank), exception);
}