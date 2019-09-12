// Author: Nathan Maynard
// Course: CSC 112 Section B (Fall 2019)
// Project: Project 1 - Battleship
// Due Date: 5:00pm, Sept. 12, 2019
// Purpose: Recreates the popular board game 'Battleship' using a 2-D Vector

#include <iostream>
#include <vector> // Enables vectors ~ Required for game-play
#include <ctime> // Enables time(); ~ Required to create 'truly' random numbers
using namespace std;

void PrintBoard(vector<vector<int>> b);

int main() {
    // The dimensions of the board (3x3)
    int row = 3;
    int col = 3;

    // The player's best score
    int bestScore = 99;

    // Variable used to tell if the game has ended
    int endGame = 0;

    // String used to end or continue game
    string userEnd;

    // Initialize Random Number Generator (Using the system time as a seed)
    srand(time(0));

    // Coordinates inputted by user
    int xUserCoord;
    int yUserCoord;

    // Set up board through vectors (without target)
    vector<int> vect(col, 0);
    vector<vector<int>> board(row, vect);

    // Place target on board (Represented by the number '1')
    board.at(rand() % 2).at(rand() % 2) = 1;

    while (endGame == 0) {
        // The player's score for a single round
        int roundScore = 0;

        // Variable used to tell if the round has ended
        int endRound = 0;
        while (endRound == 0) {
            // Print board with target visible (De-bugging purposes only, comment out when not in use)
            //for (int i = 0; i < board.size(); i++) {
            //    for (int j = 0; j < board.at(i).size(); j++) {
            //        cout <<board.at(i).at(j) << " ";
            //    }
            //    cout << endl;
            //}

            // Inquire User
            cout << "Please type the X and Y coordinate of where you think my battleship is" << endl;
            cin >> xUserCoord;
            cin >> yUserCoord;

            // Subtract 1 from coordinates to account for vector range
            xUserCoord = xUserCoord - 1;
            yUserCoord = yUserCoord - 1;

            // If player guesses out of range
            if (yUserCoord < 0 || yUserCoord > 2) {
                cout << "That guess is out of range! Try again!" << endl;
            }
            else if (xUserCoord < 0 || xUserCoord > 2) {
                cout << "That guess is out of range! Try again!" << endl;
            }

                // If player guesses correctly
            else if (board.at(xUserCoord).at(yUserCoord) == 1) {
                roundScore++;
                cout << "You sunk my battleship! (" << roundScore << " guess(es))" << endl;
                board.at(xUserCoord).at(yUserCoord) = 3;
                PrintBoard(board);
                if (roundScore < bestScore) {
                    bestScore = roundScore;
                    cout << "New best score! : " << bestScore << " guess(es)" << endl;
                }
                cout << "Would you like to play again? (y/n)" << endl;
                cin >> userEnd;
                if (userEnd == "n" || userEnd == "N") {
                    endGame = 1;
                    cout << "Final best score: " << bestScore << " guess(es)" << endl;
                }
                endRound = 1;
            }

                // If player misses
            else if (board.at(xUserCoord).at(yUserCoord) == 0) {
                roundScore++;
                cout << "You missed! Try again! (" << roundScore << " guess(es))" << endl;
                board.at(xUserCoord).at(yUserCoord) = 2;
                PrintBoard(board);
            }

                // If player guesses the same location
            else if (board.at(xUserCoord).at(yUserCoord) == 2) {
                cout << "You already hit that location! Try again!" << endl;
            }
        }

    }

    return 0;
}

// Function used to print board with markers
void PrintBoard (vector<vector<int>> b) {
    for (int i = 0; i < b.size(); i++) {
        cout << "|";
        for (int j = 0; j < b.at(i).size(); j++) {
            if (b.at(i).at(j) == 0 || b.at(i).at(j) == 1) { // Un-targeted Coordinate
                cout << " ";
            }
            else if (b.at(i).at(j) == 2) { // Missed Shot
                cout << "X";
            }
            else if (b.at(i).at(j) == 3) { // Hit
                cout << "O";
            }
            cout << "|";
        }
        cout << endl;
    }
}