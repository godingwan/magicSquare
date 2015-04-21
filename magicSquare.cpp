/*
  Author: Joshua Lee
  Date: 04/21/2015
  Description: Creates a randomly filled 4x4 matrix and then computes if it is a magic square or not
  Algorithm:
    1) Create a 4x4 2D matrix
    2) For each square, get a random value from 1-16 and fill the square in if the number has not been used
    3) Display the array
    4) Check if it is a magic square
    5) Loop until a magic square is found
*/

#include <iostream>
#include <ctime>

using namespace std;

void initializeArr(int s[][4], int size = 4){
  // Generate random number
  srand(time(NULL));

  // Iterate through the 2D array
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      s[i][j] = rand() % 16 + 1;
    }
  }
}

void displayArr(int s[][4], int size = 4){
  // Iterate through the 2D array and display the element
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << s[i][j] << "\t";
    }
    cout << endl;
  }
}

int main(){
  // Create the 2D 4x4 array
  int square [4][4];

  // Function call to fill in the array
  initializeArr(square);
  displayArr(square);

  return 0;
}