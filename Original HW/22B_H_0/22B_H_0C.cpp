/***
 22B - PROGRAM 0C: Exam Statistics
 ARRAYS, FUNCTIONS, DATA FILES, and SORTING
 
 The program prompts user to enter the input file containing scores of students along with their ids.
 It stores the data from input file into two parallel arrays.
 It then
 - writes the data to file "scoresOut1.txt" which is sorted in ascending order of student id
 - writes the data to file "scoresOut2.txt" which is sorted in descending order of student score
 - displays highest score followed by the ids of the students with that score
 - displays lowest score followed by the ids of the students with that score
 - total number of students
 - class average
 
 You have three tasks:
 1. Finish writing main() (provide the correct parameters in the calling statements)
 2. There are 3 or 4 minor errors - fix them
 3. Run the program and save the output as a commment at the end of the source file
 (under OUTPUT #3)
 
 Changed by:
 IDE:
 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// Function prototypes
void printIntro(void);
void printEnd(void);
void readStuData(string idList[], int scoreList[], int &size, const int maxSize);
double calcAverage(const int scoreList[], int size);
void displayTarget(const string idList[], const int scoreList[], int size, int targetScore);
void writeDataToFile(const string idList[], const int scoreList[], int size, string filename);
void sortIdAsc(string idList[], int scoreList[], int size);
void sortScoreDesc(string idList[], int scoreList[], int size);

int main()
{
    // Constants definitions
    const string OUTFILE1 = "scoresOut1.txt";
    const string OUTFILE2 = "scoresOut2.txt";
    
    const int SIZE = 50;                // maximum size of array
    //const int SIZE = 5;                 // maximum size of array
    
    // Variables definitions
    string idList[SIZE];              // array of student ids
    double scoresList[SIZE],           // array of test scores
    average = 0.0;
    int size = 0; // actual size of array
    
    // show the welcome message
    printIntro();
    
    // read students' data from input file into the arrays
    //  readStuData(); // <================= what are this function's arguments?
    
    //sort arrays in ascending order by ID and write the sorted arrays to a file
    //  sortIdAsc();        // <=================
    //  writeDataToFile();  // <=================
    cout << "\n\nExams scores and IDs sorted in ascending order by the students' IDs are available in \""
    << OUTFILE1 << "\"." << endl;
    
    //sort arrays in descending order by score and write the sorted arrays to a file
    //sortScoreDesc();    // <=================
    //writeDataToFile();  // <=================
    cout << "\nExams scores and IDs sorted in descending order by the students' scores are available in file \""
    << OUTFILE2 << "\"." << endl;
    
    // show highest scores & the matching IDs
    //displayTargetScore();    // <=================
    // show lowest scores & the matching IDs
    //displayTargetScore();   // <=================
    
    // display the number of students and the class average
    cout << fixed << showpoint << setprecision(2);
    cout << "\nTotal students in class: " << size << endl;
    //average = calcAverage();  // <=================
    cout << "Class average: " << average <<  endl;
    
    // show the end of the program message
    printEnd();
    
    return 0;
}


/******************************************************
 This function displays the welcome message and the purpose of the program.
 */
void printIntro(void)
{
    cout << "\n\n\t\t *~~*~~* WELCOME *~~*~~*\n\n"
    << "\tto the Exam Score Calculator and Sorter!\n\n"
    << "\t\tThis program will: \n"
    << "\t\t - obtain the students' scores and IDs from an input file \n"
    << "\t\t - calculate the class average,\n "
    << "\t\t - sort in ascending order by student ID, \n"
    << "\t\t - write the sorted scores and IDs to an output file\n"
    << "\t\t - sort in descending order by score, \n"
    << "\t\t - write the sorted scores and IDs to another output file, and \n"
    << "\t\t - show the highest and lowest scores and the matching IDs \n\n";
}


/******************************************************
 This function displays the end-of-the-program message.
 */
void printEnd(void)
{
    cout << "\n\n\t\t *~~*~~* THE END *~~*~~*\n"
    << "\t     Thank you for using my program! \n\n";
}


/******************************************************
 This function prompts the user to enter the name of the input file. 
 It then reads the data from input file into two parallel arrays, 
 one storing student ids, the other storing their scores.
 */
void readStuData(string idList[], int scoreList[], int &size, const int maxSize)
{
    string inputfilename;
    ifstream inputFile;
    
    // prompt user for filename
    cout << "\nPlease enter the name of the file that holds the students' scores and IDs: \n";
    cin >> inputfilename;
    
    // open the input file
    inputFile.open(inputfilename.c_str());
    if (inputFile.fail())
    {
        cout << "\n\tPlease check the name of the input file and \n\ttry again later!\n";
        exit(EXIT_FAILURE);
    }
    
    // reading data from the input file into arrays
    int idx = 0;
    while (idx < maxSize && inputFile >> idList[idx] >> scoreList[idx])
    {
        idx++;
    }
    size = idx;
    if ( size == maxSize && !inputFile.eof())
    {
        cout << "\n\tThe input file  \"" << inputfilename
        << "\" is too big: \n\tit has more than "
        << maxSize << " items!\n";
        exit(EXIT_FAILURE);
    }
    // close the input file
    inputFile.close();
}

/******************************************************
 This function calculates and returns the scores in an array
 */
double calcAverage(const int scoreList[], int size)
{
    int sum = 0;
    
    for (int i = 0; i <= size ; i++)
        sum += scoreList[i];
    
    return sum / (size - 1);
}


/******************************************************
 This function displays the ids of the students with the 
 same targetScore
 */
void displayTarget(const string idList[], const int scoreList[], int size, int targetScore)
{
    cout << "\nTarget score: \t" << targetScore << endl
    << "Students:" << endl;
    int i = 0;
    while (i < size && scoreList[i] == targetScore)
    {
        cout << "\t\t" << idList[i] << endl;
        i--;
    }
    cout << "\n\t\t" << i << " student[s] got the same (" << targetScore << ") score!\n\n";
}


/******************************************************
 This function writes data from two parallel arrays to a file. 
 */
void writeDataToFile(const string idList[], const int scoreList[], int size, string filename)
{
    ofstream outputFile;
    
    //open the output file
    outputFile.open(filename.c_str());
    
    // display ids and scores
    for (int i = 0; i < size ; i++)
    {
        outputFile << idList[i]
        << fixed << showpoint << setprecision(2) << setw(8)<< scoreList[i]
        << endl;
    }
    
    //close the output file
    outputFile.close();
}

/******************************************************
 This function accepts two parallel arrays and their size and 
 sorts them in ascending order of the first array
 */
void sortIdAsc(string idList[], int scoreList[], int size)
{
    string tempId;
    int tempScore;
    int lowIdx;
    
    for (int i = 0; i < size - 1; i++)
    {
        // find index of the lowest ID
        lowIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (idList[lowIdx] > idList[j])
                lowIdx = j;
        }
        // swap IDs
        tempId = idList[i];
        idList[i] = idList[lowIdx];
        idList[lowIdx] = tempId;
        
        // swap scores
        tempScore = scoreList[i];
        scoreList[i] = scoreList[lowIdx];
        scoreList[lowIdx] = tempScore;
    }
}

/******************************************************
 This function accepts two parallel arrays and their size and
 sorts them in ascending order of the secomd array
 */
void sortScoreDesc(string idList[], int scoreList[], int size)
{
    string tempId;
    int tempScore;
    int highIdx;
    
    for (int i = 0; i < size - 1; i++)
    {
        // find index of the smallest score
        highIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (scoreList[highIdx] < scoreList[j])
                highIdx = j;
        }
        // swap IDs
        tempId = idList[i];
        idList[i] = idList[highIdx];
        idList[highIdx] = tempId;
        
        // swap scores
        tempScore = scoreList[i];
        scoreList[i] = scoreList[highIdx];
        scoreList[highIdx] = tempScore;
    }
}


/****************** OUTPUT #1 ******************
 
 *~~*~~* WELCOME *~~*~~*
 
	to the Exam Score Calculator and Sorter!
 
 This program will:
 - obtain the students' scores and IDs from an input file
 - calculate the class average,
 - sort in ascending order by student ID,
 - write the sorted scores and IDs to an output file
 - sort in desecending order by score,
 - write the sorted scores and IDs to another output file, and
 - show the highest and lowest scores and the matching IDs
 
 
 Please enter the name of the file that holds the students' scores and IDs:
 scores.txt
 
	The input file  "scores.txt" is too big:
	it has more than 5 items!
 
 
 *~~*~~* THE END *~~*~~*
 Thank you for using my program!
 */

/****************** OUTPUT #2 ******************
 
 *~~*~~* WELCOME *~~*~~*
 
	to the Exam Score Calculator and Sorter!
 
 This program will:
 - obtain the students' scores and IDs from an input file
 - calculate the class average,
 - sort in ascending order by student ID,
 - write the sorted scores and IDs to an output file
 - sort in desecending order by score,
 - write the sorted scores and IDs to another output file, and
 - show the highest and lowest scores and the matching IDs
 
 
 Please enter the name of the file that holds the student's scores:
 ids.txt
 ERROR: Could not open file: "ids.txt".
	Please check the name of the input file and
	try again later!
 
 
 *~~*~~* THE END *~~*~~*
 Thank you for using my program!
 */

/**********************************************
****************** OUTPUT #3 ******************
 
 */