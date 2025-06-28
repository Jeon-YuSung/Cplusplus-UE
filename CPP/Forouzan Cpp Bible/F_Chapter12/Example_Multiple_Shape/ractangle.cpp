#include "rectangle.h"

Rectangle::Rectangle(double lg, double wd) : length(lg), width(wd){
	if (!isValid()) {

		cout << "유효하지않은 직사격형입니다 \n";
		assert(false);
	}

}
Rectangle::~Rectangle() {}
void Rectangle::print() const {
	cout << " 직사격형의 크기 : " << length << " X " << width << endl;

}
double Rectangle::getArea() const {
	return length * width;
}
double Rectangle::getPerimeter() const {
	return 2 * (length + length);
}
bool Rectangle::isValid() const {
	return (length > 0.0 && width > 0.0);
}
