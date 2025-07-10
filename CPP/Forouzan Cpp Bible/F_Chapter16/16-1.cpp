//16-1. cin 객체 상태 확인하기

#include <iostream>
using namespace std;

int main(void) {

	int n;
	cout << "정수를 입력하세요 (종료하려면 eof, ctrl+z 입력) :  \n";
	while (cin >> n) {
	
		cout << n * 2 << " ";
	}

	return 0;
}
