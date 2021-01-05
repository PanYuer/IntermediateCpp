// Specification file for the NumDays class

// Modified by: Pan Yue
// IDE: VS Code

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
using namespace std;

class NumDays; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator<<(ostream &, const NumDays &);
istream &operator>>(istream &, NumDays &);

// The NumDays class holds a number of work hours and convert it to a number of days

class NumDays
{
private:
    int hours; // To hold a number of hours
public:
    // Constructor
    NumDays() { hours = 0; }
    NumDays(int h) { hours = h; }

    // Mutator functions
    void setHours(int h) { hours = h; }
    void setDays(double d) { hours = d * 8; }

    // Accessor functions
    int getHours() const { return hours; }
    double getDays() const { return hours / 8.0; }

    // Overloaded operator functions
    NumDays operator+(const NumDays &); // Overloaded +
    NumDays operator-(const NumDays &); // Overloaded -
    NumDays operator++();               // Prefix ++
    NumDays operator++(int);            // Postfix ++
    NumDays operator--();               // Prefix --
    NumDays operator--(int);            // Postfix --

    // Friends
    friend ostream &operator<<(ostream &, const NumDays &);
    friend istream &operator>>(istream &, NumDays &);
};

#endif