//12-3 person 클래스의 인터페이스 파일 

#ifndef PERON_H
#define PERON_H
#include<iostream>
#include<string>
using namespace std;

class Person {

private:
	string name;
public:
	Person(string name);
	virtual ~Person();//소멸자
	virtual void print() const;

};

#endif // !1
