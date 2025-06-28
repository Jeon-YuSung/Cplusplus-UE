//12-8. person, stdtype 클래스의 상속을 받는 student 헤더파일 

#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "stdtype.h"

class Student : public Person, public Stdtype // 가상 상속 
{

public:
	Student(string name, double gpa);
	void printGpa();
	void print();

};
#endif // !1