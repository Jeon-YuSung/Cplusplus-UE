//14-3 오류 가능성을 확인하고 프로그램 중단을 막는 프로그램. 
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

		if (n2 == 0) {
		
			cout << "현재 입력으로는 처리가 불가능 합니다 \n";
		}
		else {
			result = n1 / n2;
			cout << " 결과 : " << result << endl;
		}

	}
	
	return 0;
} 
