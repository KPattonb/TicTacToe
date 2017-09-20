#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  //initialize variables
  bool stillPlaying = true;
  char playAgain;

  //while loop to check whether the user still wants to play
  while (stillPlaying == true) {

    srand(time(NULL));
    int randNumber = ((rand() %100) + 1);
    int guess = -1;
    int guessCount = 0;
    // char playAgain;

    cout << randNumber << endl;

    //user prompts
    cout << "New Game" << endl;
    cout << "Enter a number between 1 and 100." << endl;
    
    while (guess != randNumber) {
      cin >> guess;
      guessCount++;
      if (guess == randNumber) {
	cout << "You guessed:" << guess << endl;
       	cout << "You guessed the correct number!" << endl;
       	cout << "Number of guesses:" << guessCount << endl;
      }
      else if (guess < randNumber) {
	cout << "You guessed:" << guess << endl;
	cout << "You guessed incorrectly, Guess again." << endl;
	cout << "Hint: the number is bigger than your guess." << endl;
      }
      else if (guess > randNumber) {
	cout << "You guessd:" << guess << endl;
	cout << "You guessed incorrectly, Guess again." << endl;
	cout << "Hint: the number is smaller than your guess." << endl;
      }
    }
    cout << "Would you like to play again?" << endl;
    cout << "Please enter y for yes or n for no." << endl;
    cin >> playAgain;

    if (playAgain == 'y') {
      stillPlaying = true;
    }
    else {
      stillPlaying = false;
    }
  }
    return 0;
}
