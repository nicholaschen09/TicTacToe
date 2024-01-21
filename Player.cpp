// Player.cpp
#include "Player.h"

// Constructor definition for the Player class
// Initializes the symbol and name of the player.
Player::Player(char symbol, const string &name) : symbol(symbol), name(name) {}

// Getter function to retrieve the symbol of the player
char Player::getSymbol() const { return symbol; } // End of getSymbol()

// Getter function to retrieve the name of the player
string Player::getName() const { return name; } // End of getName()
