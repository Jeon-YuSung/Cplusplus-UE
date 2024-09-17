#include <iostream> //i/o스트림 라이브러리를 선언을 인클루드
using namespace std; //STD의 이름을 STD::없이도 사용할수 있게 사용


double square(double x) {
	return x * x;
}

void print_square(double x) { //반환 타입 void는 함수가 반환하지 않는다.

	cout << "the square of " << x << " is " << square(x) << endl;
}

int main(void){ //메인함수 
	print_square(1.234);// 1234의 제곱인 1.52276을 출력. 	
	return 0; 
}
