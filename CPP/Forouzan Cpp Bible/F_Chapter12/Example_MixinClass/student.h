//12-8. person, stdtype Ŭ������ ����� �޴� student ������� 

#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "stdtype.h"

class Student : public Person, public Stdtype // ���� ��� 
{

public:
	Student(string name, double gpa);
	void printGpa();
	void print();

};
#endif // !1