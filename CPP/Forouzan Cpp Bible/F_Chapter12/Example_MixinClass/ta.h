
#ifndef TA_H
#define TA_H
#include "person.h"
#include"stdtype.h"
#include "prftype.h"

class TA : public Person, public Stdtype, public Prftype {  //다중 상속

public :
	TA(string name, double gpa, double salary);
	void printGpa();
	void print();
	void printSal();
};

#endif // !1
