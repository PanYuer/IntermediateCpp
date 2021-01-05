// Specification file for the Cruiseship class

// Modified by: Pan Yue
// IDE: VS Code

#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "Ship.h"
#include <string>
using namespace std;

// The Cruiseship class represents a cruiseship.
class Cruiseship : public Ship
{
private:
    int passengers;

public:
    // Default constructor
    Cruiseship() : Ship()
    {
        passengers = 0;
    }

    // Constructor #2
    Cruiseship(string name, string year, int maxPassengers) : Ship(name, year)
    {
        passengers = maxPassengers;
    }

    // Accessor for maxNum attribute
    int getPassengers() const
    {
        return passengers;
    }

    // print function to display data
    void print() const override
    {
        cout << "Cruise ship" << endl;
        Ship::print();
        cout << "Max num of passengers: " << passengers << endl
             << endl;
    }
};
#endif