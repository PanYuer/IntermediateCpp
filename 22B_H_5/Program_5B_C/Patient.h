// Specification file for the Patient class
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

// Write a definition of a class
class Patient
{
private: // The class Patient has the following member variables
    string name;
    int age;
    int weight;
    double height;

public:                                        // The class Patient has the following member functions
    Patient(string n, int a, double h, int w); // Constructor

    Patient(){}; // Default constructor

    // setters
    void setName(string);
    void setAge(int);
    void setWeight(int);
    void setHeight(double);

    // getters
    string getName() const // class declaration
    {
        return name;
    }
    int getAge() const
    {
        return age;
    }
    int getHeight() const
    {
        return height;
    }
    double getWeight() const
    {
        return weight;
    }
    // other functions
    void display();
    string weightStatus();
};
#endif
