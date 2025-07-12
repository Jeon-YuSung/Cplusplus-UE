//16-12. 파일에 있는 문자와 문자의 위치를 출력하는 프로그램 

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	char ch;
	int n;

	ifstream istr;
	istr.open("sample.txt", ios::in);
	n = istr.tellg();
	while(istr.get(ch)){
		cout << n << " " << ch << endl;
		n = istr.tellg();
	}
	istr.close();
	
	return 0;
}
