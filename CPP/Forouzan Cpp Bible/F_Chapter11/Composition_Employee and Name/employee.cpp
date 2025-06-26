//11-6. employee 구현 파일

#include "employee.h"

Employee::Employee(string fst,string i, string lst, double sal) : name(fst,i,lst), salary(sal) {
	assert(0.0 < salary && salary < 1000000.00);
}

Employee::~Employee() {} // 소멸자
void Employee::print() const
{
	name.print();
	cout << "급여 : " << salary << endl;
}
