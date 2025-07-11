//16-6. 기존에 있는 파일 읽어들이기.

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	int data;
	ifstream inStrm;
	inStrm.open("16-5_interFile");
	if (!inStrm.is_open()) {
	
		cout << "파일을 열 수 없습니다, 프로그램 종료 \n";
		assert(false);
	}
	for (int i = 1; i <= 10; i++) {

		inStrm >> data;
		cout << data << " ";
	}

	inStrm.close();

	return 0;
}
