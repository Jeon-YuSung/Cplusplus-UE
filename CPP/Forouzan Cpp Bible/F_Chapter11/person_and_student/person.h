//Peron 클래스 헤더파일

#ifndef PERON_H
#define PERON_H

#include<cassert>
#include<iostream>
#include<iomanip>
using namespace std;

class Person {

private:
	long identity;
public:
	Person(); //기본생성자
	Person(long identity); //매개변수 생성자
	~Person();//소멸자
	Person(const Person& peron); //복사 생성자 
	void print() const;

};

#endif // !1


