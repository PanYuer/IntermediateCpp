// Specification file for the Rtriangle class

#ifndef RTRIANGLE_H
#define RTRIANGLE_H

class Rtriangle
{
private:
    double sideA;
    double sideB;

public:
    // setters
    void setSideA(double);
    void setSideB(double);

    // getters
    double getSideA() const;
    double getSideB() const;
    
    // other functions
    double calcHypotenuse() const;
    double calcArea() const;

};
#endif
