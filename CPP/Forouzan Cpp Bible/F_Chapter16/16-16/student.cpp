#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

Student::Student(int id, const string& name, double gpa) 
	: stdId(id), stdGpa(gpa) {
		
	strcpy(stdName, name.c_str());
	if (stdId < 1 || stdId > 99) {
		cout << "id의 범위가 넘었습니다, 프로그램 종료 \n";
		assert(false);
	}
	if (stdGpa < 0.0 || stdGpa > 4.3) {
		cout << "gpa의 제한 범위가 넘었습니다, 프로그램 종료. \n";
		assert(false);
	}
}
Student::Student() {}
Student::~Student() {}
int Student::getId() const {
	return stdId;
}
string Student::getName() const {
	return stdName;
}
double Student::getGpa() const {
	return stdGpa;
}
