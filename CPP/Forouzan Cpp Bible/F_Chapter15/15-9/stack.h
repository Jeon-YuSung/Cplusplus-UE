//15-9(12) Stack 템플릿 클래스 인터페이스 파일

#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<cassert>
using namespace std;

template<typename T>
class Stack{
private:
	T* ptr;
	int size;
	int capacity;

public:
	Stack(int capacity);
	~Stack();
	void push(const T& element);
	T pop();

};

#endif 
