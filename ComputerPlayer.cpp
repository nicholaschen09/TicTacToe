// ComputerPlayer.cpp
#include "ComputerPlayer.h"

// Constructor for the ComputerPlayer class
ComputerPlayer::ComputerPlayer(char symbol, const string &name)
    : Player(symbol, name) {}

// Implementation of the makeMove function to allow the computer player to make
// a move on the game board
void ComputerPlayer::makeMove(char gameBoard[3][3]) {
  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      if (gameBoard[row][col] == ' ') {
        gameBoard[row][col] = getSymbol();
        return; // Exit the function after making a move
      }         // end if
    }           // end for
  }             // end for
} // end makeMove
