// Implementation file for the Student List class
// Modified by: Pan Yue
// IDE: VS Code

#include <iostream> // For cout  and NULL
#include "StudentList.h"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
    count = 0;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************

void StudentList::displayList() const
{
    ListNode *pCur; // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->stu.getGpa() << " " << pCur->stu.getName() << endl;

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

//**************************************************
// displayList takes gpa as a parameter and shows
// the gpa and names of the students whose gpa are
// below the target gpa.
//**************************************************

void StudentList::displayList(double gpa) const
{
    ListNode *pCur; // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        if (pCur->stu.getGpa() < gpa)
        {
            // Display the value in this node.
            cout << pCur->stu.getGpa() << " " << pCur->stu.getName() << endl;
        }

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode; // A new node
    ListNode *pCur;    // To traverse the list
    ListNode *pPre;    // The previous node

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->stu = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find location: skip all nodes whose gpa is less than dataIn's gpa
    while (pCur != NULL && pCur->stu.getGpa() < dataIn.getGpa())
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;

    // Update the counter
    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with num as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool StudentList::deleteNode(double target)
{
    ListNode *pCur; // To traverse the list
    ListNode *pPre; // To point to the previous node
    bool deleted = false;

    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find node containing the target: Skip all nodes whose gpa is less than the target
    while (pCur != NULL && pCur->stu.getGpa() < target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // If found, delete the node
    if (pCur != NULL && pCur->stu.getGpa() == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        count--;
    }
    return deleted;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
StudentList::~StudentList()
{
    ListNode *pCur;  // To traverse the list
    ListNode *pNext; // To point to the next node

    // Position nodePtr at the head of the list.
    pCur = head->next;

    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;

        // Delete the current node.
        cout << "DEBUG - Destructor: Now deleting " << pCur->stu.getName() << endl;
        delete pCur;

        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node gpa = " << head->stu.getGpa() << endl;
    delete head; // delete the sentinel node
}
