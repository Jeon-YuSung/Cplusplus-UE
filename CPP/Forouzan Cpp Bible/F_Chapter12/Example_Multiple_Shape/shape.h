//12-6. 가상함수를 사용한 shape 클래스 헤더파일

#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;

class Shape {

private:
	virtual bool isValid() const = 0;
public:
	
	virtual void print() const= 0;
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
};

#endif // !1
