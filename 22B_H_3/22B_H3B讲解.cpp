/**
 CIS 22B: Homework 3B
 
 This program uses dynamic allocation of memory to create a
 copy of an array.
 
 It might compile; if it does, it should give a warning. If you run it, it will crash.
 Find and fix the errors. Write comments to explain the errors. Run the program and save 
 the output as a comment at the end of the source file. 
                                                    Hint: There are THREE logical errors.
NAME: Pan Yue
IDE: Visual Studio
*/
#include <iostream>
#include <iomanip>
using namespace std;

// double *create_array_1()
// {
//     double *array = new double[100];
//     // double* array[100]; // this is wrong
//     return array;
// }

// void create_array_2(double *&array)
// {
//     array = new double[100];
// }

// void create_array_3(double **array)
// {
//     *array = new double[100];
// }

// int main()
// {
//     double *my_array_1 = create_array_1();

//     double *my_array_2;
//     create_array_2(my_array_2);

//     double *my_array_3;
//     create_array_3(&my_array_3);

//     double **ptr_to_ptr = &my_array_3;

//     int array[100];
//     int size = 0;
//     read_array_from_file("sample.txt", array, size);
// }

// Function prototypes
//Solution A
void createCopy(double *pFirst, double *pLast, double *&newList);
/*
//Solution B - the BEST!
double *createCopy(double *pFirst, double *pLast);
//Solution C - multiple indirection example
void createCopy(double *pFirst, double *pLast, double **newList);
*/
void printList(double *pFirst, double *pLast);

int main()
{
    int size = 5;
    double ary[100] = {2.1, 3.5, 8.7, 1.9, 5.6};
    double *list; // will point to a replica of ary

    cout << "DEBUG list = " << list << endl;
    createCopy(ary, ary + size - 1, list);
    cout << "DEBUG list = " << list << endl;
    //ary + size - 1 is the address of the last element in ary
    printList(ary, ary + size - 1);   // print the original array
    printList(list, list + size - 1); // print its copy

    delete[] list; // release memory (that should have been allocated with new)
    //delete[] ary; (This is not a dynamically allocated array) Error#1: Only dynamically allocated array can be deleted.

    return 0;
}

/***************************************************************
 This function prints an array
 PRE: pFirst - pointer to the first element
 pLast - pointer to the last element
 POST: list printed
 ****************************************************************/
void printList(double *pFirst, double *pLast)
{
    double *pWalk;

    cout << setprecision(2) << fixed;
    for (pWalk = pFirst; pWalk <= pLast; pWalk++)
    {
        cout << *pWalk << " ";
    }
    cout << endl;

    return;
}

/***************************************************************
 This function creates a copy of an array
 PRE: pFirst - pointer to the first element
 pLast - pointer to the last element
 POST: list copied to newList
 ****************************************************************/
void createCopy(double *pFirst, double *pLast, double *&newList) //Error#3: Pointers can be passed by reference.
{
    newList = new double[pLast - pFirst + 1]; // allocate memory for the new array
    // cout << "DEBUG size = " << pLast - pFirst + 1 << endl; // Error#2: Not enough memory allocated
    double *pwSource = pFirst;
    double *pwDest = newList;
    for (; pwSource <= pLast; pwSource++, pwDest++)
    {
        *pwDest = *pwSource;
        // cout << "DEBUG " << *pwDest << endl; // DEBUG
    }
    // cout << "DEBUG newList = " << newList << endl;
}
/***************************************************************
  Save the OUTPUT below
  
  
*/
