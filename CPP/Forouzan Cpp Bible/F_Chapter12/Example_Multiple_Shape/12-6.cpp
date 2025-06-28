// 12-6. shape클래스를사용한 어플리케이션 
#include "square.h"
#include "rectangle.h"
#include "Circle.h"


int main(void) {
	
 //Square 
	cout << "정사각형의 정보 \n";
	Square square(5);
	square.print();
	cout << " 넓이 : " << square.getArea() << endl;
	cout << " 둘레 : " << square.getPerimeter() << endl;
	cout << endl;

	//Rectangle
	cout << "직사격형의 정보 \n";
		Rectangle rectangle(5, 4);
		rectangle.print();
		cout << " 넓이 : " << rectangle.getArea() << endl;
		cout << "둘레 : " << rectangle.getPerimeter() << endl;
		cout << endl;

	//Circle 
		cout << "원의 정보 \n";
		Circle circle(7);
		circle.print();
		cout << "원의 넓이 : " << circle.getArea() << endl;
		cout << "원의 둘레 : " << circle.getPerimeter() << endl;
		cout << endl;

	return 0;
}
