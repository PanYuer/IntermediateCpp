/***
 22B - PROGRAM 1C: Search a Sorted List of Strings
 BINARY SEARCH
 
 
 Written by:
 IDE:
 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAXSIZE = 128; // maximum size of the arrays

// Function prototypes
void printIntro(void);
void printEnd(void);
void readData(string eList[], string hList[], int &size, const int MAXSIZE);
void writeDataToFile(const string eList[], const string hList[], const int num_searched[], const int size, const string &filename);
int binarySearch(const string array[], const int size, const string &value);
void displayResults(const string[], const string[], int);

int main()
{
    int size = 0;
    string eList[MAXSIZE];
    string hList[MAXSIZE];
    int num_searched[MAXSIZE];
    string eWord;

    // Show the Welcome message
    printIntro();

    // read words from input file into the arrays
    readData(eList, hList, size, MAXSIZE);

    // Initialize num_searched array to 0
    int num_searched[MAXSIZE] = {0};

    // for (int i = 0; i < size; i++)
    // {
    //     num_searched[i] = 0;
    // }

    char again; // To hold a Y or N answer

    do
    {
        // Get the English word user enters
        cout << "Please enter a word in English: " << endl;
        cin >> eWord;

        // How many times does the user search the word?
        int index = binarySearch(eList, size, eWord);

        // Display the results of the search.
        if (index == -1)
        {
            cout << "Sorry, we do not have " << eWord << " in our dictionary.\n";
        }
        else
        {
            displayResults(eList, hList, index);
            num_searched[index]++;
        }

        // Does the user want to do this again?
        cout << "Do you want to search again? (y/n) ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    // write search results to output file
    writeDataToFile(eList, hList, num_searched, size, "results.txt");

    // show the end of the program message
    printEnd();

    return 0;
}

/**************************************************************************
 This function displays the welcome message and the purpose of the program.
 **************************************************************************/
void printIntro()
{
    cout << "Welina!" << endl
         << "Welcome!" << endl
         << "This program translates English words to Hawaiian." << endl;
}

/*************************************************************************
This function displays the end-of-the-program message.
**************************************************************************/

void printEnd()
{
    cout << "Your search history has been saved into an output file named “results.txt”." << endl;
}

/*************************************************************************
 This function prompts the user to enter the name of the input file. 
 It then reads the data from input file into two parallel arrays, 
 one storing English words, the other storing the Hawaiian ones.
 *************************************************************************/
void readData(string eList[], string hList[], int &size, const int MAXSIZE)
{
    string inputfilename;
    ifstream inputFile;

    // prompt user for filename
    cout << "\nWhat is the input file’s name? \n";
    cin >> inputfilename;

    // open the input file
    inputFile.open(inputfilename.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }

    // reading data from the input file into arrays
    int index = 0;
    while (index < MAXSIZE && inputFile >> eList[index] >> hList[index])
    {
        index++;
    }
    size = index;
    if (size == MAXSIZE && !inputFile.eof())
    {
        cout << "\n\tThe input file  \"" << inputfilename
             << "\" is too big: \n\tit has more than "
             << MAXSIZE << " items!\n";
        exit(EXIT_FAILURE);
    }
    // close the input file
    inputFile.close();
}

/*************************************************************************
 This function writes data from two parallel arrays to a file. 
 *************************************************************************/
void writeDataToFile(const string eList[], const string hList[], const int num_searched[], const int size, const string &filename)
{
    ofstream outputFile;

    //open the output file
    outputFile.open(filename.c_str());

    // display words both in English and Hawaiin
    for (int i = 0; i < size; i++)
    {
        if (num_searched[i] > 0)
        {
            outputFile << num_searched[i] << setw(8) << eList[i] << setw(8) << hList[i] << endl;
        }
    }
    //close the output file
    outputFile.close();
}
/*********************************************************************
Definition of binarySearch function                          
The binarySearch function performs a binary search on a string array.  
If the corresponding word is found, its array subscript is returned. 
Otherwise, -1 is returned indicating the value is not in the array.    
*********************************************************************/

int binarySearch(const string array[], const int size, const string &value)
{
    int first = 0,       // First array element
        last = size - 1, // Last array element
        middle,          // Midpoint of search
        position = -1;   // Position of search value
    bool found = false;  // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint
        if (array[middle] == value)  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
    return position;
}

/******************************************************************************
The displayResults function displays the words in both English and Hawaiian.     
******************************************************************************/
void displayResults(const string eList[], const string hList[], int index)
{
    cout << eList[index] << " in Hawaiian is " << hList[index] << endl;
    cout << endl;
}
/**************************** OUTPUT *********************************
Welina!
Welcome!
This program translates English words to Hawaiian.

What is the input file’s name? 
dictionary.txt
Please enter a word in English: 
bird
bird in Hawaiian is manu

Do you want to search again? (y/n) y
Please enter a word in English: 
room
room in Hawaiian is lumi

Do you want to search again? (y/n) y    
Please enter a word in English: 
hello
hello in Hawaiian is aloha

Do you want to search again? (y/n) y   
Please enter a word in English: 
moon
moon in Hawaiian is mahina

Do you want to search again? (y/n) y
Please enter a word in English: 
moon
moon in Hawaiian is mahina

Do you want to search again? (y/n) n
Your search history has been saved into an output file named “results.txt”.
 */
