//데코레이터 패턴 헤더 파일 

#pragma once
#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>
#include <string> 
#include <cassert>
using namespace std;

//컴포넌트 클래스의 선언 

class Component {

private:
	string text;
public:
	Component(string text);
	void draw();
};

// 데코레이터 클래스 선언
class Decorator {

private:
	Component component;
public:
	Decorator(Component component);
	void draw();
};
#endif
