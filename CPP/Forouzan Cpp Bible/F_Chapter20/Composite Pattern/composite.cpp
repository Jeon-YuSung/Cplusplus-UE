// 포인트와 멀티포인트의 클래스 구현 파일

#include "composite.h"

// 포인트의 생성자
Point::Point(double x, double y) {

	point.first = x;
	point.second = y;

}

// 포인터의 show 멤버 함수
void Point::show() {

	cout << "(" << point.first << ", " << point.second << ")\n";
}

//멀티 포인트의 생성자
Multipoint::Multipoint() {
	size = 0;
}

//멀티 포인트의 addpoint 함수 
void Multipoint::addPoint(Figure* point) {
	points.push_back(point);
	size++;
}

//멀티 포인트의 show 멤버 함수 
void Multipoint::show() {

	for (int i = 0; i < size; i++) {
		points[i]->show();
	}
}
