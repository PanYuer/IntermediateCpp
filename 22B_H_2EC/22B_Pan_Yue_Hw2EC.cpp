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
 
 Written by: Pan Yue
 Date: Jan.22, 2020
 */
#include <iostream>

using namespace std;

const int MAX_PEOPLE = 100;
const int NO_TESTS = 5;

bool locateSuperstar(const int table[][MAX_PEOPLE], int n, int &superstarIndex);

int main(void) // The main() function is a test driver for the locateSuperstar() function
{
    string names[MAX_PEOPLE] = {"Ada", "Amy", "Bob", "Cam", "Dan", "Ion", "Mia", "Tom", "Zoe"};
    int sizes[NO_TESTS] = {5, 5, 5, 7, 8}; // The array "sizes" stores the sizes of the test tables
    // The 3D array "testCases" stores the test tables for testing the locateSuperstar() function
    int testCases[NO_TESTS][MAX_PEOPLE][MAX_PEOPLE] = //square table and what test
        {
            {//  Test Table #0: 5 people
             {0, 1, 1, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
             {1, 0, 1, 0, 1},
             {0, 1, 1, 1, 0}},
            {//  Test Table #1: 5 people
             {0, 1, 1, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0},
             {1, 0, 0, 0, 1},
             {0, 1, 1, 1, 0}},
            {//  Test Table #2: 5 people
             {0, 1, 1, 1, 0},
             {0, 0, 1, 0, 0},
             {0, 0, 0, 0, 1},
             {1, 0, 1, 0, 1},
             {0, 1, 1, 1, 0}},
            {
                //  Test Table #3: 7 people
                {0, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 1, 1, 0, 1},
                {0, 0, 0, 1, 0, 1, 0},
                {0, 0, 0, 0, 0, 0, 0},
                {1, 1, 1, 1, 0, 1, 1},
                {0, 0, 0, 1, 0, 0, 0},
                {1, 0, 0, 1, 0, 1, 0},
            },
            {
                //  Test Table #4: 8 people
                {0, 1, 1, 1, 0, 1, 1, 0},
                {0, 0, 1, 0, 0, 1, 1, 1},
                {0, 0, 0, 0, 0, 1, 0, 1},
                {1, 0, 1, 0, 1, 1, 0, 1},
                {0, 1, 1, 1, 0, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 1},
                {0, 0, 1, 0, 1, 1, 0, 0},
            }};

    int superstarIndex;
    for (int t = 0; t < NO_TESTS; t++)
    {
        // CALL a function to display the current table

        if (locateSuperstar(testCases[t], sizes[t], superstarIndex))
        {
            cout << names[superstarIndex] << " is the superstar!\n";
        }
        else
        {
            cout << "There is no superstar!\n";
        }
    }

    return 0;
} // main

// DEFINE a function to locate the superstar
/*********************
 This function has two input parameters: a table and its size.
 It checks if there's a superstar: if there is, the output parameter
 superstarIndex will contain the index of the superstar, and the function
 returns true, otherwise the function returns false.
 */
bool locateSuperstar(const int table[][MAX_PEOPLE], int n, int &superstarIndex)
{
    superstarIndex = 0;
    for (int r = 0; r < n; r++)
    {
        int sum = 0;
        for (int c = 0; c < n; c++)
        {
            sum += table[r][c];
        }
        /* If the sum of every element in a row equals to 0, 
        then the value of every element is 0, which means this is the superstar's row.*/
        if (sum == 0)
        {
            superstarIndex = r;
            return true;
        }
    }
    return false;
}

/******Results*******
Bob is the superstar!
Bob is the superstar!
There is no superstar!
Cam is the superstar!
Ion is the superstar!
*/

/****************************************************************
A more efficient solution (without using nested loops) is described below:

   0 1 2 3 4
0  0 0 1 1 1
1  1 0 1 1 0
2  0 1 1 1 0
3  0 0 0 0 0
4  1 0 1 1 1

Does i know j? // Is table[i][j] == 1?
   if YES => i is NOT the celebrity
   if NO  => j is NOT the celebrity

Step1:
i = 0, j = 1, next = 2
Step2:
table[i][j] = table[0][1] = 0 => j = 0 is not the celebrity
j = next++; // now j = 2 and next is 3; i did not change
Step3:
table[i][j] = table[0][2] = 1 => i = 1 is not the celebrity
i = next++; // now i = 3, next is 4, j did not change
Step4:
table[i][j] = table[3][2] = 0 => j = 2 is not the celebrity
j = next++; / now j = 4, next = 5, i did not change
Step5:
table[i][j] = table[3][4] = 0 => j = 4 is not the celebrity


=> The candidate is 3, and you have to check this.
Delia Garbacea , Feb 5 at 7:39pm


// See correct results below
Bob is the superstar!
There is no superstar!
There is no superstar!
Cam is the superstar!
Ion is the superstar!

*/