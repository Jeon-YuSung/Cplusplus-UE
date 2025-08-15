#pragma once
#ifndef STATE_H
#define STATE_H
#include <string>
#include <iostream>

class State; 

// Light 클래스 정의
class Light {
private:
	State* state;
public:
	void setState(State* state);
	void delState();
	void turnSwitch();

};

// 상태 부모 클래스 정의
class State {
public:
	virtual void handle(Light* light) = 0;

};


//offState 구체 클래스 정의
class OffState : public State {
public:
	void handle(Light* light);

};

//onState 구체 클래스 정의
class OnState :public State {

public:
	void handle(Light* light);
};

#endif
