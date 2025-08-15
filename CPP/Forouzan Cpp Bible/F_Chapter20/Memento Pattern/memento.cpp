// 메멘토 패턴 구현 파일
#include "memento.h"

// Originator 클래스의 생성자는 메멘토 클래스에 대한 포인터를 캡슐화 
Originator::Originator() {
	memento = new Memento;
}

// Origitnator 소멸자는 메멘토 객체를 제거, 메모리 누수를 막음
Originator::~Originator() {
	delete memento;
}

std::string Originator::getState() const {
	return state;
}

void Originator::setState(std::string st) {

	memento->setState(state);
	state = st;
}

void Originator::restoreState() {
	state = memento->getState();
}

std::string Memento::getState() const {
	return state;
}

void Memento::setState(std::string st) {
	state = st;
}
