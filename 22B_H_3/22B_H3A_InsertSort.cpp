/**
 CIS 22B: Homework 3A
 
 This program uses the INSERTION sort algorithm to sort an
 array of integers in ascending order.
 
 Modify the insertion sort function to sort an array of doubles in descending order:
 1. Sort an array of doubles (instead of integers)
 2. Sort it in descending order
 
 NAME: Pan Yue
 IDE: Visual Studio
 */
#include <iostream>
using namespace std;

// Function prototypes
void insertionSort(double *, double *); // change integer into double
void showArray(double *, double *);

int main()
{
    // Define and initialize an array with unsorted values
    const int SIZE = 100;
    //int list[SIZE] = {50, 70, 20, 80, 90, 10};
    double list[SIZE] = {50.5, 70.2, 20.9, 80.3, 90.5, 10.8};
    int length = 6;

    // Display the array.
    cout << "The unsorted values are\n";
    showArray(list, list + length - 1);

    // Sort the array.
    insertionSort(list, list + length - 1);

    // Display the array again.
    cout << "The sorted values are\n";
    showArray(list, list + length - 1);
    return 0;
}

/***************************************************************
 Definition of function insertionSort.
 This function performs a descending order insertion sort on
 array. size is the number of elements in the array.
 ****************************************************************/
void insertionSort(double *pList, double *pLast)
{
    for (double *curr = pList + 1; curr <= pLast; curr++)
    {
        double hold = *curr; // copy current element to hold
        double *back = curr - 1;
        //shift elements in the sorted part of the list to make room
        while (back >= pList && hold > *back) // search where to insert the current element
        // change (hold < *back) into (hold > *back) to perform an descending order
        {
            *(back + 1) = *back; // shift to the right
            back--;
        }
        *(back + 1) = hold; // put hold back to the array
    }
}

/***************************************************************
 Definition of function showArray.
 This function displays the contents of array. size is the
 number of elements.
 ****************************************************************/
void showArray(double *pList, double *pLast)
{
    for (double *ptr = pList; ptr <= pLast; ptr++)
        cout << *ptr << " ";
    cout << endl;
}
/***************************************************************
 Save the new OUTPUT below
 
The unsorted values are
50.5 70.2 20.9 80.3 90.5 10.8 
The sorted values are
90.5 80.3 70.2 50.5 20.9 10.8 
 
 */
