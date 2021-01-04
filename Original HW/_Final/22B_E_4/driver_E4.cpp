/*~*~*~*~*~*~
   CIS 22B (30Points)
   
   This project is a variation of the Linked List project.
   It has multiple source files and a header files
       
REQUIREMENTS:
   1. Write a calling statement for the displayList() function to display the contents of the list
   2. Create a new linked list with countries that begin with the same letter, without destroying the original list
   3. Display the new list.
   4. Run the program.
   5. Save the output as a comment at the end of the source file.
   6. Write your name and IDE below
   7. Briefly explain why & is needed below
   void searchCountry(CountryList &list);
 --------------------------------^^^
          Hint: remove it and see what happens!
 
 NAME:
 IDE:
*~*/
     
#include <iostream>
#include<string>
#include<iomanip>
#include "CountryList.h"
using namespace std;

void buildList(CountryList &list);
void searchCountry(CountryList &list);
void showTimeStamp();

int main()
{
    CountryList list, list2;

    buildList(list);
    searchCountry(list);
    // call the displayList() function below
   
    list.make(list2, 'C');
    
    // call the displayList() function again, to display the new list
    
    showTimeStamp();
    return 0;
}

/*~*~*~*~*~*~
 This function reads data about countries from a given file and inserts them
 into a sorted linked list.
*~*/
void buildList(CountryList &list)
{

    Country c;
    c.setAll("MX", "Mexico", "Mexico City", 106202903);
    list.insertNode(c);
    c.setAll("AU", "Australia", "Canberra", 20090437);
    list.insertNode(c);
    c.setAll("MU", "Mauritius", "Port Louis", 1230602);
    list.insertNode(c);
    c.setAll("CA", "Canada", "Ottawa", 32805041);
    list.insertNode(c);
    c.setAll("MC", "Monaco", "Monaco", 32409);
    list.insertNode(c);
    c.setAll("CN", "China", "Beijing", 1306313812);
    list.insertNode(c);
    
}

/*~*~*~*~*~*~
   This function is used for testing the
   searchList member function of the CountryList class
*~*/
void searchCountry(CountryList  &list)
{
    string key = "AU";
    Country ctr;
    
    cout << "_____ SEARCH SECTION _____\n\n";
    if ( list.searchList(key, ctr) ) // found
        cout << ctr.getCode()<< "   " <<left << setw(21)
             << ctr.getName() <<left <<setw(22)
             << ctr.getCapital() << right
             << ctr.getPopulation() << endl;
    else cout << key << "   Not found!\n";
    
    key = "GR";
    if ( list.searchList(key, ctr) ) // found
             cout << ctr.getCode()<< "   " <<left << setw(21)
                  << ctr.getName() <<left <<setw(22)
                  << ctr.getCapital() << right
                  << ctr.getPopulation() << endl;
    else cout << key << "   Not found!\n";
    
    key = "MU";
    if ( list.searchList(key, ctr) ) // found
           cout << ctr.getCode()<< "   " <<left << setw(21)
                << ctr.getName() <<left <<setw(22)
                << ctr.getCapital() << right
                << ctr.getPopulation() << endl;
    else cout << key << "   Not found!\n";
    
    cout << "\n___________________END SEARCH SECTION _____\n";
}


/*~*~*~*~*~*~
   This function displays the current date and time
           // It does not have any error
           // Do not remove!
*~*/
void showTimeStamp()
{
    time_t timeval = time(0);
    char *chtime = ctime(&timeval);
    cout << "\n\t ~*~ " << chtime;
}
/*~*~*~*~*~*~ Save the output below



*~*/
