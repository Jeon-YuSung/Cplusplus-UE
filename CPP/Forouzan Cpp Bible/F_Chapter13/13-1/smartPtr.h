//13-3 스마트 포인터의 헤더 파일. 

#pragma once
#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <iostream>
using namespace std;

class Fraction; //전방 선언
class SmartPtr {

private:
	Fraction* ptr;
public:
	SmartPtr(Fraction* ptr);
	~SmartPtr();
	Fraction& operator*() const;
	Fraction* operator->() const;

};


#endif // !SMARTPTR_H
