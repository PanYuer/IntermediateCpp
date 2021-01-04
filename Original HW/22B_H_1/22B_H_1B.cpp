/***
 22B - PROGRAM 1B:
 INSERTION SORT
 
 Find and fix errors. Run the program once and save the output as a comment at the end
 of the source file.
 
 Changed by:
 IDE:
 
 */

#include <iostream>

using namespace std;

void insertionSort(int ary[], int size)

int main()
{
    double list[100] = {50.1, 30.2, 80.3, 10.5, 30.2, 40.9, 90.8, 30.2, 80.8, 30.5};
    int size = 10;
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    void insertionSort(int array[], int size);
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/***************************************************
 This function sorts an array in descending order
 using the Insertion Sort algorithm
 */
void insertionSort(int ary[], int size)
{
    int temp;
    int curr;
    int walk;
    
    for (curr = 1; curr < size; curr++)
    {
        // make a copy of the current element
        temp = ary[curr];
        
        // shift elements in the sorted part of the list to make room
        walk = curr - 1;
        while( walk >= 0 && temp < ary[walk] )
        {
            ary[walk + 1] = ary[walk];
            walk--;
        }
        
        // put the copy of the current element back into the list
        ary[walk + 1] = temp;
    }// end of for: move to the next element to be inserted
}


/****************** OUTPUT
 
 */
