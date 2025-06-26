/*
11-4. 구현파일
person 클래스의 구현 파일.
*/


#include "person.h"

// 생성자 
Person::Person(string nm) : name(nm) {}
Person::~Person() {}//소멸자
void Person::print() const {

	cout << " 이름 : " << name << endl;

}
