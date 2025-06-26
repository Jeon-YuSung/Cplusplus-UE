/*
11-5. 구현파일
person 클래스의 구현 파일.
*/
#include "person.h"

// 생성자 
Person::Person(long id, Date bd) : identity(id), birthDate(bd) {

	assert(111111111 < identity && identity < 999999999);
}

Person::~Person() {}//소멸자
void Person::print() const {
	cout<< "주민 등록 번호 : " << identity <<endl;
	cout << "생년 월 일 : ";
	birthDate.print();
	cout << endl << endl;

}
