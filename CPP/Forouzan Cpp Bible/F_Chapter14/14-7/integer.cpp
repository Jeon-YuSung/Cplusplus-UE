#include "Integer.h"

// function-try 블록을 사용한 생성자 
Integer::Integer(int v) try : sp(new int) {
	*sp = v;
}
catch (...) {
	throw;
}

Integer::~Integer() {} //소멸자 

int Integer::getValue() {
	
	return *sp;

}
