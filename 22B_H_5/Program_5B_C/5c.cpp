/**
 CIS 22B: Homework 5C
 
 This program is a test driver for the Patient class report.

 NAME: Pan Yue
 IDE: VS Code
 ===================================== */

#include "Patient.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

// Function prototypes
void readData(string, Patient *, int &);
void displaySelection(Patient *, string, int);
void writeData(string, Patient *, int);

int main()
{
    Patient patients[100];
    int nrows;
    readData("patient.txt", patients, nrows);

    displaySelection(patients, "Underweight", nrows);
    displaySelection(patients, "Overweight", nrows);
    displaySelection(patients, "Obese", nrows);

    writeData("patientReport.txt", patients, nrows);
}

//***********************************************************
// readData reads data from an input file (patient.txt)     *
// into this array.                                         *
//***********************************************************
void readData(string filename, Patient *patient, int &nrow)
{
    ifstream fin;

    // open the input file
    fin.open(filename.c_str());
    if (fin.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    int i = 0;
    string line;
    while (getline(fin, line))
    {
        stringstream ss;
        ss << line;
        string age, height, weight, name;
        getline(ss, age, ' ');
        getline(ss, height, ' ');
        getline(ss, weight, ' ');
        getline(ss, name);
        patient[i] = Patient(name, atoi(age.c_str()), atof(height.c_str()), atof(weight.c_str()));
        i++;
    }
    nrow = i;

    // close the input file
    fin.close();
}

//***********************************************************
// displaySelection displays on the screen:                 *
// 1. The names of the underweight patients.                *
// 2. The names of the overweight patients.                 *
// 3. The names of the obese patients.                      *
//***********************************************************
void displaySelection(Patient *patients, string status, int nrows)
{
    cout << "The names of the " << status << " patients:" << endl;
    for (int i = 0; i < nrows; i++)
    {
        if (patients[i].weightStatus() == status)
        {
            cout << patients[i].getName() << endl;
        }
    }
    cout << endl;
}

//***********************************************************
// writeData writes to another file (patientReport.txt)     *
// a table.                                                 *
//***********************************************************
void writeData(string filename, Patient *patients, const int nrow)
{
    ofstream outputFile;

    //open the output file
    outputFile.open(filename.c_str());

    //display the patient's information in a table
    outputFile << "Weight Status Report" << endl;
    outputFile << "==================== === ====== ====== =============" << endl;
    outputFile << setw(21) << left << "Name" << setw(4) << "Age" << setw(7) << "Height" << setw(7)
               << "Weight" << setw(10) << "Status" << endl;
    outputFile << "==================== === ====== ====== =============" << endl;
    for (int i = 0; i < nrow; i++)
    {
        outputFile << setw(20) << left << patients[i].getName() << " "
                   << setw(3) << patients[i].getAge() << " "
                   << setw(6) << patients[i].getHeight() << " "
                   << setw(6) << patients[i].getWeight() << " "
                   << setw(10) << patients[i].weightStatus() << endl;
    }
    //close the output file
    outputFile.close();
}

/***************************************************************
 Save the OUTPUT below
 
The names of the Underweight patients:
Paul West
Laura King

The names of the Overweight patients:
Linda East

The names of the Obese patients:
Tim South
Tom Baker
William Peterson
Peter Pan
Andrew Davis
 
*/

/* Comments
5B - BMI calculation

Redundant tests (see the attached file)

-2Points
~*~=============================~*~~
Download 5C_BMI.png
Delia Garbacea, Mar 4 at 5:13pm
~*~=============================~*~~
5C

int main()
{
  Patient patients[100];

// See below

const int NO_PATIENTS = 100;

int main()
{
    Inventory list[NO_PATIENTS];


-1Point
~*~=======================================~*~~
Delia Garbacea, Mar 4 at 5:15pm
int main()
{
    Patient patients[100];
    int nrows;
    readData("patient.txt", patients, nrows);

    displaySelection(patients, "Underweight", nrows);
    displaySelection(patients, "Overweight", nrows);
    displaySelection(patients, "Obese", nrows);

    writeData("patientReport.txt", patients, nrows);

???? // return 0;
}

-1Point
Delia Garbacea, Mar 4 at 5:16pm
~*~=======================================~*~~
5C

size = 0; 
while (size < ARY_SIZE && inFile >> age >> height >> weight)
^^^^^^^^^^^^^^^^^^ you forgot to check this

-2Points
~*~=======================================~*~~
Delia Garbacea, Mar 4 at 5:17pm
*/