// CIS22B_7A: This program demonstrates NumDays class.

// Modified by: Pan Yue
// IDE: VS Code

#include <iostream>
#include <iomanip>
#include "NumDays.h"
using namespace std;

int main()
{
    // Define some NumDays objects.
    NumDays thisWeek;
    NumDays lastWeek;

    cout << "How many hours have you worked this week?\n";
    cin >> thisWeek;
    cout << "How many hours did you work last week?\n";
    cin >> lastWeek;

    // Demonstrating the overloaded postfix ++, -- operators
    cout << fixed << showpoint << setprecision(2);
    cout << "Time your have worked this week: " << thisWeek;
    cout << endl;

    cout << "If you worked one more hour, your work hours would be: ";
    thisWeek++;
    cout << thisWeek;
    cout << endl;

    thisWeek--;

    // Demonstrating the overloaded prefix ++, --, + and - operators
    cout << "Time your worked last week: " << lastWeek;
    cout << endl;

    cout << "If you worked one more hour, your work hours would be: ";
    ++lastWeek;
    cout << lastWeek;
    cout << endl;

    --lastWeek;

    cout << "In total, this week and last week you worked: ";
    NumDays total = thisWeek + lastWeek;
    cout << total;
    cout << endl;

    cout << "The difference you worked this week and last week is: ";
    NumDays diff = thisWeek - lastWeek;
    cout << diff;
    cout << endl;

    return 0;
}

/************ OUTPUT *************

How many hours have you worked this week?
Hours: 20
How many hours did you work last week?
Hours: 23
Time your have worked this week: 20 hours or 2.50 days
If you worked one more hour, your work hours would be: 21 hours or 2.62 days
Time your worked last week: 23 hours or 2.88 days
If you worked one more hour, your work hours would be: 24 hours or 3.00 days
In total, this week and last week you worked: 43 hours or 5.38 days
The difference you worked this week and last week is: 3 hours or 0.38 days

*/