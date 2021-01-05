// Specification file for the Ship class

// Modified by: Pan Yue
// IDE: VS Code

#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;

// The Ship class holds general data about a ship in inventory.
class Ship
{
private:
    string name; // The ship's name
    string year; // The ship's built year

public:
    // Default constructor
    Ship()
    {
        name = "";
        year = "";
    }

    // Overloaded Constructor
    Ship(string n, string y)
    {
        name = n;
        year = y;
    }

    // Mutators
    void setName(string n)
    {
        name = n;
    }
    void setYear(string y)
    {
        year = y;
    }

    // Accessors
    string getName() const
    {
        return name;
    }

    string getYear() const
    {
        return year;
    }

    // print function to display data
    virtual void print() const
    {
        cout << "Ship name: " << name << endl;
        cout << "Built year: " << year << endl;
    }
};
#endif