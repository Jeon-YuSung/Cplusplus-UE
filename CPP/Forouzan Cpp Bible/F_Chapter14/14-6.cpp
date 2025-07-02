//14-6 함수 내부에서 thorw 처리하기 
#include <iostream>
#include <cassert>
using namespace std;


int quotient(int f, int s) {
	if (s == 0) {

		throw 0;
	}
	return (f / s);
}


int main(void) {

	int n1, n2, result;
	for (int i = 0; i < 5; i++) {
	
		cout << "정수 입력 : ";
		cin >> n1;
		cout << "다른 정수도 입력 : ";
		cin >> n2;
		
		try {
			
			cout << "결과 : " << quotient(n1, n2) << endl;
		}
		catch (int ex) {
			cout << "0으로 나눌 수 없습니다 \n";
		}
	}
	
	return 0;
} 
