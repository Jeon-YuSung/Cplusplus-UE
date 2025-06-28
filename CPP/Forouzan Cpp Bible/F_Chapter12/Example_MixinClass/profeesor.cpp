#include "professor.h"

Professor::Professor(string nm, double sal) : Person(nm) {
	salary = sal; 
}

void Professor::printSal() {
	cout << "Salary : " << fixed << setprecision(2) << salary << endl;
}
void Professor::print() {

	Person::print();
	printSal();
}
