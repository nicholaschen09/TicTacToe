#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

// Player class declaration
class Player {
public:
  // Constructor to initialize the player with a symbol and name
  Player(char symbol, const string &name);

  // Getter function to retrieve the symbol of the player
  char getSymbol() const;

  // Virtual destructor to allow for proper cleanup in derived classes
  virtual ~Player() {}

  // Pure virtual function to make a move on the game board (to be implemented
  // in derived classes)
  virtual void makeMove(char board[3][3]) = 0;

  // Getter function to retrieve the name of the player
  string getName() const;

private:
  char symbol; // Symbol representing the player (X or O)
  string name; // Name of the player
};

#endif // PLAYER_H
