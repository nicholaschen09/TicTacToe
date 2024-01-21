// ComputerPlayer.h
#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include <string>

using namespace std;

// Declaration of the ComputerPlayer class, which is derived from the Player
// class
class ComputerPlayer : public Player {
public:
  // Constructor to initialize a ComputerPlayer with a symbol and name
  ComputerPlayer(char symbol, const string &name);

  // Implementation of the makeMove function to allow the computer player to
  // make a move on the game board
  void makeMove(char gameBoard[3][3]);
};

#endif // COMPUTERPLAYER_H
