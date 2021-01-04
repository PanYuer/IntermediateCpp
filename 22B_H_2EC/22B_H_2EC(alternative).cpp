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
    int testCases[NO_TESTS][MAX_PEOPLE][MAX_PEOPLE] =
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
        bool is_superstar = true;
        for (int c = 0; c < n; c++)
        {
            if (table[r][c] != 0)
            {
                is_superstar = false;
                break;
            }
            if (is_superstar)
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