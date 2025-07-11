//16-10. 입출력 모두를 목적 파일 열기. 
// 파일을 읽고 내부 정수를 모두 더한 뒤 파일 끝에 쓰는 프로그램 

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {

	fstream fstr;
	fstr.open("intFile", ios::in | ios::out);

	if (!fstr.is_open()) {
	
		cout << "intFile을 열 수 없습니다 \n";
		assert(false);
	}
	int n;
	int sum = 0;
	while (fstr >> n) 
	{
		sum += n;
	}
	fstr.clear();
	fstr << "\n 숫자의 합 : ";
	fstr << sum;

	fstr.close();
	return 0;
}
