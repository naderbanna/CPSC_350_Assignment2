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

      if(r == 0 && c == 0){
        cout << "0,0 top left" << endl;
        cout << r << "," << c << endl;

        //for 0,0 corner
        cout << curr_grid[7][7];
        cout << curr_grid[7][0];
        cout << curr_grid[7][1] << endl;

        cell_grid[0][0] = curr_grid[row-1][column-1];
        cell_grid[0][1] = curr_grid[row-1][c];
        cell_grid[0][2] = curr_grid[row-1][c+1];

        cell_grid[1][0] = curr_grid[r][column-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][column-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];

      }else if(r == row-1 && c == column-1){
        cout << r << "," << c << endl;

        //for 7,7 corner
        cell_grid[0][0] = curr_grid[r-1][c-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][0];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][0];

        cell_grid[2][0] = curr_grid[0][c-1];
        cell_grid[2][1] = curr_grid[0][c];
        cell_grid[2][2] = curr_grid[0][0];

      }else if(r == 0 && c == column-1){
        cout << r << "," << c << endl;

        //for 0,7 corner
        cell_grid[0][0] = curr_grid[row-1][c-1];
        cell_grid[0][1] = curr_grid[row-1][c];
        cell_grid[0][2] = curr_grid[row-1][0];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][0];

        cell_grid[2][0] = curr_grid[r+1][c-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][0];


      }else if(r == row-1 && c == 0){
        //for 7,0 corner
        cout << r << "," << c << endl;


        cell_grid[0][0] = curr_grid[r-1][column-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c+1];

        cell_grid[1][0] = curr_grid[r][column-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[0][column-1];
        cell_grid[2][1] = curr_grid[0][c];
        cell_grid[2][2] = curr_grid[0][c+1];


      }else if(r == 0){
        cout << "top row" << endl;
        cout << r << "," << c << endl;


        //for 0,x row
        cell_grid[0][0] = curr_grid[row-1][c-1];

        cell_grid[0][1] = curr_grid[row-1][c];
        cell_grid[0][2] = curr_grid[row-1][c+1];

        cell_grid[1][0] = curr_grid[r][c-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][c-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];

      }else if(c == 0){

        cout << "left column" << endl;
        cout << r << "," << c << endl;
        //for 0,x row
        cell_grid[0][0] = curr_grid[r-1][column-1];
        cell_grid[0][1] = curr_grid[r-1][c];
        cell_grid[0][2] = curr_grid[r-1][c+1];

        cell_grid[1][0] = curr_grid[r][column-1];
        cell_grid[1][1] = curr_grid[r][c];
        cell_grid[1][2] = curr_grid[r][c+1];

        cell_grid[2][0] = curr_grid[r+1][column-1];
        cell_grid[2][1] = curr_grid[r+1][c];
        cell_grid[2][2] = curr_grid[r+1][c+1];

      }else if(r == row-1){
        cout << "bottom row" << endl;
        cout << r << "," << c << endl;

          //for 0,x row
          cell_grid[0][0] = curr_grid[r-1][c-1];
          cell_grid[0][1] = curr_grid[r-1][c];
          cell_grid[0][2] = curr_grid[r-1][c+1];

          cell_grid[1][0] = curr_grid[r][c-1];
          cell_grid[1][1] = curr_grid[r][c];
          cell_grid[1][2] = curr_grid[r][c+1];

          cell_grid[2][0] = curr_grid[0][c-1];
          cell_grid[2][1] = curr_grid[0][c];
          cell_grid[2][2] = curr_grid[0][c+1];

      }else if(c == column-1){
        cout << "right column" << endl;
        cout << r << "," << c << endl;

          //for 0,x row
          cell_grid[0][0] = curr_grid[r-1][c-1];
          cell_grid[0][1] = curr_grid[r-1][c];
          cell_grid[0][2] = curr_grid[r-1][0];

          cell_grid[1][0] = curr_grid[r][c-1];
          cell_grid[1][1] = curr_grid[r][c];
          cell_grid[1][2] = curr_grid[r][0];

          cell_grid[2][0] = curr_grid[r+1][c-1];
          cell_grid[2][1] = curr_grid[r+1][c];
          cell_grid[2][2] = curr_grid[r+1][0];

        }else{
          cout << "in the middle" << endl;
          cout << r << "," << c << endl;

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

        cout << "cell grid" << endl;
        //cout << r << "," << c << endl;

        int p = 0;
        for(int r = 0; r < 3; r++){
          for(int c = 0; c < 3; c++){
              cout << cell_grid[r][c];
              p++;
              if(p == 3){
                cout << endl;
                p = 0;
              }
            }
          }

      neighbors = 0;
      if(cell_grid[0][0] == "X")
        neighbors++;
      if(cell_grid[0][1] == "X")
        neighbors++;
      if(cell_grid[0][2] == "X")
        neighbors++;
      if(cell_grid[1][0] == "X")
        neighbors++;
      if(cell_grid[1][1] == "X")
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

        cout << "neighbors: " << neighbors << endl;


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
  for(int i = 0; i < 2; i++)
    generateGrid();


  }
