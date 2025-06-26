//11-4 emplyee 구현 파일

#include "employee.h"

Employee::Employee(string nm, double sa) : Person(nm), salary(sa) {}

Employee::~Employee() {} // 소멸자
void Employee:: print() const
{
	Person::print();
	cout << "급여 : " << salary << endl;

}
