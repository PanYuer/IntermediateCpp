// Implementation file for the Rtriangle class.

#include "Rtriangle.h"   // Needed for the Triangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function
#include <cmath>       // Needed for the sqrt function
using namespace std;

//***********************************************************
// setSideA sets the value of the member variable sideA.
//***********************************************************
void Rtriangle::setSideA(double side)
{
   if (side >= 0)
      sideA = side;
   else
   {
      cout << "Invalid value for side1\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setSideB sets the value of the member variable sideB.
//***********************************************************
void Rtriangle::setSideB(double side)
{
    if (side >= 0)
        sideB = side;
    else
    {
        cout << "Invalid value for side1\n";
        exit(EXIT_FAILURE);
    }
}

//***********************************************************
// getSideA returns the value of the member variable sideA.
//***********************************************************
double Rtriangle::getSideA() const
{
    return sideA;
}

//***********************************************************
// getSideB returns the value of the member variable sideB.
//***********************************************************
double Rtriangle::getSideB() const
{
    return sideB;
}

//***********************************************************
// calcHypotenuse calculates and returns the value of the
// triangle's hypotenuse
//***********************************************************
double Rtriangle::calcHypotenuse() const
{
    return sqrt(sideA * sideA + sideB * sideB);
}

//***********************************************************
// calcArea calculates and returns the value of the
// triangle's area
//***********************************************************
double Rtriangle::calcArea() const
{
    return sideA * sideB / 2;
}
