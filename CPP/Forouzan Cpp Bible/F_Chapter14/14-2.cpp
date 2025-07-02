//14-2 0으로 나누는 경우 강제로 프로그램 중단하기 
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
		
			cout << "0으로 나눌 수 없습니다, 프로그램 종료 \n";
			assert(false);
		}
		result = n1 / n2; 
		cout << " 결과 : " << result << endl;
	}
	
	return 0;
} 

