/*~*~*~*~*~*~
   CIS 22B
   
   This program is a variation of the Minesweeper project described below.
 
       Problem: In the game of Minesweeper, a player searches for hidden mines
       on a rectangular grid. The game board is represented by a greed of Boolean
       values stored as 0s and 1s marking the hidden mines locations with 1.
       Given such a grid, the program creates a new grid of integers storing
       the count of mines in each neighborhood. The neighborhood for a location
       includes the location itself and its eight adjacent locations.
 
       To simplify the counting process,
       a “frame” of 0s has been added to the original grid.
 
REQUIREMENTS:
   1. Find and fix all errors (about 15)
              a. comment the line with an error
              b. fix the error below
              c. briefly explain what was the error
   2. Run the program.
   3. Save the output as a comment at the end of the source file.
   4. Write your name and IDE below
 
 NAME:
 IDE:
*~*/
    
 
 

#include <iostream>
#include <ctime>

using namespace std;

const int GMAX = 100;

struct Grid
{
    int rows;
    int cols;
    int table[GMAX][GMAX];
}

void makeGrid(const Grid &g, int cntGrid[][]);
void writeGrid(int rows, int cols, int cntGrid [][]);
void showTimeStamp();

int main( void )
{
    Grid g = { 3, 5,
                    {   // adding a “frame” of 0s
                        {0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0}
                    };
    }
    int cntGrid[][GMAX] = {0};

    //makeGrid(cntGrid, g);
    write_grid(g->rows, cols, cntGrid );
        
    showTimeStamp();
    return 0;
}
/*~*~*~*~*~*~
  This function creates the grid of counters
  based on the original grid.
*~*/
void makeGrid(const Grid g, int cntGrid[][GMAX])
{
    for (int r = 1; r <= g.rows; ++r)
    {
        for (int c = 1; c <= g.cols; ++c)
        {
              cntGrid[r][c] = g.table[r-1][c-1] + g.table[r-1][c] + g.table[r-1][c+1] +
                              g.table[r][c-1]   + g.table[r][c]   + g.table[r][c+1] +
                              g.table[r+1][c-1] + g.table[r+1][c] + g.table[r+1][c+1];
        }
    }
}

/*~*~*~*~*~*~
 This function displays the grid of counters
 to the screen
*~*/
void write_grid(int cntGrid [GMAX][], int rows, int cols)
{
    cout << rows << " " << cols << endl;
    // for (int r = 0; r < rows; ++r)
    for (int r = 1; r <= rows; ++r)
    {
        // for (int c = 0; c < cols; ++c)
        for (int c = 1; c <= cols; ++c)
        {
            // cout << cntGrid[r][C] << " ";
            cout << cntGrid[r][c] << " ";
                          // change to c
        }
        cout << endl;
    }
}
/*~*~*~*~*~*~
   This function displays the current date and time
           // It does not have any error
           // Do not remove!
*~*/
void showTimeStamp()
{
    time_t timeval = time(0);
    char *chtime = ctime(&timeval);
    cout << "\n\t ~*~ " << chtime;
}
/*~*~*~*~*~*~ Save the output below



*~*/




