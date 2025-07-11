//16-5. 파일을 출력하는 5가지 단계

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	ofstream openF;
	//파일 열기 
	openF.open("16-5_interFile");
	if (!openF.is_open()) {
		cout << "파일 열 수 없음, 프로그램 종료 \n";
		assert(false);
	}
	
	//삽입 연산자 오버로드 함수를 활용해 파일에 쓰기 
	for (int i = 1; i <= 10; i++) {
	
		openF << i * 10 << " ";
	
	}
	openF.close();

	return 0;
}
