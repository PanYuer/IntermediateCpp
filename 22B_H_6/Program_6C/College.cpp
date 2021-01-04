// Implementation file for the College class
// Written By: Pan Yue
// IDE: VS Code

#include <iostream> // For cout  and NULL
#include <iomanip>  // For format design

#include "College.hpp"
using namespace std;

//*************************************************************************
// displays the data in the member variables in the hDisplay format.      *
//*************************************************************************
void College::hDisplay() const
{
    cout << left << setw(8) << code << setw(5) << rank << setw(30) << name << setw(8) << cost << endl;
}

//**************************************************************************
// displays the data in the member variables in the vDisplay format.       *
//**************************************************************************
void College::vDisplay() const
{
    cout << right << setw(20) << "Rank: " << getRank() << endl;
    cout << right << setw(20) << "School Name: " << getName() << endl;
    cout << right << setw(20) << "Cost of Attendance: " << getCost() << endl;
}