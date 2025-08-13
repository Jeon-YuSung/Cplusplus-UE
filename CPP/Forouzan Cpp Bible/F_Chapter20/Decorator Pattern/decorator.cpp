//데코레이터 패턴 구현 파일 

#include "decorator.h"

//컴포넌트 생성자
Component::Component(string tx) : text(tx) {}

// 컴포넌트의 draw구현
void Component::draw() {

	cout << text << endl;
}

//데코레이터 생성자
Decorator::Decorator(Component comp) : component(comp){}

//데코레이터의 draw 생성자 
void Decorator::draw() {

	cout << "**************\n";
	component.draw();
	cout << "***************\n";
}
