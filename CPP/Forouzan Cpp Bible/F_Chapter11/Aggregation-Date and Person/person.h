//11-5 Peron 클래스 헤더파일

#ifndef PERON_H
#define PERON_H
#include "date.h"

class Person {

private:
	long identity;
	Date birthDate;
public:
	Person(long identity, Date birthDate); 
	~Person();//소멸자
	void print() const;

};

#endif // !1
