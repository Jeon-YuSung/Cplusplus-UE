#include <iostream> //i/o스트림 라이브러리를 선언을 인클루드
using namespace std; //STD의 이름을 STD::없이도 사용할수 있게 사용

void sum(){ //sum함수 선언 
	double a = 2.2; 
	int b = 7;
	a = a + b; 
	b = a * b; 

	cout << a << endl; //a 출력
	cout << b; //b출력
}
int main(void){ //메인함수 
	sum();
	return 0; 
}
