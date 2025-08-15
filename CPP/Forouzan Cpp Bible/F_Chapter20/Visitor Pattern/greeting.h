#pragma once
#ifndef GREETING_H
#define GREETING_H
#include <string>
#include <iostream>
#include "visitor.h"

class Visitor;

class Greeting {

public:
	void accept(Visitor*);
};

#endif
