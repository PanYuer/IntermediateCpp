// Specification file for the Patient class

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
private:
    std::string name;
    double height;
    int age;
    int weight;

public:

    
    
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
};
#endif

