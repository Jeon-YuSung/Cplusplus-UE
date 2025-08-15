#pragma once
#ifndef MEMENTO_H
#define MEMENTO_H
#include <string>
#include <iostream>

class Memento;

class Originator {

private:
	std::string state;
	Memento* memento;
public:
	Originator();
	~Originator();
	std::string getState() const;
	void setState(std::string state);
	void restoreState();
};

class Memento {
private:
	std::string state;
public:
	std::string getState() const;
	void setState(std::string state);
};

#endif
