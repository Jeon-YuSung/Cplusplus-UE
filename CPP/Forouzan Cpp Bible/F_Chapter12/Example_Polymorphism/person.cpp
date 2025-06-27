//12-3 person의 구현 파일

#include "person.h"

Person::Person(string ne) : name(ne) {}
Person:: ~Person() {}//소멸자
void Person::print() const {
	cout << "Name : " << name << endl;
}
