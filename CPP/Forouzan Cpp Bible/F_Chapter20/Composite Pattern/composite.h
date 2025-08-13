//Figure, point, MultiPoint 클래스의 인터페이스 파일 

#pragma once
#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <iostream>
#include <string> 
#include <cassert>
#include <utility>
#include <vector>
using namespace std;

//Figure 클래스의 인터페이스 
class Figure {

public:
	virtual void show() = 0;
};

// Point 클래스의 인터페이스 
class Point : public Figure {
private:
	pair<double, double> point;
public:
	Point(double x, double y);
	void show();

};


// 멀티 포인트의 클래스 인터페이스 
class Multipoint : public Figure {

private:
	int size;
	vector<Figure*> points;
public:
	Multipoint();
	void addPoint(Figure* point);
	void show();
};
#endif
