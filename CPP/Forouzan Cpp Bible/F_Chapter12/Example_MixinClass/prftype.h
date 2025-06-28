#pragma once
#ifndef PRFTYPE_H
#define PREFTYPE_H
#include <iostream>
using namespace std;

class Prftype {
protected:
	double salary;
public:
	virtual void printSal() = 0;

};
#endif // !PRFTYPE_H
