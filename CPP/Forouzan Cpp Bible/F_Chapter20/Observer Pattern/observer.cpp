#include "observer.h"

//서브젝트 클래스의 구독 멤버 함수
void Subject::subscribe(Observer* observer) {

	observers.insert(observer);

}

//subject 클래스의 unsubscribe 멤버 함수 
void Subject::unsubscribe(Observer* observer) {
	observers.erase(observer);
}

// 모든 객체에게 통지하는 서브젝트의 notify 멤버 함수 정의
void Subject::notify(int price) {

	std::set<Observer*>::iterator iter;
	for (iter = observers.begin(); iter != observers.end(); iter++) {
		(*iter)->update(price);
	}
}

//ob1 클래스의 생성자
Observer1::Observer1(Subject* sj) : subject(sj) {}

void Observer1::update(int pirce) {
	std::cout << "옵저버 1의 현재 가격이 " << pirce << "이므로 구매 합니다.\n";

}

//ob2 클래스의 생성자
Observer2::Observer2(Subject* sj) : subject(sj) {}

void Observer2::update(int pirce) {
	std::cout << "옵저버2의 현재 가격이 " << pirce << "이므로 구매 합니다.\n";

}
