//16-2. get 함수 사용하기 

#include <iostream>
using namespace std;

int main(void) {

	int n;
	cout << "공백 없이 문자 5개를 입력하세요 : \n";
		
	for (int i = 0; i < 5; i++) {
	
		n = cin.get();
		cout << n << " ";

	}
	return 0;
}
