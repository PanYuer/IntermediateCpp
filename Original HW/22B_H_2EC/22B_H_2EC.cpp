/**
 CIS 22B
 H2 - Extra Credit
 
 Among n persons, a superstar is defined as someone who is known by everyone
 but does not know anyone. The problem is to identify the superstar,
 if one exits. In the relationship table shown below,
 1 means "row knows column",
 0 means "row does not know column"
 
 Amy Bob Cam Dan Ion
 Amy   0   1   1   1   0  // Amy knows Bob, Cam, and Dan
 Bob   0   0   1   0   0  // Bob knows Cam
 Cam   0   0   0   0   0  // Cam does not know anyone
 Dan   1   0   1   0   1  // Dan knows Amy, and Ion
 Ion   0   1   1   1   0  // Ion knows Bob, Cam, and Dan
 
Your task is to write a function to identify the superstar and call it from main().
 
Run the program and save the output as a comment, at the end of the source file.

 NOTE: Solving the problem with two nested loops is the straight forward solution; there is
 a more efficient solution that does not require nested loops.
 
 Written by:
 Date:
 */
#include <iostream>

using namespace std;

const int MAX_PEOPLE = 100;
const int NO_TESTS = 5;

bool locateSuperstar( const int table[][MAX_PEOPLE], int n, int &superstarIndex );


int main (void) // The main() function is a test driver for the locateSuperstar() function
{
    string names[MAX_PEOPLE] = {"Ada", "Amy", "Bob", "Cam", "Dan", "Ion", "Mia", "Tom", "Zoe"};
    int sizes[NO_TESTS] = {5, 5, 5, 7, 8};  // The array "sizes" stores the sizes of the test tables
    // The 3D array "testCases" stores the test tables for testing the locateSuperstar() function
    int  testCases[NO_TESTS][MAX_PEOPLE][MAX_PEOPLE] =
    {
        {                               //  Test Table #0: 5 people
            {0,   1,   1,   1,   0},
            {0,   0,   1,   0,   0},
            {0,   0,   0,   0,   0},
            {1,   0,   1,   0,   1},
            {0,   1,   1,   1,   0}
        },
        {                                //  Test Table #1: 5 people
            {0,   1,   1,   1,   0},
            {0,   0,   1,   0,   0},
            {0,   0,   0,   0,   0},
            {1,   0,   0,   0,   1},
            {0,   1,   1,   1,   0}
        },
        {                               //  Test Table #2: 5 people
            {0,   1,   1,   1,   0},
            {0,   0,   1,   0,   0},
            {0,   0,   0,   0,   1},
            {1,   0,   1,   0,   1},
            {0,   1,   1,   1,   0}
        },
        {                               //  Test Table #3: 7 people
            {0,   1,   1,   1,   1,   1,   0},
            {0,   0,   0,   1,   1,   0,   1},
            {0,   0,   0,   1,   0,   1,   0},
            {0,   0,   0,   0,   0,   0,   0},
            {1,   1,   1,   1,   0,   1,   1},
            {0,   0,   0,   1,   0,   0,   0},
            {1,   0,   0,   1,   0,   1,   0},
        },
        {                               //  Test Table #4: 8 people
            {0,   1,   1,   1,   0,   1,   1,   0},
            {0,   0,   1,   0,   0,   1,   1,   1},
            {0,   0,   0,   0,   0,   1,   0,   1},
            {1,   0,   1,   0,   1,   1,   0,   1},
            {0,   1,   1,   1,   0,   1,   1,   1},
            {0,   0,   0,   0,   0,   0,   0,   0},
            {0,   0,   0,   0,   0,   1,   0,   1},
            {0,   0,   1,   0,   1,   1,   0,   0},
        }
    };
    
    int superstarIndex;
    for ( int t = 0; t < NO_TESTS; t++)
    {
        // CALL a function to display the current table
        
        if (locateSuperstar( testCases[t], sizes[t], superstarIndex ))
        {
            cout << names[superstarIndex] << " is the superstar!\n";
        }
        else
        {
            cout << "There is no superstar!\n";
        }
        
        
    }
    
    return 0;
}	// main


// DEFINE a function to locate the superstar
/*********************
 This function has two input parameters: a table and its size.
 It checks if there's a superstar: it there is, the output parameter
 superstarIndex will contain the index of the superstar, and the function
 returns true, otherwise the function returns false.
 */
bool locateSuperstar( const int table[][MAX_PEOPLE], int n, int &superstarIndex )
{
    superstarIndex = 0;
    
    return true;
}




