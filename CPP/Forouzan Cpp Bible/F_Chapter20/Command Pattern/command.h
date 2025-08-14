#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <iostream>
using namespace std;

// 명령을 받는 리시버 클래스
class Receiver {

public:
	void action();

};

// Command 부모 클래스
class Command {

public:
	virtual void execute() = 0;

};

//실질적인 명령을 나타내는 클래스 정의
class Concrete : public Command {
private:
	Receiver* receiver;
public:
	Concrete(Receiver* receiver);
	void execute();
};

//명령을 호출하는 invoker 클래스 정의
class Invoker {
private:
	Command* command;
public: 
	void store(Command* command);
};
#endif // !COMMAND_H
