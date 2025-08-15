// 책임 연쇄 패턴구현 파일
#include "chain.h"

//생성자
Loan1::Loan1() {

	next = new Loan2();
}

//소멸자
Loan1::~Loan1() {
	delete next;
}

//handle 멤버함수 
void Loan1::handle(int loanValue) {
	if (loanValue <= 1000) {
		std::cout << "로안1 객체 입니다, 대출이 가능합니다 \n ";
		std::cout << "자세한 사항은 전화로 문의 주세요 \n";
	}
	else {
		next->handle(loanValue);
	}
}

// Loan2생성자
Loan2::Loan2() {

	next = new Loan3();
}

// Loan2소멸자
Loan2::~Loan2() {
	delete next;
}

//handle 멤버함수 
void Loan2::handle(int loanValue) {
	if (loanValue <= 100000) {
		std::cout << "로안2 객체 입니다, 대출이 가능합니다 \n ";
		std::cout << "자세한 사항은 전화로 문의 주세요 \n";
	}
	else {
		next->handle(loanValue);
	}
}

//로안3 생성자
Loan3::Loan3() {

	next = 0;
}

//로안3 소멸자
Loan3::~Loan3() {
	delete next;
}

//handle 멤버함수 
void Loan3::handle(int loanValue) {
	if (loanValue <= 1000000 && loanValue > 10000) {
		std::cout << "로안3 객체 입니다, 대출이 가능합니다 \n ";
		std::cout << "자세한 사항은 전화로 문의 주세요 \n";
	}
	else {
		std::cout << "해당 대출은 불가능합니다.\n";
	}
}

//로안 생성자 
Loan::Loan(int value) : loanValue(value)
{
	next = new Loan1();
	next->handle(loanValue);
}

//로안 소멸자 
Loan::~Loan() {
	delete next;
}
