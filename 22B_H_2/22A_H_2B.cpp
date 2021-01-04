/**
 CIS 22B: Homework 2B
 2D Arrays
 
 This program calls a function that takes a table of quizzes and calculates
 and stores the average for each student.
 
 
 Find and fix the errors. Run the program and save the output
 as a comment at the end of the program.
 
 NAME: Pan Yue
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int STU = 5;
const int QUIZZES = 10;

void calcStuAvg(int table[STU][QUIZZES], int nStu, int nQuiz, double stuAvg[STU]); // prototype

int main(void)
{
    int stu = 4;     //  actual number of students
    int quizzes = 8; //  a total of 8 quizzes
    int table[STU][QUIZZES] =
        {
            {10, 8, 9, 10, 4, 7, 10, 9},
            {10, 8, 9, 8, 6, 8, 9, 10},
            {10, 8, 9, 8, 9, 8, 8, 9},
            {10, 8, 9, 10, 9, 8, 10, 10},
        };
    double stuAvg[stu];

    calcStuAvg(table, stu, quizzes, stuAvg); // call calcStuAvg passing 4 arguments

    for (int i = 0; i < stu; i++)
        cout << fixed << showpoint << setprecision(2) << stuAvg[i] << " ";
    // print decimal for floating-point values
    cout << endl;

    return 0;
} // main

/*********************************************************************
 This function takes a table of quizzes and calculates and stores the
 average of each student
 PRE: - table[][] - has data
      - nStu
      - nQuiz
      - stuAvg[] - empty
 POST: stuAvg[] - contains the average for each student
 */
void calcStuAvg(int table[STU][QUIZZES], int nStu, int nQuiz, double stuAvg[STU])
{
    //int sum; // accumulator

    for (int r = 0; r < nStu; r++) // fix the errors on the range of subscripts
    {
        int sum = 0; // initialize the accumulator
        for (int c = 0; c < nQuiz; c++)
        {
            sum += table[r][c];
        }
        stuAvg[r] = static_cast<double>(sum) / nQuiz; // change sum into a double
    }
}

/** Save the correct output below
8.38 8.50 8.62 9.25 
 
*/
