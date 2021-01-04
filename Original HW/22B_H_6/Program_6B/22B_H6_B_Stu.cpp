/*
 CIS 22B: Homework 6B  // Student is a class
 
 This program demonstrates the insertNode, deleteNode, getCount(), and displayList member functions.
 It builds and displays a sorted list
 The list is sorted by gpa
 
 Write a function that displays students with gpa <= a given gpa as show below
 
 list.displayList(3.0);  //<===== see line# 61
 
 
 Run the program once and save the output as a comment at the end of this source file.
 
 Modified by:
 IDE: 
 
 */
#include <iostream>
#include "StudentList.h"
using namespace std;

int main()
{
    // Define a StudentList object.
    StudentList list;
    Student s1(3.1, "Paul");
    Student s[10] =
    {{2.5, "John"}, {3.9, "Linda"}, {3.6, "Bob"}, {2.7, "Ann"}, {4.0, "Mary"}, {3.2, "Andy"}};
    Student s2(2.3, "Tom");
    
    //******************************
    cout << "TESTING INSERT\n\n";
    //Insert one value to the list.
    cout << "\tInsert " << s1.getGpa() << " " << s1.getName() << endl;
    list.insertNode(s1);
    // Display the values in the list.
    list.displayList();
    cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    
    //Insert more values to the list
    for (int i = 0; i < 6; i++)
    {
        cout << "\tInsert " << s[i].getGpa() << " " << s[i].getName() << endl;
        list.insertNode(s[i]);
        // Display the values in the list.
        list.displayList();
        cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    }
    
    //Insert one value to the list.
    cout << "\tInsert " << s2.getGpa() << " " << s2.getName() << endl;
    list.insertNode(s2);
    list.displayList();
    int n = list.getCount();
    cout << "\t\tThis list has " << n << " student[s]\n\n";
    
    //******************************
    cout << "TESTING DISPLAY\n\n";
    list.displayList();
    //list.displayList(3.0);  //<====================================
    
    //******************************
    cout << "TESTING DELETE\n\n";
    // Delete the first node
    cout << "\tDelete the first node\n";
    list.deleteNode(2.3);
    list.displayList();
    
    // Delete the last node
    cout << "\tDelete the last node\n";
    list.deleteNode(4.0);
    list.displayList();
    
    // Delete a node in the middle
    cout << "\tDelete 3.1\n";
    if( list.deleteNode(3.1) )
        cout << "Deleted\n";
    else
        cout << "Target (3.1) not found\n";
    list.displayList();
    
    // Try to delete an item not in the list
    cout << "\tTry to delete 3.0\n";
    if( list.deleteNode(3.0) )
        cout << "Deleted\n";
    else
        cout << "Target (3.0) not found\n";
    list.displayList();
    
    cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    
    return 0;
}
/***************************************************************
 Save the OUTPUT below
 
 
 */
