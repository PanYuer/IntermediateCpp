// Implementation file for the CountryList class

#include <iostream>
#include <iomanip>
#include "CountryList.h"
using namespace std;

CountryList::CountryList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
    count = 0;
}

/*~*~*~*~*~*~
  displayList shows the value
  stored in each node of the linked list
  pointed to by head.
*~*/

void CountryList::displayList() const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    cout<<"==== ==================== ==================== ==========\n"
        <<"Code Country              Capital              Population\n"
        <<"==== ==================== ==================== ==========\n";

    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        // Display the value in this node
        cout << pCur->ctr.getCode()<< "   " <<left << setw(21)
             <<pCur->ctr.getName() <<left <<setw(22)
             << pCur->ctr.getCapital() << right
             << pCur->ctr.getPopulation() << endl;

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

/*~*~*~*~*~*~
  The insertNode function inserts a node
*~*/
void CountryList::insertNode(Country dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node

    // Allocate a new node
    newNode = new ListNode;
    newNode->ctr = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find location: skip all nodes whose code is less than the code
    while (pCur != NULL && pCur->ctr.getCode() < dataIn.getCode())
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

/*~*~*~*~*~*~
  SearchList searches for a code in the the list:
*~*/
bool CountryList::searchList(string target, Country &out) const
{
    ListNode *pCur = head->next;

    while (pCur != NULL && pCur->ctr.getCode() < target)
    {
         pCur = pCur->next;
    }
    if (pCur != NULL && pCur->ctr.getCode() == target)
    {
        out = pCur->ctr;
        return true;
    }
    return false;
}
/*~*~*~*~*~*~
  Destructor
  This function deletes every node in the list.
*~*/
CountryList::~CountryList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node

    // Position nodePtr at the head of the list.
    pCur = head->next;

    // While pCur is not at the end of the list
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;

        // Delete the current node.
        //cout << "DEBUG - Destructor: Now deleting " << pCur->ctr.getName() << endl;
        delete pCur;

        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node with population = "
         << head->ctr.getPopulation() << endl << endl;
    delete head; // delete the sentinel node
}
