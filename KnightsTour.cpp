/*
  Exercise 7.22 - C++ How to Program, 10th ed. by Deitel and Deitel
  Knight's Tour program
*/

#include <iostream>
#include <array>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printBoard();
void setStartingPosition(int row, int column);
bool isValidPosition(int row, int column);
void moveKnight();
bool isValidMove();
array<int, 2> getLowestMove(int row, int column);

const size_t SIZE = 8;
array<array<int, SIZE>, SIZE> board{};
array<array<int, SIZE>, SIZE> accessibilityRef
                                            {2, 3, 4, 4, 4, 4, 3, 2,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            2, 3, 4, 4, 4, 4, 3, 2};
                                            
array<array<int, SIZE>, SIZE> accessibility{2, 3, 4, 4, 4, 4, 3, 2,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            2, 3, 4, 4, 4, 4, 3, 2};
const array<int, SIZE> horizontal{2, 1, -1, -2, -2, -1, 1, 2};
const array<int, SIZE> vertical{-1, -2, -2, -1, 1, 2, 2, 1};

int currentRow = -1;
int currentColumn = -1;
int moveNumber = -1;

/*
Starting tasks I need to accomplish:
-move king around, check for not exceeding boundaries, check for valid move
*/

int main() {
  setStartingPosition(0,0);
  cout << currentRow << " " << currentColumn << endl;
  printBoard();
}

bool isValidPosition(int row, int column) {
  if(row < 8 && row >= 0 && column < 8 && column >= 0 && board[row][column] == 0){
    return true;
  }
  return false;
}

array<int, 2> getLowestMove(int row, int column) {
    int counter = 0;
    int lowestScore = 100;
    int tempScore = 100;
    array<int, 2> bestMove{};
    
    while(counter < 8) { //obtain lowest accessibility value
        if(isValidPosition(row + vertical[counter], column + horizontal[counter])){
            tempScore = accessibility[row + vertical[counter]][column + horizontal[counter]];
            if(tempScore < lowestScore){
                lowestScore = tempScore;
            }
        }
    }
    
    counter = 0;
    while(counter < 8){ //obtain coordinates for lowest value
        if(isValidPosition(row + vertical[counter], column + horizontal[counter]) && accessibility[row + vertical[counter]][column + horizontal[counter]] == lowestScore){
            bestMove[0] = row + vertical[counter];
            bestMove[1] = column + horizontal[counter];
        }
    }
    return bestMove;
}

void moveKnight() {
  
}

void setStartingPosition(int row, int column) {
  if(isValidPosition(row, column)){
    currentRow = row;
    currentColumn = column;
  }else{
    cout << "Invalid position. Ensure knight is placed within 8 x 8 board.\n";
  }
}

void printBoard() {
  for(size_t rows = 0; rows < SIZE; ++rows){
    for(size_t columns = 0; columns < SIZE; ++columns){
      cout << board[rows][columns] << ' ';
    }
    cout << endl;
  }
}
