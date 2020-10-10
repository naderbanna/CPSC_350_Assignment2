#include <iostream>
#include <fstream>
#include "Classicmode.h"
#include "Doughnutmode.h"
#include "Mirrormode.h"


using namespace std;

int main(int argc, char** argv){
  bool program = true;
  while(program){
    cout << "Hello..." << endl << "What would you like to: " << endl << "1. Start with random Configuration" << endl << "2. Specify a flat-file configuration" << endl << "3. End Program" << endl;
    string gridType = "";
    cin >> gridType;
    //getline(cin, gridType);

    if(gridType == "1"){
      cout << "random grid" << endl;
      string boundary = "";
      cout << "Enter the Boundary Mode: " << endl << "1. Classic" << endl << "2. Doughnut" << endl << "3. Mirror" << endl;
      cin >> boundary;
      if(boundary == "1"){

        cout << "Classic Mode Output" << endl << "___________________" << endl;
        Classicmode *test = new Classicmode();

      }if(boundary == "2"){
        cout << "Doughnut Mode Output" << endl << "___________________" << endl;
        Doughnutmode *test = new Doughnutmode();

      }if(boundary == "3"){
        cout << "Mirror Mode Output" << endl << "___________________" << endl;
        Mirrormode *test = new Mirrormode();
      }

      }if(gridType == "2"){
        string inputFile = "";
        string boundary = "";

        cout << "Enter a file name: " << endl;
        cin >> inputFile;
        cout << "Enter the Boundary Mode: " << endl << "1. Classic" << endl << "2. Doughnut" << endl << "3. Mirror" << endl;
        cin >> boundary;
        if(boundary == "1"){
          cout << "Classic Mode Output" << endl << "___________________" << endl;
          Classicmode *test = new Classicmode(inputFile);

        }if(boundary == "2"){
          cout << "Doughnut Mode Output" << endl << "___________________" << endl;
          Doughnutmode *test = new Doughnutmode(inputFile);

        }if(boundary == "3"){
          cout << "Mirror Mode Output" << endl << "___________________" << endl;
          Mirrormode *test = new Mirrormode(inputFile);
        }
      }if(gridType == "3"){
        break;
      }

}
  return 0;
};
