/**
 CIS 22B: Homework 4C
 Strings and Structures
 
 Project: Star Search
 
 NAME: Pan Yue
 IDE: VS Code
 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

/* Define a struct named Performer with the following fields:
 
 1. name (string)
 2. scores (an array of 5 doubles)
 3. final (double)
 
 */

const int SCORE_SIZE = 5;
const int MAX_PERFORMERS = 100;
const int MAX_CHAR = 100;
// Declare a struct
struct Performer
{
    string name;
    double scores[SCORE_SIZE];
    double final;
};

// Function prototypes
void printWelcome(void);
Performer *readPerfData(string filename, int &num, const int SCORE_SIZE);
double calculateFinalScore(double *scores, int size);
void updateFinalScore(Performer performers[], int num);
void insertionSort(Performer performers[], int num);
void writeFile(Performer performers[], int num, const string &filename);
void printAll(Performer performers[], int num);
void displayResults(Performer performers[], int num);
void printEnd(void);

int main(void)
{
    string inFileNames[] = {"performers.txt", "contestants.txt", "test.txt", "testempty.txt", ""};
    int choice = 1; // to stop the program to allow the user to see the results one file at a time

    for (string *ptr = inFileNames; choice == 1 && *ptr != ""; ptr++) // test loop: takes the names of 4 input files from an array
    {
        printWelcome();
        int num; // num of performers
        Performer *performers = readPerfData(*ptr, num, SCORE_SIZE);
        // Read data successfully so performers is not nullptr
        if (performers)
        {
            updateFinalScore(performers, num);
            insertionSort(performers, num);
            // print out all performers for debugging
            // printAll(performers, num);
            writeFile(performers, num, *ptr);
            displayResults(performers, num);
            printEnd();
        }

        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
        delete[] performers;
    }

    return 0;
} // main
/********************************************
 This function displays the welcome message.
 */
void printWelcome(void)
{
    cout << "Welcome\n";
}

/******************************************************************
 This function reads the data from input file into two parallel arrays, 
 one storing performers' names, the other storing their scores.
 */

Performer *readPerfData(string filename, int &num, const int SCORE_SIZE)
{
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail())
    {
        return nullptr;
    }

    // read num of rows
    string rows;
    getline(fin, rows);
    num = atoi(rows.c_str());

    // allocate the array of performer structures on heap
    Performer *ptr = new Performer[num];

    // read each row into a performer
    for (int i = 0; i < num; i++)
    {
        // Ignore the '\n' from last line.
        // fin.ignore();
        string line;
        getline(fin, line);
        stringstream ss;
        ss << line;

        // read in the name before ';'
        string name;
        getline(ss, name, ';');
        //skip the first whitespace before score
        ss.ignore();

        // read in the scores and change strings into double
        double *scores = ptr[i].scores;
        string score;
        for (int j = 0; j < SCORE_SIZE - 1; j++)
        {
            getline(ss, score, ' ');
            scores[j] = atof(score.c_str());
        }
        // read the last score
        getline(ss, score);
        scores[SCORE_SIZE - 1] = atof(score.c_str());
        ptr[i].name = name;
    }
    fin.close();
    return ptr;
}

/******************************************************************
 This function calculates and returns the performers' final score 
 by dropping the highest and the lowest score and then averaging 
 the three remaining scores.
 */
double calculateFinalScore(double *scores, int size) // <== add parameters, change void if needed
{
    double lowest = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] < lowest)
            lowest = scores[i];
    }

    double highest = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] > highest)
            highest = scores[i];
    }

    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += scores[i];

    double final = (sum - lowest - highest) / (size - 2);

    return final;
}

/*******************************************************************
 * For each performer in a performer array, update its final score field.
 */
void updateFinalScore(Performer performers[], int num)
{
    for (int i = 0; i < num; i++)
    {
        performers[i].final = calculateFinalScore(performers[i].scores, SCORE_SIZE);
    }
}

/*******************************************************************
This function sorts the array of performers in descending order by the final score 
using the insertion sortalgorithm.
 */
void insertionSort(Performer performers[], int num) // <== add parameters, change void if needed
{
    Performer temp;
    int curr;
    int walk;

    for (curr = 1; curr < num; curr++)
    {
        // make a copy of the current element
        temp = performers[curr];

        // shift elements in the sorted part of the list to make room
        walk = curr - 1;
        while (walk >= 0 && temp.final > performers[walk].final) //sort the array in descending order
        {
            performers[walk + 1] = performers[walk];
            walk--;
        }

        // put the copy of the current element back into the list
        performers[walk + 1] = temp;
    }
}

/******************************************************************
 This function writes an array of Performer structures to a file. 
 */
void writeFile(Performer performers[], int num, const string &filename) // <== add parameters, change void if needed
{
    string outputName;
    string basename;

    for (int i = 0; i < filename.size(); i++)
    {
        if (filename[i] == '.')
        {
            break;
        }
        basename += filename[i];
    }
    outputName = basename + "out.txt";

    cout << "Write report to file: "
         << outputName << endl;

    ofstream outputFile;

    //open the output file
    outputFile.open(outputName.c_str());
    if (outputFile.is_open())
    {
        // display ids and scores
        outputFile << left << setw(20) << "Name" << right << setw(30) << "Scores" << right << setw(30) << "Final Score" << endl;
        for (int i = 0; i < num; i++)
        {
            // print performer's name
            outputFile << left << setw(20) << performers[i].name << " ";
            // print performer's scores
            for (int j = 0; j < SCORE_SIZE; j++)
            {
                outputFile << fixed << showpoint << setprecision(1) << right << setw(8) << performers[i].scores[j] << " ";
            }
            outputFile << fixed << showpoint << setprecision(2) << right << setw(10) << performers[i].final;
            outputFile << endl;
        }

        //close the output file
        outputFile.close();
    }
}

/******************************************************************
 Helper function to print one performer to screen
 */
void printOnePerformer(Performer &performer)
{
    cout << left << setw(20) << performer.name;
    // print performer's scores
    for (int j = 0; j < SCORE_SIZE; j++)
    {
        cout << fixed << showpoint << setprecision(1) << right << setw(8) << performer.scores[j];
    }
    cout << endl;
}

/******************************************************************
 This function displays highest score, the winner’s names and scores. 
 If two or more performers have the same highest score, all are 
 considered winners.
 */
void displayResults(Performer performers[], int num) // <== add parameters, change void if needed
{
    cout << "Display the winners and their scores\n";

    double highest = -1;
    for (int i = 1; i < num; i++)
    {
        if (performers[i].final > highest)
        {
            highest = performers[i].final;
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (performers[i].final == highest)
        {
            printOnePerformer(performers[i]);
        }
    }
}
/*******************************************************************
Helper debug function to print all performers to screen
*/
void printAll(Performer performers[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printOnePerformer(performers[i]);
        cout << "final = "
             << fixed << showpoint << setprecision(2)
             << right << setw(8) << performers[i].final << endl;
    }
}

/******************************************************
 This function displays the end-of-the-program message.
 */
void printEnd(void)
{
    cout << "Good Bye!\n";
}

/** Save the output below
 
 Welcome
Write report to file: performersout.txt
Display the winners and their scores
David T. Ng              8.3     2.9     9.8     9.2     9.7
Good Bye!
Please enter 1 to continue 0 to stop
1       
Welcome
Write report to file: contestantsout.txt
Display the winners and their scores
James Michael Owen       9.9     9.6     9.9     9.0     9.3
Marie Kondo              9.6     9.0     9.9     9.9     9.3
Tina Queen               9.0     9.6     9.9     9.9     9.3
Jonathan Edwards         9.9     9.6     9.0     9.9     9.3
Good Bye!
Please enter 1 to continue 0 to stop
1
Welcome
Write report to file: testout.txt
Display the winners and their scores
John Lee                 8.3     7.5     8.9     9.9     8.6
David T. Ng              8.3     8.9     9.9     8.6     7.5
Mary Johnson             8.3     7.5     8.9     8.6     9.9
Andy V. Garcia           7.5     8.3     8.9     9.9     8.6
John Lee                 9.9     8.3     7.5     8.9     8.6
Ann Peterson             8.3     8.9     9.9     7.5     8.6
Dan Nguyen               8.3     9.9     7.5     8.9     8.6
Good Bye!
Please enter 1 to continue 0 to stop
1
Welcome
Write report to file: testemptyout.txt
Display the winners and their scores
Good Bye!
Please enter 1 to continue 0 to stop
0

 */