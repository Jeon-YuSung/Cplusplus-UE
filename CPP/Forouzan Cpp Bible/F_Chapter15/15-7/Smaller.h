//15-7. 템플릿 함수 인터페이스 헤더 파일 

#ifndef SMALLER_H
#define SMALLER_H
#include<iostream>
using namespace std;

template<typename T>
T smaller(const T& f1, const T& f2) {

	if (f1 < f2) {
		return f1;
	}
	return f2;
}

#endif 
