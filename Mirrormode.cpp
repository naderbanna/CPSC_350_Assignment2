#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Mirrormode.h"

using namespace std;
//constructor
Mirrormode::Mirrormode(){
  iFile = "";
  randomGrid();
}
//overloaded constructor
Mirrormode::Mirrormode(string input){
  iFile = input;
  enterFileGrid();
}
//destructor
Mirrormode::~Mirrormode(){
}

void Mirrormode::randomGrid(){
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
void Mirrormode::enterFileGrid(){
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

void Mirrormode::generateGrid(){
  //copy curr_grid into next_grid to evaluate
  worldCount++;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      next_grid[r][c] = curr_grid[r][c];
    }
  }
  //catch and adjust 4 corners and 4 sides of grid, compute other cells as well
  int neighbors = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      //create cell_grid 2D array for each cell and evaluate neighbors
      if(r == 0 && c == 0){
        // cout << "top left" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r][c];
        cell_grid[0][1] = curr_grid[r][c];
        cell_grid[0][2] = curr_grid[row][c+1];

        cell_grid[1][0] = curr_grid[r][c];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][column-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];

      }else if(r == row-1 && c == column-1){
        // cout << "bottom right" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r-1][c-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][0];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c];

        cell_grid[2][0] = curr_grid[row-1][c-1];
        cell_grid[2][1] = curr_grid[r][c];
        cell_grid[2][2] = curr_grid[r][c];

      }else if(r == 0 && c == column-1){
        // cout << "top right" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r][c-1];
        cell_grid[0][1] = curr_grid[r][c];
        cell_grid[0][2] = curr_grid[r][c];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c];

        cell_grid[2][0] = curr_grid[r+1][c-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c];
      }else if(r == row-1 && c == 0){
        // cout << "bottom left" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r-1][c];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c+1];

        cell_grid[1][0] = curr_grid[r][c];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r][c];
        cell_grid[2][1] = curr_grid[r][c];
        cell_grid[2][2] = curr_grid[r][c+1];
      }else if(r == 0){
        // cout << "top row" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r][c-1];
        cell_grid[0][1] = curr_grid[r][c];
        cell_grid[0][2] = curr_grid[r][c+1];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][c-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];
      }else if(c == 0){
        // cout << "left column" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r-1][c];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c+1];

        cell_grid[1][0] = curr_grid[r][c];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][c];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];
      }else if(r == row-1){
        // cout << "bottom row" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r-1][c-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c+1];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r][c-1];
        cell_grid[2][1] = curr_grid[r][c];
        cell_grid[2][2] = curr_grid[r][c+1];
      }else if(c == column-1){
        // cout << "right column" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r-1][c-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c];

        cell_grid[2][0] = curr_grid[r+1][c-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c];
      }else{
        // cout << "in the middle" << endl;
        // cout << r << "," << c << endl;
        cell_grid[0][0] = curr_grid[r-1][c-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c+1];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][c-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];
        }
        //test for each 2D cell_array for each cell and its neighbors
        // cout << "cell grid" << endl;
        // cout << r << "," << c << endl;
        //
        // int p = 0;
        // for(int r = 0; r < 3; r++){
        //   for(int c = 0; c < 3; c++){
        //       cout << cell_grid[r][c];
        //       p++;
        //       if(p == 3){
        //         cout << endl;
        //         p = 0;
        //       }
        //     }
        //   }
      neighbors = 0;
      if(cell_grid[0][0] == "X")
        neighbors++;
      if(cell_grid[0][1] == "X")
        neighbors++;
      if(cell_grid[0][2] == "X")
        neighbors++;
      if(cell_grid[1][0] == "X")
        neighbors++;
      if(cell_grid[1][2] == "X")
        neighbors++;
      if(cell_grid[2][0] =="X")
        neighbors++;
      if(cell_grid[2][1] == "X")
        neighbors++;
      if(cell_grid[2][2] == "X")
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
    //sett current grid to the newely generated grid
    for(int r = 0; r < row; r++){
      for(int c = 0; c < column; c++){
        curr_grid[r][c] = next_grid[r][c];
      }
    }
}
void Mirrormode::simulate(){
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
