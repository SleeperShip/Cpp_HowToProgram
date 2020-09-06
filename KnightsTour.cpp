#include <iostream>
#include <array>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printBoard();
void updateAccessBoard(int row, int column);
void setStartingPosition(int row, int column);
bool isValidPosition(int row, int column);
void moveKnight();
bool isValidMove();
bool findValue(int val);
bool tourComplete(int row, int column);
bool validMovesRemaining(int row, int column);
bool tourComplete(int row, int column);

array<int, 2> getLowestMove(int row, int column);

const size_t SIZE = 8;
array<array<int, SIZE>, SIZE> board{};                                            
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
int moveNumber = 0;

int main() {
  setStartingPosition(0,0);
  accessibility[currentRow][currentColumn] == 100;
  cout << "(starting)Current Row: "<< currentRow << endl; 
  cout << "(starting)Current Column: " << currentColumn << endl;
  moveKnight();
}

bool isValidPosition(int row, int column) {
  if(row < 8 && row >= 0 && column < 8 && column >= 0 && board[row][column] == 0){
    return true;
  }
  return false;
}

array<int, 2> getLowestMove(int row, int column) { //returns (row,column) with next best move/lowest accessibility score
    int counter = 0;
    int lowestScore = 100;
    int tempScore = 100;
    array<int, 2> bestMove{};
    int tempRow = 0;
    int tempColumn = 0;
    
    while(counter < 8) { //obtain lowest accessibility value
        tempRow = row + vertical[counter];
        tempColumn = column + horizontal[counter];
            if(isValidPosition(tempRow, tempColumn) && accessibility[tempRow][tempColumn] != 100){
                tempScore = accessibility[tempRow][tempColumn];
                if(tempScore < lowestScore){
                    lowestScore = tempScore;
                }
            }
        tempRow = 0;
        tempColumn = 0;
        counter++;
    }
    
    counter = 0;
    tempRow = 0;
    tempColumn = 0;
    
    while(counter < 8){ //obtain coordinates for lowest value
        tempRow = row + vertical[counter];
        tempColumn = column + horizontal[counter];
        if(isValidPosition(tempRow, tempColumn) && accessibility[tempRow][tempColumn] == lowestScore){
            bestMove[0] = tempRow;
            bestMove[1] = tempColumn;
        }
        tempRow = 0;
        tempColumn = 0;
        counter++;
    }
    return bestMove;
}

void moveKnight() {
  int counter = 0;
  array<int, 2> nextMove;
  
  while(counter < 64){
      nextMove = getLowestMove(currentRow, currentColumn);
      currentRow = nextMove[0];
      currentColumn = nextMove[1];
      moveNumber++;
      board[currentRow][currentColumn] = moveNumber;
      updateAccessBoard(currentRow, currentColumn);
      counter++;
      cout << moveNumber << endl;
  }
  printBoard();
}

void updateAccessBoard(int row, int column) {
    int tempRow = 0;
    int tempColumn = 0;
    int counter = 0;
    while(counter < 8){
        tempRow = row + vertical[counter];
        tempColumn = column + horizontal[counter];
        if(isValidPosition(tempRow, tempColumn) && accessibility[tempRow][tempColumn] != 100){
            --accessibility[tempRow][tempColumn];
        }
        tempRow = 0;
        tempColumn = 0;
        counter++;
    }
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
