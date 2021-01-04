/**
 CIS 22B: Homework 3C
 
  Create and sort a ragged table
 
  NAME: Pan Yue
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#ifdef _MSC_VER
#include <crtdbg.h> // needed to check for memory leaks (Windows only!)
#endif

// Function prototypes
double **readTable(string filename);
void showTable(double **table);
void insertionSort(double *pList, double *pLast);
void sortRows(double **table);
int arraySize(double *array);
void sortTable(double **table);
double **releaseTable(double **table);

int main()
{
  string filename = "ragged.txt";
  double **table;

  table = readTable(filename);
  cout << "Input Table: " << endl;
  showTable(table);
  sortRows(table);
  cout << "Table after sort each row: " << endl;
  showTable(table);
  sortTable(table);
  cout << "Table after sort by row size: " << endl;
  showTable(table);
  table = releaseTable(table); // now table should be NULL

#ifdef _MSC_VER
  cout << _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n";
#endif

  return 0;
}

/***************************************************************************
This function reads in data about the number of rows as well as the contents 
of each row in the input file, and mark the end of arrays by NULL.
****************************************************************************/
double **readTable(string filename)
{
  ifstream inputFile;

  // open the input file
  inputFile.open(filename.c_str());

  if (inputFile.fail())
  {
    cout << "Open file failure.\n";
    exit(EXIT_FAILURE);
  }

  // read rows
  int rows;
  inputFile >> rows;
  double **table = new double *[rows + 1]; // dynamically allocate an array of double pointers
  // read ragged array row by row
  for (int r = 0; r < rows; r++)
  {
    int cols;
    inputFile >> cols;
    double *row = new double[cols + 1]; // dynamically allocate an array of double to store data in a row
    row[0] = cols;
    table[r] = row; // make the r-th element of the table array points to the r-th row
    // read data into the row
    for (int c = 1; c < cols + 1; c++)
    {
      inputFile >> row[c];
    }
  }
  table[rows] = nullptr; // Mark the end of array / table by NULL
  // close the input file
  inputFile.close();
  return table;
}

/***************************************************************
This function displays the ragged table.
***************************************************************/
void showTable(double **table)
{
  for (double **cur_row = table; *cur_row != nullptr; cur_row++)
  {
    int cols = static_cast<int>(**cur_row);
    cout << setw(2) << cols;
    double *cur_col = *cur_row + 1;
    double *last_col = *cur_row + cols;
    for (; cur_col <= last_col; cur_col++)
    {
      cout << fixed << setprecision(1) << showpoint;
      cout << " " << setw(2) << *cur_col;
    }
    cout << endl;
  }
  cout << endl;
}

/***************************************************************
 Definition of function insertionSort.
 This function performs a descending order insertion sort on
 array. Size is the number of elements in the array.
 **************************************************************/
void insertionSort(double *pList, int size)
{
  for (double *curr = pList + 1; curr < pList + size; curr++)
  {
    double temp = *curr; // copy current element to hold
    double *back = curr - 1;
    //shift elements in the sorted part of the list to make room
    while (back >= pList && temp > *back) // search where to insert the current element
    {
      *(back + 1) = *back; // shift to the right
      back--;
    }
    *(back + 1) = temp; // put hold back to the array
  }
}

/**************************************************************
 This function calls the insertionSort to sort each row in the 
 ragged table in a descending order.
 *************************************************************/
void sortRows(double **table)
{
  for (double **row = table; *row != nullptr; row++)
  {
    int row_size = **row;
    insertionSort(*row + 1, row_size);
  }
}

/**************************************************************
 This function Sort the ragged table in a descending order 
 using a variation of the Insertion Sort algorithm to rearrange 
 the rows from the longest to the smallest.
 *************************************************************/
void sortTable(double **table)
{
  for (double **curr = table + 1; *curr != nullptr; curr++)
  {
    double *temp = *curr; // copy current element to hold
    double **back = curr - 1;
    //shift elements in the sorted part of the list to make room
    while (back >= table && *temp > **back) // search where to insert the current element
    {
      *(back + 1) = *back; // shift to the right
      back--;
    }
    *(back + 1) = temp; // put hold back to the array
  }
}

/**************************************************************
This function release memory by deleting pointers to dynamically
allocate memory. 
**************************************************************/
double **releaseTable(double **table)
{
  for (double **row = table; *row != nullptr; row++)
  {
    delete[] * row;
  }
  delete[] table;
  return nullptr;
}

/***************************************************************
  Save the OUTPUT below
Input Table: 
 3 23.9 51.2 35.6
 5 12.2 23.5 54.6 5.8 56.8
 1 88.8
 2 12.1 34.9
 4 23.9 3.7 51.2 35.6
 6 12.2 23.5 888.8 54.6 10.8 56.8
 2 88.8 0.5
 3 12.1 111.5 34.9
 3 3.5 5.1 5.6
11 1.2 3.5 1.6 0.8 6.2 7.5 2.1 1.2 9.0 8.9 5.3
 7 99.9 12.2 23.5 888.8 54.6 10.8 56.8
 2 2.9 384.5
 5 25.2 38.4 4.6 125.6 6.3

Table after sort each row: 
 3 51.2 35.6 23.9
 5 56.8 54.6 23.5 12.2 5.8
 1 88.8
 2 34.9 12.1
 4 51.2 35.6 23.9 3.7
 6 888.8 56.8 54.6 23.5 12.2 10.8
 2 88.8 0.5
 3 111.5 34.9 12.1
 3 5.6 5.1 3.5
11 9.0 8.9 7.5 6.2 5.3 3.5 2.1 1.6 1.2 1.2 0.8
 7 888.8 99.9 56.8 54.6 23.5 12.2 10.8
 2 384.5 2.9
 5 125.6 38.4 25.2 6.3 4.6
 
Table after sort by row size: 
11 9.0 8.9 7.5 6.2 5.3 3.5 2.1 1.6 1.2 1.2 0.8
 7 888.8 99.9 56.8 54.6 23.5 12.2 10.8
 6 888.8 56.8 54.6 23.5 12.2 10.8
 5 56.8 54.6 23.5 12.2 5.8
 5 125.6 38.4 25.2 6.3 4.6
 4 51.2 35.6 23.9 3.7
 3 51.2 35.6 23.9
 3 111.5 34.9 12.1
 3 5.6 5.1 3.5
 2 34.9 12.1
 2 88.8 0.5
 2 384.5 2.9
 1 88.8
  
*/
