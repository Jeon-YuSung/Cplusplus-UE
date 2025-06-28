#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class Student : virtual public Person // 가상 상속 
{
protected:
	double gpa;
public:
	Student(string name, double gpa);
	~Student();
	void print();

};
#endif // !1
