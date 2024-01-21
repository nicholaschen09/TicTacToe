// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include <stack>
#include <vector>

using namespace std;

// Structure to represent a move on the game board
struct Move {
  int row, col;
  char player;
};

// Declaration of the Board class
class Board {
public:
  // Constructor to initialize the game board
  Board();

  // Function to print the current state of the game board
  void print() const;

  // Function to check if the game board is full
  bool isFull() const;

  // Function to check if a player with the specified symbol has won the game
  bool checkWin(char symbol) const;

  // Function to reset the game board to its initial state
  void reset();

  // Function to get the character at a specific row and column on the game
  // board
  char getAt(int row, int col) const;

  // Function to retrieve a pointer to the game board (2D array)
  char (*getBoard())[3];

  // Function to make a move on the game board at the specified row and column
  // with the given symbol
  void makeMove(int row, int col, char symbol);

  // Function to display the game board
  void displayBoard() const;

  // 2D array representing the game board
  char board[3][3];

private:
};

#endif // BOARD_H
