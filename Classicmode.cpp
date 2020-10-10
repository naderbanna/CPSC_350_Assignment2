#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Classicmode.h"

using namespace std;

Classicmode::Classicmode(){
  iFile = "";
  randomGrid();
}

Classicmode::Classicmode(string input){
  iFile = input;
  enterFileGrid();
}

Classicmode::~Classicmode(){
}
void Classicmode::randomGrid(){
  //prompt for width, length, and population density
  popD = 0;
  cout << "Enter the width of the grid: " << endl;
  cin >> row;
  cout << "Enter the length of the grid: " << endl;
  cin >> column;
  cout << "Enter the intitial population density(0 - 1): " << endl;
  cin >> popD;
  int totalCells = row*column;

  random_array[totalCells];
  //find new random number between 0-1 and compare with population density
  for(int i = 0; i < totalCells; i++){
    randPop = (float) rand()/RAND_MAX;
    if(randPop >= popD ){
      random_array[i] = "-";
    }if(randPop <= popD){
      random_array[i] = "X";
    }
  }
  //enter random_array into 2D curr_grid
  t = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      curr_grid[r][c] = random_array[t];
      t++;
    }
  }
  //print initial grid
  cout << "0" << endl;
  int p = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
        cout << curr_grid[r][c];
        p++;
        if(p == row){
          cout << endl;
          p = 0;
        }
      }
    }
  //print first generation (in order to comply with sample output format)
  cout << "generation 1" << endl;
  q = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
        cout << curr_grid[r][c];
        q++;
        if(q == row){
          cout << endl;
          q = 0;
        }
      }
    }
    //call simulate function
    simulate();
}
//read file and enter values into curr_array
void Classicmode::enterFileGrid(){
  ifstream inputGen;
  inputGen.open(iFile);
  string cellLine = "";
  //read file and assign to gridData (accounts for newline character)
  for(int i = 0; getline(inputGen, cellLine); ++i){
    if(cellLine.back() == '\r')
      cellLine.erase(cellLine.size() - 1);
      gridData += cellLine;
  }
  inputGen.close();
  //enter each char in gridData to file_array
  int i = 0;
  for(char c : gridData){
    file_array[i] = c;
    i++;
  }
  //get row and column values
  string Row = file_array[0];
  string Column = file_array[1];
  stringstream x(Row);
  stringstream y(Column);
  x >> row;
  y >> column;
  //enter values in file_array into 2D curr_array
  int t = 2;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      curr_grid[r][c] = file_array[t];
      t++;
    }
  }
  //print input file
  cout << "0" << endl;
  int p = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
        cout << curr_grid[r][c];
        p++;
        if(p == row){
          cout << endl;
          p = 0;
        }
      }
    }
    //print first generation (in order to comply with sample output format)
    cout << "generation 1" << endl;
    int q = 0;
    for(int r = 0; r < row; r++){
      for(int c = 0; c < column; c++){
          cout << curr_grid[r][c];
          q++;
          if(q == row){
            cout << endl;
            q = 0;
          }
        }
      }
    //call simulate function
    simulate();
}
void Classicmode::generateGrid(){
  //copy curr_grid into next_grid to evaluate
  worldCount++;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      next_grid[r][c] = curr_grid[r][c];
    }
  }
  //compare cells to its neighbors, neighbors outside of bounds are assumed "-"
  int neighbors = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      neighbors = 0;
      if(curr_grid[r-1][c-1] == "X")
        neighbors++;
      if(curr_grid[r-1][c] == "X")
        neighbors++;
      if(curr_grid[r-1][c+1] == "X")
        neighbors++;
      if(curr_grid[r][c-1] == "X")
        neighbors++;
      if(curr_grid[r][c+1] == "X")
        neighbors++;
      if(curr_grid[r+1][c-1] == "X")
        neighbors++;
      if(curr_grid[r+1][c] == "X")
        neighbors++;
      if(curr_grid[r+1][c+1] == "X")
        neighbors++;

      if(neighbors == 0)
        next_grid[r][c] = "-";
      if(neighbors == 1)
        next_grid[r][c] = "-";
      if(neighbors == 3)
        next_grid[r][c] = "X";
      if(neighbors >= 4)
        next_grid[r][c] = "-";
    }
  }
  //print newely generated generatoin grid
  cout << "generation " << worldCount << endl;
  int p = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
        cout << next_grid[r][c];
        p++;
        if(p == row){
          cout << endl;
          p = 0;
        }
      }
    }
    //set current grid to the newely generated grid
    for(int r = 0; r < row; r++){
      for(int c = 0; c < column; c++){
        curr_grid[r][c] = next_grid[r][c];
      }
    }
}

void Classicmode::simulate(){
  //prompt if user would like to pause at each generation
  int pause = 0;
  cout << "Would you like to pause between generations?" << endl << "1. Yes" << endl << "2. No" << endl;
  cin >> pause;
  //does not stop when grid is stable or continue when infinate
  //simulation is hard coded to 35 generations
  if(pause == 1){
    for(int i = 0; i < 34; i++){
      cin.ignore();
      generateGrid();
    }
  }if(pause == 2){
    for(int i = 0; i < 34; i++)
      generateGrid();
    }
  }
