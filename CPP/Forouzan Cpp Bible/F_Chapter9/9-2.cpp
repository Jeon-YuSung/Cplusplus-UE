/* 
9-2. 참조로 전달을 사용해서 함수로 전달한 2개의 값을 스왑하는 프로그램 
*/

#include <iostream>
using namespace std;

void swap(int& a, int& b);
//메인함수 
int main(void) {

//변수 정의
	int x, y;
	x = 10;
	y = 20;

	//스왑 전
	cout << "스왑 하기전의 x와 y의 값 출력 \n";
	cout << " x: " << x << " y: " << y << "\n";
	
	swap(x, y);
	
	//스왑 후
	cout << "스왑 후의 x와 y의 값 \n";
	cout << "x : " << x << " y : " << y;

	return 0; 
}

void swap(int& Ra, int& Rb) {

	int temp;
	temp = Ra;
	Ra = Rb;
	Rb = temp;

}
