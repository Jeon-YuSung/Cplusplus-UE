//16-7. 파일을 열고 내용 하나하나 읽은 뒤 모니터에 출력하느 ㄴ프로그램

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	char ch;
	ifstream istrm;
	istrm.open("TestFile1.txt",ios::in);

	if (!istrm.is_open()) {
	
		cout << "파일을 열 수 없습니다, 프로그램 종료 \n";
		assert(false);
	}
	//파일의 내용을 읽어 모니터에 쓰기 
	while (istrm.get(ch)) {
		cout.put(ch);
	}

	istrm.close();
	return 0;
}
