#pragma once
#ifndef VISITOR_H
#define VISITOR_H
#include <string>
#include <iostream>

class Visitor {

public:
	virtual void visit() = 0;
};

class EngVisitor :public Visitor {
public:
	void visit();
};

class FrenchVisitor : public Visitor {
public:
	void visit();
};

class KoreanVisitor : public Visitor {

public:
	void visit();
};


#endif
