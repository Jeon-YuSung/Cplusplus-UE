#include "professor.h"

Professor::Professor(string nm, double sal) : Person(nm), salary(sal) {}
Professor::~Professor() {}
void Professor::print() {
	cout << " Professor \n";
	cout << "name : " << name << " ";
	cout << "Salary : " << salary << endl;
	cout << endl;

}
