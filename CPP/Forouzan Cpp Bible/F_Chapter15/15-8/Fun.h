//15-8(9). Fun 헤더파일 

#ifndef FUN_H
#define FUN_H
#include<iostream>
using namespace std;

template<typename T>
class Fun {

private:
	T data;
public:
	Fun(T data);
	~Fun();
	T get() const;
	void set(T data);

};

#endif 
