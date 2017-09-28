//This program checks of the input of the user is a palindrome or not.
//Author: Kian Patton
//Date: 9/28/17
#include <iostream>
#include <cstring>

using namespace std;

int main() {

//declare the char arrays and initialize variables, and set last index to null
  char input[80];
  char clean[80];
  char backwards[80];
  input [80] = '\0';
  clean [80] = '\0';
  backwards [80] = '\0';
  char temp;
  int count = 0;
  
  //read in user's input
  cin.get(input, 80);

  //check for and omit non-alphabetical characters and read alphabetical characters to the "clean" array
  for (int i = 0; i < strlen(input); i++) {
    if (isalpha(input[i]) != 0) {
      input[i] = tolower(input[i]);
      clean[count] = input[i];
      count++;
    }
  }
  
  //make sure the cout doesn't print past the end of the array
  clean[count] = '\0';

  //print out the cleaned array
  cout << "forwards:" << clean << endl;

  //create a copy of the clean array and reverse the character order in the new "backwards" array
  strcpy(backwards, clean);
  for (int i = 0; i < (strlen(backwards)/2); i++) {
    temp = backwards[i];
    backwards[i] = backwards[strlen(backwards)-i-1];
    backwards[strlen(backwards)-i-1] = temp;
  }

  //print out the backwards array
  cout << "backwards:" << backwards << endl;

  //check if the "clean' and "backwards" array are the same
  //if yes: print "palindrome"
  //if no: print "not a palindrome"
  if (strcmp(clean, backwards) == 0) {
    cout << "Palindrome" << endl;
  }
  else if (strcmp(clean, backwards) != 0) {
    cout << "Not a Palindrome." << endl;
  }
  return 0;
}
