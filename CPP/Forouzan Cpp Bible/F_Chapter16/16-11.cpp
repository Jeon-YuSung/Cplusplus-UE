//16-11. 여러 문자가 조합된 프로그램에서 정수만 추출해서 출력하는 프로그램

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	ifstream ifstr;
	ifstr.open("mixedFile.txt", ios::in); 
	if(!ifstr.is_open()){
	
		cout << "mixedFile을 열 수 없습니다!";
		assert(false);
	}

	// 정수부분만 읽고 출력 

	char ch;
	int n;
	while (ifstr.get(ch)) {
	
		if (ch >= '0' && ch <= '9') {
			ifstr.unget();
			ifstr >> n;
			cout << n << " ";
		}
	}
	ifstr.close();
	return 0;
}
