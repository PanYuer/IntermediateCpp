// Specification file for the Rectangle class
// This version has a constructor.
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle // Naming convention: choose the class name same as the name of cpp file
{
private:
   double width;
   double length;

public:
   Rectangle(double w, double len); // Constructor
   void setWidth(double);
   void setLength(double);

   double getWidth() const // class declaration
   {
      return width;
   } // only have one return (inline function: preferred when having short function)

   double getLength() const
   {
      return length;
   }

   double getArea() const
   {
      return width * length;
   }
   double getPerim() const
   {
      return 2 * (width + length);
   }
};
#endif