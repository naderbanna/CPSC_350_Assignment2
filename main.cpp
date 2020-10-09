#include <iostream>
#include <fstream>
#include "Classicmode.h"
#include "Doughnutmode.h"
#include "Mirrormode.h"


using namespace std;

int main(int argc, char** argv){

  while(true){
  string gridType = "";
  cout << "Hello..." << endl << "What would you like to: " << endl << "1. Start with random Configuration" << endl << "2. Specify a flat-file configuration" << endl;
  getline(cin, gridType);
  if(gridType == "1"){
    Classicmode *test = new Classicmode();

  }if(gridType == "2"){
    string inputFile = "";
    string boundary = "";

    cout << "Enter a file name: ";
    getline(cin, inputFile);
    cout << "Enter the Boundary Mode: " << endl << "1. Classic" << endl << "2. Doughnut" << endl << "3. Mirror" << endl;
    getline(cin, boundary);
    if(boundary == "1"){
      // string pause = "";
      // cout << "Would you like the program to pause between generations?" << endl << "1. Yes" << endl << "2. No" << endl;
      // getline(cin, pause)
      // if()
      cout << "Classic Mode Output" << endl << "___________________" << endl;
      Classicmode *test = new Classicmode(inputFile);

    }if(boundary == "2"){
      cout << "Doughnut Mode Output" << endl << "___________________" << endl;
      Doughnutmode *test = new Doughnutmode(inputFile);

    }if(boundary == "3"){
      cout << "Doughnut Mode Output" << endl << "___________________" << endl;
      Mirrormode *test = new Mirrormode(inputFile);
    }
  }
}
  //test->simulate();
  return 0;
};
