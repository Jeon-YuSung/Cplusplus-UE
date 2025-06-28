#include "student.h"

Student::Student(string na, double gp) : Person(na) {
	gpa = gp;
}
void Student::printGpa() {
	cout << " GPA : " << fixed << setprecision(2) << gpa << endl;

}
void Student::print() {

	Person::print();
	printGpa();
}
