//12-1 불완전한 다형성 프로그램
// 다형성의 2가지 재료를 사용해서 불완전한 다형성을 알아보자.

#include<iostream>
#include<string>
using namespace std;

// 부모 클래스 정의
class Base {
public:
	void print() const { cout << "부모 클래스 \n"; }

};

class Derived : public Base {
public:
	void print() const { cout << "자식 클래스 \n"; }
};

int main(void) {
	
	// ptr 포인터로 부모 클래스의 객체 가르키기
	Base* ptr;
	ptr = new Base();
	ptr->print();
	delete ptr;
	
	// 자식 클래스의 객체 가르키기
	ptr = new Derived();
	ptr->print();
	delete ptr;

	return 0;
}
