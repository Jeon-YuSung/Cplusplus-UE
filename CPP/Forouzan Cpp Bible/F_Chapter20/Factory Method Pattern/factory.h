#pragma once
#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include <string> 
#include <cassert>
using namespace std;

//shap클래스를 부모 클래스로 정의 
class Shape {

public:
	static Shape* factory(string);
	virtual void draw() = 0;
	virtual ~Shape();
};

//Square 클래스 정의 
class Square : public Shape {

private:
	Square();
public:
	static Shape* factory();
	void draw();
};

//써클 클래스 정의 
class Circle :public Shape {

private:
	Circle();
public:
	static Shape* factory();
	void draw();
};

#endif
