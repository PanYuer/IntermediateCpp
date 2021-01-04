// Implementation file for the Patient class

#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;

/*~*~*~*~*~*~
This function displays all of a Patient object's private member variables
*~*/
void Patient::display() const
{
    cout << "         Name: " << name << endl
         << "          Age: " << age << endl
         << "       Weight: " << weight << " pounds" << endl
         << "       Height: " << height << " inches" << endl
         << "Weight Status: " << weightStatus() << endl << endl;
}

/*~*~*~*~*~*~
This function calculates a Patient object's body mass index and returns
a string representing their current weight status
*~*/
string Patient::weightStatus() const
{
    double BMI = (weight * 703) / (height * height);

    if (BMI < 18.5)
        return "Underweight";
    else if (BMI < 25)
        return "Normal";
    else if (BMI < 30)
        return "Overweight";
    else
        return "Obese";
}

