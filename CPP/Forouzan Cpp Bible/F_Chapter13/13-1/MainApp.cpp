#include "smartPtr.h"
#include "fraction.h"

int main(void) {

//스마트 포인터 생성
	SmartPtr sp = new Fraction(2, 5);

//*로 접근
	cout << "* Fraction : ";
	(*sp).print();

	//->로접근
	cout << "-> Fraction : ";
	sp->print();

	cout << endl;

	return 0;
} 
