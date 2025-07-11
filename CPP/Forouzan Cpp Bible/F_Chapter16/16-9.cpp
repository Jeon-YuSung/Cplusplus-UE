//16-9. 기존의 파일 뒤에 추가하기 

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	ofstream ostr;
	ostr.open("TestFile2",ios::out | ios::app);
	if (!ostr.is_open()) {
		cout << "파일을 열 수 없습니다, 프로그램 종료 \n";
		assert(false);
	}

	ostr << "\n July 11, 2025";
	
		ostr.close();
	return 0;
}
