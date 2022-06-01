#include "libPark.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;
namespace ParkSpace
{
    int GetRand(int intLower, int intUpper){
    assert(intLower < intUpper);
    int intRange = intUpper - intLower + 1;
    return rand()%intRange + intLower;
    }

    int GetInt(string strInt)
    {
        int intNum = 0;
        stringstream V {strInt};
        V >> intNum;
        if(V.fail())
        {
            cerr << "Error in converting String to Integer! " << endl;
            exit(ERROR);
        }
        return intNum;
    }
     ParkArea MemAllo(int intRows, int intCols){

         ParkArea arrNums;
         arrNums = new ParkSp[intRows];
         for( int r = 0; r < intRows; r++){
            arrNums[r] = new int[intCols];
         }

         return arrNums;
     }
         void InitArray(ParkArea arrWorld, int intRows, int intCols){
        for(int r = 0; r < intRows; r++)
        {
            for (int c = 0; c < intCols; c++)
            {
                arrWorld[r][c] = SQ_Empty;
            }
        }
    }

    bool IsInWorld(int intRows,int intCols,int intRow,int intCol){
    return(intRow >=  0 && intRow < intRows && intCol >= 0 && intCol < intCols);
    }

    bool IsEmptyAround(ParkArea arrWorld, int intRows, int intCols,int intRow, int intCol){

    bool blnEmpty = false;
    int intCounter = 0;

        for(int r =intRow-1; r <= intRow+1; r++)
        {
            for(int c = intCol-1; c <=intCol+1; c++)
            {
                if(IsInWorld(intRows,intCols,r,c))
                {
                    cout << "r: " << r << endl;
                    cout << "c:" << c << endl;
                    cout << "intCounter:" << intCounter << endl;
                    if(arrWorld[r][c] == SQ_Empty)
                        intCounter++;
                }

        }
    }
if(intCounter == 9)
    blnEmpty = true;
    return blnEmpty;
    }

    void PlaceTrees(ParkArea arrWorld,int intRows, int intCols, int intBluegrass, int intAttempts){
        for(int i = 0; i < intAttempts; i++){
            //Generate random location
            int intRows = GetRand(0,intRows-1);
            int intCols = GetRand(0,intCols-1);

            if(IsEmptyAround(arrWorld,intRows,intCols,intRow,intCol)){
                arrWorld[intRow][intCol]= SQ_TREE;
            }


        }
    }
       void OutputWorld(ParkArea arrWorld,int intRows,int intCols){
       for(int r = 0; r < intRows; r++){
        for(int c = 0;c < intCols; c++){
            switch(arrWorld[r][c]){
        case SQ_Empty:
            cout << EmptySpace;
            break;
        case SQ_TREE:
            cout << Tree;
            break;
        case SQ_BLUEGRASS:
            cout << Bluegrass;
            break;
            default:
            cerr << "It will not Output";
            }
            cout << " ";
        }
        cout << endl;
       }
       }

       void CopyArray(ParkArea arrTo,ParkArea arrFrom,int intRows, int intCols, bool blnTrees){
       for(int r = 0; r < intRows; r++){
        for(int c = 0; c < intCols; c ++){
            if(blnTrees){
                if(arrFrom[r][c]==SQ_TREE)
                    arrTo[r][c]=SQ_Empty;
                else
                    arrTo[r][c]=arrFrom[r][c];
            }
            else
                 arrTo[r][c]=arrFrom[r][c];
        }
       }
       }

       void RetryWorld(ParkArea arrWorld,int intRows,int intCols,int intAttempts){
       ParkArea arrTemp = MemAllo(intRows,intCols);
       CopyArray(arrTemp, arrWorld,intRows,intCols,true);
        //Rid of temp array
       DeMemAllo(arrTemp,intRows);
       }

      void DeMemAllo(ParkArea &arrWorld,int intRows){
       for(int n = 0; n < intRows; n++){
            delete[]arrWorld[n];
       }
       delete[]arrWorld;
       arrWorld = nullptr;
       }
}
