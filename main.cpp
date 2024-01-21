// Include necessary header files
#include "Board.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Player.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

// Function to display the winning message
void displayWinMessage(Player *currentPlayer) {

  // Red color code for output
  const string red = "\033[31m";

  // Reset color code for output
  const string reset = "\033[0m";

  // Width for formatting player name
  const int nameWidth = 2;

  // Displays the winning message with formatting
  cout << red << "     " << setw(nameWidth) << left << currentPlayer->getName()
       << " wins!" << reset << endl;
  cout << endl;
} // End of displayWinMessage()

// Function to display winning animation
void displayWinAnimation() {

  // Red color code for output
  const string red = "\033[31m";

  // Reset color code for output
  const string reset = "\033[0m";

  // Displays the winning animation with formatting
  cout << red << "   Congratulations!" << endl;
  cout << endl;
  cout << "   \\o/    \\o/    \\o/   " << red << endl;
  cout << "   | |    | |    | |   " << red << endl;
  cout << "   / \\    / \\    / \\   " << red << endl;
  cout << "                        " << reset << endl;
} // End of displayWinAnimation()

// Function to print the instructions of the game
void printInstructions() {
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  cout << "Instructions:" << endl;
  cout << "- The game is played on a 3x3 grid." << endl;
  cout << "- Player 1 is X, Player 2 (or computer) is O." << endl;
  cout << "- Players take turns putting their marks in empty squares." << endl;
  cout << "- The first player to get 3 of their marks in a row (up, down, "
          "across, or diagonally) wins."
       << endl;
  cout << "- When all 9 squares are full, the game is over. If no player has 3 "
          "marks in a row, the game ends in a draw."
       << endl;
} // End of printInstructions()

// Function to start the game
void startGame() {

  // Variable to store the player's choice to play again
  char playAgain;
  do {

    // Variable to store selected game mode
    char gameMode;
    cout << endl;
    cout << "Choose game mode: 'p' for player vs player or 'c' for player vs "
            "computer: ";
    cin >> gameMode;

    // Error trap for uppercase input from the user
    gameMode = tolower(gameMode);

    // Handle invalid game mode selection
    while (gameMode != 'p' && gameMode != 'c') {
      cout
          << "Invalid choice. Please enter 'p' for player vs player or 'c' for "
             "player vs computer: ";
      cin >> gameMode;

      // Error trap for uppercase input from the user
      gameMode = tolower(gameMode);
    }

    // Added player name variables
    string player1Name, player2Name;

    cout << endl;
    cout << "Enter the name of Player 1 (X): ";
    cin >> player1Name;

    // Checks if the user selected a 2-player game and if yes, ask for the name
    // of the second player
    if (gameMode == 'p' || gameMode == 'P') {
      cout << "Enter the name of Player 2 (O): ";
      cin >> player2Name;
    }

    // Create a new Board object
    Board gameBoard;

    // Create new Player objects for Player 1 (X) and Player 2 (O)
    Player *playerX, *playerO;

    // Determine the game mode and create appropriate player objects
    if (gameMode == 'c' || gameMode == 'C') {
      // Check if Player 1's name is empty; if so, assign a default name
      if (player1Name == "") {
        player1Name = "Player 1";
      }

      // Create a new HumanPlayer object for Player X
      playerX = new HumanPlayer('X', player1Name);

      // Create a new ComputerPlayer object for Player O
      playerO = new ComputerPlayer('O', "Computer");
    } else {
      // Check if Player 1's name is empty; if so, assign a default name
      if (player1Name == "") {
        player1Name = "Player 1";
      }

      // Create a new HumanPlayer object for Player X
      playerX = new HumanPlayer('X', player1Name);

      // Check if Player 2's name is empty; if so, assign a default name
      if (player2Name == "") {
        player2Name = "Player 2";
      }

      // Create a new HumanPlayer object for Player O
      playerO = new HumanPlayer('O', player2Name);
    }

    // Create a new Player object for the current player (X)
    Player *currentPlayer;
    currentPlayer = playerX;

    // Variables to store game statistics
    int winsX = 0, winsO = 0, draws = 0;
    bool gameOver = false;

    cout << endl;
    cin.ignore();

    // Loop until the game is over
    do {

      // Display the game board
      gameBoard.reset();

      //
      currentPlayer = playerX;
      gameOver = false;

      int row, col;

      // Loop until the game is over
      while (!gameOver) {

        // Display the current player's turn
        gameBoard.print();
        cout << currentPlayer->getName()
             << "'s turn. Enter move (row col) or 'Q' to quit: ";

        // If player is playing
        if (gameMode != 'c' || currentPlayer == playerX) {
          string input;
          getline(cin, input);

          stringstream ss(input);
          ss >> row >> col;

          // checks if user wants to quit
          if (input == "Q" || input == "q") {
            cout << "Game ended by user." << endl;
            gameOver = true;
            break;
          } // End of if statement

          // error trap for invalid input
          if (ss.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid move. Row and column numbers should be between 1 "
                    "and 3. Try again."
                 << endl;
            continue;
          } // End of if statement

          // Convert row and column to 0-based index
          row--;
          col--;

          // Make a move on the game board at the specified row and column
          // with the current player's symbol (X or O).
          gameBoard.makeMove(row, col, currentPlayer->getSymbol());
        } // End of if statement

        else {
          // Make a move for the computer player if it's their turn and the game
          // is in 'computer' mode
          cout << "Computer is making a move." << endl;
          playerO->makeMove(gameBoard.board);
        } // End of else statement

        // Check if the game is over or it's a draw
        if (gameBoard.checkWin(currentPlayer->getSymbol())) {

          // Display the game board
          gameBoard.print();

          // Display the winning animation
          displayWinAnimation();

          // Display the winning message
          displayWinMessage(currentPlayer);
          gameOver = true;

          // Increment the win count for the current player
          currentPlayer == playerX ? winsX++ : winsO++;
        } // End of if statement

        // Check if the game is a draw
        if (gameBoard.isFull()) {
          gameBoard.print();
          cout << "It's a draw!" << endl;
          draws++;
          gameOver = true;
        } // End of if statement

        // Change the currentPlayer for the next round if the game is not over
        if (!gameOver)
          currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

      } // End while
      while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' &&
             playAgain != 'N') {
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        // Check if the user wants to exit
        if (playAgain == 'n' || playAgain == 'N') {
          cout << "Exiting the game. Thank you for playing!" << endl;
          break;
        } else if (playAgain == 'y' && playAgain == 'Y') {
          char gameMode;
          cout << endl;
          cout
              << "Choose game mode: 'p' for player vs player or 'c' for player "
                 "vs "
                 "computer: ";
          cin >> gameMode;

          // Error trap for uppercase input from the user
          gameMode = tolower(gameMode);
          while (gameMode != 'p' && gameMode != 'c') {
            cout << "Invalid choice. Please enter 'p' for player vs player or "
                    "'c' "
                    "for "
                    "player vs computer: ";
            cin >> gameMode;

            // Error trap for uppercase input from the user
            gameMode = tolower(gameMode);
          } // End of while loop
        }
        cout << "Invalid input. Please enter 'y' or 'n': ";
      }

      // output for stats
      cout << "\nStatistics:\n";
      cout << playerX->getName() << " - Wins: " << winsX
           << ", Losses: " << winsO << "\n";
      cout << playerO->getName() << " - Wins: " << winsO
           << ", Losses: " << winsX << "\n";
      cout << "Draws: " << draws << "\n";

      // Continue the game loop if the player chooses to play again (y or Y).
    } while (playAgain == 'y' || playAgain == 'Y');

    //// Deallocate memory by deleting player objects to prevent memory leaks.
    delete playerX;
    delete playerO;

    // Repeat the game from the beginning if the player chooses to play another
    // round.
  } while (playAgain == 'y' || playAgain == 'Y');

} // End of startGame()

int main() {

  // store user choice for menu
  int choice;

  // loop until user chooses to quit
  while (true) {

    // red colour code for output
    const string red = "\033[31m";

    // reset colour code for output
    const string reset = "\033[0m";

    // output for user to select choice from menu
    cout << red << "Welcome to Tic-Tac-Toe!" << reset << endl;
    cout << endl;
    cout << "Select an option from the following:" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. View Instructions" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Clear any remaining characters in the input buffer, up to the next
    // newline character ('\n').
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // switch for different cases depending on user input
    switch (choice) {
    case 1:
      startGame();
      break;
    case 2:
      printInstructions();
      cout << endl;
      break;
    case 3:
      cout << "Exiting game." << endl;
      return 0;
    default:
      cout << "Invalid choice. Please try again.\n";
      break;

    } // end of switch

  } // end of while loop

  return 0;

} // end of main()
// Check if the game is over or it's a draw
