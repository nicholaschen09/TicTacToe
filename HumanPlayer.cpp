// HumanPlayer.cpp
#include "HumanPlayer.h"
#include <iostream>

using namespace std;

// Constructor for the HumanPlayer class
HumanPlayer::HumanPlayer(char symbol, const string &name)
    : Player(symbol, name) {}

// Implementation of the makeMove function to allow a human player to make a
// move on the game board
void HumanPlayer::makeMove(char board[3][3]) { // Use 2D array here
  int row, col;
  cout << "Player " << getSymbol() << ", enter your move (row and column): ";
  cin >> row >> col;
  row--;
  col--;

  // Check if the move is valid
  if (isValidMove(board, row, col)) {
    board[row][col] = getSymbol();
  } else {
    cout << "Invalid move. Try again." << endl;
    makeMove(board);
  } // end else statement
} // end makeMove function

// Private helper function to check if a move is valid on the game board
bool HumanPlayer::isValidMove(char board[3][3], int row, int col) const {
  return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
} // End of isValidMove function
