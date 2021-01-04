/*
 CIS 22B: Homework 6C
 
 Build and procees a sorted linked list of College objects.
 The list is sorted in ascending order by the college code.
 Assume that the college code is unique.
 
 Written by: Pan Yue
 IDE: VS Code
 
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "LinkedList.hpp"

using namespace std;

const int MAX_ROW = 100;

LinkedList buildList(string filename);
void deleteManager(LinkedList &list);
void searchManager(const LinkedList &list);
void displayList(const LinkedList &list);

int main()
{
    const char inputFileName[] = "colleges.txt";
    LinkedList list = buildList(inputFileName);
    displayList(list);
    searchManager(list);
    // show the number of elements in the list
    deleteManager(list);
    // call the displayList() function again
    // show the number of elements in the list
    displayList(list);
    return 0;
}

/*****************************************************************************
 This function reads data from a given file and inserts them
 into a sorted linked list.
 *****************************************************************************/
LinkedList buildList(string filename)
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
    LinkedList list;
    while (i < MAX_ROW && getline(fin, line))
    {
        stringstream ss;
        ss << line;
        string rank, code, name, cost;
        getline(ss, rank, ' ');
        getline(ss, code, ' ');
        getline(ss, name, ';');
        getline(ss, cost);
        // insert node to the linkedlist
        list.insertNode(College(atoi(rank.c_str()), code, name, atoi(cost.c_str())));
        i++;
    }
    if (i == MAX_ROW)
    {
        cout << "Input file contains too many rows. Exit program with failure.";
        exit(EXIT_FAILURE);
    }
    // close the input file
    fin.close();

    return list;
}

/*****************************************************************************
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 *****************************************************************************/
void deleteManager(LinkedList &list)
{
    string targetName = "";

    cout << "\n Delete\n";
    cout << "=======\n";

    while (targetName != "Q")
    {
        cout << endl
             << "Enter a college code (or Q to stop deleting) : \n";
        getline(cin, targetName);

        if (targetName != "Q")
        {
            // call delete
            bool success = list.deleteNode(targetName);
            if (success)
            {
                cout << "College with code " << targetName << " has been deleted from this list.\n";
            }
            else
            {
                cout << "College with code " << targetName << " has not been found in this list.\n";
            }
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/*****************************************************************************
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 *****************************************************************************/
void searchManager(const LinkedList &list)
{
    string targetName = "";

    cout << "\n Search\n";
    cout << "=======\n";

    while (targetName != "Q")
    {
        cout << "\nEnter a college code (or Q to stop searching) : \n";
        getline(cin, targetName);

        if (targetName != "Q")
        {
            // call search
            const College *college = list.searchNode(targetName);
            if (college)
            {
                college->vDisplay();
            }
            else
            {
                cout << "College with code " << targetName << " has not been found in this list.\n";
            }
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
}

void displayList(const LinkedList &list)
{
    cout << "======= ==== ============================= =========" << endl;
    cout << left << setw(8) << "Code" << setw(5) << "Rank" << setw(30) << "Name" << setw(8) << "Cost" << endl;
    cout << "======= ==== ============================= =========" << endl;
    list.displayList();
    cout << "======= ==== ============================= =========" << endl;
    cout << "The total number of colleges: " << list.count() << endl;
}
/***************************************************************
 Save the OUTPUT below

======= ==== ============================= =========
Code    Rank Name                          Cost    
======= ==== ============================= =========
ABC     98   AB College                    9998    
CC      10   Cuesta College                19135   
CS      12   College of the Siskiyous      21936   
DAC     1    De Anza College               19302   
DVC     4    Diablo Valley College         20579   
FC      6    Foothill College              19302   
IVC     9    Irvine Valley College         20577   
NVC     7    Napa Valley College           18920   
OC      8    Ohlone College                15878   
PCC     5    Pasadena City College         17666   
PVC     15   Palo Verde College            18266   
SBCC    3    Santa Barbara City College    18524   
======= ==== ============================= =========
The total number of colleges: 12

 Search
=======

Enter a college code (or Q to stop searching) : 
ABC
              Rank: 98
       School Name: AB College
Cost of Attendance: 9998

Enter a college code (or Q to stop searching) : 
NVC
              Rank: 7
       School Name: Napa Valley College
Cost of Attendance: 18920

Enter a college code (or Q to stop searching) : 
OC
              Rank: 8
       School Name: Ohlone College
Cost of Attendance: 15878

Enter a college code (or Q to stop searching) : 
Q
___________________END SEARCH SECTION _____

 Delete
=======

Enter a college code (or Q to stop deleting) : 
SBCC
College with code SBCC has been deleted from this list.

Enter a college code (or Q to stop deleting) : 
CS
College with code CS has been deleted from this list.

Enter a college code (or Q to stop deleting) : 
Q
___________________END DELETE SECTION_____
======= ==== ============================= =========
Code    Rank Name                          Cost    
======= ==== ============================= =========
ABC     98   AB College                    9998    
CC      10   Cuesta College                19135   
DAC     1    De Anza College               19302   
DVC     4    Diablo Valley College         20579   
FC      6    Foothill College              19302   
IVC     9    Irvine Valley College         20577   
NVC     7    Napa Valley College           18920   
OC      8    Ohlone College                15878   
PCC     5    Pasadena City College         17666   
PVC     15   Palo Verde College            18266   
======= ==== ============================= =========
The total number of colleges: 10

 */

/*******  Comments
LinkedList list;
while (i < MAX_ROW && getline(fin, line))
{//^^^^^^ needed for a fixed sized array but not needed for a linked list!



 if (i == MAX_ROW)
    {
        cout << "Input file contains too many rows. Exit program with failure.";
        exit(EXIT_FAILURE);
    }

//^^^^^^ needed for a fixed sized array but not needed for a linked list!

-2Points
Delia Garbacea, Mar 11 at 10:44pm
~*~=======================================~*~~
ALGORITHM DESIGN: searching a sorted list

In insertNode:
while (pCur && pCur->data.getName() < dataIn.getName()) 

In deleteNode:
while (pCur && pCur->data.getName() < target) 

In searchNode:
while (pCur && pCur->data.getName() != target) //<====== Use <, as in insert

Unsuccessful searches do not have to traverse the entire list.
Here is an example:

10 20 30 40 50 60 70 80 90

Search for 25:
25 > 10
25 > 20
25 < 30, Stop here (not found)

-2Points
~*~=======================================~*~~
Delia Garbacea, Mar 11 at 10:52pm
const College *LinkedList::searchNode(string code) const

See a better design below
bool LinkedList::searchList(string target, College &dataOut);
*/