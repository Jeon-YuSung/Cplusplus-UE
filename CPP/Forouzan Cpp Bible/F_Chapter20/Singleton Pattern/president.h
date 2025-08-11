#pragma once
#ifndef PRESIDENT_H
#define PRESIDENT_H
#include <iostream>
#include <string> 
using namespace std;

class President {

private:
	string name;
	President(string name); //private ������
	static President* ptr; // ��������
public:
	static President* create(string name);
	string getName() const;

};
#endif