#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <cassert>
using namespace std;

class Date {
private:
	int month, day, year;
public:
	Date(int month, int day, int year);
	~Date();
	void print() const;
};

#endif
