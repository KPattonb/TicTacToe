#include <iostream>
#include <string>

using namespace std;

char Board[3][3];
string input;
char row;
int col;
int irow;
char turn = 'X';
int xwins = 0;
int owins = 0;

void printBoard() {

  Board[0][0] = 'X';
  cout << "\t1 \t2 \t3" << endl;
  cout << "a\t" << Board[0][0] << "\t" << Board[1][0] << "\t" << Board[2][0] << endl;
  cout << "b\t" << Board[0][1] << "\t" << Board[1][1] << "\t" << Board[2][1] << endl;
  cout << "c\t" << Board[0][2] << "\t" << Board[1][2] << "\t" << Board[2][2] << endl;
  
}

void chooseSpot() {
  cout << "Player " << turn << " enter a row first (a, b, or c)." << endl;
  cin >> row;
  while (row != 'a' && row != 'b' && row != 'c' && row != 'A' && row != 'B' && row != 'C') {
    cout << "Please enter a valid row. Ex) b" << endl;
    cin >> row;
  }
  if (row == 'a' || row == 'A') {
    irow = 1;
  }
  if (row == 'b' || row == 'B') {
    irow = 2;
  }
  if (row == 'c' || row == 'C') {
    irow = 3;
  }
  cout << "Player " << turn << " enter a column (1, 2, or 3)." << endl;
  cin >> col;
  while (col < 1 || col > 3) {
    cout << "Please enter a valid column. Ex) 2" << endl;
    cin >> col;
  }
  cout << row << col << endl;
}

void checkValid() {
  while (Board[irow - 1][col - 1] != 0) {
    cout << "That spot is already taken. Please choose a different one." << endl;
    chooseSpot();
  }
  Board[irow - 1][col - 1] = turn;
  if (turn == 'X') {
    turn = 'O';
    cout << turn << endl;
  }
  else if (turn == 'O') {
    turn = 'X';
    cout << turn << endl;
  }
  
}

int main() {

  printBoard();
  chooseSpot();
  checkValid();
  
  return 0;
}
