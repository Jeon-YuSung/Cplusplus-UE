// student 인터페이스 파일

#ifndef  STUDENT_H
#define STUDENT_H
#include "person.h"

class Student : public Person
{
private:
	string name;
	double gpa;
public:
	Student(string name, double gpa);
	~Student();
	void print() const;
};
#endif // ! STUDENT_h
