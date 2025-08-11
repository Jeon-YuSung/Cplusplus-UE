// Shpae는 추상 클래스, 스퀘어와 써클은 구체 클래스
#include "factory.h"

Shape* Shape::factory(string type) {

	if (type == "square") {
	
		return(Square::factory());
	}
	else if (type == "circle") {
		return (Circle::factory());
	}
	else {
		cout << "주어진 형태의 도형 객체를 생성할 수 없습니다. ";
		assert(false);
	}
}

//Shape 클래스의 가상 소멸자 정의 
Shape::~Shape() {}

// Square의 생성자 정의
Square::Square() {}

//Square 클래스의 정적 factory 함수 정의 
Shape* Square::factory() {
	return new Square();
}

//Square 클래스의 draw 함수 정의
void Square::draw() {

	cout << "사각형 객체를 그렸습니다 \n";
}

//써클 함수의 팩토리 함수 정의
Shape* Circle::factory() {
	return new Circle();
}

Circle::Circle() {}

void Circle::draw() {

	cout << "Circle 객체를 그렸습니다 \n";
}
