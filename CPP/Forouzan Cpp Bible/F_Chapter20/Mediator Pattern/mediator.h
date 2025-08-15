#pragma once
#ifndef MEDIAOTR_H
#define MEDIAOTR_H
#include <string>
#include <iostream>
#include <vector>

class Employee {

public:
	virtual void getMessage(std::string message) = 0;

};

class Employee1 : public Employee {
public:
	void getMessage(std::string message);
};

class Employee2 : public Employee {
public:
	void getMessage(std::string message);
};

class Employee3 : public Employee {
public:
	void getMessage(std::string message);
};

class Employee4 : public Employee {
public:
	void getMessage(std::string message);
};

//중재자 클래스는 고용 객체의 벡터를 캡슐화
class Mediator {
private:
	std::vector<Employee*> employ;
public:
	Mediator();
	~Mediator();
	void sendMesage(std::string message);

};
#endif
