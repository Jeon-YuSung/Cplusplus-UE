/*
11-6. 구현파일
name.h 클래스의 구현 파일.
*/
#include "name.h"

Name::Name(string fst, string i, string lst) :first(fst), init(i), last(lst) {
	assert(init.size() == 1);
	toupper(first[0]);
	toupper(init[0]);
	toupper(lst[0]);
}
Name::~Name() {}

void Name::print() const {
	cout << "직원 이름 : " << first << " " << init << "." << last << endl;

}
