#include "libPark.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace ParkSpace;

int main(int argc, char** argv)
{
  if(argc != 5){
    cerr << "Run " << argv[0] << "ROWS, COLS, TREES, BLUEGRASS_SQUARES" << endl;
    exit(ERROR);
  }
    int intAttempts = 10;
    int intRows = GetInt(argv[1]);
    int intCols = GetInt(argv[2]);
    int intTrees = GetInt(argv[3]);
    int intBluegrass = GetInt(argv[4]);

  //Range Checking
  if(intRows < MinSize || intCols < MinSize || intTrees < 0 || intBluegrass < 0){
    cerr << "Please make sure the arguements are positive or at least minimum size of 4. " << endl;
    exit(Err_Range);
  }

  srand(intTrees);

  //Declare array & Initialize
    ParkArea arrWorld = MemAllo(intRows, intCols);
    InitArray(arrWorld, intRows, intCols);
    PlaceTrees(arrWorld,intRows,intCols,intBluegrass,intAttempts);

    bool blnContinue = true;
    char chInput = '\0';
    do{

    system("cls");
    OutputWorld(arrWorld,intRows,intCols);

    //Menu System
    cout << "1. Rearrange Trees" << endl
        <<"2. Rearrange Bluegrass" << endl
        <<"3. Quit" << endl
    cin >> chInput;
    //Handling Menu System
    switch(chInput){
case: '1'
    break;
case: '2'
    break;
case: '3'
    break;
default:
    cerr << ""<< endl;
    }
    }while(blnContinue);

    return SUCCESS;
}
