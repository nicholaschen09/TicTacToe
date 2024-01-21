// HumanPlayer.h
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

// Declaration of the HumanPlayer class, which is derived from the Player class
class HumanPlayer : public Player {
public:
  // Constructor to initialize a HumanPlayer with a symbol and name
  HumanPlayer(char symbol, const string &name);

  // Implementation of the makeMove function to allow a human player to make a
  // move on the game board
  void makeMove(char board[3][3]);

private:
  // Private helper function to check if a move is valid on the game board
  bool isValidMove(char board[3][3], int row, int col) const;
};

#endif // HUMANPLAYER_H
