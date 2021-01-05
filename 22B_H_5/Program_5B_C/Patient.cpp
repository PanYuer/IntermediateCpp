// Implementation file for the Patient class.
// This version has a constructor that accepts arguments.
#include "Patient.h" // Needed for the Patient class
#include <iostream>  // Needed for cout
#include <cstdlib>   // Needed for the exit function
#include <iomanip>   // Needed for setprecision
using namespace std;

//***********************************************************
// Constructor initializes member fields.                   *
//***********************************************************
Patient::Patient(string n, int a, double h, int w)
{
    name = n;
    age = a;
    weight = w;
    height = h;
}
// Alternative ctor with initialization list
// Patient::Patient(string n, int a, double h, int w) : name(n), age(a), height(h), weight(w) {}

//***********************************************************
// setName sets the value of the member variable name.      *
//***********************************************************

void Patient::setName(string n)
{
    if (!n.empty())
        name = n;
    else
    {
        cout << "Invalid name\n";
        exit(EXIT_FAILURE);
    }
}

//***********************************************************
// setAge sets the value of the member variable age.        *
//***********************************************************

void Patient::setAge(int a)
{
    if (a >= 0)
        age = a;
    else
    {
        cout << "Invalid age\n";
        exit(EXIT_FAILURE);
    }
}

//***********************************************************
// setHeight sets the value of the member variable height.  *
//***********************************************************

void Patient::setWeight(int w)
{
    if (w >= 0)
        weight = w;
    else
    {
        cout << "Invalid weight\n";
        exit(EXIT_FAILURE);
    }
}
//***********************************************************
// setWeigth sets the value of the member variable weight.  *
//***********************************************************

void Patient::setHeight(double h)
{
    if (h >= 0)
        height = h;
    else
    {
        cout << "Invalid height\n";
        exit(EXIT_FAILURE);
    }
}
//***********************************************************
// outputs the data in the member variables                 *
//***********************************************************
void Patient::display()
{

    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << setprecision(2) << fixed;
    cout << "Height: " << height << " inches\n";
    cout << "Weight: " << weight << " pounds\n";
    cout << "Weight Status: " << weightStatus() << "\n";
    cout << endl;
}
//***********************************************************
// Calculates the patient's BMI and shows the result of his *
// or herweight status                                      *
//***********************************************************
string Patient::weightStatus()
{
    double bmi = (weight * 703) / (height * height);
    if (bmi < 18.5)
    {
        return "Underweight";
    }
    else if (bmi > 18.5 && bmi < 24.9)
    {
        return "Normal";
    }
    else if (bmi > 25 && bmi < 29.9)
    {
        return "Overweight";
    }
    else if (bmi > 30)
    {
        return "Obese";
    }
    else
    {
        return "";
    }
}