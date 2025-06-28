#include "person.h"

Person::Person(string nm) : name(nm) {

}

void Person::print() {
	cout << "Person \n";
	cout << "name : " << name  << endl;
}
