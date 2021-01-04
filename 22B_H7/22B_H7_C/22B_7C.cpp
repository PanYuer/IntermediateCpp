// CIS22B_7B: This program demonstrates Ship class.

// Modified by: Pan Yue
// IDE: VS Code

#include <iostream>
#include <iomanip>
#include "Cruiseship.h"
#include "Cargoship.h"
#include "Ship.h"
using namespace std;

int main()
{
    // Create several Ship objects and dynamically allocate them
    Ship *ship_1 = new Ship("Victoria", "2007");
    Ship *ship_2 = new Cruiseship("Grand Princess", "2008", 1000);
    Ship *ship_3 = new Cargoship("Bob Ship", "2009", 80000);
    Ship *ship_4 = new Cargoship("Tim Ship", "2010", 60000);
    Ship *ship_5 = new Cruiseship("Herme", "2011", 2000);

    // create an array of Ship pointers
    Ship *ship_arr[] = {ship_1, ship_2, ship_3, ship_4, ship_5};
    int num_ship = 5;

    // Display the ships in inventory
    for (int i = 0; i < num_ship; i++)
    {
        ship_arr[i]->print();
    }

    // release memory
    for (int i = 0; i < num_ship; i++)
    {
        delete ship_arr[i];
    }

    return 0;
}

/********** OUTPUT *************
Ship name: Victoria
Built year: 2007
Cruise ship
Ship name: Grand Princess
Built year: 2008
Max num of passengers: 1000

Cargo ship
Ship name: Bob Ship
Built year: 2009
Capacity: 80000

Cargo ship
Ship name: Tim Ship
Built year: 2010
Capacity: 60000

Cruise ship
Ship name: Herme
Built year: 2011
Max num of passengers: 2000

*/