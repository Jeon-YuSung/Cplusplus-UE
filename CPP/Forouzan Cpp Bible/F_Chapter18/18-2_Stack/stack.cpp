// stack 구현 파일 

#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

// 스택 입력 함수 push
template<typename T>
void Stack<T>::push(const T& value) {
	list.insert(0, value);
}

// 스택 출력 함수 pop
template<typename T>
void Stack<T>::pop() {
	list.erase(0);
} 

//top 함수 정의 
template<typename T>
T& Stack<T>::top() const {
	return list.get(0);
}

template<typename T>
int Stack<T>::size() const {
	return list.size();
}

#endif // !STACK_CPP
