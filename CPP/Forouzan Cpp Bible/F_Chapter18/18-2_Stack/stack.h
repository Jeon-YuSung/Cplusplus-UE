#pragma once
#ifndef STACK_H
#define STACK_H
#include "list.cpp"

// stack 정의
template<typename T>
class Stack {

private:
	List<T> list;

public:
	void push(const T& data); //스택 입력 함수
	void pop(); //스택 출력함수 
	T& top() const;
	int size() const;

};

#endif // !STACK_H
