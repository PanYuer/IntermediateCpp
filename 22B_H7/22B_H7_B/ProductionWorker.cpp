// Implementation file for the ProductionWorker class

// Modified by: Pan Yue
// IDE: VS Code

#include <iostream> // Needed for cout
#include <iomanip>  // Needed for setprecision
#include "ProductionWorker.h"
#include "Employee.h"

//*****************************************************************
// display function outputs the data about a production worker.   *
//*****************************************************************

void ProductionWorker::display() const
{
    Employee::display(); // To display employee's name, number and hire date

    // To display employee's shift
    if (shift == 1)
        cout << "Shift: Day\n";
    else if (shift == 2)
        cout << "Shift: Night\n";
    else
        cout << "Error!\n";

    // To display employee's payrate
    cout << fixed << setprecision(2) << showpoint;
    cout << "Hourly pay rate: $" << payRate << endl;
    cout << endl;
}
