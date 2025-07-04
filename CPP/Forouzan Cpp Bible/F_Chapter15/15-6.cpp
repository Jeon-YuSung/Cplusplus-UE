//15-6. smaller 템플릿 함수를 오버로딩하는 프로그램
#include<iostream>
using namespace std;

//템플릿 함수 정의
template<typename T>
T smallest(const T& f1, const T& f2) {

	if (f1 < f2) {
		return f1;
	}
	return f2;
}

//템플릿 함수 정의
template<typename T>
T smallest(const T& f1, const T& f2, const T& f3) {

	return smallest(smallest(f1, f2), f3);

}
int main(void) {

	//매개변수 3개인 형태 호출 (int)
	cout << "smallest (12,3,99) : " << smallest(12,3,99) << endl;

	//double형으로 호출
	cout << " smallest(6.5,2.3,44.21) : " << smallest(6.5, 2.3, 44.21) << endl;

	return 0;
}
