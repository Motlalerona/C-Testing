#ifndef LIBPARK_H
#define LIBPARK_H
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <sstream>

using namespace std;
namespace ParkSpace
{
    typedef int* ParkSp;
    typedef int** ParkArea;

    const int SQ_Empty = 0;
    const int SQ_TREE = 1;
    const int SQ_BLUEGRASS = 2;

    const char EmptySpace = '.';
    const char Tree = '+';
    const char Bluegrass = '|';

    const int SUCCESS = 0;
    const int ERROR = 1;
    const int Err_Range = 2;

    const int MinSize = 4;

    int GetInt(string strInt);
    ParkArea MemAllo(int intRows, int intCols);
    void DeMemAllo(ParkArea &arrWorld,int intRows);
    void InitArray(ParkArea arrWorld, int intRows, int intCols);
    void PlaceTrees(ParkArea arrWorld,int intRows, int intCols,int intBluegrass, int intAttempts);
    void OutputWorld(ParkArea arrWorld,int intRows,int intCols);
    void RetryWorld(ParkArea arrWorld,int intRows,int intCols,int intAttempts);
}

#endif // LIBPARK_H
