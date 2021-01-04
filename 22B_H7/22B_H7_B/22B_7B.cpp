// CIS22B_7B: This program demonstrates ProductionWorker class.

// Modified by: Pan Yue
// IDE: VS Code

#include <iostream>
#include <iomanip>
#include "ProductionWorker.h"
using namespace std;

int main()
{
    // Define some ProductionWorker objects.
    ProductionWorker employee1("Peter Porter", 12306, "03/12/1991", 1, 14.5);
    ProductionWorker employee2("Yaire Gump", 10086, "04/22/1992", 2, 18.5);

    cout << "Welcome!\n";

    // Output data
    cout << "You can see some basic information about employees here. \n\n";

    cout << "Below is employee 1 info: \n";
    employee1.display();

    cout << "Below is employee 2 info: \n";
    employee2.display();

    cout << "Thank you for using this system.\n";

    return 0;
}

/************ OUTPUT ************

Welcome!
You can see some basic information about employees here. 

Below is employee 1 info: 
Employee Name: Peter Porter
Employee Number: 12306
Hire Date: 03/12/1991
Shift: Day
Hourly pay rate: $14.50

Below is employee 2 info: 
Employee Name: Yaire Gump
Employee Number: 10086
Hire Date: 04/22/1992
Shift: Night
Hourly pay rate: $18.50

Thank you for using this system.

*/