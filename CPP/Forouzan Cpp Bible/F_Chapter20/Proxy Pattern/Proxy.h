//프록시 패턴의 인터페이스 파일

#pragma once
#ifndef PROXY_H
#define PROXY_H
#include <iostream>
#include <string> 
#include <cassert>
using namespace std;

//서브젝트 부모 클래스 선언
class Subject {

public:
	virtual void draw(int x, int y) = 0;
	virtual void erase() = 0;
	virtual ~Subject() {}
};

// 리얼 클래스 선언
class Real : public Subject {

public:
	void draw(int x, int y);
	void erase();
};

// Proxy 클래스 선언 
class Proxy : public Subject {

private:
	Subject* real;
public:
	Proxy();
	~Proxy();
	void draw(int x, int y);
	void erase();
};
#endif
