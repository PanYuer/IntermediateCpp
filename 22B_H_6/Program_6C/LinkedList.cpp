// Implementation file for the LinkedList class
// Written By: Pan Yue
// IDE: VS Code

#include <iostream> // For cout  and NULL
#include "LinkedList.hpp"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
LinkedList::LinkedList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************

void LinkedList::displayList() const
{
    ListNode *cur = head->next;
    while (cur)
    {
        cur->college.hDisplay();
        cur = cur->next;
    }
}

//**************************************************
// Count the number of nodes in the linkedlist
//**************************************************
int LinkedList::count() const
{
    ListNode *cur = head->next;
    int cnt = 0;
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

//**************************************************
// searchNode searches the linked list for a node
// with code as its value. The node, if found, will
// contain corresponding information of colleges
// such as name, rank and cost.
//**************************************************
const College *LinkedList::searchNode(string code) const
{
    ListNode *cur = head->next;
    while (cur)
    {
        // check if the node contains the college of interest
        if (cur->college.getCode() == code)
        {
            return &(cur->college);
        }
        cur = cur->next;
    }
    return nullptr;
}

//**************************************************
// The insertCode function inserts nodes into the
// linked list according to the code order. If there
// is a duplicate college code, return false;
// otherwise, return true;
//**************************************************
bool LinkedList::insertNode(College college)
{
    ListNode *pre = head;
    ListNode *cur = head->next;
    while (cur && cur->college.getCode() < college.getCode())
    {
        pre = cur;
        cur = cur->next;
    }
    // corner case: we don't want to insert a new node if a college already exists
    if (cur && cur->college.getCode() == college.getCode())
    {
        return false;
    }

    ListNode *new_node = new ListNode;
    new_node->college = college;
    pre->next = new_node;
    new_node->next = cur;
    return true;
}

//**************************************************
// The deleteNode function searches for a node
// with code as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool LinkedList::deleteNode(string code)
{
    ListNode *pCur = head;       // To traverse the list
    ListNode *pPre = head->next; // To point to the previous node

    // Attempt to find the node
    while (pCur && pCur->college.getCode() != code)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // If found, delete the node
    if (pCur)
    {
        pPre->next = pCur->next;
        delete pCur;
        return true;
    }
    return false;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
LinkedList::~LinkedList()
{
    ListNode *pCur = head->next; // To traverse the list
    ListNode *pNext;             // To point to the next node

    // While pCur is not at the end of the list...
    while (pCur)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;

        // Delete the current node.
        // cout << "DEBUG - Destructor: Now deleting " << pCur->college.getName() << endl;
        delete pCur;

        // Position pCur at the next node.
        pCur = pNext;
    }
    delete head; // delete the sentinel node
}
