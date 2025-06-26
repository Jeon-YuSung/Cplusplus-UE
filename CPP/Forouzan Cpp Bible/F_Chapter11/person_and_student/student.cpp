// student 구현 파일

#include "student.h"

//기본 생성자 
Student::Student() : Person(), gpa(0.0) {}

//매개변수 생성자
Student::Student(long id, double gp) : Person(id), gpa(gp) {
	assert(0.0 <= gpa && gpa <= 4.3);
}

//복사 생성자 
Student::Student(const Student & student) : Person(student), gpa(student.gpa){}

// 소멸자 
Student::~Student() {}

void Student::print() const {

	Person::print();
	cout << "Gpa : " << fixed << setprecision(2) << gpa << endl;
}
