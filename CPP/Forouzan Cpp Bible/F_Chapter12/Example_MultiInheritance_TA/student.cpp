#include "student.h"

Student::Student(string name, double gp) : Person(name), gpa(gp) {
	assert(gpa <= 3.7);
}

Student::~Student() {}
void Student::print() {
	cout << "Student " << endl;
	cout << "Name : " << name << " GPA : " << gpa << endl; 
	cout << endl;
}
