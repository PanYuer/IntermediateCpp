// Specification file for the LinkedList class

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Country.h"


class CountryList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        Country ctr;     // The value in this node
        ListNode *next;  // To point to the next node
    };

    ListNode *head;      // List head pointer
    int count;           // To keep track of the number of nodes in the list


public:
    CountryList();  // Constructor
    ~CountryList();   // Destructor

    // Linked list operations
    int getCount() const {return count;}
    void insertNode(Country);
    void displayList() const;
    bool searchList(string, Country &out) const;


};

#endif
