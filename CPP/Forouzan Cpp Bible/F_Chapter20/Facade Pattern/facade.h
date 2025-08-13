//퍼사드 패턴을 이용해서 집 구조를 구현해보기
// 퍼사드 역할을 하는 하우스 클래스와 4개의 방 클래스의 인터페이스 파일 

#pragma once
#ifndef FACADE_H
#define FACADE_H
#include <iostream>
#include <string> 
#include <cassert>
using namespace std;

// 거실 클래스
class LivingRoom{
private:
	double size;
public:
	LivingRoom(double size);
	void draw();
};

// 침실 클래스
class BedRoom {

private:
	double size;
public:
	BedRoom(double size);
	void draw();
};

//부엌 클래스 
class Kitchen {
private:
	double size;
public: 
	Kitchen(double size);
	void draw();
};

// 화장실 클래스 
class BathRoom {
private:
	double size;
public:
	BathRoom(double size);
	void draw();
};

//퍼사드 패턴 역할을 하는 하우스 클래스
class House {

private:
	double size;
public:
	House(double size);
	void draw();
};
#endif
