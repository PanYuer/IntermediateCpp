/*~*~*~*~*~*~
   CIS 22B (35Points)
   
   This project is a variation of the Patient project.
   It has two source files and a header file:
        driver.cpp
        Patient.cpp
        Patient.h
   
 
REQUIREMENTS:
   1. Define an overloaded constructor (needed for initializing the array in main())
   2. Write a calling statement for the displayBmiStatus() function to
        display the patients with status = "Underweight"
   3. Overload the stream insertion operator and eliminate the the display member function of the Patient class
      (the code in display() will be moved in the overloaded << )
   4. Run the program.
   5. Save the output as a comment at the end of the source file.
   6. Write your name and IDE below
 
 NAME: Pan Yue
 IDE: VS Code
*~*/
     

#include "Patient.h"
#include <iostream>

#include <string>
using namespace std;

const int MAX_SIZE = 100;

void displayBmiStatus(const Patient patArr[], int size, string target);
void showTimeStamp();

int main()
{
    Patient patArr[MAX_SIZE] = 
    {
        {"Paul West", 71., 31, 122 },
        {"Linda East", 69., 52, 175},
        {"Tim South", 72., 64, 251},
        {"Jane North", 66., 25, 110},
        {"Jim Gaddis", 68., 28, 143}
    };
    int size = 5;

    // call the displayBmiStatus function below
    displayBmiStatus(patArr, size, "Underweight");
    
    
    showTimeStamp();
}

/*~*~*~*~*~*~
   This function takes an array, its size, and a target string.
   For each patient object in the array, it checks if the
   weight status matches the target string, and if it does,
   it displays the information about that patient.
*~*/
void displayBmiStatus(const Patient patArr[], int size, string target)
{
    cout << "Showing patients with the \"" << target << "\" status:" << endl;
    for (int p = 0; p < size; p++)
    {
        if (patArr[p].weightStatus() == target)
            // patArr[p].display();
            cout << patArr[p];
    }
    cout << endl;
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

Showing patients with the "Underweight" status:
         Name: Paul West
          Age: 31
       Weight: 122 pounds
       Height: 71 inches
Weight Status: Underweight

         Name: Jane North
          Age: 25
       Weight: 110 pounds
       Height: 66 inches
Weight Status: Underweight



	 ~*~ Mon Mar 23 13:02:42 2020

*~*/





