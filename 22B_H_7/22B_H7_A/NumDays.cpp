// Implementation file for the NumDays class

// Modified by: Pan Yue
// IDE: VS Code

#include <iostream> // Needed for cout
#include <cstdlib>  // Needed for abs()
#include "NumDays.h"

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

NumDays NumDays::operator+(const NumDays &right)
{
    NumDays temp;

    temp.hours = hours + right.hours;

    return temp;
}

//**********************************************
// Overloaded binary - operator.               *
//**********************************************

NumDays NumDays::operator-(const NumDays &right)
{
    NumDays temp;

    temp.hours = abs(hours - right.hours);

    return temp;
}

//*************************************************************
// Overloaded prefix ++ operator. Causes the hours member to  *
// be incremented. Returns the incremented object.            *
//*************************************************************

NumDays NumDays::operator++()
{
    ++hours;
    return *this;
}

//***************************************************************
// Overloaded postfix ++ operator. Causes the hours member to   *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

NumDays NumDays::operator++(int)
{
    NumDays temp(hours);
    hours++;
    return temp;
}

//*************************************************************
// Overloaded prefix -- operator. Causes the hours member to  *
// be decremented. Returns the decremented object.            *
//*************************************************************

NumDays NumDays::operator--()
{
    --hours;
    return *this;
}

//***************************************************************
// Overloaded postfix -- operator. Causes the hours member to   *
// be decremented. Returns the value of the object before the   *
// decrement.                                                   *
//***************************************************************

NumDays NumDays::operator--(int)
{
    NumDays temp(hours);
    hours--;
    return temp;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display NumDays objects.                     *
//********************************************************

ostream &operator<<(ostream &strm, const NumDays &obj)
{
    strm << obj.hours << " hours or " << obj.getDays() << " days";
    return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into NumDays objects.       *
//********************************************************

istream &operator>>(istream &strm, NumDays &obj)
{
    // Prompt the user for the hours.
    cout << "Hours: ";
    strm >> obj.hours;

    return strm;
}