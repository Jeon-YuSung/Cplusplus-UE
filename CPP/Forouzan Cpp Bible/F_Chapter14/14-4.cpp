//14-4 함수를 사용한 오류 확인 
#include <iostream>
#include <cassert>
using namespace std;

int quotient(int f, int s) {
	if (s == 0) {

		return -1;
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
		result = quotient(n1, n2);
		if (result == -1) {
		
			cout << "오류 : 0으로 나눌 수 없습니다  \n";
		}
		else {
			cout << " 결과 : " << result << endl;
		}

	}
	
	return 0;
} 
