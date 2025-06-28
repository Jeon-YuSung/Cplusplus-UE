#include "person.h"

Person::Person(string nm) : name(nm) {

}
Person::~Person() {}
void Person::print() {
	cout << "Person \n";
	cout << "name : " << name << endl << endl;
}
