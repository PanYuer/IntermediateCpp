// Specification file for the Cargoship class

// Modified by: Pan Yue
// IDE: VS Code

#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "Ship.h"
#include <string>
using namespace std;

// The Cargoship class represents a cargoship.
class Cargoship : public Ship
{
private:
    int capacity;

public:
    // Default constructor
    Cargoship() : Ship()
    {
        capacity = 0;
    }

    // Constructor #2
    Cargoship(string name, string year, int cap) : Ship(name, year)
    {
        capacity = cap;
    }

    // Accessor for maxNum attribute
    int getCapacity() const
    {
        return capacity;
    }

    // print function to display data
    void print() const override
    {
        cout << "Cargo ship" << endl;
        Ship::print();
        cout << "Capacity: " << capacity << endl
             << endl;
    }
};
#endif