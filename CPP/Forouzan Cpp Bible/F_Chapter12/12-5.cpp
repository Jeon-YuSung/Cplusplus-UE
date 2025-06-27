// 12-5. typeid 연산자 사용하기 
// typeid로 클래스 이름을 확인 해보자 
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

class Animal {};
class Horse {};

int main(void) {
	
	Animal a;
	Horse h;

	cout << typeid(a).name() << endl;
	cout << typeid(h).name() << endl; //시스템에 따라 클래스 이름만 출력될수 있음
	return 0;
}
