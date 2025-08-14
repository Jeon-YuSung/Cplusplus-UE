#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include <iostream>
#include <set>

class Observer; //전방 선언

//subject 클래스 정의 
class Subject{
private:
	std::set<Observer*> observers;
public:
	void subscribe(Observer* observer);
	void unsubscribe(Observer* observer);
	void notify(int price);

};

//부모 클래스 옵저버 정의
class Observer {

public:
	virtual void update(int price) = 0;
	virtual ~Observer() {}
};

//옵저버1(구매자1) 클래스
class Observer1 : public Observer {

private:
	Subject* subject;
public:
	Observer1(Subject* subject);
	void update(int price);

};

//옵저버2(구매자2) 클래스
class Observer2 : public Observer {

private:
	Subject* subject;
public:
	Observer2(Subject* subject);
	void update(int price);

};
#endif
