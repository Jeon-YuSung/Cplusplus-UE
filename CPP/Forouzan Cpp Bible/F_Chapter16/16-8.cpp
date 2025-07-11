//16-8. 파일을 열고 내용을 하나한 읽은뒤 다른 파일에 출력하는 프로그램.

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	char ch;
	ifstream istr;
	ofstream ostr;
	istr.open("TestFile1.txt",ios::in);
	if (!istr.is_open()) {
	
		cout << "파일을 열 수 없습니다, 프로그램 종료 \n";
		assert(false);
	}
	ostr.open("TestFile2", ios::out);
	if (!ostr.is_open()) {
		cout << "파일을 열 수 없습니다, 프로그램 종료 \n";
		assert(false);
	}
	// 파일1의 내용을 읽어 파일2에 쓰기
	while (istr.get(ch)) {
		ostr.put(ch);
	}
	istr.close();
	ostr.close();
	return 0;
}
