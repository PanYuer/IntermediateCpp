/*~*~*~*~*~*~
   CIS 22B (15Points)
   
   A class has an even number of students. This program divides the class in two
   equal groups. It uses dynamically allocated arrays to store the names of the
   students in each group.
 
REQUIREMENTS:
   1. Find and fix all errors (8 to 10 errors, depending on how you count them)
              a. comment the line with an error
              b. fix the error below
              c. briefly explain what was the error
   3. Simplify the createGroups() function using only one loop instead of two
   2. Run the program.
   3. Save the output as a comment at the end of the source file.
   4. Write your name and IDE below
 
 NAME: Pan Yue
 IDE: VS Code
*~*/
 
#include <iostream>
#include <ctime> // Error1: Needed for ctime
#include <string> // Error2: Neeed for string

using namespace std;

// const double NO_STU = 40; // Error3: NO_STU should be an int instead of double.
const int NO_STU = 40;

// void createGroups(const string myClass[], int no_stu, string *group1, string *group2);
// Error4: pass group1 and group2 by reference to avoid creating a local variable
void createGroups(const string myClass[], int no_stu, string *&group1, string *&group2);

void printList(const string *, int);
void showTimeStamp();

int main()
{
    int no_stu = 8;
    
    string myClass[NO_STU] = { "Ann", "Tom", "Linda", "Bob", "Mary", "Jo", "Tim", "Jamie"};
    string* group1;
    string* group2;
    
    createGroups(myClass, no_stu, group1, group2);
    printList( myClass, no_stu);        // print the original list
    printList( group1, no_stu / 2 );    // print the first group
    printList( group2, no_stu / 2 );    // print the second group
    
    //delete [] myClass;                  // release memory
    // Error5: myclass has not been dynamically allocated , so its memory should not be released
    delete [] group1;
    delete [] group2;
    showTimeStamp();
    return 0;
}

/*~*~*~*~*~*~
 This function takes an array of strings and
 its number of elements and displays its contents
 on the same line
*~*/
void printList(const string *list, int size) 
{
    for( int i = 0; i < size; i++ )// Error6: index should begin with 0 (off by one error)
    {
        cout <<  list[i] << " ";
    }
    cout << endl;
}

/*~*~*~*~*~*~
  This function takes an array of strings and
  its number of elements, and creates two arrays
  group1 - contains the even numbered elements
  group2 - contains the odd numbered elements
*~*/
// Error7: fix function signature to align with change to prototype.
void createGroups(const string myClass[], int no_stu, string *&group1, string *&group2)
{
    int half = no_stu / 2;
    
    // group1 = new string; // allocate memory for the new array
    group1 = new string[half]; // Error9: pass size to the new array
    // group2 = new string; // allocate memory for the new array
    group2 = new string[half];

    /*
    for ( int i = 0, k = 0; k < half; i += 2, k++ )
    {
        group1[k] = myClass[i];
    }
    
    for ( int i = 1, k = 0; k < half; i += 2, k++)
    {
        group2[k] = myClass[i];
    }
    */
    
    // Simplify the createGroups() function using only one loop instead of two
    for (int i = 0; i < no_stu; i++)
    {
        if (i % 2 == 0)
        {
            group1[i/2] = myClass[i];
        }
        else
        {
            group2[i/2] = myClass[i];
        }
    }
}
/*~*~*~*~*~*~
   This function displays the current date and time
           // It does not have any error
           // Do not remove!
*~*/
void showTimeStamp()
{
    time_t timeval = time(0);
    char *chtime = ctime(&timeval);
    cout << "\n\t ~*~ " << chtime;
}
/*~*~*~*~*~*~ Save the output below

Ann Tom Linda Bob Mary Jo Tim Jamie 
Ann Linda Mary Tim 
Tom Bob Jo Jamie 

	 ~*~ Mon Mar 23 13:28:06 2020

*~*/



