/**
 CIS 22B: Homework 2C
 2D Arrays
 
 Project: Minesweeper Counter
 
 NAME: Pan Yue 
 IDE: Visual Studio
 
 */

#include <iostream>
#include <fstream>

using namespace std;

const int MAXGRIDSIZE = 100; // the maximum table size is 100

//prototype
bool readGrid(string, int[][MAXGRIDSIZE], int &, int &);
void makeGrid(int[][MAXGRIDSIZE], int, int, int[][MAXGRIDSIZE]);
void writeScreen(const string &in_file_name, int rows, int cols, int[][MAXGRIDSIZE], const string &out_file_name);
void writeGrid(const string &out_file_name, int cntGrid[][MAXGRIDSIZE], int rows, int cols);

int main(void)
{
    string infileName[] = {"g0.txt", "g1.txt", "abc.txt", "g2.txt", "g3.txt", ""};
    string outfileName[] = {"out0.txt", "out1.txt", "abcOut.txt", "out2.txt", "out3.txt", ""};
    int grid[MAXGRIDSIZE][MAXGRIDSIZE] = {0};    // given grid
    int cntGrid[MAXGRIDSIZE][MAXGRIDSIZE] = {0}; // grid of counters
    int rows;                                    // number of rows
    int cols;                                    // number of columns
    int choice = 1;                              // to stop the program to allow the user to see the results one table at a time
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

/**********************************************************************
This function reads in data about the grid’s number of rows and columns 
as well as the contents of the grid in the input file
***********************************************************************/
bool readGrid(string inputfilename, int grid[][MAXGRIDSIZE], int &rows, int &cols)
{
    ifstream inputFile;

    // open the input file
    inputFile.open(inputfilename.c_str());

    if (inputFile.fail())
        return false;

    // read rows & cols
    inputFile >> rows >> cols;

    // read grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            inputFile >> grid[r][c];
        }
    }

    // close the input file
    inputFile.close();
    return true;
}

/**********************************************************************
This function counts and displays "the grid of counters"
**********************************************************************/
void makeGrid(int grid[][MAXGRIDSIZE], int rows, int cols, int cntGrid[][MAXGRIDSIZE])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int cnt = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    if ((r + dr) >= 0 && (r + dr) < rows && (c + dc) >= 0 && (c + dc) < cols)
                        cnt += grid[r + dr][c + dc];
                }
            }
            cntGrid[r][c] = cnt;
        }
    }
}

/****************************************************************************************
This function displays the name of the input file, the grid’s number of rows and columns, 
the values in the four corners, and the name of the output file.
*****************************************************************************************/
void writeScreen(const string &in_file_name, int rows, int cols, int cntGrid[][MAXGRIDSIZE], const string &out_file_name)
{
    cout << "Input file name: " << in_file_name << endl;
    cout << "Grid size: " << rows << " x " << cols << endl;
    cout << "Corners: " << cntGrid[0][0] << ", " << cntGrid[0][cols - 1] << ", " << cntGrid[rows - 1][cols - 1] << ", " << cntGrid[rows - 1][0] << endl;
    cout << "Output file name: " << out_file_name << endl;
}

/**********************************************************************
This function writes to a file the grid’s number of rows and columns 
and the contents of the grid of counters. 
***********************************************************************/
void writeGrid(const string &out_file_name, int cntGrid[][MAXGRIDSIZE], int rows, int cols)
{
    ofstream outputFile;

    //open the output file
    outputFile.open(out_file_name.c_str());

    // numbers of rows and columns
    outputFile << rows << " " << cols << endl;

    // contents of the grid of counters
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            outputFile << cntGrid[r][c];
        }
        outputFile << endl;
    }
    //close the output file
    outputFile.close();
}

/** Save the output below

Input file name: g0.txt
Grid size: 3 x 5
Corners: 1, 2, 3, 0
Output file name: out0.txt
Please enter 1 to continue 0 to stop
1
Input file name: g1.txt
Grid size: 6 x 5
Corners: 1, 0, 2, 0
Output file name: out1.txt
Please enter 1 to continue 0 to stop
1
"abc.txt" not found!
Please enter 1 to continue 0 to stop
1
Input file name: g2.txt
Grid size: 5 x 4
Corners: 4, 4, 4, 4
Output file name: out2.txt
Please enter 1 to continue 0 to stop
1
Input file name: g3.txt
Grid size: 15 x 10
Corners: 1, 2, 1, 1
Output file name: out3.txt
Please enter 1 to continue 0 to stop
0
 ***********************************/
