/**
 CIS 22B: Homework 3C
 
  Create and sort a ragged table
 
  NAME:
*/
#include <iostream>
#include <iomanip>
using namespace std;

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif

// Function prototypes
double **readTable(string filename);
void showTable(double **table);
void sortRows(double **table);
void sortTable(double **table);
double ** releaseTable(double **table);
int main()
{
    string filename = "ragged.txt";
    double **table;
    
    table = readTable(filename);
    showTable(table);
    sortRows(table);
    showTable(table);
    sortTable(table);
    showTable(table);
    table = releaseTable(table); // now table should be NULL
    
    #ifdef _MSC_VER
        cout << _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n";
    #endif
    
    return 0;
}

/***************************************************************
  Save the OUTPUT below
  
  
*/

