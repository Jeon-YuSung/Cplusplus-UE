#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <cassert>

using namespace std;

//클래스 정의
class Circle
{
private:
double radius;
public:
Circle(double radius);
Circle();
Circle(const  Circle& circle);
~Circle();
void setRadius(double radius);
double getRadius() const;
double getArea() const;
double getPerimeter() const; 
}

#endif
