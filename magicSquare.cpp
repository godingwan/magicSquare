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

bool checkUnique(int s[][5], int num){
  for (int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if (s[i][j] == 0)
        return true;
      else if (s[i][j] == num)
        return false;
    }
  }
  return true;
}

void initializeArr(int s[][5], int size = 4){
  // Generate random number
  srand(time(NULL));
  bool uniq = false;
  int num;

  // Iterate through the 2D array
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      // Continue getting a number until it is unique
      while (uniq == false){
        num = rand() % 16 + 1;
        uniq = checkUnique(s, num);
      }
      s[i][j] = num;
      uniq = false;
    }
  }
}

void displayArr(int s[][5], int size = 4){
  // Iterate through the 2D array and display the element
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << s[i][j] << "\t";
    }
    cout << endl;
  }
}

bool magicSquare(int s[][5], int size = 4){
  // Value to store diagonals
  int d1=0, d2=0;

  // Calulating the sum of each row and assigning it to subscript 4
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      s[i][4] += s[i][j];
    }
  }

  // Calculating the sum of each col and assigning to to subscript 4
  for (int j = 0; j < 4; j++){
    for (int i = 0; i < 4; i++){
      s[4][j] += s[i][j];
    }
  }

  // Calculating the sum of the diagonal
  for (int i = 0, j = 0; i < 4; i++, j++){
    d1 += s[i][j];
  }
  for (int i = 3, j = 0; j < 4; i--, j++){
    d2 += s[i][j];
  }
  
  // See if the sum of everything are equal
  if (s[0][4] == d1 && s[1][4] == d1 && s[2][4] == d1 && s[3][4] == d1 && s[4][0] == d1 && s[4][1] == d1 &&
        s[4][2] == d1 && s[4][3] == d1 && d1 == d2)
    return true;
  else
    return false;
}

void zeroArr(int s[][5], int size = 4){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      s[i][j] = 0;
    }
  }
}

int main(){
  // Create the 2D 5x5 array
  int square [5][5] = {0};
  bool mSq = false;

  // Continue creating a new matrix until a magic square is found
  while (mSq == false){
    // Function call to fill in the array
    initializeArr(square);
    displayArr(square);
    // Function call to determine if it is a magic square
    mSq = magicSquare(square);
    if (mSq == true)
      cout << "Magic Square!" << endl;
    else{
      cout << "Not a Magic Square!" << endl;
      // Zero out the array
      zeroArr(square);
    }
  }
  
  return 0;
}
