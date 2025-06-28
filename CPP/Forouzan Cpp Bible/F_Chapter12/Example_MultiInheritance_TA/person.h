//12-7. person의헤더파일

#ifndef  PERSON_H
#define PERSON_H
#include<iostream>
#include<cassert>
using namespace std;

class Person {

protected:
	string name;
public:
	Person(string name);
	~Person();
	void print();
};
#endif // ! STUDENT_h
