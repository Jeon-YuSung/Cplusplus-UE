//프록시 패턴 예제의 구현 파일
#include "proxy.h"

//real의 draw 함수 
void Real::draw(int x, int y) {
	cout << "객체를 " << x << ", " << y << "위치에 그렸습니다 \n";

}

//real의 erase 멤버 함수 
void Real::erase() {
	cout << "객체를 지웠습니다 \n";
}

//Proxy의 생성자 
Proxy::Proxy() {
	real = 0;
}

// 프록시의 소멸자
Proxy::~Proxy() {
	delete real;
}

//프록시의 draw 
void Proxy::draw(int x, int y) {

	if (real == 0) {
		real = new Real;
	}
	real->draw(x, y);
}

// 프록시의 erase 멤버함수
void Proxy::erase() {
	real->erase();
}
