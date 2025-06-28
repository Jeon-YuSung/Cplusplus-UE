//12-8. person, prftype을 상속 받는 professor 헤더 파일
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "person.h"
#include "prftype.h"


class Professor : public Person, public Prftype {
public:
	Professor(string name, double salary);
	void printSal();
	void print();
};

#endif // DEBUG
