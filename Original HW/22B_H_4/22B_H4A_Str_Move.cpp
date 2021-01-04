/**
 CIS 22B: Homework 4A
 Using c-string manipulation functions: strcpy, strcat, strrchr, etc.
 
 Write a function that given a c-string of words removes the last word and inserts 
 it in the beginning of the string. All words are separated by spaces. 
 You may assume that there is only one space between two words.
 Strings that are either empty or consists of only one word will not be changed.
 // HINT: Use a temp string
 
 Example: 	  	 "Two Three Four Five One"
 After processing: "One Two Three Four Five"
 
 Save the output as a comment at the end of the program.
 
 NAME:
 ============================================================================================= */
#include <iostream>
#include <cstring>
using namespace std;


bool moveFront( char s[] );

int main( void )
{
    char sList[5][100] = {"One Two Three Four Five Zero", "", "Three Two One Four", "Second First", "Done!"};
    bool change;
    
    // test the function with 5 strings
    for (int i = 0; i < 5; i++)
    {
        cout << "Before: [" << sList[i] << "]\n";
        change = moveFront(sList[i]);
        cout << " After: [" << sList[i] << "]\n";
        if (!change)
            cout << "\t\t The string is either empty or it has only one word!";
    }
    return 0;
}

/* ============================================= */
bool moveFront( char s[] )
{
    bool success = false;
    char temp[100];
    
       
    return success;
}
/***************************************************************
 Save the OUTPUT below
 
 
 */