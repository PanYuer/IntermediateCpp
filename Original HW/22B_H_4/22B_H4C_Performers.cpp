/**
 CIS 22B: Homework 4C
 Strings and Structures
 
 Project: Star Search
 
 NAME:
 IDE:
 
 */

#include <iostream>

using namespace std;


/* Define a struct named Performer with the following fields:
 
 1. name (string)
 2. scores (an array of 5 doubles)
 3. final (double)
 
 */

// Function prototypes
void printWelcome(void);
void readPerfData();    // <== add parameters, change void if needed
void calculateScore();  // <== add parameters, change void if needed
void insertionSort();   // <== add parameters, change void if needed
void writeFile();       // <== add parameters, change void if needed
void displayResults();  // <== add parameters, change void if needed
void printEnd(void);

int main( void )
{
    string inFileName[] = {"performers.txt", "contestants.txt", "test.txt", "testempty.txt", ""};
    int choice = 1;  // to stop the program to allow the user to see the results one file at a time
    
    for (string *ptr = inFileName; choice == 1 && *ptr != ""; ptr++)    // test loop: takes the names of 4 input files from an array
    {
        printWelcome();
        readPerfData();     // <== change call to match with definition
        calculateScore();   // <== change call to match with definition
        insertionSort();    // <== change call to match with definition
        writeFile();        // <== change call to match with definition
        displayResults();   // <== change call to match with definition
        printEnd();
        
        
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
    }
    
    return 0;
}   // main
/**********************
 
 */
void printWelcome(void)
{
    cout << "Welcome\n";
}

/**********************
 
 */
void readPerfData()    // <== add parameters, change void if needed
{
    cout << "Read Performers Data\n";
}

/**********************
 
 */
void calculateScore()  // <== add parameters, change void if needed
{
    cout << "calculateScore\n";
}

/**********************
 
 */
void insertionSort()   // <== add parameters, change void if needed
{
    cout << "Insertion Sort Descending\n";
}

/**********************
 
 */
void writeFile()       // <== add parameters, change void if needed
{
    cout << "Write report to file\n";
}

/**********************
 
 */
void displayResults()  // <== add parameters, change void if needed
{
    cout << "Display the winners and their scores\n";
}

/**********************
 
 */
void printEnd(void)
{
    cout << "Good Bye!\n";
}

/** Save the output below
 
 
 */