#include "ta.h"

TA::TA(string nm, double gp, double sal) : Person(nm), Student(nm, gp), Professor(nm, sal) {}
TA::~TA() {}
void TA::print() {

	cout << "TA " << endl;
	cout << "Name : " << name << " GPA : " << gpa << " Sal : " << salary << endl;
	cout << endl;

}
