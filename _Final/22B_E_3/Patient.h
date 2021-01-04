// Specification file for the Patient class

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>

class Patient
{
private:
    std::string name;
    double height;
    int age;
    int weight;

public:
    // Overload ctor
    Patient(std::string n, double h, int a, int w) {
        name = n;
        age = a;
        weight = w;
        height = h;
    }

    // Default ctor
    Patient() {}
    
    
    void setName(std::string n)
        { name = n; }
    void setHeight(double h)
        { height = h; }
    void setAge(int a)
        { age = a; }
    void setWeight(int w)
        { weight = w; }
    
    std::string getName() const
        { return name; }
    double getHeight() const
        { return height; }
    int getAge() const
        { return age; }
    int getWeight() const
        { return weight; }
    
    void display() const;

    std::string weightStatus() const;

    // Overload ostream op.
    friend std::ostream& operator<< (std::ostream &out, const Patient &patient);
};

#endif

