/**
   CIS 22B: Homework 4B
   C-strings and arrays of pointers 
   
   This program uses a selection sort to sort an array of c-strings.
   It has some errors. Fix the errors and run the program.
   Save the output as a comment at the end of the program.
 
   NAME:
*/

/**
 A NOTE about pointers and constants: pointer constant versus pointer to constant
 
 
 const char *list[10] = {"Mary", "John", "Peter", "Anne",
                         "Paul",  "Andrew", "Linda",  "Diane"};
 
 What is list?
 
 list is an array of 10 pointers to string literals (or constants):
 the strings in the array may not be changed but the pointers pointing to these strings could change.
 
 Therefore the following statement is incorrect
 strcpy(list[0], "Tom"); // This is an attempt to change a constant: replace "Mary" by "Tom"
 
 It is OK to change the pointers in the list:
 list[0] = list[1]; // now both pointers point to "John"
 
 Here are some examples
 
 EXAMPLE ONE: A pointer variable pointing to a constant
 const double PI = 3.14;
 const double EPSILON = 0.001;
 const double *ptr = &PI;
 cout << *ptr << endl;
 
 // *ptr += 1;     //<==== this doesn't work because PI should not change
 ptr = &EPSILON;  // but you are allowed to change ptr, to make it point to another constant
 cout << *ptr << endl;
 
 EXAMPLE TWO: A pointer constant pointing to a constant
 const double PI = 3.14;
 const double EPSILON = 0.001;
 const double * const ptr = &PI; // both ptr and its pointee (PI) are constants
 cout << *ptr << endl;
 
 // *ptr += 10; // doesn't work because its pointee is PI, a constant (it may not be changed)
 // ptr = &EPSILON;  // doesn't work because because ptr is also a constant (it may not be changed)

 */

#include <iostream>
#include <cstring>
using namespace std;


void selectionSort( const char *list[],  int size );

int main( void )
{
    const char *list[10] = {"Mary", "John", "Peter", "Anne",
                         "Paul",  "Andrew", "Linda",  "Diane"};
    int size = 8;  // 8 names in the list

    selectionSort( list, size );

    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}

/** ============================================================== */
/** This function sorts a list of strings using a selection sort
    algorithm.
   	Given: ary  - a list of strings
	       size   - its actual size
*/
void selectionSort( const char *list[],  int size )
{
    const char *hold;
    int last;
    int small;
    int curr;
    int walk;

    last = size - 1;
    for(curr = 0; curr < last; curr++ )
    {
        small = curr;
		for( walk = curr + 1; walk < size; walk++ )
		    if( list[walk] < list[small] )
			    small = walk;

        hold = list[small];
		list[small] = list[curr];
		list[curr] = hold;
    }
    return;
}
/***************************************************************
 Save the OUTPUT below
 
 
 */



