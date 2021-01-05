// Specification file for the ProductionWorker class

// Modified by: Pan Yue
// IDE: VS Code

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//******************************
// Derived Class declaration   *
//******************************

class ProductionWorker : public Employee
{
private:
    int shift;      // To hold a value representing the shift the employee works
    double payRate; // To hold the employee's hourly pay rate
public:
    ProductionWorker() : Employee() // Default Constructor
    {
        shift = 0;
        payRate = 0.0;
    }
    ProductionWorker(string n, int num, string d, int s, double r) : Employee(n, num, d) // Overloaded Constructor
    {
        shift = s;
        payRate = r;
    }

    // Mutator functions
    void setShift(int s) { shift = s; }
    void setRate(double r) { payRate = r; }

    // Accessor functions
    int getShift() const { return shift; }
    double getRate() const { return payRate; }

    // Display function
    void display() const;
};

#endif