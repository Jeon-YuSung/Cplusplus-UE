//스마트포인터 구현 파일
#include "smartPtr.h"

SmartPtr::SmartPtr(Fraction* p) :ptr(p) {} //생성자
SmartPtr::~SmartPtr() {}//소멸자 

//간접 연산자 오버로드 
Fraction& SmartPtr::operator*() const {

	return *ptr;
}

//멤버 선택 연산자 오버로드 
Fraction* SmartPtr::operator->() const {

	return ptr;
}
