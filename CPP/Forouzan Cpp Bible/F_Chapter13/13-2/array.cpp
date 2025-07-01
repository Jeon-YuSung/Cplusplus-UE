#include "array.h"


//힙 메모리에 할당하는 생성자 
Array::Array(int s) : size(s) {
	ptr = new double[size];
}
//힙 메모리에서 제거하는 소멸자 
Array::~Array() {
	delete[] ptr;
}
//첨자 접근자
double& Array::operator[](int index) const { 

	if (index < 0 || index >= size) {
		cout << "(접근자)유효하지않은 인덱스, 프로그램 중단 \n";
		assert(false);
	}
	return ptr[index];
}
//첨자 설정자
double& Array::operator[](int index) {

	if (index < 0 || index >= size) {
		cout << "(설정자) 유효하지않은 인덱스, 프로그램 중단 \n";
		assert(false);
	}
	return ptr[index];
}
