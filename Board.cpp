// Board.cpp
#include "Board.h"
#include <iostream>

using namespace std;

// Constructor to initialize the game board with empty spaces
Board::Board() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      board[i][j] = ' ';
    } // end for
  }   // end for
} // end Board

// Function to print the current state of the game board
void Board::print() const {
  const string red = "\033[31m";
  const string reset = "\033[0m";
  cout << endl;
  // Print column headers
  cout << red << "    1   2   3" << reset << endl;
  cout << endl;
  for (int row = 0; row < 3; ++row) {
    // Print row header
    cout << red << " " << (row + 1) << "  " << reset;

    for (int col = 0; col < 3; ++col) {
      cout << board[row][col];
      if (col < 2)
        cout << " | ";
    } // end for

    cout << endl;

    if (row < 2) {
      cout << "   -----------" << endl;
    } // end if
  }   // end for
  cout << endl;
} // end print

// Function to check if the game board is full
bool Board::isFull() const {
  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      if (board[row][col] == ' ') {
        return false;
      } // end if
    }   // end for
  }     // end for
  return true;
} // end isFull

// Function to check if a player with the specified symbol has won the game
bool Board::checkWin(char symbol) const {
  for (int i = 0; i < 3; ++i) {
    if ((board[i][0] == symbol && board[i][1] == symbol &&
         board[i][2] == symbol) ||
        (board[0][i] == symbol && board[1][i] == symbol &&
         board[2][i] == symbol)) {
      return true;
    } // end if
  }   // end for
  if ((board[0][0] == symbol && board[1][1] == symbol &&
       board[2][2] == symbol) ||
      (board[0][2] == symbol && board[1][1] == symbol &&
       board[2][0] == symbol)) {
    return true;
  } // end if
  return false;
} // end checkWin

// Function to reset the game board to its initial state with empty spaces
void Board::reset() {
  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      board[row][col] = ' ';
    } // end for
  }   // end for
} // end reset

// Function to get the character at a specific row and column on the game board
char Board::getAt(int row, int col) const {
  return board[row][col];
} // end getAt

// Function to retrieve a pointer to the game board (2D array)
char (*Board::getBoard())[3] { return board; } // end getBoard

// Function to make a move on the game board at the specified row and column
// with the given player symbol
void Board::makeMove(int row, int col, char player) {
  if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
    board[row][col] = player;
  } // end if
} // end makeMove
