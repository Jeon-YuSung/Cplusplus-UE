//14-1 두 개의 정수 나누기
#include <iostream>
using namespace std;

int main(void) {

	int n1, n2, result;
	for (int i = 0; i < 5; i++) {
	
		cout << "정수 입력 : ";
		cin >> n1;
		cout << "다른 정수도 입력 : ";
		cin >> n2;
		result = n1 / n2; //예외를 발생 시킬수 있는 표현식
		cout << " 결과 : " << result << endl;
	}
	
	return 0;
} 
