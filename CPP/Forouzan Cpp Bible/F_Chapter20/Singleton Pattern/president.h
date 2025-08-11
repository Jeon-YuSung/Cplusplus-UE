#pragma once
#ifndef PRESIDENT_H
#define PRESIDENT_H
#include <iostream>
#include <string> 
using namespace std;

class President {

private:
	string name;
	President(string name); //private 생성자
	static President* ptr; // 정적변수
public:
	static President* create(string name);
	string getName() const;

};
#endif