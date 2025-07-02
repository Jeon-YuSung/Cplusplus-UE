//14-5 try-catch 사용하기
#include <iostream>
#include <cassert>
using namespace std;

int main(void) {

	int n1, n2, result;
	for (int i = 0; i < 5; i++) {
	
		cout << "정수 입력 : ";
		cin >> n1;
		cout << "다른 정수도 입력 : ";
		cin >> n2;

		try {
			if (n2 == 0) {
				throw 0; //int 자료형의 예외를 발생 
			}
			result = n1 / n2;
			cout << "결과 : " << result << endl;
		}
		catch (int x) {
			cout << "0으로 나눌 수 없습니다 \n";
		}
	}
	
	return 0;
} 
