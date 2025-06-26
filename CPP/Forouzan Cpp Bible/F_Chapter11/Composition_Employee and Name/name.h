//11-6 NAME 헤더 파일 

#ifndef NAME_H
#define NAME_H
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Name {


private:
	string first, init, last;
public:
	Name(string first, string init, string last);
	~Name();
	void print() const;
};



#endif // !1
