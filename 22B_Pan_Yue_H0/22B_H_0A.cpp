/***
 22B - PROGRAM 0A:
 ARRAYS and FUNCTIONS: SEARCHING using the Linear Search function
                          // also known as Sequential Search
 
 Find and fix errors. Run the program once and save the output as a comment at the end 
 of the source file.
 
 
 Changed by:
 IDE:
 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int searchAry(int array[], int size, int target);

int main()
{
    int list[] = {40, 30, 50, 13, 35, 48, 14, 31, 18, 33};
    // int * list = {40, 30, 50, 13, 35, 48, 14, 31, 18, 33};
    int length = 10;

    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    // SEARCH 20 times
    srand(time(NULL));
    for (int i = 0; i < 2 * length; i++)
    {
        // generate a random target within the range 1 to 100
        int target = rand() % 100 + 1; // （rand()%(100-1+1)) + 1
        int location = searchAry(list, length, target);
        if (location != -1)
            cout << target << " FOUND at location: " << location << endl;
        else
            cout << target << " NOT found!" << endl;
    }

    return 0;
}

/***************************************************
 This function searches a list of integers for a given target
 It returns -1 if not found.
 It returns the index of the first element in the array that is equal to
 the target value.
 */
int searchAry(int array[], int size, int target)
{
    int index = 0; // Used as a subscript to search array

    while (index < size)
    {
        if (array[index] == target) // If the value is found
        {
            return index; // return position
        }
        index++; // Go to the next element
    }
    return -1; // Return -1, value not found
}

/************** OUTPUT
40 30 50 13 35 48 14 31 18 33 
11 NOT found!
23 NOT found!
8 NOT found!
30 FOUND at location: 1
13 FOUND at location: 3
37 NOT found!
83 NOT found!
36 NOT found!
89 NOT found!
90 NOT found!
74 NOT found!
38 NOT found!
65 NOT found!
44 NOT found!
81 NOT found!
45 NOT found!
21 NOT found!
25 NOT found!
8 NOT found!
50 FOUND at location: 2
 */