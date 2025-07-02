#include "sp.h"

SP::SP(int* p) : ptr(p) {} // 생성자 
SP::~SP() { //소멸자

	delete ptr;
} 

// *연산자 오버로드
int& SP::operator*()const {

	return *ptr;
}

// ->연산자 오버로드
int* SP::operator->() const {

	return ptr;
}
