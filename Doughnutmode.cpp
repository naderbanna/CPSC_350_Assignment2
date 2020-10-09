#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Doughnutmode.h"

using namespace std;

Doughnutmode::Doughnutmode(){
  iFile = "";


  randomGrid();

}

Doughnutmode::Doughnutmode(string input){
  iFile = input;

  enterFileGrid();
}

Doughnutmode::~Doughnutmode(){

}

void Doughnutmode::randomGrid(){


}

void Doughnutmode::enterFileGrid(){
  ifstream inputGen;
  inputGen.open(iFile);
  string cellLine = "";

  for(int i = 0; getline(inputGen, cellLine); ++i){
    if(cellLine.back() == '\r')
      cellLine.erase(cellLine.size() - 1);
      gridData += cellLine;
  }
  inputGen.close();

  int i = 0;
  for(char c : gridData){
    file_array[i] = c;
    i++;
  }
  string Row = file_array[0];
  string Column = file_array[1];

  stringstream x(Row);
  stringstream y(Column);
  x >> row;
  y >> column;
  //string curr_grid[row][column];
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
    //print first generation grid
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
    simulate();
}

void Doughnutmode::generateGrid(){

  //not working with corrent rules
  worldCount++;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      next_grid[r][c] = curr_grid[r][c];
    }
  }
  int neighbors = 0;
  for(int r = 0; r < row; r++){
    for(int c = 0; c < column; c++){
      neighbors = 0;
      if(curr_grid[r+1][c-1] == "X")
        neighbors++;
      if(curr_grid[r][c-1] == "X")
        neighbors++;
      if(curr_grid[r-1][c-1] == "X")
        neighbors++;
      if(curr_grid[r-1][c] == "X")
        neighbors++;
      if(curr_grid[r-1][c+1] == "X")
        neighbors++;
      if(curr_grid[r][c+1] == "X")
        neighbors++;
      if(curr_grid[r+1][c+1] == "X")
        neighbors++;
      if(curr_grid[r+1][c] == "X")
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

void Doughnutmode::simulate(){

  //add stop & empty grid
  //add pause till enter
  for(int i = 0; i < 35; i++)
    generateGrid();


  }
