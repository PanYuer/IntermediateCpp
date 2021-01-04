/**
 CIS 22B: Homework 5A
 
 This program creates a Rtriangle object, then displyas the values of its sides and area.
 Change this program to calculate and display the triangle's perimeter. Run the program once and
 save the output as a comment at the end of this source file.
 
 NAME: Yue Pan
 IDE: VS Code
 ===================================== */

#include <iostream>
#include <iomanip>
#include "Rtriangle.hpp"
using namespace std;

int main()
{
    double a, b;

    // Get the legs of the right triangle
    cout << "\t~*~ The Right Triangle Project ~*~" << endl;
    cout << "Please enter the values for the legs of a right triangle:" << endl;
    cout << "What is the value of a? ";
    cin >> a;
    cout << "What is the value of b? ";
    cin >> b;

    // Create a Rtriangle object.
    Rtriangle t;
    t.setSideA(a);
    t.setSideB(b);

    // Display the triangle's sides, area, and perimeter
    cout << setprecision(2) << fixed;
    cout << "\tResults" << endl;
    cout << "\tSide a is  " << t.getSideA() << endl;
    cout << "\tSide b is  " << t.getSideB() << endl;
    cout << "\tSide c is  " << t.calcHypotenuse() << endl;
    cout << "\tArea is    " << t.calcArea() << endl;
    // Display the perimeter below

    return 0;
}
/***************************************************************
 Save the OUTPUT below
 
 
*/
