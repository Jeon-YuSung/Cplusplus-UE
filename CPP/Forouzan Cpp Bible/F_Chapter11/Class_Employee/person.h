//Peron 클래스 헤더파일

#ifndef PERON_H
#define PERON_H

#include<iostream>
#include<string>
using namespace std;

class Person {

private:
	string name;
public:
	Person(string nme); 
	~Person();//소멸자
	void print() const;

};

#endif // !1

