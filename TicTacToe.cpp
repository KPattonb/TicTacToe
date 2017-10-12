//This program is a two person game of tic tac toe in the console
//Author: Kian Patton
//Date: 10/12/17
#include <iostream>
#include <string>

using namespace std;

//declare variables and 2-D array for board
char Board[3][3];
string input;
char row;
int col;
int irow;
char turn = 'X';
int xwins = 0;
int owins = 0;
bool playing = true;
char play;

//function to print the playing board out to the console
void printBoard() {
  
  cout << "\t1 \t2 \t3" << endl;
  cout << "a\t" << Board[0][0] << "\t" << Board[1][0] << "\t" << Board[2][0] << endl;
  cout << "b\t" << Board[0][1] << "\t" << Board[1][1] << "\t" << Board[2][1] << endl;
  cout << "c\t" << Board[0][2] << "\t" << Board[1][2] << "\t" << Board[2][2] << endl;

}

//function that asks player X or O to input a coordinate on the grid and reads in the coordinates
void chooseSpot() {
  cout << "Player " << turn << " enter a row and column (row column)." << endl;
  cout << "Ex) a1" << endl;

  //read in the user's row
  cin >> row;

  //if the user's input is not valid then have them re-enter their row
  while (row != 'a' && row != 'b' && row != 'c' && row != 'A' && row != 'B' && row != 'C') {
    cout << "Please enter a valid row. Ex) b" << endl;
    cin >> row;
  }
  
  //set the corrosponding row integer for the Board position
  if (row == 'a' || row == 'A') {
    irow = 1;
  }
  if (row == 'b' || row == 'B') {
    irow = 2;
  }
  if (row == 'c' || row == 'C') {
    irow = 3;
  }

  //read in user's column
  cin >> col;

  //if user's input is not valid then have them re-enter their column
  while (col < 1 || col > 3) {
    cout << "Please enter a valid column. Ex) 2" << endl;
    cin >> col;
  }
}

//function to check whether or not the spot chosen is already taken. If it is have them re-choose their spot
void checkValid() {
  while (Board[col - 1][irow - 1] != 0) {
    cout << "That spot is already taken. Please choose a different one." << endl;
    chooseSpot();
  }
}

//function to change the turn from X to O and vice versa
void setTurn() {
  if (turn == 'X') {
    turn = 'O';
  }
  else if (turn == 'O') {
    turn = 'X';
  }
}

//function that sets each board position back to null
void clearBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Board[i][j] = '\0';
    }
  }
}

//function that checks each possible winning combination
bool checkWin(char turn) {
  if (Board[0][0] == turn && Board[0][1] == turn && Board[0][2] == turn) {
    return true;
  }
  else if (Board[1][0] == turn && Board[1][1] == turn && Board[1][2] == turn) {
    return true;
  }
  else if (Board[2][0] == turn && Board[2][1] == turn && Board[2][2] == turn) {
    return true;
  }
  else if (Board[0][0] == turn && Board[1][0] == turn && Board[2][0] == turn) {
    return true;
  }
  else if (Board[0][1] == turn && Board[1][1] == turn && Board[2][1] == turn) {
    return true;
  }
  else if (Board[0][2] == turn && Board[1][2] == turn && Board[2][2] == turn) {
    return true;
  }
  else if (Board[0][0] == turn && Board[1][1] == turn && Board[2][2] == turn) {
    return true;
  }
  else if (Board[2][0] == turn && Board[1][1] == turn && Board[0][2] == turn) {
    return true;
  }
  return false;
}

//function that checks whether their is still an open spot on the board left
bool checkTie() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (Board[i][j] == '\0') {
	return false;
      }
    }
  }
  return true;
}

//main function that loops the functions in order while 'playing' is true
int main() {

  cout << "2 Player Tic Tac Toe." << endl;
  printBoard();
  while (playing == true) {
    chooseSpot();
    checkValid();
    Board[col - 1][irow - 1] = turn;
    printBoard();
    checkWin(turn);
    //winning procedures
    if (checkWin(turn) == true) {
      cout << turn << " wins!" << endl;
      if (turn == 'X') {
	xwins++;
	cout << "X has won " << xwins << " times." << endl;
	cout << "O has won " << owins << " times." << endl;
      }
      else if (turn == 'O') {
	owins++;
	cout << "O has won " << owins << " times." << endl;
	cout << "X has won " << xwins << " times." << endl;
      }
      cout << "Would you like to play again? (y or n)" << endl;
      cin >> play;
      if (play == 'y' || play == 'Y') {
	playing = true;
	clearBoard();
	turn = 'X';
      }
      else if (play == 'n' || play == 'N') {
	playing = false;
      }
    }
    //tie procedures
    checkTie();
    if (checkTie() == true) {
      cout << "Nobody wins. :(" << endl;
      cout << "O has won " << owins << " times." << endl;
      cout << "X has won " << xwins << " times." << endl;
      cout << "Would you like to play again? (y or n)" << endl;
      cin >> play;
      if (play == 'y' || play == 'Y') {
	playing = true;
	clearBoard();
      }
      else if (play == 'n' || play == 'N') {
	playing = false;
      }
    }
    setTurn();
  }
  
  return 0;
}
