#include "square.h"


Square::Square(double s) : side(s) {
	if (!isValid()) {
	
		cout << "유효하지않은 정사격형입니다 \n";
		assert(false);
	}
}
Square::~Square() {} 
void Square::print() const {
	cout << " 정사각형의 크기 : " << side << endl;

}

double Square::getArea() const {
	return(side * side);

}
double Square::getPerimeter() const {
	return(4 * side);

}

bool Square::isValid() const {
	return(side > 0.0);
}
