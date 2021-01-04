/**
 CIS 22B: Homework 2C
 2D Arrays
 
 Project: Minesweeper Counter
 
 NAME:
 IDE:
 
 */

#include <iostream>

using namespace std;

const int MAXGRIDSIZE = 100;  // the maximum table size is 100


int main( void )
{
    string infileName[] = {"g0.txt", "g1.txt", "abc.txt", "g2.txt", "g3.txt", ""};
    string outfileName[] = {"out0.txt", "out1.txt", "abcOut.txt", "out2.txt", "out3.txt", ""};
    int grid[MAXGRIDSIZE][MAXGRIDSIZE] = {0};       // given grid
    int cntGrid[MAXGRIDSIZE][MAXGRIDSIZE] = {0};    // grid of counters
    int rows;     // number of rows
    int cols;     // number of columns
    int choice = 1;  // to stop the program to allow the user to see the results one table at a time
    bool fileFound;
    
    // test loop: takes the names of the input files from an array of names
    for (int i = 0; choice == 1 && infileName[i] != ""; i++)
    {
        fileFound = readGrid(infileName[i], grid, rows, cols);
        if (fileFound)
        {
            makeGrid(grid, rows, cols, cntGrid);
            writeScreen(infileName[i], rows, cols, cntGrid, outfileName[i]);
            writeGrid(outfileName[i], cntGrid, rows, cols);
        }
        else
        {
            cout << "\"" << infileName[i] << "\" not found!" << endl;
        }
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }
    
    return 0;
}


/** Save the output below
 
 
 */
