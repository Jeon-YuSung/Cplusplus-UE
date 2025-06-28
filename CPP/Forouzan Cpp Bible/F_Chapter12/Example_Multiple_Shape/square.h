//12-6. square의 클래스 헤더파일

#ifndef  SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
private:
	double side;
	bool isValid() const;
public:
	Square(double side);
	~Square();
	void print() const;
	double getArea() const;
	double getPerimeter() const;

};
#endif // ! STUDENT_h
