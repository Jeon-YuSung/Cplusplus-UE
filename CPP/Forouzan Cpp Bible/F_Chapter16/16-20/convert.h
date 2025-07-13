//16-20. 헤더파일에서 2개의 템플릿 함수를 정의하고 첫 번째 함수는 기본 자료형을 문자열로
// 두번 째 함수는 문자열을 기본 자료형으로 변환하는 함수 

#pragma once
#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>

//toSring 함수는 다른 자료형을 문자열로 변환
string toString(T data) {
	ostringstream oss("");
	oss << data;
	return oss.str();
}

//todata함수는 문자열을 다른 자료형으로 반환 
template<typename T>
T toData(string str) {
	T data;
	istringstream iss(str);
	iss >> data;
	return data;
}

#endif // !CONVERT_H
