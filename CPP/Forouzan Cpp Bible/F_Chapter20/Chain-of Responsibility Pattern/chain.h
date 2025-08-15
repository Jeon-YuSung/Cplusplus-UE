#pragma once
#ifndef CHAIN_H
#define CHAIN_H
#include <string>
#include <iostream>

class LoanOfficer {

public:
	virtual void handle(int value) = 0;
	virtual ~LoanOfficer() {} 

};

// 구체 클래스 Loan1
class Loan1 : public LoanOfficer {
private:
	LoanOfficer* next;
public:
	Loan1();
	~Loan1();
	void handle(int value);
};


// 구체 클래스 Loan2
class Loan2 : public LoanOfficer {
private:
	LoanOfficer* next;
public:
	Loan2();
	~Loan2();
	void handle(int value);
};


// 구체 클래스 Loan3
class Loan3 : public LoanOfficer {
private:
	LoanOfficer* next;
public:
	Loan3();
	~Loan3();
	void handle(int value);
};

//창구 역할을 하는 Loan 클래스 
class Loan {

private:
	int loanValue;
	LoanOfficer* next;
public:
	Loan(int loanValue);
	~Loan();

};
#endif
