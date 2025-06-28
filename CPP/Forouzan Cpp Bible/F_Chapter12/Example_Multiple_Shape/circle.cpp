#include "circle.h"

Circle::Circle(double r) : radius(r) {
	
	if (!isValid()) {
		cout << "유효하지않은 원형입니다 \n";
		assert(false);
	}
}
Circle::~Circle() {}
void Circle::print() const {
	cout << "원의 반지름 : " << radius << endl;
}
double Circle::getArea() const {
	return (3.14 * radius * radius);
}
double Circle::getPerimeter() const {
	return(radius * 2 * 3.14);
}
bool Circle::isValid() const {
	return(0 < radius);
}
