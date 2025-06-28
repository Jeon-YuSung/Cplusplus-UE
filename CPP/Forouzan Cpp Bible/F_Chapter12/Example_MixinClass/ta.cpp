#include "ta.h"

TA::TA(string nm, double gp, double sal) : Person(nm) {
	gpa = gp;
	salary = sal;
}

void TA::printGpa() {
	cout << "TA gpa : " << gpa << endl;
}
void TA::printSal() {
	cout << "TA Sal : " << fixed << setprecision(2) << salary << endl;
}

void TA::print() {

	Person::print();
	printGpa();
	printSal();
}
