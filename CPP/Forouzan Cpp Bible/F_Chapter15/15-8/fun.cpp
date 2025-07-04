//15-8(10) fun 템플릿 구현 파일

#ifndef FUN_CPP
#define FUN_CPP
#include "Fun.h"

template<typename T>
Fun<T>::Fun(T d) : data(d) {}

template<typename T>
Fun<T>::~Fun() {}

template<typename T>
T Fun<T>::get() const { return data; }

template<typename T>
void Fun<T>::set(T d) { data = d; }
#endif // !FUN_CPP
