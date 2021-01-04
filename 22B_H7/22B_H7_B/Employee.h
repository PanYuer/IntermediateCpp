// Specification file for the Employee class

// Modified by: Pan Yue
// IDE: VS Code

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

//******************************
// Base Class declaration      *
//******************************

class Employee
{
private:
    string name;     // To hold employee name
    int number;      // To hold employee number
    string hireDate; // To hold hire date
public:
    Employee() // Default Constructor
    {
        name = "";
        number = 0;
        hireDate = "";
    }
    Employee(string n, int num, string d) // Overloaded Constructor
    {
        name = n;
        number = num;
        hireDate = d;
    }

    // Mutator functions
    void setName(string n) { name = n; }
    void setNum(int num) { number = num; }
    void setDate(string d) { hireDate = d; }

    // Accessor functions
    string getName() const { return name; }
    int getNum() const { return number; }
    string getDate() const { return hireDate; }

    // Display function
    void display() const
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Number: " << number << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

#endif