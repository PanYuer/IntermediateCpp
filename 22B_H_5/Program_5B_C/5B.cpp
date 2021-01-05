/**
 CIS 22B: Homework 5B
 
 This program is a test driver for the Patient class.

 NAME: Pan Yue
 IDE: VS Code
 ===================================== */

#include <iostream>
#include <iomanip>
#include "Patient.h"
using namespace std;

int main()
{
   // Create 3 Patient objects.
   Patient patJane("Jane North", 25, 66, 120);
   Patient patTim("Tim South", 64, 72, 251);
   Patient patLinda("Linda East", 52, 69, 175);

   // Display the patient's name, age, height, and weight.
   patJane.display();
   patTim.display();
   patLinda.display();
   return 0;
}

/***************************************************************
 Save the OUTPUT below
 
Name: Jane North
Age: 25
Height: 66.00 inches
Weight: 120 pounds
Weight Status: Normal

Name: Tim South
Age: 64
Height: 72.00 inches
Weight: 251 pounds
Weight Status: Obese

Name: Linda East
Age: 52
Height: 69.00 inches
Weight: 175 pounds
Weight Status: Overweight
 
*/
