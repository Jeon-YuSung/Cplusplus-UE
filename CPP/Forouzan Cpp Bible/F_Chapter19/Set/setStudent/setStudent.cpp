#include "setStudent.h"

Student::Student(int id, string nm, double gp)
	: identity(id), name(nm), gpa(gp) {
}

Student::~Student() {}

void Student::print() const {

	cout << setw(3) << right << identity << " ";
	cout << setw(12) << left << name << " ";
	cout << setw(6) << right << showpoint << setprecision(3);
	cout << gpa << " " << endl;
}

//friend 연산자 오버로드
bool operator<(const Student& left, const Student& right) {
	return(left.identity < right.identity);
}
