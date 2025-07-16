// biginterger 헤더파일
#pragma once
#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <string>
#include <list>
#include<iostream>
using namespace std;

class Big_integer {

private:
	list<int> lst;
public:
	Big_integer();
	Big_integer(string str);
	~Big_integer();
	string toString();
	friend Big_integer operator+(Big_integer first, Big_integer second);
};
#endif // !BIGINTERGER_H
