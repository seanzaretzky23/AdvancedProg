cmake_minimum_required(VERSION 3.8)
project(AdvancedProg)

include_directories($g)
set(CMAKE_CXX_STANDARD 98)

#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
#


add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/Board.cpp src/Board.h src/BoardCell.cpp src/BoardCell.h src/ConsoleBoard.cpp src/ConsoleBoard.h src/Game.cpp src/Game.h src/Player.cpp src/Player.h src/GameLogic.cpp src/GameLogic.h src/SquareColorEnum.h src/StandardLogic.cpp src/StandardLogic.h src/HumanPlayer.cpp src/HumanPlayer.h src/AIPlayer.cpp src/AIPlayer.h src/RemotePlayer.cpp src/RemotePlayer.h  src/RemoteGame.h src/RemoteGame.cpp src/ReadFile.h src/ReadFile.cpp)

#
set(TEST_FILES tests/GameLogic-StandadLogic_Test.cpp tests/Board-ConsoleBoard_Test.cpp tests/Player-HumanPlayer_Test.cpp tests/BoardCell_Test.cpp tests/AIPlayer_Test.cpp)
#

#add_executable(AdvancedProg ${SOURCE_FILES})

#
add_executable(tests ${SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp)
add_executable(game ${SOURCE_FILES} src/main.cpp)

target_link_libraries(tests gtest gtest_main pthread)
target_link_libraries(game gtest gtest_main pthread)
add_test(test test)
#