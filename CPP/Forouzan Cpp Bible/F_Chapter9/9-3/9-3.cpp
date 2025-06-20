/* 
9-3. 7장에서 사용한 7-10 interface.h (Fraction.h)파일을 이용해서 두 분수의 키그를 비교하고 큰 분수를 찾아내는 프로그램
두 쌍의 분수를 만들고 larger함수를 호출해서 둘 중 큰 값을 찾기 
*/
#include "FRACTION.h"

Fraction& larger(Fraction&, Fraction&);

//메인함수 
int main(void) {

// 첫 번째 쌍을 만들고 큰 값을 탐색
	Fraction fract1(3, 13);
	Fraction fract2(5, 17);

	cout << "첫 번째 쌍에서 더 큰 분수 : ";
	larger(fract1, fract2).print();
	//두 번째 쌍을 만들고 큰 값 탐색 
	Fraction fract3(4, 8);
	Fraction fract4(1, 6);

	cout << "두 번째 쌍에서 더 큰 분수 : ";
	larger(fract3, fract4).print();
	return 0; 
}

// fraction 객체의 참조를 받고 더 큰 값을 찾아서 리턴하는 함수
Fraction& larger(Fraction& fract1, Fraction& fract2) {


	if (fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom()) {
		return fract1;
	}
	return fract2;
}
