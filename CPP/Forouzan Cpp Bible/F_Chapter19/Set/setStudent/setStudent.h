#pragma once
#ifndef SETSTUDENT_H
#define SETSTUDENT_H
#include <set>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {

private:
	int identity;
	string name;
	double gpa;
public:
	Student(int identity, string name, double gpa);
	~Student();
	void print() const;
	bool friend operator<(const Student& left, const Student& right);

};
#endif // !SETSTUDENT_H
