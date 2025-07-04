//15-3 템플릿 함수를 사용하여 두 값을 스왑하는 프로그램 
#include<iostream>
using namespace std;

template<typename T>
void exchage(T& f1, T& f2) {

	T temp = f1;
	f1 = f2;
	f2 = temp;

}
int main(void) {

	// int 자료형 스왑
	int a, b;
	cout << "int 정수 입력 : ";
	cin >> a >> b;
	exchage(a, b);
	cout << "swap (a,b)의 결과 : " << a << " " << b;
	cout << endl;

	//double 자료형 스왑
	double d1, d2;
	cout << "부동 소숫점 입력 : ";
	cin >> d1 >> d2;
	exchage(d1, d2);
	cout << " swap(d1,d2)의 결과 : " << d1 << " " << d2;
	cout << endl;

	return 0;
}
