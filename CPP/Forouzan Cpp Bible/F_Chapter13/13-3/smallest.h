//13 smallest 객체 - 함수 호출 연산자 

#pragma once
#ifndef SMALLEST_H
#define SMALLEST_h
#include <iostream>
using namespace std;

class Smallest {

private:
	int curr;
public:
	Smallest();
	int operator()(int next);
};

#endif 
