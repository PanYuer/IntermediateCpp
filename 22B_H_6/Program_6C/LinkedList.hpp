// Specification file for the LinkedList class
// Written By: Pan Yue
// IDE: VS Code

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "College.hpp"

class LinkedList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        College college; // The value in this node
        ListNode *next;  // To point to the next node
    };

    ListNode *head; // List head pointer

public:
    LinkedList();  // Constructor
    ~LinkedList(); // Destructor

    // Linked list operations
    int count() const;
    bool insertNode(College);
    bool deleteNode(string);
    void displayList() const;
    const College *searchNode(string) const;
};

#endif
